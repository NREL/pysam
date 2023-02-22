#include <Python.h>

#include <SAM_TcsgenericSolar.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TcsgenericSolar data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsgenericSolar", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsgenericSolar", "Weather")){
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
	return PySAM_double_getter(SAM_TcsgenericSolar_Weather_azimuth_nget, self->data_ptr);
}

static int
Weather_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Weather_azimuth_nset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsgenericSolar_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsgenericSolar_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Weather_tilt_nget, self->data_ptr);
}

static int
Weather_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Weather_tilt_nset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Weather_track_mode_nget, self->data_ptr);
}

static int
Weather_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Weather_track_mode_nset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"azimuth", (getter)Weather_get_azimuth,(setter)Weather_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle of surface/axis\n\n**Required:**\nTrue"),
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
		"TcsgenericSolar.Weather",             /*tp_name*/
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
 * GenericSolar Group
 */ 

static PyTypeObject GenericSolar_Type;

static PyObject *
GenericSolar_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = GenericSolar_Type.tp_alloc(&GenericSolar_Type,0);

	VarGroupObject* GenericSolar_obj = (VarGroupObject*)new_obj;

	GenericSolar_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* GenericSolar methods */

static PyObject *
GenericSolar_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsgenericSolar", "GenericSolar")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GenericSolar_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &GenericSolar_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsgenericSolar", "GenericSolar")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GenericSolar_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &GenericSolar_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GenericSolar_methods[] = {
		{"assign",            (PyCFunction)GenericSolar_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``GenericSolar_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)GenericSolar_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``GenericSolar_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)GenericSolar_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GenericSolar_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_GenericSolar_system_capacity_nget, self->data_ptr);
}

static int
GenericSolar_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_GenericSolar_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef GenericSolar_getset[] = {
{"system_capacity", (getter)GenericSolar_get_system_capacity,(setter)GenericSolar_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - w_des\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GenericSolar_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.GenericSolar",             /*tp_name*/
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
		GenericSolar_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GenericSolar_getset,          /*tp_getset*/
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
TouTranslator_new(SAM_TcsgenericSolar data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsgenericSolar", "TouTranslator")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsgenericSolar", "TouTranslator")){
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
	return PySAM_matrix_getter(SAM_TcsgenericSolar_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_TouTranslator_weekend_schedule_mset, self->data_ptr);
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
		"TcsgenericSolar.TouTranslator",             /*tp_name*/
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
 * Type260 Group
 */ 

static PyTypeObject Type260_Type;

static PyObject *
Type260_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = Type260_Type.tp_alloc(&Type260_Type,0);

	VarGroupObject* Type260_obj = (VarGroupObject*)new_obj;

	Type260_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Type260 methods */

static PyObject *
Type260_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsgenericSolar", "Type260")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Type260_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Type260_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsgenericSolar", "Type260")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Type260_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Type260_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Type260_methods[] = {
		{"assign",            (PyCFunction)Type260_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Type260_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Type260_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Type260_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Type260_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Type260_get_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_Type260_OpticalTable_mget, self->data_ptr);
}

static int
Type260_set_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_Type260_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Type260_get_PC_T_corr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_PC_T_corr_nget, self->data_ptr);
}

static int
Type260_set_PC_T_corr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_PC_T_corr_nset, self->data_ptr);
}

static PyObject *
Type260_get_T_pcdes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_T_pcdes_nget, self->data_ptr);
}

static int
Type260_set_T_pcdes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_T_pcdes_nset, self->data_ptr);
}

static PyObject *
Type260_get_T_sfdes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_T_sfdes_nget, self->data_ptr);
}

static int
Type260_set_T_sfdes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_T_sfdes_nset, self->data_ptr);
}

static PyObject *
Type260_get_Wpar_prodD_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_Wpar_prodD_coefs_aget, self->data_ptr);
}

static int
Type260_set_Wpar_prodD_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_Wpar_prodD_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_Wpar_prodQ_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_Wpar_prodQ_coefs_aget, self->data_ptr);
}

static int
Type260_set_Wpar_prodQ_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_Wpar_prodQ_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_Wpar_prodT_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_Wpar_prodT_coefs_aget, self->data_ptr);
}

static int
Type260_set_Wpar_prodT_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_Wpar_prodT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_diswos(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_diswos_aget, self->data_ptr);
}

static int
Type260_set_diswos(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_diswos_aset, self->data_ptr);
}

static PyObject *
Type260_get_disws(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_disws_aget, self->data_ptr);
}

static int
Type260_set_disws(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_disws_aset, self->data_ptr);
}

static PyObject *
Type260_get_etaQ_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_etaQ_coefs_aget, self->data_ptr);
}

static int
Type260_set_etaQ_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_etaQ_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_etaT_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_etaT_coefs_aget, self->data_ptr);
}

static int
Type260_set_etaT_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_etaT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_eta_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_eta_des_nget, self->data_ptr);
}

