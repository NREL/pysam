#include <Python.h>

#include <SAM_Poacalib.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * POACalibrate Group
 */ 

static PyTypeObject POACalibrate_Type;

static PyObject *
POACalibrate_new(SAM_Poacalib data_ptr)
{
	PyObject* new_obj = POACalibrate_Type.tp_alloc(&POACalibrate_Type,0);

	VarGroupObject* POACalibrate_obj = (VarGroupObject*)new_obj;

	POACalibrate_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* POACalibrate methods */

static PyObject *
POACalibrate_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Poacalib", "POACalibrate")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
POACalibrate_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &POACalibrate_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Poacalib", "POACalibrate")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
POACalibrate_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &POACalibrate_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef POACalibrate_methods[] = {
		{"assign",            (PyCFunction)POACalibrate_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``POACalibrate_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)POACalibrate_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``POACalibrate_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)POACalibrate_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
POACalibrate_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_albedo_nget, self->data_ptr);
}

static int
POACalibrate_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_albedo_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_array_az(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_array_az_nget, self->data_ptr);
}

static int
POACalibrate_set_array_az(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_array_az_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_array_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_array_tilt_nget, self->data_ptr);
}

static int
POACalibrate_set_array_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_array_tilt_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Poacalib_POACalibrate_beam_aget, self->data_ptr);
}

static int
POACalibrate_set_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Poacalib_POACalibrate_beam_aset, self->data_ptr);
}

static PyObject *
POACalibrate_get_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Poacalib_POACalibrate_diffuse_aget, self->data_ptr);
}

static int
POACalibrate_set_diffuse(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Poacalib_POACalibrate_diffuse_aset, self->data_ptr);
}

static PyObject *
POACalibrate_get_elevation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_elevation_nget, self->data_ptr);
}

static int
POACalibrate_set_elevation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_elevation_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_latitude(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_latitude_nget, self->data_ptr);
}

static int
POACalibrate_set_latitude(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_latitude_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_longitude(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_longitude_nget, self->data_ptr);
}

static int
POACalibrate_set_longitude(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_longitude_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_poa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Poacalib_POACalibrate_poa_aget, self->data_ptr);
}

static int
POACalibrate_set_poa(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Poacalib_POACalibrate_poa_aset, self->data_ptr);
}

static PyObject *
POACalibrate_get_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_pressure_nget, self->data_ptr);
}

static int
POACalibrate_set_pressure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_pressure_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_tamb_nget, self->data_ptr);
}

static int
POACalibrate_set_tamb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_tamb_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_time_zone(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_time_zone_nget, self->data_ptr);
}

static int
POACalibrate_set_time_zone(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_time_zone_nset, self->data_ptr);
}

static PyObject *
POACalibrate_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Poacalib_POACalibrate_year_nget, self->data_ptr);
}

static int
POACalibrate_set_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Poacalib_POACalibrate_year_nset, self->data_ptr);
}

