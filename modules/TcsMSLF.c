#include <Python.h>

#include <SAM_TcsMSLF.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TcsMSLF data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "Weather")){
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
	return PySAM_double_getter(SAM_TcsMSLF_Weather_azimuth_nget, self->data_ptr);
}

static int
Weather_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Weather_azimuth_nset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsMSLF_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsMSLF_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Weather_tilt_nget, self->data_ptr);
}

static int
Weather_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Weather_tilt_nset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Weather_track_mode_nget, self->data_ptr);
}

static int
Weather_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Weather_track_mode_nset, self->data_ptr);
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
		"TcsMSLF.Weather",             /*tp_name*/
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
 * Mslf Group
 */ 

static PyTypeObject Mslf_Type;

static PyObject *
Mslf_new(SAM_TcsMSLF data_ptr)
{
	PyObject* new_obj = Mslf_Type.tp_alloc(&Mslf_Type,0);

	VarGroupObject* Mslf_obj = (VarGroupObject*)new_obj;

	Mslf_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Mslf methods */

static PyObject *
Mslf_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "Mslf")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Mslf_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Mslf_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "Mslf")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Mslf_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Mslf_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Mslf_methods[] = {
		{"assign",            (PyCFunction)Mslf_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Mslf_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Mslf_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Mslf_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Mslf_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Mslf_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Mslf_system_capacity_nget, self->data_ptr);
}

static int
Mslf_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Mslf_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef Mslf_getset[] = {
{"system_capacity", (getter)Mslf_get_system_capacity,(setter)Mslf_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - P_ref\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Mslf_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF.Mslf",             /*tp_name*/
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
		Mslf_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Mslf_getset,          /*tp_getset*/
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
TouTranslator_new(SAM_TcsMSLF data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "TouTranslator")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "TouTranslator")){
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
	return PySAM_matrix_getter(SAM_TcsMSLF_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_TouTranslator_weekend_schedule_mset, self->data_ptr);
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
		"TcsMSLF.TouTranslator",             /*tp_name*/
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
 * Controller Group
 */ 

static PyTypeObject Controller_Type;

static PyObject *
Controller_new(SAM_TcsMSLF data_ptr)
{
	PyObject* new_obj = Controller_Type.tp_alloc(&Controller_Type,0);

	VarGroupObject* Controller_obj = (VarGroupObject*)new_obj;

	Controller_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Controller methods */

static PyObject *
Controller_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "Controller")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controller_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Controller_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "Controller")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controller_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Controller_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Controller_methods[] = {
		{"assign",            (PyCFunction)Controller_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Controller_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Controller_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Controller_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Controller_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Controller_get_A_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_A_aperture_nget, self->data_ptr);
}

static int
Controller_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_A_aperture_nset, self->data_ptr);
}

static PyObject *
Controller_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_AbsorberMaterial_aget, self->data_ptr);
}

static int
Controller_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_AbsorberMaterial_aset, self->data_ptr);
}

static PyObject *
Controller_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_AnnulusGas_aget, self->data_ptr);
}

static int
Controller_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_AnnulusGas_aset, self->data_ptr);
}

static PyObject *
Controller_get_ColAz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_ColAz_nget, self->data_ptr);
}

static int
Controller_set_ColAz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_ColAz_nset, self->data_ptr);
}

static PyObject *
Controller_get_DP_SGS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_DP_SGS_nget, self->data_ptr);
}

static int
Controller_set_DP_SGS(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_DP_SGS_nset, self->data_ptr);
}

static PyObject *
Controller_get_DP_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_DP_coefs_aget, self->data_ptr);
}

static int
Controller_set_DP_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_DP_coefs_aset, self->data_ptr);
}

static PyObject *
Controller_get_DP_nominal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_DP_nominal_nget, self->data_ptr);
}

static int
Controller_set_DP_nominal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_DP_nominal_nset, self->data_ptr);
}

static PyObject *
Controller_get_D_abs_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_D_abs_in_aget, self->data_ptr);
}

static int
Controller_set_D_abs_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_D_abs_in_aset, self->data_ptr);
}

static PyObject *
Controller_get_D_abs_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_D_abs_out_aget, self->data_ptr);
}

static int
Controller_set_D_abs_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_D_abs_out_aset, self->data_ptr);
}

static PyObject *
Controller_get_D_glass_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_D_glass_in_aget, self->data_ptr);
}

static int
Controller_set_D_glass_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_D_glass_in_aset, self->data_ptr);
}

static PyObject *
Controller_get_D_glass_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_D_glass_out_aget, self->data_ptr);
}

static int
Controller_set_D_glass_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_D_glass_out_aset, self->data_ptr);
}

static PyObject *
Controller_get_D_plug(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_D_plug_aget, self->data_ptr);
}

static int
Controller_set_D_plug(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_D_plug_aset, self->data_ptr);
}

static PyObject *
Controller_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_Design_loss_aget, self->data_ptr);
}

static int
Controller_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_Design_loss_aset, self->data_ptr);
}

static PyObject *
Controller_get_Dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_Dirt_mirror_nget, self->data_ptr);
}

static int
Controller_set_Dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_Dirt_mirror_nset, self->data_ptr);
}

static PyObject *
Controller_get_Error(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_Error_nget, self->data_ptr);
}

static int
Controller_set_Error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_Error_nset, self->data_ptr);
}

static PyObject *
Controller_get_FieldConfig(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_FieldConfig_nget, self->data_ptr);
}

static int
Controller_set_FieldConfig(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_FieldConfig_nset, self->data_ptr);
}

static PyObject *
Controller_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_Flow_type_aget, self->data_ptr);
}

static int
Controller_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_Flow_type_aset, self->data_ptr);
}

static PyObject *
Controller_get_Fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_Fluid_nget, self->data_ptr);
}

static int
Controller_set_Fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_Fluid_nset, self->data_ptr);
}

static PyObject *
Controller_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_GeomEffects_nget, self->data_ptr);
}

static int
Controller_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_GeomEffects_nset, self->data_ptr);
}

static PyObject *
Controller_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_GlazingIntactIn_aget, self->data_ptr);
}

static int
Controller_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_GlazingIntactIn_aset, self->data_ptr);
}

static PyObject *
Controller_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_HCE_FieldFrac_aget, self->data_ptr);
}

static int
Controller_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_HCE_FieldFrac_aset, self->data_ptr);
}

static PyObject *
Controller_get_HDR_rough(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_HDR_rough_nget, self->data_ptr);
}

static int
Controller_set_HDR_rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_HDR_rough_nset, self->data_ptr);
}

static PyObject *
Controller_get_HL_T_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_HL_T_coefs_aget, self->data_ptr);
}

static int
Controller_set_HL_T_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_HL_T_coefs_aset, self->data_ptr);
}

static PyObject *
Controller_get_HL_w_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_HL_w_coefs_aget, self->data_ptr);
}

static int
Controller_set_HL_w_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_HL_w_coefs_aset, self->data_ptr);
}

static PyObject *
Controller_get_IAM_L_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_IAM_L_coefs_aget, self->data_ptr);
}

static int
Controller_set_IAM_L_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_IAM_L_coefs_aset, self->data_ptr);
}

static PyObject *
Controller_get_IAM_T_coefs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_IAM_T_coefs_aget, self->data_ptr);
}

static int
Controller_set_IAM_T_coefs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_IAM_T_coefs_aset, self->data_ptr);
}

static PyObject *
Controller_get_I_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_I_b_nget, self->data_ptr);
}

static int
Controller_set_I_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_I_b_nset, self->data_ptr);
}

static PyObject *
Controller_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_I_bn_des_nget, self->data_ptr);
}

static int
Controller_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_I_bn_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_L_crossover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_L_crossover_nget, self->data_ptr);
}

static int
Controller_set_L_crossover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_L_crossover_nset, self->data_ptr);
}

static PyObject *
Controller_get_L_mod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_L_mod_nget, self->data_ptr);
}

static int
Controller_set_L_mod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_L_mod_nset, self->data_ptr);
}

static PyObject *
Controller_get_L_mod_spacing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_L_mod_spacing_nget, self->data_ptr);
}

static int
Controller_set_L_mod_spacing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_L_mod_spacing_nset, self->data_ptr);
}

static PyObject *
Controller_get_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_OpticalTable_mget, self->data_ptr);
}

static int
Controller_set_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Controller_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_P_a_aget, self->data_ptr);
}

static int
Controller_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_P_a_aset, self->data_ptr);
}

static PyObject *
Controller_get_P_amb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_P_amb_nget, self->data_ptr);
}

static int
Controller_set_P_amb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_P_amb_nset, self->data_ptr);
}

static PyObject *
Controller_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_Pipe_hl_coef_nget, self->data_ptr);
}

static int
Controller_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_Rough_aget, self->data_ptr);
}

static int
Controller_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_Rough_aset, self->data_ptr);
}

static PyObject *
Controller_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_SCA_drives_elec_nget, self->data_ptr);
}

static int
Controller_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
Controller_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_Shadowing_aget, self->data_ptr);
}

static int
Controller_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_Shadowing_aset, self->data_ptr);
}

static PyObject *
Controller_get_T_amb_sf_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_amb_sf_des_nget, self->data_ptr);
}

static int
Controller_set_T_amb_sf_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_amb_sf_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_cold_in_nget, self->data_ptr);
}

static int
Controller_set_T_cold_in(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_cold_in_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_db(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_db_nget, self->data_ptr);
}

static int
Controller_set_T_db(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_db_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_dp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_dp_nget, self->data_ptr);
}

static int
Controller_set_T_dp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_dp_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_field_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_field_in_des_nget, self->data_ptr);
}

static int
Controller_set_T_field_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_field_in_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_field_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_field_ini_nget, self->data_ptr);
}

static int
Controller_set_T_field_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_field_ini_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_field_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_field_out_des_nget, self->data_ptr);
}

static int
Controller_set_T_field_out_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_field_out_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_fp_nget, self->data_ptr);
}

static int
Controller_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_fp_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_loop_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_loop_in_des_nget, self->data_ptr);
}

static int
Controller_set_T_loop_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_loop_out_nget, self->data_ptr);
}

