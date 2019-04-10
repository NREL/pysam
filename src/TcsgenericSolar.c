#include <Python.h>

#include <SAM_TcsgenericSolar.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Weather Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsgenericSolar   data_ptr;
} WeatherObject;

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = Weather_Type.tp_alloc(&Weather_Type,0);

	WeatherObject* Weather_obj = (WeatherObject*)new_obj;

	Weather_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Weather methods */

static PyObject *
Weather_assign(WeatherObject *self, PyObject *args)
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
Weather_export(WeatherObject *self, PyObject *args)
{
	PyTypeObject* tp = &Weather_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Weather_methods[] = {
		{"assign",            (PyCFunction)Weather_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_azimuth(WeatherObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Weather_azimuth_fget, self->data_ptr);
}

static int
Weather_set_azimuth(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Weather_azimuth_fset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(WeatherObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsgenericSolar_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsgenericSolar_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(WeatherObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Weather_tilt_fget, self->data_ptr);
}

static int
Weather_set_tilt(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Weather_tilt_fset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(WeatherObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Weather_track_mode_fget, self->data_ptr);
}

static int
Weather_set_track_mode(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Weather_track_mode_fset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"azimuth", (getter)Weather_get_azimuth,(setter)Weather_set_azimuth,
	"Azimuth angle of surface/axis [], number.\n Required if: *.",
 	NULL},
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	"local weather file path [], string.\n Constraints: LOCAL_FILE; Required if: *.",
 	NULL},
{"tilt", (getter)Weather_get_tilt,(setter)Weather_set_tilt,
	"Tilt angle of surface/axis [], number.\n Required if: *.",
 	NULL},
{"track_mode", (getter)Weather_get_track_mode,(setter)Weather_set_track_mode,
	"Tracking mode [], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.Weather",             /*tp_name*/
		sizeof(WeatherObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Weather_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Weather_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * GenericSolar Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsgenericSolar   data_ptr;
} GenericSolarObject;

static PyTypeObject GenericSolar_Type;

static PyObject *
GenericSolar_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = GenericSolar_Type.tp_alloc(&GenericSolar_Type,0);

	GenericSolarObject* GenericSolar_obj = (GenericSolarObject*)new_obj;

	GenericSolar_obj->data_ptr = data_ptr;

	return new_obj;
}

/* GenericSolar methods */

static PyObject *
GenericSolar_assign(GenericSolarObject *self, PyObject *args)
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
GenericSolar_export(GenericSolarObject *self, PyObject *args)
{
	PyTypeObject* tp = &GenericSolar_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GenericSolar_methods[] = {
		{"assign",            (PyCFunction)GenericSolar_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)GenericSolar_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GenericSolar_get_system_capacity(GenericSolarObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_GenericSolar_system_capacity_fget, self->data_ptr);
}

static int
GenericSolar_set_system_capacity(GenericSolarObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_GenericSolar_system_capacity_fset, self->data_ptr);
}

static PyGetSetDef GenericSolar_getset[] = {
{"system_capacity", (getter)GenericSolar_get_system_capacity,(setter)GenericSolar_set_system_capacity,
	"Nameplate capacity [kW], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GenericSolar_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.GenericSolar",             /*tp_name*/
		sizeof(GenericSolarObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		GenericSolar_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GenericSolar_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * TouTranslator Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsgenericSolar   data_ptr;
} TouTranslatorObject;

static PyTypeObject TouTranslator_Type;

static PyObject *
TouTranslator_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = TouTranslator_Type.tp_alloc(&TouTranslator_Type,0);

	TouTranslatorObject* TouTranslator_obj = (TouTranslatorObject*)new_obj;

	TouTranslator_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TouTranslator methods */

static PyObject *
TouTranslator_assign(TouTranslatorObject *self, PyObject *args)
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
TouTranslator_export(TouTranslatorObject *self, PyObject *args)
{
	PyTypeObject* tp = &TouTranslator_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TouTranslator_methods[] = {
		{"assign",            (PyCFunction)TouTranslator_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)TouTranslator_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TouTranslator_get_weekday_schedule(TouTranslatorObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(TouTranslatorObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(TouTranslatorObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(TouTranslatorObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_TouTranslator_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef TouTranslator_getset[] = {
{"weekday_schedule", (getter)TouTranslator_get_weekday_schedule,(setter)TouTranslator_set_weekday_schedule,
	"12x24 Time of Use Values for week days [], matrix.\n Required if: *.",
 	NULL},
{"weekend_schedule", (getter)TouTranslator_get_weekend_schedule,(setter)TouTranslator_set_weekend_schedule,
	"12x24 Time of Use Values for week end days [], matrix.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TouTranslator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.TouTranslator",             /*tp_name*/
		sizeof(TouTranslatorObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		TouTranslator_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TouTranslator_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Type260 Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsgenericSolar   data_ptr;
} Type260Object;

static PyTypeObject Type260_Type;

static PyObject *
Type260_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = Type260_Type.tp_alloc(&Type260_Type,0);

	Type260Object* Type260_obj = (Type260Object*)new_obj;

	Type260_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Type260 methods */

static PyObject *
Type260_assign(Type260Object *self, PyObject *args)
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
Type260_export(Type260Object *self, PyObject *args)
{
	PyTypeObject* tp = &Type260_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Type260_methods[] = {
		{"assign",            (PyCFunction)Type260_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Type260_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Type260_get_OpticalTable(Type260Object *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_Type260_OpticalTable_mget, self->data_ptr);
}

static int
Type260_set_OpticalTable(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_Type260_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Type260_get_PC_T_corr(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_PC_T_corr_fget, self->data_ptr);
}

static int
Type260_set_PC_T_corr(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_PC_T_corr_fset, self->data_ptr);
}

static PyObject *
Type260_get_T_pcdes(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_T_pcdes_fget, self->data_ptr);
}

static int
Type260_set_T_pcdes(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_T_pcdes_fset, self->data_ptr);
}

static PyObject *
Type260_get_T_sfdes(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_T_sfdes_fget, self->data_ptr);
}

static int
Type260_set_T_sfdes(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_T_sfdes_fset, self->data_ptr);
}

static PyObject *
Type260_get_Wpar_prodD_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_Wpar_prodD_coefs_aget, self->data_ptr);
}

static int
Type260_set_Wpar_prodD_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_Wpar_prodD_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_Wpar_prodQ_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_Wpar_prodQ_coefs_aget, self->data_ptr);
}

static int
Type260_set_Wpar_prodQ_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_Wpar_prodQ_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_Wpar_prodT_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_Wpar_prodT_coefs_aget, self->data_ptr);
}

static int
Type260_set_Wpar_prodT_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_Wpar_prodT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_diswos(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_diswos_aget, self->data_ptr);
}

static int
Type260_set_diswos(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_diswos_aset, self->data_ptr);
}

static PyObject *
Type260_get_disws(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_disws_aget, self->data_ptr);
}

