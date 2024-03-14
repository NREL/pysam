#include <Python.h>

#include <SAM_Sco2CspSystem.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SystemDesign Group
 */ 

static PyTypeObject SystemDesign_Type;

static PyObject *
SystemDesign_new(SAM_Sco2CspSystem data_ptr)
{
	PyObject* new_obj = SystemDesign_Type.tp_alloc(&SystemDesign_Type,0);

	VarGroupObject* SystemDesign_obj = (VarGroupObject*)new_obj;

	SystemDesign_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemDesign methods */

static PyObject *
SystemDesign_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CspSystem", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemDesign_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CspSystem", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemDesign_methods[] = {
		{"assign",            (PyCFunction)SystemDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemDesign_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemDesign_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_T_amb_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_T_amb_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_htf_hot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_T_htf_hot_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_htf_hot_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_T_htf_hot_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_W_dot_net_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_W_dot_net_des_nget, self->data_ptr);
}

static int
SystemDesign_set_W_dot_net_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_W_dot_net_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_dT_PHX_hot_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_dT_PHX_hot_approach_nget, self->data_ptr);
}

static int
SystemDesign_set_dT_PHX_hot_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_dT_PHX_hot_approach_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_dT_mc_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_dT_mc_approach_nget, self->data_ptr);
}

static int
SystemDesign_set_dT_mc_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_dT_mc_approach_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_design_method(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_design_method_nget, self->data_ptr);
}

static int
SystemDesign_set_design_method(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_design_method_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_eta_thermal_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_eta_thermal_des_nget, self->data_ptr);
}

static int
SystemDesign_set_eta_thermal_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_eta_thermal_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_htf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_htf_nget, self->data_ptr);
}

static int
SystemDesign_set_htf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_htf_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_htf_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_SystemDesign_htf_props_mget, self->data_ptr);
}

static int
SystemDesign_set_htf_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Sco2CspSystem_SystemDesign_htf_props_mset, self->data_ptr);
}

static PyObject *
SystemDesign_get_site_elevation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_SystemDesign_site_elevation_nget, self->data_ptr);
}

static int
SystemDesign_set_site_elevation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_SystemDesign_site_elevation_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"T_amb_des", (getter)SystemDesign_get_T_amb_des,(setter)SystemDesign_set_T_amb_des,
	PyDoc_STR("*float*: Ambient temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_htf_hot_des", (getter)SystemDesign_get_T_htf_hot_des,(setter)SystemDesign_set_T_htf_hot_des,
	PyDoc_STR("*float*: HTF design hot temperature (PHX inlet) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"W_dot_net_des", (getter)SystemDesign_get_W_dot_net_des,(setter)SystemDesign_set_W_dot_net_des,
	PyDoc_STR("*float*: Design cycle power output (no cooling parasitics) [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"dT_PHX_hot_approach", (getter)SystemDesign_get_dT_PHX_hot_approach,(setter)SystemDesign_set_dT_PHX_hot_approach,
	PyDoc_STR("*float*: Temp diff btw hot HTF and turbine inlet [C]\n\n**Required:**\nTrue"),
 	NULL},
{"dT_mc_approach", (getter)SystemDesign_get_dT_mc_approach,(setter)SystemDesign_set_dT_mc_approach,
	PyDoc_STR("*float*: Temp diff btw ambient air and main compressor inlet [C]\n\n**Required:**\nTrue"),
 	NULL},
{"design_method", (getter)SystemDesign_get_design_method,(setter)SystemDesign_set_design_method,
	PyDoc_STR("*float*: 1 = Specify efficiency, 2 = Specify total recup UA, 3 = Specify each recup design\n\n**Required:**\nTrue"),
 	NULL},
{"eta_thermal_des", (getter)SystemDesign_get_eta_thermal_des,(setter)SystemDesign_set_eta_thermal_des,
	PyDoc_STR("*float*: Power cycle thermal efficiency\n\n**Required:**\nRequired if design_method=1"),
 	NULL},
{"htf", (getter)SystemDesign_get_htf,(setter)SystemDesign_set_htf,
	PyDoc_STR("*float*: Integer code for HTF used in PHX\n\n**Required:**\nTrue"),
 	NULL},
{"htf_props", (getter)SystemDesign_get_htf_props,(setter)SystemDesign_set_htf_props,
	PyDoc_STR("*sequence[sequence]*: User defined HTF property data\n\n**Info:**\n7 columns (T,Cp,dens,visc,kvisc,cond,h), at least 3 rows\n\n**Required:**\nFalse. Automatically set to [[0]] if not assigned explicitly or loaded from defaults."),
 	NULL},
{"site_elevation", (getter)SystemDesign_get_site_elevation,(setter)SystemDesign_set_site_elevation,
	PyDoc_STR("*float*: Site elevation [m]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem.SystemDesign",             /*tp_name*/
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
		SystemDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemDesign_getset,          /*tp_getset*/
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
 * HeatExchangerDesign Group
 */ 

static PyTypeObject HeatExchangerDesign_Type;

static PyObject *
HeatExchangerDesign_new(SAM_Sco2CspSystem data_ptr)
{
	PyObject* new_obj = HeatExchangerDesign_Type.tp_alloc(&HeatExchangerDesign_Type,0);

	VarGroupObject* HeatExchangerDesign_obj = (VarGroupObject*)new_obj;

	HeatExchangerDesign_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* HeatExchangerDesign methods */

static PyObject *
HeatExchangerDesign_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CspSystem", "HeatExchangerDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HeatExchangerDesign_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &HeatExchangerDesign_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CspSystem", "HeatExchangerDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HeatExchangerDesign_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &HeatExchangerDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef HeatExchangerDesign_methods[] = {
		{"assign",            (PyCFunction)HeatExchangerDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``HeatExchangerDesign_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)HeatExchangerDesign_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``HeatExchangerDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)HeatExchangerDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HeatExchangerDesign_get_HTR_HP_deltaP_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_HP_deltaP_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_HP_deltaP_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_HP_deltaP_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_LP_deltaP_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_LP_deltaP_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_LP_deltaP_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_LP_deltaP_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_UA_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_UA_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_UA_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_UA_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_design_code(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_design_code_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_design_code(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_design_code_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_eff_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_eff_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_eff_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_eff_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_min_dT_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_min_dT_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_min_dT_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_min_dT_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_n_sub_hx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_n_sub_hx_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_n_sub_hx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_n_sub_hx_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HTR_od_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HTR_od_model_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HTR_od_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HTR_od_model_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_HT_recup_eff_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_HT_recup_eff_max_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_HT_recup_eff_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_HT_recup_eff_max_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_HP_deltaP_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_HP_deltaP_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_HP_deltaP_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_HP_deltaP_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_LP_deltaP_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_LP_deltaP_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_LP_deltaP_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_LP_deltaP_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_UA_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_UA_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_UA_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_UA_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_design_code(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_design_code_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_design_code(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_design_code_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_eff_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_eff_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_eff_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_eff_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_min_dT_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_min_dT_des_in_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_min_dT_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_min_dT_des_in_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_n_sub_hx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_n_sub_hx_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_n_sub_hx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_n_sub_hx_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LTR_od_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LTR_od_model_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LTR_od_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LTR_od_model_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_LT_recup_eff_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_LT_recup_eff_max_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_LT_recup_eff_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_LT_recup_eff_max_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_UA_recup_tot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_UA_recup_tot_des_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_UA_recup_tot_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_UA_recup_tot_des_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_cycle_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_cycle_config_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_cycle_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_cycle_config_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_des_objective(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_des_objective_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_des_objective(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_des_objective_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_is_IP_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_is_IP_fixed_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_is_IP_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_is_IP_fixed_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_is_PR_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_is_PR_fixed_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_is_PR_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_is_PR_fixed_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_is_P_high_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_is_P_high_fixed_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_is_P_high_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_is_P_high_fixed_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_is_recomp_ok(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_is_recomp_ok_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_is_recomp_ok(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_is_recomp_ok_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_min_phx_deltaT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_min_phx_deltaT_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_min_phx_deltaT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_min_phx_deltaT_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_od_rel_tol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_od_rel_tol_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_od_rel_tol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_od_rel_tol_nset, self->data_ptr);
}

static PyObject *
HeatExchangerDesign_get_rel_tol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_HeatExchangerDesign_rel_tol_nget, self->data_ptr);
}

static int
HeatExchangerDesign_set_rel_tol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_HeatExchangerDesign_rel_tol_nset, self->data_ptr);
}

static PyGetSetDef HeatExchangerDesign_getset[] = {
{"HTR_HP_deltaP_des_in", (getter)HeatExchangerDesign_get_HTR_HP_deltaP_des_in,(setter)HeatExchangerDesign_set_HTR_HP_deltaP_des_in,
	PyDoc_STR("*float*: HTR high pressure side pressure drop as fraction of inlet pressure [-]\n\n**Info:**\nHigh temperature recuperator"),
 	NULL},
{"HTR_LP_deltaP_des_in", (getter)HeatExchangerDesign_get_HTR_LP_deltaP_des_in,(setter)HeatExchangerDesign_set_HTR_LP_deltaP_des_in,
	PyDoc_STR("*float*: HTR low pressure side pressure drop as fraction of inlet pressure [-]\n\n**Info:**\nHigh temperature recuperator"),
 	NULL},
{"HTR_UA_des_in", (getter)HeatExchangerDesign_get_HTR_UA_des_in,(setter)HeatExchangerDesign_set_HTR_UA_des_in,
	PyDoc_STR("*float*: Design HTR conductance [kW/K]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"HTR_design_code", (getter)HeatExchangerDesign_get_HTR_design_code,(setter)HeatExchangerDesign_set_HTR_design_code,
	PyDoc_STR("*float*: 1 = UA, 2 = min dT, 3 = effectiveness [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"HTR_eff_des_in", (getter)HeatExchangerDesign_get_HTR_eff_des_in,(setter)HeatExchangerDesign_set_HTR_eff_des_in,
	PyDoc_STR("*float*: Design effectiveness for HTR [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"HTR_min_dT_des_in", (getter)HeatExchangerDesign_get_HTR_min_dT_des_in,(setter)HeatExchangerDesign_set_HTR_min_dT_des_in,
	PyDoc_STR("*float*: Design minimum allowable temperature difference in HTR [C]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"HTR_n_sub_hx", (getter)HeatExchangerDesign_get_HTR_n_sub_hx,(setter)HeatExchangerDesign_set_HTR_n_sub_hx,
	PyDoc_STR("*float*: HTR number of model subsections [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"HTR_od_model", (getter)HeatExchangerDesign_get_HTR_od_model,(setter)HeatExchangerDesign_set_HTR_od_model,
	PyDoc_STR("*float*: 0: mass flow scale, 1: conductance ratio model [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"HT_recup_eff_max", (getter)HeatExchangerDesign_get_HT_recup_eff_max,(setter)HeatExchangerDesign_set_HT_recup_eff_max,
	PyDoc_STR("*float*: Maximum allowable effectiveness in HTR [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 1.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"LTR_HP_deltaP_des_in", (getter)HeatExchangerDesign_get_LTR_HP_deltaP_des_in,(setter)HeatExchangerDesign_set_LTR_HP_deltaP_des_in,
	PyDoc_STR("*float*: LTR high pressure side pressure drop as fraction of inlet pressure [-]\n\n**Info:**\nLow temperature recuperator"),
 	NULL},
{"LTR_LP_deltaP_des_in", (getter)HeatExchangerDesign_get_LTR_LP_deltaP_des_in,(setter)HeatExchangerDesign_set_LTR_LP_deltaP_des_in,
	PyDoc_STR("*float*: LTR low pressure side pressure drop as fraction of inlet pressure [-]\n\n**Info:**\nLow temperature recuperator"),
 	NULL},
{"LTR_UA_des_in", (getter)HeatExchangerDesign_get_LTR_UA_des_in,(setter)HeatExchangerDesign_set_LTR_UA_des_in,
	PyDoc_STR("*float*: Design LTR conductance [kW/K]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"LTR_design_code", (getter)HeatExchangerDesign_get_LTR_design_code,(setter)HeatExchangerDesign_set_LTR_design_code,
	PyDoc_STR("*float*: 1 = UA, 2 = min dT, 3 = effectiveness [-]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"LTR_eff_des_in", (getter)HeatExchangerDesign_get_LTR_eff_des_in,(setter)HeatExchangerDesign_set_LTR_eff_des_in,
	PyDoc_STR("*float*: Design effectiveness for LTR [-]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"LTR_min_dT_des_in", (getter)HeatExchangerDesign_get_LTR_min_dT_des_in,(setter)HeatExchangerDesign_set_LTR_min_dT_des_in,
	PyDoc_STR("*float*: Design minimum allowable temperature difference in LTR [C]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nRequired if design_method=3"),
 	NULL},
{"LTR_n_sub_hx", (getter)HeatExchangerDesign_get_LTR_n_sub_hx,(setter)HeatExchangerDesign_set_LTR_n_sub_hx,
	PyDoc_STR("*float*: LTR number of model subsections [-]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"LTR_od_model", (getter)HeatExchangerDesign_get_LTR_od_model,(setter)HeatExchangerDesign_set_LTR_od_model,
	PyDoc_STR("*float*: 0: mass flow scale, 1: conductance ratio model [-]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"LT_recup_eff_max", (getter)HeatExchangerDesign_get_LT_recup_eff_max,(setter)HeatExchangerDesign_set_LT_recup_eff_max,
	PyDoc_STR("*float*: Maximum allowable effectiveness in LTR [-]\n\n**Info:**\nLow temperature recuperator\n\n**Required:**\nFalse. Automatically set to 1.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"UA_recup_tot_des", (getter)HeatExchangerDesign_get_UA_recup_tot_des,(setter)HeatExchangerDesign_set_UA_recup_tot_des,
	PyDoc_STR("*float*: Total recuperator conductance [kW/K]\n\n**Info:**\nCombined recuperator design\n\n**Required:**\nRequired if design_method=2"),
 	NULL},
{"cycle_config", (getter)HeatExchangerDesign_get_cycle_config,(setter)HeatExchangerDesign_set_cycle_config,
	PyDoc_STR("*float*: 1 = recompression, 2 = partial cooling\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"des_objective", (getter)HeatExchangerDesign_get_des_objective,(setter)HeatExchangerDesign_set_des_objective,
	PyDoc_STR("*float*: [2] = hit min phx deltat then max eta, [else] max eta\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_IP_fixed", (getter)HeatExchangerDesign_get_is_IP_fixed,(setter)HeatExchangerDesign_set_is_IP_fixed,
	PyDoc_STR("*float*: partial cooling config: 0 = No, >0 = fixed HP-IP pressure ratio at input, <0 = fixed IP at abs(input)\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_PR_fixed", (getter)HeatExchangerDesign_get_is_PR_fixed,(setter)HeatExchangerDesign_set_is_PR_fixed,
	PyDoc_STR("*float*: 0 = No, >0 = fixed pressure ratio at input <0 = fixed LP at abs(input) [High temperature recuperator]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_P_high_fixed", (getter)HeatExchangerDesign_get_is_P_high_fixed,(setter)HeatExchangerDesign_set_is_P_high_fixed,
	PyDoc_STR("*float*: 1 = Yes (=P_high_limit), 0 = No, optimized (default)\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_recomp_ok", (getter)HeatExchangerDesign_get_is_recomp_ok,(setter)HeatExchangerDesign_set_is_recomp_ok,
	PyDoc_STR("*float*: 1 = Yes, 0 = simple cycle only, < 0 = fix f_recomp to abs(input)\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"min_phx_deltaT", (getter)HeatExchangerDesign_get_min_phx_deltaT,(setter)HeatExchangerDesign_set_min_phx_deltaT,
	PyDoc_STR("*float*: Minimum design temperature difference across PHX [C]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"od_rel_tol", (getter)HeatExchangerDesign_get_od_rel_tol,(setter)HeatExchangerDesign_set_od_rel_tol,
	PyDoc_STR("*float*: Baseline off-design relative convergence tolerance exponent (10^-od_rel_tol) [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rel_tol", (getter)HeatExchangerDesign_get_rel_tol,(setter)HeatExchangerDesign_set_rel_tol,
	PyDoc_STR("*float*: Baseline solver and optimization relative tolerance exponent (10^-rel_tol) [-]\n\n**Info:**\nHigh temperature recuperator\n\n**Required:**\nFalse. Automatically set to 3 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject HeatExchangerDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem.HeatExchangerDesign",             /*tp_name*/
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
		HeatExchangerDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		HeatExchangerDesign_getset,          /*tp_getset*/
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
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Sco2CspSystem data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CspSystem", "Common")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CspSystem", "Common")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Common_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Common_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_PHX_co2_deltaP_des_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_PHX_co2_deltaP_des_in_nget, self->data_ptr);
}

static int
Common_set_PHX_co2_deltaP_des_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_PHX_co2_deltaP_des_in_nset, self->data_ptr);
}

static PyObject *
Common_get_P_high_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_P_high_limit_nget, self->data_ptr);
}

static int
Common_set_P_high_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_P_high_limit_nset, self->data_ptr);
}

static PyObject *
Common_get_deltaP_counterHX_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_deltaP_counterHX_frac_nget, self->data_ptr);
}

static int
Common_set_deltaP_counterHX_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_deltaP_counterHX_frac_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_isen_mc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_eta_isen_mc_nget, self->data_ptr);
}

static int
Common_set_eta_isen_mc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_eta_isen_mc_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_isen_pc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_eta_isen_pc_nget, self->data_ptr);
}

static int
Common_set_eta_isen_pc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_eta_isen_pc_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_isen_rc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_eta_isen_rc_nget, self->data_ptr);
}

static int
Common_set_eta_isen_rc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_eta_isen_rc_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_isen_t(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_eta_isen_t_nget, self->data_ptr);
}

static int
Common_set_eta_isen_t(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_eta_isen_t_nset, self->data_ptr);
}

static PyObject *
Common_get_is_gen_od_polynomials(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_is_gen_od_polynomials_nget, self->data_ptr);
}

static int
Common_set_is_gen_od_polynomials(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_is_gen_od_polynomials_nset, self->data_ptr);
}

static PyObject *
Common_get_mc_comp_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_mc_comp_type_nget, self->data_ptr);
}

static int
Common_set_mc_comp_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_mc_comp_type_nset, self->data_ptr);
}

static PyObject *
Common_get_od_P_mc_in_sweep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Common_od_P_mc_in_sweep_aget, self->data_ptr);
}

static int
Common_set_od_P_mc_in_sweep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Sco2CspSystem_Common_od_P_mc_in_sweep_aset, self->data_ptr);
}

static PyObject *
Common_get_od_T_mc_in_sweep(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Common_od_T_mc_in_sweep_aget, self->data_ptr);
}

static int
Common_set_od_T_mc_in_sweep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Sco2CspSystem_Common_od_T_mc_in_sweep_aset, self->data_ptr);
}

