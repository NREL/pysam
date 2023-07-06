#include <Python.h>

#include <SAM_Pvwattsv8.h>
#include <SAM_api.h>

#include "PySAM_utils.h"

#include "Pvwattsv8_eqns.c"


/*
 * SolarResource Group
 */ 

static PyTypeObject SolarResource_Type;

static PyObject *
SolarResource_new(SAM_Pvwattsv8 data_ptr)
{
	PyObject* new_obj = SolarResource_Type.tp_alloc(&SolarResource_Type,0);

	VarGroupObject* SolarResource_obj = (VarGroupObject*)new_obj;

	SolarResource_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarResource methods */

static PyObject *
SolarResource_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv8", "SolarResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarResource_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarResource_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv8", "SolarResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarResource_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarResource_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarResource_methods[] = {
		{"assign",            (PyCFunction)SolarResource_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarResource_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarResource_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarResource_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarResource_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarResource_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_SolarResource_albedo_aget, self->data_ptr);
}

static int
SolarResource_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv8_SolarResource_albedo_aset, self->data_ptr);
}

static PyObject *
SolarResource_get_albedo_default(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SolarResource_albedo_default_nget, self->data_ptr);
}

static int
SolarResource_set_albedo_default(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SolarResource_albedo_default_nset, self->data_ptr);
}

static PyObject *
SolarResource_get_albedo_default_snow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SolarResource_albedo_default_snow_nget, self->data_ptr);
}

static int
SolarResource_set_albedo_default_snow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SolarResource_albedo_default_snow_nset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Pvwattsv8_SolarResource_solar_resource_data_tget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Pvwattsv8_SolarResource_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv8_SolarResource_solar_resource_file_sget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvwattsv8_SolarResource_solar_resource_file_sset, self->data_ptr);
}

static PyObject *
SolarResource_get_use_wf_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SolarResource_use_wf_albedo_nget, self->data_ptr);
}

static int
SolarResource_set_use_wf_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SolarResource_use_wf_albedo_nset, self->data_ptr);
}

static PyGetSetDef SolarResource_getset[] = {
{"albedo", (getter)SolarResource_get_albedo,(setter)SolarResource_set_albedo,
	PyDoc_STR("*sequence*: Albedo [0..1]\n\n**Info:**\nalbedo input array of 1 constant value or 12 monthly values"),
 	NULL},
{"albedo_default", (getter)SolarResource_get_albedo_default,(setter)SolarResource_set_albedo_default,
	PyDoc_STR("*float*: Albedo default [0..1]\n\n**Info:**\ndefault when albedo invalid\n\n**Required:**\nFalse. Automatically set to 0.2 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"albedo_default_snow", (getter)SolarResource_get_albedo_default_snow,(setter)SolarResource_set_albedo_default_snow,
	PyDoc_STR("*float*: Albedo default for snow [0..1]\n\n**Info:**\ndefault when albedo invalid and snow model enabled\n\n**Required:**\nFalse. Automatically set to 0.6 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"solar_resource_data", (getter)SolarResource_get_solar_resource_data,(setter)SolarResource_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather data\n\n**Info:**\ndn,df,tdry,wspd,lat,lon,tz,elev"),
 	NULL},
{"solar_resource_file", (getter)SolarResource_get_solar_resource_file,(setter)SolarResource_set_solar_resource_file,
	PyDoc_STR("*str*: Weather file path"),
 	NULL},
{"use_wf_albedo", (getter)SolarResource_get_use_wf_albedo,(setter)SolarResource_set_use_wf_albedo,
	PyDoc_STR("*float*: Use albedo from weather file [0/1]\n\n**Options:**\n0=albedo input, 1=albedo from weather file (use albedo default if invalid)\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv8.SolarResource",             /*tp_name*/
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
		SolarResource_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarResource_getset,          /*tp_getset*/
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
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Pvwattsv8 data_ptr)
{
	PyObject* new_obj = Lifetime_Type.tp_alloc(&Lifetime_Type,0);

	VarGroupObject* Lifetime_obj = (VarGroupObject*)new_obj;

	Lifetime_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Lifetime methods */

static PyObject *
Lifetime_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv8", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Lifetime_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv8", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Lifetime_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Lifetime_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Lifetime_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lifetime_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_dc_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Lifetime_dc_degradation_aget, self->data_ptr);
}

static int
Lifetime_set_dc_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv8_Lifetime_dc_degradation_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Analysis period [years]\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"dc_degradation", (getter)Lifetime_get_dc_degradation,(setter)Lifetime_set_dc_degradation,
	PyDoc_STR("*sequence*: Annual DC degradation for lifetime simulations [%/year]\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: Run lifetime simulation [0/1]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv8.Lifetime",             /*tp_name*/
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
		Lifetime_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Lifetime_getset,          /*tp_getset*/
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
SystemDesign_new(SAM_Pvwattsv8 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv8", "SystemDesign")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv8", "SystemDesign")){
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
SystemDesign_get_array_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_array_type_nget, self->data_ptr);
}

static int
SystemDesign_set_array_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_array_type_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_batt_simple_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_batt_simple_enable_nget, self->data_ptr);
}

