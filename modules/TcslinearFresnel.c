#include <Python.h>

#include <SAM_TcslinearFresnel.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TcslinearFresnel data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "Weather")){
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
Weather_get_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Weather_azimuth_nget, self->data_ptr);
}

static int
Weather_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Weather_azimuth_nset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcslinearFresnel_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcslinearFresnel_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Weather_tilt_nget, self->data_ptr);
}

static int
Weather_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Weather_tilt_nset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Weather_track_mode_nget, self->data_ptr);
}

static int
Weather_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Weather_track_mode_nset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"azimuth", (getter)Weather_get_azimuth,(setter)Weather_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle of surface/axis\n\n**Required:**\nTrue\n\nThe value of ``azimuth`` depends on the following variables:\n\n\t - ColAz\n"),
 	NULL},
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: local weather file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)Weather_get_tilt,(setter)Weather_set_tilt,
	PyDoc_STR("*float*: Tilt angle of surface/axis\n\n**Required:**\nTrue"),
 	NULL},
{"track_mode", (getter)Weather_get_track_mode,(setter)Weather_set_track_mode,
	PyDoc_STR("*float*: Tracking mode\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Weather",             /*tp_name*/
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
 * LinearFresnelr Group
 */ 

static PyTypeObject LinearFresnelr_Type;

static PyObject *
LinearFresnelr_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = LinearFresnelr_Type.tp_alloc(&LinearFresnelr_Type,0);

	VarGroupObject* LinearFresnelr_obj = (VarGroupObject*)new_obj;

	LinearFresnelr_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* LinearFresnelr methods */

static PyObject *
LinearFresnelr_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "LinearFresnelr")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LinearFresnelr_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &LinearFresnelr_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "LinearFresnelr")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LinearFresnelr_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &LinearFresnelr_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LinearFresnelr_methods[] = {
		{"assign",            (PyCFunction)LinearFresnelr_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``LinearFresnelr_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)LinearFresnelr_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``LinearFresnelr_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)LinearFresnelr_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LinearFresnelr_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_LinearFresnelr_system_capacity_nget, self->data_ptr);
}

static int
LinearFresnelr_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_LinearFresnelr_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef LinearFresnelr_getset[] = {
{"system_capacity", (getter)LinearFresnelr_get_system_capacity,(setter)LinearFresnelr_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - demand_var\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LinearFresnelr_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.LinearFresnelr",             /*tp_name*/
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
		LinearFresnelr_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LinearFresnelr_getset,          /*tp_getset*/
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
 * TouTranslator Group
 */ 

static PyTypeObject TouTranslator_Type;

static PyObject *
TouTranslator_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = TouTranslator_Type.tp_alloc(&TouTranslator_Type,0);

	VarGroupObject* TouTranslator_obj = (VarGroupObject*)new_obj;

	TouTranslator_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TouTranslator methods */

static PyObject *
TouTranslator_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "TouTranslator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TouTranslator_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TouTranslator_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "TouTranslator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TouTranslator_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TouTranslator_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TouTranslator_methods[] = {
		{"assign",            (PyCFunction)TouTranslator_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TouTranslator_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TouTranslator_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TouTranslator_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TouTranslator_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TouTranslator_get_weekday_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_TouTranslator_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef TouTranslator_getset[] = {
{"weekday_schedule", (getter)TouTranslator_get_weekday_schedule,(setter)TouTranslator_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 Time of Use Values for week days\n\n**Required:**\nTrue"),
 	NULL},
{"weekend_schedule", (getter)TouTranslator_get_weekend_schedule,(setter)TouTranslator_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 Time of Use Values for week end days\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TouTranslator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.TouTranslator",             /*tp_name*/
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
		TouTranslator_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TouTranslator_getset,          /*tp_getset*/
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
 * Solarfield Group
 */ 

static PyTypeObject Solarfield_Type;

static PyObject *
Solarfield_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = Solarfield_Type.tp_alloc(&Solarfield_Type,0);

	VarGroupObject* Solarfield_obj = (VarGroupObject*)new_obj;

	Solarfield_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Solarfield methods */

static PyObject *
Solarfield_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Solarfield")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Solarfield_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Solarfield_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "Solarfield")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Solarfield_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Solarfield_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Solarfield_methods[] = {
		{"assign",            (PyCFunction)Solarfield_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Solarfield_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Solarfield_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Solarfield_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Solarfield_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Solarfield_get_A_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_A_aperture_mget, self->data_ptr);
}

static int
Solarfield_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_A_aperture_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_AbsorberMaterial_mget, self->data_ptr);
}

static int
Solarfield_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_AnnulusGas_mget, self->data_ptr);
}

static int
Solarfield_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_ColAz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_ColAz_nget, self->data_ptr);
}

static int
Solarfield_set_ColAz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_ColAz_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_2_mget, self->data_ptr);
}

static int
Solarfield_set_D_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_3_mget, self->data_ptr);
}

static int
Solarfield_set_D_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_4_mget, self->data_ptr);
}

static int
Solarfield_set_D_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_5_mget, self->data_ptr);
}

static int
Solarfield_set_D_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_5_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_p(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_p_mget, self->data_ptr);
}

static int
Solarfield_set_D_p(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_p_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Design_loss_mget, self->data_ptr);
}

static int
Solarfield_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Design_loss_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Dirt_HCE(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Dirt_HCE_mget, self->data_ptr);
}

static int
Solarfield_set_Dirt_HCE(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_EPSILON_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_EPSILON_4_mget, self->data_ptr);
}

static int
Solarfield_set_EPSILON_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Flow_type_mget, self->data_ptr);
}

static int
Solarfield_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Flow_type_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_GeomEffects_mget, self->data_ptr);
}

static int
Solarfield_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_GeomEffects_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_GlazingIntactIn_mget, self->data_ptr);
}

static int
Solarfield_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HCE_FieldFrac_mget, self->data_ptr);
}

static int
Solarfield_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HLCharType(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HLCharType_mget, self->data_ptr);
}

static int
Solarfield_set_HLCharType(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HLCharType_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HL_W(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HL_W_mget, self->data_ptr);
}

static int
Solarfield_set_HL_W(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HL_W_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HL_dT(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HL_dT_mget, self->data_ptr);
}

static int
Solarfield_set_HL_dT(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HL_dT_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_IAM_L(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_IAM_L_mget, self->data_ptr);
}

static int
Solarfield_set_IAM_L(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_IAM_L_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_IAM_T(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_IAM_T_mget, self->data_ptr);
}

static int
Solarfield_set_IAM_T(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_IAM_T_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_I_bn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_I_bn_nget, self->data_ptr);
}

static int
Solarfield_set_I_bn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_I_bn_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_I_bn_des_nget, self->data_ptr);
}

static int
Solarfield_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_I_bn_des_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_LHV_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_LHV_eff_nget, self->data_ptr);
}

static int
Solarfield_set_LHV_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_LHV_eff_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_L_col(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_L_col_mget, self->data_ptr);
}