static int
Type260_set_eta_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_eta_des_nset, self->data_ptr);
}

static PyObject *
Type260_get_eta_lhv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_eta_lhv_nget, self->data_ptr);
}

static int
Type260_set_eta_lhv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_eta_lhv_nset, self->data_ptr);
}

static PyObject *
Type260_get_eta_opt_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_eta_opt_gen_nget, self->data_ptr);
}

static int
Type260_set_eta_opt_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_eta_opt_gen_nset, self->data_ptr);
}

static PyObject *
Type260_get_eta_opt_soil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_eta_opt_soil_nget, self->data_ptr);
}

static int
Type260_set_eta_opt_soil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_eta_opt_soil_nset, self->data_ptr);
}

static PyObject *
Type260_get_exergy_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_Type260_exergy_table_mget, self->data_ptr);
}

static int
Type260_set_exergy_table(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_Type260_exergy_table_mset, self->data_ptr);
}

static PyObject *
Type260_get_f_Wpar_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_Wpar_fixed_nget, self->data_ptr);
}

static int
Type260_set_f_Wpar_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_Wpar_fixed_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_Wpar_prod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_Wpar_prod_nget, self->data_ptr);
}

static int
Type260_set_f_Wpar_prod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_Wpar_prod_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_charge_nget, self->data_ptr);
}

static int
Type260_set_f_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_charge_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_disch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_disch_nget, self->data_ptr);
}

static int
Type260_set_f_disch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_disch_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_etes_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_etes_0_nget, self->data_ptr);
}

static int
Type260_set_f_etes_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_etes_0_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_sfhl_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_sfhl_ref_nget, self->data_ptr);
}

static int
Type260_set_f_sfhl_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_sfhl_ref_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_startup_nget, self->data_ptr);
}

static int
Type260_set_f_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_startup_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_teshl_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_teshl_ref_nget, self->data_ptr);
}

static int
Type260_set_f_teshl_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_teshl_ref_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_wmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_wmax_nget, self->data_ptr);
}

static int
Type260_set_f_wmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_wmax_nset, self->data_ptr);
}

static PyObject *
Type260_get_f_wmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_f_wmin_nget, self->data_ptr);
}

static int
Type260_set_f_wmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_f_wmin_nset, self->data_ptr);
}

static PyObject *
Type260_get_fdisp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_fdisp_aget, self->data_ptr);
}

static int
Type260_set_fdisp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_fdisp_aset, self->data_ptr);
}

static PyObject *
Type260_get_hrs_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_hrs_tes_nget, self->data_ptr);
}

static int
Type260_set_hrs_tes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_hrs_tes_nset, self->data_ptr);
}

static PyObject *
Type260_get_ibh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_ibh_nget, self->data_ptr);
}

static int
Type260_set_ibh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_ibh_nset, self->data_ptr);
}

static PyObject *
Type260_get_ibn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_ibn_nget, self->data_ptr);
}

static int
Type260_set_ibn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_ibn_nset, self->data_ptr);
}

static PyObject *
Type260_get_interp_arr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_interp_arr_nget, self->data_ptr);
}

static int
Type260_set_interp_arr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_interp_arr_nset, self->data_ptr);
}

static PyObject *
Type260_get_irr_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_irr_des_nget, self->data_ptr);
}

static int
Type260_set_irr_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_irr_des_nset, self->data_ptr);
}

static PyObject *
Type260_get_istableunsorted(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_istableunsorted_nget, self->data_ptr);
}

static int
Type260_set_istableunsorted(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_istableunsorted_nset, self->data_ptr);
}

static PyObject *
Type260_get_itoth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_itoth_nget, self->data_ptr);
}

static int
Type260_set_itoth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_itoth_nset, self->data_ptr);
}

static PyObject *
Type260_get_latitude(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_latitude_nget, self->data_ptr);
}

static int
Type260_set_latitude(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_latitude_nset, self->data_ptr);
}

static PyObject *
Type260_get_longitude(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_longitude_nget, self->data_ptr);
}

static int
Type260_set_longitude(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_longitude_nset, self->data_ptr);
}

static PyObject *
Type260_get_ntod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_ntod_nget, self->data_ptr);
}

static int
Type260_set_ntod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_ntod_nset, self->data_ptr);
}

static PyObject *
Type260_get_qdisp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_qdisp_aget, self->data_ptr);
}

static int
Type260_set_qdisp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_qdisp_aset, self->data_ptr);
}

static PyObject *
Type260_get_qsf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_qsf_des_nget, self->data_ptr);
}

static int
Type260_set_qsf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_qsf_des_nset, self->data_ptr);
}

static PyObject *
Type260_get_rad_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_rad_type_nget, self->data_ptr);
}

static int
Type260_set_rad_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_rad_type_nset, self->data_ptr);
}

static PyObject *
Type260_get_sfhlQ_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_sfhlQ_coefs_aget, self->data_ptr);
}