static int
SystemDesign_set_batt_simple_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_batt_simple_enable_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_bifaciality(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_bifaciality_nget, self->data_ptr);
}

static int
SystemDesign_set_bifaciality(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_bifaciality_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_dc_ac_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_dc_ac_ratio_nget, self->data_ptr);
}

static int
SystemDesign_set_dc_ac_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_dc_ac_ratio_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_en_snowloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_en_snowloss_nget, self->data_ptr);
}

static int
SystemDesign_set_en_snowloss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_en_snowloss_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_enable_wind_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_enable_wind_stow_nget, self->data_ptr);
}

static int
SystemDesign_set_enable_wind_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_enable_wind_stow_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gust_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_gust_factor_nget, self->data_ptr);
}

static int
SystemDesign_set_gust_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_gust_factor_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_inv_eff_nget, self->data_ptr);
}

static int
SystemDesign_set_inv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_inv_eff_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_losses_nget, self->data_ptr);
}

static int
SystemDesign_set_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_losses_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_module_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_module_type_nget, self->data_ptr);
}

static int
SystemDesign_set_module_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_module_type_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_rotlim_nget, self->data_ptr);
}

static int
SystemDesign_set_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_rotlim_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv8_SystemDesign_shading_azal_mget, self->data_ptr);
}

static int
SystemDesign_set_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv8_SystemDesign_shading_azal_mset, self->data_ptr);
}

static PyObject *
SystemDesign_get_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_shading_diff_nget, self->data_ptr);
}

static int
SystemDesign_set_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_shading_diff_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv8_SystemDesign_shading_mxh_mget, self->data_ptr);
}

static int
SystemDesign_set_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv8_SystemDesign_shading_mxh_mset, self->data_ptr);
}

static PyObject *
SystemDesign_get_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv8_SystemDesign_shading_timestep_mget, self->data_ptr);
}

static int
SystemDesign_set_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv8_SystemDesign_shading_timestep_mset, self->data_ptr);
}

static PyObject *
SystemDesign_get_soiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_SystemDesign_soiling_aget, self->data_ptr);
}

static int
SystemDesign_set_soiling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv8_SystemDesign_soiling_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_stow_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_stow_wspd_nget, self->data_ptr);
}

static int
SystemDesign_set_stow_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_stow_wspd_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_system_capacity_nget, self->data_ptr);
}

static int
SystemDesign_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_system_capacity_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_wind_stow_angle(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_wind_stow_angle_nget, self->data_ptr);
}

static int
SystemDesign_set_wind_stow_angle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_wind_stow_angle_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_xfmr_ll(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_xfmr_ll_nget, self->data_ptr);
}

static int
SystemDesign_set_xfmr_ll(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_xfmr_ll_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_xfmr_nll(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_SystemDesign_xfmr_nll_nget, self->data_ptr);
}

