#include <Python.h>

#include <SAM_WindFileReader.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WeatherReader Group
 */ 

static PyTypeObject WeatherReader_Type;

static PyObject *
WeatherReader_new(SAM_WindFileReader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "WindFileReader", "WeatherReader")){
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
	return PySAM_string_getter(SAM_WindFileReader_WeatherReader_file_name_sget, self->data_ptr);
}

static int
WeatherReader_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_WindFileReader_WeatherReader_file_name_sset, self->data_ptr);
}

static PyObject *
WeatherReader_get_interpolate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_WeatherReader_interpolate_nget, self->data_ptr);
}

static int
WeatherReader_set_interpolate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindFileReader_WeatherReader_interpolate_nset, self->data_ptr);
}

static PyObject *
WeatherReader_get_requested_ht(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_WeatherReader_requested_ht_nget, self->data_ptr);
}

static int
WeatherReader_set_requested_ht(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindFileReader_WeatherReader_requested_ht_nset, self->data_ptr);
}

static PyObject *
WeatherReader_get_scan_header_only(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_WeatherReader_scan_header_only_nget, self->data_ptr);
}

static int
WeatherReader_set_scan_header_only(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindFileReader_WeatherReader_scan_header_only_nset, self->data_ptr);
}

static PyGetSetDef WeatherReader_getset[] = {
{"file_name", (getter)WeatherReader_get_file_name,(setter)WeatherReader_set_file_name,
	PyDoc_STR("*str*: local weather file path\n\n*Constraints*: LOCAL_FILE\n\n*Required*: True"),
 	NULL},
{"interpolate", (getter)WeatherReader_get_interpolate,(setter)WeatherReader_set_interpolate,
	PyDoc_STR("*float*: interpolate to closest height measured? [m]\n\n*Constraints*: BOOLEAN\n\n*Required*: True if scan_header_only=0"),
 	NULL},
{"requested_ht", (getter)WeatherReader_get_requested_ht,(setter)WeatherReader_set_requested_ht,
	PyDoc_STR("*float*: requested measurement height [m]\n\n*Required*: True"),
 	NULL},
{"scan_header_only", (getter)WeatherReader_get_scan_header_only,(setter)WeatherReader_set_scan_header_only,
	PyDoc_STR("*float*: only reader headers [0/1]\n\n*Constraints*: BOOLEAN\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WeatherReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WindFileReader.WeatherReader",             /*tp_name*/
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
Outputs_new(SAM_WindFileReader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "WindFileReader", "Outputs")){
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
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindFileReader_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_closest_dir_meas_ht(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_Outputs_closest_dir_meas_ht_nget, self->data_ptr);
}

static PyObject *
Outputs_get_closest_speed_meas_ht(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_Outputs_closest_speed_meas_ht_nget, self->data_ptr);
}

static PyObject *
Outputs_get_country(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindFileReader_Outputs_country_sget, self->data_ptr);
}