static int
Controller_set_T_loop_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_loop_out_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_set_aux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_set_aux_nget, self->data_ptr);
}

static int
Controller_set_T_set_aux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_set_aux_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_startup_nget, self->data_ptr);
}

static int
Controller_set_T_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_startup_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_cold_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_tank_cold_ini_nget, self->data_ptr);
}

static int
Controller_set_T_tank_cold_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_tank_cold_ini_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_hot_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_tank_hot_ini_nget, self->data_ptr);
}

static int
Controller_set_T_tank_hot_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_tank_hot_ini_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_hot_inlet_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_T_tank_hot_inlet_min_nget, self->data_ptr);
}

static int
Controller_set_T_tank_hot_inlet_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_T_tank_hot_inlet_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_Tau_envelope_aget, self->data_ptr);
}

static int
Controller_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_Tau_envelope_aset, self->data_ptr);
}

static PyObject *
Controller_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_TrackingError_nget, self->data_ptr);
}

static int
Controller_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_TrackingError_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_hdr_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_V_hdr_max_nget, self->data_ptr);
}

static int
Controller_set_V_hdr_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_V_hdr_max_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_hdr_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_V_hdr_min_nget, self->data_ptr);
}

static int
Controller_set_V_hdr_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_V_hdr_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_tank_hot_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_V_tank_hot_ini_nget, self->data_ptr);
}

static int
Controller_set_V_tank_hot_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_V_tank_hot_ini_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_tes_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_V_tes_des_nget, self->data_ptr);
}

static int
Controller_set_V_tes_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_V_tes_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_wind(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_V_wind_nget, self->data_ptr);
}

static int
Controller_set_V_wind(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_V_wind_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_wind_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_V_wind_des_nget, self->data_ptr);
}

static int
Controller_set_V_wind_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_V_wind_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_W_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_W_pb_design_nget, self->data_ptr);
}

static int
Controller_set_W_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_W_pb_design_nset, self->data_ptr);
}

static PyObject *
Controller_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_alpha_abs_aget, self->data_ptr);
}

static int
Controller_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_alpha_abs_aset, self->data_ptr);
}

static PyObject *
Controller_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_alpha_env_aget, self->data_ptr);
}

static int
Controller_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_alpha_env_aset, self->data_ptr);
}

static PyObject *
Controller_get_aux_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_aux_array_aget, self->data_ptr);
}

static int
Controller_set_aux_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_aux_array_aset, self->data_ptr);
}

static PyObject *
Controller_get_bop_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_bop_array_aget, self->data_ptr);
}

static int
Controller_set_bop_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_bop_array_aset, self->data_ptr);
}

static PyObject *
Controller_get_calc_design_pipe_vals(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_calc_design_pipe_vals_nget, self->data_ptr);
}

static int
Controller_set_calc_design_pipe_vals(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_calc_design_pipe_vals_nset, self->data_ptr);
}

static PyObject *
Controller_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_cold_tank_Thtr_nget, self->data_ptr);
}

static int
Controller_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_sgs_pipe_sizes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_custom_sgs_pipe_sizes_nget, self->data_ptr);
}

static int
Controller_set_custom_sgs_pipe_sizes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_custom_sgs_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_p_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_custom_tes_p_loss_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_p_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_custom_tes_p_loss_nset, self->data_ptr);
}

static PyObject *
Controller_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
Controller_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
Controller_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_cycle_max_frac_nget, self->data_ptr);
}

static int
Controller_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
Controller_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_defocus_nget, self->data_ptr);
}

static int
Controller_set_defocus(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_defocus_nset, self->data_ptr);
}

static PyObject *
Controller_get_dirt_env(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_dirt_env_aget, self->data_ptr);
}

static int
Controller_set_dirt_env(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_dirt_env_aset, self->data_ptr);
}

static PyObject *
Controller_get_dt_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_dt_cold_nget, self->data_ptr);
}

static int
Controller_set_dt_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_dt_cold_nset, self->data_ptr);
}

static PyObject *
Controller_get_dt_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_dt_hot_nget, self->data_ptr);
}

static int
Controller_set_dt_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_dt_hot_nset, self->data_ptr);
}

static PyObject *
Controller_get_epsilon_abs_1(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_epsilon_abs_1_mget, self->data_ptr);
}

static int
Controller_set_epsilon_abs_1(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_epsilon_abs_1_mset, self->data_ptr);
}

static PyObject *
Controller_get_epsilon_abs_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_epsilon_abs_2_mget, self->data_ptr);
}

static int
Controller_set_epsilon_abs_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_epsilon_abs_2_mset, self->data_ptr);
}

static PyObject *
Controller_get_epsilon_abs_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_epsilon_abs_3_mget, self->data_ptr);
}

static int
Controller_set_epsilon_abs_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_epsilon_abs_3_mset, self->data_ptr);
}

static PyObject *
Controller_get_epsilon_abs_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_epsilon_abs_4_mget, self->data_ptr);
}

static int
Controller_set_epsilon_abs_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_epsilon_abs_4_mset, self->data_ptr);
}

static PyObject *
Controller_get_epsilon_glass(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_epsilon_glass_aget, self->data_ptr);
}

static int
Controller_set_epsilon_glass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_epsilon_glass_aset, self->data_ptr);
}

static PyObject *
Controller_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_eta_pump_nget, self->data_ptr);
}

static int
Controller_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_eta_pump_nset, self->data_ptr);
}

static PyObject *
Controller_get_f_tc_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_f_tc_cold_nget, self->data_ptr);
}

static int
Controller_set_f_tc_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_f_tc_cold_nset, self->data_ptr);
}

static PyObject *
Controller_get_fc_on(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_fc_on_nget, self->data_ptr);
}

static int
Controller_set_fc_on(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_fc_on_nset, self->data_ptr);
}

static PyObject *
Controller_get_ffrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_ffrac_aget, self->data_ptr);
}

static int
Controller_set_ffrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_ffrac_aset, self->data_ptr);
}

static PyObject *
Controller_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_field_fl_props_mget, self->data_ptr);
}

static int
Controller_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_field_fl_props_mset, self->data_ptr);
}

static PyObject *
Controller_get_field_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_field_fluid_nget, self->data_ptr);
}

static int
Controller_set_field_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_field_fluid_nset, self->data_ptr);
}

static PyObject *
Controller_get_fossil_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_fossil_mode_nget, self->data_ptr);
}

static int
Controller_set_fossil_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_fossil_mode_nset, self->data_ptr);
}

static PyObject *
Controller_get_fthr_ok(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_fthr_ok_nget, self->data_ptr);
}

static int
Controller_set_fthr_ok(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_fthr_ok_nset, self->data_ptr);
}

static PyObject *
Controller_get_fthrctrl(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_fthrctrl_nget, self->data_ptr);
}

static int
Controller_set_fthrctrl(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_fthrctrl_nset, self->data_ptr);
}

static PyObject *
Controller_get_fthrok(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_fthrok_nget, self->data_ptr);
}

static int
Controller_set_fthrok(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_fthrok_nset, self->data_ptr);
}

static PyObject *
Controller_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_h_tank_nget, self->data_ptr);
}

static int
Controller_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_h_tank_nset, self->data_ptr);
}

static PyObject *
Controller_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_h_tank_min_nget, self->data_ptr);
}

static int
Controller_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_h_tank_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_has_hot_tank_bypass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_has_hot_tank_bypass_nget, self->data_ptr);
}

static int
Controller_set_has_hot_tank_bypass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_has_hot_tank_bypass_nset, self->data_ptr);
}

static PyObject *
Controller_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_hot_tank_Thtr_nget, self->data_ptr);
}

static int
Controller_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
Controller_get_hx_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_hx_config_nget, self->data_ptr);
}

static int
Controller_set_hx_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_hx_config_nset, self->data_ptr);
}

static PyObject *
Controller_get_is_hx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_is_hx_nget, self->data_ptr);
}

static int
Controller_set_is_hx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_is_hx_nset, self->data_ptr);
}

static PyObject *
Controller_get_k_tes_loss_coeffs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_k_tes_loss_coeffs_aget, self->data_ptr);
}

static int
Controller_set_k_tes_loss_coeffs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_k_tes_loss_coeffs_aset, self->data_ptr);
}

static PyObject *
Controller_get_m_dot_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_m_dot_htfmax_nget, self->data_ptr);
}

static int
Controller_set_m_dot_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_m_dot_htfmax_nset, self->data_ptr);
}

static PyObject *
Controller_get_m_dot_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_m_dot_htfmin_nget, self->data_ptr);
}

static int
Controller_set_m_dot_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_m_dot_htfmin_nset, self->data_ptr);
}

static PyObject *
Controller_get_mc_bal_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_mc_bal_cold_nget, self->data_ptr);
}

static int
Controller_set_mc_bal_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_mc_bal_cold_nset, self->data_ptr);
}

static PyObject *
Controller_get_mc_bal_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_mc_bal_hot_nget, self->data_ptr);
}

static int
Controller_set_mc_bal_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_mc_bal_hot_nset, self->data_ptr);
}

static PyObject *
Controller_get_mc_bal_sca(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_mc_bal_sca_nget, self->data_ptr);
}

static int
Controller_set_mc_bal_sca(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_mc_bal_sca_nset, self->data_ptr);
}

static PyObject *
Controller_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_nLoops_nget, self->data_ptr);
}

static int
Controller_set_nLoops(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_nLoops_nset, self->data_ptr);
}

static PyObject *
Controller_get_nMod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_nMod_nget, self->data_ptr);
}

static int
Controller_set_nMod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_nMod_nset, self->data_ptr);
}

static PyObject *
Controller_get_nRecVar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_nRecVar_nget, self->data_ptr);
}

static int
Controller_set_nRecVar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_nRecVar_nset, self->data_ptr);
}

static PyObject *
Controller_get_nSCA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_nSCA_nget, self->data_ptr);
}

static int
Controller_set_nSCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_nSCA_nset, self->data_ptr);
}

static PyObject *
Controller_get_nodes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_nodes_nget, self->data_ptr);
}

static int
Controller_set_nodes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_nodes_nset, self->data_ptr);
}