static int
Type260_set_disws(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_disws_aset, self->data_ptr);
}

static PyObject *
Type260_get_etaQ_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_etaQ_coefs_aget, self->data_ptr);
}

static int
Type260_set_etaQ_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_etaQ_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_etaT_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_etaT_coefs_aget, self->data_ptr);
}

static int
Type260_set_etaT_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_etaT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_eta_des(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_eta_des_fget, self->data_ptr);
}

static int
Type260_set_eta_des(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_eta_des_fset, self->data_ptr);
}

static PyObject *
Type260_get_eta_lhv(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_eta_lhv_fget, self->data_ptr);
}

static int
Type260_set_eta_lhv(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_eta_lhv_fset, self->data_ptr);
}

static PyObject *
Type260_get_eta_opt_gen(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_eta_opt_gen_fget, self->data_ptr);
}

static int
Type260_set_eta_opt_gen(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_eta_opt_gen_fset, self->data_ptr);
}

static PyObject *
Type260_get_eta_opt_soil(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_eta_opt_soil_fget, self->data_ptr);
}

static int
Type260_set_eta_opt_soil(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_eta_opt_soil_fset, self->data_ptr);
}

static PyObject *
Type260_get_exergy_table(Type260Object *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsgenericSolar_Type260_exergy_table_mget, self->data_ptr);
}

static int
Type260_set_exergy_table(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsgenericSolar_Type260_exergy_table_mset, self->data_ptr);
}

static PyObject *
Type260_get_f_Wpar_fixed(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_Wpar_fixed_fget, self->data_ptr);
}

static int
Type260_set_f_Wpar_fixed(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_Wpar_fixed_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_Wpar_prod(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_Wpar_prod_fget, self->data_ptr);
}

static int
Type260_set_f_Wpar_prod(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_Wpar_prod_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_charge(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_charge_fget, self->data_ptr);
}

static int
Type260_set_f_charge(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_charge_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_disch(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_disch_fget, self->data_ptr);
}

static int
Type260_set_f_disch(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_disch_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_etes_0(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_etes_0_fget, self->data_ptr);
}

static int
Type260_set_f_etes_0(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_etes_0_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_sfhl_ref(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_sfhl_ref_fget, self->data_ptr);
}

static int
Type260_set_f_sfhl_ref(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_sfhl_ref_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_startup(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_startup_fget, self->data_ptr);
}

static int
Type260_set_f_startup(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_startup_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_teshl_ref(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_teshl_ref_fget, self->data_ptr);
}

static int
Type260_set_f_teshl_ref(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_teshl_ref_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_wmax(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_wmax_fget, self->data_ptr);
}

static int
Type260_set_f_wmax(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_wmax_fset, self->data_ptr);
}

static PyObject *
Type260_get_f_wmin(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_f_wmin_fget, self->data_ptr);
}

static int
Type260_set_f_wmin(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_f_wmin_fset, self->data_ptr);
}

static PyObject *
Type260_get_fdisp(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_fdisp_aget, self->data_ptr);
}

static int
Type260_set_fdisp(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_fdisp_aset, self->data_ptr);
}

static PyObject *
Type260_get_hrs_tes(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_hrs_tes_fget, self->data_ptr);
}

