#include <Python.h>

#include <SAM_Pvwattsv7.h>
#include <SAM_api.h>

#include "PySAM_utils.h"

#include "Pvwattsv7_eqns.c"


/*
 * SolarResource Group
 */ 

static PyTypeObject SolarResource_Type;

static PyObject *
SolarResource_new(SAM_Pvwattsv7 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv7", "SolarResource")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv7", "SolarResource")){
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
	return PySAM_array_getter(SAM_Pvwattsv7_SolarResource_albedo_aget, self->data_ptr);
}

static int
SolarResource_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv7_SolarResource_albedo_aset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Pvwattsv7_SolarResource_solar_resource_data_tget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Pvwattsv7_SolarResource_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv7_SolarResource_solar_resource_file_sget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvwattsv7_SolarResource_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef SolarResource_getset[] = {
{"albedo", (getter)SolarResource_get_albedo,(setter)SolarResource_set_albedo,
	PyDoc_STR("*sequence*: Albedo [frac]\n\n**Info:**\nif provided, will overwrite weather file albedo"),
 	NULL},
{"solar_resource_data", (getter)SolarResource_get_solar_resource_data,(setter)SolarResource_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather data\n\n**Info:**\ndn,df,tdry,wspd,lat,lon,tz,elev"),
 	NULL},
{"solar_resource_file", (getter)SolarResource_get_solar_resource_file,(setter)SolarResource_set_solar_resource_file,
	PyDoc_STR("*str*: Weather file path"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv7.SolarResource",             /*tp_name*/
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
Lifetime_new(SAM_Pvwattsv7 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv7", "Lifetime")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv7", "Lifetime")){
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
	return PySAM_double_getter(SAM_Pvwattsv7_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_dc_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Lifetime_dc_degradation_aget, self->data_ptr);
}

static int
Lifetime_set_dc_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv7_Lifetime_dc_degradation_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
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
		"Pvwattsv7.Lifetime",             /*tp_name*/
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
SystemDesign_new(SAM_Pvwattsv7 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv7", "SystemDesign")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv7", "SystemDesign")){
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
SystemDesign_get_ac_plant_max_f(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_ac_plant_max_f_nget, self->data_ptr);
}

static int
SystemDesign_set_ac_plant_max_f(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_ac_plant_max_f_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_array_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_array_type_nget, self->data_ptr);
}

static int
SystemDesign_set_array_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_array_type_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_batt_simple_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_batt_simple_enable_nget, self->data_ptr);
}

static int
SystemDesign_set_batt_simple_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_batt_simple_enable_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_bifaciality(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_bifaciality_nget, self->data_ptr);
}

static int
SystemDesign_set_bifaciality(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_bifaciality_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_dc_ac_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_dc_ac_ratio_nget, self->data_ptr);
}

static int
SystemDesign_set_dc_ac_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_dc_ac_ratio_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_en_snowloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_en_snowloss_nget, self->data_ptr);
}

static int
SystemDesign_set_en_snowloss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_en_snowloss_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_enable_wind_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_enable_wind_stow_nget, self->data_ptr);
}

static int
SystemDesign_set_enable_wind_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_enable_wind_stow_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gust_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_gust_factor_nget, self->data_ptr);
}

static int
SystemDesign_set_gust_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_gust_factor_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_inv_eff_nget, self->data_ptr);
}

static int
SystemDesign_set_inv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_inv_eff_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_losses_nget, self->data_ptr);
}

static int
SystemDesign_set_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_losses_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_module_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_module_type_nget, self->data_ptr);
}

static int
SystemDesign_set_module_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_module_type_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_rotlim_nget, self->data_ptr);
}

static int
SystemDesign_set_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_rotlim_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_soiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_SystemDesign_soiling_aget, self->data_ptr);
}

static int
SystemDesign_set_soiling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv7_SystemDesign_soiling_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_stow_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_stow_wspd_nget, self->data_ptr);
}

static int
SystemDesign_set_stow_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_stow_wspd_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_system_capacity_nget, self->data_ptr);
}

