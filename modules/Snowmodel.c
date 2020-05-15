#include <Python.h>

#include <SAM_Snowmodel.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * PVSnowModel Group
 */ 

static PyTypeObject PVSnowModel_Type;

static PyObject *
PVSnowModel_new(SAM_Snowmodel data_ptr)
{
	PyObject* new_obj = PVSnowModel_Type.tp_alloc(&PVSnowModel_Type,0);

	VarGroupObject* PVSnowModel_obj = (VarGroupObject*)new_obj;

	PVSnowModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PVSnowModel methods */

static PyObject *
PVSnowModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Snowmodel", "PVSnowModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVSnowModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PVSnowModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PVSnowModel_methods[] = {
		{"assign",            (PyCFunction)PVSnowModel_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``PVSnowModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PVSnowModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PVSnowModel_get_snowdepth(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_PVSnowModel_snowdepth_aget, self->data_ptr);
}

static int
PVSnowModel_set_snowdepth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_PVSnowModel_snowdepth_aset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_subarray1_nmody(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Snowmodel_PVSnowModel_subarray1_nmody_nget, self->data_ptr);
}

static int
PVSnowModel_set_subarray1_nmody(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Snowmodel_PVSnowModel_subarray1_nmody_nset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_subarray1_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_PVSnowModel_subarray1_poa_shaded_aget, self->data_ptr);
}

static int
PVSnowModel_set_subarray1_poa_shaded(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_PVSnowModel_subarray1_poa_shaded_aset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_subarray1_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_PVSnowModel_subarray1_surf_tilt_aget, self->data_ptr);
}

static int
PVSnowModel_set_subarray1_surf_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_PVSnowModel_subarray1_surf_tilt_aset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_subarray1_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Snowmodel_PVSnowModel_subarray1_tilt_nget, self->data_ptr);
}

static int
PVSnowModel_set_subarray1_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Snowmodel_PVSnowModel_subarray1_tilt_nset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_subarray1_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Snowmodel_PVSnowModel_subarray1_track_mode_nget, self->data_ptr);
}

static int
PVSnowModel_set_subarray1_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Snowmodel_PVSnowModel_subarray1_track_mode_nset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_PVSnowModel_tdry_aget, self->data_ptr);
}

static int
PVSnowModel_set_tdry(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_PVSnowModel_tdry_aset, self->data_ptr);
}

static PyObject *
PVSnowModel_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_PVSnowModel_wspd_aget, self->data_ptr);
}

static int
PVSnowModel_set_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_PVSnowModel_wspd_aset, self->data_ptr);
}