static int
Type260_set_hrs_tes(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_hrs_tes_fset, self->data_ptr);
}

static PyObject *
Type260_get_ibh(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_ibh_fget, self->data_ptr);
}

static int
Type260_set_ibh(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_ibh_fset, self->data_ptr);
}

static PyObject *
Type260_get_ibn(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_ibn_fget, self->data_ptr);
}

static int
Type260_set_ibn(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_ibn_fset, self->data_ptr);
}

static PyObject *
Type260_get_interp_arr(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_interp_arr_fget, self->data_ptr);
}

static int
Type260_set_interp_arr(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_interp_arr_fset, self->data_ptr);
}

static PyObject *
Type260_get_irr_des(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_irr_des_fget, self->data_ptr);
}

static int
Type260_set_irr_des(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_irr_des_fset, self->data_ptr);
}

static PyObject *
Type260_get_istableunsorted(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_istableunsorted_fget, self->data_ptr);
}

static int
Type260_set_istableunsorted(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_istableunsorted_fset, self->data_ptr);
}

static PyObject *
Type260_get_itoth(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_itoth_fget, self->data_ptr);
}

static int
Type260_set_itoth(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_itoth_fset, self->data_ptr);
}

static PyObject *
Type260_get_latitude(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_latitude_fget, self->data_ptr);
}

static int
Type260_set_latitude(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_latitude_fset, self->data_ptr);
}

static PyObject *
Type260_get_longitude(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_longitude_fget, self->data_ptr);
}

static int
Type260_set_longitude(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_longitude_fset, self->data_ptr);
}

static PyObject *
Type260_get_ntod(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_ntod_fget, self->data_ptr);
}

static int
Type260_set_ntod(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_ntod_fset, self->data_ptr);
}

static PyObject *
Type260_get_qdisp(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_qdisp_aget, self->data_ptr);
}

static int
Type260_set_qdisp(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_qdisp_aset, self->data_ptr);
}

static PyObject *
Type260_get_qsf_des(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_qsf_des_fget, self->data_ptr);
}

static int
Type260_set_qsf_des(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_qsf_des_fset, self->data_ptr);
}

static PyObject *
Type260_get_rad_type(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_rad_type_fget, self->data_ptr);
}

static int
Type260_set_rad_type(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_rad_type_fset, self->data_ptr);
}

static PyObject *
Type260_get_sfhlQ_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_sfhlQ_coefs_aget, self->data_ptr);
}

static int
Type260_set_sfhlQ_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_sfhlQ_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_sfhlT_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_sfhlT_coefs_aget, self->data_ptr);
}

static int
Type260_set_sfhlT_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_sfhlT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_sfhlV_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_sfhlV_coefs_aget, self->data_ptr);
}

static int
Type260_set_sfhlV_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_sfhlV_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_solarm(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_solarm_fget, self->data_ptr);
}

static int
Type260_set_solarm(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_solarm_fset, self->data_ptr);
}

static PyObject *
Type260_get_storage_config(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_storage_config_fget, self->data_ptr);
}

static int
Type260_set_storage_config(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_storage_config_fset, self->data_ptr);
}

static PyObject *
Type260_get_tdb(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_tdb_fget, self->data_ptr);
}

static int
Type260_set_tdb(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_tdb_fset, self->data_ptr);
}

static PyObject *
Type260_get_teshlT_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_teshlT_coefs_aget, self->data_ptr);
}

static int
Type260_set_teshlT_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_teshlT_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_teshlX_coefs(Type260Object *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Type260_teshlX_coefs_aget, self->data_ptr);
}

static int
Type260_set_teshlX_coefs(Type260Object *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsgenericSolar_Type260_teshlX_coefs_aset, self->data_ptr);
}

static PyObject *
Type260_get_theta_dep(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_theta_dep_fget, self->data_ptr);
}

static int
Type260_set_theta_dep(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_theta_dep_fset, self->data_ptr);
}

static PyObject *
Type260_get_theta_stow(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_theta_stow_fget, self->data_ptr);
}

static int
Type260_set_theta_stow(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_theta_stow_fset, self->data_ptr);
}

static PyObject *
Type260_get_timezone(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_timezone_fget, self->data_ptr);
}

static int
Type260_set_timezone(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_timezone_fset, self->data_ptr);
}

static PyObject *
Type260_get_twb(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_twb_fget, self->data_ptr);
}

static int
Type260_set_twb(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_twb_fset, self->data_ptr);
}

static PyObject *
Type260_get_vwind(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_vwind_fget, self->data_ptr);
}

static int
Type260_set_vwind(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_vwind_fset, self->data_ptr);
}

static PyObject *
Type260_get_w_des(Type260Object *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Type260_w_des_fget, self->data_ptr);
}

static int
Type260_set_w_des(Type260Object *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsgenericSolar_Type260_w_des_fset, self->data_ptr);
}