static int
SystemDesign_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_system_capacity_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_wind_stow_angle(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_wind_stow_angle_nget, self->data_ptr);
}

static int
SystemDesign_set_wind_stow_angle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_wind_stow_angle_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_xfmr_ll(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_xfmr_ll_nget, self->data_ptr);
}

static int
SystemDesign_set_xfmr_ll(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_xfmr_ll_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_xfmr_nll(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_SystemDesign_xfmr_nll_nget, self->data_ptr);
}

static int
SystemDesign_set_xfmr_nll(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_SystemDesign_xfmr_nll_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"ac_plant_max_f", (getter)SystemDesign_get_ac_plant_max_f,(setter)SystemDesign_set_ac_plant_max_f,
	PyDoc_STR("*float*: Plant controller max output (as f(ac_size)) [ratio]\n\n**Required:**\nFalse. Automatically set to 1.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"array_type", (getter)SystemDesign_get_array_type,(setter)SystemDesign_set_array_type,
	PyDoc_STR("*float*: Array type [0/1/2/3/4]\n\n**Info:**\nFixed Rack,Fixed Roof,1Axis,Backtracked,2Axis\n\n**Constraints:**\nMIN=0,MAX=4,INTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"azimuth", (getter)SystemDesign_get_azimuth,(setter)SystemDesign_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle [deg]\n\n**Options:**\nE=90,S=180,W=270\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\narray_type<4"),
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
	PyDoc_STR("*float*: Enable tracker stow at high wind speeds [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gcr", (getter)SystemDesign_get_gcr,(setter)SystemDesign_set_gcr,
	PyDoc_STR("*float*: Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0.01,MAX=0.99\n\n**Required:**\nFalse. Automatically set to 0.4 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gust_factor", (getter)SystemDesign_get_gust_factor,(setter)SystemDesign_set_gust_factor,
	PyDoc_STR("*float*: Wind gust estimation factor\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"inv_eff", (getter)SystemDesign_get_inv_eff,(setter)SystemDesign_set_inv_eff,
	PyDoc_STR("*float*: Inverter efficiency at rated power [%]\n\n**Constraints:**\nMIN=90,MAX=99.5\n\n**Required:**\nFalse. Automatically set to 96 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"losses", (getter)SystemDesign_get_losses,(setter)SystemDesign_set_losses,
	PyDoc_STR("*float*: Other DC losses [%]\n\n**Info:**\nTotal system losses\n\n**Constraints:**\nMIN=-5,MAX=99\n\n**Required:**\nTrue"),
 	NULL},
{"module_type", (getter)SystemDesign_get_module_type,(setter)SystemDesign_set_module_type,
	PyDoc_STR("*float*: Module type [0/1/2]\n\n**Info:**\nStandard,Premium,Thin film\n\n**Constraints:**\nMIN=0,MAX=2,INTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rotlim", (getter)SystemDesign_get_rotlim,(setter)SystemDesign_set_rotlim,
	PyDoc_STR("*float*: Tracker rotation angle limit [deg]\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
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
	PyDoc_STR("*float*: Tilt angle [deg]\n\n**Options:**\nH=0,V=90\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\narray_type<4"),
 	NULL},
{"wind_stow_angle", (getter)SystemDesign_get_wind_stow_angle,(setter)SystemDesign_set_wind_stow_angle,
	PyDoc_STR("*float*: Tracker angle for wind stow [deg]\n\n**Required:**\nFalse. Automatically set to 30.0 if not assigned explicitly or loaded from defaults."),
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
		"Pvwattsv7.SystemDesign",             /*tp_name*/
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
 * Shading Group
 */ 

static PyTypeObject Shading_Type;

static PyObject *
Shading_new(SAM_Pvwattsv7 data_ptr)
{
	PyObject* new_obj = Shading_Type.tp_alloc(&Shading_Type,0);

	VarGroupObject* Shading_obj = (VarGroupObject*)new_obj;

	Shading_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Shading methods */

static PyObject *
Shading_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv7", "Shading")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Shading_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Shading_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv7", "Shading")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Shading_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Shading_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Shading_methods[] = {
		{"assign",            (PyCFunction)Shading_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Shading_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Shading_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Shading_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Shading_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Shading_get_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv7_Shading_shading_azal_mget, self->data_ptr);
}

static int
Shading_set_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv7_Shading_shading_azal_mset, self->data_ptr);
}

static PyObject *
Shading_get_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_diff_nget, self->data_ptr);
}

static int
Shading_set_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_azal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_en_azal_nget, self->data_ptr);
}

static int
Shading_set_shading_en_azal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_en_azal_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_en_diff_nget, self->data_ptr);
}

