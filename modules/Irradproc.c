#include <Python.h>

#include <SAM_Irradproc.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * IrradianceProcessor Group
 */ 

static PyTypeObject IrradianceProcessor_Type;

static PyObject *
IrradianceProcessor_new(SAM_Irradproc data_ptr)
{
	PyObject* new_obj = IrradianceProcessor_Type.tp_alloc(&IrradianceProcessor_Type,0);

	VarGroupObject* IrradianceProcessor_obj = (VarGroupObject*)new_obj;

	IrradianceProcessor_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* IrradianceProcessor methods */

static PyObject *
IrradianceProcessor_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Irradproc", "IrradianceProcessor")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IrradianceProcessor_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &IrradianceProcessor_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Irradproc", "IrradianceProcessor")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IrradianceProcessor_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &IrradianceProcessor_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef IrradianceProcessor_methods[] = {
		{"assign",            (PyCFunction)IrradianceProcessor_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``IrradianceProcessor_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)IrradianceProcessor_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``IrradianceProcessor_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)IrradianceProcessor_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IrradianceProcessor_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_albedo_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_albedo_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_albedo_const(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_albedo_const_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_albedo_const(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_albedo_const_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_azimuth_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_azimuth_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_backtrack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_backtrack_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_backtrack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_backtrack_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_beam_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_beam_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_day_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_day(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_day_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_diff_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_diff_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_elevation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_elevation_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_elevation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_elevation_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_gcr_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_gcr_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_glob(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_glob_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_glob(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_glob_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_hour_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_hour_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_irrad_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_irrad_mode_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_irrad_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_irrad_mode_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_lat_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_lat_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_lon_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_lon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_lon_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_minute(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_minute_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_minute(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_minute_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_month_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_month_aset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_pressure_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_pressure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_pressure_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_rotlim_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_rotlim_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_sky_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_sky_model_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_sky_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_sky_model_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_slope_azm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_slope_azm_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_slope_azm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_slope_azm_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_slope_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_slope_tilt_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_slope_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_slope_tilt_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_tamb_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_tamb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_tamb_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_tilt_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_tilt_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_track_mode_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_track_mode_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Irradproc_IrradianceProcessor_tz_nget, self->data_ptr);
}

static int
IrradianceProcessor_set_tz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Irradproc_IrradianceProcessor_tz_nset, self->data_ptr);
}

static PyObject *
IrradianceProcessor_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_IrradianceProcessor_year_aget, self->data_ptr);
}

static int
IrradianceProcessor_set_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Irradproc_IrradianceProcessor_year_aset, self->data_ptr);
}

