#include <Python.h>

#include <SAM_Pvwattsv51ts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * PVWatts Group
 */ 

static PyTypeObject PVWatts_Type;

static PyObject *
PVWatts_new(SAM_Pvwattsv51ts data_ptr)
{
	PyObject* new_obj = PVWatts_Type.tp_alloc(&PVWatts_Type,0);

	VarGroupObject* PVWatts_obj = (VarGroupObject*)new_obj;

	PVWatts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PVWatts methods */

static PyObject *
PVWatts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv51ts", "PVWatts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVWatts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PVWatts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PVWatts_methods[] = {
		{"assign",            (PyCFunction)PVWatts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``PVWatts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PVWatts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PVWatts_get_alb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_alb_nget, self->data_ptr);
}

static int
PVWatts_set_alb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_alb_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_beam_nget, self->data_ptr);
}

static int
PVWatts_set_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_beam_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_day(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_day_nget, self->data_ptr);
}

static int
PVWatts_set_day(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_day_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_diffuse_nget, self->data_ptr);
}

static int
PVWatts_set_diffuse(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_diffuse_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_hour_nget, self->data_ptr);
}

static int
PVWatts_set_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_hour_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_lat_nget, self->data_ptr);
}

static int
PVWatts_set_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_lat_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_lon_nget, self->data_ptr);
}

static int
PVWatts_set_lon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_lon_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_minute(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_minute_nget, self->data_ptr);
}

static int
PVWatts_set_minute(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_minute_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_month_nget, self->data_ptr);
}

static int
PVWatts_set_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_month_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_poa_nget, self->data_ptr);
}

static int
PVWatts_set_poa(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_poa_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_tamb_nget, self->data_ptr);
}

static int
PVWatts_set_tamb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_tamb_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_tcell_nget, self->data_ptr);
}

static int
PVWatts_set_tcell(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_tcell_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_time_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_time_step_nget, self->data_ptr);
}

static int
PVWatts_set_time_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_time_step_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_tz_nget, self->data_ptr);
}

static int
PVWatts_set_tz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_tz_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_wspd_nget, self->data_ptr);
}

static int
PVWatts_set_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_wspd_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_PVWatts_year_nget, self->data_ptr);
}

static int
PVWatts_set_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_PVWatts_year_nset, self->data_ptr);
}

