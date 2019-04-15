#include <Python.h>

#include <SAM_TcslinearFresnel.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Weather Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcslinearFresnel   data_ptr;
} WeatherObject;

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TcslinearFresnel data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Weather")){
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
	return PySAM_float_getter(SAM_TcslinearFresnel_Weather_azimuth_fget, self->data_ptr);
}

static int
Weather_set_azimuth(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Weather_azimuth_fset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(WeatherObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcslinearFresnel_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcslinearFresnel_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(WeatherObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Weather_tilt_fget, self->data_ptr);
}

static int
Weather_set_tilt(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Weather_tilt_fset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(WeatherObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Weather_track_mode_fget, self->data_ptr);
}

static int
Weather_set_track_mode(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Weather_track_mode_fset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"azimuth", (getter)Weather_get_azimuth,(setter)Weather_set_azimuth,
	"Azimuth angle of surface/axis, number.\n Required.",
 	NULL},
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	"local weather file path, string.\n Constraints: LOCAL_FILE; Required.",
 	NULL},
{"tilt", (getter)Weather_get_tilt,(setter)Weather_set_tilt,
	"Tilt angle of surface/axis, number.\n Required.",
 	NULL},
{"track_mode", (getter)Weather_get_track_mode,(setter)Weather_set_track_mode,
	"Tracking mode, number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Weather",             /*tp_name*/
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
	 * LinearFresnelr Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcslinearFresnel   data_ptr;
} LinearFresnelrObject;

static PyTypeObject LinearFresnelr_Type;

static PyObject *
LinearFresnelr_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = LinearFresnelr_Type.tp_alloc(&LinearFresnelr_Type,0);

	LinearFresnelrObject* LinearFresnelr_obj = (LinearFresnelrObject*)new_obj;

	LinearFresnelr_obj->data_ptr = data_ptr;

	return new_obj;
}

/* LinearFresnelr methods */

static PyObject *
LinearFresnelr_assign(LinearFresnelrObject *self, PyObject *args)
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
LinearFresnelr_export(LinearFresnelrObject *self, PyObject *args)
{
	PyTypeObject* tp = &LinearFresnelr_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LinearFresnelr_methods[] = {
		{"assign",            (PyCFunction)LinearFresnelr_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)LinearFresnelr_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LinearFresnelr_get_system_capacity(LinearFresnelrObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_LinearFresnelr_system_capacity_fget, self->data_ptr);
}

static int
LinearFresnelr_set_system_capacity(LinearFresnelrObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_LinearFresnelr_system_capacity_fset, self->data_ptr);
}