static int
Type260_set_sfhlQ_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_sfhlQ_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_sfhlT_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_sfhlT_coefs_aget, self->data_ptr);
}

static int
Type260_set_sfhlT_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_sfhlT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_sfhlV_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_sfhlV_coefs_aget, self->data_ptr);
}

static int
Type260_set_sfhlV_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_sfhlV_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_solarm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_solarm_nget, self->data_ptr);
}

static int
Type260_set_solarm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_solarm_nset, self->data_ptr);
}

static PyObject *
Type260_get_storage_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_storage_config_nget, self->data_ptr);
}

static int
Type260_set_storage_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_storage_config_nset, self->data_ptr);
}

static PyObject *
Type260_get_tdb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_tdb_nget, self->data_ptr);
}

static int
Type260_set_tdb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_tdb_nset, self->data_ptr);
}

static PyObject *
Type260_get_teshlT_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_teshlT_coefs_aget, self->data_ptr);
}

static int
Type260_set_teshlT_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_teshlT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_teshlX_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_teshlX_coefs_aget, self->data_ptr);
}

static int
Type260_set_teshlX_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_teshlX_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_theta_dep_nget, self->data_ptr);
}

static int
Type260_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_theta_dep_nset, self->data_ptr);
}

static PyObject *
Type260_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_theta_stow_nget, self->data_ptr);
}

static int
Type260_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_theta_stow_nset, self->data_ptr);
}

static PyObject *
Type260_get_timezone(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_timezone_nget, self->data_ptr);
}

static int
Type260_set_timezone(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_timezone_nset, self->data_ptr);
}

static PyObject *
Type260_get_twb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_twb_nget, self->data_ptr);
}

static int
Type260_set_twb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_twb_nset, self->data_ptr);
}

static PyObject *
Type260_get_vwind(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_vwind_nget, self->data_ptr);
}

static int
Type260_set_vwind(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_vwind_nset, self->data_ptr);
}

static PyObject *
Type260_get_w_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Type260_w_des_nget, self->data_ptr);
}

static int
Type260_set_w_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsgenericSolar_Type260_w_des_nset, self->data_ptr);
}