static PyGetSetDef PVWatts_getset[] = {
{"alb", (getter)PVWatts_get_alb,(setter)PVWatts_set_alb,
	PyDoc_STR("*float*: Albedo [frac]\n\n*Required*: If not provided, assumed to be 0.2"),
 	NULL},
{"beam", (getter)PVWatts_get_beam,(setter)PVWatts_set_beam,
	PyDoc_STR("*float*: Beam normal irradiance [W/m2]\n\n*Required*: True"),
 	NULL},
{"day", (getter)PVWatts_get_day,(setter)PVWatts_set_day,
	PyDoc_STR("*float*: Day [dy]\n\n*Info*: 1-days in month\n\n*Required*: True"),
 	NULL},
{"diffuse", (getter)PVWatts_get_diffuse,(setter)PVWatts_set_diffuse,
	PyDoc_STR("*float*: Diffuse irradiance [W/m2]\n\n*Required*: True"),
 	NULL},
{"hour", (getter)PVWatts_get_hour,(setter)PVWatts_set_hour,
	PyDoc_STR("*float*: Hour [hr]\n\n*Info*: 0-23\n\n*Required*: True"),
 	NULL},
{"lat", (getter)PVWatts_get_lat,(setter)PVWatts_set_lat,
	PyDoc_STR("*float*: Latitude [deg]\n\n*Required*: True"),
 	NULL},
{"lon", (getter)PVWatts_get_lon,(setter)PVWatts_set_lon,
	PyDoc_STR("*float*: Longitude [deg]\n\n*Required*: True"),
 	NULL},
{"minute", (getter)PVWatts_get_minute,(setter)PVWatts_set_minute,
	PyDoc_STR("*float*: Minute [min]\n\n*Info*: 0-59\n\n*Required*: True"),
 	NULL},
{"month", (getter)PVWatts_get_month,(setter)PVWatts_set_month,
	PyDoc_STR("*float*: Month [mn]\n\n*Info*: 1-12\n\n*Required*: True"),
 	NULL},
{"poa", (getter)PVWatts_get_poa,(setter)PVWatts_set_poa,
	PyDoc_STR("*float*: Plane of array irradiance [W/m2]\n\n*Info*: Output from last time step may be used as input"),
 	NULL},
{"tamb", (getter)PVWatts_get_tamb,(setter)PVWatts_set_tamb,
	PyDoc_STR("*float*: Ambient temperature [C]\n\n*Required*: True"),
 	NULL},
{"tcell", (getter)PVWatts_get_tcell,(setter)PVWatts_set_tcell,
	PyDoc_STR("*float*: Module temperature [C]\n\n*Info*: Output from last time step may be used as input"),
 	NULL},
{"time_step", (getter)PVWatts_get_time_step,(setter)PVWatts_set_time_step,
	PyDoc_STR("*float*: Time step of input data [hr]\n\n*Constraints*: POSITIVE\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"tz", (getter)PVWatts_get_tz,(setter)PVWatts_set_tz,
	PyDoc_STR("*float*: Time zone [hr]\n\n*Required*: True"),
 	NULL},
{"wspd", (getter)PVWatts_get_wspd,(setter)PVWatts_set_wspd,
	PyDoc_STR("*float*: Wind speed [m/s]\n\n*Required*: True"),
 	NULL},
{"year", (getter)PVWatts_get_year,(setter)PVWatts_set_year,
	PyDoc_STR("*float*: Year [yr]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVWatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv51ts.PVWatts",             /*tp_name*/
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
		PVWatts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PVWatts_getset,          /*tp_getset*/
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
SystemDesign_new(SAM_Pvwattsv51ts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv51ts", "SystemDesign")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemDesign_get_array_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_array_type_nget, self->data_ptr);
}

static int
SystemDesign_set_array_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_array_type_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_dc_ac_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_dc_ac_ratio_nget, self->data_ptr);
}

static int
SystemDesign_set_dc_ac_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_dc_ac_ratio_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_inv_eff_nget, self->data_ptr);
}

static int
SystemDesign_set_inv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_inv_eff_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_losses_nget, self->data_ptr);
}

static int
SystemDesign_set_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_losses_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_module_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_module_type_nget, self->data_ptr);
}

static int
SystemDesign_set_module_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_module_type_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_system_capacity_nget, self->data_ptr);
}

