#include <Python.h>

#include <SAM_TroughPhysicalCspSolver.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "Weather")){
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
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Weather_azimuth_nget, self->data_ptr);
}

static int
Weather_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Weather_azimuth_nset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysicalCspSolver_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysicalCspSolver_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Weather_tilt_nget, self->data_ptr);
}

static int
Weather_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Weather_tilt_nset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Weather_track_mode_nget, self->data_ptr);
}

static int
Weather_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Weather_track_mode_nset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"azimuth", (getter)Weather_get_azimuth,(setter)Weather_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle of surface/axis [none]\n\n**Required:**\nTrue"),
 	NULL},
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: Local weather file with path [none]\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nTrue"),
 	NULL},
{"tilt", (getter)Weather_get_tilt,(setter)Weather_set_tilt,
	PyDoc_STR("*float*: Tilt angle of surface/axis [none]\n\n**Required:**\nTrue"),
 	NULL},
{"track_mode", (getter)Weather_get_track_mode,(setter)Weather_set_track_mode,
	PyDoc_STR("*float*: Tracking mode [none]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.Weather",             /*tp_name*/
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
 * Trough Group
 */ 

static PyTypeObject Trough_Type;

static PyObject *
Trough_new(SAM_TroughPhysicalCspSolver data_ptr)
{
	PyObject* new_obj = Trough_Type.tp_alloc(&Trough_Type,0);

	VarGroupObject* Trough_obj = (VarGroupObject*)new_obj;

	Trough_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Trough methods */

static PyObject *
Trough_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "Trough")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Trough_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Trough_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "Trough")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Trough_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Trough_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Trough_methods[] = {
		{"assign",            (PyCFunction)Trough_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Trough_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Trough_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Trough_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Trough_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Trough_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Trough_system_capacity_nget, self->data_ptr);
}

static int
Trough_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Trough_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef Trough_getset[] = {
{"system_capacity", (getter)Trough_get_system_capacity,(setter)Trough_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Trough_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.Trough",             /*tp_name*/
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
		Trough_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Trough_getset,          /*tp_getset*/
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
 * TimeOfDelivery Group
 */ 

static PyTypeObject TimeOfDelivery_Type;

static PyObject *
TimeOfDelivery_new(SAM_TroughPhysicalCspSolver data_ptr)
{
	PyObject* new_obj = TimeOfDelivery_Type.tp_alloc(&TimeOfDelivery_Type,0);

	VarGroupObject* TimeOfDelivery_obj = (VarGroupObject*)new_obj;

	TimeOfDelivery_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeOfDelivery methods */

static PyObject *
TimeOfDelivery_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "TimeOfDelivery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDelivery_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TimeOfDelivery_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "TimeOfDelivery")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDelivery_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDelivery_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDelivery_methods[] = {
		{"assign",            (PyCFunction)TimeOfDelivery_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TimeOfDelivery_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TimeOfDelivery_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TimeOfDelivery_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeOfDelivery_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDelivery_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_TimeOfDelivery_dispatch_factors_ts_aget, self->data_ptr);
}

static int
TimeOfDelivery_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_TimeOfDelivery_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
TimeOfDelivery_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_TimeOfDelivery_ppa_multiplier_model_nget, self->data_ptr);
}

static int
TimeOfDelivery_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_TimeOfDelivery_ppa_multiplier_model_nset, self->data_ptr);
}

static PyGetSetDef TimeOfDelivery_getset[] = {
{"dispatch_factors_ts", (getter)TimeOfDelivery_get_dispatch_factors_ts,(setter)TimeOfDelivery_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n**Required:**\nRequired if ppa_multiplier_model=1"),
 	NULL},
{"ppa_multiplier_model", (getter)TimeOfDelivery_get_ppa_multiplier_model,(setter)TimeOfDelivery_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDelivery_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.TimeOfDelivery",             /*tp_name*/
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
		TimeOfDelivery_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDelivery_getset,          /*tp_getset*/
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
SolarField_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "SolarField")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "SolarField")){
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
SolarField_get_A_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_A_aperture_aget, self->data_ptr);
}

static int
SolarField_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_A_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_AbsorberMaterial_mget, self->data_ptr);
}

static int
SolarField_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
SolarField_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_AnnulusGas_mget, self->data_ptr);
}

static int
SolarField_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Ave_Focal_Length(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_Ave_Focal_Length_aget, self->data_ptr);
}

static int
SolarField_set_Ave_Focal_Length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Ave_Focal_Length_aset, self->data_ptr);
}

static PyObject *
SolarField_get_ColperSCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_ColperSCA_aget, self->data_ptr);
}

static int
SolarField_set_ColperSCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_ColperSCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_D_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_D_2_mget, self->data_ptr);
}

static int
SolarField_set_D_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_D_2_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_D_3_mget, self->data_ptr);
}

static int
SolarField_set_D_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_D_3_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_D_4_mget, self->data_ptr);
}

static int
SolarField_set_D_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_D_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_D_5_mget, self->data_ptr);
}

static int
SolarField_set_D_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_D_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_p(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_D_p_mget, self->data_ptr);
}

static int
SolarField_set_D_p(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_D_p_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_Design_loss_mget, self->data_ptr);
}

static int
SolarField_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Design_loss_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_HCE(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_Dirt_HCE_mget, self->data_ptr);
}

static int
SolarField_set_Dirt_HCE(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_Dirt_mirror_aget, self->data_ptr);
}

static int
SolarField_set_Dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Dirt_mirror_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Distance_SCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_Distance_SCA_aget, self->data_ptr);
}

static int
SolarField_set_Distance_SCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Distance_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_EPSILON_4_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_EPSILON_5_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_EPSILON_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Error(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_Error_aget, self->data_ptr);
}

static int
SolarField_set_Error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Error_aset, self->data_ptr);
}

static PyObject *
SolarField_get_FieldConfig(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_FieldConfig_nget, self->data_ptr);
}

static int
SolarField_set_FieldConfig(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_FieldConfig_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_Flow_type_mget, self->data_ptr);
}

static int
SolarField_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Flow_type_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_Fluid_nget, self->data_ptr);
}

static int
SolarField_set_Fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Fluid_nset, self->data_ptr);
}

static PyObject *
SolarField_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_GeomEffects_aget, self->data_ptr);
}

static int
SolarField_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_GeomEffects_aset, self->data_ptr);
}

static PyObject *
SolarField_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_GlazingIntactIn_mget, self->data_ptr);
}

static int
SolarField_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_HCE_FieldFrac_mget, self->data_ptr);
}

static int
SolarField_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HDR_rough(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_HDR_rough_nget, self->data_ptr);
}

static int
SolarField_set_HDR_rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_HDR_rough_nset, self->data_ptr);
}

static PyObject *
SolarField_get_IAM_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_IAM_matrix_mget, self->data_ptr);
}

static int
SolarField_set_IAM_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_IAM_matrix_mset, self->data_ptr);
}

static PyObject *
SolarField_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_I_bn_des_nget, self->data_ptr);
}

static int
SolarField_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_I_bn_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_SCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_L_SCA_aget, self->data_ptr);
}

static int
SolarField_set_L_SCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_L_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_L_aperture_aget, self->data_ptr);
}

static int
SolarField_set_L_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_L_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_P_a_mget, self->data_ptr);
}

static int
SolarField_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_P_a_mset, self->data_ptr);
}

static PyObject *
SolarField_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_P_ref_nget, self->data_ptr);
}

static int
SolarField_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_P_ref_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_Pipe_hl_coef_nget, self->data_ptr);
}

static int
SolarField_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Rho_mirror_clean(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_Rho_mirror_clean_aget, self->data_ptr);
}

static int
SolarField_set_Rho_mirror_clean(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Rho_mirror_clean_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_Rough_mget, self->data_ptr);
}

static int
SolarField_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Rough_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Row_Distance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_Row_Distance_nget, self->data_ptr);
}

static int
SolarField_set_Row_Distance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Row_Distance_nset, self->data_ptr);
}

static PyObject *
SolarField_get_SCADefocusArray(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_SCADefocusArray_aget, self->data_ptr);
}

static int
SolarField_set_SCADefocusArray(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_SCADefocusArray_aset, self->data_ptr);
}

static PyObject *
SolarField_get_SCAInfoArray(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_SCAInfoArray_mget, self->data_ptr);
}

static int
SolarField_set_SCAInfoArray(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_SCAInfoArray_mset, self->data_ptr);
}