static PyGetSetDef POACalibrate_getset[] = {
{"albedo", (getter)POACalibrate_get_albedo,(setter)POACalibrate_set_albedo,
	PyDoc_STR("*float*: Albedo\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"array_az", (getter)POACalibrate_get_array_az,(setter)POACalibrate_set_array_az,
	PyDoc_STR("*float*: Array Azimuth [degrees]\n\n**Options:**\n0=N, 90=E, 180=S\n\n**Constraints:**\nMIN=0,MAX=360\n\n**Required:**\nTrue"),
 	NULL},
{"array_tilt", (getter)POACalibrate_get_array_tilt,(setter)POACalibrate_set_array_tilt,
	PyDoc_STR("*float*: Array tilt [degrees]\n\n**Info:**\n0-90\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nTrue"),
 	NULL},
{"beam", (getter)POACalibrate_get_beam,(setter)POACalibrate_set_beam,
	PyDoc_STR("*sequence*: Beam Irradiation [W/m^2]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nTrue"),
 	NULL},
{"diffuse", (getter)POACalibrate_get_diffuse,(setter)POACalibrate_set_diffuse,
	PyDoc_STR("*sequence*: Diffuse Irradiation [W/m^2]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nTrue"),
 	NULL},
{"elevation", (getter)POACalibrate_get_elevation,(setter)POACalibrate_set_elevation,
	PyDoc_STR("*float*: Elevation [m]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"latitude", (getter)POACalibrate_get_latitude,(setter)POACalibrate_set_latitude,
	PyDoc_STR("*float*: Latitude [decimal degrees]\n\n**Options:**\nN= positive\n\n**Required:**\nTrue"),
 	NULL},
{"longitude", (getter)POACalibrate_get_longitude,(setter)POACalibrate_set_longitude,
	PyDoc_STR("*float*: Longitude [decimal degrees]\n\n**Options:**\nE= positive\n\n**Required:**\nTrue"),
 	NULL},
{"poa", (getter)POACalibrate_get_poa,(setter)POACalibrate_set_poa,
	PyDoc_STR("*sequence*: Plane of Array [W/m^2]\n\n**Constraints:**\nLENGTH=8760\n\n**Required:**\nTrue"),
 	NULL},
{"pressure", (getter)POACalibrate_get_pressure,(setter)POACalibrate_set_pressure,
	PyDoc_STR("*float*: Pressure [millibars]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"tamb", (getter)POACalibrate_get_tamb,(setter)POACalibrate_set_tamb,
	PyDoc_STR("*float*: Ambient Temperature (dry bulb temperature) [°C]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"time_zone", (getter)POACalibrate_get_time_zone,(setter)POACalibrate_set_time_zone,
	PyDoc_STR("*float*: Time Zone\n\n**Options:**\n-7= Denver\n\n**Constraints:**\nMIN=-12,MAX=12\n\n**Required:**\nTrue"),
 	NULL},
{"year", (getter)POACalibrate_get_year,(setter)POACalibrate_set_year,
	PyDoc_STR("*float*: Year\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject POACalibrate_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Poacalib.POACalibrate",             /*tp_name*/
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
		POACalibrate_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		POACalibrate_getset,          /*tp_getset*/
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
Outputs_new(SAM_Poacalib data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Poacalib", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Poacalib", "Outputs")){
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
Outputs_get_pcalc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Poacalib_Outputs_pcalc_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"pcalc", (getter)Outputs_get_pcalc,(setter)0,
	PyDoc_STR("*sequence*: Calculated POA [W/m^2]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Poacalib.Outputs",             /*tp_name*/
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
 * Poacalib
 */

static PyTypeObject Poacalib_Type;

static CmodObject *
newPoacalibObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Poacalib_Type);

	PySAM_TECH_ATTR()

	PyObject* POACalibrate_obj = POACalibrate_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "POACalibrate", POACalibrate_obj);
	Py_DECREF(POACalibrate_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Poacalib methods */

static void
Poacalib_dealloc(CmodObject *self)
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
Poacalib_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Poacalib_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Poacalib_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Poacalib"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Poacalib_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Poacalib"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Poacalib_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Poacalib_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Poacalib_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Poacalib_methods[] = {
		{"execute",           (PyCFunction)Poacalib_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Poacalib_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'POA Calibrate': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Poacalib_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'POA Calibrate': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Poacalib_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Poacalib_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Poacalib_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Poacalib_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Poacalib_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Poacalib_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Poacalib",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Poacalib_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Poacalib_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Poacalib_getattro, /*tp_getattro*/
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
		Poacalib_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Poacalib object */

static PyObject *
Poacalib_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPoacalibObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Poacalib_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPoacalibObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Poacalib_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPoacalibObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Poacalib", def) < 0) {
		Poacalib_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Poacalib_from_existing(PyObject *self, PyObject *args)
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

	rv = newPoacalibObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Poacalib", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef PoacalibModule_methods[] = {
		{"new",             Poacalib_new,         METH_VARARGS,
				PyDoc_STR("new() -> Poacalib")},
		{"default",             Poacalib_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Poacalib\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Poacalib_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Poacalib\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Poacalib_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Poacalib\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Poacalib");


static int
PoacalibModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Poacalib_Type.tp_dict = PyDict_New();
	if (!Poacalib_Type.tp_dict) { goto fail; }

	/// Add the POACalibrate type object to Poacalib_Type
	if (PyType_Ready(&POACalibrate_Type) < 0) { goto fail; }
	PyDict_SetItemString(Poacalib_Type.tp_dict,
				"POACalibrate",
				(PyObject*)&POACalibrate_Type);
	Py_DECREF(&POACalibrate_Type);

	/// Add the Outputs type object to Poacalib_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Poacalib_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Poacalib type object to the module
	if (PyType_Ready(&Poacalib_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Poacalib",
				(PyObject*)&Poacalib_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot PoacalibModule_slots[] = {
		{Py_mod_exec, PoacalibModule_exec},
		{0, NULL},
};

static struct PyModuleDef PoacalibModule = {
		PyModuleDef_HEAD_INIT,
		"Poacalib",
		module_doc,
		0,
		PoacalibModule_methods,
		PoacalibModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Poacalib(void)
{
	return PyModuleDef_Init(&PoacalibModule);
}