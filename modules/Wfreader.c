#include <Python.h>

#include <SAM_Wfreader.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WeatherReader Group
 */ 

static PyTypeObject WeatherReader_Type;

static PyObject *
WeatherReader_new(SAM_Wfreader data_ptr)
{
	PyObject* new_obj = WeatherReader_Type.tp_alloc(&WeatherReader_Type,0);

	VarGroupObject* WeatherReader_obj = (VarGroupObject*)new_obj;

	WeatherReader_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* WeatherReader methods */

static PyObject *
WeatherReader_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Wfreader", "WeatherReader")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WeatherReader_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &WeatherReader_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WeatherReader_methods[] = {
		{"assign",            (PyCFunction)WeatherReader_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``WeatherReader_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)WeatherReader_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WeatherReader_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_WeatherReader_file_name_sget, self->data_ptr);
}

static int
WeatherReader_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Wfreader_WeatherReader_file_name_sset, self->data_ptr);
}

static PyObject *
WeatherReader_get_header_only(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_WeatherReader_header_only_nget, self->data_ptr);
}

static int
WeatherReader_set_header_only(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Wfreader_WeatherReader_header_only_nset, self->data_ptr);
}

static PyGetSetDef WeatherReader_getset[] = {
{"file_name", (getter)WeatherReader_get_file_name,(setter)WeatherReader_set_file_name,
	PyDoc_STR("*str*: local weather file path\n\n*Constraints*: LOCAL_FILE\n\n*Required*: True"),
 	NULL},
{"header_only", (getter)WeatherReader_get_header_only,(setter)WeatherReader_set_header_only,
	PyDoc_STR("*float*: read header only [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WeatherReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfreader.WeatherReader",             /*tp_name*/
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
		WeatherReader_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WeatherReader_getset,          /*tp_getset*/
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
Outputs_new(SAM_Wfreader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Wfreader", "Outputs")){
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
Outputs_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_albedo_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_albedo_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_beam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_beam_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_diffuse_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_global(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_global_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_snow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_snow_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_tdry_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_annual_wspd_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_country(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_country_sget, self->data_ptr);
}

static PyObject *
Outputs_get_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_description(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_description_sget, self->data_ptr);
}

static PyObject *
Outputs_get_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_diffuse_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_format(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_format_sget, self->data_ptr);
}

static PyObject *
Outputs_get_global(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_global_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_location(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_location_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_minute(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_minute_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nrecords(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_nrecords_nget, self->data_ptr);
}

static PyObject *
Outputs_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_poa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rhum(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_rhum_aget, self->data_ptr);
}

static PyObject *
Outputs_get_snow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_snow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_source(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_source_sget, self->data_ptr);
}

static PyObject *
Outputs_get_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_start_nget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_step_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tdew(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_tdew_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Wfreader_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_url(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Wfreader_Outputs_url_sget, self->data_ptr);
}

static PyObject *
Outputs_get_wdir(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_wdir_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_wspd_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Wfreader_Outputs_year_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"albedo", (getter)Outputs_get_albedo,(setter)0,
	PyDoc_STR("*sequence*: Ground Reflectance [frac]"),
 	NULL},
{"annual_albedo", (getter)Outputs_get_annual_albedo,(setter)0,
	PyDoc_STR("*float*: Average albedo"),
 	NULL},
{"annual_beam", (getter)Outputs_get_annual_beam,(setter)0,
	PyDoc_STR("*float*: Average daily beam normal [kWh/m2/day]"),
 	NULL},
{"annual_diffuse", (getter)Outputs_get_annual_diffuse,(setter)0,
	PyDoc_STR("*float*: Average daily diffuse [kWh/m2/day]"),
 	NULL},
{"annual_global", (getter)Outputs_get_annual_global,(setter)0,
	PyDoc_STR("*float*: Average daily global horizontal [kWh/m2/day]"),
 	NULL},
{"annual_snow", (getter)Outputs_get_annual_snow,(setter)0,
	PyDoc_STR("*float*: Maximum snow depth [cm]"),
 	NULL},
{"annual_tdry", (getter)Outputs_get_annual_tdry,(setter)0,
	PyDoc_STR("*float*: Average dry bulb temperature ['C]"),
 	NULL},
{"annual_wspd", (getter)Outputs_get_annual_wspd,(setter)0,
	PyDoc_STR("*float*: Average wind speed [m/s]"),
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	PyDoc_STR("*sequence*: Beam Normal Irradiance [W/m2]"),
 	NULL},
{"city", (getter)Outputs_get_city,(setter)0,
	PyDoc_STR("*str*: City"),
 	NULL},
{"country", (getter)Outputs_get_country,(setter)0,
	PyDoc_STR("*str*: Country"),
 	NULL},
{"day", (getter)Outputs_get_day,(setter)0,
	PyDoc_STR("*sequence*: Day [dy]"),
 	NULL},
{"description", (getter)Outputs_get_description,(setter)0,
	PyDoc_STR("*str*: Description"),
 	NULL},
{"diffuse", (getter)Outputs_get_diffuse,(setter)0,
	PyDoc_STR("*sequence*: Diffuse Horizontal Irradiance [W/m2]"),
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	PyDoc_STR("*float*: Elevation [m]"),
 	NULL},
{"format", (getter)Outputs_get_format,(setter)0,
	PyDoc_STR("*str*: File format"),
 	NULL},
{"global", (getter)Outputs_get_global,(setter)0,
	PyDoc_STR("*sequence*: Global Horizontal Irradiance [W/m2]"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Hour [hr]"),
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
{"minute", (getter)Outputs_get_minute,(setter)0,
	PyDoc_STR("*sequence*: Minute [min]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Month [mn]"),
 	NULL},
{"nrecords", (getter)Outputs_get_nrecords,(setter)0,
	PyDoc_STR("*float*: Number of records"),
 	NULL},
{"poa", (getter)Outputs_get_poa,(setter)0,
	PyDoc_STR("*sequence*: Plane of Array Irradiance [W/m2]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Atmospheric Pressure [millibar]"),
 	NULL},
{"rhum", (getter)Outputs_get_rhum,(setter)0,
	PyDoc_STR("*sequence*: Relative Humidity [%]"),
 	NULL},
{"snow", (getter)Outputs_get_snow,(setter)0,
	PyDoc_STR("*sequence*: Snow Depth [cm]"),
 	NULL},
{"source", (getter)Outputs_get_source,(setter)0,
	PyDoc_STR("*str*: Source"),
 	NULL},
{"start", (getter)Outputs_get_start,(setter)0,
	PyDoc_STR("*float*: Start [sec]"),
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	PyDoc_STR("*str*: State"),
 	NULL},
{"step", (getter)Outputs_get_step,(setter)0,
	PyDoc_STR("*float*: Step [sec]"),
 	NULL},
{"tdew", (getter)Outputs_get_tdew,(setter)0,
	PyDoc_STR("*sequence*: Temperature Dew Point ['C]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Temperature Dry Bulb ['C]"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Temperature Wet Bulb ['C]"),
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	PyDoc_STR("*float*: Time zone [hr]"),
 	NULL},
{"url", (getter)Outputs_get_url,(setter)0,
	PyDoc_STR("*str*: URL"),
 	NULL},
{"wdir", (getter)Outputs_get_wdir,(setter)0,
	PyDoc_STR("*sequence*: Wind Direction [deg]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Wind Speed [m/s]"),
 	NULL},
{"year", (getter)Outputs_get_year,(setter)0,
	PyDoc_STR("*sequence*: Year [yr]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfreader.Outputs",             /*tp_name*/
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
 * Wfreader
 */

static PyTypeObject Wfreader_Type;

static CmodObject *
newWfreaderObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Wfreader_Type);

	PySAM_TECH_ATTR()

	PyObject* WeatherReader_obj = WeatherReader_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WeatherReader", WeatherReader_obj);
	Py_DECREF(WeatherReader_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Wfreader methods */

static void
Wfreader_dealloc(CmodObject *self)
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
Wfreader_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Wfreader_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Wfreader_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Wfreader"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Wfreader_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Wfreader_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Wfreader_methods[] = {
		{"execute",            (PyCFunction)Wfreader_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Wfreader_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather Reader': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Wfreader_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Wfreader_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Wfreader_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Wfreader_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Wfreader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Wfreader",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Wfreader_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Wfreader_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Wfreader_getattro, /*tp_getattro*/
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
		Wfreader_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Wfreader object */

static PyObject *
Wfreader_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWfreaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Wfreader_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWfreaderObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Wfreader_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWfreaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Wfreader", def);

	return (PyObject *)rv;
}

static PyObject *
Wfreader_from_existing(PyObject *self, PyObject *args)
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

	rv = newWfreaderObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Wfreader", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WfreaderModule_methods[] = {
		{"new",             Wfreader_new,         METH_VARARGS,
				PyDoc_STR("new() -> Wfreader")},
		{"default",             Wfreader_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Wfreader\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Wfreader_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Wfreader\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Wfreader_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Wfreader\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Wfreader");


static int
WfreaderModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Wfreader_Type.tp_dict = PyDict_New();
	if (!Wfreader_Type.tp_dict) { goto fail; }

	/// Add the WeatherReader type object to Wfreader_Type
	if (PyType_Ready(&WeatherReader_Type) < 0) { goto fail; }
	PyDict_SetItemString(Wfreader_Type.tp_dict,
				"WeatherReader",
				(PyObject*)&WeatherReader_Type);
	Py_DECREF(&WeatherReader_Type);

	/// Add the Outputs type object to Wfreader_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Wfreader_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Wfreader type object to the module
	if (PyType_Ready(&Wfreader_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Wfreader",
				(PyObject*)&Wfreader_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WfreaderModule_slots[] = {
		{Py_mod_exec, WfreaderModule_exec},
		{0, NULL},
};

static struct PyModuleDef WfreaderModule = {
		PyModuleDef_HEAD_INIT,
		"Wfreader",
		module_doc,
		0,
		WfreaderModule_methods,
		WfreaderModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Wfreader(void)
{
	return PyModuleDef_Init(&WfreaderModule);
}