static int
SystemDesign_set_xfmr_nll(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv8_SystemDesign_xfmr_nll_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"array_type", (getter)SystemDesign_get_array_type,(setter)SystemDesign_set_array_type,
	PyDoc_STR("*float*: Array type [0/1/2/3/4]\n\n**Info:**\nfixed open rack,fixed roof mount,1-axis tracking,1-axis backtracking,2-axis tracking\n\n**Constraints:**\nMIN=0,MAX=4,INTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"azimuth", (getter)SystemDesign_get_azimuth,(setter)SystemDesign_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle [degrees]\n\n**Options:**\nE=90,S=180,W=270\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\narray_type<4"),
 	NULL},
{"batt_simple_enable", (getter)SystemDesign_get_batt_simple_enable,(setter)SystemDesign_set_batt_simple_enable,
	PyDoc_STR("*float*: Enable Battery [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"bifaciality", (getter)SystemDesign_get_bifaciality,(setter)SystemDesign_set_bifaciality,
	PyDoc_STR("*float*: Module bifaciality factor [0 or ~0.65]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dc_ac_ratio", (getter)SystemDesign_get_dc_ac_ratio,(setter)SystemDesign_set_dc_ac_ratio,
	PyDoc_STR("*float*: DC to AC ratio [ratio]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 1.1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_snowloss", (getter)SystemDesign_get_en_snowloss,(setter)SystemDesign_set_en_snowloss,
	PyDoc_STR("*float*: Enable snow loss model [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"enable_wind_stow", (getter)SystemDesign_get_enable_wind_stow,(setter)SystemDesign_set_enable_wind_stow,
	PyDoc_STR("*float*: Enable tracker stow at high wind speeds [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gcr", (getter)SystemDesign_get_gcr,(setter)SystemDesign_set_gcr,
	PyDoc_STR("*float*: Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0.01,MAX=0.99\n\n**Required:**\nFalse. Automatically set to 0.3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gust_factor", (getter)SystemDesign_get_gust_factor,(setter)SystemDesign_set_gust_factor,
	PyDoc_STR("*float*: Wind gust estimation factor\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"inv_eff", (getter)SystemDesign_get_inv_eff,(setter)SystemDesign_set_inv_eff,
	PyDoc_STR("*float*: Inverter efficiency at rated power [%]\n\n**Constraints:**\nMIN=90,MAX=99.5\n\n**Required:**\nFalse. Automatically set to 96 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"losses", (getter)SystemDesign_get_losses,(setter)SystemDesign_set_losses,
	PyDoc_STR("*float*: Other DC losses [%]\n\n**Info:**\ntotal system losses\n\n**Constraints:**\nMIN=-5,MAX=99\n\n**Required:**\nTrue"),
 	NULL},
{"module_type", (getter)SystemDesign_get_module_type,(setter)SystemDesign_set_module_type,
	PyDoc_STR("*float*: Module type [0/1/2]\n\n**Info:**\nstandard,premium,thin film\n\n**Constraints:**\nMIN=0,MAX=2,INTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rotlim", (getter)SystemDesign_get_rotlim,(setter)SystemDesign_set_rotlim,
	PyDoc_STR("*float*: Tracker rotation angle limit [degrees]\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_azal", (getter)SystemDesign_get_shading_azal,(setter)SystemDesign_set_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Azimuth x altitude beam shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_diff", (getter)SystemDesign_get_shading_diff,(setter)SystemDesign_set_shading_diff,
	PyDoc_STR("*float*: Diffuse shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_mxh", (getter)SystemDesign_get_shading_mxh,(setter)SystemDesign_set_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Month x Hour beam shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_timestep", (getter)SystemDesign_get_shading_timestep,(setter)SystemDesign_set_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Time step beam shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"soiling", (getter)SystemDesign_get_soiling,(setter)SystemDesign_set_soiling,
	PyDoc_STR("*sequence*: Soiling loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"stow_wspd", (getter)SystemDesign_get_stow_wspd,(setter)SystemDesign_set_stow_wspd,
	PyDoc_STR("*float*: Tracker stow wind speed threshold [m/s]\n\n**Required:**\nFalse. Automatically set to 10 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_capacity", (getter)SystemDesign_get_system_capacity,(setter)SystemDesign_set_system_capacity,
	PyDoc_STR("*float*: System size (DC nameplate) [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)SystemDesign_get_tilt,(setter)SystemDesign_set_tilt,
	PyDoc_STR("*float*: Tilt angle [degrees]\n\n**Options:**\nH=0,V=90\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\narray_type<4"),
 	NULL},
{"wind_stow_angle", (getter)SystemDesign_get_wind_stow_angle,(setter)SystemDesign_set_wind_stow_angle,
	PyDoc_STR("*float*: Tracker angle for wind stow [degrees]\n\n**Required:**\nFalse. Automatically set to 30.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"xfmr_ll", (getter)SystemDesign_get_xfmr_ll,(setter)SystemDesign_set_xfmr_ll,
	PyDoc_STR("*float*: GSU transformer load loss (resistive) [%(ac)]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"xfmr_nll", (getter)SystemDesign_get_xfmr_nll,(setter)SystemDesign_set_xfmr_nll,
	PyDoc_STR("*float*: GSU transformer no load loss (iron core) [%(ac)]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv8.SystemDesign",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Pvwattsv8 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv8", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv8", "Outputs")){
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
Outputs_get_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_annual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_ac_annual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_annual_pre_adjust(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_ac_annual_pre_adjust_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_ac_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_pre_adjust(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_ac_pre_adjust_aget, self->data_ptr);
}

static PyObject *
Outputs_get_alb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_alb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv8_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_aoi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_capacity_factor_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv8_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_dc_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dcsnowderate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_dcsnowderate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_df(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_df_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_dn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_gh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_eff_output(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_inv_eff_output_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverter_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_inverter_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_location(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv8_Outputs_location_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_percent_complete(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_percent_complete_nget, self->data_ptr);
}

static PyObject *
Outputs_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_poa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_poa_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shad_beam_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_shad_beam_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_snow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_snow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_soiling_f(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_soiling_f_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_annual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_solrad_annual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_solrad_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ss_beam_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_ss_beam_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ss_gnd_diffuse_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_ss_gnd_diffuse_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ss_sky_diffuse_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_ss_sky_diffuse_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv8_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_sunup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_sunup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_tcell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tpoa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_tpoa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_shift_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_ts_shift_hours_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv8_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv8_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	PyDoc_STR("*sequence*: AC inverter output power [W]"),
 	NULL},
{"ac_annual", (getter)Outputs_get_ac_annual,(setter)0,
	PyDoc_STR("*float*: Annual AC output [kWh]"),
 	NULL},
{"ac_annual_pre_adjust", (getter)Outputs_get_ac_annual_pre_adjust,(setter)0,
	PyDoc_STR("*float*: Annual AC output before system availability [kWh]"),
 	NULL},
{"ac_monthly", (getter)Outputs_get_ac_monthly,(setter)0,
	PyDoc_STR("*sequence*: AC output [kWh]"),
 	NULL},
{"ac_pre_adjust", (getter)Outputs_get_ac_pre_adjust,(setter)0,
	PyDoc_STR("*sequence*: AC inverter output power before system availability [W]"),
 	NULL},
{"alb", (getter)Outputs_get_alb,(setter)0,
	PyDoc_STR("*sequence*: Albedo"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"aoi", (getter)Outputs_get_aoi,(setter)0,
	PyDoc_STR("*sequence*: Angle of incidence [degrees]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on nameplate DC capacity [%]"),
 	NULL},
{"capacity_factor_ac", (getter)Outputs_get_capacity_factor_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on total AC capacity [%]"),
 	NULL},
{"city", (getter)Outputs_get_city,(setter)0,
	PyDoc_STR("*str*: City"),
 	NULL},
{"dc", (getter)Outputs_get_dc,(setter)0,
	PyDoc_STR("*sequence*: DC inverter input power [W]"),
 	NULL},
{"dc_monthly", (getter)Outputs_get_dc_monthly,(setter)0,
	PyDoc_STR("*sequence*: DC output [kWh]"),
 	NULL},
{"dcsnowderate", (getter)Outputs_get_dcsnowderate,(setter)0,
	PyDoc_STR("*sequence*: DC power loss due to snow [%]"),
 	NULL},
{"df", (getter)Outputs_get_df,(setter)0,
	PyDoc_STR("*sequence*: Weather file diffuse irradiance [W/m2]"),
 	NULL},
{"dn", (getter)Outputs_get_dn,(setter)0,
	PyDoc_STR("*sequence*: Weather file beam irradiance [W/m2]"),
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	PyDoc_STR("*float*: Site elevation [m]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"gh", (getter)Outputs_get_gh,(setter)0,
	PyDoc_STR("*sequence*: Weather file global horizontal irradiance [W/m2]"),
 	NULL},
{"inv_eff_output", (getter)Outputs_get_inv_eff_output,(setter)0,
	PyDoc_STR("*sequence*: Inverter efficiency [%]"),
 	NULL},
{"inverter_efficiency", (getter)Outputs_get_inverter_efficiency,(setter)0,
	PyDoc_STR("*float*: Inverter efficiency at rated power [%]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: Energy yield [kWh/kW]"),
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude [degrees]"),
 	NULL},
{"location", (getter)Outputs_get_location,(setter)0,
	PyDoc_STR("*str*: Location ID"),
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	PyDoc_STR("*float*: Longitude [degrees]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly energy [kWh]"),
 	NULL},
{"percent_complete", (getter)Outputs_get_percent_complete,(setter)0,
	PyDoc_STR("*float*: Estimated percent of total completed simulation [%]"),
 	NULL},
{"poa", (getter)Outputs_get_poa,(setter)0,
	PyDoc_STR("*sequence*: Plane of array irradiance [W/m2]"),
 	NULL},
{"poa_monthly", (getter)Outputs_get_poa_monthly,(setter)0,
	PyDoc_STR("*sequence*: Plane of array irradiance [kWh/m2]"),
 	NULL},
{"shad_beam_factor", (getter)Outputs_get_shad_beam_factor,(setter)0,
	PyDoc_STR("*sequence*: External shading factor for beam radiation"),
 	NULL},
{"snow", (getter)Outputs_get_snow,(setter)0,
	PyDoc_STR("*sequence*: Weather file snow depth [cm]"),
 	NULL},
{"soiling_f", (getter)Outputs_get_soiling_f,(setter)0,
	PyDoc_STR("*sequence*: Soiling factor"),
 	NULL},
{"solrad_annual", (getter)Outputs_get_solrad_annual,(setter)0,
	PyDoc_STR("*float*: Daily average solar irradiance [kWh/m2/day]"),
 	NULL},
{"solrad_monthly", (getter)Outputs_get_solrad_monthly,(setter)0,
	PyDoc_STR("*sequence*: Daily average solar irradiance [kWh/m2/day]"),
 	NULL},
{"ss_beam_factor", (getter)Outputs_get_ss_beam_factor,(setter)0,
	PyDoc_STR("*sequence*: Calculated self-shading factor for beam radiation"),
 	NULL},
{"ss_gnd_diffuse_factor", (getter)Outputs_get_ss_gnd_diffuse_factor,(setter)0,
	PyDoc_STR("*sequence*: Calculated self-shading factor for ground-reflected diffuse radiation"),
 	NULL},
{"ss_sky_diffuse_factor", (getter)Outputs_get_ss_sky_diffuse_factor,(setter)0,
	PyDoc_STR("*sequence*: Calculated self-shading factor for sky diffuse radiation"),
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	PyDoc_STR("*str*: State"),
 	NULL},
{"sunup", (getter)Outputs_get_sunup,(setter)0,
	PyDoc_STR("*sequence*: Sun up over horizon [0/1]"),
 	NULL},
{"tamb", (getter)Outputs_get_tamb,(setter)0,
	PyDoc_STR("*sequence*: Weather file ambient temperature [C]"),
 	NULL},
{"tcell", (getter)Outputs_get_tcell,(setter)0,
	PyDoc_STR("*sequence*: Module temperature [C]"),
 	NULL},
{"tpoa", (getter)Outputs_get_tpoa,(setter)0,
	PyDoc_STR("*sequence*: Transmitted plane of array irradiance [W/m2]"),
 	NULL},
{"ts_shift_hours", (getter)Outputs_get_ts_shift_hours,(setter)0,
	PyDoc_STR("*float*: Time offset for interpreting time series outputs [hours]"),
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	PyDoc_STR("*float*: Time zone [UTC offset]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Weather file wind speed [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv8.Outputs",             /*tp_name*/
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
 * Pvwattsv8
 */

static PyTypeObject Pvwattsv8_Type;

static CmodObject *
newPvwattsv8Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvwattsv8_Type);

	PySAM_TECH_ATTR()

	PyObject* SolarResource_obj = SolarResource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarResource", SolarResource_obj);
	Py_DECREF(SolarResource_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

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

/* Pvwattsv8 methods */

static void
Pvwattsv8_dealloc(CmodObject *self)
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
Pvwattsv8_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv8_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv8_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv8"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv8_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv8"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv8_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvwattsv8_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pvwattsv8_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pvwattsv8_methods[] = {
		{"execute",           (PyCFunction)Pvwattsv8_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv8_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pvwattsv8_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv8_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvwattsv8_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pvwattsv8_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"Reopt_size_battery_post", (PyCFunction)Reopt_size_battery_post, METH_VARARGS | METH_KEYWORDS,
			Reopt_size_battery_post_doc},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv8_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv8_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv8_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv8",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv8_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv8_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv8_getattro, /*tp_getattro*/
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
		Pvwattsv8_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv8 object */

static PyObject *
Pvwattsv8_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvwattsv8Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv8_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv8Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv8_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv8Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv8", def) < 0) {
		Pvwattsv8_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv8_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvwattsv8Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv8", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv8Module_methods[] = {
		{"new",             Pvwattsv8_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv8")},
		{"default",             Pvwattsv8_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv8\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"FuelCellCommercial\"*\n\n		- *\"FuelCellSingleOwner\"*\n\n		- *\"PVWattsBatteryCommercial\"*\n\n		- *\"PVWattsBatteryHostDeveloper\"*\n\n		- *\"PVWattsBatteryResidential\"*\n\n		- *\"PVWattsBatteryThirdParty\"*\n\n		- *\"PVWattsAllEquityPartnershipFlip\"*\n\n		- *\"PVWattsCommercial\"*\n\n		- *\"PVWattsCommunitySolar\"*\n\n		- *\"PVWattsHostDeveloper\"*\n\n		- *\"PVWattsLCOECalculator\"*\n\n		- *\"PVWattsLeveragedPartnershipFlip\"*\n\n		- *\"PVWattsMerchantPlant\"*\n\n		- *\"PVWattsNone\"*\n\n		- *\"PVWattsResidential\"*\n\n		- *\"PVWattsSaleLeaseback\"*\n\n		- *\"PVWattsSingleOwner\"*\n\n		- *\"PVWattsThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pvwattsv8_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv8\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pvwattsv8_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvwattsv8\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Photovoltaic system using basic NREL PVWatts V8 algorithm. Does not do detailed degradation or loss modeling. If those are important, please use pvsamv1.");


static int
Pvwattsv8Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvwattsv8_Type.tp_dict = PyDict_New();
	if (!Pvwattsv8_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Pvwattsv8_Type
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
	PyDict_SetItemString(Pvwattsv8_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the SolarResource type object to Pvwattsv8_Type
	if (PyType_Ready(&SolarResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv8_Type.tp_dict,
				"SolarResource",
				(PyObject*)&SolarResource_Type);
	Py_DECREF(&SolarResource_Type);

	/// Add the Lifetime type object to Pvwattsv8_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv8_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the SystemDesign type object to Pvwattsv8_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv8_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the Outputs type object to Pvwattsv8_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv8_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv8 type object to the module
	if (PyType_Ready(&Pvwattsv8_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv8",
				(PyObject*)&Pvwattsv8_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv8Module_slots[] = {
		{Py_mod_exec, Pvwattsv8Module_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv8Module = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv8",
		module_doc,
		0,
		Pvwattsv8Module_methods,
		Pvwattsv8Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv8(void)
{
	return PyModuleDef_Init(&Pvwattsv8Module);
}