static PyGetSetDef PVSnowModel_getset[] = {
{"snowdepth", (getter)PVSnowModel_get_snowdepth,(setter)PVSnowModel_set_snowdepth,
	PyDoc_STR("*sequence*: Snow Depth [cm]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"subarray1_nmody", (getter)PVSnowModel_get_subarray1_nmody,(setter)PVSnowModel_set_subarray1_nmody,
	PyDoc_STR("*float*: Number of Modules in a Row\n\n*Required*: True"),
 	NULL},
{"subarray1_poa_shaded", (getter)PVSnowModel_get_subarray1_poa_shaded,(setter)PVSnowModel_set_subarray1_poa_shaded,
	PyDoc_STR("*sequence*: Plane of Array Incidence [W/m^2]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"subarray1_surf_tilt", (getter)PVSnowModel_get_subarray1_surf_tilt,(setter)PVSnowModel_set_subarray1_surf_tilt,
	PyDoc_STR("*sequence*: Surface Tilt [Degrees]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"subarray1_tilt", (getter)PVSnowModel_get_subarray1_tilt,(setter)PVSnowModel_set_subarray1_tilt,
	PyDoc_STR("*float*: Base tilt [Degrees]\n\n*Required*: True"),
 	NULL},
{"subarray1_track_mode", (getter)PVSnowModel_get_subarray1_track_mode,(setter)PVSnowModel_set_subarray1_track_mode,
	PyDoc_STR("*float*: Tracking Mode\n\n*Required*: True"),
 	NULL},
{"tdry", (getter)PVSnowModel_get_tdry,(setter)PVSnowModel_set_tdry,
	PyDoc_STR("*sequence*: Ambient Temperature [Degrees Celsius]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"wspd", (getter)PVSnowModel_get_wspd,(setter)PVSnowModel_set_wspd,
	PyDoc_STR("*sequence*: Wind Speed [m/s]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVSnowModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Snowmodel.PVSnowModel",             /*tp_name*/
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
		PVSnowModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PVSnowModel_getset,          /*tp_getset*/
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
 * TimeSeries Group
 */ 

static PyTypeObject TimeSeries_Type;

static PyObject *
TimeSeries_new(SAM_Snowmodel data_ptr)
{
	PyObject* new_obj = TimeSeries_Type.tp_alloc(&TimeSeries_Type,0);

	VarGroupObject* TimeSeries_obj = (VarGroupObject*)new_obj;

	TimeSeries_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeSeries methods */

static PyObject *
TimeSeries_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Snowmodel", "TimeSeries")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeSeries_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeSeries_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeSeries_methods[] = {
		{"assign",            (PyCFunction)TimeSeries_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``TimeSeries_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeSeries_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeSeries_get_hourly_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_TimeSeries_hourly_gen_aget, self->data_ptr);
}

static int
TimeSeries_set_hourly_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_TimeSeries_hourly_gen_aset, self->data_ptr);
}

static PyObject *
TimeSeries_get_sunup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_TimeSeries_sunup_aget, self->data_ptr);
}

static int
TimeSeries_set_sunup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Snowmodel_TimeSeries_sunup_aset, self->data_ptr);
}

static PyGetSetDef TimeSeries_getset[] = {
{"hourly_gen", (getter)TimeSeries_get_hourly_gen,(setter)TimeSeries_set_hourly_gen,
	PyDoc_STR("*sequence*: Hourly Energy [kwh]\n\n*Constraints*: LENGTH=8760\n\n*Required*: True"),
 	NULL},
{"sunup", (getter)TimeSeries_get_sunup,(setter)TimeSeries_set_sunup,
	PyDoc_STR("*sequence*: Sun up over horizon [0/1]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeSeries_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Snowmodel.TimeSeries",             /*tp_name*/
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
		TimeSeries_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeSeries_getset,          /*tp_getset*/
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
Outputs_new(SAM_Snowmodel data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Snowmodel", "Outputs")){
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
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Snowmodel_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_before_snow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Snowmodel_Outputs_annual_energy_before_snow_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hourly_energy_before_snow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_Outputs_hourly_energy_before_snow_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hourly_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_Outputs_hourly_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy_before_snow(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Snowmodel_Outputs_monthly_energy_before_snow_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kwh]"),
 	NULL},
{"annual_energy_before_snow", (getter)Outputs_get_annual_energy_before_snow,(setter)0,
	PyDoc_STR("*float*: Annual Energy Without Snow Losses [kwh]"),
 	NULL},
{"hourly_energy_before_snow", (getter)Outputs_get_hourly_energy_before_snow,(setter)0,
	PyDoc_STR("*sequence*: Hourly Energy Without Snow Loss [kwh]"),
 	NULL},
{"hourly_gen", (getter)Outputs_get_hourly_gen,(setter)0,
	PyDoc_STR("*sequence*: Hourly Energy [kwh]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy [kwh]"),
 	NULL},
{"monthly_energy_before_snow", (getter)Outputs_get_monthly_energy_before_snow,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy Without Snow Loss [kwh]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Snowmodel.Outputs",             /*tp_name*/
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
 * Snowmodel
 */

static PyTypeObject Snowmodel_Type;

static CmodObject *
newSnowmodelObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Snowmodel_Type);

	PySAM_TECH_ATTR()

	PyObject* PVSnowModel_obj = PVSnowModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVSnowModel", PVSnowModel_obj);
	Py_DECREF(PVSnowModel_obj);

	PyObject* TimeSeries_obj = TimeSeries_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeSeries", TimeSeries_obj);
	Py_DECREF(TimeSeries_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Snowmodel methods */

static void
Snowmodel_dealloc(CmodObject *self)
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
Snowmodel_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Snowmodel_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Snowmodel_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Snowmodel"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Snowmodel_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Snowmodel_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Snowmodel_methods[] = {
		{"execute",            (PyCFunction)Snowmodel_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Snowmodel_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'PV Snow Model': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Snowmodel_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Snowmodel_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Snowmodel_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Snowmodel_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Snowmodel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Snowmodel",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Snowmodel_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Snowmodel_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Snowmodel_getattro, /*tp_getattro*/
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
		Snowmodel_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Snowmodel object */

static PyObject *
Snowmodel_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newSnowmodelObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Snowmodel_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSnowmodelObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Snowmodel_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newSnowmodelObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Snowmodel", def);

	return (PyObject *)rv;
}

static PyObject *
Snowmodel_from_existing(PyObject *self, PyObject *args)
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

	rv = newSnowmodelObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Snowmodel", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef SnowmodelModule_methods[] = {
		{"new",             Snowmodel_new,         METH_VARARGS,
				PyDoc_STR("new() -> Snowmodel")},
		{"default",             Snowmodel_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Snowmodel\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Snowmodel_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Snowmodel\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Snowmodel_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Snowmodel\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Snowmodel");


static int
SnowmodelModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Snowmodel_Type.tp_dict = PyDict_New();
	if (!Snowmodel_Type.tp_dict) { goto fail; }

	/// Add the PVSnowModel type object to Snowmodel_Type
	if (PyType_Ready(&PVSnowModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Snowmodel_Type.tp_dict,
				"PVSnowModel",
				(PyObject*)&PVSnowModel_Type);
	Py_DECREF(&PVSnowModel_Type);

	/// Add the TimeSeries type object to Snowmodel_Type
	if (PyType_Ready(&TimeSeries_Type) < 0) { goto fail; }
	PyDict_SetItemString(Snowmodel_Type.tp_dict,
				"TimeSeries",
				(PyObject*)&TimeSeries_Type);
	Py_DECREF(&TimeSeries_Type);

	/// Add the Outputs type object to Snowmodel_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Snowmodel_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Snowmodel type object to the module
	if (PyType_Ready(&Snowmodel_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Snowmodel",
				(PyObject*)&Snowmodel_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot SnowmodelModule_slots[] = {
		{Py_mod_exec, SnowmodelModule_exec},
		{0, NULL},
};

static struct PyModuleDef SnowmodelModule = {
		PyModuleDef_HEAD_INIT,
		"Snowmodel",
		module_doc,
		0,
		SnowmodelModule_methods,
		SnowmodelModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Snowmodel(void)
{
	return PyModuleDef_Init(&SnowmodelModule);
}