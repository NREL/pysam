#include <Python.h>

#include <SAM_TidalFileReader.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WeatherReader Group
 */ 

static PyTypeObject WeatherReader_Type;

static PyObject *
WeatherReader_new(SAM_TidalFileReader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TidalFileReader", "WeatherReader")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WeatherReader_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &WeatherReader_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TidalFileReader", "WeatherReader")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``WeatherReader_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)WeatherReader_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``WeatherReader_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)WeatherReader_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WeatherReader_get_tidal_resource_filename(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_WeatherReader_tidal_resource_filename_sget, self->data_ptr);
}

static int
WeatherReader_set_tidal_resource_filename(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TidalFileReader_WeatherReader_tidal_resource_filename_sset, self->data_ptr);
}

static PyObject *
WeatherReader_get_tidal_resource_model_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_WeatherReader_tidal_resource_model_choice_nget, self->data_ptr);
}

static int
WeatherReader_set_tidal_resource_model_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TidalFileReader_WeatherReader_tidal_resource_model_choice_nset, self->data_ptr);
}

static PyGetSetDef WeatherReader_getset[] = {
{"tidal_resource_filename", (getter)WeatherReader_get_tidal_resource_filename,(setter)WeatherReader_set_tidal_resource_filename,
	PyDoc_STR("*str*: File path with tidal resource data\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nRequired if tidal_resource_model_choice=0"),
 	NULL},
{"tidal_resource_model_choice", (getter)WeatherReader_get_tidal_resource_model_choice,(setter)WeatherReader_set_tidal_resource_model_choice,
	PyDoc_STR("*float*: Resource distribution or time series tidal resource data [0/1]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WeatherReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TidalFileReader.WeatherReader",             /*tp_name*/
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
Outputs_new(SAM_TidalFileReader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TidalFileReader", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TidalFileReader", "Outputs")){
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
Outputs_get_average_power_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_average_power_flux_nget, self->data_ptr);
}

static PyObject *
Outputs_get_bathymetry(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_bathymetry_sget, self->data_ptr);
}

static PyObject *
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_country(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_country_sget, self->data_ptr);
}

static PyObject *
Outputs_get_data_source(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_data_source_sget, self->data_ptr);
}

static PyObject *
Outputs_get_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_distance_to_shore_file(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_distance_to_shore_file_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_location(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_location_sget, self->data_ptr);
}

static PyObject *
Outputs_get_location_id(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_location_id_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_minute(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_minute_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_name_sget, self->data_ptr);
}

static PyObject *
Outputs_get_nearby_buoy_number(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_nearby_buoy_number_sget, self->data_ptr);
}

static PyObject *
Outputs_get_notes(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_notes_sget, self->data_ptr);
}

static PyObject *
Outputs_get_number_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_number_hours_nget, self->data_ptr);
}

static PyObject *
Outputs_get_number_records(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_number_records_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sea_bed(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_sea_bed_sget, self->data_ptr);
}

