#include <Python.h>

#include <SAM_Pvwattsv11ts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * PVWatts Group
 */ 

static PyTypeObject PVWatts_Type;

static PyObject *
PVWatts_new(SAM_Pvwattsv11ts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv11ts", "PVWatts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVWatts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PVWatts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv11ts", "PVWatts")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PVWatts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PVWatts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PVWatts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PVWatts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PVWatts_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_azimuth_nget, self->data_ptr);
}

static int
PVWatts_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_azimuth_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_beam_nget, self->data_ptr);
}

static int
PVWatts_set_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_beam_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_day(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_day_nget, self->data_ptr);
}

static int
PVWatts_set_day(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_day_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_derate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_derate_nget, self->data_ptr);
}

static int
PVWatts_set_derate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_derate_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_diffuse_nget, self->data_ptr);
}

static int
PVWatts_set_diffuse(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_diffuse_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_elevation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_elevation_nget, self->data_ptr);
}

static int
PVWatts_set_elevation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_elevation_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_fd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_fd_nget, self->data_ptr);
}

static int
PVWatts_set_fd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_fd_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_gamma(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_gamma_nget, self->data_ptr);
}

static int
PVWatts_set_gamma(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_gamma_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_hour_nget, self->data_ptr);
}

static int
PVWatts_set_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_hour_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_i_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_i_ref_nget, self->data_ptr);
}

static int
PVWatts_set_i_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_i_ref_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_inv_eff_nget, self->data_ptr);
}

static int
PVWatts_set_inv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_inv_eff_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_lat_nget, self->data_ptr);
}

static int
PVWatts_set_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_lat_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_lon_nget, self->data_ptr);
}

static int
PVWatts_set_lon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_lon_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_minute(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_minute_nget, self->data_ptr);
}

static int
PVWatts_set_minute(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_minute_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_month_nget, self->data_ptr);
}

static int
PVWatts_set_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_month_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_poa_nget, self->data_ptr);
}

static int
PVWatts_set_poa(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_poa_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_poa_cutin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_poa_cutin_nget, self->data_ptr);
}

static int
PVWatts_set_poa_cutin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_poa_cutin_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_pressure_nget, self->data_ptr);
}

static int
PVWatts_set_pressure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_pressure_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_rotlim_nget, self->data_ptr);
}

static int
PVWatts_set_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_rotlim_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_snow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_snow_nget, self->data_ptr);
}

static int
PVWatts_set_snow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_snow_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_system_size(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_system_size_nget, self->data_ptr);
}

static int
PVWatts_set_system_size(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_system_size_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_t_noct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_t_noct_nget, self->data_ptr);
}

static int
PVWatts_set_t_noct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_t_noct_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_t_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_t_ref_nget, self->data_ptr);
}

static int
PVWatts_set_t_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_t_ref_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_tamb_nget, self->data_ptr);
}

static int
PVWatts_set_tamb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_tamb_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_tcell_nget, self->data_ptr);
}

static int
PVWatts_set_tcell(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_tcell_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_tilt_nget, self->data_ptr);
}

static int
PVWatts_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_tilt_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_time_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_time_step_nget, self->data_ptr);
}

static int
PVWatts_set_time_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_time_step_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_track_mode_nget, self->data_ptr);
}

static int
PVWatts_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_track_mode_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_tz_nget, self->data_ptr);
}

static int
PVWatts_set_tz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_tz_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_w_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_w_stow_nget, self->data_ptr);
}

static int
PVWatts_set_w_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_w_stow_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_wspd_nget, self->data_ptr);
}

static int
PVWatts_set_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_wspd_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_PVWatts_year_nget, self->data_ptr);
}

static int
PVWatts_set_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv11ts_PVWatts_year_nset, self->data_ptr);
}