static PyObject *
Common_get_od_T_t_in_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_od_T_t_in_mode_nget, self->data_ptr);
}

static int
Common_set_od_T_t_in_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_od_T_t_in_mode_nset, self->data_ptr);
}

static PyObject *
Common_get_od_cases(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Common_od_cases_mget, self->data_ptr);
}

static int
Common_set_od_cases(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Sco2CspSystem_Common_od_cases_mset, self->data_ptr);
}

static PyObject *
Common_get_od_generate_udpc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Common_od_generate_udpc_aget, self->data_ptr);
}

static int
Common_set_od_generate_udpc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Sco2CspSystem_Common_od_generate_udpc_aset, self->data_ptr);
}

static PyObject *
Common_get_od_max_htf_m_dot(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Common_od_max_htf_m_dot_mget, self->data_ptr);
}

static int
Common_set_od_max_htf_m_dot(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Sco2CspSystem_Common_od_max_htf_m_dot_mset, self->data_ptr);
}

static PyObject *
Common_get_od_opt_objective(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Common_od_opt_objective_nget, self->data_ptr);
}

static int
Common_set_od_opt_objective(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_Common_od_opt_objective_nset, self->data_ptr);
}

static PyObject *
Common_get_od_set_control(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Common_od_set_control_mget, self->data_ptr);
}

