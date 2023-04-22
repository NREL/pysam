#include <Python.h>

#include <SAM_Swh.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SolarResource Group
 */ 

static PyTypeObject SolarResource_Type;

static PyObject *
SolarResource_new(SAM_Swh data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Swh", "SolarResource")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Swh", "SolarResource")){
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
SolarResource_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Swh_SolarResource_solar_resource_data_tget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Swh_SolarResource_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Swh_SolarResource_solar_resource_file_sget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Swh_SolarResource_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef SolarResource_getset[] = {
{"solar_resource_data", (getter)SolarResource_get_solar_resource_data,(setter)SolarResource_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather data\n\n**Info:**\ndn,df,tdry,wspd,lat,lon,tz\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"solar_resource_file", (getter)SolarResource_get_solar_resource_file,(setter)SolarResource_set_solar_resource_file,
	PyDoc_STR("*str*: local weather file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh.SolarResource",             /*tp_name*/
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
 * SWH Group
 */ 

static PyTypeObject SWH_Type;

static PyObject *
SWH_new(SAM_Swh data_ptr)
{
	PyObject* new_obj = SWH_Type.tp_alloc(&SWH_Type,0);

	VarGroupObject* SWH_obj = (VarGroupObject*)new_obj;

	SWH_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SWH methods */

static PyObject *
SWH_assign(VarGroupObject *self, PyObject *args)
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
SWH_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SWH_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Swh", "SWH")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SWH_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SWH_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SWH_methods[] = {
		{"assign",            (PyCFunction)SWH_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SWH_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SWH_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SWH_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SWH_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SWH_get_FRUL(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_FRUL_nget, self->data_ptr);
}

static int
SWH_set_FRUL(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_FRUL_nset, self->data_ptr);
}

static PyObject *
SWH_get_FRta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_FRta_nget, self->data_ptr);
}

static int
SWH_set_FRta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_FRta_nset, self->data_ptr);
}

static PyObject *
SWH_get_T_room(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_T_room_nget, self->data_ptr);
}

static int
SWH_set_T_room(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_T_room_nset, self->data_ptr);
}

static PyObject *
SWH_get_T_set(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_T_set_nget, self->data_ptr);
}

static int
SWH_set_T_set(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_T_set_nset, self->data_ptr);
}

static PyObject *
SWH_get_T_tank_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_T_tank_max_nget, self->data_ptr);
}

static int
SWH_set_T_tank_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_T_tank_max_nset, self->data_ptr);
}

static PyObject *
SWH_get_U_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_U_tank_nget, self->data_ptr);
}

static int
SWH_set_U_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_U_tank_nset, self->data_ptr);
}

static PyObject *
SWH_get_V_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_V_tank_nget, self->data_ptr);
}

static int
SWH_set_V_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_V_tank_nset, self->data_ptr);
}

static PyObject *
SWH_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_albedo_nget, self->data_ptr);
}

static int
SWH_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_albedo_nset, self->data_ptr);
}

static PyObject *
SWH_get_area_coll(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_area_coll_nget, self->data_ptr);
}

static int
SWH_set_area_coll(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_area_coll_nset, self->data_ptr);
}

static PyObject *
SWH_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_azimuth_nget, self->data_ptr);
}

static int
SWH_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_azimuth_nset, self->data_ptr);
}

static PyObject *
SWH_get_custom_mains(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_custom_mains_aget, self->data_ptr);
}

static int
SWH_set_custom_mains(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Swh_SWH_custom_mains_aset, self->data_ptr);
}

static PyObject *
SWH_get_custom_set(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_custom_set_aget, self->data_ptr);
}

static int
SWH_set_custom_set(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Swh_SWH_custom_set_aset, self->data_ptr);
}

static PyObject *
SWH_get_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_fluid_nget, self->data_ptr);
}

static int
SWH_set_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_fluid_nset, self->data_ptr);
}

static PyObject *
SWH_get_hx_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_hx_eff_nget, self->data_ptr);
}

static int
SWH_set_hx_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_hx_eff_nset, self->data_ptr);
}

static PyObject *
SWH_get_iam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_iam_nget, self->data_ptr);
}

static int
SWH_set_iam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_iam_nset, self->data_ptr);
}

