#include <Python.h>

#include <SAM_TroughPhysicalProcessHeat.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TroughPhysicalProcessHeat data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "Weather")){
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
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Weather_azimuth_nget, self->data_ptr);
}

static int
Weather_set_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Weather_azimuth_nset, self->data_ptr);
}

static PyObject *
Weather_get_file_name(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysicalProcessHeat_Weather_file_name_sget, self->data_ptr);
}

static int
Weather_set_file_name(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysicalProcessHeat_Weather_file_name_sset, self->data_ptr);
}

static PyObject *
Weather_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_TroughPhysicalProcessHeat_Weather_solar_resource_data_tget, self->data_ptr);
}

static int
Weather_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_TroughPhysicalProcessHeat_Weather_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
Weather_get_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Weather_tilt_nget, self->data_ptr);
}

static int
Weather_set_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Weather_tilt_nset, self->data_ptr);
}

static PyObject *
Weather_get_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Weather_track_mode_nget, self->data_ptr);
}

static int
Weather_set_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Weather_track_mode_nset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"azimuth", (getter)Weather_get_azimuth,(setter)Weather_set_azimuth,
	PyDoc_STR("*float*: Azimuth angle of surface/axis [none]\n\n**Required:**\nTrue"),
 	NULL},
{"file_name", (getter)Weather_get_file_name,(setter)Weather_set_file_name,
	PyDoc_STR("*str*: Local weather file with path [none]\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"solar_resource_data", (getter)Weather_get_solar_resource_data,(setter)Weather_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather resource data in memory\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
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
		"TroughPhysicalProcessHeat.Weather",             /*tp_name*/
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
 * SolarField Group
 */ 

static PyTypeObject SolarField_Type;

static PyObject *
SolarField_new(SAM_TroughPhysicalProcessHeat data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "SolarField")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "SolarField")){
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
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_A_aperture_aget, self->data_ptr);
}

static int
SolarField_set_A_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_A_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_AbsorberMaterial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_AbsorberMaterial_mget, self->data_ptr);
}

static int
SolarField_set_AbsorberMaterial(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_AbsorberMaterial_mset, self->data_ptr);
}

static PyObject *
SolarField_get_AnnulusGas(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_AnnulusGas_mget, self->data_ptr);
}

static int
SolarField_set_AnnulusGas(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_AnnulusGas_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Ave_Focal_Length(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_Ave_Focal_Length_aget, self->data_ptr);
}

static int
SolarField_set_Ave_Focal_Length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Ave_Focal_Length_aset, self->data_ptr);
}

static PyObject *
SolarField_get_ColperSCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_ColperSCA_aget, self->data_ptr);
}

static int
SolarField_set_ColperSCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_ColperSCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_D_2(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_D_2_mget, self->data_ptr);
}

static int
SolarField_set_D_2(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_D_2_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_3(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_D_3_mget, self->data_ptr);
}

static int
SolarField_set_D_3(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_D_3_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_D_4_mget, self->data_ptr);
}

static int
SolarField_set_D_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_D_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_D_5_mget, self->data_ptr);
}

static int
SolarField_set_D_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_D_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_D_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_D_cpnt(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_D_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_D_p(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_D_p_mget, self->data_ptr);
}

static int
SolarField_set_D_p(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_D_p_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Design_loss(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Design_loss_mget, self->data_ptr);
}

static int
SolarField_set_Design_loss(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Design_loss_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_HCE(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Dirt_HCE_mget, self->data_ptr);
}

static int
SolarField_set_Dirt_HCE(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Dirt_HCE_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Dirt_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_Dirt_mirror_aget, self->data_ptr);
}

static int
SolarField_set_Dirt_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Dirt_mirror_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Distance_SCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_Distance_SCA_aget, self->data_ptr);
}

static int
SolarField_set_Distance_SCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Distance_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_4(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_EPSILON_4_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_4(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_EPSILON_4_mset, self->data_ptr);
}

static PyObject *
SolarField_get_EPSILON_5(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_EPSILON_5_mget, self->data_ptr);
}

static int
SolarField_set_EPSILON_5(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_EPSILON_5_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Error(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_Error_aget, self->data_ptr);
}

static int
SolarField_set_Error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Error_aset, self->data_ptr);
}

static PyObject *
SolarField_get_FieldConfig(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_FieldConfig_nget, self->data_ptr);
}

static int
SolarField_set_FieldConfig(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_FieldConfig_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Flow_type(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Flow_type_mget, self->data_ptr);
}

static int
SolarField_set_Flow_type(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Flow_type_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Fluid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_Fluid_nget, self->data_ptr);
}

static int
SolarField_set_Fluid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Fluid_nset, self->data_ptr);
}

static PyObject *
SolarField_get_GeomEffects(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_GeomEffects_aget, self->data_ptr);
}

static int
SolarField_set_GeomEffects(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_GeomEffects_aset, self->data_ptr);
}

static PyObject *
SolarField_get_GlazingIntactIn(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_GlazingIntactIn_mget, self->data_ptr);
}

static int
SolarField_set_GlazingIntactIn(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_GlazingIntactIn_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HCE_FieldFrac(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_HCE_FieldFrac_mget, self->data_ptr);
}

static int
SolarField_set_HCE_FieldFrac(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_HCE_FieldFrac_mset, self->data_ptr);
}

static PyObject *
SolarField_get_HDR_rough(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_HDR_rough_nget, self->data_ptr);
}

static int
SolarField_set_HDR_rough(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_HDR_rough_nset, self->data_ptr);
}

static PyObject *
SolarField_get_IAM_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_IAM_matrix_mget, self->data_ptr);
}

static int
SolarField_set_IAM_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_IAM_matrix_mset, self->data_ptr);
}

static PyObject *
SolarField_get_I_bn_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_I_bn_des_nget, self->data_ptr);
}

static int
SolarField_set_I_bn_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_I_bn_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_K_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_K_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_K_cpnt(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_K_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_L_SCA(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_SCA_aget, self->data_ptr);
}

static int
SolarField_set_L_SCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_SCA_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_aperture_aget, self->data_ptr);
}

static int
SolarField_set_L_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_L_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_L_cpnt(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_L_heat_sink_piping(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_heat_sink_piping_nget, self->data_ptr);
}

static int
SolarField_set_L_heat_sink_piping(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_heat_sink_piping_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_rnr_per_xpan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_rnr_per_xpan_nget, self->data_ptr);
}

static int
SolarField_set_L_rnr_per_xpan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_rnr_per_xpan_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_xpan_hdr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_xpan_hdr_nget, self->data_ptr);
}

static int
SolarField_set_L_xpan_hdr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_xpan_hdr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_L_xpan_rnr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_L_xpan_rnr_nget, self->data_ptr);
}

static int
SolarField_set_L_xpan_rnr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_L_xpan_rnr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Min_rnr_xpans(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_Min_rnr_xpans_nget, self->data_ptr);
}

static int
SolarField_set_Min_rnr_xpans(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Min_rnr_xpans_nset, self->data_ptr);
}

static PyObject *
SolarField_get_N_hdr_per_xpan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_N_hdr_per_xpan_nget, self->data_ptr);
}

static int
SolarField_set_N_hdr_per_xpan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_N_hdr_per_xpan_nset, self->data_ptr);
}

static PyObject *
SolarField_get_N_max_hdr_diams(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_N_max_hdr_diams_nget, self->data_ptr);
}

static int
SolarField_set_N_max_hdr_diams(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_N_max_hdr_diams_nset, self->data_ptr);
}

static PyObject *
SolarField_get_P_a(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_P_a_mget, self->data_ptr);
}

static int
SolarField_set_P_a(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_P_a_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Pipe_hl_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_Pipe_hl_coef_nget, self->data_ptr);
}

static int
SolarField_set_Pipe_hl_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Pipe_hl_coef_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Rho_mirror_clean(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_Rho_mirror_clean_aget, self->data_ptr);
}

static int
SolarField_set_Rho_mirror_clean(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Rho_mirror_clean_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Rough(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Rough_mget, self->data_ptr);
}

static int
SolarField_set_Rough(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Rough_mset, self->data_ptr);
}

