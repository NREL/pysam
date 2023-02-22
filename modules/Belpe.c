#include <Python.h>

#include <SAM_Belpe.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * LoadProfileEstimator Group
 */ 

static PyTypeObject LoadProfileEstimator_Type;

static PyObject *
LoadProfileEstimator_new(SAM_Belpe data_ptr)
{
	PyObject* new_obj = LoadProfileEstimator_Type.tp_alloc(&LoadProfileEstimator_Type,0);

	VarGroupObject* LoadProfileEstimator_obj = (VarGroupObject*)new_obj;

	LoadProfileEstimator_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* LoadProfileEstimator methods */

static PyObject *
LoadProfileEstimator_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Belpe", "LoadProfileEstimator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LoadProfileEstimator_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &LoadProfileEstimator_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Belpe", "LoadProfileEstimator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LoadProfileEstimator_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &LoadProfileEstimator_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LoadProfileEstimator_methods[] = {
		{"assign",            (PyCFunction)LoadProfileEstimator_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``LoadProfileEstimator_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)LoadProfileEstimator_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``LoadProfileEstimator_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)LoadProfileEstimator_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LoadProfileEstimator_get_Monthly_util(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Belpe_LoadProfileEstimator_Monthly_util_aget, self->data_ptr);
}

static int
LoadProfileEstimator_set_Monthly_util(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Belpe_LoadProfileEstimator_Monthly_util_aset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_Occ_Schedule(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Belpe_LoadProfileEstimator_Occ_Schedule_aget, self->data_ptr);
}