static PyObject *
SWH_get_irrad_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_irrad_mode_nget, self->data_ptr);
}

static int
SWH_set_irrad_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_irrad_mode_nset, self->data_ptr);
}

static PyObject *
SWH_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_load_aget, self->data_ptr);
}

static int
SWH_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Swh_SWH_load_aset, self->data_ptr);
}

static PyObject *
SWH_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_load_escalation_aget, self->data_ptr);
}

static int
SWH_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Swh_SWH_load_escalation_aset, self->data_ptr);
}

static PyObject *
SWH_get_mdot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_mdot_nget, self->data_ptr);
}

static int
SWH_set_mdot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_mdot_nset, self->data_ptr);
}

static PyObject *
SWH_get_ncoll(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_ncoll_nget, self->data_ptr);
}

static int
SWH_set_ncoll(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_ncoll_nset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_diam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_pipe_diam_nget, self->data_ptr);
}

static int
SWH_set_pipe_diam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_pipe_diam_nset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_insul(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_pipe_insul_nget, self->data_ptr);
}

static int
SWH_set_pipe_insul(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_pipe_insul_nset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_k(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_pipe_k_nget, self->data_ptr);
}

static int
SWH_set_pipe_k(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_pipe_k_nset, self->data_ptr);
}

static PyObject *
SWH_get_pipe_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_pipe_length_nget, self->data_ptr);
}

static int
SWH_set_pipe_length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_pipe_length_nset, self->data_ptr);
}

static PyObject *
SWH_get_pump_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_pump_eff_nget, self->data_ptr);
}

static int
SWH_set_pump_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_pump_eff_nset, self->data_ptr);
}

static PyObject *
SWH_get_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_pump_power_nget, self->data_ptr);
}

static int
SWH_set_pump_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_pump_power_nset, self->data_ptr);
}

static PyObject *
SWH_get_scaled_draw(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_SWH_scaled_draw_aget, self->data_ptr);
}

static int
SWH_set_scaled_draw(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Swh_SWH_scaled_draw_aset, self->data_ptr);
}

static PyObject *
SWH_get_sky_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_sky_model_nget, self->data_ptr);
}

static int
SWH_set_sky_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_sky_model_nset, self->data_ptr);
}

static PyObject *
SWH_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_system_capacity_nget, self->data_ptr);
}

static int
SWH_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_system_capacity_nset, self->data_ptr);
}

static PyObject *
SWH_get_tank_h2d_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_tank_h2d_ratio_nget, self->data_ptr);
}

static int
SWH_set_tank_h2d_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_tank_h2d_ratio_nset, self->data_ptr);
}

static PyObject *
SWH_get_test_flow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_test_flow_nget, self->data_ptr);
}

static int
SWH_set_test_flow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_test_flow_nset, self->data_ptr);
}

static PyObject *
SWH_get_test_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_test_fluid_nget, self->data_ptr);
}

static int
SWH_set_test_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_test_fluid_nset, self->data_ptr);
}

static PyObject *
SWH_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_tilt_nget, self->data_ptr);
}

static int
SWH_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_tilt_nset, self->data_ptr);
}

static PyObject *
SWH_get_use_custom_mains(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_use_custom_mains_nget, self->data_ptr);
}

static int
SWH_set_use_custom_mains(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_use_custom_mains_nset, self->data_ptr);
}

static PyObject *
SWH_get_use_custom_set(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_SWH_use_custom_set_nget, self->data_ptr);
}

static int
SWH_set_use_custom_set(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_SWH_use_custom_set_nset, self->data_ptr);
}