static PyObject *
SolarField_get_Row_Distance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_Row_Distance_nget, self->data_ptr);
}

static int
SolarField_set_Row_Distance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Row_Distance_nset, self->data_ptr);
}

static PyObject *
SolarField_get_SCA_drives_elec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_SCA_drives_elec_nget, self->data_ptr);
}

static int
SolarField_set_SCA_drives_elec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_SCA_drives_elec_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Shadowing(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Shadowing_mget, self->data_ptr);
}

static int
SolarField_set_Shadowing(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Shadowing_mset, self->data_ptr);
}

static PyObject *
SolarField_get_T_fp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_T_fp_nget, self->data_ptr);
}

static int
SolarField_set_T_fp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_T_fp_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_T_loop_in_des_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_T_loop_in_des_nset, self->data_ptr);
}

static PyObject *
SolarField_get_T_loop_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_T_loop_out_nget, self->data_ptr);
}

static int
SolarField_set_T_loop_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_T_loop_out_nset, self->data_ptr);
}

static PyObject *
SolarField_get_Tau_envelope(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Tau_envelope_mget, self->data_ptr);
}

static int
SolarField_set_Tau_envelope(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Tau_envelope_mset, self->data_ptr);
}

static PyObject *
SolarField_get_TrackingError(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_TrackingError_aget, self->data_ptr);
}

static int
SolarField_set_TrackingError(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_TrackingError_aset, self->data_ptr);
}

static PyObject *
SolarField_get_Type_cpnt(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_Type_cpnt_mget, self->data_ptr);
}

static int
SolarField_set_Type_cpnt(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_Type_cpnt_mset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_cold_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_cold_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_cold_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_cold_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_cold_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_cold_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_cold_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_cold_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_hot_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_hot_max_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_hot_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_hot_max_nset, self->data_ptr);
}

static PyObject *
SolarField_get_V_hdr_hot_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_hot_min_nget, self->data_ptr);
}

static int
SolarField_set_V_hdr_hot_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_V_hdr_hot_min_nset, self->data_ptr);
}

static PyObject *
SolarField_get_W_aperture(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_SolarField_W_aperture_aget, self->data_ptr);
}

static int
SolarField_set_W_aperture(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_W_aperture_aset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_accept_init_nget, self->data_ptr);
}

static int
SolarField_set_accept_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_accept_init_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_loc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_accept_loc_nget, self->data_ptr);
}

static int
SolarField_set_accept_loc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_accept_loc_nset, self->data_ptr);
}

static PyObject *
SolarField_get_accept_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_accept_mode_nget, self->data_ptr);
}

static int
SolarField_set_accept_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_accept_mode_nset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_abs(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_alpha_abs_mget, self->data_ptr);
}

static int
SolarField_set_alpha_abs(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_alpha_abs_mset, self->data_ptr);
}

static PyObject *
SolarField_get_alpha_env(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_alpha_env_mget, self->data_ptr);
}

static int
SolarField_set_alpha_env(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_alpha_env_mset, self->data_ptr);
}

static PyObject *
SolarField_get_calc_design_pipe_vals(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_calc_design_pipe_vals_nget, self->data_ptr);
}

static int
SolarField_set_calc_design_pipe_vals(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_calc_design_pipe_vals_nset, self->data_ptr);
}

static PyObject *
SolarField_get_custom_sf_pipe_sizes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_custom_sf_pipe_sizes_nget, self->data_ptr);
}

static int
SolarField_set_custom_sf_pipe_sizes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_custom_sf_pipe_sizes_nset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_11(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_11_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_11(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_11_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_12(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_12_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_12(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_12_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_13(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_13_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_13(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_13_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_14(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_14_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_14(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_14_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_21(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_21_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_21(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_21_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_22(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_22_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_22(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_22_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_23(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_23_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_23(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_23_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_24(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_24_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_24(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_24_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_31(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_31_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_31(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_31_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_32(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_32_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_32(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_32_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_33(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_33_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_33(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_33_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_34(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_34_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_34(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_34_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_41(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_41_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_41(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_41_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_42(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_42_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_42(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_42_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_43(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_43_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_43(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_43_mset, self->data_ptr);
}

static PyObject *
SolarField_get_epsilon_3_44(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_44_mget, self->data_ptr);
}

static int
SolarField_set_epsilon_3_44(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_epsilon_3_44_mset, self->data_ptr);
}

static PyObject *
SolarField_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_eta_pump_nget, self->data_ptr);
}

static int
SolarField_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_eta_pump_nset, self->data_ptr);
}

static PyObject *
SolarField_get_is_model_heat_sink_piping(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_is_model_heat_sink_piping_nget, self->data_ptr);
}

static int
SolarField_set_is_model_heat_sink_piping(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_is_model_heat_sink_piping_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_m_dot_htfmax_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_m_dot_htfmax_nset, self->data_ptr);
}

static PyObject *
SolarField_get_m_dot_htfmin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_m_dot_htfmin_nget, self->data_ptr);
}

static int
SolarField_set_m_dot_htfmin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_m_dot_htfmin_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_mc_bal_cold_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_cold(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_mc_bal_cold_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_mc_bal_hot_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_mc_bal_hot_nset, self->data_ptr);
}

static PyObject *
SolarField_get_mc_bal_sca(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_mc_bal_sca_nget, self->data_ptr);
}

static int
SolarField_set_mc_bal_sca(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_mc_bal_sca_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nColt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_nColt_nget, self->data_ptr);
}

static int
SolarField_set_nColt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_nColt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEVar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_nHCEVar_nget, self->data_ptr);
}

static int
SolarField_set_nHCEVar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_nHCEVar_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nHCEt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_nHCEt_nget, self->data_ptr);
}

static int
SolarField_set_nHCEt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_nHCEt_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nLoops(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_nLoops_nget, self->data_ptr);
}

static int
SolarField_set_nLoops(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_nLoops_nset, self->data_ptr);
}

static PyObject *
SolarField_get_nSCA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_nSCA_nget, self->data_ptr);
}

static int
SolarField_set_nSCA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_nSCA_nset, self->data_ptr);
}

static PyObject *
SolarField_get_northsouth_field_sep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_northsouth_field_sep_nget, self->data_ptr);
}

static int
SolarField_set_northsouth_field_sep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_northsouth_field_sep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_offset_xpan_hdr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_offset_xpan_hdr_nget, self->data_ptr);
}

static int
SolarField_set_offset_xpan_hdr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_offset_xpan_hdr_nset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_diams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_sf_hdr_diams_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_diams(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_sf_hdr_diams_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_sf_hdr_lengths_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_sf_hdr_lengths_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_hdr_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_sf_hdr_wallthicks_mget, self->data_ptr);
}

static int
SolarField_set_sf_hdr_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_sf_hdr_wallthicks_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_diams(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_sf_rnr_diams_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_diams(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_sf_rnr_diams_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_lengths(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_sf_rnr_lengths_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_lengths(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_sf_rnr_lengths_mset, self->data_ptr);
}

static PyObject *
SolarField_get_sf_rnr_wallthicks(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_SolarField_sf_rnr_wallthicks_mget, self->data_ptr);
}

static int
SolarField_set_sf_rnr_wallthicks(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_sf_rnr_wallthicks_mset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_dep(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_theta_dep_nget, self->data_ptr);
}

static int
SolarField_set_theta_dep(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_theta_dep_nset, self->data_ptr);
}

static PyObject *
SolarField_get_theta_stow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_theta_stow_nget, self->data_ptr);
}

static int
SolarField_set_theta_stow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_theta_stow_nset, self->data_ptr);
}

static PyObject *
SolarField_get_washing_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_washing_frequency_nget, self->data_ptr);
}

static int
SolarField_set_washing_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_washing_frequency_nset, self->data_ptr);
}

static PyObject *
SolarField_get_water_usage_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_water_usage_per_wash_nget, self->data_ptr);
}

static int
SolarField_set_water_usage_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_water_usage_per_wash_nset, self->data_ptr);
}

static PyObject *
SolarField_get_wind_stow_speed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SolarField_wind_stow_speed_nget, self->data_ptr);
}

