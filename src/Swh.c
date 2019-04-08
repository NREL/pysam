#include <Python.h>

#include <SAM_Swh.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Weather Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Swh   data_ptr;
} WeatherObject;

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_Swh data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Swh", "Weather")){
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
Weather_get_solar_resource_file(WeatherObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Swh_Weather_solar_resource_file_sget, self->data_ptr);
}

static int
Weather_set_solar_resource_file(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Swh_Weather_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"solar_resource_file", (getter)Weather_get_solar_resource_file,(setter)Weather_set_solar_resource_file,
	"local weather file path [], string.\n Constraints: LOCAL_FILE; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh.Weather",             /*tp_name*/
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
	 * SWH Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Swh   data_ptr;
} SWHObject;

static PyTypeObject SWH_Type;

static PyObject *
SWH_new(SAM_Swh data_ptr)
{
	PyObject* new_obj = SWH_Type.tp_alloc(&SWH_Type,0);

	SWHObject* SWH_obj = (SWHObject*)new_obj;

	SWH_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SWH methods */

static PyObject *
SWH_assign(SWHObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Swh", "SWH")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SWH_export(SWHObject *self, PyObject *args)
{
	PyTypeObject* tp = &SWH_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SWH_methods[] = {
		{"assign",            (PyCFunction)SWH_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SWH_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SWH_get_FRUL(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_FRUL_fget, self->data_ptr);
}

static int
SWH_set_FRUL(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_FRUL_fset, self->data_ptr);
}

static PyObject *
SWH_get_FRta(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_FRta_fget, self->data_ptr);
}

static int
SWH_set_FRta(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_FRta_fset, self->data_ptr);
}

static PyObject *
SWH_get_T_room(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_T_room_fget, self->data_ptr);
}

static int
SWH_set_T_room(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_T_room_fset, self->data_ptr);
}

static PyObject *
SWH_get_T_set(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_T_set_fget, self->data_ptr);
}

static int
SWH_set_T_set(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_T_set_fset, self->data_ptr);
}

static PyObject *
SWH_get_T_tank_max(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_T_tank_max_fget, self->data_ptr);
}

static int
SWH_set_T_tank_max(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_T_tank_max_fset, self->data_ptr);
}

static PyObject *
SWH_get_U_tank(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_U_tank_fget, self->data_ptr);
}

static int
SWH_set_U_tank(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_U_tank_fset, self->data_ptr);
}

static PyObject *
SWH_get_V_tank(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_V_tank_fget, self->data_ptr);
}

static int
SWH_set_V_tank(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_V_tank_fset, self->data_ptr);
}

static PyObject *
SWH_get_albedo(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_albedo_fget, self->data_ptr);
}

static int
SWH_set_albedo(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_albedo_fset, self->data_ptr);
}

static PyObject *
SWH_get_area_coll(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_area_coll_fget, self->data_ptr);
}

static int
SWH_set_area_coll(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_area_coll_fset, self->data_ptr);
}

static PyObject *
SWH_get_azimuth(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_azimuth_fget, self->data_ptr);
}

static int
SWH_set_azimuth(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_azimuth_fset, self->data_ptr);
}

static PyObject *
SWH_get_custom_mains(SWHObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_custom_mains_aget, self->data_ptr);
}

static int
SWH_set_custom_mains(SWHObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Swh_SWH_custom_mains_aset, self->data_ptr);
}

static PyObject *
SWH_get_custom_set(SWHObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_custom_set_aget, self->data_ptr);
}

static int
SWH_set_custom_set(SWHObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Swh_SWH_custom_set_aset, self->data_ptr);
}

static PyObject *
SWH_get_fluid(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_fluid_fget, self->data_ptr);
}

static int
SWH_set_fluid(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_fluid_fset, self->data_ptr);
}

static PyObject *
SWH_get_hx_eff(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_hx_eff_fget, self->data_ptr);
}

static int
SWH_set_hx_eff(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_hx_eff_fset, self->data_ptr);
}