static PyGetSetDef SWH_getset[] = {
{"FRUL", (getter)SWH_get_FRUL,(setter)SWH_set_FRUL,
	PyDoc_STR("*float*: FRUL\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``FRUL``:\n\n\t - system_capacity\n"),
 	NULL},
{"FRta", (getter)SWH_get_FRta,(setter)SWH_set_FRta,
	PyDoc_STR("*float*: FRta\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``FRta``:\n\n\t - system_capacity\n"),
 	NULL},
{"T_room", (getter)SWH_get_T_room,(setter)SWH_set_T_room,
	PyDoc_STR("*float*: Temperature around solar tank [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"T_set", (getter)SWH_get_T_set,(setter)SWH_set_T_set,
	PyDoc_STR("*float*: Set temperature [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"T_tank_max", (getter)SWH_get_T_tank_max,(setter)SWH_set_T_tank_max,
	PyDoc_STR("*float*: Max temperature in solar tank [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"U_tank", (getter)SWH_get_U_tank,(setter)SWH_set_U_tank,
	PyDoc_STR("*float*: Solar tank heat loss coefficient [W/m2K]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"V_tank", (getter)SWH_get_V_tank,(setter)SWH_set_V_tank,
	PyDoc_STR("*float*: Solar tank volume [m3]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"albedo", (getter)SWH_get_albedo,(setter)SWH_set_albedo,
	PyDoc_STR("*float*: Ground reflectance factor [0..1]\n\n**Constraints:**\nFACTOR\n\n**Required:**\nTrue"),
 	NULL},
{"area_coll", (getter)SWH_get_area_coll,(setter)SWH_set_area_coll,
	PyDoc_STR("*float*: Single collector area [m2]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``area_coll``:\n\n\t - system_capacity\n"),
 	NULL},
{"azimuth", (getter)SWH_get_azimuth,(setter)SWH_set_azimuth,
	PyDoc_STR("*float*: Collector azimuth [deg]\n\n**Options:**\n90=E,180=S\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\nTrue"),
 	NULL},
{"custom_mains", (getter)SWH_get_custom_mains,(setter)SWH_set_custom_mains,
	PyDoc_STR("*sequence*: Custom mains [C]\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nTrue"),
 	NULL},
{"custom_set", (getter)SWH_get_custom_set,(setter)SWH_set_custom_set,
	PyDoc_STR("*sequence*: Custom set points [C]\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nTrue"),
 	NULL},
{"fluid", (getter)SWH_get_fluid,(setter)SWH_set_fluid,
	PyDoc_STR("*float*: Working fluid in system\n\n**Info:**\nWater,Glycol\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"hx_eff", (getter)SWH_get_hx_eff,(setter)SWH_set_hx_eff,
	PyDoc_STR("*float*: Heat exchanger effectiveness [0..1]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"iam", (getter)SWH_get_iam,(setter)SWH_set_iam,
	PyDoc_STR("*float*: Incidence angle modifier\n\n**Required:**\nTrue"),
 	NULL},
{"irrad_mode", (getter)SWH_get_irrad_mode,(setter)SWH_set_irrad_mode,
	PyDoc_STR("*float*: Irradiance input mode [0/1/2]\n\n**Info:**\nBeam+Diff,Global+Beam,Global+Diff\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"load", (getter)SWH_get_load,(setter)SWH_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]"),
 	NULL},
{"load_escalation", (getter)SWH_get_load_escalation,(setter)SWH_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"mdot", (getter)SWH_get_mdot,(setter)SWH_set_mdot,
	PyDoc_STR("*float*: Total system mass flow rate [kg/s]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"ncoll", (getter)SWH_get_ncoll,(setter)SWH_set_ncoll,
	PyDoc_STR("*float*: Number of collectors\n\n**Constraints:**\nPOSITIVE,INTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``ncoll``:\n\n\t - system_capacity\n"),
 	NULL},
{"pipe_diam", (getter)SWH_get_pipe_diam,(setter)SWH_set_pipe_diam,
	PyDoc_STR("*float*: Pipe diameter [m]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"pipe_insul", (getter)SWH_get_pipe_insul,(setter)SWH_set_pipe_insul,
	PyDoc_STR("*float*: Pipe insulation thickness [m]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"pipe_k", (getter)SWH_get_pipe_k,(setter)SWH_set_pipe_k,
	PyDoc_STR("*float*: Pipe insulation conductivity [W/m-C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"pipe_length", (getter)SWH_get_pipe_length,(setter)SWH_set_pipe_length,
	PyDoc_STR("*float*: Length of piping in system [m]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"pump_eff", (getter)SWH_get_pump_eff,(setter)SWH_set_pump_eff,
	PyDoc_STR("*float*: Pumping efficiency [%]\n\n**Constraints:**\nPERCENT\n\n**Required:**\nTrue"),
 	NULL},
{"pump_power", (getter)SWH_get_pump_power,(setter)SWH_set_pump_power,
	PyDoc_STR("*float*: Pump power [W]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"scaled_draw", (getter)SWH_get_scaled_draw,(setter)SWH_set_scaled_draw,
	PyDoc_STR("*sequence*: Hot water draw [kg/hr]\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nTrue"),
 	NULL},
{"sky_model", (getter)SWH_get_sky_model,(setter)SWH_set_sky_model,
	PyDoc_STR("*float*: Tilted surface irradiance model [0/1/2]\n\n**Info:**\nIsotropic,HDKR,Perez\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_capacity", (getter)SWH_get_system_capacity,(setter)SWH_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - FRUL\n\t - FRta\n\t - area_coll\n\t - ncoll\n"),
 	NULL},
{"tank_h2d_ratio", (getter)SWH_get_tank_h2d_ratio,(setter)SWH_set_tank_h2d_ratio,
	PyDoc_STR("*float*: Solar tank height to diameter ratio\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"test_flow", (getter)SWH_get_test_flow,(setter)SWH_set_test_flow,
	PyDoc_STR("*float*: Flow rate used in collector test [kg/s]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"test_fluid", (getter)SWH_get_test_fluid,(setter)SWH_set_test_fluid,
	PyDoc_STR("*float*: Fluid used in collector test\n\n**Info:**\nWater,Glycol\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)SWH_get_tilt,(setter)SWH_set_tilt,
	PyDoc_STR("*float*: Collector tilt [deg]\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nTrue"),
 	NULL},
{"use_custom_mains", (getter)SWH_get_use_custom_mains,(setter)SWH_set_use_custom_mains,
	PyDoc_STR("*float*: Use custom mains [%]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"use_custom_set", (getter)SWH_get_use_custom_set,(setter)SWH_set_use_custom_set,
	PyDoc_STR("*float*: Use custom set points [%]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SWH_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh.SWH",             /*tp_name*/
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
		SWH_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SWH_getset,          /*tp_getset*/
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
Shading_new(SAM_Swh data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Swh", "Shading")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Swh", "Shading")){
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
	return PySAM_matrix_getter(SAM_Swh_Shading_shading_azal_mget, self->data_ptr);
}

static int
Shading_set_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Swh_Shading_shading_azal_mset, self->data_ptr);
}

static PyObject *
Shading_get_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_diff_nget, self->data_ptr);
}

static int
Shading_set_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_azal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_en_azal_nget, self->data_ptr);
}

static int
Shading_set_shading_en_azal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_en_azal_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_en_diff_nget, self->data_ptr);
}

static int
Shading_set_shading_en_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_en_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_en_mxh_nget, self->data_ptr);
}

static int
Shading_set_shading_en_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_en_mxh_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_en_string_option_nget, self->data_ptr);
}

static int
Shading_set_shading_en_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_en_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_en_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_en_timestep_nget, self->data_ptr);
}

static int
Shading_set_shading_en_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_en_timestep_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Swh_Shading_shading_mxh_mget, self->data_ptr);
}

static int
Shading_set_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Swh_Shading_shading_mxh_mset, self->data_ptr);
}

static PyObject *
Shading_get_shading_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Shading_shading_string_option_nget, self->data_ptr);
}