static PyGetSetDef LinearFresnelr_getset[] = {
{"system_capacity", (getter)LinearFresnelr_get_system_capacity,(setter)LinearFresnelr_set_system_capacity,
	"Nameplate capacity [kW], number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LinearFresnelr_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.LinearFresnelr",             /*tp_name*/
		sizeof(LinearFresnelrObject),          /*tp_basicsize*/
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
		LinearFresnelr_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LinearFresnelr_getset,          /*tp_getset*/
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
	SAM_TcslinearFresnel   data_ptr;
} TouTranslatorObject;

static PyTypeObject TouTranslator_Type;

static PyObject *
TouTranslator_new(SAM_TcslinearFresnel data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "TouTranslator")){
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
	return PySAM_matrix_getter(SAM_TcslinearFresnel_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(TouTranslatorObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(TouTranslatorObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(TouTranslatorObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_TouTranslator_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef TouTranslator_getset[] = {
{"weekday_schedule", (getter)TouTranslator_get_weekday_schedule,(setter)TouTranslator_set_weekday_schedule,
	"12x24 Time of Use Values for week days, matrix.\n Required.",
 	NULL},
{"weekend_schedule", (getter)TouTranslator_get_weekend_schedule,(setter)TouTranslator_set_weekend_schedule,
	"12x24 Time of Use Values for week end days, matrix.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TouTranslator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.TouTranslator",             /*tp_name*/
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
	 * Solarfield Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcslinearFresnel   data_ptr;
} SolarfieldObject;

static PyTypeObject Solarfield_Type;

static PyObject *
Solarfield_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = Solarfield_Type.tp_alloc(&Solarfield_Type,0);

	SolarfieldObject* Solarfield_obj = (SolarfieldObject*)new_obj;

	Solarfield_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Solarfield methods */

static PyObject *
Solarfield_assign(SolarfieldObject *self, PyObject *args)
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
Solarfield_export(SolarfieldObject *self, PyObject *args)
{
	PyTypeObject* tp = &Solarfield_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Solarfield_methods[] = {
		{"assign",            (PyCFunction)Solarfield_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Solarfield_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Solarfield_get_A_aperture(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_A_aperture_mget, self->data_ptr);
}

static int
Solarfield_set_A_aperture(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_A_aperture_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_AbsorberMaterial(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_AbsorberMaterial_mget, self->data_ptr);
}

static int
Solarfield_set_AbsorberMaterial(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_AnnulusGas(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_AnnulusGas_mget, self->data_ptr);
}

static int
Solarfield_set_AnnulusGas(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_ColAz(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_ColAz_fget, self->data_ptr);
}

static int
Solarfield_set_ColAz(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_ColAz_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_2(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_2_mget, self->data_ptr);
}

static int
Solarfield_set_D_2(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_3(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_3_mget, self->data_ptr);
}

static int
Solarfield_set_D_3(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_4(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_4_mget, self->data_ptr);
}

static int
Solarfield_set_D_4(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_5(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_5_mget, self->data_ptr);
}

static int
Solarfield_set_D_5(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_5_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_p(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_D_p_mget, self->data_ptr);
}

static int
Solarfield_set_D_p(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_D_p_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Design_loss(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Design_loss_mget, self->data_ptr);
}

static int
Solarfield_set_Design_loss(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Design_loss_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Dirt_HCE(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Dirt_HCE_mget, self->data_ptr);
}

static int
Solarfield_set_Dirt_HCE(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_EPSILON_4(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_EPSILON_4_mget, self->data_ptr);
}

static int
Solarfield_set_EPSILON_4(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Flow_type(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Flow_type_mget, self->data_ptr);
}

static int
Solarfield_set_Flow_type(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Flow_type_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_GeomEffects(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_GeomEffects_mget, self->data_ptr);
}

static int
Solarfield_set_GeomEffects(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_GeomEffects_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_GlazingIntactIn(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_GlazingIntactIn_mget, self->data_ptr);
}

static int
Solarfield_set_GlazingIntactIn(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HCE_FieldFrac(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HCE_FieldFrac_mget, self->data_ptr);
}

static int
Solarfield_set_HCE_FieldFrac(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HLCharType(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HLCharType_mget, self->data_ptr);
}

static int
Solarfield_set_HLCharType(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HLCharType_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HL_W(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HL_W_mget, self->data_ptr);
}

static int
Solarfield_set_HL_W(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HL_W_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HL_dT(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_HL_dT_mget, self->data_ptr);
}

static int
Solarfield_set_HL_dT(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_HL_dT_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_IAM_L(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_IAM_L_mget, self->data_ptr);
}

static int
Solarfield_set_IAM_L(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_IAM_L_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_IAM_T(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_IAM_T_mget, self->data_ptr);
}

static int
Solarfield_set_IAM_T(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_IAM_T_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_I_bn(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_I_bn_fget, self->data_ptr);
}

static int
Solarfield_set_I_bn(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_I_bn_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_I_bn_des(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_I_bn_des_fget, self->data_ptr);
}

static int
Solarfield_set_I_bn_des(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_I_bn_des_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_LHV_eff(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_LHV_eff_fget, self->data_ptr);
}

static int
Solarfield_set_LHV_eff(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_LHV_eff_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_L_col(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_L_col_mget, self->data_ptr);
}

static int
Solarfield_set_L_col(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_L_col_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_OptCharType(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_OptCharType_mget, self->data_ptr);
}

static int
Solarfield_set_OptCharType(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_OptCharType_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_PB_fixed_par(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_PB_fixed_par_fget, self->data_ptr);
}

static int
Solarfield_set_PB_fixed_par(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_PB_fixed_par_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_PB_pump_coef(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_PB_pump_coef_fget, self->data_ptr);
}

static int
Solarfield_set_PB_pump_coef(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_PB_pump_coef_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_a(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_P_a_mget, self->data_ptr);
}

static int
Solarfield_set_P_a(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_P_a_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_amb(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_P_amb_fget, self->data_ptr);
}

static int
Solarfield_set_P_amb(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_P_amb_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_turb_des(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_P_turb_des_fget, self->data_ptr);
}

static int
Solarfield_set_P_turb_des(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_P_turb_des_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_Pipe_hl_coef(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_Pipe_hl_coef_fget, self->data_ptr);
}

static int
Solarfield_set_Pipe_hl_coef(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_Pipe_hl_coef_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_Rough(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Rough_mget, self->data_ptr);
}

static int
Solarfield_set_Rough(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Rough_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_SCA_drives_elec(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_SCA_drives_elec_fget, self->data_ptr);
}

static int
Solarfield_set_SCA_drives_elec(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_SCA_drives_elec_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_Shadowing(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Shadowing_mget, self->data_ptr);
}

static int
Solarfield_set_Shadowing(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Shadowing_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_SolarAz_init(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_SolarAz_init_fget, self->data_ptr);
}

static int
Solarfield_set_SolarAz_init(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_SolarAz_init_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_SolarZen(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_SolarZen_fget, self->data_ptr);
}

static int
Solarfield_set_SolarZen(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_SolarZen_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_amb_des_sf(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_T_amb_des_sf_fget, self->data_ptr);
}

static int
Solarfield_set_T_amb_des_sf(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_T_amb_des_sf_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_db(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_T_db_fget, self->data_ptr);
}

static int
Solarfield_set_T_db(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_T_db_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_dp(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_T_dp_fget, self->data_ptr);
}

static int
Solarfield_set_T_dp(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_T_dp_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_fp(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_T_fp_fget, self->data_ptr);
}

static int
Solarfield_set_T_fp(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_T_fp_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_pb_out_init(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_T_pb_out_init_fget, self->data_ptr);
}

static int
Solarfield_set_T_pb_out_init(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_T_pb_out_init_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_Tau_envelope(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_Tau_envelope_mget, self->data_ptr);
}

static int
Solarfield_set_Tau_envelope(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_TrackingError(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_TrackingError_mget, self->data_ptr);
}

static int
Solarfield_set_TrackingError(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_TrackingError_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_V_wind(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_V_wind_fget, self->data_ptr);
}

static int
Solarfield_set_V_wind(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_V_wind_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_V_wind_max(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_V_wind_max_fget, self->data_ptr);
}

static int
Solarfield_set_V_wind_max(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_V_wind_max_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_alpha_abs(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_alpha_abs_mget, self->data_ptr);
}

static int
Solarfield_set_alpha_abs(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_alpha_abs_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_alpha_env(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_alpha_env_mget, self->data_ptr);
}

static int
Solarfield_set_alpha_env(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_alpha_env_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_aux_array(SolarfieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Solarfield_aux_array_aget, self->data_ptr);
}

static int
Solarfield_set_aux_array(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcslinearFresnel_Solarfield_aux_array_aset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_OpticalTable(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_OpticalTable_mget, self->data_ptr);
}

static int
Solarfield_set_b_OpticalTable(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE1(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE1_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE1(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE1_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE2(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE2_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE2(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE3(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE3_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE3(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE4(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_b_eps_HCE4_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE4(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_b_eps_HCE4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_bop_array(SolarfieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Solarfield_bop_array_aget, self->data_ptr);
}

static int
Solarfield_set_bop_array(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcslinearFresnel_Solarfield_bop_array_aset, self->data_ptr);
}

static PyObject *
Solarfield_get_cycle_cutoff_frac(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_cycle_cutoff_frac_fget, self->data_ptr);
}

static int
Solarfield_set_cycle_cutoff_frac(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_cycle_cutoff_frac_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_cycle_max_fraction(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_cycle_max_fraction_fget, self->data_ptr);
}

static int
Solarfield_set_cycle_max_fraction(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_cycle_max_fraction_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_dirt_mirror(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_dirt_mirror_mget, self->data_ptr);
}

static int
Solarfield_set_dirt_mirror(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_dirt_mirror_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_dnifc(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_dnifc_fget, self->data_ptr);
}

static int
Solarfield_set_dnifc(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_dnifc_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_e_startup(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_e_startup_fget, self->data_ptr);
}

static int
Solarfield_set_e_startup(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_e_startup_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_error(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_error_mget, self->data_ptr);
}

static int
Solarfield_set_error(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_error_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_eta_pump(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_eta_pump_fget, self->data_ptr);
}

static int
Solarfield_set_eta_pump(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_eta_pump_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_boil_to_sh(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_fP_boil_to_sh_fget, self->data_ptr);
}

static int
Solarfield_set_fP_boil_to_sh(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_fP_boil_to_sh_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_hdr_c(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_fP_hdr_c_fget, self->data_ptr);
}

static int
Solarfield_set_fP_hdr_c(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_fP_hdr_c_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_hdr_h(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_fP_hdr_h_fget, self->data_ptr);
}

static int
Solarfield_set_fP_hdr_h(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_fP_hdr_h_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_sf_boil(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_fP_sf_boil_fget, self->data_ptr);
}

static int
Solarfield_set_fP_sf_boil(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_fP_sf_boil_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_sf_sh(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_fP_sf_sh_fget, self->data_ptr);
}

static int
Solarfield_set_fP_sf_sh(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_fP_sf_sh_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_ffrac(SolarfieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Solarfield_ffrac_aget, self->data_ptr);
}

static int
Solarfield_set_ffrac(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcslinearFresnel_Solarfield_ffrac_aset, self->data_ptr);
}

static PyObject *
Solarfield_get_fossil_mode(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_fossil_mode_fget, self->data_ptr);
}

static int
Solarfield_set_fossil_mode(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_fossil_mode_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_is_multgeom(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_is_multgeom_fget, self->data_ptr);
}

static int
Solarfield_set_is_multgeom(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_is_multgeom_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_is_oncethru(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_is_oncethru_fget, self->data_ptr);
}

static int
Solarfield_set_is_oncethru(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_is_oncethru_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_is_sh(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_is_sh_fget, self->data_ptr);
}

static int
Solarfield_set_is_sh(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_is_sh_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_latitude(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_latitude_fget, self->data_ptr);
}

static int
Solarfield_set_latitude(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_latitude_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_m_dot_htf_ref(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_m_dot_htf_ref_fget, self->data_ptr);
}

static int
Solarfield_set_m_dot_htf_ref(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_m_dot_htf_ref_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_m_dot_min(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_m_dot_min_fget, self->data_ptr);
}

static int
Solarfield_set_m_dot_min(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_m_dot_min_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_m_pb_demand(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_m_pb_demand_fget, self->data_ptr);
}

static int
Solarfield_set_m_pb_demand(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_m_pb_demand_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_nLoops(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_nLoops_fget, self->data_ptr);
}

static int
Solarfield_set_nLoops(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_nLoops_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_nModBoil(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_nModBoil_fget, self->data_ptr);
}

static int
Solarfield_set_nModBoil(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_nModBoil_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_nModSH(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_nModSH_fget, self->data_ptr);
}

static int
Solarfield_set_nModSH(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_nModSH_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_max_aux(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_q_max_aux_fget, self->data_ptr);
}

static int
Solarfield_set_q_max_aux(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_q_max_aux_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_pb_des(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_q_pb_des_fget, self->data_ptr);
}

static int
Solarfield_set_q_pb_des(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_q_pb_des_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_sby_frac(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_q_sby_frac_fget, self->data_ptr);
}

static int
Solarfield_set_q_sby_frac(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_q_sby_frac_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_rho_mirror_clean(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_rho_mirror_clean_mget, self->data_ptr);
}

static int
Solarfield_set_rho_mirror_clean(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_rho_mirror_clean_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_OpticalTable(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_OpticalTable_mget, self->data_ptr);
}

static int
Solarfield_set_sh_OpticalTable(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE1(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE1_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE1(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE1_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE2(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE2_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE2(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE3(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE3_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE3(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE4(SolarfieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcslinearFresnel_Solarfield_sh_eps_HCE4_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE4(SolarfieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcslinearFresnel_Solarfield_sh_eps_HCE4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_shift(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_shift_fget, self->data_ptr);
}

static int
Solarfield_set_shift(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_shift_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_solarm(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_solarm_fget, self->data_ptr);
}

static int
Solarfield_set_solarm(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_solarm_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_t_sby(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_t_sby_fget, self->data_ptr);
}

static int
Solarfield_set_t_sby(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_t_sby_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_tes_hours(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_tes_hours_fget, self->data_ptr);
}

static int
Solarfield_set_tes_hours(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_tes_hours_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_theta_dep(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_theta_dep_fget, self->data_ptr);
}

static int
Solarfield_set_theta_dep(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_theta_dep_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_theta_stow(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_theta_stow_fget, self->data_ptr);
}

static int
Solarfield_set_theta_stow(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_theta_stow_fset, self->data_ptr);
}

static PyObject *
Solarfield_get_x_b_des(SolarfieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Solarfield_x_b_des_fget, self->data_ptr);
}

static int
Solarfield_set_x_b_des(SolarfieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Solarfield_x_b_des_fset, self->data_ptr);
}

static PyGetSetDef Solarfield_getset[] = {
{"A_aperture", (getter)Solarfield_get_A_aperture,(setter)Solarfield_set_A_aperture,
	"(boiler, SH) Reflective aperture area of the collector module [m^2], matrix.\n Required.",
 	NULL},
{"AbsorberMaterial", (getter)Solarfield_get_AbsorberMaterial,(setter)Solarfield_set_AbsorberMaterial,
	"(boiler, SH) Absorber material type [none], matrix.\n Required.",
 	NULL},
{"AnnulusGas", (getter)Solarfield_get_AnnulusGas,(setter)Solarfield_set_AnnulusGas,
	"(boiler, SH) Annulus gas type {1=air; 26=Ar; 27=H2} (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"ColAz", (getter)Solarfield_get_ColAz,(setter)Solarfield_set_ColAz,
	"Collector azimuth angle [deg], number.\n Required.",
 	NULL},
{"D_2", (getter)Solarfield_get_D_2,(setter)Solarfield_set_D_2,
	"(boiler, SH) The inner absorber tube diameter [m], matrix.\n Required.",
 	NULL},
{"D_3", (getter)Solarfield_get_D_3,(setter)Solarfield_set_D_3,
	"(boiler, SH) The outer absorber tube diameter [m], matrix.\n Required.",
 	NULL},
{"D_4", (getter)Solarfield_get_D_4,(setter)Solarfield_set_D_4,
	"(boiler, SH) The inner glass envelope diameter [m], matrix.\n Required.",
 	NULL},
{"D_5", (getter)Solarfield_get_D_5,(setter)Solarfield_set_D_5,
	"(boiler, SH) The outer glass envelope diameter [m], matrix.\n Required.",
 	NULL},
{"D_p", (getter)Solarfield_get_D_p,(setter)Solarfield_set_D_p,
	"(boiler, SH) The diameter of the absorber flow plug (optional) [m], matrix.\n Required.",
 	NULL},
{"Design_loss", (getter)Solarfield_get_Design_loss,(setter)Solarfield_set_Design_loss,
	"(boiler, SH) Receiver heat loss at design (4: # field fracs) [W/m], matrix.\n Required.",
 	NULL},
{"Dirt_HCE", (getter)Solarfield_get_Dirt_HCE,(setter)Solarfield_set_Dirt_HCE,
	"(boiler, SH) Loss due to dirt on the receiver envelope (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"EPSILON_4", (getter)Solarfield_get_EPSILON_4,(setter)Solarfield_set_EPSILON_4,
	"(boiler, SH) Inner glass envelope emissivities (Pyrex) (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"Flow_type", (getter)Solarfield_get_Flow_type,(setter)Solarfield_set_Flow_type,
	"(boiler, SH) The flow type through the absorber [none], matrix.\n Required.",
 	NULL},
{"GeomEffects", (getter)Solarfield_get_GeomEffects,(setter)Solarfield_set_GeomEffects,
	"(boiler, SH) User-defined geometry effects derate [none], matrix.\n Required.",
 	NULL},
{"GlazingIntactIn", (getter)Solarfield_get_GlazingIntactIn,(setter)Solarfield_set_GlazingIntactIn,
	"(boiler, SH) The glazing intact flag {true=0; false=1} (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"HCE_FieldFrac", (getter)Solarfield_get_HCE_FieldFrac,(setter)Solarfield_set_HCE_FieldFrac,
	"(boiler, SH) The fraction of the field occupied by this HCE type (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"HLCharType", (getter)Solarfield_get_HLCharType,(setter)Solarfield_set_HLCharType,
	"(boiler, SH) Flag indicating the heat loss model type {1=poly.; 2=Forristall} [none], matrix.\n Required.",
 	NULL},
{"HL_W", (getter)Solarfield_get_HL_W,(setter)Solarfield_set_HL_W,
	"(boiler, SH) Heat loss coef adj wind velocity (0,1,2,3,4 order terms) [1/(m/s)^order], matrix.\n Required.",
 	NULL},
{"HL_dT", (getter)Solarfield_get_HL_dT,(setter)Solarfield_set_HL_dT,
	"(boiler, SH) Heat loss coefficient - HTF temperature (0,1,2,3,4 order terms) [W/m-K^order], matrix.\n Required.",
 	NULL},
{"IAM_L", (getter)Solarfield_get_IAM_L,(setter)Solarfield_set_IAM_L,
	"(boiler, SH) Longitudinal Incident angle modifiers (0,1,2,3,4 order terms) [none], matrix.\n Required.",
 	NULL},
{"IAM_T", (getter)Solarfield_get_IAM_T,(setter)Solarfield_set_IAM_T,
	"(boiler, SH) Transverse Incident angle modifiers (0,1,2,3,4 order terms) [none], matrix.\n Required.",
 	NULL},
{"I_bn", (getter)Solarfield_get_I_bn,(setter)Solarfield_set_I_bn,
	"Beam normal radiation (input kJ/m2-hr) [W/m2], number.\n Required.",
 	NULL},
{"I_bn_des", (getter)Solarfield_get_I_bn_des,(setter)Solarfield_set_I_bn_des,
	"Design point irradiation value [W/m2], number.\n Required.",
 	NULL},
{"LHV_eff", (getter)Solarfield_get_LHV_eff,(setter)Solarfield_set_LHV_eff,
	"Fuel LHV efficiency (0..1) [none], number.\n Required.",
 	NULL},
{"L_col", (getter)Solarfield_get_L_col,(setter)Solarfield_set_L_col,
	"(boiler, SH) Active length of the superheater section collector module [m], matrix.\n Required.",
 	NULL},
{"OptCharType", (getter)Solarfield_get_OptCharType,(setter)Solarfield_set_OptCharType,
	"(boiler, SH) The optical characterization method [none], matrix.\n Required.",
 	NULL},
{"PB_fixed_par", (getter)Solarfield_get_PB_fixed_par,(setter)Solarfield_set_PB_fixed_par,
	"fraction of rated gross power consumed at all hours of the year [none], number.\n Required.",
 	NULL},
{"PB_pump_coef", (getter)Solarfield_get_PB_pump_coef,(setter)Solarfield_set_PB_pump_coef,
	"Pumping power required to move 1kg of HTF through power block flow [kW/kg], number.\n Required.",
 	NULL},
{"P_a", (getter)Solarfield_get_P_a,(setter)Solarfield_set_P_a,
	"(boiler, SH) Annulus gas pressure (4: # field fracs) [torr], matrix.\n Required.",
 	NULL},
{"P_amb", (getter)Solarfield_get_P_amb,(setter)Solarfield_set_P_amb,
	"Ambient pressure [atm], number.\n Required.",
 	NULL},
{"P_turb_des", (getter)Solarfield_get_P_turb_des,(setter)Solarfield_set_P_turb_des,
	"Design-point turbine inlet pressure [bar], number.\n Required.",
 	NULL},
{"Pipe_hl_coef", (getter)Solarfield_get_Pipe_hl_coef,(setter)Solarfield_set_Pipe_hl_coef,
	"Loss coefficient from the header.. runner pipe.. and non-HCE pipin [W/m2-K], number.\n Required.",
 	NULL},
{"Rough", (getter)Solarfield_get_Rough,(setter)Solarfield_set_Rough,
	"(boiler, SH) Roughness of the internal surface [m], matrix.\n Required.",
 	NULL},
{"SCA_drives_elec", (getter)Solarfield_get_SCA_drives_elec,(setter)Solarfield_set_SCA_drives_elec,
	"Tracking power.. in Watts per SCA drive [W/m2], number.\n Required.",
 	NULL},
{"Shadowing", (getter)Solarfield_get_Shadowing,(setter)Solarfield_set_Shadowing,
	"(boiler, SH) Receiver bellows shadowing loss factor (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"SolarAz_init", (getter)Solarfield_get_SolarAz_init,(setter)Solarfield_set_SolarAz_init,
	"Solar azimuth angle [deg], number.\n Required.",
 	NULL},
{"SolarZen", (getter)Solarfield_get_SolarZen,(setter)Solarfield_set_SolarZen,
	"Solar zenith angle [deg], number.\n Required.",
 	NULL},
{"T_amb_des_sf", (getter)Solarfield_get_T_amb_des_sf,(setter)Solarfield_set_T_amb_des_sf,
	"Design-point ambient temperature [C], number.\n Required.",
 	NULL},
{"T_db", (getter)Solarfield_get_T_db,(setter)Solarfield_set_T_db,
	"Dry bulb air temperature [C], number.\n Required.",
 	NULL},
{"T_dp", (getter)Solarfield_get_T_dp,(setter)Solarfield_set_T_dp,
	"The dewpoint temperature [C], number.\n Required.",
 	NULL},
{"T_fp", (getter)Solarfield_get_T_fp,(setter)Solarfield_set_T_fp,
	"Freeze protection temperature (heat trace activation temperature) [C], number.\n Required.",
 	NULL},
{"T_pb_out_init", (getter)Solarfield_get_T_pb_out_init,(setter)Solarfield_set_T_pb_out_init,
	"Fluid temperature from the power block [C], number.\n Required.",
 	NULL},
{"Tau_envelope", (getter)Solarfield_get_Tau_envelope,(setter)Solarfield_set_Tau_envelope,
	"(boiler, SH) Envelope transmittance (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"TrackingError", (getter)Solarfield_get_TrackingError,(setter)Solarfield_set_TrackingError,
	"(boiler, SH) User-defined tracking error derate [none], matrix.\n Required.",
 	NULL},
{"V_wind", (getter)Solarfield_get_V_wind,(setter)Solarfield_set_V_wind,
	"Ambient windspeed [m/s], number.\n Required.",
 	NULL},
{"V_wind_max", (getter)Solarfield_get_V_wind_max,(setter)Solarfield_set_V_wind_max,
	"Maximum allowable wind velocity before safety stow [m/s], number.\n Required.",
 	NULL},
{"alpha_abs", (getter)Solarfield_get_alpha_abs,(setter)Solarfield_set_alpha_abs,
	"(boiler, SH) Absorber absorptance (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"alpha_env", (getter)Solarfield_get_alpha_env,(setter)Solarfield_set_alpha_env,
	"(boiler, SH) Envelope absorptance (4: # field fracs) [none], matrix.\n Required.",
 	NULL},
{"aux_array", (getter)Solarfield_get_aux_array,(setter)Solarfield_set_aux_array,
	"Aux_parVal, Aux_parPF, Aux_par0, Aux_par1, Aux_par2 [-], array.\n Required.",
 	NULL},
{"b_OpticalTable", (getter)Solarfield_get_b_OpticalTable,(setter)Solarfield_set_b_OpticalTable,
	"Values of the optical efficiency table [none], matrix.\n Required.",
 	NULL},
{"b_eps_HCE1", (getter)Solarfield_get_b_eps_HCE1,(setter)Solarfield_set_b_eps_HCE1,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"b_eps_HCE2", (getter)Solarfield_get_b_eps_HCE2,(setter)Solarfield_set_b_eps_HCE2,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"b_eps_HCE3", (getter)Solarfield_get_b_eps_HCE3,(setter)Solarfield_set_b_eps_HCE3,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"b_eps_HCE4", (getter)Solarfield_get_b_eps_HCE4,(setter)Solarfield_set_b_eps_HCE4,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"bop_array", (getter)Solarfield_get_bop_array,(setter)Solarfield_set_bop_array,
	"BOP_parVal, BOP_parPF, BOP_par0, BOP_par1, BOP_par2 [-], array.\n Required.",
 	NULL},
{"cycle_cutoff_frac", (getter)Solarfield_get_cycle_cutoff_frac,(setter)Solarfield_set_cycle_cutoff_frac,
	"Minimum turbine operation fraction before shutdown [none], number.\n Required.",
 	NULL},
{"cycle_max_fraction", (getter)Solarfield_get_cycle_max_fraction,(setter)Solarfield_set_cycle_max_fraction,
	"Maximum turbine over design operation fraction [none], number.\n Required.",
 	NULL},
{"dirt_mirror", (getter)Solarfield_get_dirt_mirror,(setter)Solarfield_set_dirt_mirror,
	"(boiler, SH) User-defined dirt on mirror derate [none], matrix.\n Required.",
 	NULL},
{"dnifc", (getter)Solarfield_get_dnifc,(setter)Solarfield_set_dnifc,
	"Forecast DNI [W/m2], number.\n Required.",
 	NULL},
{"e_startup", (getter)Solarfield_get_e_startup,(setter)Solarfield_set_e_startup,
	"Thermal inertia contribution per sq meter of solar field [kJ/K-m2], number.\n Required.",
 	NULL},
{"error", (getter)Solarfield_get_error,(setter)Solarfield_set_error,
	"(boiler, SH) User-defined general optical error derate [none], matrix.\n Required.",
 	NULL},
{"eta_pump", (getter)Solarfield_get_eta_pump,(setter)Solarfield_set_eta_pump,
	"Feedwater pump efficiency [none], number.\n Required.",
 	NULL},
{"fP_boil_to_sh", (getter)Solarfield_get_fP_boil_to_sh,(setter)Solarfield_set_fP_boil_to_sh,
	"Design-point pressure drop between the boiler and superheater frac [none], number.\n Required.",
 	NULL},
{"fP_hdr_c", (getter)Solarfield_get_fP_hdr_c,(setter)Solarfield_set_fP_hdr_c,
	"Average design-point cold header pressure drop fraction [none], number.\n Required.",
 	NULL},
{"fP_hdr_h", (getter)Solarfield_get_fP_hdr_h,(setter)Solarfield_set_fP_hdr_h,
	"Average design-point hot header pressure drop fraction [none], number.\n Required.",
 	NULL},
{"fP_sf_boil", (getter)Solarfield_get_fP_sf_boil,(setter)Solarfield_set_fP_sf_boil,
	"Design-point pressure drop across the solar field boiler fraction [none], number.\n Required.",
 	NULL},
{"fP_sf_sh", (getter)Solarfield_get_fP_sf_sh,(setter)Solarfield_set_fP_sf_sh,
	"Design-point pressure drop across the solar field superheater frac [none], number.\n Required.",
 	NULL},
{"ffrac", (getter)Solarfield_get_ffrac,(setter)Solarfield_set_ffrac,
	"Fossil dispatch logic - TOU periods [none], array.\n Required.",
 	NULL},
{"fossil_mode", (getter)Solarfield_get_fossil_mode,(setter)Solarfield_set_fossil_mode,
	"Operation mode for the fossil backup {1=Normal,2=supp,3=toppin} [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"is_multgeom", (getter)Solarfield_get_is_multgeom,(setter)Solarfield_set_is_multgeom,
	"Does the superheater have a different geometry from the boiler {1=yes} [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"is_oncethru", (getter)Solarfield_get_is_oncethru,(setter)Solarfield_set_is_oncethru,
	"Flag indicating whether flow is once through with superheat [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"is_sh", (getter)Solarfield_get_is_sh,(setter)Solarfield_set_is_sh,
	"Does the solar field include a superheating section [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"latitude", (getter)Solarfield_get_latitude,(setter)Solarfield_set_latitude,
	"Site latitude resource page [deg], number.\n Required.",
 	NULL},
{"m_dot_htf_ref", (getter)Solarfield_get_m_dot_htf_ref,(setter)Solarfield_set_m_dot_htf_ref,
	"Reference HTF flow rate at design conditions [kg/hr], number.\n Required.",
 	NULL},
{"m_dot_min", (getter)Solarfield_get_m_dot_min,(setter)Solarfield_set_m_dot_min,
	"Minimum loop flow rate [kg/s], number.\n Required.",
 	NULL},
{"m_pb_demand", (getter)Solarfield_get_m_pb_demand,(setter)Solarfield_set_m_pb_demand,
	"Demand htf flow from the power block [kg/hr], number.\n Required.",
 	NULL},
{"nLoops", (getter)Solarfield_get_nLoops,(setter)Solarfield_set_nLoops,
	"Number of loops [none], number.\n Required.",
 	NULL},
{"nModBoil", (getter)Solarfield_get_nModBoil,(setter)Solarfield_set_nModBoil,
	"Number of modules in the boiler section [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"nModSH", (getter)Solarfield_get_nModSH,(setter)Solarfield_set_nModSH,
	"Number of modules in the superheater section [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"q_max_aux", (getter)Solarfield_get_q_max_aux,(setter)Solarfield_set_q_max_aux,
	"Maximum heat rate of the auxiliary heater [MW], number.\n Required.",
 	NULL},
{"q_pb_des", (getter)Solarfield_get_q_pb_des,(setter)Solarfield_set_q_pb_des,
	"Design heat input to the power block [MW], number.\n Required.",
 	NULL},
{"q_sby_frac", (getter)Solarfield_get_q_sby_frac,(setter)Solarfield_set_q_sby_frac,
	"Fraction of thermal power required for standby [none], number.\n Required.",
 	NULL},
{"rho_mirror_clean", (getter)Solarfield_get_rho_mirror_clean,(setter)Solarfield_set_rho_mirror_clean,
	"(boiler, SH) User-defined clean mirror reflectivity [none], matrix.\n Required.",
 	NULL},
{"sh_OpticalTable", (getter)Solarfield_get_sh_OpticalTable,(setter)Solarfield_set_sh_OpticalTable,
	"Values of the optical efficiency table [none], matrix.\n Required.",
 	NULL},
{"sh_eps_HCE1", (getter)Solarfield_get_sh_eps_HCE1,(setter)Solarfield_set_sh_eps_HCE1,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"sh_eps_HCE2", (getter)Solarfield_get_sh_eps_HCE2,(setter)Solarfield_set_sh_eps_HCE2,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"sh_eps_HCE3", (getter)Solarfield_get_sh_eps_HCE3,(setter)Solarfield_set_sh_eps_HCE3,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"sh_eps_HCE4", (getter)Solarfield_get_sh_eps_HCE4,(setter)Solarfield_set_sh_eps_HCE4,
	"(temperature) Absorber emittance (eps) [none], matrix.\n Required.",
 	NULL},
{"shift", (getter)Solarfield_get_shift,(setter)Solarfield_set_shift,
	"Shift in longitude from local standard meridian [deg], number.\n Required.",
 	NULL},
{"solarm", (getter)Solarfield_get_solarm,(setter)Solarfield_set_solarm,
	"Solar multiple [none], number.\n Required.",
 	NULL},
{"t_sby", (getter)Solarfield_get_t_sby,(setter)Solarfield_set_t_sby,
	"Low resource standby period [hr], number.\n Required.",
 	NULL},
{"tes_hours", (getter)Solarfield_get_tes_hours,(setter)Solarfield_set_tes_hours,
	"Equivalent full-load thermal storage hours [hr], number.\n Required.",
 	NULL},
{"theta_dep", (getter)Solarfield_get_theta_dep,(setter)Solarfield_set_theta_dep,
	"deploy angle [deg], number.\n Required.",
 	NULL},
{"theta_stow", (getter)Solarfield_get_theta_stow,(setter)Solarfield_set_theta_stow,
	"stow angle [deg], number.\n Required.",
 	NULL},
{"x_b_des", (getter)Solarfield_get_x_b_des,(setter)Solarfield_set_x_b_des,
	"Design point boiler outlet steam quality [none], number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Solarfield_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Solarfield",             /*tp_name*/
		sizeof(SolarfieldObject),          /*tp_basicsize*/
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
		Solarfield_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Solarfield_getset,          /*tp_getset*/
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
	 * Heliostat Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcslinearFresnel   data_ptr;
} HeliostatObject;

static PyTypeObject Heliostat_Type;

static PyObject *
Heliostat_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = Heliostat_Type.tp_alloc(&Heliostat_Type,0);

	HeliostatObject* Heliostat_obj = (HeliostatObject*)new_obj;

	Heliostat_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Heliostat methods */

static PyObject *
Heliostat_assign(HeliostatObject *self, PyObject *args)
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
Heliostat_export(HeliostatObject *self, PyObject *args)
{
	PyTypeObject* tp = &Heliostat_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Heliostat_methods[] = {
		{"assign",            (PyCFunction)Heliostat_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Heliostat_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Heliostat_get_csp_lf_sf_washes_per_year(HeliostatObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Heliostat_csp_lf_sf_washes_per_year_fget, self->data_ptr);
}

static int
Heliostat_set_csp_lf_sf_washes_per_year(HeliostatObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Heliostat_csp_lf_sf_washes_per_year_fset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_lf_sf_water_per_wash(HeliostatObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Heliostat_csp_lf_sf_water_per_wash_fget, self->data_ptr);
}

static int
Heliostat_set_csp_lf_sf_water_per_wash(HeliostatObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Heliostat_csp_lf_sf_water_per_wash_fset, self->data_ptr);
}

static PyGetSetDef Heliostat_getset[] = {
{"csp_lf_sf_washes_per_year", (getter)Heliostat_get_csp_lf_sf_washes_per_year,(setter)Heliostat_set_csp_lf_sf_washes_per_year,
	"Mirror washing frequency, number.\n Required.",
 	NULL},
{"csp_lf_sf_water_per_wash", (getter)Heliostat_get_csp_lf_sf_water_per_wash,(setter)Heliostat_set_csp_lf_sf_water_per_wash,
	"Water usage per wash [L/m2_aper], number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Heliostat_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Heliostat",             /*tp_name*/
		sizeof(HeliostatObject),          /*tp_basicsize*/
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
		Heliostat_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Heliostat_getset,          /*tp_getset*/
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
	 * Powerblock Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcslinearFresnel   data_ptr;
} PowerblockObject;

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TcslinearFresnel data_ptr)
{
	PyObject* new_obj = Powerblock_Type.tp_alloc(&Powerblock_Type,0);

	PowerblockObject* Powerblock_obj = (PowerblockObject*)new_obj;

	Powerblock_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Powerblock methods */

static PyObject *
Powerblock_assign(PowerblockObject *self, PyObject *args)
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
Powerblock_export(PowerblockObject *self, PyObject *args)
{
	PyTypeObject* tp = &Powerblock_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Powerblock_methods[] = {
		{"assign",            (PyCFunction)Powerblock_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Powerblock_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Powerblock_get_CT(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_CT_fget, self->data_ptr);
}

static int
Powerblock_set_CT(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_CT_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(PowerblockObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(PowerblockObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcslinearFresnel_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_amb_pwb(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_P_amb_pwb_fget, self->data_ptr);
}

static int
Powerblock_set_P_amb_pwb(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_P_amb_pwb_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_boil_des(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_P_boil_des_fget, self->data_ptr);
}

static int
Powerblock_set_P_boil_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_P_boil_des_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_P_cond_min_fget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_P_cond_min_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_P_cond_ratio_fget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_P_cond_ratio_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_rh_ref(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_P_rh_ref_fget, self->data_ptr);
}

static int
Powerblock_set_P_rh_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_P_rh_ref_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_ITD_des_fget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_ITD_des_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_amb_des_fget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_amb_des_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_approach_fget, self->data_ptr);
}

static int
Powerblock_set_T_approach(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_approach_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_cold_ref(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_cold_ref_fget, self->data_ptr);
}

static int
Powerblock_set_T_cold_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_cold_ref_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_db_pwb(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_db_pwb_fget, self->data_ptr);
}

static int
Powerblock_set_T_db_pwb(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_db_pwb_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_hot(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_hot_fget, self->data_ptr);
}

static int
Powerblock_set_T_hot(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_hot_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_wb(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_T_wb_fget, self->data_ptr);
}

static int
Powerblock_set_T_wb(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_T_wb_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_dT_cw_ref_fget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_dT_cw_ref_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_demand_var(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_demand_var_fget, self->data_ptr);
}

static int
Powerblock_set_demand_var(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_demand_var_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_dp_b(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_dp_b_fget, self->data_ptr);
}

static int
Powerblock_set_dp_b(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_dp_b_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_dp_rh(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_dp_rh_fget, self->data_ptr);
}

static int
Powerblock_set_dp_rh(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_dp_rh_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_dp_sh(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_dp_sh_fget, self->data_ptr);
}

static int
Powerblock_set_dp_sh(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_dp_sh_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_eta_ref_fget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_eta_ref_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_f_recSU(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_f_recSU_fget, self->data_ptr);
}

static int
Powerblock_set_f_recSU(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_f_recSU_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_m_dot_st(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_m_dot_st_fget, self->data_ptr);
}

static int
Powerblock_set_m_dot_st(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_m_dot_st_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_n_pl_inc_fget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_n_pl_inc_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_pb_bd_frac_fget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_pb_bd_frac_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_mode(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_pc_mode_fget, self->data_ptr);
}

static int
Powerblock_set_pc_mode(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_pc_mode_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_q_sby_frac_fget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_q_sby_frac_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_relhum(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_relhum_fget, self->data_ptr);
}

static int
Powerblock_set_relhum(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_relhum_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_rh_frac_ref(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_rh_frac_ref_fget, self->data_ptr);
}

static int
Powerblock_set_rh_frac_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_rh_frac_ref_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_standby_control(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_standby_control_fget, self->data_ptr);
}

static int
Powerblock_set_standby_control(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_standby_control_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_startup_frac_fget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_startup_frac_fset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(PowerblockObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Powerblock_startup_time_fget, self->data_ptr);
}

static int
Powerblock_set_startup_time(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcslinearFresnel_Powerblock_startup_time_fset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"CT", (getter)Powerblock_get_CT,(setter)Powerblock_set_CT,
	"Flag for using dry cooling or wet cooling system [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	"Fraction indicating wet cooling use for hybrid system [none], array.\n Required.",
 	NULL},
{"P_amb_pwb", (getter)Powerblock_get_P_amb_pwb,(setter)Powerblock_set_P_amb_pwb,
	"Ambient pressure [atm], number.\n Required.",
 	NULL},
{"P_boil_des", (getter)Powerblock_get_P_boil_des,(setter)Powerblock_set_P_boil_des,
	"Boiler operating pressure @ design [bar], number.\n Required.",
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	"Minimum condenser pressure [inHg], number.\n Required.",
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	"Condenser pressure ratio [none], number.\n Required.",
 	NULL},
{"P_rh_ref", (getter)Powerblock_get_P_rh_ref,(setter)Powerblock_set_P_rh_ref,
	"Reheater operating pressure at design [bar], number.\n Required.",
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	"ITD at design for dry system [C], number.\n Required.",
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	"Reference ambient temperature at design point [C], number.\n Required.",
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	"Cooling tower approach temperature [C], number.\n Required.",
 	NULL},
{"T_cold_ref", (getter)Powerblock_get_T_cold_ref,(setter)Powerblock_set_T_cold_ref,
	"Reference HTF outlet temperature at design [C], number.\n Required.",
 	NULL},
{"T_db_pwb", (getter)Powerblock_get_T_db_pwb,(setter)Powerblock_set_T_db_pwb,
	"Ambient dry bulb temperature [C], number.\n Required.",
 	NULL},
{"T_hot", (getter)Powerblock_get_T_hot,(setter)Powerblock_set_T_hot,
	"Hot HTF inlet temperature, from storage tank [C], number.\n Required.",
 	NULL},
{"T_wb", (getter)Powerblock_get_T_wb,(setter)Powerblock_set_T_wb,
	"Ambient wet bulb temperature [C], number.\n Required.",
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	"Reference condenser cooling water inlet/outlet T diff [C], number.\n Required.",
 	NULL},
{"demand_var", (getter)Powerblock_get_demand_var,(setter)Powerblock_set_demand_var,
	"Control signal indicating operational mode [none], number.\n Required.",
 	NULL},
{"dp_b", (getter)Powerblock_get_dp_b,(setter)Powerblock_set_dp_b,
	"Pressure drop in boiler [Pa], number.\n Required.",
 	NULL},
{"dp_rh", (getter)Powerblock_get_dp_rh,(setter)Powerblock_set_dp_rh,
	"Pressure drop in reheater [Pa], number.\n Required.",
 	NULL},
{"dp_sh", (getter)Powerblock_get_dp_sh,(setter)Powerblock_set_dp_sh,
	"Pressure drop in superheater [Pa], number.\n Required.",
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	"Reference conversion efficiency at design condition [none], number.\n Required.",
 	NULL},
{"f_recSU", (getter)Powerblock_get_f_recSU,(setter)Powerblock_set_f_recSU,
	"Fraction powerblock can run due to receiver startup [none], number.\n Required.",
 	NULL},
{"m_dot_st", (getter)Powerblock_get_m_dot_st,(setter)Powerblock_set_m_dot_st,
	"HTF mass flow rate [kg/hr], number.\n Required.",
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	"Number of part-load increments for the heat rejection system [none], number.\n Constraints: INTEGER; Required.",
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	"Power block blowdown steam fraction  [none], number.\n Required.",
 	NULL},
{"pc_mode", (getter)Powerblock_get_pc_mode,(setter)Powerblock_set_pc_mode,
	"Cycle part load control, from plant controller [none], number.\n Required.",
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	"Fraction of thermal power required for standby mode [none], number.\n Required.",
 	NULL},
{"relhum", (getter)Powerblock_get_relhum,(setter)Powerblock_set_relhum,
	"Relative humidity of the ambient air [none], number.\n Required.",
 	NULL},
{"rh_frac_ref", (getter)Powerblock_get_rh_frac_ref,(setter)Powerblock_set_rh_frac_ref,
	"Reheater flow fraction at design [none], number.\n Required.",
 	NULL},
{"standby_control", (getter)Powerblock_get_standby_control,(setter)Powerblock_set_standby_control,
	"Control signal indicating standby mode [none], number.\n Required.",
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	"Fraction of design thermal power needed for startup [none], number.\n Required.",
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	"Time needed for power block startup [hr], number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel.Powerblock",             /*tp_name*/
		sizeof(PowerblockObject),          /*tp_basicsize*/
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
		Powerblock_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Powerblock_getset,          /*tp_getset*/
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
	SAM_TcslinearFresnel   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_TcslinearFresnel data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcslinearFresnel", "Outputs")){
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
Outputs_get_E_bal_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_E_bal_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cond(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_P_cond_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_sf_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_P_sf_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_turb_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_P_turb_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_field_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_field_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_loop_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_loop_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pb_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_pb_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pb_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_T_pb_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_cool_par(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_cool_par_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_cycle_gross(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_cycle_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_aux(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_bop(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_bop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_col(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_col_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_fixed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pump(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_dot_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_net(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_W_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_annual_W_cycle_gross_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_annual_fuel_usage_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_annual_total_water_use_fget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_conversion_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_dP_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_dP_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_opt_ave(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_opt_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_thermal(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_eta_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_bays(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_f_bays_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_aux(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_b_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_b_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_makeup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_makeup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_m_dot_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux_fluid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_aux_fluid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux_fuel(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_aux_fuel_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dump(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_dump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_field_delivered(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_field_delivered_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_inc_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_piping(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_loss_piping_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_rec(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_loss_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_loss_sf(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_loss_sf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcslinearFresnel_Outputs_system_heat_rate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcslinearFresnel_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"E_bal_startup", (getter)Outputs_get_E_bal_startup,(setter)0,
	"Cycle thermal energy startup [MWt], array.",
 	NULL},
{"P_cond", (getter)Outputs_get_P_cond,(setter)0,
	"Condenser pressure [Pa], array.",
 	NULL},
{"P_sf_in", (getter)Outputs_get_P_sf_in,(setter)0,
	"Field steam pressure at inlet [bar], array.",
 	NULL},
{"P_turb_in", (getter)Outputs_get_P_turb_in,(setter)0,
	"Cycle steam pressure at inlet [bar], array.",
 	NULL},
{"T_field_in", (getter)Outputs_get_T_field_in,(setter)0,
	"Field steam temperature at header inlet [C], array.",
 	NULL},
{"T_field_out", (getter)Outputs_get_T_field_out,(setter)0,
	"Field steam temperature at header outlet [C], array.",
 	NULL},
{"T_loop_out", (getter)Outputs_get_T_loop_out,(setter)0,
	"Field steam temperature at collector outlet [C], array.",
 	NULL},
{"T_pb_in", (getter)Outputs_get_T_pb_in,(setter)0,
	"Cycle steam temperature at inlet [C], array.",
 	NULL},
{"T_pb_out", (getter)Outputs_get_T_pb_out,(setter)0,
	"Cycle steam temperature at outlet [C], array.",
 	NULL},
{"W_cool_par", (getter)Outputs_get_W_cool_par,(setter)0,
	"Parasitic power condenser operation [MWe], array.",
 	NULL},
{"W_cycle_gross", (getter)Outputs_get_W_cycle_gross,(setter)0,
	"Cycle electrical power output (gross) [MWe], array.",
 	NULL},
{"W_dot_aux", (getter)Outputs_get_W_dot_aux,(setter)0,
	"Parasitic power auxiliary heater operation [MWe], array.",
 	NULL},
{"W_dot_bop", (getter)Outputs_get_W_dot_bop,(setter)0,
	"Parasitic power generation-dependent load [MWe], array.",
 	NULL},
{"W_dot_col", (getter)Outputs_get_W_dot_col,(setter)0,
	"Parasitic power field collector drives [MWe], array.",
 	NULL},
{"W_dot_fixed", (getter)Outputs_get_W_dot_fixed,(setter)0,
	"Parasitic power fixed load [MWe], array.",
 	NULL},
{"W_dot_pump", (getter)Outputs_get_W_dot_pump,(setter)0,
	"Parasitic power solar field pump [MWe], array.",
 	NULL},
{"W_net", (getter)Outputs_get_W_net,(setter)0,
	"Cycle electrical power output (net) [MWe], array.",
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	"Electrical source - Power cycle gross output [kWh], number.",
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual Energy [kWh], number.",
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	"Annual fuel usage [kWh], number.",
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	"Total Annual Water Usage: cycle + mirror washing [m3], number.",
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
{"dP_tot", (getter)Outputs_get_dP_tot,(setter)0,
	"Field steam pressure loss [bar], array.",
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	"Field collector focus fraction, array.",
 	NULL},
{"eta", (getter)Outputs_get_eta,(setter)0,
	"Cycle efficiency (gross), array.",
 	NULL},
{"eta_opt_ave", (getter)Outputs_get_eta_opt_ave,(setter)0,
	"Field collector optical efficiency, array.",
 	NULL},
{"eta_sf", (getter)Outputs_get_eta_sf,(setter)0,
	"Field efficiency total, array.",
 	NULL},
{"eta_thermal", (getter)Outputs_get_eta_thermal,(setter)0,
	"Field thermal efficiency, array.",
 	NULL},
{"f_bays", (getter)Outputs_get_f_bays,(setter)0,
	"Condenser fraction of operating bays [none], array.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"System power generated [kW], array.",
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	"Resource Hour of Day, array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"m_dot", (getter)Outputs_get_m_dot,(setter)0,
	"Field steam mass flow rate - loop [kg/s], array.",
 	NULL},
{"m_dot_aux", (getter)Outputs_get_m_dot_aux,(setter)0,
	"Fossil steam mass flow rate [kg/hr], array.",
 	NULL},
{"m_dot_b_tot", (getter)Outputs_get_m_dot_b_tot,(setter)0,
	"Field steam mass flow rate - boiler [kg/hr], array.",
 	NULL},
{"m_dot_field", (getter)Outputs_get_m_dot_field,(setter)0,
	"Field steam mass flow rate [kg/hr], array.",
 	NULL},
{"m_dot_makeup", (getter)Outputs_get_m_dot_makeup,(setter)0,
	"Cycle cooling water mass flow rate - makeup [kg/hr], array.",
 	NULL},
{"m_dot_to_pb", (getter)Outputs_get_m_dot_to_pb,(setter)0,
	"Cycle steam mass flow rate [kg/hr], array.",
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	"Resource Month, array.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly Energy [kWh], array.",
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	"Resource Pressure [mbar], array.",
 	NULL},
{"q_aux_fluid", (getter)Outputs_get_q_aux_fluid,(setter)0,
	"Fossil thermal power produced [MWt], array.",
 	NULL},
{"q_aux_fuel", (getter)Outputs_get_q_aux_fuel,(setter)0,
	"Fossil fuel usage [MMBTU], array.",
 	NULL},
{"q_dump", (getter)Outputs_get_q_dump,(setter)0,
	"Cycle thermal energy dumped [MWt], array.",
 	NULL},
{"q_field_delivered", (getter)Outputs_get_q_field_delivered,(setter)0,
	"Field thermal power produced [MWt], array.",
 	NULL},
{"q_inc_tot", (getter)Outputs_get_q_inc_tot,(setter)0,
	"Field thermal power incident [MWt], array.",
 	NULL},
{"q_loss_piping", (getter)Outputs_get_q_loss_piping,(setter)0,
	"Field thermal power header pipe loss [MWt], array.",
 	NULL},
{"q_loss_rec", (getter)Outputs_get_q_loss_rec,(setter)0,
	"Field thermal power receiver loss [MWt], array.",
 	NULL},
{"q_loss_sf", (getter)Outputs_get_q_loss_sf,(setter)0,
	"Field thermal power loss [MWt], array.",
 	NULL},
{"q_to_pb", (getter)Outputs_get_q_to_pb,(setter)0,
	"Cycle thermal power input [MWt], array.",
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
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	"Resource Time-of-use value, array.",
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	"Resource Wet bulb temperature [C], array.",
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
		"TcslinearFresnel.Outputs",             /*tp_name*/
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
 * TcslinearFresnel
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_TcslinearFresnel   data_ptr;
} TcslinearFresnelObject;

static PyTypeObject TcslinearFresnel_Type;

#define TcslinearFresnelObject_Check(v)      (Py_TYPE(v) == &TcslinearFresnel_Type)

static TcslinearFresnelObject *
newTcslinearFresnelObject(void* data_ptr)
{
	TcslinearFresnelObject *self;
	self = PyObject_New(TcslinearFresnelObject, &TcslinearFresnel_Type);

	PySAM_TECH_ATTR("TcslinearFresnel", SAM_TcslinearFresnel_construct)

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
		PyErr_SetString(PySAM_ErrorObject, "Couldn't create AdjustmentFactorsObject\n");
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
TcslinearFresnel_dealloc(TcslinearFresnelObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_TcslinearFresnel_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
TcslinearFresnel_execute(TcslinearFresnelObject *self, PyObject *args)
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
TcslinearFresnel_assign(TcslinearFresnelObject *self, PyObject *args)
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
TcslinearFresnel_export(TcslinearFresnelObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef TcslinearFresnel_methods[] = {
		{"execute",            (PyCFunction)TcslinearFresnel_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcslinearFresnel_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)TcslinearFresnel_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcslinearFresnel_getattro(TcslinearFresnelObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcslinearFresnel_setattr(TcslinearFresnelObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcslinearFresnel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcslinearFresnel",            /*tp_name*/
		sizeof(TcslinearFresnelObject),/*tp_basicsize*/
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
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		TcslinearFresnel_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TcslinearFresnel object */

static PyObject *
TcslinearFresnel_new(PyObject *self, PyObject *args)
{
	TcslinearFresnelObject *rv;
	rv = newTcslinearFresnelObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TcslinearFresnel_wrap(PyObject *self, PyObject *args)
{
	TcslinearFresnelObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcslinearFresnelObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TcslinearFresnel_default(PyObject *self, PyObject *args)
{
	TcslinearFresnelObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcslinearFresnelObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcslinearFresnel", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcslinearFresnelModule_methods[] = {
		{"new",             TcslinearFresnel_new,         METH_VARARGS,
				PyDoc_STR("new() -> new TcslinearFresnel object")},
		{"default",             TcslinearFresnel_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new TcslinearFresnel object with financial model-specific default attributes\n"
				"Options: Singleowner, Saleleaseback, Commercial, Levpartflip, Equpartflip, Lcoefcr, None")},
		{"wrap",             TcslinearFresnel_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new TcslinearFresnel object around existing PySSC data, taking over memory ownership")},
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
	if (PySAM_init_error(m) < 0) goto fail;

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