static PyObject *
SWH_get_iam(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_iam_fget, self->data_ptr);
}

static int
SWH_set_iam(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_iam_fset, self->data_ptr);
}

static PyObject *
SWH_get_irrad_mode(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_irrad_mode_fget, self->data_ptr);
}

static int
SWH_set_irrad_mode(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_irrad_mode_fset, self->data_ptr);
}

static PyObject *
SWH_get_mdot(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_mdot_fget, self->data_ptr);
}

static int
SWH_set_mdot(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_mdot_fset, self->data_ptr);
}

static PyObject *
SWH_get_ncoll(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_ncoll_fget, self->data_ptr);
}

static int
SWH_set_ncoll(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_ncoll_fset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_diam(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_pipe_diam_fget, self->data_ptr);
}

static int
SWH_set_pipe_diam(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_pipe_diam_fset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_insul(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_pipe_insul_fget, self->data_ptr);
}

static int
SWH_set_pipe_insul(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_pipe_insul_fset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_k(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_pipe_k_fget, self->data_ptr);
}

static int
SWH_set_pipe_k(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_pipe_k_fset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_length(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_pipe_length_fget, self->data_ptr);
}

static int
SWH_set_pipe_length(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_pipe_length_fset, self->data_ptr);
}

static PyObject *
SWH_get_pump_eff(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_pump_eff_fget, self->data_ptr);
}

static int
SWH_set_pump_eff(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_pump_eff_fset, self->data_ptr);
}

static PyObject *
SWH_get_pump_power(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_pump_power_fget, self->data_ptr);
}

static int
SWH_set_pump_power(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_pump_power_fset, self->data_ptr);
}

static PyObject *
SWH_get_scaled_draw(SWHObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_scaled_draw_aget, self->data_ptr);
}

static int
SWH_set_scaled_draw(SWHObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Swh_SWH_scaled_draw_aset, self->data_ptr);
}

static PyObject *
SWH_get_shading_azal(SWHObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Swh_SWH_shading_azal_mget, self->data_ptr);
}

static int
SWH_set_shading_azal(SWHObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Swh_SWH_shading_azal_mset, self->data_ptr);
}

static PyObject *
SWH_get_shading_diff(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_shading_diff_fget, self->data_ptr);
}

static int
SWH_set_shading_diff(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_shading_diff_fset, self->data_ptr);
}

static PyObject *
SWH_get_shading_mxh(SWHObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Swh_SWH_shading_mxh_mget, self->data_ptr);
}

static int
SWH_set_shading_mxh(SWHObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Swh_SWH_shading_mxh_mset, self->data_ptr);
}

static PyObject *
SWH_get_shading_timestep(SWHObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Swh_SWH_shading_timestep_mget, self->data_ptr);
}

static int
SWH_set_shading_timestep(SWHObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Swh_SWH_shading_timestep_mset, self->data_ptr);
}

static PyObject *
SWH_get_sky_model(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_sky_model_fget, self->data_ptr);
}

static int
SWH_set_sky_model(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_sky_model_fset, self->data_ptr);
}

static PyObject *
SWH_get_system_capacity(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_system_capacity_fget, self->data_ptr);
}

static int
SWH_set_system_capacity(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_system_capacity_fset, self->data_ptr);
}

static PyObject *
SWH_get_tank_h2d_ratio(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_tank_h2d_ratio_fget, self->data_ptr);
}

static int
SWH_set_tank_h2d_ratio(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_tank_h2d_ratio_fset, self->data_ptr);
}

static PyObject *
SWH_get_test_flow(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_test_flow_fget, self->data_ptr);
}

static int
SWH_set_test_flow(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_test_flow_fset, self->data_ptr);
}

static PyObject *
SWH_get_test_fluid(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_test_fluid_fget, self->data_ptr);
}

static int
SWH_set_test_fluid(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_test_fluid_fset, self->data_ptr);
}

static PyObject *
SWH_get_tilt(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_tilt_fget, self->data_ptr);
}

