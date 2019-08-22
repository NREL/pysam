#include <Python.h>

#include <SAM_TroughPhysical.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} WeatherObject;

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Weather")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Weather_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_file_name(WeatherObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysical_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(WeatherObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysical_Weather_file_name_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: Local weather file with path [none]\n\n*Constraints*: LOCAL_FILE\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Weather",             /*tp_name*/
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
 * SolarField Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} SolarFieldObject;

static PyTypeObject SolarField_Type;

static PyObject *
SolarField_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = SolarField_Type.tp_alloc(&SolarField_Type,0);

	SolarFieldObject* SolarField_obj = (SolarFieldObject*)new_obj;

	SolarField_obj->data_ptr = data_ptr;

	return new_obj;
}

/* SolarField methods */

static PyObject *
SolarField_assign(SolarFieldObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "SolarField")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarField_export(SolarFieldObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarField_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarField_methods[] = {
		{"assign",            (PyCFunction)SolarField_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SolarField_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarField_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarField_get_A_aperture(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_A_aperture_aget, self->data_ptr);
}

static int
SolarField_set_A_aperture(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_A_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_AbsorberMaterial(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_AbsorberMaterial_mget, self->data_ptr);
}

static int
SolarField_set_AbsorberMaterial(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
SolarField_get_AnnulusGas(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_AnnulusGas_mget, self->data_ptr);
}

static int
SolarField_set_AnnulusGas(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Ave_Focal_Length(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Ave_Focal_Length_aget, self->data_ptr);
}

static int
SolarField_set_Ave_Focal_Length(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Ave_Focal_Length_aset, self->data_ptr);
}

static PyObject *
SolarField_get_ColperSCA(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_ColperSCA_aget, self->data_ptr);
}

static int
SolarField_set_ColperSCA(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_ColperSCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_D_2(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_2_mget, self->data_ptr);
}

static int
SolarField_set_D_2(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_2_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_3(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_3_mget, self->data_ptr);
}

static int
SolarField_set_D_3(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_3_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_4(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_4_mget, self->data_ptr);
}

static int
SolarField_set_D_4(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_5(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_5_mget, self->data_ptr);
}

static int
SolarField_set_D_5(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_cpnt(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_D_cpnt(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_p(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_D_p_mget, self->data_ptr);
}

static int
SolarField_set_D_p(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_D_p_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Design_loss(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Design_loss_mget, self->data_ptr);
}

static int
SolarField_set_Design_loss(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Design_loss_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_HCE(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Dirt_HCE_mget, self->data_ptr);
}

static int
SolarField_set_Dirt_HCE(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_mirror(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Dirt_mirror_aget, self->data_ptr);
}

static int
SolarField_set_Dirt_mirror(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Dirt_mirror_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Distance_SCA(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Distance_SCA_aget, self->data_ptr);
}

static int
SolarField_set_Distance_SCA(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Distance_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_4(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_EPSILON_4_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_4(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_5(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_EPSILON_5_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_5(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_EPSILON_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Error(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Error_aget, self->data_ptr);
}

static int
SolarField_set_Error(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Error_aset, self->data_ptr);
}

static PyObject *
SolarField_get_FieldConfig(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_FieldConfig_nget, self->data_ptr);
}

static int
SolarField_set_FieldConfig(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_FieldConfig_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Flow_type(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Flow_type_mget, self->data_ptr);
}

static int
SolarField_set_Flow_type(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Flow_type_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Fluid(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Fluid_nget, self->data_ptr);
}

static int
SolarField_set_Fluid(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Fluid_nset, self->data_ptr);
}

static PyObject *
SolarField_get_GeomEffects(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_GeomEffects_aget, self->data_ptr);
}

static int
SolarField_set_GeomEffects(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_GeomEffects_aset, self->data_ptr);
}

static PyObject *
SolarField_get_GlazingIntactIn(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_GlazingIntactIn_mget, self->data_ptr);
}

static int
SolarField_set_GlazingIntactIn(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HCE_FieldFrac(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_HCE_FieldFrac_mget, self->data_ptr);
}

static int
SolarField_set_HCE_FieldFrac(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HDR_rough(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_HDR_rough_nget, self->data_ptr);
}

static int
SolarField_set_HDR_rough(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_HDR_rough_nset, self->data_ptr);
}

static PyObject *
SolarField_get_IAM_matrix(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_IAM_matrix_mget, self->data_ptr);
}

static int
SolarField_set_IAM_matrix(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_IAM_matrix_mset, self->data_ptr);
}

static PyObject *
SolarField_get_I_bn_des(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_I_bn_des_nget, self->data_ptr);
}

static int
SolarField_set_I_bn_des(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_I_bn_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_K_cpnt(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_K_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_K_cpnt(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_K_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_L_SCA(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_L_SCA_aget, self->data_ptr);
}

static int
SolarField_set_L_SCA(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_L_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_aperture(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_L_aperture_aget, self->data_ptr);
}

static int
SolarField_set_L_aperture(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_L_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_cpnt(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_L_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_L_cpnt(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_L_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_L_power_block_piping(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_power_block_piping_nget, self->data_ptr);
}

static int
SolarField_set_L_power_block_piping(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_power_block_piping_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_rnr_per_xpan(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_rnr_per_xpan_nget, self->data_ptr);
}

static int
SolarField_set_L_rnr_per_xpan(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_rnr_per_xpan_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_xpan_hdr(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_xpan_hdr_nget, self->data_ptr);
}

static int
SolarField_set_L_xpan_hdr(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_xpan_hdr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_xpan_rnr(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_L_xpan_rnr_nget, self->data_ptr);
}

static int
SolarField_set_L_xpan_rnr(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_L_xpan_rnr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Min_rnr_xpans(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Min_rnr_xpans_nget, self->data_ptr);
}

static int
SolarField_set_Min_rnr_xpans(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Min_rnr_xpans_nset, self->data_ptr);
}

static PyObject *
SolarField_get_N_hdr_per_xpan(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_N_hdr_per_xpan_nget, self->data_ptr);
}

static int
SolarField_set_N_hdr_per_xpan(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_N_hdr_per_xpan_nset, self->data_ptr);
}

static PyObject *
SolarField_get_N_max_hdr_diams(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_N_max_hdr_diams_nget, self->data_ptr);
}

static int
SolarField_set_N_max_hdr_diams(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_N_max_hdr_diams_nset, self->data_ptr);
}

static PyObject *
SolarField_get_P_a(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_P_a_mget, self->data_ptr);
}

static int
SolarField_set_P_a(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_P_a_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Pipe_hl_coef(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Pipe_hl_coef_nget, self->data_ptr);
}

static int
SolarField_set_Pipe_hl_coef(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Rho_mirror_clean(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_Rho_mirror_clean_aget, self->data_ptr);
}

static int
SolarField_set_Rho_mirror_clean(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_Rho_mirror_clean_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Rough(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Rough_mget, self->data_ptr);
}

static int
SolarField_set_Rough(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Rough_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Row_Distance(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_Row_Distance_nget, self->data_ptr);
}

static int
SolarField_set_Row_Distance(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_Row_Distance_nset, self->data_ptr);
}

static PyObject *
SolarField_get_SCADefocusArray(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_SCADefocusArray_aget, self->data_ptr);
}

static int
SolarField_set_SCADefocusArray(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_SCADefocusArray_aset, self->data_ptr);
}

static PyObject *
SolarField_get_SCAInfoArray(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_SCAInfoArray_mget, self->data_ptr);
}

static int
SolarField_set_SCAInfoArray(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_SCAInfoArray_mset, self->data_ptr);
}

static PyObject *
SolarField_get_SCA_drives_elec(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_SCA_drives_elec_nget, self->data_ptr);
}

static int
SolarField_set_SCA_drives_elec(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Shadowing(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Shadowing_mget, self->data_ptr);
}

static int
SolarField_set_Shadowing(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Shadowing_mset, self->data_ptr);
}

static PyObject *
SolarField_get_T_fp(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_fp_nget, self->data_ptr);
}