static PyObject *
SolarField_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_SCA_drives_elec_nget, self->data_ptr);
}

static int
SolarField_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_Shadowing_mget, self->data_ptr);
}

static int
SolarField_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Shadowing_mset, self->data_ptr);
}

static PyObject *
SolarField_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_T_fp_nget, self->data_ptr);
}

static int
SolarField_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_T_fp_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_T_loop_in_des_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_T_loop_out_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_T_loop_out_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_T_startup_nget, self->data_ptr);
}

static int
SolarField_set_T_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_T_startup_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_Tau_envelope_mget, self->data_ptr);
}

static int
SolarField_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
SolarField_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_TrackingError_aget, self->data_ptr);
}

static int
SolarField_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_TrackingError_aset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_V_hdr_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_V_hdr_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_V_hdr_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_V_hdr_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_W_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_SolarField_W_aperture_aget, self->data_ptr);
}

static int
SolarField_set_W_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_SolarField_W_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_accept_init_nget, self->data_ptr);
}

static int
SolarField_set_accept_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_accept_init_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_loc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_accept_loc_nget, self->data_ptr);
}

static int
SolarField_set_accept_loc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_accept_loc_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_accept_mode_nget, self->data_ptr);
}

static int
SolarField_set_accept_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_accept_mode_nset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_alpha_abs_mget, self->data_ptr);
}

static int
SolarField_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_alpha_abs_mset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_alpha_env_mget, self->data_ptr);
}

static int
SolarField_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_alpha_env_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_11(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_11_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_11(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_11_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_12(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_12_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_12(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_12_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_13(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_13_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_13(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_13_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_14(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_14_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_14(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_14_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_21(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_21_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_21(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_21_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_22(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_22_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_22(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_22_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_23(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_23_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_23(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_23_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_24(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_24_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_24(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_24_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_31(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_31_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_31(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_31_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_32(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_32_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_32(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_32_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_33(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_33_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_33(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_33_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_34(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_34_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_34(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_34_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_41(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_41_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_41(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_41_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_42(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_42_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_42(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_42_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_43(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_43_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_43(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_43_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_44(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_44_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_44(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_SolarField_epsilon_3_44_mset, self->data_ptr);
}

static PyObject *
SolarField_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_eta_pump_nget, self->data_ptr);
}

static int
SolarField_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_eta_pump_nset, self->data_ptr);
}

static PyObject *
SolarField_get_fthrctrl(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_fthrctrl_nget, self->data_ptr);
}

static int
SolarField_set_fthrctrl(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_fthrctrl_nset, self->data_ptr);
}

static PyObject *
SolarField_get_fthrok(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_fthrok_nget, self->data_ptr);
}

static int
SolarField_set_fthrok(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_fthrok_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_m_dot_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_m_dot_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_m_dot_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_m_dot_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_mc_bal_cold_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_mc_bal_cold_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_mc_bal_hot_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_mc_bal_hot_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_sca(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_mc_bal_sca_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_sca(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_mc_bal_sca_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nColt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_nColt_nget, self->data_ptr);
}

static int
SolarField_set_nColt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_nColt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEVar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_nHCEVar_nget, self->data_ptr);
}

static int
SolarField_set_nHCEVar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_nHCEVar_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_nHCEt_nget, self->data_ptr);
}

static int
SolarField_set_nHCEt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_nHCEt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_nLoops_nget, self->data_ptr);
}

static int
SolarField_set_nLoops(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_nLoops_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nSCA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_nSCA_nget, self->data_ptr);
}

static int
SolarField_set_nSCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_nSCA_nset, self->data_ptr);
}

static PyObject *
SolarField_get_solar_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_solar_mult_nget, self->data_ptr);
}

static int
SolarField_set_solar_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_solar_mult_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_theta_dep_nget, self->data_ptr);
}

static int
SolarField_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_theta_dep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_theta_stow_nget, self->data_ptr);
}

static int
SolarField_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_theta_stow_nset, self->data_ptr);
}

static PyObject *
SolarField_get_washing_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_washing_frequency_nget, self->data_ptr);
}

static int
SolarField_set_washing_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_washing_frequency_nset, self->data_ptr);
}

static PyObject *
SolarField_get_water_usage_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_SolarField_water_usage_per_wash_nget, self->data_ptr);
}

static int
SolarField_set_water_usage_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_SolarField_water_usage_per_wash_nset, self->data_ptr);
}

