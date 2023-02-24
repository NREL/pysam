#include <Python.h>

#include <SAM_Pvwattsv1.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_Pvwattsv1 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv1", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv1", "Weather")){
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
Weather_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv1_Weather_solar_resource_file_sget, self->data_ptr);
}

static int
Weather_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvwattsv1_Weather_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"solar_resource_file", (getter)Weather_get_solar_resource_file,(setter)Weather_set_solar_resource_file,
	PyDoc_STR("*str*: local weather file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1.Weather",             /*tp_name*/
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
 * PVWatts Group
 */ 

static PyTypeObject PVWatts_Type;

static PyObject *
PVWatts_new(SAM_Pvwattsv1 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv1", "PVWatts")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv1", "PVWatts")){
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
PVWatts_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_albedo_nget, self->data_ptr);
}

static int
PVWatts_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_albedo_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_ar_glass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_ar_glass_nget, self->data_ptr);
}

static int
PVWatts_set_ar_glass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_ar_glass_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_azimuth_nget, self->data_ptr);
}

static int
PVWatts_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_azimuth_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_concen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_concen_nget, self->data_ptr);
}

static int
PVWatts_set_concen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_concen_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_derate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_derate_nget, self->data_ptr);
}

static int
PVWatts_set_derate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_derate_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_enable_user_poa(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_enable_user_poa_nget, self->data_ptr);
}

static int
PVWatts_set_enable_user_poa(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_enable_user_poa_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_fd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_fd_nget, self->data_ptr);
}

static int
PVWatts_set_fd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_fd_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_fhconv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_fhconv_nget, self->data_ptr);
}

static int
PVWatts_set_fhconv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_fhconv_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_gamma(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_gamma_nget, self->data_ptr);
}

static int
PVWatts_set_gamma(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_gamma_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_gcr_nget, self->data_ptr);
}

static int
PVWatts_set_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_gcr_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_i_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_i_ref_nget, self->data_ptr);
}

static int
PVWatts_set_i_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_i_ref_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_inoct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_inoct_nget, self->data_ptr);
}

static int
PVWatts_set_inoct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_inoct_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_inv_eff_nget, self->data_ptr);
}

static int
PVWatts_set_inv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_inv_eff_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_poa_cutin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_poa_cutin_nget, self->data_ptr);
}

static int
PVWatts_set_poa_cutin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_poa_cutin_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_rotlim_nget, self->data_ptr);
}

static int
PVWatts_set_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_rotlim_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_shade_mode_1x(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_shade_mode_1x_nget, self->data_ptr);
}

static int
PVWatts_set_shade_mode_1x(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_shade_mode_1x_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv1_PVWatts_shading_azal_mget, self->data_ptr);
}

static int
PVWatts_set_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv1_PVWatts_shading_azal_mset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_shading_diff_nget, self->data_ptr);
}

static int
PVWatts_set_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_shading_diff_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv1_PVWatts_shading_mxh_mget, self->data_ptr);
}

static int
PVWatts_set_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv1_PVWatts_shading_mxh_mset, self->data_ptr);
}

static PyObject *
PVWatts_get_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv1_PVWatts_shading_timestep_mget, self->data_ptr);
}

static int
PVWatts_set_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvwattsv1_PVWatts_shading_timestep_mset, self->data_ptr);
}

static PyObject *
PVWatts_get_system_size(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_system_size_nget, self->data_ptr);
}

static int
PVWatts_set_system_size(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_system_size_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_tilt_nget, self->data_ptr);
}

static int
PVWatts_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_tilt_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tilt_eq_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_tilt_eq_lat_nget, self->data_ptr);
}

static int
PVWatts_set_tilt_eq_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_tilt_eq_lat_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_track_mode_nget, self->data_ptr);
}

static int
PVWatts_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_track_mode_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_tref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_tref_nget, self->data_ptr);
}

static int
PVWatts_set_tref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_tref_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_u0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_u0_nget, self->data_ptr);
}

static int
PVWatts_set_u0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_u0_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_u1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_u1_nget, self->data_ptr);
}

