#include <Python.h>

#include <SAM_FresnelPhysical.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SystemControl Group
 */ 

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = SystemControl_Type.tp_alloc(&SystemControl_Type,0);

	VarGroupObject* SystemControl_obj = (VarGroupObject*)new_obj;

	SystemControl_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemControl methods */

static PyObject *
SystemControl_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemControl_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemControl_methods[] = {
		{"assign",            (PyCFunction)SystemControl_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemControl_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemControl_get_disp_inventory_incentive(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemControl_disp_inventory_incentive_nget, self->data_ptr);
}

static int
SystemControl_set_disp_inventory_incentive(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemControl_disp_inventory_incentive_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_sim_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemControl_sim_type_nget, self->data_ptr);
}

static int
SystemControl_set_sim_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemControl_sim_type_nset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"disp_inventory_incentive", (getter)SystemControl_get_disp_inventory_incentive,(setter)SystemControl_set_disp_inventory_incentive,
	PyDoc_STR("*float*: Dispatch storage terminal inventory incentive multiplier\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sim_type", (getter)SystemControl_get_sim_type,(setter)SystemControl_set_sim_type,
	PyDoc_STR("*float*: 1 (default): timeseries, 2: design only\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.SystemControl",             /*tp_name*/
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
		SystemControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemControl_getset,          /*tp_getset*/
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
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = Weather_Type.tp_alloc(&Weather_Type,0);

	VarGroupObject* Weather_obj = (VarGroupObject*)new_obj;

	Weather_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Weather methods */

static PyObject *
Weather_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Weather_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Weather_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Weather_methods[] = {
		{"assign",            (PyCFunction)Weather_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Weather_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Weather_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Weather_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_FresnelPhysical_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_FresnelPhysical_Weather_file_name_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: Local weather file with path [none]\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.Weather",             /*tp_name*/
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
		Weather_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Weather_getset,          /*tp_getset*/
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
 * SystemDesign Group
 */ 

static PyTypeObject SystemDesign_Type;

static PyObject *
SystemDesign_new(SAM_FresnelPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "SystemDesign")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "SystemDesign")){
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
SystemDesign_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_I_bn_des_nget, self->data_ptr);
}

static int
SystemDesign_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_I_bn_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_P_ref_nget, self->data_ptr);
}

static int
SystemDesign_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_P_ref_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_loop_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_T_loop_in_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_loop_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_T_loop_out_nget, self->data_ptr);
}

static int
SystemDesign_set_T_loop_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_T_loop_out_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_eta_ref_nget, self->data_ptr);
}

static int
SystemDesign_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_eta_ref_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gross_net_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_gross_net_conversion_factor_nget, self->data_ptr);
}

static int
SystemDesign_set_gross_net_conversion_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_gross_net_conversion_factor_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_solar_mult_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_solar_mult_in_nget, self->data_ptr);
}

static int
SystemDesign_set_solar_mult_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_solar_mult_in_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_solar_mult_or_Ap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_solar_mult_or_Ap_nget, self->data_ptr);
}

static int
SystemDesign_set_solar_mult_or_Ap(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_solar_mult_or_Ap_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_total_Ap_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_total_Ap_in_nget, self->data_ptr);
}

static int
SystemDesign_set_total_Ap_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_total_Ap_in_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SystemDesign_tshours_nget, self->data_ptr);
}

static int
SystemDesign_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SystemDesign_tshours_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"I_bn_des", (getter)SystemDesign_get_I_bn_des,(setter)SystemDesign_set_I_bn_des,
	PyDoc_STR("*float*: Solar irradiation at design [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"P_ref", (getter)SystemDesign_get_P_ref,(setter)SystemDesign_set_P_ref,
	PyDoc_STR("*float*: Design Turbine Net Output [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_in_des", (getter)SystemDesign_get_T_loop_in_des,(setter)SystemDesign_set_T_loop_in_des,
	PyDoc_STR("*float*: Design loop inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_out", (getter)SystemDesign_get_T_loop_out,(setter)SystemDesign_set_T_loop_out,
	PyDoc_STR("*float*: Target loop outlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_ref", (getter)SystemDesign_get_eta_ref,(setter)SystemDesign_set_eta_ref,
	PyDoc_STR("*float*: Cycle thermal efficiency at design point [-]\n\n**Required:**\nTrue"),
 	NULL},
{"gross_net_conversion_factor", (getter)SystemDesign_get_gross_net_conversion_factor,(setter)SystemDesign_set_gross_net_conversion_factor,
	PyDoc_STR("*float*: Estimated gross to net conversion factor\n\n**Required:**\nTrue"),
 	NULL},
{"solar_mult_in", (getter)SystemDesign_get_solar_mult_in,(setter)SystemDesign_set_solar_mult_in,
	PyDoc_STR("*float*: Solar multiple Input\n\n**Required:**\nTrue"),
 	NULL},
{"solar_mult_or_Ap", (getter)SystemDesign_get_solar_mult_or_Ap,(setter)SystemDesign_set_solar_mult_or_Ap,
	PyDoc_STR("*float*: Design using specified solar mult or field aperture [m3]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"total_Ap_in", (getter)SystemDesign_get_total_Ap_in,(setter)SystemDesign_set_total_Ap_in,
	PyDoc_STR("*float*: Field aperture Input [m3]\n\n**Required:**\nTrue"),
 	NULL},
{"tshours", (getter)SystemDesign_get_tshours,(setter)SystemDesign_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.SystemDesign",             /*tp_name*/
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
 * SolarField Group
 */ 

static PyTypeObject SolarField_Type;

static PyObject *
SolarField_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = SolarField_Type.tp_alloc(&SolarField_Type,0);

	VarGroupObject* SolarField_obj = (VarGroupObject*)new_obj;

	SolarField_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarField methods */

static PyObject *
SolarField_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarField_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarField_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarField_methods[] = {
		{"assign",            (PyCFunction)SolarField_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarField_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarField_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarField_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarField_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarField_get_FieldConfig(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_FieldConfig_nget, self->data_ptr);
}

static int
SolarField_set_FieldConfig(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_FieldConfig_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_Fluid_nget, self->data_ptr);
}

static int
SolarField_set_Fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_Fluid_nset, self->data_ptr);
}

static PyObject *
SolarField_get_HDR_rough(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_HDR_rough_nget, self->data_ptr);
}

static int
SolarField_set_HDR_rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_HDR_rough_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_rnr_pb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_L_rnr_pb_nget, self->data_ptr);
}

static int
SolarField_set_L_rnr_pb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_L_rnr_pb_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_Pipe_hl_coef_nget, self->data_ptr);
}

static int
SolarField_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
SolarField_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_SCA_drives_elec_nget, self->data_ptr);
}

static int
SolarField_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_amb_sf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_T_amb_sf_des_nget, self->data_ptr);
}

static int
SolarField_set_T_amb_sf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_T_amb_sf_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_T_fp_nget, self->data_ptr);
}

static int
SolarField_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_T_fp_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_T_startup_nget, self->data_ptr);
}

static int
SolarField_set_T_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_T_startup_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_V_hdr_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_V_hdr_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_V_hdr_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_V_hdr_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_wind_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_V_wind_des_nget, self->data_ptr);
}

static int
SolarField_set_V_wind_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_V_wind_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_eta_pump_nget, self->data_ptr);
}

static int
SolarField_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_eta_pump_nset, self->data_ptr);
}

static PyObject *
SolarField_get_f_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_f_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_f_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_f_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_f_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_f_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_f_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_f_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_SolarField_field_fl_props_mget, self->data_ptr);
}

static int
SolarField_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_SolarField_field_fl_props_mset, self->data_ptr);
}

static PyObject *
SolarField_get_land_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_land_mult_nget, self->data_ptr);
}

static int
SolarField_set_land_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_land_mult_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_m_dot_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_m_dot_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_m_dot_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_m_dot_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_mc_bal_cold_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_mc_bal_cold_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_mc_bal_hot_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_mc_bal_hot_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_sca(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_mc_bal_sca_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_sca(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_mc_bal_sca_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nMod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_nMod_nget, self->data_ptr);
}

static int
SolarField_set_nMod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_nMod_nset, self->data_ptr);
}

static PyObject *
SolarField_get_p_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_p_start_nget, self->data_ptr);
}

static int
SolarField_set_p_start(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_p_start_nset, self->data_ptr);
}

static PyObject *
SolarField_get_rec_htf_vol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_rec_htf_vol_nget, self->data_ptr);
}

static int
SolarField_set_rec_htf_vol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_rec_htf_vol_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_theta_dep_nget, self->data_ptr);
}

static int
SolarField_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_theta_dep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_theta_stow_nget, self->data_ptr);
}

static int
SolarField_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_theta_stow_nset, self->data_ptr);
}

static PyObject *
SolarField_get_use_abs_or_rel_mdot_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_use_abs_or_rel_mdot_limit_nget, self->data_ptr);
}

static int
SolarField_set_use_abs_or_rel_mdot_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_use_abs_or_rel_mdot_limit_nset, self->data_ptr);
}

static PyObject *
SolarField_get_washes_per_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_washes_per_year_nget, self->data_ptr);
}

static int
SolarField_set_washes_per_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_washes_per_year_nset, self->data_ptr);
}

static PyObject *
SolarField_get_water_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SolarField_water_per_wash_nget, self->data_ptr);
}

static int
SolarField_set_water_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SolarField_water_per_wash_nset, self->data_ptr);
}

static PyGetSetDef SolarField_getset[] = {
{"FieldConfig", (getter)SolarField_get_FieldConfig,(setter)SolarField_set_FieldConfig,
	PyDoc_STR("*float*: Number of subfield headers\n\n**Required:**\nTrue"),
 	NULL},
{"Fluid", (getter)SolarField_get_Fluid,(setter)SolarField_set_Fluid,
	PyDoc_STR("*float*: Field HTF fluid number\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"HDR_rough", (getter)SolarField_get_HDR_rough,(setter)SolarField_set_HDR_rough,
	PyDoc_STR("*float*: Header pipe roughness [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_rnr_pb", (getter)SolarField_get_L_rnr_pb,(setter)SolarField_set_L_rnr_pb,
	PyDoc_STR("*float*: Length of runner pipe in power block [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Pipe_hl_coef", (getter)SolarField_get_Pipe_hl_coef,(setter)SolarField_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header - runner pipe - and non-HCE piping [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
{"SCA_drives_elec", (getter)SolarField_get_SCA_drives_elec,(setter)SolarField_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power in Watts per SCA drive [W/module]\n\n**Required:**\nTrue"),
 	NULL},
{"T_amb_sf_des", (getter)SolarField_get_T_amb_sf_des,(setter)SolarField_set_T_amb_sf_des,
	PyDoc_STR("*float*: Ambient design-point temperature for the solar field [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_fp", (getter)SolarField_get_T_fp,(setter)SolarField_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_startup", (getter)SolarField_get_T_startup,(setter)SolarField_set_T_startup,
	PyDoc_STR("*float*: Power block startup temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_max", (getter)SolarField_get_V_hdr_max,(setter)SolarField_set_V_hdr_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the header at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_min", (getter)SolarField_get_V_hdr_min,(setter)SolarField_set_V_hdr_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the header at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_wind_des", (getter)SolarField_get_V_wind_des,(setter)SolarField_set_V_wind_des,
	PyDoc_STR("*float*: Design-point wind velocity [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)SolarField_get_eta_pump,(setter)SolarField_set_eta_pump,
	PyDoc_STR("*float*: HTF pump efficiency\n\n**Required:**\nTrue"),
 	NULL},
{"f_htfmax", (getter)SolarField_get_f_htfmax,(setter)SolarField_set_f_htfmax,
	PyDoc_STR("*float*: Maximum loop mass flow rate fraction of design\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=1"),
 	NULL},
{"f_htfmin", (getter)SolarField_get_f_htfmin,(setter)SolarField_set_f_htfmin,
	PyDoc_STR("*float*: Minimum loop mass flow rate fraction of design\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=1"),
 	NULL},
{"field_fl_props", (getter)SolarField_get_field_fl_props,(setter)SolarField_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: Fluid property data\n\n**Required:**\nTrue"),
 	NULL},
{"land_mult", (getter)SolarField_get_land_mult,(setter)SolarField_set_land_mult,
	PyDoc_STR("*float*: Non-solar field land area multiplier [-]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htfmax", (getter)SolarField_get_m_dot_htfmax,(setter)SolarField_set_m_dot_htfmax,
	PyDoc_STR("*float*: Maximum loop HTF flow rate [kg/s]\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=0"),
 	NULL},
{"m_dot_htfmin", (getter)SolarField_get_m_dot_htfmin,(setter)SolarField_set_m_dot_htfmin,
	PyDoc_STR("*float*: Minimum loop HTF flow rate [kg/s]\n\n**Required:**\nRequired if use_abs_or_rel_mdot_limit=0"),
 	NULL},
{"mc_bal_cold", (getter)SolarField_get_mc_bal_cold,(setter)SolarField_set_mc_bal_cold,
	PyDoc_STR("*float*: The heat capacity of the balance of plant on the cold side [kWht/K-MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_hot", (getter)SolarField_get_mc_bal_hot,(setter)SolarField_set_mc_bal_hot,
	PyDoc_STR("*float*: The heat capacity of the balance of plant on the hot side [kWht/K-MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_sca", (getter)SolarField_get_mc_bal_sca,(setter)SolarField_set_mc_bal_sca,
	PyDoc_STR("*float*: Non-HTF heat capacity associated with each SCA - per meter basis [Wht/K-m]\n\n**Required:**\nTrue"),
 	NULL},
{"nMod", (getter)SolarField_get_nMod,(setter)SolarField_set_nMod,
	PyDoc_STR("*float*: Number of collector modules in a loop\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"p_start", (getter)SolarField_get_p_start,(setter)SolarField_set_p_start,
	PyDoc_STR("*float*: Collector startup energy, per SCA [kWhe]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_htf_vol", (getter)SolarField_get_rec_htf_vol,(setter)SolarField_set_rec_htf_vol,
	PyDoc_STR("*float*: Volume of HTF in a single collector unit per unit aperture area [L/m2-ap]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)SolarField_get_theta_dep,(setter)SolarField_set_theta_dep,
	PyDoc_STR("*float*: deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)SolarField_get_theta_stow,(setter)SolarField_set_theta_stow,
	PyDoc_STR("*float*: stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"use_abs_or_rel_mdot_limit", (getter)SolarField_get_use_abs_or_rel_mdot_limit,(setter)SolarField_set_use_abs_or_rel_mdot_limit,
	PyDoc_STR("*float*: Use mass flow abs (0) or relative (1) limits\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"washes_per_year", (getter)SolarField_get_washes_per_year,(setter)SolarField_set_washes_per_year,
	PyDoc_STR("*float*: Mirror washing frequency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"water_per_wash", (getter)SolarField_get_water_per_wash,(setter)SolarField_set_water_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.SolarField",             /*tp_name*/
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
		SolarField_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarField_getset,          /*tp_getset*/
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
 * ColRec Group
 */ 

static PyTypeObject ColRec_Type;

static PyObject *
ColRec_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = ColRec_Type.tp_alloc(&ColRec_Type,0);

	VarGroupObject* ColRec_obj = (VarGroupObject*)new_obj;

	ColRec_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ColRec methods */

static PyObject *
ColRec_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "ColRec")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ColRec_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ColRec_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "ColRec")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ColRec_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ColRec_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ColRec_methods[] = {
		{"assign",            (PyCFunction)ColRec_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ColRec_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ColRec_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ColRec_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ColRec_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ColRec_get_A_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_A_aperture_nget, self->data_ptr);
}

static int
ColRec_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_A_aperture_nset, self->data_ptr);
}

static PyObject *
ColRec_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_AbsorberMaterial_aget, self->data_ptr);
}

static int
ColRec_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_AbsorberMaterial_aset, self->data_ptr);
}

static PyObject *
ColRec_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_AnnulusGas_aget, self->data_ptr);
}

static int
ColRec_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_AnnulusGas_aset, self->data_ptr);
}

static PyObject *
ColRec_get_ColAz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_ColAz_nget, self->data_ptr);
}

static int
ColRec_set_ColAz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_ColAz_nset, self->data_ptr);
}

static PyObject *
ColRec_get_DP_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_DP_coefs_aget, self->data_ptr);
}

static int
ColRec_set_DP_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_DP_coefs_aset, self->data_ptr);
}