static PyGetSetDef SolarField_getset[] = {
{"A_aperture", (getter)SolarField_get_A_aperture,(setter)SolarField_set_A_aperture,
	PyDoc_STR("*sequence*: Reflective aperture area of the collector [m2]\n\n**Required:**\nTrue"),
 	NULL},
{"AbsorberMaterial", (getter)SolarField_get_AbsorberMaterial,(setter)SolarField_set_AbsorberMaterial,
	PyDoc_STR("*sequence[sequence]*: Absorber material type [none]\n\n**Required:**\nTrue"),
 	NULL},
{"AnnulusGas", (getter)SolarField_get_AnnulusGas,(setter)SolarField_set_AnnulusGas,
	PyDoc_STR("*sequence[sequence]*: Annulus gas type (1=air, 26=Ar, 27=H2) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Ave_Focal_Length", (getter)SolarField_get_Ave_Focal_Length,(setter)SolarField_set_Ave_Focal_Length,
	PyDoc_STR("*sequence*: Average focal length of the collector  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"ColperSCA", (getter)SolarField_get_ColperSCA,(setter)SolarField_set_ColperSCA,
	PyDoc_STR("*sequence*: Number of individual collector sections in an SCA  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"D_2", (getter)SolarField_get_D_2,(setter)SolarField_set_D_2,
	PyDoc_STR("*sequence[sequence]*: Inner absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_3", (getter)SolarField_get_D_3,(setter)SolarField_set_D_3,
	PyDoc_STR("*sequence[sequence]*: Outer absorber tube diameter [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_4", (getter)SolarField_get_D_4,(setter)SolarField_set_D_4,
	PyDoc_STR("*sequence[sequence]*: Inner glass envelope diameter  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_5", (getter)SolarField_get_D_5,(setter)SolarField_set_D_5,
	PyDoc_STR("*sequence[sequence]*: Outer glass envelope diameter  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"D_p", (getter)SolarField_get_D_p,(setter)SolarField_set_D_p,
	PyDoc_STR("*sequence[sequence]*: Diameter of the absorber flow plug (optional)  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Design_loss", (getter)SolarField_get_Design_loss,(setter)SolarField_set_Design_loss,
	PyDoc_STR("*sequence[sequence]*: Receiver heat loss at design [W/m]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_HCE", (getter)SolarField_get_Dirt_HCE,(setter)SolarField_set_Dirt_HCE,
	PyDoc_STR("*sequence[sequence]*: Loss due to dirt on the receiver envelope [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Dirt_mirror", (getter)SolarField_get_Dirt_mirror,(setter)SolarField_set_Dirt_mirror,
	PyDoc_STR("*sequence*: User-defined dirt on mirror derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Distance_SCA", (getter)SolarField_get_Distance_SCA,(setter)SolarField_set_Distance_SCA,
	PyDoc_STR("*sequence*: Piping distance between SCA's in the field [m]\n\n**Required:**\nTrue"),
 	NULL},
{"EPSILON_4", (getter)SolarField_get_EPSILON_4,(setter)SolarField_set_EPSILON_4,
	PyDoc_STR("*sequence[sequence]*: Inner glass envelope emissivities (Pyrex)  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"EPSILON_5", (getter)SolarField_get_EPSILON_5,(setter)SolarField_set_EPSILON_5,
	PyDoc_STR("*sequence[sequence]*: Outer glass envelope emissivities (Pyrex)  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Error", (getter)SolarField_get_Error,(setter)SolarField_set_Error,
	PyDoc_STR("*sequence*: User-defined general optical error derate  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"FieldConfig", (getter)SolarField_get_FieldConfig,(setter)SolarField_set_FieldConfig,
	PyDoc_STR("*float*: Number of subfield headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Flow_type", (getter)SolarField_get_Flow_type,(setter)SolarField_set_Flow_type,
	PyDoc_STR("*sequence[sequence]*: Flow type through the absorber [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Fluid", (getter)SolarField_get_Fluid,(setter)SolarField_set_Fluid,
	PyDoc_STR("*float*: Field HTF fluid ID number [none]\n\n**Required:**\nTrue"),
 	NULL},
{"GeomEffects", (getter)SolarField_get_GeomEffects,(setter)SolarField_set_GeomEffects,
	PyDoc_STR("*sequence*: User-defined geometry effects derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"GlazingIntactIn", (getter)SolarField_get_GlazingIntactIn,(setter)SolarField_set_GlazingIntactIn,
	PyDoc_STR("*sequence[sequence]*: Glazing intact (broken glass) flag {1=true, else=false} [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HCE_FieldFrac", (getter)SolarField_get_HCE_FieldFrac,(setter)SolarField_set_HCE_FieldFrac,
	PyDoc_STR("*sequence[sequence]*: Fraction of the field occupied by this HCE type  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"HDR_rough", (getter)SolarField_get_HDR_rough,(setter)SolarField_set_HDR_rough,
	PyDoc_STR("*float*: Header pipe roughness [m]\n\n**Required:**\nTrue"),
 	NULL},
{"IAM_matrix", (getter)SolarField_get_IAM_matrix,(setter)SolarField_set_IAM_matrix,
	PyDoc_STR("*sequence[sequence]*: IAM coefficients, matrix for 4 collectors [none]\n\n**Required:**\nTrue"),
 	NULL},
{"I_bn_des", (getter)SolarField_get_I_bn_des,(setter)SolarField_set_I_bn_des,
	PyDoc_STR("*float*: Solar irradiation at design [C]\n\n**Required:**\nTrue"),
 	NULL},
{"L_SCA", (getter)SolarField_get_L_SCA,(setter)SolarField_set_L_SCA,
	PyDoc_STR("*sequence*: Length of the SCA  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_aperture", (getter)SolarField_get_L_aperture,(setter)SolarField_set_L_aperture,
	PyDoc_STR("*sequence*: Length of a single mirror/HCE unit [m]\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)SolarField_get_P_a,(setter)SolarField_set_P_a,
	PyDoc_STR("*sequence[sequence]*: Annulus gas pressure [torr]\n\n**Required:**\nTrue"),
 	NULL},
{"P_ref", (getter)SolarField_get_P_ref,(setter)SolarField_set_P_ref,
	PyDoc_STR("*float*: Rated plant capacity [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"Pipe_hl_coef", (getter)SolarField_get_Pipe_hl_coef,(setter)SolarField_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header, runner pipe, and non-HCE piping [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"Rho_mirror_clean", (getter)SolarField_get_Rho_mirror_clean,(setter)SolarField_set_Rho_mirror_clean,
	PyDoc_STR("*sequence*: User-defined clean mirror reflectivity [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Rough", (getter)SolarField_get_Rough,(setter)SolarField_set_Rough,
	PyDoc_STR("*sequence[sequence]*: Roughness of the internal surface  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Row_Distance", (getter)SolarField_get_Row_Distance,(setter)SolarField_set_Row_Distance,
	PyDoc_STR("*float*: Spacing between rows (centerline to centerline) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"SCADefocusArray", (getter)SolarField_get_SCADefocusArray,(setter)SolarField_set_SCADefocusArray,
	PyDoc_STR("*sequence*: Collector defocus order [none]\n\n**Required:**\nTrue"),
 	NULL},
{"SCAInfoArray", (getter)SolarField_get_SCAInfoArray,(setter)SolarField_set_SCAInfoArray,
	PyDoc_STR("*sequence[sequence]*: Receiver (,1) and collector (,2) type for each assembly in loop [none]\n\n**Required:**\nTrue"),
 	NULL},
{"SCA_drives_elec", (getter)SolarField_get_SCA_drives_elec,(setter)SolarField_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power, in Watts per SCA drive [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
{"Shadowing", (getter)SolarField_get_Shadowing,(setter)SolarField_set_Shadowing,
	PyDoc_STR("*sequence[sequence]*: Receiver bellows shadowing loss factor [none]\n\n**Required:**\nTrue"),
 	NULL},
{"T_fp", (getter)SolarField_get_T_fp,(setter)SolarField_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_in_des", (getter)SolarField_get_T_loop_in_des,(setter)SolarField_set_T_loop_in_des,
	PyDoc_STR("*float*: Design loop inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_loop_out", (getter)SolarField_get_T_loop_out,(setter)SolarField_set_T_loop_out,
	PyDoc_STR("*float*: Target loop outlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_startup", (getter)SolarField_get_T_startup,(setter)SolarField_set_T_startup,
	PyDoc_STR("*float*: Required temperature of the system before the power block can be switched on [C]\n\n**Required:**\nTrue"),
 	NULL},
{"Tau_envelope", (getter)SolarField_get_Tau_envelope,(setter)SolarField_set_Tau_envelope,
	PyDoc_STR("*sequence[sequence]*: Envelope transmittance [none]\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)SolarField_get_TrackingError,(setter)SolarField_set_TrackingError,
	PyDoc_STR("*sequence*: User-defined tracking error derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_max", (getter)SolarField_get_V_hdr_max,(setter)SolarField_set_V_hdr_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the header at design [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_min", (getter)SolarField_get_V_hdr_min,(setter)SolarField_set_V_hdr_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the header at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"W_aperture", (getter)SolarField_get_W_aperture,(setter)SolarField_set_W_aperture,
	PyDoc_STR("*sequence*: The collector aperture width (Total structural area used for shadowing) [m]\n\n**Required:**\nTrue"),
 	NULL},
{"accept_init", (getter)SolarField_get_accept_init,(setter)SolarField_set_accept_init,
	PyDoc_STR("*float*: In acceptance testing mode - require steady-state startup [none]\n\n**Required:**\nTrue"),
 	NULL},
{"accept_loc", (getter)SolarField_get_accept_loc,(setter)SolarField_set_accept_loc,
	PyDoc_STR("*float*: In acceptance testing mode - temperature sensor location [1/2]\n\n**Info:**\nhx/loop\n\n**Required:**\nTrue"),
 	NULL},
{"accept_mode", (getter)SolarField_get_accept_mode,(setter)SolarField_set_accept_mode,
	PyDoc_STR("*float*: Acceptance testing mode? [0/1]\n\n**Info:**\nno/yes\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_abs", (getter)SolarField_get_alpha_abs,(setter)SolarField_set_alpha_abs,
	PyDoc_STR("*sequence[sequence]*: Absorber absorptance  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_env", (getter)SolarField_get_alpha_env,(setter)SolarField_set_alpha_env,
	PyDoc_STR("*sequence[sequence]*: Envelope absorptance  [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_11", (getter)SolarField_get_epsilon_3_11,(setter)SolarField_set_epsilon_3_11,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_12", (getter)SolarField_get_epsilon_3_12,(setter)SolarField_set_epsilon_3_12,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_13", (getter)SolarField_get_epsilon_3_13,(setter)SolarField_set_epsilon_3_13,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_14", (getter)SolarField_get_epsilon_3_14,(setter)SolarField_set_epsilon_3_14,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_21", (getter)SolarField_get_epsilon_3_21,(setter)SolarField_set_epsilon_3_21,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_22", (getter)SolarField_get_epsilon_3_22,(setter)SolarField_set_epsilon_3_22,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_23", (getter)SolarField_get_epsilon_3_23,(setter)SolarField_set_epsilon_3_23,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_24", (getter)SolarField_get_epsilon_3_24,(setter)SolarField_set_epsilon_3_24,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_31", (getter)SolarField_get_epsilon_3_31,(setter)SolarField_set_epsilon_3_31,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_32", (getter)SolarField_get_epsilon_3_32,(setter)SolarField_set_epsilon_3_32,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_33", (getter)SolarField_get_epsilon_3_33,(setter)SolarField_set_epsilon_3_33,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_34", (getter)SolarField_get_epsilon_3_34,(setter)SolarField_set_epsilon_3_34,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_41", (getter)SolarField_get_epsilon_3_41,(setter)SolarField_set_epsilon_3_41,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 1 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_42", (getter)SolarField_get_epsilon_3_42,(setter)SolarField_set_epsilon_3_42,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 2 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_43", (getter)SolarField_get_epsilon_3_43,(setter)SolarField_set_epsilon_3_43,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 3 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"epsilon_3_44", (getter)SolarField_get_epsilon_3_44,(setter)SolarField_set_epsilon_3_44,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 4 [none]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)SolarField_get_eta_pump,(setter)SolarField_set_eta_pump,
	PyDoc_STR("*float*: HTF pump efficiency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fthrctrl", (getter)SolarField_get_fthrctrl,(setter)SolarField_set_fthrctrl,
	PyDoc_STR("*float*: Defocusing strategy [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fthrok", (getter)SolarField_get_fthrok,(setter)SolarField_set_fthrok,
	PyDoc_STR("*float*: Flag to allow partial defocusing of the collectors [W/SCA]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htfmax", (getter)SolarField_get_m_dot_htfmax,(setter)SolarField_set_m_dot_htfmax,
	PyDoc_STR("*float*: Maximum loop HTF flow rate [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"m_dot_htfmin", (getter)SolarField_get_m_dot_htfmin,(setter)SolarField_set_m_dot_htfmin,
	PyDoc_STR("*float*: Minimum loop HTF flow rate [kg/s]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_cold", (getter)SolarField_get_mc_bal_cold,(setter)SolarField_set_mc_bal_cold,
	PyDoc_STR("*float*: Heat capacity of the balance of plant on the cold side [kWht/K-MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_hot", (getter)SolarField_get_mc_bal_hot,(setter)SolarField_set_mc_bal_hot,
	PyDoc_STR("*float*: Heat capacity of the balance of plant on the hot side [kWht/K-MWt]\n\n**Info:**\nnone\n\n**Required:**\nTrue"),
 	NULL},
{"mc_bal_sca", (getter)SolarField_get_mc_bal_sca,(setter)SolarField_set_mc_bal_sca,
	PyDoc_STR("*float*: Non-HTF heat capacity associated with each SCA - per meter basis [Wht/K-m]\n\n**Required:**\nTrue"),
 	NULL},
{"nColt", (getter)SolarField_get_nColt,(setter)SolarField_set_nColt,
	PyDoc_STR("*float*: Number of collector types [none]\n\n**Options:**\nconstant=4\n\n**Required:**\nTrue"),
 	NULL},
{"nHCEVar", (getter)SolarField_get_nHCEVar,(setter)SolarField_set_nHCEVar,
	PyDoc_STR("*float*: Number of HCE variants per type [none]\n\n**Required:**\nTrue"),
 	NULL},
{"nHCEt", (getter)SolarField_get_nHCEt,(setter)SolarField_set_nHCEt,
	PyDoc_STR("*float*: Number of HCE types [none]\n\n**Required:**\nTrue"),
 	NULL},
{"nLoops", (getter)SolarField_get_nLoops,(setter)SolarField_set_nLoops,
	PyDoc_STR("*float*: Number of loops in the field [none]\n\n**Required:**\nTrue"),
 	NULL},
{"nSCA", (getter)SolarField_get_nSCA,(setter)SolarField_set_nSCA,
	PyDoc_STR("*float*: Number of SCAs in a loop [none]\n\n**Required:**\nTrue"),
 	NULL},
{"solar_mult", (getter)SolarField_get_solar_mult,(setter)SolarField_set_solar_mult,
	PyDoc_STR("*float*: Solar multiple [none]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)SolarField_get_theta_dep,(setter)SolarField_set_theta_dep,
	PyDoc_STR("*float*: Deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)SolarField_get_theta_stow,(setter)SolarField_set_theta_stow,
	PyDoc_STR("*float*: Stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"washing_frequency", (getter)SolarField_get_washing_frequency,(setter)SolarField_set_washing_frequency,
	PyDoc_STR("*float*: Mirror washing frequency [none]\n\n**Required:**\nTrue"),
 	NULL},
{"water_usage_per_wash", (getter)SolarField_get_water_usage_per_wash,(setter)SolarField_set_water_usage_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.SolarField",             /*tp_name*/
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
 * Controller Group
 */ 

static PyTypeObject Controller_Type;

static PyObject *
Controller_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "Controller")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "Controller")){
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
Controller_get_T_set_aux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_T_set_aux_nget, self->data_ptr);
}

static int
Controller_set_T_set_aux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_T_set_aux_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_cold_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_T_tank_cold_ini_nget, self->data_ptr);
}

static int
Controller_set_T_tank_cold_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_T_tank_cold_ini_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_tank_hot_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_V_tank_hot_ini_nget, self->data_ptr);
}

static int
Controller_set_V_tank_hot_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_V_tank_hot_ini_nset, self->data_ptr);
}

static PyObject *
Controller_get_W_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_W_pb_design_nget, self->data_ptr);
}

static int
Controller_set_W_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_W_pb_design_nset, self->data_ptr);
}

static PyObject *
Controller_get_aux_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Controller_aux_array_aget, self->data_ptr);
}

static int
Controller_set_aux_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Controller_aux_array_aset, self->data_ptr);
}

static PyObject *
Controller_get_bop_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Controller_bop_array_aget, self->data_ptr);
}

static int
Controller_set_bop_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Controller_bop_array_aset, self->data_ptr);
}

static PyObject *
Controller_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_cold_tank_Thtr_nget, self->data_ptr);
}

static int
Controller_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
Controller_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
Controller_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
Controller_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_cycle_max_frac_nget, self->data_ptr);
}

static int
Controller_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
Controller_get_dt_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_dt_cold_nget, self->data_ptr);
}

static int
Controller_set_dt_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_dt_cold_nset, self->data_ptr);
}

static PyObject *
Controller_get_dt_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_dt_hot_nget, self->data_ptr);
}

static int
Controller_set_dt_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_dt_hot_nset, self->data_ptr);
}

static PyObject *
Controller_get_f_tc_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_f_tc_cold_nget, self->data_ptr);
}

static int
Controller_set_f_tc_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_f_tc_cold_nset, self->data_ptr);
}

static PyObject *
Controller_get_ffrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Controller_ffrac_aget, self->data_ptr);
}

static int
Controller_set_ffrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Controller_ffrac_aset, self->data_ptr);
}

static PyObject *
Controller_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_Controller_field_fl_props_mget, self->data_ptr);
}

static int
Controller_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_Controller_field_fl_props_mset, self->data_ptr);
}