static int
SolarField_set_wind_stow_speed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SolarField_wind_stow_speed_nset, self->data_ptr);
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
{"D_cpnt", (getter)SolarField_get_D_cpnt,(setter)SolarField_set_D_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component diameters, row=intc, col=cpnt [none]\n\n**Required:**\nTrue"),
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
{"K_cpnt", (getter)SolarField_get_K_cpnt,(setter)SolarField_set_K_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component minor loss coefficients, row=intc, col=cpnt [none]\n\n**Required:**\nTrue"),
 	NULL},
{"L_SCA", (getter)SolarField_get_L_SCA,(setter)SolarField_set_L_SCA,
	PyDoc_STR("*sequence*: Length of the SCA  [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_aperture", (getter)SolarField_get_L_aperture,(setter)SolarField_set_L_aperture,
	PyDoc_STR("*sequence*: Length of a single mirror/HCE unit [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_cpnt", (getter)SolarField_get_L_cpnt,(setter)SolarField_set_L_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component lengths, row=intc, col=cpnt [none]\n\n**Required:**\nTrue"),
 	NULL},
{"L_heat_sink_piping", (getter)SolarField_get_L_heat_sink_piping,(setter)SolarField_set_L_heat_sink_piping,
	PyDoc_STR("*float*: Length of piping (full mass flow) through heat sink (if applicable) [none]\n\n**Required:**\nTrue"),
 	NULL},
{"L_rnr_per_xpan", (getter)SolarField_get_L_rnr_per_xpan,(setter)SolarField_set_L_rnr_per_xpan,
	PyDoc_STR("*float*: Threshold length of straight runner pipe without an expansion loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_xpan_hdr", (getter)SolarField_get_L_xpan_hdr,(setter)SolarField_set_L_xpan_hdr,
	PyDoc_STR("*float*: Compined perpendicular lengths of each header expansion loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"L_xpan_rnr", (getter)SolarField_get_L_xpan_rnr,(setter)SolarField_set_L_xpan_rnr,
	PyDoc_STR("*float*: Compined perpendicular lengths of each runner expansion loop [m]\n\n**Required:**\nTrue"),
 	NULL},
{"Min_rnr_xpans", (getter)SolarField_get_Min_rnr_xpans,(setter)SolarField_set_Min_rnr_xpans,
	PyDoc_STR("*float*: Minimum number of expansion loops per single-diameter runner section [none]\n\n**Required:**\nTrue"),
 	NULL},
{"N_hdr_per_xpan", (getter)SolarField_get_N_hdr_per_xpan,(setter)SolarField_set_N_hdr_per_xpan,
	PyDoc_STR("*float*: Number of collector loops per expansion loop [none]\n\n**Required:**\nTrue"),
 	NULL},
{"N_max_hdr_diams", (getter)SolarField_get_N_max_hdr_diams,(setter)SolarField_set_N_max_hdr_diams,
	PyDoc_STR("*float*: Maximum number of diameters in each of the hot and cold headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"P_a", (getter)SolarField_get_P_a,(setter)SolarField_set_P_a,
	PyDoc_STR("*sequence[sequence]*: Annulus gas pressure [torr]\n\n**Required:**\nTrue"),
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
{"Tau_envelope", (getter)SolarField_get_Tau_envelope,(setter)SolarField_set_Tau_envelope,
	PyDoc_STR("*sequence[sequence]*: Envelope transmittance [none]\n\n**Required:**\nTrue"),
 	NULL},
{"TrackingError", (getter)SolarField_get_TrackingError,(setter)SolarField_set_TrackingError,
	PyDoc_STR("*sequence*: User-defined tracking error derate [none]\n\n**Required:**\nTrue"),
 	NULL},
{"Type_cpnt", (getter)SolarField_get_Type_cpnt,(setter)SolarField_set_Type_cpnt,
	PyDoc_STR("*sequence[sequence]*: Interconnect component type, row=intc, col=cpnt [none]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_cold_max", (getter)SolarField_get_V_hdr_cold_max,(setter)SolarField_set_V_hdr_cold_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the cold headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_cold_min", (getter)SolarField_get_V_hdr_cold_min,(setter)SolarField_set_V_hdr_cold_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the cold headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_hot_max", (getter)SolarField_get_V_hdr_hot_max,(setter)SolarField_set_V_hdr_hot_max,
	PyDoc_STR("*float*: Maximum HTF velocity in the hot headers at design [m/s]\n\n**Required:**\nTrue"),
 	NULL},
{"V_hdr_hot_min", (getter)SolarField_get_V_hdr_hot_min,(setter)SolarField_set_V_hdr_hot_min,
	PyDoc_STR("*float*: Minimum HTF velocity in the hot headers at design [m/s]\n\n**Required:**\nTrue"),
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
{"calc_design_pipe_vals", (getter)SolarField_get_calc_design_pipe_vals,(setter)SolarField_set_calc_design_pipe_vals,
	PyDoc_STR("*float*: Calculate temps and pressures at design conditions for runners and headers [none]\n\n**Required:**\nTrue"),
 	NULL},
{"custom_sf_pipe_sizes", (getter)SolarField_get_custom_sf_pipe_sizes,(setter)SolarField_set_custom_sf_pipe_sizes,
	PyDoc_STR("*float*: Use custom solar field pipe diams, wallthks, and lengths [none]\n\n**Required:**\nTrue"),
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
{"is_model_heat_sink_piping", (getter)SolarField_get_is_model_heat_sink_piping,(setter)SolarField_set_is_model_heat_sink_piping,
	PyDoc_STR("*float*: Should model consider piping through heat sink? [none]\n\n**Required:**\nTrue"),
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
{"northsouth_field_sep", (getter)SolarField_get_northsouth_field_sep,(setter)SolarField_set_northsouth_field_sep,
	PyDoc_STR("*float*: North/south separation between subfields. 0 = SCAs are touching [m]\n\n**Required:**\nTrue"),
 	NULL},
{"offset_xpan_hdr", (getter)SolarField_get_offset_xpan_hdr,(setter)SolarField_set_offset_xpan_hdr,
	PyDoc_STR("*float*: Location of first header expansion loop. 1 = after first collector loop [none]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_hdr_diams", (getter)SolarField_get_sf_hdr_diams,(setter)SolarField_set_sf_hdr_diams,
	PyDoc_STR("*sequence[sequence]*: Custom header diameters [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_hdr_lengths", (getter)SolarField_get_sf_hdr_lengths,(setter)SolarField_set_sf_hdr_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom header lengths [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_hdr_wallthicks", (getter)SolarField_get_sf_hdr_wallthicks,(setter)SolarField_set_sf_hdr_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom header wall thicknesses [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_rnr_diams", (getter)SolarField_get_sf_rnr_diams,(setter)SolarField_set_sf_rnr_diams,
	PyDoc_STR("*sequence[sequence]*: Custom runner diameters [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_rnr_lengths", (getter)SolarField_get_sf_rnr_lengths,(setter)SolarField_set_sf_rnr_lengths,
	PyDoc_STR("*sequence[sequence]*: Custom runner lengths [m]\n\n**Required:**\nTrue"),
 	NULL},
{"sf_rnr_wallthicks", (getter)SolarField_get_sf_rnr_wallthicks,(setter)SolarField_set_sf_rnr_wallthicks,
	PyDoc_STR("*sequence[sequence]*: Custom runner wall thicknesses [m]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_dep", (getter)SolarField_get_theta_dep,(setter)SolarField_set_theta_dep,
	PyDoc_STR("*float*: Deploy angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"theta_stow", (getter)SolarField_get_theta_stow,(setter)SolarField_set_theta_stow,
	PyDoc_STR("*float*: Stow angle [deg]\n\n**Required:**\nTrue"),
 	NULL},
{"washing_frequency", (getter)SolarField_get_washing_frequency,(setter)SolarField_set_washing_frequency,
	PyDoc_STR("*float*: Mirror washing frequency [-/year]\n\n**Required:**\nTrue"),
 	NULL},
{"water_usage_per_wash", (getter)SolarField_get_water_usage_per_wash,(setter)SolarField_set_water_usage_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n**Required:**\nTrue"),
 	NULL},
{"wind_stow_speed", (getter)SolarField_get_wind_stow_speed,(setter)SolarField_set_wind_stow_speed,
	PyDoc_STR("*float*: Trough wind stow speed [m/s]\n\n**Required:**\nFalse. Automatically set to 50 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarField_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.SolarField",             /*tp_name*/
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
Controller_new(SAM_TroughPhysicalProcessHeat data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "Controller")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "Controller")){
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
Controller_get_disp_wlim_maxspec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Controller_disp_wlim_maxspec_nget, self->data_ptr);
}

static int
Controller_set_disp_wlim_maxspec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Controller_disp_wlim_maxspec_nset, self->data_ptr);
}

static PyObject *
Controller_get_field_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_Controller_field_fl_props_mget, self->data_ptr);
}

static int
Controller_set_field_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_Controller_field_fl_props_mset, self->data_ptr);
}

static PyObject *
Controller_get_non_solar_field_land_area_multiplier(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Controller_non_solar_field_land_area_multiplier_nget, self->data_ptr);
}

static int
Controller_set_non_solar_field_land_area_multiplier(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Controller_non_solar_field_land_area_multiplier_nset, self->data_ptr);
}

static PyObject *
Controller_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Controller_pb_pump_coef_nget, self->data_ptr);
}

static int
Controller_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Controller_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
Controller_get_q_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Controller_q_pb_design_nget, self->data_ptr);
}

static int
Controller_set_q_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Controller_q_pb_design_nset, self->data_ptr);
}

static PyObject *
Controller_get_specified_solar_multiple(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Controller_specified_solar_multiple_nget, self->data_ptr);
}

static int
Controller_set_specified_solar_multiple(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Controller_specified_solar_multiple_nset, self->data_ptr);
}

