#include <Python.h>

#include <SAM_WaveFileReader.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WeatherReader Group
 */ 

static PyTypeObject WeatherReader_Type;

static PyObject *
WeatherReader_new(SAM_WaveFileReader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "WaveFileReader", "WeatherReader")){
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
WeatherReader_get_use_specific_wf_wave(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WaveFileReader_WeatherReader_use_specific_wf_wave_nget, self->data_ptr);
}

static int
WeatherReader_set_use_specific_wf_wave(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WaveFileReader_WeatherReader_use_specific_wf_wave_nset, self->data_ptr);
}

static PyObject *
WeatherReader_get_wave_resource_filename(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_WeatherReader_wave_resource_filename_sget, self->data_ptr);
}

static int
WeatherReader_set_wave_resource_filename(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_WaveFileReader_WeatherReader_wave_resource_filename_sset, self->data_ptr);
}

static PyGetSetDef WeatherReader_getset[] = {
{"use_specific_wf_wave", (getter)WeatherReader_get_use_specific_wf_wave,(setter)WeatherReader_set_use_specific_wf_wave,
	PyDoc_STR("*float*: user specified file [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 0\n\n*Changes to this variable may require updating the values of the following*: \n\t - wave_resource_filename\n"),
 	NULL},
{"wave_resource_filename", (getter)WeatherReader_get_wave_resource_filename,(setter)WeatherReader_set_wave_resource_filename,
	PyDoc_STR("*str*: local weather file path\n\n*Constraints*: LOCAL_FILE\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - use_specific_wf_wave\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WeatherReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WaveFileReader.WeatherReader",             /*tp_name*/
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
Outputs_new(SAM_WaveFileReader data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "WaveFileReader", "Outputs")){
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
Outputs_get_average_power_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WaveFileReader_Outputs_average_power_flux_nget, self->data_ptr);
}

static PyObject *
Outputs_get_bathymetry(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_bathymetry_sget, self->data_ptr);
}

static PyObject *
Outputs_get_city(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_city_sget, self->data_ptr);
}

static PyObject *
Outputs_get_country(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_country_sget, self->data_ptr);
}

static PyObject *
Outputs_get_data_source(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_data_source_sget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WaveFileReader_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WaveFileReader_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_name_sget, self->data_ptr);
}

static PyObject *
Outputs_get_nearby_buoy_number(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_nearby_buoy_number_sget, self->data_ptr);
}

static PyObject *
Outputs_get_notes(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_notes_sget, self->data_ptr);
}

static PyObject *
Outputs_get_sea_bed(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_sea_bed_sget, self->data_ptr);
}

static PyObject *
Outputs_get_state(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WaveFileReader_Outputs_state_sget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WaveFileReader_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wave_resource_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_WaveFileReader_Outputs_wave_resource_matrix_mget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"average_power_flux", (getter)Outputs_get_average_power_flux,(setter)0,
	PyDoc_STR("*float*: Distance to shore [kW/m]"),
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
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude [deg]"),
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	PyDoc_STR("*float*: Longitude [deg]"),
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
{"sea_bed", (getter)Outputs_get_sea_bed,(setter)0,
	PyDoc_STR("*str*: Sea bed"),
 	NULL},
{"state", (getter)Outputs_get_state,(setter)0,
	PyDoc_STR("*str*: State"),
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	PyDoc_STR("*float*: Time zone"),
 	NULL},
{"wave_resource_matrix", (getter)Outputs_get_wave_resource_matrix,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Frequency distribution of resource [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WaveFileReader.Outputs",             /*tp_name*/
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
 * WaveFileReader
 */

static PyTypeObject WaveFileReader_Type;

static CmodObject *
newWaveFileReaderObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &WaveFileReader_Type);

	PySAM_TECH_ATTR()

	PyObject* WeatherReader_obj = WeatherReader_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WeatherReader", WeatherReader_obj);
	Py_DECREF(WeatherReader_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* WaveFileReader methods */

static void
WaveFileReader_dealloc(CmodObject *self)
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
WaveFileReader_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_WaveFileReader_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
WaveFileReader_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "WaveFileReader"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
WaveFileReader_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
WaveFileReader_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef WaveFileReader_methods[] = {
		{"execute",            (PyCFunction)WaveFileReader_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)WaveFileReader_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather Reader': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)WaveFileReader_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)WaveFileReader_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WaveFileReader_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
WaveFileReader_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject WaveFileReader_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WaveFileReader",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)WaveFileReader_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)WaveFileReader_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)WaveFileReader_getattro, /*tp_getattro*/
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
		WaveFileReader_methods,      /*tp_methods*/
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


/* Function of no arguments returning new WaveFileReader object */

static PyObject *
WaveFileReader_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWaveFileReaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
WaveFileReader_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWaveFileReaderObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
WaveFileReader_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWaveFileReaderObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "WaveFileReader", def);

	return (PyObject *)rv;
}

static PyObject *
WaveFileReader_from_existing(PyObject *self, PyObject *args)
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

	rv = newWaveFileReaderObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "WaveFileReader", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WaveFileReaderModule_methods[] = {
		{"new",             WaveFileReader_new,         METH_VARARGS,
				PyDoc_STR("new() -> WaveFileReader")},
		{"default",             WaveFileReader_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> WaveFileReader\n\nUse financial config-specific default attributes\n"
				"config options:\n\n- \"MEwaveLCOECalculator\"")},
		{"wrap",             WaveFileReader_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> WaveFileReader\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   WaveFileReader_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> WaveFileReader\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "WaveFileReader");


static int
WaveFileReaderModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	WaveFileReader_Type.tp_dict = PyDict_New();
	if (!WaveFileReader_Type.tp_dict) { goto fail; }

	/// Add the WeatherReader type object to WaveFileReader_Type
	if (PyType_Ready(&WeatherReader_Type) < 0) { goto fail; }
	PyDict_SetItemString(WaveFileReader_Type.tp_dict,
				"WeatherReader",
				(PyObject*)&WeatherReader_Type);
	Py_DECREF(&WeatherReader_Type);

	/// Add the Outputs type object to WaveFileReader_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(WaveFileReader_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the WaveFileReader type object to the module
	if (PyType_Ready(&WaveFileReader_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"WaveFileReader",
				(PyObject*)&WaveFileReader_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WaveFileReaderModule_slots[] = {
		{Py_mod_exec, WaveFileReaderModule_exec},
		{0, NULL},
};

static struct PyModuleDef WaveFileReaderModule = {
		PyModuleDef_HEAD_INIT,
		"WaveFileReader",
		module_doc,
		0,
		WaveFileReaderModule_methods,
		WaveFileReaderModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_WaveFileReader(void)
{
	return PyModuleDef_Init(&WaveFileReaderModule);
}