static int
Common_set_od_set_control(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Sco2CspSystem_Common_od_set_control_mset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"PHX_co2_deltaP_des_in", (getter)Common_get_PHX_co2_deltaP_des_in,(setter)Common_set_PHX_co2_deltaP_des_in,
	PyDoc_STR("*float*: PHX co2 side pressure drop as fraction of inlet pressure [-]"),
 	NULL},
{"P_high_limit", (getter)Common_get_P_high_limit,(setter)Common_set_P_high_limit,
	PyDoc_STR("*float*: High pressure limit in cycle [MPa]\n\n**Required:**\nTrue"),
 	NULL},
{"deltaP_counterHX_frac", (getter)Common_get_deltaP_counterHX_frac,(setter)Common_set_deltaP_counterHX_frac,
	PyDoc_STR("*float*: Fraction of CO2 inlet pressure that is design point counterflow HX (recups & PHX) pressure drop [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"eta_isen_mc", (getter)Common_get_eta_isen_mc,(setter)Common_set_eta_isen_mc,
	PyDoc_STR("*float*: Design main compressor isentropic efficiency [-]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_isen_pc", (getter)Common_get_eta_isen_pc,(setter)Common_set_eta_isen_pc,
	PyDoc_STR("*float*: Design precompressor isentropic efficiency [-]\n\n**Required:**\nRequired if cycle_config=2"),
 	NULL},
{"eta_isen_rc", (getter)Common_get_eta_isen_rc,(setter)Common_set_eta_isen_rc,
	PyDoc_STR("*float*: Design re-compressor isentropic efficiency [-]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_isen_t", (getter)Common_get_eta_isen_t,(setter)Common_set_eta_isen_t,
	PyDoc_STR("*float*: Design turbine isentropic efficiency [-]\n\n**Required:**\nTrue"),
 	NULL},
{"is_gen_od_polynomials", (getter)Common_get_is_gen_od_polynomials,(setter)Common_set_is_gen_od_polynomials,
	PyDoc_STR("*float*: Generate off-design polynomials for Generic CSP models? 1 = Yes, 0 = No\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"mc_comp_type", (getter)Common_get_mc_comp_type,(setter)Common_set_mc_comp_type,
	PyDoc_STR("*float*: Main compressor compressor type 1: SNL 2: CompA [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"od_P_mc_in_sweep", (getter)Common_get_od_P_mc_in_sweep,(setter)Common_set_od_P_mc_in_sweep,
	PyDoc_STR("*sequence*: Columns: 0) T_htf_C, 1) m_dot_htf_ND, 2) T_amb_C, 3) T_mc_in_C, 4) T_pc_in_C, 5) f_N_rc (=1 use design, <0, frac_des = abs(input), 6) f_N_mc (=1 use design, <0, frac_des = abs(input), 7) f_N_pc (=1 use design, =0 optimize, <0, frac_des = abs(input)), 8) PHX_f_dP (=1 use design, <0 = abs(input)"),
 	NULL},
{"od_T_mc_in_sweep", (getter)Common_get_od_T_mc_in_sweep,(setter)Common_set_od_T_mc_in_sweep,
	PyDoc_STR("*sequence*: Columns: 0) T_htf_C, 1) m_dot_htf_ND, 2) T_amb_C,3) f_N_rc (=1 use design, <0, frac_des = abs(input),4) f_N_mc (=1 use design, <0, frac_des = abs(input),5) f_N_pc (=1 use design, <0, frac_des = abs(input),6) PHX_f_dP (=1 use design, <0 = abs(input)"),
 	NULL},
{"od_T_t_in_mode", (getter)Common_get_od_T_t_in_mode,(setter)Common_set_od_T_t_in_mode,
	PyDoc_STR("*float*: 0: model solves co2/HTF PHX od model to calculate turbine inlet temp, 1: model sets turbine inlet temp to HTF hot temp\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"od_cases", (getter)Common_get_od_cases,(setter)Common_set_od_cases,
	PyDoc_STR("*sequence[sequence]*: Columns: 0) T_htf_C, 1) m_dot_htf_ND, 2) T_amb_C, 3) f_N_rc (=1 use design, =0 optimize, <0, frac_des = abs(input)), 4) f_N_mc (=1 use design, =0 optimize, <0, frac_des = abs(input)), 5) f_N_pc (=1 use design, =0 optimize, <0, frac_des = abs(input)), 6) PHX_f_dP (=1 use design, <0 = abs(input), Rows: cases"),
 	NULL},
{"od_generate_udpc", (getter)Common_get_od_generate_udpc,(setter)Common_set_od_generate_udpc,
	PyDoc_STR("*sequence*: Columns 0) True/False,1) f_N_rc (=1 use design, =0 optimize, <0, frac_des = abs(input),2) f_N_mc (=1 use design, =0 optimize, <0, frac_des = abs(input),3) PHX_f_dP (=1 use design, <0 = abs(input)"),
 	NULL},
{"od_max_htf_m_dot", (getter)Common_get_od_max_htf_m_dot,(setter)Common_set_od_max_htf_m_dot,
	PyDoc_STR("*sequence[sequence]*: Columns: 0) T_htf_C, 1) T_amb_C,2) f_N_rc (=1 use design, <0, frac_des = abs(input),3) f_N_mc (=1 use design, <0, frac_des = abs(input),4) PHX_f_dP (=1 use design, <0 = abs(input), Rows: cases"),
 	NULL},
{"od_opt_objective", (getter)Common_get_od_opt_objective,(setter)Common_set_od_opt_objective,
	PyDoc_STR("*float*: 0: find P_LP_in to achieve target power, optimize efficiency 1: find P_LP_in to achieve T_HTF_cold, optimize efficiency\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"od_set_control", (getter)Common_get_od_set_control,(setter)Common_set_od_set_control,
	PyDoc_STR("*sequence[sequence]*: Columns: 0) T_htf_C, 1) m_dot_htf_ND, 2) T_amb_C, 3) P_LP_in_MPa, 4) T_mc_in_C, 5) T_pc_in_C, 6) f_N_rc (=1 use design, <0, frac_des = abs(input), 7) f_N_mc (=1 use design, <0, frac_des = abs(input), 8) f_N_pc (=1 use design, =0 optimize, <0, frac_des = abs(input)), 9) PHX_f_dP (=1 use design, <0 = abs(input), Rows: cases"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem.Common",             /*tp_name*/
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
 * PHXDesign Group
 */ 

static PyTypeObject PHXDesign_Type;

static PyObject *
PHXDesign_new(SAM_Sco2CspSystem data_ptr)
{
	PyObject* new_obj = PHXDesign_Type.tp_alloc(&PHXDesign_Type,0);

	VarGroupObject* PHXDesign_obj = (VarGroupObject*)new_obj;

	PHXDesign_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PHXDesign methods */

static PyObject *
PHXDesign_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CspSystem", "PHXDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PHXDesign_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PHXDesign_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CspSystem", "PHXDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PHXDesign_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PHXDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PHXDesign_methods[] = {
		{"assign",            (PyCFunction)PHXDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PHXDesign_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PHXDesign_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PHXDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PHXDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PHXDesign_get_PHX_n_sub_hx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_PHXDesign_PHX_n_sub_hx_nget, self->data_ptr);
}

static int
PHXDesign_set_PHX_n_sub_hx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_PHXDesign_PHX_n_sub_hx_nset, self->data_ptr);
}

static PyObject *
PHXDesign_get_PHX_od_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_PHXDesign_PHX_od_model_nget, self->data_ptr);
}

static int
PHXDesign_set_PHX_od_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_PHXDesign_PHX_od_model_nset, self->data_ptr);
}

static PyObject *
PHXDesign_get_dT_PHX_cold_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_PHXDesign_dT_PHX_cold_approach_nget, self->data_ptr);
}

static int
PHXDesign_set_dT_PHX_cold_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_PHXDesign_dT_PHX_cold_approach_nset, self->data_ptr);
}

static PyGetSetDef PHXDesign_getset[] = {
{"PHX_n_sub_hx", (getter)PHXDesign_get_PHX_n_sub_hx,(setter)PHXDesign_set_PHX_n_sub_hx,
	PyDoc_STR("*float*: Number of subsections in PHX model [-]\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"PHX_od_model", (getter)PHXDesign_get_PHX_od_model,(setter)PHXDesign_set_PHX_od_model,
	PyDoc_STR("*float*: 0: mass flow scale, 1: conductance ratio model [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dT_PHX_cold_approach", (getter)PHXDesign_get_dT_PHX_cold_approach,(setter)PHXDesign_set_dT_PHX_cold_approach,
	PyDoc_STR("*float*: Temp diff btw cold HTF and cold CO2 [C]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PHXDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem.PHXDesign",             /*tp_name*/
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
		PHXDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PHXDesign_getset,          /*tp_getset*/
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
 * AirCoolerDesign Group
 */ 

static PyTypeObject AirCoolerDesign_Type;

static PyObject *
AirCoolerDesign_new(SAM_Sco2CspSystem data_ptr)
{
	PyObject* new_obj = AirCoolerDesign_Type.tp_alloc(&AirCoolerDesign_Type,0);

	VarGroupObject* AirCoolerDesign_obj = (VarGroupObject*)new_obj;

	AirCoolerDesign_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* AirCoolerDesign methods */

static PyObject *
AirCoolerDesign_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CspSystem", "AirCoolerDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AirCoolerDesign_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &AirCoolerDesign_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CspSystem", "AirCoolerDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AirCoolerDesign_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &AirCoolerDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AirCoolerDesign_methods[] = {
		{"assign",            (PyCFunction)AirCoolerDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``AirCoolerDesign_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)AirCoolerDesign_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``AirCoolerDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AirCoolerDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AirCoolerDesign_get_N_nodes_air_cooler_pass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_AirCoolerDesign_N_nodes_air_cooler_pass_nget, self->data_ptr);
}

static int
AirCoolerDesign_set_N_nodes_air_cooler_pass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_AirCoolerDesign_N_nodes_air_cooler_pass_nset, self->data_ptr);
}

static PyObject *
AirCoolerDesign_get_deltaP_cooler_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_AirCoolerDesign_deltaP_cooler_frac_nget, self->data_ptr);
}

static int
AirCoolerDesign_set_deltaP_cooler_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_AirCoolerDesign_deltaP_cooler_frac_nset, self->data_ptr);
}

static PyObject *
AirCoolerDesign_get_eta_air_cooler_fan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_AirCoolerDesign_eta_air_cooler_fan_nget, self->data_ptr);
}

static int
AirCoolerDesign_set_eta_air_cooler_fan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_AirCoolerDesign_eta_air_cooler_fan_nset, self->data_ptr);
}

static PyObject *
AirCoolerDesign_get_fan_power_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_AirCoolerDesign_fan_power_frac_nget, self->data_ptr);
}

static int
AirCoolerDesign_set_fan_power_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_AirCoolerDesign_fan_power_frac_nset, self->data_ptr);
}

static PyObject *
AirCoolerDesign_get_is_design_air_cooler(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_AirCoolerDesign_is_design_air_cooler_nget, self->data_ptr);
}

static int
AirCoolerDesign_set_is_design_air_cooler(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Sco2CspSystem_AirCoolerDesign_is_design_air_cooler_nset, self->data_ptr);
}

static PyGetSetDef AirCoolerDesign_getset[] = {
{"N_nodes_air_cooler_pass", (getter)AirCoolerDesign_get_N_nodes_air_cooler_pass,(setter)AirCoolerDesign_set_N_nodes_air_cooler_pass,
	PyDoc_STR("*float*: Number of nodes in single air cooler pass\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"deltaP_cooler_frac", (getter)AirCoolerDesign_get_deltaP_cooler_frac,(setter)AirCoolerDesign_set_deltaP_cooler_frac,
	PyDoc_STR("*float*: Fraction of CO2 inlet pressure that is design point cooler CO2 pressure drop\n\n**Required:**\nTrue"),
 	NULL},
{"eta_air_cooler_fan", (getter)AirCoolerDesign_get_eta_air_cooler_fan,(setter)AirCoolerDesign_set_eta_air_cooler_fan,
	PyDoc_STR("*float*: Air cooler fan isentropic efficiency\n\n**Required:**\nFalse. Automatically set to 0.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"fan_power_frac", (getter)AirCoolerDesign_get_fan_power_frac,(setter)AirCoolerDesign_set_fan_power_frac,
	PyDoc_STR("*float*: Fraction of net cycle power consumed by air cooler fan\n\n**Required:**\nTrue"),
 	NULL},
{"is_design_air_cooler", (getter)AirCoolerDesign_get_is_design_air_cooler,(setter)AirCoolerDesign_set_is_design_air_cooler,
	PyDoc_STR("*float*: Defaults to True. False will skip air cooler calcs\n\n**Required:**\nFalse. Automatically set to 1.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AirCoolerDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem.AirCoolerDesign",             /*tp_name*/
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
		AirCoolerDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AirCoolerDesign_getset,          /*tp_getset*/
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
Outputs_new(SAM_Sco2CspSystem data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Sco2CspSystem", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Sco2CspSystem", "Outputs")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Outputs_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Outputs_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_HTR_HP_T_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_HP_T_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_HP_T_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_HTR_HP_T_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_HP_deltaP_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_HP_deltaP_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_HP_deltaP_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_HTR_HP_deltaP_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_LP_T_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_LP_T_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_LP_T_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_HTR_LP_T_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_LP_deltaP_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_LP_deltaP_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_LP_deltaP_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_HTR_LP_deltaP_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_UA_assigned(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_UA_assigned_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_UA_calculated(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_UA_calculated_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_min_dT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_HTR_min_dT_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HTR_min_dT_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_HTR_min_dT_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_HP_T_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_HP_T_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_HP_T_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_LTR_HP_T_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_HP_deltaP_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_HP_deltaP_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_HP_deltaP_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_LTR_HP_deltaP_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_LP_deltaP_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_LP_deltaP_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_LP_deltaP_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_LTR_LP_deltaP_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_UA_assigned(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_UA_assigned_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_UA_calculated(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_UA_calculated_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_min_dT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_LTR_min_dT_nget, self->data_ptr);
}

static PyObject *
Outputs_get_LTR_min_dT_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_LTR_min_dT_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_NTU_HTR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_NTU_HTR_nget, self->data_ptr);
}

static PyObject *
Outputs_get_NTU_LTR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_NTU_LTR_nget, self->data_ptr);
}

static PyObject *
Outputs_get_NTU_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_NTU_PHX_nget, self->data_ptr);
}

static PyObject *
Outputs_get_PHX_co2_deltaP_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_PHX_co2_deltaP_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_PHX_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_PHX_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_PHX_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_PHX_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_PHX_min_dT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_PHX_min_dT_nget, self->data_ptr);
}

static PyObject *
Outputs_get_P_co2_PHX_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_P_co2_PHX_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_P_co2_PHX_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_co2_PHX_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_comp_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_P_comp_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_P_comp_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_comp_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_comp_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_P_comp_out_nget, self->data_ptr);
}