static PyObject *
ColRec_get_DP_nominal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_DP_nominal_nget, self->data_ptr);
}

static int
ColRec_set_DP_nominal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_DP_nominal_nset, self->data_ptr);
}

static PyObject *
ColRec_get_D_abs_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_D_abs_in_aget, self->data_ptr);
}

static int
ColRec_set_D_abs_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_D_abs_in_aset, self->data_ptr);
}

static PyObject *
ColRec_get_D_abs_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_D_abs_out_aget, self->data_ptr);
}

static int
ColRec_set_D_abs_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_D_abs_out_aset, self->data_ptr);
}

static PyObject *
ColRec_get_D_glass_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_D_glass_in_aget, self->data_ptr);
}

static int
ColRec_set_D_glass_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_D_glass_in_aset, self->data_ptr);
}

static PyObject *
ColRec_get_D_glass_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_D_glass_out_aget, self->data_ptr);
}

static int
ColRec_set_D_glass_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_D_glass_out_aset, self->data_ptr);
}

static PyObject *
ColRec_get_D_plug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_D_plug_aget, self->data_ptr);
}

static int
ColRec_set_D_plug(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_D_plug_aset, self->data_ptr);
}

static PyObject *
ColRec_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_Design_loss_aget, self->data_ptr);
}

static int
ColRec_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_Design_loss_aset, self->data_ptr);
}

static PyObject *
ColRec_get_Dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_Dirt_mirror_nget, self->data_ptr);
}

static int
ColRec_set_Dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_Dirt_mirror_nset, self->data_ptr);
}

static PyObject *
ColRec_get_Error(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_Error_nget, self->data_ptr);
}

static int
ColRec_set_Error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_Error_nset, self->data_ptr);
}

static PyObject *
ColRec_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_Flow_type_aget, self->data_ptr);
}

static int
ColRec_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_Flow_type_aset, self->data_ptr);
}

static PyObject *
ColRec_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_GeomEffects_nget, self->data_ptr);
}

static int
ColRec_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_GeomEffects_nset, self->data_ptr);
}

static PyObject *
ColRec_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_GlazingIntactIn_aget, self->data_ptr);
}

static int
ColRec_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_GlazingIntactIn_aset, self->data_ptr);
}

static PyObject *
ColRec_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_HCE_FieldFrac_aget, self->data_ptr);
}

static int
ColRec_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_HCE_FieldFrac_aset, self->data_ptr);
}

static PyObject *
ColRec_get_HL_T_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_HL_T_coefs_aget, self->data_ptr);
}

static int
ColRec_set_HL_T_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_HL_T_coefs_aset, self->data_ptr);
}

static PyObject *
ColRec_get_HL_w_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_HL_w_coefs_aget, self->data_ptr);
}

static int
ColRec_set_HL_w_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_HL_w_coefs_aset, self->data_ptr);
}

static PyObject *
ColRec_get_IAM_L_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_IAM_L_coefs_aget, self->data_ptr);
}

static int
ColRec_set_IAM_L_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_IAM_L_coefs_aset, self->data_ptr);
}

static PyObject *
ColRec_get_IAM_T_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_IAM_T_coefs_aget, self->data_ptr);
}

static int
ColRec_set_IAM_T_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_IAM_T_coefs_aset, self->data_ptr);
}

static PyObject *
ColRec_get_L_crossover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_L_crossover_nget, self->data_ptr);
}

static int
ColRec_set_L_crossover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_L_crossover_nset, self->data_ptr);
}

static PyObject *
ColRec_get_L_mod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_L_mod_nget, self->data_ptr);
}

static int
ColRec_set_L_mod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_L_mod_nset, self->data_ptr);
}

static PyObject *
ColRec_get_L_mod_spacing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_L_mod_spacing_nget, self->data_ptr);
}

static int
ColRec_set_L_mod_spacing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_L_mod_spacing_nset, self->data_ptr);
}

static PyObject *
ColRec_get_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_ColRec_OpticalTable_mget, self->data_ptr);
}

static int
ColRec_set_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_ColRec_OpticalTable_mset, self->data_ptr);
}

static PyObject *
ColRec_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_P_a_aget, self->data_ptr);
}

static int
ColRec_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_P_a_aset, self->data_ptr);
}

static PyObject *
ColRec_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_Rough_aget, self->data_ptr);
}

static int
ColRec_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_Rough_aset, self->data_ptr);
}

static PyObject *
ColRec_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_Shadowing_aget, self->data_ptr);
}

static int
ColRec_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_Shadowing_aset, self->data_ptr);
}

static PyObject *
ColRec_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_Tau_envelope_aget, self->data_ptr);
}

static int
ColRec_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_Tau_envelope_aset, self->data_ptr);
}

static PyObject *
ColRec_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_TrackingError_nget, self->data_ptr);
}

static int
ColRec_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_TrackingError_nset, self->data_ptr);
}

static PyObject *
ColRec_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_alpha_abs_aget, self->data_ptr);
}

static int
ColRec_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_alpha_abs_aset, self->data_ptr);
}

static PyObject *
ColRec_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_alpha_env_aget, self->data_ptr);
}

static int
ColRec_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_alpha_env_aset, self->data_ptr);
}

static PyObject *
ColRec_get_dirt_env(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_dirt_env_aget, self->data_ptr);
}

static int
ColRec_set_dirt_env(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_dirt_env_aset, self->data_ptr);
}

static PyObject *
ColRec_get_epsilon_abs_1(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_ColRec_epsilon_abs_1_mget, self->data_ptr);
}

static int
ColRec_set_epsilon_abs_1(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_ColRec_epsilon_abs_1_mset, self->data_ptr);
}

static PyObject *
ColRec_get_epsilon_abs_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_ColRec_epsilon_abs_2_mget, self->data_ptr);
}

static int
ColRec_set_epsilon_abs_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_ColRec_epsilon_abs_2_mset, self->data_ptr);
}

static PyObject *
ColRec_get_epsilon_abs_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_ColRec_epsilon_abs_3_mget, self->data_ptr);
}

static int
ColRec_set_epsilon_abs_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_ColRec_epsilon_abs_3_mset, self->data_ptr);
}

static PyObject *
ColRec_get_epsilon_abs_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_ColRec_epsilon_abs_4_mget, self->data_ptr);
}

static int
ColRec_set_epsilon_abs_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_ColRec_epsilon_abs_4_mset, self->data_ptr);
}

static PyObject *
ColRec_get_epsilon_glass(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_ColRec_epsilon_glass_aget, self->data_ptr);
}

static int
ColRec_set_epsilon_glass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_ColRec_epsilon_glass_aset, self->data_ptr);
}

static PyObject *
ColRec_get_nRecVar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_nRecVar_nget, self->data_ptr);
}

static int
ColRec_set_nRecVar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_nRecVar_nset, self->data_ptr);
}

static PyObject *
ColRec_get_opt_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_opt_model_nget, self->data_ptr);
}

static int
ColRec_set_opt_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_opt_model_nset, self->data_ptr);
}

static PyObject *
ColRec_get_rec_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_rec_model_nget, self->data_ptr);
}

static int
ColRec_set_rec_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_rec_model_nset, self->data_ptr);
}

static PyObject *
ColRec_get_reflectivity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ColRec_reflectivity_nget, self->data_ptr);
}

static int
ColRec_set_reflectivity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ColRec_reflectivity_nset, self->data_ptr);
}