static int
SolarField_set_T_fp(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_fp_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_in_des(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_loop_in_des_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_in_des(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_out(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_T_loop_out_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_out(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_T_loop_out_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Tau_envelope(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Tau_envelope_mget, self->data_ptr);
}

static int
SolarField_set_Tau_envelope(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
SolarField_get_TrackingError(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_TrackingError_aget, self->data_ptr);
}

static int
SolarField_set_TrackingError(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_TrackingError_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Type_cpnt(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_Type_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_Type_cpnt(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_Type_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_cold_max(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_cold_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_cold_max(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_cold_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_cold_min(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_cold_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_cold_min(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_cold_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_hot_max(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_hot_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_hot_max(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_hot_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_hot_min(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_V_hdr_hot_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_hot_min(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_V_hdr_hot_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_W_aperture(SolarFieldObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_SolarField_W_aperture_aget, self->data_ptr);
}

static int
SolarField_set_W_aperture(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_SolarField_W_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_init(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_accept_init_nget, self->data_ptr);
}

static int
SolarField_set_accept_init(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_accept_init_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_loc(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_accept_loc_nget, self->data_ptr);
}

static int
SolarField_set_accept_loc(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_accept_loc_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_mode(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_accept_mode_nget, self->data_ptr);
}

static int
SolarField_set_accept_mode(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_accept_mode_nset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_abs(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_alpha_abs_mget, self->data_ptr);
}

static int
SolarField_set_alpha_abs(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_alpha_abs_mset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_env(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_alpha_env_mget, self->data_ptr);
}

static int
SolarField_set_alpha_env(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_alpha_env_mset, self->data_ptr);
}

static PyObject *
SolarField_get_azimuth(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_azimuth_nget, self->data_ptr);
}

static int
SolarField_set_azimuth(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_azimuth_nset, self->data_ptr);
}

static PyObject *
SolarField_get_calc_design_pipe_vals(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_calc_design_pipe_vals_nget, self->data_ptr);
}

static int
SolarField_set_calc_design_pipe_vals(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_calc_design_pipe_vals_nset, self->data_ptr);
}

static PyObject *
SolarField_get_custom_sf_pipe_sizes(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_custom_sf_pipe_sizes_nget, self->data_ptr);
}

static int
SolarField_set_custom_sf_pipe_sizes(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_custom_sf_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_11(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_11_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_11(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_11_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_12(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_12_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_12(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_12_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_13(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_13_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_13(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_13_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_14(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_14_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_14(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_14_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_21(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_21_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_21(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_21_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_22(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_22_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_22(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_22_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_23(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_23_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_23(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_23_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_24(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_24_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_24(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_24_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_31(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_31_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_31(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_31_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_32(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_32_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_32(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_32_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_33(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_33_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_33(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_33_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_34(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_34_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_34(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_34_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_41(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_41_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_41(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_41_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_42(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_42_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_42(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_42_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_43(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_43_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_43(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_43_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_44(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_epsilon_3_44_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_44(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_epsilon_3_44_mset, self->data_ptr);
}

static PyObject *
SolarField_get_eta_pump(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_eta_pump_nget, self->data_ptr);
}

static int
SolarField_set_eta_pump(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_eta_pump_nset, self->data_ptr);
}

static PyObject *
SolarField_get_field_fl_props(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_field_fl_props_mget, self->data_ptr);
}

static int
SolarField_set_field_fl_props(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_field_fl_props_mset, self->data_ptr);
}

static PyObject *
SolarField_get_include_fixed_power_block_runner(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_include_fixed_power_block_runner_nget, self->data_ptr);
}

static int
SolarField_set_include_fixed_power_block_runner(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_include_fixed_power_block_runner_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmax(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_m_dot_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmax(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_m_dot_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmin(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_m_dot_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmin(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_m_dot_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_cold(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_mc_bal_cold_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_cold(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_mc_bal_cold_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_hot(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_mc_bal_hot_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_hot(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_mc_bal_hot_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_sca(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_mc_bal_sca_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_sca(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_mc_bal_sca_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nColt(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nColt_nget, self->data_ptr);
}

static int
SolarField_set_nColt(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nColt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEVar(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nHCEVar_nget, self->data_ptr);
}

static int
SolarField_set_nHCEVar(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nHCEVar_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEt(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nHCEt_nget, self->data_ptr);
}

static int
SolarField_set_nHCEt(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nHCEt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nLoops(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nLoops_nget, self->data_ptr);
}

static int
SolarField_set_nLoops(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nLoops_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nSCA(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_nSCA_nget, self->data_ptr);
}

static int
SolarField_set_nSCA(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_nSCA_nset, self->data_ptr);
}

static PyObject *
SolarField_get_northsouth_field_sep(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_northsouth_field_sep_nget, self->data_ptr);
}

static int
SolarField_set_northsouth_field_sep(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_northsouth_field_sep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_offset_xpan_hdr(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_offset_xpan_hdr_nget, self->data_ptr);
}

static int
SolarField_set_offset_xpan_hdr(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_offset_xpan_hdr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_p_start(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_p_start_nget, self->data_ptr);
}

static int
SolarField_set_p_start(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_p_start_nset, self->data_ptr);
}

static PyObject *
SolarField_get_rec_qf_delay(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_rec_qf_delay_nget, self->data_ptr);
}

static int
SolarField_set_rec_qf_delay(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_rec_qf_delay_nset, self->data_ptr);
}

static PyObject *
SolarField_get_rec_su_delay(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_rec_su_delay_nget, self->data_ptr);
}

static int
SolarField_set_rec_su_delay(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_rec_su_delay_nset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_diams(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_hdr_diams_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_diams(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_hdr_diams_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_lengths(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_hdr_lengths_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_lengths(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_hdr_lengths_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_wallthicks(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_hdr_wallthicks_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_wallthicks(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_hdr_wallthicks_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_diams(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_rnr_diams_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_diams(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_rnr_diams_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_lengths(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_rnr_lengths_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_lengths(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_rnr_lengths_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_wallthicks(SolarFieldObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_SolarField_sf_rnr_wallthicks_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_wallthicks(SolarFieldObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_SolarField_sf_rnr_wallthicks_mset, self->data_ptr);
}

static PyObject *
SolarField_get_solar_mult(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_solar_mult_nget, self->data_ptr);
}

static int
SolarField_set_solar_mult(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_solar_mult_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_dep(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_theta_dep_nget, self->data_ptr);
}

static int
SolarField_set_theta_dep(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_theta_dep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_stow(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_theta_stow_nget, self->data_ptr);
}

static int
SolarField_set_theta_stow(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_theta_stow_nset, self->data_ptr);
}

static PyObject *
SolarField_get_tilt(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_tilt_nget, self->data_ptr);
}

static int
SolarField_set_tilt(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_tilt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_wind_stow_speed(SolarFieldObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_SolarField_wind_stow_speed_nget, self->data_ptr);
}

static int
SolarField_set_wind_stow_speed(SolarFieldObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_SolarField_wind_stow_speed_nset, self->data_ptr);
}

static PyGetSetDef SolarField_getset[] = {
{"A_aperture", (getter)SolarField_get_A_aperture,(setter)SolarField_set_A_aperture,
	PyDoc_STR("*sequence*: Reflective aperture area of the collector [m2]\n\n*Required*: True"),
 	NULL},
{"AbsorberMaterial", (getter)SolarField_get_AbsorberMaterial,(setter)SolarField_set_AbsorberMaterial,
	PyDoc_STR("*sequence[sequence]*: Absorber material type [none]\n\n*Required*: True"),
 	NULL},
{"AnnulusGas", (getter)SolarField_get_AnnulusGas,(setter)SolarField_set_AnnulusGas,
	PyDoc_STR("*sequence[sequence]*: Annulus gas type (1=air, 26=Ar, 27=H2) [none]\n\n*Required*: True"),
 	NULL},
{"Ave_Focal_Length", (getter)SolarField_get_Ave_Focal_Length,(setter)SolarField_set_Ave_Focal_Length,
	PyDoc_STR("*sequence*: Average focal length of the collector  [m]\n\n*Required*: True"),
 	NULL},
{"ColperSCA", (getter)SolarField_get_ColperSCA,(setter)SolarField_set_ColperSCA,
	PyDoc_STR("*sequence*: Number of individual collector sections in an SCA  [none]\n\n*Required*: True"),
 	NULL},
{"D_2", (getter)SolarField_get_D_2,(setter)SolarField_set_D_2,
	PyDoc_STR("*sequence[sequence]*: Inner absorber tube diameter [m]\n\n*Required*: True"),
 	NULL},
{"D_3", (getter)SolarField_get_D_3,(setter)SolarField_set_D_3,
	PyDoc_STR("*sequence[sequence]*: Outer absorber tube diameter [m]\n\n*Required*: True"),
 	NULL},
{"D_4", (getter)SolarField_get_D_4,(setter)SolarField_set_D_4,
	PyDoc_STR("*sequence[sequence]*: Inner glass envelope diameter  [m]\n\n*Required*: True"),
 	NULL},
{"D_5", (getter)SolarField_get_D_5,(setter)SolarField_set_D_5,
	PyDoc_STR("*sequence[sequence]*: Outer glass envelope diameter  [m]\n\n*Required*: True"),
 	NULL},
{"D_cpnt", (getter)SolarField_get_D_cpnt,(setter)SolarField_set_D_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component diameters, row=intc, col=cpnt [none]\n\n*Required*: True"),
 	NULL},
{"D_p", (getter)SolarField_get_D_p,(setter)SolarField_set_D_p,
	PyDoc_STR("*sequence[sequence]*: Diameter of the absorber flow plug (optional)  [m]\n\n*Required*: True"),
 	NULL},
{"Design_loss", (getter)SolarField_get_Design_loss,(setter)SolarField_set_Design_loss,
	PyDoc_STR("*sequence[sequence]*: Receiver heat loss at design [W/m]\n\n*Required*: True"),
 	NULL},
{"Dirt_HCE", (getter)SolarField_get_Dirt_HCE,(setter)SolarField_set_Dirt_HCE,
	PyDoc_STR("*sequence[sequence]*: Loss due to dirt on the receiver envelope [none]\n\n*Required*: True"),
 	NULL},
{"Dirt_mirror", (getter)SolarField_get_Dirt_mirror,(setter)SolarField_set_Dirt_mirror,
	PyDoc_STR("*sequence*: User-defined dirt on mirror derate [none]\n\n*Required*: True"),
 	NULL},
{"Distance_SCA", (getter)SolarField_get_Distance_SCA,(setter)SolarField_set_Distance_SCA,
	PyDoc_STR("*sequence*: Piping distance between SCA's in the field [m]\n\n*Required*: True"),
 	NULL},
{"EPSILON_4", (getter)SolarField_get_EPSILON_4,(setter)SolarField_set_EPSILON_4,
	PyDoc_STR("*sequence[sequence]*: Inner glass envelope emissivities (Pyrex)  [none]\n\n*Required*: True"),
 	NULL},
{"EPSILON_5", (getter)SolarField_get_EPSILON_5,(setter)SolarField_set_EPSILON_5,
	PyDoc_STR("*sequence[sequence]*: Outer glass envelope emissivities (Pyrex)  [none]\n\n*Required*: True"),
 	NULL},
{"Error", (getter)SolarField_get_Error,(setter)SolarField_set_Error,
	PyDoc_STR("*sequence*: User-defined general optical error derate  [none]\n\n*Required*: True"),
 	NULL},
{"FieldConfig", (getter)SolarField_get_FieldConfig,(setter)SolarField_set_FieldConfig,
	PyDoc_STR("*float*: Number of subfield headers [none]\n\n*Required*: True"),
 	NULL},
{"Flow_type", (getter)SolarField_get_Flow_type,(setter)SolarField_set_Flow_type,
	PyDoc_STR("*sequence[sequence]*: Flow type through the absorber [none]\n\n*Required*: True"),
 	NULL},
{"Fluid", (getter)SolarField_get_Fluid,(setter)SolarField_set_Fluid,
	PyDoc_STR("*float*: Field HTF fluid ID number [none]\n\n*Required*: True"),
 	NULL},
{"GeomEffects", (getter)SolarField_get_GeomEffects,(setter)SolarField_set_GeomEffects,
	PyDoc_STR("*sequence*: User-defined geometry effects derate [none]\n\n*Required*: True"),
 	NULL},
{"GlazingIntactIn", (getter)SolarField_get_GlazingIntactIn,(setter)SolarField_set_GlazingIntactIn,
	PyDoc_STR("*sequence[sequence]*: Glazing intact (broken glass) flag {1=true, else=false} [none]\n\n*Required*: True"),
 	NULL},
{"HCE_FieldFrac", (getter)SolarField_get_HCE_FieldFrac,(setter)SolarField_set_HCE_FieldFrac,
	PyDoc_STR("*sequence[sequence]*: Fraction of the field occupied by this HCE type  [none]\n\n*Required*: True"),
 	NULL},
{"HDR_rough", (getter)SolarField_get_HDR_rough,(setter)SolarField_set_HDR_rough,
	PyDoc_STR("*float*: Header pipe roughness [m]\n\n*Required*: True"),
 	NULL},
{"IAM_matrix", (getter)SolarField_get_IAM_matrix,(setter)SolarField_set_IAM_matrix,
	PyDoc_STR("*sequence[sequence]*: IAM coefficients, matrix for 4 collectors [none]\n\n*Required*: True"),
 	NULL},
{"I_bn_des", (getter)SolarField_get_I_bn_des,(setter)SolarField_set_I_bn_des,
	PyDoc_STR("*float*: Solar irradiation at design [C]\n\n*Required*: True"),
 	NULL},
{"K_cpnt", (getter)SolarField_get_K_cpnt,(setter)SolarField_set_K_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component minor loss coefficients, row=intc, col=cpnt [none]\n\n*Required*: True"),
 	NULL},
{"L_SCA", (getter)SolarField_get_L_SCA,(setter)SolarField_set_L_SCA,
	PyDoc_STR("*sequence*: Length of the SCA  [m]\n\n*Required*: True"),
 	NULL},
{"L_aperture", (getter)SolarField_get_L_aperture,(setter)SolarField_set_L_aperture,
	PyDoc_STR("*sequence*: Length of a single mirror/HCE unit [m]\n\n*Required*: True"),
 	NULL},
{"L_cpnt", (getter)SolarField_get_L_cpnt,(setter)SolarField_set_L_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component lengths, row=intc, col=cpnt [none]\n\n*Required*: True"),
 	NULL},
{"L_power_block_piping", (getter)SolarField_get_L_power_block_piping,(setter)SolarField_set_L_power_block_piping,
	PyDoc_STR("*float*: Length of piping (full mass flow) through heat sink (if applicable) [none]\n\n*Required*: True"),
 	NULL},
{"L_rnr_per_xpan", (getter)SolarField_get_L_rnr_per_xpan,(setter)SolarField_set_L_rnr_per_xpan,
	PyDoc_STR("*float*: Threshold length of straight runner pipe without an expansion loop [m]\n\n*Required*: True"),
 	NULL},
{"L_xpan_hdr", (getter)SolarField_get_L_xpan_hdr,(setter)SolarField_set_L_xpan_hdr,
	PyDoc_STR("*float*: Compined perpendicular lengths of each header expansion loop [m]\n\n*Required*: True"),
 	NULL},
{"L_xpan_rnr", (getter)SolarField_get_L_xpan_rnr,(setter)SolarField_set_L_xpan_rnr,
	PyDoc_STR("*float*: Compined perpendicular lengths of each runner expansion loop [m]\n\n*Required*: True"),
 	NULL},
{"Min_rnr_xpans", (getter)SolarField_get_Min_rnr_xpans,(setter)SolarField_set_Min_rnr_xpans,
	PyDoc_STR("*float*: Minimum number of expansion loops per single-diameter runner section [none]\n\n*Required*: True"),
 	NULL},
{"N_hdr_per_xpan", (getter)SolarField_get_N_hdr_per_xpan,(setter)SolarField_set_N_hdr_per_xpan,
	PyDoc_STR("*float*: Number of collector loops per expansion loop [none]\n\n*Required*: True"),
 	NULL},
{"N_max_hdr_diams", (getter)SolarField_get_N_max_hdr_diams,(setter)SolarField_set_N_max_hdr_diams,
	PyDoc_STR("*float*: Maximum number of diameters in each of the hot and cold headers [none]\n\n*Required*: True"),
 	NULL},
{"P_a", (getter)SolarField_get_P_a,(setter)SolarField_set_P_a,
	PyDoc_STR("*sequence[sequence]*: Annulus gas pressure [torr]\n\n*Required*: True"),
 	NULL},
{"Pipe_hl_coef", (getter)SolarField_get_Pipe_hl_coef,(setter)SolarField_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header, runner pipe, and non-HCE piping [m/s]\n\n*Required*: True"),
 	NULL},
{"Rho_mirror_clean", (getter)SolarField_get_Rho_mirror_clean,(setter)SolarField_set_Rho_mirror_clean,
	PyDoc_STR("*sequence*: User-defined clean mirror reflectivity [none]\n\n*Required*: True"),
 	NULL},
{"Rough", (getter)SolarField_get_Rough,(setter)SolarField_set_Rough,
	PyDoc_STR("*sequence[sequence]*: Roughness of the internal surface  [m]\n\n*Required*: True"),
 	NULL},
{"Row_Distance", (getter)SolarField_get_Row_Distance,(setter)SolarField_set_Row_Distance,
	PyDoc_STR("*float*: Spacing between rows (centerline to centerline) [m]\n\n*Required*: True"),
 	NULL},
{"SCADefocusArray", (getter)SolarField_get_SCADefocusArray,(setter)SolarField_set_SCADefocusArray,
	PyDoc_STR("*sequence*: Collector defocus order [none]\n\n*Required*: True"),
 	NULL},
{"SCAInfoArray", (getter)SolarField_get_SCAInfoArray,(setter)SolarField_set_SCAInfoArray,
	PyDoc_STR("*sequence[sequence]*: Receiver (,1) and collector (,2) type for each assembly in loop [none]\n\n*Required*: True"),
 	NULL},
{"SCA_drives_elec", (getter)SolarField_get_SCA_drives_elec,(setter)SolarField_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power, in Watts per SCA drive [W/m2-K]\n\n*Required*: True"),
 	NULL},
{"Shadowing", (getter)SolarField_get_Shadowing,(setter)SolarField_set_Shadowing,
	PyDoc_STR("*sequence[sequence]*: Receiver bellows shadowing loss factor [none]\n\n*Required*: True"),
 	NULL},
{"T_fp", (getter)SolarField_get_T_fp,(setter)SolarField_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [none]\n\n*Required*: True"),
 	NULL},
{"T_loop_in_des", (getter)SolarField_get_T_loop_in_des,(setter)SolarField_set_T_loop_in_des,
	PyDoc_STR("*float*: Design loop inlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"T_loop_out", (getter)SolarField_get_T_loop_out,(setter)SolarField_set_T_loop_out,
	PyDoc_STR("*float*: Target loop outlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"Tau_envelope", (getter)SolarField_get_Tau_envelope,(setter)SolarField_set_Tau_envelope,
	PyDoc_STR("*sequence[sequence]*: Envelope transmittance [none]\n\n*Required*: True"),
 	NULL},
{"TrackingError", (getter)SolarField_get_TrackingError,(setter)SolarField_set_TrackingError,
	PyDoc_STR("*sequence*: User-defined tracking error derate [none]\n\n*Required*: True"),
 	NULL},
{"Type_cpnt", (getter)SolarField_get_Type_cpnt,(setter)SolarField_set_Type_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component type, row=intc, col=cpnt [none]\n\n*Required*: True"),
 	NULL},
{"V_hdr_cold_max", (getter)SolarField_get_V_hdr_cold_max,(setter)SolarField_set_V_hdr_cold_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the cold headers at design [m/s]\n\n*Required*: True"),
 	NULL},
{"V_hdr_cold_min", (getter)SolarField_get_V_hdr_cold_min,(setter)SolarField_set_V_hdr_cold_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the cold headers at design [m/s]\n\n*Required*: True"),
 	NULL},
{"V_hdr_hot_max", (getter)SolarField_get_V_hdr_hot_max,(setter)SolarField_set_V_hdr_hot_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the hot headers at design [m/s]\n\n*Required*: True"),
 	NULL},
{"V_hdr_hot_min", (getter)SolarField_get_V_hdr_hot_min,(setter)SolarField_set_V_hdr_hot_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the hot headers at design [m/s]\n\n*Required*: True"),
 	NULL},
{"W_aperture", (getter)SolarField_get_W_aperture,(setter)SolarField_set_W_aperture,
	PyDoc_STR("*sequence*: The collector aperture width (Total structural area used for shadowing) [m]\n\n*Required*: True"),
 	NULL},
{"accept_init", (getter)SolarField_get_accept_init,(setter)SolarField_set_accept_init,
	PyDoc_STR("*float*: In acceptance testing mode - require steady-state startup [none]\n\n*Required*: True"),
 	NULL},
{"accept_loc", (getter)SolarField_get_accept_loc,(setter)SolarField_set_accept_loc,
	PyDoc_STR("*float*: In acceptance testing mode - temperature sensor location [1/2]\n\n*Info*: hx/loop\n\n*Required*: True"),
 	NULL},
{"accept_mode", (getter)SolarField_get_accept_mode,(setter)SolarField_set_accept_mode,
	PyDoc_STR("*float*: Acceptance testing mode? [0/1]\n\n*Info*: no/yes\n\n*Required*: True"),
 	NULL},
{"alpha_abs", (getter)SolarField_get_alpha_abs,(setter)SolarField_set_alpha_abs,
	PyDoc_STR("*sequence[sequence]*: Absorber absorptance  [none]\n\n*Required*: True"),
 	NULL},
{"alpha_env", (getter)SolarField_get_alpha_env,(setter)SolarField_set_alpha_env,
	PyDoc_STR("*sequence[sequence]*: Envelope absorptance  [none]\n\n*Required*: True"),
 	NULL},
{"azimuth", (getter)SolarField_get_azimuth,(setter)SolarField_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle of surface/axis [none]\n\n*Required*: True"),
 	NULL},
{"calc_design_pipe_vals", (getter)SolarField_get_calc_design_pipe_vals,(setter)SolarField_set_calc_design_pipe_vals,
	PyDoc_STR("*float*: Calculate temps and pressures at design conditions for runners and headers [none]\n\n*Required*: True"),
 	NULL},
{"custom_sf_pipe_sizes", (getter)SolarField_get_custom_sf_pipe_sizes,(setter)SolarField_set_custom_sf_pipe_sizes,
	PyDoc_STR("*float*: Use custom solar field pipe diams, wallthks, and lengths [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_11", (getter)SolarField_get_epsilon_3_11,(setter)SolarField_set_epsilon_3_11,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 1 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_12", (getter)SolarField_get_epsilon_3_12,(setter)SolarField_set_epsilon_3_12,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 2 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_13", (getter)SolarField_get_epsilon_3_13,(setter)SolarField_set_epsilon_3_13,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 3 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_14", (getter)SolarField_get_epsilon_3_14,(setter)SolarField_set_epsilon_3_14,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 1 variation 4 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_21", (getter)SolarField_get_epsilon_3_21,(setter)SolarField_set_epsilon_3_21,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 1 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_22", (getter)SolarField_get_epsilon_3_22,(setter)SolarField_set_epsilon_3_22,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 2 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_23", (getter)SolarField_get_epsilon_3_23,(setter)SolarField_set_epsilon_3_23,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 3 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_24", (getter)SolarField_get_epsilon_3_24,(setter)SolarField_set_epsilon_3_24,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 2 variation 4 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_31", (getter)SolarField_get_epsilon_3_31,(setter)SolarField_set_epsilon_3_31,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 1 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_32", (getter)SolarField_get_epsilon_3_32,(setter)SolarField_set_epsilon_3_32,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 2 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_33", (getter)SolarField_get_epsilon_3_33,(setter)SolarField_set_epsilon_3_33,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 3 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_34", (getter)SolarField_get_epsilon_3_34,(setter)SolarField_set_epsilon_3_34,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 3 variation 4 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_41", (getter)SolarField_get_epsilon_3_41,(setter)SolarField_set_epsilon_3_41,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 1 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_42", (getter)SolarField_get_epsilon_3_42,(setter)SolarField_set_epsilon_3_42,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 2 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_43", (getter)SolarField_get_epsilon_3_43,(setter)SolarField_set_epsilon_3_43,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 3 [none]\n\n*Required*: True"),
 	NULL},
{"epsilon_3_44", (getter)SolarField_get_epsilon_3_44,(setter)SolarField_set_epsilon_3_44,
	PyDoc_STR("*sequence[sequence]*: Absorber emittance for receiver type 4 variation 4 [none]\n\n*Required*: True"),
 	NULL},
{"eta_pump", (getter)SolarField_get_eta_pump,(setter)SolarField_set_eta_pump,
	PyDoc_STR("*float*: HTF pump efficiency [none]\n\n*Required*: True"),
 	NULL},
{"field_fl_props", (getter)SolarField_get_field_fl_props,(setter)SolarField_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n*Required*: True"),
 	NULL},
{"include_fixed_power_block_runner", (getter)SolarField_get_include_fixed_power_block_runner,(setter)SolarField_set_include_fixed_power_block_runner,
	PyDoc_STR("*float*: Should model consider piping through power block? [none]\n\n*Required*: True"),
 	NULL},
{"m_dot_htfmax", (getter)SolarField_get_m_dot_htfmax,(setter)SolarField_set_m_dot_htfmax,
	PyDoc_STR("*float*: Maximum loop HTF flow rate [kg/s]\n\n*Required*: True"),
 	NULL},
{"m_dot_htfmin", (getter)SolarField_get_m_dot_htfmin,(setter)SolarField_set_m_dot_htfmin,
	PyDoc_STR("*float*: Minimum loop HTF flow rate [kg/s]\n\n*Required*: True"),
 	NULL},
{"mc_bal_cold", (getter)SolarField_get_mc_bal_cold,(setter)SolarField_set_mc_bal_cold,
	PyDoc_STR("*float*: Heat capacity of the balance of plant on the cold side [kWht/K-MWt]\n\n*Required*: True"),
 	NULL},
{"mc_bal_hot", (getter)SolarField_get_mc_bal_hot,(setter)SolarField_set_mc_bal_hot,
	PyDoc_STR("*float*: Heat capacity of the balance of plant on the hot side [kWht/K-MWt]\n\n*Info*: none\n\n*Required*: True"),
 	NULL},
{"mc_bal_sca", (getter)SolarField_get_mc_bal_sca,(setter)SolarField_set_mc_bal_sca,
	PyDoc_STR("*float*: Non-HTF heat capacity associated with each SCA - per meter basis [Wht/K-m]\n\n*Required*: True"),
 	NULL},
{"nColt", (getter)SolarField_get_nColt,(setter)SolarField_set_nColt,
	PyDoc_STR("*float*: Number of collector types [none]\n\n*Options*: constant=4\n\n*Required*: True"),
 	NULL},
{"nHCEVar", (getter)SolarField_get_nHCEVar,(setter)SolarField_set_nHCEVar,
	PyDoc_STR("*float*: Number of HCE variants per type [none]\n\n*Required*: True"),
 	NULL},
{"nHCEt", (getter)SolarField_get_nHCEt,(setter)SolarField_set_nHCEt,
	PyDoc_STR("*float*: Number of HCE types [none]\n\n*Required*: True"),
 	NULL},
{"nLoops", (getter)SolarField_get_nLoops,(setter)SolarField_set_nLoops,
	PyDoc_STR("*float*: Number of loops in the field [none]\n\n*Required*: True"),
 	NULL},
{"nSCA", (getter)SolarField_get_nSCA,(setter)SolarField_set_nSCA,
	PyDoc_STR("*float*: Number of SCAs in a loop [none]\n\n*Required*: True"),
 	NULL},
{"northsouth_field_sep", (getter)SolarField_get_northsouth_field_sep,(setter)SolarField_set_northsouth_field_sep,
	PyDoc_STR("*float*: North/south separation between subfields. 0 = SCAs are touching [m]\n\n*Required*: True"),
 	NULL},
{"offset_xpan_hdr", (getter)SolarField_get_offset_xpan_hdr,(setter)SolarField_set_offset_xpan_hdr,
	PyDoc_STR("*float*: Location of first header expansion loop. 1 = after first collector loop [none]\n\n*Required*: True"),
 	NULL},
{"p_start", (getter)SolarField_get_p_start,(setter)SolarField_set_p_start,
	PyDoc_STR("*float*: Collector startup energy, per SCA [kWe-hr]\n\n*Required*: True"),
 	NULL},
{"rec_qf_delay", (getter)SolarField_get_rec_qf_delay,(setter)SolarField_set_rec_qf_delay,
	PyDoc_STR("*float*: Energy-based receiver startup delay (fraction of rated thermal power) [-]\n\n*Required*: True"),
 	NULL},
{"rec_su_delay", (getter)SolarField_get_rec_su_delay,(setter)SolarField_set_rec_su_delay,
	PyDoc_STR("*float*: Fixed startup delay time for the receiver [hr]\n\n*Required*: True"),
 	NULL},
{"sf_hdr_diams", (getter)SolarField_get_sf_hdr_diams,(setter)SolarField_set_sf_hdr_diams,
	PyDoc_STR("*sequence[sequence]*: Custom header diameters [m]\n\n*Required*: True"),
 	NULL},
{"sf_hdr_lengths", (getter)SolarField_get_sf_hdr_lengths,(setter)SolarField_set_sf_hdr_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom header lengths [m]\n\n*Required*: True"),
 	NULL},
{"sf_hdr_wallthicks", (getter)SolarField_get_sf_hdr_wallthicks,(setter)SolarField_set_sf_hdr_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom header wall thicknesses [m]\n\n*Required*: True"),
 	NULL},
{"sf_rnr_diams", (getter)SolarField_get_sf_rnr_diams,(setter)SolarField_set_sf_rnr_diams,
	PyDoc_STR("*sequence[sequence]*: Custom runner diameters [m]\n\n*Required*: True"),
 	NULL},
{"sf_rnr_lengths", (getter)SolarField_get_sf_rnr_lengths,(setter)SolarField_set_sf_rnr_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom runner lengths [m]\n\n*Required*: True"),
 	NULL},
{"sf_rnr_wallthicks", (getter)SolarField_get_sf_rnr_wallthicks,(setter)SolarField_set_sf_rnr_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom runner wall thicknesses [m]\n\n*Required*: True"),
 	NULL},
{"solar_mult", (getter)SolarField_get_solar_mult,(setter)SolarField_set_solar_mult,
	PyDoc_STR("*float*: Solar multiple [none]\n\n*Required*: True"),
 	NULL},
{"theta_dep", (getter)SolarField_get_theta_dep,(setter)SolarField_set_theta_dep,
	PyDoc_STR("*float*: Deploy angle [deg]\n\n*Required*: True"),
 	NULL},
{"theta_stow", (getter)SolarField_get_theta_stow,(setter)SolarField_set_theta_stow,
	PyDoc_STR("*float*: Stow angle [deg]\n\n*Required*: True"),
 	NULL},
{"tilt", (getter)SolarField_get_tilt,(setter)SolarField_set_tilt,
	PyDoc_STR("*float*: Tilt angle of surface/axis [none]\n\n*Required*: True"),
 	NULL},
{"wind_stow_speed", (getter)SolarField_get_wind_stow_speed,(setter)SolarField_set_wind_stow_speed,
	PyDoc_STR("*float*: Trough wind stow speed [m/s]\n\n*Required*: If not provided, assumed to be 50"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.SolarField",             /*tp_name*/
		sizeof(SolarFieldObject),          /*tp_basicsize*/
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

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} PowerblockObject;

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Powerblock")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Powerblock_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Powerblock_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Powerblock_get_CT(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_CT_nget, self->data_ptr);
}

static int
Powerblock_set_CT(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_CT_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_F_wc(PowerblockObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_L_rnr_pb(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_L_rnr_pb_nget, self->data_ptr);
}

static int
Powerblock_set_L_rnr_pb(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_L_rnr_pb_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_boil(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_boil_nget, self->data_ptr);
}

static int
Powerblock_set_P_boil(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_boil_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_ref(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_P_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_P_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_approach(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_T_approach_nget, self->data_ptr);
}

static int
Powerblock_set_T_approach(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_T_approach_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_cycle_cutoff_frac(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
Powerblock_set_cycle_cutoff_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_cycle_max_frac(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_cycle_max_frac_nget, self->data_ptr);
}

static int
Powerblock_set_cycle_max_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_pump_coef(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_pb_pump_coef_nget, self->data_ptr);
}

static int
Powerblock_set_pb_pump_coef(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pc_config(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_pc_config_nget, self->data_ptr);
}

static int
Powerblock_set_pc_config(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_pc_config_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_startup_time_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_tech_type(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_tech_type_nget, self->data_ptr);
}

static int
Powerblock_set_tech_type(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_tech_type_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_amb_des(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_ud_T_amb_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_amb_high(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_T_amb_high_nget, self->data_ptr);
}

static int
Powerblock_set_ud_T_amb_high(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_T_amb_high_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_amb_ind_od(PowerblockObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Powerblock_ud_T_amb_ind_od_mget, self->data_ptr);
}

static int
Powerblock_set_ud_T_amb_ind_od(PowerblockObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Powerblock_ud_T_amb_ind_od_mset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_amb_low(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_T_amb_low_nget, self->data_ptr);
}

static int
Powerblock_set_ud_T_amb_low(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_T_amb_low_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_htf_high(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_T_htf_high_nget, self->data_ptr);
}

static int
Powerblock_set_ud_T_htf_high(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_T_htf_high_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_htf_ind_od(PowerblockObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Powerblock_ud_T_htf_ind_od_mget, self->data_ptr);
}

static int
Powerblock_set_ud_T_htf_ind_od(PowerblockObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Powerblock_ud_T_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_T_htf_low(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_T_htf_low_nget, self->data_ptr);
}

static int
Powerblock_set_ud_T_htf_low(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_T_htf_low_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_f_W_dot_cool_des(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_f_W_dot_cool_des_nget, self->data_ptr);
}

static int
Powerblock_set_ud_f_W_dot_cool_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_f_W_dot_cool_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_ind_od(PowerblockObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Powerblock_ud_ind_od_mget, self->data_ptr);
}

static int
Powerblock_set_ud_ind_od(PowerblockObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Powerblock_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_m_dot_htf_high(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_m_dot_htf_high_nget, self->data_ptr);
}

static int
Powerblock_set_ud_m_dot_htf_high(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_m_dot_htf_high_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_m_dot_htf_ind_od(PowerblockObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Powerblock_ud_m_dot_htf_ind_od_mget, self->data_ptr);
}

static int
Powerblock_set_ud_m_dot_htf_ind_od(PowerblockObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Powerblock_ud_m_dot_htf_ind_od_mset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_m_dot_htf_low(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_m_dot_htf_low_nget, self->data_ptr);
}

static int
Powerblock_set_ud_m_dot_htf_low(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_m_dot_htf_low_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_ud_m_dot_water_cool_des(PowerblockObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Powerblock_ud_m_dot_water_cool_des_nget, self->data_ptr);
}

static int
Powerblock_set_ud_m_dot_water_cool_des(PowerblockObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Powerblock_ud_m_dot_water_cool_des_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"CT", (getter)Powerblock_get_CT,(setter)Powerblock_set_CT,
	PyDoc_STR("*float*: Flag for using dry cooling or wet cooling system [none]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	PyDoc_STR("*sequence*: Fraction indicating wet cooling use for hybrid system [none]\n\n*Options*: constant=[0,0,0,0,0,0,0,0,0]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"L_rnr_pb", (getter)Powerblock_get_L_rnr_pb,(setter)Powerblock_set_L_rnr_pb,
	PyDoc_STR("*float*: Length of runner pipe in power block [m]\n\n*Required*: True"),
 	NULL},
{"P_boil", (getter)Powerblock_get_P_boil,(setter)Powerblock_set_P_boil,
	PyDoc_STR("*float*: Boiler operating pressure [bar]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio [none]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"P_ref", (getter)Powerblock_get_P_ref,(setter)Powerblock_set_P_ref,
	PyDoc_STR("*float*: Rated plant capacity [MWe]\n\n*Required*: True"),
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"T_approach", (getter)Powerblock_get_T_approach,(setter)Powerblock_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"cycle_cutoff_frac", (getter)Powerblock_get_cycle_cutoff_frac,(setter)Powerblock_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown [-]\n\n*Required*: True"),
 	NULL},
{"cycle_max_frac", (getter)Powerblock_get_cycle_max_frac,(setter)Powerblock_set_cycle_max_frac,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction [-]\n\n*Required*: True"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Power cycle efficiency at design [none]\n\n*Required*: True"),
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction  [none]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"pb_pump_coef", (getter)Powerblock_get_pb_pump_coef,(setter)Powerblock_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n*Required*: True"),
 	NULL},
{"pc_config", (getter)Powerblock_get_pc_config,(setter)Powerblock_set_pc_config,
	PyDoc_STR("*float*: 0: Steam Rankine (224), 1: user defined [-]\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby mode [none]\n\n*Required*: True"),
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n*Required*: True"),
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n*Required*: True"),
 	NULL},
{"tech_type", (getter)Powerblock_get_tech_type,(setter)Powerblock_set_tech_type,
	PyDoc_STR("*float*: Turbine inlet pressure control flag (sliding=user, fixed=trough) [1/2/3]\n\n*Info*: tower/trough/user\n\n*Required*: True if pc_config=0"),
 	NULL},
{"ud_T_amb_des", (getter)Powerblock_get_ud_T_amb_des,(setter)Powerblock_set_ud_T_amb_des,
	PyDoc_STR("*float*: Ambient temperature at user-defined power cycle design point [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_T_amb_high", (getter)Powerblock_get_ud_T_amb_high,(setter)Powerblock_set_ud_T_amb_high,
	PyDoc_STR("*float*: High level ambient temperature for HTF mass flow rate parametric [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_T_amb_ind_od", (getter)Powerblock_get_ud_T_amb_ind_od,(setter)Powerblock_set_ud_T_amb_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design table of user-defined power cycle performance formed from parametric on T_amb [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_T_amb_low", (getter)Powerblock_get_ud_T_amb_low,(setter)Powerblock_set_ud_T_amb_low,
	PyDoc_STR("*float*: Low level ambient temperature for HTF mass flow rate parametric [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_T_htf_high", (getter)Powerblock_get_ud_T_htf_high,(setter)Powerblock_set_ud_T_htf_high,
	PyDoc_STR("*float*: High level HTF inlet temperature for T_amb parametric [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_T_htf_ind_od", (getter)Powerblock_get_ud_T_htf_ind_od,(setter)Powerblock_set_ud_T_htf_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design table of user-defined power cycle performance formed from parametric on T_htf_hot [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_T_htf_low", (getter)Powerblock_get_ud_T_htf_low,(setter)Powerblock_set_ud_T_htf_low,
	PyDoc_STR("*float*: Low level HTF inlet temperature for T_amb parametric [C]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_f_W_dot_cool_des", (getter)Powerblock_get_ud_f_W_dot_cool_des,(setter)Powerblock_set_ud_f_W_dot_cool_des,
	PyDoc_STR("*float*: Percent of user-defined power cycle design gross output consumed by cooling [%]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_ind_od", (getter)Powerblock_get_ud_ind_od,(setter)Powerblock_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_m_dot_htf_high", (getter)Powerblock_get_ud_m_dot_htf_high,(setter)Powerblock_set_ud_m_dot_htf_high,
	PyDoc_STR("*float*: High level normalized HTF mass flow rate for T_HTF parametric [-]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_m_dot_htf_ind_od", (getter)Powerblock_get_ud_m_dot_htf_ind_od,(setter)Powerblock_set_ud_m_dot_htf_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design table of user-defined power cycle performance formed from parametric on m_dot_htf [ND]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_m_dot_htf_low", (getter)Powerblock_get_ud_m_dot_htf_low,(setter)Powerblock_set_ud_m_dot_htf_low,
	PyDoc_STR("*float*: Low level normalized HTF mass flow rate for T_HTF parametric [-]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_m_dot_water_cool_des", (getter)Powerblock_get_ud_m_dot_water_cool_des,(setter)Powerblock_set_ud_m_dot_water_cool_des,
	PyDoc_STR("*float*: Mass flow rate of water required at user-defined power cycle design point [kg/s]\n\n*Required*: True if pc_config=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Powerblock",             /*tp_name*/
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
 * TES Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} TESObject;

static PyTypeObject TES_Type;

static PyObject *
TES_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = TES_Type.tp_alloc(&TES_Type,0);

	TESObject* TES_obj = (TESObject*)new_obj;

	TES_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TES methods */

static PyObject *
TES_assign(TESObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "TES")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES_export(TESObject *self, PyObject *args)
{
	PyTypeObject* tp = &TES_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TES_methods[] = {
		{"assign",            (PyCFunction)TES_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``TES_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TES_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TES_get_cold_tank_Thtr(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_cold_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_cold_tank_Thtr(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_cold_tank_max_heat(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_cold_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_cold_tank_max_heat(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_dt_hot(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_dt_hot_nget, self->data_ptr);
}

static int
TES_set_dt_hot(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_dt_hot_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_h_tank_nget, self->data_ptr);
}

static int
TES_set_h_tank(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_h_tank_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank_min(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_h_tank_min_nget, self->data_ptr);
}

static int
TES_set_h_tank_min(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_h_tank_min_nset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_Thtr(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_hot_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_hot_tank_Thtr(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_hot_tank_max_heat(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_hot_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_hot_tank_max_heat(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_hot_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_init_hot_htf_percent(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_init_hot_htf_percent_nget, self->data_ptr);
}

static int
TES_set_init_hot_htf_percent(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
TES_get_is_hx(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_is_hx_nget, self->data_ptr);
}

static int
TES_set_is_hx(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_is_hx_nset, self->data_ptr);
}

static PyObject *
TES_get_store_fl_props(TESObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_TES_store_fl_props_mget, self->data_ptr);
}

static int
TES_set_store_fl_props(TESObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_TES_store_fl_props_mset, self->data_ptr);
}

static PyObject *
TES_get_store_fluid(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_store_fluid_nget, self->data_ptr);
}

static int
TES_set_store_fluid(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_store_fluid_nset, self->data_ptr);
}

static PyObject *
TES_get_tank_pairs(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tank_pairs_nget, self->data_ptr);
}

static int
TES_set_tank_pairs(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tank_pairs_nset, self->data_ptr);
}

static PyObject *
TES_get_tshours(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_tshours_nget, self->data_ptr);
}

static int
TES_set_tshours(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_tshours_nset, self->data_ptr);
}

static PyObject *
TES_get_u_tank(TESObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_TES_u_tank_nget, self->data_ptr);
}

static int
TES_set_u_tank(TESObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_TES_u_tank_nset, self->data_ptr);
}

static PyGetSetDef TES_getset[] = {
{"cold_tank_Thtr", (getter)TES_get_cold_tank_Thtr,(setter)TES_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable cold tank HTF temp [C]\n\n*Required*: True"),
 	NULL},
{"cold_tank_max_heat", (getter)TES_get_cold_tank_max_heat,(setter)TES_set_cold_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for cold tank heating [MWe]\n\n*Required*: True"),
 	NULL},
{"dt_hot", (getter)TES_get_dt_hot,(setter)TES_set_dt_hot,
	PyDoc_STR("*float*: Hot side HX approach temp [C]\n\n*Required*: True"),
 	NULL},
{"h_tank", (getter)TES_get_h_tank,(setter)TES_set_h_tank,
	PyDoc_STR("*float*: Total height of tank (height of HTF when tank is full [m]\n\n*Required*: True"),
 	NULL},
{"h_tank_min", (getter)TES_get_h_tank_min,(setter)TES_set_h_tank_min,
	PyDoc_STR("*float*: Minimum allowable HTF height in storage tank [m]\n\n*Required*: True"),
 	NULL},
{"hot_tank_Thtr", (getter)TES_get_hot_tank_Thtr,(setter)TES_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable hot tank HTF temp [C]\n\n*Required*: True"),
 	NULL},
{"hot_tank_max_heat", (getter)TES_get_hot_tank_max_heat,(setter)TES_set_hot_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for hot tank heating [MWe]\n\n*Required*: True"),
 	NULL},
{"init_hot_htf_percent", (getter)TES_get_init_hot_htf_percent,(setter)TES_set_init_hot_htf_percent,
	PyDoc_STR("*float*: Initial fraction of avail. vol that is hot [%]\n\n*Required*: True"),
 	NULL},
{"is_hx", (getter)TES_get_is_hx,(setter)TES_set_is_hx,
	PyDoc_STR("*float*: Heat exchanger (HX) exists (1=yes, 0=no) [-]\n\n*Required*: True"),
 	NULL},
{"store_fl_props", (getter)TES_get_store_fl_props,(setter)TES_set_store_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined storage fluid property data [-]\n\n*Required*: True"),
 	NULL},
{"store_fluid", (getter)TES_get_store_fluid,(setter)TES_set_store_fluid,
	PyDoc_STR("*float*: Material number for storage fluid [-]\n\n*Required*: True"),
 	NULL},
{"tank_pairs", (getter)TES_get_tank_pairs,(setter)TES_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"tshours", (getter)TES_get_tshours,(setter)TES_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n*Required*: True"),
 	NULL},
{"u_tank", (getter)TES_get_u_tank,(setter)TES_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TES_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.TES",             /*tp_name*/
		sizeof(TESObject),          /*tp_basicsize*/
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
		TES_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TES_getset,          /*tp_getset*/
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
 * Tou Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} TouObject;

static PyTypeObject Tou_Type;

static PyObject *
Tou_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = Tou_Type.tp_alloc(&Tou_Type,0);

	TouObject* Tou_obj = (TouObject*)new_obj;

	Tou_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Tou methods */

static PyObject *
Tou_assign(TouObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_export(TouObject *self, PyObject *args)
{
	PyTypeObject* tp = &Tou_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Tou_methods[] = {
		{"assign",            (PyCFunction)Tou_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Tou_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Tou_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Tou_get_ampl_data_dir(TouObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysical_Tou_ampl_data_dir_sget, self->data_ptr);
}

static int
Tou_set_ampl_data_dir(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysical_Tou_ampl_data_dir_sset, self->data_ptr);
}

static PyObject *
Tou_get_ampl_exec_call(TouObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysical_Tou_ampl_exec_call_sget, self->data_ptr);
}

static int
Tou_set_ampl_exec_call(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysical_Tou_ampl_exec_call_sset, self->data_ptr);
}

static PyObject *
Tou_get_disp_csu_cost(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_csu_cost_nget, self->data_ptr);
}

static int
Tou_set_disp_csu_cost(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_csu_cost_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_frequency(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_frequency_nget, self->data_ptr);
}

static int
Tou_set_disp_frequency(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_frequency_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_horizon(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_horizon_nget, self->data_ptr);
}

static int
Tou_set_disp_horizon(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_horizon_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_max_iter(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_max_iter_nget, self->data_ptr);
}

static int
Tou_set_disp_max_iter(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_max_iter_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_mip_gap(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_mip_gap_nget, self->data_ptr);
}

static int
Tou_set_disp_mip_gap(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_mip_gap_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_pen_delta_w(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_pen_delta_w_nget, self->data_ptr);
}

static int
Tou_set_disp_pen_delta_w(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_pen_delta_w_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_reporting(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_reporting_nget, self->data_ptr);
}

static int
Tou_set_disp_reporting(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_reporting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_rsu_cost(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_rsu_cost_nget, self->data_ptr);
}

static int
Tou_set_disp_rsu_cost(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_rsu_cost_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_bb(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_spec_bb_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_bb(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_spec_bb_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_presolve(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_spec_presolve_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_presolve(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_spec_presolve_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_scaling(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_spec_scaling_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_scaling(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_spec_scaling_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_steps_per_hour(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_steps_per_hour_nget, self->data_ptr);
}

static int
Tou_set_disp_steps_per_hour(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_time_weighting(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_time_weighting_nget, self->data_ptr);
}

static int
Tou_set_disp_time_weighting(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_time_weighting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_timeout(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_disp_timeout_nget, self->data_ptr);
}

static int
Tou_set_disp_timeout(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_disp_timeout_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor1(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor1_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor1(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor1_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor2(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor2_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor2(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor2_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor3(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor3_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor3(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor3_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor4(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor4_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor4(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor4_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor5(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor5_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor5(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor5_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor6(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor6_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor6(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor6_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor7(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor7_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor7(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor7_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor8(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor8_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor8(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor8_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor9(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_dispatch_factor9_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor9(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_dispatch_factor9_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factors_ts(TouObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_dispatch_factors_ts_aget, self->data_ptr);
}

static int
Tou_set_dispatch_factors_ts(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_sched_weekday(TouObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
Tou_set_dispatch_sched_weekday(TouObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_sched_weekend(TouObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
Tou_set_dispatch_sched_weekend(TouObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_series(TouObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_dispatch_series_aget, self->data_ptr);
}

static int
Tou_set_dispatch_series(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_dispatch_series_aset, self->data_ptr);
}

static PyObject *
Tou_get_f_turb_tou_periods(TouObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_f_turb_tou_periods_aget, self->data_ptr);
}

static int
Tou_set_f_turb_tou_periods(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_f_turb_tou_periods_aset, self->data_ptr);
}

static PyObject *
Tou_get_is_ampl_engine(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_ampl_engine_nget, self->data_ptr);
}

static int
Tou_set_is_ampl_engine(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_ampl_engine_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_dispatch(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_dispatch_nget, self->data_ptr);
}

static int
Tou_set_is_dispatch(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_dispatch_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_dispatch_series(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_dispatch_series_nget, self->data_ptr);
}

static int
Tou_set_is_dispatch_series(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_dispatch_series_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_wlim_series(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_wlim_series_nget, self->data_ptr);
}

static int
Tou_set_is_wlim_series(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_wlim_series_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_write_ampl_dat(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_is_write_ampl_dat_nget, self->data_ptr);
}

static int
Tou_set_is_write_ampl_dat(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_is_write_ampl_dat_nset, self->data_ptr);
}

static PyObject *
Tou_get_ppa_multiplier_model(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_ppa_multiplier_model_nget, self->data_ptr);
}

static int
Tou_set_ppa_multiplier_model(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_heattrace(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_q_rec_heattrace_nget, self->data_ptr);
}

static int
Tou_set_q_rec_heattrace(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_q_rec_heattrace_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_standby(TouObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Tou_q_rec_standby_nget, self->data_ptr);
}

static int
Tou_set_q_rec_standby(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Tou_q_rec_standby_nset, self->data_ptr);
}

static PyObject *
Tou_get_weekday_schedule(TouObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_weekday_schedule_mget, self->data_ptr);
}

static int
Tou_set_weekday_schedule(TouObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
Tou_get_weekend_schedule(TouObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Tou_weekend_schedule_mget, self->data_ptr);
}

static int
Tou_set_weekend_schedule(TouObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Tou_weekend_schedule_mset, self->data_ptr);
}

static PyObject *
Tou_get_wlim_series(TouObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Tou_wlim_series_aget, self->data_ptr);
}

static int
Tou_set_wlim_series(TouObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_Tou_wlim_series_aset, self->data_ptr);
}

static PyGetSetDef Tou_getset[] = {
{"ampl_data_dir", (getter)Tou_get_ampl_data_dir,(setter)Tou_set_ampl_data_dir,
	PyDoc_STR("*str*: AMPL data file directory [-]\n\n*Required*: If not provided, assumed to be ''"),
 	NULL},
{"ampl_exec_call", (getter)Tou_get_ampl_exec_call,(setter)Tou_set_ampl_exec_call,
	PyDoc_STR("*str*: System command to run AMPL code [-]\n\n*Required*: If not provided, assumed to be 'ampl sdk_solution.run'"),
 	NULL},
{"disp_csu_cost", (getter)Tou_get_disp_csu_cost,(setter)Tou_set_disp_csu_cost,
	PyDoc_STR("*float*: Cycle startup cost [$]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_frequency", (getter)Tou_get_disp_frequency,(setter)Tou_set_disp_frequency,
	PyDoc_STR("*float*: Frequency for dispatch optimization calculations [hour]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_horizon", (getter)Tou_get_disp_horizon,(setter)Tou_set_disp_horizon,
	PyDoc_STR("*float*: Time horizon for dispatch optimization [hour]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_max_iter", (getter)Tou_get_disp_max_iter,(setter)Tou_set_disp_max_iter,
	PyDoc_STR("*float*: Max. no. dispatch optimization iterations [-]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_mip_gap", (getter)Tou_get_disp_mip_gap,(setter)Tou_set_disp_mip_gap,
	PyDoc_STR("*float*: Dispatch optimization solution tolerance [-]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_pen_delta_w", (getter)Tou_get_disp_pen_delta_w,(setter)Tou_set_disp_pen_delta_w,
	PyDoc_STR("*float*: Dispatch cycle production change penalty [$/kWe-change]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_reporting", (getter)Tou_get_disp_reporting,(setter)Tou_set_disp_reporting,
	PyDoc_STR("*float*: Dispatch optimization reporting level [-]\n\n*Required*: If not provided, assumed to be -1"),
 	NULL},
{"disp_rsu_cost", (getter)Tou_get_disp_rsu_cost,(setter)Tou_set_disp_rsu_cost,
	PyDoc_STR("*float*: Receiver startup cost [$]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"disp_spec_bb", (getter)Tou_get_disp_spec_bb,(setter)Tou_set_disp_spec_bb,
	PyDoc_STR("*float*: Dispatch optimization B&B heuristic [-]\n\n*Required*: If not provided, assumed to be -1"),
 	NULL},
{"disp_spec_presolve", (getter)Tou_get_disp_spec_presolve,(setter)Tou_set_disp_spec_presolve,
	PyDoc_STR("*float*: Dispatch optimization presolve heuristic [-]\n\n*Required*: If not provided, assumed to be -1"),
 	NULL},
{"disp_spec_scaling", (getter)Tou_get_disp_spec_scaling,(setter)Tou_set_disp_spec_scaling,
	PyDoc_STR("*float*: Dispatch optimization scaling heuristic [-]\n\n*Required*: If not provided, assumed to be -1"),
 	NULL},
{"disp_steps_per_hour", (getter)Tou_get_disp_steps_per_hour,(setter)Tou_set_disp_steps_per_hour,
	PyDoc_STR("*float*: Time steps per hour for dispatch optimization calculations [-]\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"disp_time_weighting", (getter)Tou_get_disp_time_weighting,(setter)Tou_set_disp_time_weighting,
	PyDoc_STR("*float*: Dispatch optimization future time discounting factor [-]\n\n*Required*: If not provided, assumed to be 0.99"),
 	NULL},
{"disp_timeout", (getter)Tou_get_disp_timeout,(setter)Tou_set_disp_timeout,
	PyDoc_STR("*float*: Max. dispatch optimization solve duration [s]\n\n*Required*: True if is_dispatch=1"),
 	NULL},
{"dispatch_factor1", (getter)Tou_get_dispatch_factor1,(setter)Tou_set_dispatch_factor1,
	PyDoc_STR("*float*: Dispatch payment factor 1\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor2", (getter)Tou_get_dispatch_factor2,(setter)Tou_set_dispatch_factor2,
	PyDoc_STR("*float*: Dispatch payment factor 2\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor3", (getter)Tou_get_dispatch_factor3,(setter)Tou_set_dispatch_factor3,
	PyDoc_STR("*float*: Dispatch payment factor 3\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor4", (getter)Tou_get_dispatch_factor4,(setter)Tou_set_dispatch_factor4,
	PyDoc_STR("*float*: Dispatch payment factor 4\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor5", (getter)Tou_get_dispatch_factor5,(setter)Tou_set_dispatch_factor5,
	PyDoc_STR("*float*: Dispatch payment factor 5\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor6", (getter)Tou_get_dispatch_factor6,(setter)Tou_set_dispatch_factor6,
	PyDoc_STR("*float*: Dispatch payment factor 6\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor7", (getter)Tou_get_dispatch_factor7,(setter)Tou_set_dispatch_factor7,
	PyDoc_STR("*float*: Dispatch payment factor 7\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor8", (getter)Tou_get_dispatch_factor8,(setter)Tou_set_dispatch_factor8,
	PyDoc_STR("*float*: Dispatch payment factor 8\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor9", (getter)Tou_get_dispatch_factor9,(setter)Tou_set_dispatch_factor9,
	PyDoc_STR("*float*: Dispatch payment factor 9\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factors_ts", (getter)Tou_get_dispatch_factors_ts,(setter)Tou_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n*Required*: True if ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)Tou_get_dispatch_sched_weekday,(setter)Tou_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: 12x24 PPA pricing Weekday schedule\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_sched_weekend", (getter)Tou_get_dispatch_sched_weekend,(setter)Tou_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: 12x24 PPA pricing Weekend schedule\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_series", (getter)Tou_get_dispatch_series,(setter)Tou_set_dispatch_series,
	PyDoc_STR("*sequence*: Time series dispatch factors"),
 	NULL},
{"f_turb_tou_periods", (getter)Tou_get_f_turb_tou_periods,(setter)Tou_set_f_turb_tou_periods,
	PyDoc_STR("*sequence*: Dispatch logic for turbine load fraction [-]\n\n*Required*: True"),
 	NULL},
{"is_ampl_engine", (getter)Tou_get_is_ampl_engine,(setter)Tou_set_is_ampl_engine,
	PyDoc_STR("*float*: Run dispatch optimization with external AMPL engine [-]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"is_dispatch", (getter)Tou_get_is_dispatch,(setter)Tou_set_is_dispatch,
	PyDoc_STR("*float*: Allow dispatch optimization? [-]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"is_dispatch_series", (getter)Tou_get_is_dispatch_series,(setter)Tou_set_is_dispatch_series,
	PyDoc_STR("*float*: Use time-series dispatch factors\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"is_wlim_series", (getter)Tou_get_is_wlim_series,(setter)Tou_set_is_wlim_series,
	PyDoc_STR("*float*: Use time-series net electricity generation limits\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"is_write_ampl_dat", (getter)Tou_get_is_write_ampl_dat,(setter)Tou_set_is_write_ampl_dat,
	PyDoc_STR("*float*: Write AMPL data files for dispatch run [-]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"ppa_multiplier_model", (getter)Tou_get_ppa_multiplier_model,(setter)Tou_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n*Options*: 0=diurnal,1=timestep\n\n*Constraints*: INTEGER,MIN=0\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"q_rec_heattrace", (getter)Tou_get_q_rec_heattrace,(setter)Tou_set_q_rec_heattrace,
	PyDoc_STR("*float*: Receiver heat trace energy consumption during startup [kWe-hr]\n\n*Required*: If not provided, assumed to be 0.0"),
 	NULL},
{"q_rec_standby", (getter)Tou_get_q_rec_standby,(setter)Tou_set_q_rec_standby,
	PyDoc_STR("*float*: Receiver standby energy consumption [kWt]\n\n*Required*: If not provided, assumed to be 9e99"),
 	NULL},
{"weekday_schedule", (getter)Tou_get_weekday_schedule,(setter)Tou_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 CSP operation Time-of-Use Weekday schedule [-]\n\n*Required*: True"),
 	NULL},
{"weekend_schedule", (getter)Tou_get_weekend_schedule,(setter)Tou_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 CSP operation Time-of-Use Weekend schedule [-]\n\n*Required*: True"),
 	NULL},
{"wlim_series", (getter)Tou_get_wlim_series,(setter)Tou_set_wlim_series,
	PyDoc_STR("*sequence*: Time series net electicity generation limits [kWe]\n\n*Required*: True if is_wlim_series=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Tou_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Tou",             /*tp_name*/
		sizeof(TouObject),          /*tp_basicsize*/
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
		Tou_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Tou_getset,          /*tp_getset*/
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
 * System Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} SystemObject;

static PyTypeObject System_Type;

static PyObject *
System_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = System_Type.tp_alloc(&System_Type,0);

	SystemObject* System_obj = (SystemObject*)new_obj;

	System_obj->data_ptr = data_ptr;

	return new_obj;
}

/* System methods */

static PyObject *
System_assign(SystemObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "System")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
System_export(SystemObject *self, PyObject *args)
{
	PyTypeObject* tp = &System_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef System_methods[] = {
		{"assign",            (PyCFunction)System_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``System_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)System_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
System_get_aux_array(SystemObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_System_aux_array_aget, self->data_ptr);
}

static int
System_set_aux_array(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_System_aux_array_aset, self->data_ptr);
}

static PyObject *
System_get_bop_array(SystemObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_System_bop_array_aget, self->data_ptr);
}

static int
System_set_bop_array(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysical_System_bop_array_aset, self->data_ptr);
}

static PyObject *
System_get_gross_net_conversion_factor(SystemObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_gross_net_conversion_factor_nget, self->data_ptr);
}

static int
System_set_gross_net_conversion_factor(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_gross_net_conversion_factor_nset, self->data_ptr);
}

static PyObject *
System_get_pb_fixed_par(SystemObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_pb_fixed_par_nget, self->data_ptr);
}

static int
System_set_pb_fixed_par(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
System_get_washing_frequency(SystemObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_washing_frequency_nget, self->data_ptr);
}

static int
System_set_washing_frequency(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_washing_frequency_nset, self->data_ptr);
}

static PyObject *
System_get_water_usage_per_wash(SystemObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_System_water_usage_per_wash_nget, self->data_ptr);
}

static int
System_set_water_usage_per_wash(SystemObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_System_water_usage_per_wash_nset, self->data_ptr);
}

static PyGetSetDef System_getset[] = {
{"aux_array", (getter)System_get_aux_array,(setter)System_set_aux_array,
	PyDoc_STR("*sequence*: Auxiliary heater, mult frac and const, linear and quad coeff\n\n*Required*: True"),
 	NULL},
{"bop_array", (getter)System_get_bop_array,(setter)System_set_bop_array,
	PyDoc_STR("*sequence*: Balance of plant parasitic power fraction, mult frac and const, linear and quad coeff\n\n*Required*: True"),
 	NULL},
{"gross_net_conversion_factor", (getter)System_get_gross_net_conversion_factor,(setter)System_set_gross_net_conversion_factor,
	PyDoc_STR("*float*: Estimated gross to net conversion factor\n\n*Required*: True"),
 	NULL},
{"pb_fixed_par", (getter)System_get_pb_fixed_par,(setter)System_set_pb_fixed_par,
	PyDoc_STR("*float*: Fraction of rated gross power constantly consumed [MWe/MWcap]\n\n*Required*: True"),
 	NULL},
{"washing_frequency", (getter)System_get_washing_frequency,(setter)System_set_washing_frequency,
	PyDoc_STR("*float*: Mirror washing frequency [-/year]\n\n*Required*: True"),
 	NULL},
{"water_usage_per_wash", (getter)System_get_water_usage_per_wash,(setter)System_set_water_usage_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject System_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.System",             /*tp_name*/
		sizeof(SystemObject),          /*tp_basicsize*/
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
		System_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		System_getset,          /*tp_getset*/
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

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} ControllerObject;

static PyTypeObject Controller_Type;

static PyObject *
Controller_new(SAM_TroughPhysical data_ptr)
{
	PyObject* new_obj = Controller_Type.tp_alloc(&Controller_Type,0);

	ControllerObject* Controller_obj = (ControllerObject*)new_obj;

	Controller_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Controller methods */

static PyObject *
Controller_assign(ControllerObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Controller")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Controller_export(ControllerObject *self, PyObject *args)
{
	PyTypeObject* tp = &Controller_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Controller_methods[] = {
		{"assign",            (PyCFunction)Controller_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Controller_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Controller_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Controller_get_DP_SGS(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_DP_SGS_nget, self->data_ptr);
}

static int
Controller_set_DP_SGS(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_DP_SGS_nset, self->data_ptr);
}

static PyObject *
Controller_get_T_tank_hot_inlet_min(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_T_tank_hot_inlet_min_nget, self->data_ptr);
}

static int
Controller_set_T_tank_hot_inlet_min(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_T_tank_hot_inlet_min_nset, self->data_ptr);
}

static PyObject *
Controller_get_V_tes_des(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_V_tes_des_nget, self->data_ptr);
}

static int
Controller_set_V_tes_des(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_V_tes_des_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_p_loss(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_custom_tes_p_loss_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_p_loss(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_custom_tes_p_loss_nset, self->data_ptr);
}

static PyObject *
Controller_get_custom_tes_pipe_sizes(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_custom_tes_pipe_sizes_nget, self->data_ptr);
}

static int
Controller_set_custom_tes_pipe_sizes(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_custom_tes_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
Controller_get_has_hot_tank_bypass(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_has_hot_tank_bypass_nget, self->data_ptr);
}

static int
Controller_set_has_hot_tank_bypass(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_has_hot_tank_bypass_nset, self->data_ptr);
}

static PyObject *
Controller_get_k_tes_loss_coeffs(ControllerObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_k_tes_loss_coeffs_mget, self->data_ptr);
}

static int
Controller_set_k_tes_loss_coeffs(ControllerObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_k_tes_loss_coeffs_mset, self->data_ptr);
}

static PyObject *
Controller_get_tanks_in_parallel(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_tanks_in_parallel_nget, self->data_ptr);
}

static int
Controller_set_tanks_in_parallel(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_tanks_in_parallel_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_diams(ControllerObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_tes_diams_mget, self->data_ptr);
}

static int
Controller_set_tes_diams(ControllerObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_tes_diams_mset, self->data_ptr);
}

static PyObject *
Controller_get_tes_lengths(ControllerObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_tes_lengths_mget, self->data_ptr);
}

static int
Controller_set_tes_lengths(ControllerObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_tes_lengths_mset, self->data_ptr);
}

static PyObject *
Controller_get_tes_pump_coef(ControllerObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Controller_tes_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_tes_pump_coef(ControllerObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysical_Controller_tes_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_tes_wallthicks(ControllerObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysical_Controller_tes_wallthicks_mget, self->data_ptr);
}

static int
Controller_set_tes_wallthicks(ControllerObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysical_Controller_tes_wallthicks_mset, self->data_ptr);
}

static PyGetSetDef Controller_getset[] = {
{"DP_SGS", (getter)Controller_get_DP_SGS,(setter)Controller_set_DP_SGS,
	PyDoc_STR("*float*: Pressure drop within the steam generator [bar]\n\n*Required*: True"),
 	NULL},
{"T_tank_hot_inlet_min", (getter)Controller_get_T_tank_hot_inlet_min,(setter)Controller_set_T_tank_hot_inlet_min,
	PyDoc_STR("*float*: Minimum hot tank htf inlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"V_tes_des", (getter)Controller_get_V_tes_des,(setter)Controller_set_V_tes_des,
	PyDoc_STR("*float*: Design-point velocity to size the TES pipe diameters [m/s]\n\n*Required*: True"),
 	NULL},
{"custom_tes_p_loss", (getter)Controller_get_custom_tes_p_loss,(setter)Controller_set_custom_tes_p_loss,
	PyDoc_STR("*float*: TES pipe losses are based on custom lengths and coeffs [-]\n\n*Required*: True"),
 	NULL},
{"custom_tes_pipe_sizes", (getter)Controller_get_custom_tes_pipe_sizes,(setter)Controller_set_custom_tes_pipe_sizes,
	PyDoc_STR("*float*: Use custom TES pipe diams, wallthks, and lengths [-]\n\n*Required*: True"),
 	NULL},
{"has_hot_tank_bypass", (getter)Controller_get_has_hot_tank_bypass,(setter)Controller_set_has_hot_tank_bypass,
	PyDoc_STR("*float*: Bypass valve connects field outlet to cold tank [-]\n\n*Required*: True"),
 	NULL},
{"k_tes_loss_coeffs", (getter)Controller_get_k_tes_loss_coeffs,(setter)Controller_set_k_tes_loss_coeffs,
	PyDoc_STR("*sequence[sequence]*: Minor loss coeffs for the coll, gen, and bypass loops [-]\n\n*Required*: True"),
 	NULL},
{"tanks_in_parallel", (getter)Controller_get_tanks_in_parallel,(setter)Controller_set_tanks_in_parallel,
	PyDoc_STR("*float*: Tanks are in parallel, not in series, with solar field [-]\n\n*Required*: True"),
 	NULL},
{"tes_diams", (getter)Controller_get_tes_diams,(setter)Controller_set_tes_diams,
	PyDoc_STR("*sequence[sequence]*: Custom TES diameters [m]\n\n*Required*: True"),
 	NULL},
{"tes_lengths", (getter)Controller_get_tes_lengths,(setter)Controller_set_tes_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom TES lengths [m]\n\n*Required*: True"),
 	NULL},
{"tes_pump_coef", (getter)Controller_get_tes_pump_coef,(setter)Controller_set_tes_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through tes loop [kW/(kg/s)]\n\n*Required*: True"),
 	NULL},
{"tes_wallthicks", (getter)Controller_get_tes_wallthicks,(setter)Controller_set_tes_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom TES wall thicknesses [m]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controller_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical.Controller",             /*tp_name*/
		sizeof(ControllerObject),          /*tp_basicsize*/
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
 * Outputs Group
 */ 

typedef struct {
	PyObject_HEAD
	SAM_TroughPhysical   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_TroughPhysical data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysical", "Outputs")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_CosTh_ave(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_CosTh_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_EndLoss_ave(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_EndLoss_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_EqOpteff(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_EqOpteff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_IAM_ave(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_IAM_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cooling_tower_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_cooling_tower_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cycle(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_fixed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_out_net(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_plant_balance_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_P_plant_balance_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_RowShadow_ave(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_RowShadow_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_SCAs_def(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_SCAs_def_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_cold_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_field_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_hot_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_field_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_pc_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_pc_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_pc_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_cold_in(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_rec_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_hot_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_rec_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Theta_ave(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_Theta_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_field_pump(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_W_dot_field_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_sca_track(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_W_dot_sca_track_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_field_freeze_protection(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_field_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_gross_energy(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_gross_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_tes_freeze_protection(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_tes_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_thermal_consumption(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_thermal_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaP_field(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_deltaP_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_obj_relax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_obj_relax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_objective(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_objective_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_pceff_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_pceff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nconstr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_presolve_nconstr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_presolve_nvar(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_presolve_nvar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qpbsu_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qpbsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsf_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qsf_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfprod_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qsfprod_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_qsfsu_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_qsfsu_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_rev_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_rev_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_iter(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_solve_iter_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_state(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_solve_state_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_solve_time(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_solve_time_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_tes_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_tes_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_thermeff_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_thermeff_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_disp_wpb_expected(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_disp_wpb_expected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dni_costh(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_dni_costh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_dot_field_int_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_e_dot_field_int_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour_day(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_hour_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_htf_pump_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_htf_pump_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_sb_allowed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_is_pc_sb_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_pc_su_allowed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_is_pc_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_is_rec_su_allowed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_is_rec_su_allowed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysical_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_delivered(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_field_delivered_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_recirc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_field_recirc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_loop(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_loop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_ch(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_dc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_water_pc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_m_dot_water_pc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_n_op_modes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_n_op_modes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_a(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_operating_modes_a_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_b(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_operating_modes_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_operating_modes_c(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_operating_modes_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_P_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_T_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_diams(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_expansions(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_expansions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_lengths(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_lengths_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_mdot_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_vel_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_header_wallthk(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_header_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_loop_P_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_loop_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_loop_T_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_loop_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_P_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_T_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_diams(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_expansions(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_expansions_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_lengths(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_lengths_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_mdot_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_vel_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_runner_wallthk(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_runner_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_P_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_P_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_T_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_T_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_diams(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_diams_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_mdot_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_mdot_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_vel_dsn(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_vel_dsn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pipe_tes_wallthk(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pipe_tes_wallthk_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pricing_mult(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_pricing_mult_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_ch_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dc_tes(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_on(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_cr_on_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_cr_su(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_cr_su_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_ch(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_tes_ch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_est_tes_dc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_est_tes_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_freeze_prot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_freeze_prot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_htf_sf_out(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_htf_sf_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_max(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_min(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_min_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_sb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_sb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_pc_target(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_pc_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_piping_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_piping_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_abs(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_rec_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_thermal_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_dot_rec_thermal_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_sf_tot(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_inc_sf_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_pc_startup(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_pc_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_tes_heater(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_q_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_qinc_costh(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_qinc_costh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_recirculating(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_recirculating_aget, self->data_ptr);
}

static PyObject *
Outputs_get_rh(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysical_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"CosTh_ave", (getter)Outputs_get_CosTh_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector cosine efficiency"),
 	NULL},
{"EndLoss_ave", (getter)Outputs_get_EndLoss_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector optical end loss"),
 	NULL},
{"EqOpteff", (getter)Outputs_get_EqOpteff,(setter)0,
	PyDoc_STR("*sequence*: Field optical efficiency before defocus"),
 	NULL},
{"IAM_ave", (getter)Outputs_get_IAM_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector incidence angle modifier"),
 	NULL},
{"P_cooling_tower_tot", (getter)Outputs_get_P_cooling_tower_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"P_cycle", (getter)Outputs_get_P_cycle,(setter)0,
	PyDoc_STR("*sequence*: PC electrical power output: gross [MWe]"),
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
{"RowShadow_ave", (getter)Outputs_get_RowShadow_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector row shadowing loss"),
 	NULL},
{"SCAs_def", (getter)Outputs_get_SCAs_def,(setter)0,
	PyDoc_STR("*sequence*: Field fraction of focused SCAs"),
 	NULL},
{"T_field_cold_in", (getter)Outputs_get_T_field_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_field_hot_out", (getter)Outputs_get_T_field_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_pc_in", (getter)Outputs_get_T_pc_in,(setter)0,
	PyDoc_STR("*sequence*: PC HTF inlet temperature [C]"),
 	NULL},
{"T_pc_out", (getter)Outputs_get_T_pc_out,(setter)0,
	PyDoc_STR("*sequence*: PC HTF outlet temperature [C]"),
 	NULL},
{"T_rec_cold_in", (getter)Outputs_get_T_rec_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_rec_hot_out", (getter)Outputs_get_T_rec_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"Theta_ave", (getter)Outputs_get_Theta_ave,(setter)0,
	PyDoc_STR("*sequence*: Field collector solar incidence angle [deg]"),
 	NULL},
{"W_dot_field_pump", (getter)Outputs_get_W_dot_field_pump,(setter)0,
	PyDoc_STR("*sequence*: Field htf pumping power [MWe]"),
 	NULL},
{"W_dot_sca_track", (getter)Outputs_get_W_dot_sca_track,(setter)0,
	PyDoc_STR("*sequence*: Field collector tracking power [MWe]"),
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Electrical source - Power cycle gross output [kWhe]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Net Electrical Energy Production w/ avail derate [kWe-hr]"),
 	NULL},
{"annual_field_freeze_protection", (getter)Outputs_get_annual_field_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for field freeze protection [kWt-hr]"),
 	NULL},
{"annual_gross_energy", (getter)Outputs_get_annual_gross_energy,(setter)0,
	PyDoc_STR("*float*: Annual Gross Electrical Energy Production w/ avail derate [kWe-hr]"),
 	NULL},
{"annual_tes_freeze_protection", (getter)Outputs_get_annual_tes_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for TES freeze protection [kWt-hr]"),
 	NULL},
{"annual_thermal_consumption", (getter)Outputs_get_annual_thermal_consumption,(setter)0,
	PyDoc_STR("*float*: Annual thermal freeze protection required [kWt-hr]"),
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	PyDoc_STR("*float*: Total Annual Water Usage [m^3]"),
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
{"deltaP_field", (getter)Outputs_get_deltaP_field,(setter)0,
	PyDoc_STR("*sequence*: Field pressure drop [bar]"),
 	NULL},
{"disp_obj_relax", (getter)Outputs_get_disp_obj_relax,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function - relaxed max"),
 	NULL},
{"disp_objective", (getter)Outputs_get_disp_objective,(setter)0,
	PyDoc_STR("*sequence*: Dispatch objective function value"),
 	NULL},
{"disp_pceff_expected", (getter)Outputs_get_disp_pceff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power cycle efficiency adj."),
 	NULL},
{"disp_presolve_nconstr", (getter)Outputs_get_disp_presolve_nconstr,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of constraints in problem"),
 	NULL},
{"disp_presolve_nvar", (getter)Outputs_get_disp_presolve_nvar,(setter)0,
	PyDoc_STR("*sequence*: Dispatch number of variables in problem"),
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
{"disp_tes_expected", (getter)Outputs_get_disp_tes_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected TES charge level [MWht]"),
 	NULL},
{"disp_thermeff_expected", (getter)Outputs_get_disp_thermeff_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected SF thermal efficiency adj."),
 	NULL},
{"disp_wpb_expected", (getter)Outputs_get_disp_wpb_expected,(setter)0,
	PyDoc_STR("*sequence*: Dispatch expected power generation [MWe]"),
 	NULL},
{"dni_costh", (getter)Outputs_get_dni_costh,(setter)0,
	PyDoc_STR("*sequence*: Field collector DNI-cosine product [W/m2]"),
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge state [MWht]"),
 	NULL},
{"e_dot_field_int_energy", (getter)Outputs_get_e_dot_field_int_energy,(setter)0,
	PyDoc_STR("*sequence*: Field change in material/htf internal energy [MWt]"),
 	NULL},
{"eta", (getter)Outputs_get_eta,(setter)0,
	PyDoc_STR("*sequence*: PC efficiency: gross"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid w/ avail. derate [kWe]"),
 	NULL},
{"hour_day", (getter)Outputs_get_hour_day,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
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
{"m_dot_field_delivered", (getter)Outputs_get_m_dot_field_delivered,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow delivered [kg/s]"),
 	NULL},
{"m_dot_field_recirc", (getter)Outputs_get_m_dot_field_recirc,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow recirculated [kg/s]"),
 	NULL},
{"m_dot_loop", (getter)Outputs_get_m_dot_loop,(setter)0,
	PyDoc_STR("*sequence*: Receiver mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc", (getter)Outputs_get_m_dot_pc,(setter)0,
	PyDoc_STR("*sequence*: PC HTF mass flow rate [kg/s]"),
 	NULL},
{"m_dot_tes_ch", (getter)Outputs_get_m_dot_tes_ch,(setter)0,
	PyDoc_STR("*sequence*: TES charge mass flow rate [kg/s]"),
 	NULL},
{"m_dot_tes_dc", (getter)Outputs_get_m_dot_tes_dc,(setter)0,
	PyDoc_STR("*sequence*: TES discharge mass flow rate [kg/s]"),
 	NULL},
{"m_dot_water_pc", (getter)Outputs_get_m_dot_water_pc,(setter)0,
	PyDoc_STR("*sequence*: PC water consumption: makeup + cooling [kg/s]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
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
{"pipe_header_P_dsn", (getter)Outputs_get_pipe_header_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header pressure at design [bar]"),
 	NULL},
{"pipe_header_T_dsn", (getter)Outputs_get_pipe_header_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header temperature at design [C]"),
 	NULL},
{"pipe_header_diams", (getter)Outputs_get_pipe_header_diams,(setter)0,
	PyDoc_STR("*sequence*: Field piping header diameters [m]"),
 	NULL},
{"pipe_header_expansions", (getter)Outputs_get_pipe_header_expansions,(setter)0,
	PyDoc_STR("*sequence*: Number of field piping header expansions [-]"),
 	NULL},
{"pipe_header_lengths", (getter)Outputs_get_pipe_header_lengths,(setter)0,
	PyDoc_STR("*sequence*: Field piping header lengths [m]"),
 	NULL},
{"pipe_header_mdot_dsn", (getter)Outputs_get_pipe_header_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header mass flow at design [kg/s]"),
 	NULL},
{"pipe_header_vel_dsn", (getter)Outputs_get_pipe_header_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping header velocity at design [m/s]"),
 	NULL},
{"pipe_header_wallthk", (getter)Outputs_get_pipe_header_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Field piping header wall thicknesses [m]"),
 	NULL},
{"pipe_loop_P_dsn", (getter)Outputs_get_pipe_loop_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping loop pressure at design [bar]"),
 	NULL},
{"pipe_loop_T_dsn", (getter)Outputs_get_pipe_loop_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping loop temperature at design [C]"),
 	NULL},
{"pipe_runner_P_dsn", (getter)Outputs_get_pipe_runner_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner pressure at design [bar]"),
 	NULL},
{"pipe_runner_T_dsn", (getter)Outputs_get_pipe_runner_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner temperature at design [C]"),
 	NULL},
{"pipe_runner_diams", (getter)Outputs_get_pipe_runner_diams,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner diameters [m]"),
 	NULL},
{"pipe_runner_expansions", (getter)Outputs_get_pipe_runner_expansions,(setter)0,
	PyDoc_STR("*sequence*: Number of field piping runner expansions [-]"),
 	NULL},
{"pipe_runner_lengths", (getter)Outputs_get_pipe_runner_lengths,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner lengths [m]"),
 	NULL},
{"pipe_runner_mdot_dsn", (getter)Outputs_get_pipe_runner_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner mass flow at design [kg/s]"),
 	NULL},
{"pipe_runner_vel_dsn", (getter)Outputs_get_pipe_runner_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner velocity at design [m/s]"),
 	NULL},
{"pipe_runner_wallthk", (getter)Outputs_get_pipe_runner_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Field piping runner wall thicknesses [m]"),
 	NULL},
{"pipe_tes_P_dsn", (getter)Outputs_get_pipe_tes_P_dsn,(setter)0,
	PyDoc_STR("*sequence*: Pressure in TES pipes at design conditions [bar]"),
 	NULL},
{"pipe_tes_T_dsn", (getter)Outputs_get_pipe_tes_T_dsn,(setter)0,
	PyDoc_STR("*sequence*: Temperature in TES pipes at design conditions [C]"),
 	NULL},
{"pipe_tes_diams", (getter)Outputs_get_pipe_tes_diams,(setter)0,
	PyDoc_STR("*sequence*: Pipe diameters in TES [m]"),
 	NULL},
{"pipe_tes_mdot_dsn", (getter)Outputs_get_pipe_tes_mdot_dsn,(setter)0,
	PyDoc_STR("*sequence*: Mass flow TES pipes at design conditions [kg/s]"),
 	NULL},
{"pipe_tes_vel_dsn", (getter)Outputs_get_pipe_tes_vel_dsn,(setter)0,
	PyDoc_STR("*sequence*: Velocity in TES pipes at design conditions [m/s]"),
 	NULL},
{"pipe_tes_wallthk", (getter)Outputs_get_pipe_tes_wallthk,(setter)0,
	PyDoc_STR("*sequence*: Pipe wall thickness in TES [m]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
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
{"q_dot_freeze_prot", (getter)Outputs_get_q_dot_freeze_prot,(setter)0,
	PyDoc_STR("*sequence*: Field freeze protection required [MWt]"),
 	NULL},
{"q_dot_htf_sf_out", (getter)Outputs_get_q_dot_htf_sf_out,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power leaving in HTF [MWt]"),
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
{"q_dot_piping_loss", (getter)Outputs_get_q_dot_piping_loss,(setter)0,
	PyDoc_STR("*sequence*: Field piping thermal losses [MWt]"),
 	NULL},
{"q_dot_rec_abs", (getter)Outputs_get_q_dot_rec_abs,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power absorbed [MWt]"),
 	NULL},
{"q_dot_rec_inc", (getter)Outputs_get_q_dot_rec_inc,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal power incident [MWt]"),
 	NULL},
{"q_dot_rec_thermal_loss", (getter)Outputs_get_q_dot_rec_thermal_loss,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal losses [MWt]"),
 	NULL},
{"q_inc_sf_tot", (getter)Outputs_get_q_inc_sf_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_pb", (getter)Outputs_get_q_pb,(setter)0,
	PyDoc_STR("*sequence*: PC input energy [MWt]"),
 	NULL},
{"q_pc_startup", (getter)Outputs_get_q_pc_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal energy [MWht]"),
 	NULL},
{"q_tes_heater", (getter)Outputs_get_q_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"qinc_costh", (getter)Outputs_get_qinc_costh,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident after cosine [MWt]"),
 	NULL},
{"recirculating", (getter)Outputs_get_recirculating,(setter)0,
	PyDoc_STR("*sequence*: Field recirculating (bypass valve open) [-]"),
 	NULL},
{"rh", (getter)Outputs_get_rh,(setter)0,
	PyDoc_STR("*sequence*: Resource Relative Humidity [%]"),
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Azimuth [deg]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"tank_losses", (getter)Outputs_get_tank_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: CSP operating Time-of-use value"),
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
		"TroughPhysical.Outputs",             /*tp_name*/
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
 * TroughPhysical
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_TroughPhysical   data_ptr;
} TroughPhysicalObject;

static PyTypeObject TroughPhysical_Type;

static TroughPhysicalObject *
newTroughPhysicalObject(void* data_ptr)
{
	TroughPhysicalObject *self;
	self = PyObject_New(TroughPhysicalObject, &TroughPhysical_Type);

	PySAM_TECH_ATTR("TroughPhysical", SAM_TroughPhysical_construct)

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* TES_obj = TES_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TES", TES_obj);
	Py_DECREF(TES_obj);

	PyObject* Tou_obj = Tou_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Tou", Tou_obj);
	Py_DECREF(Tou_obj);

	PyObject* System_obj = System_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "System", System_obj);
	Py_DECREF(System_obj);

	PyObject* Controller_obj = Controller_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controller", Controller_obj);
	Py_DECREF(Controller_obj);

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

/* TroughPhysical methods */

static void
TroughPhysical_dealloc(TroughPhysicalObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_TroughPhysical_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
TroughPhysical_execute(TroughPhysicalObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TroughPhysical_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TroughPhysical_assign(TroughPhysicalObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysical"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TroughPhysical_export(TroughPhysicalObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef TroughPhysical_methods[] = {
		{"execute",            (PyCFunction)TroughPhysical_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TroughPhysical_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TroughPhysical_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TroughPhysical_getattro(TroughPhysicalObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TroughPhysical_setattr(TroughPhysicalObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TroughPhysical_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysical",            /*tp_name*/
		sizeof(TroughPhysicalObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TroughPhysical_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TroughPhysical_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TroughPhysical_getattro, /*tp_getattro*/
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
		TroughPhysical_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TroughPhysical object */

static PyObject *
TroughPhysical_new(PyObject *self, PyObject *args)
{
	TroughPhysicalObject *rv;
	rv = newTroughPhysicalObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysical_wrap(PyObject *self, PyObject *args)
{
	TroughPhysicalObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysical_default(PyObject *self, PyObject *args)
{
	TroughPhysicalObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysical", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TroughPhysicalModule_methods[] = {
		{"new",             TroughPhysical_new,         METH_VARARGS,
				PyDoc_STR("new() -> TroughPhysical")},
		{"default",             TroughPhysical_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TroughPhysical\n\nUse financial model-specific default attributes\n"
				"config options:\n\n- \"PhysicalTroughAllEquityPartnershipFlip\"\n- \"PhysicalTroughCommercial\"\n- \"PhysicalTroughIndependentPowerProducer\"\n- \"PhysicalTroughLCOECalculator\"\n- \"PhysicalTroughLeveragedPartnershipFlip\"\n- \"PhysicalTroughNone\"\n- \"PhysicalTroughSaleLeaseback\"\n- \"PhysicalTroughSingleOwner\"")},
		{"wrap",             TroughPhysical_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TroughPhysical\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CSP parabolic trough model based on heat transfer and thermodynamic principles for power generation");


static int
TroughPhysicalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	TroughPhysical_Type.tp_dict = PyDict_New();
	if (!TroughPhysical_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TroughPhysical_Type
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
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TroughPhysical_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the SolarField type object to TroughPhysical_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the Powerblock type object to TroughPhysical_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the TES type object to TroughPhysical_Type
	if (PyType_Ready(&TES_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"TES",
				(PyObject*)&TES_Type);
	Py_DECREF(&TES_Type);

	/// Add the Tou type object to TroughPhysical_Type
	if (PyType_Ready(&Tou_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Tou",
				(PyObject*)&Tou_Type);
	Py_DECREF(&Tou_Type);

	/// Add the System type object to TroughPhysical_Type
	if (PyType_Ready(&System_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"System",
				(PyObject*)&System_Type);
	Py_DECREF(&System_Type);

	/// Add the Controller type object to TroughPhysical_Type
	if (PyType_Ready(&Controller_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Controller",
				(PyObject*)&Controller_Type);
	Py_DECREF(&Controller_Type);

	/// Add the Outputs type object to TroughPhysical_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysical_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TroughPhysical type object to the module
	if (PyType_Ready(&TroughPhysical_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TroughPhysical",
				(PyObject*)&TroughPhysical_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TroughPhysicalModule_slots[] = {
		{Py_mod_exec, TroughPhysicalModule_exec},
		{0, NULL},
};

static struct PyModuleDef TroughPhysicalModule = {
		PyModuleDef_HEAD_INIT,
		"TroughPhysical",
		module_doc,
		0,
		TroughPhysicalModule_methods,
		TroughPhysicalModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TroughPhysical(void)
{
	return PyModuleDef_Init(&TroughPhysicalModule);
}