static PyGetSetDef Type260_getset[] = {
{"OpticalTable", (getter)Type260_get_OpticalTable,(setter)Type260_set_OpticalTable,
	PyDoc_STR("*sequence[sequence]*: Optical table [none]\n\n**Required:**\nTrue"),
 	NULL},
{"PC_T_corr", (getter)Type260_get_PC_T_corr,(setter)Type260_set_PC_T_corr,
	PyDoc_STR("*float*: Power conversion temperature correction mode (1=wetb, 2=dryb) [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"T_pcdes", (getter)Type260_get_T_pcdes,(setter)Type260_set_T_pcdes,
	PyDoc_STR("*float*: Power conversion reference temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_sfdes", (getter)Type260_get_T_sfdes,(setter)Type260_set_T_sfdes,
	PyDoc_STR("*float*: Solar field design point temperature (dry bulb) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"Wpar_prodD_coefs", (getter)Type260_get_Wpar_prodD_coefs,(setter)Type260_set_Wpar_prodD_coefs,
	PyDoc_STR("*sequence*: DNI-based production parasitic adjustment coefs. [m2/W]\n\n**Required:**\nTrue"),
 	NULL},
{"Wpar_prodQ_coefs", (getter)Type260_get_Wpar_prodQ_coefs,(setter)Type260_set_Wpar_prodQ_coefs,
	PyDoc_STR("*sequence*: Part-load production parasitic adjustment coefs. [1/MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"Wpar_prodT_coefs", (getter)Type260_get_Wpar_prodT_coefs,(setter)Type260_set_Wpar_prodT_coefs,
	PyDoc_STR("*sequence*: Temp.-based production parasitic adjustment coefs. [1/C]\n\n**Required:**\nTrue"),
 	NULL},
{"diswos", (getter)Type260_get_diswos,(setter)Type260_set_diswos,
	PyDoc_STR("*sequence*: Time-of-dispatch control for without-solar conditions [none]\n\n**Required:**\nTrue"),
 	NULL},
{"disws", (getter)Type260_get_disws,(setter)Type260_set_disws,
	PyDoc_STR("*sequence*: Time-of-dispatch control for with-solar conditions [none]\n\n**Required:**\nTrue"),
 	NULL},
{"etaQ_coefs", (getter)Type260_get_etaQ_coefs,(setter)Type260_set_etaQ_coefs,
	PyDoc_STR("*sequence*: Part-load power conversion efficiency adjustment coefficients [1/MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"etaT_coefs", (getter)Type260_get_etaT_coefs,(setter)Type260_set_etaT_coefs,
	PyDoc_STR("*sequence*: Temp.-based power conversion efficiency adjustment coefs. [1/C]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_des", (getter)Type260_get_eta_des,(setter)Type260_set_eta_des,
	PyDoc_STR("*float*: Design power cycle gross efficiency [none]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``eta_des``:\n\n\t - qsf_des\n"),
 	NULL},
{"eta_lhv", (getter)Type260_get_eta_lhv,(setter)Type260_set_eta_lhv,
	PyDoc_STR("*float*: Fossil backup lower heating value efficiency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_opt_gen", (getter)Type260_get_eta_opt_gen,(setter)Type260_set_eta_opt_gen,
	PyDoc_STR("*float*: General/other optical derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_opt_soil", (getter)Type260_get_eta_opt_soil,(setter)Type260_set_eta_opt_soil,
	PyDoc_STR("*float*: Soiling optical derate factor [none]\n\n**Required:**\nTrue"),
 	NULL},
{"exergy_table", (getter)Type260_get_exergy_table,(setter)Type260_set_exergy_table,
	PyDoc_STR("*sequence[sequence]*: Exergy table [none]\n\n**Required:**\nTrue"),
 	NULL},
{"f_Wpar_fixed", (getter)Type260_get_f_Wpar_fixed,(setter)Type260_set_f_Wpar_fixed,
	PyDoc_STR("*float*: Fixed capacity-based parasitic loss fraction [MWe/MWcap]\n\n**Required:**\nTrue"),
 	NULL},
{"f_Wpar_prod", (getter)Type260_get_f_Wpar_prod,(setter)Type260_set_f_Wpar_prod,
	PyDoc_STR("*float*: Production-based parasitic loss fraction [MWe/MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"f_charge", (getter)Type260_get_f_charge,(setter)Type260_set_f_charge,
	PyDoc_STR("*float*: Storage charging energy derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"f_disch", (getter)Type260_get_f_disch,(setter)Type260_set_f_disch,
	PyDoc_STR("*float*: Storage discharging energy derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"f_etes_0", (getter)Type260_get_f_etes_0,(setter)Type260_set_f_etes_0,
	PyDoc_STR("*float*: Initial fractional charge level of thermal storage (0..1) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"f_sfhl_ref", (getter)Type260_get_f_sfhl_ref,(setter)Type260_set_f_sfhl_ref,
	PyDoc_STR("*float*: Reference solar field thermal loss fraction [MW/MWcap]\n\n**Required:**\nTrue"),
 	NULL},
{"f_startup", (getter)Type260_get_f_startup,(setter)Type260_set_f_startup,
	PyDoc_STR("*float*: Equivalent full-load hours required for power system startup [hours]\n\n**Required:**\nTrue"),
 	NULL},
{"f_teshl_ref", (getter)Type260_get_f_teshl_ref,(setter)Type260_set_f_teshl_ref,
	PyDoc_STR("*float*: Reference heat loss from storage per max stored capacity [kWt/MWhr-stored]\n\n**Required:**\nTrue"),
 	NULL},
{"f_wmax", (getter)Type260_get_f_wmax,(setter)Type260_set_f_wmax,
	PyDoc_STR("*float*: Maximum over-design power cycle operation fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"f_wmin", (getter)Type260_get_f_wmin,(setter)Type260_set_f_wmin,
	PyDoc_STR("*float*: Minimum part-load power cycle operation fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fdisp", (getter)Type260_get_fdisp,(setter)Type260_set_fdisp,
	PyDoc_STR("*sequence*: Fossil backup output control factors [none]\n\n**Required:**\nTrue"),
 	NULL},
{"hrs_tes", (getter)Type260_get_hrs_tes,(setter)Type260_set_hrs_tes,
	PyDoc_STR("*float*: Equivalent full-load hours of storage [hours]\n\n**Required:**\nTrue"),
 	NULL},
{"ibh", (getter)Type260_get_ibh,(setter)Type260_set_ibh,
	PyDoc_STR("*float*: Beam-horizontal irradiation [kJ/hr-m^2]\n\n**Required:**\nTrue"),
 	NULL},
{"ibn", (getter)Type260_get_ibn,(setter)Type260_set_ibn,
	PyDoc_STR("*float*: Beam-normal (DNI) irradiation [kJ/hr-m^2]\n\n**Required:**\nTrue"),
 	NULL},
{"interp_arr", (getter)Type260_get_interp_arr,(setter)Type260_set_interp_arr,
	PyDoc_STR("*float*: Interpolate the array or find nearest neighbor? (1=interp,2=no) [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"irr_des", (getter)Type260_get_irr_des,(setter)Type260_set_irr_des,
	PyDoc_STR("*float*: Irradiation design point [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"istableunsorted", (getter)Type260_get_istableunsorted,(setter)Type260_set_istableunsorted,
	PyDoc_STR("*float*: Is optical table unsorted format? [none]\n\n**Required:**\nTrue"),
 	NULL},
{"itoth", (getter)Type260_get_itoth,(setter)Type260_set_itoth,
	PyDoc_STR("*float*: Total horizontal irradiation [kJ/hr-m^2]\n\n**Required:**\nTrue"),
 	NULL},
{"latitude", (getter)Type260_get_latitude,(setter)Type260_set_latitude,
	PyDoc_STR("*float*: Site latitude\n\n**Required:**\nTrue"),
 	NULL},
{"longitude", (getter)Type260_get_longitude,(setter)Type260_set_longitude,
	PyDoc_STR("*float*: Site longitude\n\n**Required:**\nTrue"),
 	NULL},
{"ntod", (getter)Type260_get_ntod,(setter)Type260_set_ntod,
	PyDoc_STR("*float*: Number of time-of-dispatch periods in the dispatch schedule [none]\n\n**Required:**\nTrue"),
 	NULL},
{"qdisp", (getter)Type260_get_qdisp,(setter)Type260_set_qdisp,
	PyDoc_STR("*sequence*: TOD power output control factors [none]\n\n**Required:**\nTrue"),
 	NULL},
{"qsf_des", (getter)Type260_get_qsf_des,(setter)Type260_set_qsf_des,
	PyDoc_STR("*float*: Solar field thermal production at design [MWt]\n\n**Required:**\nTrue\n\nThe value of ``qsf_des`` depends on the following variables:\n\n\t - eta_des\n\t - solarm\n\t - w_des\n"),
 	NULL},
{"rad_type", (getter)Type260_get_rad_type,(setter)Type260_set_rad_type,
	PyDoc_STR("*float*: Solar resource radiation type (1=DNI,2=horiz.beam,3=tot.horiz) [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"sfhlQ_coefs", (getter)Type260_get_sfhlQ_coefs,(setter)Type260_set_sfhlQ_coefs,
	PyDoc_STR("*sequence*: Irr-based solar field thermal loss adjustment coefficients [1/MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"sfhlT_coefs", (getter)Type260_get_sfhlT_coefs,(setter)Type260_set_sfhlT_coefs,
	PyDoc_STR("*sequence*: Temp.-based solar field thermal loss adjustment coefficients [1/C]\n\n**Required:**\nTrue"),
 	NULL},
{"sfhlV_coefs", (getter)Type260_get_sfhlV_coefs,(setter)Type260_set_sfhlV_coefs,
	PyDoc_STR("*sequence*: Wind-based solar field thermal loss adjustment coefficients [1/(m/s)]\n\n**Required:**\nTrue"),
 	NULL},
{"solarm", (getter)Type260_get_solarm,(setter)Type260_set_solarm,
	PyDoc_STR("*float*: Solar multiple [none]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``solarm``:\n\n\t - qsf_des\n"),
 	NULL},
{"storage_config", (getter)Type260_get_storage_config,(setter)Type260_set_storage_config,
	PyDoc_STR("*float*: Thermal storage configuration [none]\n\n**Required:**\nTrue"),
 	NULL},
{"tdb", (getter)Type260_get_tdb,(setter)Type260_set_tdb,
	PyDoc_STR("*float*: Ambient dry-bulb temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"teshlT_coefs", (getter)Type260_get_teshlT_coefs,(setter)Type260_set_teshlT_coefs,
	PyDoc_STR("*sequence*: Temp.-based thermal loss adjustment - constant coef. [1/C]\n\n**Required:**\nTrue"),
 	NULL},
{"teshlX_coefs", (getter)Type260_get_teshlX_coefs,(setter)Type260_set_teshlX_coefs,
	PyDoc_STR("*sequence*: Charge-based thermal loss adjustment - constant coef. [1/MWhr-stored]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)Type260_get_theta_dep,(setter)Type260_set_theta_dep,
	PyDoc_STR("*float*: Solar elevation angle at which the solar field begins operating [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)Type260_get_theta_stow,(setter)Type260_set_theta_stow,
	PyDoc_STR("*float*: Solar elevation angle at which the solar field stops operating [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"timezone", (getter)Type260_get_timezone,(setter)Type260_set_timezone,
	PyDoc_STR("*float*: Site timezone [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"twb", (getter)Type260_get_twb,(setter)Type260_set_twb,
	PyDoc_STR("*float*: Ambient wet-bulb temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"vwind", (getter)Type260_get_vwind,(setter)Type260_set_vwind,
	PyDoc_STR("*float*: Wind velocity [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"w_des", (getter)Type260_get_w_des,(setter)Type260_set_w_des,
	PyDoc_STR("*float*: Design power cycle gross output [MWe]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``w_des``:\n\n\t - qsf_des\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Type260_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.Type260",             /*tp_name*/
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
		Type260_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Type260_getset,          /*tp_getset*/
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
Outputs_new(SAM_TcsgenericSolar data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsgenericSolar", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsgenericSolar", "Outputs")){
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
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_fuel_usage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_dump_tot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_dump_tot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_fossil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_fossil_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_from_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_from_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_hl_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_hl_sf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_hl_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_hl_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_sf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_startup_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_to_pb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_to_pb_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_to_tes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_q_to_tes_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_w_gr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_annual_w_gr_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_in_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_e_in_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_enet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_enet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_eta_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_opt_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_eta_opt_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_effpc_qtpb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_effpc_qtpb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_effpc_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_effpc_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sfhl_qdni(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_sfhl_qdni_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sfhl_tamb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_sfhl_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sfhl_vwind(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_sfhl_vwind_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_global(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_global_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_dump_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_dump_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_fossil(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_fossil_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_from_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_from_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_hl_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_hl_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_hl_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_hl_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_to_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_to_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_to_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_w_gr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_w_gr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_teschg(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_teschg_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_tesfull(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_tesfull_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_umin(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_umin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_fossil(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_fossil_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_from_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_from_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_gas(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_gas_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_hl_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_hl_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_hl_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_hl_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_sf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_to_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsgenericSolar_Outputs_system_heat_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_gr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_gr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_gr_fossil(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_gr_fossil_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_gr_solar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_gr_solar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_offline(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_offline_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_online(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_online_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_prod(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_prod_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	PyDoc_STR("*float*: Annual fuel usage [kWh]"),
 	NULL},
{"annual_q_dump_tot", (getter)Outputs_get_annual_q_dump_tot,(setter)0,
	PyDoc_STR("*float*: Total dumped energy [MWht]"),
 	NULL},
{"annual_q_fossil", (getter)Outputs_get_annual_q_fossil,(setter)0,
	PyDoc_STR("*float*: Thermal energy supplied from aux firing [MWht]"),
 	NULL},
{"annual_q_from_tes", (getter)Outputs_get_annual_q_from_tes,(setter)0,
	PyDoc_STR("*float*: Thermal energy from storage [MWht]"),
 	NULL},
{"annual_q_hl_sf", (getter)Outputs_get_annual_q_hl_sf,(setter)0,
	PyDoc_STR("*float*: Solar field thermal losses [MWht]"),
 	NULL},
{"annual_q_hl_tes", (getter)Outputs_get_annual_q_hl_tes,(setter)0,
	PyDoc_STR("*float*: Thermal losses from storage [MWht]"),
 	NULL},
{"annual_q_sf", (getter)Outputs_get_annual_q_sf,(setter)0,
	PyDoc_STR("*float*: Solar field delivered thermal power [MWht]"),
 	NULL},
{"annual_q_startup", (getter)Outputs_get_annual_q_startup,(setter)0,
	PyDoc_STR("*float*: Power conversion startup energy [MWht]"),
 	NULL},
{"annual_q_to_pb", (getter)Outputs_get_annual_q_to_pb,(setter)0,
	PyDoc_STR("*float*: Thermal energy to the power conversion system [MWht]"),
 	NULL},
{"annual_q_to_tes", (getter)Outputs_get_annual_q_to_tes,(setter)0,
	PyDoc_STR("*float*: Thermal energy into storage [MWht]"),
 	NULL},
{"annual_w_gr", (getter)Outputs_get_annual_w_gr,(setter)0,
	PyDoc_STR("*float*: Total gross power production [kWh]"),
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
{"diff", (getter)Outputs_get_diff,(setter)0,
	PyDoc_STR("*sequence*: Resource Diffuse horizontal irradiance [W/m2]"),
 	NULL},
{"e_in_tes", (getter)Outputs_get_e_in_tes,(setter)0,
	PyDoc_STR("*sequence*: TES thermal energy available [MWht]"),
 	NULL},
{"enet", (getter)Outputs_get_enet,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (net) [MWe]"),
 	NULL},
{"eta_cycle", (getter)Outputs_get_eta_cycle,(setter)0,
	PyDoc_STR("*sequence*: Cycle efficiency (gross)"),
 	NULL},
{"eta_opt_sf", (getter)Outputs_get_eta_opt_sf,(setter)0,
	PyDoc_STR("*sequence*: Field collector optical efficiency [none]"),
 	NULL},
{"f_effpc_qtpb", (getter)Outputs_get_f_effpc_qtpb,(setter)0,
	PyDoc_STR("*sequence*: Cycle efficiency load-based correction"),
 	NULL},
{"f_effpc_tamb", (getter)Outputs_get_f_effpc_tamb,(setter)0,
	PyDoc_STR("*sequence*: Cycle efficiency temperature-based correction"),
 	NULL},
{"f_sfhl_qdni", (getter)Outputs_get_f_sfhl_qdni,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power load-based loss correction [none]"),
 	NULL},
{"f_sfhl_tamb", (getter)Outputs_get_f_sfhl_tamb,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power temp.-based loss correction [none]"),
 	NULL},
{"f_sfhl_vwind", (getter)Outputs_get_f_sfhl_vwind,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power wind-based loss correction [none]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"global", (getter)Outputs_get_global,(setter)0,
	PyDoc_STR("*sequence*: Resource Global horizontal irradiance [W/m2]"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy Gross [kWh]"),
 	NULL},
{"monthly_q_dump_tot", (getter)Outputs_get_monthly_q_dump_tot,(setter)0,
	PyDoc_STR("*sequence*: Total dumped energy [MWt]"),
 	NULL},
{"monthly_q_fossil", (getter)Outputs_get_monthly_q_fossil,(setter)0,
	PyDoc_STR("*sequence*: Thermal energy supplied from aux firing [MWt]"),
 	NULL},
{"monthly_q_from_tes", (getter)Outputs_get_monthly_q_from_tes,(setter)0,
	PyDoc_STR("*sequence*: Thermal energy from storage [MWt]"),
 	NULL},
{"monthly_q_hl_sf", (getter)Outputs_get_monthly_q_hl_sf,(setter)0,
	PyDoc_STR("*sequence*: Solar field thermal losses [MWt]"),
 	NULL},
{"monthly_q_hl_tes", (getter)Outputs_get_monthly_q_hl_tes,(setter)0,
	PyDoc_STR("*sequence*: Thermal losses from storage [MWt]"),
 	NULL},
{"monthly_q_sf", (getter)Outputs_get_monthly_q_sf,(setter)0,
	PyDoc_STR("*sequence*: Solar field delivered thermal power [MWt]"),
 	NULL},
{"monthly_q_startup", (getter)Outputs_get_monthly_q_startup,(setter)0,
	PyDoc_STR("*sequence*: Power conversion startup energy [MWt]"),
 	NULL},
{"monthly_q_to_pb", (getter)Outputs_get_monthly_q_to_pb,(setter)0,
	PyDoc_STR("*sequence*: Thermal energy to the power conversion system [MWt]"),
 	NULL},
{"monthly_q_to_tes", (getter)Outputs_get_monthly_q_to_tes,(setter)0,
	PyDoc_STR("*sequence*: Thermal energy into storage [MWt]"),
 	NULL},
{"monthly_w_gr", (getter)Outputs_get_monthly_w_gr,(setter)0,
	PyDoc_STR("*sequence*: Total gross power production [kWh]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"q_dump_teschg", (getter)Outputs_get_q_dump_teschg,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal energy dumped - solar field [MWt]"),
 	NULL},
{"q_dump_tesfull", (getter)Outputs_get_q_dump_tesfull,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal energy dumped - TES is full [MWt]"),
 	NULL},
{"q_dump_tot", (getter)Outputs_get_q_dump_tot,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal energy dumped total [MWt]"),
 	NULL},
{"q_dump_umin", (getter)Outputs_get_q_dump_umin,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal energy dumped - min. load requirement [MWt]"),
 	NULL},
{"q_fossil", (getter)Outputs_get_q_fossil,(setter)0,
	PyDoc_STR("*sequence*: Fossil thermal power produced [MWt]"),
 	NULL},
{"q_from_tes", (getter)Outputs_get_q_from_tes,(setter)0,
	PyDoc_STR("*sequence*: TES thermal energy from storage [MWt]"),
 	NULL},
{"q_gas", (getter)Outputs_get_q_gas,(setter)0,
	PyDoc_STR("*sequence*: Fossil fuel used [MWt]"),
 	NULL},
{"q_hl_sf", (getter)Outputs_get_q_hl_sf,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power loss total [MWt]"),
 	NULL},
{"q_hl_tes", (getter)Outputs_get_q_hl_tes,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses from tank(s) [MWt]"),
 	NULL},
{"q_inc", (getter)Outputs_get_q_inc,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_sf", (getter)Outputs_get_q_sf,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power total produced [MWt]"),
 	NULL},
{"q_startup", (getter)Outputs_get_q_startup,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal startup energy [MWt]"),
 	NULL},
{"q_to_pb", (getter)Outputs_get_q_to_pb,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal power input [MWt]"),
 	NULL},
{"q_to_tes", (getter)Outputs_get_q_to_tes,(setter)0,
	PyDoc_STR("*sequence*: TES thermal energy into storage [MWt]"),
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
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"w_gr", (getter)Outputs_get_w_gr,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (gross) [MWe]"),
 	NULL},
{"w_gr_fossil", (getter)Outputs_get_w_gr_fossil,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (gross, fossil share) [MWe]"),
 	NULL},
{"w_gr_solar", (getter)Outputs_get_w_gr_solar,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (gross, solar share) [MWe]"),
 	NULL},
{"w_par_fixed", (getter)Outputs_get_w_par_fixed,(setter)0,
	PyDoc_STR("*sequence*: Fixed parasitic losses [MWh]"),
 	NULL},
{"w_par_offline", (getter)Outputs_get_w_par_offline,(setter)0,
	PyDoc_STR("*sequence*: Offline parasitics [MWh]"),
 	NULL},
{"w_par_online", (getter)Outputs_get_w_par_online,(setter)0,
	PyDoc_STR("*sequence*: Online parasitics [MWh]"),
 	NULL},
{"w_par_prod", (getter)Outputs_get_w_par_prod,(setter)0,
	PyDoc_STR("*sequence*: Production-based parasitic losses [MWh]"),
 	NULL},
{"w_par_tot", (getter)Outputs_get_w_par_tot,(setter)0,
	PyDoc_STR("*sequence*: Total parasitic losses [MWh]"),
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
		"TcsgenericSolar.Outputs",             /*tp_name*/
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
 * TcsgenericSolar
 */

static PyTypeObject TcsgenericSolar_Type;

static CmodObject *
newTcsgenericSolarObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TcsgenericSolar_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* GenericSolar_obj = GenericSolar_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GenericSolar", GenericSolar_obj);
	Py_DECREF(GenericSolar_obj);

	PyObject* TouTranslator_obj = TouTranslator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TouTranslator", TouTranslator_obj);
	Py_DECREF(TouTranslator_obj);

	PyObject* Type260_obj = Type260_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Type260", Type260_obj);
	Py_DECREF(Type260_obj);

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

/* TcsgenericSolar methods */

static void
TcsgenericSolar_dealloc(CmodObject *self)
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
TcsgenericSolar_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TcsgenericSolar_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcsgenericSolar_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcsgenericSolar"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TcsgenericSolar_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcsgenericSolar"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TcsgenericSolar_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TcsgenericSolar_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TcsgenericSolar_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TcsgenericSolar_methods[] = {
		{"execute",           (PyCFunction)TcsgenericSolar_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcsgenericSolar_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TcsgenericSolar_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TcsgenericSolar_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TcsgenericSolar_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TcsgenericSolar_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcsgenericSolar_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcsgenericSolar_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcsgenericSolar_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TcsgenericSolar_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TcsgenericSolar_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TcsgenericSolar_getattro, /*tp_getattro*/
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
		TcsgenericSolar_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TcsgenericSolar object */

static PyObject *
TcsgenericSolar_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTcsgenericSolarObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsgenericSolar_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsgenericSolarObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsgenericSolar_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsgenericSolarObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsgenericSolar", def) < 0) {
		TcsgenericSolar_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TcsgenericSolar_from_existing(PyObject *self, PyObject *args)
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

	rv = newTcsgenericSolarObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsgenericSolar", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcsgenericSolarModule_methods[] = {
		{"new",             TcsgenericSolar_new,         METH_VARARGS,
				PyDoc_STR("new() -> TcsgenericSolar")},
		{"default",             TcsgenericSolar_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TcsgenericSolar\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"GenericCSPSystemAllEquityPartnershipFlip\"*\n\n		- *\"GenericCSPSystemCommercial\"*\n\n		- *\"GenericCSPSystemLCOECalculator\"*\n\n		- *\"GenericCSPSystemLeveragedPartnershipFlip\"*\n\n		- *\"GenericCSPSystemMerchantPlant\"*\n\n		- *\"GenericCSPSystemNone\"*\n\n		- *\"GenericCSPSystemSaleLeaseback\"*\n\n		- *\"GenericCSPSystemSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TcsgenericSolar_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TcsgenericSolar\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TcsgenericSolar_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TcsgenericSolar\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CSP power system model with solar field characterized using a table of optical efficiency values");


static int
TcsgenericSolarModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TcsgenericSolar_Type.tp_dict = PyDict_New();
	if (!TcsgenericSolar_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TcsgenericSolar_Type
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
	PyDict_SetItemString(TcsgenericSolar_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TcsgenericSolar_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsgenericSolar_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the GenericSolar type object to TcsgenericSolar_Type
	if (PyType_Ready(&GenericSolar_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsgenericSolar_Type.tp_dict,
				"GenericSolar",
				(PyObject*)&GenericSolar_Type);
	Py_DECREF(&GenericSolar_Type);

	/// Add the TouTranslator type object to TcsgenericSolar_Type
	if (PyType_Ready(&TouTranslator_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsgenericSolar_Type.tp_dict,
				"TouTranslator",
				(PyObject*)&TouTranslator_Type);
	Py_DECREF(&TouTranslator_Type);

	/// Add the Type260 type object to TcsgenericSolar_Type
	if (PyType_Ready(&Type260_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsgenericSolar_Type.tp_dict,
				"Type260",
				(PyObject*)&Type260_Type);
	Py_DECREF(&Type260_Type);

	/// Add the Outputs type object to TcsgenericSolar_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsgenericSolar_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TcsgenericSolar type object to the module
	if (PyType_Ready(&TcsgenericSolar_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TcsgenericSolar",
				(PyObject*)&TcsgenericSolar_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TcsgenericSolarModule_slots[] = {
		{Py_mod_exec, TcsgenericSolarModule_exec},
		{0, NULL},
};

static struct PyModuleDef TcsgenericSolarModule = {
		PyModuleDef_HEAD_INIT,
		"TcsgenericSolar",
		module_doc,
		0,
		TcsgenericSolarModule_methods,
		TcsgenericSolarModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TcsgenericSolar(void)
{
	return PyModuleDef_Init(&TcsgenericSolarModule);
}