static PyGetSetDef ColRec_getset[] = {
{"A_aperture", (getter)ColRec_get_A_aperture,(setter)ColRec_set_A_aperture,
	PyDoc_STR("*float*: Reflective aperture area of the collector [m2]\n\n**Required:**\nTrue"),
 	NULL},
{"AbsorberMaterial", (getter)ColRec_get_AbsorberMaterial,(setter)ColRec_set_AbsorberMaterial,
	PyDoc_STR("*sequence*: Absorber material type\n\n**Required:**\nTrue"),
 	NULL},
{"AnnulusGas", (getter)ColRec_get_AnnulusGas,(setter)ColRec_set_AnnulusGas,
	PyDoc_STR("*sequence*: Annulus gas type (1=air; 26=Ar; 27=H2)\n\n**Required:**\nTrue"),
 	NULL},
{"ColAz", (getter)ColRec_get_ColAz,(setter)ColRec_set_ColAz,
	PyDoc_STR("*float*: Collector azimuth angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"DP_coefs", (getter)ColRec_get_DP_coefs,(setter)ColRec_set_DP_coefs,
	PyDoc_STR("*sequence*: Pressure drop mass flow based part-load curve\n\n**Required:**\nTrue"),
 	NULL},
{"DP_nominal", (getter)ColRec_get_DP_nominal,(setter)ColRec_set_DP_nominal,
	PyDoc_STR("*float*: Pressure drop across a single collector assembly at design [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"D_abs_in", (getter)ColRec_get_D_abs_in,(setter)ColRec_set_D_abs_in,
	PyDoc_STR("*sequence*: The inner absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_abs_out", (getter)ColRec_get_D_abs_out,(setter)ColRec_set_D_abs_out,
	PyDoc_STR("*sequence*: The outer absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_glass_in", (getter)ColRec_get_D_glass_in,(setter)ColRec_set_D_glass_in,
	PyDoc_STR("*sequence*: The inner glass envelope diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_glass_out", (getter)ColRec_get_D_glass_out,(setter)ColRec_set_D_glass_out,
	PyDoc_STR("*sequence*: The outer glass envelope diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_plug", (getter)ColRec_get_D_plug,(setter)ColRec_set_D_plug,
	PyDoc_STR("*sequence*: The diameter of the absorber flow plug (optional) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Design_loss", (getter)ColRec_get_Design_loss,(setter)ColRec_set_Design_loss,
	PyDoc_STR("*sequence*: Receiver heat loss at design [W/m]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_mirror", (getter)ColRec_get_Dirt_mirror,(setter)ColRec_set_Dirt_mirror,
	PyDoc_STR("*float*: User-defined dirt on mirror derate\n\n**Required:**\nTrue"),
 	NULL},
{"Error", (getter)ColRec_get_Error,(setter)ColRec_set_Error,
	PyDoc_STR("*float*: User-defined general optical error derate\n\n**Required:**\nTrue"),
 	NULL},
{"Flow_type", (getter)ColRec_get_Flow_type,(setter)ColRec_set_Flow_type,
	PyDoc_STR("*sequence*: The flow type through the absorber\n\n**Required:**\nTrue"),
 	NULL},
{"GeomEffects", (getter)ColRec_get_GeomEffects,(setter)ColRec_set_GeomEffects,
	PyDoc_STR("*float*: Geometry effects derate\n\n**Required:**\nTrue"),
 	NULL},
{"GlazingIntactIn", (getter)ColRec_get_GlazingIntactIn,(setter)ColRec_set_GlazingIntactIn,
	PyDoc_STR("*sequence*: The glazing intact flag\n\n**Required:**\nTrue"),
 	NULL},
{"HCE_FieldFrac", (getter)ColRec_get_HCE_FieldFrac,(setter)ColRec_set_HCE_FieldFrac,
	PyDoc_STR("*sequence*: The fraction of the field occupied by this HCE type\n\n**Required:**\nTrue"),
 	NULL},
{"HL_T_coefs", (getter)ColRec_get_HL_T_coefs,(setter)ColRec_set_HL_T_coefs,
	PyDoc_STR("*sequence*: HTF temperature-dependent heat loss coefficients [W/m-K]\n\n**Required:**\nTrue"),
 	NULL},
{"HL_w_coefs", (getter)ColRec_get_HL_w_coefs,(setter)ColRec_set_HL_w_coefs,
	PyDoc_STR("*sequence*: Wind-speed-dependent heat loss coefficients [W/m-(m/s)]\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_L_coefs", (getter)ColRec_get_IAM_L_coefs,(setter)ColRec_set_IAM_L_coefs,
	PyDoc_STR("*sequence*: Incidence angle modifier coefficients - longitudinal plane\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_T_coefs", (getter)ColRec_get_IAM_T_coefs,(setter)ColRec_set_IAM_T_coefs,
	PyDoc_STR("*sequence*: Incidence angle modifier coefficients - transversal plane\n\n**Required:**\nTrue"),
 	NULL},
{"L_crossover", (getter)ColRec_get_L_crossover,(setter)ColRec_set_L_crossover,
	PyDoc_STR("*float*: Length of crossover piping in a loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_mod", (getter)ColRec_get_L_mod,(setter)ColRec_set_L_mod,
	PyDoc_STR("*float*: The length of the collector module [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_mod_spacing", (getter)ColRec_get_L_mod_spacing,(setter)ColRec_set_L_mod_spacing,
	PyDoc_STR("*float*: Piping distance between sequential modules in a loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"OpticalTable", (getter)ColRec_get_OpticalTable,(setter)ColRec_set_OpticalTable,
	PyDoc_STR("*sequence[sequence]*: Values of the optical efficiency table\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)ColRec_get_P_a,(setter)ColRec_set_P_a,
	PyDoc_STR("*sequence*: Annulus gas pressure [torr]\n\n**Required:**\nTrue"),
 	NULL},
{"Rough", (getter)ColRec_get_Rough,(setter)ColRec_set_Rough,
	PyDoc_STR("*sequence*: Roughness of the internal surface [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Shadowing", (getter)ColRec_get_Shadowing,(setter)ColRec_set_Shadowing,
	PyDoc_STR("*sequence*: Receiver bellows shadowing loss factor\n\n**Required:**\nTrue"),
 	NULL},
{"Tau_envelope", (getter)ColRec_get_Tau_envelope,(setter)ColRec_set_Tau_envelope,
	PyDoc_STR("*sequence*: Envelope transmittance\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)ColRec_get_TrackingError,(setter)ColRec_set_TrackingError,
	PyDoc_STR("*float*: Tracking error derate\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_abs", (getter)ColRec_get_alpha_abs,(setter)ColRec_set_alpha_abs,
	PyDoc_STR("*sequence*: Absorber absorptance\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_env", (getter)ColRec_get_alpha_env,(setter)ColRec_set_alpha_env,
	PyDoc_STR("*sequence*: Envelope absorptance\n\n**Required:**\nTrue"),
 	NULL},
{"dirt_env", (getter)ColRec_get_dirt_env,(setter)ColRec_set_dirt_env,
	PyDoc_STR("*sequence*: Loss due to dirt on the receiver envelope\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_1", (getter)ColRec_get_epsilon_abs_1,(setter)ColRec_set_epsilon_abs_1,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 1\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_2", (getter)ColRec_get_epsilon_abs_2,(setter)ColRec_set_epsilon_abs_2,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 2\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_3", (getter)ColRec_get_epsilon_abs_3,(setter)ColRec_set_epsilon_abs_3,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 3\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_4", (getter)ColRec_get_epsilon_abs_4,(setter)ColRec_set_epsilon_abs_4,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 4\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_glass", (getter)ColRec_get_epsilon_glass,(setter)ColRec_set_epsilon_glass,
	PyDoc_STR("*sequence*: Glass envelope emissivity\n\n**Required:**\nTrue"),
 	NULL},
{"nRecVar", (getter)ColRec_get_nRecVar,(setter)ColRec_set_nRecVar,
	PyDoc_STR("*float*: Number of receiver variations\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 4 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"opt_model", (getter)ColRec_get_opt_model,(setter)ColRec_set_opt_model,
	PyDoc_STR("*float*: The optical model\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"rec_model", (getter)ColRec_get_rec_model,(setter)ColRec_set_rec_model,
	PyDoc_STR("*float*: Receiver model type (1=Polynomial ; 2=Evac tube)\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"reflectivity", (getter)ColRec_get_reflectivity,(setter)ColRec_set_reflectivity,
	PyDoc_STR("*float*: Solar-weighted mirror reflectivity value\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ColRec_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.ColRec",             /*tp_name*/
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
		ColRec_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ColRec_getset,          /*tp_getset*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = Powerblock_Type.tp_alloc(&Powerblock_Type,0);

	VarGroupObject* Powerblock_obj = (VarGroupObject*)new_obj;

	Powerblock_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Powerblock methods */

static PyObject *
Powerblock_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Powerblock_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Powerblock_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Powerblock_methods[] = {
		{"assign",            (PyCFunction)Powerblock_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Powerblock_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Powerblock_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Powerblock_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Powerblock_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Powerblock_get_CT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_CT_nget, self->data_ptr);
}

static int
Powerblock_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_CT_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_DP_SGS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_DP_SGS_nget, self->data_ptr);
}

static int
Powerblock_set_DP_SGS(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_DP_SGS_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_T_approach_nget, self->data_ptr);
}

static int
Powerblock_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_T_approach_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
Powerblock_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_cycle_max_frac_nget, self->data_ptr);
}

static int
Powerblock_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_pb_pump_coef_nget, self->data_ptr);
}

static int
Powerblock_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_pc_config_nget, self->data_ptr);
}

static int
Powerblock_set_pc_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_pc_config_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_startup_time_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_tech_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Powerblock_tech_type_nget, self->data_ptr);
}

static int
Powerblock_set_tech_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Powerblock_tech_type_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"CT", (getter)Powerblock_get_CT,(setter)Powerblock_set_CT,
	PyDoc_STR("*float*: Flag for using dry cooling or wet cooling system [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"DP_SGS", (getter)Powerblock_get_DP_SGS,(setter)Powerblock_set_DP_SGS,
	PyDoc_STR("*float*: Pressure drop within the steam generator [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	PyDoc_STR("*sequence*: Fraction indicating wet cooling use for hybrid system [none]\n\n**Options:**\nconstant=[0,0,0,0,0,0,0,0,0]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"cycle_cutoff_frac", (getter)Powerblock_get_cycle_cutoff_frac,(setter)Powerblock_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_max_frac", (getter)Powerblock_get_cycle_max_frac,(setter)Powerblock_set_cycle_max_frac,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction\n\n**Required:**\nTrue"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction  [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"pb_pump_coef", (getter)Powerblock_get_pb_pump_coef,(setter)Powerblock_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
{"pc_config", (getter)Powerblock_get_pc_config,(setter)Powerblock_set_pc_config,
	PyDoc_STR("*float*: 0: Steam Rankine (224), 1: user defined [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby mode [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"tech_type", (getter)Powerblock_get_tech_type,(setter)Powerblock_set_tech_type,
	PyDoc_STR("*float*: Turbine inlet pressure control flag (sliding=user, fixed=fresnel) [1/2/3]\n\n**Info:**\ntower/trough/user\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.Powerblock",             /*tp_name*/
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
		Powerblock_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Powerblock_getset,          /*tp_getset*/
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
 * UserDefinedPC Group
 */ 

static PyTypeObject UserDefinedPC_Type;

static PyObject *
UserDefinedPC_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = UserDefinedPC_Type.tp_alloc(&UserDefinedPC_Type,0);

	VarGroupObject* UserDefinedPC_obj = (VarGroupObject*)new_obj;

	UserDefinedPC_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* UserDefinedPC methods */

static PyObject *
UserDefinedPC_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "UserDefinedPC")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPC_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &UserDefinedPC_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "UserDefinedPC")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPC_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &UserDefinedPC_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef UserDefinedPC_methods[] = {
		{"assign",            (PyCFunction)UserDefinedPC_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``UserDefinedPC_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)UserDefinedPC_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``UserDefinedPC_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)UserDefinedPC_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UserDefinedPC_get_ud_f_W_dot_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_UserDefinedPC_ud_f_W_dot_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_f_W_dot_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_UserDefinedPC_ud_f_W_dot_cool_des_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_UserDefinedPC_ud_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_UserDefinedPC_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_is_sco2_regr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_UserDefinedPC_ud_is_sco2_regr_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_is_sco2_regr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_UserDefinedPC_ud_is_sco2_regr_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_m_dot_water_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_UserDefinedPC_ud_m_dot_water_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_m_dot_water_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_UserDefinedPC_ud_m_dot_water_cool_des_nset, self->data_ptr);
}

static PyGetSetDef UserDefinedPC_getset[] = {
{"ud_f_W_dot_cool_des", (getter)UserDefinedPC_get_ud_f_W_dot_cool_des,(setter)UserDefinedPC_set_ud_f_W_dot_cool_des,
	PyDoc_STR("*float*: Percent of user-defined power cycle design gross output consumed by cooling [%]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_ind_od", (getter)UserDefinedPC_get_ud_ind_od,(setter)UserDefinedPC_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_is_sco2_regr", (getter)UserDefinedPC_get_ud_is_sco2_regr,(setter)UserDefinedPC_set_ud_is_sco2_regr,
	PyDoc_STR("*float*: 0: (default) simple max htf mass flow correction; 1: sco2 heuristic regression; 2: no correction\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ud_m_dot_water_cool_des", (getter)UserDefinedPC_get_ud_m_dot_water_cool_des,(setter)UserDefinedPC_set_ud_m_dot_water_cool_des,
	PyDoc_STR("*float*: Mass flow rate of water required at user-defined power cycle design point [kg/s]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject UserDefinedPC_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.UserDefinedPC",             /*tp_name*/
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
		UserDefinedPC_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		UserDefinedPC_getset,          /*tp_getset*/
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
 * Storage Group
 */ 

static PyTypeObject Storage_Type;

static PyObject *
Storage_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = Storage_Type.tp_alloc(&Storage_Type,0);

	VarGroupObject* Storage_obj = (VarGroupObject*)new_obj;

	Storage_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Storage methods */

static PyObject *
Storage_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "Storage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Storage_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Storage_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "Storage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Storage_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Storage_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Storage_methods[] = {
		{"assign",            (PyCFunction)Storage_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Storage_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Storage_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Storage_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Storage_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Storage_get_V_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_V_tes_des_nget, self->data_ptr);
}

static int
Storage_set_V_tes_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_V_tes_des_nset, self->data_ptr);
}

static PyObject *
Storage_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_cold_tank_Thtr_nget, self->data_ptr);
}

static int
Storage_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
Storage_get_cold_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_cold_tank_max_heat_nget, self->data_ptr);
}

static int
Storage_set_cold_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
Storage_get_dt_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_dt_cold_nget, self->data_ptr);
}

static int
Storage_set_dt_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_dt_cold_nset, self->data_ptr);
}

static PyObject *
Storage_get_dt_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_dt_hot_nget, self->data_ptr);
}

static int
Storage_set_dt_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_dt_hot_nset, self->data_ptr);
}

static PyObject *
Storage_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_h_tank_nget, self->data_ptr);
}

static int
Storage_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_h_tank_nset, self->data_ptr);
}

static PyObject *
Storage_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_h_tank_min_nget, self->data_ptr);
}

static int
Storage_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_h_tank_min_nset, self->data_ptr);
}

static PyObject *
Storage_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_hot_tank_Thtr_nget, self->data_ptr);
}

static int
Storage_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
Storage_get_hot_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_hot_tank_max_heat_nget, self->data_ptr);
}

static int
Storage_set_hot_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_hot_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
Storage_get_init_hot_htf_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_init_hot_htf_percent_nget, self->data_ptr);
}

static int
Storage_set_init_hot_htf_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
Storage_get_store_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_Storage_store_fl_props_mget, self->data_ptr);
}

static int
Storage_set_store_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_Storage_store_fl_props_mset, self->data_ptr);
}

static PyObject *
Storage_get_store_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_store_fluid_nget, self->data_ptr);
}

static int
Storage_set_store_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_store_fluid_nset, self->data_ptr);
}

static PyObject *
Storage_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_tank_pairs_nget, self->data_ptr);
}

static int
Storage_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_tank_pairs_nset, self->data_ptr);
}

static PyObject *
Storage_get_tanks_in_parallel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_tanks_in_parallel_nget, self->data_ptr);
}

static int
Storage_set_tanks_in_parallel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_tanks_in_parallel_nset, self->data_ptr);
}

static PyObject *
Storage_get_tes_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_tes_pump_coef_nget, self->data_ptr);
}

static int
Storage_set_tes_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_tes_pump_coef_nset, self->data_ptr);
}

static PyObject *
Storage_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Storage_u_tank_nget, self->data_ptr);
}

static int
Storage_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Storage_u_tank_nset, self->data_ptr);
}

static PyGetSetDef Storage_getset[] = {
{"V_tes_des", (getter)Storage_get_V_tes_des,(setter)Storage_set_V_tes_des,
	PyDoc_STR("*float*: Design-point velocity to size the TES pipe diameters [m/s]\n\n**Required:**\nFalse. Automatically set to 1.85 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cold_tank_Thtr", (getter)Storage_get_cold_tank_Thtr,(setter)Storage_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Cold tank heater set point\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_max_heat", (getter)Storage_get_cold_tank_max_heat,(setter)Storage_set_cold_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for cold tank heating [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"dt_cold", (getter)Storage_get_dt_cold,(setter)Storage_set_dt_cold,
	PyDoc_STR("*float*: Cold side HX approach temp\n\n**Required:**\nTrue\n\nThe value of ``dt_cold`` depends on the following variables:\n\n\t - dt_hot\n"),
 	NULL},
{"dt_hot", (getter)Storage_get_dt_hot,(setter)Storage_set_dt_hot,
	PyDoc_STR("*float*: Hot side HX approach temp\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``dt_hot``:\n\n\t - dt_cold\n"),
 	NULL},
{"h_tank", (getter)Storage_get_h_tank,(setter)Storage_set_h_tank,
	PyDoc_STR("*float*: Height of HTF when tank is full\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank_min", (getter)Storage_get_h_tank_min,(setter)Storage_set_h_tank_min,
	PyDoc_STR("*float*: Minimum tank fluid height\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_Thtr", (getter)Storage_get_hot_tank_Thtr,(setter)Storage_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Hot tank heater set point\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_max_heat", (getter)Storage_get_hot_tank_max_heat,(setter)Storage_set_hot_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for hot tank heating [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"init_hot_htf_percent", (getter)Storage_get_init_hot_htf_percent,(setter)Storage_set_init_hot_htf_percent,
	PyDoc_STR("*float*: Initial fraction of avail. vol that is hot [%]\n\n**Required:**\nTrue"),
 	NULL},
{"store_fl_props", (getter)Storage_get_store_fl_props,(setter)Storage_set_store_fl_props,
	PyDoc_STR("*sequence[sequence]*: Storage user-defined HTF Properties\n\n**Required:**\nTrue"),
 	NULL},
{"store_fluid", (getter)Storage_get_store_fluid,(setter)Storage_set_store_fluid,
	PyDoc_STR("*float*: Storage HTF ID\n\n**Required:**\nTrue"),
 	NULL},
{"tank_pairs", (getter)Storage_get_tank_pairs,(setter)Storage_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tanks_in_parallel", (getter)Storage_get_tanks_in_parallel,(setter)Storage_set_tanks_in_parallel,
	PyDoc_STR("*float*: Tanks are in parallel, not in series, with solar field [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_pump_coef", (getter)Storage_get_tes_pump_coef,(setter)Storage_set_tes_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through tes loop [kW/(kg/s)]\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)Storage_get_u_tank,(setter)Storage_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from tank\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Storage_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.Storage",             /*tp_name*/
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
		Storage_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Storage_getset,          /*tp_getset*/
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
 * Tou Group
 */ 

static PyTypeObject Tou_Type;

static PyObject *
Tou_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = Tou_Type.tp_alloc(&Tou_Type,0);

	VarGroupObject* Tou_obj = (VarGroupObject*)new_obj;

	Tou_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Tou methods */

static PyObject *
Tou_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Tou_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Tou_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Tou_methods[] = {
		{"assign",            (PyCFunction)Tou_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Tou_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Tou_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Tou_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Tou_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Tou_get_can_cycle_use_standby(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_can_cycle_use_standby_nget, self->data_ptr);
}

static int
Tou_set_can_cycle_use_standby(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_can_cycle_use_standby_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_reporting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_disp_reporting_nget, self->data_ptr);
}

static int
Tou_set_disp_reporting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_disp_reporting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_bb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_disp_spec_bb_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_bb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_disp_spec_bb_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_presolve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_disp_spec_presolve_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_presolve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_disp_spec_presolve_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_scaling(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_disp_spec_scaling_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_scaling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_disp_spec_scaling_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_disp_steps_per_hour_nget, self->data_ptr);
}

static int
Tou_set_disp_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_disp_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Tou_dispatch_factors_ts_aget, self->data_ptr);
}

static int
Tou_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_Tou_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
Tou_get_f_turb_tou_periods(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Tou_f_turb_tou_periods_aget, self->data_ptr);
}

static int
Tou_set_f_turb_tou_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_Tou_f_turb_tou_periods_aset, self->data_ptr);
}

static PyObject *
Tou_get_is_timestep_load_fractions(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_is_timestep_load_fractions_nget, self->data_ptr);
}