static PyGetSetDef Type260_getset[] = {
{"OpticalTable", (getter)Type260_get_OpticalTable,(setter)Type260_set_OpticalTable,
	"Optical table [none], matrix.\n Required if: *.",
 	NULL},
{"PC_T_corr", (getter)Type260_get_PC_T_corr,(setter)Type260_set_PC_T_corr,
	"Power conversion temperature correction mode (1=wetb, 2=dryb) [none], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"T_pcdes", (getter)Type260_get_T_pcdes,(setter)Type260_set_T_pcdes,
	"Power conversion reference temperature [C], number.\n Required if: *.",
 	NULL},
{"T_sfdes", (getter)Type260_get_T_sfdes,(setter)Type260_set_T_sfdes,
	"Solar field design point temperature (dry bulb) [C], number.\n Required if: *.",
 	NULL},
{"Wpar_prodD_coefs", (getter)Type260_get_Wpar_prodD_coefs,(setter)Type260_set_Wpar_prodD_coefs,
	"DNI-based production parasitic adjustment coefs. [m2/W], array.\n Required if: *.",
 	NULL},
{"Wpar_prodQ_coefs", (getter)Type260_get_Wpar_prodQ_coefs,(setter)Type260_set_Wpar_prodQ_coefs,
	"Part-load production parasitic adjustment coefs. [1/MWe], array.\n Required if: *.",
 	NULL},
{"Wpar_prodT_coefs", (getter)Type260_get_Wpar_prodT_coefs,(setter)Type260_set_Wpar_prodT_coefs,
	"Temp.-based production parasitic adjustment coefs. [1/C], array.\n Required if: *.",
 	NULL},
{"diswos", (getter)Type260_get_diswos,(setter)Type260_set_diswos,
	"Time-of-dispatch control for without-solar conditions [none], array.\n Required if: *.",
 	NULL},
{"disws", (getter)Type260_get_disws,(setter)Type260_set_disws,
	"Time-of-dispatch control for with-solar conditions [none], array.\n Required if: *.",
 	NULL},
{"etaQ_coefs", (getter)Type260_get_etaQ_coefs,(setter)Type260_set_etaQ_coefs,
	"Part-load power conversion efficiency adjustment coefficients [1/MWt], array.\n Required if: *.",
 	NULL},
{"etaT_coefs", (getter)Type260_get_etaT_coefs,(setter)Type260_set_etaT_coefs,
	"Temp.-based power conversion efficiency adjustment coefs. [1/C], array.\n Required if: *.",
 	NULL},
{"eta_des", (getter)Type260_get_eta_des,(setter)Type260_set_eta_des,
	"Design power cycle gross efficiency [none], number.\n Required if: *.",
 	NULL},
{"eta_lhv", (getter)Type260_get_eta_lhv,(setter)Type260_set_eta_lhv,
	"Fossil backup lower heating value efficiency [none], number.\n Required if: *.",
 	NULL},
{"eta_opt_gen", (getter)Type260_get_eta_opt_gen,(setter)Type260_set_eta_opt_gen,
	"General/other optical derate [none], number.\n Required if: *.",
 	NULL},
{"eta_opt_soil", (getter)Type260_get_eta_opt_soil,(setter)Type260_set_eta_opt_soil,
	"Soiling optical derate factor [none], number.\n Required if: *.",
 	NULL},
{"exergy_table", (getter)Type260_get_exergy_table,(setter)Type260_set_exergy_table,
	"Exergy table [none], matrix.\n Required if: *.",
 	NULL},
{"f_Wpar_fixed", (getter)Type260_get_f_Wpar_fixed,(setter)Type260_set_f_Wpar_fixed,
	"Fixed capacity-based parasitic loss fraction [MWe/MWcap], number.\n Required if: *.",
 	NULL},
{"f_Wpar_prod", (getter)Type260_get_f_Wpar_prod,(setter)Type260_set_f_Wpar_prod,
	"Production-based parasitic loss fraction [MWe/MWe], number.\n Required if: *.",
 	NULL},
{"f_charge", (getter)Type260_get_f_charge,(setter)Type260_set_f_charge,
	"Storage charging energy derate [none], number.\n Required if: *.",
 	NULL},
{"f_disch", (getter)Type260_get_f_disch,(setter)Type260_set_f_disch,
	"Storage discharging energy derate [none], number.\n Required if: *.",
 	NULL},
{"f_etes_0", (getter)Type260_get_f_etes_0,(setter)Type260_set_f_etes_0,
	"Initial fractional charge level of thermal storage (0..1) [none], number.\n Required if: *.",
 	NULL},
{"f_sfhl_ref", (getter)Type260_get_f_sfhl_ref,(setter)Type260_set_f_sfhl_ref,
	"Reference solar field thermal loss fraction [MW/MWcap], number.\n Required if: *.",
 	NULL},
{"f_startup", (getter)Type260_get_f_startup,(setter)Type260_set_f_startup,
	"Equivalent full-load hours required for power system startup [hours], number.\n Required if: *.",
 	NULL},
{"f_teshl_ref", (getter)Type260_get_f_teshl_ref,(setter)Type260_set_f_teshl_ref,
	"Reference heat loss from storage per max stored capacity [kWt/MWhr-stored], number.\n Required if: *.",
 	NULL},
{"f_wmax", (getter)Type260_get_f_wmax,(setter)Type260_set_f_wmax,
	"Maximum over-design power cycle operation fraction [none], number.\n Required if: *.",
 	NULL},
{"f_wmin", (getter)Type260_get_f_wmin,(setter)Type260_set_f_wmin,
	"Minimum part-load power cycle operation fraction [none], number.\n Required if: *.",
 	NULL},
{"fdisp", (getter)Type260_get_fdisp,(setter)Type260_set_fdisp,
	"Fossil backup output control factors [none], array.\n Required if: *.",
 	NULL},
{"hrs_tes", (getter)Type260_get_hrs_tes,(setter)Type260_set_hrs_tes,
	"Equivalent full-load hours of storage [hours], number.\n Required if: *.",
 	NULL},
{"ibh", (getter)Type260_get_ibh,(setter)Type260_set_ibh,
	"Beam-horizontal irradiation [kJ/hr-m^2], number.\n Required if: *.",
 	NULL},
{"ibn", (getter)Type260_get_ibn,(setter)Type260_set_ibn,
	"Beam-normal (DNI) irradiation [kJ/hr-m^2], number.\n Required if: *.",
 	NULL},
{"interp_arr", (getter)Type260_get_interp_arr,(setter)Type260_set_interp_arr,
	"Interpolate the array or find nearest neighbor? (1=interp,2=no) [none], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"irr_des", (getter)Type260_get_irr_des,(setter)Type260_set_irr_des,
	"Irradiation design point [W/m2], number.\n Required if: *.",
 	NULL},
{"istableunsorted", (getter)Type260_get_istableunsorted,(setter)Type260_set_istableunsorted,
	"Is optical table unsorted format? [none], number.\n Required if: *.",
 	NULL},
{"itoth", (getter)Type260_get_itoth,(setter)Type260_set_itoth,
	"Total horizontal irradiation [kJ/hr-m^2], number.\n Required if: *.",
 	NULL},
{"latitude", (getter)Type260_get_latitude,(setter)Type260_set_latitude,
	"Site latitude [], number.\n Required if: *.",
 	NULL},
{"longitude", (getter)Type260_get_longitude,(setter)Type260_set_longitude,
	"Site longitude [], number.\n Required if: *.",
 	NULL},
{"ntod", (getter)Type260_get_ntod,(setter)Type260_set_ntod,
	"Number of time-of-dispatch periods in the dispatch schedule [none], number.\n Required if: *.",
 	NULL},
{"qdisp", (getter)Type260_get_qdisp,(setter)Type260_set_qdisp,
	"TOD power output control factors [none], array.\n Required if: *.",
 	NULL},
{"qsf_des", (getter)Type260_get_qsf_des,(setter)Type260_set_qsf_des,
	"Solar field thermal production at design [MWt], number.\n Required if: *.",
 	NULL},
{"rad_type", (getter)Type260_get_rad_type,(setter)Type260_set_rad_type,
	"Solar resource radiation type (1=DNI,2=horiz.beam,3=tot.horiz) [none], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"sfhlQ_coefs", (getter)Type260_get_sfhlQ_coefs,(setter)Type260_set_sfhlQ_coefs,
	"Irr-based solar field thermal loss adjustment coefficients [1/MWt], array.\n Required if: *.",
 	NULL},
{"sfhlT_coefs", (getter)Type260_get_sfhlT_coefs,(setter)Type260_set_sfhlT_coefs,
	"Temp.-based solar field thermal loss adjustment coefficients [1/C], array.\n Required if: *.",
 	NULL},
{"sfhlV_coefs", (getter)Type260_get_sfhlV_coefs,(setter)Type260_set_sfhlV_coefs,
	"Wind-based solar field thermal loss adjustment coefficients [1/(m/s)], array.\n Required if: *.",
 	NULL},
{"solarm", (getter)Type260_get_solarm,(setter)Type260_set_solarm,
	"Solar multiple [none], number.\n Required if: *.",
 	NULL},
{"storage_config", (getter)Type260_get_storage_config,(setter)Type260_set_storage_config,
	"Thermal storage configuration [none], number.\n Required if: *.",
 	NULL},
{"tdb", (getter)Type260_get_tdb,(setter)Type260_set_tdb,
	"Ambient dry-bulb temperature [C], number.\n Required if: *.",
 	NULL},
{"teshlT_coefs", (getter)Type260_get_teshlT_coefs,(setter)Type260_set_teshlT_coefs,
	"Temp.-based thermal loss adjustment - constant coef. [1/C], array.\n Required if: *.",
 	NULL},
{"teshlX_coefs", (getter)Type260_get_teshlX_coefs,(setter)Type260_set_teshlX_coefs,
	"Charge-based thermal loss adjustment - constant coef. [1/MWhr-stored], array.\n Required if: *.",
 	NULL},
{"theta_dep", (getter)Type260_get_theta_dep,(setter)Type260_set_theta_dep,
	"Solar elevation angle at which the solar field begins operating [deg], number.\n Required if: *.",
 	NULL},
{"theta_stow", (getter)Type260_get_theta_stow,(setter)Type260_set_theta_stow,
	"Solar elevation angle at which the solar field stops operating [deg], number.\n Required if: *.",
 	NULL},
{"timezone", (getter)Type260_get_timezone,(setter)Type260_set_timezone,
	"Site timezone [hr], number.\n Required if: *.",
 	NULL},
{"twb", (getter)Type260_get_twb,(setter)Type260_set_twb,
	"Ambient wet-bulb temperature [C], number.\n Required if: *.",
 	NULL},
{"vwind", (getter)Type260_get_vwind,(setter)Type260_set_vwind,
	"Wind velocity [m/s], number.\n Required if: *.",
 	NULL},
{"w_des", (getter)Type260_get_w_des,(setter)Type260_set_w_des,
	"Design power cycle gross output [MWe], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Type260_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.Type260",             /*tp_name*/
		sizeof(Type260Object),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Type260_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Type260_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


	/*
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsgenericSolar   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_TcsgenericSolar data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
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
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_fuel_usage_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_dump_tot(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_dump_tot_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_fossil(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_fossil_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_from_tes(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_from_tes_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_hl_sf(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_hl_sf_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_hl_tes(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_hl_tes_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_sf(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_sf_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_startup(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_startup_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_to_pb_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_q_to_tes(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_q_to_tes_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_w_gr(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_annual_w_gr_fget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_conversion_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_diff(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_in_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_e_in_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_enet(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_enet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_cycle(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_eta_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_opt_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_eta_opt_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_effpc_qtpb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_effpc_qtpb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_effpc_tamb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_effpc_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sfhl_qdni(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_sfhl_qdni_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sfhl_tamb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_sfhl_tamb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_sfhl_vwind(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_f_sfhl_vwind_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_global(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_global_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_month(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_dump_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_dump_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_fossil(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_fossil_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_from_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_from_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_hl_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_hl_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_hl_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_hl_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_to_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_q_to_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_w_gr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_monthly_w_gr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_teschg(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_teschg_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_tesfull(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_tesfull_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump_umin(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_dump_umin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_fossil(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_fossil_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_from_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_from_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_gas(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_gas_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_hl_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_hl_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_hl_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_hl_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_q_to_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsgenericSolar_Outputs_system_heat_rate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_gr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_gr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_gr_fossil(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_gr_fossil_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_gr_solar(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_gr_solar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_fixed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_offline(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_offline_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_online(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_online_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_prod(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_prod_aget, self->data_ptr);
}

static PyObject *
Outputs_get_w_par_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_w_par_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsgenericSolar_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual Energy [kWh], number.",
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	"Annual fuel usage [kWh], number.",
 	NULL},
{"annual_q_dump_tot", (getter)Outputs_get_annual_q_dump_tot,(setter)0,
	"Total dumped energy [MWht], number.",
 	NULL},
{"annual_q_fossil", (getter)Outputs_get_annual_q_fossil,(setter)0,
	"Thermal energy supplied from aux firing [MWht], number.",
 	NULL},
{"annual_q_from_tes", (getter)Outputs_get_annual_q_from_tes,(setter)0,
	"Thermal energy from storage [MWht], number.",
 	NULL},
{"annual_q_hl_sf", (getter)Outputs_get_annual_q_hl_sf,(setter)0,
	"Solar field thermal losses [MWht], number.",
 	NULL},
{"annual_q_hl_tes", (getter)Outputs_get_annual_q_hl_tes,(setter)0,
	"Thermal losses from storage [MWht], number.",
 	NULL},
{"annual_q_sf", (getter)Outputs_get_annual_q_sf,(setter)0,
	"Solar field delivered thermal power [MWht], number.",
 	NULL},
{"annual_q_startup", (getter)Outputs_get_annual_q_startup,(setter)0,
	"Power conversion startup energy [MWht], number.",
 	NULL},
{"annual_q_to_pb", (getter)Outputs_get_annual_q_to_pb,(setter)0,
	"Thermal energy to the power conversion system [MWht], number.",
 	NULL},
{"annual_q_to_tes", (getter)Outputs_get_annual_q_to_tes,(setter)0,
	"Thermal energy into storage [MWht], number.",
 	NULL},
{"annual_w_gr", (getter)Outputs_get_annual_w_gr,(setter)0,
	"Total gross power production [kWh], number.",
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	"Resource Beam normal irradiance [W/m2], array.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"conversion_factor", (getter)Outputs_get_conversion_factor,(setter)0,
	"Gross to Net Conversion Factor [%], number.",
 	NULL},
{"diff", (getter)Outputs_get_diff,(setter)0,
	"Resource Diffuse horizontal irradiance [W/m2], array.",
 	NULL},
{"e_in_tes", (getter)Outputs_get_e_in_tes,(setter)0,
	"TES thermal energy available [MWht], array.",
 	NULL},
{"enet", (getter)Outputs_get_enet,(setter)0,
	"Cycle electrical power output (net) [MWe], array.",
 	NULL},
{"eta_cycle", (getter)Outputs_get_eta_cycle,(setter)0,
	"Cycle efficiency (gross) [], array.",
 	NULL},
{"eta_opt_sf", (getter)Outputs_get_eta_opt_sf,(setter)0,
	"Field collector optical efficiency [none], array.",
 	NULL},
{"f_effpc_qtpb", (getter)Outputs_get_f_effpc_qtpb,(setter)0,
	"Cycle efficiency load-based correction [], array.",
 	NULL},
{"f_effpc_tamb", (getter)Outputs_get_f_effpc_tamb,(setter)0,
	"Cycle efficiency temperature-based correction [], array.",
 	NULL},
{"f_sfhl_qdni", (getter)Outputs_get_f_sfhl_qdni,(setter)0,
	"Field thermal power load-based loss correction [none], array.",
 	NULL},
{"f_sfhl_tamb", (getter)Outputs_get_f_sfhl_tamb,(setter)0,
	"Field thermal power temp.-based loss correction [none], array.",
 	NULL},
{"f_sfhl_vwind", (getter)Outputs_get_f_sfhl_vwind,(setter)0,
	"Field thermal power wind-based loss correction [none], array.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"System power generated [kW], array.",
 	NULL},
{"global", (getter)Outputs_get_global,(setter)0,
	"Resource Global horizontal irradiance [W/m2], array.",
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	"Resource Hour of Day [], array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	"Resource Month [], array.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly Energy [kWh], array.",
 	NULL},
{"monthly_q_dump_tot", (getter)Outputs_get_monthly_q_dump_tot,(setter)0,
	"Total dumped energy [MWt], array.",
 	NULL},
{"monthly_q_fossil", (getter)Outputs_get_monthly_q_fossil,(setter)0,
	"Thermal energy supplied from aux firing [MWt], array.",
 	NULL},
{"monthly_q_from_tes", (getter)Outputs_get_monthly_q_from_tes,(setter)0,
	"Thermal energy from storage [MWt], array.",
 	NULL},
{"monthly_q_hl_sf", (getter)Outputs_get_monthly_q_hl_sf,(setter)0,
	"Solar field thermal losses [MWt], array.",
 	NULL},
{"monthly_q_hl_tes", (getter)Outputs_get_monthly_q_hl_tes,(setter)0,
	"Thermal losses from storage [MWt], array.",
 	NULL},
{"monthly_q_sf", (getter)Outputs_get_monthly_q_sf,(setter)0,
	"Solar field delivered thermal power [MWt], array.",
 	NULL},
{"monthly_q_startup", (getter)Outputs_get_monthly_q_startup,(setter)0,
	"Power conversion startup energy [MWt], array.",
 	NULL},
{"monthly_q_to_pb", (getter)Outputs_get_monthly_q_to_pb,(setter)0,
	"Thermal energy to the power conversion system [MWt], array.",
 	NULL},
{"monthly_q_to_tes", (getter)Outputs_get_monthly_q_to_tes,(setter)0,
	"Thermal energy into storage [MWt], array.",
 	NULL},
{"monthly_w_gr", (getter)Outputs_get_monthly_w_gr,(setter)0,
	"Total gross power production [kWh], array.",
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	"Resource Pressure [mbar], array.",
 	NULL},
{"q_dump_teschg", (getter)Outputs_get_q_dump_teschg,(setter)0,
	"Cycle thermal energy dumped - solar field [MWt], array.",
 	NULL},
{"q_dump_tesfull", (getter)Outputs_get_q_dump_tesfull,(setter)0,
	"Cycle thermal energy dumped - TES is full [MWt], array.",
 	NULL},
{"q_dump_tot", (getter)Outputs_get_q_dump_tot,(setter)0,
	"Cycle thermal energy dumped total [MWt], array.",
 	NULL},
{"q_dump_umin", (getter)Outputs_get_q_dump_umin,(setter)0,
	"Cycle thermal energy dumped - min. load requirement [MWt], array.",
 	NULL},
{"q_fossil", (getter)Outputs_get_q_fossil,(setter)0,
	"Fossil thermal power produced [MWt], array.",
 	NULL},
{"q_from_tes", (getter)Outputs_get_q_from_tes,(setter)0,
	"TES thermal energy from storage [MWt], array.",
 	NULL},
{"q_gas", (getter)Outputs_get_q_gas,(setter)0,
	"Fossil fuel used [MWt], array.",
 	NULL},
{"q_hl_sf", (getter)Outputs_get_q_hl_sf,(setter)0,
	"Field thermal power loss total [MWt], array.",
 	NULL},
{"q_hl_tes", (getter)Outputs_get_q_hl_tes,(setter)0,
	"TES thermal losses from tank(s) [MWt], array.",
 	NULL},
{"q_inc", (getter)Outputs_get_q_inc,(setter)0,
	"Field thermal power incident [MWt], array.",
 	NULL},
{"q_sf", (getter)Outputs_get_q_sf,(setter)0,
	"Field thermal power total produced [MWt], array.",
 	NULL},
{"q_startup", (getter)Outputs_get_q_startup,(setter)0,
	"Cycle thermal startup energy [MWt], array.",
 	NULL},
{"q_to_pb", (getter)Outputs_get_q_to_pb,(setter)0,
	"Cycle thermal power input [MWt], array.",
 	NULL},
{"q_to_tes", (getter)Outputs_get_q_to_tes,(setter)0,
	"TES thermal energy into storage [MWt], array.",
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	"Resource Solar Azimuth [deg], array.",
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	"Resource Solar Zenith [deg], array.",
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	"System heat rate [MMBtu/MWh], number.",
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	"Resource Dry bulb temperature [C], array.",
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	"Resource Wet bulb temperature [C], array.",
 	NULL},
{"w_gr", (getter)Outputs_get_w_gr,(setter)0,
	"Cycle electrical power output (gross) [MWe], array.",
 	NULL},
{"w_gr_fossil", (getter)Outputs_get_w_gr_fossil,(setter)0,
	"Cycle electrical power output (gross, fossil share) [MWe], array.",
 	NULL},
{"w_gr_solar", (getter)Outputs_get_w_gr_solar,(setter)0,
	"Cycle electrical power output (gross, solar share) [MWe], array.",
 	NULL},
{"w_par_fixed", (getter)Outputs_get_w_par_fixed,(setter)0,
	"Fixed parasitic losses [MWh], array.",
 	NULL},
{"w_par_offline", (getter)Outputs_get_w_par_offline,(setter)0,
	"Offline parasitics [MWh], array.",
 	NULL},
{"w_par_online", (getter)Outputs_get_w_par_online,(setter)0,
	"Online parasitics [MWh], array.",
 	NULL},
{"w_par_prod", (getter)Outputs_get_w_par_prod,(setter)0,
	"Production-based parasitic losses [MWh], array.",
 	NULL},
{"w_par_tot", (getter)Outputs_get_w_par_tot,(setter)0,
	"Total parasitic losses [MWh], array.",
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	"Resource Wind Speed [m/s], array.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * TcsgenericSolar
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_TcsgenericSolar   data_ptr;
} TcsgenericSolarObject;

static PyTypeObject TcsgenericSolar_Type;

#define TcsgenericSolarObject_Check(v)      (Py_TYPE(v) == &TcsgenericSolar_Type)

static TcsgenericSolarObject *
newTcsgenericSolarObject(void* data_ptr)
{
	TcsgenericSolarObject *self;
	self = PyObject_New(TcsgenericSolarObject, &TcsgenericSolar_Type);

	PySAM_TECH_ATTR("TcsgenericSolar", SAM_TcsgenericSolar_construct)

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

PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

PyObject* AdjustmentFactorsModule = PyImport_ImportModule("AdjustmentFactors");

	PyObject* data_cap = PyCapsule_New(self->data_ptr, NULL, NULL);
	PyObject* Adjust_obj = PyObject_CallMethod(AdjustmentFactorsModule, "new", "(O)", data_cap);
	Py_XDECREF(data_cap);
	Py_XDECREF(AdjustmentFactorsModule);

	if (!Adjust_obj){
		PyErr_SetString(PySAM_ErrorObject, "Couldn't create AdjustmentFactorsObject\n");
		return NULL;
	}

	PyDict_SetItemString(attr_dict, "AdjustmentFactors", Adjust_obj);
	Py_DECREF(Adjust_obj);

	return self;
}

/* TcsgenericSolar methods */

static void
TcsgenericSolar_dealloc(TcsgenericSolarObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_TcsgenericSolar_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
TcsgenericSolar_execute(TcsgenericSolarObject *self, PyObject *args)
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
TcsgenericSolar_assign(TcsgenericSolarObject *self, PyObject *args)
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
TcsgenericSolar_export(TcsgenericSolarObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef TcsgenericSolar_methods[] = {
		{"execute",            (PyCFunction)TcsgenericSolar_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcsgenericSolar_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)TcsgenericSolar_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcsgenericSolar_getattro(TcsgenericSolarObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcsgenericSolar_setattr(TcsgenericSolarObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcsgenericSolar_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsgenericSolar",            /*tp_name*/
		sizeof(TcsgenericSolarObject),/*tp_basicsize*/
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
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		TcsgenericSolar_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictoffset*/
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
	TcsgenericSolarObject *rv;
	rv = newTcsgenericSolarObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsgenericSolar_wrap(PyObject *self, PyObject *args)
{
	TcsgenericSolarObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsgenericSolarObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsgenericSolar_default(PyObject *self, PyObject *args)
{
	TcsgenericSolarObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsgenericSolarObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsgenericSolar", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcsgenericSolarModule_methods[] = {
		{"new",             TcsgenericSolar_new,         METH_VARARGS,
				PyDoc_STR("new() -> new TcsgenericSolar object")},
		{"default",             TcsgenericSolar_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new TcsgenericSolar object with financial model-specific default attributes\n"
				"Options: LCOE Calculator, Leveraged Partnership Flip, Single Owner, Independent Power Producer, None, All Equity Partnership Flip, Sale Leaseback, Commercial PPA, Commercial, ")},
		{"wrap",             TcsgenericSolar_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new TcsgenericSolar object around existing PySSC data")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Refer to http://www.github.com/nrel/PySAM for source code.");


static int
TcsgenericSolarModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

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

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

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