static int
LoadProfileEstimator_set_Occ_Schedule(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Belpe_LoadProfileEstimator_Occ_Schedule_aset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_Occupants(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_Occupants_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_Occupants(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_Occupants_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_Retrofits(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_Retrofits_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_Retrofits(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_Retrofits_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_Stories(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_Stories_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_Stories(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_Stories_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_TCool(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_TCool_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_TCool(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_TCool_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_TCoolSB(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_TCoolSB_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_TCoolSB(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_TCoolSB_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_THeat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_THeat_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_THeat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_THeat_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_THeatSB(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_THeatSB_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_THeatSB(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_THeatSB_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_T_Sched(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Belpe_LoadProfileEstimator_T_Sched_aget, self->data_ptr);
}

static int
LoadProfileEstimator_set_T_Sched(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Belpe_LoadProfileEstimator_T_Sched_aset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_YrBuilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_YrBuilt_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_YrBuilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_YrBuilt_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_belpe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_belpe_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_belpe(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_belpe_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_cool(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_cool_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_cool(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_cool_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_dish(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_dish_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_dish(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_dish_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_dry(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_dry_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_dry(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_dry_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_fridge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_fridge_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_fridge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_fridge_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_heat_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_heat_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_mels(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_mels_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_mels(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_mels_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_range(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_range_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_range(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_range_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_en_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_en_wash_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_en_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_en_wash_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_floor_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Belpe_LoadProfileEstimator_floor_area_nget, self->data_ptr);
}

static int
LoadProfileEstimator_set_floor_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Belpe_LoadProfileEstimator_floor_area_nset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Belpe_LoadProfileEstimator_load_aget, self->data_ptr);
}

static int
LoadProfileEstimator_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Belpe_LoadProfileEstimator_load_aset, self->data_ptr);
}

static PyObject *
LoadProfileEstimator_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Belpe_LoadProfileEstimator_solar_resource_file_sget, self->data_ptr);
}

static int
LoadProfileEstimator_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Belpe_LoadProfileEstimator_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef LoadProfileEstimator_getset[] = {
{"Monthly_util", (getter)LoadProfileEstimator_get_Monthly_util,(setter)LoadProfileEstimator_set_Monthly_util,
	PyDoc_STR("*sequence*: Monthly consumption from utility bill [kWh]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"Occ_Schedule", (getter)LoadProfileEstimator_get_Occ_Schedule,(setter)LoadProfileEstimator_set_Occ_Schedule,
	PyDoc_STR("*sequence*: Hourly occupant schedule [frac/hr]\n\n**Constraints:**\nLENGTH=24\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"Occupants", (getter)LoadProfileEstimator_get_Occupants,(setter)LoadProfileEstimator_set_Occupants,
	PyDoc_STR("*float*: Occupants [#]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"Retrofits", (getter)LoadProfileEstimator_get_Retrofits,(setter)LoadProfileEstimator_set_Retrofits,
	PyDoc_STR("*float*: Energy retrofitted [0/1]\n\n**Options:**\n0=No, 1=Yes\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"Stories", (getter)LoadProfileEstimator_get_Stories,(setter)LoadProfileEstimator_set_Stories,
	PyDoc_STR("*float*: Number of stories [#]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"TCool", (getter)LoadProfileEstimator_get_TCool,(setter)LoadProfileEstimator_set_TCool,
	PyDoc_STR("*float*: Cooling setpoint [degF]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"TCoolSB", (getter)LoadProfileEstimator_get_TCoolSB,(setter)LoadProfileEstimator_set_TCoolSB,
	PyDoc_STR("*float*: Cooling setpoint setback [degF]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"THeat", (getter)LoadProfileEstimator_get_THeat,(setter)LoadProfileEstimator_set_THeat,
	PyDoc_STR("*float*: Heating setpoint [degF]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"THeatSB", (getter)LoadProfileEstimator_get_THeatSB,(setter)LoadProfileEstimator_set_THeatSB,
	PyDoc_STR("*float*: Heating setpoint setback [degf]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"T_Sched", (getter)LoadProfileEstimator_get_T_Sched,(setter)LoadProfileEstimator_set_T_Sched,
	PyDoc_STR("*sequence*: Temperature schedule [0/1]\n\n**Constraints:**\nLENGTH=24\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"YrBuilt", (getter)LoadProfileEstimator_get_YrBuilt,(setter)LoadProfileEstimator_set_YrBuilt,
	PyDoc_STR("*float*: Year built [yr]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_belpe", (getter)LoadProfileEstimator_get_en_belpe,(setter)LoadProfileEstimator_set_en_belpe,
	PyDoc_STR("*float*: Enable building load calculator [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nTrue"),
 	NULL},
{"en_cool", (getter)LoadProfileEstimator_get_en_cool,(setter)LoadProfileEstimator_set_en_cool,
	PyDoc_STR("*float*: Enable electric cool [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_dish", (getter)LoadProfileEstimator_get_en_dish,(setter)LoadProfileEstimator_set_en_dish,
	PyDoc_STR("*float*: Enable electric dishwasher [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_dry", (getter)LoadProfileEstimator_get_en_dry,(setter)LoadProfileEstimator_set_en_dry,
	PyDoc_STR("*float*: Enable electric dryer [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_fridge", (getter)LoadProfileEstimator_get_en_fridge,(setter)LoadProfileEstimator_set_en_fridge,
	PyDoc_STR("*float*: Enable electric fridge [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_heat", (getter)LoadProfileEstimator_get_en_heat,(setter)LoadProfileEstimator_set_en_heat,
	PyDoc_STR("*float*: Enable electric heat [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_mels", (getter)LoadProfileEstimator_get_en_mels,(setter)LoadProfileEstimator_set_en_mels,
	PyDoc_STR("*float*: Enable misc electric loads [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_range", (getter)LoadProfileEstimator_get_en_range,(setter)LoadProfileEstimator_set_en_range,
	PyDoc_STR("*float*: Enable electric range [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"en_wash", (getter)LoadProfileEstimator_get_en_wash,(setter)LoadProfileEstimator_set_en_wash,
	PyDoc_STR("*float*: Enable electric washer [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"floor_area", (getter)LoadProfileEstimator_get_floor_area,(setter)LoadProfileEstimator_set_floor_area,
	PyDoc_STR("*float*: Building floor area [m2]\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
{"load", (getter)LoadProfileEstimator_get_load,(setter)LoadProfileEstimator_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nRequired if en_belpe=0"),
 	NULL},
{"solar_resource_file", (getter)LoadProfileEstimator_get_solar_resource_file,(setter)LoadProfileEstimator_set_solar_resource_file,
	PyDoc_STR("*str*: Weather Data file [n/a]\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nRequired if en_belpe=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LoadProfileEstimator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Belpe.LoadProfileEstimator",             /*tp_name*/
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
		LoadProfileEstimator_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LoadProfileEstimator_getset,          /*tp_getset*/
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
 * Belpe
 */

static PyTypeObject Belpe_Type;

static CmodObject *
newBelpeObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Belpe_Type);

	PySAM_TECH_ATTR()

	PyObject* LoadProfileEstimator_obj = LoadProfileEstimator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LoadProfileEstimator", LoadProfileEstimator_obj);
	Py_DECREF(LoadProfileEstimator_obj);

	return self;
}

/* Belpe methods */

static void
Belpe_dealloc(CmodObject *self)
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
Belpe_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Belpe_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Belpe_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Belpe"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Belpe_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Belpe"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Belpe_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Belpe_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Belpe_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Belpe_methods[] = {
		{"execute",           (PyCFunction)Belpe_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Belpe_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Load Profile Estimator': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Belpe_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Load Profile Estimator': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Belpe_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Belpe_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Belpe_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Belpe_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Belpe_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Belpe_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Belpe",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Belpe_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Belpe_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Belpe_getattro, /*tp_getattro*/
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
		Belpe_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Belpe object */

static PyObject *
Belpe_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newBelpeObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Belpe_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBelpeObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Belpe_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBelpeObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Belpe", def) < 0) {
		Belpe_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Belpe_from_existing(PyObject *self, PyObject *args)
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

	rv = newBelpeObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Belpe", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BelpeModule_methods[] = {
		{"new",             Belpe_new,         METH_VARARGS,
				PyDoc_STR("new() -> Belpe")},
		{"default",             Belpe_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Belpe\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"FlatPlatePVResidential\"*\n\n		- *\"FlatPlatePVThirdParty\"*\n\n		- *\"GenericBatteryResidential\"*\n\n		- *\"GenericBatteryThirdParty\"*\n\n		- *\"PVBatteryResidential\"*\n\n		- *\"PVBatteryThirdParty\"*\n\n		- *\"PVWattsBatteryResidential\"*\n\n		- *\"PVWattsBatteryThirdParty\"*\n\n		- *\"PVWattsResidential\"*\n\n		- *\"PVWattsThirdParty\"*\n\n		- *\"SolarWaterHeatingResidential\"*\n\n		- *\"StandaloneBatteryResidential\"*\n\n		- *\"StandaloneBatteryThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Belpe_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Belpe\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Belpe_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Belpe\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Electric load calculator for residential buildings");


static int
BelpeModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Belpe_Type.tp_dict = PyDict_New();
	if (!Belpe_Type.tp_dict) { goto fail; }

	/// Add the LoadProfileEstimator type object to Belpe_Type
	if (PyType_Ready(&LoadProfileEstimator_Type) < 0) { goto fail; }
	PyDict_SetItemString(Belpe_Type.tp_dict,
				"LoadProfileEstimator",
				(PyObject*)&LoadProfileEstimator_Type);
	Py_DECREF(&LoadProfileEstimator_Type);

	/// Add the Belpe type object to the module
	if (PyType_Ready(&Belpe_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Belpe",
				(PyObject*)&Belpe_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot BelpeModule_slots[] = {
		{Py_mod_exec, BelpeModule_exec},
		{0, NULL},
};

static struct PyModuleDef BelpeModule = {
		PyModuleDef_HEAD_INIT,
		"Belpe",
		module_doc,
		0,
		BelpeModule_methods,
		BelpeModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Belpe(void)
{
	return PyModuleDef_Init(&BelpeModule);
}