static PyObject *
Outputs_get_description(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindFileReader_Outputs_description_sget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_location_id(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindFileReader_Outputs_location_id_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_WindFileReader_Outputs_pressure_aget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindFileReader_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_WindFileReader_Outputs_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_direction(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_WindFileReader_Outputs_wind_direction_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_speed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_WindFileReader_Outputs_wind_speed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindFileReader_Outputs_year_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"city", (getter)Outputs_get_city,(setter)0,
	PyDoc_STR("*str*: City"),
 	NULL},
{"closest_dir_meas_ht", (getter)Outputs_get_closest_dir_meas_ht,(setter)0,
	PyDoc_STR("*float*: Height of closest direction meas in file [m]"),
 	NULL},
{"closest_speed_meas_ht", (getter)Outputs_get_closest_speed_meas_ht,(setter)0,
	PyDoc_STR("*float*: Height of closest speed meas in file [m]"),
 	NULL},
{"country", (getter)Outputs_get_country,(setter)0,
	PyDoc_STR("*str*: Country"),
 	NULL},
{"description", (getter)Outputs_get_description,(setter)0,
	PyDoc_STR("*str*: Description"),
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	PyDoc_STR("*float*: Elevation [m]"),
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude [deg]"),
 	NULL},
{"location_id", (getter)Outputs_get_location_id,(setter)0,
	PyDoc_STR("*str*: Location ID"),
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	PyDoc_STR("*float*: Longitude [deg]"),
 	NULL},
{"pressure", (getter)Outputs_get_pressure,(setter)0,
	PyDoc_STR("*sequence*: Atmospheric Pressure [atm]"),
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	PyDoc_STR("*str*: State"),
 	NULL},
{"temperature", (getter)Outputs_get_temperature,(setter)0,
	PyDoc_STR("*sequence*: Temperature ['C]"),
 	NULL},
{"wind_direction", (getter)Outputs_get_wind_direction,(setter)0,
	PyDoc_STR("*sequence*: Wind Direction [deg]"),
 	NULL},
{"wind_speed", (getter)Outputs_get_wind_speed,(setter)0,
	PyDoc_STR("*sequence*: Wind Speed [m/s]"),
 	NULL},
{"year", (getter)Outputs_get_year,(setter)0,
	PyDoc_STR("*float*: Calendar year of data"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WindFileReader.Outputs",             /*tp_name*/
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
 * WindFileReader
 */

static PyTypeObject WindFileReader_Type;

static CmodObject *
newWindFileReaderObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &WindFileReader_Type);

	PySAM_TECH_ATTR()

	PyObject* WeatherReader_obj = WeatherReader_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WeatherReader", WeatherReader_obj);
	Py_DECREF(WeatherReader_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* WindFileReader methods */

static void
WindFileReader_dealloc(CmodObject *self)
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
WindFileReader_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_WindFileReader_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
WindFileReader_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "WindFileReader"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
WindFileReader_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
WindFileReader_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef WindFileReader_methods[] = {
		{"execute",            (PyCFunction)WindFileReader_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)WindFileReader_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather Reader': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)WindFileReader_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)WindFileReader_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindFileReader_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
WindFileReader_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject WindFileReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WindFileReader",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)WindFileReader_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)WindFileReader_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)WindFileReader_getattro, /*tp_getattro*/
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
		WindFileReader_methods,      /*tp_methods*/
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


/* Function of no arguments returning new WindFileReader object */

static PyObject *
WindFileReader_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWindFileReaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
WindFileReader_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindFileReaderObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
WindFileReader_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindFileReaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "WindFileReader", def);

	return (PyObject *)rv;
}

static PyObject *
WindFileReader_from_existing(PyObject *self, PyObject *args)
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

	rv = newWindFileReaderObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "WindFileReader", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WindFileReaderModule_methods[] = {
		{"new",             WindFileReader_new,         METH_VARARGS,
				PyDoc_STR("new() -> WindFileReader")},
		{"default",             WindFileReader_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> WindFileReader\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             WindFileReader_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> WindFileReader\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   WindFileReader_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> WindFileReader\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "WindFileReader");


static int
WindFileReaderModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	WindFileReader_Type.tp_dict = PyDict_New();
	if (!WindFileReader_Type.tp_dict) { goto fail; }

	/// Add the WeatherReader type object to WindFileReader_Type
	if (PyType_Ready(&WeatherReader_Type) < 0) { goto fail; }
	PyDict_SetItemString(WindFileReader_Type.tp_dict,
				"WeatherReader",
				(PyObject*)&WeatherReader_Type);
	Py_DECREF(&WeatherReader_Type);

	/// Add the Outputs type object to WindFileReader_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(WindFileReader_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the WindFileReader type object to the module
	if (PyType_Ready(&WindFileReader_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"WindFileReader",
				(PyObject*)&WindFileReader_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WindFileReaderModule_slots[] = {
		{Py_mod_exec, WindFileReaderModule_exec},
		{0, NULL},
};

static struct PyModuleDef WindFileReaderModule = {
		PyModuleDef_HEAD_INIT,
		"WindFileReader",
		module_doc,
		0,
		WindFileReaderModule_methods,
		WindFileReaderModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_WindFileReader(void)
{
	return PyModuleDef_Init(&WindFileReaderModule);
}