static PyObject *
Controller_get_tanks_in_parallel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Controller_tanks_in_parallel_nget, self->data_ptr);
}

static int
Controller_set_tanks_in_parallel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Controller_tanks_in_parallel_nset, self->data_ptr);
}

static PyObject *
Controller_get_trough_loop_control(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Controller_trough_loop_control_aget, self->data_ptr);
}

static int
Controller_set_trough_loop_control(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_Controller_trough_loop_control_aset, self->data_ptr);
}

static PyGetSetDef Controller_getset[] = {
{"disp_wlim_maxspec", (getter)Controller_get_disp_wlim_maxspec,(setter)Controller_set_disp_wlim_maxspec,
	PyDoc_STR("*float*: disp_wlim_maxspec [-]\n\n**Required:**\nTrue"),
 	NULL},
{"field_fl_props", (getter)Controller_get_field_fl_props,(setter)Controller_set_field_fl_props,
	PyDoc_STR("*sequence[sequence]*: User defined field fluid property data [-]\n\n**Required:**\nTrue"),
 	NULL},
{"non_solar_field_land_area_multiplier", (getter)Controller_get_non_solar_field_land_area_multiplier,(setter)Controller_set_non_solar_field_land_area_multiplier,
	PyDoc_STR("*float*: non_solar_field_land_area_multiplier [-]\n\n**Required:**\nTrue"),
 	NULL},
{"pb_pump_coef", (getter)Controller_get_pb_pump_coef,(setter)Controller_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n**Required:**\nTrue"),
 	NULL},
{"q_pb_design", (getter)Controller_get_q_pb_design,(setter)Controller_set_q_pb_design,
	PyDoc_STR("*float*: Design heat input to power block [MWt]\n\n**Required:**\nTrue"),
 	NULL},
{"specified_solar_multiple", (getter)Controller_get_specified_solar_multiple,(setter)Controller_set_specified_solar_multiple,
	PyDoc_STR("*float*: specified_solar_multiple [-]\n\n**Required:**\nTrue"),
 	NULL},
{"tanks_in_parallel", (getter)Controller_get_tanks_in_parallel,(setter)Controller_set_tanks_in_parallel,
	PyDoc_STR("*float*: Tanks are in parallel, not in series, with solar field [-]\n\n**Required:**\nTrue"),
 	NULL},
{"trough_loop_control", (getter)Controller_get_trough_loop_control,(setter)Controller_set_trough_loop_control,
	PyDoc_STR("*sequence*: trough_loop_control [-]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Controller_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.Controller",             /*tp_name*/
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
 * SystemDesign Group
 */ 

static PyTypeObject SystemDesign_Type;

static PyObject *
SystemDesign_new(SAM_TroughPhysicalProcessHeat data_ptr)
{
	PyObject* new_obj = SystemDesign_Type.tp_alloc(&SystemDesign_Type,0);

	VarGroupObject* SystemDesign_obj = (VarGroupObject*)new_obj;

	SystemDesign_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemDesign methods */

static PyObject *
SystemDesign_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemDesign_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "SystemDesign")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemDesign_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemDesign_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemDesign_methods[] = {
		{"assign",            (PyCFunction)SystemDesign_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemDesign_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemDesign_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SystemDesign_tshours_nget, self->data_ptr);
}

static int
SystemDesign_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SystemDesign_tshours_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"tshours", (getter)SystemDesign_get_tshours,(setter)SystemDesign_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.SystemDesign",             /*tp_name*/
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
		SystemDesign_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemDesign_getset,          /*tp_getset*/
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

static PyTypeObject TES_Type;

static PyObject *
TES_new(SAM_TroughPhysicalProcessHeat data_ptr)
{
	PyObject* new_obj = TES_Type.tp_alloc(&TES_Type,0);

	VarGroupObject* TES_obj = (VarGroupObject*)new_obj;

	TES_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TES methods */

static PyObject *
TES_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "TES")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TES_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "TES")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TES_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TES_methods[] = {
		{"assign",            (PyCFunction)TES_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TES_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TES_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TES_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TES_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TES_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES_cold_tank_Thtr_nget, self->data_ptr);
}

static int
TES_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES_get_cold_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES_cold_tank_max_heat_nget, self->data_ptr);
}

static int
TES_set_cold_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
TES_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES_h_tank_nget, self->data_ptr);
}

static int
TES_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES_h_tank_nset, self->data_ptr);
}

static PyObject *
TES_get_init_hot_htf_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES_init_hot_htf_percent_nget, self->data_ptr);
}

static int
TES_set_init_hot_htf_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
TES_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES_tank_pairs_nget, self->data_ptr);
}

static int
TES_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES_tank_pairs_nset, self->data_ptr);
}

static PyObject *
TES_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES_u_tank_nget, self->data_ptr);
}

static int
TES_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES_u_tank_nset, self->data_ptr);
}

static PyGetSetDef TES_getset[] = {
{"cold_tank_Thtr", (getter)TES_get_cold_tank_Thtr,(setter)TES_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable cold tank HTF temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_tank_max_heat", (getter)TES_get_cold_tank_max_heat,(setter)TES_set_cold_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for cold tank heating [MW]\n\n**Required:**\nTrue"),
 	NULL},
{"h_tank", (getter)TES_get_h_tank,(setter)TES_set_h_tank,
	PyDoc_STR("*float*: Total height of tank (height of HTF when tank is full [m]\n\n**Required:**\nTrue"),
 	NULL},
{"init_hot_htf_percent", (getter)TES_get_init_hot_htf_percent,(setter)TES_set_init_hot_htf_percent,
	PyDoc_STR("*float*: Initial fraction of avail. vol that is hot [%]\n\n**Required:**\nTrue"),
 	NULL},
{"tank_pairs", (getter)TES_get_tank_pairs,(setter)TES_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs [-]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue"),
 	NULL},
{"u_tank", (getter)TES_get_u_tank,(setter)TES_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TES_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.TES",             /*tp_name*/
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
 * TES2tank Group
 */ 

static PyTypeObject TES2tank_Type;

static PyObject *
TES2tank_new(SAM_TroughPhysicalProcessHeat data_ptr)
{
	PyObject* new_obj = TES2tank_Type.tp_alloc(&TES2tank_Type,0);

	VarGroupObject* TES2tank_obj = (VarGroupObject*)new_obj;

	TES2tank_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TES2tank methods */

static PyObject *
TES2tank_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "TES2tank")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES2tank_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &TES2tank_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "TES2tank")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES2tank_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TES2tank_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TES2tank_methods[] = {
		{"assign",            (PyCFunction)TES2tank_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``TES2tank_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)TES2tank_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``TES2tank_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TES2tank_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TES2tank_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES2tank_h_tank_min_nget, self->data_ptr);
}