static PyObject *
Controller_get_opt_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_opt_model_nget, self->data_ptr);
}

static int
Controller_set_opt_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_opt_model_nset, self->data_ptr);
}

static PyObject *
Controller_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_pb_fixed_par_nget, self->data_ptr);
}

static int
Controller_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
Controller_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_pb_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_pb_rated_cap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_pb_rated_cap_nget, self->data_ptr);
}

static int
Controller_set_pb_rated_cap(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_pb_rated_cap_nset, self->data_ptr);
}

static PyObject *
Controller_get_q_max_aux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_q_max_aux_nget, self->data_ptr);
}

static int
Controller_set_q_max_aux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_q_max_aux_nset, self->data_ptr);
}

static PyObject *
Controller_get_q_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_q_pb_design_nget, self->data_ptr);
}

static int
Controller_set_q_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_q_pb_design_nset, self->data_ptr);
}

static PyObject *
Controller_get_rec_htf_vol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_rec_htf_vol_nget, self->data_ptr);
}

static int
Controller_set_rec_htf_vol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_rec_htf_vol_nset, self->data_ptr);
}

static PyObject *
Controller_get_rec_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_rec_model_nget, self->data_ptr);
}

static int
Controller_set_rec_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_rec_model_nset, self->data_ptr);
}

static PyObject *
Controller_get_reflectivity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_reflectivity_nget, self->data_ptr);
}

static int
Controller_set_reflectivity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_reflectivity_nset, self->data_ptr);
}

static PyObject *
Controller_get_sgs_diams(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_sgs_diams_aget, self->data_ptr);
}

static int
Controller_set_sgs_diams(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_sgs_diams_aset, self->data_ptr);
}

static PyObject *
Controller_get_sgs_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_sgs_lengths_aget, self->data_ptr);
}

static int
Controller_set_sgs_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_sgs_lengths_aset, self->data_ptr);
}

static PyObject *
Controller_get_sgs_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_sgs_wallthicks_aget, self->data_ptr);
}

static int
Controller_set_sgs_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_sgs_wallthicks_aset, self->data_ptr);
}

static PyObject *
Controller_get_solar_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_solar_mult_nget, self->data_ptr);
}

static int
Controller_set_solar_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_solar_mult_nset, self->data_ptr);
}

static PyObject *
Controller_get_solarm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_solarm_nget, self->data_ptr);
}

static int
Controller_set_solarm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_solarm_nset, self->data_ptr);
}

static PyObject *
Controller_get_store_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Controller_store_fl_props_mget, self->data_ptr);
}

static int
Controller_set_store_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_Controller_store_fl_props_mset, self->data_ptr);
}

static PyObject *
Controller_get_store_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_store_fluid_nget, self->data_ptr);
}

static int
Controller_set_store_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_store_fluid_nset, self->data_ptr);
}

static PyObject *
Controller_get_t_ch_out_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_t_ch_out_max_nget, self->data_ptr);
}

static int
Controller_set_t_ch_out_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_t_ch_out_max_nset, self->data_ptr);
}

static PyObject *
Controller_get_t_dis_out_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_t_dis_out_min_nget, self->data_ptr);
}

static int
Controller_set_t_dis_out_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_t_dis_out_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_t_standby_reset(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_t_standby_reset_nget, self->data_ptr);
}

static int
Controller_set_t_standby_reset(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_t_standby_reset_nset, self->data_ptr);
}

static PyObject *
Controller_get_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tank_max_heat_nget, self->data_ptr);
}

static int
Controller_set_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
Controller_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tank_pairs_nget, self->data_ptr);
}

static int
Controller_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tank_pairs_nset, self->data_ptr);
}

static PyObject *
Controller_get_tanks_in_parallel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tanks_in_parallel_nget, self->data_ptr);
}

static int
Controller_set_tanks_in_parallel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tanks_in_parallel_nset, self->data_ptr);
}

static PyObject *
Controller_get_tc_fill(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tc_fill_nget, self->data_ptr);
}

static int
Controller_set_tc_fill(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tc_fill_nset, self->data_ptr);
}

static PyObject *
Controller_get_tc_void(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tc_void_nget, self->data_ptr);
}

static int
Controller_set_tc_void(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tc_void_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tes_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_tes_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tes_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tes_temp_nget, self->data_ptr);
}

static int
Controller_set_tes_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tes_temp_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tes_type_nget, self->data_ptr);
}

static int
Controller_set_tes_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tes_type_nset, self->data_ptr);
}

static PyObject *
Controller_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_theta_dep_nget, self->data_ptr);
}

static int
Controller_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_theta_dep_nset, self->data_ptr);
}

static PyObject *
Controller_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_theta_stow_nget, self->data_ptr);
}

static int
Controller_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_theta_stow_nset, self->data_ptr);
}

static PyObject *
Controller_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_tshours_nget, self->data_ptr);
}

static int
Controller_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_tshours_nset, self->data_ptr);
}

static PyObject *
Controller_get_tslogic_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_tslogic_a_aget, self->data_ptr);
}

static int
Controller_set_tslogic_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_tslogic_a_aset, self->data_ptr);
}

static PyObject *
Controller_get_tslogic_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_tslogic_b_aget, self->data_ptr);
}

static int
Controller_set_tslogic_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_tslogic_b_aset, self->data_ptr);
}

static PyObject *
Controller_get_tslogic_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Controller_tslogic_c_aget, self->data_ptr);
}

static int
Controller_set_tslogic_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Controller_tslogic_c_aset, self->data_ptr);
}

static PyObject *
Controller_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_u_tank_nget, self->data_ptr);
}

static int
Controller_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_u_tank_nset, self->data_ptr);
}

static PyObject *
Controller_get_vol_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Controller_vol_tank_nget, self->data_ptr);
}

static int
Controller_set_vol_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Controller_vol_tank_nset, self->data_ptr);
}