static PyObject *
Outputs_get_P_mc_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_mc_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_mc_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_mc_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_pc_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_pc_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_rc_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_rc_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_state_points(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_state_points_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_t_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_P_t_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_Q_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_HTR_HP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_HTR_HP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_HTR_LP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_HTR_LP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_LTR_HP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_LTR_HP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_LTR_LP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_LTR_LP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_PHX_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_PHX_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_amb_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_co2_PHX_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_T_co2_PHX_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_co2_PHX_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_co2_PHX_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_co2_PHX_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_co2_PHX_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_comp_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_T_comp_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_cold_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_T_htf_cold_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_cold_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_htf_cold_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_htf_hot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_htf_hot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_main_cooler_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_main_cooler_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_mc_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_mc_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pre_cooler_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_pre_cooler_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_state_points(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_T_state_points_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_turb_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_T_turb_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_UA_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_UA_PHX_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_net_less_cooling(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_W_dot_net_less_cooling_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_net_less_cooling_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_W_dot_net_less_cooling_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_net_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_W_dot_net_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_c_tot_W_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_c_tot_W_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_c_tot_W_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_c_tot_W_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_c_tot_cost_equip(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_c_tot_cost_equip_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cooler_tot_UA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cooler_tot_UA_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cooler_tot_W_dot_fan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cooler_tot_W_dot_fan_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cooler_tot_W_dot_fan_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_cooler_tot_W_dot_fan_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cooler_tot_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cooler_tot_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cooler_tot_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cooler_tot_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cycle_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cycle_spec_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_spec_cost_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_cycle_spec_cost_thermal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaT_HTF_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_deltaT_HTF_PHX_nget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaT_HTF_PHX_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_deltaT_HTF_PHX_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_diff_E_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_diff_E_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_diff_Q_HTR(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_diff_Q_HTR_aget, self->data_ptr);
}

static PyObject *
Outputs_get_diff_Q_LTR(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_diff_Q_LTR_aget, self->data_ptr);
}

static PyObject *
Outputs_get_diff_m_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_diff_m_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_HTR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_eff_HTR_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_HTR_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_eff_HTR_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_LTR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_eff_LTR_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_LTR_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_eff_LTR_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_eff_PHX_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_eta_thermal_calc_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal_net_less_cooling_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_eta_thermal_net_less_cooling_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal_net_less_cooling_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_eta_thermal_net_less_cooling_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_eta_thermal_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_h_mc_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_h_mc_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_h_pc_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_h_pc_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_h_rc_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_h_rc_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_h_state_points(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_h_state_points_aget, self->data_ptr);
}

static PyObject *
Outputs_get_h_t_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_h_t_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_co2_full(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_m_dot_co2_full_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_co2_full_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_m_dot_co2_full_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_m_dot_htf_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htf_fracs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_m_dot_htf_fracs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_D(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_D_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_N_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_N_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_N_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_N_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_N_od_perc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_N_od_perc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_T_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_T_out_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_T_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_T_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_W_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_W_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_W_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_W_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_P_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_P_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_T_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_T_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_T_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_T_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_UA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_UA_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_W_dot_fan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_W_dot_fan_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_W_dot_fan_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_W_dot_fan_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_co2_deltaP_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_co2_deltaP_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_co2_deltaP_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_co2_deltaP_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_in_isen_deltah_to_P_mc_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_in_isen_deltah_to_P_mc_out_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_in_isen_deltah_to_P_mc_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_in_isen_deltah_to_P_mc_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_m_dot_co2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_m_dot_co2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_q_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_q_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_rho_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_rho_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cooler_rho_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_cooler_rho_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_eta_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_eta_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_eta_stages_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_eta_stages_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_eta_stages_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_mc_eta_stages_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_f_bypass_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_f_bypass_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_ideal_spec_work(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_ideal_spec_work_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_ideal_spec_work_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_ideal_spec_work_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_m_dot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_m_dot_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_m_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_m_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_n_stages(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_n_stages_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_phi_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_phi_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_phi_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_mc_phi_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_phi_surge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_phi_surge_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_psi_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_psi_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_psi_max_at_N_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_psi_max_at_N_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_psi_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_mc_psi_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_rho_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_mc_rho_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_rho_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_rho_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_tip_ratio_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_mc_tip_ratio_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mc_tip_ratio_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_mc_tip_ratio_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_od_code(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_od_code_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_D(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_D_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_N_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_N_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_N_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_N_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_P_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_P_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_P_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_P_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_T_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_T_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_T_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_T_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_W_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_W_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_W_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_W_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_P_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_P_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_T_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_T_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_UA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_UA_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_W_dot_fan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_W_dot_fan_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_W_dot_fan_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_W_dot_fan_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_m_dot_co2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_m_dot_co2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cooler_q_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cooler_q_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_eta_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_eta_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_eta_stages_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_eta_stages_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_eta_stages_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_pc_eta_stages_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_f_bypass_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_f_bypass_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_ideal_spec_work_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_ideal_spec_work_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_ideal_spec_work_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_ideal_spec_work_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_m_dot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_m_dot_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_m_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_m_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_n_stages(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_n_stages_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_phi_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_phi_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_phi_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_pc_phi_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_phi_surge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_phi_surge_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_rho_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_pc_rho_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_rho_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_rho_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_tip_ratio_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_pc_tip_ratio_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_tip_ratio_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_pc_tip_ratio_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_phx_co2_deltaP_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_phx_co2_deltaP_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_phx_eff_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_phx_eff_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_piping_inventory_etc_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_piping_inventory_etc_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_HTR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_q_dot_HTR_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_HTR_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_q_dot_HTR_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_LTR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_q_dot_LTR_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_LTR_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_q_dot_LTR_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_PHX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_q_dot_PHX_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_D(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_D_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_N_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_N_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_N_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_N_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_N_od_perc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_N_od_perc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_P_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_P_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_P_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_P_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_P_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_P_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_P_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_P_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_T_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_T_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_T_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_T_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_T_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_T_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_T_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_T_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_W_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_W_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_W_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_W_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_eta_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_eta_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_eta_stages_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_eta_stages_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_eta_stages_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_rc_eta_stages_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_m_dot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_m_dot_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_m_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_m_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_n_stages(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_n_stages_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_phi_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_phi_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_phi_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_rc_phi_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_phi_surge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_phi_surge_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_psi_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_psi_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_psi_max_at_N_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_rc_psi_max_at_N_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_psi_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_rc_psi_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_tip_ratio_des(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_rc_tip_ratio_des_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rc_tip_ratio_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_rc_tip_ratio_od_mget, self->data_ptr);
}

static PyObject *
Outputs_get_recomp_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_recomp_frac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_recomp_frac_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_recomp_frac_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_recup_LTR_UA_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_recup_LTR_UA_frac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_recup_total_UA_assigned(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_recup_total_UA_assigned_nget, self->data_ptr);
}

static PyObject *
Outputs_get_recup_total_UA_calculated(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_recup_total_UA_calculated_nget, self->data_ptr);
}

static PyObject *
Outputs_get_recup_total_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_recup_total_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_recup_total_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_recup_total_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_s_HTR_HP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_HTR_HP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_HTR_LP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_HTR_LP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_LTR_HP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_LTR_HP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_LTR_LP_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_LTR_LP_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_PHX_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_PHX_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_main_cooler_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_main_cooler_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_pre_cooler_data(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_pre_cooler_data_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_state_points(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_s_state_points_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sim_time_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_sim_time_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_D(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_D_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_N_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_N_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_N_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_N_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_P_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_P_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_P_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_P_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_P_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_P_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_P_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_P_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_T_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_T_out_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_T_out_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_T_out_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_W_dot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_W_dot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_W_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_W_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_cost_bare_erected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_cost_bare_erected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_cost_equipment(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_cost_equipment_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_delta_h_isen_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_delta_h_isen_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_delta_h_isen_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_delta_h_isen_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_eta_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_eta_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_m_dot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_m_dot_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_m_dot_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_m_dot_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_nu_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_nu_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_nu_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_nu_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_rho_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_rho_in_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_rho_in_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_rho_in_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_t_tip_ratio_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_t_tip_ratio_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_tip_ratio_od(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Sco2CspSystem_Outputs_t_tip_ratio_od_aget, self->data_ptr);
}

static PyObject *
Outputs_get_udpc_n_T_amb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_udpc_n_T_amb_nget, self->data_ptr);
}

static PyObject *
Outputs_get_udpc_n_T_htf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_udpc_n_T_htf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_udpc_n_m_dot_htf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Sco2CspSystem_Outputs_udpc_n_m_dot_htf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_udpc_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Sco2CspSystem_Outputs_udpc_table_mget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"HTR_HP_T_in_des", (getter)Outputs_get_HTR_HP_T_in_des,(setter)0,
	PyDoc_STR("*float*: High temp recuperator HP inlet temperature [C]"),
 	NULL},
{"HTR_HP_T_in_od", (getter)Outputs_get_HTR_HP_T_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup HP inlet temperature [C]"),
 	NULL},
{"HTR_HP_deltaP_des", (getter)Outputs_get_HTR_HP_deltaP_des,(setter)0,
	PyDoc_STR("*float*: High temp recuperator high pressure design pressure drop [-]"),
 	NULL},
{"HTR_HP_deltaP_od", (getter)Outputs_get_HTR_HP_deltaP_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup high pressure side pressure drop [-]"),
 	NULL},
{"HTR_LP_T_out_des", (getter)Outputs_get_HTR_LP_T_out_des,(setter)0,
	PyDoc_STR("*float*: High temp recuperator LP outlet temperature [C]"),
 	NULL},
{"HTR_LP_T_out_od", (getter)Outputs_get_HTR_LP_T_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup LP outlet temperature [C]"),
 	NULL},
{"HTR_LP_deltaP_des", (getter)Outputs_get_HTR_LP_deltaP_des,(setter)0,
	PyDoc_STR("*float*: High temp recuperator low pressure design pressure drop [-]"),
 	NULL},
{"HTR_LP_deltaP_od", (getter)Outputs_get_HTR_LP_deltaP_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup low pressure side pressure drop [-]"),
 	NULL},
{"HTR_UA_assigned", (getter)Outputs_get_HTR_UA_assigned,(setter)0,
	PyDoc_STR("*float*: High temp recuperator UA assigned from total [MW/K]"),
 	NULL},
{"HTR_UA_calculated", (getter)Outputs_get_HTR_UA_calculated,(setter)0,
	PyDoc_STR("*float*: High temp recuperator UA calculated considering max eff and/or min temp diff parameter [MW/K]"),
 	NULL},
{"HTR_cost_bare_erected", (getter)Outputs_get_HTR_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: High temp recuperator cost equipment and install [M$]"),
 	NULL},
{"HTR_cost_equipment", (getter)Outputs_get_HTR_cost_equipment,(setter)0,
	PyDoc_STR("*float*: High temp recuperator cost equipment [M$]"),
 	NULL},
{"HTR_min_dT", (getter)Outputs_get_HTR_min_dT,(setter)0,
	PyDoc_STR("*float*: High temp recuperator min temperature difference [C]"),
 	NULL},
{"HTR_min_dT_od", (getter)Outputs_get_HTR_min_dT_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup minimum temperature difference [C]"),
 	NULL},
{"LTR_HP_T_out_des", (getter)Outputs_get_LTR_HP_T_out_des,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator HP outlet temperature [C]"),
 	NULL},
{"LTR_HP_T_out_od", (getter)Outputs_get_LTR_HP_T_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design low temp recup HP outlet temperature [C]"),
 	NULL},
{"LTR_HP_deltaP_des", (getter)Outputs_get_LTR_HP_deltaP_des,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator high pressure design pressure drop [-]"),
 	NULL},
{"LTR_HP_deltaP_od", (getter)Outputs_get_LTR_HP_deltaP_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design low temp recup high pressure side pressure drop [-]"),
 	NULL},
{"LTR_LP_deltaP_des", (getter)Outputs_get_LTR_LP_deltaP_des,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator low pressure design pressure drop [-]"),
 	NULL},
{"LTR_LP_deltaP_od", (getter)Outputs_get_LTR_LP_deltaP_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design low temp recup low pressure side pressure drop [-]"),
 	NULL},
{"LTR_UA_assigned", (getter)Outputs_get_LTR_UA_assigned,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator UA assigned from total [MW/K]"),
 	NULL},
{"LTR_UA_calculated", (getter)Outputs_get_LTR_UA_calculated,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator UA calculated considering max eff and/or min temp diff parameter [MW/K]"),
 	NULL},
{"LTR_cost_bare_erected", (getter)Outputs_get_LTR_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator cost equipment and install [M$]"),
 	NULL},
{"LTR_cost_equipment", (getter)Outputs_get_LTR_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator cost equipment [M$]"),
 	NULL},
{"LTR_min_dT", (getter)Outputs_get_LTR_min_dT,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator min temperature difference [C]"),
 	NULL},
{"LTR_min_dT_od", (getter)Outputs_get_LTR_min_dT_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design low temp recup minimum temperature difference [C]"),
 	NULL},
{"NTU_HTR", (getter)Outputs_get_NTU_HTR,(setter)0,
	PyDoc_STR("*float*: High temp recuperator NTRU"),
 	NULL},
{"NTU_LTR", (getter)Outputs_get_NTU_LTR,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator NTU"),
 	NULL},
{"NTU_PHX", (getter)Outputs_get_NTU_PHX,(setter)0,
	PyDoc_STR("*float*: PHX NTU"),
 	NULL},
{"PHX_co2_deltaP_des", (getter)Outputs_get_PHX_co2_deltaP_des,(setter)0,
	PyDoc_STR("*float*: PHX co2 side design pressure drop [-]"),
 	NULL},
{"PHX_cost_bare_erected", (getter)Outputs_get_PHX_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: PHX cost equipment and install [M$]"),
 	NULL},
{"PHX_cost_equipment", (getter)Outputs_get_PHX_cost_equipment,(setter)0,
	PyDoc_STR("*float*: PHX cost equipment [M$]"),
 	NULL},
{"PHX_min_dT", (getter)Outputs_get_PHX_min_dT,(setter)0,
	PyDoc_STR("*float*: PHX min temperature difference [C]"),
 	NULL},
{"P_co2_PHX_in", (getter)Outputs_get_P_co2_PHX_in,(setter)0,
	PyDoc_STR("*float*: CO2 pressure at PHX inlet [MPa]"),
 	NULL},
{"P_co2_PHX_in_od", (getter)Outputs_get_P_co2_PHX_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design PHX co2 inlet pressure [MPa]"),
 	NULL},
{"P_comp_in", (getter)Outputs_get_P_comp_in,(setter)0,
	PyDoc_STR("*float*: Compressor inlet pressure [MPa]"),
 	NULL},
{"P_comp_in_od", (getter)Outputs_get_P_comp_in_od,(setter)0,
	PyDoc_STR("*sequence*: Main compressor inlet pressures [MPa]"),
 	NULL},
{"P_comp_out", (getter)Outputs_get_P_comp_out,(setter)0,
	PyDoc_STR("*float*: Compressor outlet pressure [MPa]"),
 	NULL},
{"P_mc_data", (getter)Outputs_get_P_mc_data,(setter)0,
	PyDoc_STR("*sequence*: Pressure points along main compression [MPa]"),
 	NULL},
{"P_mc_out_od", (getter)Outputs_get_P_mc_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high side pressure [MPa]"),
 	NULL},
{"P_pc_data", (getter)Outputs_get_P_pc_data,(setter)0,
	PyDoc_STR("*sequence*: Pressure points along pre compression [MPa]"),
 	NULL},
{"P_rc_data", (getter)Outputs_get_P_rc_data,(setter)0,
	PyDoc_STR("*sequence*: Pressure points along re compression [MPa]"),
 	NULL},
{"P_state_points", (getter)Outputs_get_P_state_points,(setter)0,
	PyDoc_STR("*sequence*: Cycle pressure state points [MPa]"),
 	NULL},
{"P_t_data", (getter)Outputs_get_P_t_data,(setter)0,
	PyDoc_STR("*sequence*: Pressure points along turbine expansion [MPa]"),
 	NULL},
{"Q_dot_od", (getter)Outputs_get_Q_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design thermal input [MWt]"),
 	NULL},
{"T_HTR_HP_data", (getter)Outputs_get_T_HTR_HP_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along HTR HP stream [C]"),
 	NULL},
{"T_HTR_LP_data", (getter)Outputs_get_T_HTR_LP_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along HTR LP stream [C]"),
 	NULL},
{"T_LTR_HP_data", (getter)Outputs_get_T_LTR_HP_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along LTR HP stream [C]"),
 	NULL},
{"T_LTR_LP_data", (getter)Outputs_get_T_LTR_LP_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along LTR LP stream [C]"),
 	NULL},
{"T_PHX_data", (getter)Outputs_get_T_PHX_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along PHX stream [C]"),
 	NULL},
{"T_amb_od", (getter)Outputs_get_T_amb_od,(setter)0,
	PyDoc_STR("*sequence*: Ambient temperatures [C]"),
 	NULL},
{"T_co2_PHX_in", (getter)Outputs_get_T_co2_PHX_in,(setter)0,
	PyDoc_STR("*float*: CO2 temperature at PHX inlet [C]"),
 	NULL},
{"T_co2_PHX_in_od", (getter)Outputs_get_T_co2_PHX_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design PHX co2 inlet temperature [C]"),
 	NULL},
{"T_co2_PHX_out_od", (getter)Outputs_get_T_co2_PHX_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design PHX co2 outlet temperature [C]"),
 	NULL},
{"T_comp_in", (getter)Outputs_get_T_comp_in,(setter)0,
	PyDoc_STR("*float*: Compressor inlet temperature [C]"),
 	NULL},
{"T_htf_cold_des", (getter)Outputs_get_T_htf_cold_des,(setter)0,
	PyDoc_STR("*float*: HTF design cold temperature (PHX outlet) [C]"),
 	NULL},
{"T_htf_cold_od", (getter)Outputs_get_T_htf_cold_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design cold return temperature [C]"),
 	NULL},
{"T_htf_hot_od", (getter)Outputs_get_T_htf_hot_od,(setter)0,
	PyDoc_STR("*sequence*: HTF hot temperatures [C]"),
 	NULL},
{"T_main_cooler_data", (getter)Outputs_get_T_main_cooler_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along main cooler stream [C]"),
 	NULL},
{"T_mc_in_od", (getter)Outputs_get_T_mc_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design compressor inlet temperature [C]"),
 	NULL},
{"T_pre_cooler_data", (getter)Outputs_get_T_pre_cooler_data,(setter)0,
	PyDoc_STR("*sequence*: Temperature points along pre cooler stream [C]"),
 	NULL},
{"T_state_points", (getter)Outputs_get_T_state_points,(setter)0,
	PyDoc_STR("*sequence*: Cycle temperature state points [C]"),
 	NULL},
{"T_turb_in", (getter)Outputs_get_T_turb_in,(setter)0,
	PyDoc_STR("*float*: Turbine inlet temperature [C]"),
 	NULL},
{"UA_PHX", (getter)Outputs_get_UA_PHX,(setter)0,
	PyDoc_STR("*float*: PHX Conductance [MW/K]"),
 	NULL},
{"W_dot_net_less_cooling", (getter)Outputs_get_W_dot_net_less_cooling,(setter)0,
	PyDoc_STR("*float*: System power output subtracting cooling parastics [MWe,System Design Solution]"),
 	NULL},
{"W_dot_net_less_cooling_od", (getter)Outputs_get_W_dot_net_less_cooling_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design system output subtracting cooling parastics [MWe]"),
 	NULL},
{"W_dot_net_od", (getter)Outputs_get_W_dot_net_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design cycle net output (no cooling pars) [MWe]"),
 	NULL},
{"c_tot_W_dot", (getter)Outputs_get_c_tot_W_dot,(setter)0,
	PyDoc_STR("*float*: Compressor total summed power [MWe]"),
 	NULL},
{"c_tot_W_dot_od", (getter)Outputs_get_c_tot_W_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Compressor total off-design power [MWe]"),
 	NULL},
{"c_tot_cost_equip", (getter)Outputs_get_c_tot_cost_equip,(setter)0,
	PyDoc_STR("*float*: Compressor total cost [M$]"),
 	NULL},
{"cooler_tot_UA", (getter)Outputs_get_cooler_tot_UA,(setter)0,
	PyDoc_STR("*float*: Total cooler conductance [MW/K]"),
 	NULL},
{"cooler_tot_W_dot_fan", (getter)Outputs_get_cooler_tot_W_dot_fan,(setter)0,
	PyDoc_STR("*float*: Total cooler fan power [MWe]"),
 	NULL},
{"cooler_tot_W_dot_fan_od", (getter)Outputs_get_cooler_tot_W_dot_fan_od,(setter)0,
	PyDoc_STR("*sequence*: Intermediate pressure cooler fan power [MWe]"),
 	NULL},
{"cooler_tot_cost_bare_erected", (getter)Outputs_get_cooler_tot_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Total cooler cost equipment and install [M$]"),
 	NULL},
{"cooler_tot_cost_equipment", (getter)Outputs_get_cooler_tot_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Total cooler cost equipment [M$]"),
 	NULL},
{"cycle_cost", (getter)Outputs_get_cycle_cost,(setter)0,
	PyDoc_STR("*float*: Cycle cost bare erected [M$]"),
 	NULL},
{"cycle_spec_cost", (getter)Outputs_get_cycle_spec_cost,(setter)0,
	PyDoc_STR("*float*: Cycle specific cost bare erected [$/kWe]"),
 	NULL},
{"cycle_spec_cost_thermal", (getter)Outputs_get_cycle_spec_cost_thermal,(setter)0,
	PyDoc_STR("*float*: Cycle specific (thermal) cost bare erected [$/kWt]"),
 	NULL},
{"deltaT_HTF_PHX", (getter)Outputs_get_deltaT_HTF_PHX,(setter)0,
	PyDoc_STR("*float*: HTF temp difference across PHX [C]"),
 	NULL},
{"deltaT_HTF_PHX_od", (getter)Outputs_get_deltaT_HTF_PHX_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design HTF temp difference across PHX [C]"),
 	NULL},
{"diff_E_cycle", (getter)Outputs_get_diff_E_cycle,(setter)0,
	PyDoc_STR("*sequence*: Off-design cycle energy balance [-]"),
 	NULL},
{"diff_Q_HTR", (getter)Outputs_get_diff_Q_HTR,(setter)0,
	PyDoc_STR("*sequence*: Off-design HTR energy balance [-]"),
 	NULL},
{"diff_Q_LTR", (getter)Outputs_get_diff_Q_LTR,(setter)0,
	PyDoc_STR("*sequence*: Off-design LTR energy balance [-]"),
 	NULL},
{"diff_m_dot_od", (getter)Outputs_get_diff_m_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design mass flow rate balance [-]"),
 	NULL},
{"eff_HTR", (getter)Outputs_get_eff_HTR,(setter)0,
	PyDoc_STR("*float*: High temp recuperator effectiveness"),
 	NULL},
{"eff_HTR_od", (getter)Outputs_get_eff_HTR_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup effectiveness"),
 	NULL},
{"eff_LTR", (getter)Outputs_get_eff_LTR,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator effectiveness"),
 	NULL},
{"eff_LTR_od", (getter)Outputs_get_eff_LTR_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design low temp recup effectiveness"),
 	NULL},
{"eff_PHX", (getter)Outputs_get_eff_PHX,(setter)0,
	PyDoc_STR("*float*: PHX effectiveness"),
 	NULL},
{"eta_thermal_calc", (getter)Outputs_get_eta_thermal_calc,(setter)0,
	PyDoc_STR("*float*: Calculated cycle thermal efficiency [-]"),
 	NULL},
{"eta_thermal_net_less_cooling_des", (getter)Outputs_get_eta_thermal_net_less_cooling_des,(setter)0,
	PyDoc_STR("*float*: Calculated cycle thermal efficiency using W_dot_net_less_cooling [-]"),
 	NULL},
{"eta_thermal_net_less_cooling_od", (getter)Outputs_get_eta_thermal_net_less_cooling_od,(setter)0,
	PyDoc_STR("*sequence*: Calculated cycle thermal efficiency using W_dot_net_less_cooling [-]"),
 	NULL},
{"eta_thermal_od", (getter)Outputs_get_eta_thermal_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design cycle thermal efficiency"),
 	NULL},
{"h_mc_data", (getter)Outputs_get_h_mc_data,(setter)0,
	PyDoc_STR("*sequence*: Enthalpy points along main compression [kJ/kg]"),
 	NULL},
{"h_pc_data", (getter)Outputs_get_h_pc_data,(setter)0,
	PyDoc_STR("*sequence*: Enthalpy points along pre compression [kJ/kg]"),
 	NULL},
{"h_rc_data", (getter)Outputs_get_h_rc_data,(setter)0,
	PyDoc_STR("*sequence*: Enthalpy points along re compression [kJ/kg]"),
 	NULL},
{"h_state_points", (getter)Outputs_get_h_state_points,(setter)0,
	PyDoc_STR("*sequence*: Cycle enthalpy state points [kJ/kg]"),
 	NULL},
{"h_t_data", (getter)Outputs_get_h_t_data,(setter)0,
	PyDoc_STR("*sequence*: Enthalpy points along turbine expansion [kJ/kg]"),
 	NULL},
{"m_dot_co2_full", (getter)Outputs_get_m_dot_co2_full,(setter)0,
	PyDoc_STR("*float*: CO2 mass flow rate through HTR, PHX, turbine [kg/s]"),
 	NULL},
{"m_dot_co2_full_od", (getter)Outputs_get_m_dot_co2_full_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design mass flow rate through turbine [kg/s]"),
 	NULL},
{"m_dot_htf_des", (getter)Outputs_get_m_dot_htf_des,(setter)0,
	PyDoc_STR("*float*: HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_htf_fracs", (getter)Outputs_get_m_dot_htf_fracs,(setter)0,
	PyDoc_STR("*sequence*: Normalized mass flow rate"),
 	NULL},
{"mc_D", (getter)Outputs_get_mc_D,(setter)0,
	PyDoc_STR("*sequence*: Compressor stage diameters [m]"),
 	NULL},
{"mc_N_des", (getter)Outputs_get_mc_N_des,(setter)0,
	PyDoc_STR("*float*: Compressor design shaft speed [rpm]"),
 	NULL},
{"mc_N_od", (getter)Outputs_get_mc_N_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor speed [rpm]"),
 	NULL},
{"mc_N_od_perc", (getter)Outputs_get_mc_N_od_perc,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor speed relative to design [%]"),
 	NULL},
{"mc_T_out", (getter)Outputs_get_mc_T_out,(setter)0,
	PyDoc_STR("*float*: Compressor outlet temperature [C]"),
 	NULL},
{"mc_T_out_od", (getter)Outputs_get_mc_T_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor outlet temperature [C]"),
 	NULL},
{"mc_W_dot", (getter)Outputs_get_mc_W_dot,(setter)0,
	PyDoc_STR("*float*: Compressor power [MWe]"),
 	NULL},
{"mc_W_dot_od", (getter)Outputs_get_mc_W_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor power [MWe]"),
 	NULL},
{"mc_cooler_P_in", (getter)Outputs_get_mc_cooler_P_in,(setter)0,
	PyDoc_STR("*float*: Low pressure cross flow cooler inlet pressure [MPa]"),
 	NULL},
{"mc_cooler_T_in", (getter)Outputs_get_mc_cooler_T_in,(setter)0,
	PyDoc_STR("*float*: Low pressure cross flow cooler inlet temperature [C]"),
 	NULL},
{"mc_cooler_T_in_od", (getter)Outputs_get_mc_cooler_T_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design Low pressure cooler inlet temperature [C]"),
 	NULL},
{"mc_cooler_UA", (getter)Outputs_get_mc_cooler_UA,(setter)0,
	PyDoc_STR("*float*: Low pressure cross flow cooler conductance [MW/K]"),
 	NULL},
{"mc_cooler_W_dot_fan", (getter)Outputs_get_mc_cooler_W_dot_fan,(setter)0,
	PyDoc_STR("*float*: Low pressure cooler fan power [MWe]"),
 	NULL},
{"mc_cooler_W_dot_fan_od", (getter)Outputs_get_mc_cooler_W_dot_fan_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design Low pressure cooler fan power [MWe]"),
 	NULL},
{"mc_cooler_co2_deltaP_des", (getter)Outputs_get_mc_cooler_co2_deltaP_des,(setter)0,
	PyDoc_STR("*float*: Low pressure cooler co2 side design pressure drop [-]"),
 	NULL},
{"mc_cooler_co2_deltaP_od", (getter)Outputs_get_mc_cooler_co2_deltaP_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design Off-design low pressure cooler co2 side pressure drop [-]"),
 	NULL},
{"mc_cooler_cost_bare_erected", (getter)Outputs_get_mc_cooler_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Low pressure cooler cost equipment and install [M$]"),
 	NULL},
{"mc_cooler_cost_equipment", (getter)Outputs_get_mc_cooler_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Low pressure cooler cost equipment [M$]"),
 	NULL},
{"mc_cooler_in_isen_deltah_to_P_mc_out", (getter)Outputs_get_mc_cooler_in_isen_deltah_to_P_mc_out,(setter)0,
	PyDoc_STR("*float*: Low pressure cross flow cooler inlet isen enthalpy rise to mc outlet pressure [kJ/kg]"),
 	NULL},
{"mc_cooler_in_isen_deltah_to_P_mc_out_od", (getter)Outputs_get_mc_cooler_in_isen_deltah_to_P_mc_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design Low pressure cooler inlet isen enthalpy rise to mc outlet pressure [kJ/kg]"),
 	NULL},
{"mc_cooler_m_dot_co2", (getter)Outputs_get_mc_cooler_m_dot_co2,(setter)0,
	PyDoc_STR("*float*: Low pressure cross flow cooler CO2 mass flow rate [kg/s]"),
 	NULL},
{"mc_cooler_q_dot", (getter)Outputs_get_mc_cooler_q_dot,(setter)0,
	PyDoc_STR("*float*: Low pressure cooler heat transfer [MWt]"),
 	NULL},
{"mc_cooler_rho_in", (getter)Outputs_get_mc_cooler_rho_in,(setter)0,
	PyDoc_STR("*float*: Low pressure cross flow cooler inlet density [kg/m3]"),
 	NULL},
{"mc_cooler_rho_in_od", (getter)Outputs_get_mc_cooler_rho_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design Low pressure cooler inlet density [kg/m3]"),
 	NULL},
{"mc_cost_bare_erected", (getter)Outputs_get_mc_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Compressor cost equipment plus install [M$]"),
 	NULL},
{"mc_cost_equipment", (getter)Outputs_get_mc_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Compressor cost equipment [M$]"),
 	NULL},
{"mc_eta_od", (getter)Outputs_get_mc_eta_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor overall isentropic efficiency"),
 	NULL},
{"mc_eta_stages_des", (getter)Outputs_get_mc_eta_stages_des,(setter)0,
	PyDoc_STR("*sequence*: Compressor design stage isentropic efficiencies"),
 	NULL},
{"mc_eta_stages_od", (getter)Outputs_get_mc_eta_stages_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design main compressor stages isentropic efficiency [od run][stage]"),
 	NULL},
{"mc_f_bypass_od", (getter)Outputs_get_mc_f_bypass_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor bypass to cooler inlet [-]"),
 	NULL},
{"mc_ideal_spec_work", (getter)Outputs_get_mc_ideal_spec_work,(setter)0,
	PyDoc_STR("*float*: Compressor ideal spec work [kJ/kg]"),
 	NULL},
{"mc_ideal_spec_work_od", (getter)Outputs_get_mc_ideal_spec_work_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor ideal specific work [kJ/kg]"),
 	NULL},
{"mc_m_dot_des", (getter)Outputs_get_mc_m_dot_des,(setter)0,
	PyDoc_STR("*float*: Compressor mass flow rate [kg/s]"),
 	NULL},
{"mc_m_dot_od", (getter)Outputs_get_mc_m_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor mass flow [kg/s]"),
 	NULL},
{"mc_n_stages", (getter)Outputs_get_mc_n_stages,(setter)0,
	PyDoc_STR("*float*: Compressor stages"),
 	NULL},
{"mc_phi_des", (getter)Outputs_get_mc_phi_des,(setter)0,
	PyDoc_STR("*float*: Compressor design flow coefficient"),
 	NULL},
{"mc_phi_od", (getter)Outputs_get_mc_phi_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design main compressor flow coefficient [od run][stage]"),
 	NULL},
{"mc_phi_surge", (getter)Outputs_get_mc_phi_surge,(setter)0,
	PyDoc_STR("*float*: Compressor flow coefficient where surge occurs"),
 	NULL},
{"mc_psi_des", (getter)Outputs_get_mc_psi_des,(setter)0,
	PyDoc_STR("*float*: Compressor design ideal head coefficient"),
 	NULL},
{"mc_psi_max_at_N_des", (getter)Outputs_get_mc_psi_max_at_N_des,(setter)0,
	PyDoc_STR("*float*: Compressor max ideal head coefficient at design shaft speed"),
 	NULL},
{"mc_psi_od", (getter)Outputs_get_mc_psi_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design main compressor ideal head coefficient [od run][stage]"),
 	NULL},
{"mc_rho_in", (getter)Outputs_get_mc_rho_in,(setter)0,
	PyDoc_STR("*float*: Compressor inlet density [kg/m3]"),
 	NULL},
{"mc_rho_in_od", (getter)Outputs_get_mc_rho_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design main compressor inlet density [kg/m3]"),
 	NULL},
{"mc_tip_ratio_des", (getter)Outputs_get_mc_tip_ratio_des,(setter)0,
	PyDoc_STR("*sequence*: Compressor design stage tip speed ratio"),
 	NULL},
{"mc_tip_ratio_od", (getter)Outputs_get_mc_tip_ratio_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design main compressor tip speed ratio [od run][stage]"),
 	NULL},
{"od_code", (getter)Outputs_get_od_code,(setter)0,
	PyDoc_STR("*sequence*: Diagnostic info [-]"),
 	NULL},
{"pc_D", (getter)Outputs_get_pc_D,(setter)0,
	PyDoc_STR("*sequence*: Precompressor stage diameters [m]"),
 	NULL},
{"pc_N_des", (getter)Outputs_get_pc_N_des,(setter)0,
	PyDoc_STR("*float*: Precompressor design shaft speed [rpm]"),
 	NULL},
{"pc_N_od", (getter)Outputs_get_pc_N_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor shaft speed [rpm]"),
 	NULL},
{"pc_P_in_des", (getter)Outputs_get_pc_P_in_des,(setter)0,
	PyDoc_STR("*float*: Precompressor inlet pressure [MPa]"),
 	NULL},
{"pc_P_in_od", (getter)Outputs_get_pc_P_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor inlet pressure [MPa]"),
 	NULL},
{"pc_T_in_des", (getter)Outputs_get_pc_T_in_des,(setter)0,
	PyDoc_STR("*float*: Precompressor inlet temperature [C]"),
 	NULL},
{"pc_T_in_od", (getter)Outputs_get_pc_T_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor inlet temperature [C]"),
 	NULL},
{"pc_W_dot", (getter)Outputs_get_pc_W_dot,(setter)0,
	PyDoc_STR("*float*: Precompressor power [MWe]"),
 	NULL},
{"pc_W_dot_od", (getter)Outputs_get_pc_W_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor power [MWe]"),
 	NULL},
{"pc_cooler_P_in", (getter)Outputs_get_pc_cooler_P_in,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cross flow cooler inlet pressure [MPa]"),
 	NULL},
{"pc_cooler_T_in", (getter)Outputs_get_pc_cooler_T_in,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cross flow cooler inlet temperature [C]"),
 	NULL},
{"pc_cooler_UA", (getter)Outputs_get_pc_cooler_UA,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cross flow cooler conductance [MW/K]"),
 	NULL},
{"pc_cooler_W_dot_fan", (getter)Outputs_get_pc_cooler_W_dot_fan,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cooler fan power [MWe]"),
 	NULL},
{"pc_cooler_W_dot_fan_od", (getter)Outputs_get_pc_cooler_W_dot_fan_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design Intermediate pressure cooler fan power [MWe]"),
 	NULL},
{"pc_cooler_cost_bare_erected", (getter)Outputs_get_pc_cooler_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cooler cost equipment and install [M$]"),
 	NULL},
{"pc_cooler_cost_equipment", (getter)Outputs_get_pc_cooler_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cooler cost equipment [M$]"),
 	NULL},
{"pc_cooler_m_dot_co2", (getter)Outputs_get_pc_cooler_m_dot_co2,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cross flow cooler CO2 mass flow rate [kg/s]"),
 	NULL},
{"pc_cooler_q_dot", (getter)Outputs_get_pc_cooler_q_dot,(setter)0,
	PyDoc_STR("*float*: Intermediate pressure cooler heat transfer [MWt]"),
 	NULL},
{"pc_cost_bare_erected", (getter)Outputs_get_pc_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Precompressor cost equipment plus install [M$]"),
 	NULL},
{"pc_cost_equipment", (getter)Outputs_get_pc_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Precompressor cost equipment [M$]"),
 	NULL},
{"pc_eta_od", (getter)Outputs_get_pc_eta_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor overal isentropic efficiency"),
 	NULL},
{"pc_eta_stages_des", (getter)Outputs_get_pc_eta_stages_des,(setter)0,
	PyDoc_STR("*sequence*: Precompressor design stage isenstropic efficiencies"),
 	NULL},
{"pc_eta_stages_od", (getter)Outputs_get_pc_eta_stages_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design precompressor stages isentropic efficiency [od run][stage]"),
 	NULL},
{"pc_f_bypass_od", (getter)Outputs_get_pc_f_bypass_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor bypass to cooler inlet [-]"),
 	NULL},
{"pc_ideal_spec_work_des", (getter)Outputs_get_pc_ideal_spec_work_des,(setter)0,
	PyDoc_STR("*float*: Precompressor ideal spec work [kJ/kg]"),
 	NULL},
{"pc_ideal_spec_work_od", (getter)Outputs_get_pc_ideal_spec_work_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor ideal spec work [kJ/kg]"),
 	NULL},
{"pc_m_dot_des", (getter)Outputs_get_pc_m_dot_des,(setter)0,
	PyDoc_STR("*float*: Precompressor mass flow rate [kg/s]"),
 	NULL},
{"pc_m_dot_od", (getter)Outputs_get_pc_m_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor mass flow [kg/s]"),
 	NULL},
{"pc_n_stages", (getter)Outputs_get_pc_n_stages,(setter)0,
	PyDoc_STR("*float*: Precompressor stages"),
 	NULL},
{"pc_phi_des", (getter)Outputs_get_pc_phi_des,(setter)0,
	PyDoc_STR("*float*: Precompressor design flow coefficient"),
 	NULL},
{"pc_phi_od", (getter)Outputs_get_pc_phi_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design precompressor flow coefficient [od run][stage] [-]"),
 	NULL},
{"pc_phi_surge", (getter)Outputs_get_pc_phi_surge,(setter)0,
	PyDoc_STR("*float*: Precompressor flow coefficient where surge occurs"),
 	NULL},
{"pc_rho_in_des", (getter)Outputs_get_pc_rho_in_des,(setter)0,
	PyDoc_STR("*float*: Precompressor inlet density [kg/m3]"),
 	NULL},
{"pc_rho_in_od", (getter)Outputs_get_pc_rho_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design precompressor inlet density [kg/m3]"),
 	NULL},
{"pc_tip_ratio_des", (getter)Outputs_get_pc_tip_ratio_des,(setter)0,
	PyDoc_STR("*sequence*: Precompressor design stage tip speed ratio"),
 	NULL},
{"pc_tip_ratio_od", (getter)Outputs_get_pc_tip_ratio_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design precompressor tip speed ratio [od run][stage] [-]"),
 	NULL},
{"phx_co2_deltaP_od", (getter)Outputs_get_phx_co2_deltaP_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design PHX co2 side pressure drop [-]"),
 	NULL},
{"phx_eff_od", (getter)Outputs_get_phx_eff_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design PHX effectiveness [-]"),
 	NULL},
{"piping_inventory_etc_cost", (getter)Outputs_get_piping_inventory_etc_cost,(setter)0,
	PyDoc_STR("*float*: Cost of remaining cycle equipment on BEC basis [M$]"),
 	NULL},
{"q_dot_HTR", (getter)Outputs_get_q_dot_HTR,(setter)0,
	PyDoc_STR("*float*: High temp recuperator heat transfer [MWt]"),
 	NULL},
{"q_dot_HTR_od", (getter)Outputs_get_q_dot_HTR_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design high temp recup heat transfer [MWt]"),
 	NULL},
{"q_dot_LTR", (getter)Outputs_get_q_dot_LTR,(setter)0,
	PyDoc_STR("*float*: Low temp recuperator heat transfer [MWt]"),
 	NULL},
{"q_dot_LTR_od", (getter)Outputs_get_q_dot_LTR_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design low temp recup heat transfer [MWt]"),
 	NULL},
{"q_dot_PHX", (getter)Outputs_get_q_dot_PHX,(setter)0,
	PyDoc_STR("*float*: PHX heat transfer [MWt]"),
 	NULL},
{"rc_D", (getter)Outputs_get_rc_D,(setter)0,
	PyDoc_STR("*sequence*: Recompressor stage diameters [m]"),
 	NULL},
{"rc_N_des", (getter)Outputs_get_rc_N_des,(setter)0,
	PyDoc_STR("*float*: Recompressor design shaft speed [rpm]"),
 	NULL},
{"rc_N_od", (getter)Outputs_get_rc_N_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor shaft speed [rpm]"),
 	NULL},
{"rc_N_od_perc", (getter)Outputs_get_rc_N_od_perc,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor shaft speed relative to design [%]"),
 	NULL},
{"rc_P_in_des", (getter)Outputs_get_rc_P_in_des,(setter)0,
	PyDoc_STR("*float*: Recompressor inlet pressure [MPa]"),
 	NULL},
{"rc_P_in_od", (getter)Outputs_get_rc_P_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor inlet pressure [MPa]"),
 	NULL},
{"rc_P_out_des", (getter)Outputs_get_rc_P_out_des,(setter)0,
	PyDoc_STR("*float*: Recompressor inlet pressure [MPa]"),
 	NULL},
{"rc_P_out_od", (getter)Outputs_get_rc_P_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor outlet pressure [MPa]"),
 	NULL},
{"rc_T_in_des", (getter)Outputs_get_rc_T_in_des,(setter)0,
	PyDoc_STR("*float*: Recompressor inlet temperature [C]"),
 	NULL},
{"rc_T_in_od", (getter)Outputs_get_rc_T_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor inlet temperature [C]"),
 	NULL},
{"rc_T_out_des", (getter)Outputs_get_rc_T_out_des,(setter)0,
	PyDoc_STR("*float*: Recompressor inlet temperature [C]"),
 	NULL},
{"rc_T_out_od", (getter)Outputs_get_rc_T_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor outlet temperature [C]"),
 	NULL},
{"rc_W_dot", (getter)Outputs_get_rc_W_dot,(setter)0,
	PyDoc_STR("*float*: Recompressor power [MWe]"),
 	NULL},
{"rc_W_dot_od", (getter)Outputs_get_rc_W_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor power [MWe]"),
 	NULL},
{"rc_cost_bare_erected", (getter)Outputs_get_rc_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Recompressor cost equipment plus install [M$]"),
 	NULL},
{"rc_cost_equipment", (getter)Outputs_get_rc_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Recompressor cost equipment [M$]"),
 	NULL},
{"rc_eta_od", (getter)Outputs_get_rc_eta_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor overal isentropic efficiency"),
 	NULL},
{"rc_eta_stages_des", (getter)Outputs_get_rc_eta_stages_des,(setter)0,
	PyDoc_STR("*sequence*: Recompressor design stage isenstropic efficiencies"),
 	NULL},
{"rc_eta_stages_od", (getter)Outputs_get_rc_eta_stages_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design recompressor stages isentropic efficiency [od run][stage]"),
 	NULL},
{"rc_m_dot_des", (getter)Outputs_get_rc_m_dot_des,(setter)0,
	PyDoc_STR("*float*: Recompressor mass flow rate [kg/s]"),
 	NULL},
{"rc_m_dot_od", (getter)Outputs_get_rc_m_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design recompressor mass flow [kg/s]"),
 	NULL},
{"rc_n_stages", (getter)Outputs_get_rc_n_stages,(setter)0,
	PyDoc_STR("*float*: Recompressor stages"),
 	NULL},
{"rc_phi_des", (getter)Outputs_get_rc_phi_des,(setter)0,
	PyDoc_STR("*float*: Recompressor design flow coefficient"),
 	NULL},
{"rc_phi_od", (getter)Outputs_get_rc_phi_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design recompressor flow coefficients [od run][stage] [-]"),
 	NULL},
{"rc_phi_surge", (getter)Outputs_get_rc_phi_surge,(setter)0,
	PyDoc_STR("*float*: Recompressor flow coefficient where surge occurs"),
 	NULL},
{"rc_psi_des", (getter)Outputs_get_rc_psi_des,(setter)0,
	PyDoc_STR("*float*: Recompressor design ideal head coefficient"),
 	NULL},
{"rc_psi_max_at_N_des", (getter)Outputs_get_rc_psi_max_at_N_des,(setter)0,
	PyDoc_STR("*float*: Recompressor max ideal head coefficient at design shaft speed"),
 	NULL},
{"rc_psi_od", (getter)Outputs_get_rc_psi_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design recompressor ideal head coefficient [od run][stage] [-]"),
 	NULL},
{"rc_tip_ratio_des", (getter)Outputs_get_rc_tip_ratio_des,(setter)0,
	PyDoc_STR("*sequence*: Recompressor design stage tip speed ratio"),
 	NULL},
{"rc_tip_ratio_od", (getter)Outputs_get_rc_tip_ratio_od,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Off-design recompressor tip speed ratio [od run][stage] [-]"),
 	NULL},
{"recomp_frac", (getter)Outputs_get_recomp_frac,(setter)0,
	PyDoc_STR("*float*: Recompression fraction [-]"),
 	NULL},
{"recomp_frac_od", (getter)Outputs_get_recomp_frac_od,(setter)0,
	PyDoc_STR("*sequence*: Recompression fractions"),
 	NULL},
{"recup_LTR_UA_frac", (getter)Outputs_get_recup_LTR_UA_frac,(setter)0,
	PyDoc_STR("*float*: Fraction of total conductance to LTR"),
 	NULL},
{"recup_total_UA_assigned", (getter)Outputs_get_recup_total_UA_assigned,(setter)0,
	PyDoc_STR("*float*: Total recuperator UA assigned to design routine [MW/K]"),
 	NULL},
{"recup_total_UA_calculated", (getter)Outputs_get_recup_total_UA_calculated,(setter)0,
	PyDoc_STR("*float*: Total recuperator UA calculated considering max eff and/or min temp diff parameter [MW/K]"),
 	NULL},
{"recup_total_cost_bare_erected", (getter)Outputs_get_recup_total_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Total recuperator cost bare erected [M$]"),
 	NULL},
{"recup_total_cost_equipment", (getter)Outputs_get_recup_total_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Total recuperator cost equipment [M$]"),
 	NULL},
{"s_HTR_HP_data", (getter)Outputs_get_s_HTR_HP_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along HTR HP stream [kJ/kg-K]"),
 	NULL},
{"s_HTR_LP_data", (getter)Outputs_get_s_HTR_LP_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along HTR LP stream [kJ/kg-K]"),
 	NULL},
{"s_LTR_HP_data", (getter)Outputs_get_s_LTR_HP_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along LTR HP stream [kJ/kg-K]"),
 	NULL},
{"s_LTR_LP_data", (getter)Outputs_get_s_LTR_LP_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along LTR LP stream [kJ/kg-K]"),
 	NULL},
{"s_PHX_data", (getter)Outputs_get_s_PHX_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along PHX stream [kJ/kg-K]"),
 	NULL},
{"s_main_cooler_data", (getter)Outputs_get_s_main_cooler_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along main cooler stream [kJ/kg-K]"),
 	NULL},
{"s_pre_cooler_data", (getter)Outputs_get_s_pre_cooler_data,(setter)0,
	PyDoc_STR("*sequence*: Entropy points along pre cooler stream [kJ/kg-K]"),
 	NULL},
{"s_state_points", (getter)Outputs_get_s_state_points,(setter)0,
	PyDoc_STR("*sequence*: Cycle entropy state points [kJ/kg-K]"),
 	NULL},
{"sim_time_od", (getter)Outputs_get_sim_time_od,(setter)0,
	PyDoc_STR("*sequence*: Simulation time for off design optimization [s]"),
 	NULL},
{"t_D", (getter)Outputs_get_t_D,(setter)0,
	PyDoc_STR("*float*: Turbine diameter [m]"),
 	NULL},
{"t_N_des", (getter)Outputs_get_t_N_des,(setter)0,
	PyDoc_STR("*float*: Turbine design shaft speed [rpm]"),
 	NULL},
{"t_N_od", (getter)Outputs_get_t_N_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine shaft speed [rpm]"),
 	NULL},
{"t_P_in_des", (getter)Outputs_get_t_P_in_des,(setter)0,
	PyDoc_STR("*float*: Turbine design inlet pressure [MPa]"),
 	NULL},
{"t_P_in_od", (getter)Outputs_get_t_P_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine inlet pressure [MPa]"),
 	NULL},
{"t_P_out_des", (getter)Outputs_get_t_P_out_des,(setter)0,
	PyDoc_STR("*float*: Turbine design outlet pressure [MPa]"),
 	NULL},
{"t_P_out_od", (getter)Outputs_get_t_P_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine outlet pressure [MPa]"),
 	NULL},
{"t_T_out_des", (getter)Outputs_get_t_T_out_des,(setter)0,
	PyDoc_STR("*float*: Turbine outlet temperature [C]"),
 	NULL},
{"t_T_out_od", (getter)Outputs_get_t_T_out_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine outlet temperature [C]"),
 	NULL},
{"t_W_dot", (getter)Outputs_get_t_W_dot,(setter)0,
	PyDoc_STR("*float*: Turbine power [MWe]"),
 	NULL},
{"t_W_dot_od", (getter)Outputs_get_t_W_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine power [MWe]"),
 	NULL},
{"t_cost_bare_erected", (getter)Outputs_get_t_cost_bare_erected,(setter)0,
	PyDoc_STR("*float*: Tubine cost - equipment plus install [M$]"),
 	NULL},
{"t_cost_equipment", (getter)Outputs_get_t_cost_equipment,(setter)0,
	PyDoc_STR("*float*: Tubine cost - equipment [M$]"),
 	NULL},
{"t_delta_h_isen_des", (getter)Outputs_get_t_delta_h_isen_des,(setter)0,
	PyDoc_STR("*float*: Turbine isentropic specific work [kJ/kg]"),
 	NULL},
{"t_delta_h_isen_od", (getter)Outputs_get_t_delta_h_isen_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine isentropic specific work [kg/s]"),
 	NULL},
{"t_eta_od", (getter)Outputs_get_t_eta_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine efficiency [-]"),
 	NULL},
{"t_m_dot_des", (getter)Outputs_get_t_m_dot_des,(setter)0,
	PyDoc_STR("*float*: Turbine mass flow rate [kg/s]"),
 	NULL},
{"t_m_dot_od", (getter)Outputs_get_t_m_dot_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine mass flow rate [kg/s]"),
 	NULL},
{"t_nu_des", (getter)Outputs_get_t_nu_des,(setter)0,
	PyDoc_STR("*float*: Turbine design velocity ratio"),
 	NULL},
{"t_nu_od", (getter)Outputs_get_t_nu_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine velocity ratio [-]"),
 	NULL},
{"t_rho_in_des", (getter)Outputs_get_t_rho_in_des,(setter)0,
	PyDoc_STR("*float*: Turbine inlet density [kg/m3]"),
 	NULL},
{"t_rho_in_od", (getter)Outputs_get_t_rho_in_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine inlet density [kg/m3]"),
 	NULL},
{"t_tip_ratio_des", (getter)Outputs_get_t_tip_ratio_des,(setter)0,
	PyDoc_STR("*float*: Turbine design tip speed ratio"),
 	NULL},
{"t_tip_ratio_od", (getter)Outputs_get_t_tip_ratio_od,(setter)0,
	PyDoc_STR("*sequence*: Off-design turbine tip speed ratio [-]"),
 	NULL},
{"udpc_n_T_amb", (getter)Outputs_get_udpc_n_T_amb,(setter)0,
	PyDoc_STR("*float*: Number of ambient temperature values in udpc parametric"),
 	NULL},
{"udpc_n_T_htf", (getter)Outputs_get_udpc_n_T_htf,(setter)0,
	PyDoc_STR("*float*: Number of HTF temperature values in udpc parametric"),
 	NULL},
{"udpc_n_m_dot_htf", (getter)Outputs_get_udpc_n_m_dot_htf,(setter)0,
	PyDoc_STR("*float*: Number of HTF mass flow rate values in udpc parameteric"),
 	NULL},
{"udpc_table", (getter)Outputs_get_udpc_table,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Columns (7): HTF Temp [C], HTF ND mass flow [-], Ambient Temp [C], ND Power, ND Heat In, ND Fan Power, ND Water. Rows = runs"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem.Outputs",             /*tp_name*/
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
 * Sco2CspSystem
 */

static PyTypeObject Sco2CspSystem_Type;

static CmodObject *
newSco2CspSystemObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Sco2CspSystem_Type);

	PySAM_TECH_ATTR()

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* HeatExchangerDesign_obj = HeatExchangerDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "HeatExchangerDesign", HeatExchangerDesign_obj);
	Py_DECREF(HeatExchangerDesign_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* PHXDesign_obj = PHXDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PHXDesign", PHXDesign_obj);
	Py_DECREF(PHXDesign_obj);

	PyObject* AirCoolerDesign_obj = AirCoolerDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AirCoolerDesign", AirCoolerDesign_obj);
	Py_DECREF(AirCoolerDesign_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Sco2CspSystem methods */

static void
Sco2CspSystem_dealloc(CmodObject *self)
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
Sco2CspSystem_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
Sco2CspSystem_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Sco2CspSystem_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Sco2CspSystem_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2CspSystem"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Sco2CspSystem_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Sco2CspSystem"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Sco2CspSystem_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Sco2CspSystem_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Sco2CspSystem_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Sco2CspSystem_methods[] = {
		{"execute",           (PyCFunction)Sco2CspSystem_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Sco2CspSystem_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'System Design': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Sco2CspSystem_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'System Design': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Sco2CspSystem_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Sco2CspSystem_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Sco2CspSystem_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)Sco2CspSystem_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Sco2CspSystem_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Sco2CspSystem_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Sco2CspSystem_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Sco2CspSystem",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Sco2CspSystem_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Sco2CspSystem_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Sco2CspSystem_getattro, /*tp_getattro*/
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
		Sco2CspSystem_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Sco2CspSystem object */

static PyObject *
Sco2CspSystem_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSco2CspSystemObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2CspSystem_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2CspSystemObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Sco2CspSystem_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSco2CspSystemObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2CspSystem", def) < 0) {
		Sco2CspSystem_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Sco2CspSystem_from_existing(PyObject *self, PyObject *args)
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

	rv = newSco2CspSystemObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Sco2CspSystem", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Sco2CspSystemModule_methods[] = {
		{"new",             Sco2CspSystem_new,         METH_VARARGS,
				PyDoc_STR("new() -> Sco2CspSystem")},
		{"default",             Sco2CspSystem_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Sco2CspSystem\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Sco2CspSystem_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Sco2CspSystem\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Sco2CspSystem_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Sco2CspSystem\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Supercritical CO2 Power Cycle Design and Off-Design Simulation");


static int
Sco2CspSystemModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Sco2CspSystem_Type.tp_dict = PyDict_New();
	if (!Sco2CspSystem_Type.tp_dict) { goto fail; }

	/// Add the SystemDesign type object to Sco2CspSystem_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CspSystem_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the HeatExchangerDesign type object to Sco2CspSystem_Type
	if (PyType_Ready(&HeatExchangerDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CspSystem_Type.tp_dict,
				"HeatExchangerDesign",
				(PyObject*)&HeatExchangerDesign_Type);
	Py_DECREF(&HeatExchangerDesign_Type);

	/// Add the Common type object to Sco2CspSystem_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CspSystem_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the PHXDesign type object to Sco2CspSystem_Type
	if (PyType_Ready(&PHXDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CspSystem_Type.tp_dict,
				"PHXDesign",
				(PyObject*)&PHXDesign_Type);
	Py_DECREF(&PHXDesign_Type);

	/// Add the AirCoolerDesign type object to Sco2CspSystem_Type
	if (PyType_Ready(&AirCoolerDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CspSystem_Type.tp_dict,
				"AirCoolerDesign",
				(PyObject*)&AirCoolerDesign_Type);
	Py_DECREF(&AirCoolerDesign_Type);

	/// Add the Outputs type object to Sco2CspSystem_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Sco2CspSystem_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Sco2CspSystem type object to the module
	if (PyType_Ready(&Sco2CspSystem_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Sco2CspSystem",
				(PyObject*)&Sco2CspSystem_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Sco2CspSystemModule_slots[] = {
		{Py_mod_exec, Sco2CspSystemModule_exec},
		{0, NULL},
};

static struct PyModuleDef Sco2CspSystemModule = {
		PyModuleDef_HEAD_INIT,
		"Sco2CspSystem",
		module_doc,
		0,
		Sco2CspSystemModule_methods,
		Sco2CspSystemModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Sco2CspSystem(void)
{
	return PyModuleDef_Init(&Sco2CspSystemModule);
}