static int
TES2tank_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES2tank_h_tank_min_nset, self->data_ptr);
}

static PyObject *
TES2tank_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES2tank_hot_tank_Thtr_nget, self->data_ptr);
}

static int
TES2tank_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES2tank_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
TES2tank_get_hot_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_TES2tank_hot_tank_max_heat_nget, self->data_ptr);
}

static int
TES2tank_set_hot_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_TES2tank_hot_tank_max_heat_nset, self->data_ptr);
}

static PyGetSetDef TES2tank_getset[] = {
{"h_tank_min", (getter)TES2tank_get_h_tank_min,(setter)TES2tank_set_h_tank_min,
	PyDoc_STR("*float*: Minimum allowable HTF height in storage tank [m]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_Thtr", (getter)TES2tank_get_hot_tank_Thtr,(setter)TES2tank_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable hot tank HTF temp [C]\n\n**Required:**\nTrue"),
 	NULL},
{"hot_tank_max_heat", (getter)TES2tank_get_hot_tank_max_heat,(setter)TES2tank_set_hot_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for hot tank heating [MW]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TES2tank_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.TES2tank",             /*tp_name*/
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
		TES2tank_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TES2tank_getset,          /*tp_getset*/
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

static PyTypeObject Tou_Type;

static PyObject *
Tou_new(SAM_TroughPhysicalProcessHeat data_ptr)
{
	PyObject* new_obj = Tou_Type.tp_alloc(&Tou_Type,0);

	VarGroupObject* Tou_obj = (VarGroupObject*)new_obj;

	Tou_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Tou methods */

static PyObject *
Tou_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Tou_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "Tou")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Tou_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Tou_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Tou_methods[] = {
		{"assign",            (PyCFunction)Tou_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Tou_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Tou_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Tou_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Tou_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Tou_get_ampl_data_dir(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysicalProcessHeat_Tou_ampl_data_dir_sget, self->data_ptr);
}

static int
Tou_set_ampl_data_dir(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysicalProcessHeat_Tou_ampl_data_dir_sset, self->data_ptr);
}

static PyObject *
Tou_get_ampl_exec_call(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TroughPhysicalProcessHeat_Tou_ampl_exec_call_sget, self->data_ptr);
}

static int
Tou_set_ampl_exec_call(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TroughPhysicalProcessHeat_Tou_ampl_exec_call_sset, self->data_ptr);
}

static PyObject *
Tou_get_disp_csu_cost_rel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_csu_cost_rel_nget, self->data_ptr);
}

static int
Tou_set_disp_csu_cost_rel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_csu_cost_rel_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_frequency_nget, self->data_ptr);
}

static int
Tou_set_disp_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_frequency_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_horizon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_horizon_nget, self->data_ptr);
}

static int
Tou_set_disp_horizon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_horizon_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_max_iter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_max_iter_nget, self->data_ptr);
}

static int
Tou_set_disp_max_iter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_max_iter_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_mip_gap(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_mip_gap_nget, self->data_ptr);
}

static int
Tou_set_disp_mip_gap(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_mip_gap_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_pen_ramping(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_pen_ramping_nget, self->data_ptr);
}

static int
Tou_set_disp_pen_ramping(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_pen_ramping_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_reporting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_reporting_nget, self->data_ptr);
}

static int
Tou_set_disp_reporting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_reporting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_rsu_cost_rel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_rsu_cost_rel_nget, self->data_ptr);
}

static int
Tou_set_disp_rsu_cost_rel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_rsu_cost_rel_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_bb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_spec_bb_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_bb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_spec_bb_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_presolve(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_spec_presolve_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_presolve(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_spec_presolve_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_spec_scaling(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_spec_scaling_nget, self->data_ptr);
}

static int
Tou_set_disp_spec_scaling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_spec_scaling_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_steps_per_hour_nget, self->data_ptr);
}

static int
Tou_set_disp_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_time_weighting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_time_weighting_nget, self->data_ptr);
}

static int
Tou_set_disp_time_weighting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_time_weighting_nset, self->data_ptr);
}

static PyObject *
Tou_get_disp_timeout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_disp_timeout_nget, self->data_ptr);
}

static int
Tou_set_disp_timeout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_disp_timeout_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor1_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor1_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor2_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor2_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor3_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor3_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor4_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor4_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor5_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor5_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor6_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor6_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor7_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor7_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor8_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor8_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factor9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor9_nget, self->data_ptr);
}

static int
Tou_set_dispatch_factor9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factor9_nset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_factors_ts_aget, self->data_ptr);
}

static int
Tou_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
Tou_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
Tou_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
Tou_get_dispatch_series(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Tou_dispatch_series_aget, self->data_ptr);
}

static int
Tou_set_dispatch_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_Tou_dispatch_series_aset, self->data_ptr);
}

static PyObject *
Tou_get_f_turb_tou_periods(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Tou_f_turb_tou_periods_aget, self->data_ptr);
}

static int
Tou_set_f_turb_tou_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_Tou_f_turb_tou_periods_aset, self->data_ptr);
}

static PyObject *
Tou_get_is_ampl_engine(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_is_ampl_engine_nget, self->data_ptr);
}

static int
Tou_set_is_ampl_engine(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_is_ampl_engine_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_is_dispatch_nget, self->data_ptr);
}

static int
Tou_set_is_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_is_dispatch_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_dispatch_series(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_is_dispatch_series_nget, self->data_ptr);
}

static int
Tou_set_is_dispatch_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_is_dispatch_series_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_tod_pc_target_also_pc_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_is_tod_pc_target_also_pc_max_nget, self->data_ptr);
}

static int
Tou_set_is_tod_pc_target_also_pc_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_is_tod_pc_target_also_pc_max_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_wlim_series(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_is_wlim_series_nget, self->data_ptr);
}

static int
Tou_set_is_wlim_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_is_wlim_series_nset, self->data_ptr);
}

static PyObject *
Tou_get_is_write_ampl_dat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_is_write_ampl_dat_nget, self->data_ptr);
}

static int
Tou_set_is_write_ampl_dat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_is_write_ampl_dat_nset, self->data_ptr);
}

static PyObject *
Tou_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_ppa_multiplier_model_nget, self->data_ptr);
}

static int
Tou_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_heattrace(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_q_rec_heattrace_nget, self->data_ptr);
}

static int
Tou_set_q_rec_heattrace(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_q_rec_heattrace_nset, self->data_ptr);
}

static PyObject *
Tou_get_q_rec_standby(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Tou_q_rec_standby_nget, self->data_ptr);
}

static int
Tou_set_q_rec_standby(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Tou_q_rec_standby_nset, self->data_ptr);
}

static PyObject *
Tou_get_timestep_load_fractions(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Tou_timestep_load_fractions_aget, self->data_ptr);
}

static int
Tou_set_timestep_load_fractions(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_Tou_timestep_load_fractions_aset, self->data_ptr);
}

static PyObject *
Tou_get_weekday_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_Tou_weekday_schedule_mget, self->data_ptr);
}

static int
Tou_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_Tou_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
Tou_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_Tou_weekend_schedule_mget, self->data_ptr);
}

static int
Tou_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TroughPhysicalProcessHeat_Tou_weekend_schedule_mset, self->data_ptr);
}

static PyObject *
Tou_get_wlim_series(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Tou_wlim_series_aget, self->data_ptr);
}

static int
Tou_set_wlim_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_Tou_wlim_series_aset, self->data_ptr);
}