static PyGetSetDef PVWatts_getset[] = {
{"azimuth", (getter)PVWatts_get_azimuth,(setter)PVWatts_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle [deg]\n\n**Options:**\nE=90,S=180,W=270\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\nTrue"),
 	NULL},
{"beam", (getter)PVWatts_get_beam,(setter)PVWatts_set_beam,
	PyDoc_STR("*float*: Beam normal irradiance [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"day", (getter)PVWatts_get_day,(setter)PVWatts_set_day,
	PyDoc_STR("*float*: Day [dy]\n\n**Info:**\n1-days in month\n\n**Required:**\nTrue"),
 	NULL},
{"derate", (getter)PVWatts_get_derate,(setter)PVWatts_set_derate,
	PyDoc_STR("*float*: System derate value [frac]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"diffuse", (getter)PVWatts_get_diffuse,(setter)PVWatts_set_diffuse,
	PyDoc_STR("*float*: Diffuse irradiance [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"elevation", (getter)PVWatts_get_elevation,(setter)PVWatts_set_elevation,
	PyDoc_STR("*float*: Elevation [m]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"fd", (getter)PVWatts_get_fd,(setter)PVWatts_set_fd,
	PyDoc_STR("*float*: Diffuse fraction [0..1]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 1.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gamma", (getter)PVWatts_get_gamma,(setter)PVWatts_set_gamma,
	PyDoc_STR("*float*: Max power temperature coefficient [%/C]\n\n**Required:**\nFalse. Automatically set to -0.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"hour", (getter)PVWatts_get_hour,(setter)PVWatts_set_hour,
	PyDoc_STR("*float*: Hour [hr]\n\n**Info:**\n0-23\n\n**Required:**\nTrue"),
 	NULL},
{"i_ref", (getter)PVWatts_get_i_ref,(setter)PVWatts_set_i_ref,
	PyDoc_STR("*float*: Rating condition irradiance [W/m2]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 1000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inv_eff", (getter)PVWatts_get_inv_eff,(setter)PVWatts_set_inv_eff,
	PyDoc_STR("*float*: Inverter efficiency at rated power [frac]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0.92 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"lat", (getter)PVWatts_get_lat,(setter)PVWatts_set_lat,
	PyDoc_STR("*float*: Latitude [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"lon", (getter)PVWatts_get_lon,(setter)PVWatts_set_lon,
	PyDoc_STR("*float*: Longitude [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"minute", (getter)PVWatts_get_minute,(setter)PVWatts_set_minute,
	PyDoc_STR("*float*: Minute [min]\n\n**Info:**\n0-59\n\n**Required:**\nTrue"),
 	NULL},
{"month", (getter)PVWatts_get_month,(setter)PVWatts_set_month,
	PyDoc_STR("*float*: Month [mn]\n\n**Info:**\n1-12\n\n**Required:**\nTrue"),
 	NULL},
{"poa", (getter)PVWatts_get_poa,(setter)PVWatts_set_poa,
	PyDoc_STR("*float*: Plane of array irradiance [W/m2]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"poa_cutin", (getter)PVWatts_get_poa_cutin,(setter)PVWatts_set_poa_cutin,
	PyDoc_STR("*float*: Min reqd irradiance for operation [W/m2]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"pressure", (getter)PVWatts_get_pressure,(setter)PVWatts_set_pressure,
	PyDoc_STR("*float*: Pressure [millibars]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"rotlim", (getter)PVWatts_get_rotlim,(setter)PVWatts_set_rotlim,
	PyDoc_STR("*float*: Tracker rotation limit (+/- 1 axis) [deg]\n\n**Constraints:**\nMIN=1,MAX=90\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"snow", (getter)PVWatts_get_snow,(setter)PVWatts_set_snow,
	PyDoc_STR("*float*: Snow cover [cm]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_size", (getter)PVWatts_get_system_size,(setter)PVWatts_set_system_size,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"t_noct", (getter)PVWatts_get_t_noct,(setter)PVWatts_set_t_noct,
	PyDoc_STR("*float*: Nominal operating cell temperature [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"t_ref", (getter)PVWatts_get_t_ref,(setter)PVWatts_set_t_ref,
	PyDoc_STR("*float*: Reference cell temperature [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 25.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tamb", (getter)PVWatts_get_tamb,(setter)PVWatts_set_tamb,
	PyDoc_STR("*float*: Ambient temperature (dry bulb temperature) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"tcell", (getter)PVWatts_get_tcell,(setter)PVWatts_set_tcell,
	PyDoc_STR("*float*: Module temperature [C]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)PVWatts_get_tilt,(setter)PVWatts_set_tilt,
	PyDoc_STR("*float*: Tilt angle [deg]\n\n**Options:**\nH=0,V=90\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nnaof:tilt_eq_lat"),
 	NULL},
{"time_step", (getter)PVWatts_get_time_step,(setter)PVWatts_set_time_step,
	PyDoc_STR("*float*: Time step of input data [hr]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"track_mode", (getter)PVWatts_get_track_mode,(setter)PVWatts_set_track_mode,
	PyDoc_STR("*float*: Tracking mode [0/1/2/3]\n\n**Info:**\nFixed,1Axis,2Axis,AziAxis\n\n**Constraints:**\nMIN=0,MAX=3,INTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tz", (getter)PVWatts_get_tz,(setter)PVWatts_set_tz,
	PyDoc_STR("*float*: Time zone [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"w_stow", (getter)PVWatts_get_w_stow,(setter)PVWatts_set_w_stow,
	PyDoc_STR("*float*: Wind stow speed [m/s]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"wspd", (getter)PVWatts_get_wspd,(setter)PVWatts_set_wspd,
	PyDoc_STR("*float*: Wind speed [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"year", (getter)PVWatts_get_year,(setter)PVWatts_set_year,
	PyDoc_STR("*float*: Year [yr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVWatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv11ts.PVWatts",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Pvwattsv11ts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv11ts", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv11ts", "Outputs")){
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
	return PySAM_double_getter(SAM_Pvwattsv11ts_Outputs_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv11ts_Outputs_dc_nget, self->data_ptr);
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
		"Pvwattsv11ts.Outputs",             /*tp_name*/
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
 * Pvwattsv11ts
 */

static PyTypeObject Pvwattsv11ts_Type;

static CmodObject *
newPvwattsv11tsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvwattsv11ts_Type);

	PySAM_TECH_ATTR()

	PyObject* PVWatts_obj = PVWatts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVWatts", PVWatts_obj);
	Py_DECREF(PVWatts_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Pvwattsv11ts methods */

static void
Pvwattsv11ts_dealloc(CmodObject *self)
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
Pvwattsv11ts_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv11ts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv11ts_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv11ts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv11ts_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv11ts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv11ts_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvwattsv11ts_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pvwattsv11ts_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pvwattsv11ts_methods[] = {
		{"execute",           (PyCFunction)Pvwattsv11ts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv11ts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'PVWatts': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pvwattsv11ts_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'PVWatts': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv11ts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvwattsv11ts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pvwattsv11ts_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv11ts_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv11ts_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv11ts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv11ts",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv11ts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv11ts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv11ts_getattro, /*tp_getattro*/
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
		Pvwattsv11ts_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv11ts object */

static PyObject *
Pvwattsv11ts_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvwattsv11tsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv11ts_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv11tsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv11ts_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv11tsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv11ts", def) < 0) {
		Pvwattsv11ts_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv11ts_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvwattsv11tsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv11ts", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv11tsModule_methods[] = {
		{"new",             Pvwattsv11ts_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv11ts")},
		{"default",             Pvwattsv11ts_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv11ts\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pvwattsv11ts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv11ts\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pvwattsv11ts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvwattsv11ts\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pvwattsv11ts");


static int
Pvwattsv11tsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvwattsv11ts_Type.tp_dict = PyDict_New();
	if (!Pvwattsv11ts_Type.tp_dict) { goto fail; }

	/// Add the PVWatts type object to Pvwattsv11ts_Type
	if (PyType_Ready(&PVWatts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv11ts_Type.tp_dict,
				"PVWatts",
				(PyObject*)&PVWatts_Type);
	Py_DECREF(&PVWatts_Type);

	/// Add the Outputs type object to Pvwattsv11ts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv11ts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv11ts type object to the module
	if (PyType_Ready(&Pvwattsv11ts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv11ts",
				(PyObject*)&Pvwattsv11ts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv11tsModule_slots[] = {
		{Py_mod_exec, Pvwattsv11tsModule_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv11tsModule = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv11ts",
		module_doc,
		0,
		Pvwattsv11tsModule_methods,
		Pvwattsv11tsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv11ts(void)
{
	return PyModuleDef_Init(&Pvwattsv11tsModule);
}