static PyGetSetDef IrradianceProcessor_getset[] = {
{"albedo", (getter)IrradianceProcessor_get_albedo,(setter)IrradianceProcessor_set_albedo,
	PyDoc_STR("*sequence*: Ground reflectance (time depend.) [frac]\n\n**Info:**\n0..1\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"albedo_const", (getter)IrradianceProcessor_get_albedo_const,(setter)IrradianceProcessor_set_albedo_const,
	PyDoc_STR("*float*: Ground reflectance (single value) [frac]\n\n**Info:**\n0..1\n\n**Required:**\nFalse. Automatically set to 0.2 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"azimuth", (getter)IrradianceProcessor_get_azimuth,(setter)IrradianceProcessor_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle [deg]\n\n**Options:**\nE=90,S=180,W=270\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\nTrue"),
 	NULL},
{"backtrack", (getter)IrradianceProcessor_get_backtrack,(setter)IrradianceProcessor_set_backtrack,
	PyDoc_STR("*float*: Enable backtracking [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"beam", (getter)IrradianceProcessor_get_beam,(setter)IrradianceProcessor_set_beam,
	PyDoc_STR("*sequence*: Beam normal irradiance [W/m2]\n\n**Required:**\nirrad_mode~2"),
 	NULL},
{"day", (getter)IrradianceProcessor_get_day,(setter)IrradianceProcessor_set_day,
	PyDoc_STR("*sequence*: Day [dy]\n\n**Info:**\n1-days in month\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"diff", (getter)IrradianceProcessor_get_diff,(setter)IrradianceProcessor_set_diff,
	PyDoc_STR("*sequence*: Diffuse horizontal irradiance [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nirrad_mode~1"),
 	NULL},
{"elevation", (getter)IrradianceProcessor_get_elevation,(setter)IrradianceProcessor_set_elevation,
	PyDoc_STR("*float*: Elevation [m]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"gcr", (getter)IrradianceProcessor_get_gcr,(setter)IrradianceProcessor_set_gcr,
	PyDoc_STR("*float*: Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if backtrack=1"),
 	NULL},
{"glob", (getter)IrradianceProcessor_get_glob,(setter)IrradianceProcessor_set_glob,
	PyDoc_STR("*sequence*: Global horizontal irradiance [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nirrad_mode~0"),
 	NULL},
{"hour", (getter)IrradianceProcessor_get_hour,(setter)IrradianceProcessor_set_hour,
	PyDoc_STR("*sequence*: Hour [hr]\n\n**Info:**\n0-23\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"irrad_mode", (getter)IrradianceProcessor_get_irrad_mode,(setter)IrradianceProcessor_set_irrad_mode,
	PyDoc_STR("*float*: Irradiance input mode [0/1/2/3/4]\n\n**Info:**\nBeam+Diff,Global+Beam, Global+Diff, POA Ref cell, POA Pyranometer \n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"lat", (getter)IrradianceProcessor_get_lat,(setter)IrradianceProcessor_set_lat,
	PyDoc_STR("*float*: Latitude [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"lon", (getter)IrradianceProcessor_get_lon,(setter)IrradianceProcessor_set_lon,
	PyDoc_STR("*float*: Longitude [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"minute", (getter)IrradianceProcessor_get_minute,(setter)IrradianceProcessor_set_minute,
	PyDoc_STR("*sequence*: Minute [min]\n\n**Info:**\n0-59\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"month", (getter)IrradianceProcessor_get_month,(setter)IrradianceProcessor_set_month,
	PyDoc_STR("*sequence*: Month [mn]\n\n**Info:**\n1-12\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"pressure", (getter)IrradianceProcessor_get_pressure,(setter)IrradianceProcessor_set_pressure,
	PyDoc_STR("*float*: Pressure [mbars]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"rotlim", (getter)IrradianceProcessor_get_rotlim,(setter)IrradianceProcessor_set_rotlim,
	PyDoc_STR("*float*: Rotational limit on tracker [deg]\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nFalse. Automatically set to 45 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sky_model", (getter)IrradianceProcessor_get_sky_model,(setter)IrradianceProcessor_set_sky_model,
	PyDoc_STR("*float*: Tilted surface irradiance model [0/1/2]\n\n**Info:**\nIsotropic,HDKR,Perez\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 2 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"slope_azm", (getter)IrradianceProcessor_get_slope_azm,(setter)IrradianceProcessor_set_slope_azm,
	PyDoc_STR("*float*: Terrain azimuth [deg]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"slope_tilt", (getter)IrradianceProcessor_get_slope_tilt,(setter)IrradianceProcessor_set_slope_tilt,
	PyDoc_STR("*float*: Terrain slope [deg]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tamb", (getter)IrradianceProcessor_get_tamb,(setter)IrradianceProcessor_set_tamb,
	PyDoc_STR("*float*: Ambient Temperature (dry bulb temperature) [°C]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"tilt", (getter)IrradianceProcessor_get_tilt,(setter)IrradianceProcessor_set_tilt,
	PyDoc_STR("*float*: Tilt angle [deg]\n\n**Options:**\nH=0,V=90\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"track_mode", (getter)IrradianceProcessor_get_track_mode,(setter)IrradianceProcessor_set_track_mode,
	PyDoc_STR("*float*: Tracking mode [0/1/2]\n\n**Info:**\nFixed,1Axis,2Axis\n\n**Constraints:**\nMIN=0,MAX=2,INTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tz", (getter)IrradianceProcessor_get_tz,(setter)IrradianceProcessor_set_tz,
	PyDoc_STR("*float*: Time zone [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"year", (getter)IrradianceProcessor_get_year,(setter)IrradianceProcessor_set_year,
	PyDoc_STR("*sequence*: Year [yr]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IrradianceProcessor_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Irradproc.IrradianceProcessor",             /*tp_name*/
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
		IrradianceProcessor_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		IrradianceProcessor_getset,          /*tp_getset*/
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
Outputs_new(SAM_Irradproc data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Irradproc", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Irradproc", "Outputs")){
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
Outputs_get_axis_rotation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_axis_rotation_aget, self->data_ptr);
}

static PyObject *
Outputs_get_bt_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_bt_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_incidence(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_incidence_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_poa_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_gnddiff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_poa_gnddiff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_skydiff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_poa_skydiff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_skydiff_cir(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_poa_skydiff_cir_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_skydiff_hor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_poa_skydiff_hor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_skydiff_iso(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_poa_skydiff_iso_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sun_azm(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_sun_azm_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sun_dec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_sun_dec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sun_elv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_sun_elv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sun_zen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_sun_zen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_surf_azm(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_surf_azm_aget, self->data_ptr);
}

static PyObject *
Outputs_get_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Irradproc_Outputs_surf_tilt_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"axis_rotation", (getter)Outputs_get_axis_rotation,(setter)0,
	PyDoc_STR("*sequence*: Tracking axis rotation angle [deg]"),
 	NULL},
{"bt_diff", (getter)Outputs_get_bt_diff,(setter)0,
	PyDoc_STR("*sequence*: Backtracking difference from ideal rotation [deg]"),
 	NULL},
{"incidence", (getter)Outputs_get_incidence,(setter)0,
	PyDoc_STR("*sequence*: Incidence angle to surface [deg]"),
 	NULL},
{"poa_beam", (getter)Outputs_get_poa_beam,(setter)0,
	PyDoc_STR("*sequence*: Incident Beam Irradiance [W/m2]"),
 	NULL},
{"poa_gnddiff", (getter)Outputs_get_poa_gnddiff,(setter)0,
	PyDoc_STR("*sequence*: Incident Ground Reflected Diffuse [W/m2]"),
 	NULL},
{"poa_skydiff", (getter)Outputs_get_poa_skydiff,(setter)0,
	PyDoc_STR("*sequence*: Incident Sky Diffuse [W/m2]"),
 	NULL},
{"poa_skydiff_cir", (getter)Outputs_get_poa_skydiff_cir,(setter)0,
	PyDoc_STR("*sequence*: Incident Diffuse Circumsolar Component [W/m2]"),
 	NULL},
{"poa_skydiff_hor", (getter)Outputs_get_poa_skydiff_hor,(setter)0,
	PyDoc_STR("*sequence*: Incident Diffuse Horizon Brightening Component [W/m2]"),
 	NULL},
{"poa_skydiff_iso", (getter)Outputs_get_poa_skydiff_iso,(setter)0,
	PyDoc_STR("*sequence*: Incident Diffuse Isotropic Component [W/m2]"),
 	NULL},
{"sun_azm", (getter)Outputs_get_sun_azm,(setter)0,
	PyDoc_STR("*sequence*: Solar azimuth [deg]"),
 	NULL},
{"sun_dec", (getter)Outputs_get_sun_dec,(setter)0,
	PyDoc_STR("*sequence*: Sun declination [deg]"),
 	NULL},
{"sun_elv", (getter)Outputs_get_sun_elv,(setter)0,
	PyDoc_STR("*sequence*: Sun elevation [deg]"),
 	NULL},
{"sun_zen", (getter)Outputs_get_sun_zen,(setter)0,
	PyDoc_STR("*sequence*: Solar zenith [deg]"),
 	NULL},
{"surf_azm", (getter)Outputs_get_surf_azm,(setter)0,
	PyDoc_STR("*sequence*: Surface azimuth angle [deg]"),
 	NULL},
{"surf_tilt", (getter)Outputs_get_surf_tilt,(setter)0,
	PyDoc_STR("*sequence*: Surface tilt angle [deg]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Irradproc.Outputs",             /*tp_name*/
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
 * Irradproc
 */

static PyTypeObject Irradproc_Type;

static CmodObject *
newIrradprocObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Irradproc_Type);

	PySAM_TECH_ATTR()

	PyObject* IrradianceProcessor_obj = IrradianceProcessor_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IrradianceProcessor", IrradianceProcessor_obj);
	Py_DECREF(IrradianceProcessor_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Irradproc methods */

static void
Irradproc_dealloc(CmodObject *self)
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
Irradproc_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Irradproc_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Irradproc_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Irradproc"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Irradproc_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Irradproc"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Irradproc_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Irradproc_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Irradproc_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Irradproc_methods[] = {
		{"execute",           (PyCFunction)Irradproc_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Irradproc_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Irradiance Processor': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Irradproc_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Irradiance Processor': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Irradproc_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Irradproc_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Irradproc_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Irradproc_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Irradproc_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Irradproc_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Irradproc",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Irradproc_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Irradproc_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Irradproc_getattro, /*tp_getattro*/
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
		Irradproc_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Irradproc object */

static PyObject *
Irradproc_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newIrradprocObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Irradproc_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIrradprocObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Irradproc_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newIrradprocObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Irradproc", def) < 0) {
		Irradproc_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Irradproc_from_existing(PyObject *self, PyObject *args)
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

	rv = newIrradprocObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Irradproc", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef IrradprocModule_methods[] = {
		{"new",             Irradproc_new,         METH_VARARGS,
				PyDoc_STR("new() -> Irradproc")},
		{"default",             Irradproc_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Irradproc\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Irradproc_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Irradproc\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Irradproc_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Irradproc\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Irradproc");


static int
IrradprocModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Irradproc_Type.tp_dict = PyDict_New();
	if (!Irradproc_Type.tp_dict) { goto fail; }

	/// Add the IrradianceProcessor type object to Irradproc_Type
	if (PyType_Ready(&IrradianceProcessor_Type) < 0) { goto fail; }
	PyDict_SetItemString(Irradproc_Type.tp_dict,
				"IrradianceProcessor",
				(PyObject*)&IrradianceProcessor_Type);
	Py_DECREF(&IrradianceProcessor_Type);

	/// Add the Outputs type object to Irradproc_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Irradproc_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Irradproc type object to the module
	if (PyType_Ready(&Irradproc_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Irradproc",
				(PyObject*)&Irradproc_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot IrradprocModule_slots[] = {
		{Py_mod_exec, IrradprocModule_exec},
		{0, NULL},
};

static struct PyModuleDef IrradprocModule = {
		PyModuleDef_HEAD_INIT,
		"Irradproc",
		module_doc,
		0,
		IrradprocModule_methods,
		IrradprocModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Irradproc(void)
{
	return PyModuleDef_Init(&IrradprocModule);
}