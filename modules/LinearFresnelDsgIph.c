#include <Python.h>

#include <SAM_LinearFresnelDsgIph.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_LinearFresnelDsgIph data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "Weather")){
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
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_LinearFresnelDsgIph_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_LinearFresnelDsgIph_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_LinearFresnelDsgIph_Weather_solar_resource_data_tget, self->data_ptr);
}

static int
Weather_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_LinearFresnelDsgIph_Weather_solar_resource_data_tset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: local weather file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nTrue"),
 	NULL},
{"solar_resource_data", (getter)Weather_get_solar_resource_data,(setter)Weather_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather resource data in memory\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph.Weather",             /*tp_name*/
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
 * Solarfield Group
 */ 

static PyTypeObject Solarfield_Type;

static PyObject *
Solarfield_new(SAM_LinearFresnelDsgIph data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "Solarfield")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "Solarfield")){
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
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_A_aperture_mget, self->data_ptr);
}

static int
Solarfield_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_A_aperture_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_AbsorberMaterial_mget, self->data_ptr);
}

static int
Solarfield_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_AnnulusGas_mget, self->data_ptr);
}

static int
Solarfield_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_ColAz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_ColAz_nget, self->data_ptr);
}

static int
Solarfield_set_ColAz(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_ColAz_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_D_2_mget, self->data_ptr);
}

static int
Solarfield_set_D_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_D_2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_D_3_mget, self->data_ptr);
}

static int
Solarfield_set_D_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_D_3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_D_4_mget, self->data_ptr);
}

static int
Solarfield_set_D_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_D_4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_D_5_mget, self->data_ptr);
}

static int
Solarfield_set_D_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_D_5_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_D_p(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_D_p_mget, self->data_ptr);
}

static int
Solarfield_set_D_p(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_D_p_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_Design_loss_mget, self->data_ptr);
}

static int
Solarfield_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Design_loss_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Dirt_HCE(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_Dirt_HCE_mget, self->data_ptr);
}

static int
Solarfield_set_Dirt_HCE(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_EPSILON_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_EPSILON_4_mget, self->data_ptr);
}

static int
Solarfield_set_EPSILON_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_Flow_type_mget, self->data_ptr);
}

static int
Solarfield_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Flow_type_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_GeomEffects_mget, self->data_ptr);
}

static int
Solarfield_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_GeomEffects_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_GlazingIntactIn_mget, self->data_ptr);
}

static int
Solarfield_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_HCE_FieldFrac_mget, self->data_ptr);
}

static int
Solarfield_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HLCharType(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_HLCharType_mget, self->data_ptr);
}

static int
Solarfield_set_HLCharType(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_HLCharType_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HL_W(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_HL_W_mget, self->data_ptr);
}

static int
Solarfield_set_HL_W(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_HL_W_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_HL_dT(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_HL_dT_mget, self->data_ptr);
}

static int
Solarfield_set_HL_dT(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_HL_dT_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_IAM_L(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_IAM_L_mget, self->data_ptr);
}

static int
Solarfield_set_IAM_L(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_IAM_L_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_IAM_T(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_IAM_T_mget, self->data_ptr);
}

static int
Solarfield_set_IAM_T(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_IAM_T_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_I_bn_des_nget, self->data_ptr);
}

static int
Solarfield_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_I_bn_des_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_L_col(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_L_col_mget, self->data_ptr);
}

static int
Solarfield_set_L_col(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_L_col_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_OptCharType(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_OptCharType_mget, self->data_ptr);
}

static int
Solarfield_set_OptCharType(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_OptCharType_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_P_a_mget, self->data_ptr);
}

static int
Solarfield_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_P_a_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_P_turb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_P_turb_des_nget, self->data_ptr);
}

static int
Solarfield_set_P_turb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_P_turb_des_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_Pipe_hl_coef_nget, self->data_ptr);
}

static int
Solarfield_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_Rough_mget, self->data_ptr);
}

static int
Solarfield_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Rough_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_SCA_drives_elec_nget, self->data_ptr);
}

static int
Solarfield_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_Shadowing_mget, self->data_ptr);
}

static int
Solarfield_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Shadowing_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_amb_des_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_T_amb_des_sf_nget, self->data_ptr);
}

static int
Solarfield_set_T_amb_des_sf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_T_amb_des_sf_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_T_fp_nget, self->data_ptr);
}