static int
SystemDesign_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_system_capacity_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_SystemDesign_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv51ts_SystemDesign_tilt_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"array_type", (getter)SystemDesign_get_array_type,(setter)SystemDesign_set_array_type,
	PyDoc_STR("*float*: Array type [0/1/2/3/4]\n\n*Info*: Fixed OR,Fixed Roof,1Axis,Backtracked,2Axis\n\n*Constraints*: MIN=0,MAX=4,INTEGER\n\n*Required*: True"),
 	NULL},
{"azimuth", (getter)SystemDesign_get_azimuth,(setter)SystemDesign_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle [deg]\n\n*Options*: E=90,S=180,W=270\n\n*Constraints*: MIN=0,MAX=360\n\n*Required*: array_type<4"),
 	NULL},
{"dc_ac_ratio", (getter)SystemDesign_get_dc_ac_ratio,(setter)SystemDesign_set_dc_ac_ratio,
	PyDoc_STR("*float*: DC to AC ratio [ratio]\n\n*Constraints*: POSITIVE\n\n*Required*: If not provided, assumed to be 1.1"),
 	NULL},
{"gcr", (getter)SystemDesign_get_gcr,(setter)SystemDesign_set_gcr,
	PyDoc_STR("*float*: Ground coverage ratio [0..1]\n\n*Constraints*: MIN=0.01,MAX=0.99\n\n*Required*: If not provided, assumed to be 0.4"),
 	NULL},
{"inv_eff", (getter)SystemDesign_get_inv_eff,(setter)SystemDesign_set_inv_eff,
	PyDoc_STR("*float*: Inverter efficiency at rated power [%]\n\n*Constraints*: MIN=90,MAX=99.5\n\n*Required*: If not provided, assumed to be 96"),
 	NULL},
{"losses", (getter)SystemDesign_get_losses,(setter)SystemDesign_set_losses,
	PyDoc_STR("*float*: System losses [%]\n\n*Info*: Total system losses\n\n*Constraints*: MIN=-5,MAX=99\n\n*Required*: True"),
 	NULL},
{"module_type", (getter)SystemDesign_get_module_type,(setter)SystemDesign_set_module_type,
	PyDoc_STR("*float*: Module type [0/1/2]\n\n*Info*: Standard,Premium,Thin film\n\n*Constraints*: MIN=0,MAX=2,INTEGER\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"system_capacity", (getter)SystemDesign_get_system_capacity,(setter)SystemDesign_set_system_capacity,
	PyDoc_STR("*float*: System size (DC nameplate) [kW]\n\n*Required*: True"),
 	NULL},
{"tilt", (getter)SystemDesign_get_tilt,(setter)SystemDesign_set_tilt,
	PyDoc_STR("*float*: Tilt angle [deg]\n\n*Options*: H=0,V=90\n\n*Constraints*: MIN=0,MAX=90\n\n*Required*: array_type<4"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv51ts.SystemDesign",             /*tp_name*/
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
Outputs_new(SAM_Pvwattsv51ts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv51ts", "Outputs")){
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
Outputs_get_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_Outputs_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv51ts_Outputs_dc_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	PyDoc_STR("*float*: AC system output [Wac]"),
 	NULL},
{"dc", (getter)Outputs_get_dc,(setter)0,
	PyDoc_STR("*float*: DC array output [Wdc]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv51ts.Outputs",             /*tp_name*/
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
 * Pvwattsv51ts
 */

static PyTypeObject Pvwattsv51ts_Type;

static CmodObject *
newPvwattsv51tsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvwattsv51ts_Type);

	PySAM_TECH_ATTR()

	PyObject* PVWatts_obj = PVWatts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVWatts", PVWatts_obj);
	Py_DECREF(PVWatts_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Pvwattsv51ts methods */

static void
Pvwattsv51ts_dealloc(CmodObject *self)
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
Pvwattsv51ts_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv51ts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv51ts_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv51ts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv51ts_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvwattsv51ts_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Pvwattsv51ts_methods[] = {
		{"execute",            (PyCFunction)Pvwattsv51ts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv51ts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'PVWatts': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv51ts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvwattsv51ts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv51ts_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv51ts_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv51ts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv51ts",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv51ts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv51ts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv51ts_getattro, /*tp_getattro*/
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
		Pvwattsv51ts_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv51ts object */

static PyObject *
Pvwattsv51ts_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvwattsv51tsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv51ts_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv51tsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv51ts_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv51tsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv51ts", def);

	return (PyObject *)rv;
}

static PyObject *
Pvwattsv51ts_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvwattsv51tsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv51ts", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv51tsModule_methods[] = {
		{"new",             Pvwattsv51ts_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv51ts")},
		{"default",             Pvwattsv51ts_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv51ts\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Pvwattsv51ts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv51ts\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Pvwattsv51ts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvwattsv51ts\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pvwattsv51ts");


static int
Pvwattsv51tsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvwattsv51ts_Type.tp_dict = PyDict_New();
	if (!Pvwattsv51ts_Type.tp_dict) { goto fail; }

	/// Add the PVWatts type object to Pvwattsv51ts_Type
	if (PyType_Ready(&PVWatts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv51ts_Type.tp_dict,
				"PVWatts",
				(PyObject*)&PVWatts_Type);
	Py_DECREF(&PVWatts_Type);

	/// Add the SystemDesign type object to Pvwattsv51ts_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv51ts_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the Outputs type object to Pvwattsv51ts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv51ts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv51ts type object to the module
	if (PyType_Ready(&Pvwattsv51ts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv51ts",
				(PyObject*)&Pvwattsv51ts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv51tsModule_slots[] = {
		{Py_mod_exec, Pvwattsv51tsModule_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv51tsModule = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv51ts",
		module_doc,
		0,
		Pvwattsv51tsModule_methods,
		Pvwattsv51tsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv51ts(void)
{
	return PyModuleDef_Init(&Pvwattsv51tsModule);
}