static int
Tou_set_is_timestep_load_fractions(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_is_timestep_load_fractions_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_tod_pc_target_also_pc_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_is_tod_pc_target_also_pc_max_nget, self->data_ptr);
}

static int
Tou_set_is_tod_pc_target_also_pc_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_is_tod_pc_target_also_pc_max_nset, self->data_ptr);
}

static PyObject *
Tou_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_ppa_multiplier_model_nget, self->data_ptr);
}

static int
Tou_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_heattrace(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_q_rec_heattrace_nget, self->data_ptr);
}

static int
Tou_set_q_rec_heattrace(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_q_rec_heattrace_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_standby(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Tou_q_rec_standby_nget, self->data_ptr);
}

static int
Tou_set_q_rec_standby(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_Tou_q_rec_standby_nset, self->data_ptr);
}

static PyObject *
Tou_get_timestep_load_fractions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Tou_timestep_load_fractions_aget, self->data_ptr);
}

static int
Tou_set_timestep_load_fractions(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_Tou_timestep_load_fractions_aset, self->data_ptr);
}

static PyGetSetDef Tou_getset[] = {
{"can_cycle_use_standby", (getter)Tou_get_can_cycle_use_standby,(setter)Tou_set_can_cycle_use_standby,
	PyDoc_STR("*float*: Can the cycle use standby operation?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_reporting", (getter)Tou_get_disp_reporting,(setter)Tou_set_disp_reporting,
	PyDoc_STR("*float*: Dispatch optimization reporting level [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_bb", (getter)Tou_get_disp_spec_bb,(setter)Tou_set_disp_spec_bb,
	PyDoc_STR("*float*: Dispatch optimization B&B heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_presolve", (getter)Tou_get_disp_spec_presolve,(setter)Tou_set_disp_spec_presolve,
	PyDoc_STR("*float*: Dispatch optimization presolve heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_scaling", (getter)Tou_get_disp_spec_scaling,(setter)Tou_set_disp_spec_scaling,
	PyDoc_STR("*float*: Dispatch optimization scaling heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_steps_per_hour", (getter)Tou_get_disp_steps_per_hour,(setter)Tou_set_disp_steps_per_hour,
	PyDoc_STR("*float*: Time steps per hour for dispatch optimization calculations [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factors_ts", (getter)Tou_get_dispatch_factors_ts,(setter)Tou_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n**Required:**\nRequired if ppa_multiplier_model=1&csp_financial_model<5&is_dispatch=1"),
 	NULL},
{"f_turb_tou_periods", (getter)Tou_get_f_turb_tou_periods,(setter)Tou_set_f_turb_tou_periods,
	PyDoc_STR("*sequence*: Dispatch logic for turbine load fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"is_timestep_load_fractions", (getter)Tou_get_is_timestep_load_fractions,(setter)Tou_set_is_timestep_load_fractions,
	PyDoc_STR("*float*: Use turbine load fraction for each timestep instead of block dispatch?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_tod_pc_target_also_pc_max", (getter)Tou_get_is_tod_pc_target_also_pc_max,(setter)Tou_set_is_tod_pc_target_also_pc_max,
	PyDoc_STR("*float*: Is the TOD target cycle heat input also the max cycle heat input?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_multiplier_model", (getter)Tou_get_ppa_multiplier_model,(setter)Tou_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model 0: dispatch factors dispatch_factorX, 1: hourly multipliers dispatch_factors_ts [0/1]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_rec_heattrace", (getter)Tou_get_q_rec_heattrace,(setter)Tou_set_q_rec_heattrace,
	PyDoc_STR("*float*: Receiver heat trace energy consumption during startup [kWhe]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_rec_standby", (getter)Tou_get_q_rec_standby,(setter)Tou_set_q_rec_standby,
	PyDoc_STR("*float*: Receiver standby energy consumption [kWt]\n\n**Required:**\nFalse. Automatically set to 9e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"timestep_load_fractions", (getter)Tou_get_timestep_load_fractions,(setter)Tou_set_timestep_load_fractions,
	PyDoc_STR("*sequence*: Turbine load fraction for each timestep, alternative to block dispatch\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Tou_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.Tou",             /*tp_name*/
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
		Tou_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Tou_getset,          /*tp_getset*/
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
 * SysControl Group
 */ 

static PyTypeObject SysControl_Type;

static PyObject *
SysControl_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = SysControl_Type.tp_alloc(&SysControl_Type,0);

	VarGroupObject* SysControl_obj = (VarGroupObject*)new_obj;

	SysControl_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SysControl methods */

static PyObject *
SysControl_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "SysControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SysControl_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SysControl_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "SysControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SysControl_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SysControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SysControl_methods[] = {
		{"assign",            (PyCFunction)SysControl_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SysControl_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SysControl_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SysControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SysControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SysControl_get_aux_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_SysControl_aux_array_aget, self->data_ptr);
}

static int
SysControl_set_aux_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_SysControl_aux_array_aset, self->data_ptr);
}

static PyObject *
SysControl_get_bop_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_SysControl_bop_array_aget, self->data_ptr);
}

static int
SysControl_set_bop_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_SysControl_bop_array_aset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_csu_cost_rel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_csu_cost_rel_nget, self->data_ptr);
}

static int
SysControl_set_disp_csu_cost_rel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_csu_cost_rel_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_frequency_nget, self->data_ptr);
}

static int
SysControl_set_disp_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_frequency_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_horizon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_horizon_nget, self->data_ptr);
}

static int
SysControl_set_disp_horizon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_horizon_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_max_iter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_max_iter_nget, self->data_ptr);
}

static int
SysControl_set_disp_max_iter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_max_iter_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_mip_gap_nget, self->data_ptr);
}

static int
SysControl_set_disp_mip_gap(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_mip_gap_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_pen_ramping(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_pen_ramping_nget, self->data_ptr);
}

static int
SysControl_set_disp_pen_ramping(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_pen_ramping_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_rsu_cost_rel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_rsu_cost_rel_nget, self->data_ptr);
}

static int
SysControl_set_disp_rsu_cost_rel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_rsu_cost_rel_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_time_weighting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_time_weighting_nget, self->data_ptr);
}

static int
SysControl_set_disp_time_weighting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_time_weighting_nset, self->data_ptr);
}

static PyObject *
SysControl_get_disp_timeout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_disp_timeout_nget, self->data_ptr);
}

static int
SysControl_set_disp_timeout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_disp_timeout_nset, self->data_ptr);
}

static PyObject *
SysControl_get_is_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_is_dispatch_nget, self->data_ptr);
}

static int
SysControl_set_is_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_is_dispatch_nset, self->data_ptr);
}

static PyObject *
SysControl_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_pb_fixed_par_nget, self->data_ptr);
}

static int
SysControl_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
SysControl_get_rec_qf_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_rec_qf_delay_nget, self->data_ptr);
}

static int
SysControl_set_rec_qf_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_rec_qf_delay_nset, self->data_ptr);
}

static PyObject *
SysControl_get_rec_su_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_SysControl_rec_su_delay_nget, self->data_ptr);
}

static int
SysControl_set_rec_su_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_SysControl_rec_su_delay_nset, self->data_ptr);
}

static PyObject *
SysControl_get_weekday_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_SysControl_weekday_schedule_mget, self->data_ptr);
}

static int
SysControl_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_SysControl_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
SysControl_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_SysControl_weekend_schedule_mget, self->data_ptr);
}

static int
SysControl_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_SysControl_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef SysControl_getset[] = {
{"aux_array", (getter)SysControl_get_aux_array,(setter)SysControl_set_aux_array,
	PyDoc_STR("*sequence*: Aux heater, boiler parasitic\n\n**Required:**\nTrue"),
 	NULL},
{"bop_array", (getter)SysControl_get_bop_array,(setter)SysControl_set_bop_array,
	PyDoc_STR("*sequence*: Balance of plant parasitic power fraction\n\n**Required:**\nTrue"),
 	NULL},
{"disp_csu_cost_rel", (getter)SysControl_get_disp_csu_cost_rel,(setter)SysControl_set_disp_csu_cost_rel,
	PyDoc_STR("*float*: Cycle startup cost [$/MWe-cycle/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_frequency", (getter)SysControl_get_disp_frequency,(setter)SysControl_set_disp_frequency,
	PyDoc_STR("*float*: Frequency for dispatch optimization calculations [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_horizon", (getter)SysControl_get_disp_horizon,(setter)SysControl_set_disp_horizon,
	PyDoc_STR("*float*: Time horizon for dispatch optimization [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_max_iter", (getter)SysControl_get_disp_max_iter,(setter)SysControl_set_disp_max_iter,
	PyDoc_STR("*float*: Max. no. dispatch optimization iterations [-]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_mip_gap", (getter)SysControl_get_disp_mip_gap,(setter)SysControl_set_disp_mip_gap,
	PyDoc_STR("*float*: Dispatch optimization solution tolerance [-]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_pen_ramping", (getter)SysControl_get_disp_pen_ramping,(setter)SysControl_set_disp_pen_ramping,
	PyDoc_STR("*float*: Dispatch cycle production change penalty [$/MWe-change]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_rsu_cost_rel", (getter)SysControl_get_disp_rsu_cost_rel,(setter)SysControl_set_disp_rsu_cost_rel,
	PyDoc_STR("*float*: Receiver startup cost [$/MWt/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_time_weighting", (getter)SysControl_get_disp_time_weighting,(setter)SysControl_set_disp_time_weighting,
	PyDoc_STR("*float*: Dispatch optimization future time discounting factor [-]\n\n**Required:**\nFalse. Automatically set to 0.99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_timeout", (getter)SysControl_get_disp_timeout,(setter)SysControl_set_disp_timeout,
	PyDoc_STR("*float*: Max. dispatch optimization solve duration [s]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"is_dispatch", (getter)SysControl_get_is_dispatch,(setter)SysControl_set_is_dispatch,
	PyDoc_STR("*float*: Allow dispatch optimization? [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pb_fixed_par", (getter)SysControl_get_pb_fixed_par,(setter)SysControl_set_pb_fixed_par,
	PyDoc_STR("*float*: Fixed parasitic load - runs at all times\n\n**Required:**\nTrue"),
 	NULL},
{"rec_qf_delay", (getter)SysControl_get_rec_qf_delay,(setter)SysControl_set_rec_qf_delay,
	PyDoc_STR("*float*: Energy-based receiver startup delay (fraction of rated thermal power) [-]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_su_delay", (getter)SysControl_get_rec_su_delay,(setter)SysControl_set_rec_su_delay,
	PyDoc_STR("*float*: Fixed startup delay time for the receiver [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"weekday_schedule", (getter)SysControl_get_weekday_schedule,(setter)SysControl_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 Time of Use Values for week days\n\n**Required:**\nTrue"),
 	NULL},
{"weekend_schedule", (getter)SysControl_get_weekend_schedule,(setter)SysControl_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 Time of Use Values for week end days\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SysControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.SysControl",             /*tp_name*/
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
		SysControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SysControl_getset,          /*tp_getset*/
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
 * FinancialModel Group
 */ 

static PyTypeObject FinancialModel_Type;

static PyObject *
FinancialModel_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = FinancialModel_Type.tp_alloc(&FinancialModel_Type,0);

	VarGroupObject* FinancialModel_obj = (VarGroupObject*)new_obj;

	FinancialModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialModel methods */

static PyObject *
FinancialModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "FinancialModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "FinancialModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialModel_methods[] = {
		{"assign",            (PyCFunction)FinancialModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialModel_get_csp_financial_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialModel_csp_financial_model_nget, self->data_ptr);
}

static int
FinancialModel_set_csp_financial_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialModel_csp_financial_model_nset, self->data_ptr);
}

static PyGetSetDef FinancialModel_getset[] = {
{"csp_financial_model", (getter)FinancialModel_get_csp_financial_model,(setter)FinancialModel_set_csp_financial_model,
	PyDoc_STR("*float*:  [1-8]\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.FinancialModel",             /*tp_name*/
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
		FinancialModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialModel_getset,          /*tp_getset*/
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
 * ElectricityRates Group
 */ 

static PyTypeObject ElectricityRates_Type;

static PyObject *
ElectricityRates_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = ElectricityRates_Type.tp_alloc(&ElectricityRates_Type,0);

	VarGroupObject* ElectricityRates_obj = (VarGroupObject*)new_obj;

	ElectricityRates_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ElectricityRates methods */

static PyObject *
ElectricityRates_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "ElectricityRates")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRates_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ElectricityRates_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "ElectricityRates")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRates_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityRates_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityRates_methods[] = {
		{"assign",            (PyCFunction)ElectricityRates_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ElectricityRates_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ElectricityRates_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricityRates_get_en_electricity_rates(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Enable electricity rates for grid purchase [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.ElectricityRates",             /*tp_name*/
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
		ElectricityRates_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricityRates_getset,          /*tp_getset*/
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
 * TimeOfDeliveryFactors Group
 */ 

static PyTypeObject TimeOfDeliveryFactors_Type;

static PyObject *
TimeOfDeliveryFactors_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = TimeOfDeliveryFactors_Type.tp_alloc(&TimeOfDeliveryFactors_Type,0);

	VarGroupObject* TimeOfDeliveryFactors_obj = (VarGroupObject*)new_obj;

	TimeOfDeliveryFactors_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeOfDeliveryFactors methods */

static PyObject *
TimeOfDeliveryFactors_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "TimeOfDeliveryFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDeliveryFactors_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TimeOfDeliveryFactors_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "TimeOfDeliveryFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDeliveryFactors_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDeliveryFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDeliveryFactors_methods[] = {
		{"assign",            (PyCFunction)TimeOfDeliveryFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TimeOfDeliveryFactors_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TimeOfDeliveryFactors_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TimeOfDeliveryFactors_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeOfDeliveryFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_TimeOfDeliveryFactors_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_TimeOfDeliveryFactors_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_TimeOfDeliveryFactors_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_TimeOfDeliveryFactors_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_tod_factors(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_TimeOfDeliveryFactors_dispatch_tod_factors_aget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_tod_factors(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_TimeOfDeliveryFactors_dispatch_tod_factors_aset, self->data_ptr);
}

static PyGetSetDef TimeOfDeliveryFactors_getset[] = {
{"dispatch_sched_weekday", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekday,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: PPA pricing weekday schedule, 12x24\n\n**Required:**\nRequired if ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"dispatch_sched_weekend", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekend,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: PPA pricing weekend schedule, 12x24\n\n**Required:**\nRequired if ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"dispatch_tod_factors", (getter)TimeOfDeliveryFactors_get_dispatch_tod_factors,(setter)TimeOfDeliveryFactors_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1 through 9\n\n**Info:**\nWe added this array input after SAM 2022.12.21 to replace the functionality of former single value inputs dispatch_factor1 through dispatch_factor9\n\n**Required:**\nRequired if ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDeliveryFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.TimeOfDeliveryFactors",             /*tp_name*/
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
		TimeOfDeliveryFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDeliveryFactors_getset,          /*tp_getset*/
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
 * FinancialSolutionMode Group
 */ 

static PyTypeObject FinancialSolutionMode_Type;

static PyObject *
FinancialSolutionMode_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = FinancialSolutionMode_Type.tp_alloc(&FinancialSolutionMode_Type,0);

	VarGroupObject* FinancialSolutionMode_obj = (VarGroupObject*)new_obj;

	FinancialSolutionMode_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialSolutionMode methods */

static PyObject *
FinancialSolutionMode_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "FinancialSolutionMode")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialSolutionMode_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialSolutionMode_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "FinancialSolutionMode")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialSolutionMode_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialSolutionMode_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialSolutionMode_methods[] = {
		{"assign",            (PyCFunction)FinancialSolutionMode_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialSolutionMode_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialSolutionMode_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialSolutionMode_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialSolutionMode_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialSolutionMode_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_FinancialSolutionMode_ppa_price_input_aget, self->data_ptr);
}

static int
FinancialSolutionMode_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_FresnelPhysical_FinancialSolutionMode_ppa_price_input_aset, self->data_ptr);
}

static PyObject *
FinancialSolutionMode_get_ppa_soln_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialSolutionMode_ppa_soln_mode_nget, self->data_ptr);
}

static int
FinancialSolutionMode_set_ppa_soln_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialSolutionMode_ppa_soln_mode_nset, self->data_ptr);
}

static PyGetSetDef FinancialSolutionMode_getset[] = {
{"ppa_price_input", (getter)FinancialSolutionMode_get_ppa_price_input,(setter)FinancialSolutionMode_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA solution mode (0=Specify IRR target, 1=Specify PPA price)\n\n**Required:**\nRequired if ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
{"ppa_soln_mode", (getter)FinancialSolutionMode_get_ppa_soln_mode,(setter)FinancialSolutionMode_set_ppa_soln_mode,
	PyDoc_STR("*float*: PPA solution mode (0=Specify IRR target, 1=Specify PPA price)\n\n**Required:**\nRequired if ppa_multiplier_model=0&csp_financial_model<5&is_dispatch=1&sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialSolutionMode_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.FinancialSolutionMode",             /*tp_name*/
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
		FinancialSolutionMode_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialSolutionMode_getset,          /*tp_getset*/
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
 * Revenue Group
 */ 

static PyTypeObject Revenue_Type;

static PyObject *
Revenue_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = Revenue_Type.tp_alloc(&Revenue_Type,0);

	VarGroupObject* Revenue_obj = (VarGroupObject*)new_obj;

	Revenue_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Revenue methods */

static PyObject *
Revenue_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "Revenue")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Revenue_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Revenue_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "Revenue")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Revenue_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Revenue_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Revenue_methods[] = {
		{"assign",            (PyCFunction)Revenue_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Revenue_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Revenue_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Revenue_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Revenue_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Revenue_get_mp_energy_market_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_FresnelPhysical_Revenue_mp_energy_market_revenue_mget, self->data_ptr);
}

static int
Revenue_set_mp_energy_market_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_FresnelPhysical_Revenue_mp_energy_market_revenue_mset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"mp_energy_market_revenue", (getter)Revenue_get_mp_energy_market_revenue,(setter)Revenue_set_mp_energy_market_revenue,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input\n\n**Info:**\nLifetime x 2[Cleared Capacity(MW),Price($ / MWh)]\n\n**Required:**\nRequired if csp_financial_model=6&is_dispatch=1&sim_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.Revenue",             /*tp_name*/
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
		Revenue_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Revenue_getset,          /*tp_getset*/
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
 * CapitalCosts Group
 */ 

static PyTypeObject CapitalCosts_Type;

static PyObject *
CapitalCosts_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = CapitalCosts_Type.tp_alloc(&CapitalCosts_Type,0);

	VarGroupObject* CapitalCosts_obj = (VarGroupObject*)new_obj;

	CapitalCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* CapitalCosts methods */

static PyObject *
CapitalCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "CapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CapitalCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &CapitalCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "CapitalCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CapitalCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &CapitalCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CapitalCosts_methods[] = {
		{"assign",            (PyCFunction)CapitalCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``CapitalCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)CapitalCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``CapitalCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)CapitalCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CapitalCosts_get_bop_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_bop_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_bop_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_bop_spec_cost_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_contingency_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_contingency_percent_nget, self->data_ptr);
}

static int
CapitalCosts_set_contingency_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_contingency_percent_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_epc_cost_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_epc_cost_fixed_nget, self->data_ptr);
}

static int
CapitalCosts_set_epc_cost_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_epc_cost_fixed_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_epc_cost_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_epc_cost_per_acre_nget, self->data_ptr);
}

static int
CapitalCosts_set_epc_cost_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_epc_cost_per_acre_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_epc_cost_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_epc_cost_per_watt_nget, self->data_ptr);
}

static int
CapitalCosts_set_epc_cost_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_epc_cost_per_watt_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_epc_cost_percent_direct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_epc_cost_percent_direct_nget, self->data_ptr);
}

static int
CapitalCosts_set_epc_cost_percent_direct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_epc_cost_percent_direct_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_fossil_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_fossil_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_fossil_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_fossil_spec_cost_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_htf_system_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_htf_system_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_htf_system_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_htf_system_spec_cost_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_plm_cost_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_plm_cost_fixed_nget, self->data_ptr);
}

static int
CapitalCosts_set_plm_cost_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_plm_cost_fixed_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_plm_cost_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_plm_cost_per_acre_nget, self->data_ptr);
}