static PyObject *
Controller_get_fossil_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_fossil_mode_nget, self->data_ptr);
}

static int
Controller_set_fossil_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_fossil_mode_nset, self->data_ptr);
}

static PyObject *
Controller_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_h_tank_nget, self->data_ptr);
}

static int
Controller_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_h_tank_nset, self->data_ptr);
}

static PyObject *
Controller_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_h_tank_min_nget, self->data_ptr);
}

static int
Controller_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_h_tank_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_hot_tank_Thtr_nget, self->data_ptr);
}

static int
Controller_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
Controller_get_hx_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_hx_config_nget, self->data_ptr);
}

static int
Controller_set_hx_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_hx_config_nset, self->data_ptr);
}

static PyObject *
Controller_get_is_hx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_is_hx_nget, self->data_ptr);
}

static int
Controller_set_is_hx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_is_hx_nset, self->data_ptr);
}

static PyObject *
Controller_get_nodes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_nodes_nget, self->data_ptr);
}

static int
Controller_set_nodes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_nodes_nset, self->data_ptr);
}

static PyObject *
Controller_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_pb_fixed_par_nget, self->data_ptr);
}

static int
Controller_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
Controller_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_pb_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_q_max_aux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_q_max_aux_nget, self->data_ptr);
}

static int
Controller_set_q_max_aux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_q_max_aux_nset, self->data_ptr);
}

static PyObject *
Controller_get_q_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_q_pb_design_nget, self->data_ptr);
}

static int
Controller_set_q_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_q_pb_design_nset, self->data_ptr);
}

static PyObject *
Controller_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_q_sby_frac_nget, self->data_ptr);
}

static int
Controller_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Controller_get_sf_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_sf_type_nget, self->data_ptr);
}

static int
Controller_set_sf_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_sf_type_nset, self->data_ptr);
}

static PyObject *
Controller_get_store_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_Controller_store_fl_props_mget, self->data_ptr);
}

static int
Controller_set_store_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_Controller_store_fl_props_mset, self->data_ptr);
}

static PyObject *
Controller_get_store_fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_store_fluid_nget, self->data_ptr);
}

static int
Controller_set_store_fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_store_fluid_nset, self->data_ptr);
}

static PyObject *
Controller_get_t_ch_out_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_t_ch_out_max_nget, self->data_ptr);
}

static int
Controller_set_t_ch_out_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_t_ch_out_max_nset, self->data_ptr);
}

static PyObject *
Controller_get_t_dis_out_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_t_dis_out_min_nget, self->data_ptr);
}

static int
Controller_set_t_dis_out_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_t_dis_out_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_t_standby_reset(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_t_standby_reset_nget, self->data_ptr);
}