static int
PVWatts_set_u1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_u1_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_user_poa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_PVWatts_user_poa_aget, self->data_ptr);
}

static int
PVWatts_set_user_poa(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1_PVWatts_user_poa_aset, self->data_ptr);
}

static PyObject *
PVWatts_get_w_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_PVWatts_w_stow_nget, self->data_ptr);
}

static int
PVWatts_set_w_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1_PVWatts_w_stow_nset, self->data_ptr);
}

static PyGetSetDef PVWatts_getset[] = {
{"albedo", (getter)PVWatts_get_albedo,(setter)PVWatts_set_albedo,
	PyDoc_STR("*float*: Albedo (ground reflectance) [frac]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"ar_glass", (getter)PVWatts_get_ar_glass,(setter)PVWatts_set_ar_glass,
	PyDoc_STR("*float*: Enable anti-reflective glass coating (beta) [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"azimuth", (getter)PVWatts_get_azimuth,(setter)PVWatts_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle [deg]\n\n**Options:**\nE=90,S=180,W=270\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\nTrue"),
 	NULL},
{"concen", (getter)PVWatts_get_concen,(setter)PVWatts_set_concen,
	PyDoc_STR("*float*: Concentration ratio\n\n**Constraints:**\nMIN=1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"derate", (getter)PVWatts_get_derate,(setter)PVWatts_set_derate,
	PyDoc_STR("*float*: System derate value [frac]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"enable_user_poa", (getter)PVWatts_get_enable_user_poa,(setter)PVWatts_set_enable_user_poa,
	PyDoc_STR("*float*: Enable user-defined POA irradiance input [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"fd", (getter)PVWatts_get_fd,(setter)PVWatts_set_fd,
	PyDoc_STR("*float*: Diffuse fraction [0..1]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 1.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"fhconv", (getter)PVWatts_get_fhconv,(setter)PVWatts_set_fhconv,
	PyDoc_STR("*float*: Convective heat transfer factor\n\n**Constraints:**\nMIN=0.1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gamma", (getter)PVWatts_get_gamma,(setter)PVWatts_set_gamma,
	PyDoc_STR("*float*: Max power temperature coefficient [%/C]\n\n**Required:**\nFalse. Automatically set to -0.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"gcr", (getter)PVWatts_get_gcr,(setter)PVWatts_set_gcr,
	PyDoc_STR("*float*: Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0,MAX=3\n\n**Required:**\nFalse. Automatically set to 0.3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"i_ref", (getter)PVWatts_get_i_ref,(setter)PVWatts_set_i_ref,
	PyDoc_STR("*float*: Rating condition irradiance [W/m2]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 1000 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inoct", (getter)PVWatts_get_inoct,(setter)PVWatts_set_inoct,
	PyDoc_STR("*float*: Nominal operating cell temperature [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inv_eff", (getter)PVWatts_get_inv_eff,(setter)PVWatts_set_inv_eff,
	PyDoc_STR("*float*: Inverter efficiency at rated power [frac]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0.92 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"poa_cutin", (getter)PVWatts_get_poa_cutin,(setter)PVWatts_set_poa_cutin,
	PyDoc_STR("*float*: Min reqd irradiance for operation [W/m2]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"rotlim", (getter)PVWatts_get_rotlim,(setter)PVWatts_set_rotlim,
	PyDoc_STR("*float*: Tracker rotation limit (+/- 1 axis) [deg]\n\n**Constraints:**\nMIN=1,MAX=90\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shade_mode_1x", (getter)PVWatts_get_shade_mode_1x,(setter)PVWatts_set_shade_mode_1x,
	PyDoc_STR("*float*: Tracker self-shading mode [0/1/2]\n\n**Options:**\n0=shading,1=backtrack,2=none\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 2 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"shading_azal", (getter)PVWatts_get_shading_azal,(setter)PVWatts_set_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Azimuth x altitude beam shading factors\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_diff", (getter)PVWatts_get_shading_diff,(setter)PVWatts_set_shading_diff,
	PyDoc_STR("*float*: Diffuse shading factor\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_mxh", (getter)PVWatts_get_shading_mxh,(setter)PVWatts_set_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Month x Hour beam shading factors\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"shading_timestep", (getter)PVWatts_get_shading_timestep,(setter)PVWatts_set_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Time step beam shading factors\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"system_size", (getter)PVWatts_get_system_size,(setter)PVWatts_set_system_size,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)PVWatts_get_tilt,(setter)PVWatts_set_tilt,
	PyDoc_STR("*float*: Tilt angle [deg]\n\n**Options:**\nH=0,V=90\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nnaof:tilt_eq_lat"),
 	NULL},
{"tilt_eq_lat", (getter)PVWatts_get_tilt_eq_lat,(setter)PVWatts_set_tilt_eq_lat,
	PyDoc_STR("*float*: Tilt=latitude override [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nna:tilt"),
 	NULL},
{"track_mode", (getter)PVWatts_get_track_mode,(setter)PVWatts_set_track_mode,
	PyDoc_STR("*float*: Tracking mode [0/1/2/3]\n\n**Info:**\nFixed,1Axis,2Axis,AziAxis\n\n**Constraints:**\nMIN=0,MAX=3,INTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tref", (getter)PVWatts_get_tref,(setter)PVWatts_set_tref,
	PyDoc_STR("*float*: Reference cell temperature [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 25.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"u0", (getter)PVWatts_get_u0,(setter)PVWatts_set_u0,
	PyDoc_STR("*float*: thermal model coeff U0\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"u1", (getter)PVWatts_get_u1,(setter)PVWatts_set_u1,
	PyDoc_STR("*float*: thermal model coeff U0\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"user_poa", (getter)PVWatts_get_user_poa,(setter)PVWatts_set_user_poa,
	PyDoc_STR("*sequence*: User-defined POA irradiance [W/m2]\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nRequired if enable_user_poa=1"),
 	NULL},
{"w_stow", (getter)PVWatts_get_w_stow,(setter)PVWatts_set_w_stow,
	PyDoc_STR("*float*: Wind stow speed [m/s]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVWatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1.PVWatts",             /*tp_name*/
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
Outputs_new(SAM_Pvwattsv1 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv1", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv1", "Outputs")){
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
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_annual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_ac_annual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_ac_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvwattsv1_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv1_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_dc_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_df(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_df_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_dn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_gh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_location(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv1_Outputs_location_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_poa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_poa_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shad_beam_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_shad_beam_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_annual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_solrad_annual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solrad_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_solrad_monthly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvwattsv1_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_sunup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_sunup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_tcell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdew(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_tdew_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tpoa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_tpoa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	PyDoc_STR("*sequence*: AC system output [Wac]"),
 	NULL},
{"ac_annual", (getter)Outputs_get_ac_annual,(setter)0,
	PyDoc_STR("*float*: Annual AC system output [kWhac]"),
 	NULL},
{"ac_monthly", (getter)Outputs_get_ac_monthly,(setter)0,
	PyDoc_STR("*sequence*: AC system output [kWhac]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"city", (getter)Outputs_get_city,(setter)0,
	PyDoc_STR("*str*: City"),
 	NULL},
{"dc", (getter)Outputs_get_dc,(setter)0,
	PyDoc_STR("*sequence*: DC array output [Wdc]"),
 	NULL},
{"dc_monthly", (getter)Outputs_get_dc_monthly,(setter)0,
	PyDoc_STR("*sequence*: DC array output [kWhdc]"),
 	NULL},
{"df", (getter)Outputs_get_df,(setter)0,
	PyDoc_STR("*sequence*: Diffuse irradiance [W/m2]"),
 	NULL},
{"dn", (getter)Outputs_get_dn,(setter)0,
	PyDoc_STR("*sequence*: Beam irradiance [W/m2]"),
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	PyDoc_STR("*float*: Site elevation [m]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"gh", (getter)Outputs_get_gh,(setter)0,
	PyDoc_STR("*sequence*: Global horizontal irradiance [W/m2]"),
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
	PyDoc_STR("*sequence*: Monthly energy [kWh]"),
 	NULL},
{"poa", (getter)Outputs_get_poa,(setter)0,
	PyDoc_STR("*sequence*: Plane of array irradiance [W/m2]"),
 	NULL},
{"poa_monthly", (getter)Outputs_get_poa_monthly,(setter)0,
	PyDoc_STR("*sequence*: Plane of array irradiance [kWh/m2]"),
 	NULL},
{"shad_beam_factor", (getter)Outputs_get_shad_beam_factor,(setter)0,
	PyDoc_STR("*sequence*: Shading factor for beam radiation"),
 	NULL},
{"solrad_annual", (getter)Outputs_get_solrad_annual,(setter)0,
	PyDoc_STR("*float*: Daily average solar irradiance [kWh/m2/day]"),
 	NULL},
{"solrad_monthly", (getter)Outputs_get_solrad_monthly,(setter)0,
	PyDoc_STR("*sequence*: Daily average solar irradiance [kWh/m2/day]"),
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	PyDoc_STR("*str*: State"),
 	NULL},
{"sunup", (getter)Outputs_get_sunup,(setter)0,
	PyDoc_STR("*sequence*: Sun up over horizon [0/1]"),
 	NULL},
{"tamb", (getter)Outputs_get_tamb,(setter)0,
	PyDoc_STR("*sequence*: Ambient temperature [C]"),
 	NULL},
{"tcell", (getter)Outputs_get_tcell,(setter)0,
	PyDoc_STR("*sequence*: Module temperature [C]"),
 	NULL},
{"tdew", (getter)Outputs_get_tdew,(setter)0,
	PyDoc_STR("*sequence*: Dew point temperature [C]"),
 	NULL},
{"tpoa", (getter)Outputs_get_tpoa,(setter)0,
	PyDoc_STR("*sequence*: Transmitted plane of array irradiance [W/m2]"),
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	PyDoc_STR("*float*: Time zone [hr]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Wind speed [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1.Outputs",             /*tp_name*/
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
 * Pvwattsv1
 */

static PyTypeObject Pvwattsv1_Type;

static CmodObject *
newPvwattsv1Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvwattsv1_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* PVWatts_obj = PVWatts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVWatts", PVWatts_obj);
	Py_DECREF(PVWatts_obj);

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

/* Pvwattsv1 methods */

static void
Pvwattsv1_dealloc(CmodObject *self)
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
Pvwattsv1_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv1_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv1_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv1"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv1_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv1"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv1_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvwattsv1_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pvwattsv1_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pvwattsv1_methods[] = {
		{"execute",           (PyCFunction)Pvwattsv1_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv1_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pvwattsv1_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv1_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvwattsv1_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pvwattsv1_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv1_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv1_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv1_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv1_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv1_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv1_getattro, /*tp_getattro*/
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
		Pvwattsv1_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv1 object */

static PyObject *
Pvwattsv1_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvwattsv1Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv1_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv1Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv1_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv1Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv1", def) < 0) {
		Pvwattsv1_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv1_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvwattsv1Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv1", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv1Module_methods[] = {
		{"new",             Pvwattsv1_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv1")},
		{"default",             Pvwattsv1_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv1\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pvwattsv1_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv1\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pvwattsv1_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvwattsv1\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pvwattsv1");


static int
Pvwattsv1Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvwattsv1_Type.tp_dict = PyDict_New();
	if (!Pvwattsv1_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Pvwattsv1_Type
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
	PyDict_SetItemString(Pvwattsv1_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to Pvwattsv1_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv1_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the PVWatts type object to Pvwattsv1_Type
	if (PyType_Ready(&PVWatts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv1_Type.tp_dict,
				"PVWatts",
				(PyObject*)&PVWatts_Type);
	Py_DECREF(&PVWatts_Type);

	/// Add the Outputs type object to Pvwattsv1_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv1_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv1 type object to the module
	if (PyType_Ready(&Pvwattsv1_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv1",
				(PyObject*)&Pvwattsv1_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv1Module_slots[] = {
		{Py_mod_exec, Pvwattsv1Module_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv1Module = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv1",
		module_doc,
		0,
		Pvwattsv1Module_methods,
		Pvwattsv1Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv1(void)
{
	return PyModuleDef_Init(&Pvwattsv1Module);
}