static int
Solarfield_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_T_fp_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_Tau_envelope_mget, self->data_ptr);
}

static int
Solarfield_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_TrackingError_mget, self->data_ptr);
}

static int
Solarfield_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_TrackingError_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_V_wind_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_V_wind_max_nget, self->data_ptr);
}

static int
Solarfield_set_V_wind_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_V_wind_max_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_alpha_abs_mget, self->data_ptr);
}

static int
Solarfield_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_alpha_abs_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_alpha_env_mget, self->data_ptr);
}

static int
Solarfield_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_alpha_env_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_b_OpticalTable_mget, self->data_ptr);
}

static int
Solarfield_set_b_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_b_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE1(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE1_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE1(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE1_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE2_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE3_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_b_eps_HCE4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE4_mget, self->data_ptr);
}

static int
Solarfield_set_b_eps_HCE4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_b_eps_HCE4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_deltaT_subcooled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_deltaT_subcooled_nget, self->data_ptr);
}

static int
Solarfield_set_deltaT_subcooled(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_deltaT_subcooled_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_dirt_mirror_mget, self->data_ptr);
}

static int
Solarfield_set_dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_dirt_mirror_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_e_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_e_startup_nget, self->data_ptr);
}

static int
Solarfield_set_e_startup(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_e_startup_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_error(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_error_mget, self->data_ptr);
}

static int
Solarfield_set_error(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_error_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_eta_pump_nget, self->data_ptr);
}

static int
Solarfield_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_eta_pump_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_hdr_c(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_fP_hdr_c_nget, self->data_ptr);
}

static int
Solarfield_set_fP_hdr_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_fP_hdr_c_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_hdr_h(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_fP_hdr_h_nget, self->data_ptr);
}

static int
Solarfield_set_fP_hdr_h(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_fP_hdr_h_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_fP_sf_boil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_fP_sf_boil_nget, self->data_ptr);
}

static int
Solarfield_set_fP_sf_boil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_fP_sf_boil_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_nLoops_nget, self->data_ptr);
}

static int
Solarfield_set_nLoops(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_nLoops_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_nModBoil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_nModBoil_nget, self->data_ptr);
}

static int
Solarfield_set_nModBoil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_nModBoil_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_q_pb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_q_pb_des_nget, self->data_ptr);
}

static int
Solarfield_set_q_pb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_q_pb_des_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_rho_mirror_clean(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_rho_mirror_clean_mget, self->data_ptr);
}

static int
Solarfield_set_rho_mirror_clean(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_rho_mirror_clean_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_OpticalTable(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_sh_OpticalTable_mget, self->data_ptr);
}

static int
Solarfield_set_sh_OpticalTable(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_sh_OpticalTable_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE1(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE1_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE1(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE1_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE2_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE2_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE3_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE3_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_sh_eps_HCE4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE4_mget, self->data_ptr);
}

static int
Solarfield_set_sh_eps_HCE4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_Solarfield_sh_eps_HCE4_mset, self->data_ptr);
}

static PyObject *
Solarfield_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_theta_dep_nget, self->data_ptr);
}

static int
Solarfield_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_theta_dep_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_theta_stow_nget, self->data_ptr);
}

static int
Solarfield_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_theta_stow_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_use_quality_or_subcooled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_use_quality_or_subcooled_nget, self->data_ptr);
}

static int
Solarfield_set_use_quality_or_subcooled(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_use_quality_or_subcooled_nset, self->data_ptr);
}

static PyObject *
Solarfield_get_x_b_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Solarfield_x_b_des_nget, self->data_ptr);
}