static int
SWH_set_tilt(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_tilt_fset, self->data_ptr);
}

static PyObject *
SWH_get_use_custom_mains(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_use_custom_mains_fget, self->data_ptr);
}

static int
SWH_set_use_custom_mains(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_use_custom_mains_fset, self->data_ptr);
}

static PyObject *
SWH_get_use_custom_set(SWHObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_SWH_use_custom_set_fget, self->data_ptr);
}

static int
SWH_set_use_custom_set(SWHObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Swh_SWH_use_custom_set_fset, self->data_ptr);
}

static PyGetSetDef SWH_getset[] = {
{"FRUL", (getter)SWH_get_FRUL,(setter)SWH_set_FRUL,
	"FRUL [], number.\n Required if: *.",
 	NULL},
{"FRta", (getter)SWH_get_FRta,(setter)SWH_set_FRta,
	"FRta [], number.\n Required if: *.",
 	NULL},
{"T_room", (getter)SWH_get_T_room,(setter)SWH_set_T_room,
	"Temperature around solar tank [C], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"T_set", (getter)SWH_get_T_set,(setter)SWH_set_T_set,
	"Set temperature [C], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"T_tank_max", (getter)SWH_get_T_tank_max,(setter)SWH_set_T_tank_max,
	"Max temperature in solar tank [C], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"U_tank", (getter)SWH_get_U_tank,(setter)SWH_set_U_tank,
	"Solar tank heat loss coefficient [W/m2K], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"V_tank", (getter)SWH_get_V_tank,(setter)SWH_set_V_tank,
	"Solar tank volume [m3], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"albedo", (getter)SWH_get_albedo,(setter)SWH_set_albedo,
	"Ground reflectance factor [0..1], number.\n Constraints: FACTOR; Required if: *.",
 	NULL},
{"area_coll", (getter)SWH_get_area_coll,(setter)SWH_set_area_coll,
	"Single collector area [m2], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"azimuth", (getter)SWH_get_azimuth,(setter)SWH_set_azimuth,
	"Collector azimuth [deg], number.\n 90=E,180=S; Constraints: MIN=0,MAX=360; Required if: *.",
 	NULL},
{"custom_mains", (getter)SWH_get_custom_mains,(setter)SWH_set_custom_mains,
	"Custom mains [C], array.\n Constraints: LENGTH=8760; Required if: *.",
 	NULL},
{"custom_set", (getter)SWH_get_custom_set,(setter)SWH_set_custom_set,
	"Custom set points [C], array.\n Constraints: LENGTH=8760; Required if: *.",
 	NULL},
{"fluid", (getter)SWH_get_fluid,(setter)SWH_set_fluid,
	"Working fluid in system [], number.\n Water,Glycol; Constraints: INTEGER,MIN=0,MAX=1; Required if: *.",
 	NULL},
{"hx_eff", (getter)SWH_get_hx_eff,(setter)SWH_set_hx_eff,
	"Heat exchanger effectiveness [0..1], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"iam", (getter)SWH_get_iam,(setter)SWH_set_iam,
	"Incidence angle modifier [], number.\n Required if: *.",
 	NULL},
{"irrad_mode", (getter)SWH_get_irrad_mode,(setter)SWH_set_irrad_mode,
	"Irradiance input mode [0/1/2], number.\n Beam+Diff,Global+Beam,Global+Diff; Constraints: INTEGER,MIN=0,MAX=2; Required if: ?=0.",
 	NULL},
{"mdot", (getter)SWH_get_mdot,(setter)SWH_set_mdot,
	"Total system mass flow rate [kg/s], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"ncoll", (getter)SWH_get_ncoll,(setter)SWH_set_ncoll,
	"Number of collectors [], number.\n Constraints: POSITIVE,INTEGER; Required if: *.",
 	NULL},
{"pipe_diam", (getter)SWH_get_pipe_diam,(setter)SWH_set_pipe_diam,
	"Pipe diameter [m], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"pipe_insul", (getter)SWH_get_pipe_insul,(setter)SWH_set_pipe_insul,
	"Pipe insulation thickness [m], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"pipe_k", (getter)SWH_get_pipe_k,(setter)SWH_set_pipe_k,
	"Pipe insulation conductivity [W/m2.C], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"pipe_length", (getter)SWH_get_pipe_length,(setter)SWH_set_pipe_length,
	"Length of piping in system [m], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"pump_eff", (getter)SWH_get_pump_eff,(setter)SWH_set_pump_eff,
	"Pumping efficiency [%], number.\n Constraints: PERCENT; Required if: *.",
 	NULL},
{"pump_power", (getter)SWH_get_pump_power,(setter)SWH_set_pump_power,
	"Pump power [W], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"scaled_draw", (getter)SWH_get_scaled_draw,(setter)SWH_set_scaled_draw,
	"Hot water draw [kg/hr], array.\n Constraints: LENGTH=8760; Required if: *.",
 	NULL},
{"shading_azal", (getter)SWH_get_shading_azal,(setter)SWH_set_shading_azal,
	"Azimuth x altitude beam shading loss [%], matrix.\n Required if: ?.",
 	NULL},
{"shading_diff", (getter)SWH_get_shading_diff,(setter)SWH_set_shading_diff,
	"Diffuse shading loss [%], number.\n Required if: ?.",
 	NULL},
{"shading_mxh", (getter)SWH_get_shading_mxh,(setter)SWH_set_shading_mxh,
	"Month x Hour beam shading loss [%], matrix.\n Required if: ?.",
 	NULL},
{"shading_timestep", (getter)SWH_get_shading_timestep,(setter)SWH_set_shading_timestep,
	"Time step beam shading loss [%], matrix.\n Required if: ?.",
 	NULL},
{"sky_model", (getter)SWH_get_sky_model,(setter)SWH_set_sky_model,
	"Tilted surface irradiance model [0/1/2], number.\n Isotropic,HDKR,Perez; Constraints: INTEGER,MIN=0,MAX=2; Required if: ?=1.",
 	NULL},
{"system_capacity", (getter)SWH_get_system_capacity,(setter)SWH_set_system_capacity,
	"Nameplate capacity [kW], number.\n Required if: *.",
 	NULL},
{"tank_h2d_ratio", (getter)SWH_get_tank_h2d_ratio,(setter)SWH_set_tank_h2d_ratio,
	"Solar tank height to diameter ratio [], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"test_flow", (getter)SWH_get_test_flow,(setter)SWH_set_test_flow,
	"Flow rate used in collector test [kg/s], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"test_fluid", (getter)SWH_get_test_fluid,(setter)SWH_set_test_fluid,
	"Fluid used in collector test [], number.\n Water,Glycol; Constraints: INTEGER,MIN=0,MAX=1; Required if: *.",
 	NULL},
{"tilt", (getter)SWH_get_tilt,(setter)SWH_set_tilt,
	"Collector tilt [deg], number.\n Constraints: MIN=0,MAX=90; Required if: *.",
 	NULL},
{"use_custom_mains", (getter)SWH_get_use_custom_mains,(setter)SWH_set_use_custom_mains,
	"Use custom mains [%], number.\n Constraints: INTEGER,MIN=0,MAX=1; Required if: *.",
 	NULL},
{"use_custom_set", (getter)SWH_get_use_custom_set,(setter)SWH_set_use_custom_set,
	"Use custom set points [%], number.\n Constraints: INTEGER,MIN=0,MAX=1; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SWH_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh.SWH",             /*tp_name*/
		sizeof(SWHObject),          /*tp_basicsize*/
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
		SWH_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SWH_getset,          /*tp_getset*/
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
	SAM_Swh   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Swh data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Swh", "Outputs")){
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
Outputs_get_I_incident(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_I_incident_aget, self->data_ptr);
}

static PyObject *
Outputs_get_I_transmitted(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_I_transmitted_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_pump(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_P_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_aux(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_auxonly(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_auxonly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_deliv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_deliv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_transmitted(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_transmitted_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_useful(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_useful_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_amb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_cold(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_deliv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_deliv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_hot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_mains(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_mains_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_tank_aget, self->data_ptr);
}

static PyObject *
Outputs_get_V_cold(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_V_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_V_hot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_V_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_aux(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_annual_Q_aux_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_auxonly(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_annual_Q_auxonly_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_deliv(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_annual_Q_deliv_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_diffuse(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_diffuse_aget, self->data_ptr);
}

static PyObject *
Outputs_get_draw(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_draw_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_mode(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_mode_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_Q_aux(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_Q_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_Q_auxonly(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_Q_auxonly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_Q_deliv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_Q_deliv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shading_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_shading_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solar_fraction(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_solar_fraction_fget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_shift_hours(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Swh_Outputs_ts_shift_hours_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"I_incident", (getter)Outputs_get_I_incident,(setter)0,
	"Irradiance - Incident [W/m2], array.",
 	NULL},
{"I_transmitted", (getter)Outputs_get_I_transmitted,(setter)0,
	"Irradiance - Transmitted [W/m2], array.",
 	NULL},
{"P_pump", (getter)Outputs_get_P_pump,(setter)0,
	"P pump [kW], array.",
 	NULL},
{"Q_aux", (getter)Outputs_get_Q_aux,(setter)0,
	"Q auxiliary [kW], array.",
 	NULL},
{"Q_auxonly", (getter)Outputs_get_Q_auxonly,(setter)0,
	"Q auxiliary only [kW], array.",
 	NULL},
{"Q_deliv", (getter)Outputs_get_Q_deliv,(setter)0,
	"Q delivered [kW], array.",
 	NULL},
{"Q_loss", (getter)Outputs_get_Q_loss,(setter)0,
	"Q loss [kW], array.",
 	NULL},
{"Q_transmitted", (getter)Outputs_get_Q_transmitted,(setter)0,
	"Q transmitted [kW], array.",
 	NULL},
{"Q_useful", (getter)Outputs_get_Q_useful,(setter)0,
	"Q useful [kW], array.",
 	NULL},
{"T_amb", (getter)Outputs_get_T_amb,(setter)0,
	"T ambient [C], array.",
 	NULL},
{"T_cold", (getter)Outputs_get_T_cold,(setter)0,
	"T cold [C], array.",
 	NULL},
{"T_deliv", (getter)Outputs_get_T_deliv,(setter)0,
	"T delivered [C], array.",
 	NULL},
{"T_hot", (getter)Outputs_get_T_hot,(setter)0,
	"T hot [C], array.",
 	NULL},
{"T_mains", (getter)Outputs_get_T_mains,(setter)0,
	"T mains [C], array.",
 	NULL},
{"T_tank", (getter)Outputs_get_T_tank,(setter)0,
	"T tank [C], array.",
 	NULL},
{"V_cold", (getter)Outputs_get_V_cold,(setter)0,
	"V cold [m3], array.",
 	NULL},
{"V_hot", (getter)Outputs_get_V_hot,(setter)0,
	"V hot [m3], array.",
 	NULL},
{"annual_Q_aux", (getter)Outputs_get_annual_Q_aux,(setter)0,
	"Q auxiliary [kWh], number.",
 	NULL},
{"annual_Q_auxonly", (getter)Outputs_get_annual_Q_auxonly,(setter)0,
	"Q auxiliary only [kWh], number.",
 	NULL},
{"annual_Q_deliv", (getter)Outputs_get_annual_Q_deliv,(setter)0,
	"Q delivered [kWh], number.",
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"System energy [kWh], number.",
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	"Irradiance - Beam [W/m2], array.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"diffuse", (getter)Outputs_get_diffuse,(setter)0,
	"Irradiance - Diffuse [W/m2], array.",
 	NULL},
{"draw", (getter)Outputs_get_draw,(setter)0,
	"Hot water draw [kg/hr], array.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"System power generated [kW], array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"mode", (getter)Outputs_get_mode,(setter)0,
	"Operation mode [], array.",
 	NULL},
{"monthly_Q_aux", (getter)Outputs_get_monthly_Q_aux,(setter)0,
	"Q auxiliary [kWh], array.",
 	NULL},
{"monthly_Q_auxonly", (getter)Outputs_get_monthly_Q_auxonly,(setter)0,
	"Q auxiliary only [kWh], array.",
 	NULL},
{"monthly_Q_deliv", (getter)Outputs_get_monthly_Q_deliv,(setter)0,
	"Q delivered [kWh], array.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"System energy [kWh], array.",
 	NULL},
{"shading_loss", (getter)Outputs_get_shading_loss,(setter)0,
	"Shading losses [%], array.",
 	NULL},
{"solar_fraction", (getter)Outputs_get_solar_fraction,(setter)0,
	"Solar fraction [], number.",
 	NULL},
{"ts_shift_hours", (getter)Outputs_get_ts_shift_hours,(setter)0,
	"Time offset for interpreting time series outputs [hours], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh.Outputs",             /*tp_name*/
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
 * Swh
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Swh   data_ptr;
} SwhObject;

static PyTypeObject Swh_Type;

#define SwhObject_Check(v)      (Py_TYPE(v) == &Swh_Type)

static SwhObject *
newSwhObject(void* data_ptr)
{
	SwhObject *self;
	self = PyObject_New(SwhObject, &Swh_Type);

	PySAM_TECH_ATTR("Swh", SAM_Swh_construct)

PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

PyObject* SWH_obj = SWH_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SWH", SWH_obj);
	Py_DECREF(SWH_obj);

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

/* Swh methods */

static void
Swh_dealloc(SwhObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Swh_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Swh_execute(SwhObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Swh_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Swh_assign(SwhObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Swh"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Swh_export(SwhObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Swh_methods[] = {
		{"execute",            (PyCFunction)Swh_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Swh_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Swh_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Swh_getattro(SwhObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Swh_setattr(SwhObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Swh_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh",            /*tp_name*/
		sizeof(SwhObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Swh_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Swh_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Swh_getattro, /*tp_getattro*/
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
		Swh_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Swh object */

static PyObject *
Swh_new(PyObject *self, PyObject *args)
{
	SwhObject *rv;
	rv = newSwhObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Swh_wrap(PyObject *self, PyObject *args)
{
	SwhObject *rv;
	long int ptr = 0;
	if (!PyArg_ParseTuple(args, "l:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSwhObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Swh_default(PyObject *self, PyObject *args)
{
	SwhObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSwhObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Swh", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SwhModule_methods[] = {
		{"new",             Swh_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Swh object")},
		{"default",             Swh_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Swh object with financial model-specific default attributes\n"
				"Options: Commercial, None, Residential, LCOE Calculator, ")},
		{"wrap",             Swh_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Swh object around existing PySSC data")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Refer to http://www.github.com/nrel/PySAM for source code.");


static int
SwhModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Swh_Type.tp_dict = PyDict_New();
	if (!Swh_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Swh_Type
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
	PyDict_SetItemString(Swh_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to Swh_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(Swh_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the SWH type object to Swh_Type
	if (PyType_Ready(&SWH_Type) < 0) { goto fail; }
	PyDict_SetItemString(Swh_Type.tp_dict,
				"SWH",
				(PyObject*)&SWH_Type);
	Py_DECREF(&SWH_Type);

	/// Add the Outputs type object to Swh_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Swh_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Swh type object to the module
	if (PyType_Ready(&Swh_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Swh",
				(PyObject*)&Swh_Type);

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot SwhModule_slots[] = {
		{Py_mod_exec, SwhModule_exec},
		{0, NULL},
};

static struct PyModuleDef SwhModule = {
		PyModuleDef_HEAD_INIT,
		"Swh",
		module_doc,
		0,
		SwhModule_methods,
		SwhModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Swh(void)
{
	return PyModuleDef_Init(&SwhModule);
}