static PyObject *
Outputs_get_significant_wave_height(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_significant_wave_height_aget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TidalFileReader_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_tidal_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_tidal_velocity_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_water_depth_file(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TidalFileReader_Outputs_water_depth_file_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TidalFileReader_Outputs_year_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"average_power_flux", (getter)Outputs_get_average_power_flux,(setter)0,
	PyDoc_STR("*float*: Average power flux [kW/m]"),
 	NULL},
{"bathymetry", (getter)Outputs_get_bathymetry,(setter)0,
	PyDoc_STR("*str*: Bathymetry"),
 	NULL},
{"city", (getter)Outputs_get_city,(setter)0,
	PyDoc_STR("*str*: City"),
 	NULL},
{"country", (getter)Outputs_get_country,(setter)0,
	PyDoc_STR("*str*: Country"),
 	NULL},
{"data_source", (getter)Outputs_get_data_source,(setter)0,
	PyDoc_STR("*str*: Data source"),
 	NULL},
{"day", (getter)Outputs_get_day,(setter)0,
	PyDoc_STR("*sequence*: Day [dy]"),
 	NULL},
{"distance_to_shore_file", (getter)Outputs_get_distance_to_shore_file,(setter)0,
	PyDoc_STR("*float*: Distance to shore [m]"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Hour [hr]"),
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude [deg]"),
 	NULL},
{"location", (getter)Outputs_get_location,(setter)0,
	PyDoc_STR("*str*: Location"),
 	NULL},
{"location_id", (getter)Outputs_get_location_id,(setter)0,
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
{"name", (getter)Outputs_get_name,(setter)0,
	PyDoc_STR("*str*: Name"),
 	NULL},
{"nearby_buoy_number", (getter)Outputs_get_nearby_buoy_number,(setter)0,
	PyDoc_STR("*str*: Nearby buoy number"),
 	NULL},
{"notes", (getter)Outputs_get_notes,(setter)0,
	PyDoc_STR("*str*: Notes"),
 	NULL},
{"number_hours", (getter)Outputs_get_number_hours,(setter)0,
	PyDoc_STR("*float*: Number of hours in wave time series"),
 	NULL},
{"number_records", (getter)Outputs_get_number_records,(setter)0,
	PyDoc_STR("*float*: Number of records in wave time series"),
 	NULL},
{"sea_bed", (getter)Outputs_get_sea_bed,(setter)0,
	PyDoc_STR("*str*: Sea bed"),
 	NULL},
{"significant_wave_height", (getter)Outputs_get_significant_wave_height,(setter)0,
	PyDoc_STR("*sequence*: Wave height time series data [m]"),
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	PyDoc_STR("*str*: State"),
 	NULL},
{"tidal_velocity", (getter)Outputs_get_tidal_velocity,(setter)0,
	PyDoc_STR("*sequence*: Tidal velocity [m/s]"),
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	PyDoc_STR("*float*: Time zone"),
 	NULL},
{"water_depth_file", (getter)Outputs_get_water_depth_file,(setter)0,
	PyDoc_STR("*float*: Water depth [m]"),
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
		"TidalFileReader.Outputs",             /*tp_name*/
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
 * TidalFileReader
 */

static PyTypeObject TidalFileReader_Type;

static CmodObject *
newTidalFileReaderObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TidalFileReader_Type);

	PySAM_TECH_ATTR()

	PyObject* WeatherReader_obj = WeatherReader_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WeatherReader", WeatherReader_obj);
	Py_DECREF(WeatherReader_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* TidalFileReader methods */

static void
TidalFileReader_dealloc(CmodObject *self)
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
TidalFileReader_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
TidalFileReader_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TidalFileReader_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TidalFileReader_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TidalFileReader"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TidalFileReader_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TidalFileReader"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TidalFileReader_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TidalFileReader_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TidalFileReader_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TidalFileReader_methods[] = {
		{"execute",           (PyCFunction)TidalFileReader_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TidalFileReader_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather Reader': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TidalFileReader_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Weather Reader': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TidalFileReader_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TidalFileReader_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TidalFileReader_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)TidalFileReader_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TidalFileReader_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TidalFileReader_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TidalFileReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TidalFileReader",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TidalFileReader_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TidalFileReader_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TidalFileReader_getattro, /*tp_getattro*/
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
		TidalFileReader_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TidalFileReader object */

static PyObject *
TidalFileReader_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTidalFileReaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TidalFileReader_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTidalFileReaderObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TidalFileReader_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTidalFileReaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TidalFileReader", def) < 0) {
		TidalFileReader_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TidalFileReader_from_existing(PyObject *self, PyObject *args)
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

	rv = newTidalFileReaderObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TidalFileReader", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TidalFileReaderModule_methods[] = {
		{"new",             TidalFileReader_new,         METH_VARARGS,
				PyDoc_STR("new() -> TidalFileReader")},
		{"default",             TidalFileReader_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TidalFileReader\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"MEtidalLCOECalculator\"*\n\n		- *\"MEtidalNone\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TidalFileReader_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TidalFileReader\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TidalFileReader_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TidalFileReader\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "TidalFileReader");


static int
TidalFileReaderModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TidalFileReader_Type.tp_dict = PyDict_New();
	if (!TidalFileReader_Type.tp_dict) { goto fail; }

	/// Add the WeatherReader type object to TidalFileReader_Type
	if (PyType_Ready(&WeatherReader_Type) < 0) { goto fail; }
	PyDict_SetItemString(TidalFileReader_Type.tp_dict,
				"WeatherReader",
				(PyObject*)&WeatherReader_Type);
	Py_DECREF(&WeatherReader_Type);

	/// Add the Outputs type object to TidalFileReader_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TidalFileReader_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TidalFileReader type object to the module
	if (PyType_Ready(&TidalFileReader_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TidalFileReader",
				(PyObject*)&TidalFileReader_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TidalFileReaderModule_slots[] = {
		{Py_mod_exec, TidalFileReaderModule_exec},
		{0, NULL},
};

static struct PyModuleDef TidalFileReaderModule = {
		PyModuleDef_HEAD_INIT,
		"TidalFileReader",
		module_doc,
		0,
		TidalFileReaderModule_methods,
		TidalFileReaderModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TidalFileReader(void)
{
	return PyModuleDef_Init(&TidalFileReaderModule);
}