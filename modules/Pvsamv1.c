#include <Python.h>

#include <SAM_Pvsamv1.h>
#include <SAM_api.h>

#include "PySAM_utils.h"

#include "Pvsamv1_eqns.c"


/*
 * SolarResource Group
 */ 

static PyTypeObject SolarResource_Type;

static PyObject *
SolarResource_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = SolarResource_Type.tp_alloc(&SolarResource_Type,0);

	VarGroupObject* SolarResource_obj = (VarGroupObject*)new_obj;

	SolarResource_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SolarResource methods */

static PyObject *
SolarResource_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "SolarResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarResource_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SolarResource_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "SolarResource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SolarResource_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SolarResource_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SolarResource_methods[] = {
		{"assign",            (PyCFunction)SolarResource_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SolarResource_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SolarResource_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SolarResource_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarResource_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarResource_get_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SolarResource_albedo_aget, self->data_ptr);
}

static int
SolarResource_set_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SolarResource_albedo_aset, self->data_ptr);
}

static PyObject *
SolarResource_get_albedo_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_SolarResource_albedo_spatial_mget, self->data_ptr);
}

static int
SolarResource_set_albedo_spatial(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_SolarResource_albedo_spatial_mset, self->data_ptr);
}

static PyObject *
SolarResource_get_irrad_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SolarResource_irrad_mode_nget, self->data_ptr);
}

static int
SolarResource_set_irrad_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SolarResource_irrad_mode_nset, self->data_ptr);
}

static PyObject *
SolarResource_get_sky_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SolarResource_sky_model_nget, self->data_ptr);
}

static int
SolarResource_set_sky_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SolarResource_sky_model_nset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Pvsamv1_SolarResource_solar_resource_data_tget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Pvsamv1_SolarResource_solar_resource_data_tset, self->data_ptr);
}

static PyObject *
SolarResource_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvsamv1_SolarResource_solar_resource_file_sget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvsamv1_SolarResource_solar_resource_file_sset, self->data_ptr);
}

static PyObject *
SolarResource_get_use_spatial_albedos(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SolarResource_use_spatial_albedos_nget, self->data_ptr);
}

static int
SolarResource_set_use_spatial_albedos(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SolarResource_use_spatial_albedos_nset, self->data_ptr);
}

static PyObject *
SolarResource_get_use_wf_albedo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SolarResource_use_wf_albedo_nget, self->data_ptr);
}

static int
SolarResource_set_use_wf_albedo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SolarResource_use_wf_albedo_nset, self->data_ptr);
}

static PyGetSetDef SolarResource_getset[] = {
{"albedo", (getter)SolarResource_get_albedo,(setter)SolarResource_set_albedo,
	PyDoc_STR("*sequence*: User specified monthly ground albedo (non-spatial) [0..1]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if use_spatial_albedos=0"),
 	NULL},
{"albedo_spatial", (getter)SolarResource_get_albedo_spatial,(setter)SolarResource_set_albedo_spatial,
	PyDoc_STR("*sequence[sequence]*: User specified monthly ground albedo (spatial) [0..1]\n\n**Required:**\nRequired if use_spatial_albedos=1"),
 	NULL},
{"irrad_mode", (getter)SolarResource_get_irrad_mode,(setter)SolarResource_set_irrad_mode,
	PyDoc_STR("*float*: Irradiance input translation mode\n\n**Options:**\n0=beam&diffuse,1=total&beam,2=total&diffuse,3=poa_reference,4=poa_pyranometer\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"sky_model", (getter)SolarResource_get_sky_model,(setter)SolarResource_set_sky_model,
	PyDoc_STR("*float*: Diffuse sky model\n\n**Options:**\n0=isotropic,1=hkdr,2=perez\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 2 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"solar_resource_data", (getter)SolarResource_get_solar_resource_data,(setter)SolarResource_set_solar_resource_data,
	PyDoc_STR("*dict*: Weather data\n\n**Info:**\nlat,lon,tz,elev,year,month,hour,minute,gh,dn,df,poa,tdry,twet,tdew,rhum,pres,snow,alb,aod,wspd,wdir\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"solar_resource_file", (getter)SolarResource_get_solar_resource_file,(setter)SolarResource_set_solar_resource_file,
	PyDoc_STR("*str*: Weather file in TMY2, TMY3, EPW, or SAM CSV\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"use_spatial_albedos", (getter)SolarResource_get_use_spatial_albedos,(setter)SolarResource_set_use_spatial_albedos,
	PyDoc_STR("*float*: Use spatial albedo values [0/1]\n\n**Options:**\n0=no,1=yes\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"use_wf_albedo", (getter)SolarResource_get_use_wf_albedo,(setter)SolarResource_set_use_wf_albedo,
	PyDoc_STR("*float*: Use albedo in weather file if provided [0/1]\n\n**Options:**\n0=user-specified,1=weatherfile\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.SolarResource",             /*tp_name*/
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
		SolarResource_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SolarResource_getset,          /*tp_getset*/
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
 * Losses Group
 */ 

static PyTypeObject Losses_Type;

static PyObject *
Losses_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Losses_Type.tp_alloc(&Losses_Type,0);

	VarGroupObject* Losses_obj = (VarGroupObject*)new_obj;

	Losses_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Losses methods */

static PyObject *
Losses_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Losses")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Losses_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Losses_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Losses")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Losses_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Losses_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Losses_methods[] = {
		{"assign",            (PyCFunction)Losses_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Losses_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Losses_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Losses_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Losses_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Losses_get_acwiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_acwiring_loss_nget, self->data_ptr);
}

static int
Losses_set_acwiring_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_acwiring_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_calculate_bifacial_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_calculate_bifacial_electrical_mismatch_nget, self->data_ptr);
}

static int
Losses_set_calculate_bifacial_electrical_mismatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_calculate_bifacial_electrical_mismatch_nset, self->data_ptr);
}

static PyObject *
Losses_get_calculate_rack_shading(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_calculate_rack_shading_nget, self->data_ptr);
}

static int
Losses_set_calculate_rack_shading(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_calculate_rack_shading_nset, self->data_ptr);
}

static PyObject *
Losses_get_dcoptimizer_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_dcoptimizer_loss_nget, self->data_ptr);
}

static int
Losses_set_dcoptimizer_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_dcoptimizer_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_en_snow_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_en_snow_model_nget, self->data_ptr);
}

static int
Losses_set_en_snow_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_en_snow_model_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_dcwiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_dcwiring_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray1_dcwiring_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_dcwiring_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_diodeconn_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_diodeconn_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray1_diodeconn_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_diodeconn_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_electrical_mismatch_nget, self->data_ptr);
}

static int
Losses_set_subarray1_electrical_mismatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_electrical_mismatch_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_mismatch_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray1_mismatch_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_mismatch_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_nameplate_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray1_nameplate_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_nameplate_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_rack_shading(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_rack_shading_nget, self->data_ptr);
}

static int
Losses_set_subarray1_rack_shading(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_rack_shading_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_rear_soiling_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_rear_soiling_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray1_rear_soiling_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_rear_soiling_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_soiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Losses_subarray1_soiling_aget, self->data_ptr);
}

static int
Losses_set_subarray1_soiling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Losses_subarray1_soiling_aset, self->data_ptr);
}

static PyObject *
Losses_get_subarray1_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray1_tracking_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray1_tracking_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray1_tracking_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_dcwiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_dcwiring_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray2_dcwiring_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_dcwiring_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_diodeconn_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_diodeconn_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray2_diodeconn_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_diodeconn_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_electrical_mismatch_nget, self->data_ptr);
}

static int
Losses_set_subarray2_electrical_mismatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_electrical_mismatch_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_mismatch_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray2_mismatch_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_mismatch_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_nameplate_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray2_nameplate_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_nameplate_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_rack_shading(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_rack_shading_nget, self->data_ptr);
}

static int
Losses_set_subarray2_rack_shading(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_rack_shading_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_rear_soiling_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_rear_soiling_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray2_rear_soiling_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_rear_soiling_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_soiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Losses_subarray2_soiling_aget, self->data_ptr);
}

static int
Losses_set_subarray2_soiling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Losses_subarray2_soiling_aset, self->data_ptr);
}

static PyObject *
Losses_get_subarray2_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray2_tracking_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray2_tracking_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray2_tracking_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_dcwiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_dcwiring_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray3_dcwiring_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_dcwiring_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_diodeconn_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_diodeconn_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray3_diodeconn_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_diodeconn_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_electrical_mismatch_nget, self->data_ptr);
}

static int
Losses_set_subarray3_electrical_mismatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_electrical_mismatch_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_mismatch_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray3_mismatch_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_mismatch_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_nameplate_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray3_nameplate_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_nameplate_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_rack_shading(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_rack_shading_nget, self->data_ptr);
}

static int
Losses_set_subarray3_rack_shading(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_rack_shading_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_rear_soiling_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_rear_soiling_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray3_rear_soiling_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_rear_soiling_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_soiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Losses_subarray3_soiling_aget, self->data_ptr);
}

static int
Losses_set_subarray3_soiling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Losses_subarray3_soiling_aset, self->data_ptr);
}

static PyObject *
Losses_get_subarray3_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray3_tracking_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray3_tracking_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray3_tracking_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_dcwiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_dcwiring_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray4_dcwiring_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_dcwiring_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_diodeconn_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_diodeconn_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray4_diodeconn_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_diodeconn_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_electrical_mismatch_nget, self->data_ptr);
}

static int
Losses_set_subarray4_electrical_mismatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_electrical_mismatch_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_mismatch_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray4_mismatch_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_mismatch_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_nameplate_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray4_nameplate_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_nameplate_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_rack_shading(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_rack_shading_nget, self->data_ptr);
}

static int
Losses_set_subarray4_rack_shading(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_rack_shading_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_rear_soiling_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_rear_soiling_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray4_rear_soiling_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_rear_soiling_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_soiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Losses_subarray4_soiling_aget, self->data_ptr);
}

static int
Losses_set_subarray4_soiling(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Losses_subarray4_soiling_aset, self->data_ptr);
}

static PyObject *
Losses_get_subarray4_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_subarray4_tracking_loss_nget, self->data_ptr);
}

static int
Losses_set_subarray4_tracking_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_subarray4_tracking_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_transformer_load_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_transformer_load_loss_nget, self->data_ptr);
}

static int
Losses_set_transformer_load_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_transformer_load_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_transformer_no_load_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_transformer_no_load_loss_nget, self->data_ptr);
}

static int
Losses_set_transformer_no_load_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_transformer_no_load_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_transmission_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Losses_transmission_loss_nget, self->data_ptr);
}

static int
Losses_set_transmission_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Losses_transmission_loss_nset, self->data_ptr);
}

static PyGetSetDef Losses_getset[] = {
{"acwiring_loss", (getter)Losses_get_acwiring_loss,(setter)Losses_set_acwiring_loss,
	PyDoc_STR("*float*: AC wiring loss [%]\n\n**Info:**\npercent of inverter AC output\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"calculate_bifacial_electrical_mismatch", (getter)Losses_get_calculate_bifacial_electrical_mismatch,(setter)Losses_set_calculate_bifacial_electrical_mismatch,
	PyDoc_STR("*float*: Calculate bifacial electrical mismatch\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"calculate_rack_shading", (getter)Losses_get_calculate_rack_shading,(setter)Losses_set_calculate_rack_shading,
	PyDoc_STR("*float*: Calculate rack shading\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"dcoptimizer_loss", (getter)Losses_get_dcoptimizer_loss,(setter)Losses_set_dcoptimizer_loss,
	PyDoc_STR("*float*: DC power optimizer loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"en_snow_model", (getter)Losses_get_en_snow_model,(setter)Losses_set_en_snow_model,
	PyDoc_STR("*float*: Toggle snow loss estimation [0/1]\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_dcwiring_loss", (getter)Losses_get_subarray1_dcwiring_loss,(setter)Losses_set_subarray1_dcwiring_loss,
	PyDoc_STR("*float*: Sub-array 1 DC wiring loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_diodeconn_loss", (getter)Losses_get_subarray1_diodeconn_loss,(setter)Losses_set_subarray1_diodeconn_loss,
	PyDoc_STR("*float*: Sub-array 1 DC diodes and connections loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_electrical_mismatch", (getter)Losses_get_subarray1_electrical_mismatch,(setter)Losses_set_subarray1_electrical_mismatch,
	PyDoc_STR("*float*: Sub-array 1 bifacial electrical mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_mismatch_loss", (getter)Losses_get_subarray1_mismatch_loss,(setter)Losses_set_subarray1_mismatch_loss,
	PyDoc_STR("*float*: Sub-array 1 DC mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_nameplate_loss", (getter)Losses_get_subarray1_nameplate_loss,(setter)Losses_set_subarray1_nameplate_loss,
	PyDoc_STR("*float*: Sub-array 1 DC nameplate loss [%]\n\n**Constraints:**\nMIN=-5,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_rack_shading", (getter)Losses_get_subarray1_rack_shading,(setter)Losses_set_subarray1_rack_shading,
	PyDoc_STR("*float*: Sub-array 1 rack shading loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_rear_soiling_loss", (getter)Losses_get_subarray1_rear_soiling_loss,(setter)Losses_set_subarray1_rear_soiling_loss,
	PyDoc_STR("*float*: Sub-array 1 rear soiling loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_soiling", (getter)Losses_get_subarray1_soiling,(setter)Losses_set_subarray1_soiling,
	PyDoc_STR("*sequence*: Sub-array 1 Monthly soiling loss [%]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_tracking_loss", (getter)Losses_get_subarray1_tracking_loss,(setter)Losses_set_subarray1_tracking_loss,
	PyDoc_STR("*float*: Sub-array 1 DC tracking error loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
{"subarray2_dcwiring_loss", (getter)Losses_get_subarray2_dcwiring_loss,(setter)Losses_set_subarray2_dcwiring_loss,
	PyDoc_STR("*float*: Sub-array 2 DC wiring loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_diodeconn_loss", (getter)Losses_get_subarray2_diodeconn_loss,(setter)Losses_set_subarray2_diodeconn_loss,
	PyDoc_STR("*float*: Sub-array 2 DC diodes and connections loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_electrical_mismatch", (getter)Losses_get_subarray2_electrical_mismatch,(setter)Losses_set_subarray2_electrical_mismatch,
	PyDoc_STR("*float*: Sub-array 2 bifacial electrical mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_mismatch_loss", (getter)Losses_get_subarray2_mismatch_loss,(setter)Losses_set_subarray2_mismatch_loss,
	PyDoc_STR("*float*: Sub-array 2 DC mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_nameplate_loss", (getter)Losses_get_subarray2_nameplate_loss,(setter)Losses_set_subarray2_nameplate_loss,
	PyDoc_STR("*float*: Sub-array 2 DC nameplate loss [%]\n\n**Constraints:**\nMIN=-5,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_rack_shading", (getter)Losses_get_subarray2_rack_shading,(setter)Losses_set_subarray2_rack_shading,
	PyDoc_STR("*float*: Sub-array 2 rack shading loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_rear_soiling_loss", (getter)Losses_get_subarray2_rear_soiling_loss,(setter)Losses_set_subarray2_rear_soiling_loss,
	PyDoc_STR("*float*: Sub-array 2 rear soiling loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_soiling", (getter)Losses_get_subarray2_soiling,(setter)Losses_set_subarray2_soiling,
	PyDoc_STR("*sequence*: Sub-array 2 Monthly soiling loss [%]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_tracking_loss", (getter)Losses_get_subarray2_tracking_loss,(setter)Losses_set_subarray2_tracking_loss,
	PyDoc_STR("*float*: Sub-array 2 DC tracking error loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray3_dcwiring_loss", (getter)Losses_get_subarray3_dcwiring_loss,(setter)Losses_set_subarray3_dcwiring_loss,
	PyDoc_STR("*float*: Sub-array 3 DC wiring loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_diodeconn_loss", (getter)Losses_get_subarray3_diodeconn_loss,(setter)Losses_set_subarray3_diodeconn_loss,
	PyDoc_STR("*float*: Sub-array 3 DC diodes and connections loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_electrical_mismatch", (getter)Losses_get_subarray3_electrical_mismatch,(setter)Losses_set_subarray3_electrical_mismatch,
	PyDoc_STR("*float*: Sub-array 3 bifacial electrical mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_mismatch_loss", (getter)Losses_get_subarray3_mismatch_loss,(setter)Losses_set_subarray3_mismatch_loss,
	PyDoc_STR("*float*: Sub-array 3 DC mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_nameplate_loss", (getter)Losses_get_subarray3_nameplate_loss,(setter)Losses_set_subarray3_nameplate_loss,
	PyDoc_STR("*float*: Sub-array 3 DC nameplate loss [%]\n\n**Constraints:**\nMIN=-5,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_rack_shading", (getter)Losses_get_subarray3_rack_shading,(setter)Losses_set_subarray3_rack_shading,
	PyDoc_STR("*float*: Sub-array 3 rack shading loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_rear_soiling_loss", (getter)Losses_get_subarray3_rear_soiling_loss,(setter)Losses_set_subarray3_rear_soiling_loss,
	PyDoc_STR("*float*: Sub-array 3 rear soiling loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_soiling", (getter)Losses_get_subarray3_soiling,(setter)Losses_set_subarray3_soiling,
	PyDoc_STR("*sequence*: Sub-array 3 Monthly soiling loss [%]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_tracking_loss", (getter)Losses_get_subarray3_tracking_loss,(setter)Losses_set_subarray3_tracking_loss,
	PyDoc_STR("*float*: Sub-array 3 DC tracking error loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray4_dcwiring_loss", (getter)Losses_get_subarray4_dcwiring_loss,(setter)Losses_set_subarray4_dcwiring_loss,
	PyDoc_STR("*float*: Sub-array 4 DC wiring loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_diodeconn_loss", (getter)Losses_get_subarray4_diodeconn_loss,(setter)Losses_set_subarray4_diodeconn_loss,
	PyDoc_STR("*float*: Sub-array 4 DC diodes and connections loss [%]\n\n**Info:**\n?\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_electrical_mismatch", (getter)Losses_get_subarray4_electrical_mismatch,(setter)Losses_set_subarray4_electrical_mismatch,
	PyDoc_STR("*float*: Sub-array 4 bifacial electrical mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_mismatch_loss", (getter)Losses_get_subarray4_mismatch_loss,(setter)Losses_set_subarray4_mismatch_loss,
	PyDoc_STR("*float*: Sub-array 4 DC mismatch loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_nameplate_loss", (getter)Losses_get_subarray4_nameplate_loss,(setter)Losses_set_subarray4_nameplate_loss,
	PyDoc_STR("*float*: Sub-array 4 DC nameplate loss [%]\n\n**Constraints:**\nMIN=-5,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_rack_shading", (getter)Losses_get_subarray4_rack_shading,(setter)Losses_set_subarray4_rack_shading,
	PyDoc_STR("*float*: Sub-array 4 rack shading loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_rear_soiling_loss", (getter)Losses_get_subarray4_rear_soiling_loss,(setter)Losses_set_subarray4_rear_soiling_loss,
	PyDoc_STR("*float*: Sub-array 4 rear soiling loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_soiling", (getter)Losses_get_subarray4_soiling,(setter)Losses_set_subarray4_soiling,
	PyDoc_STR("*sequence*: Sub-array 4 Monthly soiling loss [%]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_tracking_loss", (getter)Losses_get_subarray4_tracking_loss,(setter)Losses_set_subarray4_tracking_loss,
	PyDoc_STR("*float*: Sub-array 4 DC tracking error loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"transformer_load_loss", (getter)Losses_get_transformer_load_loss,(setter)Losses_set_transformer_load_loss,
	PyDoc_STR("*float*: Power transformer load loss [%]\n\n**Info:**\npercent of AC output\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"transformer_no_load_loss", (getter)Losses_get_transformer_no_load_loss,(setter)Losses_set_transformer_no_load_loss,
	PyDoc_STR("*float*: Power transformer no load loss [%]\n\n**Info:**\npercent of inverter AC capacity\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"transmission_loss", (getter)Losses_get_transmission_loss,(setter)Losses_set_transmission_loss,
	PyDoc_STR("*float*: Transmission loss [%]\n\n**Info:**\npercent of AC output after transformer losses\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Losses_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Losses",             /*tp_name*/
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
		Losses_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Losses_getset,          /*tp_getset*/
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
 * Lifetime Group
 */ 

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Lifetime_Type.tp_alloc(&Lifetime_Type,0);

	VarGroupObject* Lifetime_obj = (VarGroupObject*)new_obj;

	Lifetime_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Lifetime methods */

static PyObject *
Lifetime_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Lifetime_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Lifetime_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Lifetime_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Lifetime_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lifetime_get_ac_lifetime_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Lifetime_ac_lifetime_losses_aget, self->data_ptr);
}

static int
Lifetime_set_ac_lifetime_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Lifetime_ac_lifetime_losses_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_analysis_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Lifetime_analysis_period_nget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Lifetime_analysis_period_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_dc_degradation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Lifetime_dc_degradation_aget, self->data_ptr);
}

static int
Lifetime_set_dc_degradation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Lifetime_dc_degradation_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_dc_lifetime_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Lifetime_dc_lifetime_losses_aget, self->data_ptr);
}

static int
Lifetime_set_dc_lifetime_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Lifetime_dc_lifetime_losses_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_en_ac_lifetime_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Lifetime_en_ac_lifetime_losses_nget, self->data_ptr);
}

static int
Lifetime_set_en_ac_lifetime_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Lifetime_en_ac_lifetime_losses_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_en_dc_lifetime_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Lifetime_en_dc_lifetime_losses_nget, self->data_ptr);
}

static int
Lifetime_set_en_dc_lifetime_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Lifetime_en_dc_lifetime_losses_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_inflation_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Lifetime_inflation_rate_nget, self->data_ptr);
}

static int
Lifetime_set_inflation_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Lifetime_inflation_rate_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_save_full_lifetime_variables(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Lifetime_save_full_lifetime_variables_nget, self->data_ptr);
}

static int
Lifetime_set_save_full_lifetime_variables(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Lifetime_save_full_lifetime_variables_nset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Lifetime_system_use_lifetime_output_nget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Lifetime_system_use_lifetime_output_nset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"ac_lifetime_losses", (getter)Lifetime_get_ac_lifetime_losses,(setter)Lifetime_set_ac_lifetime_losses,
	PyDoc_STR("*sequence*: Lifetime daily AC losses [%]\n\n**Required:**\nRequired if en_ac_lifetime_losses=1"),
 	NULL},
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	PyDoc_STR("*float*: Lifetime analysis period [years]\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"dc_degradation", (getter)Lifetime_get_dc_degradation,(setter)Lifetime_set_dc_degradation,
	PyDoc_STR("*sequence*: Annual DC degradation [%/year]\n\n**Required:**\nRequired if system_use_lifetime_output=1"),
 	NULL},
{"dc_lifetime_losses", (getter)Lifetime_get_dc_lifetime_losses,(setter)Lifetime_set_dc_lifetime_losses,
	PyDoc_STR("*sequence*: Lifetime daily DC losses [%]\n\n**Required:**\nRequired if en_dc_lifetime_losses=1"),
 	NULL},
{"en_ac_lifetime_losses", (getter)Lifetime_get_en_ac_lifetime_losses,(setter)Lifetime_set_en_ac_lifetime_losses,
	PyDoc_STR("*float*: Enable lifetime daily AC losses [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_dc_lifetime_losses", (getter)Lifetime_get_en_dc_lifetime_losses,(setter)Lifetime_set_en_dc_lifetime_losses,
	PyDoc_STR("*float*: Enable lifetime daily DC losses [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inflation_rate", (getter)Lifetime_get_inflation_rate,(setter)Lifetime_set_inflation_rate,
	PyDoc_STR("*float*: Inflation rate [%]\n\n**Constraints:**\nMIN=-99\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"save_full_lifetime_variables", (getter)Lifetime_get_save_full_lifetime_variables,(setter)Lifetime_set_save_full_lifetime_variables,
	PyDoc_STR("*float*: Save and display vars for full lifetime [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	PyDoc_STR("*float*: PV lifetime simulation [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Lifetime",             /*tp_name*/
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
		Lifetime_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Lifetime_getset,          /*tp_getset*/
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
SystemDesign_new(SAM_Pvsamv1 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "SystemDesign")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "SystemDesign")){
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
SystemDesign_get_enable_mismatch_vmax_calc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_enable_mismatch_vmax_calc_nget, self->data_ptr);
}

static int
SystemDesign_set_enable_mismatch_vmax_calc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_enable_mismatch_vmax_calc_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_inverter_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_inverter_count_nget, self->data_ptr);
}

static int
SystemDesign_set_inverter_count(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_inverter_count_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_measured_temp_array(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemDesign_measured_temp_array_aget, self->data_ptr);
}

static int
SystemDesign_set_measured_temp_array(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemDesign_measured_temp_array_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_backtrack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_backtrack_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_backtrack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_backtrack_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_modules_per_string(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_modules_per_string_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_modules_per_string(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_modules_per_string_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_monthly_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemDesign_subarray1_monthly_tilt_aget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_monthly_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_monthly_tilt_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_mppt_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_mppt_input_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_mppt_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_mppt_input_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_nstrings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_nstrings_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_nstrings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_nstrings_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_rotlim_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_rotlim_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_slope_azm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_slope_azm_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_slope_azm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_slope_azm_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_slope_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_slope_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_slope_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_slope_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_tilt_eq_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_tilt_eq_lat_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_tilt_eq_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_tilt_eq_lat_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray1_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray1_track_mode_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray1_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray1_track_mode_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_backtrack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_backtrack_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_backtrack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_backtrack_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_enable_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_enable_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_modules_per_string(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_modules_per_string_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_modules_per_string(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_modules_per_string_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_monthly_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemDesign_subarray2_monthly_tilt_aget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_monthly_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_monthly_tilt_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_mppt_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_mppt_input_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_mppt_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_mppt_input_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_nstrings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_nstrings_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_nstrings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_nstrings_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_rotlim_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_rotlim_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_slope_azm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_slope_azm_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_slope_azm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_slope_azm_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_slope_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_slope_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_slope_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_slope_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_tilt_eq_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_tilt_eq_lat_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_tilt_eq_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_tilt_eq_lat_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray2_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray2_track_mode_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray2_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray2_track_mode_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_backtrack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_backtrack_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_backtrack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_backtrack_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_enable_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_enable_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_modules_per_string(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_modules_per_string_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_modules_per_string(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_modules_per_string_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_monthly_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemDesign_subarray3_monthly_tilt_aget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_monthly_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_monthly_tilt_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_mppt_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_mppt_input_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_mppt_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_mppt_input_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_nstrings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_nstrings_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_nstrings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_nstrings_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_rotlim_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_rotlim_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_slope_azm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_slope_azm_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_slope_azm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_slope_azm_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_slope_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_slope_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_slope_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_slope_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_tilt_eq_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_tilt_eq_lat_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_tilt_eq_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_tilt_eq_lat_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray3_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray3_track_mode_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray3_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray3_track_mode_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_azimuth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_azimuth_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_azimuth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_azimuth_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_backtrack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_backtrack_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_backtrack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_backtrack_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_enable_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_enable_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_gcr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_gcr_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_gcr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_gcr_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_modules_per_string(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_modules_per_string_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_modules_per_string(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_modules_per_string_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_monthly_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemDesign_subarray4_monthly_tilt_aget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_monthly_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_monthly_tilt_aset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_mppt_input(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_mppt_input_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_mppt_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_mppt_input_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_nstrings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_nstrings_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_nstrings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_nstrings_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_rotlim(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_rotlim_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_rotlim(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_rotlim_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_slope_azm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_slope_azm_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_slope_azm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_slope_azm_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_slope_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_slope_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_slope_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_slope_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_tilt_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_tilt_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_tilt_eq_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_tilt_eq_lat_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_tilt_eq_lat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_tilt_eq_lat_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_subarray4_track_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_subarray4_track_mode_nget, self->data_ptr);
}

static int
SystemDesign_set_subarray4_track_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_subarray4_track_mode_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_system_capacity_nget, self->data_ptr);
}

static int
SystemDesign_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_system_capacity_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_use_measured_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemDesign_use_measured_temp_nget, self->data_ptr);
}

static int
SystemDesign_set_use_measured_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemDesign_use_measured_temp_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"enable_mismatch_vmax_calc", (getter)SystemDesign_get_enable_mismatch_vmax_calc,(setter)SystemDesign_set_enable_mismatch_vmax_calc,
	PyDoc_STR("*float*: Enable mismatched subarray Vmax calculation\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inverter_count", (getter)SystemDesign_get_inverter_count,(setter)SystemDesign_set_inverter_count,
	PyDoc_STR("*float*: Number of inverters\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue\n\nThe value of ``inverter_count`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"measured_temp_array", (getter)SystemDesign_get_measured_temp_array,(setter)SystemDesign_set_measured_temp_array,
	PyDoc_STR("*sequence*: Measured module temperature [C]\n\n**Required:**\nRequired if use_measured_temp=1"),
 	NULL},
{"subarray1_azimuth", (getter)SystemDesign_get_subarray1_azimuth,(setter)SystemDesign_set_subarray1_azimuth,
	PyDoc_STR("*float*: Sub-array 1 Azimuth [degrees]\n\n**Options:**\n0=N,90=E,180=S,270=W\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nsubarray1_track_mode~2&subarray1_track_mode~3"),
 	NULL},
{"subarray1_backtrack", (getter)SystemDesign_get_subarray1_backtrack,(setter)SystemDesign_set_subarray1_backtrack,
	PyDoc_STR("*float*: Sub-array 1 Backtracking enabled\n\n**Options:**\n0=no backtracking,1=backtrack\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nRequired if subarray1_track_mode=1"),
 	NULL},
{"subarray1_gcr", (getter)SystemDesign_get_subarray1_gcr,(setter)SystemDesign_set_subarray1_gcr,
	PyDoc_STR("*float*: Sub-array 1 Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0.01,MAX=0.99\n\n**Required:**\nFalse. Automatically set to 0.3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_modules_per_string", (getter)SystemDesign_get_subarray1_modules_per_string,(setter)SystemDesign_set_subarray1_modules_per_string,
	PyDoc_STR("*float*: Sub-array 1 Modules per string\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``subarray1_modules_per_string``:\n\n\t - system_capacity\n\n\nThe value of ``subarray1_modules_per_string`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"subarray1_monthly_tilt", (getter)SystemDesign_get_subarray1_monthly_tilt,(setter)SystemDesign_set_subarray1_monthly_tilt,
	PyDoc_STR("*sequence*: Sub-array 1 monthly tilt input [degrees]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if subarray1_track_mode=4"),
 	NULL},
{"subarray1_mppt_input", (getter)SystemDesign_get_subarray1_mppt_input,(setter)SystemDesign_set_subarray1_mppt_input,
	PyDoc_STR("*float*: Sub-array 1 Inverter MPPT input number\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_nstrings", (getter)SystemDesign_get_subarray1_nstrings,(setter)SystemDesign_set_subarray1_nstrings,
	PyDoc_STR("*float*: Sub-array 1 Number of parallel strings\n\n**Constraints:**\nINTEGER\n\nThe value of the following variables depends on ``subarray1_nstrings``:\n\n\t - system_capacity\n\n\nThe value of ``subarray1_nstrings`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"subarray1_rotlim", (getter)SystemDesign_get_subarray1_rotlim,(setter)SystemDesign_set_subarray1_rotlim,
	PyDoc_STR("*float*: Sub-array 1 Tracker rotation limit [degrees]\n\n**Constraints:**\nMIN=0,MAX=85\n\n**Required:**\nFalse. Automatically set to 45 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_slope_azm", (getter)SystemDesign_get_subarray1_slope_azm,(setter)SystemDesign_set_subarray1_slope_azm,
	PyDoc_STR("*float*: Sub-array 1 terrain azimuth [degrees]\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray1_track_mode=1"),
 	NULL},
{"subarray1_slope_tilt", (getter)SystemDesign_get_subarray1_slope_tilt,(setter)SystemDesign_set_subarray1_slope_tilt,
	PyDoc_STR("*float*: Sub-array 1 terrain tilt [degrees]\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray1_track_mode=1"),
 	NULL},
{"subarray1_tilt", (getter)SystemDesign_get_subarray1_tilt,(setter)SystemDesign_set_subarray1_tilt,
	PyDoc_STR("*float*: Sub-array 1 Tilt [degrees]\n\n**Options:**\n0=horizontal,90=vertical\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nsubarray1_track_mode~2&subarray1_track_mode~4"),
 	NULL},
{"subarray1_tilt_eq_lat", (getter)SystemDesign_get_subarray1_tilt_eq_lat,(setter)SystemDesign_set_subarray1_tilt_eq_lat,
	PyDoc_STR("*float*: Sub-array 1 Tilt=latitude override [0/1]\n\n**Options:**\n0=false,1=override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_track_mode", (getter)SystemDesign_get_subarray1_track_mode,(setter)SystemDesign_set_subarray1_track_mode,
	PyDoc_STR("*float*: Sub-array 1 Tracking mode\n\n**Options:**\n0=fixed,1=1axis,2=2axis,3=azi,4=monthly\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nTrue"),
 	NULL},
{"subarray2_azimuth", (getter)SystemDesign_get_subarray2_azimuth,(setter)SystemDesign_set_subarray2_azimuth,
	PyDoc_STR("*float*: Sub-array 2 Azimuth [degrees]\n\n**Options:**\n0=N,90=E,180=S,270=W\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray2_enable=1&subarray2_track_mode~2&subarray2_track_mode~3"),
 	NULL},
{"subarray2_backtrack", (getter)SystemDesign_get_subarray2_backtrack,(setter)SystemDesign_set_subarray2_backtrack,
	PyDoc_STR("*float*: Sub-array 2 Backtracking enabled\n\n**Options:**\n0=no backtracking,1=backtrack\n\n**Constraints:**\nBOOLEAN"),
 	NULL},
{"subarray2_enable", (getter)SystemDesign_get_subarray2_enable,(setter)SystemDesign_set_subarray2_enable,
	PyDoc_STR("*float*: Sub-array 2 Enable [0/1]\n\n**Options:**\n0=disabled,1=enabled\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``subarray2_enable``:\n\n\t - system_capacity\n\n\nThe value of ``subarray2_enable`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"subarray2_gcr", (getter)SystemDesign_get_subarray2_gcr,(setter)SystemDesign_set_subarray2_gcr,
	PyDoc_STR("*float*: Sub-array 2 Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0.01,MAX=0.99\n\n**Required:**\nFalse. Automatically set to 0.3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray2_modules_per_string", (getter)SystemDesign_get_subarray2_modules_per_string,(setter)SystemDesign_set_subarray2_modules_per_string,
	PyDoc_STR("*float*: Sub-array 2 Modules per string\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nRequired if subarray2_enable=1\n\nThe value of the following variables depends on ``subarray2_modules_per_string``:\n\n\t - system_capacity\n"),
 	NULL},
{"subarray2_monthly_tilt", (getter)SystemDesign_get_subarray2_monthly_tilt,(setter)SystemDesign_set_subarray2_monthly_tilt,
	PyDoc_STR("*sequence*: Sub-array 2 Monthly tilt input [degrees]\n\n**Constraints:**\nLENGTH=12\n\n**Required:**\nRequired if subarray2_track_mode=4"),
 	NULL},
{"subarray2_mppt_input", (getter)SystemDesign_get_subarray2_mppt_input,(setter)SystemDesign_set_subarray2_mppt_input,
	PyDoc_STR("*float*: Sub-array 2 Inverter MPPT input number\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray2_nstrings", (getter)SystemDesign_get_subarray2_nstrings,(setter)SystemDesign_set_subarray2_nstrings,
	PyDoc_STR("*float*: Sub-array 2 Number of parallel strings\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nRequired if subarray2_enable=1\n\nThe value of the following variables depends on ``subarray2_nstrings``:\n\n\t - system_capacity\n"),
 	NULL},
{"subarray2_rotlim", (getter)SystemDesign_get_subarray2_rotlim,(setter)SystemDesign_set_subarray2_rotlim,
	PyDoc_STR("*float*: Sub-array 2 Tracker rotation limit [degrees]\n\n**Constraints:**\nMIN=0,MAX=85\n\n**Required:**\nFalse. Automatically set to 45 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray2_slope_azm", (getter)SystemDesign_get_subarray2_slope_azm,(setter)SystemDesign_set_subarray2_slope_azm,
	PyDoc_STR("*float*: Sub-array 2 terrain azimuth [degrees]\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray2_enable=1&subarray2_track_mode=1"),
 	NULL},
{"subarray2_slope_tilt", (getter)SystemDesign_get_subarray2_slope_tilt,(setter)SystemDesign_set_subarray2_slope_tilt,
	PyDoc_STR("*float*: Sub-array 2 terrain tilt [degrees]\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray2_enable=1&subarray2_track_mode=1"),
 	NULL},
{"subarray2_tilt", (getter)SystemDesign_get_subarray2_tilt,(setter)SystemDesign_set_subarray2_tilt,
	PyDoc_STR("*float*: Sub-array 2 Tilt [degrees]\n\n**Options:**\n0=horizontal,90=vertical\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray2_enable=1&subarray2_track_mode~2&subarray2_track_mode~4"),
 	NULL},
{"subarray2_tilt_eq_lat", (getter)SystemDesign_get_subarray2_tilt_eq_lat,(setter)SystemDesign_set_subarray2_tilt_eq_lat,
	PyDoc_STR("*float*: Sub-array 2 Tilt=latitude override [0/1]\n\n**Options:**\n0=false,1=override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray2_track_mode", (getter)SystemDesign_get_subarray2_track_mode,(setter)SystemDesign_set_subarray2_track_mode,
	PyDoc_STR("*float*: Sub-array 2 Tracking mode\n\n**Options:**\n0=fixed,1=1axis,2=2axis,3=azi,4=monthly\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray3_azimuth", (getter)SystemDesign_get_subarray3_azimuth,(setter)SystemDesign_set_subarray3_azimuth,
	PyDoc_STR("*float*: Sub-array 3 Azimuth [degrees]\n\n**Options:**\n0=N,90=E,180=S,270=W\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray3_enable=1&subarray3_track_mode~2&subarray3_track_mode~3"),
 	NULL},
{"subarray3_backtrack", (getter)SystemDesign_get_subarray3_backtrack,(setter)SystemDesign_set_subarray3_backtrack,
	PyDoc_STR("*float*: Sub-array 3 Backtracking enabled\n\n**Options:**\n0=no backtracking,1=backtrack\n\n**Constraints:**\nBOOLEAN"),
 	NULL},
{"subarray3_enable", (getter)SystemDesign_get_subarray3_enable,(setter)SystemDesign_set_subarray3_enable,
	PyDoc_STR("*float*: Sub-array 3 Enable [0/1]\n\n**Options:**\n0=disabled,1=enabled\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``subarray3_enable``:\n\n\t - system_capacity\n\n\nThe value of ``subarray3_enable`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"subarray3_gcr", (getter)SystemDesign_get_subarray3_gcr,(setter)SystemDesign_set_subarray3_gcr,
	PyDoc_STR("*float*: Sub-array 3 Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0.01,MAX=0.99\n\n**Required:**\nFalse. Automatically set to 0.3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray3_modules_per_string", (getter)SystemDesign_get_subarray3_modules_per_string,(setter)SystemDesign_set_subarray3_modules_per_string,
	PyDoc_STR("*float*: Sub-array 3 Modules per string\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nRequired if subarray3_enable=1\n\nThe value of the following variables depends on ``subarray3_modules_per_string``:\n\n\t - system_capacity\n"),
 	NULL},
{"subarray3_monthly_tilt", (getter)SystemDesign_get_subarray3_monthly_tilt,(setter)SystemDesign_set_subarray3_monthly_tilt,
	PyDoc_STR("*sequence*: Sub-array 3 Monthly tilt input [degrees]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"subarray3_mppt_input", (getter)SystemDesign_get_subarray3_mppt_input,(setter)SystemDesign_set_subarray3_mppt_input,
	PyDoc_STR("*float*: Sub-array 3 Inverter MPPT input number\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray3_nstrings", (getter)SystemDesign_get_subarray3_nstrings,(setter)SystemDesign_set_subarray3_nstrings,
	PyDoc_STR("*float*: Sub-array 3 Number of parallel strings\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nRequired if subarray3_enable=1\n\nThe value of the following variables depends on ``subarray3_nstrings``:\n\n\t - system_capacity\n"),
 	NULL},
{"subarray3_rotlim", (getter)SystemDesign_get_subarray3_rotlim,(setter)SystemDesign_set_subarray3_rotlim,
	PyDoc_STR("*float*: Sub-array 3 Tracker rotation limit [degrees]\n\n**Constraints:**\nMIN=0,MAX=85\n\n**Required:**\nFalse. Automatically set to 45 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray3_slope_azm", (getter)SystemDesign_get_subarray3_slope_azm,(setter)SystemDesign_set_subarray3_slope_azm,
	PyDoc_STR("*float*: Sub-array 3 terrain azimuth [degrees]\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray3_enable=1&subarray3_track_mode=1"),
 	NULL},
{"subarray3_slope_tilt", (getter)SystemDesign_get_subarray3_slope_tilt,(setter)SystemDesign_set_subarray3_slope_tilt,
	PyDoc_STR("*float*: Sub-array 3 terrain tilt [degrees]\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray3_enable=1&subarray3_track_mode=1"),
 	NULL},
{"subarray3_tilt", (getter)SystemDesign_get_subarray3_tilt,(setter)SystemDesign_set_subarray3_tilt,
	PyDoc_STR("*float*: Sub-array 3 Tilt [degrees]\n\n**Options:**\n0=horizontal,90=vertical\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray3_enable=1&subarray3_track_mode~2&subarray3_track_mode~4"),
 	NULL},
{"subarray3_tilt_eq_lat", (getter)SystemDesign_get_subarray3_tilt_eq_lat,(setter)SystemDesign_set_subarray3_tilt_eq_lat,
	PyDoc_STR("*float*: Sub-array 3 Tilt=latitude override [0/1]\n\n**Options:**\n0=false,1=override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray3_track_mode", (getter)SystemDesign_get_subarray3_track_mode,(setter)SystemDesign_set_subarray3_track_mode,
	PyDoc_STR("*float*: Sub-array 3 Tracking mode\n\n**Options:**\n0=fixed,1=1axis,2=2axis,3=azi,4=monthly\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray4_azimuth", (getter)SystemDesign_get_subarray4_azimuth,(setter)SystemDesign_set_subarray4_azimuth,
	PyDoc_STR("*float*: Sub-array 4 Azimuth [degrees]\n\n**Options:**\n0=N,90=E,180=S,270=W\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray4_enable=1&subarray4_track_mode~2&subarray4_track_mode~3"),
 	NULL},
{"subarray4_backtrack", (getter)SystemDesign_get_subarray4_backtrack,(setter)SystemDesign_set_subarray4_backtrack,
	PyDoc_STR("*float*: Sub-array 4 Backtracking enabled\n\n**Options:**\n0=no backtracking,1=backtrack\n\n**Constraints:**\nBOOLEAN"),
 	NULL},
{"subarray4_enable", (getter)SystemDesign_get_subarray4_enable,(setter)SystemDesign_set_subarray4_enable,
	PyDoc_STR("*float*: Sub-array 4 Enable [0/1]\n\n**Options:**\n0=disabled,1=enabled\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``subarray4_enable``:\n\n\t - system_capacity\n\n\nThe value of ``subarray4_enable`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"subarray4_gcr", (getter)SystemDesign_get_subarray4_gcr,(setter)SystemDesign_set_subarray4_gcr,
	PyDoc_STR("*float*: Sub-array 4 Ground coverage ratio [0..1]\n\n**Constraints:**\nMIN=0.01,MAX=0.99\n\n**Required:**\nFalse. Automatically set to 0.3 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray4_modules_per_string", (getter)SystemDesign_get_subarray4_modules_per_string,(setter)SystemDesign_set_subarray4_modules_per_string,
	PyDoc_STR("*float*: Sub-array 4 Modules per string\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nRequired if subarray4_enable=1\n\nThe value of the following variables depends on ``subarray4_modules_per_string``:\n\n\t - system_capacity\n"),
 	NULL},
{"subarray4_monthly_tilt", (getter)SystemDesign_get_subarray4_monthly_tilt,(setter)SystemDesign_set_subarray4_monthly_tilt,
	PyDoc_STR("*sequence*: Sub-array 4 Monthly tilt input [degrees]\n\n**Constraints:**\nLENGTH=12"),
 	NULL},
{"subarray4_mppt_input", (getter)SystemDesign_get_subarray4_mppt_input,(setter)SystemDesign_set_subarray4_mppt_input,
	PyDoc_STR("*float*: Sub-array 4 Inverter MPPT input number\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray4_nstrings", (getter)SystemDesign_get_subarray4_nstrings,(setter)SystemDesign_set_subarray4_nstrings,
	PyDoc_STR("*float*: Sub-array 4 Number of parallel strings\n\n**Constraints:**\nINTEGER,MIN=1\n\n**Required:**\nRequired if subarray4_enable=1\n\nThe value of the following variables depends on ``subarray4_nstrings``:\n\n\t - system_capacity\n"),
 	NULL},
{"subarray4_rotlim", (getter)SystemDesign_get_subarray4_rotlim,(setter)SystemDesign_set_subarray4_rotlim,
	PyDoc_STR("*float*: Sub-array 4 Tracker rotation limit [degrees]\n\n**Constraints:**\nMIN=0,MAX=85\n\n**Required:**\nFalse. Automatically set to 45 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray4_slope_azm", (getter)SystemDesign_get_subarray4_slope_azm,(setter)SystemDesign_set_subarray4_slope_azm,
	PyDoc_STR("*float*: Sub-array 4 terrain azimuth [degrees]\n\n**Constraints:**\nMIN=0,MAX=359.9\n\n**Required:**\nRequired if subarray4_enable=1&subarray4_track_mode=1"),
 	NULL},
{"subarray4_slope_tilt", (getter)SystemDesign_get_subarray4_slope_tilt,(setter)SystemDesign_set_subarray4_slope_tilt,
	PyDoc_STR("*float*: Sub-array 4 terrain tilt [degrees]\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray4_enable=1&subarray4_track_mode=1"),
 	NULL},
{"subarray4_tilt", (getter)SystemDesign_get_subarray4_tilt,(setter)SystemDesign_set_subarray4_tilt,
	PyDoc_STR("*float*: Sub-array 4 Tilt [degrees]\n\n**Options:**\n0=horizontal,90=vertical\n\n**Constraints:**\nMIN=0,MAX=90\n\n**Required:**\nRequired if subarray4_enable=1&subarray4_track_mode~2&subarray4_track_mode~4"),
 	NULL},
{"subarray4_tilt_eq_lat", (getter)SystemDesign_get_subarray4_tilt_eq_lat,(setter)SystemDesign_set_subarray4_tilt_eq_lat,
	PyDoc_STR("*float*: Sub-array 4 Tilt=latitude override [0/1]\n\n**Options:**\n0=false,1=override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray4_track_mode", (getter)SystemDesign_get_subarray4_track_mode,(setter)SystemDesign_set_subarray4_track_mode,
	PyDoc_STR("*float*: Sub-array 4 Tracking mode\n\n**Options:**\n0=fixed,1=1axis,2=2axis,3=azi,4=monthly\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"system_capacity", (getter)SystemDesign_get_system_capacity,(setter)SystemDesign_set_system_capacity,
	PyDoc_STR("*float*: DC Nameplate capacity [kWdc]\n\n**Required:**\nTrue\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray2_modules_per_string\n\t - subarray2_nstrings\n\t - subarray3_enable\n\t - subarray3_modules_per_string\n\t - subarray3_nstrings\n\t - subarray4_enable\n\t - subarray4_modules_per_string\n\t - subarray4_nstrings\n"),
 	NULL},
{"use_measured_temp", (getter)SystemDesign_get_use_measured_temp,(setter)SystemDesign_set_use_measured_temp,
	PyDoc_STR("*float*: Use measured temperatures [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.SystemDesign",             /*tp_name*/
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
 * Shading Group
 */ 

static PyTypeObject Shading_Type;

static PyObject *
Shading_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Shading_Type.tp_alloc(&Shading_Type,0);

	VarGroupObject* Shading_obj = (VarGroupObject*)new_obj;

	Shading_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Shading methods */

static PyObject *
Shading_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Shading")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Shading_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Shading_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Shading")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Shading_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Shading_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Shading_methods[] = {
		{"assign",            (PyCFunction)Shading_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Shading_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Shading_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Shading_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Shading_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Shading_get_subarray1_shade_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray1_shade_mode_nget, self->data_ptr);
}

static int
Shading_set_subarray1_shade_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray1_shade_mode_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray1_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray1_shading_azal_mget, self->data_ptr);
}

static int
Shading_set_subarray1_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray1_shading_azal_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray1_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray1_shading_diff_nget, self->data_ptr);
}

static int
Shading_set_subarray1_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray1_shading_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray1_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray1_shading_mxh_mget, self->data_ptr);
}

static int
Shading_set_subarray1_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray1_shading_mxh_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray1_shading_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray1_shading_string_option_nget, self->data_ptr);
}

static int
Shading_set_subarray1_shading_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray1_shading_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray1_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray1_shading_timestep_mget, self->data_ptr);
}

static int
Shading_set_subarray1_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray1_shading_timestep_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray2_shade_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray2_shade_mode_nget, self->data_ptr);
}

static int
Shading_set_subarray2_shade_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray2_shade_mode_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray2_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray2_shading_azal_mget, self->data_ptr);
}

static int
Shading_set_subarray2_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray2_shading_azal_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray2_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray2_shading_diff_nget, self->data_ptr);
}

static int
Shading_set_subarray2_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray2_shading_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray2_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray2_shading_mxh_mget, self->data_ptr);
}

static int
Shading_set_subarray2_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray2_shading_mxh_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray2_shading_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray2_shading_string_option_nget, self->data_ptr);
}

static int
Shading_set_subarray2_shading_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray2_shading_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray2_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray2_shading_timestep_mget, self->data_ptr);
}

static int
Shading_set_subarray2_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray2_shading_timestep_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray3_shade_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray3_shade_mode_nget, self->data_ptr);
}

static int
Shading_set_subarray3_shade_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray3_shade_mode_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray3_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray3_shading_azal_mget, self->data_ptr);
}

static int
Shading_set_subarray3_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray3_shading_azal_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray3_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray3_shading_diff_nget, self->data_ptr);
}

static int
Shading_set_subarray3_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray3_shading_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray3_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray3_shading_mxh_mget, self->data_ptr);
}

static int
Shading_set_subarray3_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray3_shading_mxh_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray3_shading_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray3_shading_string_option_nget, self->data_ptr);
}

static int
Shading_set_subarray3_shading_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray3_shading_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray3_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray3_shading_timestep_mget, self->data_ptr);
}

static int
Shading_set_subarray3_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray3_shading_timestep_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray4_shade_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray4_shade_mode_nget, self->data_ptr);
}

static int
Shading_set_subarray4_shade_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray4_shade_mode_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray4_shading_azal(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray4_shading_azal_mget, self->data_ptr);
}

static int
Shading_set_subarray4_shading_azal(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray4_shading_azal_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray4_shading_diff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray4_shading_diff_nget, self->data_ptr);
}

static int
Shading_set_subarray4_shading_diff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray4_shading_diff_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray4_shading_mxh(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray4_shading_mxh_mget, self->data_ptr);
}

static int
Shading_set_subarray4_shading_mxh(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray4_shading_mxh_mset, self->data_ptr);
}

static PyObject *
Shading_get_subarray4_shading_string_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Shading_subarray4_shading_string_option_nget, self->data_ptr);
}

static int
Shading_set_subarray4_shading_string_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Shading_subarray4_shading_string_option_nset, self->data_ptr);
}

static PyObject *
Shading_get_subarray4_shading_timestep(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Shading_subarray4_shading_timestep_mget, self->data_ptr);
}

static int
Shading_set_subarray4_shading_timestep(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Shading_subarray4_shading_timestep_mset, self->data_ptr);
}

static PyGetSetDef Shading_getset[] = {
{"subarray1_shade_mode", (getter)Shading_get_subarray1_shade_mode,(setter)Shading_set_subarray1_shade_mode,
	PyDoc_STR("*float*: Sub-array 1 shading mode (fixed tilt or 1x tracking) [0/1/2]\n\n**Options:**\n0=none,1=standard(non-linear),2=thin film(linear)\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_shading_azal", (getter)Shading_get_subarray1_shading_azal,(setter)Shading_set_subarray1_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Sub-array 1 Azimuth x altitude beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray1_shading_diff", (getter)Shading_get_subarray1_shading_diff,(setter)Shading_set_subarray1_shading_diff,
	PyDoc_STR("*float*: Sub-array 1 Diffuse shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray1_shading_mxh", (getter)Shading_get_subarray1_shading_mxh,(setter)Shading_set_subarray1_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Sub-array 1 Month x Hour beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray1_shading_string_option", (getter)Shading_get_subarray1_shading_string_option,(setter)Shading_set_subarray1_shading_string_option,
	PyDoc_STR("*float*: Sub-array 1 shading string option\n\n**Options:**\n0=shadingdb,1=average,2=maximum,3=minimum\n\n**Constraints:**\nINTEGER,MIN=-1,MAX=4\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_shading_timestep", (getter)Shading_get_subarray1_shading_timestep,(setter)Shading_set_subarray1_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Sub-array 1 timestep beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray2_shade_mode", (getter)Shading_get_subarray2_shade_mode,(setter)Shading_set_subarray2_shade_mode,
	PyDoc_STR("*float*: Sub-array 2 Shading mode (fixed tilt or 1x tracking) [0/1/2]\n\n**Options:**\n0=none,1=standard(non-linear),2=thin film(linear)\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_shading_azal", (getter)Shading_get_subarray2_shading_azal,(setter)Shading_set_subarray2_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Sub-array 2 Azimuth x altitude beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray2_shading_diff", (getter)Shading_get_subarray2_shading_diff,(setter)Shading_set_subarray2_shading_diff,
	PyDoc_STR("*float*: Sub-array 2 Diffuse shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray2_shading_mxh", (getter)Shading_get_subarray2_shading_mxh,(setter)Shading_set_subarray2_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Sub-array 2 Month x Hour beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray2_shading_string_option", (getter)Shading_get_subarray2_shading_string_option,(setter)Shading_set_subarray2_shading_string_option,
	PyDoc_STR("*float*: Sub-array 2 Shading string option\n\n**Options:**\n0=shadingdb,1=average,2=maximum,3=minimum\n\n**Constraints:**\nINTEGER,MIN=-1,MAX=4\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray2_shading_timestep", (getter)Shading_get_subarray2_shading_timestep,(setter)Shading_set_subarray2_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Sub-array 2 Timestep beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray3_shade_mode", (getter)Shading_get_subarray3_shade_mode,(setter)Shading_set_subarray3_shade_mode,
	PyDoc_STR("*float*: Sub-array 3 Shading mode (fixed tilt or 1x tracking) [0/1/2]\n\n**Options:**\n0=none,1=standard(non-linear),2=thin film(linear)\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_shading_azal", (getter)Shading_get_subarray3_shading_azal,(setter)Shading_set_subarray3_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Sub-array 3 Azimuth x altitude beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray3_shading_diff", (getter)Shading_get_subarray3_shading_diff,(setter)Shading_set_subarray3_shading_diff,
	PyDoc_STR("*float*: Sub-array 3 Diffuse shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray3_shading_mxh", (getter)Shading_get_subarray3_shading_mxh,(setter)Shading_set_subarray3_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Sub-array 3 Month x Hour beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray3_shading_string_option", (getter)Shading_get_subarray3_shading_string_option,(setter)Shading_set_subarray3_shading_string_option,
	PyDoc_STR("*float*: Sub-array 3 Shading string option\n\n**Options:**\n0=shadingdb,1=average,2=maximum,3=minimum\n\n**Constraints:**\nINTEGER,MIN=-1,MAX=4\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray3_shading_timestep", (getter)Shading_get_subarray3_shading_timestep,(setter)Shading_set_subarray3_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Sub-array 3 Timestep beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray4_shade_mode", (getter)Shading_get_subarray4_shade_mode,(setter)Shading_set_subarray4_shade_mode,
	PyDoc_STR("*float*: Sub-array 4 shading mode (fixed tilt or 1x tracking) [0/1/2]\n\n**Options:**\n0=none,1=standard(non-linear),2=thin film(linear)\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_shading_azal", (getter)Shading_get_subarray4_shading_azal,(setter)Shading_set_subarray4_shading_azal,
	PyDoc_STR("*sequence[sequence]*: Sub-array 4 Azimuth x altitude beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray4_shading_diff", (getter)Shading_get_subarray4_shading_diff,(setter)Shading_set_subarray4_shading_diff,
	PyDoc_STR("*float*: Sub-array 4 Diffuse shading loss [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray4_shading_mxh", (getter)Shading_get_subarray4_shading_mxh,(setter)Shading_set_subarray4_shading_mxh,
	PyDoc_STR("*sequence[sequence]*: Sub-array 4 Month x Hour beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"subarray4_shading_string_option", (getter)Shading_get_subarray4_shading_string_option,(setter)Shading_set_subarray4_shading_string_option,
	PyDoc_STR("*float*: Sub-array 4 Shading string option\n\n**Options:**\n0=shadingdb,1=average,2=maximum,3=minimum\n\n**Constraints:**\nINTEGER,MIN=-1,MAX=4\n\n**Required:**\nFalse. Automatically set to -1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray4_shading_timestep", (getter)Shading_get_subarray4_shading_timestep,(setter)Shading_set_subarray4_shading_timestep,
	PyDoc_STR("*sequence[sequence]*: Sub-array 4 Timestep beam shading losses [%]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Shading_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Shading",             /*tp_name*/
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
		Shading_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Shading_getset,          /*tp_getset*/
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
 * Layout Group
 */ 

static PyTypeObject Layout_Type;

static PyObject *
Layout_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Layout_Type.tp_alloc(&Layout_Type,0);

	VarGroupObject* Layout_obj = (VarGroupObject*)new_obj;

	Layout_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Layout methods */

static PyObject *
Layout_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Layout")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Layout_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Layout_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Layout")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Layout_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Layout_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Layout_methods[] = {
		{"assign",            (PyCFunction)Layout_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Layout_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Layout_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Layout_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Layout_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Layout_get_module_aspect_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_module_aspect_ratio_nget, self->data_ptr);
}

static int
Layout_set_module_aspect_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_module_aspect_ratio_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray1_mod_orient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray1_mod_orient_nget, self->data_ptr);
}

static int
Layout_set_subarray1_mod_orient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray1_mod_orient_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray1_nmodx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray1_nmodx_nget, self->data_ptr);
}

static int
Layout_set_subarray1_nmodx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray1_nmodx_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray1_nmody(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray1_nmody_nget, self->data_ptr);
}

static int
Layout_set_subarray1_nmody(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray1_nmody_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray2_mod_orient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray2_mod_orient_nget, self->data_ptr);
}

static int
Layout_set_subarray2_mod_orient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray2_mod_orient_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray2_nmodx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray2_nmodx_nget, self->data_ptr);
}

static int
Layout_set_subarray2_nmodx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray2_nmodx_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray2_nmody(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray2_nmody_nget, self->data_ptr);
}

static int
Layout_set_subarray2_nmody(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray2_nmody_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray3_mod_orient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray3_mod_orient_nget, self->data_ptr);
}

static int
Layout_set_subarray3_mod_orient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray3_mod_orient_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray3_nmodx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray3_nmodx_nget, self->data_ptr);
}

static int
Layout_set_subarray3_nmodx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray3_nmodx_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray3_nmody(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray3_nmody_nget, self->data_ptr);
}

static int
Layout_set_subarray3_nmody(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray3_nmody_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray4_mod_orient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray4_mod_orient_nget, self->data_ptr);
}

static int
Layout_set_subarray4_mod_orient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray4_mod_orient_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray4_nmodx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray4_nmodx_nget, self->data_ptr);
}

static int
Layout_set_subarray4_nmodx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray4_nmodx_nset, self->data_ptr);
}

static PyObject *
Layout_get_subarray4_nmody(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Layout_subarray4_nmody_nget, self->data_ptr);
}

static int
Layout_set_subarray4_nmody(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Layout_subarray4_nmody_nset, self->data_ptr);
}

static PyGetSetDef Layout_getset[] = {
{"module_aspect_ratio", (getter)Layout_get_module_aspect_ratio,(setter)Layout_set_module_aspect_ratio,
	PyDoc_STR("*float*: Module aspect ratio\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 1.7 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"subarray1_mod_orient", (getter)Layout_get_subarray1_mod_orient,(setter)Layout_set_subarray1_mod_orient,
	PyDoc_STR("*float*: Sub-array 1 Module orientation [0/1]\n\n**Options:**\n0=portrait,1=landscape\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_nmodx", (getter)Layout_get_subarray1_nmodx,(setter)Layout_set_subarray1_nmodx,
	PyDoc_STR("*float*: Sub-array 1 Number of modules along bottom of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"subarray1_nmody", (getter)Layout_get_subarray1_nmody,(setter)Layout_set_subarray1_nmody,
	PyDoc_STR("*float*: Sub-array 1 Number of modules along side of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nTrue"),
 	NULL},
{"subarray2_mod_orient", (getter)Layout_get_subarray2_mod_orient,(setter)Layout_set_subarray2_mod_orient,
	PyDoc_STR("*float*: Sub-array 2 Module orientation [0/1]\n\n**Options:**\n0=portrait,1=landscape\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_nmodx", (getter)Layout_get_subarray2_nmodx,(setter)Layout_set_subarray2_nmodx,
	PyDoc_STR("*float*: Sub-array 2 Number of modules along bottom of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray2_nmody", (getter)Layout_get_subarray2_nmody,(setter)Layout_set_subarray2_nmody,
	PyDoc_STR("*float*: Sub-array 2 Number of modules along side of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if subarray2_enable=1"),
 	NULL},
{"subarray3_mod_orient", (getter)Layout_get_subarray3_mod_orient,(setter)Layout_set_subarray3_mod_orient,
	PyDoc_STR("*float*: Sub-array 3 Module orientation [0/1]\n\n**Options:**\n0=portrait,1=landscape\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_nmodx", (getter)Layout_get_subarray3_nmodx,(setter)Layout_set_subarray3_nmodx,
	PyDoc_STR("*float*: Sub-array 3 Number of modules along bottom of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray3_nmody", (getter)Layout_get_subarray3_nmody,(setter)Layout_set_subarray3_nmody,
	PyDoc_STR("*float*: Sub-array 3 Number of modules along side of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if subarray3_enable=1"),
 	NULL},
{"subarray4_mod_orient", (getter)Layout_get_subarray4_mod_orient,(setter)Layout_set_subarray4_mod_orient,
	PyDoc_STR("*float*: Sub-array 4 Module orientation [0/1]\n\n**Options:**\n0=portrait,1=landscape\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_nmodx", (getter)Layout_get_subarray4_nmodx,(setter)Layout_set_subarray4_nmodx,
	PyDoc_STR("*float*: Sub-array 4 Number of modules along bottom of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
{"subarray4_nmody", (getter)Layout_get_subarray4_nmody,(setter)Layout_set_subarray4_nmody,
	PyDoc_STR("*float*: Sub-array 4 Number of modules along side of row\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if subarray4_enable=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Layout_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Layout",             /*tp_name*/
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
		Layout_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Layout_getset,          /*tp_getset*/
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
 * Module Group
 */ 

static PyTypeObject Module_Type;

static PyObject *
Module_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Module_Type.tp_alloc(&Module_Type,0);

	VarGroupObject* Module_obj = (VarGroupObject*)new_obj;

	Module_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Module methods */

static PyObject *
Module_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Module")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Module_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Module_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Module")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Module_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Module_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Module_methods[] = {
		{"assign",            (PyCFunction)Module_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Module_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Module_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Module_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Module_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Module_get_module_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Module_module_model_nget, self->data_ptr);
}

static int
Module_set_module_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Module_module_model_nset, self->data_ptr);
}

static PyGetSetDef Module_getset[] = {
{"module_model", (getter)Module_get_module_model,(setter)Module_set_module_model,
	PyDoc_STR("*float*: Photovoltaic module model specifier\n\n**Options:**\n0=spe,1=cec,2=6par_user,3=snl,4=sd11-iec61853,5=PVYield\n\n**Constraints:**\nINTEGER,MIN=0,MAX=5\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``module_model``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Module_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Module",             /*tp_name*/
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
		Module_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Module_getset,          /*tp_getset*/
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
 * SimpleEfficiencyModuleModel Group
 */ 

static PyTypeObject SimpleEfficiencyModuleModel_Type;

static PyObject *
SimpleEfficiencyModuleModel_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = SimpleEfficiencyModuleModel_Type.tp_alloc(&SimpleEfficiencyModuleModel_Type,0);

	VarGroupObject* SimpleEfficiencyModuleModel_obj = (VarGroupObject*)new_obj;

	SimpleEfficiencyModuleModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SimpleEfficiencyModuleModel methods */

static PyObject *
SimpleEfficiencyModuleModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "SimpleEfficiencyModuleModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SimpleEfficiencyModuleModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SimpleEfficiencyModuleModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "SimpleEfficiencyModuleModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SimpleEfficiencyModuleModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SimpleEfficiencyModuleModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SimpleEfficiencyModuleModel_methods[] = {
		{"assign",            (PyCFunction)SimpleEfficiencyModuleModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SimpleEfficiencyModuleModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SimpleEfficiencyModuleModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SimpleEfficiencyModuleModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SimpleEfficiencyModuleModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SimpleEfficiencyModuleModel_get_spe_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_a_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_a_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_area_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_area_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_b_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_b_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_bifacial_ground_clearance_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_bifacial_ground_clearance_height_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_bifacial_ground_clearance_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_bifacial_ground_clearance_height_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_bifacial_transmission_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_bifacial_transmission_factor_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_bifacial_transmission_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_bifacial_transmission_factor_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_bifaciality(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_bifaciality_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_bifaciality(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_bifaciality_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_dT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_dT_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_dT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_dT_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_eff0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff0_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_eff0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff0_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_eff1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff1_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_eff1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff1_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_eff2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff2_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_eff2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff2_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_eff3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff3_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_eff3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff3_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_eff4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff4_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_eff4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_eff4_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_fd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_fd_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_fd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_fd_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_is_bifacial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_is_bifacial_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_is_bifacial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_is_bifacial_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_module_structure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_module_structure_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_module_structure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_module_structure_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_rad0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad0_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_rad0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad0_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_rad1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad1_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_rad1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad1_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_rad2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad2_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_rad2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad2_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_rad3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad3_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_rad3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad3_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_rad4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad4_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_rad4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_rad4_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_reference(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_reference_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_reference(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_reference_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_temp_coeff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_temp_coeff_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_temp_coeff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_temp_coeff_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_vmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_vmp_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_vmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_vmp_nset, self->data_ptr);
}

static PyObject *
SimpleEfficiencyModuleModel_get_spe_voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_voc_nget, self->data_ptr);
}

static int
SimpleEfficiencyModuleModel_set_spe_voc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SimpleEfficiencyModuleModel_spe_voc_nset, self->data_ptr);
}

static PyGetSetDef SimpleEfficiencyModuleModel_getset[] = {
{"spe_a", (getter)SimpleEfficiencyModuleModel_get_spe_a,(setter)SimpleEfficiencyModuleModel_set_spe_a,
	PyDoc_STR("*float*: Cell temp parameter a\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_area", (getter)SimpleEfficiencyModuleModel_get_spe_area,(setter)SimpleEfficiencyModuleModel_set_spe_area,
	PyDoc_STR("*float*: Module area [m2]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_area``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_b", (getter)SimpleEfficiencyModuleModel_get_spe_b,(setter)SimpleEfficiencyModuleModel_set_spe_b,
	PyDoc_STR("*float*: Cell temp parameter b\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_bifacial_ground_clearance_height", (getter)SimpleEfficiencyModuleModel_get_spe_bifacial_ground_clearance_height,(setter)SimpleEfficiencyModuleModel_set_spe_bifacial_ground_clearance_height,
	PyDoc_STR("*float*: Module ground clearance height [m]\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_bifacial_transmission_factor", (getter)SimpleEfficiencyModuleModel_get_spe_bifacial_transmission_factor,(setter)SimpleEfficiencyModuleModel_set_spe_bifacial_transmission_factor,
	PyDoc_STR("*float*: Bifacial transmission factor [0-1]\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_bifaciality", (getter)SimpleEfficiencyModuleModel_get_spe_bifaciality,(setter)SimpleEfficiencyModuleModel_set_spe_bifaciality,
	PyDoc_STR("*float*: Bifaciality factor [%]\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_dT", (getter)SimpleEfficiencyModuleModel_get_spe_dT,(setter)SimpleEfficiencyModuleModel_set_spe_dT,
	PyDoc_STR("*float*: Cell temp parameter dT\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_eff0", (getter)SimpleEfficiencyModuleModel_get_spe_eff0,(setter)SimpleEfficiencyModuleModel_set_spe_eff0,
	PyDoc_STR("*float*: Efficiency at irradiance level 0 [%]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_eff0``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_eff1", (getter)SimpleEfficiencyModuleModel_get_spe_eff1,(setter)SimpleEfficiencyModuleModel_set_spe_eff1,
	PyDoc_STR("*float*: Efficiency at irradiance level 1 [%]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_eff1``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_eff2", (getter)SimpleEfficiencyModuleModel_get_spe_eff2,(setter)SimpleEfficiencyModuleModel_set_spe_eff2,
	PyDoc_STR("*float*: Efficiency at irradiance level 2 [%]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_eff2``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_eff3", (getter)SimpleEfficiencyModuleModel_get_spe_eff3,(setter)SimpleEfficiencyModuleModel_set_spe_eff3,
	PyDoc_STR("*float*: Efficiency at irradiance level 3 [%]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_eff3``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_eff4", (getter)SimpleEfficiencyModuleModel_get_spe_eff4,(setter)SimpleEfficiencyModuleModel_set_spe_eff4,
	PyDoc_STR("*float*: Efficiency at irradiance level 4 [%]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_eff4``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_fd", (getter)SimpleEfficiencyModuleModel_get_spe_fd,(setter)SimpleEfficiencyModuleModel_set_spe_fd,
	PyDoc_STR("*float*: Diffuse fraction [0..1]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_is_bifacial", (getter)SimpleEfficiencyModuleModel_get_spe_is_bifacial,(setter)SimpleEfficiencyModuleModel_set_spe_is_bifacial,
	PyDoc_STR("*float*: Modules are bifacial [0/1]\n\n**Options:**\n0=monofacial,1=bifacial\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_module_structure", (getter)SimpleEfficiencyModuleModel_get_spe_module_structure,(setter)SimpleEfficiencyModuleModel_set_spe_module_structure,
	PyDoc_STR("*float*: Mounting and module structure\n\n**Options:**\n0=glass/cell/polymer sheet - open rack,1=glass/cell/glass - open rack,2=polymer/thin film/steel - open rack,3=Insulated back, building-integrated PV,4=close roof mount,5=user-defined\n\n**Constraints:**\nINTEGER,MIN=0,MAX=5\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_rad0", (getter)SimpleEfficiencyModuleModel_get_spe_rad0,(setter)SimpleEfficiencyModuleModel_set_spe_rad0,
	PyDoc_STR("*float*: Irradiance level 0 [W/m2]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_rad0``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_rad1", (getter)SimpleEfficiencyModuleModel_get_spe_rad1,(setter)SimpleEfficiencyModuleModel_set_spe_rad1,
	PyDoc_STR("*float*: Irradiance level 1 [W/m2]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_rad1``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_rad2", (getter)SimpleEfficiencyModuleModel_get_spe_rad2,(setter)SimpleEfficiencyModuleModel_set_spe_rad2,
	PyDoc_STR("*float*: Irradiance level 2 [W/m2]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_rad2``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_rad3", (getter)SimpleEfficiencyModuleModel_get_spe_rad3,(setter)SimpleEfficiencyModuleModel_set_spe_rad3,
	PyDoc_STR("*float*: Irradiance level 3 [W/m2]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_rad3``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_rad4", (getter)SimpleEfficiencyModuleModel_get_spe_rad4,(setter)SimpleEfficiencyModuleModel_set_spe_rad4,
	PyDoc_STR("*float*: Irradiance level 4 [W/m2]\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_rad4``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_reference", (getter)SimpleEfficiencyModuleModel_get_spe_reference,(setter)SimpleEfficiencyModuleModel_set_spe_reference,
	PyDoc_STR("*float*: Reference irradiance level\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_reference``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_temp_coeff", (getter)SimpleEfficiencyModuleModel_get_spe_temp_coeff,(setter)SimpleEfficiencyModuleModel_set_spe_temp_coeff,
	PyDoc_STR("*float*: Temperature coefficient [%/C]\n\n**Required:**\nRequired if module_model=0"),
 	NULL},
{"spe_vmp", (getter)SimpleEfficiencyModuleModel_get_spe_vmp,(setter)SimpleEfficiencyModuleModel_set_spe_vmp,
	PyDoc_STR("*float*: Nominal max power voltage [V]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_vmp``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"spe_voc", (getter)SimpleEfficiencyModuleModel_get_spe_voc,(setter)SimpleEfficiencyModuleModel_set_spe_voc,
	PyDoc_STR("*float*: Nominal open circuit voltage [V]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nRequired if module_model=0\n\nThe value of the following variables depends on ``spe_voc``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SimpleEfficiencyModuleModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.SimpleEfficiencyModuleModel",             /*tp_name*/
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
		SimpleEfficiencyModuleModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SimpleEfficiencyModuleModel_getset,          /*tp_getset*/
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
 * CECPerformanceModelWithModuleDatabase Group
 */ 

static PyTypeObject CECPerformanceModelWithModuleDatabase_Type;

static PyObject *
CECPerformanceModelWithModuleDatabase_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = CECPerformanceModelWithModuleDatabase_Type.tp_alloc(&CECPerformanceModelWithModuleDatabase_Type,0);

	VarGroupObject* CECPerformanceModelWithModuleDatabase_obj = (VarGroupObject*)new_obj;

	CECPerformanceModelWithModuleDatabase_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* CECPerformanceModelWithModuleDatabase methods */

static PyObject *
CECPerformanceModelWithModuleDatabase_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "CECPerformanceModelWithModuleDatabase")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CECPerformanceModelWithModuleDatabase_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &CECPerformanceModelWithModuleDatabase_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "CECPerformanceModelWithModuleDatabase")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CECPerformanceModelWithModuleDatabase_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &CECPerformanceModelWithModuleDatabase_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CECPerformanceModelWithModuleDatabase_methods[] = {
		{"assign",            (PyCFunction)CECPerformanceModelWithModuleDatabase_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``CECPerformanceModelWithModuleDatabase_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)CECPerformanceModelWithModuleDatabase_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``CECPerformanceModelWithModuleDatabase_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)CECPerformanceModelWithModuleDatabase_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_a_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_a_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_a_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_a_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_adjust(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_adjust_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_adjust(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_adjust_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_alpha_sc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_alpha_sc_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_alpha_sc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_alpha_sc_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_area_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_area_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_array_cols(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_array_cols_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_array_cols(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_array_cols_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_array_rows(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_array_rows_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_array_rows(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_array_rows_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_backside_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_backside_temp_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_backside_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_backside_temp_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_beta_oc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_beta_oc_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_beta_oc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_beta_oc_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_bifacial_ground_clearance_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_bifacial_ground_clearance_height_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_bifacial_ground_clearance_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_bifacial_ground_clearance_height_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_bifacial_transmission_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_bifacial_transmission_factor_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_bifacial_transmission_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_bifacial_transmission_factor_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_bifaciality(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_bifaciality_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_bifaciality(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_bifaciality_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_gamma_r(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_gamma_r_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_gamma_r(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_gamma_r_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_gap_spacing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_gap_spacing_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_gap_spacing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_gap_spacing_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_ground_clearance_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_ground_clearance_height_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_ground_clearance_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_ground_clearance_height_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_heat_transfer(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_heat_transfer_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_heat_transfer(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_heat_transfer_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_height_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_height_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_i_l_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_l_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_i_l_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_l_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_i_mp_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_mp_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_i_mp_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_mp_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_i_o_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_o_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_i_o_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_o_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_i_sc_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_sc_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_i_sc_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_i_sc_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_is_bifacial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_is_bifacial_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_is_bifacial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_is_bifacial_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_lacunarity_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_lacunarity_enable_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_lacunarity_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_lacunarity_enable_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_lacunarity_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_lacunarity_length_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_lacunarity_length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_lacunarity_length_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_module_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_module_length_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_module_length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_module_length_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_module_width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_module_width_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_module_width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_module_width_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_mounting_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_mounting_config_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_mounting_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_mounting_config_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_mounting_orientation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_mounting_orientation_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_mounting_orientation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_mounting_orientation_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_n_s(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_n_s_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_n_s(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_n_s_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_r_s(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_r_s_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_r_s(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_r_s_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_r_sh_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_r_sh_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_r_sh_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_r_sh_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_standoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_standoff_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_standoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_standoff_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_t_noct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_t_noct_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_t_noct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_t_noct_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_temp_corr_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_temp_corr_mode_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_temp_corr_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_temp_corr_mode_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_transient_thermal_model_unit_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_transient_thermal_model_unit_mass_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_transient_thermal_model_unit_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_transient_thermal_model_unit_mass_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_v_mp_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_v_mp_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_v_mp_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_v_mp_ref_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithModuleDatabase_get_cec_v_oc_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_v_oc_ref_nget, self->data_ptr);
}

static int
CECPerformanceModelWithModuleDatabase_set_cec_v_oc_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithModuleDatabase_cec_v_oc_ref_nset, self->data_ptr);
}

static PyGetSetDef CECPerformanceModelWithModuleDatabase_getset[] = {
{"cec_a_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_a_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_a_ref,
	PyDoc_STR("*float*: Nonideality factor a\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_adjust", (getter)CECPerformanceModelWithModuleDatabase_get_cec_adjust,(setter)CECPerformanceModelWithModuleDatabase_set_cec_adjust,
	PyDoc_STR("*float*: Temperature coefficient adjustment [%]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_alpha_sc", (getter)CECPerformanceModelWithModuleDatabase_get_cec_alpha_sc,(setter)CECPerformanceModelWithModuleDatabase_set_cec_alpha_sc,
	PyDoc_STR("*float*: Short circuit current temperature coefficient [A/C]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_area", (getter)CECPerformanceModelWithModuleDatabase_get_cec_area,(setter)CECPerformanceModelWithModuleDatabase_set_cec_area,
	PyDoc_STR("*float*: Module area [m2]\n\n**Required:**\nRequired if module_model=1\n\nThe value of the following variables depends on ``cec_area``:\n\n\t - cec_module_length\n"),
 	NULL},
{"cec_array_cols", (getter)CECPerformanceModelWithModuleDatabase_get_cec_array_cols,(setter)CECPerformanceModelWithModuleDatabase_set_cec_array_cols,
	PyDoc_STR("*float*: Columns of modules in array\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_array_rows", (getter)CECPerformanceModelWithModuleDatabase_get_cec_array_rows,(setter)CECPerformanceModelWithModuleDatabase_set_cec_array_rows,
	PyDoc_STR("*float*: Rows of modules in array\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_backside_temp", (getter)CECPerformanceModelWithModuleDatabase_get_cec_backside_temp,(setter)CECPerformanceModelWithModuleDatabase_set_cec_backside_temp,
	PyDoc_STR("*float*: Module backside temperature [C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_beta_oc", (getter)CECPerformanceModelWithModuleDatabase_get_cec_beta_oc,(setter)CECPerformanceModelWithModuleDatabase_set_cec_beta_oc,
	PyDoc_STR("*float*: Open circuit voltage temperature coefficient [V/C]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_bifacial_ground_clearance_height", (getter)CECPerformanceModelWithModuleDatabase_get_cec_bifacial_ground_clearance_height,(setter)CECPerformanceModelWithModuleDatabase_set_cec_bifacial_ground_clearance_height,
	PyDoc_STR("*float*: Module ground clearance height [m]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_bifacial_transmission_factor", (getter)CECPerformanceModelWithModuleDatabase_get_cec_bifacial_transmission_factor,(setter)CECPerformanceModelWithModuleDatabase_set_cec_bifacial_transmission_factor,
	PyDoc_STR("*float*: Bifacial transmission factor [0-1]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_bifaciality", (getter)CECPerformanceModelWithModuleDatabase_get_cec_bifaciality,(setter)CECPerformanceModelWithModuleDatabase_set_cec_bifaciality,
	PyDoc_STR("*float*: Bifaciality factor [%]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_gamma_r", (getter)CECPerformanceModelWithModuleDatabase_get_cec_gamma_r,(setter)CECPerformanceModelWithModuleDatabase_set_cec_gamma_r,
	PyDoc_STR("*float*: Maximum power point temperature coefficient [%/C]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_gap_spacing", (getter)CECPerformanceModelWithModuleDatabase_get_cec_gap_spacing,(setter)CECPerformanceModelWithModuleDatabase_set_cec_gap_spacing,
	PyDoc_STR("*float*: Gap spacing [m]\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_ground_clearance_height", (getter)CECPerformanceModelWithModuleDatabase_get_cec_ground_clearance_height,(setter)CECPerformanceModelWithModuleDatabase_set_cec_ground_clearance_height,
	PyDoc_STR("*float*: Module ground clearance height for heat transfer coefficient [m]\n\n**Required:**\nRequired if cec_lacunarity_enable=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_heat_transfer", (getter)CECPerformanceModelWithModuleDatabase_get_cec_heat_transfer,(setter)CECPerformanceModelWithModuleDatabase_set_cec_heat_transfer,
	PyDoc_STR("*float*: Heat transfer dimensions\n\n**Options:**\n0=module,1=array\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_height", (getter)CECPerformanceModelWithModuleDatabase_get_cec_height,(setter)CECPerformanceModelWithModuleDatabase_set_cec_height,
	PyDoc_STR("*float*: Array mounting height\n\n**Options:**\n0=one story,1=two story\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_i_l_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_i_l_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_i_l_ref,
	PyDoc_STR("*float*: Light current [A]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_i_mp_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_i_mp_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_i_mp_ref,
	PyDoc_STR("*float*: Maximum power point current [A]\n\n**Required:**\nRequired if module_model=1\n\nThe value of the following variables depends on ``cec_i_mp_ref``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"cec_i_o_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_i_o_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_i_o_ref,
	PyDoc_STR("*float*: Saturation current [A]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_i_sc_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_i_sc_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_i_sc_ref,
	PyDoc_STR("*float*: Short circuit current [A]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_is_bifacial", (getter)CECPerformanceModelWithModuleDatabase_get_cec_is_bifacial,(setter)CECPerformanceModelWithModuleDatabase_set_cec_is_bifacial,
	PyDoc_STR("*float*: Modules are bifacial [0/1]\n\n**Options:**\n0=monofacial,1=bifacial\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_lacunarity_enable", (getter)CECPerformanceModelWithModuleDatabase_get_cec_lacunarity_enable,(setter)CECPerformanceModelWithModuleDatabase_set_cec_lacunarity_enable,
	PyDoc_STR("*float*: Enable lacunarity heat transfer model [0/1]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"cec_lacunarity_length", (getter)CECPerformanceModelWithModuleDatabase_get_cec_lacunarity_length,(setter)CECPerformanceModelWithModuleDatabase_set_cec_lacunarity_length,
	PyDoc_STR("*float*: Module lacurnarity length for spatial heterogeneity [C]\n\n**Required:**\nRequired if cec_lacunarity_enable=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_module_length", (getter)CECPerformanceModelWithModuleDatabase_get_cec_module_length,(setter)CECPerformanceModelWithModuleDatabase_set_cec_module_length,
	PyDoc_STR("*float*: Module height [m]\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1\n\nThe value of ``cec_module_length`` depends on the following variables:\n\n\t - cec_area\n\t - cec_module_width\n"),
 	NULL},
{"cec_module_width", (getter)CECPerformanceModelWithModuleDatabase_get_cec_module_width,(setter)CECPerformanceModelWithModuleDatabase_set_cec_module_width,
	PyDoc_STR("*float*: Module width [m]\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1\n\nThe value of the following variables depends on ``cec_module_width``:\n\n\t - cec_module_length\n"),
 	NULL},
{"cec_mounting_config", (getter)CECPerformanceModelWithModuleDatabase_get_cec_mounting_config,(setter)CECPerformanceModelWithModuleDatabase_set_cec_mounting_config,
	PyDoc_STR("*float*: Mounting configuration\n\n**Options:**\n0=rack,1=flush,2=integrated,3=gap\n\n**Constraints:**\nINTEGER,MIN=0,MAX=3\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_mounting_orientation", (getter)CECPerformanceModelWithModuleDatabase_get_cec_mounting_orientation,(setter)CECPerformanceModelWithModuleDatabase_set_cec_mounting_orientation,
	PyDoc_STR("*float*: Mounting structure orientation\n\n**Options:**\n0=do not impede flow,1=vertical supports,2=horizontal supports\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nRequired if module_model=1&cec_temp_corr_mode=1"),
 	NULL},
{"cec_n_s", (getter)CECPerformanceModelWithModuleDatabase_get_cec_n_s,(setter)CECPerformanceModelWithModuleDatabase_set_cec_n_s,
	PyDoc_STR("*float*: Number of cells in series\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_r_s", (getter)CECPerformanceModelWithModuleDatabase_get_cec_r_s,(setter)CECPerformanceModelWithModuleDatabase_set_cec_r_s,
	PyDoc_STR("*float*: Series resistance [ohm]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_r_sh_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_r_sh_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_r_sh_ref,
	PyDoc_STR("*float*: Shunt resistance [ohm]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_standoff", (getter)CECPerformanceModelWithModuleDatabase_get_cec_standoff,(setter)CECPerformanceModelWithModuleDatabase_set_cec_standoff,
	PyDoc_STR("*float*: Standoff mode\n\n**Options:**\n0=bipv,1=>3.5in,2=2.5-3.5in,3=1.5-2.5in,4=0.5-1.5in,5=<0.5in,6=ground/rack\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_t_noct", (getter)CECPerformanceModelWithModuleDatabase_get_cec_t_noct,(setter)CECPerformanceModelWithModuleDatabase_set_cec_t_noct,
	PyDoc_STR("*float*: Nominal operating cell temperature [C]\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_temp_corr_mode", (getter)CECPerformanceModelWithModuleDatabase_get_cec_temp_corr_mode,(setter)CECPerformanceModelWithModuleDatabase_set_cec_temp_corr_mode,
	PyDoc_STR("*float*: Cell temperature model selection\n\n**Options:**\n0=noct,1=mc\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_transient_thermal_model_unit_mass", (getter)CECPerformanceModelWithModuleDatabase_get_cec_transient_thermal_model_unit_mass,(setter)CECPerformanceModelWithModuleDatabase_set_cec_transient_thermal_model_unit_mass,
	PyDoc_STR("*float*: Module unit mass [kg/m^2]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nRequired if module_model=1"),
 	NULL},
{"cec_v_mp_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_v_mp_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_v_mp_ref,
	PyDoc_STR("*float*: Maximum power point voltage [V]\n\n**Required:**\nRequired if module_model=1\n\nThe value of the following variables depends on ``cec_v_mp_ref``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"cec_v_oc_ref", (getter)CECPerformanceModelWithModuleDatabase_get_cec_v_oc_ref,(setter)CECPerformanceModelWithModuleDatabase_set_cec_v_oc_ref,
	PyDoc_STR("*float*: Open circuit voltage [V]\n\n**Required:**\nRequired if module_model=1\n\nThe value of the following variables depends on ``cec_v_oc_ref``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CECPerformanceModelWithModuleDatabase_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.CECPerformanceModelWithModuleDatabase",             /*tp_name*/
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
		CECPerformanceModelWithModuleDatabase_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CECPerformanceModelWithModuleDatabase_getset,          /*tp_getset*/
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
 * CECPerformanceModelWithUserEnteredSpecifications Group
 */ 

static PyTypeObject CECPerformanceModelWithUserEnteredSpecifications_Type;

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = CECPerformanceModelWithUserEnteredSpecifications_Type.tp_alloc(&CECPerformanceModelWithUserEnteredSpecifications_Type,0);

	VarGroupObject* CECPerformanceModelWithUserEnteredSpecifications_obj = (VarGroupObject*)new_obj;

	CECPerformanceModelWithUserEnteredSpecifications_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* CECPerformanceModelWithUserEnteredSpecifications methods */

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "CECPerformanceModelWithUserEnteredSpecifications")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &CECPerformanceModelWithUserEnteredSpecifications_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "CECPerformanceModelWithUserEnteredSpecifications")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &CECPerformanceModelWithUserEnteredSpecifications_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CECPerformanceModelWithUserEnteredSpecifications_methods[] = {
		{"assign",            (PyCFunction)CECPerformanceModelWithUserEnteredSpecifications_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``CECPerformanceModelWithUserEnteredSpecifications_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)CECPerformanceModelWithUserEnteredSpecifications_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``CECPerformanceModelWithUserEnteredSpecifications_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)CECPerformanceModelWithUserEnteredSpecifications_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_aisc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_aisc_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_aisc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_aisc_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_area_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_area_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bifacial_ground_clearance_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bifacial_ground_clearance_height_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bifacial_ground_clearance_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bifacial_ground_clearance_height_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bifacial_transmission_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bifacial_transmission_factor_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bifacial_transmission_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bifacial_transmission_factor_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bifaciality(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bifaciality_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bifaciality(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bifaciality_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bvoc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bvoc_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bvoc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_bvoc_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_celltech(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_celltech_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_celltech(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_celltech_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_gpmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_gpmp_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_gpmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_gpmp_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_imp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_imp_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_imp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_imp_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_is_bifacial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_is_bifacial_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_is_bifacial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_is_bifacial_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_isc_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_isc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_isc_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_mounting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_mounting_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_mounting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_mounting_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_nser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_nser_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_nser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_nser_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_standoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_standoff_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_standoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_standoff_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_tnoct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_tnoct_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_tnoct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_tnoct_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_transient_thermal_model_unit_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_transient_thermal_model_unit_mass_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_transient_thermal_model_unit_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_transient_thermal_model_unit_mass_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_vmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_vmp_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_vmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_vmp_nset, self->data_ptr);
}

static PyObject *
CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_voc_nget, self->data_ptr);
}

static int
CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_voc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_CECPerformanceModelWithUserEnteredSpecifications_sixpar_voc_nset, self->data_ptr);
}

static PyGetSetDef CECPerformanceModelWithUserEnteredSpecifications_getset[] = {
{"sixpar_aisc", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_aisc,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_aisc,
	PyDoc_STR("*float*: Short circuit current temperature coefficient [A/C]\n\n**Required:**\nRequired if module_model=2\n\nThe value of ``sixpar_aisc`` depends on the following variables:\n\n\t - 6par_isc\n"),
 	NULL},
{"sixpar_area", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_area,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_area,
	PyDoc_STR("*float*: Module area [m2]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_bifacial_ground_clearance_height", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bifacial_ground_clearance_height,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bifacial_ground_clearance_height,
	PyDoc_STR("*float*: Module ground clearance height [m]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_bifacial_transmission_factor", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bifacial_transmission_factor,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bifacial_transmission_factor,
	PyDoc_STR("*float*: Bifacial transmission factor [0-1]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_bifaciality", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bifaciality,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bifaciality,
	PyDoc_STR("*float*: Bifaciality factor [%]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_bvoc", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_bvoc,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_bvoc,
	PyDoc_STR("*float*: Open circuit voltage temperature coefficient [V/C]\n\n**Required:**\nRequired if module_model=2\n\nThe value of ``sixpar_bvoc`` depends on the following variables:\n\n\t - 6par_voc\n"),
 	NULL},
{"sixpar_celltech", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_celltech,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_celltech,
	PyDoc_STR("*float*: Solar cell technology type\n\n**Options:**\nmonoSi=0,multiSi=1,CdTe=2,CIS=3,CIGS=4,Amorphous=5\n\n**Constraints:**\nINTEGER,MIN=0,MAX=5\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_gpmp", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_gpmp,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_gpmp,
	PyDoc_STR("*float*: Maximum power point temperature coefficient [%/C]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_imp", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_imp,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_imp,
	PyDoc_STR("*float*: Imp [A]\n\n**Required:**\nRequired if module_model=2\n\nThe value of the following variables depends on ``sixpar_imp``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"sixpar_is_bifacial", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_is_bifacial,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_is_bifacial,
	PyDoc_STR("*float*: Modules are bifacial [0/1]\n\n**Options:**\n0=monofacial,1=bifacial\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_isc", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_isc,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_isc,
	PyDoc_STR("*float*: Isc [A]\n\n**Required:**\nRequired if module_model=2\n\nThe value of the following variables depends on ``sixpar_isc``:\n\n\t - 6par_aisc\n"),
 	NULL},
{"sixpar_mounting", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_mounting,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_mounting,
	PyDoc_STR("*float*: Array mounting height\n\n**Options:**\n0=one story,1=two story\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_nser", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_nser,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_nser,
	PyDoc_STR("*float*: Nseries\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_standoff", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_standoff,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_standoff,
	PyDoc_STR("*float*: Standoff mode\n\n**Options:**\n0=bipv,1=>3.5in,2=2.5-3.5in,3=1.5-2.5in,4=0.5-1.5in,5=<0.5in,6=ground/rack\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_tnoct", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_tnoct,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_tnoct,
	PyDoc_STR("*float*: Nominal operating cell temperature [C]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_transient_thermal_model_unit_mass", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_transient_thermal_model_unit_mass,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_transient_thermal_model_unit_mass,
	PyDoc_STR("*float*: Module unit mass [kg/m^2]\n\n**Required:**\nRequired if module_model=2"),
 	NULL},
{"sixpar_vmp", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_vmp,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_vmp,
	PyDoc_STR("*float*: Maximum power point voltage [V]\n\n**Required:**\nRequired if module_model=2\n\nThe value of the following variables depends on ``sixpar_vmp``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"sixpar_voc", (getter)CECPerformanceModelWithUserEnteredSpecifications_get_sixpar_voc,(setter)CECPerformanceModelWithUserEnteredSpecifications_set_sixpar_voc,
	PyDoc_STR("*float*: Voc [V]\n\n**Required:**\nRequired if module_model=2\n\nThe value of the following variables depends on ``sixpar_voc``:\n\n\t - 6par_bvoc\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CECPerformanceModelWithUserEnteredSpecifications_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.CECPerformanceModelWithUserEnteredSpecifications",             /*tp_name*/
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
		CECPerformanceModelWithUserEnteredSpecifications_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CECPerformanceModelWithUserEnteredSpecifications_getset,          /*tp_getset*/
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
 * SandiaPVArrayPerformanceModelWithModuleDatabase Group
 */ 

static PyTypeObject SandiaPVArrayPerformanceModelWithModuleDatabase_Type;

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = SandiaPVArrayPerformanceModelWithModuleDatabase_Type.tp_alloc(&SandiaPVArrayPerformanceModelWithModuleDatabase_Type,0);

	VarGroupObject* SandiaPVArrayPerformanceModelWithModuleDatabase_obj = (VarGroupObject*)new_obj;

	SandiaPVArrayPerformanceModelWithModuleDatabase_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SandiaPVArrayPerformanceModelWithModuleDatabase methods */

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "SandiaPVArrayPerformanceModelWithModuleDatabase")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SandiaPVArrayPerformanceModelWithModuleDatabase_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "SandiaPVArrayPerformanceModelWithModuleDatabase")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SandiaPVArrayPerformanceModelWithModuleDatabase_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SandiaPVArrayPerformanceModelWithModuleDatabase_methods[] = {
		{"assign",            (PyCFunction)SandiaPVArrayPerformanceModelWithModuleDatabase_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SandiaPVArrayPerformanceModelWithModuleDatabase_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SandiaPVArrayPerformanceModelWithModuleDatabase_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SandiaPVArrayPerformanceModelWithModuleDatabase_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SandiaPVArrayPerformanceModelWithModuleDatabase_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a0_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a0_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a1_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a1_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a2_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a2_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a3_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a3_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a4_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_a4_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_aimp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_aimp_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_aimp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_aimp_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_aisc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_aisc_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_aisc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_aisc_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_area_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_area_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b0_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b0_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b1_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b1_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b2_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b2_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b3_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b3_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b4_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b4_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b5_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_b5_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_bvmpo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_bvmpo_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_bvmpo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_bvmpo_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_bvoco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_bvoco_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_bvoco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_bvoco_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c0_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c0_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c1_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c1_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c2_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c2_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c3_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c3_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c4_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c4_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c5_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c5_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c6_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c6_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c7_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_c7_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_dtc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_dtc_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_dtc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_dtc_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_fd(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_fd_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_fd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_fd_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_impo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_impo_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_impo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_impo_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_isco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_isco_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_isco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_isco_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ixo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ixo_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ixo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ixo_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ixxo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ixxo_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ixxo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ixxo_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_mbvmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_mbvmp_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_mbvmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_mbvmp_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_mbvoc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_mbvoc_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_mbvoc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_mbvoc_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_module_structure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_module_structure_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_module_structure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_module_structure_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_n(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_n_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_n(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_n_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ref_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ref_a_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ref_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ref_a_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ref_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ref_b_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ref_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ref_b_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ref_dT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ref_dT_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ref_dT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_ref_dT_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_series_cells(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_series_cells_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_series_cells(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_series_cells_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_transient_thermal_model_unit_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_transient_thermal_model_unit_mass_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_transient_thermal_model_unit_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_transient_thermal_model_unit_mass_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_vmpo(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_vmpo_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_vmpo(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_vmpo_nset, self->data_ptr);
}

static PyObject *
SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_voco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_voco_nget, self->data_ptr);
}

static int
SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_voco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SandiaPVArrayPerformanceModelWithModuleDatabase_snl_voco_nset, self->data_ptr);
}

static PyGetSetDef SandiaPVArrayPerformanceModelWithModuleDatabase_getset[] = {
{"snl_a", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a,
	PyDoc_STR("*float*: Temperature coefficient a\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_a``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_a0", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a0,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a0,
	PyDoc_STR("*float*: Air mass polynomial coeff 0\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_a0``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_a1", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a1,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a1,
	PyDoc_STR("*float*: Air mass polynomial coeff 1\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_a1``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_a2", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a2,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a2,
	PyDoc_STR("*float*: Air mass polynomial coeff 2\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_a2``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_a3", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a3,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a3,
	PyDoc_STR("*float*: Air mass polynomial coeff 3\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_a3``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_a4", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_a4,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_a4,
	PyDoc_STR("*float*: Air mass polynomial coeff 4\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_a4``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_aimp", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_aimp,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_aimp,
	PyDoc_STR("*float*: Max power point current temperature coefficient\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_aimp``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_aisc", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_aisc,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_aisc,
	PyDoc_STR("*float*: Short circuit current temperature coefficient\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_aisc``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_area", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_area,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_area,
	PyDoc_STR("*float*: Module area\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_area``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b,
	PyDoc_STR("*float*: Temperature coefficient b\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b0", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b0,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b0,
	PyDoc_STR("*float*: Incidence angle modifier polynomial coeff 0\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b0``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b1", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b1,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b1,
	PyDoc_STR("*float*: Incidence angle modifier polynomial coeff 1\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b1``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b2", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b2,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b2,
	PyDoc_STR("*float*: Incidence angle modifier polynomial coeff 2\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b2``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b3", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b3,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b3,
	PyDoc_STR("*float*: Incidence angle modifier polynomial coeff 3\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b3``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b4", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b4,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b4,
	PyDoc_STR("*float*: Incidence angle modifier polynomial coeff 4\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b4``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_b5", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_b5,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_b5,
	PyDoc_STR("*float*: Incidence angle modifier polynomial coeff 5\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_b5``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_bvmpo", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_bvmpo,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_bvmpo,
	PyDoc_STR("*float*: Max power point voltage temperature coefficient\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_bvmpo``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_bvoco", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_bvoco,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_bvoco,
	PyDoc_STR("*float*: Open circuit voltage temperature coefficient\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_bvoco``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_c0", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c0,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c0,
	PyDoc_STR("*float*: C0\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_c0``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_c1", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c1,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c1,
	PyDoc_STR("*float*: C1\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_c1``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_c2", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c2,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c2,
	PyDoc_STR("*float*: C2\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_c2``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_c3", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c3,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c3,
	PyDoc_STR("*float*: C3\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_c3``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_c4", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c4,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c4,
	PyDoc_STR("*float*: C4\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_c5", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c5,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c5,
	PyDoc_STR("*float*: C5\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_c6", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c6,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c6,
	PyDoc_STR("*float*: C6\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_c7", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_c7,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_c7,
	PyDoc_STR("*float*: C7\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_dtc", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_dtc,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_dtc,
	PyDoc_STR("*float*: Temperature coefficient dT\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_dtc``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_fd", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_fd,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_fd,
	PyDoc_STR("*float*: Diffuse fraction\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_fd``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_impo", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_impo,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_impo,
	PyDoc_STR("*float*: Max power point current\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_impo``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_isco", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_isco,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_isco,
	PyDoc_STR("*float*: Short circuit current\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_isco``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_ixo", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ixo,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ixo,
	PyDoc_STR("*float*: Ix midpoint current\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_ixxo", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ixxo,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ixxo,
	PyDoc_STR("*float*: Ixx midpoint current\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_mbvmp", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_mbvmp,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_mbvmp,
	PyDoc_STR("*float*: Irradiance dependence of Vmp temperature coefficient\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_mbvmp``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_mbvoc", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_mbvoc,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_mbvoc,
	PyDoc_STR("*float*: Irradiance dependence of Voc temperature coefficient\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_mbvoc``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_module_structure", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_module_structure,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_module_structure,
	PyDoc_STR("*float*: Module and mounting structure configuration\n\n**Options:**\n0=Use Database Values,1=glass/cell/polymer sheet-open rack,2=glass/cell/glass-open rack,3=polymer/thin film/steel-open rack,4=Insulated back BIPV,5=close roof mount,6=user-defined\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_module_structure``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_n", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_n,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_n,
	PyDoc_STR("*float*: Diode factor\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_n``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_ref_a", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ref_a,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ref_a,
	PyDoc_STR("*float*: User-specified a\n\n**Required:**\nRequired if module_model=3\n\nThe value of ``snl_ref_a`` depends on the following variables:\n\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n"),
 	NULL},
{"snl_ref_b", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ref_b,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ref_b,
	PyDoc_STR("*float*: User-specified b\n\n**Required:**\nRequired if module_model=3\n\nThe value of ``snl_ref_b`` depends on the following variables:\n\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n"),
 	NULL},
{"snl_ref_dT", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_ref_dT,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_ref_dT,
	PyDoc_STR("*float*: User-specified dT\n\n**Required:**\nRequired if module_model=3\n\nThe value of ``snl_ref_dT`` depends on the following variables:\n\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n"),
 	NULL},
{"snl_series_cells", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_series_cells,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_series_cells,
	PyDoc_STR("*float*: Number of cells in series\n\n**Constraints:**\nINTEGER\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_series_cells``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_transient_thermal_model_unit_mass", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_transient_thermal_model_unit_mass,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_transient_thermal_model_unit_mass,
	PyDoc_STR("*float*: Module unit mass [kg/m^2]\n\n**Required:**\nRequired if module_model=3"),
 	NULL},
{"snl_vmpo", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_vmpo,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_vmpo,
	PyDoc_STR("*float*: Max power point voltage\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_vmpo``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"snl_voco", (getter)SandiaPVArrayPerformanceModelWithModuleDatabase_get_snl_voco,(setter)SandiaPVArrayPerformanceModelWithModuleDatabase_set_snl_voco,
	PyDoc_STR("*float*: Open circuit voltage\n\n**Required:**\nRequired if module_model=3\n\nThe value of the following variables depends on ``snl_voco``:\n\n\t - inverter_count\n\t - snl_ref_a\n\t - snl_ref_b\n\t - snl_ref_dT\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SandiaPVArrayPerformanceModelWithModuleDatabase_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.SandiaPVArrayPerformanceModelWithModuleDatabase",             /*tp_name*/
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
		SandiaPVArrayPerformanceModelWithModuleDatabase_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SandiaPVArrayPerformanceModelWithModuleDatabase_getset,          /*tp_getset*/
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
 * IEC61853SingleDiodeModel Group
 */ 

static PyTypeObject IEC61853SingleDiodeModel_Type;

static PyObject *
IEC61853SingleDiodeModel_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = IEC61853SingleDiodeModel_Type.tp_alloc(&IEC61853SingleDiodeModel_Type,0);

	VarGroupObject* IEC61853SingleDiodeModel_obj = (VarGroupObject*)new_obj;

	IEC61853SingleDiodeModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* IEC61853SingleDiodeModel methods */

static PyObject *
IEC61853SingleDiodeModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "IEC61853SingleDiodeModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IEC61853SingleDiodeModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &IEC61853SingleDiodeModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "IEC61853SingleDiodeModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
IEC61853SingleDiodeModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &IEC61853SingleDiodeModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef IEC61853SingleDiodeModel_methods[] = {
		{"assign",            (PyCFunction)IEC61853SingleDiodeModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``IEC61853SingleDiodeModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)IEC61853SingleDiodeModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``IEC61853SingleDiodeModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)IEC61853SingleDiodeModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_AMa0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa0_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_AMa0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa0_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_AMa1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa1_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_AMa1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa1_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_AMa2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa2_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_AMa2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa2_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_AMa3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa3_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_AMa3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa3_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_AMa4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa4_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_AMa4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_AMa4_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Egref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Egref_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Egref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Egref_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Il_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Il(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Il_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Imp0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Imp0_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Imp0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Imp0_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Io_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Io(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Io_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Isc0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Isc0_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Isc0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Isc0_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Vmp0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Vmp0_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Vmp0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Vmp0_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_Voc0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Voc0_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_Voc0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_Voc0_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_alphaIsc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_alphaIsc_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_alphaIsc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_alphaIsc_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_area_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_area_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_c1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_c1_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_c1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_c1_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_c2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_c2_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_c2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_c2_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_c3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_c3_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_c3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_c3_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_d1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_d1_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_d1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_d1_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_d2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_d2_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_d2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_d2_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_d3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_d3_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_d3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_d3_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_glass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_glass_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_glass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_glass_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_mounting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_mounting_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_mounting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_mounting_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_n(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_n_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_n(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_n_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_nser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_nser_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_nser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_nser_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_standoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_standoff_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_standoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_standoff_nset, self->data_ptr);
}

static PyObject *
IEC61853SingleDiodeModel_get_sd11par_tnoct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_tnoct_nget, self->data_ptr);
}

static int
IEC61853SingleDiodeModel_set_sd11par_tnoct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_IEC61853SingleDiodeModel_sd11par_tnoct_nset, self->data_ptr);
}

static PyGetSetDef IEC61853SingleDiodeModel_getset[] = {
{"sd11par_AMa0", (getter)IEC61853SingleDiodeModel_get_sd11par_AMa0,(setter)IEC61853SingleDiodeModel_set_sd11par_AMa0,
	PyDoc_STR("*float*: Air mass modifier coeff 0\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_AMa1", (getter)IEC61853SingleDiodeModel_get_sd11par_AMa1,(setter)IEC61853SingleDiodeModel_set_sd11par_AMa1,
	PyDoc_STR("*float*: Air mass modifier coeff 1\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_AMa2", (getter)IEC61853SingleDiodeModel_get_sd11par_AMa2,(setter)IEC61853SingleDiodeModel_set_sd11par_AMa2,
	PyDoc_STR("*float*: Air mass modifier coeff 2\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_AMa3", (getter)IEC61853SingleDiodeModel_get_sd11par_AMa3,(setter)IEC61853SingleDiodeModel_set_sd11par_AMa3,
	PyDoc_STR("*float*: Air mass modifier coeff 3\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_AMa4", (getter)IEC61853SingleDiodeModel_get_sd11par_AMa4,(setter)IEC61853SingleDiodeModel_set_sd11par_AMa4,
	PyDoc_STR("*float*: Air mass modifier coeff 4\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_Egref", (getter)IEC61853SingleDiodeModel_get_sd11par_Egref,(setter)IEC61853SingleDiodeModel_set_sd11par_Egref,
	PyDoc_STR("*float*: Bandgap voltage [eV]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_Il", (getter)IEC61853SingleDiodeModel_get_sd11par_Il,(setter)IEC61853SingleDiodeModel_set_sd11par_Il,
	PyDoc_STR("*float*: Light current [A]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_Imp0", (getter)IEC61853SingleDiodeModel_get_sd11par_Imp0,(setter)IEC61853SingleDiodeModel_set_sd11par_Imp0,
	PyDoc_STR("*float*: Imp (STC) [A]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_Io", (getter)IEC61853SingleDiodeModel_get_sd11par_Io,(setter)IEC61853SingleDiodeModel_set_sd11par_Io,
	PyDoc_STR("*float*: Saturation current [A]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_Isc0", (getter)IEC61853SingleDiodeModel_get_sd11par_Isc0,(setter)IEC61853SingleDiodeModel_set_sd11par_Isc0,
	PyDoc_STR("*float*: Isc (STC) [A]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_Vmp0", (getter)IEC61853SingleDiodeModel_get_sd11par_Vmp0,(setter)IEC61853SingleDiodeModel_set_sd11par_Vmp0,
	PyDoc_STR("*float*: Vmp (STC) [V]\n\n**Required:**\nRequired if module_model=4\n\nThe value of the following variables depends on ``sd11par_Vmp0``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"sd11par_Voc0", (getter)IEC61853SingleDiodeModel_get_sd11par_Voc0,(setter)IEC61853SingleDiodeModel_set_sd11par_Voc0,
	PyDoc_STR("*float*: Voc (STC) [V]\n\n**Required:**\nRequired if module_model=4\n\nThe value of the following variables depends on ``sd11par_Voc0``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"sd11par_alphaIsc", (getter)IEC61853SingleDiodeModel_get_sd11par_alphaIsc,(setter)IEC61853SingleDiodeModel_set_sd11par_alphaIsc,
	PyDoc_STR("*float*: Short curcuit current temperature coefficient [A/C]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_area", (getter)IEC61853SingleDiodeModel_get_sd11par_area,(setter)IEC61853SingleDiodeModel_set_sd11par_area,
	PyDoc_STR("*float*: Module area [m2]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_c1", (getter)IEC61853SingleDiodeModel_get_sd11par_c1,(setter)IEC61853SingleDiodeModel_set_sd11par_c1,
	PyDoc_STR("*float*: Rsh fit parameter 1\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_c2", (getter)IEC61853SingleDiodeModel_get_sd11par_c2,(setter)IEC61853SingleDiodeModel_set_sd11par_c2,
	PyDoc_STR("*float*: Rsh fit parameter 2\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_c3", (getter)IEC61853SingleDiodeModel_get_sd11par_c3,(setter)IEC61853SingleDiodeModel_set_sd11par_c3,
	PyDoc_STR("*float*: Rsh fit parameter 3\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_d1", (getter)IEC61853SingleDiodeModel_get_sd11par_d1,(setter)IEC61853SingleDiodeModel_set_sd11par_d1,
	PyDoc_STR("*float*: Rs fit parameter 1\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_d2", (getter)IEC61853SingleDiodeModel_get_sd11par_d2,(setter)IEC61853SingleDiodeModel_set_sd11par_d2,
	PyDoc_STR("*float*: Rs fit parameter 2\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_d3", (getter)IEC61853SingleDiodeModel_get_sd11par_d3,(setter)IEC61853SingleDiodeModel_set_sd11par_d3,
	PyDoc_STR("*float*: Rs fit parameter 3\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_glass", (getter)IEC61853SingleDiodeModel_get_sd11par_glass,(setter)IEC61853SingleDiodeModel_set_sd11par_glass,
	PyDoc_STR("*float*: Module cover glass type\n\n**Options:**\n0=normal,1=AR glass\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_mounting", (getter)IEC61853SingleDiodeModel_get_sd11par_mounting,(setter)IEC61853SingleDiodeModel_set_sd11par_mounting,
	PyDoc_STR("*float*: Array mounting height\n\n**Options:**\n0=one story,1=two story\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_n", (getter)IEC61853SingleDiodeModel_get_sd11par_n,(setter)IEC61853SingleDiodeModel_set_sd11par_n,
	PyDoc_STR("*float*: Diode nonideality factor\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_nser", (getter)IEC61853SingleDiodeModel_get_sd11par_nser,(setter)IEC61853SingleDiodeModel_set_sd11par_nser,
	PyDoc_STR("*float*: Nseries\n\n**Constraints:**\nINTEGER,POSITIVE\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_standoff", (getter)IEC61853SingleDiodeModel_get_sd11par_standoff,(setter)IEC61853SingleDiodeModel_set_sd11par_standoff,
	PyDoc_STR("*float*: Standoff mode\n\n**Options:**\n0=bipv,1=>3.5in,2=2.5-3.5in,3=1.5-2.5in,4=0.5-1.5in,5=<0.5in,6=ground/rack\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
{"sd11par_tnoct", (getter)IEC61853SingleDiodeModel_get_sd11par_tnoct,(setter)IEC61853SingleDiodeModel_set_sd11par_tnoct,
	PyDoc_STR("*float*: Nominal operating cell temperature [C]\n\n**Required:**\nRequired if module_model=4"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject IEC61853SingleDiodeModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.IEC61853SingleDiodeModel",             /*tp_name*/
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
		IEC61853SingleDiodeModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		IEC61853SingleDiodeModel_getset,          /*tp_getset*/
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
 * MermoudLejeuneSingleDiodeModel Group
 */ 

static PyTypeObject MermoudLejeuneSingleDiodeModel_Type;

static PyObject *
MermoudLejeuneSingleDiodeModel_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = MermoudLejeuneSingleDiodeModel_Type.tp_alloc(&MermoudLejeuneSingleDiodeModel_Type,0);

	VarGroupObject* MermoudLejeuneSingleDiodeModel_obj = (VarGroupObject*)new_obj;

	MermoudLejeuneSingleDiodeModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* MermoudLejeuneSingleDiodeModel methods */

static PyObject *
MermoudLejeuneSingleDiodeModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "MermoudLejeuneSingleDiodeModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MermoudLejeuneSingleDiodeModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &MermoudLejeuneSingleDiodeModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "MermoudLejeuneSingleDiodeModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MermoudLejeuneSingleDiodeModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &MermoudLejeuneSingleDiodeModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef MermoudLejeuneSingleDiodeModel_methods[] = {
		{"assign",            (PyCFunction)MermoudLejeuneSingleDiodeModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``MermoudLejeuneSingleDiodeModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)MermoudLejeuneSingleDiodeModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``MermoudLejeuneSingleDiodeModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)MermoudLejeuneSingleDiodeModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp0_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp0_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp1_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp1_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp2_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp2_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp3_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp3_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp4_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp4_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp5_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_lp5_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa0_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa0_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa1_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa1_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa2_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa2_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa3_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa3_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa4_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_c_sa4_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_AM_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_mode_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_AM_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_AM_mode_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_D2MuTau(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_D2MuTau_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_D2MuTau(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_D2MuTau_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_E_g(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_E_g_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_E_g(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_E_g_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_as(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_as_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_as(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_as_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_cs_iamValue(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_cs_iamValue_aget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_cs_iamValue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_cs_iamValue_aset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_cs_incAngle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_cs_incAngle_aget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_cs_incAngle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_cs_incAngle_aset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa0_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa0_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa1_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa1_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa2_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa2_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa3_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa3_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa4_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa4_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa5_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_c_sa5_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_IAM_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_mode_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_IAM_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_IAM_mode_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_I_mp_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_I_mp_ref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_I_mp_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_I_mp_ref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_I_sc_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_I_sc_ref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_I_sc_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_I_sc_ref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_Length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_Length_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_Length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_Length_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_N_diodes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_N_diodes_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_N_diodes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_N_diodes_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_N_parallel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_N_parallel_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_N_parallel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_N_parallel_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_N_series(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_N_series_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_N_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_N_series_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_R_s(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_s_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_R_s(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_s_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_R_sh0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_sh0_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_R_sh0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_sh0_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_R_shexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_shexp_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_R_shexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_shexp_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_R_shref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_shref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_R_shref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_R_shref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_S_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_S_ref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_S_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_S_ref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_c_fa_U0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_fa_U0_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_c_fa_U0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_fa_U0_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_c_fa_U1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_fa_U1_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_c_fa_U1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_fa_U1_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_c_fa_alpha(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_fa_alpha_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_c_fa_alpha(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_fa_alpha_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_c_no_mounting(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_no_mounting_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_c_no_mounting(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_no_mounting_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_c_no_standoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_no_standoff_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_c_no_standoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_no_standoff_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_c_no_tnoct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_no_tnoct_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_c_no_tnoct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_c_no_tnoct_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_mode_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_mode_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_T_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_ref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_T_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_T_ref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_V_mp_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_V_mp_ref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_V_mp_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_V_mp_ref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_V_oc_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_V_oc_ref_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_V_oc_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_V_oc_ref_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_Width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_Width_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_Width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_Width_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_alpha_isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_alpha_isc_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_alpha_isc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_alpha_isc_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_beta_voc_spec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_beta_voc_spec_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_beta_voc_spec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_beta_voc_spec_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_bifacial_ground_clearance_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_bifacial_ground_clearance_height_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_bifacial_ground_clearance_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_bifacial_ground_clearance_height_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_bifacial_transmission_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_bifacial_transmission_factor_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_bifacial_transmission_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_bifacial_transmission_factor_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_bifaciality(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_bifaciality_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_bifaciality(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_bifaciality_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_groundRelfectionFraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_groundRelfectionFraction_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_groundRelfectionFraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_groundRelfectionFraction_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_is_bifacial(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_is_bifacial_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_is_bifacial(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_is_bifacial_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_mu_n(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_mu_n_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_mu_n(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_mu_n_nset, self->data_ptr);
}

static PyObject *
MermoudLejeuneSingleDiodeModel_get_mlm_n_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_n_0_nget, self->data_ptr);
}

static int
MermoudLejeuneSingleDiodeModel_set_mlm_n_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_MermoudLejeuneSingleDiodeModel_mlm_n_0_nset, self->data_ptr);
}

static PyGetSetDef MermoudLejeuneSingleDiodeModel_getset[] = {
{"mlm_AM_c_lp0", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp0,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp0,
	PyDoc_STR("*float*: Coefficient 0 for Lee/Panchula Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_lp1", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp1,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp1,
	PyDoc_STR("*float*: Coefficient 1 for Lee/Panchula Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_lp2", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp2,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp2,
	PyDoc_STR("*float*: Coefficient 2 for Lee/Panchula Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_lp3", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp3,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp3,
	PyDoc_STR("*float*: Coefficient 3 for Lee/Panchula Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_lp4", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp4,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp4,
	PyDoc_STR("*float*: Coefficient 4 for Lee/Panchula Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_lp5", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_lp5,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_lp5,
	PyDoc_STR("*float*: Coefficient 5 for Lee/Panchula Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_sa0", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa0,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa0,
	PyDoc_STR("*float*: Coefficient 0 for Sandia Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_sa1", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa1,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa1,
	PyDoc_STR("*float*: Coefficient 1 for Sandia Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_sa2", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa2,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa2,
	PyDoc_STR("*float*: Coefficient 2 for Sandia Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_sa3", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa3,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa3,
	PyDoc_STR("*float*: Coefficient 3 for Sandia Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_c_sa4", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_c_sa4,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_c_sa4,
	PyDoc_STR("*float*: Coefficient 4 for Sandia Air Mass Modifier [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_AM_mode", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_AM_mode,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_AM_mode,
	PyDoc_STR("*float*: Air-mass modifier mode [-]\n\n**Options:**\n1: Do not consider AM effects, 2: Use Sandia polynomial [corr=f(AM)], 3: Use standard coefficients from DeSoto model [corr=f(AM)], 4: Use First Solar polynomial [corr=f(AM, p_wat)]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_D2MuTau", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_D2MuTau,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_D2MuTau,
	PyDoc_STR("*float*: Coefficient for recombination losses [V]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_E_g", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_E_g,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_E_g,
	PyDoc_STR("*float*: Reference bandgap energy [eV]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_as", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_as,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_as,
	PyDoc_STR("*float*: ASHRAE incidence modifier coefficient b_0 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_cs_iamValue", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_cs_iamValue,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_cs_iamValue,
	PyDoc_STR("*sequence*: Spline IAM - IAM values [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_cs_incAngle", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_cs_incAngle,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_cs_incAngle,
	PyDoc_STR("*sequence*: Spline IAM - Incidence angles [degrees]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_sa0", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa0,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa0,
	PyDoc_STR("*float*: Sandia IAM coefficient 0 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_sa1", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa1,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa1,
	PyDoc_STR("*float*: Sandia IAM coefficient 1 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_sa2", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa2,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa2,
	PyDoc_STR("*float*: Sandia IAM coefficient 2 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_sa3", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa3,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa3,
	PyDoc_STR("*float*: Sandia IAM coefficient 3 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_sa4", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa4,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa4,
	PyDoc_STR("*float*: Sandia IAM coefficient 4 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_c_sa5", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_c_sa5,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_c_sa5,
	PyDoc_STR("*float*: Sandia IAM coefficient 5 [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_IAM_mode", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_IAM_mode,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_IAM_mode,
	PyDoc_STR("*float*: Incidence Angle Modifier mode [-]\n\n**Info:**\n1: Use ASHRAE formula, 2: Use Sandia polynomial, 3: Use cubic spline with user-supplied data\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_I_mp_ref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_I_mp_ref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_I_mp_ref,
	PyDoc_STR("*float*: I_mp at STC [A]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_I_sc_ref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_I_sc_ref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_I_sc_ref,
	PyDoc_STR("*float*: I_sc at STC [A]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_Length", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_Length,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_Length,
	PyDoc_STR("*float*: Module length (long side) [m]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_N_diodes", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_N_diodes,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_N_diodes,
	PyDoc_STR("*float*: Number of diodes [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_N_parallel", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_N_parallel,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_N_parallel,
	PyDoc_STR("*float*: Number of cells in parallel [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_N_series", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_N_series,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_N_series,
	PyDoc_STR("*float*: Number of cells in series [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_R_s", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_R_s,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_R_s,
	PyDoc_STR("*float*: Series resistance [V/A]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_R_sh0", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_R_sh0,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_R_sh0,
	PyDoc_STR("*float*: Rsh,0 [V/A]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_R_shexp", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_R_shexp,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_R_shexp,
	PyDoc_STR("*float*: Rsh exponential coefficient [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_R_shref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_R_shref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_R_shref,
	PyDoc_STR("*float*: Reference shunt resistance [V/A]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_S_ref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_S_ref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_S_ref,
	PyDoc_STR("*float*: Reference irradiance (Typically 1000W/m²) [W/m²]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_c_fa_U0", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_c_fa_U0,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_c_fa_U0,
	PyDoc_STR("*float*: Extended Faiman model U_0 [W/m²K]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_c_fa_U1", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_c_fa_U1,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_c_fa_U1,
	PyDoc_STR("*float*: Extended Faiman model U_1 [W/m³sK]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_c_fa_alpha", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_c_fa_alpha,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_c_fa_alpha,
	PyDoc_STR("*float*: Extended Faiman model absorptivity [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_c_no_mounting", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_c_no_mounting,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_c_no_mounting,
	PyDoc_STR("*float*: NOCT Array mounting height [-]\n\n**Options:**\n0=one story,1=two story\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_c_no_standoff", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_c_no_standoff,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_c_no_standoff,
	PyDoc_STR("*float*: NOCT standoff mode [-]\n\n**Options:**\n0=bipv,1=>3.5in,2=2.5-3.5in,3=1.5-2.5in,4=0.5-1.5in,5=<0.5in,6=ground/rack\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_c_no_tnoct", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_c_no_tnoct,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_c_no_tnoct,
	PyDoc_STR("*float*: NOCT cell temperature [°C]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_mode", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_mode,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_mode,
	PyDoc_STR("*float*: Cell temperature model mode [-]\n\n**Info:**\n1: NOCT\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_T_ref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_T_ref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_T_ref,
	PyDoc_STR("*float*: Reference temperature (Typically 25°C) [°C]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_V_mp_ref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_V_mp_ref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_V_mp_ref,
	PyDoc_STR("*float*: V_mp at STC [V]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_V_oc_ref", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_V_oc_ref,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_V_oc_ref,
	PyDoc_STR("*float*: V_oc at STC [V]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_Width", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_Width,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_Width,
	PyDoc_STR("*float*: Module width (short side) [m]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_alpha_isc", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_alpha_isc,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_alpha_isc,
	PyDoc_STR("*float*: Temperature coefficient for I_sc [A/K]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_beta_voc_spec", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_beta_voc_spec,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_beta_voc_spec,
	PyDoc_STR("*float*: Temperature coefficient for V_oc [V/K]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_bifacial_ground_clearance_height", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_bifacial_ground_clearance_height,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_bifacial_ground_clearance_height,
	PyDoc_STR("*float*: Module ground clearance height [m]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_bifacial_transmission_factor", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_bifacial_transmission_factor,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_bifacial_transmission_factor,
	PyDoc_STR("*float*: Bifacial transmission factor [0-1]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_bifaciality", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_bifaciality,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_bifaciality,
	PyDoc_STR("*float*: Bifaciality factor [%]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_groundRelfectionFraction", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_groundRelfectionFraction,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_groundRelfectionFraction,
	PyDoc_STR("*float*: Ground reflection fraction [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_is_bifacial", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_is_bifacial,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_is_bifacial,
	PyDoc_STR("*float*: Modules are bifacial [0/1]\n\n**Options:**\n0=monofacial,1=bifacial\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_mu_n", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_mu_n,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_mu_n,
	PyDoc_STR("*float*: Temperature coefficient of gamma [1/K]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
{"mlm_n_0", (getter)MermoudLejeuneSingleDiodeModel_get_mlm_n_0,(setter)MermoudLejeuneSingleDiodeModel_set_mlm_n_0,
	PyDoc_STR("*float*: Gamma [-]\n\n**Required:**\nRequired if module_model=5"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject MermoudLejeuneSingleDiodeModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.MermoudLejeuneSingleDiodeModel",             /*tp_name*/
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
		MermoudLejeuneSingleDiodeModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		MermoudLejeuneSingleDiodeModel_getset,          /*tp_getset*/
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
 * Inverter Group
 */ 

static PyTypeObject Inverter_Type;

static PyObject *
Inverter_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Inverter_Type.tp_alloc(&Inverter_Type,0);

	VarGroupObject* Inverter_obj = (VarGroupObject*)new_obj;

	Inverter_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Inverter methods */

static PyObject *
Inverter_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Inverter")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Inverter_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Inverter_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Inverter")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Inverter_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Inverter_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Inverter_methods[] = {
		{"assign",            (PyCFunction)Inverter_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Inverter_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Inverter_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Inverter_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Inverter_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Inverter_get_inv_cec_cg_eff_cec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_cec_cg_eff_cec_nget, self->data_ptr);
}

static int
Inverter_set_inv_cec_cg_eff_cec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_cec_cg_eff_cec_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_cec_cg_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_cec_cg_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_cec_cg_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_cec_cg_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_ds_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_ds_eff_nget, self->data_ptr);
}

static int
Inverter_set_inv_ds_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_ds_eff_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_ds_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_ds_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_ds_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_ds_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_num_mppt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_num_mppt_nget, self->data_ptr);
}

static int
Inverter_set_inv_num_mppt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_num_mppt_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_pd_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_pd_eff_nget, self->data_ptr);
}

static int
Inverter_set_inv_pd_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_pd_eff_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_pd_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_pd_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_pd_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_pd_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_snl_eff_cec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_snl_eff_cec_nget, self->data_ptr);
}

static int
Inverter_set_inv_snl_eff_cec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_snl_eff_cec_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inv_snl_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inv_snl_paco_nget, self->data_ptr);
}

static int
Inverter_set_inv_snl_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inv_snl_paco_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inverter_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inverter_count_nget, self->data_ptr);
}

static int
Inverter_set_inverter_count(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inverter_count_nset, self->data_ptr);
}

static PyObject *
Inverter_get_inverter_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_inverter_model_nget, self->data_ptr);
}

static int
Inverter_set_inverter_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_inverter_model_nset, self->data_ptr);
}

static PyObject *
Inverter_get_mppt_hi_inverter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_mppt_hi_inverter_nget, self->data_ptr);
}

static int
Inverter_set_mppt_hi_inverter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_mppt_hi_inverter_nset, self->data_ptr);
}

static PyObject *
Inverter_get_mppt_low_inverter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Inverter_mppt_low_inverter_nget, self->data_ptr);
}

static int
Inverter_set_mppt_low_inverter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Inverter_mppt_low_inverter_nset, self->data_ptr);
}

static PyGetSetDef Inverter_getset[] = {
{"inv_cec_cg_eff_cec", (getter)Inverter_get_inv_cec_cg_eff_cec,(setter)Inverter_set_inv_cec_cg_eff_cec,
	PyDoc_STR("*float*: Inverter Coefficient Generator CEC Efficiency [%]\n\nThe value of ``inv_cec_cg_eff_cec`` depends on the following variables:\n\n\t - inv_cec_cg_c0\n\t - inv_cec_cg_c1\n\t - inv_cec_cg_c2\n\t - inv_cec_cg_c3\n\t - inv_cec_cg_paco\n\t - inv_cec_cg_pdco\n\t - inv_cec_cg_psco\n\t - inv_cec_cg_vdco\n"),
 	NULL},
{"inv_cec_cg_paco", (getter)Inverter_get_inv_cec_cg_paco,(setter)Inverter_set_inv_cec_cg_paco,
	PyDoc_STR("*float*: Inverter Coefficient Generator Max AC Power [Wac]\n\nThe value of the following variables depends on ``inv_cec_cg_paco``:\n\n\t - inv_cec_cg_eff_cec\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_ds_eff", (getter)Inverter_get_inv_ds_eff,(setter)Inverter_set_inv_ds_eff,
	PyDoc_STR("*float*: Inverter Datasheet Efficiency [%]"),
 	NULL},
{"inv_ds_paco", (getter)Inverter_get_inv_ds_paco,(setter)Inverter_set_inv_ds_paco,
	PyDoc_STR("*float*: Inverter Datasheet Maximum AC Power [Wac]\n\nThe value of the following variables depends on ``inv_ds_paco``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_num_mppt", (getter)Inverter_get_inv_num_mppt,(setter)Inverter_set_inv_num_mppt,
	PyDoc_STR("*float*: Number of MPPT inputs\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults.\n\nThe value of ``inv_num_mppt`` depends on the following variables:\n\n\t - inverter_model\n"),
 	NULL},
{"inv_pd_eff", (getter)Inverter_get_inv_pd_eff,(setter)Inverter_set_inv_pd_eff,
	PyDoc_STR("*float*: Inverter Partload Efficiency [%]\n\nThe value of the following variables depends on ``inv_pd_eff``:\n\n\t - inv_pd_pdco\n"),
 	NULL},
{"inv_pd_paco", (getter)Inverter_get_inv_pd_paco,(setter)Inverter_set_inv_pd_paco,
	PyDoc_STR("*float*: Inverter Partload Maximum AC Power [Wac]\n\nThe value of the following variables depends on ``inv_pd_paco``:\n\n\t - inv_pd_pdco\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_snl_eff_cec", (getter)Inverter_get_inv_snl_eff_cec,(setter)Inverter_set_inv_snl_eff_cec,
	PyDoc_STR("*float*: Inverter Sandia CEC Efficiency [%]\n\nThe value of ``inv_snl_eff_cec`` depends on the following variables:\n\n\t - inv_snl_c0\n\t - inv_snl_c1\n\t - inv_snl_c2\n\t - inv_snl_c3\n\t - inv_snl_paco\n\t - inv_snl_pdco\n\t - inv_snl_pso\n\t - inv_snl_vdco\n"),
 	NULL},
{"inv_snl_paco", (getter)Inverter_get_inv_snl_paco,(setter)Inverter_set_inv_snl_paco,
	PyDoc_STR("*float*: Inverter Sandia Maximum AC Power [Wac]\n\nThe value of the following variables depends on ``inv_snl_paco``:\n\n\t - inv_snl_eff_cec\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inverter_count", (getter)Inverter_get_inverter_count,(setter)Inverter_set_inverter_count,
	PyDoc_STR("*float*: Number of inverters\n\nThe value of ``inverter_count`` depends on the following variables:\n\n\t - 6par_imp\n\t - 6par_vmp\n\t - 6par_voc\n\t - cec_i_mp_ref\n\t - cec_v_mp_ref\n\t - cec_v_oc_ref\n\t - inv_cec_cg_paco\n\t - inv_ds_paco\n\t - inv_pd_paco\n\t - inv_snl_paco\n\t - inverter_model\n\t - module_model\n\t - mppt_hi_inverter\n\t - mppt_low_inverter\n\t - sd11par_Vmp0\n\t - sd11par_Voc0\n\t - snl_a\n\t - snl_a0\n\t - snl_a1\n\t - snl_a2\n\t - snl_a3\n\t - snl_a4\n\t - snl_aimp\n\t - snl_aisc\n\t - snl_area\n\t - snl_b\n\t - snl_b0\n\t - snl_b1\n\t - snl_b2\n\t - snl_b3\n\t - snl_b4\n\t - snl_b5\n\t - snl_bvmpo\n\t - snl_bvoco\n\t - snl_c0\n\t - snl_c1\n\t - snl_c2\n\t - snl_c3\n\t - snl_dtc\n\t - snl_fd\n\t - snl_impo\n\t - snl_isco\n\t - snl_mbvmp\n\t - snl_mbvoc\n\t - snl_module_structure\n\t - snl_n\n\t - snl_series_cells\n\t - snl_vmpo\n\t - snl_voco\n\t - spe_area\n\t - spe_eff0\n\t - spe_eff1\n\t - spe_eff2\n\t - spe_eff3\n\t - spe_eff4\n\t - spe_rad0\n\t - spe_rad1\n\t - spe_rad2\n\t - spe_rad3\n\t - spe_rad4\n\t - spe_reference\n\t - spe_vmp\n\t - spe_voc\n"),
 	NULL},
{"inverter_model", (getter)Inverter_get_inverter_model,(setter)Inverter_set_inverter_model,
	PyDoc_STR("*float*: Inverter model specifier\n\n**Options:**\n0=cec,1=datasheet,2=partload,3=coefficientgenerator,4=PVYield\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``inverter_model``:\n\n\t - inv_num_mppt\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"mppt_hi_inverter", (getter)Inverter_get_mppt_hi_inverter,(setter)Inverter_set_mppt_hi_inverter,
	PyDoc_STR("*float*: Maximum inverter MPPT voltage window [Vdc]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``mppt_hi_inverter``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"mppt_low_inverter", (getter)Inverter_get_mppt_low_inverter,(setter)Inverter_set_mppt_low_inverter,
	PyDoc_STR("*float*: Minimum inverter MPPT voltage window [Vdc]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``mppt_low_inverter``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Inverter_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Inverter",             /*tp_name*/
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
		Inverter_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Inverter_getset,          /*tp_getset*/
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
 * InverterCECDatabase Group
 */ 

static PyTypeObject InverterCECDatabase_Type;

static PyObject *
InverterCECDatabase_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = InverterCECDatabase_Type.tp_alloc(&InverterCECDatabase_Type,0);

	VarGroupObject* InverterCECDatabase_obj = (VarGroupObject*)new_obj;

	InverterCECDatabase_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* InverterCECDatabase methods */

static PyObject *
InverterCECDatabase_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "InverterCECDatabase")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterCECDatabase_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &InverterCECDatabase_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "InverterCECDatabase")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterCECDatabase_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &InverterCECDatabase_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef InverterCECDatabase_methods[] = {
		{"assign",            (PyCFunction)InverterCECDatabase_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``InverterCECDatabase_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)InverterCECDatabase_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``InverterCECDatabase_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)InverterCECDatabase_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
InverterCECDatabase_get_inv_snl_c0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_c0_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_c0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_c0_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_c1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_c1_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_c1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_c1_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_c2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_c2_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_c2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_c2_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_c3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_c3_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_c3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_c3_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_paco_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_paco_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_pdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_pdco_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_pdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_pdco_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_pnt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_pnt_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_pnt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_pnt_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_pso(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_pso_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_pso(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_pso_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_vdcmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_vdcmax_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_vdcmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_vdcmax_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_snl_vdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECDatabase_inv_snl_vdco_nget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_snl_vdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_snl_vdco_nset, self->data_ptr);
}

static PyObject *
InverterCECDatabase_get_inv_tdc_cec_db(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterCECDatabase_inv_tdc_cec_db_mget, self->data_ptr);
}

static int
InverterCECDatabase_set_inv_tdc_cec_db(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterCECDatabase_inv_tdc_cec_db_mset, self->data_ptr);
}

static PyGetSetDef InverterCECDatabase_getset[] = {
{"inv_snl_c0", (getter)InverterCECDatabase_get_inv_snl_c0,(setter)InverterCECDatabase_set_inv_snl_c0,
	PyDoc_STR("*float*: Curvature between AC power and DC power at ref [1/W]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_c0``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_snl_c1", (getter)InverterCECDatabase_get_inv_snl_c1,(setter)InverterCECDatabase_set_inv_snl_c1,
	PyDoc_STR("*float*: Coefficient of Pdco variation with DC input voltage [1/V]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_c1``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_snl_c2", (getter)InverterCECDatabase_get_inv_snl_c2,(setter)InverterCECDatabase_set_inv_snl_c2,
	PyDoc_STR("*float*: Coefficient of Pso variation with DC input voltage [1/V]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_c2``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_snl_c3", (getter)InverterCECDatabase_get_inv_snl_c3,(setter)InverterCECDatabase_set_inv_snl_c3,
	PyDoc_STR("*float*: Coefficient of Co variation with DC input voltage [1/V]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_c3``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_snl_paco", (getter)InverterCECDatabase_get_inv_snl_paco,(setter)InverterCECDatabase_set_inv_snl_paco,
	PyDoc_STR("*float*: AC maximum power rating [Wac]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_paco``:\n\n\t - inv_snl_eff_cec\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_snl_pdco", (getter)InverterCECDatabase_get_inv_snl_pdco,(setter)InverterCECDatabase_set_inv_snl_pdco,
	PyDoc_STR("*float*: DC input power at which AC power rating is achieved [Wdc]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_pdco``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_snl_pnt", (getter)InverterCECDatabase_get_inv_snl_pnt,(setter)InverterCECDatabase_set_inv_snl_pnt,
	PyDoc_STR("*float*: AC power consumed by inverter at night [Wac]\n\n**Required:**\nRequired if inverter_model=0"),
 	NULL},
{"inv_snl_pso", (getter)InverterCECDatabase_get_inv_snl_pso,(setter)InverterCECDatabase_set_inv_snl_pso,
	PyDoc_STR("*float*: DC power required to enable the inversion process [Wdc]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_pso``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_snl_vdcmax", (getter)InverterCECDatabase_get_inv_snl_vdcmax,(setter)InverterCECDatabase_set_inv_snl_vdcmax,
	PyDoc_STR("*float*: Maximum DC input operating voltage [Vdc]\n\n**Required:**\nRequired if inverter_model=0"),
 	NULL},
{"inv_snl_vdco", (getter)InverterCECDatabase_get_inv_snl_vdco,(setter)InverterCECDatabase_set_inv_snl_vdco,
	PyDoc_STR("*float*: DC input voltage for the rated AC power rating [Vdc]\n\n**Required:**\nRequired if inverter_model=0\n\nThe value of the following variables depends on ``inv_snl_vdco``:\n\n\t - inv_snl_eff_cec\n"),
 	NULL},
{"inv_tdc_cec_db", (getter)InverterCECDatabase_get_inv_tdc_cec_db,(setter)InverterCECDatabase_set_inv_tdc_cec_db,
	PyDoc_STR("*sequence[sequence]*: Temperature derate curves for CEC Database [(Vdc, C, %/C)]\n\n**Required:**\nRequired if inverter_model=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject InverterCECDatabase_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.InverterCECDatabase",             /*tp_name*/
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
		InverterCECDatabase_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		InverterCECDatabase_getset,          /*tp_getset*/
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
 * InverterCECCoefficientGenerator Group
 */ 

static PyTypeObject InverterCECCoefficientGenerator_Type;

static PyObject *
InverterCECCoefficientGenerator_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = InverterCECCoefficientGenerator_Type.tp_alloc(&InverterCECCoefficientGenerator_Type,0);

	VarGroupObject* InverterCECCoefficientGenerator_obj = (VarGroupObject*)new_obj;

	InverterCECCoefficientGenerator_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* InverterCECCoefficientGenerator methods */

static PyObject *
InverterCECCoefficientGenerator_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "InverterCECCoefficientGenerator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterCECCoefficientGenerator_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &InverterCECCoefficientGenerator_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "InverterCECCoefficientGenerator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterCECCoefficientGenerator_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &InverterCECCoefficientGenerator_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef InverterCECCoefficientGenerator_methods[] = {
		{"assign",            (PyCFunction)InverterCECCoefficientGenerator_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``InverterCECCoefficientGenerator_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)InverterCECCoefficientGenerator_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``InverterCECCoefficientGenerator_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)InverterCECCoefficientGenerator_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_c0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c0_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_c0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c0_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_c1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c1_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_c1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c1_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_c2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c2_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_c2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c2_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_c3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c3_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_c3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_c3_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_paco_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_paco_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_pdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_pdco_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_pdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_pdco_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_pnt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_pnt_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_pnt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_pnt_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_psco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_psco_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_psco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_psco_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_vdcmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_vdcmax_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_vdcmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_vdcmax_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_cec_cg_vdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_vdco_nget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_cec_cg_vdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_cec_cg_vdco_nset, self->data_ptr);
}

static PyObject *
InverterCECCoefficientGenerator_get_inv_tdc_cec_cg(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_tdc_cec_cg_mget, self->data_ptr);
}

static int
InverterCECCoefficientGenerator_set_inv_tdc_cec_cg(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterCECCoefficientGenerator_inv_tdc_cec_cg_mset, self->data_ptr);
}

static PyGetSetDef InverterCECCoefficientGenerator_getset[] = {
{"inv_cec_cg_c0", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_c0,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_c0,
	PyDoc_STR("*float*: Curvature between AC power and DC power at ref [1/W]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_c0``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_cec_cg_c1", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_c1,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_c1,
	PyDoc_STR("*float*: Coefficient of Pdco variation with DC input voltage [1/V]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_c1``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_cec_cg_c2", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_c2,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_c2,
	PyDoc_STR("*float*: Coefficient of Pso variation with DC input voltage [1/V]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_c2``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_cec_cg_c3", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_c3,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_c3,
	PyDoc_STR("*float*: Coefficient of Co variation with DC input voltage [1/V]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_c3``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_cec_cg_paco", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_paco,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_paco,
	PyDoc_STR("*float*: AC maximum power rating [Wac]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_paco``:\n\n\t - inv_cec_cg_eff_cec\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_cec_cg_pdco", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_pdco,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_pdco,
	PyDoc_STR("*float*: DC input power at which AC power rating is achieved [Wdc]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_pdco``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_cec_cg_pnt", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_pnt,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_pnt,
	PyDoc_STR("*float*: AC power consumed by inverter at night [Wac]\n\n**Required:**\nRequired if inverter_model=3"),
 	NULL},
{"inv_cec_cg_psco", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_psco,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_psco,
	PyDoc_STR("*float*: DC power required to enable the inversion process [Wdc]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_psco``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_cec_cg_vdcmax", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_vdcmax,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_vdcmax,
	PyDoc_STR("*float*: Maximum DC input operating voltage [Vdc]\n\n**Required:**\nRequired if inverter_model=3"),
 	NULL},
{"inv_cec_cg_vdco", (getter)InverterCECCoefficientGenerator_get_inv_cec_cg_vdco,(setter)InverterCECCoefficientGenerator_set_inv_cec_cg_vdco,
	PyDoc_STR("*float*: DC input voltage for the rated AC power rating [Vdc]\n\n**Required:**\nRequired if inverter_model=3\n\nThe value of the following variables depends on ``inv_cec_cg_vdco``:\n\n\t - inv_cec_cg_eff_cec\n"),
 	NULL},
{"inv_tdc_cec_cg", (getter)InverterCECCoefficientGenerator_get_inv_tdc_cec_cg,(setter)InverterCECCoefficientGenerator_set_inv_tdc_cec_cg,
	PyDoc_STR("*sequence[sequence]*: Temperature derate curves for CEC Coef Gen [(Vdc, C, %/C)]\n\n**Required:**\nRequired if inverter_model=3"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject InverterCECCoefficientGenerator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.InverterCECCoefficientGenerator",             /*tp_name*/
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
		InverterCECCoefficientGenerator_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		InverterCECCoefficientGenerator_getset,          /*tp_getset*/
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
 * InverterDatasheet Group
 */ 

static PyTypeObject InverterDatasheet_Type;

static PyObject *
InverterDatasheet_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = InverterDatasheet_Type.tp_alloc(&InverterDatasheet_Type,0);

	VarGroupObject* InverterDatasheet_obj = (VarGroupObject*)new_obj;

	InverterDatasheet_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* InverterDatasheet methods */

static PyObject *
InverterDatasheet_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "InverterDatasheet")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterDatasheet_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &InverterDatasheet_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "InverterDatasheet")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterDatasheet_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &InverterDatasheet_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef InverterDatasheet_methods[] = {
		{"assign",            (PyCFunction)InverterDatasheet_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``InverterDatasheet_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)InverterDatasheet_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``InverterDatasheet_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)InverterDatasheet_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
InverterDatasheet_get_inv_ds_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterDatasheet_inv_ds_eff_nget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_ds_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_ds_eff_nset, self->data_ptr);
}

static PyObject *
InverterDatasheet_get_inv_ds_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterDatasheet_inv_ds_paco_nget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_ds_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_ds_paco_nset, self->data_ptr);
}

static PyObject *
InverterDatasheet_get_inv_ds_pnt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterDatasheet_inv_ds_pnt_nget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_ds_pnt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_ds_pnt_nset, self->data_ptr);
}

static PyObject *
InverterDatasheet_get_inv_ds_pso(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterDatasheet_inv_ds_pso_nget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_ds_pso(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_ds_pso_nset, self->data_ptr);
}

static PyObject *
InverterDatasheet_get_inv_ds_vdcmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterDatasheet_inv_ds_vdcmax_nget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_ds_vdcmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_ds_vdcmax_nset, self->data_ptr);
}

static PyObject *
InverterDatasheet_get_inv_ds_vdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterDatasheet_inv_ds_vdco_nget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_ds_vdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_ds_vdco_nset, self->data_ptr);
}

static PyObject *
InverterDatasheet_get_inv_tdc_ds(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterDatasheet_inv_tdc_ds_mget, self->data_ptr);
}

static int
InverterDatasheet_set_inv_tdc_ds(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterDatasheet_inv_tdc_ds_mset, self->data_ptr);
}

static PyGetSetDef InverterDatasheet_getset[] = {
{"inv_ds_eff", (getter)InverterDatasheet_get_inv_ds_eff,(setter)InverterDatasheet_set_inv_ds_eff,
	PyDoc_STR("*float*: Weighted or Peak or Nominal Efficiency [Wdc]\n\n**Required:**\nRequired if inverter_model=1"),
 	NULL},
{"inv_ds_paco", (getter)InverterDatasheet_get_inv_ds_paco,(setter)InverterDatasheet_set_inv_ds_paco,
	PyDoc_STR("*float*: AC maximum power rating [Wac]\n\n**Required:**\nRequired if inverter_model=1\n\nThe value of the following variables depends on ``inv_ds_paco``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_ds_pnt", (getter)InverterDatasheet_get_inv_ds_pnt,(setter)InverterDatasheet_set_inv_ds_pnt,
	PyDoc_STR("*float*: AC power consumed by inverter at night [Wac]\n\n**Required:**\nRequired if inverter_model=1"),
 	NULL},
{"inv_ds_pso", (getter)InverterDatasheet_get_inv_ds_pso,(setter)InverterDatasheet_set_inv_ds_pso,
	PyDoc_STR("*float*: DC power required to enable the inversion process [Wdc]\n\n**Required:**\nRequired if inverter_model=1"),
 	NULL},
{"inv_ds_vdcmax", (getter)InverterDatasheet_get_inv_ds_vdcmax,(setter)InverterDatasheet_set_inv_ds_vdcmax,
	PyDoc_STR("*float*: Maximum DC input operating voltage [Vdc]\n\n**Required:**\nRequired if inverter_model=1"),
 	NULL},
{"inv_ds_vdco", (getter)InverterDatasheet_get_inv_ds_vdco,(setter)InverterDatasheet_set_inv_ds_vdco,
	PyDoc_STR("*float*: DC input voltage for the rated AC power rating [Vdc]\n\n**Required:**\nRequired if inverter_model=1"),
 	NULL},
{"inv_tdc_ds", (getter)InverterDatasheet_get_inv_tdc_ds,(setter)InverterDatasheet_set_inv_tdc_ds,
	PyDoc_STR("*sequence[sequence]*: Temperature derate curves for Inv Datasheet [(Vdc, C, %/C)]\n\n**Required:**\nRequired if inverter_model=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject InverterDatasheet_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.InverterDatasheet",             /*tp_name*/
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
		InverterDatasheet_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		InverterDatasheet_getset,          /*tp_getset*/
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
 * InverterPartLoadCurve Group
 */ 

static PyTypeObject InverterPartLoadCurve_Type;

static PyObject *
InverterPartLoadCurve_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = InverterPartLoadCurve_Type.tp_alloc(&InverterPartLoadCurve_Type,0);

	VarGroupObject* InverterPartLoadCurve_obj = (VarGroupObject*)new_obj;

	InverterPartLoadCurve_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* InverterPartLoadCurve methods */

static PyObject *
InverterPartLoadCurve_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "InverterPartLoadCurve")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterPartLoadCurve_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &InverterPartLoadCurve_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "InverterPartLoadCurve")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterPartLoadCurve_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &InverterPartLoadCurve_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef InverterPartLoadCurve_methods[] = {
		{"assign",            (PyCFunction)InverterPartLoadCurve_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``InverterPartLoadCurve_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)InverterPartLoadCurve_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``InverterPartLoadCurve_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)InverterPartLoadCurve_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
InverterPartLoadCurve_get_inv_pd_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_efficiency_aget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_efficiency_aset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_pd_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_paco_nget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_paco_nset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_pd_partload(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_partload_aget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_partload(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_partload_aset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_pd_pdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_pdco_nget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_pdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_pdco_nset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_pd_pnt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_pnt_nget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_pnt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_pnt_nset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_pd_vdcmax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_vdcmax_nget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_vdcmax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_vdcmax_nset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_pd_vdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_vdco_nget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_pd_vdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_pd_vdco_nset, self->data_ptr);
}

static PyObject *
InverterPartLoadCurve_get_inv_tdc_plc(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterPartLoadCurve_inv_tdc_plc_mget, self->data_ptr);
}

static int
InverterPartLoadCurve_set_inv_tdc_plc(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterPartLoadCurve_inv_tdc_plc_mset, self->data_ptr);
}

static PyGetSetDef InverterPartLoadCurve_getset[] = {
{"inv_pd_efficiency", (getter)InverterPartLoadCurve_get_inv_pd_efficiency,(setter)InverterPartLoadCurve_set_inv_pd_efficiency,
	PyDoc_STR("*sequence*: Partload curve efficiency values [%]\n\n**Required:**\nRequired if inverter_model=2"),
 	NULL},
{"inv_pd_paco", (getter)InverterPartLoadCurve_get_inv_pd_paco,(setter)InverterPartLoadCurve_set_inv_pd_paco,
	PyDoc_STR("*float*: AC maximum power rating [Wac]\n\n**Required:**\nRequired if inverter_model=2\n\nThe value of the following variables depends on ``inv_pd_paco``:\n\n\t - inv_pd_pdco\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"inv_pd_partload", (getter)InverterPartLoadCurve_get_inv_pd_partload,(setter)InverterPartLoadCurve_set_inv_pd_partload,
	PyDoc_STR("*sequence*: Partload curve partload values [%]\n\n**Required:**\nRequired if inverter_model=2"),
 	NULL},
{"inv_pd_pdco", (getter)InverterPartLoadCurve_get_inv_pd_pdco,(setter)InverterPartLoadCurve_set_inv_pd_pdco,
	PyDoc_STR("*float*: DC input power at which AC power rating is achieved [Wdc]\n\n**Required:**\nRequired if inverter_model=2\n\nThe value of ``inv_pd_pdco`` depends on the following variables:\n\n\t - inv_pd_eff\n\t - inv_pd_paco\n"),
 	NULL},
{"inv_pd_pnt", (getter)InverterPartLoadCurve_get_inv_pd_pnt,(setter)InverterPartLoadCurve_set_inv_pd_pnt,
	PyDoc_STR("*float*: AC power consumed by inverter at night [Wac]\n\n**Required:**\nRequired if inverter_model=2"),
 	NULL},
{"inv_pd_vdcmax", (getter)InverterPartLoadCurve_get_inv_pd_vdcmax,(setter)InverterPartLoadCurve_set_inv_pd_vdcmax,
	PyDoc_STR("*float*: Maximum DC input operating voltage [Vdc]\n\n**Required:**\nRequired if inverter_model=2"),
 	NULL},
{"inv_pd_vdco", (getter)InverterPartLoadCurve_get_inv_pd_vdco,(setter)InverterPartLoadCurve_set_inv_pd_vdco,
	PyDoc_STR("*float*: DC input voltage for the rated AC power rating [Vdc]\n\n**Required:**\nRequired if inverter_model=2"),
 	NULL},
{"inv_tdc_plc", (getter)InverterPartLoadCurve_get_inv_tdc_plc,(setter)InverterPartLoadCurve_set_inv_tdc_plc,
	PyDoc_STR("*sequence[sequence]*: Temperature derate curves for Part Load Curve [(Vdc, C, %/C)]\n\n**Required:**\nRequired if inverter_model=2"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject InverterPartLoadCurve_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.InverterPartLoadCurve",             /*tp_name*/
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
		InverterPartLoadCurve_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		InverterPartLoadCurve_getset,          /*tp_getset*/
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
 * InverterMermoudLejeuneModel Group
 */ 

static PyTypeObject InverterMermoudLejeuneModel_Type;

static PyObject *
InverterMermoudLejeuneModel_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = InverterMermoudLejeuneModel_Type.tp_alloc(&InverterMermoudLejeuneModel_Type,0);

	VarGroupObject* InverterMermoudLejeuneModel_obj = (VarGroupObject*)new_obj;

	InverterMermoudLejeuneModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* InverterMermoudLejeuneModel methods */

static PyObject *
InverterMermoudLejeuneModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "InverterMermoudLejeuneModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterMermoudLejeuneModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &InverterMermoudLejeuneModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "InverterMermoudLejeuneModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
InverterMermoudLejeuneModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &InverterMermoudLejeuneModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef InverterMermoudLejeuneModel_methods[] = {
		{"assign",            (PyCFunction)InverterMermoudLejeuneModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``InverterMermoudLejeuneModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)InverterMermoudLejeuneModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``InverterMermoudLejeuneModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)InverterMermoudLejeuneModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
InverterMermoudLejeuneModel_get_ond_Aux_Loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_Aux_Loss_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_Aux_Loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_Aux_Loss_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_CompPMax(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_CompPMax_sget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_CompPMax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_CompPMax_sset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_CompVMax(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_CompVMax_sget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_CompVMax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_CompVMax_sset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_IMaxAC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_IMaxAC_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_IMaxAC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_IMaxAC_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_IMaxDC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_IMaxDC_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_IMaxDC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_IMaxDC_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_INomAC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_INomAC_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_INomAC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_INomAC_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_INomDC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_INomDC_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_INomDC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_INomDC_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_ModeAffEnum(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_ModeAffEnum_sget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_ModeAffEnum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_ModeAffEnum_sset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_ModeOper(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_ModeOper_sget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_ModeOper(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_ModeOper_sset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_NbInputs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_NbInputs_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_NbInputs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_NbInputs_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_NbMPPT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_NbMPPT_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_NbMPPT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_NbMPPT_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_Night_Loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_Night_Loss_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_Night_Loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_Night_Loss_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PLim1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PLim1_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PLim1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PLim1_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PLimAbs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PLimAbs_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PLimAbs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PLimAbs_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PMaxDC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PMaxDC_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PMaxDC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PMaxDC_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PMaxOUT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PMaxOUT_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PMaxOUT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PMaxOUT_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PNomConv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PNomConv_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PNomConv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PNomConv_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PNomDC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PNomDC_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PNomDC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PNomDC_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_PSeuil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PSeuil_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_PSeuil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_PSeuil_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_TPLim1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPLim1_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_TPLim1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPLim1_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_TPLimAbs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPLimAbs_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_TPLimAbs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPLimAbs_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_TPMax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPMax_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_TPMax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPMax_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_TPNom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPNom_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_TPNom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_TPNom_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_VAbsMax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VAbsMax_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_VAbsMax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VAbsMax_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_VMPPMax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VMPPMax_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_VMPPMax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VMPPMax_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_VMppMin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VMppMin_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_VMppMin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VMppMin_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_VNomEff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VNomEff_aget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_VNomEff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VNomEff_aset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_VOutConv(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VOutConv_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_VOutConv(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_VOutConv_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_doAllowOverpower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_doAllowOverpower_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_doAllowOverpower(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_doAllowOverpower_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_doUseTemperatureLimit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_doUseTemperatureLimit_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_doUseTemperatureLimit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_doUseTemperatureLimit_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_effCurve_Pac(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_Pac_mget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_effCurve_Pac(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_Pac_mset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_effCurve_Pdc(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_Pdc_mget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_effCurve_Pdc(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_Pdc_mset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_effCurve_elements(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_elements_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_effCurve_elements(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_elements_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_effCurve_eta(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_eta_mget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_effCurve_eta(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_effCurve_eta_mset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_lossRAc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_lossRAc_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_lossRAc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_lossRAc_nset, self->data_ptr);
}

static PyObject *
InverterMermoudLejeuneModel_get_ond_lossRDc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_lossRDc_nget, self->data_ptr);
}

static int
InverterMermoudLejeuneModel_set_ond_lossRDc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_InverterMermoudLejeuneModel_ond_lossRDc_nset, self->data_ptr);
}

static PyGetSetDef InverterMermoudLejeuneModel_getset[] = {
{"ond_Aux_Loss", (getter)InverterMermoudLejeuneModel_get_ond_Aux_Loss,(setter)InverterMermoudLejeuneModel_set_ond_Aux_Loss,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_CompPMax", (getter)InverterMermoudLejeuneModel_get_ond_CompPMax,(setter)InverterMermoudLejeuneModel_set_ond_CompPMax,
	PyDoc_STR("*str*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_CompVMax", (getter)InverterMermoudLejeuneModel_get_ond_CompVMax,(setter)InverterMermoudLejeuneModel_set_ond_CompVMax,
	PyDoc_STR("*str*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_IMaxAC", (getter)InverterMermoudLejeuneModel_get_ond_IMaxAC,(setter)InverterMermoudLejeuneModel_set_ond_IMaxAC,
	PyDoc_STR("*float*:  [A]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_IMaxDC", (getter)InverterMermoudLejeuneModel_get_ond_IMaxDC,(setter)InverterMermoudLejeuneModel_set_ond_IMaxDC,
	PyDoc_STR("*float*:  [A]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_INomAC", (getter)InverterMermoudLejeuneModel_get_ond_INomAC,(setter)InverterMermoudLejeuneModel_set_ond_INomAC,
	PyDoc_STR("*float*:  [A]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_INomDC", (getter)InverterMermoudLejeuneModel_get_ond_INomDC,(setter)InverterMermoudLejeuneModel_set_ond_INomDC,
	PyDoc_STR("*float*:  [A]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_ModeAffEnum", (getter)InverterMermoudLejeuneModel_get_ond_ModeAffEnum,(setter)InverterMermoudLejeuneModel_set_ond_ModeAffEnum,
	PyDoc_STR("*str*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_ModeOper", (getter)InverterMermoudLejeuneModel_get_ond_ModeOper,(setter)InverterMermoudLejeuneModel_set_ond_ModeOper,
	PyDoc_STR("*str*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_NbInputs", (getter)InverterMermoudLejeuneModel_get_ond_NbInputs,(setter)InverterMermoudLejeuneModel_set_ond_NbInputs,
	PyDoc_STR("*float*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_NbMPPT", (getter)InverterMermoudLejeuneModel_get_ond_NbMPPT,(setter)InverterMermoudLejeuneModel_set_ond_NbMPPT,
	PyDoc_STR("*float*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_Night_Loss", (getter)InverterMermoudLejeuneModel_get_ond_Night_Loss,(setter)InverterMermoudLejeuneModel_set_ond_Night_Loss,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PLim1", (getter)InverterMermoudLejeuneModel_get_ond_PLim1,(setter)InverterMermoudLejeuneModel_set_ond_PLim1,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PLimAbs", (getter)InverterMermoudLejeuneModel_get_ond_PLimAbs,(setter)InverterMermoudLejeuneModel_set_ond_PLimAbs,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PMaxDC", (getter)InverterMermoudLejeuneModel_get_ond_PMaxDC,(setter)InverterMermoudLejeuneModel_set_ond_PMaxDC,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PMaxOUT", (getter)InverterMermoudLejeuneModel_get_ond_PMaxOUT,(setter)InverterMermoudLejeuneModel_set_ond_PMaxOUT,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PNomConv", (getter)InverterMermoudLejeuneModel_get_ond_PNomConv,(setter)InverterMermoudLejeuneModel_set_ond_PNomConv,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PNomDC", (getter)InverterMermoudLejeuneModel_get_ond_PNomDC,(setter)InverterMermoudLejeuneModel_set_ond_PNomDC,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_PSeuil", (getter)InverterMermoudLejeuneModel_get_ond_PSeuil,(setter)InverterMermoudLejeuneModel_set_ond_PSeuil,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_TPLim1", (getter)InverterMermoudLejeuneModel_get_ond_TPLim1,(setter)InverterMermoudLejeuneModel_set_ond_TPLim1,
	PyDoc_STR("*float*:  [°C]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_TPLimAbs", (getter)InverterMermoudLejeuneModel_get_ond_TPLimAbs,(setter)InverterMermoudLejeuneModel_set_ond_TPLimAbs,
	PyDoc_STR("*float*:  [°C]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_TPMax", (getter)InverterMermoudLejeuneModel_get_ond_TPMax,(setter)InverterMermoudLejeuneModel_set_ond_TPMax,
	PyDoc_STR("*float*:  [°C]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_TPNom", (getter)InverterMermoudLejeuneModel_get_ond_TPNom,(setter)InverterMermoudLejeuneModel_set_ond_TPNom,
	PyDoc_STR("*float*:  [°C]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_VAbsMax", (getter)InverterMermoudLejeuneModel_get_ond_VAbsMax,(setter)InverterMermoudLejeuneModel_set_ond_VAbsMax,
	PyDoc_STR("*float*:  [V]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_VMPPMax", (getter)InverterMermoudLejeuneModel_get_ond_VMPPMax,(setter)InverterMermoudLejeuneModel_set_ond_VMPPMax,
	PyDoc_STR("*float*:  [V]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_VMppMin", (getter)InverterMermoudLejeuneModel_get_ond_VMppMin,(setter)InverterMermoudLejeuneModel_set_ond_VMppMin,
	PyDoc_STR("*float*:  [V]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_VNomEff", (getter)InverterMermoudLejeuneModel_get_ond_VNomEff,(setter)InverterMermoudLejeuneModel_set_ond_VNomEff,
	PyDoc_STR("*sequence*:  [V]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_VOutConv", (getter)InverterMermoudLejeuneModel_get_ond_VOutConv,(setter)InverterMermoudLejeuneModel_set_ond_VOutConv,
	PyDoc_STR("*float*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_doAllowOverpower", (getter)InverterMermoudLejeuneModel_get_ond_doAllowOverpower,(setter)InverterMermoudLejeuneModel_set_ond_doAllowOverpower,
	PyDoc_STR("*float*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_doUseTemperatureLimit", (getter)InverterMermoudLejeuneModel_get_ond_doUseTemperatureLimit,(setter)InverterMermoudLejeuneModel_set_ond_doUseTemperatureLimit,
	PyDoc_STR("*float*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_effCurve_Pac", (getter)InverterMermoudLejeuneModel_get_ond_effCurve_Pac,(setter)InverterMermoudLejeuneModel_set_ond_effCurve_Pac,
	PyDoc_STR("*sequence[sequence]*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_effCurve_Pdc", (getter)InverterMermoudLejeuneModel_get_ond_effCurve_Pdc,(setter)InverterMermoudLejeuneModel_set_ond_effCurve_Pdc,
	PyDoc_STR("*sequence[sequence]*:  [W]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_effCurve_elements", (getter)InverterMermoudLejeuneModel_get_ond_effCurve_elements,(setter)InverterMermoudLejeuneModel_set_ond_effCurve_elements,
	PyDoc_STR("*float*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_effCurve_eta", (getter)InverterMermoudLejeuneModel_get_ond_effCurve_eta,(setter)InverterMermoudLejeuneModel_set_ond_effCurve_eta,
	PyDoc_STR("*sequence[sequence]*:  [-]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_lossRAc", (getter)InverterMermoudLejeuneModel_get_ond_lossRAc,(setter)InverterMermoudLejeuneModel_set_ond_lossRAc,
	PyDoc_STR("*float*:  [A]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
{"ond_lossRDc", (getter)InverterMermoudLejeuneModel_get_ond_lossRDc,(setter)InverterMermoudLejeuneModel_set_ond_lossRDc,
	PyDoc_STR("*float*:  [V/A]\n\n**Required:**\nRequired if inverter_model=4"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject InverterMermoudLejeuneModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.InverterMermoudLejeuneModel",             /*tp_name*/
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
		InverterMermoudLejeuneModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		InverterMermoudLejeuneModel_getset,          /*tp_getset*/
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
 * BatterySystem Group
 */ 

static PyTypeObject BatterySystem_Type;

static PyObject *
BatterySystem_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = BatterySystem_Type.tp_alloc(&BatterySystem_Type,0);

	VarGroupObject* BatterySystem_obj = (VarGroupObject*)new_obj;

	BatterySystem_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* BatterySystem methods */

static PyObject *
BatterySystem_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "BatterySystem")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatterySystem_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &BatterySystem_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "BatterySystem")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatterySystem_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatterySystem_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatterySystem_methods[] = {
		{"assign",            (PyCFunction)BatterySystem_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``BatterySystem_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)BatterySystem_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``BatterySystem_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatterySystem_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatterySystem_get_batt_ac_dc_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_ac_dc_efficiency_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_ac_dc_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_ac_dc_efficiency_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_ac_or_dc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_ac_or_dc_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_ac_or_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_ac_or_dc_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_bank_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_computed_bank_capacity_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_bank_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_computed_bank_capacity_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_series(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_computed_series_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_series(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_computed_series_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_computed_strings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_computed_strings_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_computed_strings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_computed_strings_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_current_charge_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_current_charge_max_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_current_charge_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_current_charge_max_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_current_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_current_choice_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_current_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_current_choice_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_current_discharge_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_current_discharge_max_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_current_discharge_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_current_discharge_max_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_dc_ac_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_dc_ac_efficiency_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_dc_ac_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_dc_ac_efficiency_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_dc_dc_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_dc_dc_efficiency_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_dc_dc_efficiency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_dc_dc_efficiency_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_inverter_efficiency_cutoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_inverter_efficiency_cutoff_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_inverter_efficiency_cutoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_inverter_efficiency_cutoff_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_loss_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_loss_choice_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_loss_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_loss_choice_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatterySystem_batt_losses_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatterySystem_batt_losses_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses_charging(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatterySystem_batt_losses_charging_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses_charging(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatterySystem_batt_losses_charging_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses_discharging(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatterySystem_batt_losses_discharging_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses_discharging(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatterySystem_batt_losses_discharging_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_losses_idle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatterySystem_batt_losses_idle_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_losses_idle(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatterySystem_batt_losses_idle_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_mass_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_mass_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_meter_position(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_meter_position_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_meter_position(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_meter_position_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_charge_max_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_power_charge_max_kwac_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_charge_max_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_power_charge_max_kwac_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_charge_max_kwdc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_power_charge_max_kwdc_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_charge_max_kwdc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_power_charge_max_kwdc_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_discharge_max_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_power_discharge_max_kwac_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_discharge_max_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_power_discharge_max_kwac_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_power_discharge_max_kwdc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_power_discharge_max_kwdc_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_power_discharge_max_kwdc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_power_discharge_max_kwdc_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_replacement_capacity_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_replacement_capacity_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_replacement_option_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_replacement_option_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_replacement_schedule_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatterySystem_batt_replacement_schedule_percent_aget, self->data_ptr);
}

static int
BatterySystem_set_batt_replacement_schedule_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatterySystem_batt_replacement_schedule_percent_aset, self->data_ptr);
}

static PyObject *
BatterySystem_get_batt_surface_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_batt_surface_area_nget, self->data_ptr);
}

static int
BatterySystem_set_batt_surface_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_batt_surface_area_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_en_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_en_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_en_standalone_batt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatterySystem_en_standalone_batt_nget, self->data_ptr);
}

static int
BatterySystem_set_en_standalone_batt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatterySystem_en_standalone_batt_nset, self->data_ptr);
}

static PyObject *
BatterySystem_get_om_replacement_cost1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatterySystem_om_replacement_cost1_aget, self->data_ptr);
}

static int
BatterySystem_set_om_replacement_cost1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatterySystem_om_replacement_cost1_aset, self->data_ptr);
}

static PyGetSetDef BatterySystem_getset[] = {
{"batt_ac_dc_efficiency", (getter)BatterySystem_get_batt_ac_dc_efficiency,(setter)BatterySystem_set_batt_ac_dc_efficiency,
	PyDoc_STR("*float*: Inverter AC to battery DC efficiency"),
 	NULL},
{"batt_ac_or_dc", (getter)BatterySystem_get_batt_ac_or_dc,(setter)BatterySystem_set_batt_ac_or_dc,
	PyDoc_STR("*float*: Battery interconnection (AC or DC)\n\n**Options:**\n0=DC_Connected,1=AC_Connected\n\nThe value of the following variables depends on ``batt_ac_or_dc``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"batt_computed_bank_capacity", (getter)BatterySystem_get_batt_computed_bank_capacity,(setter)BatterySystem_set_batt_computed_bank_capacity,
	PyDoc_STR("*float*: Battery computed bank capacity [kWh]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_computed_series", (getter)BatterySystem_get_batt_computed_series,(setter)BatterySystem_set_batt_computed_series,
	PyDoc_STR("*float*: Battery number of cells in series\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_computed_strings", (getter)BatterySystem_get_batt_computed_strings,(setter)BatterySystem_set_batt_computed_strings,
	PyDoc_STR("*float*: Battery number of strings of cells\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_current_charge_max", (getter)BatterySystem_get_batt_current_charge_max,(setter)BatterySystem_set_batt_current_charge_max,
	PyDoc_STR("*float*: Battery maximum charge current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_current_choice", (getter)BatterySystem_get_batt_current_choice,(setter)BatterySystem_set_batt_current_choice,
	PyDoc_STR("*float*: Limit cells by current or power"),
 	NULL},
{"batt_current_discharge_max", (getter)BatterySystem_get_batt_current_discharge_max,(setter)BatterySystem_set_batt_current_discharge_max,
	PyDoc_STR("*float*: Battery maximum discharge current [A]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_dc_ac_efficiency", (getter)BatterySystem_get_batt_dc_ac_efficiency,(setter)BatterySystem_set_batt_dc_ac_efficiency,
	PyDoc_STR("*float*: Battery DC to AC efficiency"),
 	NULL},
{"batt_dc_dc_efficiency", (getter)BatterySystem_get_batt_dc_dc_efficiency,(setter)BatterySystem_set_batt_dc_dc_efficiency,
	PyDoc_STR("*float*: System DC to battery DC efficiency"),
 	NULL},
{"batt_inverter_efficiency_cutoff", (getter)BatterySystem_get_batt_inverter_efficiency_cutoff,(setter)BatterySystem_set_batt_inverter_efficiency_cutoff,
	PyDoc_STR("*float*: Inverter efficiency at which to cut battery charge or discharge off [%]"),
 	NULL},
{"batt_loss_choice", (getter)BatterySystem_get_batt_loss_choice,(setter)BatterySystem_set_batt_loss_choice,
	PyDoc_STR("*float*: Loss power input option [0/1]\n\n**Options:**\n0=Monthly,1=TimeSeries\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses", (getter)BatterySystem_get_batt_losses,(setter)BatterySystem_set_batt_losses,
	PyDoc_STR("*sequence*: Battery system losses at each timestep (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses_charging", (getter)BatterySystem_get_batt_losses_charging,(setter)BatterySystem_set_batt_losses_charging,
	PyDoc_STR("*sequence*: Battery system losses when charging (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses_discharging", (getter)BatterySystem_get_batt_losses_discharging,(setter)BatterySystem_set_batt_losses_discharging,
	PyDoc_STR("*sequence*: Battery system losses when discharging (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_losses_idle", (getter)BatterySystem_get_batt_losses_idle,(setter)BatterySystem_set_batt_losses_idle,
	PyDoc_STR("*sequence*: Battery system losses when idle (kW DC for DC connected, AC for AC connected) [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_mass", (getter)BatterySystem_get_batt_mass,(setter)BatterySystem_set_batt_mass,
	PyDoc_STR("*float*: Battery mass [kg]"),
 	NULL},
{"batt_meter_position", (getter)BatterySystem_get_batt_meter_position,(setter)BatterySystem_set_batt_meter_position,
	PyDoc_STR("*float*: Position of battery relative to electric meter\n\n**Options:**\n0=BehindTheMeter,1=FrontOfMeter"),
 	NULL},
{"batt_power_charge_max_kwac", (getter)BatterySystem_get_batt_power_charge_max_kwac,(setter)BatterySystem_set_batt_power_charge_max_kwac,
	PyDoc_STR("*float*: Battery maximum charge power (AC) [kWac]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_power_charge_max_kwdc", (getter)BatterySystem_get_batt_power_charge_max_kwdc,(setter)BatterySystem_set_batt_power_charge_max_kwdc,
	PyDoc_STR("*float*: Battery maximum charge power (DC) [kWdc]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_power_discharge_max_kwac", (getter)BatterySystem_get_batt_power_discharge_max_kwac,(setter)BatterySystem_set_batt_power_discharge_max_kwac,
	PyDoc_STR("*float*: Battery maximum discharge power (AC) [kWac]\n\n**INOUT:** This variable is both an input and an output to the compute module."),
 	NULL},
{"batt_power_discharge_max_kwdc", (getter)BatterySystem_get_batt_power_discharge_max_kwdc,(setter)BatterySystem_set_batt_power_discharge_max_kwdc,
	PyDoc_STR("*float*: Battery maximum discharge power (DC) [kWdc]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\nThe value of the following variables depends on ``batt_power_discharge_max_kwdc``:\n\n\t - inverter_count\n\t - subarray1_modules_per_string\n\t - subarray1_nstrings\n\t - subarray2_enable\n\t - subarray3_enable\n\t - subarray4_enable\n\t - system_capacity\n"),
 	NULL},
{"batt_replacement_capacity", (getter)BatterySystem_get_batt_replacement_capacity,(setter)BatterySystem_set_batt_replacement_capacity,
	PyDoc_STR("*float*: Capacity degradation at which to replace battery [%]"),
 	NULL},
{"batt_replacement_option", (getter)BatterySystem_get_batt_replacement_option,(setter)BatterySystem_set_batt_replacement_option,
	PyDoc_STR("*float*: Enable battery replacement? [0=none,1=capacity based,2=user schedule]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=2\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_replacement_schedule_percent", (getter)BatterySystem_get_batt_replacement_schedule_percent,(setter)BatterySystem_set_batt_replacement_schedule_percent,
	PyDoc_STR("*sequence*: Percentage of battery capacity to replace in each year [%]\n\n**Options:**\nlength <= analysis_period\n\n**Required:**\nRequired if batt_replacement_option=2"),
 	NULL},
{"batt_surface_area", (getter)BatterySystem_get_batt_surface_area,(setter)BatterySystem_set_batt_surface_area,
	PyDoc_STR("*float*: Battery surface area [m^2]"),
 	NULL},
{"en_batt", (getter)BatterySystem_get_en_batt,(setter)BatterySystem_set_en_batt,
	PyDoc_STR("*float*: Enable battery storage model [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_standalone_batt", (getter)BatterySystem_get_en_standalone_batt,(setter)BatterySystem_set_en_standalone_batt,
	PyDoc_STR("*float*: Enable standalone battery storage model [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_replacement_cost1", (getter)BatterySystem_get_om_replacement_cost1,(setter)BatterySystem_set_om_replacement_cost1,
	PyDoc_STR("*sequence*: Cost to replace battery per kWh [$/kWh]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatterySystem_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.BatterySystem",             /*tp_name*/
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
		BatterySystem_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatterySystem_getset,          /*tp_getset*/
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
 * Load Group
 */ 

static PyTypeObject Load_Type;

static PyObject *
Load_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = Load_Type.tp_alloc(&Load_Type,0);

	VarGroupObject* Load_obj = (VarGroupObject*)new_obj;

	Load_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Load methods */

static PyObject *
Load_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Load")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Load_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Load_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Load")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Load_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Load_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Load_methods[] = {
		{"assign",            (PyCFunction)Load_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Load_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Load_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Load_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Load_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Load_get_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Load_crit_load_aget, self->data_ptr);
}

static int
Load_set_crit_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Load_crit_load_aset, self->data_ptr);
}

static PyObject *
Load_get_crit_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Load_crit_load_escalation_aget, self->data_ptr);
}

static int
Load_set_crit_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Load_crit_load_escalation_aset, self->data_ptr);
}

static PyObject *
Load_get_grid_outage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Load_grid_outage_aget, self->data_ptr);
}

static int
Load_set_grid_outage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Load_grid_outage_aset, self->data_ptr);
}

static PyObject *
Load_get_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Load_load_aget, self->data_ptr);
}

static int
Load_set_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Load_load_aset, self->data_ptr);
}

static PyObject *
Load_get_load_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Load_load_escalation_aget, self->data_ptr);
}

static int
Load_set_load_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_Load_load_escalation_aset, self->data_ptr);
}

static PyObject *
Load_get_run_resiliency_calcs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Load_run_resiliency_calcs_nget, self->data_ptr);
}

static int
Load_set_run_resiliency_calcs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Load_run_resiliency_calcs_nset, self->data_ptr);
}

static PyGetSetDef Load_getset[] = {
{"crit_load", (getter)Load_get_crit_load,(setter)Load_set_crit_load,
	PyDoc_STR("*sequence*: Critical Electricity load (year 1) [kW]"),
 	NULL},
{"crit_load_escalation", (getter)Load_get_crit_load_escalation,(setter)Load_set_crit_load_escalation,
	PyDoc_STR("*sequence*: Annual critical load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"grid_outage", (getter)Load_get_grid_outage,(setter)Load_set_grid_outage,
	PyDoc_STR("*sequence*: Grid outage in this time step [0/1]\n\n**Options:**\n0=GridAvailable,1=GridUnavailable,Length=load"),
 	NULL},
{"load", (getter)Load_get_load,(setter)Load_set_load,
	PyDoc_STR("*sequence*: Electricity load (year 1) [kW]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"load_escalation", (getter)Load_get_load_escalation,(setter)Load_set_load_escalation,
	PyDoc_STR("*sequence*: Annual load escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"run_resiliency_calcs", (getter)Load_get_run_resiliency_calcs,(setter)Load_set_run_resiliency_calcs,
	PyDoc_STR("*float*: Enable resilence calculations for every timestep [0/1]\n\n**Options:**\n0=DisableCalcs,1=EnableCalcs\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Load_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Load",             /*tp_name*/
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
		Load_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Load_getset,          /*tp_getset*/
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
 * BatteryCell Group
 */ 

static PyTypeObject BatteryCell_Type;

static PyObject *
BatteryCell_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = BatteryCell_Type.tp_alloc(&BatteryCell_Type,0);

	VarGroupObject* BatteryCell_obj = (VarGroupObject*)new_obj;

	BatteryCell_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* BatteryCell methods */

static PyObject *
BatteryCell_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "BatteryCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryCell_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &BatteryCell_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "BatteryCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryCell_methods[] = {
		{"assign",            (PyCFunction)BatteryCell_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``BatteryCell_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)BatteryCell_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``BatteryCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatteryCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryCell_get_LeadAcid_q10_computed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_LeadAcid_q10_computed_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_q10_computed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_LeadAcid_q10_computed_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_LeadAcid_q20_computed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_LeadAcid_q20_computed_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_q20_computed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_LeadAcid_q20_computed_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_LeadAcid_qn_computed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_LeadAcid_qn_computed_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_qn_computed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_LeadAcid_qn_computed_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_LeadAcid_tn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_LeadAcid_tn_nget, self->data_ptr);
}

static int
BatteryCell_set_LeadAcid_tn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_LeadAcid_tn_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_C_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_C_rate_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_C_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_C_rate_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Cp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Cp_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Cp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Cp_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Qexp_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Qexp_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qfull(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Qfull_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qfull(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Qfull_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qfull_flow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Qfull_flow_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qfull_flow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Qfull_flow_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Qnom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Qnom_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Qnom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Qnom_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vcut(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Vcut_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vcut(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Vcut_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vexp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Vexp_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vexp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Vexp_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vfull(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Vfull_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vfull(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Vfull_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vnom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Vnom_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vnom(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Vnom_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_Vnom_default(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_Vnom_default_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_Vnom_default(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_Vnom_default_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_calendar_a_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_calendar_a_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_b(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_calendar_b_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_b(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_calendar_b_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_c(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_calendar_c_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_c(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_calendar_c_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_calendar_choice_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_calendar_choice_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_lifetime_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_BatteryCell_batt_calendar_lifetime_matrix_mget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_lifetime_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_BatteryCell_batt_calendar_lifetime_matrix_mset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_calendar_q0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_calendar_q0_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_calendar_q0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_calendar_q0_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_chem(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_chem_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_chem(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_chem_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_h_to_ambient(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_h_to_ambient_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_h_to_ambient(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_h_to_ambient_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_initial_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_initial_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_initial_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_initial_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_life_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_life_model_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_life_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_life_model_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_lifetime_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_BatteryCell_batt_lifetime_matrix_mget, self->data_ptr);
}

static int
BatteryCell_set_batt_lifetime_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_BatteryCell_batt_lifetime_matrix_mset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_maximum_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_maximum_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_maximum_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_maximum_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_minimum_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_minimum_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_minimum_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_minimum_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_minimum_modetime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_minimum_modetime_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_minimum_modetime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_minimum_modetime_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_minimum_outage_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_minimum_outage_SOC_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_minimum_outage_SOC(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_minimum_outage_SOC_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_resistance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_resistance_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_resistance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_resistance_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_room_temperature_celsius(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryCell_batt_room_temperature_celsius_aget, self->data_ptr);
}

static int
BatteryCell_set_batt_room_temperature_celsius(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryCell_batt_room_temperature_celsius_aset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_voltage_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryCell_batt_voltage_choice_nget, self->data_ptr);
}

static int
BatteryCell_set_batt_voltage_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryCell_batt_voltage_choice_nset, self->data_ptr);
}

static PyObject *
BatteryCell_get_batt_voltage_matrix(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_BatteryCell_batt_voltage_matrix_mget, self->data_ptr);
}

static int
BatteryCell_set_batt_voltage_matrix(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_BatteryCell_batt_voltage_matrix_mset, self->data_ptr);
}

static PyObject *
BatteryCell_get_cap_vs_temp(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_BatteryCell_cap_vs_temp_mget, self->data_ptr);
}

static int
BatteryCell_set_cap_vs_temp(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_BatteryCell_cap_vs_temp_mset, self->data_ptr);
}

static PyGetSetDef BatteryCell_getset[] = {
{"LeadAcid_q10_computed", (getter)BatteryCell_get_LeadAcid_q10_computed,(setter)BatteryCell_set_LeadAcid_q10_computed,
	PyDoc_STR("*float*: Capacity at 10-hour discharge rate [Ah]"),
 	NULL},
{"LeadAcid_q20_computed", (getter)BatteryCell_get_LeadAcid_q20_computed,(setter)BatteryCell_set_LeadAcid_q20_computed,
	PyDoc_STR("*float*: Capacity at 20-hour discharge rate [Ah]"),
 	NULL},
{"LeadAcid_qn_computed", (getter)BatteryCell_get_LeadAcid_qn_computed,(setter)BatteryCell_set_LeadAcid_qn_computed,
	PyDoc_STR("*float*: Capacity at discharge rate for n-hour rate [Ah]"),
 	NULL},
{"LeadAcid_tn", (getter)BatteryCell_get_LeadAcid_tn,(setter)BatteryCell_set_LeadAcid_tn,
	PyDoc_STR("*float*: Time to discharge [h]"),
 	NULL},
{"batt_C_rate", (getter)BatteryCell_get_batt_C_rate,(setter)BatteryCell_set_batt_C_rate,
	PyDoc_STR("*float*: Rate at which voltage vs. capacity curve input"),
 	NULL},
{"batt_Cp", (getter)BatteryCell_get_batt_Cp,(setter)BatteryCell_set_batt_Cp,
	PyDoc_STR("*float*: Battery specific heat capacity [J/KgK]"),
 	NULL},
{"batt_Qexp", (getter)BatteryCell_get_batt_Qexp,(setter)BatteryCell_set_batt_Qexp,
	PyDoc_STR("*float*: Cell capacity at end of exponential zone [Ah]"),
 	NULL},
{"batt_Qfull", (getter)BatteryCell_get_batt_Qfull,(setter)BatteryCell_set_batt_Qfull,
	PyDoc_STR("*float*: Fully charged cell capacity [Ah]"),
 	NULL},
{"batt_Qfull_flow", (getter)BatteryCell_get_batt_Qfull_flow,(setter)BatteryCell_set_batt_Qfull_flow,
	PyDoc_STR("*float*: Fully charged flow battery capacity [Ah]"),
 	NULL},
{"batt_Qnom", (getter)BatteryCell_get_batt_Qnom,(setter)BatteryCell_set_batt_Qnom,
	PyDoc_STR("*float*: Cell capacity at end of nominal zone [Ah]"),
 	NULL},
{"batt_Vcut", (getter)BatteryCell_get_batt_Vcut,(setter)BatteryCell_set_batt_Vcut,
	PyDoc_STR("*float*: Cutoff voltage for battery rated capacity [V]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_Vexp", (getter)BatteryCell_get_batt_Vexp,(setter)BatteryCell_set_batt_Vexp,
	PyDoc_STR("*float*: Cell voltage at end of exponential zone [V]"),
 	NULL},
{"batt_Vfull", (getter)BatteryCell_get_batt_Vfull,(setter)BatteryCell_set_batt_Vfull,
	PyDoc_STR("*float*: Fully charged cell voltage [V]"),
 	NULL},
{"batt_Vnom", (getter)BatteryCell_get_batt_Vnom,(setter)BatteryCell_set_batt_Vnom,
	PyDoc_STR("*float*: Cell voltage at end of nominal zone [V]"),
 	NULL},
{"batt_Vnom_default", (getter)BatteryCell_get_batt_Vnom_default,(setter)BatteryCell_set_batt_Vnom_default,
	PyDoc_STR("*float*: Default nominal cell voltage [V]"),
 	NULL},
{"batt_calendar_a", (getter)BatteryCell_get_batt_calendar_a,(setter)BatteryCell_set_batt_calendar_a,
	PyDoc_STR("*float*: Calendar life model coefficient [1/sqrt(day)]\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_calendar_b", (getter)BatteryCell_get_batt_calendar_b,(setter)BatteryCell_set_batt_calendar_b,
	PyDoc_STR("*float*: Calendar life model coefficient [K]\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_calendar_c", (getter)BatteryCell_get_batt_calendar_c,(setter)BatteryCell_set_batt_calendar_c,
	PyDoc_STR("*float*: Calendar life model coefficient [K]\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_calendar_choice", (getter)BatteryCell_get_batt_calendar_choice,(setter)BatteryCell_set_batt_calendar_choice,
	PyDoc_STR("*float*: Calendar life degradation input option [0/1/2]\n\n**Options:**\n0=NoCalendarDegradation,1=LithiomIonModel,2=InputLossTable\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0"),
 	NULL},
{"batt_calendar_lifetime_matrix", (getter)BatteryCell_get_batt_calendar_lifetime_matrix,(setter)BatteryCell_set_batt_calendar_lifetime_matrix,
	PyDoc_STR("*sequence[sequence]*: Days vs capacity\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=2"),
 	NULL},
{"batt_calendar_q0", (getter)BatteryCell_get_batt_calendar_q0,(setter)BatteryCell_set_batt_calendar_q0,
	PyDoc_STR("*float*: Calendar life model initial capacity cofficient\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0&batt_calendar_choice=1"),
 	NULL},
{"batt_chem", (getter)BatteryCell_get_batt_chem,(setter)BatteryCell_set_batt_chem,
	PyDoc_STR("*float*: Battery chemistry\n\n**Options:**\n0=LeadAcid,1=LiIon"),
 	NULL},
{"batt_h_to_ambient", (getter)BatteryCell_get_batt_h_to_ambient,(setter)BatteryCell_set_batt_h_to_ambient,
	PyDoc_STR("*float*: Heat transfer between battery and environment [W/m2K]"),
 	NULL},
{"batt_initial_SOC", (getter)BatteryCell_get_batt_initial_SOC,(setter)BatteryCell_set_batt_initial_SOC,
	PyDoc_STR("*float*: Initial state-of-charge [%]"),
 	NULL},
{"batt_life_model", (getter)BatteryCell_get_batt_life_model,(setter)BatteryCell_set_batt_life_model,
	PyDoc_STR("*float*: Battery life model specifier [0/1/2]\n\n**Options:**\n0=calendar/cycle,1=NMC,2=LMO/LTO\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_lifetime_matrix", (getter)BatteryCell_get_batt_lifetime_matrix,(setter)BatteryCell_set_batt_lifetime_matrix,
	PyDoc_STR("*sequence[sequence]*: Cycles vs capacity at different depths-of-discharge\n\n**Required:**\nRequired if en_batt=1&batt_life_model=0"),
 	NULL},
{"batt_maximum_SOC", (getter)BatteryCell_get_batt_maximum_SOC,(setter)BatteryCell_set_batt_maximum_SOC,
	PyDoc_STR("*float*: Maximum allowed state-of-charge [%]"),
 	NULL},
{"batt_minimum_SOC", (getter)BatteryCell_get_batt_minimum_SOC,(setter)BatteryCell_set_batt_minimum_SOC,
	PyDoc_STR("*float*: Minimum allowed state-of-charge during nominal operation [%]"),
 	NULL},
{"batt_minimum_modetime", (getter)BatteryCell_get_batt_minimum_modetime,(setter)BatteryCell_set_batt_minimum_modetime,
	PyDoc_STR("*float*: Minimum time at charge state [min]"),
 	NULL},
{"batt_minimum_outage_SOC", (getter)BatteryCell_get_batt_minimum_outage_SOC,(setter)BatteryCell_set_batt_minimum_outage_SOC,
	PyDoc_STR("*float*: Minimum allowed state-of-charge during an outage [%]"),
 	NULL},
{"batt_resistance", (getter)BatteryCell_get_batt_resistance,(setter)BatteryCell_set_batt_resistance,
	PyDoc_STR("*float*: Internal resistance [Ohm]"),
 	NULL},
{"batt_room_temperature_celsius", (getter)BatteryCell_get_batt_room_temperature_celsius,(setter)BatteryCell_set_batt_room_temperature_celsius,
	PyDoc_STR("*sequence*: Temperature of storage room [C]\n\n**Options:**\nlength=1 for fixed, # of weatherfile records otherwise"),
 	NULL},
{"batt_voltage_choice", (getter)BatteryCell_get_batt_voltage_choice,(setter)BatteryCell_set_batt_voltage_choice,
	PyDoc_STR("*float*: Battery voltage input option [0/1]\n\n**Options:**\n0=UseVoltageModel,1=InputVoltageTable\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_voltage_matrix", (getter)BatteryCell_get_batt_voltage_matrix,(setter)BatteryCell_set_batt_voltage_matrix,
	PyDoc_STR("*sequence[sequence]*: Battery voltage vs. depth-of-discharge"),
 	NULL},
{"cap_vs_temp", (getter)BatteryCell_get_cap_vs_temp,(setter)BatteryCell_set_cap_vs_temp,
	PyDoc_STR("*sequence[sequence]*: Effective capacity as function of temperature [C,%]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatteryCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.BatteryCell",             /*tp_name*/
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
		BatteryCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatteryCell_getset,          /*tp_getset*/
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
 * BatteryDispatch Group
 */ 

static PyTypeObject BatteryDispatch_Type;

static PyObject *
BatteryDispatch_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = BatteryDispatch_Type.tp_alloc(&BatteryDispatch_Type,0);

	VarGroupObject* BatteryDispatch_obj = (VarGroupObject*)new_obj;

	BatteryDispatch_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* BatteryDispatch methods */

static PyObject *
BatteryDispatch_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "BatteryDispatch")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryDispatch_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &BatteryDispatch_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "BatteryDispatch")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryDispatch_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryDispatch_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryDispatch_methods[] = {
		{"assign",            (PyCFunction)BatteryDispatch_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``BatteryDispatch_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)BatteryDispatch_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``BatteryDispatch_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)BatteryDispatch_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryDispatch_get_batt_custom_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_custom_dispatch_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_custom_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_custom_dispatch_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_cycle_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_cycle_cost_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_cycle_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_cycle_cost_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_cycle_cost_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_cycle_cost_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_cycle_cost_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_cycle_cost_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_btm_can_discharge_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_btm_can_discharge_to_grid_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_btm_can_discharge_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_btm_can_discharge_to_grid_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_charge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_charge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_clipcharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_clipcharge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_clipcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_clipcharge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_fuelcellcharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_fuelcellcharge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_fuelcellcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_fuelcellcharge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_auto_can_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_gridcharge_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_auto_can_gridcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_auto_can_gridcharge_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_charge_only_system_exceeds_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_charge_only_system_exceeds_load_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_charge_only_system_exceeds_load(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_charge_only_system_exceeds_load_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_discharge_only_load_exceeds_system(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_discharge_only_load_exceeds_system_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_discharge_only_load_exceeds_system(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_discharge_only_load_exceeds_system_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_load_forecast_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_load_forecast_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_load_forecast_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_load_forecast_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_lb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_lb_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_lb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_lb_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_lb_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_lb_enable_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_lb_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_lb_enable_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_ub(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_ub_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_ub(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_ub_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ac_ub_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_ub_enable_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ac_ub_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ac_ub_enable_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_curtail_as_control(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_curtail_as_control_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_curtail_as_control(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_curtail_as_control_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_curtail_if_violation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_curtail_if_violation_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_curtail_if_violation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_curtail_if_violation_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_forecast_shift_periods(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_forecast_shift_periods_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_forecast_shift_periods(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_forecast_shift_periods_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_kf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_kf_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_kf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_kf_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_ki(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ki_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_ki(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_ki_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_kp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_kp_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_kp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_kp_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_max_ramp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_max_ramp_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_max_ramp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_max_ramp_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_nameplate_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_nameplate_ac_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_nameplate_ac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_nameplate_ac_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_short_forecast_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_short_forecast_enable_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_short_forecast_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_short_forecast_enable_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_soc_rest(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_soc_rest_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_soc_rest(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_soc_rest_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_pvs_timestep_multiplier(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_timestep_multiplier_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_pvs_timestep_multiplier(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_pvs_timestep_multiplier_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_update_frequency_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_update_frequency_hours_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_update_frequency_hours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_update_frequency_hours_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_dispatch_wf_forecast_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_dispatch_wf_forecast_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_dispatch_wf_forecast_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_dispatch_wf_forecast_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_load_ac_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_load_ac_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_load_ac_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_load_ac_forecast_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_load_ac_forecast_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_load_ac_forecast_escalation_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_load_ac_forecast_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_load_ac_forecast_escalation_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_look_ahead_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_look_ahead_hours_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_look_ahead_hours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_look_ahead_hours_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_pv_ac_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_pv_ac_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_pv_ac_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_pv_ac_forecast_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_pv_clipping_forecast(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_pv_clipping_forecast_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_pv_clipping_forecast(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_pv_clipping_forecast_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_target_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_batt_target_choice_nget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_target_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_target_choice_nset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_target_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_target_power_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_target_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_target_power_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_batt_target_power_monthly(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_batt_target_power_monthly_aget, self->data_ptr);
}

static int
BatteryDispatch_set_batt_target_power_monthly(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_batt_target_power_monthly_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_btm_discharge_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_btm_discharge_to_grid_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_btm_discharge_to_grid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_btm_discharge_to_grid_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_charge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_charge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_discharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_discharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_discharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_fuelcellcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_fuelcellcharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_fuelcellcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_fuelcellcharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_gridcharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_gridcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_gridcharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_percent_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_percent_discharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_percent_discharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_percent_discharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_percent_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_percent_gridcharge_aget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_percent_gridcharge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_percent_gridcharge_aset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_sched(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_sched_mget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_sched(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_sched_mset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_sched_weekend_mget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_sched_weekend_mset, self->data_ptr);
}

static PyObject *
BatteryDispatch_get_dispatch_manual_system_charge_first(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_BatteryDispatch_dispatch_manual_system_charge_first_nget, self->data_ptr);
}

static int
BatteryDispatch_set_dispatch_manual_system_charge_first(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_BatteryDispatch_dispatch_manual_system_charge_first_nset, self->data_ptr);
}

static PyGetSetDef BatteryDispatch_getset[] = {
{"batt_custom_dispatch", (getter)BatteryDispatch_get_batt_custom_dispatch,(setter)BatteryDispatch_set_batt_custom_dispatch,
	PyDoc_STR("*sequence*: Custom battery power for every time step [kW]\n\n**Info:**\nkWAC if AC-connected, else kWDC\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_dispatch_choice=2"),
 	NULL},
{"batt_cycle_cost", (getter)BatteryDispatch_get_batt_cycle_cost,(setter)BatteryDispatch_set_batt_cycle_cost,
	PyDoc_STR("*sequence*: Input battery cycle degradaton penalty per year [$/cycle-kWh]\n\n**Info:**\nlength 1 or analysis_period, length 1 will be extended using inflation\n\n**Required:**\nRequired if batt_cycle_cost_choice=1"),
 	NULL},
{"batt_cycle_cost_choice", (getter)BatteryDispatch_get_batt_cycle_cost_choice,(setter)BatteryDispatch_set_batt_cycle_cost_choice,
	PyDoc_STR("*float*: Use SAM cost model for degradaton penalty or input custom via batt_cycle_cost [0/1]\n\n**Options:**\n0=UseCostModel,1=InputCost\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_dispatch_auto_btm_can_discharge_to_grid", (getter)BatteryDispatch_get_batt_dispatch_auto_btm_can_discharge_to_grid,(setter)BatteryDispatch_set_batt_dispatch_auto_btm_can_discharge_to_grid,
	PyDoc_STR("*float*: Behind the meter battery can discharge to grid? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_charge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_charge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_charge,
	PyDoc_STR("*float*: System charging allowed for automated dispatch? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_clipcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_clipcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_clipcharge,
	PyDoc_STR("*float*: Battery can charge from clipped power? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_fuelcellcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_fuelcellcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_fuelcellcharge,
	PyDoc_STR("*float*: Charging from fuel cell allowed for automated dispatch? [0/1]"),
 	NULL},
{"batt_dispatch_auto_can_gridcharge", (getter)BatteryDispatch_get_batt_dispatch_auto_can_gridcharge,(setter)BatteryDispatch_set_batt_dispatch_auto_can_gridcharge,
	PyDoc_STR("*float*: Grid charging allowed for automated dispatch? [0/1]"),
 	NULL},
{"batt_dispatch_charge_only_system_exceeds_load", (getter)BatteryDispatch_get_batt_dispatch_charge_only_system_exceeds_load,(setter)BatteryDispatch_set_batt_dispatch_charge_only_system_exceeds_load,
	PyDoc_STR("*float*: Battery can charge from system only when system output exceeds load [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0"),
 	NULL},
{"batt_dispatch_choice", (getter)BatteryDispatch_get_batt_dispatch_choice,(setter)BatteryDispatch_set_batt_dispatch_choice,
	PyDoc_STR("*float*: Battery dispatch algorithm [0/1/2/3/4]\n\n**Options:**\nIf behind the meter: 0=PeakShaving,1=InputGridTarget,2=InputBatteryPower,3=ManualDispatch,4=PriceSignalForecast if front of meter: 0=AutomatedEconomic,1=PV_Smoothing,2=InputBatteryPower,3=ManualDispatch\n\n**Required:**\nRequired if en_batt=1"),
 	NULL},
{"batt_dispatch_discharge_only_load_exceeds_system", (getter)BatteryDispatch_get_batt_dispatch_discharge_only_load_exceeds_system,(setter)BatteryDispatch_set_batt_dispatch_discharge_only_load_exceeds_system,
	PyDoc_STR("*float*: Battery can discharge battery only when load exceeds system output [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0"),
 	NULL},
{"batt_dispatch_load_forecast_choice", (getter)BatteryDispatch_get_batt_dispatch_load_forecast_choice,(setter)BatteryDispatch_set_batt_dispatch_load_forecast_choice,
	PyDoc_STR("*float*: Load forecast choice for automatic dispatch [0/1/2]\n\n**Options:**\n0=LookAhead,1=LookBehind,2=InputForecast\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_dispatch_pvs_ac_lb", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_lb,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_lb,
	PyDoc_STR("*float*: AC lower bound [fraction of nameplate]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ac_lb_enable", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_lb_enable,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_lb_enable,
	PyDoc_STR("*float*: Enable AC lower bound [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ac_ub", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_ub,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_ub,
	PyDoc_STR("*float*: AC upper bound [fraction of nameplate]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ac_ub_enable", (getter)BatteryDispatch_get_batt_dispatch_pvs_ac_ub_enable,(setter)BatteryDispatch_set_batt_dispatch_pvs_ac_ub_enable,
	PyDoc_STR("*float*: Enable AC upper bound [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_curtail_as_control", (getter)BatteryDispatch_get_batt_dispatch_pvs_curtail_as_control,(setter)BatteryDispatch_set_batt_dispatch_pvs_curtail_as_control,
	PyDoc_STR("*float*: Correct up-ramp violations [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_curtail_if_violation", (getter)BatteryDispatch_get_batt_dispatch_pvs_curtail_if_violation,(setter)BatteryDispatch_set_batt_dispatch_pvs_curtail_if_violation,
	PyDoc_STR("*float*: Curtail violations [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_forecast_shift_periods", (getter)BatteryDispatch_get_batt_dispatch_pvs_forecast_shift_periods,(setter)BatteryDispatch_set_batt_dispatch_pvs_forecast_shift_periods,
	PyDoc_STR("*float*: Forecasting window [periods of ramp intervals]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_kf", (getter)BatteryDispatch_get_batt_dispatch_pvs_kf,(setter)BatteryDispatch_set_batt_dispatch_pvs_kf,
	PyDoc_STR("*float*: Forecast accumulation error multiplier (kf)\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_ki", (getter)BatteryDispatch_get_batt_dispatch_pvs_ki,(setter)BatteryDispatch_set_batt_dispatch_pvs_ki,
	PyDoc_STR("*float*: Return to rest SOC multiplier (ki)\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_kp", (getter)BatteryDispatch_get_batt_dispatch_pvs_kp,(setter)BatteryDispatch_set_batt_dispatch_pvs_kp,
	PyDoc_STR("*float*: Track PV power multiplier (kp)\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_max_ramp", (getter)BatteryDispatch_get_batt_dispatch_pvs_max_ramp,(setter)BatteryDispatch_set_batt_dispatch_pvs_max_ramp,
	PyDoc_STR("*float*: Maximum ramp rate [% of nameplate per ramp interval]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_nameplate_ac", (getter)BatteryDispatch_get_batt_dispatch_pvs_nameplate_ac,(setter)BatteryDispatch_set_batt_dispatch_pvs_nameplate_ac,
	PyDoc_STR("*float*: Nameplate for pv smoothing [kWac]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_short_forecast_enable", (getter)BatteryDispatch_get_batt_dispatch_pvs_short_forecast_enable,(setter)BatteryDispatch_set_batt_dispatch_pvs_short_forecast_enable,
	PyDoc_STR("*float*: Enable short term power forecast [0/1]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_soc_rest", (getter)BatteryDispatch_get_batt_dispatch_pvs_soc_rest,(setter)BatteryDispatch_set_batt_dispatch_pvs_soc_rest,
	PyDoc_STR("*float*: Battery resting SOC [%]\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_pvs_timestep_multiplier", (getter)BatteryDispatch_get_batt_dispatch_pvs_timestep_multiplier,(setter)BatteryDispatch_set_batt_dispatch_pvs_timestep_multiplier,
	PyDoc_STR("*float*: Ramp timestep multiplier\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=1&batt_dispatch_choice=1"),
 	NULL},
{"batt_dispatch_update_frequency_hours", (getter)BatteryDispatch_get_batt_dispatch_update_frequency_hours,(setter)BatteryDispatch_set_batt_dispatch_update_frequency_hours,
	PyDoc_STR("*float*: Frequency to update the look-ahead dispatch [hours]"),
 	NULL},
{"batt_dispatch_wf_forecast_choice", (getter)BatteryDispatch_get_batt_dispatch_wf_forecast_choice,(setter)BatteryDispatch_set_batt_dispatch_wf_forecast_choice,
	PyDoc_STR("*float*: Weather forecast choice for automatic dispatch [0/1/2]\n\n**Options:**\n0=LookAhead,1=LookBehind,2=InputForecast\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"batt_load_ac_forecast", (getter)BatteryDispatch_get_batt_load_ac_forecast,(setter)BatteryDispatch_set_batt_load_ac_forecast,
	PyDoc_STR("*sequence*: Load ac power forecast [kW]\n\n**Info:**\nLength either 8760 or 8760 * steps per hour"),
 	NULL},
{"batt_load_ac_forecast_escalation", (getter)BatteryDispatch_get_batt_load_ac_forecast_escalation,(setter)BatteryDispatch_set_batt_load_ac_forecast_escalation,
	PyDoc_STR("*sequence*: Annual load escalation for ac power forecast [kW]\n\n**Options:**\nlength <= analysis_period"),
 	NULL},
{"batt_look_ahead_hours", (getter)BatteryDispatch_get_batt_look_ahead_hours,(setter)BatteryDispatch_set_batt_look_ahead_hours,
	PyDoc_STR("*float*: Hours to look ahead in automated dispatch [hours]"),
 	NULL},
{"batt_pv_ac_forecast", (getter)BatteryDispatch_get_batt_pv_ac_forecast,(setter)BatteryDispatch_set_batt_pv_ac_forecast,
	PyDoc_STR("*sequence*: PV ac power forecast [kW]\n\n**Info:**\nLength either 8760 * steps per hour (values repeat each year) or 8760 * steps per hour * analysis period"),
 	NULL},
{"batt_pv_clipping_forecast", (getter)BatteryDispatch_get_batt_pv_clipping_forecast,(setter)BatteryDispatch_set_batt_pv_clipping_forecast,
	PyDoc_STR("*sequence*: PV clipping forecast [kW]\n\n**Info:**\nLength either 8760 * steps per hour (values repeat each year) or 8760 * steps per hour * analysis period"),
 	NULL},
{"batt_target_choice", (getter)BatteryDispatch_get_batt_target_choice,(setter)BatteryDispatch_set_batt_target_choice,
	PyDoc_STR("*float*: Target power input option [0/1]\n\n**Options:**\n0=InputMonthlyTarget,1=InputFullTimeSeries\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0&batt_dispatch_choice=1"),
 	NULL},
{"batt_target_power", (getter)BatteryDispatch_get_batt_target_power,(setter)BatteryDispatch_set_batt_target_power,
	PyDoc_STR("*sequence*: Grid target power for every time step [kW]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=0&batt_dispatch_choice=1"),
 	NULL},
{"batt_target_power_monthly", (getter)BatteryDispatch_get_batt_target_power_monthly,(setter)BatteryDispatch_set_batt_target_power_monthly,
	PyDoc_STR("*sequence*: Grid target power on monthly basis [kW]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=0&batt_dispatch_choice=1"),
 	NULL},
{"dispatch_manual_btm_discharge_to_grid", (getter)BatteryDispatch_get_dispatch_manual_btm_discharge_to_grid,(setter)BatteryDispatch_set_dispatch_manual_btm_discharge_to_grid,
	PyDoc_STR("*sequence*: Periods 1-6 behind the meter discharging to grid allowed?\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3&batt_meter_position=0"),
 	NULL},
{"dispatch_manual_charge", (getter)BatteryDispatch_get_dispatch_manual_charge,(setter)BatteryDispatch_set_dispatch_manual_charge,
	PyDoc_STR("*sequence*: Periods 1-6 charging from system allowed?\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_discharge", (getter)BatteryDispatch_get_dispatch_manual_discharge,(setter)BatteryDispatch_set_dispatch_manual_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 discharging allowed?\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_fuelcellcharge", (getter)BatteryDispatch_get_dispatch_manual_fuelcellcharge,(setter)BatteryDispatch_set_dispatch_manual_fuelcellcharge,
	PyDoc_STR("*sequence*: Periods 1-6 charging from fuel cell allowed?"),
 	NULL},
{"dispatch_manual_gridcharge", (getter)BatteryDispatch_get_dispatch_manual_gridcharge,(setter)BatteryDispatch_set_dispatch_manual_gridcharge,
	PyDoc_STR("*sequence*: Periods 1-6 grid charging allowed?\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_percent_discharge", (getter)BatteryDispatch_get_dispatch_manual_percent_discharge,(setter)BatteryDispatch_set_dispatch_manual_percent_discharge,
	PyDoc_STR("*sequence*: Periods 1-6 discharge percent [%]\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_percent_gridcharge", (getter)BatteryDispatch_get_dispatch_manual_percent_gridcharge,(setter)BatteryDispatch_set_dispatch_manual_percent_gridcharge,
	PyDoc_STR("*sequence*: Periods 1-6 gridcharge percent [%]\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_sched", (getter)BatteryDispatch_get_dispatch_manual_sched,(setter)BatteryDispatch_set_dispatch_manual_sched,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule for weekday\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_sched_weekend", (getter)BatteryDispatch_get_dispatch_manual_sched_weekend,(setter)BatteryDispatch_set_dispatch_manual_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule for weekend\n\n**Required:**\nRequired if en_batt=1&batt_dispatch_choice=3"),
 	NULL},
{"dispatch_manual_system_charge_first", (getter)BatteryDispatch_get_dispatch_manual_system_charge_first,(setter)BatteryDispatch_set_dispatch_manual_system_charge_first,
	PyDoc_STR("*float*: System charges battery before meeting load [0/1]\n\n**Options:**\n0=LoadFirst,1=ChargeFirst\n\n**Required:**\nRequired if en_batt=1&en_standalone_batt=0&batt_meter_position=0&batt_dispatch_choice=3&batt_dispatch_charge_only_system_exceeds_load=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatteryDispatch_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.BatteryDispatch",             /*tp_name*/
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
		BatteryDispatch_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatteryDispatch_getset,          /*tp_getset*/
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
 * SystemCosts Group
 */ 

static PyTypeObject SystemCosts_Type;

static PyObject *
SystemCosts_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = SystemCosts_Type.tp_alloc(&SystemCosts_Type,0);

	VarGroupObject* SystemCosts_obj = (VarGroupObject*)new_obj;

	SystemCosts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemCosts methods */

static PyObject *
SystemCosts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "SystemCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCosts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &SystemCosts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "SystemCosts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCosts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemCosts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemCosts_methods[] = {
		{"assign",            (PyCFunction)SystemCosts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``SystemCosts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)SystemCosts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``SystemCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCosts_get_om_batt_replacement_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemCosts_om_batt_replacement_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_replacement_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemCosts_om_batt_replacement_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_batt_variable_cost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_SystemCosts_om_batt_variable_cost_aget, self->data_ptr);
}

static int
SystemCosts_set_om_batt_variable_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_SystemCosts_om_batt_variable_cost_aset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_production_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemCosts_om_production_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_production_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemCosts_om_production_escal_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_om_replacement_cost_escal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_SystemCosts_om_replacement_cost_escal_nget, self->data_ptr);
}

static int
SystemCosts_set_om_replacement_cost_escal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_SystemCosts_om_replacement_cost_escal_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"om_batt_replacement_cost", (getter)SystemCosts_get_om_batt_replacement_cost,(setter)SystemCosts_set_om_batt_replacement_cost,
	PyDoc_STR("*sequence*: Replacement cost 1 [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_batt_variable_cost", (getter)SystemCosts_get_om_batt_variable_cost,(setter)SystemCosts_set_om_batt_variable_cost,
	PyDoc_STR("*sequence*: Battery production-based System Costs amount [$/MWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_production_escal", (getter)SystemCosts_get_om_production_escal,(setter)SystemCosts_set_om_production_escal,
	PyDoc_STR("*float*: Production-based O&M escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"om_replacement_cost_escal", (getter)SystemCosts_get_om_replacement_cost_escal,(setter)SystemCosts_set_om_replacement_cost_escal,
	PyDoc_STR("*float*: Replacement cost escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.SystemCosts",             /*tp_name*/
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
		SystemCosts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemCosts_getset,          /*tp_getset*/
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
 * FuelCell Group
 */ 

static PyTypeObject FuelCell_Type;

static PyObject *
FuelCell_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = FuelCell_Type.tp_alloc(&FuelCell_Type,0);

	VarGroupObject* FuelCell_obj = (VarGroupObject*)new_obj;

	FuelCell_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FuelCell methods */

static PyObject *
FuelCell_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "FuelCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FuelCell_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &FuelCell_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "FuelCell")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FuelCell_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FuelCell_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FuelCell_methods[] = {
		{"assign",            (PyCFunction)FuelCell_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``FuelCell_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)FuelCell_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``FuelCell_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FuelCell_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FuelCell_get_fuelcell_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_FuelCell_fuelcell_power_aget, self->data_ptr);
}

static int
FuelCell_set_fuelcell_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_FuelCell_fuelcell_power_aset, self->data_ptr);
}

static PyGetSetDef FuelCell_getset[] = {
{"fuelcell_power", (getter)FuelCell_get_fuelcell_power,(setter)FuelCell_set_fuelcell_power,
	PyDoc_STR("*sequence*: Electricity from fuel cell AC [kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FuelCell_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.FuelCell",             /*tp_name*/
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
		FuelCell_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FuelCell_getset,          /*tp_getset*/
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
 * PriceSignal Group
 */ 

static PyTypeObject PriceSignal_Type;

static PyObject *
PriceSignal_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = PriceSignal_Type.tp_alloc(&PriceSignal_Type,0);

	VarGroupObject* PriceSignal_obj = (VarGroupObject*)new_obj;

	PriceSignal_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PriceSignal methods */

static PyObject *
PriceSignal_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "PriceSignal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PriceSignal_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PriceSignal_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "PriceSignal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PriceSignal_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PriceSignal_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PriceSignal_methods[] = {
		{"assign",            (PyCFunction)PriceSignal_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PriceSignal_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PriceSignal_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PriceSignal_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PriceSignal_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PriceSignal_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_PriceSignal_dispatch_factors_ts_aget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_PriceSignal_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
PriceSignal_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_dispatch_tod_factors(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_PriceSignal_dispatch_tod_factors_aget, self->data_ptr);
}

static int
PriceSignal_set_dispatch_tod_factors(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_PriceSignal_dispatch_tod_factors_aset, self->data_ptr);
}

static PyObject *
PriceSignal_get_forecast_price_signal_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_forecast_price_signal_model_nget, self->data_ptr);
}

static int
PriceSignal_set_forecast_price_signal_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_forecast_price_signal_model_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv1_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_mp_ancserv1_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv1_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_mp_ancserv1_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv2_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_mp_ancserv2_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv2_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_mp_ancserv2_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv3_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_mp_ancserv3_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv3_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_mp_ancserv3_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_ancserv4_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_mp_ancserv4_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_ancserv4_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_mp_ancserv4_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_mp_enable_ancserv1_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_mp_enable_ancserv1_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_mp_enable_ancserv2_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_mp_enable_ancserv2_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_mp_enable_ancserv3_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_mp_enable_ancserv3_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_ancserv4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_mp_enable_ancserv4_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_ancserv4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_mp_enable_ancserv4_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_enable_energy_market_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_mp_enable_energy_market_revenue_nget, self->data_ptr);
}

static int
PriceSignal_set_mp_enable_energy_market_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_mp_enable_energy_market_revenue_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_mp_energy_market_revenue(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_PriceSignal_mp_energy_market_revenue_mget, self->data_ptr);
}

static int
PriceSignal_set_mp_energy_market_revenue(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_PriceSignal_mp_energy_market_revenue_mset, self->data_ptr);
}

static PyObject *
PriceSignal_get_ppa_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_ppa_escalation_nget, self->data_ptr);
}

static int
PriceSignal_set_ppa_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_ppa_escalation_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_PriceSignal_ppa_multiplier_model_nget, self->data_ptr);
}

static int
PriceSignal_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_PriceSignal_ppa_multiplier_model_nset, self->data_ptr);
}

static PyObject *
PriceSignal_get_ppa_price_input(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_PriceSignal_ppa_price_input_aget, self->data_ptr);
}

static int
PriceSignal_set_ppa_price_input(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_PriceSignal_ppa_price_input_aset, self->data_ptr);
}

static PyGetSetDef PriceSignal_getset[] = {
{"dispatch_factors_ts", (getter)PriceSignal_get_dispatch_factors_ts,(setter)PriceSignal_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor time step\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1&ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)PriceSignal_get_dispatch_sched_weekday,(setter)PriceSignal_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekday TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"dispatch_sched_weekend", (getter)PriceSignal_get_dispatch_sched_weekend,(setter)PriceSignal_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Diurnal weekend TOD periods [1..9]\n\n**Info:**\n12 x 24 matrix\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"dispatch_tod_factors", (getter)PriceSignal_get_dispatch_tod_factors,(setter)PriceSignal_set_dispatch_tod_factors,
	PyDoc_STR("*sequence*: TOD factors for periods 1-9\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=0&ppa_multiplier_model=0"),
 	NULL},
{"forecast_price_signal_model", (getter)PriceSignal_get_forecast_price_signal_model,(setter)PriceSignal_set_forecast_price_signal_model,
	PyDoc_STR("*float*: Forecast price signal model selected [0/1]\n\n**Options:**\n0=PPA based,1=Merchant Plant\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"mp_ancserv1_revenue", (getter)PriceSignal_get_mp_ancserv1_revenue,(setter)PriceSignal_set_mp_ancserv1_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 1 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv2_revenue", (getter)PriceSignal_get_mp_ancserv2_revenue,(setter)PriceSignal_set_mp_ancserv2_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 2 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv3_revenue", (getter)PriceSignal_get_mp_ancserv3_revenue,(setter)PriceSignal_set_mp_ancserv3_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 3 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_ancserv4_revenue", (getter)PriceSignal_get_mp_ancserv4_revenue,(setter)PriceSignal_set_mp_ancserv4_revenue,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 4 revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv1", (getter)PriceSignal_get_mp_enable_ancserv1,(setter)PriceSignal_set_mp_enable_ancserv1,
	PyDoc_STR("*float*: Enable ancillary services 1 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv2", (getter)PriceSignal_get_mp_enable_ancserv2,(setter)PriceSignal_set_mp_enable_ancserv2,
	PyDoc_STR("*float*: Enable ancillary services 2 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv3", (getter)PriceSignal_get_mp_enable_ancserv3,(setter)PriceSignal_set_mp_enable_ancserv3,
	PyDoc_STR("*float*: Enable ancillary services 3 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv4", (getter)PriceSignal_get_mp_enable_ancserv4,(setter)PriceSignal_set_mp_enable_ancserv4,
	PyDoc_STR("*float*: Enable ancillary services 4 revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_energy_market_revenue", (getter)PriceSignal_get_mp_enable_energy_market_revenue,(setter)PriceSignal_set_mp_enable_energy_market_revenue,
	PyDoc_STR("*float*: Enable energy market revenue [0/1]\n\n**Options:**\n0=false,1=true\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"mp_energy_market_revenue", (getter)PriceSignal_get_mp_energy_market_revenue,(setter)PriceSignal_set_mp_energy_market_revenue,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input [ [MW, $/MW]]\n\n**Required:**\nRequired if en_batt=1&batt_meter_position=1&forecast_price_signal_model=1"),
 	NULL},
{"ppa_escalation", (getter)PriceSignal_get_ppa_escalation,(setter)PriceSignal_set_ppa_escalation,
	PyDoc_STR("*float*: PPA escalation rate [%/year]\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
{"ppa_multiplier_model", (getter)PriceSignal_get_ppa_multiplier_model,(setter)PriceSignal_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n**Options:**\n0=diurnal,1=timestep\n\n**Constraints:**\nINTEGER,MIN=0\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
{"ppa_price_input", (getter)PriceSignal_get_ppa_price_input,(setter)PriceSignal_set_ppa_price_input,
	PyDoc_STR("*sequence*: PPA Price Input [$/kWh]\n\n**Required:**\nRequired if forecast_price_signal_model=0&en_batt=1&batt_meter_position=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PriceSignal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.PriceSignal",             /*tp_name*/
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
		PriceSignal_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PriceSignal_getset,          /*tp_getset*/
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
Revenue_new(SAM_Pvsamv1 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Revenue")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Revenue")){
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
Revenue_get_mp_ancserv1_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Revenue_mp_ancserv1_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv1_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Revenue_mp_ancserv1_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_ancserv2_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Revenue_mp_ancserv2_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv2_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Revenue_mp_ancserv2_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_ancserv3_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Revenue_mp_ancserv3_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv3_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Revenue_mp_ancserv3_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_ancserv4_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Revenue_mp_ancserv4_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_ancserv4_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Revenue_mp_ancserv4_revenue_single_mset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv1_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Revenue_mp_enable_ancserv1_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv1_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Revenue_mp_enable_ancserv1_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv2_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Revenue_mp_enable_ancserv2_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv2_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Revenue_mp_enable_ancserv2_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv3_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Revenue_mp_enable_ancserv3_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv3_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Revenue_mp_enable_ancserv3_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_ancserv4_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Revenue_mp_enable_ancserv4_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_ancserv4_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Revenue_mp_enable_ancserv4_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_enable_market_percent_gen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Revenue_mp_enable_market_percent_gen_nget, self->data_ptr);
}

static int
Revenue_set_mp_enable_market_percent_gen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_Revenue_mp_enable_market_percent_gen_nset, self->data_ptr);
}

static PyObject *
Revenue_get_mp_energy_market_revenue_single(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Revenue_mp_energy_market_revenue_single_mget, self->data_ptr);
}

static int
Revenue_set_mp_energy_market_revenue_single(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_Revenue_mp_energy_market_revenue_single_mset, self->data_ptr);
}

static PyGetSetDef Revenue_getset[] = {
{"mp_ancserv1_revenue_single", (getter)Revenue_get_mp_ancserv1_revenue_single,(setter)Revenue_set_mp_ancserv1_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 1 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv1_percent_gen=1"),
 	NULL},
{"mp_ancserv2_revenue_single", (getter)Revenue_get_mp_ancserv2_revenue_single,(setter)Revenue_set_mp_ancserv2_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 2 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv2_percent_gen=1"),
 	NULL},
{"mp_ancserv3_revenue_single", (getter)Revenue_get_mp_ancserv3_revenue_single,(setter)Revenue_set_mp_ancserv3_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 3 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv3_percent_gen=1"),
 	NULL},
{"mp_ancserv4_revenue_single", (getter)Revenue_get_mp_ancserv4_revenue_single,(setter)Revenue_set_mp_ancserv4_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Ancillary services 4 revenue input\n\n**Info:**\nLifetime x 1[Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_ancserv4_percent_gen=1"),
 	NULL},
{"mp_enable_ancserv1_percent_gen", (getter)Revenue_get_mp_enable_ancserv1_percent_gen,(setter)Revenue_set_mp_enable_ancserv1_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 1 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv2_percent_gen", (getter)Revenue_get_mp_enable_ancserv2_percent_gen,(setter)Revenue_set_mp_enable_ancserv2_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 2 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv3_percent_gen", (getter)Revenue_get_mp_enable_ancserv3_percent_gen,(setter)Revenue_set_mp_enable_ancserv3_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 3 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_ancserv4_percent_gen", (getter)Revenue_get_mp_enable_ancserv4_percent_gen,(setter)Revenue_set_mp_enable_ancserv4_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for ancillary service 4 [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_enable_market_percent_gen", (getter)Revenue_get_mp_enable_market_percent_gen,(setter)Revenue_set_mp_enable_market_percent_gen,
	PyDoc_STR("*float*: Enable percent demand cleared capacity option for market revenue [0/1]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nRequired if forecast_price_signal_model=1"),
 	NULL},
{"mp_energy_market_revenue_single", (getter)Revenue_get_mp_energy_market_revenue_single,(setter)Revenue_set_mp_energy_market_revenue_single,
	PyDoc_STR("*sequence[sequence]*: Energy market revenue input\n\n**Info:**\nLifetime x 1 [Price($/MWh)]\n\n**Required:**\nRequired if forecast_price_signal_model=1&mp_enable_market_percent_gen=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Revenue_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Revenue",             /*tp_name*/
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
 * ElectricityRates Group
 */ 

static PyTypeObject ElectricityRates_Type;

static PyObject *
ElectricityRates_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = ElectricityRates_Type.tp_alloc(&ElectricityRates_Type,0);

	VarGroupObject* ElectricityRates_obj = (VarGroupObject*)new_obj;

	ElectricityRates_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ElectricityRates methods */

static PyObject *
ElectricityRates_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "ElectricityRates")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRates_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &ElectricityRates_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "ElectricityRates")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricityRates_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricityRates_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricityRates_methods[] = {
		{"assign",            (PyCFunction)ElectricityRates_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)ElectricityRates_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``ElectricityRates_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ElectricityRates_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricityRates_get_en_electricity_rates(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_en_electricity_rates_nget, self->data_ptr);
}

static int
ElectricityRates_set_en_electricity_rates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_en_electricity_rates_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_rate_escalation(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_ElectricityRates_rate_escalation_aget, self->data_ptr);
}

static int
ElectricityRates_set_rate_escalation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_ElectricityRates_rate_escalation_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_annual_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_annual_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_annual_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_annual_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_percentages(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_billing_demand_lookback_percentages_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_percentages(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_billing_demand_lookback_percentages_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_lookback_period(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_billing_demand_lookback_period_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_lookback_period(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_billing_demand_lookback_period_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_billing_demand_minimum(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_billing_demand_minimum_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_billing_demand_minimum(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_billing_demand_minimum_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_billing_demand_periods(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_dc_billing_demand_periods_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_billing_demand_periods(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_dc_billing_demand_periods_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_enable(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_dc_enable_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_enable(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_dc_enable_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_flat_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_dc_flat_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_flat_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_dc_flat_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_dc_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_dc_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_dc_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_dc_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_dc_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_dc_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_dc_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_dc_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_ec_sched_weekday_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_ec_sched_weekday_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_ec_sched_weekend_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_ec_sched_weekend_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ec_tou_mat(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_ElectricityRates_ur_ec_tou_mat_mget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ec_tou_mat(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Pvsamv1_ElectricityRates_ur_ec_tou_mat_mset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_en_ts_buy_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_en_ts_buy_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_en_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_en_ts_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_en_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_en_ts_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_enable_billing_demand(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_enable_billing_demand_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_enable_billing_demand(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_enable_billing_demand_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_metering_option(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_metering_option_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_metering_option(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_metering_option_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_fixed_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_monthly_fixed_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_fixed_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_monthly_fixed_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_monthly_min_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_monthly_min_charge_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_monthly_min_charge(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_monthly_min_charge_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_month(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_nm_credit_month_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_month(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_nm_credit_month_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_credit_rollover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_nm_credit_rollover_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_credit_rollover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_nm_credit_rollover_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_nm_yearend_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_nm_yearend_sell_rate_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_nm_yearend_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_nm_yearend_sell_rate_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_sell_eq_buy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_ElectricityRates_ur_sell_eq_buy_nget, self->data_ptr);
}

static int
ElectricityRates_set_ur_sell_eq_buy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_ElectricityRates_ur_sell_eq_buy_nset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_buy_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_ElectricityRates_ur_ts_buy_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_buy_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_ElectricityRates_ur_ts_buy_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_ts_sell_rate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_ElectricityRates_ur_ts_sell_rate_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_ts_sell_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_ElectricityRates_ur_ts_sell_rate_aset, self->data_ptr);
}

static PyObject *
ElectricityRates_get_ur_yearzero_usage_peaks(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_ElectricityRates_ur_yearzero_usage_peaks_aget, self->data_ptr);
}

static int
ElectricityRates_set_ur_yearzero_usage_peaks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_ElectricityRates_ur_yearzero_usage_peaks_aset, self->data_ptr);
}

static PyGetSetDef ElectricityRates_getset[] = {
{"en_electricity_rates", (getter)ElectricityRates_get_en_electricity_rates,(setter)ElectricityRates_set_en_electricity_rates,
	PyDoc_STR("*float*: Optionally enable/disable electricity_rate [years]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1"),
 	NULL},
{"rate_escalation", (getter)ElectricityRates_get_rate_escalation,(setter)ElectricityRates_set_rate_escalation,
	PyDoc_STR("*sequence*: Annual electricity rate escalation [%/year]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_annual_min_charge", (getter)ElectricityRates_get_ur_annual_min_charge,(setter)ElectricityRates_set_ur_annual_min_charge,
	PyDoc_STR("*float*: Annual minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_billing_demand_lookback_percentages", (getter)ElectricityRates_get_ur_billing_demand_lookback_percentages,(setter)ElectricityRates_set_ur_billing_demand_lookback_percentages,
	PyDoc_STR("*sequence[sequence]*: Billing demand lookback percentages by month and consider actual peak demand [%]\n\n**Info:**\n12x2\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_billing_demand_lookback_period", (getter)ElectricityRates_get_ur_billing_demand_lookback_period,(setter)ElectricityRates_set_ur_billing_demand_lookback_period,
	PyDoc_STR("*float*: Billing demand lookback period [mn]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=12\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_billing_demand_minimum", (getter)ElectricityRates_get_ur_billing_demand_minimum,(setter)ElectricityRates_set_ur_billing_demand_minimum,
	PyDoc_STR("*float*: Minimum billing demand [kW]\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_dc_billing_demand_periods", (getter)ElectricityRates_get_ur_dc_billing_demand_periods,(setter)ElectricityRates_set_ur_dc_billing_demand_periods,
	PyDoc_STR("*sequence[sequence]*: Billing demand applicability to a given demand charge time of use period\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
{"ur_dc_enable", (getter)ElectricityRates_get_ur_dc_enable,(setter)ElectricityRates_set_ur_dc_enable,
	PyDoc_STR("*float*: Enable demand charge [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_dc_flat_mat", (getter)ElectricityRates_get_ur_dc_flat_mat,(setter)ElectricityRates_set_ur_dc_flat_mat,
	PyDoc_STR("*sequence[sequence]*: Demand rates (flat) table [col 0=month, col 1=tier no, col 2=tier peak (kW), col 3=charge ($/kW)]\n\n**Info:**\nnx4\n\n**Required:**\nRequired if ur_dc_enable=1"),
 	NULL},
{"ur_dc_sched_weekday", (getter)ElectricityRates_get_ur_dc_sched_weekday,(setter)ElectricityRates_set_ur_dc_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Demand charge weekday schedule [Periods defined in ur_dc_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_sched_weekend", (getter)ElectricityRates_get_ur_dc_sched_weekend,(setter)ElectricityRates_set_ur_dc_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Demand charge weekend schedule [Periods defined in ur_dc_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_dc_tou_mat", (getter)ElectricityRates_get_ur_dc_tou_mat,(setter)ElectricityRates_set_ur_dc_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Demand rates (TOU) table [col 0=period no, col 1=tier no, col 2=tier peak (kW), col 3=charge ($/kW)]\n\n**Info:**\nnx4\n\n**Required:**\nRequired if ur_dc_enable=1"),
 	NULL},
{"ur_ec_sched_weekday", (getter)ElectricityRates_get_ur_ec_sched_weekday,(setter)ElectricityRates_set_ur_ec_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekday schedule [Periods defined in ur_ec_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_ec_sched_weekend", (getter)ElectricityRates_get_ur_ec_sched_weekend,(setter)ElectricityRates_set_ur_ec_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: Energy charge weekend schedule [Periods defined in ur_ec_tou_mat]\n\n**Info:**\n12x24"),
 	NULL},
{"ur_ec_tou_mat", (getter)ElectricityRates_get_ur_ec_tou_mat,(setter)ElectricityRates_set_ur_ec_tou_mat,
	PyDoc_STR("*sequence[sequence]*: Energy rates table [col 0=period no, col 1=tier no, col 2=max usage, col 3=max usage units (0=kWh, 1=kWh/kW, 2=kWh daily, 3=kWh/kW daily), col 4=buy rate ($/kWh), col 5=sell rate ($/kWh)]\n\n**Info:**\nnx6"),
 	NULL},
{"ur_en_ts_buy_rate", (getter)ElectricityRates_get_ur_en_ts_buy_rate,(setter)ElectricityRates_set_ur_en_ts_buy_rate,
	PyDoc_STR("*float*: Enable time step buy rates [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_en_ts_sell_rate", (getter)ElectricityRates_get_ur_en_ts_sell_rate,(setter)ElectricityRates_set_ur_en_ts_sell_rate,
	PyDoc_STR("*float*: Enable time step sell rates [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_enable_billing_demand", (getter)ElectricityRates_get_ur_enable_billing_demand,(setter)ElectricityRates_set_ur_enable_billing_demand,
	PyDoc_STR("*float*: Enable billing demand ratchets [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_metering_option", (getter)ElectricityRates_get_ur_metering_option,(setter)ElectricityRates_set_ur_metering_option,
	PyDoc_STR("*float*: Metering options [0=net energy metering,1=net energy metering with $ credits,2=net billing,3=net billing with carryover to next month,4=buy all - sell all]\n\n**Info:**\nNet metering monthly excess\n\n**Constraints:**\nINTEGER,MIN=0,MAX=4\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_monthly_fixed_charge", (getter)ElectricityRates_get_ur_monthly_fixed_charge,(setter)ElectricityRates_set_ur_monthly_fixed_charge,
	PyDoc_STR("*float*: Monthly fixed charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_monthly_min_charge", (getter)ElectricityRates_get_ur_monthly_min_charge,(setter)ElectricityRates_set_ur_monthly_min_charge,
	PyDoc_STR("*float*: Monthly minimum charge [$]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_credit_month", (getter)ElectricityRates_get_ur_nm_credit_month,(setter)ElectricityRates_set_ur_nm_credit_month,
	PyDoc_STR("*float*: Month of year end payout (true-up) [mn]\n\n**Constraints:**\nINTEGER,MIN=0,MAX=11\n\n**Required:**\nFalse. Automatically set to 11 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_credit_rollover", (getter)ElectricityRates_get_ur_nm_credit_rollover,(setter)ElectricityRates_set_ur_nm_credit_rollover,
	PyDoc_STR("*float*: Apply net metering true-up credits to future bills [0/1]\n\n**Options:**\n0=disable,1=enable\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_nm_yearend_sell_rate", (getter)ElectricityRates_get_ur_nm_yearend_sell_rate,(setter)ElectricityRates_set_ur_nm_yearend_sell_rate,
	PyDoc_STR("*float*: Net metering true-up credit sell rate [$/kWh]\n\n**Required:**\nFalse. Automatically set to 0.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_sell_eq_buy", (getter)ElectricityRates_get_ur_sell_eq_buy,(setter)ElectricityRates_set_ur_sell_eq_buy,
	PyDoc_STR("*float*: Set sell rate equal to buy rate [0/1]\n\n**Info:**\nOptional override\n\n**Constraints:**\nBOOLEAN\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ur_ts_buy_rate", (getter)ElectricityRates_get_ur_ts_buy_rate,(setter)ElectricityRates_set_ur_ts_buy_rate,
	PyDoc_STR("*sequence*: Time step buy rates [$/kWh]"),
 	NULL},
{"ur_ts_sell_rate", (getter)ElectricityRates_get_ur_ts_sell_rate,(setter)ElectricityRates_set_ur_ts_sell_rate,
	PyDoc_STR("*sequence*: Time step sell rates [$/kWh]"),
 	NULL},
{"ur_yearzero_usage_peaks", (getter)ElectricityRates_get_ur_yearzero_usage_peaks,(setter)ElectricityRates_set_ur_yearzero_usage_peaks,
	PyDoc_STR("*sequence*: Peak usage by month for year zero [kW]\n\n**Info:**\n12\n\n**Required:**\nRequired if ur_enable_billing_demand=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricityRates_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.ElectricityRates",             /*tp_name*/
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
		ElectricityRates_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricityRates_getset,          /*tp_getset*/
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
 * GridLimits Group
 */ 

static PyTypeObject GridLimits_Type;

static PyObject *
GridLimits_new(SAM_Pvsamv1 data_ptr)
{
	PyObject* new_obj = GridLimits_Type.tp_alloc(&GridLimits_Type,0);

	VarGroupObject* GridLimits_obj = (VarGroupObject*)new_obj;

	GridLimits_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* GridLimits methods */

static PyObject *
GridLimits_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "GridLimits")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GridLimits_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &GridLimits_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "GridLimits")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GridLimits_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &GridLimits_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GridLimits_methods[] = {
		{"assign",            (PyCFunction)GridLimits_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``GridLimits_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)GridLimits_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``GridLimits_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)GridLimits_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GridLimits_get_enable_interconnection_limit(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_GridLimits_enable_interconnection_limit_nget, self->data_ptr);
}

static int
GridLimits_set_enable_interconnection_limit(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_GridLimits_enable_interconnection_limit_nset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_curtailment(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_GridLimits_grid_curtailment_aget, self->data_ptr);
}

static int
GridLimits_set_grid_curtailment(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsamv1_GridLimits_grid_curtailment_aset, self->data_ptr);
}

static PyObject *
GridLimits_get_grid_interconnection_limit_kwac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_GridLimits_grid_interconnection_limit_kwac_nget, self->data_ptr);
}

static int
GridLimits_set_grid_interconnection_limit_kwac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsamv1_GridLimits_grid_interconnection_limit_kwac_nset, self->data_ptr);
}

static PyGetSetDef GridLimits_getset[] = {
{"enable_interconnection_limit", (getter)GridLimits_get_enable_interconnection_limit,(setter)GridLimits_set_enable_interconnection_limit,
	PyDoc_STR("*float*: Enable grid interconnection limit [0/1]\n\n**Info:**\nEnable a grid interconnection limit"),
 	NULL},
{"grid_curtailment", (getter)GridLimits_get_grid_curtailment,(setter)GridLimits_set_grid_curtailment,
	PyDoc_STR("*sequence*: Grid curtailment as energy delivery limit (first year) [MW]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"grid_interconnection_limit_kwac", (getter)GridLimits_get_grid_interconnection_limit_kwac,(setter)GridLimits_set_grid_interconnection_limit_kwac,
	PyDoc_STR("*float*: Grid interconnection limit [kWac]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GridLimits_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.GridLimits",             /*tp_name*/
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
		GridLimits_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GridLimits_getset,          /*tp_getset*/
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
Outputs_new(SAM_Pvsamv1 data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsamv1", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvsamv1", "Outputs")){
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
Outputs_get_ac_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ac_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_lifetime_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ac_lifetime_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_perf_adj_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ac_perf_adj_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_transmission_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ac_transmission_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ac_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ac_wiring_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_airmass(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_airmass_aget, self->data_ptr);
}

static PyObject *
Outputs_get_alb(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_alb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_alb_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_alb_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_battery_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_battery_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_inv_clip_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_inv_clip_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_inv_eff_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_inv_eff_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_inv_pnt_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_inv_pnt_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_inv_pso_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_inv_pso_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_lifetime_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_lifetime_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_loss_ond(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_loss_ond_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_perf_adj_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_perf_adj_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_wiring_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ac_wiring_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ac_wiring_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_bifacial_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_bifacial_electrical_mismatch_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_bifacial_electrical_mismatch_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_bifacial_electrical_mismatch_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_crit_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_crit_load_unmet_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_crit_load_unmet_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_crit_load_unmet_percentage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_battery_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_battery_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_diodes_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_diodes_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_diodes_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_diodes_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_inv_tdc_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_inv_tdc_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_invmppt_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_invmppt_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_lifetime_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_lifetime_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_loss_ond(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_loss_ond_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_mismatch_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_mismatch_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_mismatch_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_module_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_module_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_mppt_clip_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_mppt_clip_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_nameplate_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_nameplate_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_nameplate_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_net(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_net_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_nominal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_nominal_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_optimizer_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_optimizer_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_optimizer_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_optimizer_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_perf_adj_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_perf_adj_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_snow_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_snow_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_tracking_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_tracking_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_tracking_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_wiring_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_dc_wiring_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_dc_wiring_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_export_to_grid_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_annual_export_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_gh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_gh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ground_absorbed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ground_absorbed_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ground_absorbed_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ground_absorbed_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ground_incident(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ground_incident_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_ground_incident_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_ground_incident_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_import_to_grid_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_annual_import_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_inv_cliploss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_inv_cliploss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_inv_pntloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_inv_pntloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_inv_psoloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_inv_psoloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_inv_tdcloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_inv_tdcloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_outage_losses_unmet_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_beam_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_beam_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_beam_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_beam_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_cover_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_cover_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_front_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_nom_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_direct_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_direct_diffuse_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_gain_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_gain_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_ground_reflected(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_ground_reflected_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_rack_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_rack_shaded_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_row_reflections(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_row_reflections_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_self_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_self_shaded_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_rear_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_rear_soiled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_shaded_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_shaded_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_shaded_soiled_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_shading_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_shading_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_poa_soiling_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_poa_soiling_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_rack_shaded_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_rack_shaded_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_rear_direct_diffuse_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_rear_direct_diffuse_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_rear_ground_reflected_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_rear_ground_reflected_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_rear_row_reflections_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_rear_row_reflections_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_rear_self_shaded_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_rear_self_shaded_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_rear_soiled_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_rear_soiled_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_snow_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray1_dc_diodes_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray1_dc_diodes_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray1_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray1_dc_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray1_dc_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray1_dc_mismatch_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray1_dc_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray1_dc_nameplate_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray1_dc_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray1_dc_tracking_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray1_dc_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray1_dc_wiring_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray2_dc_diodes_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray2_dc_diodes_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray2_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray2_dc_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray2_dc_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray2_dc_mismatch_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray2_dc_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray2_dc_nameplate_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray2_dc_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray2_dc_tracking_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray2_dc_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray2_dc_wiring_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray3_dc_diodes_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray3_dc_diodes_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray3_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray3_dc_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray3_dc_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray3_dc_mismatch_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray3_dc_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray3_dc_nameplate_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray3_dc_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray3_dc_tracking_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray3_dc_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray3_dc_wiring_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray4_dc_diodes_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray4_dc_diodes_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray4_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray4_dc_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray4_dc_mismatch_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray4_dc_mismatch_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray4_dc_nameplate_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray4_dc_nameplate_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray4_dc_tracking_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray4_dc_tracking_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_subarray4_dc_wiring_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_subarray4_dc_wiring_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_total_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_transmission_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_transmission_loss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_transmission_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_transmission_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_xfmr_loss_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_annual_xfmr_loss_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_conversion_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_average_battery_conversion_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_roundtrip_efficiency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_average_battery_roundtrip_efficiency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avg_critical_load(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_avg_critical_load_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_DOD_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD_cycle_average(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_DOD_cycle_average_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_I(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_I_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_SOC(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_SOC_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_annual_charge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_annual_charge_from_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_system(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_annual_charge_from_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_discharge_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_annual_discharge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_annual_energy_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_system_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_annual_energy_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_installed_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_batt_bank_installed_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_replacement(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_bank_replacement_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_capacity_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent_calendar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_capacity_percent_calendar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_capacity_percent_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_thermal_percent(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_capacity_thermal_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_conversion_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_conversion_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cost_to_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_cost_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cycles(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_cycles_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_dispatch_sched(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_batt_dispatch_sched_mget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_power_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_PV_ramp_interval(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_PV_ramp_interval_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_P_pv_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_P_pv_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_battpower(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_battpower_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_battsoc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_battsoc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_curtail(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_curtail_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_energy_to_grid_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_batt_pvs_energy_to_grid_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_energy_to_grid_percent_sam(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_batt_pvs_energy_to_grid_percent_sam_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_forecast_pv_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_forecast_pv_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_outpower(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_outpower_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_batt_pvs_violation_count_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_list(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_pvs_violation_list_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pvs_violation_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_batt_pvs_violation_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q0(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_q0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_q1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_q2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_qmax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmaxI(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_qmaxI_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax_thermal(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_qmax_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_revenue_charge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_clipcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_revenue_clipcharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_revenue_discharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_revenue_gridcharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_revenue_gridcharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_charge_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_batt_system_charge_percent_nget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_inverter_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_to_inverter_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_system_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_to_system_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage_cell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_batt_voltage_cell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_bifacial_electrical_mismatch(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_bifacial_electrical_mismatch_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor_ac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_capacity_factor_ac_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_cdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_crit_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_crit_load_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_degrade_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dc_degrade_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_invmppt_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dc_invmppt_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_lifetime_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dc_lifetime_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dc_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dc_snow_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_df(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_df_aget, self->data_ptr);
}

static PyObject *
Outputs_get_df_calc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_df_calc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dn(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dn_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dn_calc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_dn_calc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_fuelcell_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen_without_battery(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_gen_without_battery_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_gh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gh_calc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_gh_calc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_grid_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power_target(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_grid_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ground_absorbed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ground_absorbed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ground_incident(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_ground_incident_aget, self->data_ptr);
}

static PyObject *
Outputs_get_interconnection_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_interconnection_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cliploss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inv_cliploss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inv_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_pntloss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inv_pntloss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_psoloss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inv_psoloss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_tdcloss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inv_tdcloss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_total_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inv_total_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverterMPPT1_DCVoltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inverterMPPT1_DCVoltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverterMPPT2_DCVoltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inverterMPPT2_DCVoltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverterMPPT3_DCVoltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inverterMPPT3_DCVoltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inverterMPPT4_DCVoltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_inverterMPPT4_DCVoltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_market_sell_rate_series_yr1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_market_sell_rate_series_yr1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_system_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_batt_to_system_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_crit_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_crit_load_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_crit_load_unmet_percentage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_crit_load_unmet_percentage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_interconnection_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_interconnection_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_outage_losses_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_poa_beam_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_poa_beam_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_poa_beam_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_poa_beam_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_poa_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_poa_front_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_poa_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_poa_rear_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_snow_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_system_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_monthly_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_nameplate_dc_rating(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_nameplate_dc_rating_nget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_durations(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_outage_durations_aget, self->data_ptr);
}

static PyObject *
Outputs_get_outage_losses_unmet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_outage_losses_unmet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pdf_of_surviving(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_pdf_of_surviving_aget, self->data_ptr);
}

static PyObject *
Outputs_get_performance_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_performance_ratio_nget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_beam_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_beam_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_beam_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_beam_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_front_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear_direct_diffuse(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_direct_diffuse_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear_ground_reflected(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_ground_reflected_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear_rack_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_rack_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear_row_reflections(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_row_reflections_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear_self_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_self_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_rear_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_rear_soiled_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_poa_shaded_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_poa_shaded_soiled_aget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_resilience_hrs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_avg(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_resilience_hrs_avg_nget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_resilience_hrs_max_nget, self->data_ptr);
}

static PyObject *
Outputs_get_resilience_hrs_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_resilience_hrs_min_nget, self->data_ptr);
}

static PyObject *
Outputs_get_shadedb_subarray1_shade_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_shadedb_subarray1_shade_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shadedb_subarray2_shade_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_shadedb_subarray2_shade_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shadedb_subarray3_shade_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_shadedb_subarray3_shade_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_shadedb_subarray4_shade_frac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_shadedb_subarray4_shade_frac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sixpar_Adj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_sixpar_Adj_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sixpar_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_sixpar_Il_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sixpar_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_sixpar_Io_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sixpar_Rs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_sixpar_Rs_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sixpar_Rsh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_sixpar_Rsh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_sixpar_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_sixpar_a_nget, self->data_ptr);
}

static PyObject *
Outputs_get_snowdepth(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_snowdepth_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sol_alt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_sol_alt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sol_azi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_sol_azi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sol_zen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_sol_zen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_aoi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_aoi_modifier(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_aoi_modifier_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_axisrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_axisrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_beam_shading_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_beam_shading_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_celltemp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_celltemp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_celltempSS(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_celltempSS_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_dc_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_dc_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_dc_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_dcloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_subarray1_dcloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_ground_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray1_ground_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_idealrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_idealrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_isc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_isc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_linear_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_linear_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_modeff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_modeff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_eff_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_eff_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_eff_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_eff_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_front_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_rear_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray1_poa_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_poa_shaded_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_poa_shaded_soiled_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_snow_coverage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_snow_coverage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_snow_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_soiling_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_soiling_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_ss_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_ss_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_ss_diffuse_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_ss_diffuse_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_ss_reflected_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_ss_reflected_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_surf_azi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_surf_azi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_surf_tilt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray1_voc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray1_voc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_aoi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_aoi_modifier(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_aoi_modifier_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_axisrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_axisrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_beam_shading_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_beam_shading_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_celltemp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_celltemp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_celltempSS(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_celltempSS_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_dc_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_dc_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_dc_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_dcloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_subarray2_dcloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_ground_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray2_ground_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_idealrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_idealrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_isc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_isc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_linear_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_linear_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_modeff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_modeff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_eff_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_eff_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_eff_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_eff_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_front_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_rear_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray2_poa_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_poa_shaded_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_poa_shaded_soiled_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_snow_coverage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_snow_coverage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_snow_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_soiling_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_soiling_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_ss_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_ss_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_ss_diffuse_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_ss_diffuse_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_ss_reflected_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_ss_reflected_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_surf_azi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_surf_azi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_surf_tilt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray2_voc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray2_voc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_aoi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_aoi_modifier(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_aoi_modifier_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_axisrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_axisrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_beam_shading_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_beam_shading_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_celltemp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_celltemp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_celltempSS(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_celltempSS_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_dc_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_dc_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_dc_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_dcloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_subarray3_dcloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_ground_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray3_ground_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_idealrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_idealrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_isc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_isc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_linear_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_linear_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_modeff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_modeff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_eff_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_eff_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_eff_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_eff_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_front_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_rear_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray3_poa_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_poa_shaded_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_poa_shaded_soiled_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_snow_coverage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_snow_coverage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_snow_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_soiling_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_soiling_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_ss_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_ss_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_ss_diffuse_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_ss_diffuse_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_ss_reflected_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_ss_reflected_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_surf_azi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_surf_azi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_surf_tilt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray3_voc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray3_voc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_aoi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_aoi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_aoi_modifier(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_aoi_modifier_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_axisrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_axisrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_beam_shading_factor(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_beam_shading_factor_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_celltemp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_celltemp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_celltempSS(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_celltempSS_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_dc_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_dc_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_dc_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_dc_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_dcloss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_subarray4_dcloss_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_ground_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray4_ground_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_idealrot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_idealrot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_isc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_isc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_linear_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_linear_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_modeff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_modeff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_eff_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_eff_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_eff_diff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_eff_diff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_front(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_front_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_nom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_nom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_rear(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_rear_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_rear_spatial(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Pvsamv1_Outputs_subarray4_poa_rear_spatial_mget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_shaded(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_shaded_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_poa_shaded_soiled(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_poa_shaded_soiled_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_snow_coverage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_snow_coverage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_snow_loss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_snow_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_soiling_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_soiling_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_ss_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_ss_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_ss_diffuse_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_ss_diffuse_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_ss_reflected_derate(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_ss_reflected_derate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_surf_azi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_surf_azi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_surf_tilt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_subarray4_voc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_subarray4_voc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sunpos_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_sunpos_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_sunup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_sunup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_survival_function(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_survival_function_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_batt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_system_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_batt_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_system_to_batt_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_grid(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_system_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_to_load(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_system_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ts_shift_hours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_ts_shift_hours_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tz(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_tz_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wfpoa(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_wfpoa_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_wspd_aget, self->data_ptr);
}

static PyObject *
Outputs_get_xfmr_ll_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_xfmr_ll_ts_aget, self->data_ptr);
}

static PyObject *
Outputs_get_xfmr_ll_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_xfmr_ll_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_xfmr_loss_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_xfmr_loss_ts_aget, self->data_ptr);
}

static PyObject *
Outputs_get_xfmr_loss_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_xfmr_loss_year1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_xfmr_nll_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsamv1_Outputs_xfmr_nll_ts_aget, self->data_ptr);
}

static PyObject *
Outputs_get_xfmr_nll_year1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsamv1_Outputs_xfmr_nll_year1_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac_gross", (getter)Outputs_get_ac_gross,(setter)0,
	PyDoc_STR("*sequence*: Inverter AC output power [kW]"),
 	NULL},
{"ac_lifetime_loss", (getter)Outputs_get_ac_lifetime_loss,(setter)0,
	PyDoc_STR("*sequence*: AC lifetime daily loss [kW]"),
 	NULL},
{"ac_perf_adj_loss", (getter)Outputs_get_ac_perf_adj_loss,(setter)0,
	PyDoc_STR("*sequence*: AC performance adjustment loss [kW]"),
 	NULL},
{"ac_transmission_loss", (getter)Outputs_get_ac_transmission_loss,(setter)0,
	PyDoc_STR("*sequence*: Transmission loss [kW]"),
 	NULL},
{"ac_wiring_loss", (getter)Outputs_get_ac_wiring_loss,(setter)0,
	PyDoc_STR("*sequence*: AC wiring loss [kW]"),
 	NULL},
{"airmass", (getter)Outputs_get_airmass,(setter)0,
	PyDoc_STR("*sequence*: Absolute air mass"),
 	NULL},
{"alb", (getter)Outputs_get_alb,(setter)0,
	PyDoc_STR("*sequence*: Albedo"),
 	NULL},
{"alb_spatial", (getter)Outputs_get_alb_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Albedo spatial"),
 	NULL},
{"annual_ac_battery_loss_percent", (getter)Outputs_get_annual_ac_battery_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC-connected battery loss - year 1 [%]"),
 	NULL},
{"annual_ac_gross", (getter)Outputs_get_annual_ac_gross,(setter)0,
	PyDoc_STR("*float*: Annual AC energy gross [kWh/yr]"),
 	NULL},
{"annual_ac_inv_clip_loss_percent", (getter)Outputs_get_annual_ac_inv_clip_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC inverter power clipping loss [%]"),
 	NULL},
{"annual_ac_inv_eff_loss_percent", (getter)Outputs_get_annual_ac_inv_eff_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC inverter efficiency loss [%]"),
 	NULL},
{"annual_ac_inv_pnt_loss_percent", (getter)Outputs_get_annual_ac_inv_pnt_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC inverter night tare loss [%]"),
 	NULL},
{"annual_ac_inv_pso_loss_percent", (getter)Outputs_get_annual_ac_inv_pso_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC inverter power consumption loss [%]"),
 	NULL},
{"annual_ac_lifetime_loss_percent", (getter)Outputs_get_annual_ac_lifetime_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC lifetime daily loss - year 1 [%]"),
 	NULL},
{"annual_ac_loss_ond", (getter)Outputs_get_annual_ac_loss_ond,(setter)0,
	PyDoc_STR("*float*: Annual AC loss OND model [kWh/yr]"),
 	NULL},
{"annual_ac_perf_adj_loss_percent", (getter)Outputs_get_annual_ac_perf_adj_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC performance adjustment loss [%]"),
 	NULL},
{"annual_ac_wiring_loss", (getter)Outputs_get_annual_ac_wiring_loss,(setter)0,
	PyDoc_STR("*float*: AC wiring loss [kWh]"),
 	NULL},
{"annual_ac_wiring_loss_percent", (getter)Outputs_get_annual_ac_wiring_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC wiring loss [%]"),
 	NULL},
{"annual_bifacial_electrical_mismatch", (getter)Outputs_get_annual_bifacial_electrical_mismatch,(setter)0,
	PyDoc_STR("*float*: Bifacial electrical mismatch loss [kWh/yr]"),
 	NULL},
{"annual_bifacial_electrical_mismatch_percent", (getter)Outputs_get_annual_bifacial_electrical_mismatch_percent,(setter)0,
	PyDoc_STR("*float*: Bifacial electrical mismatch loss [%]"),
 	NULL},
{"annual_crit_load", (getter)Outputs_get_annual_crit_load,(setter)0,
	PyDoc_STR("*float*: Critical load energy (year 1) [kWh]"),
 	NULL},
{"annual_crit_load_unmet", (getter)Outputs_get_annual_crit_load_unmet,(setter)0,
	PyDoc_STR("*float*: Critical load energy unmet (year 1) [kWh]"),
 	NULL},
{"annual_crit_load_unmet_percentage", (getter)Outputs_get_annual_crit_load_unmet_percentage,(setter)0,
	PyDoc_STR("*float*: Critical load unmet percentage (year 1) [%]"),
 	NULL},
{"annual_dc_battery_loss_percent", (getter)Outputs_get_annual_dc_battery_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC connected battery loss- year 1 [%]"),
 	NULL},
{"annual_dc_diodes_loss", (getter)Outputs_get_annual_dc_diodes_loss,(setter)0,
	PyDoc_STR("*float*: DC diodes and connections loss [kWh]"),
 	NULL},
{"annual_dc_diodes_loss_percent", (getter)Outputs_get_annual_dc_diodes_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC diodes and connections loss [%]"),
 	NULL},
{"annual_dc_gross", (getter)Outputs_get_annual_dc_gross,(setter)0,
	PyDoc_STR("*float*: Annual DC energy gross [kWh/yr]"),
 	NULL},
{"annual_dc_inv_tdc_loss_percent", (getter)Outputs_get_annual_dc_inv_tdc_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC inverter thermal derate loss [%]"),
 	NULL},
{"annual_dc_invmppt_loss", (getter)Outputs_get_annual_dc_invmppt_loss,(setter)0,
	PyDoc_STR("*float*: Inverter clipping loss DC MPPT voltage limits [kWh/yr]"),
 	NULL},
{"annual_dc_lifetime_loss_percent", (getter)Outputs_get_annual_dc_lifetime_loss_percent,(setter)0,
	PyDoc_STR("*float*: Lifetime daily DC loss- year 1 [%]"),
 	NULL},
{"annual_dc_loss_ond", (getter)Outputs_get_annual_dc_loss_ond,(setter)0,
	PyDoc_STR("*float*: Annual DC loss OND model [kWh/yr]"),
 	NULL},
{"annual_dc_mismatch_loss", (getter)Outputs_get_annual_dc_mismatch_loss,(setter)0,
	PyDoc_STR("*float*: DC mismatch loss [kWh]"),
 	NULL},
{"annual_dc_mismatch_loss_percent", (getter)Outputs_get_annual_dc_mismatch_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC mismatch loss [%]"),
 	NULL},
{"annual_dc_module_loss_percent", (getter)Outputs_get_annual_dc_module_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC module deviation from STC [%]"),
 	NULL},
{"annual_dc_mppt_clip_loss_percent", (getter)Outputs_get_annual_dc_mppt_clip_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC inverter MPPT clipping loss [%]"),
 	NULL},
{"annual_dc_nameplate_loss", (getter)Outputs_get_annual_dc_nameplate_loss,(setter)0,
	PyDoc_STR("*float*: DC nameplate loss [kWh]"),
 	NULL},
{"annual_dc_nameplate_loss_percent", (getter)Outputs_get_annual_dc_nameplate_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC nameplate loss [%]"),
 	NULL},
{"annual_dc_net", (getter)Outputs_get_annual_dc_net,(setter)0,
	PyDoc_STR("*float*: Annual DC energy [kWh/yr]"),
 	NULL},
{"annual_dc_nominal", (getter)Outputs_get_annual_dc_nominal,(setter)0,
	PyDoc_STR("*float*: Annual DC energy nominal [kWh/yr]"),
 	NULL},
{"annual_dc_optimizer_loss", (getter)Outputs_get_annual_dc_optimizer_loss,(setter)0,
	PyDoc_STR("*float*: DC power optimizer loss [kWh]"),
 	NULL},
{"annual_dc_optimizer_loss_percent", (getter)Outputs_get_annual_dc_optimizer_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC power optimizer loss [%]"),
 	NULL},
{"annual_dc_perf_adj_loss_percent", (getter)Outputs_get_annual_dc_perf_adj_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC performance adjustment loss [%]"),
 	NULL},
{"annual_dc_snow_loss_percent", (getter)Outputs_get_annual_dc_snow_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC snow loss [%]"),
 	NULL},
{"annual_dc_tracking_loss", (getter)Outputs_get_annual_dc_tracking_loss,(setter)0,
	PyDoc_STR("*float*: DC tracking loss [kWh]"),
 	NULL},
{"annual_dc_tracking_loss_percent", (getter)Outputs_get_annual_dc_tracking_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC tracking loss [%]"),
 	NULL},
{"annual_dc_wiring_loss", (getter)Outputs_get_annual_dc_wiring_loss,(setter)0,
	PyDoc_STR("*float*: DC wiring loss [kWh]"),
 	NULL},
{"annual_dc_wiring_loss_percent", (getter)Outputs_get_annual_dc_wiring_loss_percent,(setter)0,
	PyDoc_STR("*float*: DC wiring loss [%]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual AC energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_export_to_grid_energy", (getter)Outputs_get_annual_export_to_grid_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy exported to grid [kWh]"),
 	NULL},
{"annual_gh", (getter)Outputs_get_annual_gh,(setter)0,
	PyDoc_STR("*float*: Annual GHI [Wh/m2/yr]"),
 	NULL},
{"annual_ground_absorbed", (getter)Outputs_get_annual_ground_absorbed,(setter)0,
	PyDoc_STR("*float*: Irradiance absorbed by the ground within the array [kWh/yr]"),
 	NULL},
{"annual_ground_absorbed_percent", (getter)Outputs_get_annual_ground_absorbed_percent,(setter)0,
	PyDoc_STR("*float*: Ground absorbed loss [%]"),
 	NULL},
{"annual_ground_incident", (getter)Outputs_get_annual_ground_incident,(setter)0,
	PyDoc_STR("*float*: Irradiance incident on the ground within the array [kWh/yr]"),
 	NULL},
{"annual_ground_incident_percent", (getter)Outputs_get_annual_ground_incident_percent,(setter)0,
	PyDoc_STR("*float*: Ground incident gain [%]"),
 	NULL},
{"annual_import_to_grid_energy", (getter)Outputs_get_annual_import_to_grid_energy,(setter)0,
	PyDoc_STR("*sequence*: Annual energy imported from grid [kWh]"),
 	NULL},
{"annual_inv_cliploss", (getter)Outputs_get_annual_inv_cliploss,(setter)0,
	PyDoc_STR("*float*: Inverter clipping loss AC power limit [kWh/yr]"),
 	NULL},
{"annual_inv_pntloss", (getter)Outputs_get_annual_inv_pntloss,(setter)0,
	PyDoc_STR("*float*: Inverter night time loss [kWh/yr]"),
 	NULL},
{"annual_inv_psoloss", (getter)Outputs_get_annual_inv_psoloss,(setter)0,
	PyDoc_STR("*float*: Inverter power consumption loss [kWh/yr]"),
 	NULL},
{"annual_inv_tdcloss", (getter)Outputs_get_annual_inv_tdcloss,(setter)0,
	PyDoc_STR("*float*: Inverter thermal derate DC power loss [kWh/yr]"),
 	NULL},
{"annual_outage_losses_unmet", (getter)Outputs_get_annual_outage_losses_unmet,(setter)0,
	PyDoc_STR("*float*: Battery and system losses unmet energy (year 1) [kWh]"),
 	NULL},
{"annual_poa_beam_eff", (getter)Outputs_get_annual_poa_beam_eff,(setter)0,
	PyDoc_STR("*float*: POA front-side irradiance beam after shading and soiling [kWh/yr]"),
 	NULL},
{"annual_poa_beam_nom", (getter)Outputs_get_annual_poa_beam_nom,(setter)0,
	PyDoc_STR("*float*: POA front-side irradiance beam nominal [kWh/yr]"),
 	NULL},
{"annual_poa_cover_loss_percent", (getter)Outputs_get_annual_poa_cover_loss_percent,(setter)0,
	PyDoc_STR("*float*: POA front-side reflection (IAM) loss [%]"),
 	NULL},
{"annual_poa_eff", (getter)Outputs_get_annual_poa_eff,(setter)0,
	PyDoc_STR("*float*: POA irradiance total after reflection (IAM) [kWh/yr]"),
 	NULL},
{"annual_poa_front", (getter)Outputs_get_annual_poa_front,(setter)0,
	PyDoc_STR("*float*: POA front-side irradiance total after reflection (IAM) [kWh/yr]"),
 	NULL},
{"annual_poa_nom", (getter)Outputs_get_annual_poa_nom,(setter)0,
	PyDoc_STR("*float*: POA front-side irradiance total nominal [kWh/yr]"),
 	NULL},
{"annual_poa_rear", (getter)Outputs_get_annual_poa_rear,(setter)0,
	PyDoc_STR("*float*: POA rear-side irradiance total after reflection (IAM) [kWh/yr]"),
 	NULL},
{"annual_poa_rear_direct_diffuse", (getter)Outputs_get_annual_poa_rear_direct_diffuse,(setter)0,
	PyDoc_STR("*float*: POA rear-side direct and diffuse radiation after reflection (IAM) [kWh/yr]"),
 	NULL},
{"annual_poa_rear_gain_percent", (getter)Outputs_get_annual_poa_rear_gain_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side bifacial gain [%]"),
 	NULL},
{"annual_poa_rear_ground_reflected", (getter)Outputs_get_annual_poa_rear_ground_reflected,(setter)0,
	PyDoc_STR("*float*: POA rear-side radiation reflected from the ground after (IAM) [kWh/yr]"),
 	NULL},
{"annual_poa_rear_rack_shaded", (getter)Outputs_get_annual_poa_rear_rack_shaded,(setter)0,
	PyDoc_STR("*float*: POA blocked by racks [kWh/yr]"),
 	NULL},
{"annual_poa_rear_row_reflections", (getter)Outputs_get_annual_poa_rear_row_reflections,(setter)0,
	PyDoc_STR("*float*: POA rear-side radiation reflected from the rear row after (IAM) [kWh/yr]"),
 	NULL},
{"annual_poa_rear_self_shaded", (getter)Outputs_get_annual_poa_rear_self_shaded,(setter)0,
	PyDoc_STR("*float*: POA blocked by self shading [kWh/yr]"),
 	NULL},
{"annual_poa_rear_soiled", (getter)Outputs_get_annual_poa_rear_soiled,(setter)0,
	PyDoc_STR("*float*: POA blocked by rear soiling [kWh/yr]"),
 	NULL},
{"annual_poa_shaded", (getter)Outputs_get_annual_poa_shaded,(setter)0,
	PyDoc_STR("*float*: POA front-side irradiance total after shading [kWh/yr]"),
 	NULL},
{"annual_poa_shaded_soiled", (getter)Outputs_get_annual_poa_shaded_soiled,(setter)0,
	PyDoc_STR("*float*: POA front-side irradiance total after shading and soiling [kWh/yr]"),
 	NULL},
{"annual_poa_shading_loss_percent", (getter)Outputs_get_annual_poa_shading_loss_percent,(setter)0,
	PyDoc_STR("*float*: POA front-side shading loss [%]"),
 	NULL},
{"annual_poa_soiling_loss_percent", (getter)Outputs_get_annual_poa_soiling_loss_percent,(setter)0,
	PyDoc_STR("*float*: POA front-side soiling loss [%]"),
 	NULL},
{"annual_rack_shaded_percent", (getter)Outputs_get_annual_rack_shaded_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side rack shaded loss [%]"),
 	NULL},
{"annual_rear_direct_diffuse_percent", (getter)Outputs_get_annual_rear_direct_diffuse_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side direct and diffuse gain [%]"),
 	NULL},
{"annual_rear_ground_reflected_percent", (getter)Outputs_get_annual_rear_ground_reflected_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side view factor reflected from ground gain [%]"),
 	NULL},
{"annual_rear_row_reflections_percent", (getter)Outputs_get_annual_rear_row_reflections_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side rear row reflections gain [%]"),
 	NULL},
{"annual_rear_self_shaded_percent", (getter)Outputs_get_annual_rear_self_shaded_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side self shaded loss [%]"),
 	NULL},
{"annual_rear_soiled_percent", (getter)Outputs_get_annual_rear_soiled_percent,(setter)0,
	PyDoc_STR("*float*: POA rear-side soiled loss [%]"),
 	NULL},
{"annual_snow_loss", (getter)Outputs_get_annual_snow_loss,(setter)0,
	PyDoc_STR("*float*: Snow DC energy loss [kWh/yr]"),
 	NULL},
{"annual_subarray1_dc_diodes_loss", (getter)Outputs_get_annual_subarray1_dc_diodes_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 1 DC diodes and connections loss [kWh]"),
 	NULL},
{"annual_subarray1_dc_gross", (getter)Outputs_get_annual_subarray1_dc_gross,(setter)0,
	PyDoc_STR("*float*: Subarray 1 Gross DC energy [kWh]"),
 	NULL},
{"annual_subarray1_dc_mismatch_loss", (getter)Outputs_get_annual_subarray1_dc_mismatch_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 1 DC mismatch loss [kWh]"),
 	NULL},
{"annual_subarray1_dc_nameplate_loss", (getter)Outputs_get_annual_subarray1_dc_nameplate_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 1 DC nameplate loss [kWh]"),
 	NULL},
{"annual_subarray1_dc_tracking_loss", (getter)Outputs_get_annual_subarray1_dc_tracking_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 1 DC tracking loss [kWh]"),
 	NULL},
{"annual_subarray1_dc_wiring_loss", (getter)Outputs_get_annual_subarray1_dc_wiring_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 1 DC wiring loss [kWh]"),
 	NULL},
{"annual_subarray2_dc_diodes_loss", (getter)Outputs_get_annual_subarray2_dc_diodes_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 2 DC diodes and connections loss [kWh]"),
 	NULL},
{"annual_subarray2_dc_gross", (getter)Outputs_get_annual_subarray2_dc_gross,(setter)0,
	PyDoc_STR("*float*: Subarray 2 Gross DC energy [kWh]"),
 	NULL},
{"annual_subarray2_dc_mismatch_loss", (getter)Outputs_get_annual_subarray2_dc_mismatch_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 2 DC mismatch loss [kWh]"),
 	NULL},
{"annual_subarray2_dc_nameplate_loss", (getter)Outputs_get_annual_subarray2_dc_nameplate_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 2 DC nameplate loss [kWh]"),
 	NULL},
{"annual_subarray2_dc_tracking_loss", (getter)Outputs_get_annual_subarray2_dc_tracking_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 2 DC tracking loss [kWh]"),
 	NULL},
{"annual_subarray2_dc_wiring_loss", (getter)Outputs_get_annual_subarray2_dc_wiring_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 2 DC wiring loss [kWh]"),
 	NULL},
{"annual_subarray3_dc_diodes_loss", (getter)Outputs_get_annual_subarray3_dc_diodes_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 3 DC diodes and connections loss [kWh]"),
 	NULL},
{"annual_subarray3_dc_gross", (getter)Outputs_get_annual_subarray3_dc_gross,(setter)0,
	PyDoc_STR("*float*: Subarray 3 Gross DC energy [kWh]"),
 	NULL},
{"annual_subarray3_dc_mismatch_loss", (getter)Outputs_get_annual_subarray3_dc_mismatch_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 3 DC mismatch loss [kWh]"),
 	NULL},
{"annual_subarray3_dc_nameplate_loss", (getter)Outputs_get_annual_subarray3_dc_nameplate_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 3 DC nameplate loss [kWh]"),
 	NULL},
{"annual_subarray3_dc_tracking_loss", (getter)Outputs_get_annual_subarray3_dc_tracking_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 3 DC tracking loss [kWh]"),
 	NULL},
{"annual_subarray3_dc_wiring_loss", (getter)Outputs_get_annual_subarray3_dc_wiring_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 3 DC wiring loss [kWh]"),
 	NULL},
{"annual_subarray4_dc_diodes_loss", (getter)Outputs_get_annual_subarray4_dc_diodes_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 4 DC diodes and connections loss [kWh]"),
 	NULL},
{"annual_subarray4_dc_gross", (getter)Outputs_get_annual_subarray4_dc_gross,(setter)0,
	PyDoc_STR("*float*: Subarray 4 Gross DC energy [kWh]"),
 	NULL},
{"annual_subarray4_dc_mismatch_loss", (getter)Outputs_get_annual_subarray4_dc_mismatch_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 4 DC mismatch loss [kWh]"),
 	NULL},
{"annual_subarray4_dc_nameplate_loss", (getter)Outputs_get_annual_subarray4_dc_nameplate_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 4 DC nameplate loss [kWh]"),
 	NULL},
{"annual_subarray4_dc_tracking_loss", (getter)Outputs_get_annual_subarray4_dc_tracking_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 4 DC tracking loss [kWh]"),
 	NULL},
{"annual_subarray4_dc_wiring_loss", (getter)Outputs_get_annual_subarray4_dc_wiring_loss,(setter)0,
	PyDoc_STR("*float*: Subarray 4 DC wiring loss [kWh]"),
 	NULL},
{"annual_total_loss_percent", (getter)Outputs_get_annual_total_loss_percent,(setter)0,
	PyDoc_STR("*float*: Total loss from nominal POA to net AC [%]"),
 	NULL},
{"annual_transmission_loss", (getter)Outputs_get_annual_transmission_loss,(setter)0,
	PyDoc_STR("*float*: Transmission loss [kWh]"),
 	NULL},
{"annual_transmission_loss_percent", (getter)Outputs_get_annual_transmission_loss_percent,(setter)0,
	PyDoc_STR("*float*: AC transmission loss [%]"),
 	NULL},
{"annual_xfmr_loss_percent", (getter)Outputs_get_annual_xfmr_loss_percent,(setter)0,
	PyDoc_STR("*float*: Transformer loss percent [%]"),
 	NULL},
{"average_battery_conversion_efficiency", (getter)Outputs_get_average_battery_conversion_efficiency,(setter)0,
	PyDoc_STR("*float*: Battery average cycle conversion efficiency [%]"),
 	NULL},
{"average_battery_roundtrip_efficiency", (getter)Outputs_get_average_battery_roundtrip_efficiency,(setter)0,
	PyDoc_STR("*float*: Battery average roundtrip efficiency [%]"),
 	NULL},
{"avg_critical_load", (getter)Outputs_get_avg_critical_load,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage critical load met [kWh]"),
 	NULL},
{"batt_DOD", (getter)Outputs_get_batt_DOD,(setter)0,
	PyDoc_STR("*sequence*: Battery cycle depth of discharge [%]"),
 	NULL},
{"batt_DOD_cycle_average", (getter)Outputs_get_batt_DOD_cycle_average,(setter)0,
	PyDoc_STR("*sequence*: Battery average cycle DOD"),
 	NULL},
{"batt_I", (getter)Outputs_get_batt_I,(setter)0,
	PyDoc_STR("*sequence*: Battery current [A]"),
 	NULL},
{"batt_SOC", (getter)Outputs_get_batt_SOC,(setter)0,
	PyDoc_STR("*sequence*: Battery state of charge [%]"),
 	NULL},
{"batt_annual_charge_energy", (getter)Outputs_get_batt_annual_charge_energy,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged [kWh]"),
 	NULL},
{"batt_annual_charge_from_grid", (getter)Outputs_get_batt_annual_charge_from_grid,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged from grid [kWh]"),
 	NULL},
{"batt_annual_charge_from_system", (getter)Outputs_get_batt_annual_charge_from_system,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy charged from system [kWh]"),
 	NULL},
{"batt_annual_discharge_energy", (getter)Outputs_get_batt_annual_discharge_energy,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy discharged [kWh]"),
 	NULL},
{"batt_annual_energy_loss", (getter)Outputs_get_batt_annual_energy_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery annual energy loss [kWh]"),
 	NULL},
{"batt_annual_energy_system_loss", (getter)Outputs_get_batt_annual_energy_system_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery annual system energy loss [kWh]"),
 	NULL},
{"batt_bank_installed_capacity", (getter)Outputs_get_batt_bank_installed_capacity,(setter)0,
	PyDoc_STR("*float*: Battery bank installed capacity [kWh]"),
 	NULL},
{"batt_bank_replacement", (getter)Outputs_get_batt_bank_replacement,(setter)0,
	PyDoc_STR("*sequence*: Battery bank replacements per year [number/year]"),
 	NULL},
{"batt_capacity_percent", (getter)Outputs_get_batt_capacity_percent,(setter)0,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate [%]"),
 	NULL},
{"batt_capacity_percent_calendar", (getter)Outputs_get_batt_capacity_percent_calendar,(setter)0,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate (calendar) [%]"),
 	NULL},
{"batt_capacity_percent_cycle", (getter)Outputs_get_batt_capacity_percent_cycle,(setter)0,
	PyDoc_STR("*sequence*: Battery relative capacity to nameplate (cycling) [%]"),
 	NULL},
{"batt_capacity_thermal_percent", (getter)Outputs_get_batt_capacity_thermal_percent,(setter)0,
	PyDoc_STR("*sequence*: Battery capacity percent for temperature [%]"),
 	NULL},
{"batt_conversion_loss", (getter)Outputs_get_batt_conversion_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery loss from power electronics [kW]"),
 	NULL},
{"batt_cost_to_cycle", (getter)Outputs_get_batt_cost_to_cycle,(setter)0,
	PyDoc_STR("*sequence*: Battery computed cycle degradation penalty [$/cycle-kWh]"),
 	NULL},
{"batt_cycles", (getter)Outputs_get_batt_cycles,(setter)0,
	PyDoc_STR("*sequence*: Battery number of cycles"),
 	NULL},
{"batt_dispatch_sched", (getter)Outputs_get_batt_dispatch_sched,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Battery dispatch schedule"),
 	NULL},
{"batt_power", (getter)Outputs_get_batt_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from battery AC [kW]"),
 	NULL},
{"batt_power_dc", (getter)Outputs_get_batt_power_dc,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from battery DC [kW]"),
 	NULL},
{"batt_power_target", (getter)Outputs_get_batt_power_target,(setter)0,
	PyDoc_STR("*sequence*: Electricity battery power target for automated dispatch [kW]"),
 	NULL},
{"batt_pvs_PV_ramp_interval", (getter)Outputs_get_batt_pvs_PV_ramp_interval,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing PV power sampled [kW]"),
 	NULL},
{"batt_pvs_P_pv_ac", (getter)Outputs_get_batt_pvs_P_pv_ac,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing PV power before smoothing [kW]"),
 	NULL},
{"batt_pvs_battpower", (getter)Outputs_get_batt_pvs_battpower,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing battpower [kW]"),
 	NULL},
{"batt_pvs_battsoc", (getter)Outputs_get_batt_pvs_battsoc,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing battery SOC [%]"),
 	NULL},
{"batt_pvs_curtail", (getter)Outputs_get_batt_pvs_curtail,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing curtailed power [kW]"),
 	NULL},
{"batt_pvs_energy_to_grid_percent", (getter)Outputs_get_batt_pvs_energy_to_grid_percent,(setter)0,
	PyDoc_STR("*float*: PV smoothing energy to grid percent (loss due to curtail and battery loss) [%]"),
 	NULL},
{"batt_pvs_energy_to_grid_percent_sam", (getter)Outputs_get_batt_pvs_energy_to_grid_percent_sam,(setter)0,
	PyDoc_STR("*float*: PV smoothing energy to grid percent actual (loss due to curtail and battery loss) [%]"),
 	NULL},
{"batt_pvs_forecast_pv_energy", (getter)Outputs_get_batt_pvs_forecast_pv_energy,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing PV power forecast [kW]"),
 	NULL},
{"batt_pvs_outpower", (getter)Outputs_get_batt_pvs_outpower,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing outpower [kW]"),
 	NULL},
{"batt_pvs_violation_count", (getter)Outputs_get_batt_pvs_violation_count,(setter)0,
	PyDoc_STR("*float*: PV smoothing violation count"),
 	NULL},
{"batt_pvs_violation_list", (getter)Outputs_get_batt_pvs_violation_list,(setter)0,
	PyDoc_STR("*sequence*: PV smoothing violation"),
 	NULL},
{"batt_pvs_violation_percent", (getter)Outputs_get_batt_pvs_violation_percent,(setter)0,
	PyDoc_STR("*float*: PV smoothing violation percent (of all intervals-including nighttime) [%]"),
 	NULL},
{"batt_q0", (getter)Outputs_get_batt_q0,(setter)0,
	PyDoc_STR("*sequence*: Battery total charge [Ah]"),
 	NULL},
{"batt_q1", (getter)Outputs_get_batt_q1,(setter)0,
	PyDoc_STR("*sequence*: Battery available charge [Ah]"),
 	NULL},
{"batt_q2", (getter)Outputs_get_batt_q2,(setter)0,
	PyDoc_STR("*sequence*: Battery bound charge [Ah]"),
 	NULL},
{"batt_qmax", (getter)Outputs_get_batt_qmax,(setter)0,
	PyDoc_STR("*sequence*: Battery maximum charge with degradation [Ah]"),
 	NULL},
{"batt_qmaxI", (getter)Outputs_get_batt_qmaxI,(setter)0,
	PyDoc_STR("*sequence*: Battery maximum capacity at current [Ah]"),
 	NULL},
{"batt_qmax_thermal", (getter)Outputs_get_batt_qmax_thermal,(setter)0,
	PyDoc_STR("*sequence*: Battery maximum charge at temperature [Ah]"),
 	NULL},
{"batt_revenue_charge", (getter)Outputs_get_batt_revenue_charge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to charge from system [$/kWh]"),
 	NULL},
{"batt_revenue_clipcharge", (getter)Outputs_get_batt_revenue_clipcharge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to charge from clipped [$/kWh]"),
 	NULL},
{"batt_revenue_discharge", (getter)Outputs_get_batt_revenue_discharge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to discharge [$/kWh]"),
 	NULL},
{"batt_revenue_gridcharge", (getter)Outputs_get_batt_revenue_gridcharge,(setter)0,
	PyDoc_STR("*sequence*: Revenue to charge from grid [$/kWh]"),
 	NULL},
{"batt_system_charge_percent", (getter)Outputs_get_batt_system_charge_percent,(setter)0,
	PyDoc_STR("*float*: Battery charge energy charged from system [%]"),
 	NULL},
{"batt_system_loss", (getter)Outputs_get_batt_system_loss,(setter)0,
	PyDoc_STR("*sequence*: Battery loss from ancillary equipment [kW]"),
 	NULL},
{"batt_temperature", (getter)Outputs_get_batt_temperature,(setter)0,
	PyDoc_STR("*sequence*: Battery temperature [C]"),
 	NULL},
{"batt_to_grid", (getter)Outputs_get_batt_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from battery AC [kW]"),
 	NULL},
{"batt_to_inverter_dc", (getter)Outputs_get_batt_to_inverter_dc,(setter)0,
	PyDoc_STR("*sequence*: Electricity to inverter from battery DC [kW]"),
 	NULL},
{"batt_to_load", (getter)Outputs_get_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from battery AC [kW]"),
 	NULL},
{"batt_to_system_load", (getter)Outputs_get_batt_to_system_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to system loads from battery AC [kW]"),
 	NULL},
{"batt_voltage", (getter)Outputs_get_batt_voltage,(setter)0,
	PyDoc_STR("*sequence*: Battery voltage [V]"),
 	NULL},
{"batt_voltage_cell", (getter)Outputs_get_batt_voltage_cell,(setter)0,
	PyDoc_STR("*sequence*: Battery cell voltage [V]"),
 	NULL},
{"bifacial_electrical_mismatch", (getter)Outputs_get_bifacial_electrical_mismatch,(setter)0,
	PyDoc_STR("*sequence*: Array bifacial electrical mismatch loss [kW]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on nameplate DC capacity [%]"),
 	NULL},
{"capacity_factor_ac", (getter)Outputs_get_capacity_factor_ac,(setter)0,
	PyDoc_STR("*float*: Capacity factor based on total AC capacity [%]"),
 	NULL},
{"cdf_of_surviving", (getter)Outputs_get_cdf_of_surviving,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage cumulative probabilities"),
 	NULL},
{"crit_load", (getter)Outputs_get_crit_load,(setter)0,
	PyDoc_STR("*sequence*: Critical load in this timestep [kW]"),
 	NULL},
{"crit_load_unmet", (getter)Outputs_get_crit_load_unmet,(setter)0,
	PyDoc_STR("*sequence*: Critical load unmet in this timestep [kW]"),
 	NULL},
{"dc_degrade_factor", (getter)Outputs_get_dc_degrade_factor,(setter)0,
	PyDoc_STR("*sequence*: Annual DC degradation factor"),
 	NULL},
{"dc_invmppt_loss", (getter)Outputs_get_dc_invmppt_loss,(setter)0,
	PyDoc_STR("*sequence*: Inverter clipping loss DC MPPT voltage limits [kW]"),
 	NULL},
{"dc_lifetime_loss", (getter)Outputs_get_dc_lifetime_loss,(setter)0,
	PyDoc_STR("*sequence*: DC lifetime daily loss [kW]"),
 	NULL},
{"dc_net", (getter)Outputs_get_dc_net,(setter)0,
	PyDoc_STR("*sequence*: Inverter DC input power [kW]"),
 	NULL},
{"dc_snow_loss", (getter)Outputs_get_dc_snow_loss,(setter)0,
	PyDoc_STR("*sequence*: DC power loss due to snow [kW]"),
 	NULL},
{"df", (getter)Outputs_get_df,(setter)0,
	PyDoc_STR("*sequence*: Irradiance DHI from weather file [W/m2]"),
 	NULL},
{"df_calc", (getter)Outputs_get_df_calc,(setter)0,
	PyDoc_STR("*sequence*: Irradiance DHI calculated [W/m2]"),
 	NULL},
{"dn", (getter)Outputs_get_dn,(setter)0,
	PyDoc_STR("*sequence*: Irradiance DNI from weather file [W/m2]"),
 	NULL},
{"dn_calc", (getter)Outputs_get_dn_calc,(setter)0,
	PyDoc_STR("*sequence*: Irradiance DNI calculated [W/m2]"),
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	PyDoc_STR("*float*: Site elevation from weather file [m]"),
 	NULL},
{"fuelcell_to_batt", (getter)Outputs_get_fuelcell_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from fuel cell AC [kW]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"gen_without_battery", (getter)Outputs_get_gen_without_battery,(setter)0,
	PyDoc_STR("*sequence*: Power produced without the battery or curtailment [kW]"),
 	NULL},
{"gh", (getter)Outputs_get_gh,(setter)0,
	PyDoc_STR("*sequence*: Irradiance GHI from weather file [W/m2]"),
 	NULL},
{"gh_calc", (getter)Outputs_get_gh_calc,(setter)0,
	PyDoc_STR("*sequence*: Irradiance GHI calculated [W/m2]"),
 	NULL},
{"grid_power", (getter)Outputs_get_grid_power,(setter)0,
	PyDoc_STR("*sequence*: Electricity to/from grid AC [kW]"),
 	NULL},
{"grid_power_target", (getter)Outputs_get_grid_power_target,(setter)0,
	PyDoc_STR("*sequence*: Electricity grid power target for automated dispatch [kW]"),
 	NULL},
{"grid_to_batt", (getter)Outputs_get_grid_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from grid AC [kW]"),
 	NULL},
{"grid_to_load", (getter)Outputs_get_grid_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from grid AC [kW]"),
 	NULL},
{"ground_absorbed", (getter)Outputs_get_ground_absorbed,(setter)0,
	PyDoc_STR("*sequence*: Irradiance absorbed by the ground within the array [kW]"),
 	NULL},
{"ground_incident", (getter)Outputs_get_ground_incident,(setter)0,
	PyDoc_STR("*sequence*: Irradiance incident on the ground within the array [kW]"),
 	NULL},
{"interconnection_loss", (getter)Outputs_get_interconnection_loss,(setter)0,
	PyDoc_STR("*sequence*: Electricity loss due to curtailment interconnection outage [kW]"),
 	NULL},
{"inv_cliploss", (getter)Outputs_get_inv_cliploss,(setter)0,
	PyDoc_STR("*sequence*: Inverter clipping loss AC power limit [kW]"),
 	NULL},
{"inv_eff", (getter)Outputs_get_inv_eff,(setter)0,
	PyDoc_STR("*sequence*: Inverter efficiency [%]"),
 	NULL},
{"inv_pntloss", (getter)Outputs_get_inv_pntloss,(setter)0,
	PyDoc_STR("*sequence*: Inverter night time loss [kW]"),
 	NULL},
{"inv_psoloss", (getter)Outputs_get_inv_psoloss,(setter)0,
	PyDoc_STR("*sequence*: Inverter power consumption loss [kW]"),
 	NULL},
{"inv_tdcloss", (getter)Outputs_get_inv_tdcloss,(setter)0,
	PyDoc_STR("*sequence*: Inverter thermal derate DC power loss [kW]"),
 	NULL},
{"inv_total_loss", (getter)Outputs_get_inv_total_loss,(setter)0,
	PyDoc_STR("*sequence*: Inverter total power loss [kW]"),
 	NULL},
{"inverterMPPT1_DCVoltage", (getter)Outputs_get_inverterMPPT1_DCVoltage,(setter)0,
	PyDoc_STR("*sequence*: Inverter MPPT 1 Nominal DC voltage [V]"),
 	NULL},
{"inverterMPPT2_DCVoltage", (getter)Outputs_get_inverterMPPT2_DCVoltage,(setter)0,
	PyDoc_STR("*sequence*: Inverter MPPT 2 Nominal DC voltage [V]"),
 	NULL},
{"inverterMPPT3_DCVoltage", (getter)Outputs_get_inverterMPPT3_DCVoltage,(setter)0,
	PyDoc_STR("*sequence*: Inverter MPPT 3 Nominal DC voltage [V]"),
 	NULL},
{"inverterMPPT4_DCVoltage", (getter)Outputs_get_inverterMPPT4_DCVoltage,(setter)0,
	PyDoc_STR("*sequence*: Inverter MPPT 4 Nominal DC voltage [V]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: Energy yield [kWh/kW]"),
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude from weather file [degrees]"),
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	PyDoc_STR("*float*: Longitude from weather file [degrees]"),
 	NULL},
{"market_sell_rate_series_yr1", (getter)Outputs_get_market_sell_rate_series_yr1,(setter)0,
	PyDoc_STR("*sequence*: Power price for battery dispatch [$/MWh]"),
 	NULL},
{"monthly_batt_to_grid", (getter)Outputs_get_monthly_batt_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Energy to grid from battery [kWh]"),
 	NULL},
{"monthly_batt_to_load", (getter)Outputs_get_monthly_batt_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from battery [kWh]"),
 	NULL},
{"monthly_batt_to_system_load", (getter)Outputs_get_monthly_batt_to_system_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to system loads from battery [kWh]"),
 	NULL},
{"monthly_crit_load", (getter)Outputs_get_monthly_crit_load,(setter)0,
	PyDoc_STR("*sequence*: Critical load energy [kWh]"),
 	NULL},
{"monthly_crit_load_unmet", (getter)Outputs_get_monthly_crit_load_unmet,(setter)0,
	PyDoc_STR("*sequence*: Critical load energy unmet [kWh]"),
 	NULL},
{"monthly_crit_load_unmet_percentage", (getter)Outputs_get_monthly_crit_load_unmet_percentage,(setter)0,
	PyDoc_STR("*sequence*: Critical load unmet percentage [%]"),
 	NULL},
{"monthly_dc", (getter)Outputs_get_monthly_dc,(setter)0,
	PyDoc_STR("*sequence*: DC energy [kWh/mo]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: AC energy gross [kWh/mo]"),
 	NULL},
{"monthly_grid_to_batt", (getter)Outputs_get_monthly_grid_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Energy to battery from grid [kWh]"),
 	NULL},
{"monthly_grid_to_load", (getter)Outputs_get_monthly_grid_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from grid [kWh]"),
 	NULL},
{"monthly_interconnection_loss", (getter)Outputs_get_monthly_interconnection_loss,(setter)0,
	PyDoc_STR("*sequence*: Energy loss due to curtailment, interconnection, or outage [kWh]"),
 	NULL},
{"monthly_outage_losses_unmet", (getter)Outputs_get_monthly_outage_losses_unmet,(setter)0,
	PyDoc_STR("*sequence*: Battery and system losses unmet energy [kWh]"),
 	NULL},
{"monthly_poa_beam_eff", (getter)Outputs_get_monthly_poa_beam_eff,(setter)0,
	PyDoc_STR("*sequence*: POA front-side irradiance beam after shading and soiling [kWh/mo]"),
 	NULL},
{"monthly_poa_beam_nom", (getter)Outputs_get_monthly_poa_beam_nom,(setter)0,
	PyDoc_STR("*sequence*: POA front-side irradiance beam nominal [kWh/mo]"),
 	NULL},
{"monthly_poa_eff", (getter)Outputs_get_monthly_poa_eff,(setter)0,
	PyDoc_STR("*sequence*: POA irradiance total after shading and soiling [kWh/mo]"),
 	NULL},
{"monthly_poa_front", (getter)Outputs_get_monthly_poa_front,(setter)0,
	PyDoc_STR("*sequence*: POA front-side irradiance total [kWh/mo]"),
 	NULL},
{"monthly_poa_nom", (getter)Outputs_get_monthly_poa_nom,(setter)0,
	PyDoc_STR("*sequence*: POA front-side irradiance total nominal [kWh/mo]"),
 	NULL},
{"monthly_poa_rear", (getter)Outputs_get_monthly_poa_rear,(setter)0,
	PyDoc_STR("*sequence*: POA rear-side irradiance total [kWh/mo]"),
 	NULL},
{"monthly_snow_loss", (getter)Outputs_get_monthly_snow_loss,(setter)0,
	PyDoc_STR("*sequence*: Snow DC energy loss [kWh/mo]"),
 	NULL},
{"monthly_system_to_batt", (getter)Outputs_get_monthly_system_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Energy to battery from system [kWh]"),
 	NULL},
{"monthly_system_to_grid", (getter)Outputs_get_monthly_system_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Energy to grid from system [kWh]"),
 	NULL},
{"monthly_system_to_load", (getter)Outputs_get_monthly_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Energy to load from system [kWh]"),
 	NULL},
{"nameplate_dc_rating", (getter)Outputs_get_nameplate_dc_rating,(setter)0,
	PyDoc_STR("*float*: System nameplate DC rating [kW]"),
 	NULL},
{"outage_durations", (getter)Outputs_get_outage_durations,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage hour list from min to max [hr]"),
 	NULL},
{"outage_losses_unmet", (getter)Outputs_get_outage_losses_unmet,(setter)0,
	PyDoc_STR("*sequence*: Battery and system losses unmet in this timestep [kW]"),
 	NULL},
{"pdf_of_surviving", (getter)Outputs_get_pdf_of_surviving,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage probabilities"),
 	NULL},
{"performance_ratio", (getter)Outputs_get_performance_ratio,(setter)0,
	PyDoc_STR("*float*: Performance ratio"),
 	NULL},
{"poa_beam_eff", (getter)Outputs_get_poa_beam_eff,(setter)0,
	PyDoc_STR("*sequence*: Array POA beam radiation after shading and soiling [kW]"),
 	NULL},
{"poa_beam_nom", (getter)Outputs_get_poa_beam_nom,(setter)0,
	PyDoc_STR("*sequence*: Array POA front-side beam radiation nominal [kW]"),
 	NULL},
{"poa_eff", (getter)Outputs_get_poa_eff,(setter)0,
	PyDoc_STR("*sequence*: Array POA radiation total after reflection (IAM) [kW]"),
 	NULL},
{"poa_front", (getter)Outputs_get_poa_front,(setter)0,
	PyDoc_STR("*sequence*: Array POA front-side total radiation after reflection (IAM) [kW]"),
 	NULL},
{"poa_nom", (getter)Outputs_get_poa_nom,(setter)0,
	PyDoc_STR("*sequence*: Array POA front-side total radiation nominal [kW]"),
 	NULL},
{"poa_rear", (getter)Outputs_get_poa_rear,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side total radiation after reflection (IAM) [kW]"),
 	NULL},
{"poa_rear_direct_diffuse", (getter)Outputs_get_poa_rear_direct_diffuse,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side direct and diffuse radiation after (IAM) [kW]"),
 	NULL},
{"poa_rear_ground_reflected", (getter)Outputs_get_poa_rear_ground_reflected,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side radiation reflected from the ground after (IAM) [kW]"),
 	NULL},
{"poa_rear_rack_shaded", (getter)Outputs_get_poa_rear_rack_shaded,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side radiation blocked by racks [kW]"),
 	NULL},
{"poa_rear_row_reflections", (getter)Outputs_get_poa_rear_row_reflections,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side radiation reflected from the rear row after (IAM) [kW]"),
 	NULL},
{"poa_rear_self_shaded", (getter)Outputs_get_poa_rear_self_shaded,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side radiation blocked by self shading [kW]"),
 	NULL},
{"poa_rear_soiled", (getter)Outputs_get_poa_rear_soiled,(setter)0,
	PyDoc_STR("*sequence*: Array POA rear-side radiation blocked by rear soiling [kW]"),
 	NULL},
{"poa_shaded", (getter)Outputs_get_poa_shaded,(setter)0,
	PyDoc_STR("*sequence*: Array POA front-side total radiation after shading only [kW]"),
 	NULL},
{"poa_shaded_soiled", (getter)Outputs_get_poa_shaded_soiled,(setter)0,
	PyDoc_STR("*sequence*: Array POA front-side total radiation after shading and soiling [kW]"),
 	NULL},
{"resilience_hrs", (getter)Outputs_get_resilience_hrs,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage at each timestep [hr]"),
 	NULL},
{"resilience_hrs_avg", (getter)Outputs_get_resilience_hrs_avg,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage average [hr]"),
 	NULL},
{"resilience_hrs_max", (getter)Outputs_get_resilience_hrs_max,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage maximum [hr]"),
 	NULL},
{"resilience_hrs_min", (getter)Outputs_get_resilience_hrs_min,(setter)0,
	PyDoc_STR("*float*: Hours of autonomy during grid outage minimum [hr]"),
 	NULL},
{"shadedb_subarray1_shade_frac", (getter)Outputs_get_shadedb_subarray1_shade_frac,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Partial external shading DC factor [frac]"),
 	NULL},
{"shadedb_subarray2_shade_frac", (getter)Outputs_get_shadedb_subarray2_shade_frac,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Partial shading DC factor [frac]"),
 	NULL},
{"shadedb_subarray3_shade_frac", (getter)Outputs_get_shadedb_subarray3_shade_frac,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Partial external shading DC factor [frac]"),
 	NULL},
{"shadedb_subarray4_shade_frac", (getter)Outputs_get_shadedb_subarray4_shade_frac,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Partial external shading DC factor [frac]"),
 	NULL},
{"sixpar_Adj", (getter)Outputs_get_sixpar_Adj,(setter)0,
	PyDoc_STR("*float*: CEC 6-parameter: Adj"),
 	NULL},
{"sixpar_Il", (getter)Outputs_get_sixpar_Il,(setter)0,
	PyDoc_STR("*float*: CEC 6-parameter: Il"),
 	NULL},
{"sixpar_Io", (getter)Outputs_get_sixpar_Io,(setter)0,
	PyDoc_STR("*float*: CEC 6-parameter: Io"),
 	NULL},
{"sixpar_Rs", (getter)Outputs_get_sixpar_Rs,(setter)0,
	PyDoc_STR("*float*: CEC 6-parameter: Rs"),
 	NULL},
{"sixpar_Rsh", (getter)Outputs_get_sixpar_Rsh,(setter)0,
	PyDoc_STR("*float*: CEC 6-parameter: Rsh"),
 	NULL},
{"sixpar_a", (getter)Outputs_get_sixpar_a,(setter)0,
	PyDoc_STR("*float*: CEC 6-parameter: a"),
 	NULL},
{"snowdepth", (getter)Outputs_get_snowdepth,(setter)0,
	PyDoc_STR("*sequence*: Weather file snow depth [cm]"),
 	NULL},
{"sol_alt", (getter)Outputs_get_sol_alt,(setter)0,
	PyDoc_STR("*sequence*: Sun altitude angle [degrees]"),
 	NULL},
{"sol_azi", (getter)Outputs_get_sol_azi,(setter)0,
	PyDoc_STR("*sequence*: Sun azimuth angle [degrees]"),
 	NULL},
{"sol_zen", (getter)Outputs_get_sol_zen,(setter)0,
	PyDoc_STR("*sequence*: Sun zenith angle [degrees]"),
 	NULL},
{"subarray1_aoi", (getter)Outputs_get_subarray1_aoi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Angle of incidence [degrees]"),
 	NULL},
{"subarray1_aoi_modifier", (getter)Outputs_get_subarray1_aoi_modifier,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Angle of incidence Modifier [0-1]"),
 	NULL},
{"subarray1_axisrot", (getter)Outputs_get_subarray1_axisrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Axis rotation for 1 axis trackers [degrees]"),
 	NULL},
{"subarray1_beam_shading_factor", (getter)Outputs_get_subarray1_beam_shading_factor,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 External shading and soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray1_celltemp", (getter)Outputs_get_subarray1_celltemp,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Cell temperature [C]"),
 	NULL},
{"subarray1_celltempSS", (getter)Outputs_get_subarray1_celltempSS,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Cell temperature (steady state) [C]"),
 	NULL},
{"subarray1_dc_gross", (getter)Outputs_get_subarray1_dc_gross,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 DC power gross [kW]"),
 	NULL},
{"subarray1_dc_voltage", (getter)Outputs_get_subarray1_dc_voltage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Operating DC voltage [V]"),
 	NULL},
{"subarray1_dcloss", (getter)Outputs_get_subarray1_dcloss,(setter)0,
	PyDoc_STR("*float*: Subarray 1 Total DC power loss [%]"),
 	NULL},
{"subarray1_ground_rear_spatial", (getter)Outputs_get_subarray1_ground_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 1 spatial irradiance incident on the ground between rows [W/m2]"),
 	NULL},
{"subarray1_idealrot", (getter)Outputs_get_subarray1_idealrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Axis rotation ideal for 1 axis trackers [degrees]"),
 	NULL},
{"subarray1_isc", (getter)Outputs_get_subarray1_isc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 String short circuit DC current [A]"),
 	NULL},
{"subarray1_linear_derate", (getter)Outputs_get_subarray1_linear_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Self-shading linear beam irradiance factor [frac]"),
 	NULL},
{"subarray1_modeff", (getter)Outputs_get_subarray1_modeff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Module efficiency [%]"),
 	NULL},
{"subarray1_poa_eff", (getter)Outputs_get_subarray1_poa_eff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray1_poa_eff_beam", (getter)Outputs_get_subarray1_poa_eff_beam,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA front beam irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray1_poa_eff_diff", (getter)Outputs_get_subarray1_poa_eff_diff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA front diffuse irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray1_poa_front", (getter)Outputs_get_subarray1_poa_front,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA front total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray1_poa_nom", (getter)Outputs_get_subarray1_poa_nom,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA front total irradiance nominal [W/m2]"),
 	NULL},
{"subarray1_poa_rear", (getter)Outputs_get_subarray1_poa_rear,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA rear total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray1_poa_rear_spatial", (getter)Outputs_get_subarray1_poa_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 1 POA spatial rear total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray1_poa_shaded", (getter)Outputs_get_subarray1_poa_shaded,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA front total irradiance after shading only [W/m2]"),
 	NULL},
{"subarray1_poa_shaded_soiled", (getter)Outputs_get_subarray1_poa_shaded_soiled,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 POA front total irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray1_snow_coverage", (getter)Outputs_get_subarray1_snow_coverage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Snow cover [0..1]"),
 	NULL},
{"subarray1_snow_loss", (getter)Outputs_get_subarray1_snow_loss,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Snow cover DC power loss [kW]"),
 	NULL},
{"subarray1_soiling_derate", (getter)Outputs_get_subarray1_soiling_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray1_ss_derate", (getter)Outputs_get_subarray1_ss_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Self-shading non-linear DC factor [frac]"),
 	NULL},
{"subarray1_ss_diffuse_derate", (getter)Outputs_get_subarray1_ss_diffuse_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Self-shading non-linear sky diffuse irradiance factor [frac]"),
 	NULL},
{"subarray1_ss_reflected_derate", (getter)Outputs_get_subarray1_ss_reflected_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Self-shading non-linear ground diffuse irradiance factor [frac]"),
 	NULL},
{"subarray1_surf_azi", (getter)Outputs_get_subarray1_surf_azi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Surface azimuth [degrees]"),
 	NULL},
{"subarray1_surf_tilt", (getter)Outputs_get_subarray1_surf_tilt,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Surface tilt [degrees]"),
 	NULL},
{"subarray1_voc", (getter)Outputs_get_subarray1_voc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 1 Open circuit DC voltage [V]"),
 	NULL},
{"subarray2_aoi", (getter)Outputs_get_subarray2_aoi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Angle of incidence [degrees]"),
 	NULL},
{"subarray2_aoi_modifier", (getter)Outputs_get_subarray2_aoi_modifier,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Angle of incidence Modifier [0-1]"),
 	NULL},
{"subarray2_axisrot", (getter)Outputs_get_subarray2_axisrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Axis rotation for 1 axis trackers [degrees]"),
 	NULL},
{"subarray2_beam_shading_factor", (getter)Outputs_get_subarray2_beam_shading_factor,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 External shading and soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray2_celltemp", (getter)Outputs_get_subarray2_celltemp,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Cell temperature [C]"),
 	NULL},
{"subarray2_celltempSS", (getter)Outputs_get_subarray2_celltempSS,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Cell temperature (steady state) [C]"),
 	NULL},
{"subarray2_dc_gross", (getter)Outputs_get_subarray2_dc_gross,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 DC power gross [kW]"),
 	NULL},
{"subarray2_dc_voltage", (getter)Outputs_get_subarray2_dc_voltage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Operating DC voltage [V]"),
 	NULL},
{"subarray2_dcloss", (getter)Outputs_get_subarray2_dcloss,(setter)0,
	PyDoc_STR("*float*: Subarray 2 Total DC power loss [%]"),
 	NULL},
{"subarray2_ground_rear_spatial", (getter)Outputs_get_subarray2_ground_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 2 spatial irradiance incident on the ground between rows [W/m2]"),
 	NULL},
{"subarray2_idealrot", (getter)Outputs_get_subarray2_idealrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Axis rotation ideal for 1 axis trackers [degrees]"),
 	NULL},
{"subarray2_isc", (getter)Outputs_get_subarray2_isc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 String short circuit DC current [A]"),
 	NULL},
{"subarray2_linear_derate", (getter)Outputs_get_subarray2_linear_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Self-shading linear beam irradiance factor [frac]"),
 	NULL},
{"subarray2_modeff", (getter)Outputs_get_subarray2_modeff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Module efficiency [%]"),
 	NULL},
{"subarray2_poa_eff", (getter)Outputs_get_subarray2_poa_eff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA total irradiance after module reflection (IAM) [W/m2]"),
 	NULL},
{"subarray2_poa_eff_beam", (getter)Outputs_get_subarray2_poa_eff_beam,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA front beam irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray2_poa_eff_diff", (getter)Outputs_get_subarray2_poa_eff_diff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA front diffuse irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray2_poa_front", (getter)Outputs_get_subarray2_poa_front,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA front total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray2_poa_nom", (getter)Outputs_get_subarray2_poa_nom,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA front total irradiance nominal [W/m2]"),
 	NULL},
{"subarray2_poa_rear", (getter)Outputs_get_subarray2_poa_rear,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA rear irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray2_poa_rear_spatial", (getter)Outputs_get_subarray2_poa_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 2 POA spatial rear total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray2_poa_shaded", (getter)Outputs_get_subarray2_poa_shaded,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA front total irradiance after shading only [W/m2]"),
 	NULL},
{"subarray2_poa_shaded_soiled", (getter)Outputs_get_subarray2_poa_shaded_soiled,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 POA front total irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray2_snow_coverage", (getter)Outputs_get_subarray2_snow_coverage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Snow cover [0..1]"),
 	NULL},
{"subarray2_snow_loss", (getter)Outputs_get_subarray2_snow_loss,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Snow cover DC power loss [kW]"),
 	NULL},
{"subarray2_soiling_derate", (getter)Outputs_get_subarray2_soiling_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray2_ss_derate", (getter)Outputs_get_subarray2_ss_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Self-shading non-linear DC factor [frac]"),
 	NULL},
{"subarray2_ss_diffuse_derate", (getter)Outputs_get_subarray2_ss_diffuse_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Self-shading non-linear sky diffuse irradiance factor [frac]"),
 	NULL},
{"subarray2_ss_reflected_derate", (getter)Outputs_get_subarray2_ss_reflected_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Self-shading non-linear ground diffuse irradiance factor [frac]"),
 	NULL},
{"subarray2_surf_azi", (getter)Outputs_get_subarray2_surf_azi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Surface azimuth [degrees]"),
 	NULL},
{"subarray2_surf_tilt", (getter)Outputs_get_subarray2_surf_tilt,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Surface tilt [degrees]"),
 	NULL},
{"subarray2_voc", (getter)Outputs_get_subarray2_voc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 2 Open circuit DC voltage [V]"),
 	NULL},
{"subarray3_aoi", (getter)Outputs_get_subarray3_aoi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Angle of incidence [degrees]"),
 	NULL},
{"subarray3_aoi_modifier", (getter)Outputs_get_subarray3_aoi_modifier,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Angle of incidence Modifier [0-1]"),
 	NULL},
{"subarray3_axisrot", (getter)Outputs_get_subarray3_axisrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Axis rotation for 1 axis trackers [degrees]"),
 	NULL},
{"subarray3_beam_shading_factor", (getter)Outputs_get_subarray3_beam_shading_factor,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 External shading and soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray3_celltemp", (getter)Outputs_get_subarray3_celltemp,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Cell temperature [C]"),
 	NULL},
{"subarray3_celltempSS", (getter)Outputs_get_subarray3_celltempSS,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Cell temperature (steady state) [C]"),
 	NULL},
{"subarray3_dc_gross", (getter)Outputs_get_subarray3_dc_gross,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 DC power gross [kW]"),
 	NULL},
{"subarray3_dc_voltage", (getter)Outputs_get_subarray3_dc_voltage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Operating DC voltage [V]"),
 	NULL},
{"subarray3_dcloss", (getter)Outputs_get_subarray3_dcloss,(setter)0,
	PyDoc_STR("*float*: Subarray 3 Total DC power loss [%]"),
 	NULL},
{"subarray3_ground_rear_spatial", (getter)Outputs_get_subarray3_ground_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 3 spatial irradiance incident on the ground between rows [W/m2]"),
 	NULL},
{"subarray3_idealrot", (getter)Outputs_get_subarray3_idealrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Axis rotation ideal for 1 axis trackers [degrees]"),
 	NULL},
{"subarray3_isc", (getter)Outputs_get_subarray3_isc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 String short circuit DC current [A]"),
 	NULL},
{"subarray3_linear_derate", (getter)Outputs_get_subarray3_linear_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Self-shading linear beam irradiance factor [frac]"),
 	NULL},
{"subarray3_modeff", (getter)Outputs_get_subarray3_modeff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Module efficiency [%]"),
 	NULL},
{"subarray3_poa_eff", (getter)Outputs_get_subarray3_poa_eff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray3_poa_eff_beam", (getter)Outputs_get_subarray3_poa_eff_beam,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA front beam irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray3_poa_eff_diff", (getter)Outputs_get_subarray3_poa_eff_diff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA front diffuse irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray3_poa_front", (getter)Outputs_get_subarray3_poa_front,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA front total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray3_poa_nom", (getter)Outputs_get_subarray3_poa_nom,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA font total irradiance nominal [W/m2]"),
 	NULL},
{"subarray3_poa_rear", (getter)Outputs_get_subarray3_poa_rear,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA rear irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray3_poa_rear_spatial", (getter)Outputs_get_subarray3_poa_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 3 POA spatial rear total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray3_poa_shaded", (getter)Outputs_get_subarray3_poa_shaded,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA front total irradiance after shading only [W/m2]"),
 	NULL},
{"subarray3_poa_shaded_soiled", (getter)Outputs_get_subarray3_poa_shaded_soiled,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 POA front total irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray3_snow_coverage", (getter)Outputs_get_subarray3_snow_coverage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Snow cover [0..1]"),
 	NULL},
{"subarray3_snow_loss", (getter)Outputs_get_subarray3_snow_loss,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Snow cover DC power loss [kW]"),
 	NULL},
{"subarray3_soiling_derate", (getter)Outputs_get_subarray3_soiling_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray3_ss_derate", (getter)Outputs_get_subarray3_ss_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Self-shading non-linear DC factor [frac]"),
 	NULL},
{"subarray3_ss_diffuse_derate", (getter)Outputs_get_subarray3_ss_diffuse_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Self-shading non-linear sky diffuse irradiance factor [frac]"),
 	NULL},
{"subarray3_ss_reflected_derate", (getter)Outputs_get_subarray3_ss_reflected_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Self-shading non-linear ground diffuse irradiance factor [frac]"),
 	NULL},
{"subarray3_surf_azi", (getter)Outputs_get_subarray3_surf_azi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Surface azimuth [degrees]"),
 	NULL},
{"subarray3_surf_tilt", (getter)Outputs_get_subarray3_surf_tilt,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Surface tilt [degrees]"),
 	NULL},
{"subarray3_voc", (getter)Outputs_get_subarray3_voc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 3 Open circuit DC voltage [V]"),
 	NULL},
{"subarray4_aoi", (getter)Outputs_get_subarray4_aoi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Angle of incidence [degrees]"),
 	NULL},
{"subarray4_aoi_modifier", (getter)Outputs_get_subarray4_aoi_modifier,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Angle of incidence Modifier [0-1]"),
 	NULL},
{"subarray4_axisrot", (getter)Outputs_get_subarray4_axisrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Axis rotation for 1 axis trackers [degrees]"),
 	NULL},
{"subarray4_beam_shading_factor", (getter)Outputs_get_subarray4_beam_shading_factor,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 External shading and soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray4_celltemp", (getter)Outputs_get_subarray4_celltemp,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Cell temperature [C]"),
 	NULL},
{"subarray4_celltempSS", (getter)Outputs_get_subarray4_celltempSS,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Cell temperature (steady state) [C]"),
 	NULL},
{"subarray4_dc_gross", (getter)Outputs_get_subarray4_dc_gross,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 DC power gross [kW]"),
 	NULL},
{"subarray4_dc_voltage", (getter)Outputs_get_subarray4_dc_voltage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Operating DC voltage [V]"),
 	NULL},
{"subarray4_dcloss", (getter)Outputs_get_subarray4_dcloss,(setter)0,
	PyDoc_STR("*float*: Subarray 4 Total DC power loss [%]"),
 	NULL},
{"subarray4_ground_rear_spatial", (getter)Outputs_get_subarray4_ground_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 4 spatial irradiance incident on the ground between rows [W/m2]"),
 	NULL},
{"subarray4_idealrot", (getter)Outputs_get_subarray4_idealrot,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Axis rotation ideal for 1 axis trackers [degrees]"),
 	NULL},
{"subarray4_isc", (getter)Outputs_get_subarray4_isc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 String short circuit DC current [A]"),
 	NULL},
{"subarray4_linear_derate", (getter)Outputs_get_subarray4_linear_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Self-shading linear beam irradiance factor [frac]"),
 	NULL},
{"subarray4_modeff", (getter)Outputs_get_subarray4_modeff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Module efficiency [%]"),
 	NULL},
{"subarray4_poa_eff", (getter)Outputs_get_subarray4_poa_eff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray4_poa_eff_beam", (getter)Outputs_get_subarray4_poa_eff_beam,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA front beam irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray4_poa_eff_diff", (getter)Outputs_get_subarray4_poa_eff_diff,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA front diffuse irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray4_poa_front", (getter)Outputs_get_subarray4_poa_front,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA front total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray4_poa_nom", (getter)Outputs_get_subarray4_poa_nom,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA front total irradiance nominal [W/m2]"),
 	NULL},
{"subarray4_poa_rear", (getter)Outputs_get_subarray4_poa_rear,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA rear irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray4_poa_rear_spatial", (getter)Outputs_get_subarray4_poa_rear_spatial,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Subarray 4 POA spatial rear total irradiance after reflection (IAM) [W/m2]"),
 	NULL},
{"subarray4_poa_shaded", (getter)Outputs_get_subarray4_poa_shaded,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA front total irradiance after shading only [W/m2]"),
 	NULL},
{"subarray4_poa_shaded_soiled", (getter)Outputs_get_subarray4_poa_shaded_soiled,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 POA front total irradiance after shading and soiling [W/m2]"),
 	NULL},
{"subarray4_snow_coverage", (getter)Outputs_get_subarray4_snow_coverage,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Snow cover [0..1]"),
 	NULL},
{"subarray4_snow_loss", (getter)Outputs_get_subarray4_snow_loss,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Snow cover DC power loss [kW]"),
 	NULL},
{"subarray4_soiling_derate", (getter)Outputs_get_subarray4_soiling_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Soiling beam irradiance factor [frac]"),
 	NULL},
{"subarray4_ss_derate", (getter)Outputs_get_subarray4_ss_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Self-shading non-linear DC factor [frac]"),
 	NULL},
{"subarray4_ss_diffuse_derate", (getter)Outputs_get_subarray4_ss_diffuse_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Self-shading non-linear sky diffuse irradiance factor [frac]"),
 	NULL},
{"subarray4_ss_reflected_derate", (getter)Outputs_get_subarray4_ss_reflected_derate,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Self-shading non-linear ground diffuse irradiance factor [frac]"),
 	NULL},
{"subarray4_surf_azi", (getter)Outputs_get_subarray4_surf_azi,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Surface azimuth [degrees]"),
 	NULL},
{"subarray4_surf_tilt", (getter)Outputs_get_subarray4_surf_tilt,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Surface tilt [degrees]"),
 	NULL},
{"subarray4_voc", (getter)Outputs_get_subarray4_voc,(setter)0,
	PyDoc_STR("*sequence*: Subarray 4 Open circuit DC voltage [V]"),
 	NULL},
{"sunpos_hour", (getter)Outputs_get_sunpos_hour,(setter)0,
	PyDoc_STR("*sequence*: Sun position time [hour]"),
 	NULL},
{"sunup", (getter)Outputs_get_sunup,(setter)0,
	PyDoc_STR("*sequence*: Sun up over horizon [0/1/2/3]"),
 	NULL},
{"survival_function", (getter)Outputs_get_survival_function,(setter)0,
	PyDoc_STR("*sequence*: Hours of autonomy during grid outage survival function"),
 	NULL},
{"system_to_batt", (getter)Outputs_get_system_to_batt,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from system AC [kW]"),
 	NULL},
{"system_to_batt_dc", (getter)Outputs_get_system_to_batt_dc,(setter)0,
	PyDoc_STR("*sequence*: Electricity to battery from system DC [kW]"),
 	NULL},
{"system_to_grid", (getter)Outputs_get_system_to_grid,(setter)0,
	PyDoc_STR("*sequence*: Electricity to grid from system AC [kW]"),
 	NULL},
{"system_to_load", (getter)Outputs_get_system_to_load,(setter)0,
	PyDoc_STR("*sequence*: Electricity to load from system AC [kW]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Weather file ambient temperature [C]"),
 	NULL},
{"ts_shift_hours", (getter)Outputs_get_ts_shift_hours,(setter)0,
	PyDoc_STR("*float*: Sun position time offset [hours]"),
 	NULL},
{"tz", (getter)Outputs_get_tz,(setter)0,
	PyDoc_STR("*float*: Time zone from weather file [UTC offset]"),
 	NULL},
{"wfpoa", (getter)Outputs_get_wfpoa,(setter)0,
	PyDoc_STR("*sequence*: Irradiance POA from weather file [W/m2]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Weather file wind speed [m/s]"),
 	NULL},
{"xfmr_ll_ts", (getter)Outputs_get_xfmr_ll_ts,(setter)0,
	PyDoc_STR("*sequence*: Transformer load loss [kW]"),
 	NULL},
{"xfmr_ll_year1", (getter)Outputs_get_xfmr_ll_year1,(setter)0,
	PyDoc_STR("*float*: Transformer load loss [kWh/yr]"),
 	NULL},
{"xfmr_loss_ts", (getter)Outputs_get_xfmr_loss_ts,(setter)0,
	PyDoc_STR("*sequence*: Transformer total loss [kW]"),
 	NULL},
{"xfmr_loss_year1", (getter)Outputs_get_xfmr_loss_year1,(setter)0,
	PyDoc_STR("*float*: Transformer total loss [kWh/yr]"),
 	NULL},
{"xfmr_nll_ts", (getter)Outputs_get_xfmr_nll_ts,(setter)0,
	PyDoc_STR("*sequence*: Transformer no load loss [kW]"),
 	NULL},
{"xfmr_nll_year1", (getter)Outputs_get_xfmr_nll_year1,(setter)0,
	PyDoc_STR("*float*: Transformer no load loss [kWh/yr]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1.Outputs",             /*tp_name*/
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
 * Pvsamv1
 */

static PyTypeObject Pvsamv1_Type;

static CmodObject *
newPvsamv1Object(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvsamv1_Type);

	PySAM_TECH_ATTR()

	PyObject* SolarResource_obj = SolarResource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarResource", SolarResource_obj);
	Py_DECREF(SolarResource_obj);

	PyObject* Losses_obj = Losses_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Losses", Losses_obj);
	Py_DECREF(Losses_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* Shading_obj = Shading_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Shading", Shading_obj);
	Py_DECREF(Shading_obj);

	PyObject* Layout_obj = Layout_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Layout", Layout_obj);
	Py_DECREF(Layout_obj);

	PyObject* Module_obj = Module_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Module", Module_obj);
	Py_DECREF(Module_obj);

	PyObject* SimpleEfficiencyModuleModel_obj = SimpleEfficiencyModuleModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SimpleEfficiencyModuleModel", SimpleEfficiencyModuleModel_obj);
	Py_DECREF(SimpleEfficiencyModuleModel_obj);

	PyObject* CECPerformanceModelWithModuleDatabase_obj = CECPerformanceModelWithModuleDatabase_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CECPerformanceModelWithModuleDatabase", CECPerformanceModelWithModuleDatabase_obj);
	Py_DECREF(CECPerformanceModelWithModuleDatabase_obj);

	PyObject* CECPerformanceModelWithUserEnteredSpecifications_obj = CECPerformanceModelWithUserEnteredSpecifications_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CECPerformanceModelWithUserEnteredSpecifications", CECPerformanceModelWithUserEnteredSpecifications_obj);
	Py_DECREF(CECPerformanceModelWithUserEnteredSpecifications_obj);

	PyObject* SandiaPVArrayPerformanceModelWithModuleDatabase_obj = SandiaPVArrayPerformanceModelWithModuleDatabase_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SandiaPVArrayPerformanceModelWithModuleDatabase", SandiaPVArrayPerformanceModelWithModuleDatabase_obj);
	Py_DECREF(SandiaPVArrayPerformanceModelWithModuleDatabase_obj);

	PyObject* IEC61853SingleDiodeModel_obj = IEC61853SingleDiodeModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "IEC61853SingleDiodeModel", IEC61853SingleDiodeModel_obj);
	Py_DECREF(IEC61853SingleDiodeModel_obj);

	PyObject* MermoudLejeuneSingleDiodeModel_obj = MermoudLejeuneSingleDiodeModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "MermoudLejeuneSingleDiodeModel", MermoudLejeuneSingleDiodeModel_obj);
	Py_DECREF(MermoudLejeuneSingleDiodeModel_obj);

	PyObject* Inverter_obj = Inverter_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Inverter", Inverter_obj);
	Py_DECREF(Inverter_obj);

	PyObject* InverterCECDatabase_obj = InverterCECDatabase_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "InverterCECDatabase", InverterCECDatabase_obj);
	Py_DECREF(InverterCECDatabase_obj);

	PyObject* InverterCECCoefficientGenerator_obj = InverterCECCoefficientGenerator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "InverterCECCoefficientGenerator", InverterCECCoefficientGenerator_obj);
	Py_DECREF(InverterCECCoefficientGenerator_obj);

	PyObject* InverterDatasheet_obj = InverterDatasheet_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "InverterDatasheet", InverterDatasheet_obj);
	Py_DECREF(InverterDatasheet_obj);

	PyObject* InverterPartLoadCurve_obj = InverterPartLoadCurve_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "InverterPartLoadCurve", InverterPartLoadCurve_obj);
	Py_DECREF(InverterPartLoadCurve_obj);

	PyObject* InverterMermoudLejeuneModel_obj = InverterMermoudLejeuneModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "InverterMermoudLejeuneModel", InverterMermoudLejeuneModel_obj);
	Py_DECREF(InverterMermoudLejeuneModel_obj);

	PyObject* BatterySystem_obj = BatterySystem_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatterySystem", BatterySystem_obj);
	Py_DECREF(BatterySystem_obj);

	PyObject* Load_obj = Load_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Load", Load_obj);
	Py_DECREF(Load_obj);

	PyObject* BatteryCell_obj = BatteryCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatteryCell", BatteryCell_obj);
	Py_DECREF(BatteryCell_obj);

	PyObject* BatteryDispatch_obj = BatteryDispatch_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatteryDispatch", BatteryDispatch_obj);
	Py_DECREF(BatteryDispatch_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* FuelCell_obj = FuelCell_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FuelCell", FuelCell_obj);
	Py_DECREF(FuelCell_obj);

	PyObject* PriceSignal_obj = PriceSignal_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PriceSignal", PriceSignal_obj);
	Py_DECREF(PriceSignal_obj);

	PyObject* Revenue_obj = Revenue_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Revenue", Revenue_obj);
	Py_DECREF(Revenue_obj);

	PyObject* ElectricityRates_obj = ElectricityRates_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricityRates", ElectricityRates_obj);
	Py_DECREF(ElectricityRates_obj);

	PyObject* GridLimits_obj = GridLimits_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GridLimits", GridLimits_obj);
	Py_DECREF(GridLimits_obj);

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

/* Pvsamv1 methods */

static void
Pvsamv1_dealloc(CmodObject *self)
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
Pvsamv1_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvsamv1_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvsamv1_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvsamv1"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvsamv1_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvsamv1"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvsamv1_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvsamv1_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pvsamv1_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pvsamv1_methods[] = {
		{"execute",           (PyCFunction)Pvsamv1_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvsamv1_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pvsamv1_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvsamv1_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvsamv1_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pvsamv1_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"Reopt_size_battery_post", (PyCFunction)Reopt_size_battery_post, METH_VARARGS | METH_KEYWORDS,
			Reopt_size_battery_post_doc},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvsamv1_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvsamv1_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvsamv1_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsamv1",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvsamv1_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvsamv1_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvsamv1_getattro, /*tp_getattro*/
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
		Pvsamv1_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvsamv1 object */

static PyObject *
Pvsamv1_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvsamv1Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvsamv1_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvsamv1Object((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvsamv1_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvsamv1Object(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvsamv1", def) < 0) {
		Pvsamv1_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pvsamv1_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvsamv1Object((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvsamv1", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvsamv1Module_methods[] = {
		{"new",             Pvsamv1_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvsamv1")},
		{"default",             Pvsamv1_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvsamv1\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"FlatPlatePVAllEquityPartnershipFlip\"*\n\n		- *\"FlatPlatePVCommercial\"*\n\n		- *\"FlatPlatePVHostDeveloper\"*\n\n		- *\"FlatPlatePVLCOECalculator\"*\n\n		- *\"FlatPlatePVLeveragedPartnershipFlip\"*\n\n		- *\"FlatPlatePVMerchantPlant\"*\n\n		- *\"FlatPlatePVNone\"*\n\n		- *\"FlatPlatePVResidential\"*\n\n		- *\"FlatPlatePVSaleLeaseback\"*\n\n		- *\"FlatPlatePVSingleOwner\"*\n\n		- *\"FlatPlatePVThirdParty\"*\n\n		- *\"PVBatteryAllEquityPartnershipFlip\"*\n\n		- *\"PVBatteryCommercial\"*\n\n		- *\"PVBatteryHostDeveloper\"*\n\n		- *\"PVBatteryLeveragedPartnershipFlip\"*\n\n		- *\"PVBatteryMerchantPlant\"*\n\n		- *\"PVBatteryResidential\"*\n\n		- *\"PVBatterySaleLeaseback\"*\n\n		- *\"PVBatterySingleOwner\"*\n\n		- *\"PVBatteryThirdParty\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pvsamv1_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvsamv1\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pvsamv1_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvsamv1\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Detailed photovoltaic system model with separate components for module and inverter");


static int
Pvsamv1Module_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvsamv1_Type.tp_dict = PyDict_New();
	if (!Pvsamv1_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Pvsamv1_Type
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
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the SolarResource type object to Pvsamv1_Type
	if (PyType_Ready(&SolarResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"SolarResource",
				(PyObject*)&SolarResource_Type);
	Py_DECREF(&SolarResource_Type);

	/// Add the Losses type object to Pvsamv1_Type
	if (PyType_Ready(&Losses_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Losses",
				(PyObject*)&Losses_Type);
	Py_DECREF(&Losses_Type);

	/// Add the Lifetime type object to Pvsamv1_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the SystemDesign type object to Pvsamv1_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the Shading type object to Pvsamv1_Type
	if (PyType_Ready(&Shading_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Shading",
				(PyObject*)&Shading_Type);
	Py_DECREF(&Shading_Type);

	/// Add the Layout type object to Pvsamv1_Type
	if (PyType_Ready(&Layout_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Layout",
				(PyObject*)&Layout_Type);
	Py_DECREF(&Layout_Type);

	/// Add the Module type object to Pvsamv1_Type
	if (PyType_Ready(&Module_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Module",
				(PyObject*)&Module_Type);
	Py_DECREF(&Module_Type);

	/// Add the SimpleEfficiencyModuleModel type object to Pvsamv1_Type
	if (PyType_Ready(&SimpleEfficiencyModuleModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"SimpleEfficiencyModuleModel",
				(PyObject*)&SimpleEfficiencyModuleModel_Type);
	Py_DECREF(&SimpleEfficiencyModuleModel_Type);

	/// Add the CECPerformanceModelWithModuleDatabase type object to Pvsamv1_Type
	if (PyType_Ready(&CECPerformanceModelWithModuleDatabase_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"CECPerformanceModelWithModuleDatabase",
				(PyObject*)&CECPerformanceModelWithModuleDatabase_Type);
	Py_DECREF(&CECPerformanceModelWithModuleDatabase_Type);

	/// Add the CECPerformanceModelWithUserEnteredSpecifications type object to Pvsamv1_Type
	if (PyType_Ready(&CECPerformanceModelWithUserEnteredSpecifications_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"CECPerformanceModelWithUserEnteredSpecifications",
				(PyObject*)&CECPerformanceModelWithUserEnteredSpecifications_Type);
	Py_DECREF(&CECPerformanceModelWithUserEnteredSpecifications_Type);

	/// Add the SandiaPVArrayPerformanceModelWithModuleDatabase type object to Pvsamv1_Type
	if (PyType_Ready(&SandiaPVArrayPerformanceModelWithModuleDatabase_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"SandiaPVArrayPerformanceModelWithModuleDatabase",
				(PyObject*)&SandiaPVArrayPerformanceModelWithModuleDatabase_Type);
	Py_DECREF(&SandiaPVArrayPerformanceModelWithModuleDatabase_Type);

	/// Add the IEC61853SingleDiodeModel type object to Pvsamv1_Type
	if (PyType_Ready(&IEC61853SingleDiodeModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"IEC61853SingleDiodeModel",
				(PyObject*)&IEC61853SingleDiodeModel_Type);
	Py_DECREF(&IEC61853SingleDiodeModel_Type);

	/// Add the MermoudLejeuneSingleDiodeModel type object to Pvsamv1_Type
	if (PyType_Ready(&MermoudLejeuneSingleDiodeModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"MermoudLejeuneSingleDiodeModel",
				(PyObject*)&MermoudLejeuneSingleDiodeModel_Type);
	Py_DECREF(&MermoudLejeuneSingleDiodeModel_Type);

	/// Add the Inverter type object to Pvsamv1_Type
	if (PyType_Ready(&Inverter_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Inverter",
				(PyObject*)&Inverter_Type);
	Py_DECREF(&Inverter_Type);

	/// Add the InverterCECDatabase type object to Pvsamv1_Type
	if (PyType_Ready(&InverterCECDatabase_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"InverterCECDatabase",
				(PyObject*)&InverterCECDatabase_Type);
	Py_DECREF(&InverterCECDatabase_Type);

	/// Add the InverterCECCoefficientGenerator type object to Pvsamv1_Type
	if (PyType_Ready(&InverterCECCoefficientGenerator_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"InverterCECCoefficientGenerator",
				(PyObject*)&InverterCECCoefficientGenerator_Type);
	Py_DECREF(&InverterCECCoefficientGenerator_Type);

	/// Add the InverterDatasheet type object to Pvsamv1_Type
	if (PyType_Ready(&InverterDatasheet_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"InverterDatasheet",
				(PyObject*)&InverterDatasheet_Type);
	Py_DECREF(&InverterDatasheet_Type);

	/// Add the InverterPartLoadCurve type object to Pvsamv1_Type
	if (PyType_Ready(&InverterPartLoadCurve_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"InverterPartLoadCurve",
				(PyObject*)&InverterPartLoadCurve_Type);
	Py_DECREF(&InverterPartLoadCurve_Type);

	/// Add the InverterMermoudLejeuneModel type object to Pvsamv1_Type
	if (PyType_Ready(&InverterMermoudLejeuneModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"InverterMermoudLejeuneModel",
				(PyObject*)&InverterMermoudLejeuneModel_Type);
	Py_DECREF(&InverterMermoudLejeuneModel_Type);

	/// Add the BatterySystem type object to Pvsamv1_Type
	if (PyType_Ready(&BatterySystem_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"BatterySystem",
				(PyObject*)&BatterySystem_Type);
	Py_DECREF(&BatterySystem_Type);

	/// Add the Load type object to Pvsamv1_Type
	if (PyType_Ready(&Load_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Load",
				(PyObject*)&Load_Type);
	Py_DECREF(&Load_Type);

	/// Add the BatteryCell type object to Pvsamv1_Type
	if (PyType_Ready(&BatteryCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"BatteryCell",
				(PyObject*)&BatteryCell_Type);
	Py_DECREF(&BatteryCell_Type);

	/// Add the BatteryDispatch type object to Pvsamv1_Type
	if (PyType_Ready(&BatteryDispatch_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"BatteryDispatch",
				(PyObject*)&BatteryDispatch_Type);
	Py_DECREF(&BatteryDispatch_Type);

	/// Add the SystemCosts type object to Pvsamv1_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the FuelCell type object to Pvsamv1_Type
	if (PyType_Ready(&FuelCell_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"FuelCell",
				(PyObject*)&FuelCell_Type);
	Py_DECREF(&FuelCell_Type);

	/// Add the PriceSignal type object to Pvsamv1_Type
	if (PyType_Ready(&PriceSignal_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"PriceSignal",
				(PyObject*)&PriceSignal_Type);
	Py_DECREF(&PriceSignal_Type);

	/// Add the Revenue type object to Pvsamv1_Type
	if (PyType_Ready(&Revenue_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Revenue",
				(PyObject*)&Revenue_Type);
	Py_DECREF(&Revenue_Type);

	/// Add the ElectricityRates type object to Pvsamv1_Type
	if (PyType_Ready(&ElectricityRates_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"ElectricityRates",
				(PyObject*)&ElectricityRates_Type);
	Py_DECREF(&ElectricityRates_Type);

	/// Add the GridLimits type object to Pvsamv1_Type
	if (PyType_Ready(&GridLimits_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"GridLimits",
				(PyObject*)&GridLimits_Type);
	Py_DECREF(&GridLimits_Type);

	/// Add the Outputs type object to Pvsamv1_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsamv1_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvsamv1 type object to the module
	if (PyType_Ready(&Pvsamv1_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvsamv1",
				(PyObject*)&Pvsamv1_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvsamv1Module_slots[] = {
		{Py_mod_exec, Pvsamv1Module_exec},
		{0, NULL},
};

static struct PyModuleDef Pvsamv1Module = {
		PyModuleDef_HEAD_INIT,
		"Pvsamv1",
		module_doc,
		0,
		Pvsamv1Module_methods,
		Pvsamv1Module_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvsamv1(void)
{
	return PyModuleDef_Init(&Pvsamv1Module);
}