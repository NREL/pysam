#include <Python.h>

#include <SAM_TcsmoltenSalt.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * LocationAndResource Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} LocationAndResourceObject;

static PyTypeObject LocationAndResource_Type;

static PyObject *
LocationAndResource_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = LocationAndResource_Type.tp_alloc(&LocationAndResource_Type,0);

	LocationAndResourceObject* LocationAndResource_obj = (LocationAndResourceObject*)new_obj;

	LocationAndResource_obj->data_ptr = data_ptr;

	return new_obj;
}

/* LocationAndResource methods */

static PyObject *
LocationAndResource_assign(LocationAndResourceObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "LocationAndResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LocationAndResource_export(LocationAndResourceObject *self, PyObject *args)
{
	PyTypeObject* tp = &LocationAndResource_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef LocationAndResource_methods[] = {
		{"assign",            (PyCFunction)LocationAndResource_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)LocationAndResource_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LocationAndResource_get_solar_resource_data(LocationAndResourceObject *self, void *closure)
{
	return PySAM_table_getter(SAM_TcsmoltenSalt_LocationAndResource_solar_resource_data_tget, self->data_ptr);
}

static int
LocationAndResource_set_solar_resource_data(LocationAndResourceObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_TcsmoltenSalt_LocationAndResource_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
LocationAndResource_get_solar_resource_file(LocationAndResourceObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsmoltenSalt_LocationAndResource_file_sget, self->data_ptr);
}

static int
LocationAndResource_set_solar_resource_file(LocationAndResourceObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsmoltenSalt_LocationAndResource_file_sset, self->data_ptr);
}

static PyGetSetDef LocationAndResource_getset[] = {
{"solar_resource_data", (getter)LocationAndResource_get_solar_resource_data,(setter)LocationAndResource_set_solar_resource_data,
	"Weather resource data in memory [], table.\n Required if: ?.",
 	NULL},
{"solar_resource_file", (getter)LocationAndResource_get_solar_resource_file,(setter)LocationAndResource_set_solar_resource_file,
	"Local weather file path [], string.\n Constraints: LOCAL_FILE; Required if: ?.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject LocationAndResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.LocationAndResource",             /*tp_name*/
		sizeof(LocationAndResourceObject),          /*tp_basicsize*/
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
		LocationAndResource_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		LocationAndResource_getset,          /*tp_getset*/
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
	 * TimeOfDeliveryFactors Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} TimeOfDeliveryFactorsObject;

static PyTypeObject TimeOfDeliveryFactors_Type;

static PyObject *
TimeOfDeliveryFactors_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = TimeOfDeliveryFactors_Type.tp_alloc(&TimeOfDeliveryFactors_Type,0);

	TimeOfDeliveryFactorsObject* TimeOfDeliveryFactors_obj = (TimeOfDeliveryFactorsObject*)new_obj;

	TimeOfDeliveryFactors_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TimeOfDeliveryFactors methods */

static PyObject *
TimeOfDeliveryFactors_assign(TimeOfDeliveryFactorsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "TimeOfDeliveryFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDeliveryFactors_export(TimeOfDeliveryFactorsObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDeliveryFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDeliveryFactors_methods[] = {
		{"assign",            (PyCFunction)TimeOfDeliveryFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)TimeOfDeliveryFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor1(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor1_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor1(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor1_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor2(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor2_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor2(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor2_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor3(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor3_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor3(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor3_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor4(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor4_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor4(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor4_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor5(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor5_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor5(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor5_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor6(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor6_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor6(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor6_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor7(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor7_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor7(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor7_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor8(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor8_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor8(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor8_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor9(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor9_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor9(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factor9_fset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factors_ts(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factors_ts_aget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factors_ts(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekday(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekday(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekend(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekend(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_ppa_multiplier_model(TimeOfDeliveryFactorsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TimeOfDeliveryFactors_ppa_multiplier_model_fget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_ppa_multiplier_model(TimeOfDeliveryFactorsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TimeOfDeliveryFactors_ppa_multiplier_model_fset, self->data_ptr);
}

static PyGetSetDef TimeOfDeliveryFactors_getset[] = {
{"dispatch_factor1", (getter)TimeOfDeliveryFactors_get_dispatch_factor1,(setter)TimeOfDeliveryFactors_set_dispatch_factor1,
	"Dispatch payment factor 1 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor2", (getter)TimeOfDeliveryFactors_get_dispatch_factor2,(setter)TimeOfDeliveryFactors_set_dispatch_factor2,
	"Dispatch payment factor 2 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor3", (getter)TimeOfDeliveryFactors_get_dispatch_factor3,(setter)TimeOfDeliveryFactors_set_dispatch_factor3,
	"Dispatch payment factor 3 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor4", (getter)TimeOfDeliveryFactors_get_dispatch_factor4,(setter)TimeOfDeliveryFactors_set_dispatch_factor4,
	"Dispatch payment factor 4 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor5", (getter)TimeOfDeliveryFactors_get_dispatch_factor5,(setter)TimeOfDeliveryFactors_set_dispatch_factor5,
	"Dispatch payment factor 5 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor6", (getter)TimeOfDeliveryFactors_get_dispatch_factor6,(setter)TimeOfDeliveryFactors_set_dispatch_factor6,
	"Dispatch payment factor 6 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor7", (getter)TimeOfDeliveryFactors_get_dispatch_factor7,(setter)TimeOfDeliveryFactors_set_dispatch_factor7,
	"Dispatch payment factor 7 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor8", (getter)TimeOfDeliveryFactors_get_dispatch_factor8,(setter)TimeOfDeliveryFactors_set_dispatch_factor8,
	"Dispatch payment factor 8 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factor9", (getter)TimeOfDeliveryFactors_get_dispatch_factor9,(setter)TimeOfDeliveryFactors_set_dispatch_factor9,
	"Dispatch payment factor 9 [], number.\n Required if: *.",
 	NULL},
{"dispatch_factors_ts", (getter)TimeOfDeliveryFactors_get_dispatch_factors_ts,(setter)TimeOfDeliveryFactors_set_dispatch_factors_ts,
	"Dispatch payment factor array [], array.\n Required if: ppa_multiplier_model=1.",
 	NULL},
{"dispatch_sched_weekday", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekday,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekday,
	"PPA pricing weekday schedule, 12x24 [], matrix.\n Required if: *.",
 	NULL},
{"dispatch_sched_weekend", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekend,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekend,
	"PPA pricing weekend schedule, 12x24 [], matrix.\n Required if: *.",
 	NULL},
{"ppa_multiplier_model", (getter)TimeOfDeliveryFactors_get_ppa_multiplier_model,(setter)TimeOfDeliveryFactors_set_ppa_multiplier_model,
	"PPA multiplier model [0/1], number.\n 0=diurnal,1=timestep; Constraints: INTEGER,MIN=0; Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDeliveryFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.TimeOfDeliveryFactors",             /*tp_name*/
		sizeof(TimeOfDeliveryFactorsObject),          /*tp_basicsize*/
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
		TimeOfDeliveryFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDeliveryFactors_getset,          /*tp_getset*/
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
	 * HeliostatField Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} HeliostatFieldObject;

static PyTypeObject HeliostatField_Type;

static PyObject *
HeliostatField_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = HeliostatField_Type.tp_alloc(&HeliostatField_Type,0);

	HeliostatFieldObject* HeliostatField_obj = (HeliostatFieldObject*)new_obj;

	HeliostatField_obj->data_ptr = data_ptr;

	return new_obj;
}

/* HeliostatField methods */

static PyObject *
HeliostatField_assign(HeliostatFieldObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "HeliostatField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HeliostatField_export(HeliostatFieldObject *self, PyObject *args)
{
	PyTypeObject* tp = &HeliostatField_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef HeliostatField_methods[] = {
		{"assign",            (PyCFunction)HeliostatField_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)HeliostatField_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HeliostatField_get_A_sf_in(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_A_sf_in_fget, self->data_ptr);
}

static int
HeliostatField_set_A_sf_in(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_A_sf_in_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_N_hel(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_N_hel_fget, self->data_ptr);
}

static int
HeliostatField_set_N_hel(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_N_hel_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_c_atm_0(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_c_atm_0_fget, self->data_ptr);
}

static int
HeliostatField_set_c_atm_0(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_c_atm_0_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_c_atm_1(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_c_atm_1_fget, self->data_ptr);
}

static int
HeliostatField_set_c_atm_1(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_c_atm_1_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_c_atm_2(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_c_atm_2_fget, self->data_ptr);
}

static int
HeliostatField_set_c_atm_2(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_c_atm_2_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_c_atm_3(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_c_atm_3_fget, self->data_ptr);
}

static int
HeliostatField_set_c_atm_3(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_c_atm_3_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_calc_fluxmaps(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_calc_fluxmaps_fget, self->data_ptr);
}

static int
HeliostatField_set_calc_fluxmaps(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_calc_fluxmaps_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_cant_type(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_cant_type_fget, self->data_ptr);
}

static int
HeliostatField_set_cant_type(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_cant_type_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_check_max_flux(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_check_max_flux_fget, self->data_ptr);
}

static int
HeliostatField_set_check_max_flux(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_check_max_flux_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_csp_pt_sf_fixed_land_area(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_csp_pt_sf_fixed_land_area_fget, self->data_ptr);
}

static int
HeliostatField_set_csp_pt_sf_fixed_land_area(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_csp_pt_sf_fixed_land_area_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_csp_pt_sf_land_overhead_factor(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_csp_pt_sf_land_overhead_factor_fget, self->data_ptr);
}

static int
HeliostatField_set_csp_pt_sf_land_overhead_factor(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_csp_pt_sf_land_overhead_factor_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_dens_mirror(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_dens_mirror_fget, self->data_ptr);
}

static int
HeliostatField_set_dens_mirror(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_dens_mirror_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_eta_map(HeliostatFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_HeliostatField_eta_map_mget, self->data_ptr);
}

static int
HeliostatField_set_eta_map(HeliostatFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_HeliostatField_eta_map_mset, self->data_ptr);
}

static PyObject *
HeliostatField_get_eta_map_aod_format(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_eta_map_aod_format_fget, self->data_ptr);
}

static int
HeliostatField_set_eta_map_aod_format(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_eta_map_aod_format_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_field_model_type(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_field_model_type_fget, self->data_ptr);
}

static int
HeliostatField_set_field_model_type(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_field_model_type_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_flux_maps(HeliostatFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_HeliostatField_flux_maps_mget, self->data_ptr);
}

static int
HeliostatField_set_flux_maps(HeliostatFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_HeliostatField_flux_maps_mset, self->data_ptr);
}

static PyObject *
HeliostatField_get_focus_type(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_focus_type_fget, self->data_ptr);
}

static int
HeliostatField_set_focus_type(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_focus_type_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_hel_stow_deploy(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_hel_stow_deploy_fget, self->data_ptr);
}

static int
HeliostatField_set_hel_stow_deploy(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_hel_stow_deploy_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_active_fraction(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_helio_active_fraction_fget, self->data_ptr);
}

static int
HeliostatField_set_helio_active_fraction(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_active_fraction_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_aim_points(HeliostatFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_HeliostatField_helio_aim_points_mget, self->data_ptr);
}

static int
HeliostatField_set_helio_aim_points(HeliostatFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_aim_points_mset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_height(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_helio_height_fget, self->data_ptr);
}

static int
HeliostatField_set_helio_height(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_height_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_optical_error_mrad(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_helio_optical_error_mrad_fget, self->data_ptr);
}

static int
HeliostatField_set_helio_optical_error_mrad(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_optical_error_mrad_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_positions(HeliostatFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_HeliostatField_helio_positions_mget, self->data_ptr);
}

static int
HeliostatField_set_helio_positions(HeliostatFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_positions_mset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_reflectance(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_helio_reflectance_fget, self->data_ptr);
}

static int
HeliostatField_set_helio_reflectance(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_reflectance_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_helio_width(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_helio_width_fget, self->data_ptr);
}

static int
HeliostatField_set_helio_width(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_helio_width_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_land_area_base(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_land_area_base_fget, self->data_ptr);
}

static int
HeliostatField_set_land_area_base(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_land_area_base_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_land_bound_list(HeliostatFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_HeliostatField_land_bound_list_aget, self->data_ptr);
}

static int
HeliostatField_set_land_bound_list(HeliostatFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsmoltenSalt_HeliostatField_land_bound_list_aset, self->data_ptr);
}

static PyObject *
HeliostatField_get_land_bound_table(HeliostatFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_HeliostatField_land_bound_table_mget, self->data_ptr);
}

static int
HeliostatField_set_land_bound_table(HeliostatFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_HeliostatField_land_bound_table_mset, self->data_ptr);
}

static PyObject *
HeliostatField_get_land_max(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_land_max_fget, self->data_ptr);
}

static int
HeliostatField_set_land_max(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_land_max_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_land_min(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_land_min_fget, self->data_ptr);
}

static int
HeliostatField_set_land_min(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_land_min_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_n_facet_x(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_n_facet_x_fget, self->data_ptr);
}

static int
HeliostatField_set_n_facet_x(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_n_facet_x_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_n_facet_y(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_n_facet_y_fget, self->data_ptr);
}

static int
HeliostatField_set_n_facet_y(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_n_facet_y_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_opt_algorithm(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_opt_algorithm_fget, self->data_ptr);
}

static int
HeliostatField_set_opt_algorithm(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_opt_algorithm_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_opt_conv_tol(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_opt_conv_tol_fget, self->data_ptr);
}

static int
HeliostatField_set_opt_conv_tol(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_opt_conv_tol_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_opt_flux_penalty(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_opt_flux_penalty_fget, self->data_ptr);
}

static int
HeliostatField_set_opt_flux_penalty(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_opt_flux_penalty_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_opt_init_step(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_opt_init_step_fget, self->data_ptr);
}

static int
HeliostatField_set_opt_init_step(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_opt_init_step_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_opt_max_iter(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_opt_max_iter_fget, self->data_ptr);
}

static int
HeliostatField_set_opt_max_iter(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_opt_max_iter_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_p_start(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_p_start_fget, self->data_ptr);
}

static int
HeliostatField_set_p_start(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_p_start_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_p_track(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_p_track_fget, self->data_ptr);
}

static int
HeliostatField_set_p_track(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_p_track_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_v_wind_max(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_v_wind_max_fget, self->data_ptr);
}

static int
HeliostatField_set_v_wind_max(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_v_wind_max_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_washing_frequency(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_washing_frequency_fget, self->data_ptr);
}

static int
HeliostatField_set_washing_frequency(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_washing_frequency_fset, self->data_ptr);
}

static PyObject *
HeliostatField_get_water_usage_per_wash(HeliostatFieldObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_HeliostatField_water_usage_per_wash_fget, self->data_ptr);
}

static int
HeliostatField_set_water_usage_per_wash(HeliostatFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_HeliostatField_water_usage_per_wash_fset, self->data_ptr);
}

static PyGetSetDef HeliostatField_getset[] = {
{"A_sf_in", (getter)HeliostatField_get_A_sf_in,(setter)HeliostatField_set_A_sf_in,
	"Solar field area [m^2], number.\n ",
 	NULL},
{"N_hel", (getter)HeliostatField_get_N_hel,(setter)HeliostatField_set_N_hel,
	"Number of heliostats [], number.\n ",
 	NULL},
{"c_atm_0", (getter)HeliostatField_get_c_atm_0,(setter)HeliostatField_set_c_atm_0,
	"Attenuation coefficient 0 [], number.\n Required if: ?=0.006789.",
 	NULL},
{"c_atm_1", (getter)HeliostatField_get_c_atm_1,(setter)HeliostatField_set_c_atm_1,
	"Attenuation coefficient 1 [], number.\n Required if: ?=0.1046.",
 	NULL},
{"c_atm_2", (getter)HeliostatField_get_c_atm_2,(setter)HeliostatField_set_c_atm_2,
	"Attenuation coefficient 2 [], number.\n Required if: ?=-0.0107.",
 	NULL},
{"c_atm_3", (getter)HeliostatField_get_c_atm_3,(setter)HeliostatField_set_c_atm_3,
	"Attenuation coefficient 3 [], number.\n Required if: ?=0.002845.",
 	NULL},
{"calc_fluxmaps", (getter)HeliostatField_get_calc_fluxmaps,(setter)HeliostatField_set_calc_fluxmaps,
	"Include fluxmap calculations [], number.\n Required if: ?=0.",
 	NULL},
{"cant_type", (getter)HeliostatField_get_cant_type,(setter)HeliostatField_set_cant_type,
	"Heliostat canting method [], number.\n Required if: *.",
 	NULL},
{"check_max_flux", (getter)HeliostatField_get_check_max_flux,(setter)HeliostatField_set_check_max_flux,
	"Check max flux at design point [], number.\n Required if: ?=0.",
 	NULL},
{"csp_pt_sf_fixed_land_area", (getter)HeliostatField_get_csp_pt_sf_fixed_land_area,(setter)HeliostatField_set_csp_pt_sf_fixed_land_area,
	"Fixed land area [acre], number.\n Required if: *.",
 	NULL},
{"csp_pt_sf_land_overhead_factor", (getter)HeliostatField_get_csp_pt_sf_land_overhead_factor,(setter)HeliostatField_set_csp_pt_sf_land_overhead_factor,
	"Land overhead factor [], number.\n Required if: *.",
 	NULL},
{"dens_mirror", (getter)HeliostatField_get_dens_mirror,(setter)HeliostatField_set_dens_mirror,
	"Ratio of heliostat reflective area to profile [], number.\n Required if: *.",
 	NULL},
{"eta_map", (getter)HeliostatField_get_eta_map,(setter)HeliostatField_set_eta_map,
	"Field efficiency array [], matrix.\n Required if: ?.",
 	NULL},
{"eta_map_aod_format", (getter)HeliostatField_get_eta_map_aod_format,(setter)HeliostatField_set_eta_map_aod_format,
	"Use 3D AOD format field efficiency array [], number.\n heliostat; ",
 	NULL},
{"field_model_type", (getter)HeliostatField_get_field_model_type,(setter)HeliostatField_set_field_model_type,
	"0=design field and tower/receiver geometry, 1=design field, 2=user specified field, 3=user performance maps vs solar position [], number.\n Required if: *.",
 	NULL},
{"flux_maps", (getter)HeliostatField_get_flux_maps,(setter)HeliostatField_set_flux_maps,
	"Flux map intensities [], matrix.\n Required if: ?.",
 	NULL},
{"focus_type", (getter)HeliostatField_get_focus_type,(setter)HeliostatField_set_focus_type,
	"Heliostat focus method [], number.\n Required if: *.",
 	NULL},
{"hel_stow_deploy", (getter)HeliostatField_get_hel_stow_deploy,(setter)HeliostatField_set_hel_stow_deploy,
	"Stow/deploy elevation angle [deg], number.\n Required if: *.",
 	NULL},
{"helio_active_fraction", (getter)HeliostatField_get_helio_active_fraction,(setter)HeliostatField_set_helio_active_fraction,
	"Heliostat active fraction [], number.\n Required if: *.",
 	NULL},
{"helio_aim_points", (getter)HeliostatField_get_helio_aim_points,(setter)HeliostatField_set_helio_aim_points,
	"Heliostat aim point table [m], matrix.\n Required if: ?.",
 	NULL},
{"helio_height", (getter)HeliostatField_get_helio_height,(setter)HeliostatField_set_helio_height,
	"Heliostat height [m], number.\n Required if: *.",
 	NULL},
{"helio_optical_error_mrad", (getter)HeliostatField_get_helio_optical_error_mrad,(setter)HeliostatField_set_helio_optical_error_mrad,
	"Heliostat optical error [mrad], number.\n Required if: *.",
 	NULL},
{"helio_positions", (getter)HeliostatField_get_helio_positions,(setter)HeliostatField_set_helio_positions,
	"Heliostat position table [], matrix.\n Required if: *.",
 	NULL},
{"helio_reflectance", (getter)HeliostatField_get_helio_reflectance,(setter)HeliostatField_set_helio_reflectance,
	"Heliostat reflectance [], number.\n Required if: *.",
 	NULL},
{"helio_width", (getter)HeliostatField_get_helio_width,(setter)HeliostatField_set_helio_width,
	"Heliostat width [m], number.\n Required if: *.",
 	NULL},
{"land_area_base", (getter)HeliostatField_get_land_area_base,(setter)HeliostatField_set_land_area_base,
	"Base land area occupied by heliostats [acre], number.\n Required if: *.",
 	NULL},
{"land_bound_list", (getter)HeliostatField_get_land_bound_list,(setter)HeliostatField_set_land_bound_list,
	"Land boundary table listing [], array.\n Required if: ?.",
 	NULL},
{"land_bound_table", (getter)HeliostatField_get_land_bound_table,(setter)HeliostatField_set_land_bound_table,
	"Land boundary table [m], matrix.\n Required if: ?.",
 	NULL},
{"land_max", (getter)HeliostatField_get_land_max,(setter)HeliostatField_set_land_max,
	"Land max boundary [-ORm], number.\n Required if: ?=7.5.",
 	NULL},
{"land_min", (getter)HeliostatField_get_land_min,(setter)HeliostatField_set_land_min,
	"Land min boundary [-ORm], number.\n Required if: ?=0.75.",
 	NULL},
{"n_facet_x", (getter)HeliostatField_get_n_facet_x,(setter)HeliostatField_set_n_facet_x,
	"Number of heliostat facets - X [], number.\n Required if: *.",
 	NULL},
{"n_facet_y", (getter)HeliostatField_get_n_facet_y,(setter)HeliostatField_set_n_facet_y,
	"Number of heliostat facets - Y [], number.\n Required if: *.",
 	NULL},
{"opt_algorithm", (getter)HeliostatField_get_opt_algorithm,(setter)HeliostatField_set_opt_algorithm,
	"Optimization algorithm [], number.\n Required if: ?=0.",
 	NULL},
{"opt_conv_tol", (getter)HeliostatField_get_opt_conv_tol,(setter)HeliostatField_set_opt_conv_tol,
	"Optimization convergence tolerance [], number.\n Required if: ?=0.001.",
 	NULL},
{"opt_flux_penalty", (getter)HeliostatField_get_opt_flux_penalty,(setter)HeliostatField_set_opt_flux_penalty,
	"Optimization flux overage penalty [], number.\n Required if: *.",
 	NULL},
{"opt_init_step", (getter)HeliostatField_get_opt_init_step,(setter)HeliostatField_set_opt_init_step,
	"Optimization initial step size [], number.\n Required if: ?=0.05.",
 	NULL},
{"opt_max_iter", (getter)HeliostatField_get_opt_max_iter,(setter)HeliostatField_set_opt_max_iter,
	"Max number iteration steps [], number.\n Required if: ?=200.",
 	NULL},
{"p_start", (getter)HeliostatField_get_p_start,(setter)HeliostatField_set_p_start,
	"Heliostat startup energy [kWe-hr], number.\n Required if: *.",
 	NULL},
{"p_track", (getter)HeliostatField_get_p_track,(setter)HeliostatField_set_p_track,
	"Heliostat tracking energy [kWe], number.\n Required if: *.",
 	NULL},
{"v_wind_max", (getter)HeliostatField_get_v_wind_max,(setter)HeliostatField_set_v_wind_max,
	"Heliostat max wind velocity [m/s], number.\n Required if: *.",
 	NULL},
{"washing_frequency", (getter)HeliostatField_get_washing_frequency,(setter)HeliostatField_set_washing_frequency,
	"Mirror washing frequency [none], number.\n Required if: *.",
 	NULL},
{"water_usage_per_wash", (getter)HeliostatField_get_water_usage_per_wash,(setter)HeliostatField_set_water_usage_per_wash,
	"Water usage per wash [L/m2_aper], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject HeliostatField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.HeliostatField",             /*tp_name*/
		sizeof(HeliostatFieldObject),          /*tp_basicsize*/
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
		HeliostatField_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		HeliostatField_getset,          /*tp_getset*/
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
	 * SystemDesign Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} SystemDesignObject;

static PyTypeObject SystemDesign_Type;

static PyObject *
SystemDesign_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = SystemDesign_Type.tp_alloc(&SystemDesign_Type,0);

	SystemDesignObject* SystemDesign_obj = (SystemDesignObject*)new_obj;

	SystemDesign_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SystemDesign methods */

static PyObject *
SystemDesign_assign(SystemDesignObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_export(SystemDesignObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemDesign_methods[] = {
		{"assign",            (PyCFunction)SystemDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SystemDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemDesign_get_P_ref(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_P_ref_fget, self->data_ptr);
}

static int
SystemDesign_set_P_ref(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_P_ref_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_htf_cold_des(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_T_htf_cold_des_fget, self->data_ptr);
}

static int
SystemDesign_set_T_htf_cold_des(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_T_htf_cold_des_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_htf_hot_des(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_T_htf_hot_des_fget, self->data_ptr);
}

static int
SystemDesign_set_T_htf_hot_des(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_T_htf_hot_des_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_design_eff(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_design_eff_fget, self->data_ptr);
}

static int
SystemDesign_set_design_eff(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_design_eff_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_dni_des(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_dni_des_fget, self->data_ptr);
}

static int
SystemDesign_set_dni_des(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_dni_des_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gross_net_conversion_factor(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_gross_net_conversion_factor_fget, self->data_ptr);
}

static int
SystemDesign_set_gross_net_conversion_factor(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_gross_net_conversion_factor_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_sf_excess(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_sf_excess_fget, self->data_ptr);
}

static int
SystemDesign_set_sf_excess(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_sf_excess_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_solarm(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_solarm_fget, self->data_ptr);
}

static int
SystemDesign_set_solarm(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_solarm_fset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tshours(SystemDesignObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemDesign_tshours_fget, self->data_ptr);
}

static int
SystemDesign_set_tshours(SystemDesignObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemDesign_tshours_fset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"P_ref", (getter)SystemDesign_get_P_ref,(setter)SystemDesign_set_P_ref,
	"Reference output electric power at design condition [MW], number.\n Required if: *.",
 	NULL},
{"T_htf_cold_des", (getter)SystemDesign_get_T_htf_cold_des,(setter)SystemDesign_set_T_htf_cold_des,
	"Cold HTF inlet temperature at design conditions [C], number.\n Required if: *.",
 	NULL},
{"T_htf_hot_des", (getter)SystemDesign_get_T_htf_hot_des,(setter)SystemDesign_set_T_htf_hot_des,
	"Hot HTF outlet temperature at design conditions [C], number.\n Required if: *.",
 	NULL},
{"design_eff", (getter)SystemDesign_get_design_eff,(setter)SystemDesign_set_design_eff,
	"Power cycle efficiency at design [none], number.\n Required if: *.",
 	NULL},
{"dni_des", (getter)SystemDesign_get_dni_des,(setter)SystemDesign_set_dni_des,
	"Design-point DNI [W/m2], number.\n Required if: *.",
 	NULL},
{"gross_net_conversion_factor", (getter)SystemDesign_get_gross_net_conversion_factor,(setter)SystemDesign_set_gross_net_conversion_factor,
	"Estimated gross to net conversion factor [], number.\n Required if: *.",
 	NULL},
{"sf_excess", (getter)SystemDesign_get_sf_excess,(setter)SystemDesign_set_sf_excess,
	"Heliostat field multiple [], number.\n Required if: ?=1.0.",
 	NULL},
{"solarm", (getter)SystemDesign_get_solarm,(setter)SystemDesign_set_solarm,
	"Solar multiple [-], number.\n Required if: *.",
 	NULL},
{"tshours", (getter)SystemDesign_get_tshours,(setter)SystemDesign_set_tshours,
	"Equivalent full-load thermal storage hours [hr], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.SystemDesign",             /*tp_name*/
		sizeof(SystemDesignObject),          /*tp_basicsize*/
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
		SystemDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemDesign_getset,          /*tp_getset*/
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
	 * TowerAndReceiver Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} TowerAndReceiverObject;

static PyTypeObject TowerAndReceiver_Type;

static PyObject *
TowerAndReceiver_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = TowerAndReceiver_Type.tp_alloc(&TowerAndReceiver_Type,0);

	TowerAndReceiverObject* TowerAndReceiver_obj = (TowerAndReceiverObject*)new_obj;

	TowerAndReceiver_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TowerAndReceiver methods */

static PyObject *
TowerAndReceiver_assign(TowerAndReceiverObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "TowerAndReceiver")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TowerAndReceiver_export(TowerAndReceiverObject *self, PyObject *args)
{
	PyTypeObject* tp = &TowerAndReceiver_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TowerAndReceiver_methods[] = {
		{"assign",            (PyCFunction)TowerAndReceiver_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)TowerAndReceiver_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TowerAndReceiver_get_D_rec(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_D_rec_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_D_rec(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_D_rec_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_Flow_type(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_Flow_type_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_Flow_type(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_Flow_type_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_N_panels(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_N_panels_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_N_panels(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_N_panels_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_crossover_shift(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_crossover_shift_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_crossover_shift(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_crossover_shift_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_csp_pt_rec_max_oper_frac(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_csp_pt_rec_max_oper_frac_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_csp_pt_rec_max_oper_frac(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_csp_pt_rec_max_oper_frac_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_d_tube_out(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_d_tube_out_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_d_tube_out(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_d_tube_out_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_delta_flux_hrs(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_delta_flux_hrs_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_delta_flux_hrs(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_delta_flux_hrs_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_epsilon(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_epsilon_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_epsilon(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_epsilon_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_eta_pump(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_eta_pump_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_eta_pump(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_eta_pump_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_f_rec_min(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_f_rec_min_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_f_rec_min(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_f_rec_min_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_field_fl_props(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_TowerAndReceiver_field_fl_props_mget, self->data_ptr);
}

static int
TowerAndReceiver_set_field_fl_props(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_field_fl_props_mset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_flux_max(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_flux_max_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_flux_max(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_flux_max_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_h_tower(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_h_tower_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_h_tower(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_h_tower_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_hl_ffact(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_hl_ffact_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_hl_ffact(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_hl_ffact_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_mat_tube(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_mat_tube_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_mat_tube(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_mat_tube_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_n_flux_days(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_n_flux_days_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_n_flux_days(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_n_flux_days_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_piping_length_const(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_piping_length_const_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_length_const(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_piping_length_const_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_piping_length_mult(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_piping_length_mult_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_length_mult(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_piping_length_mult_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_piping_loss(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_piping_loss_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_piping_loss(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_piping_loss_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_absorptance(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_rec_absorptance_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_absorptance(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_rec_absorptance_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_height(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_rec_height_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_height(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_rec_height_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_hl_perm2(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_rec_hl_perm2_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_hl_perm2(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_rec_hl_perm2_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_htf(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_rec_htf_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_htf(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_rec_htf_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_qf_delay(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_rec_qf_delay_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_qf_delay(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_rec_qf_delay_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_rec_su_delay(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_rec_su_delay_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_rec_su_delay(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_rec_su_delay_fset, self->data_ptr);
}

static PyObject *
TowerAndReceiver_get_th_tube(TowerAndReceiverObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_TowerAndReceiver_th_tube_fget, self->data_ptr);
}

static int
TowerAndReceiver_set_th_tube(TowerAndReceiverObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_TowerAndReceiver_th_tube_fset, self->data_ptr);
}

static PyGetSetDef TowerAndReceiver_getset[] = {
{"D_rec", (getter)TowerAndReceiver_get_D_rec,(setter)TowerAndReceiver_set_D_rec,
	"The overall outer diameter of the receiver [m], number.\n Required if: *.",
 	NULL},
{"Flow_type", (getter)TowerAndReceiver_get_Flow_type,(setter)TowerAndReceiver_set_Flow_type,
	"Receiver flow pattern: see figure on SAM Receiver page [], number.\n Required if: *.",
 	NULL},
{"N_panels", (getter)TowerAndReceiver_get_N_panels,(setter)TowerAndReceiver_set_N_panels,
	"Number of individual panels on the receiver [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"crossover_shift", (getter)TowerAndReceiver_get_crossover_shift,(setter)TowerAndReceiver_set_crossover_shift,
	"Number of panels shift in receiver crossover position [], number.\n Required if: ?=0.",
 	NULL},
{"csp_pt_rec_max_oper_frac", (getter)TowerAndReceiver_get_csp_pt_rec_max_oper_frac,(setter)TowerAndReceiver_set_csp_pt_rec_max_oper_frac,
	"Maximum receiver mass flow rate fraction [], number.\n Required if: *.",
 	NULL},
{"d_tube_out", (getter)TowerAndReceiver_get_d_tube_out,(setter)TowerAndReceiver_set_d_tube_out,
	"The outer diameter of an individual receiver tube [mm], number.\n Required if: *.",
 	NULL},
{"delta_flux_hrs", (getter)TowerAndReceiver_get_delta_flux_hrs,(setter)TowerAndReceiver_set_delta_flux_hrs,
	"Hourly frequency in flux map lookup [], number.\n Required if: ?=1.",
 	NULL},
{"epsilon", (getter)TowerAndReceiver_get_epsilon,(setter)TowerAndReceiver_set_epsilon,
	"The emissivity of the receiver surface coating [], number.\n Required if: *.",
 	NULL},
{"eta_pump", (getter)TowerAndReceiver_get_eta_pump,(setter)TowerAndReceiver_set_eta_pump,
	"Receiver HTF pump efficiency [], number.\n Required if: *.",
 	NULL},
{"f_rec_min", (getter)TowerAndReceiver_get_f_rec_min,(setter)TowerAndReceiver_set_f_rec_min,
	"Minimum receiver mass flow rate turn down fraction [], number.\n Required if: *.",
 	NULL},
{"field_fl_props", (getter)TowerAndReceiver_get_field_fl_props,(setter)TowerAndReceiver_set_field_fl_props,
	"User defined field fluid property data [-], matrix.\n Required if: *.",
 	NULL},
{"flux_max", (getter)TowerAndReceiver_get_flux_max,(setter)TowerAndReceiver_set_flux_max,
	"Maximum allowable flux [], number.\n Required if: ?=1000.",
 	NULL},
{"h_tower", (getter)TowerAndReceiver_get_h_tower,(setter)TowerAndReceiver_set_h_tower,
	"Tower height [m], number.\n Required if: *.",
 	NULL},
{"hl_ffact", (getter)TowerAndReceiver_get_hl_ffact,(setter)TowerAndReceiver_set_hl_ffact,
	"The heat loss factor (thermal loss fudge factor) [], number.\n Required if: *.",
 	NULL},
{"mat_tube", (getter)TowerAndReceiver_get_mat_tube,(setter)TowerAndReceiver_set_mat_tube,
	"Receiver tube material, 2=Stainless AISI316 [], number.\n Required if: *.",
 	NULL},
{"n_flux_days", (getter)TowerAndReceiver_get_n_flux_days,(setter)TowerAndReceiver_set_n_flux_days,
	"Number of days in flux map lookup [], number.\n Required if: ?=8.",
 	NULL},
{"piping_length_const", (getter)TowerAndReceiver_get_piping_length_const,(setter)TowerAndReceiver_set_piping_length_const,
	"Piping constant length [m], number.\n Required if: *.",
 	NULL},
{"piping_length_mult", (getter)TowerAndReceiver_get_piping_length_mult,(setter)TowerAndReceiver_set_piping_length_mult,
	"Piping length multiplier [], number.\n Required if: *.",
 	NULL},
{"piping_loss", (getter)TowerAndReceiver_get_piping_loss,(setter)TowerAndReceiver_set_piping_loss,
	"Thermal loss per meter of piping [Wt/m], number.\n Required if: *.",
 	NULL},
{"rec_absorptance", (getter)TowerAndReceiver_get_rec_absorptance,(setter)TowerAndReceiver_set_rec_absorptance,
	"Receiver absorptance [], number.\n Required if: *.",
 	NULL},
{"rec_height", (getter)TowerAndReceiver_get_rec_height,(setter)TowerAndReceiver_set_rec_height,
	"Receiver height [m], number.\n Required if: *.",
 	NULL},
{"rec_hl_perm2", (getter)TowerAndReceiver_get_rec_hl_perm2,(setter)TowerAndReceiver_set_rec_hl_perm2,
	"Receiver design heatloss [kW/m2], number.\n Required if: *.",
 	NULL},
{"rec_htf", (getter)TowerAndReceiver_get_rec_htf,(setter)TowerAndReceiver_set_rec_htf,
	"Receiver HTF, 17=Salt (60% NaNO3, 40% KNO3) 10=Salt (46.5% LiF 11.5% NaF 42% KF) 50=Lookup tables [], number.\n Required if: *.",
 	NULL},
{"rec_qf_delay", (getter)TowerAndReceiver_get_rec_qf_delay,(setter)TowerAndReceiver_set_rec_qf_delay,
	"Energy-based receiver startup delay (fraction of rated thermal power) [], number.\n Required if: *.",
 	NULL},
{"rec_su_delay", (getter)TowerAndReceiver_get_rec_su_delay,(setter)TowerAndReceiver_set_rec_su_delay,
	"Fixed startup delay time for the receiver [hr], number.\n Required if: *.",
 	NULL},
{"th_tube", (getter)TowerAndReceiver_get_th_tube,(setter)TowerAndReceiver_set_th_tube,
	"The wall thickness of a single receiver tube [mm], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TowerAndReceiver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.TowerAndReceiver",             /*tp_name*/
		sizeof(TowerAndReceiverObject),          /*tp_basicsize*/
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
		TowerAndReceiver_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TowerAndReceiver_getset,          /*tp_getset*/
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
	 * SystemCosts Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} SystemCostsObject;

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = SystemCosts_Type.tp_alloc(&SystemCosts_Type,0);

	SystemCostsObject* SystemCosts_obj = (SystemCostsObject*)new_obj;

	SystemCosts_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SystemCosts methods */

static PyObject *
SystemCosts_assign(SystemCostsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "SystemCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCosts_export(SystemCostsObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemCosts_methods[] = {
		{"assign",            (PyCFunction)SystemCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SystemCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCosts_get_bop_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_bop_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_bop_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_bop_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_contingency_rate(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_contingency_rate_fget, self->data_ptr);
}

static int
SystemCosts_set_contingency_rate(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_contingency_rate_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_cost_sf_fixed(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_cost_sf_fixed_fget, self->data_ptr);
}

static int
SystemCosts_set_cost_sf_fixed(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_cost_sf_fixed_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_fixed(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_fixed_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_fixed(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_fixed_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_per_acre(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_per_acre_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_per_acre(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_per_acre_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_per_watt(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_per_watt_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_per_watt(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_per_watt_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_percent(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_percent_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_percent(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_epc_percent_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_fixed(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_plm_fixed_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_fixed(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_plm_fixed_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_per_watt(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_plm_per_watt_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_per_watt(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_plm_per_watt_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_percent(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_plm_percent_fget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_percent(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_csp_pt_cost_plm_percent_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_fossil_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_fossil_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_fossil_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_fossil_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_heliostat_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_heliostat_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_heliostat_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_heliostat_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_land_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_land_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_land_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_plant_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_plant_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_plant_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_plant_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_rec_cost_exp(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_rec_cost_exp_fget, self->data_ptr);
}

static int
SystemCosts_set_rec_cost_exp(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_rec_cost_exp_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_rec_ref_area(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_rec_ref_area_fget, self->data_ptr);
}

static int
SystemCosts_set_rec_ref_area(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_rec_ref_area_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_rec_ref_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_rec_ref_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_rec_ref_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_rec_ref_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_sales_tax_frac(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_sales_tax_frac_fget, self->data_ptr);
}

static int
SystemCosts_set_sales_tax_frac(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_sales_tax_frac_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_site_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_site_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_site_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_site_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tes_spec_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_tes_spec_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_tes_spec_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_tes_spec_cost_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tower_exp(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_tower_exp_fget, self->data_ptr);
}

static int
SystemCosts_set_tower_exp(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_tower_exp_fset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tower_fixed_cost(SystemCostsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemCosts_tower_fixed_cost_fget, self->data_ptr);
}

static int
SystemCosts_set_tower_fixed_cost(SystemCostsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemCosts_tower_fixed_cost_fset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"bop_spec_cost", (getter)SystemCosts_get_bop_spec_cost,(setter)SystemCosts_set_bop_spec_cost,
	"BOS specific cost [$/kWe], number.\n Required if: *.",
 	NULL},
{"contingency_rate", (getter)SystemCosts_get_contingency_rate,(setter)SystemCosts_set_contingency_rate,
	"Contingency for cost overrun [%], number.\n Required if: *.",
 	NULL},
{"cost_sf_fixed", (getter)SystemCosts_get_cost_sf_fixed,(setter)SystemCosts_set_cost_sf_fixed,
	"Solar field fixed cost [$], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_epc_fixed", (getter)SystemCosts_get_csp_pt_cost_epc_fixed,(setter)SystemCosts_set_csp_pt_cost_epc_fixed,
	"EPC fixed [$], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_epc_per_acre", (getter)SystemCosts_get_csp_pt_cost_epc_per_acre,(setter)SystemCosts_set_csp_pt_cost_epc_per_acre,
	"EPC cost per acre [$/acre], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_epc_per_watt", (getter)SystemCosts_get_csp_pt_cost_epc_per_watt,(setter)SystemCosts_set_csp_pt_cost_epc_per_watt,
	"EPC cost per watt [$/W], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_epc_percent", (getter)SystemCosts_get_csp_pt_cost_epc_percent,(setter)SystemCosts_set_csp_pt_cost_epc_percent,
	"EPC cost percent of direct [%], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_plm_fixed", (getter)SystemCosts_get_csp_pt_cost_plm_fixed,(setter)SystemCosts_set_csp_pt_cost_plm_fixed,
	"PLM fixed [$], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_plm_per_watt", (getter)SystemCosts_get_csp_pt_cost_plm_per_watt,(setter)SystemCosts_set_csp_pt_cost_plm_per_watt,
	"PLM cost per watt [$/W], number.\n Required if: *.",
 	NULL},
{"csp_pt_cost_plm_percent", (getter)SystemCosts_get_csp_pt_cost_plm_percent,(setter)SystemCosts_set_csp_pt_cost_plm_percent,
	"PLM cost percent of direct [%], number.\n Required if: *.",
 	NULL},
{"fossil_spec_cost", (getter)SystemCosts_get_fossil_spec_cost,(setter)SystemCosts_set_fossil_spec_cost,
	"Fossil system specific cost [$/kWe], number.\n Required if: *.",
 	NULL},
{"heliostat_spec_cost", (getter)SystemCosts_get_heliostat_spec_cost,(setter)SystemCosts_set_heliostat_spec_cost,
	"Heliostat field cost [$/m2], number.\n Required if: *.",
 	NULL},
{"land_spec_cost", (getter)SystemCosts_get_land_spec_cost,(setter)SystemCosts_set_land_spec_cost,
	"Total land area cost [$/acre], number.\n Required if: *.",
 	NULL},
{"plant_spec_cost", (getter)SystemCosts_get_plant_spec_cost,(setter)SystemCosts_set_plant_spec_cost,
	"Power cycle specific cost [$/kWe], number.\n Required if: *.",
 	NULL},
{"rec_cost_exp", (getter)SystemCosts_get_rec_cost_exp,(setter)SystemCosts_set_rec_cost_exp,
	"Receiver cost scaling exponent [], number.\n Required if: *.",
 	NULL},
{"rec_ref_area", (getter)SystemCosts_get_rec_ref_area,(setter)SystemCosts_set_rec_ref_area,
	"Receiver reference area for cost scale [], number.\n Required if: *.",
 	NULL},
{"rec_ref_cost", (getter)SystemCosts_get_rec_ref_cost,(setter)SystemCosts_set_rec_ref_cost,
	"Receiver reference cost [$], number.\n Required if: *.",
 	NULL},
{"sales_tax_frac", (getter)SystemCosts_get_sales_tax_frac,(setter)SystemCosts_set_sales_tax_frac,
	"Percent of cost to which sales tax applies [%], number.\n Required if: *.",
 	NULL},
{"site_spec_cost", (getter)SystemCosts_get_site_spec_cost,(setter)SystemCosts_set_site_spec_cost,
	"Site improvement cost [$/m2], number.\n Required if: *.",
 	NULL},
{"tes_spec_cost", (getter)SystemCosts_get_tes_spec_cost,(setter)SystemCosts_set_tes_spec_cost,
	"Thermal energy storage cost [$/kWht], number.\n Required if: *.",
 	NULL},
{"tower_exp", (getter)SystemCosts_get_tower_exp,(setter)SystemCosts_set_tower_exp,
	"Tower cost scaling exponent [], number.\n Required if: *.",
 	NULL},
{"tower_fixed_cost", (getter)SystemCosts_get_tower_fixed_cost,(setter)SystemCosts_set_tower_fixed_cost,
	"Tower fixed cost [$], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.SystemCosts",             /*tp_name*/
		sizeof(SystemCostsObject),          /*tp_basicsize*/
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
		SystemCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemCosts_getset,          /*tp_getset*/
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
	 * FinancialParameters Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} FinancialParametersObject;

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	FinancialParametersObject* FinancialParameters_obj = (FinancialParametersObject*)new_obj;

	FinancialParameters_obj->data_ptr = data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(FinancialParametersObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(FinancialParametersObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_const_per_interest_rate1(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate1_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate1(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate1_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate2(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate2_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate2(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate2_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate3(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate3_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate3(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate3_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate4(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate4_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate4(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate4_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate5(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate5_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate5(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_interest_rate5_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months1(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_months1_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months1(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_months1_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months2(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_months2_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months2(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_months2_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months3(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_months3_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months3(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_months3_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months4(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_months4_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months4(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_months4_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months5(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_months5_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months5(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_months5_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent1(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_percent1_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent1(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_percent1_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent2(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_percent2_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent2(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_percent2_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent3(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_percent3_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent3(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_percent3_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent4(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_percent4_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent4(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_percent4_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent5(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_percent5_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent5(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_percent5_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate1(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate1_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate1(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate1_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate2(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate2_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate2(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate2_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate3(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate3_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate3(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate3_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate4(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate4_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate4(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate4_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate5(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate5_fget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate5(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_const_per_upfront_rate5_fset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_sales_tax_rate(FinancialParametersObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_FinancialParameters_sales_tax_rate_fget, self->data_ptr);
}

static int
FinancialParameters_set_sales_tax_rate(FinancialParametersObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_FinancialParameters_sales_tax_rate_fset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"const_per_interest_rate1", (getter)FinancialParameters_get_const_per_interest_rate1,(setter)FinancialParameters_set_const_per_interest_rate1,
	"Interest rate, loan 1 [%], number.\n Required if: *.",
 	NULL},
{"const_per_interest_rate2", (getter)FinancialParameters_get_const_per_interest_rate2,(setter)FinancialParameters_set_const_per_interest_rate2,
	"Interest rate, loan 2 [%], number.\n Required if: *.",
 	NULL},
{"const_per_interest_rate3", (getter)FinancialParameters_get_const_per_interest_rate3,(setter)FinancialParameters_set_const_per_interest_rate3,
	"Interest rate, loan 3 [%], number.\n Required if: *.",
 	NULL},
{"const_per_interest_rate4", (getter)FinancialParameters_get_const_per_interest_rate4,(setter)FinancialParameters_set_const_per_interest_rate4,
	"Interest rate, loan 4 [%], number.\n Required if: *.",
 	NULL},
{"const_per_interest_rate5", (getter)FinancialParameters_get_const_per_interest_rate5,(setter)FinancialParameters_set_const_per_interest_rate5,
	"Interest rate, loan 5 [%], number.\n Required if: *.",
 	NULL},
{"const_per_months1", (getter)FinancialParameters_get_const_per_months1,(setter)FinancialParameters_set_const_per_months1,
	"Months prior to operation, loan 1 [], number.\n Required if: *.",
 	NULL},
{"const_per_months2", (getter)FinancialParameters_get_const_per_months2,(setter)FinancialParameters_set_const_per_months2,
	"Months prior to operation, loan 2 [], number.\n Required if: *.",
 	NULL},
{"const_per_months3", (getter)FinancialParameters_get_const_per_months3,(setter)FinancialParameters_set_const_per_months3,
	"Months prior to operation, loan 3 [], number.\n Required if: *.",
 	NULL},
{"const_per_months4", (getter)FinancialParameters_get_const_per_months4,(setter)FinancialParameters_set_const_per_months4,
	"Months prior to operation, loan 4 [], number.\n Required if: *.",
 	NULL},
{"const_per_months5", (getter)FinancialParameters_get_const_per_months5,(setter)FinancialParameters_set_const_per_months5,
	"Months prior to operation, loan 5 [], number.\n Required if: *.",
 	NULL},
{"const_per_percent1", (getter)FinancialParameters_get_const_per_percent1,(setter)FinancialParameters_set_const_per_percent1,
	"Percent of total installed cost, loan 1 [%], number.\n Required if: *.",
 	NULL},
{"const_per_percent2", (getter)FinancialParameters_get_const_per_percent2,(setter)FinancialParameters_set_const_per_percent2,
	"Percent of total installed cost, loan 2 [%], number.\n Required if: *.",
 	NULL},
{"const_per_percent3", (getter)FinancialParameters_get_const_per_percent3,(setter)FinancialParameters_set_const_per_percent3,
	"Percent of total installed cost, loan 3 [%], number.\n Required if: *.",
 	NULL},
{"const_per_percent4", (getter)FinancialParameters_get_const_per_percent4,(setter)FinancialParameters_set_const_per_percent4,
	"Percent of total installed cost, loan 4 [%], number.\n Required if: *.",
 	NULL},
{"const_per_percent5", (getter)FinancialParameters_get_const_per_percent5,(setter)FinancialParameters_set_const_per_percent5,
	"Percent of total installed cost, loan 5 [%], number.\n Required if: *.",
 	NULL},
{"const_per_upfront_rate1", (getter)FinancialParameters_get_const_per_upfront_rate1,(setter)FinancialParameters_set_const_per_upfront_rate1,
	"Upfront fee on principal, loan 1 [%], number.\n Required if: *.",
 	NULL},
{"const_per_upfront_rate2", (getter)FinancialParameters_get_const_per_upfront_rate2,(setter)FinancialParameters_set_const_per_upfront_rate2,
	"Upfront fee on principal, loan 2 [%], number.\n Required if: *.",
 	NULL},
{"const_per_upfront_rate3", (getter)FinancialParameters_get_const_per_upfront_rate3,(setter)FinancialParameters_set_const_per_upfront_rate3,
	"Upfront fee on principal, loan 3 [%], number.\n Required if: *.",
 	NULL},
{"const_per_upfront_rate4", (getter)FinancialParameters_get_const_per_upfront_rate4,(setter)FinancialParameters_set_const_per_upfront_rate4,
	"Upfront fee on principal, loan 4 [%], number.\n Required if: *.",
 	NULL},
{"const_per_upfront_rate5", (getter)FinancialParameters_get_const_per_upfront_rate5,(setter)FinancialParameters_set_const_per_upfront_rate5,
	"Upfront fee on principal, loan 5 [%], number.\n Required if: *.",
 	NULL},
{"sales_tax_rate", (getter)FinancialParameters_get_sales_tax_rate,(setter)FinancialParameters_set_sales_tax_rate,
	"Sales tax rate [%], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.FinancialParameters",             /*tp_name*/
		sizeof(FinancialParametersObject),          /*tp_basicsize*/
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
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
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
	 * ThermalStorage Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} ThermalStorageObject;

static PyTypeObject ThermalStorage_Type;

static PyObject *
ThermalStorage_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = ThermalStorage_Type.tp_alloc(&ThermalStorage_Type,0);

	ThermalStorageObject* ThermalStorage_obj = (ThermalStorageObject*)new_obj;

	ThermalStorage_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ThermalStorage methods */

static PyObject *
ThermalStorage_assign(ThermalStorageObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "ThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalStorage_export(ThermalStorageObject *self, PyObject *args)
{
	PyTypeObject* tp = &ThermalStorage_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ThermalStorage_methods[] = {
		{"assign",            (PyCFunction)ThermalStorage_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ThermalStorage_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThermalStorage_get_cold_tank_Thtr(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_cold_tank_Thtr_fget, self->data_ptr);
}

static int
ThermalStorage_set_cold_tank_Thtr(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_cold_tank_Thtr_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_cold_tank_max_heat(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_cold_tank_max_heat_fget, self->data_ptr);
}

static int
ThermalStorage_set_cold_tank_max_heat(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_cold_tank_max_heat_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_csp_pt_tes_init_hot_htf_percent(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_csp_pt_tes_init_hot_htf_percent_fget, self->data_ptr);
}

static int
ThermalStorage_set_csp_pt_tes_init_hot_htf_percent(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_csp_pt_tes_init_hot_htf_percent_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_h_tank(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_h_tank_fget, self->data_ptr);
}

static int
ThermalStorage_set_h_tank(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_h_tank_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_h_tank_min(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_h_tank_min_fget, self->data_ptr);
}

static int
ThermalStorage_set_h_tank_min(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_h_tank_min_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_hot_tank_Thtr(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_hot_tank_Thtr_fget, self->data_ptr);
}

static int
ThermalStorage_set_hot_tank_Thtr(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_hot_tank_Thtr_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_hot_tank_max_heat(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_hot_tank_max_heat_fget, self->data_ptr);
}

static int
ThermalStorage_set_hot_tank_max_heat(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_hot_tank_max_heat_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_tank_pairs(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_tank_pairs_fget, self->data_ptr);
}

static int
ThermalStorage_set_tank_pairs(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_tank_pairs_fset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_u_tank(ThermalStorageObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_ThermalStorage_u_tank_fget, self->data_ptr);
}

static int
ThermalStorage_set_u_tank(ThermalStorageObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_ThermalStorage_u_tank_fset, self->data_ptr);
}

static PyGetSetDef ThermalStorage_getset[] = {
{"cold_tank_Thtr", (getter)ThermalStorage_get_cold_tank_Thtr,(setter)ThermalStorage_set_cold_tank_Thtr,
	"Minimum allowable cold tank HTF temperature [C], number.\n Required if: *.",
 	NULL},
{"cold_tank_max_heat", (getter)ThermalStorage_get_cold_tank_max_heat,(setter)ThermalStorage_set_cold_tank_max_heat,
	"Rated heater capacity for cold tank heating [MW], number.\n Required if: *.",
 	NULL},
{"csp_pt_tes_init_hot_htf_percent", (getter)ThermalStorage_get_csp_pt_tes_init_hot_htf_percent,(setter)ThermalStorage_set_csp_pt_tes_init_hot_htf_percent,
	"Initial fraction of available volume that is hot [%], number.\n Required if: *.",
 	NULL},
{"h_tank", (getter)ThermalStorage_get_h_tank,(setter)ThermalStorage_set_h_tank,
	"Total height of tank (height of HTF when tank is full) [m], number.\n Required if: *.",
 	NULL},
{"h_tank_min", (getter)ThermalStorage_get_h_tank_min,(setter)ThermalStorage_set_h_tank_min,
	"Minimum allowable HTF height in storage tank [m], number.\n Required if: *.",
 	NULL},
{"hot_tank_Thtr", (getter)ThermalStorage_get_hot_tank_Thtr,(setter)ThermalStorage_set_hot_tank_Thtr,
	"Minimum allowable hot tank HTF temperature [C], number.\n Required if: *.",
 	NULL},
{"hot_tank_max_heat", (getter)ThermalStorage_get_hot_tank_max_heat,(setter)ThermalStorage_set_hot_tank_max_heat,
	"Rated heater capacity for hot tank heating [MW], number.\n Required if: *.",
 	NULL},
{"tank_pairs", (getter)ThermalStorage_get_tank_pairs,(setter)ThermalStorage_set_tank_pairs,
	"Number of equivalent tank pairs [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"u_tank", (getter)ThermalStorage_get_u_tank,(setter)ThermalStorage_set_u_tank,
	"Loss coefficient from the tank [W/m2-K], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ThermalStorage_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.ThermalStorage",             /*tp_name*/
		sizeof(ThermalStorageObject),          /*tp_basicsize*/
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
		ThermalStorage_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ThermalStorage_getset,          /*tp_getset*/
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
	 * PowerCycle Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} PowerCycleObject;

static PyTypeObject PowerCycle_Type;

static PyObject *
PowerCycle_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = PowerCycle_Type.tp_alloc(&PowerCycle_Type,0);

	PowerCycleObject* PowerCycle_obj = (PowerCycleObject*)new_obj;

	PowerCycle_obj->data_ptr = data_ptr;

	return new_obj;
}

/* PowerCycle methods */

static PyObject *
PowerCycle_assign(PowerCycleObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "PowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PowerCycle_export(PowerCycleObject *self, PyObject *args)
{
	PyTypeObject* tp = &PowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PowerCycle_methods[] = {
		{"assign",            (PyCFunction)PowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)PowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PowerCycle_get_cycle_cutoff_frac(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_cycle_cutoff_frac_fget, self->data_ptr);
}

static int
PowerCycle_set_cycle_cutoff_frac(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_cycle_cutoff_frac_fset, self->data_ptr);
}

static PyObject *
PowerCycle_get_cycle_max_frac(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_cycle_max_frac_fget, self->data_ptr);
}

static int
PowerCycle_set_cycle_max_frac(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_cycle_max_frac_fset, self->data_ptr);
}

static PyObject *
PowerCycle_get_pb_pump_coef(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_pb_pump_coef_fget, self->data_ptr);
}

static int
PowerCycle_set_pb_pump_coef(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_pb_pump_coef_fset, self->data_ptr);
}

static PyObject *
PowerCycle_get_pc_config(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_pc_config_fget, self->data_ptr);
}

static int
PowerCycle_set_pc_config(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_pc_config_fset, self->data_ptr);
}

static PyObject *
PowerCycle_get_q_sby_frac(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_q_sby_frac_fget, self->data_ptr);
}

static int
PowerCycle_set_q_sby_frac(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_q_sby_frac_fset, self->data_ptr);
}

static PyObject *
PowerCycle_get_startup_frac(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_startup_frac_fget, self->data_ptr);
}

static int
PowerCycle_set_startup_frac(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_startup_frac_fset, self->data_ptr);
}

static PyObject *
PowerCycle_get_startup_time(PowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_PowerCycle_startup_time_fget, self->data_ptr);
}

static int
PowerCycle_set_startup_time(PowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_PowerCycle_startup_time_fset, self->data_ptr);
}

static PyGetSetDef PowerCycle_getset[] = {
{"cycle_cutoff_frac", (getter)PowerCycle_get_cycle_cutoff_frac,(setter)PowerCycle_set_cycle_cutoff_frac,
	"Minimum turbine operation fraction before shutdown [], number.\n Required if: *.",
 	NULL},
{"cycle_max_frac", (getter)PowerCycle_get_cycle_max_frac,(setter)PowerCycle_set_cycle_max_frac,
	"Maximum turbine over design operation fraction [], number.\n Required if: *.",
 	NULL},
{"pb_pump_coef", (getter)PowerCycle_get_pb_pump_coef,(setter)PowerCycle_set_pb_pump_coef,
	"Pumping power to move 1kg of HTF through PB loop [kW/kg], number.\n Required if: *.",
 	NULL},
{"pc_config", (getter)PowerCycle_get_pc_config,(setter)PowerCycle_set_pc_config,
	"PC configuration 0=Steam Rankine (224), 1=user defined, 2=sCO2 Recompression (424) [], number.\n Constraints: INTEGER; Required if: ?=0.",
 	NULL},
{"q_sby_frac", (getter)PowerCycle_get_q_sby_frac,(setter)PowerCycle_set_q_sby_frac,
	"Fraction of thermal power required for standby [], number.\n Required if: *.",
 	NULL},
{"startup_frac", (getter)PowerCycle_get_startup_frac,(setter)PowerCycle_set_startup_frac,
	"Fraction of design thermal power needed for startup [none], number.\n Required if: *.",
 	NULL},
{"startup_time", (getter)PowerCycle_get_startup_time,(setter)PowerCycle_set_startup_time,
	"Time needed for power block startup [hr], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.PowerCycle",             /*tp_name*/
		sizeof(PowerCycleObject),          /*tp_basicsize*/
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
		PowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PowerCycle_getset,          /*tp_getset*/
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
	 * RankineCycle Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} RankineCycleObject;

static PyTypeObject RankineCycle_Type;

static PyObject *
RankineCycle_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = RankineCycle_Type.tp_alloc(&RankineCycle_Type,0);

	RankineCycleObject* RankineCycle_obj = (RankineCycleObject*)new_obj;

	RankineCycle_obj->data_ptr = data_ptr;

	return new_obj;
}

/* RankineCycle methods */

static PyObject *
RankineCycle_assign(RankineCycleObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "RankineCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
RankineCycle_export(RankineCycleObject *self, PyObject *args)
{
	PyTypeObject* tp = &RankineCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef RankineCycle_methods[] = {
		{"assign",            (PyCFunction)RankineCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)RankineCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
RankineCycle_get_CT(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_CT_fget, self->data_ptr);
}

static int
RankineCycle_set_CT(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_CT_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_P_boil(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_P_boil_fget, self->data_ptr);
}

static int
RankineCycle_set_P_boil(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_P_boil_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_P_cond_min(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_P_cond_min_fget, self->data_ptr);
}

static int
RankineCycle_set_P_cond_min(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_P_cond_min_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_P_cond_ratio(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_P_cond_ratio_fget, self->data_ptr);
}

static int
RankineCycle_set_P_cond_ratio(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_P_cond_ratio_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_T_ITD_des(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_T_ITD_des_fget, self->data_ptr);
}

static int
RankineCycle_set_T_ITD_des(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_T_ITD_des_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_T_amb_des(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_T_amb_des_fget, self->data_ptr);
}

static int
RankineCycle_set_T_amb_des(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_T_amb_des_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_T_approach(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_T_approach_fget, self->data_ptr);
}

static int
RankineCycle_set_T_approach(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_T_approach_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_dT_cw_ref(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_dT_cw_ref_fget, self->data_ptr);
}

static int
RankineCycle_set_dT_cw_ref(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_dT_cw_ref_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_n_pl_inc(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_n_pl_inc_fget, self->data_ptr);
}

static int
RankineCycle_set_n_pl_inc(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_n_pl_inc_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_pb_bd_frac(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_pb_bd_frac_fget, self->data_ptr);
}

static int
RankineCycle_set_pb_bd_frac(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_pb_bd_frac_fset, self->data_ptr);
}

static PyObject *
RankineCycle_get_tech_type(RankineCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_RankineCycle_tech_type_fget, self->data_ptr);
}

static int
RankineCycle_set_tech_type(RankineCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_RankineCycle_tech_type_fset, self->data_ptr);
}

static PyGetSetDef RankineCycle_getset[] = {
{"CT", (getter)RankineCycle_get_CT,(setter)RankineCycle_set_CT,
	"Condensor type: 1=evaporative, 2=air, 3=hybrid [], number.\n Required if: pc_config=0.",
 	NULL},
{"P_boil", (getter)RankineCycle_get_P_boil,(setter)RankineCycle_set_P_boil,
	"Boiler operating pressure [bar], number.\n Required if: pc_config=0.",
 	NULL},
{"P_cond_min", (getter)RankineCycle_get_P_cond_min,(setter)RankineCycle_set_P_cond_min,
	"Minimum condenser pressure [inHg], number.\n Required if: pc_config=0.",
 	NULL},
{"P_cond_ratio", (getter)RankineCycle_get_P_cond_ratio,(setter)RankineCycle_set_P_cond_ratio,
	"Condenser pressure ratio [], number.\n Required if: pc_config=0.",
 	NULL},
{"T_ITD_des", (getter)RankineCycle_get_T_ITD_des,(setter)RankineCycle_set_T_ITD_des,
	"ITD at design for dry system [C], number.\n Required if: pc_config=0.",
 	NULL},
{"T_amb_des", (getter)RankineCycle_get_T_amb_des,(setter)RankineCycle_set_T_amb_des,
	"Reference ambient temperature at design point [C], number.\n Required if: pc_config=0.",
 	NULL},
{"T_approach", (getter)RankineCycle_get_T_approach,(setter)RankineCycle_set_T_approach,
	"Cooling tower approach temperature [C], number.\n Required if: pc_config=0.",
 	NULL},
{"dT_cw_ref", (getter)RankineCycle_get_dT_cw_ref,(setter)RankineCycle_set_dT_cw_ref,
	"Reference condenser cooling water inlet/outlet temperature difference [C], number.\n Required if: pc_config=0.",
 	NULL},
{"n_pl_inc", (getter)RankineCycle_get_n_pl_inc,(setter)RankineCycle_set_n_pl_inc,
	"Number of part-load increments for the heat rejection system [none], number.\n Constraints: INTEGER; Required if: pc_config=0.",
 	NULL},
{"pb_bd_frac", (getter)RankineCycle_get_pb_bd_frac,(setter)RankineCycle_set_pb_bd_frac,
	"Power block blowdown steam fraction [], number.\n Required if: pc_config=0.",
 	NULL},
{"tech_type", (getter)RankineCycle_get_tech_type,(setter)RankineCycle_set_tech_type,
	"Turbine inlet pressure control 1=Fixed, 3=Sliding [], number.\n Required if: pc_config=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject RankineCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.RankineCycle",             /*tp_name*/
		sizeof(RankineCycleObject),          /*tp_basicsize*/
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
		RankineCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		RankineCycle_getset,          /*tp_getset*/
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
	 * SystemControl Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} SystemControlObject;

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = SystemControl_Type.tp_alloc(&SystemControl_Type,0);

	SystemControlObject* SystemControl_obj = (SystemControlObject*)new_obj;

	SystemControl_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SystemControl methods */

static PyObject *
SystemControl_assign(SystemControlObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_export(SystemControlObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemControl_methods[] = {
		{"assign",            (PyCFunction)SystemControl_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SystemControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemControl_get_F_wc(SystemControlObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_SystemControl_F_wc_aget, self->data_ptr);
}

static int
SystemControl_set_F_wc(SystemControlObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsmoltenSalt_SystemControl_F_wc_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_ampl_data_dir(SystemControlObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsmoltenSalt_SystemControl_file_sget, self->data_ptr);
}

static int
SystemControl_set_ampl_data_dir(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsmoltenSalt_SystemControl_file_sset, self->data_ptr);
}

static PyObject *
SystemControl_get_ampl_exec_call(SystemControlObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsmoltenSalt_SystemControl_file_sget, self->data_ptr);
}

static int
SystemControl_set_ampl_exec_call(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsmoltenSalt_SystemControl_file_sset, self->data_ptr);
}

static PyObject *
SystemControl_get_aux_par(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_aux_par_fget, self->data_ptr);
}

static int
SystemControl_set_aux_par(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_aux_par_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_aux_par_0(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_aux_par_0_fget, self->data_ptr);
}

static int
SystemControl_set_aux_par_0(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_aux_par_0_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_aux_par_1(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_aux_par_1_fget, self->data_ptr);
}

static int
SystemControl_set_aux_par_1(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_aux_par_1_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_aux_par_2(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_aux_par_2_fget, self->data_ptr);
}

static int
SystemControl_set_aux_par_2(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_aux_par_2_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_aux_par_f(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_aux_par_f_fget, self->data_ptr);
}

static int
SystemControl_set_aux_par_f(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_aux_par_f_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_bop_par_fget, self->data_ptr);
}

static int
SystemControl_set_bop_par(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_bop_par_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_0(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_bop_par_0_fget, self->data_ptr);
}

static int
SystemControl_set_bop_par_0(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_bop_par_0_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_1(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_bop_par_1_fget, self->data_ptr);
}

static int
SystemControl_set_bop_par_1(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_bop_par_1_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_2(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_bop_par_2_fget, self->data_ptr);
}

static int
SystemControl_set_bop_par_2(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_bop_par_2_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_f(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_bop_par_f_fget, self->data_ptr);
}

static int
SystemControl_set_bop_par_f(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_bop_par_f_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_csu_cost(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_csu_cost_fget, self->data_ptr);
}

static int
SystemControl_set_disp_csu_cost(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_csu_cost_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_frequency(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_frequency_fget, self->data_ptr);
}

static int
SystemControl_set_disp_frequency(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_frequency_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_horizon(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_horizon_fget, self->data_ptr);
}

static int
SystemControl_set_disp_horizon(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_horizon_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_max_iter(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_max_iter_fget, self->data_ptr);
}

static int
SystemControl_set_disp_max_iter(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_max_iter_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_mip_gap(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_mip_gap_fget, self->data_ptr);
}

static int
SystemControl_set_disp_mip_gap(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_mip_gap_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_pen_delta_w(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_pen_delta_w_fget, self->data_ptr);
}

static int
SystemControl_set_disp_pen_delta_w(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_pen_delta_w_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_reporting(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_reporting_fget, self->data_ptr);
}

static int
SystemControl_set_disp_reporting(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_reporting_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_rsu_cost(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_rsu_cost_fget, self->data_ptr);
}

static int
SystemControl_set_disp_rsu_cost(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_rsu_cost_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_spec_bb(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_spec_bb_fget, self->data_ptr);
}

static int
SystemControl_set_disp_spec_bb(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_spec_bb_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_spec_presolve(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_spec_presolve_fget, self->data_ptr);
}

static int
SystemControl_set_disp_spec_presolve(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_spec_presolve_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_spec_scaling(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_spec_scaling_fget, self->data_ptr);
}

static int
SystemControl_set_disp_spec_scaling(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_spec_scaling_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_steps_per_hour(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_steps_per_hour_fget, self->data_ptr);
}

static int
SystemControl_set_disp_steps_per_hour(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_steps_per_hour_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_time_weighting(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_time_weighting_fget, self->data_ptr);
}

static int
SystemControl_set_disp_time_weighting(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_time_weighting_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_disp_timeout(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_disp_timeout_fget, self->data_ptr);
}

static int
SystemControl_set_disp_timeout(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_disp_timeout_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_dispatch_series(SystemControlObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_SystemControl_dispatch_series_aget, self->data_ptr);
}

static int
SystemControl_set_dispatch_series(SystemControlObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsmoltenSalt_SystemControl_dispatch_series_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_f_turb_tou_periods(SystemControlObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_SystemControl_f_turb_tou_periods_aget, self->data_ptr);
}

static int
SystemControl_set_f_turb_tou_periods(SystemControlObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsmoltenSalt_SystemControl_f_turb_tou_periods_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_ampl_engine(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_is_ampl_engine_fget, self->data_ptr);
}

static int
SystemControl_set_is_ampl_engine(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_is_ampl_engine_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_dispatch(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_is_dispatch_fget, self->data_ptr);
}

static int
SystemControl_set_is_dispatch(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_is_dispatch_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_dispatch_series(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_is_dispatch_series_fget, self->data_ptr);
}

static int
SystemControl_set_is_dispatch_series(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_is_dispatch_series_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_wlim_series(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_is_wlim_series_fget, self->data_ptr);
}

static int
SystemControl_set_is_wlim_series(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_is_wlim_series_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_write_ampl_dat(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_is_write_ampl_dat_fget, self->data_ptr);
}

static int
SystemControl_set_is_write_ampl_dat(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_is_write_ampl_dat_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_pb_fixed_par(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_pb_fixed_par_fget, self->data_ptr);
}

static int
SystemControl_set_pb_fixed_par(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_pb_fixed_par_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_q_rec_heattrace(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_q_rec_heattrace_fget, self->data_ptr);
}

static int
SystemControl_set_q_rec_heattrace(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_q_rec_heattrace_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_q_rec_standby(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_q_rec_standby_fget, self->data_ptr);
}

static int
SystemControl_set_q_rec_standby(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_q_rec_standby_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_start(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_time_start_fget, self->data_ptr);
}

static int
SystemControl_set_time_start(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_time_start_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_steps_per_hour(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_time_steps_per_hour_fget, self->data_ptr);
}

static int
SystemControl_set_time_steps_per_hour(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_time_steps_per_hour_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_stop(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_time_stop_fget, self->data_ptr);
}

static int
SystemControl_set_time_stop(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_time_stop_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_vacuum_arrays(SystemControlObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SystemControl_vacuum_arrays_fget, self->data_ptr);
}

static int
SystemControl_set_vacuum_arrays(SystemControlObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SystemControl_vacuum_arrays_fset, self->data_ptr);
}

static PyObject *
SystemControl_get_weekday_schedule(SystemControlObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_SystemControl_weekday_schedule_mget, self->data_ptr);
}

static int
SystemControl_set_weekday_schedule(SystemControlObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_SystemControl_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
SystemControl_get_weekend_schedule(SystemControlObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_SystemControl_weekend_schedule_mget, self->data_ptr);
}

static int
SystemControl_set_weekend_schedule(SystemControlObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_SystemControl_weekend_schedule_mset, self->data_ptr);
}

static PyObject *
SystemControl_get_wlim_series(SystemControlObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_SystemControl_wlim_series_aget, self->data_ptr);
}

static int
SystemControl_set_wlim_series(SystemControlObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_TcsmoltenSalt_SystemControl_wlim_series_aset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"F_wc", (getter)SystemControl_get_F_wc,(setter)SystemControl_set_F_wc,
	"TOU array of fractions indicating wet cooling share for hybrid cooling [], array.\n Required if: pc_config=0.",
 	NULL},
{"ampl_data_dir", (getter)SystemControl_get_ampl_data_dir,(setter)SystemControl_set_ampl_data_dir,
	"AMPL data file directory [], string.\n Required if: ?=''.",
 	NULL},
{"ampl_exec_call", (getter)SystemControl_get_ampl_exec_call,(setter)SystemControl_set_ampl_exec_call,
	"System command to run AMPL code [], string.\n Required if: ?='ampl sdk_solution.run'.",
 	NULL},
{"aux_par", (getter)SystemControl_get_aux_par,(setter)SystemControl_set_aux_par,
	"Aux heater, boiler parasitic [MWe/MWcap], number.\n Required if: *.",
 	NULL},
{"aux_par_0", (getter)SystemControl_get_aux_par_0,(setter)SystemControl_set_aux_par_0,
	"Aux heater, boiler parasitic - constant coefficient [], number.\n Required if: *.",
 	NULL},
{"aux_par_1", (getter)SystemControl_get_aux_par_1,(setter)SystemControl_set_aux_par_1,
	"Aux heater, boiler parasitic - linear coefficient [], number.\n Required if: *.",
 	NULL},
{"aux_par_2", (getter)SystemControl_get_aux_par_2,(setter)SystemControl_set_aux_par_2,
	"Aux heater, boiler parasitic - quadratic coefficient [], number.\n Required if: *.",
 	NULL},
{"aux_par_f", (getter)SystemControl_get_aux_par_f,(setter)SystemControl_set_aux_par_f,
	"Aux heater, boiler parasitic - multiplying fraction [], number.\n Required if: *.",
 	NULL},
{"bop_par", (getter)SystemControl_get_bop_par,(setter)SystemControl_set_bop_par,
	"Balance of plant parasitic power fraction [MWe/MWcap], number.\n Required if: *.",
 	NULL},
{"bop_par_0", (getter)SystemControl_get_bop_par_0,(setter)SystemControl_set_bop_par_0,
	"Balance of plant parasitic power fraction - const coeff [], number.\n Required if: *.",
 	NULL},
{"bop_par_1", (getter)SystemControl_get_bop_par_1,(setter)SystemControl_set_bop_par_1,
	"Balance of plant parasitic power fraction - linear coeff [], number.\n Required if: *.",
 	NULL},
{"bop_par_2", (getter)SystemControl_get_bop_par_2,(setter)SystemControl_set_bop_par_2,
	"Balance of plant parasitic power fraction - quadratic coeff [], number.\n Required if: *.",
 	NULL},
{"bop_par_f", (getter)SystemControl_get_bop_par_f,(setter)SystemControl_set_bop_par_f,
	"Balance of plant parasitic power fraction - mult frac [], number.\n Required if: *.",
 	NULL},
{"disp_csu_cost", (getter)SystemControl_get_disp_csu_cost,(setter)SystemControl_set_disp_csu_cost,
	"Cycle startup cost [$], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_frequency", (getter)SystemControl_get_disp_frequency,(setter)SystemControl_set_disp_frequency,
	"Frequency for dispatch optimization calculations [hour], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_horizon", (getter)SystemControl_get_disp_horizon,(setter)SystemControl_set_disp_horizon,
	"Time horizon for dispatch optimization [hour], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_max_iter", (getter)SystemControl_get_disp_max_iter,(setter)SystemControl_set_disp_max_iter,
	"Max number of dispatch optimization iterations [], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_mip_gap", (getter)SystemControl_get_disp_mip_gap,(setter)SystemControl_set_disp_mip_gap,
	"Dispatch optimization solution tolerance [], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_pen_delta_w", (getter)SystemControl_get_disp_pen_delta_w,(setter)SystemControl_set_disp_pen_delta_w,
	"Dispatch cycle production change penalty [$/kWe-change], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_reporting", (getter)SystemControl_get_disp_reporting,(setter)SystemControl_set_disp_reporting,
	"Dispatch optimization reporting level [], number.\n Required if: ?=-1.",
 	NULL},
{"disp_rsu_cost", (getter)SystemControl_get_disp_rsu_cost,(setter)SystemControl_set_disp_rsu_cost,
	"Receiver startup cost [$], number.\n Required if: is_dispatch=1.",
 	NULL},
{"disp_spec_bb", (getter)SystemControl_get_disp_spec_bb,(setter)SystemControl_set_disp_spec_bb,
	"Dispatch optimization B&B heuristic [], number.\n Required if: ?=-1.",
 	NULL},
{"disp_spec_presolve", (getter)SystemControl_get_disp_spec_presolve,(setter)SystemControl_set_disp_spec_presolve,
	"Dispatch optimization presolve heuristic [], number.\n Required if: ?=-1.",
 	NULL},
{"disp_spec_scaling", (getter)SystemControl_get_disp_spec_scaling,(setter)SystemControl_set_disp_spec_scaling,
	"Dispatch optimization scaling heuristic [], number.\n Required if: ?=-1.",
 	NULL},
{"disp_steps_per_hour", (getter)SystemControl_get_disp_steps_per_hour,(setter)SystemControl_set_disp_steps_per_hour,
	"Time steps per hour for dispatch optimization calculations [], number.\n Required if: ?=1.",
 	NULL},
{"disp_time_weighting", (getter)SystemControl_get_disp_time_weighting,(setter)SystemControl_set_disp_time_weighting,
	"Dispatch optimization future time discounting factor [], number.\n Required if: ?=0.99.",
 	NULL},
{"disp_timeout", (getter)SystemControl_get_disp_timeout,(setter)SystemControl_set_disp_timeout,
	"Max dispatch optimization solve duration [s], number.\n Required if: is_dispatch=1.",
 	NULL},
{"dispatch_series", (getter)SystemControl_get_dispatch_series,(setter)SystemControl_set_dispatch_series,
	"Time series dispatch factors [], array.\n ",
 	NULL},
{"f_turb_tou_periods", (getter)SystemControl_get_f_turb_tou_periods,(setter)SystemControl_set_f_turb_tou_periods,
	"Dispatch logic for turbine load fraction [], array.\n Required if: *.",
 	NULL},
{"is_ampl_engine", (getter)SystemControl_get_is_ampl_engine,(setter)SystemControl_set_is_ampl_engine,
	"Run dispatch optimization with external AMPL engine [], number.\n Required if: ?=0.",
 	NULL},
{"is_dispatch", (getter)SystemControl_get_is_dispatch,(setter)SystemControl_set_is_dispatch,
	"Allow dispatch optimization? [], number.\n Required if: ?=0.",
 	NULL},
{"is_dispatch_series", (getter)SystemControl_get_is_dispatch_series,(setter)SystemControl_set_is_dispatch_series,
	"Use time-series dispatch factors [], number.\n Required if: ?=0.",
 	NULL},
{"is_wlim_series", (getter)SystemControl_get_is_wlim_series,(setter)SystemControl_set_is_wlim_series,
	"Use time-series net electricity generation limits [], number.\n Required if: ?=0.",
 	NULL},
{"is_write_ampl_dat", (getter)SystemControl_get_is_write_ampl_dat,(setter)SystemControl_set_is_write_ampl_dat,
	"Write AMPL data files for dispatch run [], number.\n Required if: ?=0.",
 	NULL},
{"pb_fixed_par", (getter)SystemControl_get_pb_fixed_par,(setter)SystemControl_set_pb_fixed_par,
	"Fixed parasitic load - runs at all times [MWe/MWcap], number.\n Required if: *.",
 	NULL},
{"q_rec_heattrace", (getter)SystemControl_get_q_rec_heattrace,(setter)SystemControl_set_q_rec_heattrace,
	"Receiver heat trace energy consumption during startup [kWe-hr], number.\n Required if: ?=0.0.",
 	NULL},
{"q_rec_standby", (getter)SystemControl_get_q_rec_standby,(setter)SystemControl_set_q_rec_standby,
	"Receiver standby energy consumption [kWt], number.\n Required if: ?=9e99.",
 	NULL},
{"time_start", (getter)SystemControl_get_time_start,(setter)SystemControl_set_time_start,
	"Simulation start time [s], number.\n Required if: ?=0.",
 	NULL},
{"time_steps_per_hour", (getter)SystemControl_get_time_steps_per_hour,(setter)SystemControl_set_time_steps_per_hour,
	"Number of simulation time steps per hour [], number.\n Required if: ?=-1.",
 	NULL},
{"time_stop", (getter)SystemControl_get_time_stop,(setter)SystemControl_set_time_stop,
	"Simulation stop time [s], number.\n Required if: ?=31536000.",
 	NULL},
{"vacuum_arrays", (getter)SystemControl_get_vacuum_arrays,(setter)SystemControl_set_vacuum_arrays,
	"Allocate arrays for only the required number of steps [], number.\n Required if: ?=0.",
 	NULL},
{"weekday_schedule", (getter)SystemControl_get_weekday_schedule,(setter)SystemControl_set_weekday_schedule,
	"12x24 CSP operation Time-of-Use Weekday schedule [], matrix.\n Required if: *.",
 	NULL},
{"weekend_schedule", (getter)SystemControl_get_weekend_schedule,(setter)SystemControl_set_weekend_schedule,
	"12x24 CSP operation Time-of-Use Weekend schedule [], matrix.\n Required if: *.",
 	NULL},
{"wlim_series", (getter)SystemControl_get_wlim_series,(setter)SystemControl_set_wlim_series,
	"Time series net electicity generation limits [kWe], array.\n Required if: is_wlim_series=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.SystemControl",             /*tp_name*/
		sizeof(SystemControlObject),          /*tp_basicsize*/
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
		SystemControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemControl_getset,          /*tp_getset*/
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
	 * UserDefinedPowerCycle Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} UserDefinedPowerCycleObject;

static PyTypeObject UserDefinedPowerCycle_Type;

static PyObject *
UserDefinedPowerCycle_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = UserDefinedPowerCycle_Type.tp_alloc(&UserDefinedPowerCycle_Type,0);

	UserDefinedPowerCycleObject* UserDefinedPowerCycle_obj = (UserDefinedPowerCycleObject*)new_obj;

	UserDefinedPowerCycle_obj->data_ptr = data_ptr;

	return new_obj;
}

/* UserDefinedPowerCycle methods */

static PyObject *
UserDefinedPowerCycle_assign(UserDefinedPowerCycleObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "UserDefinedPowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPowerCycle_export(UserDefinedPowerCycleObject *self, PyObject *args)
{
	PyTypeObject* tp = &UserDefinedPowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef UserDefinedPowerCycle_methods[] = {
		{"assign",            (PyCFunction)UserDefinedPowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)UserDefinedPowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UserDefinedPowerCycle_get_ud_T_amb_des(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_des_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_amb_des(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_des_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_T_amb_high(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_high_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_amb_high(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_high_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_T_amb_ind_od(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_amb_ind_od(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_T_amb_low(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_low_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_amb_low(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_amb_low_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_T_htf_high(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_htf_high_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_htf_high(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_htf_high_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_T_htf_ind_od(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_htf_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_htf_ind_od(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_T_htf_low(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_htf_low_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_T_htf_low(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_T_htf_low_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_f_W_dot_cool_des(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_f_W_dot_cool_des_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_f_W_dot_cool_des(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_f_W_dot_cool_des_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_ind_od(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_ind_od(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_m_dot_htf_high(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_htf_high_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_m_dot_htf_high(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_htf_high_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_m_dot_htf_ind_od(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_htf_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_m_dot_htf_ind_od(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_m_dot_htf_low(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_htf_low_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_m_dot_htf_low(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_htf_low_fset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_m_dot_water_cool_des(UserDefinedPowerCycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_water_cool_des_fget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_m_dot_water_cool_des(UserDefinedPowerCycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_UserDefinedPowerCycle_ud_m_dot_water_cool_des_fset, self->data_ptr);
}

static PyGetSetDef UserDefinedPowerCycle_getset[] = {
{"ud_T_amb_des", (getter)UserDefinedPowerCycle_get_ud_T_amb_des,(setter)UserDefinedPowerCycle_set_ud_T_amb_des,
	"Ambient temperature at user-defined power cycle design point [C], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_T_amb_high", (getter)UserDefinedPowerCycle_get_ud_T_amb_high,(setter)UserDefinedPowerCycle_set_ud_T_amb_high,
	"High level ambient temperature for HTF mass flow rate parametric [C], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_T_amb_ind_od", (getter)UserDefinedPowerCycle_get_ud_T_amb_ind_od,(setter)UserDefinedPowerCycle_set_ud_T_amb_ind_od,
	"Off design table of user-defined power cycle performance formed from parametric on T_amb [C] [], matrix.\n Required if: pc_config=1.",
 	NULL},
{"ud_T_amb_low", (getter)UserDefinedPowerCycle_get_ud_T_amb_low,(setter)UserDefinedPowerCycle_set_ud_T_amb_low,
	"Low level ambient temperature for HTF mass flow rate parametric [C], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_T_htf_high", (getter)UserDefinedPowerCycle_get_ud_T_htf_high,(setter)UserDefinedPowerCycle_set_ud_T_htf_high,
	"High level HTF inlet temperature for T_amb parametric [C], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_T_htf_ind_od", (getter)UserDefinedPowerCycle_get_ud_T_htf_ind_od,(setter)UserDefinedPowerCycle_set_ud_T_htf_ind_od,
	"Off design table of user-defined power cycle performance formed from parametric on T_htf_hot [C] [], matrix.\n Required if: pc_config=1.",
 	NULL},
{"ud_T_htf_low", (getter)UserDefinedPowerCycle_get_ud_T_htf_low,(setter)UserDefinedPowerCycle_set_ud_T_htf_low,
	"Low level HTF inlet temperature for T_amb parametric [C], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_f_W_dot_cool_des", (getter)UserDefinedPowerCycle_get_ud_f_W_dot_cool_des,(setter)UserDefinedPowerCycle_set_ud_f_W_dot_cool_des,
	"Percent of user-defined power cycle design gross output consumed by cooling [%], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_ind_od", (getter)UserDefinedPowerCycle_get_ud_ind_od,(setter)UserDefinedPowerCycle_set_ud_ind_od,
	"Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb [], matrix.\n Required if: pc_config=1.",
 	NULL},
{"ud_m_dot_htf_high", (getter)UserDefinedPowerCycle_get_ud_m_dot_htf_high,(setter)UserDefinedPowerCycle_set_ud_m_dot_htf_high,
	"High level normalized HTF mass flow rate for T_HTF parametric [], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_m_dot_htf_ind_od", (getter)UserDefinedPowerCycle_get_ud_m_dot_htf_ind_od,(setter)UserDefinedPowerCycle_set_ud_m_dot_htf_ind_od,
	"Off design table of user-defined power cycle performance formed from parametric on m_dot_htf [ND] [], matrix.\n Required if: pc_config=1.",
 	NULL},
{"ud_m_dot_htf_low", (getter)UserDefinedPowerCycle_get_ud_m_dot_htf_low,(setter)UserDefinedPowerCycle_set_ud_m_dot_htf_low,
	"Low level normalized HTF mass flow rate for T_HTF parametric [], number.\n Required if: pc_config=1.",
 	NULL},
{"ud_m_dot_water_cool_des", (getter)UserDefinedPowerCycle_get_ud_m_dot_water_cool_des,(setter)UserDefinedPowerCycle_set_ud_m_dot_water_cool_des,
	"Mass flow rate of water required at user-defined power cycle design point [kg/s], number.\n Required if: pc_config=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject UserDefinedPowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.UserDefinedPowerCycle",             /*tp_name*/
		sizeof(UserDefinedPowerCycleObject),          /*tp_basicsize*/
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
		UserDefinedPowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		UserDefinedPowerCycle_getset,          /*tp_getset*/
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
	 * SCO2Cycle Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_TcsmoltenSalt   data_ptr;
} SCO2CycleObject;

static PyTypeObject SCO2Cycle_Type;

static PyObject *
SCO2Cycle_new(SAM_TcsmoltenSalt data_ptr)
{
	PyObject* new_obj = SCO2Cycle_Type.tp_alloc(&SCO2Cycle_Type,0);

	SCO2CycleObject* SCO2Cycle_obj = (SCO2CycleObject*)new_obj;

	SCO2Cycle_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SCO2Cycle methods */

static PyObject *
SCO2Cycle_assign(SCO2CycleObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "SCO2Cycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SCO2Cycle_export(SCO2CycleObject *self, PyObject *args)
{
	PyTypeObject* tp = &SCO2Cycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SCO2Cycle_methods[] = {
		{"assign",            (PyCFunction)SCO2Cycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)SCO2Cycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SCO2Cycle_get_P_high_limit(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_P_high_limit_fget, self->data_ptr);
}

static int
SCO2Cycle_set_P_high_limit(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_P_high_limit_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_P_high_limit(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_P_high_limit_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_P_high_limit(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_P_high_limit_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_P_ref(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_P_ref_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_P_ref(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_P_ref_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_T_amb_des(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_T_amb_des_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_T_amb_des(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_T_amb_des_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_T_approach(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_T_approach_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_T_approach(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_T_approach_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_T_htf_hot_des(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_T_htf_hot_des_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_T_htf_hot_des(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_T_htf_hot_des_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_deltaT_PHX(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_deltaT_PHX_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_deltaT_PHX(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_deltaT_PHX_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_design_eff(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_design_eff_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_design_eff(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_design_eff_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_eta_c(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_eta_c_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_eta_c(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_eta_c_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_eta_t(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_eta_t_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_eta_t(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_eta_t_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get__sco2_recup_eff_max(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle__sco2_recup_eff_max_fget, self->data_ptr);
}

static int
SCO2Cycle_set__sco2_recup_eff_max(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle__sco2_recup_eff_max_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_deltaT_PHX(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_deltaT_PHX_fget, self->data_ptr);
}

static int
SCO2Cycle_set_deltaT_PHX(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_deltaT_PHX_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_eta_c(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_eta_c_fget, self->data_ptr);
}

static int
SCO2Cycle_set_eta_c(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_eta_c_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_eta_t(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_eta_t_fget, self->data_ptr);
}

static int
SCO2Cycle_set_eta_t(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_eta_t_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_fan_power_perc_net(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_fan_power_perc_net_fget, self->data_ptr);
}

static int
SCO2Cycle_set_fan_power_perc_net(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_fan_power_perc_net_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_is_sco2_preprocess(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_is_sco2_preprocess_fget, self->data_ptr);
}

static int
SCO2Cycle_set_is_sco2_preprocess(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_is_sco2_preprocess_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_recup_eff_max(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_recup_eff_max_fget, self->data_ptr);
}

static int
SCO2Cycle_set_recup_eff_max(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_recup_eff_max_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2_T_amb_des(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2_T_amb_des_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2_T_amb_des(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2_T_amb_des_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2_T_approach(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2_T_approach_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2_T_approach(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2_T_approach_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2_cycle_config(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2_cycle_config_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2_cycle_config(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2_cycle_config_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_amb_high(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_amb_high_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_amb_high(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_amb_high_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_amb_ind_od(SCO2CycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_amb_ind_od_mget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_amb_ind_od(SCO2CycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_amb_ind_od_mset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_amb_low(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_amb_low_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_amb_low(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_amb_low_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_htf_cold_calc(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_cold_calc_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_htf_cold_calc(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_cold_calc_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_htf_high(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_high_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_htf_high(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_high_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_htf_ind_od(SCO2CycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_ind_od_mget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_htf_ind_od(SCO2CycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_T_htf_low(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_low_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_T_htf_low(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_T_htf_low_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_m_dot_htf_high(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_m_dot_htf_high_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_m_dot_htf_high(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_m_dot_htf_high_fset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_m_dot_htf_ind_od(SCO2CycleObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_m_dot_htf_ind_od_mget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_m_dot_htf_ind_od(SCO2CycleObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_m_dot_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
SCO2Cycle_get_sco2ud_m_dot_htf_low(SCO2CycleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_m_dot_htf_low_fget, self->data_ptr);
}

static int
SCO2Cycle_set_sco2ud_m_dot_htf_low(SCO2CycleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_TcsmoltenSalt_SCO2Cycle_sco2ud_m_dot_htf_low_fset, self->data_ptr);
}

static PyGetSetDef SCO2Cycle_getset[] = {
{"P_high_limit", (getter)SCO2Cycle_get_P_high_limit,(setter)SCO2Cycle_set_P_high_limit,
	"Upper pressure limit in cycle [MPa], number.\n Required if: pc_config=2.",
 	NULL},
{"_sco2_P_high_limit", (getter)SCO2Cycle_get__sco2_P_high_limit,(setter)SCO2Cycle_set__sco2_P_high_limit,
	"Preprocess input: upper pressure limit [MPa], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_P_ref", (getter)SCO2Cycle_get__sco2_P_ref,(setter)SCO2Cycle_set__sco2_P_ref,
	"Preprocess input: gross power output [MWe], number.\n sco2_pc_pre; ",
 	NULL},
{"_sco2_T_amb_des", (getter)SCO2Cycle_get__sco2_T_amb_des,(setter)SCO2Cycle_set__sco2_T_amb_des,
	"Preprocess input: design ambient temperature [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_T_approach", (getter)SCO2Cycle_get__sco2_T_approach,(setter)SCO2Cycle_set__sco2_T_approach,
	"Preprocess input: compressor approach temperature [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_T_htf_hot_des", (getter)SCO2Cycle_get__sco2_T_htf_hot_des,(setter)SCO2Cycle_set__sco2_T_htf_hot_des,
	"Preprocess input: HTF hot temperature [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_deltaT_PHX", (getter)SCO2Cycle_get__sco2_deltaT_PHX,(setter)SCO2Cycle_set__sco2_deltaT_PHX,
	"Preprocess input: PHX approach temperature [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_design_eff", (getter)SCO2Cycle_get__sco2_design_eff,(setter)SCO2Cycle_set__sco2_design_eff,
	"Preprocess input: cycle thermal efficiency [], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_eta_c", (getter)SCO2Cycle_get__sco2_eta_c,(setter)SCO2Cycle_set__sco2_eta_c,
	"Preprocess input: compressor isentropic efficiency [], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_eta_t", (getter)SCO2Cycle_get__sco2_eta_t,(setter)SCO2Cycle_set__sco2_eta_t,
	"Preprocess input: turbine isentropic efficiency [], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"_sco2_recup_eff_max", (getter)SCO2Cycle_get__sco2_recup_eff_max,(setter)SCO2Cycle_set__sco2_recup_eff_max,
	"Preprocess input: max recuperator effectiveness [], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"deltaT_PHX", (getter)SCO2Cycle_get_deltaT_PHX,(setter)SCO2Cycle_set_deltaT_PHX,
	"Design temperature difference in PHX [C], number.\n Required if: pc_config=2.",
 	NULL},
{"eta_c", (getter)SCO2Cycle_get_eta_c,(setter)SCO2Cycle_set_eta_c,
	"Isentropic efficiency of compressor(s) [], number.\n Required if: pc_config=2.",
 	NULL},
{"eta_t", (getter)SCO2Cycle_get_eta_t,(setter)SCO2Cycle_set_eta_t,
	"Isentropic efficiency of turbine [], number.\n Required if: pc_config=2.",
 	NULL},
{"fan_power_perc_net", (getter)SCO2Cycle_get_fan_power_perc_net,(setter)SCO2Cycle_set_fan_power_perc_net,
	"Percent of net cycle output used for fan power at design [%], number.\n Required if: pc_config=2.",
 	NULL},
{"is_sco2_preprocess", (getter)SCO2Cycle_get_is_sco2_preprocess,(setter)SCO2Cycle_set_is_sco2_preprocess,
	"Is sco2 off-design performance preprocessed? 1=yes [], number.\n Required if: ?=0.",
 	NULL},
{"recup_eff_max", (getter)SCO2Cycle_get_recup_eff_max,(setter)SCO2Cycle_set_recup_eff_max,
	"Maximum recuperator effectiveness [], number.\n Required if: pc_config=2.",
 	NULL},
{"sco2_T_amb_des", (getter)SCO2Cycle_get_sco2_T_amb_des,(setter)SCO2Cycle_set_sco2_T_amb_des,
	"Ambient temperature at design point [C], number.\n Required if: pc_config=2.",
 	NULL},
{"sco2_T_approach", (getter)SCO2Cycle_get_sco2_T_approach,(setter)SCO2Cycle_set_sco2_T_approach,
	"Temperature difference between main compressor CO2 inlet and ambient air [C], number.\n Required if: pc_config=2.",
 	NULL},
{"sco2_cycle_config", (getter)SCO2Cycle_get_sco2_cycle_config,(setter)SCO2Cycle_set_sco2_cycle_config,
	"SCO2 cycle configuration, 1=recompression, 2=partial cooling [], number.\n Required if: pc_config=2.",
 	NULL},
{"sco2ud_T_amb_high", (getter)SCO2Cycle_get_sco2ud_T_amb_high,(setter)SCO2Cycle_set_sco2ud_T_amb_high,
	"High level ambient temperature for HTF mass flow rate parametric [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_T_amb_ind_od", (getter)SCO2Cycle_get_sco2ud_T_amb_ind_od,(setter)SCO2Cycle_set_sco2ud_T_amb_ind_od,
	"Off design table of user-defined power cycle performance formed from parametric on T_amb [C] [], matrix.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_T_amb_low", (getter)SCO2Cycle_get_sco2ud_T_amb_low,(setter)SCO2Cycle_set_sco2ud_T_amb_low,
	"Low level ambient temperature for HTF mass flow rate parametric [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_T_htf_cold_calc", (getter)SCO2Cycle_get_sco2ud_T_htf_cold_calc,(setter)SCO2Cycle_set_sco2ud_T_htf_cold_calc,
	"HTF cold temperature from sCO2 cycle des, may be different than T_htf_cold_des [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_T_htf_high", (getter)SCO2Cycle_get_sco2ud_T_htf_high,(setter)SCO2Cycle_set_sco2ud_T_htf_high,
	"High level HTF inlet temperature for T_amb parametric [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_T_htf_ind_od", (getter)SCO2Cycle_get_sco2ud_T_htf_ind_od,(setter)SCO2Cycle_set_sco2ud_T_htf_ind_od,
	"Off design table of user-defined power cycle performance formed from parametric on T_htf_hot [C] [], matrix.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_T_htf_low", (getter)SCO2Cycle_get_sco2ud_T_htf_low,(setter)SCO2Cycle_set_sco2ud_T_htf_low,
	"Low level HTF inlet temperature for T_amb parametric [C], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_m_dot_htf_high", (getter)SCO2Cycle_get_sco2ud_m_dot_htf_high,(setter)SCO2Cycle_set_sco2ud_m_dot_htf_high,
	"High level normalized HTF mass flow rate for T_HTF parametric [], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_m_dot_htf_ind_od", (getter)SCO2Cycle_get_sco2ud_m_dot_htf_ind_od,(setter)SCO2Cycle_set_sco2ud_m_dot_htf_ind_od,
	"Off design table of user-defined power cycle performance formed from parametric on m_dot_htf [ND] [], matrix.\n Required if: is_sco2_preprocess=1.",
 	NULL},
{"sco2ud_m_dot_htf_low", (getter)SCO2Cycle_get_sco2ud_m_dot_htf_low,(setter)SCO2Cycle_set_sco2ud_m_dot_htf_low,
	"Low level normalized HTF mass flow rate for T_HTF parametric [], number.\n Required if: is_sco2_preprocess=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SCO2Cycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.SCO2Cycle",             /*tp_name*/
		sizeof(SCO2CycleObject),          /*tp_basicsize*/
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
		SCO2Cycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SCO2Cycle_getset,          /*tp_getset*/
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
	SAM_TcsmoltenSalt   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_TcsmoltenSalt data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsmoltenSalt", "Outputs")){
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
Outputs_get_A_sf(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_A_sf_fget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cooling_tower_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_P_cooling_tower_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cycle(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_P_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_fixed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_P_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_out_net(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_P_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_plant_balance_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_P_plant_balance_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_tower_pump(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_P_tower_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Q_thermal(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_Q_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_T_pc_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_T_pc_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_T_rec_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_T_rec_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_annual_W_cycle_gross_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_annual_total_water_use_fget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_interest1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_interest2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_interest3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest4(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_interest4_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_interest5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_interest_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_interest_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_percent_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_percent_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_principal1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_principal2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_principal3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal4(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_principal4_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_principal5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_principal_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_principal_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_total1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total2(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_total2_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total3(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_total3_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total4(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_total4_fget, self->data_ptr);
}

static PyObject *
Outputs_get_const_per_total5(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_const_per_total5_fget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_financing_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_construction_financing_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_conversion_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_bop(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_bop_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_contingency(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_contingency_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_epc_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_epc_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_fossil(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_fossil_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_heliostats(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_heliostats_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_installed_per_capacity(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_installed_per_capacity_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_plm_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_plm_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_power_block(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_power_block_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_receiver(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_receiver_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_sales_tax_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_sales_tax_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_site_improvements(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_site_improvements_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_storage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_storage_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_total_land_area(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_total_land_area_fget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_tower(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_csp_pt_cost_tower_fget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_iter_ann(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_disp_iter_ann_fget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_obj_relax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_obj_relax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_objective_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective_ann(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_disp_objective_ann_fget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_pceff_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_pceff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_presolve_nconstr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr_ann(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_disp_presolve_nconstr_ann_fget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_presolve_nvar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar_ann(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_disp_presolve_nvar_ann_fget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qpbsu_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_qpbsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsf_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_qsf_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfprod_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_qsfprod_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfsu_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_qsfsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rev_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_rev_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_iter(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_solve_iter_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_solve_state_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_solve_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time_ann(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_disp_solve_time_ann_fget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_tes_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_tes_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_thermeff_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_thermeff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_wpb_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_disp_wpb_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_field(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_eta_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_map_out(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_Outputs_eta_map_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_therm(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_eta_therm_aget, self->data_ptr);
}

static PyObject *
Outputs_get_flux_maps_out(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_Outputs_flux_maps_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_htf_pump_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_sb_allowed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_is_pc_sb_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_su_allowed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_is_pc_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_rec_su_allowed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_is_rec_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_m_dot_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_rec(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_m_dot_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_ch(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_m_dot_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_dc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_m_dot_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_water_pc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_m_dot_water_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_n_op_modes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_n_op_modes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_a(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_operating_modes_a_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_b(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_operating_modes_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_c(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_operating_modes_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pparasi(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_pparasi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pricing_mult(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_pricing_mult_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_ch_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dc_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_on(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_est_cr_on_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_su(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_est_cr_su_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_ch(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_est_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_dc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_est_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_max(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_pc_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_min(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_pc_min_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_sb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_pc_sb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_target(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_pc_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_heater(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pc_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_piping_losses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_piping_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_sf_inc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_sf_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_thermal_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_q_thermal_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rh(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sf_adjust_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_sf_adjust_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solaz(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_solaz_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_total_direct_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_total_direct_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_total_indirect_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_total_indirect_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_total_installed_cost(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_total_installed_cost_fget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ud_T_amb_ind_od_out(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_Outputs_ud_T_amb_ind_od_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_ud_T_htf_ind_od_out(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_Outputs_ud_T_htf_ind_od_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_ud_m_dot_htf_ind_od_out(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsmoltenSalt_Outputs_ud_m_dot_htf_ind_od_out_mget, self->data_ptr);
}

static PyObject *
Outputs_get_ui_direct_subtotal(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_TcsmoltenSalt_Outputs_ui_direct_subtotal_fget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsmoltenSalt_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"A_sf", (getter)Outputs_get_A_sf,(setter)0,
	"Solar field area [m^2], number.",
 	NULL},
{"P_cooling_tower_tot", (getter)Outputs_get_P_cooling_tower_tot,(setter)0,
	"Parasitic power condenser operation [MWe], array.",
 	NULL},
{"P_cycle", (getter)Outputs_get_P_cycle,(setter)0,
	"PC electrical power output, gross [MWe], array.",
 	NULL},
{"P_fixed", (getter)Outputs_get_P_fixed,(setter)0,
	"Parasitic power fixed load [MWe], array.",
 	NULL},
{"P_out_net", (getter)Outputs_get_P_out_net,(setter)0,
	"Total electric power to grid [MWe], array.",
 	NULL},
{"P_plant_balance_tot", (getter)Outputs_get_P_plant_balance_tot,(setter)0,
	"Parasitic power generation-dependent load [MWe], array.",
 	NULL},
{"P_tower_pump", (getter)Outputs_get_P_tower_pump,(setter)0,
	"Parasitic power receiver/tower HTF pump [MWe], array.",
 	NULL},
{"Q_thermal", (getter)Outputs_get_Q_thermal,(setter)0,
	"Receiver thermal power to HTF less piping loss [MWt], array.",
 	NULL},
{"T_pc_in", (getter)Outputs_get_T_pc_in,(setter)0,
	"PC HTF inlet temperature [C], array.",
 	NULL},
{"T_pc_out", (getter)Outputs_get_T_pc_out,(setter)0,
	"PC HTF outlet temperature [C], array.",
 	NULL},
{"T_rec_in", (getter)Outputs_get_T_rec_in,(setter)0,
	"Receiver HTF inlet temperature [C], array.",
 	NULL},
{"T_rec_out", (getter)Outputs_get_T_rec_out,(setter)0,
	"Receiver HTF outlet temperature [C], array.",
 	NULL},
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	"TES cold temperature [C], array.",
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	"TES hot temperature [C], array.",
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	"Electrical source - power cycle gross output [kWhe], number.",
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual total electric power to grid [kWhe], number.",
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	"Total annual water usage, cycle + mirror washing [m3], number.",
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	"Resource beam normal irradiance [W/m2], array.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"const_per_interest1", (getter)Outputs_get_const_per_interest1,(setter)0,
	"Interest cost, loan 1 [$], number.",
 	NULL},
{"const_per_interest2", (getter)Outputs_get_const_per_interest2,(setter)0,
	"Interest cost, loan 2 [$], number.",
 	NULL},
{"const_per_interest3", (getter)Outputs_get_const_per_interest3,(setter)0,
	"Interest cost, loan 3 [$], number.",
 	NULL},
{"const_per_interest4", (getter)Outputs_get_const_per_interest4,(setter)0,
	"Interest cost, loan 4 [$], number.",
 	NULL},
{"const_per_interest5", (getter)Outputs_get_const_per_interest5,(setter)0,
	"Interest cost, loan 5 [$], number.",
 	NULL},
{"const_per_interest_total", (getter)Outputs_get_const_per_interest_total,(setter)0,
	"Total interest costs, all loans [$], number.",
 	NULL},
{"const_per_percent_total", (getter)Outputs_get_const_per_percent_total,(setter)0,
	"Total percent of installed costs, all loans [%], number.",
 	NULL},
{"const_per_principal1", (getter)Outputs_get_const_per_principal1,(setter)0,
	"Principal, loan 1 [$], number.",
 	NULL},
{"const_per_principal2", (getter)Outputs_get_const_per_principal2,(setter)0,
	"Principal, loan 2 [$], number.",
 	NULL},
{"const_per_principal3", (getter)Outputs_get_const_per_principal3,(setter)0,
	"Principal, loan 3 [$], number.",
 	NULL},
{"const_per_principal4", (getter)Outputs_get_const_per_principal4,(setter)0,
	"Principal, loan 4 [$], number.",
 	NULL},
{"const_per_principal5", (getter)Outputs_get_const_per_principal5,(setter)0,
	"Principal, loan 5 [$], number.",
 	NULL},
{"const_per_principal_total", (getter)Outputs_get_const_per_principal_total,(setter)0,
	"Total principal, all loans [$], number.",
 	NULL},
{"const_per_total1", (getter)Outputs_get_const_per_total1,(setter)0,
	"Total financing cost, loan 1 [$], number.",
 	NULL},
{"const_per_total2", (getter)Outputs_get_const_per_total2,(setter)0,
	"Total financing cost, loan 2 [$], number.",
 	NULL},
{"const_per_total3", (getter)Outputs_get_const_per_total3,(setter)0,
	"Total financing cost, loan 3 [$], number.",
 	NULL},
{"const_per_total4", (getter)Outputs_get_const_per_total4,(setter)0,
	"Total financing cost, loan 4 [$], number.",
 	NULL},
{"const_per_total5", (getter)Outputs_get_const_per_total5,(setter)0,
	"Total financing cost, loan 5 [$], number.",
 	NULL},
{"construction_financing_cost", (getter)Outputs_get_construction_financing_cost,(setter)0,
	"Total construction financing cost [$], number.",
 	NULL},
{"conversion_factor", (getter)Outputs_get_conversion_factor,(setter)0,
	"Gross to net conversion factor [%], number.",
 	NULL},
{"csp_pt_cost_bop", (getter)Outputs_get_csp_pt_cost_bop,(setter)0,
	"BOP cost [$], number.",
 	NULL},
{"csp_pt_cost_contingency", (getter)Outputs_get_csp_pt_cost_contingency,(setter)0,
	"Contingency cost [$], number.",
 	NULL},
{"csp_pt_cost_epc_total", (getter)Outputs_get_csp_pt_cost_epc_total,(setter)0,
	"EPC and owner cost [$], number.",
 	NULL},
{"csp_pt_cost_fossil", (getter)Outputs_get_csp_pt_cost_fossil,(setter)0,
	"Fossil backup cost [$], number.",
 	NULL},
{"csp_pt_cost_heliostats", (getter)Outputs_get_csp_pt_cost_heliostats,(setter)0,
	"Heliostat cost [$], number.",
 	NULL},
{"csp_pt_cost_installed_per_capacity", (getter)Outputs_get_csp_pt_cost_installed_per_capacity,(setter)0,
	"Estimated installed cost per cap [$], number.",
 	NULL},
{"csp_pt_cost_plm_total", (getter)Outputs_get_csp_pt_cost_plm_total,(setter)0,
	"Total land cost [$], number.",
 	NULL},
{"csp_pt_cost_power_block", (getter)Outputs_get_csp_pt_cost_power_block,(setter)0,
	"Power cycle cost [$], number.",
 	NULL},
{"csp_pt_cost_receiver", (getter)Outputs_get_csp_pt_cost_receiver,(setter)0,
	"Receiver cost [$], number.",
 	NULL},
{"csp_pt_cost_sales_tax_total", (getter)Outputs_get_csp_pt_cost_sales_tax_total,(setter)0,
	"Sales tax cost [$], number.",
 	NULL},
{"csp_pt_cost_site_improvements", (getter)Outputs_get_csp_pt_cost_site_improvements,(setter)0,
	"Site improvement cost [$], number.",
 	NULL},
{"csp_pt_cost_storage", (getter)Outputs_get_csp_pt_cost_storage,(setter)0,
	"TES cost [$], number.",
 	NULL},
{"csp_pt_cost_total_land_area", (getter)Outputs_get_csp_pt_cost_total_land_area,(setter)0,
	"Total land area [acre], number.",
 	NULL},
{"csp_pt_cost_tower", (getter)Outputs_get_csp_pt_cost_tower,(setter)0,
	"Tower cost [$], number.",
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	"Field optical focus fraction [], array.",
 	NULL},
{"disp_iter_ann", (getter)Outputs_get_disp_iter_ann,(setter)0,
	"Annual sum of dispatch solver iterations [], number.",
 	NULL},
{"disp_obj_relax", (getter)Outputs_get_disp_obj_relax,(setter)0,
	"Dispatch objective function - relaxed max [], array.",
 	NULL},
{"disp_objective", (getter)Outputs_get_disp_objective,(setter)0,
	"Dispatch objective function value [], array.",
 	NULL},
{"disp_objective_ann", (getter)Outputs_get_disp_objective_ann,(setter)0,
	"Annual sum of dispatch objective function value [], number.",
 	NULL},
{"disp_pceff_expected", (getter)Outputs_get_disp_pceff_expected,(setter)0,
	"Dispatch expected power cycle efficiency adj. [], array.",
 	NULL},
{"disp_presolve_nconstr", (getter)Outputs_get_disp_presolve_nconstr,(setter)0,
	"Dispatch number of constraints in problem [], array.",
 	NULL},
{"disp_presolve_nconstr_ann", (getter)Outputs_get_disp_presolve_nconstr_ann,(setter)0,
	"Annual sum of dispatch problem constraint count [], number.",
 	NULL},
{"disp_presolve_nvar", (getter)Outputs_get_disp_presolve_nvar,(setter)0,
	"Dispatch number of variables in problem [], array.",
 	NULL},
{"disp_presolve_nvar_ann", (getter)Outputs_get_disp_presolve_nvar_ann,(setter)0,
	"Annual sum of dispatch problem variable count [], number.",
 	NULL},
{"disp_qpbsu_expected", (getter)Outputs_get_disp_qpbsu_expected,(setter)0,
	"Dispatch expected power cycle startup energy [MWht], array.",
 	NULL},
{"disp_qsf_expected", (getter)Outputs_get_disp_qsf_expected,(setter)0,
	"Dispatch expected solar field available energy [MWt], array.",
 	NULL},
{"disp_qsfprod_expected", (getter)Outputs_get_disp_qsfprod_expected,(setter)0,
	"Dispatch expected solar field generation [MWt], array.",
 	NULL},
{"disp_qsfsu_expected", (getter)Outputs_get_disp_qsfsu_expected,(setter)0,
	"Dispatch expected solar field startup enegy [MWt], array.",
 	NULL},
{"disp_rev_expected", (getter)Outputs_get_disp_rev_expected,(setter)0,
	"Dispatch expected revenue factor [], array.",
 	NULL},
{"disp_solve_iter", (getter)Outputs_get_disp_solve_iter,(setter)0,
	"Dispatch iterations count [], array.",
 	NULL},
{"disp_solve_state", (getter)Outputs_get_disp_solve_state,(setter)0,
	"Dispatch solver state [], array.",
 	NULL},
{"disp_solve_time", (getter)Outputs_get_disp_solve_time,(setter)0,
	"Dispatch solver time [sec], array.",
 	NULL},
{"disp_solve_time_ann", (getter)Outputs_get_disp_solve_time_ann,(setter)0,
	"Annual sum of dispatch solver time [], number.",
 	NULL},
{"disp_tes_expected", (getter)Outputs_get_disp_tes_expected,(setter)0,
	"Dispatch expected TES charge level [MWht], array.",
 	NULL},
{"disp_thermeff_expected", (getter)Outputs_get_disp_thermeff_expected,(setter)0,
	"Dispatch expected SF thermal efficiency adj. [], array.",
 	NULL},
{"disp_wpb_expected", (getter)Outputs_get_disp_wpb_expected,(setter)0,
	"Dispatch expected power generation [MWe], array.",
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	"TES charge state [MWht], array.",
 	NULL},
{"eta", (getter)Outputs_get_eta,(setter)0,
	"PC efficiency, gross [], array.",
 	NULL},
{"eta_field", (getter)Outputs_get_eta_field,(setter)0,
	"Field optical efficiency [], array.",
 	NULL},
{"eta_map_out", (getter)Outputs_get_eta_map_out,(setter)0,
	"Solar field optical efficiencies [], matrix.",
 	NULL},
{"eta_therm", (getter)Outputs_get_eta_therm,(setter)0,
	"Receiver thermal efficiency [], array.",
 	NULL},
{"flux_maps_out", (getter)Outputs_get_flux_maps_out,(setter)0,
	"Flux map intensities [], matrix.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"Total electric power to grid with available derate [kWe], array.",
 	NULL},
{"htf_pump_power", (getter)Outputs_get_htf_pump_power,(setter)0,
	"Parasitic power TES and cycle HTF pump [MWe], array.",
 	NULL},
{"is_pc_sb_allowed", (getter)Outputs_get_is_pc_sb_allowed,(setter)0,
	"Is power cycle standby allowed [], array.",
 	NULL},
{"is_pc_su_allowed", (getter)Outputs_get_is_pc_su_allowed,(setter)0,
	"Is power cycle startup allowed [], array.",
 	NULL},
{"is_rec_su_allowed", (getter)Outputs_get_is_rec_su_allowed,(setter)0,
	"Is receiver startup allowed [], array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"m_dot_balance", (getter)Outputs_get_m_dot_balance,(setter)0,
	"Relative mass flow balance error [], array.",
 	NULL},
{"m_dot_pc", (getter)Outputs_get_m_dot_pc,(setter)0,
	"PC HTF mass flow rate [kg/s], array.",
 	NULL},
{"m_dot_rec", (getter)Outputs_get_m_dot_rec,(setter)0,
	"Receiver mass flow rate [kg/s], array.",
 	NULL},
{"m_dot_tes_ch", (getter)Outputs_get_m_dot_tes_ch,(setter)0,
	"TES charge mass flow rate [kg/s], array.",
 	NULL},
{"m_dot_tes_dc", (getter)Outputs_get_m_dot_tes_dc,(setter)0,
	"TES discharge mass flow rate [kg/s], array.",
 	NULL},
{"m_dot_water_pc", (getter)Outputs_get_m_dot_water_pc,(setter)0,
	"PC water consumption, makeup + cooling [kg/s], array.",
 	NULL},
{"n_op_modes", (getter)Outputs_get_n_op_modes,(setter)0,
	"Operating modes in reporting timestep [], array.",
 	NULL},
{"op_mode_1", (getter)Outputs_get_op_mode_1,(setter)0,
	"1st operating mode [], array.",
 	NULL},
{"op_mode_2", (getter)Outputs_get_op_mode_2,(setter)0,
	"2nd operating mode, if applicable [], array.",
 	NULL},
{"op_mode_3", (getter)Outputs_get_op_mode_3,(setter)0,
	"3rd operating mode, if applicable [], array.",
 	NULL},
{"operating_modes_a", (getter)Outputs_get_operating_modes_a,(setter)0,
	"First 3 operating modes tried [], array.",
 	NULL},
{"operating_modes_b", (getter)Outputs_get_operating_modes_b,(setter)0,
	"Next 3 operating modes tried [], array.",
 	NULL},
{"operating_modes_c", (getter)Outputs_get_operating_modes_c,(setter)0,
	"Final 3 operating modes tried [], array.",
 	NULL},
{"pparasi", (getter)Outputs_get_pparasi,(setter)0,
	"Parasitic power heliostat drives [MWe], array.",
 	NULL},
{"pricing_mult", (getter)Outputs_get_pricing_mult,(setter)0,
	"PPA price multiplier [], array.",
 	NULL},
{"q_balance", (getter)Outputs_get_q_balance,(setter)0,
	"Relative energy balance error [], array.",
 	NULL},
{"q_ch_tes", (getter)Outputs_get_q_ch_tes,(setter)0,
	"TES charge thermal power [MWt], array.",
 	NULL},
{"q_dc_tes", (getter)Outputs_get_q_dc_tes,(setter)0,
	"TES discharge thermal power [MWt], array.",
 	NULL},
{"q_dot_est_cr_on", (getter)Outputs_get_q_dot_est_cr_on,(setter)0,
	"Estimated receiver thermal power TO HTF [MWt], array.",
 	NULL},
{"q_dot_est_cr_su", (getter)Outputs_get_q_dot_est_cr_su,(setter)0,
	"Estimated receiver startup thermal power [MWt], array.",
 	NULL},
{"q_dot_est_tes_ch", (getter)Outputs_get_q_dot_est_tes_ch,(setter)0,
	"Estimated max TES charge thermal power [MWt], array.",
 	NULL},
{"q_dot_est_tes_dc", (getter)Outputs_get_q_dot_est_tes_dc,(setter)0,
	"Estimated max TES discharge thermal power [MWt], array.",
 	NULL},
{"q_dot_pc_max", (getter)Outputs_get_q_dot_pc_max,(setter)0,
	"Max thermal power to PC [MWt], array.",
 	NULL},
{"q_dot_pc_min", (getter)Outputs_get_q_dot_pc_min,(setter)0,
	"Thermal power for PC min operation [MWt], array.",
 	NULL},
{"q_dot_pc_sb", (getter)Outputs_get_q_dot_pc_sb,(setter)0,
	"Thermal power for PC standby [MWt], array.",
 	NULL},
{"q_dot_pc_startup", (getter)Outputs_get_q_dot_pc_startup,(setter)0,
	"PC startup thermal power [MWt], array.",
 	NULL},
{"q_dot_pc_target", (getter)Outputs_get_q_dot_pc_target,(setter)0,
	"Target thermal power to PC [MWt], array.",
 	NULL},
{"q_dot_rec_inc", (getter)Outputs_get_q_dot_rec_inc,(setter)0,
	"Receiver incident thermal power [MWt], array.",
 	NULL},
{"q_heater", (getter)Outputs_get_q_heater,(setter)0,
	"TES freeze protection power [MWe], array.",
 	NULL},
{"q_pb", (getter)Outputs_get_q_pb,(setter)0,
	"PC input energy [MWt], array.",
 	NULL},
{"q_pc_startup", (getter)Outputs_get_q_pc_startup,(setter)0,
	"PC startup thermal energy [MWht], array.",
 	NULL},
{"q_piping_losses", (getter)Outputs_get_q_piping_losses,(setter)0,
	"Receiver header/tower piping losses [MWt], array.",
 	NULL},
{"q_sf_inc", (getter)Outputs_get_q_sf_inc,(setter)0,
	"Field incident thermal power [MWt], array.",
 	NULL},
{"q_startup", (getter)Outputs_get_q_startup,(setter)0,
	"Receiver startup thermal energy consumed [MWt], array.",
 	NULL},
{"q_thermal_loss", (getter)Outputs_get_q_thermal_loss,(setter)0,
	"Receiver convection and emission losses [MWt], array.",
 	NULL},
{"rh", (getter)Outputs_get_rh,(setter)0,
	"Resource relative humidity [%], array.",
 	NULL},
{"sf_adjust_out", (getter)Outputs_get_sf_adjust_out,(setter)0,
	"Field availability adjustment factor [], array.",
 	NULL},
{"solaz", (getter)Outputs_get_solaz,(setter)0,
	"Resource solar azimuth [deg], array.",
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	"Resource solar zenith [deg], array.",
 	NULL},
{"tank_losses", (getter)Outputs_get_tank_losses,(setter)0,
	"TES thermal losses [MWt], array.",
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	"Resource dry Bulb temperature [C], array.",
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	"Time at end of timestep [hr], array.",
 	NULL},
{"total_direct_cost", (getter)Outputs_get_total_direct_cost,(setter)0,
	"Total direct cost [$], number.",
 	NULL},
{"total_indirect_cost", (getter)Outputs_get_total_indirect_cost,(setter)0,
	"Total indirect cost [$], number.",
 	NULL},
{"total_installed_cost", (getter)Outputs_get_total_installed_cost,(setter)0,
	"Total installed cost [$], number.",
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	"CSP operating time-of-use value [], array.",
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	"Resource wet Bulb temperature [C], array.",
 	NULL},
{"ud_T_amb_ind_od_out", (getter)Outputs_get_ud_T_amb_ind_od_out,(setter)0,
	"T_amb cycle off design [], matrix.",
 	NULL},
{"ud_T_htf_ind_od_out", (getter)Outputs_get_ud_T_htf_ind_od_out,(setter)0,
	"T_htf_hot cycle off design [], matrix.",
 	NULL},
{"ud_m_dot_htf_ind_od_out", (getter)Outputs_get_ud_m_dot_htf_ind_od_out,(setter)0,
	"M_dot_htf cycle off design [], matrix.",
 	NULL},
{"ui_direct_subtotal", (getter)Outputs_get_ui_direct_subtotal,(setter)0,
	"Direct capital precontingency cost [$], number.",
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	"Resource wind velocity [m/s], array.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt.Outputs",             /*tp_name*/
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
 * TcsmoltenSalt
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_TcsmoltenSalt   data_ptr;
} TcsmoltenSaltObject;

static PyTypeObject TcsmoltenSalt_Type;

#define TcsmoltenSaltObject_Check(v)      (Py_TYPE(v) == &TcsmoltenSalt_Type)

static TcsmoltenSaltObject *
newTcsmoltenSaltObject(void* data_ptr)
{
	TcsmoltenSaltObject *self;
	self = PyObject_New(TcsmoltenSaltObject, &TcsmoltenSalt_Type);

	PySAM_TECH_ATTR("TcsmoltenSalt", SAM_TcsmoltenSalt_construct)

PyObject* LocationAndResource_obj = LocationAndResource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "LocationAndResource", LocationAndResource_obj);
	Py_DECREF(LocationAndResource_obj);

PyObject* TimeOfDeliveryFactors_obj = TimeOfDeliveryFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDeliveryFactors", TimeOfDeliveryFactors_obj);
	Py_DECREF(TimeOfDeliveryFactors_obj);

PyObject* HeliostatField_obj = HeliostatField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "HeliostatField", HeliostatField_obj);
	Py_DECREF(HeliostatField_obj);

PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

PyObject* TowerAndReceiver_obj = TowerAndReceiver_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TowerAndReceiver", TowerAndReceiver_obj);
	Py_DECREF(TowerAndReceiver_obj);

PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

PyObject* ThermalStorage_obj = ThermalStorage_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ThermalStorage", ThermalStorage_obj);
	Py_DECREF(ThermalStorage_obj);

PyObject* PowerCycle_obj = PowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PowerCycle", PowerCycle_obj);
	Py_DECREF(PowerCycle_obj);

PyObject* RankineCycle_obj = RankineCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "RankineCycle", RankineCycle_obj);
	Py_DECREF(RankineCycle_obj);

PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

PyObject* UserDefinedPowerCycle_obj = UserDefinedPowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "UserDefinedPowerCycle", UserDefinedPowerCycle_obj);
	Py_DECREF(UserDefinedPowerCycle_obj);

PyObject* SCO2Cycle_obj = SCO2Cycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SCO2Cycle", SCO2Cycle_obj);
	Py_DECREF(SCO2Cycle_obj);

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

/* TcsmoltenSalt methods */

static void
TcsmoltenSalt_dealloc(TcsmoltenSaltObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_TcsmoltenSalt_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
TcsmoltenSalt_execute(TcsmoltenSaltObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TcsmoltenSalt_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcsmoltenSalt_assign(TcsmoltenSaltObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict(self, self->x_attr, self->data_ptr, dict, "TcsmoltenSalt"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcsmoltenSalt_export(TcsmoltenSaltObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}


static PyMethodDef TcsmoltenSalt_methods[] = {
		{"execute",            (PyCFunction)TcsmoltenSalt_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcsmoltenSalt_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)TcsmoltenSalt_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcsmoltenSalt_getattro(TcsmoltenSaltObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcsmoltenSalt_setattr(TcsmoltenSaltObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcsmoltenSalt_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsmoltenSalt",            /*tp_name*/
		sizeof(TcsmoltenSaltObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TcsmoltenSalt_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TcsmoltenSalt_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TcsmoltenSalt_getattro, /*tp_getattro*/
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
		TcsmoltenSalt_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TcsmoltenSalt object */

static PyObject *
TcsmoltenSalt_new(PyObject *self, PyObject *args)
{
	TcsmoltenSaltObject *rv;
	rv = newTcsmoltenSaltObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsmoltenSalt_wrap(PyObject *self, PyObject *args)
{
	TcsmoltenSaltObject *rv;
	long int ptr = 0;
	if (!PyArg_ParseTuple(args, "l:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsmoltenSaltObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsmoltenSalt_default(PyObject *self, PyObject *args)
{
	TcsmoltenSaltObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsmoltenSaltObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults(rv, rv->x_attr, rv->data_ptr, "TcsmoltenSalt", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcsmoltenSaltModule_methods[] = {
		{"new",             TcsmoltenSalt_new,         METH_VARARGS,
				PyDoc_STR("new() -> new TcsmoltenSalt object")},
		{"wrap",             TcsmoltenSalt_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new TcsmoltenSalt object around existing data")},
		{"default",             TcsmoltenSalt_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new TcsmoltenSalt object with financial model-specific default attributes")},		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "This is a template module just for instruction.");


static int
TcsmoltenSaltModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	TcsmoltenSalt_Type.tp_dict = PyDict_New();
	if (!TcsmoltenSalt_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TcsmoltenSalt_Type
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
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the LocationAndResource type object to TcsmoltenSalt_Type
	if (PyType_Ready(&LocationAndResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"LocationAndResource",
				(PyObject*)&LocationAndResource_Type);
	Py_DECREF(&LocationAndResource_Type);

	/// Add the TimeOfDeliveryFactors type object to TcsmoltenSalt_Type
	if (PyType_Ready(&TimeOfDeliveryFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"TimeOfDeliveryFactors",
				(PyObject*)&TimeOfDeliveryFactors_Type);
	Py_DECREF(&TimeOfDeliveryFactors_Type);

	/// Add the HeliostatField type object to TcsmoltenSalt_Type
	if (PyType_Ready(&HeliostatField_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"HeliostatField",
				(PyObject*)&HeliostatField_Type);
	Py_DECREF(&HeliostatField_Type);

	/// Add the SystemDesign type object to TcsmoltenSalt_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the TowerAndReceiver type object to TcsmoltenSalt_Type
	if (PyType_Ready(&TowerAndReceiver_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"TowerAndReceiver",
				(PyObject*)&TowerAndReceiver_Type);
	Py_DECREF(&TowerAndReceiver_Type);

	/// Add the SystemCosts type object to TcsmoltenSalt_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the FinancialParameters type object to TcsmoltenSalt_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the ThermalStorage type object to TcsmoltenSalt_Type
	if (PyType_Ready(&ThermalStorage_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"ThermalStorage",
				(PyObject*)&ThermalStorage_Type);
	Py_DECREF(&ThermalStorage_Type);

	/// Add the PowerCycle type object to TcsmoltenSalt_Type
	if (PyType_Ready(&PowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"PowerCycle",
				(PyObject*)&PowerCycle_Type);
	Py_DECREF(&PowerCycle_Type);

	/// Add the RankineCycle type object to TcsmoltenSalt_Type
	if (PyType_Ready(&RankineCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"RankineCycle",
				(PyObject*)&RankineCycle_Type);
	Py_DECREF(&RankineCycle_Type);

	/// Add the SystemControl type object to TcsmoltenSalt_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the UserDefinedPowerCycle type object to TcsmoltenSalt_Type
	if (PyType_Ready(&UserDefinedPowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"UserDefinedPowerCycle",
				(PyObject*)&UserDefinedPowerCycle_Type);
	Py_DECREF(&UserDefinedPowerCycle_Type);

	/// Add the SCO2Cycle type object to TcsmoltenSalt_Type
	if (PyType_Ready(&SCO2Cycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"SCO2Cycle",
				(PyObject*)&SCO2Cycle_Type);
	Py_DECREF(&SCO2Cycle_Type);

	/// Add the Outputs type object to TcsmoltenSalt_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsmoltenSalt_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TcsmoltenSalt type object to the module
	if (PyType_Ready(&TcsmoltenSalt_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TcsmoltenSalt",
				(PyObject*)&TcsmoltenSalt_Type);

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TcsmoltenSaltModule_slots[] = {
		{Py_mod_exec, TcsmoltenSaltModule_exec},
		{0, NULL},
};

static struct PyModuleDef TcsmoltenSaltModule = {
		PyModuleDef_HEAD_INIT,
		"TcsmoltenSalt",
		module_doc,
		0,
		TcsmoltenSaltModule_methods,
		TcsmoltenSaltModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TcsmoltenSalt(void)
{
	return PyModuleDef_Init(&TcsmoltenSaltModule);
}