static int
Shading_set_shading_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Swh_Shading_shading_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Swh_Shading_shading_timestep_mget, self->data_ptr);
}

static int
Shading_set_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Swh_Shading_shading_timestep_mset, self->data_ptr);
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
		"Swh.Shading",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Swh data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Swh", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Swh", "Outputs")){
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
Outputs_get_I_incident(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_I_incident_aget, self->data_ptr);
}

static PyObject *
Outputs_get_I_transmitted(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_I_transmitted_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_P_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_aux(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_auxonly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_auxonly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_deliv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_deliv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_transmitted(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_transmitted_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_useful(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_Q_useful_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_amb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_amb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_deliv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_deliv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_mains(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_mains_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_T_tank_aget, self->data_ptr);
}

static PyObject *
Outputs_get_V_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_V_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_V_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_V_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_aux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_annual_Q_aux_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_auxonly(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_annual_Q_auxonly_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_deliv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_annual_Q_deliv_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Swh_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_diffuse_aget, self->data_ptr);
}

static PyObject *
Outputs_get_draw(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_draw_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mode(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_mode_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_Q_aux(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_Q_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_Q_auxonly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_Q_auxonly_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_Q_deliv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_Q_deliv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shading_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Swh_Outputs_shading_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solar_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_solar_fraction_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_shift_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Swh_Outputs_ts_shift_hours_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"I_incident", (getter)Outputs_get_I_incident,(setter)0,
	PyDoc_STR("*sequence*: Irradiance - Incident [W/m2]"),
 	NULL},
{"I_transmitted", (getter)Outputs_get_I_transmitted,(setter)0,
	PyDoc_STR("*sequence*: Irradiance - Transmitted [W/m2]"),
 	NULL},
{"P_pump", (getter)Outputs_get_P_pump,(setter)0,
	PyDoc_STR("*sequence*: P pump [kW]"),
 	NULL},
{"Q_aux", (getter)Outputs_get_Q_aux,(setter)0,
	PyDoc_STR("*sequence*: Q auxiliary [kW]"),
 	NULL},
{"Q_auxonly", (getter)Outputs_get_Q_auxonly,(setter)0,
	PyDoc_STR("*sequence*: Q auxiliary only [kW]"),
 	NULL},
{"Q_deliv", (getter)Outputs_get_Q_deliv,(setter)0,
	PyDoc_STR("*sequence*: Q delivered [kW]"),
 	NULL},
{"Q_loss", (getter)Outputs_get_Q_loss,(setter)0,
	PyDoc_STR("*sequence*: Q loss [kW]"),
 	NULL},
{"Q_transmitted", (getter)Outputs_get_Q_transmitted,(setter)0,
	PyDoc_STR("*sequence*: Q transmitted [kW]"),
 	NULL},
{"Q_useful", (getter)Outputs_get_Q_useful,(setter)0,
	PyDoc_STR("*sequence*: Q useful [kW]"),
 	NULL},
{"T_amb", (getter)Outputs_get_T_amb,(setter)0,
	PyDoc_STR("*sequence*: T ambient [C]"),
 	NULL},
{"T_cold", (getter)Outputs_get_T_cold,(setter)0,
	PyDoc_STR("*sequence*: T cold [C]"),
 	NULL},
{"T_deliv", (getter)Outputs_get_T_deliv,(setter)0,
	PyDoc_STR("*sequence*: T delivered [C]"),
 	NULL},
{"T_hot", (getter)Outputs_get_T_hot,(setter)0,
	PyDoc_STR("*sequence*: T hot [C]"),
 	NULL},
{"T_mains", (getter)Outputs_get_T_mains,(setter)0,
	PyDoc_STR("*sequence*: T mains [C]"),
 	NULL},
{"T_tank", (getter)Outputs_get_T_tank,(setter)0,
	PyDoc_STR("*sequence*: T tank [C]"),
 	NULL},
{"V_cold", (getter)Outputs_get_V_cold,(setter)0,
	PyDoc_STR("*sequence*: V cold [m3]"),
 	NULL},
{"V_hot", (getter)Outputs_get_V_hot,(setter)0,
	PyDoc_STR("*sequence*: V hot [m3]"),
 	NULL},
{"annual_Q_aux", (getter)Outputs_get_annual_Q_aux,(setter)0,
	PyDoc_STR("*float*: Q auxiliary [kWh]"),
 	NULL},
{"annual_Q_auxonly", (getter)Outputs_get_annual_Q_auxonly,(setter)0,
	PyDoc_STR("*float*: Q auxiliary only [kWh]"),
 	NULL},
{"annual_Q_deliv", (getter)Outputs_get_annual_Q_deliv,(setter)0,
	PyDoc_STR("*float*: Q delivered [kWh]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: System energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	PyDoc_STR("*sequence*: Irradiance - Beam [W/m2]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"diffuse", (getter)Outputs_get_diffuse,(setter)0,
	PyDoc_STR("*sequence*: Irradiance - Diffuse [W/m2]"),
 	NULL},
{"draw", (getter)Outputs_get_draw,(setter)0,
	PyDoc_STR("*sequence*: Hot water draw [kg/hr]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"mode", (getter)Outputs_get_mode,(setter)0,
	PyDoc_STR("*sequence*: Operation mode"),
 	NULL},
{"monthly_Q_aux", (getter)Outputs_get_monthly_Q_aux,(setter)0,
	PyDoc_STR("*sequence*: Q auxiliary [kWh]"),
 	NULL},
{"monthly_Q_auxonly", (getter)Outputs_get_monthly_Q_auxonly,(setter)0,
	PyDoc_STR("*sequence*: Q auxiliary only [kWh]"),
 	NULL},
{"monthly_Q_deliv", (getter)Outputs_get_monthly_Q_deliv,(setter)0,
	PyDoc_STR("*sequence*: Q delivered [kWh]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: System energy [kWh]"),
 	NULL},
{"shading_loss", (getter)Outputs_get_shading_loss,(setter)0,
	PyDoc_STR("*sequence*: Shading losses [%]"),
 	NULL},
{"solar_fraction", (getter)Outputs_get_solar_fraction,(setter)0,
	PyDoc_STR("*float*: Solar fraction"),
 	NULL},
{"ts_shift_hours", (getter)Outputs_get_ts_shift_hours,(setter)0,
	PyDoc_STR("*float*: Time offset for interpreting time series outputs [hours]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh.Outputs",             /*tp_name*/
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
 * Swh
 */

static PyTypeObject Swh_Type;

static CmodObject *
newSwhObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Swh_Type);

	PySAM_TECH_ATTR()

	PyObject* SolarResource_obj = SolarResource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarResource", SolarResource_obj);
	Py_DECREF(SolarResource_obj);

	PyObject* SWH_obj = SWH_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SWH", SWH_obj);
	Py_DECREF(SWH_obj);

	PyObject* Shading_obj = Shading_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Shading", Shading_obj);
	Py_DECREF(Shading_obj);

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

/* Swh methods */

static void
Swh_dealloc(CmodObject *self)
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
Swh_execute(CmodObject *self, PyObject *args)
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
Swh_assign(CmodObject *self, PyObject *args)
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
Swh_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Swh"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Swh_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Swh_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Swh_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Swh_methods[] = {
		{"execute",           (PyCFunction)Swh_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Swh_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Swh_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Swh_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Swh_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Swh_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Swh_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Swh_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Swh_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Swh",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
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
		"This class contains all the variable information for running a simulation. Variables are grouped together in the subclasses as properties. If property assignments are the wrong type, an error is thrown.",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Swh_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Swh object */

static PyObject *
Swh_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSwhObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Swh_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSwhObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Swh_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSwhObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Swh", def) < 0) {
		Swh_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Swh_from_existing(PyObject *self, PyObject *args)
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

	rv = newSwhObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Swh", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SwhModule_methods[] = {
		{"new",             Swh_new,         METH_VARARGS,
				PyDoc_STR("new() -> Swh")},
		{"default",             Swh_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Swh\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"SolarWaterHeatingCommercial\"*\n\n		- *\"SolarWaterHeatingLCOECalculator\"*\n\n		- *\"SolarWaterHeatingNone\"*\n\n		- *\"SolarWaterHeatingResidential\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Swh_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Swh\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Swh_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Swh\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Solar water heating model for residential and commercial building applications");


static int
SwhModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Swh_Type.tp_dict = PyDict_New();
	if (!Swh_Type.tp_dict) { goto fail; }

	/// Add the SolarResource type object to Swh_Type
	if (PyType_Ready(&SolarResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(Swh_Type.tp_dict,
				"SolarResource",
				(PyObject*)&SolarResource_Type);
	Py_DECREF(&SolarResource_Type);

	/// Add the SWH type object to Swh_Type
	if (PyType_Ready(&SWH_Type) < 0) { goto fail; }
	PyDict_SetItemString(Swh_Type.tp_dict,
				"SWH",
				(PyObject*)&SWH_Type);
	Py_DECREF(&SWH_Type);

	/// Add the Shading type object to Swh_Type
	if (PyType_Ready(&Shading_Type) < 0) { goto fail; }
	PyDict_SetItemString(Swh_Type.tp_dict,
				"Shading",
				(PyObject*)&Shading_Type);
	Py_DECREF(&Shading_Type);

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