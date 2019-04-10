#include <Python.h>

#include <SAM_Pvwattsv5Lifetime.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Common Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Pvwattsv5Lifetime data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	CommonObject* Common_obj = (CommonObject*)new_obj;

	Common_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(CommonObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(CommonObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_system_use_lifetime_output(CommonObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Common_system_use_lifetime_output_fget, self->data_ptr);
}

static int
Common_set_system_use_lifetime_output(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_Common_system_use_lifetime_output_fset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"system_use_lifetime_output", (getter)Common_get_system_use_lifetime_output,(setter)Common_set_system_use_lifetime_output,
	"Run lifetime simulation [0/1], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.Common",             /*tp_name*/
		sizeof(CommonObject),          /*tp_basicsize*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
	 * FinancialAnalysisParameters Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} FinancialAnalysisParametersObject;

static PyTypeObject FinancialAnalysisParameters_Type;

static PyObject *
FinancialAnalysisParameters_new(SAM_Pvwattsv5Lifetime data_ptr)
{
	PyObject* new_obj = FinancialAnalysisParameters_Type.tp_alloc(&FinancialAnalysisParameters_Type,0);

	FinancialAnalysisParametersObject* FinancialAnalysisParameters_obj = (FinancialAnalysisParametersObject*)new_obj;

	FinancialAnalysisParameters_obj->data_ptr = data_ptr;

	return new_obj;
}

/* FinancialAnalysisParameters methods */

static PyObject *
FinancialAnalysisParameters_assign(FinancialAnalysisParametersObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "FinancialAnalysisParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialAnalysisParameters_export(FinancialAnalysisParametersObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialAnalysisParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialAnalysisParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialAnalysisParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)FinancialAnalysisParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialAnalysisParameters_get_analysis_period(FinancialAnalysisParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_FinancialAnalysisParameters_analysis_period_fget, self->data_ptr);
}

static int
FinancialAnalysisParameters_set_analysis_period(FinancialAnalysisParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_FinancialAnalysisParameters_analysis_period_fset, self->data_ptr);
}

static PyGetSetDef FinancialAnalysisParameters_getset[] = {
{"analysis_period", (getter)FinancialAnalysisParameters_get_analysis_period,(setter)FinancialAnalysisParameters_set_analysis_period,
	"Analysis period [years], number.\n Required if: system_use_lifetime_output=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialAnalysisParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.FinancialAnalysisParameters",             /*tp_name*/
		sizeof(FinancialAnalysisParametersObject),          /*tp_basicsize*/
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
		FinancialAnalysisParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialAnalysisParameters_getset,          /*tp_getset*/
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
	 * LifetimePV Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} LifetimePVObject;

static PyTypeObject LifetimePV_Type;

static PyObject *
LifetimePV_new(SAM_Pvwattsv5Lifetime data_ptr)
{
	PyObject* new_obj = LifetimePV_Type.tp_alloc(&LifetimePV_Type,0);

	LifetimePVObject* LifetimePV_obj = (LifetimePVObject*)new_obj;

	LifetimePV_obj->data_ptr = data_ptr;

	return new_obj;
}

/* LifetimePV methods */

static PyObject *
LifetimePV_assign(LifetimePVObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "LifetimePV")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LifetimePV_export(LifetimePVObject *self, PyObject *args)
{
	PyTypeObject* tp = &LifetimePV_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LifetimePV_methods[] = {
		{"assign",            (PyCFunction)LifetimePV_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)LifetimePV_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LifetimePV_get_dc_degradation(LifetimePVObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_LifetimePV_dc_degradation_aget, self->data_ptr);
}

static int
LifetimePV_set_dc_degradation(LifetimePVObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Pvwattsv5Lifetime_LifetimePV_dc_degradation_aset, self->data_ptr);
}

static PyGetSetDef LifetimePV_getset[] = {
{"dc_degradation", (getter)LifetimePV_get_dc_degradation,(setter)LifetimePV_set_dc_degradation,
	"Annual AC degradation [%/year], array.\n Required if: system_use_lifetime_output=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LifetimePV_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.LifetimePV",             /*tp_name*/
		sizeof(LifetimePVObject),          /*tp_basicsize*/
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
		LifetimePV_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LifetimePV_getset,          /*tp_getset*/
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
	 * Weather Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} WeatherObject;

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_Pvwattsv5Lifetime data_ptr)
{
	PyObject* new_obj = Weather_Type.tp_alloc(&Weather_Type,0);

	WeatherObject* Weather_obj = (WeatherObject*)new_obj;

	Weather_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Weather methods */

static PyObject *
Weather_assign(WeatherObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_export(WeatherObject *self, PyObject *args)
{
	PyTypeObject* tp = &Weather_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Weather_methods[] = {
		{"assign",            (PyCFunction)Weather_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_solar_resource_data(WeatherObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Pvwattsv5Lifetime_Weather_solar_resource_data_tget, self->data_ptr);
}

static int
Weather_set_solar_resource_data(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Pvwattsv5Lifetime_Weather_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
Weather_get_solar_resource_file(WeatherObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv5Lifetime_Weather_solar_resource_file_sget, self->data_ptr);
}

static int
Weather_set_solar_resource_file(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvwattsv5Lifetime_Weather_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"solar_resource_data", (getter)Weather_get_solar_resource_data,(setter)Weather_set_solar_resource_data,
	"Weather data [], table.\n dn,df,tdry,wspd,lat,lon,tz; Required if: ?.",
 	NULL},
{"solar_resource_file", (getter)Weather_get_solar_resource_file,(setter)Weather_set_solar_resource_file,
	"Weather file path [], string.\n Required if: ?.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.Weather",             /*tp_name*/
		sizeof(WeatherObject),          /*tp_basicsize*/
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
		Weather_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Weather_getset,          /*tp_getset*/
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
	 * PVWatts Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} PVWattsObject;

static PyTypeObject PVWatts_Type;

static PyObject *
PVWatts_new(SAM_Pvwattsv5Lifetime data_ptr)
{
	PyObject* new_obj = PVWatts_Type.tp_alloc(&PVWatts_Type,0);

	PVWattsObject* PVWatts_obj = (PVWattsObject*)new_obj;

	PVWatts_obj->data_ptr = data_ptr;

	return new_obj;
}

/* PVWatts methods */

static PyObject *
PVWatts_assign(PVWattsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "PVWatts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVWatts_export(PVWattsObject *self, PyObject *args)
{
	PyTypeObject* tp = &PVWatts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PVWatts_methods[] = {
		{"assign",            (PyCFunction)PVWatts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)PVWatts_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PVWatts_get_array_type(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_array_type_fget, self->data_ptr);
}

static int
PVWatts_set_array_type(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_array_type_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_azimuth(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_azimuth_fget, self->data_ptr);
}

static int
PVWatts_set_azimuth(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_azimuth_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_dc_ac_ratio(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_dc_ac_ratio_fget, self->data_ptr);
}

static int
PVWatts_set_dc_ac_ratio(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_dc_ac_ratio_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_gcr(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_gcr_fget, self->data_ptr);
}

static int
PVWatts_set_gcr(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_gcr_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_inv_eff(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_inv_eff_fget, self->data_ptr);
}

static int
PVWatts_set_inv_eff(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_inv_eff_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_losses(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_losses_fget, self->data_ptr);
}

static int
PVWatts_set_losses(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_losses_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_module_type(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_module_type_fget, self->data_ptr);
}

static int
PVWatts_set_module_type(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_module_type_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_azal(PVWattsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv5Lifetime_PVWatts_shading_azal_mget, self->data_ptr);
}

static int
PVWatts_set_shading_azal(PVWattsObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_shading_azal_mset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_diff(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_shading_diff_fget, self->data_ptr);
}

static int
PVWatts_set_shading_diff(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_shading_diff_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_mxh(PVWattsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv5Lifetime_PVWatts_shading_mxh_mget, self->data_ptr);
}

static int
PVWatts_set_shading_mxh(PVWattsObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_shading_mxh_mset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_timestep(PVWattsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv5Lifetime_PVWatts_shading_timestep_mget, self->data_ptr);
}

static int
PVWatts_set_shading_timestep(PVWattsObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_shading_timestep_mset, self->data_ptr);
}

static PyObject *
PVWatts_get_system_capacity(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_system_capacity_fget, self->data_ptr);
}

static int
PVWatts_set_system_capacity(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_system_capacity_fset, self->data_ptr);
}

static PyObject *
PVWatts_get_tilt(PVWattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_PVWatts_tilt_fget, self->data_ptr);
}

static int
PVWatts_set_tilt(PVWattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_PVWatts_tilt_fset, self->data_ptr);
}

static PyGetSetDef PVWatts_getset[] = {
{"array_type", (getter)PVWatts_get_array_type,(setter)PVWatts_set_array_type,
	"Array type [0/1/2/3/4], number.\n Fixed OR,Fixed Roof,1Axis,Backtracked,2Axis; Constraints: MIN=0,MAX=4,INTEGER; Required if: *.",
 	NULL},
{"azimuth", (getter)PVWatts_get_azimuth,(setter)PVWatts_set_azimuth,
	"Azimuth angle [deg], number.\n E=90,S=180,W=270; Constraints: MIN=0,MAX=360; Required if: array_type<4.",
 	NULL},
{"dc_ac_ratio", (getter)PVWatts_get_dc_ac_ratio,(setter)PVWatts_set_dc_ac_ratio,
	"DC to AC ratio [ratio], number.\n Constraints: POSITIVE; Required if: ?=1.1.",
 	NULL},
{"gcr", (getter)PVWatts_get_gcr,(setter)PVWatts_set_gcr,
	"Ground coverage ratio [0..1], number.\n Constraints: MIN=0,MAX=3; Required if: ?=0.4.",
 	NULL},
{"inv_eff", (getter)PVWatts_get_inv_eff,(setter)PVWatts_set_inv_eff,
	"Inverter efficiency at rated power [%], number.\n Constraints: MIN=90,MAX=99.5; Required if: ?=96.",
 	NULL},
{"losses", (getter)PVWatts_get_losses,(setter)PVWatts_set_losses,
	"System losses [%], number.\n Total system losses; Constraints: MIN=-5,MAX=99; Required if: *.",
 	NULL},
{"module_type", (getter)PVWatts_get_module_type,(setter)PVWatts_set_module_type,
	"Module type [0/1/2], number.\n Standard,Premium,Thin film; Constraints: MIN=0,MAX=2,INTEGER; Required if: ?=0.",
 	NULL},
{"shading_azal", (getter)PVWatts_get_shading_azal,(setter)PVWatts_set_shading_azal,
	"Azimuth x altitude beam shading loss [%], matrix.\n Required if: ?.",
 	NULL},
{"shading_diff", (getter)PVWatts_get_shading_diff,(setter)PVWatts_set_shading_diff,
	"Diffuse shading loss [%], number.\n Required if: ?.",
 	NULL},
{"shading_mxh", (getter)PVWatts_get_shading_mxh,(setter)PVWatts_set_shading_mxh,
	"Month x Hour beam shading loss [%], matrix.\n Required if: ?.",
 	NULL},
{"shading_timestep", (getter)PVWatts_get_shading_timestep,(setter)PVWatts_set_shading_timestep,
	"Time step beam shading loss [%], matrix.\n Required if: ?.",
 	NULL},
{"system_capacity", (getter)PVWatts_get_system_capacity,(setter)PVWatts_set_system_capacity,
	"System size (DC nameplate) [kW], number.\n Required if: *.",
 	NULL},
{"tilt", (getter)PVWatts_get_tilt,(setter)PVWatts_set_tilt,
	"Tilt angle [deg], number.\n H=0,V=90; Constraints: MIN=0,MAX=90; Required if: array_type<4.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVWatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.PVWatts",             /*tp_name*/
		sizeof(PVWattsObject),          /*tp_basicsize*/
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
		PVWatts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PVWatts_getset,          /*tp_getset*/
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
	 * Battwatts Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Pvwattsv5Lifetime   data_ptr;
} BattwattsObject;

static PyTypeObject Battwatts_Type;

static PyObject *
Battwatts_new(SAM_Pvwattsv5Lifetime data_ptr)
{
	PyObject* new_obj = Battwatts_Type.tp_alloc(&Battwatts_Type,0);

	BattwattsObject* Battwatts_obj = (BattwattsObject*)new_obj;

	Battwatts_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Battwatts methods */

static PyObject *
Battwatts_assign(BattwattsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "Battwatts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Battwatts_export(BattwattsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Battwatts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Battwatts_methods[] = {
		{"assign",            (PyCFunction)Battwatts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Battwatts_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battwatts_get_batt_simple_enable(BattwattsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Battwatts_batt_simple_enable_fget, self->data_ptr);
}

static int
Battwatts_set_batt_simple_enable(BattwattsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Pvwattsv5Lifetime_Battwatts_batt_simple_enable_fset, self->data_ptr);
}

static PyGetSetDef Battwatts_getset[] = {
{"batt_simple_enable", (getter)Battwatts_get_batt_simple_enable,(setter)Battwatts_set_batt_simple_enable,
	"Enable Battery [0/1], number.\n Constraints: BOOLEAN; Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Battwatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.Battwatts",             /*tp_name*/
		sizeof(BattwattsObject),          /*tp_basicsize*/
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
		Battwatts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Battwatts_getset,          /*tp_getset*/
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
	SAM_Pvwattsv5Lifetime   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Pvwattsv5Lifetime data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv5Lifetime", "Outputs")){
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
Outputs_get_ac(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_annual(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_ac_annual_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_monthly(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_ac_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_aoi(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_city(OutputsObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv5Lifetime_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_monthly(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_dc_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_df(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_df_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_dn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_elev_fget, self->data_ptr);
}

static PyObject *
Outputs_get_gh(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_gh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverter_efficiency(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_inverter_efficiency_fget, self->data_ptr);
}

static PyObject *
Outputs_get_inverter_model(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_inverter_model_fget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_lat_fget, self->data_ptr);
}

static PyObject *
Outputs_get_location(OutputsObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv5Lifetime_Outputs_location_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_lon_fget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_percent_complete(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_percent_complete_fget, self->data_ptr);
}

static PyObject *
Outputs_get_poa(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_poa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_monthly(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_poa_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shad_beam_factor(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_shad_beam_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_annual(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_solrad_annual_fget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_monthly(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_solrad_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_state(OutputsObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv5Lifetime_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_sunup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_sunup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tamb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tcell(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_tcell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tpoa(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_tpoa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_shift_hours(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_ts_shift_hours_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Pvwattsv5Lifetime_Outputs_tz_fget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv5Lifetime_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	"AC inverter power [W], array.",
 	NULL},
{"ac_annual", (getter)Outputs_get_ac_annual,(setter)0,
	"Annual AC system output [kWh], number.",
 	NULL},
{"ac_monthly", (getter)Outputs_get_ac_monthly,(setter)0,
	"AC system output [kWh], array.",
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual energy [kWh], number.",
 	NULL},
{"aoi", (getter)Outputs_get_aoi,(setter)0,
	"Angle of incidence [deg], array.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"city", (getter)Outputs_get_city,(setter)0,
	"City [], string.",
 	NULL},
{"dc", (getter)Outputs_get_dc,(setter)0,
	"DC array power [W], array.",
 	NULL},
{"dc_monthly", (getter)Outputs_get_dc_monthly,(setter)0,
	"DC array output [kWh], array.",
 	NULL},
{"df", (getter)Outputs_get_df,(setter)0,
	"Diffuse irradiance [W/m2], array.",
 	NULL},
{"dn", (getter)Outputs_get_dn,(setter)0,
	"Beam irradiance [W/m2], array.",
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	"Site elevation [m], number.",
 	NULL},
{"gh", (getter)Outputs_get_gh,(setter)0,
	"Global horizontal irradiance [W/m2], array.",
 	NULL},
{"inverter_efficiency", (getter)Outputs_get_inverter_efficiency,(setter)0,
	"Inverter efficiency at rated power [%], number.",
 	NULL},
{"inverter_model", (getter)Outputs_get_inverter_model,(setter)0,
	"Inverter model specifier [], number.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [], number.",
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	"Latitude [deg], number.",
 	NULL},
{"location", (getter)Outputs_get_location,(setter)0,
	"Location ID [], string.",
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	"Longitude [deg], number.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly energy [kWh], array.",
 	NULL},
{"percent_complete", (getter)Outputs_get_percent_complete,(setter)0,
	"Estimated percent of total comleted simulation [%], number.",
 	NULL},
{"poa", (getter)Outputs_get_poa,(setter)0,
	"Plane of array irradiance [W/m2], array.",
 	NULL},
{"poa_monthly", (getter)Outputs_get_poa_monthly,(setter)0,
	"Plane of array irradiance [kWh/m2], array.",
 	NULL},
{"shad_beam_factor", (getter)Outputs_get_shad_beam_factor,(setter)0,
	"Shading factor for beam radiation [], array.",
 	NULL},
{"solrad_annual", (getter)Outputs_get_solrad_annual,(setter)0,
	"Daily average solar irradiance [kWh/m2/day], number.",
 	NULL},
{"solrad_monthly", (getter)Outputs_get_solrad_monthly,(setter)0,
	"Daily average solar irradiance [kWh/m2/day], array.",
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	"State [], string.",
 	NULL},
{"sunup", (getter)Outputs_get_sunup,(setter)0,
	"Sun up over horizon [0/1], array.",
 	NULL},
{"tamb", (getter)Outputs_get_tamb,(setter)0,
	"Ambient temperature [C], array.",
 	NULL},
{"tcell", (getter)Outputs_get_tcell,(setter)0,
	"Module temperature [C], array.",
 	NULL},
{"tpoa", (getter)Outputs_get_tpoa,(setter)0,
	"Transmitted plane of array irradiance [W/m2], array.",
 	NULL},
{"ts_shift_hours", (getter)Outputs_get_ts_shift_hours,(setter)0,
	"Time offset for interpreting time series outputs [hours], number.",
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	"Time zone [hr], number.",
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	"Wind speed [m/s], array.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime.Outputs",             /*tp_name*/
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
 * Pvwattsv5Lifetime
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Pvwattsv5Lifetime   data_ptr;
} Pvwattsv5LifetimeObject;

static PyTypeObject Pvwattsv5Lifetime_Type;

#define Pvwattsv5LifetimeObject_Check(v)      (Py_TYPE(v) == &Pvwattsv5Lifetime_Type)

static Pvwattsv5LifetimeObject *
newPvwattsv5LifetimeObject(void* data_ptr)
{
	Pvwattsv5LifetimeObject *self;
	self = PyObject_New(Pvwattsv5LifetimeObject, &Pvwattsv5Lifetime_Type);

	PySAM_TECH_ATTR("Pvwattsv5Lifetime", SAM_Pvwattsv5Lifetime_construct)

PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

PyObject* FinancialAnalysisParameters_obj = FinancialAnalysisParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialAnalysisParameters", FinancialAnalysisParameters_obj);
	Py_DECREF(FinancialAnalysisParameters_obj);

PyObject* LifetimePV_obj = LifetimePV_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LifetimePV", LifetimePV_obj);
	Py_DECREF(LifetimePV_obj);

PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

PyObject* PVWatts_obj = PVWatts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVWatts", PVWatts_obj);
	Py_DECREF(PVWatts_obj);

PyObject* Battwatts_obj = Battwatts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Battwatts", Battwatts_obj);
	Py_DECREF(Battwatts_obj);

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

/* Pvwattsv5Lifetime methods */

static void
Pvwattsv5Lifetime_dealloc(Pvwattsv5LifetimeObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Pvwattsv5Lifetime_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Pvwattsv5Lifetime_execute(Pvwattsv5LifetimeObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv5Lifetime_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv5Lifetime_assign(Pvwattsv5LifetimeObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv5Lifetime"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv5Lifetime_export(Pvwattsv5LifetimeObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Pvwattsv5Lifetime_methods[] = {
		{"execute",            (PyCFunction)Pvwattsv5Lifetime_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv5Lifetime_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Pvwattsv5Lifetime_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv5Lifetime_getattro(Pvwattsv5LifetimeObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv5Lifetime_setattr(Pvwattsv5LifetimeObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv5Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv5Lifetime",            /*tp_name*/
		sizeof(Pvwattsv5LifetimeObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv5Lifetime_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv5Lifetime_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv5Lifetime_getattro, /*tp_getattro*/
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
		Pvwattsv5Lifetime_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv5Lifetime object */

static PyObject *
Pvwattsv5Lifetime_new(PyObject *self, PyObject *args)
{
	Pvwattsv5LifetimeObject *rv;
	rv = newPvwattsv5LifetimeObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv5Lifetime_wrap(PyObject *self, PyObject *args)
{
	Pvwattsv5LifetimeObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv5LifetimeObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv5Lifetime_default(PyObject *self, PyObject *args)
{
	Pvwattsv5LifetimeObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv5LifetimeObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv5Lifetime", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv5LifetimeModule_methods[] = {
		{"new",             Pvwattsv5Lifetime_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Pvwattsv5Lifetime object")},
		{"default",             Pvwattsv5Lifetime_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Pvwattsv5Lifetime object with financial model-specific default attributes\n"
				"Options: Single Owner, Commercial, ")},
		{"wrap",             Pvwattsv5Lifetime_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Pvwattsv5Lifetime object around existing PySSC data")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Refer to http://www.github.com/nrel/PySAM for source code.");


static int
Pvwattsv5LifetimeModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Pvwattsv5Lifetime_Type.tp_dict = PyDict_New();
	if (!Pvwattsv5Lifetime_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Pvwattsv5Lifetime_Type
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
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Common type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the FinancialAnalysisParameters type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&FinancialAnalysisParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"FinancialAnalysisParameters",
				(PyObject*)&FinancialAnalysisParameters_Type);
	Py_DECREF(&FinancialAnalysisParameters_Type);

	/// Add the LifetimePV type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&LifetimePV_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"LifetimePV",
				(PyObject*)&LifetimePV_Type);
	Py_DECREF(&LifetimePV_Type);

	/// Add the Weather type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the PVWatts type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&PVWatts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"PVWatts",
				(PyObject*)&PVWatts_Type);
	Py_DECREF(&PVWatts_Type);

	/// Add the Battwatts type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&Battwatts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"Battwatts",
				(PyObject*)&Battwatts_Type);
	Py_DECREF(&Battwatts_Type);

	/// Add the Outputs type object to Pvwattsv5Lifetime_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv5Lifetime_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv5Lifetime type object to the module
	if (PyType_Ready(&Pvwattsv5Lifetime_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv5Lifetime",
				(PyObject*)&Pvwattsv5Lifetime_Type);

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv5LifetimeModule_slots[] = {
		{Py_mod_exec, Pvwattsv5LifetimeModule_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv5LifetimeModule = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv5Lifetime",
		module_doc,
		0,
		Pvwattsv5LifetimeModule_methods,
		Pvwattsv5LifetimeModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv5Lifetime(void)
{
	return PyModuleDef_Init(&Pvwattsv5LifetimeModule);
}