static int
Shading_set_shading_en_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_en_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_en_mxh_nget, self->data_ptr);
}

static int
Shading_set_shading_en_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_en_mxh_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_en_string_option_nget, self->data_ptr);
}

static int
Shading_set_shading_en_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_en_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_en_timestep_nget, self->data_ptr);
}

static int
Shading_set_shading_en_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_en_timestep_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv7_Shading_shading_mxh_mget, self->data_ptr);
}

static int
Shading_set_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv7_Shading_shading_mxh_mset, self->data_ptr);
}

static PyObject *
Shading_get_shading_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Shading_shading_string_option_nget, self->data_ptr);
}

static int
Shading_set_shading_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_Shading_shading_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv7_Shading_shading_timestep_mget, self->data_ptr);
}

static int
Shading_set_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv7_Shading_shading_timestep_mset, self->data_ptr);
}

static PyGetSetDef Shading_getset[] = {
{"shading_azal", (getter)Shading_get_shading_azal,(setter)Shading_set_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Azimuth x altitude beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_diff", (getter)Shading_get_shading_diff,(setter)Shading_set_shading_diff,
	PyDoc_STR("*float*: Diffuse shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_en_azal", (getter)Shading_get_shading_en_azal,(setter)Shading_set_shading_en_azal,
	PyDoc_STR("*float*: Enable azimuth x altitude beam shading losses [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_en_diff", (getter)Shading_get_shading_en_diff,(setter)Shading_set_shading_en_diff,
	PyDoc_STR("*float*: Enable diffuse shading loss [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_en_mxh", (getter)Shading_get_shading_en_mxh,(setter)Shading_set_shading_en_mxh,
	PyDoc_STR("*float*: Enable month x Hour beam shading losses [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_en_string_option", (getter)Shading_get_shading_en_string_option,(setter)Shading_set_shading_en_string_option,
	PyDoc_STR("*float*: Enable shading string option [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_en_timestep", (getter)Shading_get_shading_en_timestep,(setter)Shading_set_shading_en_timestep,
	PyDoc_STR("*float*: Enable timestep beam shading losses [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_mxh", (getter)Shading_get_shading_mxh,(setter)Shading_set_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Month x Hour beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_string_option", (getter)Shading_get_shading_string_option,(setter)Shading_set_shading_string_option,
	PyDoc_STR("*float*: Shading string option\n\n**Options:**\n0=shadingdb,1=average,2=maximum,3=minimum\n\n**Constraints:**\nINTEGER,MIN=-1,MAX=4\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_timestep", (getter)Shading_get_shading_timestep,(setter)Shading_set_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Timestep beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Shading_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv7.Shading",             /*tp_name*/
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
		Shading_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Shading_getset,          /*tp_getset*/
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
 * AdjustmentFactors Group
 */ 

static PyTypeObject AdjustmentFactors_Type;

static PyObject *
AdjustmentFactors_new(SAM_Pvwattsv7 data_ptr)
{
	PyObject* new_obj = AdjustmentFactors_Type.tp_alloc(&AdjustmentFactors_Type,0);

	VarGroupObject* AdjustmentFactors_obj = (VarGroupObject*)new_obj;

	AdjustmentFactors_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* AdjustmentFactors methods */

static PyObject *
AdjustmentFactors_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv7", "AdjustmentFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AdjustmentFactors_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &AdjustmentFactors_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv7", "AdjustmentFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AdjustmentFactors_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &AdjustmentFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AdjustmentFactors_methods[] = {
		{"assign",            (PyCFunction)AdjustmentFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``AdjustmentFactors_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)AdjustmentFactors_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``AdjustmentFactors_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AdjustmentFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AdjustmentFactors_get_adjust_constant(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_AdjustmentFactors_adjust_constant_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_constant(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_AdjustmentFactors_adjust_constant_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_en_periods(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_AdjustmentFactors_adjust_en_periods_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_en_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_AdjustmentFactors_adjust_en_periods_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_en_timeindex(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_AdjustmentFactors_adjust_en_timeindex_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_en_timeindex(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv7_AdjustmentFactors_adjust_en_timeindex_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv7_AdjustmentFactors_adjust_periods_mget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv7_AdjustmentFactors_adjust_periods_mset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_timeindex(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_AdjustmentFactors_adjust_timeindex_aget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_timeindex(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv7_AdjustmentFactors_adjust_timeindex_aset, self->data_ptr);
}

static PyGetSetDef AdjustmentFactors_getset[] = {
{"adjust_constant", (getter)AdjustmentFactors_get_adjust_constant,(setter)AdjustmentFactors_set_adjust_constant,
	PyDoc_STR("*float*: Constant loss adjustment [%]\n\n**Info:**\n'adjust' and 'constant' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nMAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_en_periods", (getter)AdjustmentFactors_get_adjust_en_periods,(setter)AdjustmentFactors_set_adjust_en_periods,
	PyDoc_STR("*float*: Enable period-based adjustment factors [0/1]\n\n**Info:**\n'adjust' and 'en_periods' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_en_timeindex", (getter)AdjustmentFactors_get_adjust_en_timeindex,(setter)AdjustmentFactors_set_adjust_en_timeindex,
	PyDoc_STR("*float*: Enable lifetime adjustment factors [0/1]\n\n**Info:**\n'adjust' and 'en_timeindex' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_periods", (getter)AdjustmentFactors_get_adjust_periods,(setter)AdjustmentFactors_set_adjust_periods,
	PyDoc_STR("*sequence[sequence]*: Period-based adjustment factors [%]\n\n**Info:**\nSyntax: n x 3 matrix [ start, end, loss ]; Version upgrade: 'adjust' and 'periods' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nCOLS=3\n\n**Required:**\nRequired if adjust_en_periods=1"),
 	NULL},
{"adjust_timeindex", (getter)AdjustmentFactors_get_adjust_timeindex,(setter)AdjustmentFactors_set_adjust_timeindex,
	PyDoc_STR("*sequence*: Lifetime adjustment factors [%]\n\n**Info:**\n'adjust' and 'timeindex' separated by _ instead of : after SAM 2022.12.21\n\n**Required:**\nRequired if adjust_en_timeindex=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AdjustmentFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv7.AdjustmentFactors",             /*tp_name*/
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
		AdjustmentFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AdjustmentFactors_getset,          /*tp_getset*/
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
Outputs_new(SAM_Pvwattsv7 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv7", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv7", "Outputs")){
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
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_annual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_ac_annual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_ac_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv7_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_aoi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv7_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_dc_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dcsnowderate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_dcsnowderate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_df(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_df_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_dn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_gh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverter_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_inverter_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_location(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv7_Outputs_location_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_percent_complete(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_percent_complete_nget, self->data_ptr);
}

static PyObject *
Outputs_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_poa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_poa_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shad_beam_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_shad_beam_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_snow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_snow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_snow_cover(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_snow_cover_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_annual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_solrad_annual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_solrad_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ss_beam_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_ss_beam_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ss_gnd_diffuse_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_ss_gnd_diffuse_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ss_sky_diffuse_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_ss_sky_diffuse_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv7_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_sunup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_sunup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_tcell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tpoa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_tpoa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_shift_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_ts_shift_hours_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv7_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv7_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	PyDoc_STR("*sequence*: AC inverter output power [W]"),
 	NULL},
{"ac_annual", (getter)Outputs_get_ac_annual,(setter)0,
	PyDoc_STR("*float*: Annual AC output [kWh]"),
 	NULL},
{"ac_monthly", (getter)Outputs_get_ac_monthly,(setter)0,
	PyDoc_STR("*sequence*: AC output [kWh]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"aoi", (getter)Outputs_get_aoi,(setter)0,
	PyDoc_STR("*sequence*: Angle of incidence [deg]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
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
{"inverter_efficiency", (getter)Outputs_get_inverter_efficiency,(setter)0,
	PyDoc_STR("*float*: Inverter efficiency at rated power [%]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: Energy yield [kWh/kW]"),
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude [deg]"),
 	NULL},
{"location", (getter)Outputs_get_location,(setter)0,
	PyDoc_STR("*str*: Location ID"),
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	PyDoc_STR("*float*: Longitude [deg]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly energy gross [kWh]"),
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
{"snow_cover", (getter)Outputs_get_snow_cover,(setter)0,
	PyDoc_STR("*sequence*: Fraction of row covered by snow [0..1]"),
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
	PyDoc_STR("*float*: Time zone [hr]"),
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
		"Pvwattsv7.Outputs",             /*tp_name*/
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
 * Pvwattsv7
 */

static PyTypeObject Pvwattsv7_Type;

static CmodObject *
newPvwattsv7Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvwattsv7_Type);

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

	PyObject* Shading_obj = Shading_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Shading", Shading_obj);
	Py_DECREF(Shading_obj);

	PyObject* AdjustmentFactors_obj = AdjustmentFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AdjustmentFactors", AdjustmentFactors_obj);
	Py_DECREF(AdjustmentFactors_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Pvwattsv7 methods */

static void
Pvwattsv7_dealloc(CmodObject *self)
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
Pvwattsv7_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
Pvwattsv7_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv7_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv7_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv7"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv7_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv7"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv7_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvwattsv7_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pvwattsv7_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pvwattsv7_methods[] = {
		{"execute",           (PyCFunction)Pvwattsv7_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv7_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pvwattsv7_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv7_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvwattsv7_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pvwattsv7_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)Pvwattsv7_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{"Reopt_size_battery_post", (PyCFunction)Reopt_size_battery_post, METH_VARARGS | METH_KEYWORDS,
			Reopt_size_battery_post_doc},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv7_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv7_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv7_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv7",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv7_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv7_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv7_getattro, /*tp_getattro*/
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
		Pvwattsv7_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv7 object */

static PyObject *
Pvwattsv7_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvwattsv7Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv7_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv7Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv7_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv7Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv7", def) < 0) {
		Pvwattsv7_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv7_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvwattsv7Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv7", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv7Module_methods[] = {
		{"new",             Pvwattsv7_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv7")},
		{"default",             Pvwattsv7_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv7\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pvwattsv7_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv7\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pvwattsv7_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvwattsv7\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pvwattsv7");


static int
Pvwattsv7Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvwattsv7_Type.tp_dict = PyDict_New();
	if (!Pvwattsv7_Type.tp_dict) { goto fail; }

	/// Add the SolarResource type object to Pvwattsv7_Type
	if (PyType_Ready(&SolarResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv7_Type.tp_dict,
				"SolarResource",
				(PyObject*)&SolarResource_Type);
	Py_DECREF(&SolarResource_Type);

	/// Add the Lifetime type object to Pvwattsv7_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv7_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the SystemDesign type object to Pvwattsv7_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv7_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the Shading type object to Pvwattsv7_Type
	if (PyType_Ready(&Shading_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv7_Type.tp_dict,
				"Shading",
				(PyObject*)&Shading_Type);
	Py_DECREF(&Shading_Type);

	/// Add the AdjustmentFactors type object to Pvwattsv7_Type
	if (PyType_Ready(&AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv7_Type.tp_dict,
				"AdjustmentFactors",
				(PyObject*)&AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);

	/// Add the Outputs type object to Pvwattsv7_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv7_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv7 type object to the module
	if (PyType_Ready(&Pvwattsv7_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv7",
				(PyObject*)&Pvwattsv7_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv7Module_slots[] = {
		{Py_mod_exec, Pvwattsv7Module_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv7Module = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv7",
		module_doc,
		0,
		Pvwattsv7Module_methods,
		Pvwattsv7Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv7(void)
{
	return PyModuleDef_Init(&Pvwattsv7Module);
}