static PyGetSetDef Tou_getset[] = {
{"ampl_data_dir", (getter)Tou_get_ampl_data_dir,(setter)Tou_set_ampl_data_dir,
	PyDoc_STR("*str*: AMPL data file directory [-]\n\n**Required:**\nFalse. Automatically set to '' if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ampl_exec_call", (getter)Tou_get_ampl_exec_call,(setter)Tou_set_ampl_exec_call,
	PyDoc_STR("*str*: System command to run AMPL code [-]\n\n**Required:**\nFalse. Automatically set to 'ampl sdk_solution.run' if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_csu_cost_rel", (getter)Tou_get_disp_csu_cost_rel,(setter)Tou_set_disp_csu_cost_rel,
	PyDoc_STR("*float*: Heat sink startup cost [$/MWe-cycle/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_frequency", (getter)Tou_get_disp_frequency,(setter)Tou_set_disp_frequency,
	PyDoc_STR("*float*: Frequency for dispatch optimization calculations [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_horizon", (getter)Tou_get_disp_horizon,(setter)Tou_set_disp_horizon,
	PyDoc_STR("*float*: Time horizon for dispatch optimization [hour]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_max_iter", (getter)Tou_get_disp_max_iter,(setter)Tou_set_disp_max_iter,
	PyDoc_STR("*float*: Max. no. dispatch optimization iterations [-]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_mip_gap", (getter)Tou_get_disp_mip_gap,(setter)Tou_set_disp_mip_gap,
	PyDoc_STR("*float*: Dispatch optimization solution tolerance [-]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_pen_ramping", (getter)Tou_get_disp_pen_ramping,(setter)Tou_set_disp_pen_ramping,
	PyDoc_STR("*float*: Dispatch heat production change penalty [$/MWt-change]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_reporting", (getter)Tou_get_disp_reporting,(setter)Tou_set_disp_reporting,
	PyDoc_STR("*float*: Dispatch optimization reporting level [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_rsu_cost_rel", (getter)Tou_get_disp_rsu_cost_rel,(setter)Tou_set_disp_rsu_cost_rel,
	PyDoc_STR("*float*: Receiver startup cost [$/MWt/start]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"disp_spec_bb", (getter)Tou_get_disp_spec_bb,(setter)Tou_set_disp_spec_bb,
	PyDoc_STR("*float*: Dispatch optimization B&B heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_presolve", (getter)Tou_get_disp_spec_presolve,(setter)Tou_set_disp_spec_presolve,
	PyDoc_STR("*float*: Dispatch optimization presolve heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_spec_scaling", (getter)Tou_get_disp_spec_scaling,(setter)Tou_set_disp_spec_scaling,
	PyDoc_STR("*float*: Dispatch optimization scaling heuristic [-]\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_steps_per_hour", (getter)Tou_get_disp_steps_per_hour,(setter)Tou_set_disp_steps_per_hour,
	PyDoc_STR("*float*: Time steps per hour for dispatch optimization calculations [-]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_time_weighting", (getter)Tou_get_disp_time_weighting,(setter)Tou_set_disp_time_weighting,
	PyDoc_STR("*float*: Dispatch optimization future time discounting factor [-]\n\n**Required:**\nFalse. Automatically set to 0.99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"disp_timeout", (getter)Tou_get_disp_timeout,(setter)Tou_set_disp_timeout,
	PyDoc_STR("*float*: Max. dispatch optimization solve duration [s]\n\n**Required:**\nRequired if is_dispatch=1"),
 	NULL},
{"dispatch_factor1", (getter)Tou_get_dispatch_factor1,(setter)Tou_set_dispatch_factor1,
	PyDoc_STR("*float*: Dispatch payment factor 1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor2", (getter)Tou_get_dispatch_factor2,(setter)Tou_set_dispatch_factor2,
	PyDoc_STR("*float*: Dispatch payment factor 2\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor3", (getter)Tou_get_dispatch_factor3,(setter)Tou_set_dispatch_factor3,
	PyDoc_STR("*float*: Dispatch payment factor 3\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor4", (getter)Tou_get_dispatch_factor4,(setter)Tou_set_dispatch_factor4,
	PyDoc_STR("*float*: Dispatch payment factor 4\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor5", (getter)Tou_get_dispatch_factor5,(setter)Tou_set_dispatch_factor5,
	PyDoc_STR("*float*: Dispatch payment factor 5\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor6", (getter)Tou_get_dispatch_factor6,(setter)Tou_set_dispatch_factor6,
	PyDoc_STR("*float*: Dispatch payment factor 6\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor7", (getter)Tou_get_dispatch_factor7,(setter)Tou_set_dispatch_factor7,
	PyDoc_STR("*float*: Dispatch payment factor 7\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor8", (getter)Tou_get_dispatch_factor8,(setter)Tou_set_dispatch_factor8,
	PyDoc_STR("*float*: Dispatch payment factor 8\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factor9", (getter)Tou_get_dispatch_factor9,(setter)Tou_set_dispatch_factor9,
	PyDoc_STR("*float*: Dispatch payment factor 9\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_factors_ts", (getter)Tou_get_dispatch_factors_ts,(setter)Tou_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n**Required:**\nRequired if ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)Tou_get_dispatch_sched_weekday,(setter)Tou_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: 12x24 PPA pricing Weekday schedule\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_sched_weekend", (getter)Tou_get_dispatch_sched_weekend,(setter)Tou_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: 12x24 PPA pricing Weekend schedule\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dispatch_series", (getter)Tou_get_dispatch_series,(setter)Tou_set_dispatch_series,
	PyDoc_STR("*sequence*: Time series dispatch factors"),
 	NULL},
{"f_turb_tou_periods", (getter)Tou_get_f_turb_tou_periods,(setter)Tou_set_f_turb_tou_periods,
	PyDoc_STR("*sequence*: Dispatch logic for heat sink load fraction [-]\n\n**Required:**\nTrue"),
 	NULL},
{"is_ampl_engine", (getter)Tou_get_is_ampl_engine,(setter)Tou_set_is_ampl_engine,
	PyDoc_STR("*float*: Run dispatch optimization with external AMPL engine [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_dispatch", (getter)Tou_get_is_dispatch,(setter)Tou_set_is_dispatch,
	PyDoc_STR("*float*: Allow dispatch optimization? [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_dispatch_series", (getter)Tou_get_is_dispatch_series,(setter)Tou_set_is_dispatch_series,
	PyDoc_STR("*float*: Use time-series dispatch factors\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_tod_pc_target_also_pc_max", (getter)Tou_get_is_tod_pc_target_also_pc_max,(setter)Tou_set_is_tod_pc_target_also_pc_max,
	PyDoc_STR("*float*: Is the TOD target cycle heat input also the max cycle heat input?\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_wlim_series", (getter)Tou_get_is_wlim_series,(setter)Tou_set_is_wlim_series,
	PyDoc_STR("*float*: Use time-series net heat generation limits\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"is_write_ampl_dat", (getter)Tou_get_is_write_ampl_dat,(setter)Tou_set_is_write_ampl_dat,
	PyDoc_STR("*float*: Write AMPL data files for dispatch run [-]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ppa_multiplier_model", (getter)Tou_get_ppa_multiplier_model,(setter)Tou_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_rec_heattrace", (getter)Tou_get_q_rec_heattrace,(setter)Tou_set_q_rec_heattrace,
	PyDoc_STR("*float*: Receiver heat trace energy consumption during startup [kWe-hr]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"q_rec_standby", (getter)Tou_get_q_rec_standby,(setter)Tou_set_q_rec_standby,
	PyDoc_STR("*float*: Receiver standby energy consumption [kWt]\n\n**Required:**\nFalse. Automatically set to 9e99 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"timestep_load_fractions", (getter)Tou_get_timestep_load_fractions,(setter)Tou_set_timestep_load_fractions,
	PyDoc_STR("*sequence*: Turbine load fraction for each timestep, alternative to block dispatch\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"weekday_schedule", (getter)Tou_get_weekday_schedule,(setter)Tou_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 CSP operation Time-of-Use Weekday schedule [-]\n\n**Required:**\nTrue"),
 	NULL},
{"weekend_schedule", (getter)Tou_get_weekend_schedule,(setter)Tou_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 CSP operation Time-of-Use Weekend schedule [-]\n\n**Required:**\nTrue"),
 	NULL},
{"wlim_series", (getter)Tou_get_wlim_series,(setter)Tou_set_wlim_series,
	PyDoc_STR("*sequence*: Time series net heat generation limits [kWt]\n\n**Required:**\nRequired if is_wlim_series=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Tou_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.Tou",             /*tp_name*/
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
 * SystemControl Group
 */ 

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_TroughPhysicalProcessHeat data_ptr)
{
	PyObject* new_obj = SystemControl_Type.tp_alloc(&SystemControl_Type,0);

	VarGroupObject* SystemControl_obj = (VarGroupObject*)new_obj;

	SystemControl_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemControl methods */

static PyObject *
SystemControl_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemControl_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "SystemControl")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemControl_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemControl_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemControl_methods[] = {
		{"assign",            (PyCFunction)SystemControl_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemControl_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemControl_get_disp_inventory_incentive(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_SystemControl_disp_inventory_incentive_nget, self->data_ptr);
}

static int
SystemControl_set_disp_inventory_incentive(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_SystemControl_disp_inventory_incentive_nset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"disp_inventory_incentive", (getter)SystemControl_get_disp_inventory_incentive,(setter)SystemControl_set_disp_inventory_incentive,
	PyDoc_STR("*float*: Dispatch storage terminal inventory incentive multiplier\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.SystemControl",             /*tp_name*/
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
		SystemControl_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemControl_getset,          /*tp_getset*/
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

static PyTypeObject System_Type;

static PyObject *
System_new(SAM_TroughPhysicalProcessHeat data_ptr)
{
	PyObject* new_obj = System_Type.tp_alloc(&System_Type,0);

	VarGroupObject* System_obj = (VarGroupObject*)new_obj;

	System_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* System methods */

static PyObject *
System_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "System")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
System_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &System_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "System")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
System_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &System_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef System_methods[] = {
		{"assign",            (PyCFunction)System_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``System_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)System_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``System_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)System_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
System_get_aux_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_System_aux_array_aget, self->data_ptr);
}

static int
System_set_aux_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_System_aux_array_aset, self->data_ptr);
}

static PyObject *
System_get_bop_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_System_bop_array_aget, self->data_ptr);
}

static int
System_set_bop_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TroughPhysicalProcessHeat_System_bop_array_aset, self->data_ptr);
}

static PyObject *
System_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_System_pb_fixed_par_nget, self->data_ptr);
}

static int
System_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_System_pb_fixed_par_nset, self->data_ptr);
}

static PyGetSetDef System_getset[] = {
{"aux_array", (getter)System_get_aux_array,(setter)System_set_aux_array,
	PyDoc_STR("*sequence*: Auxiliary heater, mult frac and const, linear and quad coeff\n\n**Required:**\nTrue"),
 	NULL},
{"bop_array", (getter)System_get_bop_array,(setter)System_set_bop_array,
	PyDoc_STR("*sequence*: Balance of plant parasitic power fraction, mult frac and const, linear and quad coeff\n\n**Required:**\nTrue"),
 	NULL},
{"pb_fixed_par", (getter)System_get_pb_fixed_par,(setter)System_set_pb_fixed_par,
	PyDoc_STR("*float*: Fraction of rated gross power constantly consumed [MWe/MWcap]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject System_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.System",             /*tp_name*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TroughPhysicalProcessHeat data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "Powerblock")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "Powerblock")){
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
Powerblock_get_L_rnr_pb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Powerblock_L_rnr_pb_nget, self->data_ptr);
}

static int
Powerblock_set_L_rnr_pb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TroughPhysicalProcessHeat_Powerblock_L_rnr_pb_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"L_rnr_pb", (getter)Powerblock_get_L_rnr_pb,(setter)Powerblock_set_L_rnr_pb,
	PyDoc_STR("*float*: Length of runner pipe in power block [m]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat.Powerblock",             /*tp_name*/
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
Outputs_new(SAM_TroughPhysicalProcessHeat data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TroughPhysicalProcessHeat", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "TroughPhysicalProcessHeat", "Outputs")){
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
Outputs_get_CosTh_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_CosTh_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_EndLoss_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_EndLoss_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_EqOpteff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_EqOpteff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_IAM_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_IAM_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_RowShadow_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_RowShadow_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_SCAs_def(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_SCAs_def_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_field_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_field_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_field_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_heat_sink_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_heat_sink_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_heat_sink_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_heat_sink_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_cold_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_rec_cold_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rec_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_rec_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_Theta_ave(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_Theta_ave_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_field_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_W_dot_field_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_parasitic_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_W_dot_parasitic_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_pc_pump(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_W_dot_pc_pump_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_sca_track(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_W_dot_sca_track_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_electricity_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_electricity_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_field_freeze_protection(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_field_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_gross_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_gross_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_tes_freeze_protection(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_tes_freeze_protection_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_thermal_consumption(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_thermal_consumption_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_deltaP_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_deltaP_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dni_costh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_dni_costh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_e_dot_field_int_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_e_dot_field_int_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour_day(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_hour_day_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cr_to_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_cr_to_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_cycle_to_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_cycle_to_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_delivered(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_field_delivered_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_recirc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_field_recirc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_field_to_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_field_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_htf_heat_sink(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_htf_heat_sink_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_loop(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_loop_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_pc_to_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_pc_to_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_cold_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_tes_cold_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_tes_hot_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_m_dot_tes_hot_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_mass_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_mass_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_op_mode_1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_op_mode_2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_op_mode_3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_op_mode_3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_balance(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_balance_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dc_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_freeze_prot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_freeze_prot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_htf_sf_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_htf_sf_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_piping_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_rec_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_inc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_rec_inc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_rec_thermal_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_rec_thermal_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_to_heat_sink(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_dot_to_heat_sink_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_sf_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_inc_sf_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_q_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_qinc_costh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_qinc_costh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solar_multiple_actual(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TroughPhysicalProcessHeat_Outputs_solar_multiple_actual_nget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tank_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_tank_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TroughPhysicalProcessHeat_Outputs_wspd_aget, self->data_ptr);
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
{"T_heat_sink_in", (getter)Outputs_get_T_heat_sink_in,(setter)0,
	PyDoc_STR("*sequence*: Heat sink HTF inlet temp [C]"),
 	NULL},
{"T_heat_sink_out", (getter)Outputs_get_T_heat_sink_out,(setter)0,
	PyDoc_STR("*sequence*: Heat sink HTF outlet temp [C]"),
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
{"W_dot_parasitic_tot", (getter)Outputs_get_W_dot_parasitic_tot,(setter)0,
	PyDoc_STR("*sequence*: System total electrical parasitic [MWe]"),
 	NULL},
{"W_dot_pc_pump", (getter)Outputs_get_W_dot_pc_pump,(setter)0,
	PyDoc_STR("*sequence*: Heat sink pumping power [MWe]"),
 	NULL},
{"W_dot_sca_track", (getter)Outputs_get_W_dot_sca_track,(setter)0,
	PyDoc_STR("*sequence*: Field collector tracking power [MWe]"),
 	NULL},
{"annual_electricity_consumption", (getter)Outputs_get_annual_electricity_consumption,(setter)0,
	PyDoc_STR("*float*: Annual electricity consumption w/ avail derate [kWe-hr]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Net Thermal Energy Production w/ avail derate [kWt-hr]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_field_freeze_protection", (getter)Outputs_get_annual_field_freeze_protection,(setter)0,
	PyDoc_STR("*float*: Annual thermal power for field freeze protection [kWt-hr]"),
 	NULL},
{"annual_gross_energy", (getter)Outputs_get_annual_gross_energy,(setter)0,
	PyDoc_STR("*float*: Annual Gross Thermal Energy Production w/ avail derate [kWt-hr]"),
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
{"deltaP_field", (getter)Outputs_get_deltaP_field,(setter)0,
	PyDoc_STR("*sequence*: Field pressure drop [bar]"),
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
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"hour_day", (getter)Outputs_get_hour_day,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWht/kWt]"),
 	NULL},
{"m_dot_balance", (getter)Outputs_get_m_dot_balance,(setter)0,
	PyDoc_STR("*sequence*: Relative mass flow balance error"),
 	NULL},
{"m_dot_cr_to_tes_hot", (getter)Outputs_get_m_dot_cr_to_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: field to hot TES [kg/s]"),
 	NULL},
{"m_dot_cycle_to_field", (getter)Outputs_get_m_dot_cycle_to_field,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cycle to field [kg/s]"),
 	NULL},
{"m_dot_field_delivered", (getter)Outputs_get_m_dot_field_delivered,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow delivered [kg/s]"),
 	NULL},
{"m_dot_field_recirc", (getter)Outputs_get_m_dot_field_recirc,(setter)0,
	PyDoc_STR("*sequence*: Field total mass flow recirculated [kg/s]"),
 	NULL},
{"m_dot_field_to_cycle", (getter)Outputs_get_m_dot_field_to_cycle,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: field to cycle [kg/s]"),
 	NULL},
{"m_dot_htf_heat_sink", (getter)Outputs_get_m_dot_htf_heat_sink,(setter)0,
	PyDoc_STR("*sequence*: Heat sink HTF mass flow [kg/s]"),
 	NULL},
{"m_dot_loop", (getter)Outputs_get_m_dot_loop,(setter)0,
	PyDoc_STR("*sequence*: Receiver mass flow rate [kg/s]"),
 	NULL},
{"m_dot_pc_to_tes_cold", (getter)Outputs_get_m_dot_pc_to_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: cycle to cold TES [kg/s]"),
 	NULL},
{"m_dot_tes_cold_out", (getter)Outputs_get_m_dot_tes_cold_out,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: TES cold out [kg/s]"),
 	NULL},
{"m_dot_tes_hot_out", (getter)Outputs_get_m_dot_tes_hot_out,(setter)0,
	PyDoc_STR("*sequence*: Mass flow: TES hot out [kg/s]"),
 	NULL},
{"mass_tes_cold", (getter)Outputs_get_mass_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold tank mass (end) [kg]"),
 	NULL},
{"mass_tes_hot", (getter)Outputs_get_mass_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot tank mass (end) [kg]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
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
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
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
{"q_dot_freeze_prot", (getter)Outputs_get_q_dot_freeze_prot,(setter)0,
	PyDoc_STR("*sequence*: Field freeze protection required [MWt]"),
 	NULL},
{"q_dot_htf_sf_out", (getter)Outputs_get_q_dot_htf_sf_out,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power leaving in HTF [MWt]"),
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
{"q_dot_to_heat_sink", (getter)Outputs_get_q_dot_to_heat_sink,(setter)0,
	PyDoc_STR("*sequence*: Heat sink thermal power [MWt]"),
 	NULL},
{"q_inc_sf_tot", (getter)Outputs_get_q_inc_sf_tot,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident [MWt]"),
 	NULL},
{"q_tes_heater", (getter)Outputs_get_q_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"qinc_costh", (getter)Outputs_get_qinc_costh,(setter)0,
	PyDoc_STR("*sequence*: Field thermal power incident after cosine [MWt]"),
 	NULL},
{"solar_multiple_actual", (getter)Outputs_get_solar_multiple_actual,(setter)0,
	PyDoc_STR("*float*: Actual solar multiple of system [-]"),
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
		"TroughPhysicalProcessHeat.Outputs",             /*tp_name*/
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
 * TroughPhysicalProcessHeat
 */

static PyTypeObject TroughPhysicalProcessHeat_Type;

static CmodObject *
newTroughPhysicalProcessHeatObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TroughPhysicalProcessHeat_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* SolarField_obj = SolarField_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarField", SolarField_obj);
	Py_DECREF(SolarField_obj);

	PyObject* Controller_obj = Controller_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Controller", Controller_obj);
	Py_DECREF(Controller_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* TES_obj = TES_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TES", TES_obj);
	Py_DECREF(TES_obj);

	PyObject* TES2tank_obj = TES2tank_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TES2tank", TES2tank_obj);
	Py_DECREF(TES2tank_obj);

	PyObject* Tou_obj = Tou_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Tou", Tou_obj);
	Py_DECREF(Tou_obj);

	PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

	PyObject* System_obj = System_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "System", System_obj);
	Py_DECREF(System_obj);

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

/* TroughPhysicalProcessHeat methods */

static void
TroughPhysicalProcessHeat_dealloc(CmodObject *self)
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
TroughPhysicalProcessHeat_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TroughPhysicalProcessHeat_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TroughPhysicalProcessHeat_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysicalProcessHeat"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TroughPhysicalProcessHeat_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TroughPhysicalProcessHeat"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TroughPhysicalProcessHeat_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TroughPhysicalProcessHeat_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
TroughPhysicalProcessHeat_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef TroughPhysicalProcessHeat_methods[] = {
		{"execute",           (PyCFunction)TroughPhysicalProcessHeat_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TroughPhysicalProcessHeat_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)TroughPhysicalProcessHeat_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TroughPhysicalProcessHeat_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TroughPhysicalProcessHeat_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)TroughPhysicalProcessHeat_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TroughPhysicalProcessHeat_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TroughPhysicalProcessHeat_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TroughPhysicalProcessHeat_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TroughPhysicalProcessHeat",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TroughPhysicalProcessHeat_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TroughPhysicalProcessHeat_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TroughPhysicalProcessHeat_getattro, /*tp_getattro*/
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
		TroughPhysicalProcessHeat_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TroughPhysicalProcessHeat object */

static PyObject *
TroughPhysicalProcessHeat_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTroughPhysicalProcessHeatObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysicalProcessHeat_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalProcessHeatObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TroughPhysicalProcessHeat_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTroughPhysicalProcessHeatObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysicalProcessHeat", def) < 0) {
		TroughPhysicalProcessHeat_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
TroughPhysicalProcessHeat_from_existing(PyObject *self, PyObject *args)
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

	rv = newTroughPhysicalProcessHeatObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TroughPhysicalProcessHeat", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TroughPhysicalProcessHeatModule_methods[] = {
		{"new",             TroughPhysicalProcessHeat_new,         METH_VARARGS,
				PyDoc_STR("new() -> TroughPhysicalProcessHeat")},
		{"default",             TroughPhysicalProcessHeat_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TroughPhysicalProcessHeat\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"PhysicalTroughIPHLCOHCalculator\"*\n\n		- *\"PhysicalTroughIPHNone\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             TroughPhysicalProcessHeat_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TroughPhysicalProcessHeat\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   TroughPhysicalProcessHeat_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TroughPhysicalProcessHeat\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Parabolic trough for industrial process heat applications");


static int
TroughPhysicalProcessHeatModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TroughPhysicalProcessHeat_Type.tp_dict = PyDict_New();
	if (!TroughPhysicalProcessHeat_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TroughPhysicalProcessHeat_Type
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
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the SolarField type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&SolarField_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"SolarField",
				(PyObject*)&SolarField_Type);
	Py_DECREF(&SolarField_Type);

	/// Add the Controller type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&Controller_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"Controller",
				(PyObject*)&Controller_Type);
	Py_DECREF(&Controller_Type);

	/// Add the SystemDesign type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the TES type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&TES_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"TES",
				(PyObject*)&TES_Type);
	Py_DECREF(&TES_Type);

	/// Add the TES2tank type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&TES2tank_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"TES2tank",
				(PyObject*)&TES2tank_Type);
	Py_DECREF(&TES2tank_Type);

	/// Add the Tou type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&Tou_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"Tou",
				(PyObject*)&Tou_Type);
	Py_DECREF(&Tou_Type);

	/// Add the SystemControl type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the System type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&System_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"System",
				(PyObject*)&System_Type);
	Py_DECREF(&System_Type);

	/// Add the Powerblock type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the Outputs type object to TroughPhysicalProcessHeat_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TroughPhysicalProcessHeat_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TroughPhysicalProcessHeat type object to the module
	if (PyType_Ready(&TroughPhysicalProcessHeat_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TroughPhysicalProcessHeat",
				(PyObject*)&TroughPhysicalProcessHeat_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TroughPhysicalProcessHeatModule_slots[] = {
		{Py_mod_exec, TroughPhysicalProcessHeatModule_exec},
		{0, NULL},
};

static struct PyModuleDef TroughPhysicalProcessHeatModule = {
		PyModuleDef_HEAD_INIT,
		"TroughPhysicalProcessHeat",
		module_doc,
		0,
		TroughPhysicalProcessHeatModule_methods,
		TroughPhysicalProcessHeatModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TroughPhysicalProcessHeat(void)
{
	return PyModuleDef_Init(&TroughPhysicalProcessHeatModule);
}