static int
Solarfield_set_x_b_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Solarfield_x_b_des_nset, self->data_ptr);
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
	PyDoc_STR("*float*: Collector azimuth angle [deg]\n\n**Required:**\nTrue"),
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
{"I_bn_des", (getter)Solarfield_get_I_bn_des,(setter)Solarfield_set_I_bn_des,
	PyDoc_STR("*float*: Design point irradiation value [W/m2]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``I_bn_des``:\n\n\t - nLoops\n"),
 	NULL},
{"L_col", (getter)Solarfield_get_L_col,(setter)Solarfield_set_L_col,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Active length of the superheater section collector module [m]\n\n**Required:**\nTrue"),
 	NULL},
{"OptCharType", (getter)Solarfield_get_OptCharType,(setter)Solarfield_set_OptCharType,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) The optical characterization method [none]\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)Solarfield_get_P_a,(setter)Solarfield_set_P_a,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Annulus gas pressure (4: # field fracs) [torr]\n\n**Required:**\nTrue"),
 	NULL},
{"P_turb_des", (getter)Solarfield_get_P_turb_des,(setter)Solarfield_set_P_turb_des,
	PyDoc_STR("*float*: Design-point turbine inlet pressure [bar]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``P_turb_des``:\n\n\t - nLoops\n"),
 	NULL},
{"Pipe_hl_coef", (getter)Solarfield_get_Pipe_hl_coef,(setter)Solarfield_set_Pipe_hl_coef,
	PyDoc_STR("*float*: Loss coefficient from the header.. runner pipe.. and non-HCE pipin [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
{"Rough", (getter)Solarfield_get_Rough,(setter)Solarfield_set_Rough,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Roughness of the internal surface [m]\n\n**Required:**\nTrue"),
 	NULL},
{"SCA_drives_elec", (getter)Solarfield_get_SCA_drives_elec,(setter)Solarfield_set_SCA_drives_elec,
	PyDoc_STR("*float*: Tracking power.. in Watts per m2 [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"Shadowing", (getter)Solarfield_get_Shadowing,(setter)Solarfield_set_Shadowing,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Receiver bellows shadowing loss factor (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"T_amb_des_sf", (getter)Solarfield_get_T_amb_des_sf,(setter)Solarfield_set_T_amb_des_sf,
	PyDoc_STR("*float*: Design-point ambient temperature [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_amb_des_sf``:\n\n\t - nLoops\n"),
 	NULL},
{"T_fp", (getter)Solarfield_get_T_fp,(setter)Solarfield_set_T_fp,
	PyDoc_STR("*float*: Freeze protection temperature (heat trace activation temperature) [C]\n\n**Required:**\nTrue"),
 	NULL},
{"Tau_envelope", (getter)Solarfield_get_Tau_envelope,(setter)Solarfield_set_Tau_envelope,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) Envelope transmittance (4: # field fracs) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)Solarfield_get_TrackingError,(setter)Solarfield_set_TrackingError,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined tracking error derate [none]\n\n**Required:**\nTrue"),
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
{"deltaT_subcooled", (getter)Solarfield_get_deltaT_subcooled,(setter)Solarfield_set_deltaT_subcooled,
	PyDoc_STR("*float*: Subcooled temperature difference from saturation temp [C]\n\n**Required:**\nFalse. Automatically set to 1.23 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``deltaT_subcooled``:\n\n\t - nLoops\n"),
 	NULL},
{"dirt_mirror", (getter)Solarfield_get_dirt_mirror,(setter)Solarfield_set_dirt_mirror,
	PyDoc_STR("*sequence[sequence]*: (boiler, SH) User-defined dirt on mirror derate [none]\n\n**Required:**\nTrue"),
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
{"fP_hdr_c", (getter)Solarfield_get_fP_hdr_c,(setter)Solarfield_set_fP_hdr_c,
	PyDoc_STR("*float*: Average design-point cold header pressure drop fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_hdr_h", (getter)Solarfield_get_fP_hdr_h,(setter)Solarfield_set_fP_hdr_h,
	PyDoc_STR("*float*: Average design-point hot header pressure drop fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"fP_sf_boil", (getter)Solarfield_get_fP_sf_boil,(setter)Solarfield_set_fP_sf_boil,
	PyDoc_STR("*float*: Design-point pressure drop across the solar field boiler fraction [none]\n\n**Required:**\nTrue"),
 	NULL},
{"nLoops", (getter)Solarfield_get_nLoops,(setter)Solarfield_set_nLoops,
	PyDoc_STR("*float*: Number of loops [none]\n\n**Required:**\nTrue\n\nThe value of ``nLoops`` depends on the following variables:\n\n\t - I_bn_des\n\t - P_turb_des\n\t - T_amb_des_sf\n\t - T_cold_ref\n\t - deltaT_subcooled\n\t - nModBoil\n\t - q_pb_des\n\t - use_quality_or_subcooled\n"),
 	NULL},
{"nModBoil", (getter)Solarfield_get_nModBoil,(setter)Solarfield_set_nModBoil,
	PyDoc_STR("*float*: Number of modules in the boiler section [none]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``nModBoil``:\n\n\t - nLoops\n"),
 	NULL},
{"q_pb_des", (getter)Solarfield_get_q_pb_des,(setter)Solarfield_set_q_pb_des,
	PyDoc_STR("*float*: Design heat input to the power block [MW]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``q_pb_des``:\n\n\t - nLoops\n"),
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
{"theta_dep", (getter)Solarfield_get_theta_dep,(setter)Solarfield_set_theta_dep,
	PyDoc_STR("*float*: deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)Solarfield_get_theta_stow,(setter)Solarfield_set_theta_stow,
	PyDoc_STR("*float*: stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"use_quality_or_subcooled", (getter)Solarfield_get_use_quality_or_subcooled,(setter)Solarfield_set_use_quality_or_subcooled,
	PyDoc_STR("*float*: 0 = 2 phase outlet, 1 = subcooled\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``use_quality_or_subcooled``:\n\n\t - nLoops\n"),
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
		"LinearFresnelDsgIph.Solarfield",             /*tp_name*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_LinearFresnelDsgIph data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "Powerblock")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "Powerblock")){
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
Powerblock_get_T_cold_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Powerblock_T_cold_ref_nget, self->data_ptr);
}

static int
Powerblock_set_T_cold_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Powerblock_T_cold_ref_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"T_cold_ref", (getter)Powerblock_get_T_cold_ref,(setter)Powerblock_set_T_cold_ref,
	PyDoc_STR("*float*: Reference HTF outlet temperature at design [C]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``T_cold_ref``:\n\n\t - nLoops\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph.Powerblock",             /*tp_name*/
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
 * Heliostat Group
 */ 

static PyTypeObject Heliostat_Type;

static PyObject *
Heliostat_new(SAM_LinearFresnelDsgIph data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "Heliostat")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "Heliostat")){
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
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Heliostat_csp_lf_sf_washes_per_year_nget, self->data_ptr);
}

static int
Heliostat_set_csp_lf_sf_washes_per_year(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Heliostat_csp_lf_sf_washes_per_year_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_lf_sf_water_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Heliostat_csp_lf_sf_water_per_wash_nget, self->data_ptr);
}

static int
Heliostat_set_csp_lf_sf_water_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_Heliostat_csp_lf_sf_water_per_wash_nset, self->data_ptr);
}

static PyGetSetDef Heliostat_getset[] = {
{"csp_lf_sf_washes_per_year", (getter)Heliostat_get_csp_lf_sf_washes_per_year,(setter)Heliostat_set_csp_lf_sf_washes_per_year,
	PyDoc_STR("*float*: Mirror washing frequency [-/year]\n\n**Required:**\nTrue"),
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
		"LinearFresnelDsgIph.Heliostat",             /*tp_name*/
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
 * HeatSink Group
 */ 

static PyTypeObject HeatSink_Type;

static PyObject *
HeatSink_new(SAM_LinearFresnelDsgIph data_ptr)
{
	PyObject* new_obj = HeatSink_Type.tp_alloc(&HeatSink_Type,0);

	VarGroupObject* HeatSink_obj = (VarGroupObject*)new_obj;

	HeatSink_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* HeatSink methods */

static PyObject *
HeatSink_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "HeatSink")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HeatSink_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &HeatSink_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "HeatSink")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
HeatSink_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &HeatSink_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef HeatSink_methods[] = {
		{"assign",            (PyCFunction)HeatSink_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``HeatSink_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)HeatSink_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``HeatSink_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)HeatSink_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
HeatSink_get_heat_sink_dP_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_HeatSink_heat_sink_dP_frac_nget, self->data_ptr);
}

static int
HeatSink_set_heat_sink_dP_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_HeatSink_heat_sink_dP_frac_nset, self->data_ptr);
}

static PyGetSetDef HeatSink_getset[] = {
{"heat_sink_dP_frac", (getter)HeatSink_get_heat_sink_dP_frac,(setter)HeatSink_set_heat_sink_dP_frac,
	PyDoc_STR("*float*: Fractional pressure drop through heat sink\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject HeatSink_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph.HeatSink",             /*tp_name*/
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
		HeatSink_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		HeatSink_getset,          /*tp_getset*/
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
 * Revenue Group
 */ 

static PyTypeObject Revenue_Type;

static PyObject *
Revenue_new(SAM_LinearFresnelDsgIph data_ptr)
{
	PyObject* new_obj = Revenue_Type.tp_alloc(&Revenue_Type,0);

	VarGroupObject* Revenue_obj = (VarGroupObject*)new_obj;

	Revenue_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Revenue methods */

static PyObject *
Revenue_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "Revenue")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Revenue_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Revenue_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "Revenue")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Revenue_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Revenue_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Revenue_methods[] = {
		{"assign",            (PyCFunction)Revenue_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Revenue_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Revenue_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Revenue_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Revenue_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Revenue_get_ppa_price_input_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Revenue_ppa_price_input_heat_btu_aget, self->data_ptr);
}

static int
Revenue_set_ppa_price_input_heat_btu(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_LinearFresnelDsgIph_Revenue_ppa_price_input_heat_btu_aset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"ppa_price_input_heat_btu", (getter)Revenue_get_ppa_price_input_heat_btu,(setter)Revenue_set_ppa_price_input_heat_btu,
	PyDoc_STR("*sequence*: PPA prices - yearly [$/MMBtu]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph.Revenue",             /*tp_name*/
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
		Revenue_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Revenue_getset,          /*tp_getset*/
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
 * AdjustmentFactors Group
 */ 

static PyTypeObject AdjustmentFactors_Type;

static PyObject *
AdjustmentFactors_new(SAM_LinearFresnelDsgIph data_ptr)
{
	PyObject* new_obj = AdjustmentFactors_Type.tp_alloc(&AdjustmentFactors_Type,0);

	VarGroupObject* AdjustmentFactors_obj = (VarGroupObject*)new_obj;

	AdjustmentFactors_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* AdjustmentFactors methods */

static PyObject *
AdjustmentFactors_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "AdjustmentFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AdjustmentFactors_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &AdjustmentFactors_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "AdjustmentFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AdjustmentFactors_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &AdjustmentFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AdjustmentFactors_methods[] = {
		{"assign",            (PyCFunction)AdjustmentFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``AdjustmentFactors_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)AdjustmentFactors_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``AdjustmentFactors_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)AdjustmentFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AdjustmentFactors_get_adjust_constant(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_constant_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_constant(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_constant_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_en_periods(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_en_periods_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_en_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_en_periods_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_en_timeindex(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_en_timeindex_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_en_timeindex(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_en_timeindex_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_periods_mget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_periods_mset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_adjust_timeindex(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_timeindex_aget, self->data_ptr);
}

static int
AdjustmentFactors_set_adjust_timeindex(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_LinearFresnelDsgIph_AdjustmentFactors_adjust_timeindex_aset, self->data_ptr);
}

static PyGetSetDef AdjustmentFactors_getset[] = {
{"adjust_constant", (getter)AdjustmentFactors_get_adjust_constant,(setter)AdjustmentFactors_set_adjust_constant,
	PyDoc_STR("*float*: Constant loss adjustment [%]\n\n**Info:**\n'adjust' and 'constant' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nMAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_en_periods", (getter)AdjustmentFactors_get_adjust_en_periods,(setter)AdjustmentFactors_set_adjust_en_periods,
	PyDoc_STR("*float*: Enable period-based adjustment factors [0/1]\n\n**Info:**\n'adjust' and 'en_periods' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_en_timeindex", (getter)AdjustmentFactors_get_adjust_en_timeindex,(setter)AdjustmentFactors_set_adjust_en_timeindex,
	PyDoc_STR("*float*: Enable lifetime adjustment factors [0/1]\n\n**Info:**\n'adjust' and 'en_timeindex' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"adjust_periods", (getter)AdjustmentFactors_get_adjust_periods,(setter)AdjustmentFactors_set_adjust_periods,
	PyDoc_STR("*sequence[sequence]*: Period-based adjustment factors [%]\n\n**Info:**\nSyntax: n x 3 matrix [ start, end, loss ]; Version upgrade: 'adjust' and 'periods' separated by _ instead of : after SAM 2022.12.21\n\n**Constraints:**\nCOLS=3\n\n**Required:**\nRequired if adjust_en_periods=1"),
 	NULL},
{"adjust_timeindex", (getter)AdjustmentFactors_get_adjust_timeindex,(setter)AdjustmentFactors_set_adjust_timeindex,
	PyDoc_STR("*sequence*: Lifetime adjustment factors [%]\n\n**Info:**\n'adjust' and 'timeindex' separated by _ instead of : after SAM 2022.12.21\n\n**Required:**\nRequired if adjust_en_timeindex=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AdjustmentFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph.AdjustmentFactors",             /*tp_name*/
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
		AdjustmentFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AdjustmentFactors_getset,          /*tp_getset*/
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
Outputs_new(SAM_LinearFresnelDsgIph data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "LinearFresnelDsgIph", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "LinearFresnelDsgIph", "Outputs")){
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
Outputs_get_T_field_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_T_field_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_T_field_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_T_rec_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_T_rec_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_field_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_W_dot_field_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_heat_sink_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_W_dot_heat_sink_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_parasitic_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_W_dot_parasitic_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_sca_track(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_W_dot_sca_track_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_electricity_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_annual_electricity_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_LinearFresnelDsgIph_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_annual_energy_heat_btu_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_field_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_annual_field_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_thermal_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_annual_thermal_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cp_system_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_cp_system_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaP_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_deltaP_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_dot_field_int_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_e_dot_field_int_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_opt_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_eta_opt_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen_heat(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_gen_heat_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen_heat_btu(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_gen_heat_btu_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_hour_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_m_dot_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_loop(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_m_dot_loop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nameplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_nameplate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_ppa_price_input_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_freeze_prot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_freeze_prot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_piping_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_rec_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_thermal_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_rec_thermal_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_sf_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_sf_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_to_heat_sink(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_dot_to_heat_sink_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_sf_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_q_inc_sf_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_LinearFresnelDsgIph_Outputs_system_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_theta_longitudinal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_theta_longitudinal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_theta_traverse(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_theta_traverse_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_wspd_aget, self->data_ptr);
}

static PyObject *
Outputs_get_x_field_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_x_field_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_x_rec_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_LinearFresnelDsgIph_Outputs_x_rec_hot_out_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_field_cold_in", (getter)Outputs_get_T_field_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_field_hot_out", (getter)Outputs_get_T_field_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged outlet temperature [C]"),
 	NULL},
{"T_rec_cold_in", (getter)Outputs_get_T_rec_cold_in,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged inlet temperature [C]"),
 	NULL},
{"T_rec_hot_out", (getter)Outputs_get_T_rec_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged outlet temperature [C]"),
 	NULL},
{"W_dot_field_pump", (getter)Outputs_get_W_dot_field_pump,(setter)0,
	PyDoc_STR("*sequence*: Field htf pumping power [MWe]"),
 	NULL},
{"W_dot_heat_sink_pump", (getter)Outputs_get_W_dot_heat_sink_pump,(setter)0,
	PyDoc_STR("*sequence*: Heat sink pumping power [MWe]"),
 	NULL},
{"W_dot_parasitic_tot", (getter)Outputs_get_W_dot_parasitic_tot,(setter)0,
	PyDoc_STR("*sequence*: System total electrical parasitic [MWe]"),
 	NULL},
{"W_dot_sca_track", (getter)Outputs_get_W_dot_sca_track,(setter)0,
	PyDoc_STR("*sequence*: Field collector tracking power [MWe]"),
 	NULL},
{"annual_electricity_consumption", (getter)Outputs_get_annual_electricity_consumption,(setter)0,
	PyDoc_STR("*float*: Annual electricity consumptoin w/ avail derate [kWhe]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual net thermal energy w/ avail. derate [kWht]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_energy_heat_btu", (getter)Outputs_get_annual_energy_heat_btu,(setter)0,
	PyDoc_STR("*float*: Annual net thermal energy w/ avail. derate [MMBtu]"),
 	NULL},
{"annual_field_energy", (getter)Outputs_get_annual_field_energy,(setter)0,
	PyDoc_STR("*float*: Annual Gross Thermal Energy Production w/ avail derate [kWht]"),
 	NULL},
{"annual_thermal_consumption", (getter)Outputs_get_annual_thermal_consumption,(setter)0,
	PyDoc_STR("*float*: Annual thermal freeze protection required [kWht]"),
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
{"cp_system_nameplate", (getter)Outputs_get_cp_system_nameplate,(setter)0,
	PyDoc_STR("*float*: System capacity for capacity payments [MWt]"),
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	PyDoc_STR("*sequence*: Field collector focus fraction"),
 	NULL},
{"deltaP_field", (getter)Outputs_get_deltaP_field,(setter)0,
	PyDoc_STR("*sequence*: Field pressure drop [bar]"),
 	NULL},
{"e_dot_field_int_energy", (getter)Outputs_get_e_dot_field_int_energy,(setter)0,
	PyDoc_STR("*sequence*: Field change in material/htf internal energy [MWt]"),
 	NULL},
{"eta_opt_ave", (getter)Outputs_get_eta_opt_ave,(setter)0,
	PyDoc_STR("*sequence*: Field optical efficiency before defocus [deg]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System net electrical power w/ avail. derate [kWe]"),
 	NULL},
{"gen_heat", (getter)Outputs_get_gen_heat,(setter)0,
	PyDoc_STR("*sequence*: System net thermal power w/ avail. derate [kWt]"),
 	NULL},
{"gen_heat_btu", (getter)Outputs_get_gen_heat_btu,(setter)0,
	PyDoc_STR("*sequence*: System net thermal power w/ avail. derate [MMBtu/hr]"),
 	NULL},
{"hour_day", (getter)Outputs_get_hour_day,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWht/kWt]"),
 	NULL},
{"m_dot_field", (getter)Outputs_get_m_dot_field,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow rate [kg/s]"),
 	NULL},
{"m_dot_loop", (getter)Outputs_get_m_dot_loop,(setter)0,
	PyDoc_STR("*sequence*: Receiver mass flow rate [kg/s]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"nameplate", (getter)Outputs_get_nameplate,(setter)0,
	PyDoc_STR("*float*: Nameplate capacity [MWt]"),
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
{"ppa_price_input", (getter)Outputs_get_ppa_price_input,(setter)0,
	PyDoc_STR("*sequence*: PPA prices - yearly [$/kWh]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"q_dot_freeze_prot", (getter)Outputs_get_q_dot_freeze_prot,(setter)0,
	PyDoc_STR("*sequence*: Field freeze protection required [MWt]"),
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
{"q_dot_sf_out", (getter)Outputs_get_q_dot_sf_out,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power leaving in steam [MWt]"),
 	NULL},
{"q_dot_to_heat_sink", (getter)Outputs_get_q_dot_to_heat_sink,(setter)0,
	PyDoc_STR("*sequence*: Heat sink thermal power [MWt]"),
 	NULL},
{"q_inc_sf_tot", (getter)Outputs_get_q_inc_sf_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Azimuth [deg]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"system_capacity", (getter)Outputs_get_system_capacity,(setter)0,
	PyDoc_STR("*float*: System capacity [kWt]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"theta_longitudinal", (getter)Outputs_get_theta_longitudinal,(setter)0,
	PyDoc_STR("*sequence*: Field traverse incidence angle [deg]"),
 	NULL},
{"theta_traverse", (getter)Outputs_get_theta_traverse,(setter)0,
	PyDoc_STR("*sequence*: Field traverse incidence angle [deg]"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Resource Wind Speed [m/s]"),
 	NULL},
{"x_field_hot_out", (getter)Outputs_get_x_field_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Field timestep-averaged outlet quality"),
 	NULL},
{"x_rec_hot_out", (getter)Outputs_get_x_rec_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Loop timestep-averaged outlet quality"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph.Outputs",             /*tp_name*/
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
 * LinearFresnelDsgIph
 */

static PyTypeObject LinearFresnelDsgIph_Type;

static CmodObject *
newLinearFresnelDsgIphObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &LinearFresnelDsgIph_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* Solarfield_obj = Solarfield_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Solarfield", Solarfield_obj);
	Py_DECREF(Solarfield_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* Heliostat_obj = Heliostat_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Heliostat", Heliostat_obj);
	Py_DECREF(Heliostat_obj);

	PyObject* HeatSink_obj = HeatSink_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "HeatSink", HeatSink_obj);
	Py_DECREF(HeatSink_obj);

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* AdjustmentFactors_obj = AdjustmentFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AdjustmentFactors", AdjustmentFactors_obj);
	Py_DECREF(AdjustmentFactors_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* LinearFresnelDsgIph methods */

static void
LinearFresnelDsgIph_dealloc(CmodObject *self)
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
LinearFresnelDsgIph_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
LinearFresnelDsgIph_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_LinearFresnelDsgIph_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
LinearFresnelDsgIph_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "LinearFresnelDsgIph"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LinearFresnelDsgIph_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "LinearFresnelDsgIph"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
LinearFresnelDsgIph_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
LinearFresnelDsgIph_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
LinearFresnelDsgIph_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef LinearFresnelDsgIph_methods[] = {
		{"execute",           (PyCFunction)LinearFresnelDsgIph_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)LinearFresnelDsgIph_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)LinearFresnelDsgIph_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)LinearFresnelDsgIph_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)LinearFresnelDsgIph_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)LinearFresnelDsgIph_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)LinearFresnelDsgIph_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
LinearFresnelDsgIph_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
LinearFresnelDsgIph_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject LinearFresnelDsgIph_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"LinearFresnelDsgIph",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)LinearFresnelDsgIph_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)LinearFresnelDsgIph_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)LinearFresnelDsgIph_getattro, /*tp_getattro*/
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
		LinearFresnelDsgIph_methods,      /*tp_methods*/
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


/* Function of no arguments returning new LinearFresnelDsgIph object */

static PyObject *
LinearFresnelDsgIph_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newLinearFresnelDsgIphObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
LinearFresnelDsgIph_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLinearFresnelDsgIphObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
LinearFresnelDsgIph_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newLinearFresnelDsgIphObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "LinearFresnelDsgIph", def) < 0) {
		LinearFresnelDsgIph_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
LinearFresnelDsgIph_from_existing(PyObject *self, PyObject *args)
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

	rv = newLinearFresnelDsgIphObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "LinearFresnelDsgIph", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef LinearFresnelDsgIphModule_methods[] = {
		{"new",             LinearFresnelDsgIph_new,         METH_VARARGS,
				PyDoc_STR("new() -> LinearFresnelDsgIph")},
		{"default",             LinearFresnelDsgIph_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> LinearFresnelDsgIph\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"DSGLIPHLCOHCalculator\"*\n\n		- *\"DSGLIPHNone\"*\n\n		- *\"DSGLIPHSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             LinearFresnelDsgIph_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> LinearFresnelDsgIph\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   LinearFresnelDsgIph_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> LinearFresnelDsgIph\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Linear Fresnel model with steam heat transfer fluid for industrial process heat applications");


static int
LinearFresnelDsgIphModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	LinearFresnelDsgIph_Type.tp_dict = PyDict_New();
	if (!LinearFresnelDsgIph_Type.tp_dict) { goto fail; }

	/// Add the Weather type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the Solarfield type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&Solarfield_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"Solarfield",
				(PyObject*)&Solarfield_Type);
	Py_DECREF(&Solarfield_Type);

	/// Add the Powerblock type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the Heliostat type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&Heliostat_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"Heliostat",
				(PyObject*)&Heliostat_Type);
	Py_DECREF(&Heliostat_Type);

	/// Add the HeatSink type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&HeatSink_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"HeatSink",
				(PyObject*)&HeatSink_Type);
	Py_DECREF(&HeatSink_Type);

	/// Add the Revenue type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the AdjustmentFactors type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&AdjustmentFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"AdjustmentFactors",
				(PyObject*)&AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);

	/// Add the Outputs type object to LinearFresnelDsgIph_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(LinearFresnelDsgIph_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the LinearFresnelDsgIph type object to the module
	if (PyType_Ready(&LinearFresnelDsgIph_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"LinearFresnelDsgIph",
				(PyObject*)&LinearFresnelDsgIph_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot LinearFresnelDsgIphModule_slots[] = {
		{Py_mod_exec, LinearFresnelDsgIphModule_exec},
		{0, NULL},
};

static struct PyModuleDef LinearFresnelDsgIphModule = {
		PyModuleDef_HEAD_INIT,
		"LinearFresnelDsgIph",
		module_doc,
		0,
		LinearFresnelDsgIphModule_methods,
		LinearFresnelDsgIphModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_LinearFresnelDsgIph(void)
{
	return PyModuleDef_Init(&LinearFresnelDsgIphModule);
}