static int
CapitalCosts_set_plm_cost_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_plm_cost_per_acre_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_plm_cost_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_plm_cost_per_watt_nget, self->data_ptr);
}

static int
CapitalCosts_set_plm_cost_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_plm_cost_per_watt_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_plm_cost_percent_direct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_plm_cost_percent_direct_nget, self->data_ptr);
}

static int
CapitalCosts_set_plm_cost_percent_direct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_plm_cost_percent_direct_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_power_plant_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_power_plant_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_power_plant_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_power_plant_spec_cost_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_sales_tax_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_sales_tax_percent_nget, self->data_ptr);
}

static int
CapitalCosts_set_sales_tax_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_sales_tax_percent_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_sales_tax_rate_nget, self->data_ptr);
}

static int
CapitalCosts_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_sales_tax_rate_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_site_improvements_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_site_improvements_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_site_improvements_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_site_improvements_spec_cost_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_solar_field_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_solar_field_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_solar_field_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_solar_field_spec_cost_nset, self->data_ptr);
}

static PyObject *
CapitalCosts_get_storage_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_CapitalCosts_storage_spec_cost_nget, self->data_ptr);
}

static int
CapitalCosts_set_storage_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_CapitalCosts_storage_spec_cost_nset, self->data_ptr);
}

static PyGetSetDef CapitalCosts_getset[] = {
{"bop_spec_cost", (getter)CapitalCosts_get_bop_spec_cost,(setter)CapitalCosts_set_bop_spec_cost,
	PyDoc_STR("*float*: Balance of Plant Cost per kWe [$/kWe]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"contingency_percent", (getter)CapitalCosts_get_contingency_percent,(setter)CapitalCosts_set_contingency_percent,
	PyDoc_STR("*float*: Contingency Percent [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"epc_cost_fixed", (getter)CapitalCosts_get_epc_cost_fixed,(setter)CapitalCosts_set_epc_cost_fixed,
	PyDoc_STR("*float*: Fixed EPC Cost [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"epc_cost_per_acre", (getter)CapitalCosts_get_epc_cost_per_acre,(setter)CapitalCosts_set_epc_cost_per_acre,
	PyDoc_STR("*float*: EPC Costs per acre [$/acre]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"epc_cost_per_watt", (getter)CapitalCosts_get_epc_cost_per_watt,(setter)CapitalCosts_set_epc_cost_per_watt,
	PyDoc_STR("*float*: EPC Cost Wac [$/Wac]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"epc_cost_percent_direct", (getter)CapitalCosts_get_epc_cost_percent_direct,(setter)CapitalCosts_set_epc_cost_percent_direct,
	PyDoc_STR("*float*: EPC Costs % direct [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"fossil_spec_cost", (getter)CapitalCosts_get_fossil_spec_cost,(setter)CapitalCosts_set_fossil_spec_cost,
	PyDoc_STR("*float*: Fossil Backup Cost per kWe [$/kWe]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"htf_system_spec_cost", (getter)CapitalCosts_get_htf_system_spec_cost,(setter)CapitalCosts_set_htf_system_spec_cost,
	PyDoc_STR("*float*: HTF System Cost Per m2 [$/m2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"plm_cost_fixed", (getter)CapitalCosts_get_plm_cost_fixed,(setter)CapitalCosts_set_plm_cost_fixed,
	PyDoc_STR("*float*: Fixed Land Cost [$]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"plm_cost_per_acre", (getter)CapitalCosts_get_plm_cost_per_acre,(setter)CapitalCosts_set_plm_cost_per_acre,
	PyDoc_STR("*float*: Land Cost per acre [$/acre]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"plm_cost_per_watt", (getter)CapitalCosts_get_plm_cost_per_watt,(setter)CapitalCosts_set_plm_cost_per_watt,
	PyDoc_STR("*float*: Land Cost Wac [$/Wac]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"plm_cost_percent_direct", (getter)CapitalCosts_get_plm_cost_percent_direct,(setter)CapitalCosts_set_plm_cost_percent_direct,
	PyDoc_STR("*float*: Land Cost % direct [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"power_plant_spec_cost", (getter)CapitalCosts_get_power_plant_spec_cost,(setter)CapitalCosts_set_power_plant_spec_cost,
	PyDoc_STR("*float*: Power Plant Cost per kWe [$/kWe]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sales_tax_percent", (getter)CapitalCosts_get_sales_tax_percent,(setter)CapitalCosts_set_sales_tax_percent,
	PyDoc_STR("*float*: Sales Tax Percentage of Direct Cost [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sales_tax_rate", (getter)CapitalCosts_get_sales_tax_rate,(setter)CapitalCosts_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales Tax Rate [%]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"site_improvements_spec_cost", (getter)CapitalCosts_get_site_improvements_spec_cost,(setter)CapitalCosts_set_site_improvements_spec_cost,
	PyDoc_STR("*float*: Site Improvement Cost per m2 [$/m2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"solar_field_spec_cost", (getter)CapitalCosts_get_solar_field_spec_cost,(setter)CapitalCosts_set_solar_field_spec_cost,
	PyDoc_STR("*float*: Solar Field Cost per m2 [$/m2]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"storage_spec_cost", (getter)CapitalCosts_get_storage_spec_cost,(setter)CapitalCosts_set_storage_spec_cost,
	PyDoc_STR("*float*: Storage cost per kWht [$/kWht]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CapitalCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.CapitalCosts",             /*tp_name*/
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
		CapitalCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CapitalCosts_getset,          /*tp_getset*/
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
 * FinancialParameters Group
 */ 

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_FresnelPhysical data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	VarGroupObject* FinancialParameters_obj = (VarGroupObject*)new_obj;

	FinancialParameters_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FinancialParameters_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FinancialParameters_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_const_per_interest_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_interest_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_months1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_months1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_months2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_months2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_months3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_months3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_months4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_months4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_months5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_months5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_percent1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_percent1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_percent2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_percent2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_percent3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_percent3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_percent4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_percent4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_percent5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_percent5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_FresnelPhysical_FinancialParameters_const_per_upfront_rate5_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"const_per_interest_rate1", (getter)FinancialParameters_get_const_per_interest_rate1,(setter)FinancialParameters_set_const_per_interest_rate1,
	PyDoc_STR("*float*: Interest rate, loan 1 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate2", (getter)FinancialParameters_get_const_per_interest_rate2,(setter)FinancialParameters_set_const_per_interest_rate2,
	PyDoc_STR("*float*: Interest rate, loan 2 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate3", (getter)FinancialParameters_get_const_per_interest_rate3,(setter)FinancialParameters_set_const_per_interest_rate3,
	PyDoc_STR("*float*: Interest rate, loan 3 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate4", (getter)FinancialParameters_get_const_per_interest_rate4,(setter)FinancialParameters_set_const_per_interest_rate4,
	PyDoc_STR("*float*: Interest rate, loan 4 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_interest_rate5", (getter)FinancialParameters_get_const_per_interest_rate5,(setter)FinancialParameters_set_const_per_interest_rate5,
	PyDoc_STR("*float*: Interest rate, loan 5 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months1", (getter)FinancialParameters_get_const_per_months1,(setter)FinancialParameters_set_const_per_months1,
	PyDoc_STR("*float*: Months prior to operation, loan 1\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months2", (getter)FinancialParameters_get_const_per_months2,(setter)FinancialParameters_set_const_per_months2,
	PyDoc_STR("*float*: Months prior to operation, loan 2\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months3", (getter)FinancialParameters_get_const_per_months3,(setter)FinancialParameters_set_const_per_months3,
	PyDoc_STR("*float*: Months prior to operation, loan 3\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months4", (getter)FinancialParameters_get_const_per_months4,(setter)FinancialParameters_set_const_per_months4,
	PyDoc_STR("*float*: Months prior to operation, loan 4\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_months5", (getter)FinancialParameters_get_const_per_months5,(setter)FinancialParameters_set_const_per_months5,
	PyDoc_STR("*float*: Months prior to operation, loan 5\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent1", (getter)FinancialParameters_get_const_per_percent1,(setter)FinancialParameters_set_const_per_percent1,
	PyDoc_STR("*float*: Percent of total installed cost, loan 1 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent2", (getter)FinancialParameters_get_const_per_percent2,(setter)FinancialParameters_set_const_per_percent2,
	PyDoc_STR("*float*: Percent of total installed cost, loan 2 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent3", (getter)FinancialParameters_get_const_per_percent3,(setter)FinancialParameters_set_const_per_percent3,
	PyDoc_STR("*float*: Percent of total installed cost, loan 3 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent4", (getter)FinancialParameters_get_const_per_percent4,(setter)FinancialParameters_set_const_per_percent4,
	PyDoc_STR("*float*: Percent of total installed cost, loan 4 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_percent5", (getter)FinancialParameters_get_const_per_percent5,(setter)FinancialParameters_set_const_per_percent5,
	PyDoc_STR("*float*: Percent of total installed cost, loan 5 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate1", (getter)FinancialParameters_get_const_per_upfront_rate1,(setter)FinancialParameters_set_const_per_upfront_rate1,
	PyDoc_STR("*float*: Upfront fee on principal, loan 1 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate2", (getter)FinancialParameters_get_const_per_upfront_rate2,(setter)FinancialParameters_set_const_per_upfront_rate2,
	PyDoc_STR("*float*: Upfront fee on principal, loan 2 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate3", (getter)FinancialParameters_get_const_per_upfront_rate3,(setter)FinancialParameters_set_const_per_upfront_rate3,
	PyDoc_STR("*float*: Upfront fee on principal, loan 3 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate4", (getter)FinancialParameters_get_const_per_upfront_rate4,(setter)FinancialParameters_set_const_per_upfront_rate4,
	PyDoc_STR("*float*: Upfront fee on principal, loan 4 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
{"const_per_upfront_rate5", (getter)FinancialParameters_get_const_per_upfront_rate5,(setter)FinancialParameters_set_const_per_upfront_rate5,
	PyDoc_STR("*float*: Upfront fee on principal, loan 5 [%]\n\n**Required:**\nRequired if csp_financial_model<5|csp_financial_model=6"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.FinancialParameters",             /*tp_name*/
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
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
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
Outputs_new(SAM_FresnelPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "FresnelPhysical", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "FresnelPhysical", "Outputs")){
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
Outputs_get_A_field(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_A_field_nget, self->data_ptr);
}

static PyObject *
Outputs_get_A_loop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_A_loop_nget, self->data_ptr);
}

static PyObject *
Outputs_get_DP_pressure_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_DP_pressure_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_EqOpteff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_EqOpteff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cooling_tower_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_P_cooling_tower_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_P_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_P_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_out_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_P_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_plant_balance_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_P_plant_balance_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_field_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_Q_field_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_loop_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_Q_loop_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_loss_hdr_rnr_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_Q_loss_hdr_rnr_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_loss_receiver_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_Q_loss_receiver_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_Q_tes_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_SCAs_def(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_SCAs_def_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_field_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_field_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_out_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_T_field_out_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_loop_out_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_T_loop_out_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_pc_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_pc_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_rec_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_rec_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_V_hdr_max_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_V_hdr_max_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_V_hdr_min_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_V_hdr_min_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_bop_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_W_dot_bop_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_field_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_W_dot_field_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_W_dot_fixed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pump_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_W_dot_pump_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_sca_track(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_W_dot_sca_track_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_field_freeze_protection(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_annual_field_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_tes_freeze_protection(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_annual_tes_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_thermal_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_annual_thermal_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_aux_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_aux_design_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_dt_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_avg_dt_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_suboptimal_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_avg_suboptimal_rel_mip_gap_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_bop_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_bop_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_interest1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_interest2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_interest3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_interest4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_interest5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_interest_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_percent_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_percent_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_principal1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_principal2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_principal3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_principal4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_principal5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_principal_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_total1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_total2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_total3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_total4_nget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_const_per_total5_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_construction_financing_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_contingency_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_contingency_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_battery_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_cp_battery_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_system_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_cp_system_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_htf_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_cycle_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dP_field_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_dP_field_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_d_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_d_tank_nget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaP_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_deltaP_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_obj_relax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_obj_relax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_objective_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_pceff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_pceff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_presolve_nconstr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_presolve_nvar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qpbsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_qpbsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsf_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_qsf_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfprod_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_qsfprod_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_qsfsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_rel_mip_gap_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rev_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_rev_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_iter(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_solve_iter_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_solve_state_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_solve_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_subopt_flag(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_subopt_flag_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_tes_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_tes_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_thermeff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_thermeff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_wpb_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_disp_wpb_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_dot_field_int_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_e_dot_field_int_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_eff_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_loop_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_eff_loop_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_epc_total_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_epc_total_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_optical_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_eta_optical_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_f_htfmax_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_f_htfmax_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_f_htfmin_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_f_htfmin_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_field_area_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_htf_max_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_field_htf_max_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_field_htf_min_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_field_htf_min_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_fossil_backup_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_fossil_backup_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hl_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_hl_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hour_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_hour_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_htf_system_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_htf_system_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_installed_per_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_installed_per_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_sb_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_is_pc_sb_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_su_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_is_pc_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_rec_su_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_is_rec_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_loop_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_loop_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_loop_opt_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_loop_opt_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_loop_therm_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_loop_therm_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cold_tank_to_hot_tank(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_cold_tank_to_hot_tank_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cr_to_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_cr_to_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cycle_to_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_cycle_to_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_m_dot_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_delivered(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_field_delivered_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_recirc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_field_recirc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_to_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_field_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htfmax_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_m_dot_htfmax_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htfmin_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_m_dot_htfmin_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_loop(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_loop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_loop_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_m_dot_loop_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_to_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_pc_to_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_cold_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_tes_cold_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_tes_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_water_pc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_m_dot_water_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_mass_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_mass_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mdot_cycle_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_mdot_cycle_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mdot_field_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_mdot_field_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_nLoops_nget, self->data_ptr);
}

static PyObject *
Outputs_get_n_op_modes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_n_op_modes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_operating_modes_a_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_operating_modes_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_operating_modes_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_opt_derate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_opt_derate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_opt_normal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_opt_normal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_P_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_T_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_diams(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_lengths_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_mdot_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_vel_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_wallthk(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pipe_tes_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_plm_total_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_plm_total_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_power_plant_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_power_plant_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pricing_mult(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_pricing_mult_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dc_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_cycle_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_q_dot_cycle_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_on(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_est_cr_on_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_su(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_est_cr_su_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_ch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_est_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_est_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_freeze_prot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_freeze_prot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_htf_sf_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_htf_sf_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_loss_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_q_dot_loss_tes_des_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_pc_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_min(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_pc_min_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_sb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_pc_sb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_pc_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_piping_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_rec_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_thermal_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_dot_rec_thermal_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_field_des_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_q_field_des_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_field_des_ideal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_q_field_des_ideal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_sf_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_inc_sf_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_q_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rec_thermal_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_rec_thermal_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_recirculating(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_recirculating_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sales_tax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_sales_tax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sim_duration(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_sim_duration_nget, self->data_ptr);
}

static PyObject *
Outputs_get_site_improvements_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_site_improvements_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sm1_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_sm1_aperture_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sm1_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_sm1_nLoops_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solar_field_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_solar_field_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solar_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_solar_mult_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_system_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_cp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_tes_htf_cp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_dens(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_tes_htf_dens_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_max_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_tes_htf_max_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_min_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_tes_htf_min_temp_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tes_htf_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_tes_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_therm_eff_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_therm_eff_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_therm_eff_loop_des_SS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_therm_eff_loop_des_SS_nget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_total_Ap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_total_Ap_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_direct_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_total_direct_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_indirect_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_total_indirect_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_total_installed_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_total_land_area_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_tracking_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_total_tracking_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_ts_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_vol_min_nget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_FresnelPhysical_Outputs_vol_tank_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_FresnelPhysical_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"A_field", (getter)Outputs_get_A_field,(setter)0,
	PyDoc_STR("*float*: Total field aperture [m2]"),
 	NULL},
{"A_loop", (getter)Outputs_get_A_loop,(setter)0,
	PyDoc_STR("*float*: Aperture of a single loop [m2]"),
 	NULL},
{"DP_pressure_loss", (getter)Outputs_get_DP_pressure_loss,(setter)0,
	PyDoc_STR("*float*: Total loop pressure loss at design [bar]"),
 	NULL},
{"EqOpteff", (getter)Outputs_get_EqOpteff,(setter)0,
	PyDoc_STR("*sequence*: Field optical efficiency before defocus"),
 	NULL},
{"P_cooling_tower_tot", (getter)Outputs_get_P_cooling_tower_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"P_cycle", (getter)Outputs_get_P_cycle,(setter)0,
	PyDoc_STR("*sequence*: PC electrical power output: gross [MWe]"),
 	NULL},
{"P_fixed", (getter)Outputs_get_P_fixed,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power fixed load [MWe]"),
 	NULL},
{"P_out_net", (getter)Outputs_get_P_out_net,(setter)0,
	PyDoc_STR("*sequence*: System net electrical power [MWe]"),
 	NULL},
{"P_plant_balance_tot", (getter)Outputs_get_P_plant_balance_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power generation-dependent load [MWe]"),
 	NULL},
{"Q_field_des_SS", (getter)Outputs_get_Q_field_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State Field design thermal power [MWt]"),
 	NULL},
{"Q_loop_des_SS", (getter)Outputs_get_Q_loop_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State loop design thermal power [MWt]"),
 	NULL},
{"Q_loss_hdr_rnr_des_SS", (getter)Outputs_get_Q_loss_hdr_rnr_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State field heat loss from headers and runners [MWt]"),
 	NULL},
{"Q_loss_receiver_des_SS", (getter)Outputs_get_Q_loss_receiver_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State field heat loss from receiver [MWt]"),
 	NULL},
{"Q_tes_des", (getter)Outputs_get_Q_tes_des,(setter)0,
	PyDoc_STR("*float*: TES design capacity [MWt-hr]"),
 	NULL},
{"SCAs_def", (getter)Outputs_get_SCAs_def,(setter)0,
	PyDoc_STR("*sequence*: Field fraction of focused SCAs"),
 	NULL},
{"T_field_cold_in", (getter)Outputs_get_T_field_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_field_hot_out", (getter)Outputs_get_T_field_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_field_out_des_SS", (getter)Outputs_get_T_field_out_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State Field design outlet temperature [C]"),
 	NULL},
{"T_loop_out_des_SS", (getter)Outputs_get_T_loop_out_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State loop design outlet temperature [C]"),
 	NULL},
{"T_pc_in", (getter)Outputs_get_T_pc_in,(setter)0,
	PyDoc_STR("*sequence*: PC HTF inlet temperature [C]"),
 	NULL},
{"T_pc_out", (getter)Outputs_get_T_pc_out,(setter)0,
	PyDoc_STR("*sequence*: PC HTF outlet temperature [C]"),
 	NULL},
{"T_rec_cold_in", (getter)Outputs_get_T_rec_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_rec_hot_out", (getter)Outputs_get_T_rec_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"V_hdr_max_des_SS", (getter)Outputs_get_V_hdr_max_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State max header velocity [m/s]"),
 	NULL},
{"V_hdr_min_des_SS", (getter)Outputs_get_V_hdr_min_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State min header velocity [m/s]"),
 	NULL},
{"W_dot_bop_design", (getter)Outputs_get_W_dot_bop_design,(setter)0,
	PyDoc_STR("*float*: BOP parasitics at design [MWe]"),
 	NULL},
{"W_dot_field_pump", (getter)Outputs_get_W_dot_field_pump,(setter)0,
	PyDoc_STR("*sequence*: Field htf pumping power [MWe]"),
 	NULL},
{"W_dot_fixed", (getter)Outputs_get_W_dot_fixed,(setter)0,
	PyDoc_STR("*float*: Fixed parasitic at design [MWe]"),
 	NULL},
{"W_dot_pump_des_SS", (getter)Outputs_get_W_dot_pump_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State field pumping power [MWe]"),
 	NULL},
{"W_dot_sca_track", (getter)Outputs_get_W_dot_sca_track,(setter)0,
	PyDoc_STR("*sequence*: Field collector tracking power [MWe]"),
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Electrical source - Power cycle gross output [kWhe]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual net electrical energy w/ avail. derate [kWhe]"),
 	NULL},
{"annual_field_freeze_protection", (getter)Outputs_get_annual_field_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for field freeze protection [kWht]"),
 	NULL},
{"annual_tes_freeze_protection", (getter)Outputs_get_annual_tes_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for TES freeze protection [kWht]"),
 	NULL},
{"annual_thermal_consumption", (getter)Outputs_get_annual_thermal_consumption,(setter)0,
	PyDoc_STR("*float*: Annual thermal freeze protection required [kWht]"),
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	PyDoc_STR("*float*: Total annual water usage [m^3]"),
 	NULL},
{"aux_design", (getter)Outputs_get_aux_design,(setter)0,
	PyDoc_STR("*float*: Aux parasitics at design [MWe]"),
 	NULL},
{"avg_dt_des", (getter)Outputs_get_avg_dt_des,(setter)0,
	PyDoc_STR("*float*: Average field temp difference at design [C]"),
 	NULL},
{"avg_suboptimal_rel_mip_gap", (getter)Outputs_get_avg_suboptimal_rel_mip_gap,(setter)0,
	PyDoc_STR("*float*: Average suboptimal relative MIP gap [%]"),
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	PyDoc_STR("*sequence*: Resource Beam normal irradiance [W/m2]"),
 	NULL},
{"bop_cost", (getter)Outputs_get_bop_cost,(setter)0,
	PyDoc_STR("*float*: Balance of plant cost [$]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"const_per_interest1", (getter)Outputs_get_const_per_interest1,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 1 [$]"),
 	NULL},
{"const_per_interest2", (getter)Outputs_get_const_per_interest2,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 2 [$]"),
 	NULL},
{"const_per_interest3", (getter)Outputs_get_const_per_interest3,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 3 [$]"),
 	NULL},
{"const_per_interest4", (getter)Outputs_get_const_per_interest4,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 4 [$]"),
 	NULL},
{"const_per_interest5", (getter)Outputs_get_const_per_interest5,(setter)0,
	PyDoc_STR("*float*: Interest cost, loan 5 [$]"),
 	NULL},
{"const_per_interest_total", (getter)Outputs_get_const_per_interest_total,(setter)0,
	PyDoc_STR("*float*: Total interest costs, all loans [$]"),
 	NULL},
{"const_per_percent_total", (getter)Outputs_get_const_per_percent_total,(setter)0,
	PyDoc_STR("*float*: Total percent of installed costs, all loans [%]"),
 	NULL},
{"const_per_principal1", (getter)Outputs_get_const_per_principal1,(setter)0,
	PyDoc_STR("*float*: Principal, loan 1 [$]"),
 	NULL},
{"const_per_principal2", (getter)Outputs_get_const_per_principal2,(setter)0,
	PyDoc_STR("*float*: Principal, loan 2 [$]"),
 	NULL},
{"const_per_principal3", (getter)Outputs_get_const_per_principal3,(setter)0,
	PyDoc_STR("*float*: Principal, loan 3 [$]"),
 	NULL},
{"const_per_principal4", (getter)Outputs_get_const_per_principal4,(setter)0,
	PyDoc_STR("*float*: Principal, loan 4 [$]"),
 	NULL},
{"const_per_principal5", (getter)Outputs_get_const_per_principal5,(setter)0,
	PyDoc_STR("*float*: Principal, loan 5 [$]"),
 	NULL},
{"const_per_principal_total", (getter)Outputs_get_const_per_principal_total,(setter)0,
	PyDoc_STR("*float*: Total principal, all loans [$]"),
 	NULL},
{"const_per_total1", (getter)Outputs_get_const_per_total1,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 1 [$]"),
 	NULL},
{"const_per_total2", (getter)Outputs_get_const_per_total2,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 2 [$]"),
 	NULL},
{"const_per_total3", (getter)Outputs_get_const_per_total3,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 3 [$]"),
 	NULL},
{"const_per_total4", (getter)Outputs_get_const_per_total4,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 4 [$]"),
 	NULL},
{"const_per_total5", (getter)Outputs_get_const_per_total5,(setter)0,
	PyDoc_STR("*float*: Total financing cost, loan 5 [$]"),
 	NULL},
{"construction_financing_cost", (getter)Outputs_get_construction_financing_cost,(setter)0,
	PyDoc_STR("*float*: Total construction financing cost [$]"),
 	NULL},
{"contingency_cost", (getter)Outputs_get_contingency_cost,(setter)0,
	PyDoc_STR("*float*: Contingency cost [$]"),
 	NULL},
{"conversion_factor", (getter)Outputs_get_conversion_factor,(setter)0,
	PyDoc_STR("*float*: Gross to Net Conversion Factor [%]"),
 	NULL},
{"cp_battery_nameplate", (getter)Outputs_get_cp_battery_nameplate,(setter)0,
	PyDoc_STR("*float*: Battery nameplate [MWe]"),
 	NULL},
{"cp_system_nameplate", (getter)Outputs_get_cp_system_nameplate,(setter)0,
	PyDoc_STR("*float*: System capacity for capacity payments [MWe]"),
 	NULL},
{"cycle_htf_pump_power", (getter)Outputs_get_cycle_htf_pump_power,(setter)0,
	PyDoc_STR("*sequence*: PC HTF pump power [MWe]"),
 	NULL},
{"dP_field_des_SS", (getter)Outputs_get_dP_field_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State Field design total pressure drop [bar]"),
 	NULL},
{"d_tank", (getter)Outputs_get_d_tank,(setter)0,
	PyDoc_STR("*float*: Tank diameter [m]"),
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	PyDoc_STR("*sequence*: Field optical focus fraction"),
 	NULL},
{"deltaP_field", (getter)Outputs_get_deltaP_field,(setter)0,
	PyDoc_STR("*sequence*: Field pressure drop [bar]"),
 	NULL},
{"disp_obj_relax", (getter)Outputs_get_disp_obj_relax,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function - relaxed max"),
 	NULL},
{"disp_objective", (getter)Outputs_get_disp_objective,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function value"),
 	NULL},
{"disp_pceff_expected", (getter)Outputs_get_disp_pceff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle efficiency adj."),
 	NULL},
{"disp_presolve_nconstr", (getter)Outputs_get_disp_presolve_nconstr,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of constraints in problem"),
 	NULL},
{"disp_presolve_nvar", (getter)Outputs_get_disp_presolve_nvar,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of variables in problem"),
 	NULL},
{"disp_qpbsu_expected", (getter)Outputs_get_disp_qpbsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle startup energy [MWht]"),
 	NULL},
{"disp_qsf_expected", (getter)Outputs_get_disp_qsf_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field available energy [MWt]"),
 	NULL},
{"disp_qsfprod_expected", (getter)Outputs_get_disp_qsfprod_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field generation [MWt]"),
 	NULL},
{"disp_qsfsu_expected", (getter)Outputs_get_disp_qsfsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field startup enegy [MWt]"),
 	NULL},
{"disp_rel_mip_gap", (getter)Outputs_get_disp_rel_mip_gap,(setter)0,
	PyDoc_STR("*sequence*: Dispatch relative MIP gap"),
 	NULL},
{"disp_rev_expected", (getter)Outputs_get_disp_rev_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected revenue factor"),
 	NULL},
{"disp_solve_iter", (getter)Outputs_get_disp_solve_iter,(setter)0,
	PyDoc_STR("*sequence*: Dispatch iterations count"),
 	NULL},
{"disp_solve_state", (getter)Outputs_get_disp_solve_state,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver state"),
 	NULL},
{"disp_solve_time", (getter)Outputs_get_disp_solve_time,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver time [sec]"),
 	NULL},
{"disp_subopt_flag", (getter)Outputs_get_disp_subopt_flag,(setter)0,
	PyDoc_STR("*sequence*: Dispatch suboptimal solution flag"),
 	NULL},
{"disp_tes_expected", (getter)Outputs_get_disp_tes_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected TES charge level [MWht]"),
 	NULL},
{"disp_thermeff_expected", (getter)Outputs_get_disp_thermeff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected SF thermal efficiency adj."),
 	NULL},
{"disp_wpb_expected", (getter)Outputs_get_disp_wpb_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power generation [MWe]"),
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge state [MWht]"),
 	NULL},
{"e_dot_field_int_energy", (getter)Outputs_get_e_dot_field_int_energy,(setter)0,
	PyDoc_STR("*sequence*: Field change in material/htf internal energy [MWt]"),
 	NULL},
{"eff_des_SS", (getter)Outputs_get_eff_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State field total efficiency"),
 	NULL},
{"eff_loop_des_SS", (getter)Outputs_get_eff_loop_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State loop total efficiency"),
 	NULL},
{"epc_total_cost", (getter)Outputs_get_epc_total_cost,(setter)0,
	PyDoc_STR("*float*: EPC total cost [$]"),
 	NULL},
{"eta", (getter)Outputs_get_eta,(setter)0,
	PyDoc_STR("*sequence*: PC efficiency: gross"),
 	NULL},
{"eta_optical_des_SS", (getter)Outputs_get_eta_optical_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State optical efficiency"),
 	NULL},
{"f_htfmax_actual", (getter)Outputs_get_f_htfmax_actual,(setter)0,
	PyDoc_STR("*float*: Actual maximum loop mass flow rate fraction of design"),
 	NULL},
{"f_htfmin_actual", (getter)Outputs_get_f_htfmin_actual,(setter)0,
	PyDoc_STR("*float*: Actual minimum loop mass flow rate fraction of design"),
 	NULL},
{"field_area", (getter)Outputs_get_field_area,(setter)0,
	PyDoc_STR("*float*: Solar field area [acres]"),
 	NULL},
{"field_htf_max_temp", (getter)Outputs_get_field_htf_max_temp,(setter)0,
	PyDoc_STR("*float*: Maximum field htf temp [C]"),
 	NULL},
{"field_htf_min_temp", (getter)Outputs_get_field_htf_min_temp,(setter)0,
	PyDoc_STR("*float*: Minimum field htf temp [C]"),
 	NULL},
{"fossil_backup_cost", (getter)Outputs_get_fossil_backup_cost,(setter)0,
	PyDoc_STR("*float*: Fossil backup cost [$]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System net electrical power w/ avail. derate [kWe]"),
 	NULL},
{"hl_des", (getter)Outputs_get_hl_des,(setter)0,
	PyDoc_STR("*float*: Heat loss at design [W/m]"),
 	NULL},
{"hour_day", (getter)Outputs_get_hour_day,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"htf_system_cost", (getter)Outputs_get_htf_system_cost,(setter)0,
	PyDoc_STR("*float*: HTF system cost [$]"),
 	NULL},
{"installed_per_capacity", (getter)Outputs_get_installed_per_capacity,(setter)0,
	PyDoc_STR("*float*: Estimated total installed cost per net capacity ($/kW) [$/kW]"),
 	NULL},
{"is_pc_sb_allowed", (getter)Outputs_get_is_pc_sb_allowed,(setter)0,
	PyDoc_STR("*sequence*: is power cycle standby allowed"),
 	NULL},
{"is_pc_su_allowed", (getter)Outputs_get_is_pc_su_allowed,(setter)0,
	PyDoc_STR("*sequence*: is power cycle startup allowed"),
 	NULL},
{"is_rec_su_allowed", (getter)Outputs_get_is_rec_su_allowed,(setter)0,
	PyDoc_STR("*sequence*: is receiver startup allowed"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"loop_eff", (getter)Outputs_get_loop_eff,(setter)0,
	PyDoc_STR("*float*: Total loop conversion efficiency at design"),
 	NULL},
{"loop_opt_eff", (getter)Outputs_get_loop_opt_eff,(setter)0,
	PyDoc_STR("*float*: Loop optical efficiency at design"),
 	NULL},
{"loop_therm_eff", (getter)Outputs_get_loop_therm_eff,(setter)0,
	PyDoc_STR("*float*: Loop thermal efficiency at design"),
 	NULL},
{"m_dot_balance", (getter)Outputs_get_m_dot_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative mass flow balance error"),
 	NULL},
{"m_dot_cold_tank_to_hot_tank", (getter)Outputs_get_m_dot_cold_tank_to_hot_tank,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cold tank to hot tank [kg/s]"),
 	NULL},
{"m_dot_cr_to_tes_hot", (getter)Outputs_get_m_dot_cr_to_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: field to hot TES [kg/s]"),
 	NULL},
{"m_dot_cycle_to_field", (getter)Outputs_get_m_dot_cycle_to_field,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cycle to field [kg/s]"),
 	NULL},
{"m_dot_des_SS", (getter)Outputs_get_m_dot_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State Field mass flow rate [kg/s]"),
 	NULL},
{"m_dot_field_delivered", (getter)Outputs_get_m_dot_field_delivered,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow delivered [kg/s]"),
 	NULL},
{"m_dot_field_recirc", (getter)Outputs_get_m_dot_field_recirc,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow recirculated [kg/s]"),
 	NULL},
{"m_dot_field_to_cycle", (getter)Outputs_get_m_dot_field_to_cycle,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: field to cycle [kg/s]"),
 	NULL},
{"m_dot_htfmax_actual", (getter)Outputs_get_m_dot_htfmax_actual,(setter)0,
	PyDoc_STR("*float*: Actual maximum loop HTF flow rate [kg/s]"),
 	NULL},
{"m_dot_htfmin_actual", (getter)Outputs_get_m_dot_htfmin_actual,(setter)0,
	PyDoc_STR("*float*: Actual minimum loop HTF flow rate [kg/s]"),
 	NULL},
{"m_dot_loop", (getter)Outputs_get_m_dot_loop,(setter)0,
	PyDoc_STR("*sequence*: Receiver mass flow rate [kg/s]"),
 	NULL},
{"m_dot_loop_des_SS", (getter)Outputs_get_m_dot_loop_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State Loop mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc", (getter)Outputs_get_m_dot_pc,(setter)0,
	PyDoc_STR("*sequence*: PC HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_to_tes_cold", (getter)Outputs_get_m_dot_pc_to_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cycle to cold TES [kg/s]"),
 	NULL},
{"m_dot_tes_cold_out", (getter)Outputs_get_m_dot_tes_cold_out,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: TES cold out [kg/s]"),
 	NULL},
{"m_dot_tes_hot_out", (getter)Outputs_get_m_dot_tes_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: TES hot out [kg/s]"),
 	NULL},
{"m_dot_water_pc", (getter)Outputs_get_m_dot_water_pc,(setter)0,
	PyDoc_STR("*sequence*: PC water consumption: makeup + cooling [kg/s]"),
 	NULL},
{"mass_tes_cold", (getter)Outputs_get_mass_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold tank mass (end) [kg]"),
 	NULL},
{"mass_tes_hot", (getter)Outputs_get_mass_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot tank mass (end) [kg]"),
 	NULL},
{"mdot_cycle_des", (getter)Outputs_get_mdot_cycle_des,(setter)0,
	PyDoc_STR("*float*: PC mass flow rate at design [kg/s]"),
 	NULL},
{"mdot_field_des", (getter)Outputs_get_mdot_field_des,(setter)0,
	PyDoc_STR("*float*: Field design HTF mass flow rate [kg/s]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly AC energy in Year 1 [kWh]"),
 	NULL},
{"nLoops", (getter)Outputs_get_nLoops,(setter)0,
	PyDoc_STR("*float*: Number of loops in the field"),
 	NULL},
{"n_op_modes", (getter)Outputs_get_n_op_modes,(setter)0,
	PyDoc_STR("*sequence*: Operating modes in reporting timestep"),
 	NULL},
{"nameplate", (getter)Outputs_get_nameplate,(setter)0,
	PyDoc_STR("*float*: Nameplate capacity [MWe]"),
 	NULL},
{"op_mode_1", (getter)Outputs_get_op_mode_1,(setter)0,
	PyDoc_STR("*sequence*: 1st operating mode"),
 	NULL},
{"op_mode_2", (getter)Outputs_get_op_mode_2,(setter)0,
	PyDoc_STR("*sequence*: 2nd op. mode, if applicable"),
 	NULL},
{"op_mode_3", (getter)Outputs_get_op_mode_3,(setter)0,
	PyDoc_STR("*sequence*: 3rd op. mode, if applicable"),
 	NULL},
{"operating_modes_a", (getter)Outputs_get_operating_modes_a,(setter)0,
	PyDoc_STR("*sequence*: First 3 operating modes tried"),
 	NULL},
{"operating_modes_b", (getter)Outputs_get_operating_modes_b,(setter)0,
	PyDoc_STR("*sequence*: Next 3 operating modes tried"),
 	NULL},
{"operating_modes_c", (getter)Outputs_get_operating_modes_c,(setter)0,
	PyDoc_STR("*sequence*: Final 3 operating modes tried"),
 	NULL},
{"opt_derate", (getter)Outputs_get_opt_derate,(setter)0,
	PyDoc_STR("*float*: Receiver optical derate"),
 	NULL},
{"opt_normal", (getter)Outputs_get_opt_normal,(setter)0,
	PyDoc_STR("*float*: Collector optical loss at normal incidence"),
 	NULL},
{"pipe_tes_P_dsn", (getter)Outputs_get_pipe_tes_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Pressure in TES pipes at design conditions [bar]"),
 	NULL},
{"pipe_tes_T_dsn", (getter)Outputs_get_pipe_tes_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Temperature in TES pipes at design conditions [C]"),
 	NULL},
{"pipe_tes_diams", (getter)Outputs_get_pipe_tes_diams,(setter)0,
	PyDoc_STR("*sequence*: Pipe diameters in TES [m]"),
 	NULL},
{"pipe_tes_lengths", (getter)Outputs_get_pipe_tes_lengths,(setter)0,
	PyDoc_STR("*sequence*: Pipe lengths in TES [m]"),
 	NULL},
{"pipe_tes_mdot_dsn", (getter)Outputs_get_pipe_tes_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Mass flow TES pipes at design conditions [kg/s]"),
 	NULL},
{"pipe_tes_vel_dsn", (getter)Outputs_get_pipe_tes_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Velocity in TES pipes at design conditions [m/s]"),
 	NULL},
{"pipe_tes_wallthk", (getter)Outputs_get_pipe_tes_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Pipe wall thickness in TES [m]"),
 	NULL},
{"plm_total_cost", (getter)Outputs_get_plm_total_cost,(setter)0,
	PyDoc_STR("*float*: Total land cost [$]"),
 	NULL},
{"power_plant_cost", (getter)Outputs_get_power_plant_cost,(setter)0,
	PyDoc_STR("*float*: Power plant cost [$]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"pricing_mult", (getter)Outputs_get_pricing_mult,(setter)0,
	PyDoc_STR("*sequence*: PPA price multiplier"),
 	NULL},
{"q_balance", (getter)Outputs_get_q_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative energy balance error"),
 	NULL},
{"q_ch_tes", (getter)Outputs_get_q_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge thermal power [MWt]"),
 	NULL},
{"q_dc_tes", (getter)Outputs_get_q_dc_tes,(setter)0,
	PyDoc_STR("*sequence*: TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_cycle_des", (getter)Outputs_get_q_dot_cycle_des,(setter)0,
	PyDoc_STR("*float*: PC thermal input at design [MWt]"),
 	NULL},
{"q_dot_est_cr_on", (getter)Outputs_get_q_dot_est_cr_on,(setter)0,
	PyDoc_STR("*sequence*: Estimate rec. thermal power TO HTF [MWt]"),
 	NULL},
{"q_dot_est_cr_su", (getter)Outputs_get_q_dot_est_cr_su,(setter)0,
	PyDoc_STR("*sequence*: Estimate rec. startup thermal power [MWt]"),
 	NULL},
{"q_dot_est_tes_ch", (getter)Outputs_get_q_dot_est_tes_ch,(setter)0,
	PyDoc_STR("*sequence*: Estimate max TES charge thermal power [MWt]"),
 	NULL},
{"q_dot_est_tes_dc", (getter)Outputs_get_q_dot_est_tes_dc,(setter)0,
	PyDoc_STR("*sequence*: Estimate max TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_freeze_prot", (getter)Outputs_get_q_dot_freeze_prot,(setter)0,
	PyDoc_STR("*sequence*: Field freeze protection required [MWt]"),
 	NULL},
{"q_dot_htf_sf_out", (getter)Outputs_get_q_dot_htf_sf_out,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power leaving in HTF [MWt]"),
 	NULL},
{"q_dot_loss_tes_des", (getter)Outputs_get_q_dot_loss_tes_des,(setter)0,
	PyDoc_STR("*float*: Estimated TES Heat Loss [MW]"),
 	NULL},
{"q_dot_pc_max", (getter)Outputs_get_q_dot_pc_max,(setter)0,
	PyDoc_STR("*sequence*: Max thermal power to PC [MWt]"),
 	NULL},
{"q_dot_pc_min", (getter)Outputs_get_q_dot_pc_min,(setter)0,
	PyDoc_STR("*sequence*: Thermal power for PC min operation [MWt]"),
 	NULL},
{"q_dot_pc_sb", (getter)Outputs_get_q_dot_pc_sb,(setter)0,
	PyDoc_STR("*sequence*: Thermal power for PC standby [MWt]"),
 	NULL},
{"q_dot_pc_startup", (getter)Outputs_get_q_dot_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal power [MWt]"),
 	NULL},
{"q_dot_pc_target", (getter)Outputs_get_q_dot_pc_target,(setter)0,
	PyDoc_STR("*sequence*: Target thermal power to PC [MWt]"),
 	NULL},
{"q_dot_piping_loss", (getter)Outputs_get_q_dot_piping_loss,(setter)0,
	PyDoc_STR("*sequence*: Field piping thermal losses [MWt]"),
 	NULL},
{"q_dot_rec_abs", (getter)Outputs_get_q_dot_rec_abs,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power absorbed [MWt]"),
 	NULL},
{"q_dot_rec_inc", (getter)Outputs_get_q_dot_rec_inc,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power incident [MWt]"),
 	NULL},
{"q_dot_rec_thermal_loss", (getter)Outputs_get_q_dot_rec_thermal_loss,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal losses [MWt]"),
 	NULL},
{"q_field_des_actual", (getter)Outputs_get_q_field_des_actual,(setter)0,
	PyDoc_STR("*float*: Design-point thermal power from the solar field limited by mass flow [MW]"),
 	NULL},
{"q_field_des_ideal", (getter)Outputs_get_q_field_des_ideal,(setter)0,
	PyDoc_STR("*float*: Design-point thermal power from the solar field with no limit [MW]"),
 	NULL},
{"q_inc_sf_tot", (getter)Outputs_get_q_inc_sf_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_pb", (getter)Outputs_get_q_pb,(setter)0,
	PyDoc_STR("*sequence*: PC input energy [MWt]"),
 	NULL},
{"q_pc_startup", (getter)Outputs_get_q_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal energy [MWht]"),
 	NULL},
{"q_tes_heater", (getter)Outputs_get_q_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"rec_thermal_eff", (getter)Outputs_get_rec_thermal_eff,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal efficiency"),
 	NULL},
{"recirculating", (getter)Outputs_get_recirculating,(setter)0,
	PyDoc_STR("*sequence*: Field recirculating (bypass valve open) [-]"),
 	NULL},
{"rh", (getter)Outputs_get_rh,(setter)0,
	PyDoc_STR("*sequence*: Resource Relative Humidity [%]"),
 	NULL},
{"sales_tax_total", (getter)Outputs_get_sales_tax_total,(setter)0,
	PyDoc_STR("*float*: Sales tax total [$]"),
 	NULL},
{"sim_duration", (getter)Outputs_get_sim_duration,(setter)0,
	PyDoc_STR("*float*: Computational time of timeseries simulation [s]"),
 	NULL},
{"site_improvements_cost", (getter)Outputs_get_site_improvements_cost,(setter)0,
	PyDoc_STR("*float*: Site improvements cost [$]"),
 	NULL},
{"sm1_aperture", (getter)Outputs_get_sm1_aperture,(setter)0,
	PyDoc_STR("*float*: Total required aperture, SM=1 [m2]"),
 	NULL},
{"sm1_nLoops", (getter)Outputs_get_sm1_nLoops,(setter)0,
	PyDoc_STR("*float*: Required number of loops, SM=1"),
 	NULL},
{"solar_field_cost", (getter)Outputs_get_solar_field_cost,(setter)0,
	PyDoc_STR("*float*: Solar field cost [$]"),
 	NULL},
{"solar_mult", (getter)Outputs_get_solar_mult,(setter)0,
	PyDoc_STR("*float*: Actual solar multiple"),
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Azimuth [deg]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"system_capacity", (getter)Outputs_get_system_capacity,(setter)0,
	PyDoc_STR("*float*: System capacity [kWe]"),
 	NULL},
{"tank_losses", (getter)Outputs_get_tank_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"tes_htf_cp", (getter)Outputs_get_tes_htf_cp,(setter)0,
	PyDoc_STR("*float*: Storage htf specific heat [kJ/kg-K]"),
 	NULL},
{"tes_htf_dens", (getter)Outputs_get_tes_htf_dens,(setter)0,
	PyDoc_STR("*float*: Storage htf density [kg/m3]"),
 	NULL},
{"tes_htf_max_temp", (getter)Outputs_get_tes_htf_max_temp,(setter)0,
	PyDoc_STR("*float*: Maximum storage htf temp [C]"),
 	NULL},
{"tes_htf_min_temp", (getter)Outputs_get_tes_htf_min_temp,(setter)0,
	PyDoc_STR("*float*: Minimum storage htf temp [C]"),
 	NULL},
{"tes_htf_pump_power", (getter)Outputs_get_tes_htf_pump_power,(setter)0,
	PyDoc_STR("*sequence*: TES HTF pump power [MWe]"),
 	NULL},
{"therm_eff_des_SS", (getter)Outputs_get_therm_eff_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State field optical efficiency"),
 	NULL},
{"therm_eff_loop_des_SS", (getter)Outputs_get_therm_eff_loop_des_SS,(setter)0,
	PyDoc_STR("*float*: Steady State loop optical efficiency"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"total_Ap", (getter)Outputs_get_total_Ap,(setter)0,
	PyDoc_STR("*float*: Actual field aperture [m2]"),
 	NULL},
{"total_direct_cost", (getter)Outputs_get_total_direct_cost,(setter)0,
	PyDoc_STR("*float*: Total direct cost [$]"),
 	NULL},
{"total_indirect_cost", (getter)Outputs_get_total_indirect_cost,(setter)0,
	PyDoc_STR("*float*: Total direct cost [$]"),
 	NULL},
{"total_installed_cost", (getter)Outputs_get_total_installed_cost,(setter)0,
	PyDoc_STR("*float*: Total installed cost [$]"),
 	NULL},
{"total_land_area", (getter)Outputs_get_total_land_area,(setter)0,
	PyDoc_STR("*float*: Total land area [acres]"),
 	NULL},
{"total_tracking_power", (getter)Outputs_get_total_tracking_power,(setter)0,
	PyDoc_STR("*float*: Design tracking power [MW]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: CSP operating Time-of-use value"),
 	NULL},
{"ts_cost", (getter)Outputs_get_ts_cost,(setter)0,
	PyDoc_STR("*float*: Thermal storage cost [$]"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"vol_min", (getter)Outputs_get_vol_min,(setter)0,
	PyDoc_STR("*float*: Minimum Fluid Volume [m3]"),
 	NULL},
{"vol_tank", (getter)Outputs_get_vol_tank,(setter)0,
	PyDoc_STR("*float*: Total tank volume [m3]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Resource Wind Speed [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical.Outputs",             /*tp_name*/
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
 * FresnelPhysical
 */

static PyTypeObject FresnelPhysical_Type;

static CmodObject *
newFresnelPhysicalObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &FresnelPhysical_Type);

	PySAM_TECH_ATTR()

	PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* ColRec_obj = ColRec_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ColRec", ColRec_obj);
	Py_DECREF(ColRec_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* UserDefinedPC_obj = UserDefinedPC_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "UserDefinedPC", UserDefinedPC_obj);
	Py_DECREF(UserDefinedPC_obj);

	PyObject* Storage_obj = Storage_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Storage", Storage_obj);
	Py_DECREF(Storage_obj);

	PyObject* Tou_obj = Tou_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Tou", Tou_obj);
	Py_DECREF(Tou_obj);

	PyObject* SysControl_obj = SysControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SysControl", SysControl_obj);
	Py_DECREF(SysControl_obj);

	PyObject* FinancialModel_obj = FinancialModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialModel", FinancialModel_obj);
	Py_DECREF(FinancialModel_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* TimeOfDeliveryFactors_obj = TimeOfDeliveryFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDeliveryFactors", TimeOfDeliveryFactors_obj);
	Py_DECREF(TimeOfDeliveryFactors_obj);

	PyObject* FinancialSolutionMode_obj = FinancialSolutionMode_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialSolutionMode", FinancialSolutionMode_obj);
	Py_DECREF(FinancialSolutionMode_obj);

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* CapitalCosts_obj = CapitalCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CapitalCosts", CapitalCosts_obj);
	Py_DECREF(CapitalCosts_obj);

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

	PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PyExc_Exception, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* FresnelPhysical methods */

static void
FresnelPhysical_dealloc(CmodObject *self)
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
FresnelPhysical_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
FresnelPhysical_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_FresnelPhysical_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
FresnelPhysical_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "FresnelPhysical"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FresnelPhysical_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "FresnelPhysical"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FresnelPhysical_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
FresnelPhysical_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
FresnelPhysical_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef FresnelPhysical_methods[] = {
		{"execute",           (PyCFunction)FresnelPhysical_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)FresnelPhysical_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'System Control': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)FresnelPhysical_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'System Control': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)FresnelPhysical_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)FresnelPhysical_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)FresnelPhysical_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)FresnelPhysical_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FresnelPhysical_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
FresnelPhysical_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject FresnelPhysical_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"FresnelPhysical",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)FresnelPhysical_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)FresnelPhysical_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)FresnelPhysical_getattro, /*tp_getattro*/
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
		FresnelPhysical_methods,      /*tp_methods*/
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


/* Function of no arguments returning new FresnelPhysical object */

static PyObject *
FresnelPhysical_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newFresnelPhysicalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
FresnelPhysical_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newFresnelPhysicalObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
FresnelPhysical_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newFresnelPhysicalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "FresnelPhysical", def) < 0) {
		FresnelPhysical_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
FresnelPhysical_from_existing(PyObject *self, PyObject *args)
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

	rv = newFresnelPhysicalObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "FresnelPhysical", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef FresnelPhysicalModule_methods[] = {
		{"new",             FresnelPhysical_new,         METH_VARARGS,
				PyDoc_STR("new() -> FresnelPhysical")},
		{"default",             FresnelPhysical_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> FresnelPhysical\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"MSLFAllEquityPartnershipFlip\"*\n\n		- *\"MSLFLeveragedPartnershipFlip\"*\n\n		- *\"MSLFMerchantPlant\"*\n\n		- *\"MSLFSaleLeaseback\"*\n\n		- *\"MSLFSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             FresnelPhysical_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> FresnelPhysical\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   FresnelPhysical_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> FresnelPhysical\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "FresnelPhysical");


static int
FresnelPhysicalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	FresnelPhysical_Type.tp_dict = PyDict_New();
	if (!FresnelPhysical_Type.tp_dict) { goto fail; }

	/// Add the SystemControl type object to FresnelPhysical_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the Weather type object to FresnelPhysical_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the SystemDesign type object to FresnelPhysical_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the SolarField type object to FresnelPhysical_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the ColRec type object to FresnelPhysical_Type
	if (PyType_Ready(&ColRec_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"ColRec",
				(PyObject*)&ColRec_Type);
	Py_DECREF(&ColRec_Type);

	/// Add the Powerblock type object to FresnelPhysical_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the UserDefinedPC type object to FresnelPhysical_Type
	if (PyType_Ready(&UserDefinedPC_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"UserDefinedPC",
				(PyObject*)&UserDefinedPC_Type);
	Py_DECREF(&UserDefinedPC_Type);

	/// Add the Storage type object to FresnelPhysical_Type
	if (PyType_Ready(&Storage_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"Storage",
				(PyObject*)&Storage_Type);
	Py_DECREF(&Storage_Type);

	/// Add the Tou type object to FresnelPhysical_Type
	if (PyType_Ready(&Tou_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"Tou",
				(PyObject*)&Tou_Type);
	Py_DECREF(&Tou_Type);

	/// Add the SysControl type object to FresnelPhysical_Type
	if (PyType_Ready(&SysControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"SysControl",
				(PyObject*)&SysControl_Type);
	Py_DECREF(&SysControl_Type);

	/// Add the FinancialModel type object to FresnelPhysical_Type
	if (PyType_Ready(&FinancialModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"FinancialModel",
				(PyObject*)&FinancialModel_Type);
	Py_DECREF(&FinancialModel_Type);

	/// Add the ElectricityRates type object to FresnelPhysical_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the TimeOfDeliveryFactors type object to FresnelPhysical_Type
	if (PyType_Ready(&TimeOfDeliveryFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"TimeOfDeliveryFactors",
				(PyObject*)&TimeOfDeliveryFactors_Type);
	Py_DECREF(&TimeOfDeliveryFactors_Type);

	/// Add the FinancialSolutionMode type object to FresnelPhysical_Type
	if (PyType_Ready(&FinancialSolutionMode_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"FinancialSolutionMode",
				(PyObject*)&FinancialSolutionMode_Type);
	Py_DECREF(&FinancialSolutionMode_Type);

	/// Add the Revenue type object to FresnelPhysical_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the CapitalCosts type object to FresnelPhysical_Type
	if (PyType_Ready(&CapitalCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"CapitalCosts",
				(PyObject*)&CapitalCosts_Type);
	Py_DECREF(&CapitalCosts_Type);

	/// Add the FinancialParameters type object to FresnelPhysical_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the Outputs type object to FresnelPhysical_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(FresnelPhysical_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the FresnelPhysical type object to the module
	if (PyType_Ready(&FresnelPhysical_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"FresnelPhysical",
				(PyObject*)&FresnelPhysical_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot FresnelPhysicalModule_slots[] = {
		{Py_mod_exec, FresnelPhysicalModule_exec},
		{0, NULL},
};

static struct PyModuleDef FresnelPhysicalModule = {
		PyModuleDef_HEAD_INIT,
		"FresnelPhysical",
		module_doc,
		0,
		FresnelPhysicalModule_methods,
		FresnelPhysicalModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_FresnelPhysical(void)
{
	return PyModuleDef_Init(&FresnelPhysicalModule);
}