static int
Controller_set_t_standby_reset(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_t_standby_reset_nset, self->data_ptr);
}

static PyObject *
Controller_get_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tank_max_heat_nget, self->data_ptr);
}

static int
Controller_set_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
Controller_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tank_pairs_nget, self->data_ptr);
}

static int
Controller_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tank_pairs_nset, self->data_ptr);
}

static PyObject *
Controller_get_tc_fill(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tc_fill_nget, self->data_ptr);
}

static int
Controller_set_tc_fill(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tc_fill_nset, self->data_ptr);
}

static PyObject *
Controller_get_tc_void(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tc_void_nget, self->data_ptr);
}

static int
Controller_set_tc_void(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tc_void_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tes_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_tes_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tes_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tes_type_nget, self->data_ptr);
}

static int
Controller_set_tes_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tes_type_nset, self->data_ptr);
}

static PyObject *
Controller_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_tshours_nget, self->data_ptr);
}

static int
Controller_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_tshours_nset, self->data_ptr);
}

static PyObject *
Controller_get_tslogic_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Controller_tslogic_a_aget, self->data_ptr);
}

static int
Controller_set_tslogic_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Controller_tslogic_a_aset, self->data_ptr);
}

static PyObject *
Controller_get_tslogic_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Controller_tslogic_b_aget, self->data_ptr);
}

static int
Controller_set_tslogic_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Controller_tslogic_b_aset, self->data_ptr);
}

static PyObject *
Controller_get_tslogic_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Controller_tslogic_c_aget, self->data_ptr);
}

static int
Controller_set_tslogic_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Controller_tslogic_c_aset, self->data_ptr);
}

static PyObject *
Controller_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_u_tank_nget, self->data_ptr);
}

static int
Controller_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_u_tank_nset, self->data_ptr);
}

static PyObject *
Controller_get_vol_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Controller_vol_tank_nget, self->data_ptr);
}

static int
Controller_set_vol_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Controller_vol_tank_nset, self->data_ptr);
}