static PyGetSetDef Controller_getset[] = {
{"A_aperture", (getter)Controller_get_A_aperture,(setter)Controller_set_A_aperture,
	PyDoc_STR("*float*: Reflective aperture area of the collector [m2]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``A_aperture``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"AbsorberMaterial", (getter)Controller_get_AbsorberMaterial,(setter)Controller_set_AbsorberMaterial,
	PyDoc_STR("*sequence*: Absorber material type\n\n**Required:**\nTrue"),
 	NULL},
{"AnnulusGas", (getter)Controller_get_AnnulusGas,(setter)Controller_set_AnnulusGas,
	PyDoc_STR("*sequence*: Annulus gas type (1=air; 26=Ar; 27=H2)\n\n**Required:**\nTrue"),
 	NULL},
{"ColAz", (getter)Controller_get_ColAz,(setter)Controller_set_ColAz,
	PyDoc_STR("*float*: Collector azimuth angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"DP_SGS", (getter)Controller_get_DP_SGS,(setter)Controller_set_DP_SGS,
	PyDoc_STR("*float*: Pressure drop within the steam generator [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"DP_coefs", (getter)Controller_get_DP_coefs,(setter)Controller_set_DP_coefs,
	PyDoc_STR("*sequence*: Pressure drop mass flow based part-load curve\n\n**Required:**\nTrue"),
 	NULL},
{"DP_nominal", (getter)Controller_get_DP_nominal,(setter)Controller_set_DP_nominal,
	PyDoc_STR("*float*: Pressure drop across a single collector assembly at design [bar]\n\n**Required:**\nTrue"),
 	NULL},
{"D_abs_in", (getter)Controller_get_D_abs_in,(setter)Controller_set_D_abs_in,
	PyDoc_STR("*sequence*: The inner absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_abs_out", (getter)Controller_get_D_abs_out,(setter)Controller_set_D_abs_out,
	PyDoc_STR("*sequence*: The outer absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_glass_in", (getter)Controller_get_D_glass_in,(setter)Controller_set_D_glass_in,
	PyDoc_STR("*sequence*: The inner glass envelope diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_glass_out", (getter)Controller_get_D_glass_out,(setter)Controller_set_D_glass_out,
	PyDoc_STR("*sequence*: The outer glass envelope diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_plug", (getter)Controller_get_D_plug,(setter)Controller_set_D_plug,
	PyDoc_STR("*sequence*: The diameter of the absorber flow plug (optional) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Design_loss", (getter)Controller_get_Design_loss,(setter)Controller_set_Design_loss,
	PyDoc_STR("*sequence*: Receiver heat loss at design [W/m]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_mirror", (getter)Controller_get_Dirt_mirror,(setter)Controller_set_Dirt_mirror,
	PyDoc_STR("*float*: User-defined dirt on mirror derate\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``Dirt_mirror``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"Error", (getter)Controller_get_Error,(setter)Controller_set_Error,
	PyDoc_STR("*float*: User-defined general optical error derate\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``Error``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"FieldConfig", (getter)Controller_get_FieldConfig,(setter)Controller_set_FieldConfig,
	PyDoc_STR("*float*: Number of subfield headers\n\n**Required:**\nTrue"),
 	NULL},
{"Flow_type", (getter)Controller_get_Flow_type,(setter)Controller_set_Flow_type,
	PyDoc_STR("*sequence*: The flow type through the absorber\n\n**Required:**\nTrue"),
 	NULL},
{"Fluid", (getter)Controller_get_Fluid,(setter)Controller_set_Fluid,
	PyDoc_STR("*float*: Field HTF fluid number\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``Fluid``:\n\n\t - field_fluid\n\t - is_hx\n"),
 	NULL},
{"GeomEffects", (getter)Controller_get_GeomEffects,(setter)Controller_set_GeomEffects,
	PyDoc_STR("*float*: Geometry effects derate\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``GeomEffects``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"GlazingIntactIn", (getter)Controller_get_GlazingIntactIn,(setter)Controller_set_GlazingIntactIn,
	PyDoc_STR("*sequence*: The glazing intact flag\n\n**Required:**\nTrue"),
 	NULL},
{"HCE_FieldFrac", (getter)Controller_get_HCE_FieldFrac,(setter)Controller_set_HCE_FieldFrac,
	PyDoc_STR("*sequence*: The fraction of the field occupied by this HCE type\n\n**Required:**\nTrue"),
 	NULL},
{"HDR_rough", (getter)Controller_get_HDR_rough,(setter)Controller_set_HDR_rough,
	PyDoc_STR("*float*: Header pipe roughness [m]\n\n**Required:**\nTrue"),
 	NULL},
{"HL_T_coefs", (getter)Controller_get_HL_T_coefs,(setter)Controller_set_HL_T_coefs,
	PyDoc_STR("*sequence*: HTF temperature-dependent heat loss coefficients [W/m-K]\n\n**Required:**\nTrue"),
 	NULL},
{"HL_w_coefs", (getter)Controller_get_HL_w_coefs,(setter)Controller_set_HL_w_coefs,
	PyDoc_STR("*sequence*: Wind-speed-dependent heat loss coefficients [W/m-(m/s)]\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_L_coefs", (getter)Controller_get_IAM_L_coefs,(setter)Controller_set_IAM_L_coefs,
	PyDoc_STR("*sequence*: Incidence angle modifier coefficients - longitudinal plane\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_T_coefs", (getter)Controller_get_IAM_T_coefs,(setter)Controller_set_IAM_T_coefs,
	PyDoc_STR("*sequence*: Incidence angle modifier coefficients - transversal plane\n\n**Required:**\nTrue"),
 	NULL},
{"I_b", (getter)Controller_get_I_b,(setter)Controller_set_I_b,
	PyDoc_STR("*float*: Direct normal incident solar irradiation [kJ/m2-hr]\n\n**Required:**\nTrue"),
 	NULL},
{"I_bn_des", (getter)Controller_get_I_bn_des,(setter)Controller_set_I_bn_des,
	PyDoc_STR("*float*: Solar irradiation at design [W/m2]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``I_bn_des``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"L_crossover", (getter)Controller_get_L_crossover,(setter)Controller_set_L_crossover,
	PyDoc_STR("*float*: Length of crossover piping in a loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_mod", (getter)Controller_get_L_mod,(setter)Controller_set_L_mod,
	PyDoc_STR("*float*: The length of the collector module [m]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``L_mod``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"L_mod_spacing", (getter)Controller_get_L_mod_spacing,(setter)Controller_set_L_mod_spacing,
	PyDoc_STR("*float*: Piping distance between sequential modules in a loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"OpticalTable", (getter)Controller_get_OpticalTable,(setter)Controller_set_OpticalTable,
	PyDoc_STR("*sequence[sequence]*: Values of the optical efficiency table\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)Controller_get_P_a,(setter)Controller_set_P_a,
	PyDoc_STR("*sequence*: Annulus gas pressure [torr]\n\n**Required:**\nTrue"),
 	NULL},
{"P_amb", (getter)Controller_get_P_amb,(setter)Controller_set_P_amb,
	PyDoc_STR("*float*: Ambient pressure [atm]\n\n**Required:**\nTrue"),
 	NULL},
{"Pipe_hl_coef", (getter)Controller_get_Pipe_hl_coef,(setter)Controller_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header - runner pipe - and non-HCE piping [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
{"Rough", (getter)Controller_get_Rough,(setter)Controller_set_Rough,
	PyDoc_STR("*sequence*: Roughness of the internal surface [m]\n\n**Required:**\nTrue"),
 	NULL},
{"SCA_drives_elec", (getter)Controller_get_SCA_drives_elec,(setter)Controller_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power in Watts per SCA drive [W/module]\n\n**Required:**\nTrue"),
 	NULL},
{"Shadowing", (getter)Controller_get_Shadowing,(setter)Controller_set_Shadowing,
	PyDoc_STR("*sequence*: Receiver bellows shadowing loss factor\n\n**Required:**\nTrue"),
 	NULL},
{"T_amb_sf_des", (getter)Controller_get_T_amb_sf_des,(setter)Controller_set_T_amb_sf_des,
	PyDoc_STR("*float*: Ambient design-point temperature for the solar field [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_amb_sf_des``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"T_cold_in", (getter)Controller_get_T_cold_in,(setter)Controller_set_T_cold_in,
	PyDoc_STR("*float*: HTF return temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_db", (getter)Controller_get_T_db,(setter)Controller_set_T_db,
	PyDoc_STR("*float*: Dry bulb air temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_dp", (getter)Controller_get_T_dp,(setter)Controller_set_T_dp,
	PyDoc_STR("*float*: The dewpoint temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_field_in_des", (getter)Controller_get_T_field_in_des,(setter)Controller_set_T_field_in_des,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``T_field_in_des`` depends on the following variables:\n\n\t - T_loop_in_des\n"),
 	NULL},
{"T_field_ini", (getter)Controller_get_T_field_ini,(setter)Controller_set_T_field_ini,
	PyDoc_STR("*float*: Initial field temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_field_out_des", (getter)Controller_get_T_field_out_des,(setter)Controller_set_T_field_out_des,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``T_field_out_des`` depends on the following variables:\n\n\t - T_loop_out\n"),
 	NULL},
{"T_fp", (getter)Controller_get_T_fp,(setter)Controller_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_in_des", (getter)Controller_get_T_loop_in_des,(setter)Controller_set_T_loop_in_des,
	PyDoc_STR("*float*: Design loop inlet temperature [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_loop_in_des``:\n\n\t - T_field_in_des\n\t - T_htf_cold_ref\n\t - T_tank_cold_ini\n\t - V_tank_hot_ini\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n\t - tes_temp\n\t - vol_tank\n"),
 	NULL},
{"T_loop_out", (getter)Controller_get_T_loop_out,(setter)Controller_set_T_loop_out,
	PyDoc_STR("*float*: Target loop outlet temperature [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_loop_out``:\n\n\t - T_field_out_des\n\t - T_htf_hot_ref\n\t - T_tank_hot_ini\n\t - V_tank_hot_ini\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n\t - tes_temp\n\t - vol_tank\n"),
 	NULL},
{"T_set_aux", (getter)Controller_get_T_set_aux,(setter)Controller_set_T_set_aux,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"T_startup", (getter)Controller_get_T_startup,(setter)Controller_set_T_startup,
	PyDoc_STR("*float*: Power block startup temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_tank_cold_ini", (getter)Controller_get_T_tank_cold_ini,(setter)Controller_set_T_tank_cold_ini,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``T_tank_cold_ini`` depends on the following variables:\n\n\t - T_loop_in_des\n"),
 	NULL},
{"T_tank_hot_ini", (getter)Controller_get_T_tank_hot_ini,(setter)Controller_set_T_tank_hot_ini,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``T_tank_hot_ini`` depends on the following variables:\n\n\t - T_loop_out\n"),
 	NULL},
{"T_tank_hot_inlet_min", (getter)Controller_get_T_tank_hot_inlet_min,(setter)Controller_set_T_tank_hot_inlet_min,
	PyDoc_STR("*float*: Minimum hot tank htf inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"Tau_envelope", (getter)Controller_get_Tau_envelope,(setter)Controller_set_Tau_envelope,
	PyDoc_STR("*sequence*: Envelope transmittance\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)Controller_get_TrackingError,(setter)Controller_set_TrackingError,
	PyDoc_STR("*float*: Tracking error derate\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``TrackingError``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"V_hdr_max", (getter)Controller_get_V_hdr_max,(setter)Controller_set_V_hdr_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the header at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_min", (getter)Controller_get_V_hdr_min,(setter)Controller_set_V_hdr_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the header at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_tank_hot_ini", (getter)Controller_get_V_tank_hot_ini,(setter)Controller_set_V_tank_hot_ini,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``V_tank_hot_ini`` depends on the following variables:\n\n\t - P_ref\n\t - T_loop_in_des\n\t - T_loop_out\n\t - dt_cold\n\t - dt_hot\n\t - eta_ref\n\t - store_fl_props\n\t - tes_temp\n\t - tshours\n\t - vol_tank\n"),
 	NULL},
{"V_tes_des", (getter)Controller_get_V_tes_des,(setter)Controller_set_V_tes_des,
	PyDoc_STR("*float*: Design-point velocity to size the TES pipe diameters [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_wind", (getter)Controller_get_V_wind,(setter)Controller_set_V_wind,
	PyDoc_STR("*float*: Ambient windspeed [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_wind_des", (getter)Controller_get_V_wind_des,(setter)Controller_set_V_wind_des,
	PyDoc_STR("*float*: Design-point wind velocity [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"W_pb_design", (getter)Controller_get_W_pb_design,(setter)Controller_set_W_pb_design,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``W_pb_design`` depends on the following variables:\n\n\t - P_ref\n"),
 	NULL},
{"alpha_abs", (getter)Controller_get_alpha_abs,(setter)Controller_set_alpha_abs,
	PyDoc_STR("*sequence*: Absorber absorptance\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_env", (getter)Controller_get_alpha_env,(setter)Controller_set_alpha_env,
	PyDoc_STR("*sequence*: Envelope absorptance\n\n**Required:**\nTrue"),
 	NULL},
{"aux_array", (getter)Controller_get_aux_array,(setter)Controller_set_aux_array,
	PyDoc_STR("*sequence*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"bop_array", (getter)Controller_get_bop_array,(setter)Controller_set_bop_array,
	PyDoc_STR("*sequence*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"calc_design_pipe_vals", (getter)Controller_get_calc_design_pipe_vals,(setter)Controller_set_calc_design_pipe_vals,
	PyDoc_STR("*float*: Calculate temps and pressures at design conditions for runners and headers [-]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_Thtr", (getter)Controller_get_cold_tank_Thtr,(setter)Controller_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"custom_sgs_pipe_sizes", (getter)Controller_get_custom_sgs_pipe_sizes,(setter)Controller_set_custom_sgs_pipe_sizes,
	PyDoc_STR("*float*: Use custom SGS pipe diams, wallthks, and lengths [-]\n\n**Required:**\nTrue"),
 	NULL},
{"custom_tes_p_loss", (getter)Controller_get_custom_tes_p_loss,(setter)Controller_set_custom_tes_p_loss,
	PyDoc_STR("*float*: TES pipe losses are based on custom lengths and coeffs [-]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_cutoff_frac", (getter)Controller_get_cycle_cutoff_frac,(setter)Controller_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_max_frac", (getter)Controller_get_cycle_max_frac,(setter)Controller_set_cycle_max_frac,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"defocus", (getter)Controller_get_defocus,(setter)Controller_set_defocus,
	PyDoc_STR("*float*: Defocus control\n\n**Required:**\nTrue"),
 	NULL},
{"dirt_env", (getter)Controller_get_dirt_env,(setter)Controller_set_dirt_env,
	PyDoc_STR("*sequence*: Loss due to dirt on the receiver envelope\n\n**Required:**\nTrue"),
 	NULL},
{"dt_cold", (getter)Controller_get_dt_cold,(setter)Controller_set_dt_cold,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``dt_cold``:\n\n\t - V_tank_hot_ini\n\t - vol_tank\n\n\nThe value of ``dt_cold`` depends on the following variables:\n\n\t - dt_hot\n"),
 	NULL},
{"dt_hot", (getter)Controller_get_dt_hot,(setter)Controller_set_dt_hot,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``dt_hot``:\n\n\t - V_tank_hot_ini\n\t - dt_cold\n\t - vol_tank\n"),
 	NULL},
{"epsilon_abs_1", (getter)Controller_get_epsilon_abs_1,(setter)Controller_set_epsilon_abs_1,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 1\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_2", (getter)Controller_get_epsilon_abs_2,(setter)Controller_set_epsilon_abs_2,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 2\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_3", (getter)Controller_get_epsilon_abs_3,(setter)Controller_set_epsilon_abs_3,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 3\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_abs_4", (getter)Controller_get_epsilon_abs_4,(setter)Controller_set_epsilon_abs_4,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance - HCE variation 4\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_glass", (getter)Controller_get_epsilon_glass,(setter)Controller_set_epsilon_glass,
	PyDoc_STR("*sequence*: Glass envelope emissivity\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)Controller_get_eta_pump,(setter)Controller_set_eta_pump,
	PyDoc_STR("*float*: HTF pump efficiency\n\n**Required:**\nTrue"),
 	NULL},
{"f_tc_cold", (getter)Controller_get_f_tc_cold,(setter)Controller_set_f_tc_cold,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"fc_on", (getter)Controller_get_fc_on,(setter)Controller_set_fc_on,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"ffrac", (getter)Controller_get_ffrac,(setter)Controller_set_ffrac,
	PyDoc_STR("*sequence*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"field_fl_props", (getter)Controller_get_field_fl_props,(setter)Controller_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: Fluid property data\n\n**Required:**\nTrue"),
 	NULL},
{"field_fluid", (getter)Controller_get_field_fluid,(setter)Controller_set_field_fluid,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``field_fluid`` depends on the following variables:\n\n\t - Fluid\n"),
 	NULL},
{"fossil_mode", (getter)Controller_get_fossil_mode,(setter)Controller_set_fossil_mode,
	PyDoc_STR("*float*: Label\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"fthr_ok", (getter)Controller_get_fthr_ok,(setter)Controller_set_fthr_ok,
	PyDoc_STR("*float*: Label\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of ``fthr_ok`` depends on the following variables:\n\n\t - fthrok\n"),
 	NULL},
{"fthrctrl", (getter)Controller_get_fthrctrl,(setter)Controller_set_fthrctrl,
	PyDoc_STR("*float*: Defocusing strategy\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"fthrok", (getter)Controller_get_fthrok,(setter)Controller_set_fthrok,
	PyDoc_STR("*float*: Flag to allow partial defocusing of the collectors\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``fthrok``:\n\n\t - fthr_ok\n"),
 	NULL},
{"h_tank", (getter)Controller_get_h_tank,(setter)Controller_set_h_tank,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank_min", (getter)Controller_get_h_tank_min,(setter)Controller_set_h_tank_min,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"has_hot_tank_bypass", (getter)Controller_get_has_hot_tank_bypass,(setter)Controller_set_has_hot_tank_bypass,
	PyDoc_STR("*float*: Bypass valve connects field outlet to cold tank [-]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_Thtr", (getter)Controller_get_hot_tank_Thtr,(setter)Controller_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"hx_config", (getter)Controller_get_hx_config,(setter)Controller_set_hx_config,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"is_hx", (getter)Controller_get_is_hx,(setter)Controller_set_is_hx,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``is_hx`` depends on the following variables:\n\n\t - Fluid\n\t - store_fluid\n"),
 	NULL},
{"k_tes_loss_coeffs", (getter)Controller_get_k_tes_loss_coeffs,(setter)Controller_set_k_tes_loss_coeffs,
	PyDoc_STR("*sequence*: Minor loss coeffs for the coll, gen, and bypass loops [-]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htfmax", (getter)Controller_get_m_dot_htfmax,(setter)Controller_set_m_dot_htfmax,
	PyDoc_STR("*float*: Maximum loop HTF flow rate [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htfmin", (getter)Controller_get_m_dot_htfmin,(setter)Controller_set_m_dot_htfmin,
	PyDoc_STR("*float*: Minimum loop HTF flow rate [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_cold", (getter)Controller_get_mc_bal_cold,(setter)Controller_set_mc_bal_cold,
	PyDoc_STR("*float*: The heat capacity of the balance of plant on the cold side [kWht/K-MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_hot", (getter)Controller_get_mc_bal_hot,(setter)Controller_set_mc_bal_hot,
	PyDoc_STR("*float*: The heat capacity of the balance of plant on the hot side [kWht/K-MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_sca", (getter)Controller_get_mc_bal_sca,(setter)Controller_set_mc_bal_sca,
	PyDoc_STR("*float*: Non-HTF heat capacity associated with each SCA - per meter basis [Wht/K-m]\n\n**Required:**\nTrue"),
 	NULL},
{"nLoops", (getter)Controller_get_nLoops,(setter)Controller_set_nLoops,
	PyDoc_STR("*float*: Number of loops in the field\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nLoops``:\n\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n\n\nThe value of ``nLoops`` depends on the following variables:\n\n\t - A_aperture\n\t - Dirt_mirror\n\t - Error\n\t - GeomEffects\n\t - I_bn_des\n\t - L_mod\n\t - P_ref\n\t - T_amb_sf_des\n\t - T_loop_in_des\n\t - T_loop_out\n\t - TrackingError\n\t - eta_ref\n\t - nMod\n\t - reflectivity\n"),
 	NULL},
{"nMod", (getter)Controller_get_nMod,(setter)Controller_set_nMod,
	PyDoc_STR("*float*: Number of collector modules in a loop\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nMod``:\n\n\t - nLoops\n\t - nSCA\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"nRecVar", (getter)Controller_get_nRecVar,(setter)Controller_set_nRecVar,
	PyDoc_STR("*float*: Number of receiver variantions\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 4 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"nSCA", (getter)Controller_get_nSCA,(setter)Controller_set_nSCA,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``nSCA`` depends on the following variables:\n\n\t - nMod\n"),
 	NULL},
{"nodes", (getter)Controller_get_nodes,(setter)Controller_set_nodes,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"opt_model", (getter)Controller_get_opt_model,(setter)Controller_set_opt_model,
	PyDoc_STR("*float*: The optical model\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"pb_fixed_par", (getter)Controller_get_pb_fixed_par,(setter)Controller_set_pb_fixed_par,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"pb_pump_coef", (getter)Controller_get_pb_pump_coef,(setter)Controller_set_pb_pump_coef,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"pb_rated_cap", (getter)Controller_get_pb_rated_cap,(setter)Controller_set_pb_rated_cap,
	PyDoc_STR("*float*: Rated plant capacity [MWe]\n\n**Required:**\nTrue\n\nThe value of ``pb_rated_cap`` depends on the following variables:\n\n\t - P_ref\n"),
 	NULL},
{"q_max_aux", (getter)Controller_get_q_max_aux,(setter)Controller_set_q_max_aux,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``q_max_aux`` depends on the following variables:\n\n\t - A_aperture\n\t - Dirt_mirror\n\t - Error\n\t - GeomEffects\n\t - I_bn_des\n\t - L_mod\n\t - P_ref\n\t - T_amb_sf_des\n\t - T_loop_in_des\n\t - T_loop_out\n\t - TrackingError\n\t - eta_ref\n\t - nLoops\n\t - nMod\n\t - reflectivity\n\t - solar_mult\n"),
 	NULL},
{"q_pb_design", (getter)Controller_get_q_pb_design,(setter)Controller_set_q_pb_design,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``q_pb_design`` depends on the following variables:\n\n\t - P_ref\n\t - eta_ref\n"),
 	NULL},
{"rec_htf_vol", (getter)Controller_get_rec_htf_vol,(setter)Controller_set_rec_htf_vol,
	PyDoc_STR("*float*: Volume of HTF in a single collector unit per unit aperture area [L/m2-ap]\n\n**Required:**\nTrue"),
 	NULL},
{"rec_model", (getter)Controller_get_rec_model,(setter)Controller_set_rec_model,
	PyDoc_STR("*float*: Receiver model type (1=Polynomial ; 2=Evac tube)\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"reflectivity", (getter)Controller_get_reflectivity,(setter)Controller_set_reflectivity,
	PyDoc_STR("*float*: Solar-weighted mirror reflectivity value\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``reflectivity``:\n\n\t - nLoops\n\t - q_max_aux\n\t - solar_mult\n\t - solarm\n"),
 	NULL},
{"sgs_diams", (getter)Controller_get_sgs_diams,(setter)Controller_set_sgs_diams,
	PyDoc_STR("*sequence*: Custom SGS diameters [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sgs_lengths", (getter)Controller_get_sgs_lengths,(setter)Controller_set_sgs_lengths,
	PyDoc_STR("*sequence*: Custom SGS lengths [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sgs_wallthicks", (getter)Controller_get_sgs_wallthicks,(setter)Controller_set_sgs_wallthicks,
	PyDoc_STR("*sequence*: Custom SGS wall thicknesses [m]\n\n**Required:**\nTrue"),
 	NULL},
{"solar_mult", (getter)Controller_get_solar_mult,(setter)Controller_set_solar_mult,
	PyDoc_STR("*float*: Solar multiple\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``solar_mult``:\n\n\t - q_max_aux\n\t - solarm\n\n\nThe value of ``solar_mult`` depends on the following variables:\n\n\t - A_aperture\n\t - Dirt_mirror\n\t - Error\n\t - GeomEffects\n\t - I_bn_des\n\t - L_mod\n\t - P_ref\n\t - T_amb_sf_des\n\t - T_loop_in_des\n\t - T_loop_out\n\t - TrackingError\n\t - eta_ref\n\t - nLoops\n\t - nMod\n\t - reflectivity\n"),
 	NULL},
{"solarm", (getter)Controller_get_solarm,(setter)Controller_set_solarm,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of ``solarm`` depends on the following variables:\n\n\t - A_aperture\n\t - Dirt_mirror\n\t - Error\n\t - GeomEffects\n\t - I_bn_des\n\t - L_mod\n\t - P_ref\n\t - T_amb_sf_des\n\t - T_loop_in_des\n\t - T_loop_out\n\t - TrackingError\n\t - eta_ref\n\t - nLoops\n\t - nMod\n\t - reflectivity\n\t - solar_mult\n"),
 	NULL},
{"store_fl_props", (getter)Controller_get_store_fl_props,(setter)Controller_set_store_fl_props,
	PyDoc_STR("*sequence[sequence]*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``store_fl_props``:\n\n\t - V_tank_hot_ini\n\t - vol_tank\n"),
 	NULL},
{"store_fluid", (getter)Controller_get_store_fluid,(setter)Controller_set_store_fluid,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``store_fluid``:\n\n\t - is_hx\n"),
 	NULL},
{"t_ch_out_max", (getter)Controller_get_t_ch_out_max,(setter)Controller_set_t_ch_out_max,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"t_dis_out_min", (getter)Controller_get_t_dis_out_min,(setter)Controller_set_t_dis_out_min,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"t_standby_reset", (getter)Controller_get_t_standby_reset,(setter)Controller_set_t_standby_reset,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tank_max_heat", (getter)Controller_get_tank_max_heat,(setter)Controller_set_tank_max_heat,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tank_pairs", (getter)Controller_get_tank_pairs,(setter)Controller_set_tank_pairs,
	PyDoc_STR("*float*: Label\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tanks_in_parallel", (getter)Controller_get_tanks_in_parallel,(setter)Controller_set_tanks_in_parallel,
	PyDoc_STR("*float*: Tanks are in parallel, not in series, with solar field [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tc_fill", (getter)Controller_get_tc_fill,(setter)Controller_set_tc_fill,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tc_void", (getter)Controller_get_tc_void,(setter)Controller_set_tc_void,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tes_pump_coef", (getter)Controller_get_tes_pump_coef,(setter)Controller_set_tes_pump_coef,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tes_temp", (getter)Controller_get_tes_temp,(setter)Controller_set_tes_temp,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``tes_temp``:\n\n\t - V_tank_hot_ini\n\t - vol_tank\n\n\nThe value of ``tes_temp`` depends on the following variables:\n\n\t - T_loop_in_des\n\t - T_loop_out\n"),
 	NULL},
{"tes_type", (getter)Controller_get_tes_type,(setter)Controller_set_tes_type,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)Controller_get_theta_dep,(setter)Controller_set_theta_dep,
	PyDoc_STR("*float*: deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)Controller_get_theta_stow,(setter)Controller_set_theta_stow,
	PyDoc_STR("*float*: stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"tshours", (getter)Controller_get_tshours,(setter)Controller_set_tshours,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``tshours``:\n\n\t - V_tank_hot_ini\n\t - vol_tank\n"),
 	NULL},
{"tslogic_a", (getter)Controller_get_tslogic_a,(setter)Controller_set_tslogic_a,
	PyDoc_STR("*sequence*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tslogic_b", (getter)Controller_get_tslogic_b,(setter)Controller_set_tslogic_b,
	PyDoc_STR("*sequence*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"tslogic_c", (getter)Controller_get_tslogic_c,(setter)Controller_set_tslogic_c,
	PyDoc_STR("*sequence*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)Controller_get_u_tank,(setter)Controller_set_u_tank,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue"),
 	NULL},
{"vol_tank", (getter)Controller_get_vol_tank,(setter)Controller_set_vol_tank,
	PyDoc_STR("*float*: Label\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``vol_tank``:\n\n\t - V_tank_hot_ini\n\n\nThe value of ``vol_tank`` depends on the following variables:\n\n\t - P_ref\n\t - T_loop_in_des\n\t - T_loop_out\n\t - dt_cold\n\t - dt_hot\n\t - eta_ref\n\t - store_fl_props\n\t - tes_temp\n\t - tshours\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controller_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF.Controller",             /*tp_name*/
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
		Controller_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Controller_getset,          /*tp_getset*/
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
 * SolarField Group
 */ 

static PyTypeObject SolarField_Type;

static PyObject *
SolarField_new(SAM_TcsMSLF data_ptr)
{
	PyObject* new_obj = SolarField_Type.tp_alloc(&SolarField_Type,0);

	VarGroupObject* SolarField_obj = (VarGroupObject*)new_obj;

	SolarField_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarField methods */

static PyObject *
SolarField_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarField_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarField_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarField_methods[] = {
		{"assign",            (PyCFunction)SolarField_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarField_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarField_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarField_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarField_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarField_get_washes_per_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_SolarField_washes_per_year_nget, self->data_ptr);
}

static int
SolarField_set_washes_per_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_SolarField_washes_per_year_nset, self->data_ptr);
}

static PyObject *
SolarField_get_water_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_SolarField_water_per_wash_nget, self->data_ptr);
}

static int
SolarField_set_water_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_SolarField_water_per_wash_nset, self->data_ptr);
}

static PyGetSetDef SolarField_getset[] = {
{"washes_per_year", (getter)SolarField_get_washes_per_year,(setter)SolarField_set_washes_per_year,
	PyDoc_STR("*float*: Mirror washing frequency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"water_per_wash", (getter)SolarField_get_water_per_wash,(setter)SolarField_set_water_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF.SolarField",             /*tp_name*/
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
		SolarField_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarField_getset,          /*tp_getset*/
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
Powerblock_new(SAM_TcsMSLF data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "Powerblock")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "Powerblock")){
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
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_CT_nget, self->data_ptr);
}

static int
Powerblock_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_CT_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsMSLF_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_P_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_P_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_T_approach_nget, self->data_ptr);
}

static int
Powerblock_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_T_approach_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_htf_cold_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_T_htf_cold_ref_nget, self->data_ptr);
}

static int
Powerblock_set_T_htf_cold_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_T_htf_cold_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_htf_hot_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_T_htf_hot_ref_nget, self->data_ptr);
}

static int
Powerblock_set_T_htf_hot_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_T_htf_hot_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_pc_config_nget, self->data_ptr);
}

static int
Powerblock_set_pc_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_pc_config_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_startup_time_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_tech_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Powerblock_tech_type_nget, self->data_ptr);
}

static int
Powerblock_set_tech_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Powerblock_tech_type_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"CT", (getter)Powerblock_get_CT,(setter)Powerblock_set_CT,
	PyDoc_STR("*float*: Flag for using dry cooling or wet cooling system [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	PyDoc_STR("*sequence*: Fraction indicating wet cooling use for hybrid system [none]\n\n**Options:**\nconstant=[0,0,0,0,0,0,0,0,0]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"P_ref", (getter)Powerblock_get_P_ref,(setter)Powerblock_set_P_ref,
	PyDoc_STR("*float*: Label [-]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``P_ref``:\n\n\t - V_tank_hot_ini\n\t - W_pb_design\n\t - nLoops\n\t - pb_rated_cap\n\t - q_max_aux\n\t - q_pb_design\n\t - solar_mult\n\t - solarm\n\t - system_capacity\n\t - vol_tank\n"),
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_htf_cold_ref", (getter)Powerblock_get_T_htf_cold_ref,(setter)Powerblock_set_T_htf_cold_ref,
	PyDoc_STR("*float*: Label [-]\n\n**Required:**\nTrue\n\nThe value of ``T_htf_cold_ref`` depends on the following variables:\n\n\t - T_loop_in_des\n"),
 	NULL},
{"T_htf_hot_ref", (getter)Powerblock_get_T_htf_hot_ref,(setter)Powerblock_set_T_htf_hot_ref,
	PyDoc_STR("*float*: Label [-]\n\n**Required:**\nTrue\n\nThe value of ``T_htf_hot_ref`` depends on the following variables:\n\n\t - T_loop_out\n"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Cycle thermal efficiency at design point [-]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``eta_ref``:\n\n\t - V_tank_hot_ini\n\t - nLoops\n\t - q_max_aux\n\t - q_pb_design\n\t - solar_mult\n\t - solarm\n\t - vol_tank\n"),
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction  [none]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"pc_config", (getter)Powerblock_get_pc_config,(setter)Powerblock_set_pc_config,
	PyDoc_STR("*float*: 0: Steam Rankine (224), 1: user defined [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby mode [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"tech_type", (getter)Powerblock_get_tech_type,(setter)Powerblock_set_tech_type,
	PyDoc_STR("*float*: Turbine inlet pressure control flag (sliding=user, fixed=trough) [1/2/3]\n\n**Info:**\ntower/trough/user\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF.Powerblock",             /*tp_name*/
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
 * UserDefinedPC Group
 */ 

static PyTypeObject UserDefinedPC_Type;

static PyObject *
UserDefinedPC_new(SAM_TcsMSLF data_ptr)
{
	PyObject* new_obj = UserDefinedPC_Type.tp_alloc(&UserDefinedPC_Type,0);

	VarGroupObject* UserDefinedPC_obj = (VarGroupObject*)new_obj;

	UserDefinedPC_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* UserDefinedPC methods */

static PyObject *
UserDefinedPC_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "UserDefinedPC")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPC_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &UserDefinedPC_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "UserDefinedPC")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPC_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &UserDefinedPC_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef UserDefinedPC_methods[] = {
		{"assign",            (PyCFunction)UserDefinedPC_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``UserDefinedPC_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)UserDefinedPC_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``UserDefinedPC_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)UserDefinedPC_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UserDefinedPC_get_ud_f_W_dot_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_UserDefinedPC_ud_f_W_dot_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_f_W_dot_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_UserDefinedPC_ud_f_W_dot_cool_des_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_UserDefinedPC_ud_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsMSLF_UserDefinedPC_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_m_dot_water_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_UserDefinedPC_ud_m_dot_water_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_m_dot_water_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_UserDefinedPC_ud_m_dot_water_cool_des_nset, self->data_ptr);
}

static PyGetSetDef UserDefinedPC_getset[] = {
{"ud_f_W_dot_cool_des", (getter)UserDefinedPC_get_ud_f_W_dot_cool_des,(setter)UserDefinedPC_set_ud_f_W_dot_cool_des,
	PyDoc_STR("*float*: Percent of user-defined power cycle design gross output consumed by cooling [%]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_ind_od", (getter)UserDefinedPC_get_ud_ind_od,(setter)UserDefinedPC_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_m_dot_water_cool_des", (getter)UserDefinedPC_get_ud_m_dot_water_cool_des,(setter)UserDefinedPC_set_ud_m_dot_water_cool_des,
	PyDoc_STR("*float*: Mass flow rate of water required at user-defined power cycle design point [kg/s]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject UserDefinedPC_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF.UserDefinedPC",             /*tp_name*/
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
		UserDefinedPC_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		UserDefinedPC_getset,          /*tp_getset*/
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
 * Enet Group
 */ 

static PyTypeObject Enet_Type;

static PyObject *
Enet_new(SAM_TcsMSLF data_ptr)
{
	PyObject* new_obj = Enet_Type.tp_alloc(&Enet_Type,0);

	VarGroupObject* Enet_obj = (VarGroupObject*)new_obj;

	Enet_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Enet methods */

static PyObject *
Enet_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "Enet")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Enet_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Enet_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "Enet")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Enet_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Enet_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Enet_methods[] = {
		{"assign",            (PyCFunction)Enet_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Enet_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Enet_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Enet_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Enet_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Enet_get_eta_lhv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Enet_eta_lhv_nget, self->data_ptr);
}

static int
Enet_set_eta_lhv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Enet_eta_lhv_nset, self->data_ptr);
}

static PyObject *
Enet_get_eta_tes_htr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Enet_eta_tes_htr_nget, self->data_ptr);
}

static int
Enet_set_eta_tes_htr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Enet_eta_tes_htr_nset, self->data_ptr);
}

static PyObject *
Enet_get_fp_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Enet_fp_mode_nget, self->data_ptr);
}

static int
Enet_set_fp_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsMSLF_Enet_fp_mode_nset, self->data_ptr);
}

static PyGetSetDef Enet_getset[] = {
{"eta_lhv", (getter)Enet_get_eta_lhv,(setter)Enet_set_eta_lhv,
	PyDoc_STR("*float*: Label [-]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_tes_htr", (getter)Enet_get_eta_tes_htr,(setter)Enet_set_eta_tes_htr,
	PyDoc_STR("*float*: Label [-]\n\n**Required:**\nTrue"),
 	NULL},
{"fp_mode", (getter)Enet_get_fp_mode,(setter)Enet_set_fp_mode,
	PyDoc_STR("*float*: Label [-]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Enet_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF.Enet",             /*tp_name*/
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
		Enet_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Enet_getset,          /*tp_getset*/
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
Outputs_new(SAM_TcsMSLF data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsMSLF", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TcsMSLF", "Outputs")){
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
Outputs_get_DP_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_DP_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_E_bal_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_E_bal_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_EqOptEff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_EqOptEff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_P_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Pipe_hl(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_Pipe_hl_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_par_sf_fp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_Q_par_sf_fp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_par_tes_fp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_Q_par_tes_fp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pb_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_pb_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pb_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_pb_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_sys_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_sys_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_sys_h(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_sys_h_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank_cold_fin(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_tank_cold_fin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_tank_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank_hot_fin(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_tank_hot_fin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tank_hot_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_T_tank_hot_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Ts_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_Ts_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Ts_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_Ts_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_cool_par(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_W_cool_par_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_W_dot_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_W_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_par_BOP(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_W_par_BOP_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_par_aux_boiler(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_W_par_aux_boiler_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsMSLF_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_annual_fuel_usage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_optical(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_eta_optical_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_eta_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_fixed_par_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_htf_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_avail(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_m_dot_avail_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_charge_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_m_dot_charge_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_discharge_tank(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_m_dot_discharge_tank_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htf2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_m_dot_htf2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_makeup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_m_dot_makeup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_m_dot_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tank_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_mass_tank_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tank_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_mass_tank_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_phi_t(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_phi_t_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_sgs_P_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pipe_sgs_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_sgs_T_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pipe_sgs_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_sgs_diams(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pipe_sgs_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_sgs_mdot_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pipe_sgs_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_sgs_vel_dsn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pipe_sgs_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_sgs_wallthk(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pipe_sgs_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_abs_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_abs_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux_fuel(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_aux_fuel_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_avail(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_avail_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_dump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_sf_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_inc_sf_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_spec_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_loss_spec_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_loss_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_q_to_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sf_def(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_sf_def_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsMSLF_Outputs_system_heat_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_t_loop_outlet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_t_loop_outlet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_theta_L(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_theta_L_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_track_par_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_track_par_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tank_cold_fin(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_vol_tank_cold_fin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tank_hot_fin(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_vol_tank_hot_fin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_vol_tank_total(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_vol_tank_total_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsMSLF_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"DP_tot", (getter)Outputs_get_DP_tot,(setter)0,
	PyDoc_STR("*sequence*: Field HTF pressure drop total [bar]"),
 	NULL},
{"E_bal_startup", (getter)Outputs_get_E_bal_startup,(setter)0,
	PyDoc_STR("*sequence*: Field HTF energy inertial (consumed) [MWht]"),
 	NULL},
{"EqOptEff", (getter)Outputs_get_EqOptEff,(setter)0,
	PyDoc_STR("*sequence*: Field collector and receiver optical efficiency"),
 	NULL},
{"P_cycle", (getter)Outputs_get_P_cycle,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (gross) [MWe]"),
 	NULL},
{"Pipe_hl", (getter)Outputs_get_Pipe_hl,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power header pipe losses [MWt]"),
 	NULL},
{"Q_par_sf_fp", (getter)Outputs_get_Q_par_sf_fp,(setter)0,
	PyDoc_STR("*sequence*: Parasitic thermal field freeze protection [MWt]"),
 	NULL},
{"Q_par_tes_fp", (getter)Outputs_get_Q_par_tes_fp,(setter)0,
	PyDoc_STR("*sequence*: Parasitic thermal TES freeze protection [MWt]"),
 	NULL},
{"T_pb_in", (getter)Outputs_get_T_pb_in,(setter)0,
	PyDoc_STR("*sequence*: Cycle HTF temperature in (hot) [C]"),
 	NULL},
{"T_pb_out", (getter)Outputs_get_T_pb_out,(setter)0,
	PyDoc_STR("*sequence*: Cycle HTF temperature out (cold) [C]"),
 	NULL},
{"T_sys_c", (getter)Outputs_get_T_sys_c,(setter)0,
	PyDoc_STR("*sequence*: Field HTF temperature cold header inlet [C]"),
 	NULL},
{"T_sys_h", (getter)Outputs_get_T_sys_h,(setter)0,
	PyDoc_STR("*sequence*: Field HTF temperature hot header outlet [C]"),
 	NULL},
{"T_tank_cold_fin", (getter)Outputs_get_T_tank_cold_fin,(setter)0,
	PyDoc_STR("*sequence*: TES HTF temperature in cold tank [C]"),
 	NULL},
{"T_tank_cold_in", (getter)Outputs_get_T_tank_cold_in,(setter)0,
	PyDoc_STR("*sequence*: TES HTF temperature cold tank inlet [C]"),
 	NULL},
{"T_tank_hot_fin", (getter)Outputs_get_T_tank_hot_fin,(setter)0,
	PyDoc_STR("*sequence*: TES HTF temperature in hot tank [C]"),
 	NULL},
{"T_tank_hot_in", (getter)Outputs_get_T_tank_hot_in,(setter)0,
	PyDoc_STR("*sequence*: TES HTF temperature hot tank inlet [C]"),
 	NULL},
{"Ts_cold", (getter)Outputs_get_Ts_cold,(setter)0,
	PyDoc_STR("*sequence*: TES HTF temperature HX field side cold [C]"),
 	NULL},
{"Ts_hot", (getter)Outputs_get_Ts_hot,(setter)0,
	PyDoc_STR("*sequence*: TES HTF temperature HX field side hot [C]"),
 	NULL},
{"W_cool_par", (getter)Outputs_get_W_cool_par,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"W_dot_pump", (getter)Outputs_get_W_dot_pump,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power solar field HTF pump [MWe]"),
 	NULL},
{"W_net", (getter)Outputs_get_W_net,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (net) [MWe]"),
 	NULL},
{"W_par_BOP", (getter)Outputs_get_W_par_BOP,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power generation-dependent load [MWe]"),
 	NULL},
{"W_par_aux_boiler", (getter)Outputs_get_W_par_aux_boiler,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power auxiliary heater operation [MWe]"),
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
{"eta", (getter)Outputs_get_eta,(setter)0,
	PyDoc_STR("*sequence*: Cycle efficiency (gross)"),
 	NULL},
{"eta_optical", (getter)Outputs_get_eta_optical,(setter)0,
	PyDoc_STR("*sequence*: Field collector optical efficiency"),
 	NULL},
{"eta_thermal", (getter)Outputs_get_eta_thermal,(setter)0,
	PyDoc_STR("*sequence*: Field thermal efficiency"),
 	NULL},
{"fixed_par", (getter)Outputs_get_fixed_par,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power fixed load [MWe]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"htf_pump_power", (getter)Outputs_get_htf_pump_power,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power TES and Cycle HTF pump [MWe]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"m_dot_avail", (getter)Outputs_get_m_dot_avail,(setter)0,
	PyDoc_STR("*sequence*: Field HTF mass flow rate total [kg/hr]"),
 	NULL},
{"m_dot_charge_field", (getter)Outputs_get_m_dot_charge_field,(setter)0,
	PyDoc_STR("*sequence*: TES HTF mass flow rate - field side of HX [kg/hr]"),
 	NULL},
{"m_dot_discharge_tank", (getter)Outputs_get_m_dot_discharge_tank,(setter)0,
	PyDoc_STR("*sequence*: TES HTF mass flow rate - storage side of HX [kg/hr]"),
 	NULL},
{"m_dot_htf2", (getter)Outputs_get_m_dot_htf2,(setter)0,
	PyDoc_STR("*sequence*: Field HTF mass flow rate loop [kg/s]"),
 	NULL},
{"m_dot_makeup", (getter)Outputs_get_m_dot_makeup,(setter)0,
	PyDoc_STR("*sequence*: Cycle cooling water mass flow rate - makeup [kg/hr]"),
 	NULL},
{"m_dot_pb", (getter)Outputs_get_m_dot_pb,(setter)0,
	PyDoc_STR("*sequence*: Cycle HTF mass flow rate [kg/hr]"),
 	NULL},
{"mass_tank_cold", (getter)Outputs_get_mass_tank_cold,(setter)0,
	PyDoc_STR("*sequence*: TES HTF mass in cold tank [kg]"),
 	NULL},
{"mass_tank_hot", (getter)Outputs_get_mass_tank_hot,(setter)0,
	PyDoc_STR("*sequence*: TES HTF mass in hot tank [kg]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy Gross [kWh]"),
 	NULL},
{"phi_t", (getter)Outputs_get_phi_t,(setter)0,
	PyDoc_STR("*sequence*: Field collector incidence angle - transversal [deg]"),
 	NULL},
{"pipe_sgs_P_dsn", (getter)Outputs_get_pipe_sgs_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Pressure in SGS pipes at design conditions [bar]"),
 	NULL},
{"pipe_sgs_T_dsn", (getter)Outputs_get_pipe_sgs_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Temperature in SGS pipes at design conditions [C]"),
 	NULL},
{"pipe_sgs_diams", (getter)Outputs_get_pipe_sgs_diams,(setter)0,
	PyDoc_STR("*sequence*: Pipe diameters in SGS [m]"),
 	NULL},
{"pipe_sgs_mdot_dsn", (getter)Outputs_get_pipe_sgs_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Mass flow SGS pipes at design conditions [kg/s]"),
 	NULL},
{"pipe_sgs_vel_dsn", (getter)Outputs_get_pipe_sgs_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Velocity in SGS pipes at design conditions [m/s]"),
 	NULL},
{"pipe_sgs_wallthk", (getter)Outputs_get_pipe_sgs_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Pipe wall thickness in SGS [m]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"q_abs_tot", (getter)Outputs_get_q_abs_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power absorbed [MWt]"),
 	NULL},
{"q_aux_fuel", (getter)Outputs_get_q_aux_fuel,(setter)0,
	PyDoc_STR("*sequence*: Fossil fuel usage (all subsystems) [MMBTU]"),
 	NULL},
{"q_avail", (getter)Outputs_get_q_avail,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power produced [MWt]"),
 	NULL},
{"q_dump", (getter)Outputs_get_q_dump,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power dumped [MWt]"),
 	NULL},
{"q_inc_sf_tot", (getter)Outputs_get_q_inc_sf_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_loss_spec_tot", (getter)Outputs_get_q_loss_spec_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power avg. receiver loss [W/m]"),
 	NULL},
{"q_loss_tot", (getter)Outputs_get_q_loss_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power receiver loss [MWt]"),
 	NULL},
{"q_pb", (getter)Outputs_get_q_pb,(setter)0,
	PyDoc_STR("*sequence*: Cycle thermal power input [MWt]"),
 	NULL},
{"q_to_tes", (getter)Outputs_get_q_to_tes,(setter)0,
	PyDoc_STR("*sequence*: TES thermal energy into storage [MWt]"),
 	NULL},
{"sf_def", (getter)Outputs_get_sf_def,(setter)0,
	PyDoc_STR("*sequence*: Field collector focus fraction"),
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
{"t_loop_outlet", (getter)Outputs_get_t_loop_outlet,(setter)0,
	PyDoc_STR("*sequence*: Field HTF temperature loop outlet [C]"),
 	NULL},
{"tank_losses", (getter)Outputs_get_tank_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses from tank(s) [MWt]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"theta_L", (getter)Outputs_get_theta_L,(setter)0,
	PyDoc_STR("*sequence*: Field collector incidence angle - longitudinal [deg]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: Resource Time-of-use value"),
 	NULL},
{"track_par_tot", (getter)Outputs_get_track_par_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power field collector drives [MWe]"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"vol_tank_cold_fin", (getter)Outputs_get_vol_tank_cold_fin,(setter)0,
	PyDoc_STR("*sequence*: TES HTF volume in cold tank [m3]"),
 	NULL},
{"vol_tank_hot_fin", (getter)Outputs_get_vol_tank_hot_fin,(setter)0,
	PyDoc_STR("*sequence*: TES HTF volume in hot tank [m3]"),
 	NULL},
{"vol_tank_total", (getter)Outputs_get_vol_tank_total,(setter)0,
	PyDoc_STR("*sequence*: TES HTF volume total [m3]"),
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
		"TcsMSLF.Outputs",             /*tp_name*/
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
 * TcsMSLF
 */

static PyTypeObject TcsMSLF_Type;

static CmodObject *
newTcsMSLFObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TcsMSLF_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* Mslf_obj = Mslf_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Mslf", Mslf_obj);
	Py_DECREF(Mslf_obj);

	PyObject* TouTranslator_obj = TouTranslator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TouTranslator", TouTranslator_obj);
	Py_DECREF(TouTranslator_obj);

	PyObject* Controller_obj = Controller_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controller", Controller_obj);
	Py_DECREF(Controller_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* UserDefinedPC_obj = UserDefinedPC_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "UserDefinedPC", UserDefinedPC_obj);
	Py_DECREF(UserDefinedPC_obj);

	PyObject* Enet_obj = Enet_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Enet", Enet_obj);
	Py_DECREF(Enet_obj);

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

/* TcsMSLF methods */

static void
TcsMSLF_dealloc(CmodObject *self)
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
TcsMSLF_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TcsMSLF_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcsMSLF_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcsMSLF"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TcsMSLF_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcsMSLF"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TcsMSLF_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TcsMSLF_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TcsMSLF_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TcsMSLF_methods[] = {
		{"execute",           (PyCFunction)TcsMSLF_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcsMSLF_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TcsMSLF_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TcsMSLF_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TcsMSLF_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TcsMSLF_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcsMSLF_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcsMSLF_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcsMSLF_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsMSLF",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TcsMSLF_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TcsMSLF_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TcsMSLF_getattro, /*tp_getattro*/
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
		TcsMSLF_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TcsMSLF object */

static PyObject *
TcsMSLF_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTcsMSLFObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsMSLF_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsMSLFObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsMSLF_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsMSLFObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsMSLF", def) < 0) {
		TcsMSLF_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TcsMSLF_from_existing(PyObject *self, PyObject *args)
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

	rv = newTcsMSLFObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsMSLF", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcsMSLFModule_methods[] = {
		{"new",             TcsMSLF_new,         METH_VARARGS,
				PyDoc_STR("new() -> TcsMSLF")},
		{"default",             TcsMSLF_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TcsMSLF\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"MSLFAllEquityPartnershipFlip\"*\n\n		- *\"MSLFCommercial\"*\n\n		- *\"MSLFLCOECalculator\"*\n\n		- *\"MSLFLeveragedPartnershipFlip\"*\n\n		- *\"MSLFMerchantPlant\"*\n\n		- *\"MSLFNone\"*\n\n		- *\"MSLFSaleLeaseback\"*\n\n		- *\"MSLFSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TcsMSLF_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TcsMSLF\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TcsMSLF_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TcsMSLF\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CSP linear Fresnel with molten salt heat transfer fluid for power generation");


static int
TcsMSLFModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TcsMSLF_Type.tp_dict = PyDict_New();
	if (!TcsMSLF_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TcsMSLF_Type
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
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TcsMSLF_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the Mslf type object to TcsMSLF_Type
	if (PyType_Ready(&Mslf_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"Mslf",
				(PyObject*)&Mslf_Type);
	Py_DECREF(&Mslf_Type);

	/// Add the TouTranslator type object to TcsMSLF_Type
	if (PyType_Ready(&TouTranslator_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"TouTranslator",
				(PyObject*)&TouTranslator_Type);
	Py_DECREF(&TouTranslator_Type);

	/// Add the Controller type object to TcsMSLF_Type
	if (PyType_Ready(&Controller_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"Controller",
				(PyObject*)&Controller_Type);
	Py_DECREF(&Controller_Type);

	/// Add the SolarField type object to TcsMSLF_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the Powerblock type object to TcsMSLF_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the UserDefinedPC type object to TcsMSLF_Type
	if (PyType_Ready(&UserDefinedPC_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"UserDefinedPC",
				(PyObject*)&UserDefinedPC_Type);
	Py_DECREF(&UserDefinedPC_Type);

	/// Add the Enet type object to TcsMSLF_Type
	if (PyType_Ready(&Enet_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"Enet",
				(PyObject*)&Enet_Type);
	Py_DECREF(&Enet_Type);

	/// Add the Outputs type object to TcsMSLF_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsMSLF_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TcsMSLF type object to the module
	if (PyType_Ready(&TcsMSLF_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TcsMSLF",
				(PyObject*)&TcsMSLF_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TcsMSLFModule_slots[] = {
		{Py_mod_exec, TcsMSLFModule_exec},
		{0, NULL},
};

static struct PyModuleDef TcsMSLFModule = {
		PyModuleDef_HEAD_INIT,
		"TcsMSLF",
		module_doc,
		0,
		TcsMSLFModule_methods,
		TcsMSLFModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TcsMSLF(void)
{
	return PyModuleDef_Init(&TcsMSLFModule);
}