static int
Solarfield_set_L_col(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_L_col_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_OptCharType(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_OptCharType_mget, self->data_ptr);
}

static int
Solarfield_set_OptCharType(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_OptCharType_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_PB_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_PB_fixed_par_nget, self->data_ptr);
}

static int
Solarfield_set_PB_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_PB_fixed_par_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_PB_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_PB_pump_coef_nget, self->data_ptr);
}

static int
Solarfield_set_PB_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_PB_pump_coef_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_P_a_mget, self->data_ptr);
}

static int
Solarfield_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_P_a_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_amb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_P_amb_nget, self->data_ptr);
}

static int
Solarfield_set_P_amb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_P_amb_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_turb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_P_turb_des_nget, self->data_ptr);
}

static int
Solarfield_set_P_turb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_P_turb_des_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_Pipe_hl_coef_nget, self->data_ptr);
}

static int
Solarfield_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Rough_mget, self->data_ptr);
}

static int
Solarfield_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Rough_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_SCA_drives_elec_nget, self->data_ptr);
}

static int
Solarfield_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Shadowing_mget, self->data_ptr);
}

static int
Solarfield_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Shadowing_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_SolarAz_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_SolarAz_init_nget, self->data_ptr);
}

static int
Solarfield_set_SolarAz_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_SolarAz_init_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_SolarZen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_SolarZen_nget, self->data_ptr);
}

static int
Solarfield_set_SolarZen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_SolarZen_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_amb_des_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_T_amb_des_sf_nget, self->data_ptr);
}

static int
Solarfield_set_T_amb_des_sf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_T_amb_des_sf_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_db(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_T_db_nget, self->data_ptr);
}

static int
Solarfield_set_T_db(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_T_db_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_dp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_T_dp_nget, self->data_ptr);
}

static int
Solarfield_set_T_dp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_T_dp_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_T_fp_nget, self->data_ptr);
}

static int
Solarfield_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_T_fp_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_pb_out_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_T_pb_out_init_nget, self->data_ptr);
}

static int
Solarfield_set_T_pb_out_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_T_pb_out_init_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Tau_envelope_mget, self->data_ptr);
}

static int
Solarfield_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_TrackingError_mget, self->data_ptr);
}

static int
Solarfield_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_TrackingError_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_V_wind(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_V_wind_nget, self->data_ptr);
}

static int
Solarfield_set_V_wind(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_V_wind_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_V_wind_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_V_wind_max_nget, self->data_ptr);
}

static int
Solarfield_set_V_wind_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_V_wind_max_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_alpha_abs_mget, self->data_ptr);
}

static int
Solarfield_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_alpha_abs_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_alpha_env_mget, self->data_ptr);
}

static int
Solarfield_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_alpha_env_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_aux_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Solarfield_aux_array_aget, self->data_ptr);
}

static int
Solarfield_set_aux_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcslinearFresnel_Solarfield_aux_array_aset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_OpticalTable_mget, self->data_ptr);
}

static int
Solarfield_set_b_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE1(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE1_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE1(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE1_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE2_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE3_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE4_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_bop_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Solarfield_bop_array_aget, self->data_ptr);
}

static int
Solarfield_set_bop_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcslinearFresnel_Solarfield_bop_array_aset, self->data_ptr);
}

static PyObject *
Solarfield_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
Solarfield_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_cycle_max_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_cycle_max_fraction_nget, self->data_ptr);
}

static int
Solarfield_set_cycle_max_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_cycle_max_fraction_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_dirt_mirror_mget, self->data_ptr);
}

static int
Solarfield_set_dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_dirt_mirror_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_dnifc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_dnifc_nget, self->data_ptr);
}

static int
Solarfield_set_dnifc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_dnifc_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_e_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_e_startup_nget, self->data_ptr);
}

static int
Solarfield_set_e_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_e_startup_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_error(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_error_mget, self->data_ptr);
}

static int
Solarfield_set_error(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_error_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_eta_pump_nget, self->data_ptr);
}

static int
Solarfield_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_eta_pump_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_boil_to_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_fP_boil_to_sh_nget, self->data_ptr);
}

static int
Solarfield_set_fP_boil_to_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_fP_boil_to_sh_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_hdr_c(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_fP_hdr_c_nget, self->data_ptr);
}

static int
Solarfield_set_fP_hdr_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_fP_hdr_c_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_hdr_h(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_fP_hdr_h_nget, self->data_ptr);
}

static int
Solarfield_set_fP_hdr_h(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_fP_hdr_h_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_sf_boil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_fP_sf_boil_nget, self->data_ptr);
}

static int
Solarfield_set_fP_sf_boil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_fP_sf_boil_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_sf_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_fP_sf_sh_nget, self->data_ptr);
}

static int
Solarfield_set_fP_sf_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_fP_sf_sh_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_ffrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Solarfield_ffrac_aget, self->data_ptr);
}

static int
Solarfield_set_ffrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcslinearFresnel_Solarfield_ffrac_aset, self->data_ptr);
}

static PyObject *
Solarfield_get_fossil_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_fossil_mode_nget, self->data_ptr);
}

static int
Solarfield_set_fossil_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_fossil_mode_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_is_multgeom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_is_multgeom_nget, self->data_ptr);
}

static int
Solarfield_set_is_multgeom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_is_multgeom_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_is_oncethru(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_is_oncethru_nget, self->data_ptr);
}

static int
Solarfield_set_is_oncethru(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_is_oncethru_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_is_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_is_sh_nget, self->data_ptr);
}

static int
Solarfield_set_is_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_is_sh_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_latitude(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_latitude_nget, self->data_ptr);
}

static int
Solarfield_set_latitude(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_latitude_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_m_dot_htf_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_m_dot_htf_ref_nget, self->data_ptr);
}

static int
Solarfield_set_m_dot_htf_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_m_dot_htf_ref_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_m_dot_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_m_dot_min_nget, self->data_ptr);
}

static int
Solarfield_set_m_dot_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_m_dot_min_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_m_pb_demand(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_m_pb_demand_nget, self->data_ptr);
}

static int
Solarfield_set_m_pb_demand(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_m_pb_demand_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_nLoops_nget, self->data_ptr);
}

static int
Solarfield_set_nLoops(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_nLoops_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_nModBoil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_nModBoil_nget, self->data_ptr);
}

static int
Solarfield_set_nModBoil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_nModBoil_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_nModSH(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_nModSH_nget, self->data_ptr);
}

static int
Solarfield_set_nModSH(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_nModSH_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_max_aux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_q_max_aux_nget, self->data_ptr);
}

static int
Solarfield_set_q_max_aux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_q_max_aux_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_pb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_q_pb_des_nget, self->data_ptr);
}

static int
Solarfield_set_q_pb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_q_pb_des_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_q_sby_frac_nget, self->data_ptr);
}

static int
Solarfield_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_rho_mirror_clean(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_rho_mirror_clean_mget, self->data_ptr);
}