static PyGetSetDef Controller_getset[] = {
{"T_set_aux", (getter)Controller_get_T_set_aux,(setter)Controller_set_T_set_aux,
	PyDoc_STR("*float*: Aux heater outlet temp set point [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_tank_cold_ini", (getter)Controller_get_T_tank_cold_ini,(setter)Controller_set_T_tank_cold_ini,
	PyDoc_STR("*float*: Initial cold tank fluid tmeperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"V_tank_hot_ini", (getter)Controller_get_V_tank_hot_ini,(setter)Controller_set_V_tank_hot_ini,
	PyDoc_STR("*float*: Initial hot tank fluid volume [m3]\n\n**Required:**\nTrue"),
 	NULL},
{"W_pb_design", (getter)Controller_get_W_pb_design,(setter)Controller_set_W_pb_design,
	PyDoc_STR("*float*: Rated plant capacity [MWe]\n\n**Required:**\nTrue"),
 	NULL},
{"aux_array", (getter)Controller_get_aux_array,(setter)Controller_set_aux_array,
	PyDoc_STR("*sequence*: Coefficients for auxiliary heater parasitics calcs [-]\n\n**Required:**\nTrue"),
 	NULL},
{"bop_array", (getter)Controller_get_bop_array,(setter)Controller_set_bop_array,
	PyDoc_STR("*sequence*: Coefficients for balance of plant parasitics calcs [-]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_Thtr", (getter)Controller_get_cold_tank_Thtr,(setter)Controller_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable cold tank HTF temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_cutoff_frac", (getter)Controller_get_cycle_cutoff_frac,(setter)Controller_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown [-]\n\n**Required:**\nTrue"),
 	NULL},
{"cycle_max_frac", (getter)Controller_get_cycle_max_frac,(setter)Controller_set_cycle_max_frac,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"dt_cold", (getter)Controller_get_dt_cold,(setter)Controller_set_dt_cold,
	PyDoc_STR("*float*: Cold side HX approach temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"dt_hot", (getter)Controller_get_dt_hot,(setter)Controller_set_dt_hot,
	PyDoc_STR("*float*: Hot side HX approach temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"f_tc_cold", (getter)Controller_get_f_tc_cold,(setter)Controller_set_f_tc_cold,
	PyDoc_STR("*float*: 0=entire tank is hot, 1=entire tank is cold [-]\n\n**Required:**\nTrue"),
 	NULL},
{"ffrac", (getter)Controller_get_ffrac,(setter)Controller_set_ffrac,
	PyDoc_STR("*sequence*: Fossil dispatch logic [-]\n\n**Required:**\nTrue"),
 	NULL},
{"field_fl_props", (getter)Controller_get_field_fl_props,(setter)Controller_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
{"fossil_mode", (getter)Controller_get_fossil_mode,(setter)Controller_set_fossil_mode,
	PyDoc_STR("*float*: Fossil backup mode 1=Normal 2=Topping [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank", (getter)Controller_get_h_tank,(setter)Controller_set_h_tank,
	PyDoc_STR("*float*: Total height of tank (height of HTF when tank is full [m]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank_min", (getter)Controller_get_h_tank_min,(setter)Controller_set_h_tank_min,
	PyDoc_STR("*float*: Minimum allowable HTF height in storage tank [m]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_Thtr", (getter)Controller_get_hot_tank_Thtr,(setter)Controller_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable hot tank HTF temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"hx_config", (getter)Controller_get_hx_config,(setter)Controller_set_hx_config,
	PyDoc_STR("*float*: HX configuration [-]\n\n**Required:**\nTrue"),
 	NULL},
{"is_hx", (getter)Controller_get_is_hx,(setter)Controller_set_is_hx,
	PyDoc_STR("*float*: Heat exchanger (HX) exists (1=yes, 0=no) [-]\n\n**Required:**\nTrue"),
 	NULL},
{"nodes", (getter)Controller_get_nodes,(setter)Controller_set_nodes,
	PyDoc_STR("*float*: Nodes modeled in the flow path [-]\n\n**Required:**\nTrue"),
 	NULL},
{"pb_fixed_par", (getter)Controller_get_pb_fixed_par,(setter)Controller_set_pb_fixed_par,
	PyDoc_STR("*float*: Fraction of rated gross power constantly consumed [-]\n\n**Required:**\nTrue"),
 	NULL},
{"pb_pump_coef", (getter)Controller_get_pb_pump_coef,(setter)Controller_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
{"q_max_aux", (getter)Controller_get_q_max_aux,(setter)Controller_set_q_max_aux,
	PyDoc_STR("*float*: Max heat rate of auxiliary heater [MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"q_pb_design", (getter)Controller_get_q_pb_design,(setter)Controller_set_q_pb_design,
	PyDoc_STR("*float*: Design heat input to power block [MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"q_sby_frac", (getter)Controller_get_q_sby_frac,(setter)Controller_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby [-]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_type", (getter)Controller_get_sf_type,(setter)Controller_set_sf_type,
	PyDoc_STR("*float*: Solar field type, 1 = trough, 2 = tower [-]\n\n**Required:**\nTrue"),
 	NULL},
{"store_fl_props", (getter)Controller_get_store_fl_props,(setter)Controller_set_store_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined storage fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
{"store_fluid", (getter)Controller_get_store_fluid,(setter)Controller_set_store_fluid,
	PyDoc_STR("*float*: Material number for storage fluid [-]\n\n**Required:**\nTrue"),
 	NULL},
{"t_ch_out_max", (getter)Controller_get_t_ch_out_max,(setter)Controller_set_t_ch_out_max,
	PyDoc_STR("*float*: Max allowable cold side outlet temp during charge [C]\n\n**Required:**\nTrue"),
 	NULL},
{"t_dis_out_min", (getter)Controller_get_t_dis_out_min,(setter)Controller_set_t_dis_out_min,
	PyDoc_STR("*float*: Min allowable hot side outlet temp during discharge [C]\n\n**Required:**\nTrue"),
 	NULL},
{"t_standby_reset", (getter)Controller_get_t_standby_reset,(setter)Controller_set_t_standby_reset,
	PyDoc_STR("*float*: Maximum allowable time for PB standby operation [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"tank_max_heat", (getter)Controller_get_tank_max_heat,(setter)Controller_set_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for tank heating [MW]\n\n**Required:**\nTrue"),
 	NULL},
{"tank_pairs", (getter)Controller_get_tank_pairs,(setter)Controller_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"tc_fill", (getter)Controller_get_tc_fill,(setter)Controller_set_tc_fill,
	PyDoc_STR("*float*: Thermocline fill material [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tc_void", (getter)Controller_get_tc_void,(setter)Controller_set_tc_void,
	PyDoc_STR("*float*: Thermocline void fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_pump_coef", (getter)Controller_get_tes_pump_coef,(setter)Controller_set_tes_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through tes loop [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
{"tes_type", (getter)Controller_get_tes_type,(setter)Controller_set_tes_type,
	PyDoc_STR("*float*: 1=2-tank, 2=thermocline [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tshours", (getter)Controller_get_tshours,(setter)Controller_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"tslogic_a", (getter)Controller_get_tslogic_a,(setter)Controller_set_tslogic_a,
	PyDoc_STR("*sequence*: Dispatch logic without solar [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tslogic_b", (getter)Controller_get_tslogic_b,(setter)Controller_set_tslogic_b,
	PyDoc_STR("*sequence*: Dispatch logic with solar [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tslogic_c", (getter)Controller_get_tslogic_c,(setter)Controller_set_tslogic_c,
	PyDoc_STR("*sequence*: Dispatch logic for turbine load fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)Controller_get_u_tank,(setter)Controller_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
{"vol_tank", (getter)Controller_get_vol_tank,(setter)Controller_set_vol_tank,
	PyDoc_STR("*float*: Total tank volume, including unusable HTF at bottom [m3]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controller_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.Controller",             /*tp_name*/
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
 * TouTranslator Group
 */ 

static PyTypeObject TouTranslator_Type;

static PyObject *
TouTranslator_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "TouTranslator")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "TouTranslator")){
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
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_TouTranslator_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef TouTranslator_getset[] = {
{"weekday_schedule", (getter)TouTranslator_get_weekday_schedule,(setter)TouTranslator_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: Dispatch 12mx24h schedule for week days\n\n**Required:**\nTrue"),
 	NULL},
{"weekend_schedule", (getter)TouTranslator_get_weekend_schedule,(setter)TouTranslator_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: Dispatch 12mx24h schedule for weekends\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TouTranslator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.TouTranslator",             /*tp_name*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "Powerblock")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "Powerblock")){
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
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_CT_nget, self->data_ptr);
}

static int
Powerblock_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_CT_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_T_approach_nget, self->data_ptr);
}

static int
Powerblock_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_T_approach_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_pc_config_nget, self->data_ptr);
}

static int
Powerblock_set_pc_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_pc_config_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_startup_time_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_tech_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Powerblock_tech_type_nget, self->data_ptr);
}

static int
Powerblock_set_tech_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Powerblock_tech_type_nset, self->data_ptr);
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
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n**Required:**\nRequired if pc_config=0"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Reference conversion efficiency at design condition [none]\n\n**Required:**\nTrue"),
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
		"TroughPhysicalCspSolver.Powerblock",             /*tp_name*/
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
UserDefinedPC_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "UserDefinedPC")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "UserDefinedPC")){
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
UserDefinedPC_get_ud_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_des_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_T_amb_high(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_high_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_amb_high(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_high_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_T_amb_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_amb_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_T_amb_low(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_low_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_amb_low(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_amb_low_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_T_htf_high(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_htf_high_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_htf_high(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_htf_high_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_T_htf_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_htf_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_htf_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_T_htf_low(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_htf_low_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_T_htf_low(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_T_htf_low_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_f_W_dot_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_f_W_dot_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_f_W_dot_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_f_W_dot_cool_des_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_m_dot_htf_high(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_htf_high_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_m_dot_htf_high(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_htf_high_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_m_dot_htf_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_htf_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_m_dot_htf_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_m_dot_htf_low(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_htf_low_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_m_dot_htf_low(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_htf_low_nset, self->data_ptr);
}

static PyObject *
UserDefinedPC_get_ud_m_dot_water_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_water_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPC_set_ud_m_dot_water_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_UserDefinedPC_ud_m_dot_water_cool_des_nset, self->data_ptr);
}

static PyGetSetDef UserDefinedPC_getset[] = {
{"ud_T_amb_des", (getter)UserDefinedPC_get_ud_T_amb_des,(setter)UserDefinedPC_set_ud_T_amb_des,
	PyDoc_STR("*float*: Ambient temperature at user-defined power cycle design point [C]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_T_amb_high", (getter)UserDefinedPC_get_ud_T_amb_high,(setter)UserDefinedPC_set_ud_T_amb_high,
	PyDoc_STR("*float*: High level ambient temperature for HTF mass flow rate parametric [C]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_T_amb_ind_od", (getter)UserDefinedPC_get_ud_T_amb_ind_od,(setter)UserDefinedPC_set_ud_T_amb_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design table of user-defined power cycle performance formed from parametric on T_amb [C]\n\n**Required:**\nFalse. Automatically set to [[0]] if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ud_T_amb_low", (getter)UserDefinedPC_get_ud_T_amb_low,(setter)UserDefinedPC_set_ud_T_amb_low,
	PyDoc_STR("*float*: Low level ambient temperature for HTF mass flow rate parametric [C]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_T_htf_high", (getter)UserDefinedPC_get_ud_T_htf_high,(setter)UserDefinedPC_set_ud_T_htf_high,
	PyDoc_STR("*float*: High level HTF inlet temperature for T_amb parametric [C]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_T_htf_ind_od", (getter)UserDefinedPC_get_ud_T_htf_ind_od,(setter)UserDefinedPC_set_ud_T_htf_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design table of user-defined power cycle performance formed from parametric on T_htf_hot [C]\n\n**Required:**\nFalse. Automatically set to [[0]] if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ud_T_htf_low", (getter)UserDefinedPC_get_ud_T_htf_low,(setter)UserDefinedPC_set_ud_T_htf_low,
	PyDoc_STR("*float*: Low level HTF inlet temperature for T_amb parametric [C]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_f_W_dot_cool_des", (getter)UserDefinedPC_get_ud_f_W_dot_cool_des,(setter)UserDefinedPC_set_ud_f_W_dot_cool_des,
	PyDoc_STR("*float*: Percent of user-defined power cycle design gross output consumed by cooling [%]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_ind_od", (getter)UserDefinedPC_get_ud_ind_od,(setter)UserDefinedPC_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n**Required:**\nFalse. Automatically set to [[0]] if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ud_m_dot_htf_high", (getter)UserDefinedPC_get_ud_m_dot_htf_high,(setter)UserDefinedPC_set_ud_m_dot_htf_high,
	PyDoc_STR("*float*: High level normalized HTF mass flow rate for T_HTF parametric [-]\n\n**Required:**\nRequired if pc_config=1"),
 	NULL},
{"ud_m_dot_htf_ind_od", (getter)UserDefinedPC_get_ud_m_dot_htf_ind_od,(setter)UserDefinedPC_set_ud_m_dot_htf_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design table of user-defined power cycle performance formed from parametric on m_dot_htf [ND]\n\n**Required:**\nFalse. Automatically set to [[0]] if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ud_m_dot_htf_low", (getter)UserDefinedPC_get_ud_m_dot_htf_low,(setter)UserDefinedPC_set_ud_m_dot_htf_low,
	PyDoc_STR("*float*: Low level normalized HTF mass flow rate for T_HTF parametric [-]\n\n**Required:**\nRequired if pc_config=1"),
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
		"TroughPhysicalCspSolver.UserDefinedPC",             /*tp_name*/
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
Enet_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "Enet")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "Enet")){
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
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Enet_eta_lhv_nget, self->data_ptr);
}

static int
Enet_set_eta_lhv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Enet_eta_lhv_nset, self->data_ptr);
}

static PyObject *
Enet_get_eta_tes_htr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Enet_eta_tes_htr_nget, self->data_ptr);
}

static int
Enet_set_eta_tes_htr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalCspSolver_Enet_eta_tes_htr_nset, self->data_ptr);
}

static PyGetSetDef Enet_getset[] = {
{"eta_lhv", (getter)Enet_get_eta_lhv,(setter)Enet_set_eta_lhv,
	PyDoc_STR("*float*: Fossil fuel lower heating value - Thermal power generated per unit fuel [MW/MMBTU]\n\n**Required:**\nTrue"),
 	NULL},
{"eta_tes_htr", (getter)Enet_get_eta_tes_htr,(setter)Enet_set_eta_tes_htr,
	PyDoc_STR("*float*: Thermal storage tank heater efficiency (fp_mode=1 only) [none]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Enet_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.Enet",             /*tp_name*/
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
Outputs_new(SAM_TroughPhysicalCspSolver data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalCspSolver", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalCspSolver", "Outputs")){
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
Outputs_get_P_cooling_tower_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_P_cooling_tower_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_P_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_out_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_P_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_plant_balance_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_P_plant_balance_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_tower_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_P_tower_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_Q_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_iter_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_iter_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_obj_relax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_obj_relax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_objective_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_objective_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_pceff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_pceff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_presolve_nconstr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_presolve_nconstr_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_presolve_nvar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_presolve_nvar_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qpbsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_qpbsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsf_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_qsf_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfprod_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_qsfprod_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfsu_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_qsfsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rel_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_rel_mip_gap_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rev_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_rev_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_iter(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_solve_iter_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_solve_state_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_solve_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time_ann(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_solve_time_ann_nget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_subopt_flag(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_subopt_flag_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_tes_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_tes_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_thermeff_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_thermeff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_wpb_expected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_disp_wpb_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_map_out(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_Outputs_eta_map_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_flux_maps_out(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalCspSolver_Outputs_flux_maps_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_htf_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_sb_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_is_pc_sb_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_su_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_is_pc_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_rec_su_allowed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_is_rec_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalCspSolver_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_m_dot_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_m_dot_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_ch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_m_dot_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_m_dot_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_n_op_modes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_n_op_modes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_a(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_operating_modes_a_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_operating_modes_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_c(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_operating_modes_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pparasi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_pparasi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pricing_mult(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_pricing_mult_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dc_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_on(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_est_cr_on_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_su(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_est_cr_su_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_ch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_est_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_est_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_pc_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_min(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_pc_min_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_sb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_pc_sb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_dot_pc_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pc_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_q_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalCspSolver_Outputs_tou_value_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"P_cooling_tower_tot", (getter)Outputs_get_P_cooling_tower_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"P_fixed", (getter)Outputs_get_P_fixed,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power fixed load [MWe]"),
 	NULL},
{"P_out_net", (getter)Outputs_get_P_out_net,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid [MWe]"),
 	NULL},
{"P_plant_balance_tot", (getter)Outputs_get_P_plant_balance_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power generation-dependent load [MWe]"),
 	NULL},
{"P_tower_pump", (getter)Outputs_get_P_tower_pump,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power receiver/tower HTF pump [MWe]"),
 	NULL},
{"Q_thermal", (getter)Outputs_get_Q_thermal,(setter)0,
	PyDoc_STR("*sequence*: Rec. thermal power to HTF less piping loss [MWt]"),
 	NULL},
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Electrical source - Power cycle gross output [kWhe]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual total electric power to grid [kWhe]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
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
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	PyDoc_STR("*sequence*: Field optical focus fraction"),
 	NULL},
{"disp_iter_ann", (getter)Outputs_get_disp_iter_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch solver iterations"),
 	NULL},
{"disp_obj_relax", (getter)Outputs_get_disp_obj_relax,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function - relaxed max"),
 	NULL},
{"disp_objective", (getter)Outputs_get_disp_objective,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function value"),
 	NULL},
{"disp_objective_ann", (getter)Outputs_get_disp_objective_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch objective func. value"),
 	NULL},
{"disp_pceff_expected", (getter)Outputs_get_disp_pceff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle efficiency adj."),
 	NULL},
{"disp_presolve_nconstr", (getter)Outputs_get_disp_presolve_nconstr,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of constraints in problem"),
 	NULL},
{"disp_presolve_nconstr_ann", (getter)Outputs_get_disp_presolve_nconstr_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch problem constraint count"),
 	NULL},
{"disp_presolve_nvar", (getter)Outputs_get_disp_presolve_nvar,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of variables in problem"),
 	NULL},
{"disp_presolve_nvar_ann", (getter)Outputs_get_disp_presolve_nvar_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch problem variable count"),
 	NULL},
{"disp_qpbsu_expected", (getter)Outputs_get_disp_qpbsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle startup energy [MWht]"),
 	NULL},
{"disp_qsf_expected", (getter)Outputs_get_disp_qsf_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field available energy [MWt]"),
 	NULL},
{"disp_qsfprod_expected", (getter)Outputs_get_disp_qsfprod_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field generation [MWt]"),
 	NULL},
{"disp_qsfsu_expected", (getter)Outputs_get_disp_qsfsu_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected solar field startup enegy [MWt]"),
 	NULL},
{"disp_rel_mip_gap", (getter)Outputs_get_disp_rel_mip_gap,(setter)0,
	PyDoc_STR("*sequence*: Dispatch relative MIP gap"),
 	NULL},
{"disp_rev_expected", (getter)Outputs_get_disp_rev_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected revenue factor"),
 	NULL},
{"disp_solve_iter", (getter)Outputs_get_disp_solve_iter,(setter)0,
	PyDoc_STR("*sequence*: Dispatch iterations count"),
 	NULL},
{"disp_solve_state", (getter)Outputs_get_disp_solve_state,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver state"),
 	NULL},
{"disp_solve_time", (getter)Outputs_get_disp_solve_time,(setter)0,
	PyDoc_STR("*sequence*: Dispatch solver time [sec]"),
 	NULL},
{"disp_solve_time_ann", (getter)Outputs_get_disp_solve_time_ann,(setter)0,
	PyDoc_STR("*float*: Annual sum of dispatch solver time"),
 	NULL},
{"disp_subopt_flag", (getter)Outputs_get_disp_subopt_flag,(setter)0,
	PyDoc_STR("*sequence*: Dispatch suboptimal solution flag"),
 	NULL},
{"disp_tes_expected", (getter)Outputs_get_disp_tes_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected TES charge level [MWht]"),
 	NULL},
{"disp_thermeff_expected", (getter)Outputs_get_disp_thermeff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected SF thermal efficiency adj."),
 	NULL},
{"disp_wpb_expected", (getter)Outputs_get_disp_wpb_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power generation [MWe]"),
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge state [MWht]"),
 	NULL},
{"eta_map_out", (getter)Outputs_get_eta_map_out,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Solar field optical efficiencies"),
 	NULL},
{"flux_maps_out", (getter)Outputs_get_flux_maps_out,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Flux map intensities"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid w/ avail. derate [kWe]"),
 	NULL},
{"htf_pump_power", (getter)Outputs_get_htf_pump_power,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power TES and Cycle HTF pump [MWe]"),
 	NULL},
{"is_pc_sb_allowed", (getter)Outputs_get_is_pc_sb_allowed,(setter)0,
	PyDoc_STR("*sequence*: is power cycle standby allowed"),
 	NULL},
{"is_pc_su_allowed", (getter)Outputs_get_is_pc_su_allowed,(setter)0,
	PyDoc_STR("*sequence*: is power cycle startup allowed"),
 	NULL},
{"is_rec_su_allowed", (getter)Outputs_get_is_rec_su_allowed,(setter)0,
	PyDoc_STR("*sequence*: is receiver startup allowed"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"m_dot_balance", (getter)Outputs_get_m_dot_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative mass flow balance error"),
 	NULL},
{"m_dot_pc", (getter)Outputs_get_m_dot_pc,(setter)0,
	PyDoc_STR("*sequence*: PC HTF mass flow rate [kg/hr]"),
 	NULL},
{"m_dot_rec", (getter)Outputs_get_m_dot_rec,(setter)0,
	PyDoc_STR("*sequence*: Rec. mass flow rate [kg/hr]"),
 	NULL},
{"m_dot_tes_ch", (getter)Outputs_get_m_dot_tes_ch,(setter)0,
	PyDoc_STR("*sequence*: TES charge mass flow rate [kg/hr]"),
 	NULL},
{"m_dot_tes_dc", (getter)Outputs_get_m_dot_tes_dc,(setter)0,
	PyDoc_STR("*sequence*: TES discharge mass flow rate [kg/hr]"),
 	NULL},
{"n_op_modes", (getter)Outputs_get_n_op_modes,(setter)0,
	PyDoc_STR("*sequence*: Operating modes in reporting timestep"),
 	NULL},
{"op_mode_1", (getter)Outputs_get_op_mode_1,(setter)0,
	PyDoc_STR("*sequence*: 1st operating mode"),
 	NULL},
{"op_mode_2", (getter)Outputs_get_op_mode_2,(setter)0,
	PyDoc_STR("*sequence*: 2nd op. mode, if applicable"),
 	NULL},
{"op_mode_3", (getter)Outputs_get_op_mode_3,(setter)0,
	PyDoc_STR("*sequence*: 3rd op. mode, if applicable"),
 	NULL},
{"operating_modes_a", (getter)Outputs_get_operating_modes_a,(setter)0,
	PyDoc_STR("*sequence*: First 3 operating modes tried"),
 	NULL},
{"operating_modes_b", (getter)Outputs_get_operating_modes_b,(setter)0,
	PyDoc_STR("*sequence*: Next 3 operating modes tried"),
 	NULL},
{"operating_modes_c", (getter)Outputs_get_operating_modes_c,(setter)0,
	PyDoc_STR("*sequence*: Final 3 operating modes tried"),
 	NULL},
{"pparasi", (getter)Outputs_get_pparasi,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power heliostat drives [MWe]"),
 	NULL},
{"pricing_mult", (getter)Outputs_get_pricing_mult,(setter)0,
	PyDoc_STR("*sequence*: PPA price multiplier"),
 	NULL},
{"q_balance", (getter)Outputs_get_q_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative energy balance error"),
 	NULL},
{"q_ch_tes", (getter)Outputs_get_q_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge thermal power [MWt]"),
 	NULL},
{"q_dc_tes", (getter)Outputs_get_q_dc_tes,(setter)0,
	PyDoc_STR("*sequence*: TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_est_cr_on", (getter)Outputs_get_q_dot_est_cr_on,(setter)0,
	PyDoc_STR("*sequence*: Estimate rec. thermal power TO HTF [MWt]"),
 	NULL},
{"q_dot_est_cr_su", (getter)Outputs_get_q_dot_est_cr_su,(setter)0,
	PyDoc_STR("*sequence*: Estimate rec. startup thermal power [MWt]"),
 	NULL},
{"q_dot_est_tes_ch", (getter)Outputs_get_q_dot_est_tes_ch,(setter)0,
	PyDoc_STR("*sequence*: Estimate max TES charge thermal power [MWt]"),
 	NULL},
{"q_dot_est_tes_dc", (getter)Outputs_get_q_dot_est_tes_dc,(setter)0,
	PyDoc_STR("*sequence*: Estimate max TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_pc_max", (getter)Outputs_get_q_dot_pc_max,(setter)0,
	PyDoc_STR("*sequence*: Max thermal power to PC [MWt]"),
 	NULL},
{"q_dot_pc_min", (getter)Outputs_get_q_dot_pc_min,(setter)0,
	PyDoc_STR("*sequence*: Thermal power for PC min operation [MWt]"),
 	NULL},
{"q_dot_pc_sb", (getter)Outputs_get_q_dot_pc_sb,(setter)0,
	PyDoc_STR("*sequence*: Thermal power for PC standby [MWt]"),
 	NULL},
{"q_dot_pc_startup", (getter)Outputs_get_q_dot_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal power [MWt]"),
 	NULL},
{"q_dot_pc_target", (getter)Outputs_get_q_dot_pc_target,(setter)0,
	PyDoc_STR("*sequence*: Target thermal power to PC [MWt]"),
 	NULL},
{"q_heater", (getter)Outputs_get_q_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"q_pb", (getter)Outputs_get_q_pb,(setter)0,
	PyDoc_STR("*sequence*: PC input energy [MWt]"),
 	NULL},
{"q_pc_startup", (getter)Outputs_get_q_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal energy [MWht]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"tank_losses", (getter)Outputs_get_tank_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: CSP operating Time-of-use value"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver.Outputs",             /*tp_name*/
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
 * TroughPhysicalCspSolver
 */

static PyTypeObject TroughPhysicalCspSolver_Type;

static CmodObject *
newTroughPhysicalCspSolverObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TroughPhysicalCspSolver_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* Trough_obj = Trough_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Trough", Trough_obj);
	Py_DECREF(Trough_obj);

	PyObject* TimeOfDelivery_obj = TimeOfDelivery_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDelivery", TimeOfDelivery_obj);
	Py_DECREF(TimeOfDelivery_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* Controller_obj = Controller_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controller", Controller_obj);
	Py_DECREF(Controller_obj);

	PyObject* TouTranslator_obj = TouTranslator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TouTranslator", TouTranslator_obj);
	Py_DECREF(TouTranslator_obj);

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

/* TroughPhysicalCspSolver methods */

static void
TroughPhysicalCspSolver_dealloc(CmodObject *self)
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
TroughPhysicalCspSolver_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TroughPhysicalCspSolver_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TroughPhysicalCspSolver_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysicalCspSolver"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TroughPhysicalCspSolver_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysicalCspSolver"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TroughPhysicalCspSolver_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TroughPhysicalCspSolver_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TroughPhysicalCspSolver_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TroughPhysicalCspSolver_methods[] = {
		{"execute",           (PyCFunction)TroughPhysicalCspSolver_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TroughPhysicalCspSolver_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TroughPhysicalCspSolver_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TroughPhysicalCspSolver_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TroughPhysicalCspSolver_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TroughPhysicalCspSolver_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TroughPhysicalCspSolver_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TroughPhysicalCspSolver_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TroughPhysicalCspSolver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalCspSolver",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TroughPhysicalCspSolver_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TroughPhysicalCspSolver_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TroughPhysicalCspSolver_getattro, /*tp_getattro*/
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
		TroughPhysicalCspSolver_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TroughPhysicalCspSolver object */

static PyObject *
TroughPhysicalCspSolver_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTroughPhysicalCspSolverObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysicalCspSolver_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalCspSolverObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysicalCspSolver_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalCspSolverObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysicalCspSolver", def) < 0) {
		TroughPhysicalCspSolver_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TroughPhysicalCspSolver_from_existing(PyObject *self, PyObject *args)
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

	rv = newTroughPhysicalCspSolverObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysicalCspSolver", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TroughPhysicalCspSolverModule_methods[] = {
		{"new",             TroughPhysicalCspSolver_new,         METH_VARARGS,
				PyDoc_STR("new() -> TroughPhysicalCspSolver")},
		{"default",             TroughPhysicalCspSolver_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TroughPhysicalCspSolver\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TroughPhysicalCspSolver_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TroughPhysicalCspSolver\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TroughPhysicalCspSolver_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TroughPhysicalCspSolver\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "TroughPhysicalCspSolver");


static int
TroughPhysicalCspSolverModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TroughPhysicalCspSolver_Type.tp_dict = PyDict_New();
	if (!TroughPhysicalCspSolver_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TroughPhysicalCspSolver_Type
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
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the Trough type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&Trough_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"Trough",
				(PyObject*)&Trough_Type);
	Py_DECREF(&Trough_Type);

	/// Add the TimeOfDelivery type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&TimeOfDelivery_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"TimeOfDelivery",
				(PyObject*)&TimeOfDelivery_Type);
	Py_DECREF(&TimeOfDelivery_Type);

	/// Add the SolarField type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the Controller type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&Controller_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"Controller",
				(PyObject*)&Controller_Type);
	Py_DECREF(&Controller_Type);

	/// Add the TouTranslator type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&TouTranslator_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"TouTranslator",
				(PyObject*)&TouTranslator_Type);
	Py_DECREF(&TouTranslator_Type);

	/// Add the Powerblock type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the UserDefinedPC type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&UserDefinedPC_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"UserDefinedPC",
				(PyObject*)&UserDefinedPC_Type);
	Py_DECREF(&UserDefinedPC_Type);

	/// Add the Enet type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&Enet_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"Enet",
				(PyObject*)&Enet_Type);
	Py_DECREF(&Enet_Type);

	/// Add the Outputs type object to TroughPhysicalCspSolver_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalCspSolver_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TroughPhysicalCspSolver type object to the module
	if (PyType_Ready(&TroughPhysicalCspSolver_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TroughPhysicalCspSolver",
				(PyObject*)&TroughPhysicalCspSolver_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TroughPhysicalCspSolverModule_slots[] = {
		{Py_mod_exec, TroughPhysicalCspSolverModule_exec},
		{0, NULL},
};

static struct PyModuleDef TroughPhysicalCspSolverModule = {
		PyModuleDef_HEAD_INIT,
		"TroughPhysicalCspSolver",
		module_doc,
		0,
		TroughPhysicalCspSolverModule_methods,
		TroughPhysicalCspSolverModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TroughPhysicalCspSolver(void)
{
	return PyModuleDef_Init(&TroughPhysicalCspSolverModule);
}