static int
Solarfield_set_rho_mirror_clean(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_rho_mirror_clean_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_OpticalTable_mget, self->data_ptr);
}

static int
Solarfield_set_sh_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE1(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE1_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE1(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE1_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE2_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE3_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE4_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_shift(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_shift_nget, self->data_ptr);
}

static int
Solarfield_set_shift(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_shift_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_solarm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_solarm_nget, self->data_ptr);
}

static int
Solarfield_set_solarm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_solarm_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_t_sby(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_t_sby_nget, self->data_ptr);
}

static int
Solarfield_set_t_sby(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_t_sby_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_tes_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_tes_hours_nget, self->data_ptr);
}

static int
Solarfield_set_tes_hours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_tes_hours_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_theta_dep_nget, self->data_ptr);
}

static int
Solarfield_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_theta_dep_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_theta_stow_nget, self->data_ptr);
}

static int
Solarfield_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_theta_stow_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_x_b_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Solarfield_x_b_des_nget, self->data_ptr);
}

static int
Solarfield_set_x_b_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Solarfield_x_b_des_nset, self->data_ptr);
}

static PyGetSetDef Solarfield_getset[] = {
{"A_aperture", (getter)Solarfield_get_A_aperture,(setter)Solarfield_set_A_aperture,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Reflective aperture area of the collector module [m^2]\n\n**Required:**\nTrue"),
 	NULL},
{"AbsorberMaterial", (getter)Solarfield_get_AbsorberMaterial,(setter)Solarfield_set_AbsorberMaterial,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Absorber material type [none]\n\n**Required:**\nTrue"),
 	NULL},
{"AnnulusGas", (getter)Solarfield_get_AnnulusGas,(setter)Solarfield_set_AnnulusGas,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Annulus gas type {1=air; 26=Ar; 27=H2} (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"ColAz", (getter)Solarfield_get_ColAz,(setter)Solarfield_set_ColAz,
	PyDoc_STR("*float*: Collector azimuth angle [deg]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``ColAz``:\n\n\t - azimuth\n"),
 	NULL},
{"D_2", (getter)Solarfield_get_D_2,(setter)Solarfield_set_D_2,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The inner absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_3", (getter)Solarfield_get_D_3,(setter)Solarfield_set_D_3,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The outer absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_4", (getter)Solarfield_get_D_4,(setter)Solarfield_set_D_4,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The inner glass envelope diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_5", (getter)Solarfield_get_D_5,(setter)Solarfield_set_D_5,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The outer glass envelope diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_p", (getter)Solarfield_get_D_p,(setter)Solarfield_set_D_p,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The diameter of the absorber flow plug (optional) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Design_loss", (getter)Solarfield_get_Design_loss,(setter)Solarfield_set_Design_loss,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Receiver heat loss at design (4: # field fracs) [W/m]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_HCE", (getter)Solarfield_get_Dirt_HCE,(setter)Solarfield_set_Dirt_HCE,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Loss due to dirt on the receiver envelope (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"EPSILON_4", (getter)Solarfield_get_EPSILON_4,(setter)Solarfield_set_EPSILON_4,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Inner glass envelope emissivities (Pyrex) (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Flow_type", (getter)Solarfield_get_Flow_type,(setter)Solarfield_set_Flow_type,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The flow type through the absorber [none]\n\n**Required:**\nTrue"),
 	NULL},
{"GeomEffects", (getter)Solarfield_get_GeomEffects,(setter)Solarfield_set_GeomEffects,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined geometry effects derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"GlazingIntactIn", (getter)Solarfield_get_GlazingIntactIn,(setter)Solarfield_set_GlazingIntactIn,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The glazing intact flag {true=0; false=1} (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HCE_FieldFrac", (getter)Solarfield_get_HCE_FieldFrac,(setter)Solarfield_set_HCE_FieldFrac,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The fraction of the field occupied by this HCE type (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HLCharType", (getter)Solarfield_get_HLCharType,(setter)Solarfield_set_HLCharType,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Flag indicating the heat loss model type {1=poly.; 2=Forristall} [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HL_W", (getter)Solarfield_get_HL_W,(setter)Solarfield_set_HL_W,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Heat loss coef adj wind velocity (0,1,2,3,4 order terms) [1/(m/s)^order]\n\n**Required:**\nTrue"),
 	NULL},
{"HL_dT", (getter)Solarfield_get_HL_dT,(setter)Solarfield_set_HL_dT,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Heat loss coefficient - HTF temperature (0,1,2,3,4 order terms) [W/m-K^order]\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_L", (getter)Solarfield_get_IAM_L,(setter)Solarfield_set_IAM_L,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Longitudinal Incident angle modifiers (0,1,2,3,4 order terms) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_T", (getter)Solarfield_get_IAM_T,(setter)Solarfield_set_IAM_T,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Transverse Incident angle modifiers (0,1,2,3,4 order terms) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"I_bn", (getter)Solarfield_get_I_bn,(setter)Solarfield_set_I_bn,
	PyDoc_STR("*float*: Beam normal radiation (input kJ/m2-hr) [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"I_bn_des", (getter)Solarfield_get_I_bn_des,(setter)Solarfield_set_I_bn_des,
	PyDoc_STR("*float*: Design point irradiation value [W/m2]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``I_bn_des``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"LHV_eff", (getter)Solarfield_get_LHV_eff,(setter)Solarfield_set_LHV_eff,
	PyDoc_STR("*float*: Fuel LHV efficiency (0..1) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"L_col", (getter)Solarfield_get_L_col,(setter)Solarfield_set_L_col,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Active length of the superheater section collector module [m]\n\n**Required:**\nTrue"),
 	NULL},
{"OptCharType", (getter)Solarfield_get_OptCharType,(setter)Solarfield_set_OptCharType,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The optical characterization method [none]\n\n**Required:**\nTrue"),
 	NULL},
{"PB_fixed_par", (getter)Solarfield_get_PB_fixed_par,(setter)Solarfield_set_PB_fixed_par,
	PyDoc_STR("*float*: fraction of rated gross power consumed at all hours of the year [none]\n\n**Required:**\nTrue"),
 	NULL},
{"PB_pump_coef", (getter)Solarfield_get_PB_pump_coef,(setter)Solarfield_set_PB_pump_coef,
	PyDoc_STR("*float*: Pumping power required to move 1kg of HTF through power block flow [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)Solarfield_get_P_a,(setter)Solarfield_set_P_a,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Annulus gas pressure (4: # field fracs) [torr]\n\n**Required:**\nTrue"),
 	NULL},
{"P_amb", (getter)Solarfield_get_P_amb,(setter)Solarfield_set_P_amb,
	PyDoc_STR("*float*: Ambient pressure [atm]\n\n**Required:**\nTrue"),
 	NULL},
{"P_turb_des", (getter)Solarfield_get_P_turb_des,(setter)Solarfield_set_P_turb_des,
	PyDoc_STR("*float*: Design-point turbine inlet pressure [bar]\n\n**Required:**\nTrue\n\nThe value of ``P_turb_des`` depends on the following variables:\n\n\t - P_boil_des\n"),
 	NULL},
{"Pipe_hl_coef", (getter)Solarfield_get_Pipe_hl_coef,(setter)Solarfield_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header.. runner pipe.. and non-HCE pipin [W/m2-K]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``Pipe_hl_coef``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"Rough", (getter)Solarfield_get_Rough,(setter)Solarfield_set_Rough,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Roughness of the internal surface [m]\n\n**Required:**\nTrue"),
 	NULL},
{"SCA_drives_elec", (getter)Solarfield_get_SCA_drives_elec,(setter)Solarfield_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power.. in Watts per SCA drive [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"Shadowing", (getter)Solarfield_get_Shadowing,(setter)Solarfield_set_Shadowing,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Receiver bellows shadowing loss factor (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"SolarAz_init", (getter)Solarfield_get_SolarAz_init,(setter)Solarfield_set_SolarAz_init,
	PyDoc_STR("*float*: Solar azimuth angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"SolarZen", (getter)Solarfield_get_SolarZen,(setter)Solarfield_set_SolarZen,
	PyDoc_STR("*float*: Solar zenith angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"T_amb_des_sf", (getter)Solarfield_get_T_amb_des_sf,(setter)Solarfield_set_T_amb_des_sf,
	PyDoc_STR("*float*: Design-point ambient temperature [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_amb_des_sf``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"T_db", (getter)Solarfield_get_T_db,(setter)Solarfield_set_T_db,
	PyDoc_STR("*float*: Dry bulb air temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_dp", (getter)Solarfield_get_T_dp,(setter)Solarfield_set_T_dp,
	PyDoc_STR("*float*: The dewpoint temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_fp", (getter)Solarfield_get_T_fp,(setter)Solarfield_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_pb_out_init", (getter)Solarfield_get_T_pb_out_init,(setter)Solarfield_set_T_pb_out_init,
	PyDoc_STR("*float*: Fluid temperature from the power block [C]\n\n**Required:**\nTrue"),
 	NULL},
{"Tau_envelope", (getter)Solarfield_get_Tau_envelope,(setter)Solarfield_set_Tau_envelope,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Envelope transmittance (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)Solarfield_get_TrackingError,(setter)Solarfield_set_TrackingError,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined tracking error derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"V_wind", (getter)Solarfield_get_V_wind,(setter)Solarfield_set_V_wind,
	PyDoc_STR("*float*: Ambient windspeed [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_wind_max", (getter)Solarfield_get_V_wind_max,(setter)Solarfield_set_V_wind_max,
	PyDoc_STR("*float*: Maximum allowable wind velocity before safety stow [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_abs", (getter)Solarfield_get_alpha_abs,(setter)Solarfield_set_alpha_abs,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Absorber absorptance (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_env", (getter)Solarfield_get_alpha_env,(setter)Solarfield_set_alpha_env,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Envelope absorptance (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"aux_array", (getter)Solarfield_get_aux_array,(setter)Solarfield_set_aux_array,
	PyDoc_STR("*sequence*: Aux_parVal, Aux_parPF, Aux_par0, Aux_par1, Aux_par2 [-]\n\n**Required:**\nTrue"),
 	NULL},
{"b_OpticalTable", (getter)Solarfield_get_b_OpticalTable,(setter)Solarfield_set_b_OpticalTable,
	PyDoc_STR("*sequence[sequence]*: Values of the optical efficiency table [none]\n\n**Required:**\nTrue"),
 	NULL},
{"b_eps_HCE1", (getter)Solarfield_get_b_eps_HCE1,(setter)Solarfield_set_b_eps_HCE1,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"b_eps_HCE2", (getter)Solarfield_get_b_eps_HCE2,(setter)Solarfield_set_b_eps_HCE2,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"b_eps_HCE3", (getter)Solarfield_get_b_eps_HCE3,(setter)Solarfield_set_b_eps_HCE3,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"b_eps_HCE4", (getter)Solarfield_get_b_eps_HCE4,(setter)Solarfield_set_b_eps_HCE4,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"bop_array", (getter)Solarfield_get_bop_array,(setter)Solarfield_set_bop_array,
	PyDoc_STR("*sequence*: BOP_parVal, BOP_parPF, BOP_par0, BOP_par1, BOP_par2 [-]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_cutoff_frac", (getter)Solarfield_get_cycle_cutoff_frac,(setter)Solarfield_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown [none]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_max_fraction", (getter)Solarfield_get_cycle_max_fraction,(setter)Solarfield_set_cycle_max_fraction,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"dirt_mirror", (getter)Solarfield_get_dirt_mirror,(setter)Solarfield_set_dirt_mirror,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined dirt on mirror derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"dnifc", (getter)Solarfield_get_dnifc,(setter)Solarfield_set_dnifc,
	PyDoc_STR("*float*: Forecast DNI [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"e_startup", (getter)Solarfield_get_e_startup,(setter)Solarfield_set_e_startup,
	PyDoc_STR("*float*: Thermal inertia contribution per sq meter of solar field [kJ/K-m2]\n\n**Required:**\nTrue"),
 	NULL},
{"error", (getter)Solarfield_get_error,(setter)Solarfield_set_error,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined general optical error derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)Solarfield_get_eta_pump,(setter)Solarfield_set_eta_pump,
	PyDoc_STR("*float*: Feedwater pump efficiency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_boil_to_sh", (getter)Solarfield_get_fP_boil_to_sh,(setter)Solarfield_set_fP_boil_to_sh,
	PyDoc_STR("*float*: Design-point pressure drop between the boiler and superheater frac [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_hdr_c", (getter)Solarfield_get_fP_hdr_c,(setter)Solarfield_set_fP_hdr_c,
	PyDoc_STR("*float*: Average design-point cold header pressure drop fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_hdr_h", (getter)Solarfield_get_fP_hdr_h,(setter)Solarfield_set_fP_hdr_h,
	PyDoc_STR("*float*: Average design-point hot header pressure drop fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_sf_boil", (getter)Solarfield_get_fP_sf_boil,(setter)Solarfield_set_fP_sf_boil,
	PyDoc_STR("*float*: Design-point pressure drop across the solar field boiler fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_sf_sh", (getter)Solarfield_get_fP_sf_sh,(setter)Solarfield_set_fP_sf_sh,
	PyDoc_STR("*float*: Design-point pressure drop across the solar field superheater frac [none]\n\n**Required:**\nTrue"),
 	NULL},
{"ffrac", (getter)Solarfield_get_ffrac,(setter)Solarfield_set_ffrac,
	PyDoc_STR("*sequence*: Fossil dispatch logic - TOU periods [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fossil_mode", (getter)Solarfield_get_fossil_mode,(setter)Solarfield_set_fossil_mode,
	PyDoc_STR("*float*: Operation mode for the fossil backup {1=Normal,2=supp,3=toppin} [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"is_multgeom", (getter)Solarfield_get_is_multgeom,(setter)Solarfield_set_is_multgeom,
	PyDoc_STR("*float*: Does the superheater have a different geometry from the boiler {1=yes} [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"is_oncethru", (getter)Solarfield_get_is_oncethru,(setter)Solarfield_set_is_oncethru,
	PyDoc_STR("*float*: Flag indicating whether flow is once through with superheat [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"is_sh", (getter)Solarfield_get_is_sh,(setter)Solarfield_set_is_sh,
	PyDoc_STR("*float*: Does the solar field include a superheating section [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"latitude", (getter)Solarfield_get_latitude,(setter)Solarfield_set_latitude,
	PyDoc_STR("*float*: Site latitude resource page [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htf_ref", (getter)Solarfield_get_m_dot_htf_ref,(setter)Solarfield_set_m_dot_htf_ref,
	PyDoc_STR("*float*: Reference HTF flow rate at design conditions [kg/hr]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_min", (getter)Solarfield_get_m_dot_min,(setter)Solarfield_set_m_dot_min,
	PyDoc_STR("*float*: Minimum loop flow rate [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"m_pb_demand", (getter)Solarfield_get_m_pb_demand,(setter)Solarfield_set_m_pb_demand,
	PyDoc_STR("*float*: Demand htf flow from the power block [kg/hr]\n\n**Required:**\nTrue"),
 	NULL},
{"nLoops", (getter)Solarfield_get_nLoops,(setter)Solarfield_set_nLoops,
	PyDoc_STR("*float*: Number of loops [none]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nLoops``:\n\n\t - q_max_aux\n\t - solarm\n\n\nThe value of ``nLoops`` depends on the following variables:\n\n\t - I_bn_des\n\t - Pipe_hl_coef\n\t - T_amb_des_sf\n\t - T_cold_ref\n\t - T_hot\n\t - demand_var\n\t - eta_ref\n\t - nModBoil\n\t - nModSH\n"),
 	NULL},
{"nModBoil", (getter)Solarfield_get_nModBoil,(setter)Solarfield_set_nModBoil,
	PyDoc_STR("*float*: Number of modules in the boiler section [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nModBoil``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"nModSH", (getter)Solarfield_get_nModSH,(setter)Solarfield_set_nModSH,
	PyDoc_STR("*float*: Number of modules in the superheater section [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nModSH``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"q_max_aux", (getter)Solarfield_get_q_max_aux,(setter)Solarfield_set_q_max_aux,
	PyDoc_STR("*float*: Maximum heat rate of the auxiliary heater [MW]\n\n**Required:**\nTrue\n\nThe value of ``q_max_aux`` depends on the following variables:\n\n\t - I_bn_des\n\t - Pipe_hl_coef\n\t - T_amb_des_sf\n\t - T_cold_ref\n\t - T_hot\n\t - demand_var\n\t - eta_ref\n\t - nLoops\n\t - nModBoil\n\t - nModSH\n"),
 	NULL},
{"q_pb_des", (getter)Solarfield_get_q_pb_des,(setter)Solarfield_set_q_pb_des,
	PyDoc_STR("*float*: Design heat input to the power block [MW]\n\n**Required:**\nTrue\n\nThe value of ``q_pb_des`` depends on the following variables:\n\n\t - demand_var\n\t - eta_ref\n"),
 	NULL},
{"q_sby_frac", (getter)Solarfield_get_q_sby_frac,(setter)Solarfield_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby [none]\n\n**Required:**\nTrue"),
 	NULL},
{"rho_mirror_clean", (getter)Solarfield_get_rho_mirror_clean,(setter)Solarfield_set_rho_mirror_clean,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined clean mirror reflectivity [none]\n\n**Required:**\nTrue"),
 	NULL},
{"sh_OpticalTable", (getter)Solarfield_get_sh_OpticalTable,(setter)Solarfield_set_sh_OpticalTable,
	PyDoc_STR("*sequence[sequence]*: Values of the optical efficiency table [none]\n\n**Required:**\nTrue"),
 	NULL},
{"sh_eps_HCE1", (getter)Solarfield_get_sh_eps_HCE1,(setter)Solarfield_set_sh_eps_HCE1,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"sh_eps_HCE2", (getter)Solarfield_get_sh_eps_HCE2,(setter)Solarfield_set_sh_eps_HCE2,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"sh_eps_HCE3", (getter)Solarfield_get_sh_eps_HCE3,(setter)Solarfield_set_sh_eps_HCE3,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"sh_eps_HCE4", (getter)Solarfield_get_sh_eps_HCE4,(setter)Solarfield_set_sh_eps_HCE4,
	PyDoc_STR("*sequence[sequence]*: (temperature) Absorber emittance (eps) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"shift", (getter)Solarfield_get_shift,(setter)Solarfield_set_shift,
	PyDoc_STR("*float*: Shift in longitude from local standard meridian [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"solarm", (getter)Solarfield_get_solarm,(setter)Solarfield_set_solarm,
	PyDoc_STR("*float*: Solar multiple [none]\n\n**Required:**\nTrue\n\nThe value of ``solarm`` depends on the following variables:\n\n\t - I_bn_des\n\t - Pipe_hl_coef\n\t - T_amb_des_sf\n\t - T_cold_ref\n\t - T_hot\n\t - demand_var\n\t - eta_ref\n\t - nLoops\n\t - nModBoil\n\t - nModSH\n"),
 	NULL},
{"t_sby", (getter)Solarfield_get_t_sby,(setter)Solarfield_set_t_sby,
	PyDoc_STR("*float*: Low resource standby period [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_hours", (getter)Solarfield_get_tes_hours,(setter)Solarfield_set_tes_hours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)Solarfield_get_theta_dep,(setter)Solarfield_set_theta_dep,
	PyDoc_STR("*float*: deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)Solarfield_get_theta_stow,(setter)Solarfield_set_theta_stow,
	PyDoc_STR("*float*: stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"x_b_des", (getter)Solarfield_get_x_b_des,(setter)Solarfield_set_x_b_des,
	PyDoc_STR("*float*: Design point boiler outlet steam quality [none]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Solarfield_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Solarfield",             /*tp_name*/
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
		Solarfield_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Solarfield_getset,          /*tp_getset*/
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
 * Heliostat Group
 */ 

static PyTypeObject Heliostat_Type;

static PyObject *
Heliostat_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = Heliostat_Type.tp_alloc(&Heliostat_Type,0);

	VarGroupObject* Heliostat_obj = (VarGroupObject*)new_obj;

	Heliostat_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Heliostat methods */

static PyObject *
Heliostat_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Heliostat")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Heliostat_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Heliostat_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "Heliostat")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Heliostat_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Heliostat_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Heliostat_methods[] = {
		{"assign",            (PyCFunction)Heliostat_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Heliostat_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Heliostat_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Heliostat_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Heliostat_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Heliostat_get_csp_lf_sf_washes_per_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Heliostat_csp_lf_sf_washes_per_year_nget, self->data_ptr);
}

static int
Heliostat_set_csp_lf_sf_washes_per_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Heliostat_csp_lf_sf_washes_per_year_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_lf_sf_water_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Heliostat_csp_lf_sf_water_per_wash_nget, self->data_ptr);
}

static int
Heliostat_set_csp_lf_sf_water_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Heliostat_csp_lf_sf_water_per_wash_nset, self->data_ptr);
}

static PyGetSetDef Heliostat_getset[] = {
{"csp_lf_sf_washes_per_year", (getter)Heliostat_get_csp_lf_sf_washes_per_year,(setter)Heliostat_set_csp_lf_sf_washes_per_year,
	PyDoc_STR("*float*: Mirror washing frequency\n\n**Required:**\nTrue"),
 	NULL},
{"csp_lf_sf_water_per_wash", (getter)Heliostat_get_csp_lf_sf_water_per_wash,(setter)Heliostat_set_csp_lf_sf_water_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Heliostat_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Heliostat",             /*tp_name*/
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
		Heliostat_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Heliostat_getset,          /*tp_getset*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = Powerblock_Type.tp_alloc(&Powerblock_Type,0);

	VarGroupObject* Powerblock_obj = (VarGroupObject*)new_obj;

	Powerblock_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Powerblock methods */

static PyObject *
Powerblock_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Powerblock_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Powerblock_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Powerblock_methods[] = {
		{"assign",            (PyCFunction)Powerblock_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Powerblock_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Powerblock_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Powerblock_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Powerblock_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Powerblock_get_CT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_CT_nget, self->data_ptr);
}

static int
Powerblock_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_CT_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcslinearFresnel_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_amb_pwb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_P_amb_pwb_nget, self->data_ptr);
}

static int
Powerblock_set_P_amb_pwb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_P_amb_pwb_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_boil_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_P_boil_des_nget, self->data_ptr);
}

static int
Powerblock_set_P_boil_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_P_boil_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_rh_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_P_rh_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_rh_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_P_rh_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_approach_nget, self->data_ptr);
}

static int
Powerblock_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_approach_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_cold_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_cold_ref_nget, self->data_ptr);
}

static int
Powerblock_set_T_cold_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_cold_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_db_pwb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_db_pwb_nget, self->data_ptr);
}

static int
Powerblock_set_T_db_pwb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_db_pwb_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_hot_nget, self->data_ptr);
}

static int
Powerblock_set_T_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_hot_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_wb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_T_wb_nget, self->data_ptr);
}

static int
Powerblock_set_T_wb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_T_wb_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_demand_var(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_demand_var_nget, self->data_ptr);
}

static int
Powerblock_set_demand_var(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_demand_var_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dp_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_dp_b_nget, self->data_ptr);
}

static int
Powerblock_set_dp_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_dp_b_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dp_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_dp_rh_nget, self->data_ptr);
}

static int
Powerblock_set_dp_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_dp_rh_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dp_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_dp_sh_nget, self->data_ptr);
}

static int
Powerblock_set_dp_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_dp_sh_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_f_recSU(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_f_recSU_nget, self->data_ptr);
}

static int
Powerblock_set_f_recSU(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_f_recSU_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_m_dot_st(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_m_dot_st_nget, self->data_ptr);
}

static int
Powerblock_set_m_dot_st(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_m_dot_st_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_pc_mode_nget, self->data_ptr);
}

static int
Powerblock_set_pc_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_pc_mode_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_relhum(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_relhum_nget, self->data_ptr);
}

static int
Powerblock_set_relhum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_relhum_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_rh_frac_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_rh_frac_ref_nget, self->data_ptr);
}

static int
Powerblock_set_rh_frac_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_rh_frac_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_standby_control(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_standby_control_nget, self->data_ptr);
}

static int
Powerblock_set_standby_control(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_standby_control_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcslinearFresnel_Powerblock_startup_time_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"CT", (getter)Powerblock_get_CT,(setter)Powerblock_set_CT,
	PyDoc_STR("*float*: Flag for using dry cooling or wet cooling system [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	PyDoc_STR("*sequence*: Fraction indicating wet cooling use for hybrid system [none]\n\n**Required:**\nTrue"),
 	NULL},
{"P_amb_pwb", (getter)Powerblock_get_P_amb_pwb,(setter)Powerblock_set_P_amb_pwb,
	PyDoc_STR("*float*: Ambient pressure [atm]\n\n**Required:**\nTrue"),
 	NULL},
{"P_boil_des", (getter)Powerblock_get_P_boil_des,(setter)Powerblock_set_P_boil_des,
	PyDoc_STR("*float*: Boiler operating pressure @ design [bar]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``P_boil_des``:\n\n\t - P_turb_des\n"),
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n**Required:**\nTrue"),
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio [none]\n\n**Required:**\nTrue"),
 	NULL},
{"P_rh_ref", (getter)Powerblock_get_P_rh_ref,(setter)Powerblock_set_P_rh_ref,
	PyDoc_STR("*float*: Reheater operating pressure at design [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_cold_ref", (getter)Powerblock_get_T_cold_ref,(setter)Powerblock_set_T_cold_ref,
	PyDoc_STR("*float*: Reference HTF outlet temperature at design [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_cold_ref``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"T_db_pwb", (getter)Powerblock_get_T_db_pwb,(setter)Powerblock_set_T_db_pwb,
	PyDoc_STR("*float*: Ambient dry bulb temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_hot", (getter)Powerblock_get_T_hot,(setter)Powerblock_set_T_hot,
	PyDoc_STR("*float*: Hot HTF inlet temperature, from storage tank [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_hot``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solarm\n"),
 	NULL},
{"T_wb", (getter)Powerblock_get_T_wb,(setter)Powerblock_set_T_wb,
	PyDoc_STR("*float*: Ambient wet bulb temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n**Required:**\nTrue"),
 	NULL},
{"demand_var", (getter)Powerblock_get_demand_var,(setter)Powerblock_set_demand_var,
	PyDoc_STR("*float*: Control signal indicating operational mode [none]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``demand_var``:\n\n\t - nLoops\n\t - q_max_aux\n\t - q_pb_des\n\t - solarm\n\t - system_capacity\n"),
 	NULL},
{"dp_b", (getter)Powerblock_get_dp_b,(setter)Powerblock_set_dp_b,
	PyDoc_STR("*float*: Pressure drop in boiler [Pa]\n\n**Required:**\nTrue"),
 	NULL},
{"dp_rh", (getter)Powerblock_get_dp_rh,(setter)Powerblock_set_dp_rh,
	PyDoc_STR("*float*: Pressure drop in reheater [Pa]\n\n**Required:**\nTrue"),
 	NULL},
{"dp_sh", (getter)Powerblock_get_dp_sh,(setter)Powerblock_set_dp_sh,
	PyDoc_STR("*float*: Pressure drop in superheater [Pa]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Reference conversion efficiency at design condition [none]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``eta_ref``:\n\n\t - nLoops\n\t - q_max_aux\n\t - q_pb_des\n\t - solarm\n"),
 	NULL},
{"f_recSU", (getter)Powerblock_get_f_recSU,(setter)Powerblock_set_f_recSU,
	PyDoc_STR("*float*: Fraction powerblock can run due to receiver startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_st", (getter)Powerblock_get_m_dot_st,(setter)Powerblock_set_m_dot_st,
	PyDoc_STR("*float*: HTF mass flow rate [kg/hr]\n\n**Required:**\nTrue"),
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"pc_mode", (getter)Powerblock_get_pc_mode,(setter)Powerblock_set_pc_mode,
	PyDoc_STR("*float*: Cycle part load control, from plant controller [none]\n\n**Required:**\nTrue"),
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby mode [none]\n\n**Required:**\nTrue"),
 	NULL},
{"relhum", (getter)Powerblock_get_relhum,(setter)Powerblock_set_relhum,
	PyDoc_STR("*float*: Relative humidity of the ambient air [none]\n\n**Required:**\nTrue"),
 	NULL},
{"rh_frac_ref", (getter)Powerblock_get_rh_frac_ref,(setter)Powerblock_set_rh_frac_ref,
	PyDoc_STR("*float*: Reheater flow fraction at design [none]\n\n**Required:**\nTrue"),
 	NULL},
{"standby_control", (getter)Powerblock_get_standby_control,(setter)Powerblock_set_standby_control,
	PyDoc_STR("*float*: Control signal indicating standby mode [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Powerblock",             /*tp_name*/
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
		Powerblock_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Powerblock_getset,          /*tp_getset*/
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
Outputs_new(SAM_TcslinearFresnel data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcslinearFresnel", "Outputs")){
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
Outputs_get_E_bal_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_E_bal_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cond(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_P_cond_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_sf_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_P_sf_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_turb_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_P_turb_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_field_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_field_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_loop_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pb_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_pb_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pb_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_pb_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_cool_par(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_cool_par_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_cycle_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_aux(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_bop(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_bop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_col(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_col_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_annual_fuel_usage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_dP_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_dP_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_opt_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_opt_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_bays(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_f_bays_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_aux(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_b_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_b_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_makeup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_makeup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_to_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_aux_fluid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux_fuel(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_aux_fuel_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_dump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_field_delivered(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_field_delivered_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_inc_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_piping(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_loss_piping_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_loss_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_loss_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcslinearFresnel_Outputs_system_heat_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"E_bal_startup", (getter)Outputs_get_E_bal_startup,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal energy startup [MWt]"),
 	NULL},
{"P_cond", (getter)Outputs_get_P_cond,(setter)0,
	PyDoc_STR("*sequence*: Condenser pressure [Pa]"),
 	NULL},
{"P_sf_in", (getter)Outputs_get_P_sf_in,(setter)0,
	PyDoc_STR("*sequence*: Field steam pressure at inlet [bar]"),
 	NULL},
{"P_turb_in", (getter)Outputs_get_P_turb_in,(setter)0,
	PyDoc_STR("*sequence*: Cycle steam pressure at inlet [bar]"),
 	NULL},
{"T_field_in", (getter)Outputs_get_T_field_in,(setter)0,
	PyDoc_STR("*sequence*: Field steam temperature at header inlet [C]"),
 	NULL},
{"T_field_out", (getter)Outputs_get_T_field_out,(setter)0,
	PyDoc_STR("*sequence*: Field steam temperature at header outlet [C]"),
 	NULL},
{"T_loop_out", (getter)Outputs_get_T_loop_out,(setter)0,
	PyDoc_STR("*sequence*: Field steam temperature at collector outlet [C]"),
 	NULL},
{"T_pb_in", (getter)Outputs_get_T_pb_in,(setter)0,
	PyDoc_STR("*sequence*: Cycle steam temperature at inlet [C]"),
 	NULL},
{"T_pb_out", (getter)Outputs_get_T_pb_out,(setter)0,
	PyDoc_STR("*sequence*: Cycle steam temperature at outlet [C]"),
 	NULL},
{"W_cool_par", (getter)Outputs_get_W_cool_par,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"W_cycle_gross", (getter)Outputs_get_W_cycle_gross,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (gross) [MWe]"),
 	NULL},
{"W_dot_aux", (getter)Outputs_get_W_dot_aux,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power auxiliary heater operation [MWe]"),
 	NULL},
{"W_dot_bop", (getter)Outputs_get_W_dot_bop,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power generation-dependent load [MWe]"),
 	NULL},
{"W_dot_col", (getter)Outputs_get_W_dot_col,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power field collector drives [MWe]"),
 	NULL},
{"W_dot_fixed", (getter)Outputs_get_W_dot_fixed,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power fixed load [MWe]"),
 	NULL},
{"W_dot_pump", (getter)Outputs_get_W_dot_pump,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power solar field pump [MWe]"),
 	NULL},
{"W_net", (getter)Outputs_get_W_net,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (net) [MWe]"),
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Electrical source - Power cycle gross output [kWh]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	PyDoc_STR("*float*: Annual fuel usage [kWh]"),
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	PyDoc_STR("*float*: Total Annual Water Usage: cycle + mirror washing [m3]"),
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	PyDoc_STR("*sequence*: Resource Beam normal irradiance [W/m2]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"conversion_factor", (getter)Outputs_get_conversion_factor,(setter)0,
	PyDoc_STR("*float*: Gross to Net Conversion Factor [%]"),
 	NULL},
{"dP_tot", (getter)Outputs_get_dP_tot,(setter)0,
	PyDoc_STR("*sequence*: Field steam pressure loss [bar]"),
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	PyDoc_STR("*sequence*: Field collector focus fraction"),
 	NULL},
{"eta", (getter)Outputs_get_eta,(setter)0,
	PyDoc_STR("*sequence*: Cycle efficiency (gross)"),
 	NULL},
{"eta_opt_ave", (getter)Outputs_get_eta_opt_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector optical efficiency"),
 	NULL},
{"eta_sf", (getter)Outputs_get_eta_sf,(setter)0,
	PyDoc_STR("*sequence*: Field efficiency total"),
 	NULL},
{"eta_thermal", (getter)Outputs_get_eta_thermal,(setter)0,
	PyDoc_STR("*sequence*: Field thermal efficiency"),
 	NULL},
{"f_bays", (getter)Outputs_get_f_bays,(setter)0,
	PyDoc_STR("*sequence*: Condenser fraction of operating bays [none]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"m_dot", (getter)Outputs_get_m_dot,(setter)0,
	PyDoc_STR("*sequence*: Field steam mass flow rate - loop [kg/s]"),
 	NULL},
{"m_dot_aux", (getter)Outputs_get_m_dot_aux,(setter)0,
	PyDoc_STR("*sequence*: Fossil steam mass flow rate [kg/hr]"),
 	NULL},
{"m_dot_b_tot", (getter)Outputs_get_m_dot_b_tot,(setter)0,
	PyDoc_STR("*sequence*: Field steam mass flow rate - boiler [kg/hr]"),
 	NULL},
{"m_dot_field", (getter)Outputs_get_m_dot_field,(setter)0,
	PyDoc_STR("*sequence*: Field steam mass flow rate [kg/hr]"),
 	NULL},
{"m_dot_makeup", (getter)Outputs_get_m_dot_makeup,(setter)0,
	PyDoc_STR("*sequence*: Cycle cooling water mass flow rate - makeup [kg/hr]"),
 	NULL},
{"m_dot_to_pb", (getter)Outputs_get_m_dot_to_pb,(setter)0,
	PyDoc_STR("*sequence*: Cycle steam mass flow rate [kg/hr]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy Gross [kWh]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"q_aux_fluid", (getter)Outputs_get_q_aux_fluid,(setter)0,
	PyDoc_STR("*sequence*: Fossil thermal power produced [MWt]"),
 	NULL},
{"q_aux_fuel", (getter)Outputs_get_q_aux_fuel,(setter)0,
	PyDoc_STR("*sequence*: Fossil fuel usage [MMBTU]"),
 	NULL},
{"q_dump", (getter)Outputs_get_q_dump,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal energy dumped [MWt]"),
 	NULL},
{"q_field_delivered", (getter)Outputs_get_q_field_delivered,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power produced [MWt]"),
 	NULL},
{"q_inc_tot", (getter)Outputs_get_q_inc_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_loss_piping", (getter)Outputs_get_q_loss_piping,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power header pipe loss [MWt]"),
 	NULL},
{"q_loss_rec", (getter)Outputs_get_q_loss_rec,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power receiver loss [MWt]"),
 	NULL},
{"q_loss_sf", (getter)Outputs_get_q_loss_sf,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power loss [MWt]"),
 	NULL},
{"q_to_pb", (getter)Outputs_get_q_to_pb,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal power input [MWt]"),
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Azimuth [deg]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	PyDoc_STR("*float*: System heat rate [MMBtu/MWh]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: Resource Time-of-use value"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Resource Wind Speed [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Outputs",             /*tp_name*/
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
 * TcslinearFresnel
 */

static PyTypeObject TcslinearFresnel_Type;

static CmodObject *
newTcslinearFresnelObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TcslinearFresnel_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* LinearFresnelr_obj = LinearFresnelr_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LinearFresnelr", LinearFresnelr_obj);
	Py_DECREF(LinearFresnelr_obj);

	PyObject* TouTranslator_obj = TouTranslator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TouTranslator", TouTranslator_obj);
	Py_DECREF(TouTranslator_obj);

	PyObject* Solarfield_obj = Solarfield_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Solarfield", Solarfield_obj);
	Py_DECREF(Solarfield_obj);

	PyObject* Heliostat_obj = Heliostat_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Heliostat", Heliostat_obj);
	Py_DECREF(Heliostat_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

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

/* TcslinearFresnel methods */

static void
TcslinearFresnel_dealloc(CmodObject *self)
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
TcslinearFresnel_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TcslinearFresnel_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcslinearFresnel_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcslinearFresnel"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TcslinearFresnel_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcslinearFresnel"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TcslinearFresnel_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TcslinearFresnel_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TcslinearFresnel_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TcslinearFresnel_methods[] = {
		{"execute",           (PyCFunction)TcslinearFresnel_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcslinearFresnel_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TcslinearFresnel_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TcslinearFresnel_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TcslinearFresnel_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TcslinearFresnel_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcslinearFresnel_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcslinearFresnel_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcslinearFresnel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TcslinearFresnel_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TcslinearFresnel_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TcslinearFresnel_getattro, /*tp_getattro*/
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
		TcslinearFresnel_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TcslinearFresnel object */

static PyObject *
TcslinearFresnel_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTcslinearFresnelObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcslinearFresnel_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcslinearFresnelObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcslinearFresnel_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcslinearFresnelObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcslinearFresnel", def) < 0) {
		TcslinearFresnel_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TcslinearFresnel_from_existing(PyObject *self, PyObject *args)
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

	rv = newTcslinearFresnelObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcslinearFresnel", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcslinearFresnelModule_methods[] = {
		{"new",             TcslinearFresnel_new,         METH_VARARGS,
				PyDoc_STR("new() -> TcslinearFresnel")},
		{"default",             TcslinearFresnel_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TcslinearFresnel\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"DSLFAllEquityPartnershipFlip\"*\n\n		- *\"DSLFCommercial\"*\n\n		- *\"DSLFLCOECalculator\"*\n\n		- *\"DSLFLeveragedPartnershipFlip\"*\n\n		- *\"DSLFMerchantPlant\"*\n\n		- *\"DSLFNone\"*\n\n		- *\"DSLFSaleLeaseback\"*\n\n		- *\"DSLFSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TcslinearFresnel_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TcslinearFresnel\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TcslinearFresnel_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TcslinearFresnel\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Process heat linear direct steam ");


static int
TcslinearFresnelModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TcslinearFresnel_Type.tp_dict = PyDict_New();
	if (!TcslinearFresnel_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TcslinearFresnel_Type
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
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TcslinearFresnel_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the LinearFresnelr type object to TcslinearFresnel_Type
	if (PyType_Ready(&LinearFresnelr_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"LinearFresnelr",
				(PyObject*)&LinearFresnelr_Type);
	Py_DECREF(&LinearFresnelr_Type);

	/// Add the TouTranslator type object to TcslinearFresnel_Type
	if (PyType_Ready(&TouTranslator_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"TouTranslator",
				(PyObject*)&TouTranslator_Type);
	Py_DECREF(&TouTranslator_Type);

	/// Add the Solarfield type object to TcslinearFresnel_Type
	if (PyType_Ready(&Solarfield_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"Solarfield",
				(PyObject*)&Solarfield_Type);
	Py_DECREF(&Solarfield_Type);

	/// Add the Heliostat type object to TcslinearFresnel_Type
	if (PyType_Ready(&Heliostat_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"Heliostat",
				(PyObject*)&Heliostat_Type);
	Py_DECREF(&Heliostat_Type);

	/// Add the Powerblock type object to TcslinearFresnel_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the Outputs type object to TcslinearFresnel_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcslinearFresnel_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TcslinearFresnel type object to the module
	if (PyType_Ready(&TcslinearFresnel_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TcslinearFresnel",
				(PyObject*)&TcslinearFresnel_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TcslinearFresnelModule_slots[] = {
		{Py_mod_exec, TcslinearFresnelModule_exec},
		{0, NULL},
};

static struct PyModuleDef TcslinearFresnelModule = {
		PyModuleDef_HEAD_INIT,
		"TcslinearFresnel",
		module_doc,
		0,
		TcslinearFresnelModule_methods,
		TcslinearFresnelModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TcslinearFresnel(void)
{
	return PyModuleDef_Init(&TcslinearFresnelModule);
}