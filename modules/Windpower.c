#include <Python.h>

#include <SAM_Windpower.h>
#include <SAM_api.h>

#include "PySAM_utils.h"

#include "Windpower_eqns.c"


/*
 * Resource Group
 */ 

static PyTypeObject Resource_Type;

static PyObject *
Resource_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = Resource_Type.tp_alloc(&Resource_Type,0);

	VarGroupObject* Resource_obj = (VarGroupObject*)new_obj;

	Resource_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Resource methods */

static PyObject *
Resource_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Resource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Resource_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Resource_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Windpower", "Resource")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Resource_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Resource_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Resource_methods[] = {
		{"assign",            (PyCFunction)Resource_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Resource_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Resource_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Resource_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Resource_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Resource_get_weibull_k_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Resource_weibull_k_factor_nget, self->data_ptr);
}

static int
Resource_set_weibull_k_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Resource_weibull_k_factor_nset, self->data_ptr);
}

static PyObject *
Resource_get_weibull_reference_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Resource_weibull_reference_height_nget, self->data_ptr);
}

static int
Resource_set_weibull_reference_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Resource_weibull_reference_height_nset, self->data_ptr);
}

static PyObject *
Resource_get_weibull_wind_speed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Resource_weibull_wind_speed_nget, self->data_ptr);
}

static int
Resource_set_weibull_wind_speed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Resource_weibull_wind_speed_nset, self->data_ptr);
}

static PyObject *
Resource_get_wind_resource_data(VarGroupObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Windpower_Resource_wind_resource_data_tget, self->data_ptr);
}

static int
Resource_set_wind_resource_data(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Windpower_Resource_wind_resource_data_tset, self->data_ptr);
}

static PyObject *
Resource_get_wind_resource_distribution(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Windpower_Resource_wind_resource_distribution_mget, self->data_ptr);
}

static int
Resource_set_wind_resource_distribution(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_Windpower_Resource_wind_resource_distribution_mset, self->data_ptr);
}

static PyObject *
Resource_get_wind_resource_filename(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Windpower_Resource_wind_resource_filename_sget, self->data_ptr);
}

static int
Resource_set_wind_resource_filename(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Windpower_Resource_wind_resource_filename_sset, self->data_ptr);
}

static PyObject *
Resource_get_wind_resource_model_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Resource_wind_resource_model_choice_nget, self->data_ptr);
}

static int
Resource_set_wind_resource_model_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Resource_wind_resource_model_choice_nset, self->data_ptr);
}

static PyGetSetDef Resource_getset[] = {
{"weibull_k_factor", (getter)Resource_get_weibull_k_factor,(setter)Resource_set_weibull_k_factor,
	PyDoc_STR("*float*: Weibull K factor for wind resource\n\n**Required:**\nRequired if wind_resource_model_choice=1"),
 	NULL},
{"weibull_reference_height", (getter)Resource_get_weibull_reference_height,(setter)Resource_set_weibull_reference_height,
	PyDoc_STR("*float*: Reference height for Weibull wind speed [m]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nFalse. Automatically set to 50 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"weibull_wind_speed", (getter)Resource_get_weibull_wind_speed,(setter)Resource_set_weibull_wind_speed,
	PyDoc_STR("*float*: Average wind speed for Weibull model\n\n**Constraints:**\nMIN=0\n\n**Required:**\nRequired if wind_resource_model_choice=1"),
 	NULL},
{"wind_resource_data", (getter)Resource_get_wind_resource_data,(setter)Resource_set_wind_resource_data,
	PyDoc_STR("*dict*: Wind resouce data in memory\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"wind_resource_distribution", (getter)Resource_get_wind_resource_distribution,(setter)Resource_set_wind_resource_distribution,
	PyDoc_STR("*sequence[sequence]*: Wind Speed x Dir Distribution as 2-D PDF [m/s,deg]\n\n**Required:**\nRequired if wind_resource_model_choice=2"),
 	NULL},
{"wind_resource_filename", (getter)Resource_get_wind_resource_filename,(setter)Resource_set_wind_resource_filename,
	PyDoc_STR("*str*: Local wind data file path\n\n**Constraints:**\nLOCAL_FILE\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"wind_resource_model_choice", (getter)Resource_get_wind_resource_model_choice,(setter)Resource_set_wind_resource_model_choice,
	PyDoc_STR("*float*: Hourly, Weibull or Distribution model [0/1/2]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``wind_resource_model_choice``:\n\n\t - wind_turbine_powercurve_powerout\n\t - wind_turbine_powercurve_windspeeds\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Resource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Resource",             /*tp_name*/
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
		Resource_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Resource_getset,          /*tp_getset*/
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
 * Turbine Group
 */ 

static PyTypeObject Turbine_Type;

static PyObject *
Turbine_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = Turbine_Type.tp_alloc(&Turbine_Type,0);

	VarGroupObject* Turbine_obj = (VarGroupObject*)new_obj;

	Turbine_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Turbine methods */

static PyObject *
Turbine_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Turbine")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Turbine_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Turbine_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Windpower", "Turbine")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Turbine_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Turbine_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Turbine_methods[] = {
		{"assign",            (PyCFunction)Turbine_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Turbine_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Turbine_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Turbine_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Turbine_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{"calculate_powercurve", (PyCFunction)Turbine_calculate_powercurve, METH_VARARGS | METH_KEYWORDS,
			Turbine_calculate_powercurve_doc},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Turbine_get_wind_resource_shear(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Turbine_wind_resource_shear_nget, self->data_ptr);
}

static int
Turbine_set_wind_resource_shear(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Turbine_wind_resource_shear_nset, self->data_ptr);
}

static PyObject *
Turbine_get_wind_turbine_hub_ht(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Turbine_wind_turbine_hub_ht_nget, self->data_ptr);
}

static int
Turbine_set_wind_turbine_hub_ht(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Turbine_wind_turbine_hub_ht_nset, self->data_ptr);
}

static PyObject *
Turbine_get_wind_turbine_max_cp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Turbine_wind_turbine_max_cp_nget, self->data_ptr);
}

static int
Turbine_set_wind_turbine_max_cp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Turbine_wind_turbine_max_cp_nset, self->data_ptr);
}

static PyObject *
Turbine_get_wind_turbine_powercurve_powerout(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Turbine_wind_turbine_powercurve_powerout_aget, self->data_ptr);
}

static int
Turbine_set_wind_turbine_powercurve_powerout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Windpower_Turbine_wind_turbine_powercurve_powerout_aset, self->data_ptr);
}

static PyObject *
Turbine_get_wind_turbine_powercurve_windspeeds(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Turbine_wind_turbine_powercurve_windspeeds_aget, self->data_ptr);
}

static int
Turbine_set_wind_turbine_powercurve_windspeeds(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Windpower_Turbine_wind_turbine_powercurve_windspeeds_aset, self->data_ptr);
}

static PyObject *
Turbine_get_wind_turbine_rotor_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Turbine_wind_turbine_rotor_diameter_nget, self->data_ptr);
}

static int
Turbine_set_wind_turbine_rotor_diameter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Turbine_wind_turbine_rotor_diameter_nset, self->data_ptr);
}

static PyGetSetDef Turbine_getset[] = {
{"wind_resource_shear", (getter)Turbine_get_wind_resource_shear,(setter)Turbine_set_wind_resource_shear,
	PyDoc_STR("*float*: Shear exponent\n\n**Constraints:**\nMIN=0\n\n**Required:**\nTrue"),
 	NULL},
{"wind_turbine_hub_ht", (getter)Turbine_get_wind_turbine_hub_ht,(setter)Turbine_set_wind_turbine_hub_ht,
	PyDoc_STR("*float*: Hub height [m]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``wind_turbine_hub_ht``:\n\n\t - wind_turbine_powercurve_powerout\n\t - wind_turbine_powercurve_windspeeds\n"),
 	NULL},
{"wind_turbine_max_cp", (getter)Turbine_get_wind_turbine_max_cp,(setter)Turbine_set_wind_turbine_max_cp,
	PyDoc_STR("*float*: Max Coefficient of Power\n\n**Constraints:**\nMIN=0\n\n**Required:**\nRequired if wind_resource_model_choice=1\n\nThe value of the following variables depends on ``wind_turbine_max_cp``:\n\n\t - wind_turbine_powercurve_powerout\n\t - wind_turbine_powercurve_windspeeds\n"),
 	NULL},
{"wind_turbine_powercurve_powerout", (getter)Turbine_get_wind_turbine_powercurve_powerout,(setter)Turbine_set_wind_turbine_powercurve_powerout,
	PyDoc_STR("*sequence*: Power curve turbine output array [kW]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Constraints:**\nLENGTH_EQUAL=wind_turbine_powercurve_windspeeds\n\n**Required:**\nTrue\n\nThe value of ``wind_turbine_powercurve_powerout`` depends on the following variables:\n\n\t - wind_resource_model_choice\n\t - wind_turbine_hub_ht\n\t - wind_turbine_max_cp\n"),
 	NULL},
{"wind_turbine_powercurve_windspeeds", (getter)Turbine_get_wind_turbine_powercurve_windspeeds,(setter)Turbine_set_wind_turbine_powercurve_windspeeds,
	PyDoc_STR("*sequence*: Power curve wind speed array [m/s]\n\n**INOUT:** This variable is both an input and an output to the compute module.\n\n**Required:**\nTrue\n\nThe value of ``wind_turbine_powercurve_windspeeds`` depends on the following variables:\n\n\t - wind_resource_model_choice\n\t - wind_turbine_hub_ht\n\t - wind_turbine_max_cp\n"),
 	NULL},
{"wind_turbine_rotor_diameter", (getter)Turbine_get_wind_turbine_rotor_diameter,(setter)Turbine_set_wind_turbine_rotor_diameter,
	PyDoc_STR("*float*: Rotor diameter [m]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``wind_turbine_rotor_diameter``:\n\n\t - system_capacity\n\t - wind_farm_xCoordinates\n\t - wind_farm_yCoordinates\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Turbine_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Turbine",             /*tp_name*/
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
		Turbine_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Turbine_getset,          /*tp_getset*/
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
 * Farm Group
 */ 

static PyTypeObject Farm_Type;

static PyObject *
Farm_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = Farm_Type.tp_alloc(&Farm_Type,0);

	VarGroupObject* Farm_obj = (VarGroupObject*)new_obj;

	Farm_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Farm methods */

static PyObject *
Farm_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Farm")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Farm_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Farm_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Windpower", "Farm")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Farm_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Farm_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Farm_methods[] = {
		{"assign",            (PyCFunction)Farm_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Farm_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Farm_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Farm_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Farm_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Farm_get_max_turbine_override(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Farm_max_turbine_override_nget, self->data_ptr);
}

static int
Farm_set_max_turbine_override(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Farm_max_turbine_override_nset, self->data_ptr);
}

static PyObject *
Farm_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Farm_system_capacity_nget, self->data_ptr);
}

static int
Farm_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Farm_system_capacity_nset, self->data_ptr);
}

static PyObject *
Farm_get_wind_farm_wake_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Farm_wind_farm_wake_model_nget, self->data_ptr);
}

static int
Farm_set_wind_farm_wake_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Farm_wind_farm_wake_model_nset, self->data_ptr);
}

static PyObject *
Farm_get_wind_farm_xCoordinates(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Farm_wind_farm_xCoordinates_aget, self->data_ptr);
}

static int
Farm_set_wind_farm_xCoordinates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Windpower_Farm_wind_farm_xCoordinates_aset, self->data_ptr);
}

static PyObject *
Farm_get_wind_farm_yCoordinates(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Farm_wind_farm_yCoordinates_aget, self->data_ptr);
}

static int
Farm_set_wind_farm_yCoordinates(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Windpower_Farm_wind_farm_yCoordinates_aset, self->data_ptr);
}

static PyObject *
Farm_get_wind_resource_turbulence_coeff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Farm_wind_resource_turbulence_coeff_nget, self->data_ptr);
}

static int
Farm_set_wind_resource_turbulence_coeff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Farm_wind_resource_turbulence_coeff_nset, self->data_ptr);
}

static PyGetSetDef Farm_getset[] = {
{"max_turbine_override", (getter)Farm_get_max_turbine_override,(setter)Farm_set_max_turbine_override,
	PyDoc_STR("*float*: Override the max number of turbines for wake modeling [numTurbines]\n\n**Info:**\nset new max num turbines"),
 	NULL},
{"system_capacity", (getter)Farm_get_system_capacity,(setter)Farm_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nTrue\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - wind_turbine_rotor_diameter\n"),
 	NULL},
{"wind_farm_wake_model", (getter)Farm_get_wind_farm_wake_model,(setter)Farm_set_wind_farm_wake_model,
	PyDoc_STR("*float*: Wake Model [Simple, Park, EV, Constant] [0/1/2/3]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``wind_farm_wake_model``:\n\n\t - wake_int_loss\n"),
 	NULL},
{"wind_farm_xCoordinates", (getter)Farm_get_wind_farm_xCoordinates,(setter)Farm_set_wind_farm_xCoordinates,
	PyDoc_STR("*sequence*: Turbine X coordinates [m]\n\n**Required:**\nTrue\n\nThe value of ``wind_farm_xCoordinates`` depends on the following variables:\n\n\t - wind_turbine_rotor_diameter\n"),
 	NULL},
{"wind_farm_yCoordinates", (getter)Farm_get_wind_farm_yCoordinates,(setter)Farm_set_wind_farm_yCoordinates,
	PyDoc_STR("*sequence*: Turbine Y coordinates [m]\n\n**Constraints:**\nLENGTH_EQUAL=wind_farm_xCoordinates\n\n**Required:**\nTrue\n\nThe value of ``wind_farm_yCoordinates`` depends on the following variables:\n\n\t - wind_turbine_rotor_diameter\n"),
 	NULL},
{"wind_resource_turbulence_coeff", (getter)Farm_get_wind_resource_turbulence_coeff,(setter)Farm_set_wind_resource_turbulence_coeff,
	PyDoc_STR("*float*: Turbulence coefficient [%]\n\n**Constraints:**\nMIN=0\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Farm_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Farm",             /*tp_name*/
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
		Farm_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Farm_getset,          /*tp_getset*/
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
Losses_new(SAM_Windpower data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Losses")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Windpower", "Losses")){
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
Losses_get_avail_bop_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_avail_bop_loss_nget, self->data_ptr);
}

static int
Losses_set_avail_bop_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_avail_bop_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_avail_grid_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_avail_grid_loss_nget, self->data_ptr);
}

static int
Losses_set_avail_grid_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_avail_grid_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_avail_turb_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_avail_turb_loss_nget, self->data_ptr);
}

static int
Losses_set_avail_turb_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_avail_turb_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_elec_eff_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_elec_eff_loss_nget, self->data_ptr);
}

static int
Losses_set_elec_eff_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_elec_eff_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_elec_parasitic_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_elec_parasitic_loss_nget, self->data_ptr);
}

static int
Losses_set_elec_parasitic_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_elec_parasitic_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_en_icing_cutoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_en_icing_cutoff_nget, self->data_ptr);
}

static int
Losses_set_en_icing_cutoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_en_icing_cutoff_nset, self->data_ptr);
}

static PyObject *
Losses_get_en_low_temp_cutoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_en_low_temp_cutoff_nget, self->data_ptr);
}

static int
Losses_set_en_low_temp_cutoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_en_low_temp_cutoff_nset, self->data_ptr);
}

static PyObject *
Losses_get_env_degrad_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_env_degrad_loss_nget, self->data_ptr);
}

static int
Losses_set_env_degrad_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_env_degrad_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_env_env_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_env_env_loss_nget, self->data_ptr);
}

static int
Losses_set_env_env_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_env_env_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_env_exposure_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_env_exposure_loss_nget, self->data_ptr);
}

static int
Losses_set_env_exposure_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_env_exposure_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_env_icing_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_env_icing_loss_nget, self->data_ptr);
}

static int
Losses_set_env_icing_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_env_icing_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_icing_cutoff_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_icing_cutoff_rh_nget, self->data_ptr);
}

static int
Losses_set_icing_cutoff_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_icing_cutoff_rh_nset, self->data_ptr);
}

static PyObject *
Losses_get_icing_cutoff_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_icing_cutoff_temp_nget, self->data_ptr);
}

static int
Losses_set_icing_cutoff_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_icing_cutoff_temp_nset, self->data_ptr);
}

static PyObject *
Losses_get_low_temp_cutoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_low_temp_cutoff_nget, self->data_ptr);
}

static int
Losses_set_low_temp_cutoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_low_temp_cutoff_nset, self->data_ptr);
}

static PyObject *
Losses_get_ops_env_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_ops_env_loss_nget, self->data_ptr);
}

static int
Losses_set_ops_env_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_ops_env_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_ops_grid_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_ops_grid_loss_nget, self->data_ptr);
}

static int
Losses_set_ops_grid_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_ops_grid_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_ops_load_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_ops_load_loss_nget, self->data_ptr);
}

static int
Losses_set_ops_load_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_ops_load_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_ops_strategies_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_ops_strategies_loss_nget, self->data_ptr);
}

static int
Losses_set_ops_strategies_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_ops_strategies_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_turb_generic_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_turb_generic_loss_nget, self->data_ptr);
}

static int
Losses_set_turb_generic_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_turb_generic_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_turb_hysteresis_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_turb_hysteresis_loss_nget, self->data_ptr);
}

static int
Losses_set_turb_hysteresis_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_turb_hysteresis_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_turb_perf_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_turb_perf_loss_nget, self->data_ptr);
}

static int
Losses_set_turb_perf_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_turb_perf_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_turb_specific_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_turb_specific_loss_nget, self->data_ptr);
}

static int
Losses_set_turb_specific_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_turb_specific_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_wake_ext_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_wake_ext_loss_nget, self->data_ptr);
}

static int
Losses_set_wake_ext_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_wake_ext_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_wake_future_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_wake_future_loss_nget, self->data_ptr);
}

static int
Losses_set_wake_future_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_wake_future_loss_nset, self->data_ptr);
}

static PyObject *
Losses_get_wake_int_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Losses_wake_int_loss_nget, self->data_ptr);
}

static int
Losses_set_wake_int_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Losses_wake_int_loss_nset, self->data_ptr);
}

static PyGetSetDef Losses_getset[] = {
{"avail_bop_loss", (getter)Losses_get_avail_bop_loss,(setter)Losses_set_avail_bop_loss,
	PyDoc_STR("*float*: Balance-of-plant availability loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"avail_grid_loss", (getter)Losses_get_avail_grid_loss,(setter)Losses_set_avail_grid_loss,
	PyDoc_STR("*float*: Grid availability loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"avail_turb_loss", (getter)Losses_get_avail_turb_loss,(setter)Losses_set_avail_turb_loss,
	PyDoc_STR("*float*: Turbine availabaility loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"elec_eff_loss", (getter)Losses_get_elec_eff_loss,(setter)Losses_set_elec_eff_loss,
	PyDoc_STR("*float*: Electrical efficiency loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"elec_parasitic_loss", (getter)Losses_get_elec_parasitic_loss,(setter)Losses_set_elec_parasitic_loss,
	PyDoc_STR("*float*: Electrical parasitic consumption loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_icing_cutoff", (getter)Losses_get_en_icing_cutoff,(setter)Losses_set_en_icing_cutoff,
	PyDoc_STR("*float*: Enable Icing Cutoff [0/1]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"en_low_temp_cutoff", (getter)Losses_get_en_low_temp_cutoff,(setter)Losses_set_en_low_temp_cutoff,
	PyDoc_STR("*float*: Enable Low Temperature Cutoff [0/1]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"env_degrad_loss", (getter)Losses_get_env_degrad_loss,(setter)Losses_set_env_degrad_loss,
	PyDoc_STR("*float*: Environmental Degradation loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"env_env_loss", (getter)Losses_get_env_env_loss,(setter)Losses_set_env_env_loss,
	PyDoc_STR("*float*: Environmental External Conditions loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"env_exposure_loss", (getter)Losses_get_env_exposure_loss,(setter)Losses_set_env_exposure_loss,
	PyDoc_STR("*float*: Environmental Exposure loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"env_icing_loss", (getter)Losses_get_env_icing_loss,(setter)Losses_set_env_icing_loss,
	PyDoc_STR("*float*: Environmental Icing loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"icing_cutoff_rh", (getter)Losses_get_icing_cutoff_rh,(setter)Losses_set_icing_cutoff_rh,
	PyDoc_STR("*float*: Icing Cutoff Relative Humidity [%]\n\n**Info:**\n'rh' required in wind_resource_data\n\n**Constraints:**\nMIN=0\n\n**Required:**\nRequired if en_icing_cutoff=1"),
 	NULL},
{"icing_cutoff_temp", (getter)Losses_get_icing_cutoff_temp,(setter)Losses_set_icing_cutoff_temp,
	PyDoc_STR("*float*: Icing Cutoff Temperature [C]\n\n**Required:**\nRequired if en_icing_cutoff=1"),
 	NULL},
{"low_temp_cutoff", (getter)Losses_get_low_temp_cutoff,(setter)Losses_set_low_temp_cutoff,
	PyDoc_STR("*float*: Low Temperature Cutoff [C]\n\n**Required:**\nRequired if en_low_temp_cutoff=1"),
 	NULL},
{"ops_env_loss", (getter)Losses_get_ops_env_loss,(setter)Losses_set_ops_env_loss,
	PyDoc_STR("*float*: Environmental/Permit Curtailment loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ops_grid_loss", (getter)Losses_get_ops_grid_loss,(setter)Losses_set_ops_grid_loss,
	PyDoc_STR("*float*: Grid curtailment loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ops_load_loss", (getter)Losses_get_ops_load_loss,(setter)Losses_set_ops_load_loss,
	PyDoc_STR("*float*: Load curtailment loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"ops_strategies_loss", (getter)Losses_get_ops_strategies_loss,(setter)Losses_set_ops_strategies_loss,
	PyDoc_STR("*float*: Operational strategies loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"turb_generic_loss", (getter)Losses_get_turb_generic_loss,(setter)Losses_set_turb_generic_loss,
	PyDoc_STR("*float*: Turbine Generic Powercurve loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"turb_hysteresis_loss", (getter)Losses_get_turb_hysteresis_loss,(setter)Losses_set_turb_hysteresis_loss,
	PyDoc_STR("*float*: Turbine High Wind Hysteresis loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"turb_perf_loss", (getter)Losses_get_turb_perf_loss,(setter)Losses_set_turb_perf_loss,
	PyDoc_STR("*float*: Turbine Sub-optimal performance loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"turb_specific_loss", (getter)Losses_get_turb_specific_loss,(setter)Losses_set_turb_specific_loss,
	PyDoc_STR("*float*: Turbine Site-specific Powercurve loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"wake_ext_loss", (getter)Losses_get_wake_ext_loss,(setter)Losses_set_wake_ext_loss,
	PyDoc_STR("*float*: External Wake loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"wake_future_loss", (getter)Losses_get_wake_future_loss,(setter)Losses_set_wake_future_loss,
	PyDoc_STR("*float*: Future Wake loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"wake_int_loss", (getter)Losses_get_wake_int_loss,(setter)Losses_set_wake_int_loss,
	PyDoc_STR("*float*: Constant Wake Model, internal wake loss [%]\n\n**Constraints:**\nMIN=0,MAX=100\n\n**Required:**\nRequired if wind_farm_wake_model=3\n\nThe value of ``wake_int_loss`` depends on the following variables:\n\n\t - wind_farm_wake_model\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Losses_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Losses",             /*tp_name*/
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
 * Uncertainty Group
 */ 

static PyTypeObject Uncertainty_Type;

static PyObject *
Uncertainty_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = Uncertainty_Type.tp_alloc(&Uncertainty_Type,0);

	VarGroupObject* Uncertainty_obj = (VarGroupObject*)new_obj;

	Uncertainty_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Uncertainty methods */

static PyObject *
Uncertainty_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Uncertainty")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Uncertainty_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Uncertainty_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Windpower", "Uncertainty")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Uncertainty_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Uncertainty_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Uncertainty_methods[] = {
		{"assign",            (PyCFunction)Uncertainty_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Uncertainty_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Uncertainty_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Uncertainty_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Uncertainty_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Uncertainty_get_total_uncert(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Uncertainty_total_uncert_nget, self->data_ptr);
}

static int
Uncertainty_set_total_uncert(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windpower_Uncertainty_total_uncert_nset, self->data_ptr);
}

static PyGetSetDef Uncertainty_getset[] = {
{"total_uncert", (getter)Uncertainty_get_total_uncert,(setter)Uncertainty_set_total_uncert,
	PyDoc_STR("*float*: Total uncertainty in energy production as percent of annual energy [%]\n\n**Constraints:**\nMIN=0,MAX=100"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Uncertainty_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Uncertainty",             /*tp_name*/
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
		Uncertainty_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Uncertainty_getset,          /*tp_getset*/
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
Outputs_new(SAM_Windpower data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Windpower", "Outputs")){
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
	return PySAM_double_getter(SAM_Windpower_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution_time(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Windpower_Outputs_annual_energy_distribution_time_mget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_p75(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_annual_energy_p75_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_p90(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_annual_energy_p90_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_p95(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_annual_energy_p95_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_gross_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_annual_gross_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_avail_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_avail_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cutoff_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_cutoff_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_elec_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_elec_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_elev_nget, self->data_ptr);
}

static PyObject *
Outputs_get_env_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_env_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_lat_nget, self->data_ptr);
}

static PyObject *
Outputs_get_lon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_lon_nget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ops_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_ops_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_pressure_aget, self->data_ptr);
}

static PyObject *
Outputs_get_temp(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_temp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_turb_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_turb_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_turbine_output_by_windspeed_bin(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_turbine_output_by_windspeed_bin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wake_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_wake_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_direction(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_wind_direction_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_speed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_wind_speed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_speed_average(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_wind_speed_average_nget, self->data_ptr);
}

static PyObject *
Outputs_get_year(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windpower_Outputs_year_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kWh]"),
 	NULL},
{"annual_energy_distribution_time", (getter)Outputs_get_annual_energy_distribution_time,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Annual energy production as function of time [kW]"),
 	NULL},
{"annual_energy_p75", (getter)Outputs_get_annual_energy_p75,(setter)0,
	PyDoc_STR("*float*: Annual energy with 75% probability of exceedance [kWh]"),
 	NULL},
{"annual_energy_p90", (getter)Outputs_get_annual_energy_p90,(setter)0,
	PyDoc_STR("*float*: Annual energy with 90% probability of exceedance [kWh]"),
 	NULL},
{"annual_energy_p95", (getter)Outputs_get_annual_energy_p95,(setter)0,
	PyDoc_STR("*float*: Annual energy with 95% probability of exceedance [kWh]"),
 	NULL},
{"annual_gross_energy", (getter)Outputs_get_annual_gross_energy,(setter)0,
	PyDoc_STR("*float*: Annual Gross Energy [kWh]"),
 	NULL},
{"avail_losses", (getter)Outputs_get_avail_losses,(setter)0,
	PyDoc_STR("*float*: Availability losses [%]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"cutoff_losses", (getter)Outputs_get_cutoff_losses,(setter)0,
	PyDoc_STR("*float*: Low temp and Icing Cutoff losses [%]"),
 	NULL},
{"elec_losses", (getter)Outputs_get_elec_losses,(setter)0,
	PyDoc_STR("*float*: Electrical losses [%]"),
 	NULL},
{"elev", (getter)Outputs_get_elev,(setter)0,
	PyDoc_STR("*float*: Site elevation [m]"),
 	NULL},
{"env_losses", (getter)Outputs_get_env_losses,(setter)0,
	PyDoc_STR("*float*: Environmental losses [%]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"lat", (getter)Outputs_get_lat,(setter)0,
	PyDoc_STR("*float*: Latitude [degrees]"),
 	NULL},
{"lon", (getter)Outputs_get_lon,(setter)0,
	PyDoc_STR("*float*: Longitude [degrees]"),
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	PyDoc_STR("*sequence*: Monthly Energy Gross [kWh]"),
 	NULL},
{"ops_losses", (getter)Outputs_get_ops_losses,(setter)0,
	PyDoc_STR("*float*: Operational losses [%]"),
 	NULL},
{"pressure", (getter)Outputs_get_pressure,(setter)0,
	PyDoc_STR("*sequence*: Pressure [atm]"),
 	NULL},
{"temp", (getter)Outputs_get_temp,(setter)0,
	PyDoc_STR("*sequence*: Air temperature ['C]"),
 	NULL},
{"turb_losses", (getter)Outputs_get_turb_losses,(setter)0,
	PyDoc_STR("*float*: Turbine losses [%]"),
 	NULL},
{"turbine_output_by_windspeed_bin", (getter)Outputs_get_turbine_output_by_windspeed_bin,(setter)0,
	PyDoc_STR("*sequence*: Turbine output by wind speed bin [kW]"),
 	NULL},
{"wake_losses", (getter)Outputs_get_wake_losses,(setter)0,
	PyDoc_STR("*float*: Wake losses [%]"),
 	NULL},
{"wind_direction", (getter)Outputs_get_wind_direction,(setter)0,
	PyDoc_STR("*sequence*: Wind direction [degrees]"),
 	NULL},
{"wind_speed", (getter)Outputs_get_wind_speed,(setter)0,
	PyDoc_STR("*sequence*: Wind speed [m/s]"),
 	NULL},
{"wind_speed_average", (getter)Outputs_get_wind_speed_average,(setter)0,
	PyDoc_STR("*float*: Average Wind speed [m/s]"),
 	NULL},
{"year", (getter)Outputs_get_year,(setter)0,
	PyDoc_STR("*float*: Year"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Outputs",             /*tp_name*/
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
 * Windpower
 */

static PyTypeObject Windpower_Type;

static CmodObject *
newWindpowerObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Windpower_Type);

	PySAM_TECH_ATTR()

	PyObject* Resource_obj = Resource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Resource", Resource_obj);
	Py_DECREF(Resource_obj);

	PyObject* Turbine_obj = Turbine_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Turbine", Turbine_obj);
	Py_DECREF(Turbine_obj);

	PyObject* Farm_obj = Farm_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Farm", Farm_obj);
	Py_DECREF(Farm_obj);

	PyObject* Losses_obj = Losses_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Losses", Losses_obj);
	Py_DECREF(Losses_obj);

	PyObject* Uncertainty_obj = Uncertainty_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Uncertainty", Uncertainty_obj);
	Py_DECREF(Uncertainty_obj);

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

/* Windpower methods */

static void
Windpower_dealloc(CmodObject *self)
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
Windpower_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Windpower_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Windpower_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Windpower"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Windpower_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Windpower"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Windpower_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Windpower_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Windpower_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Windpower_methods[] = {
		{"execute",           (PyCFunction)Windpower_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Windpower_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Resource': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Windpower_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Windpower_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Windpower_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Windpower_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Windpower_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Windpower_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Windpower_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Windpower_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Windpower_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Windpower_getattro, /*tp_getattro*/
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
		Windpower_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Windpower object */

static PyObject *
Windpower_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWindpowerObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Windpower_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindpowerObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Windpower_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindpowerObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Windpower", def) < 0) {
		Windpower_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Windpower_from_existing(PyObject *self, PyObject *args)
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

	rv = newWindpowerObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Windpower", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WindpowerModule_methods[] = {
		{"new",             Windpower_new,         METH_VARARGS,
				PyDoc_STR("new() -> Windpower")},
		{"default",             Windpower_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Windpower\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"WindPowerAllEquityPartnershipFlip\"*\n\n		- *\"WindPowerCommercial\"*\n\n		- *\"WindPowerLCOECalculator\"*\n\n		- *\"WindPowerLeveragedPartnershipFlip\"*\n\n		- *\"WindPowerMerchantPlant\"*\n\n		- *\"WindPowerNone\"*\n\n		- *\"WindPowerResidential\"*\n\n		- *\"WindPowerSaleLeaseback\"*\n\n		- *\"WindPowerSingleOwner\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Windpower_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Windpower\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Windpower_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Windpower\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Wind power system with one or more wind turbines");


static int
WindpowerModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Windpower_Type.tp_dict = PyDict_New();
	if (!Windpower_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Windpower_Type
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
	PyDict_SetItemString(Windpower_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Resource type object to Windpower_Type
	if (PyType_Ready(&Resource_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"Resource",
				(PyObject*)&Resource_Type);
	Py_DECREF(&Resource_Type);

	/// Add the Turbine type object to Windpower_Type
	if (PyType_Ready(&Turbine_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"Turbine",
				(PyObject*)&Turbine_Type);
	Py_DECREF(&Turbine_Type);

	/// Add the Farm type object to Windpower_Type
	if (PyType_Ready(&Farm_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"Farm",
				(PyObject*)&Farm_Type);
	Py_DECREF(&Farm_Type);

	/// Add the Losses type object to Windpower_Type
	if (PyType_Ready(&Losses_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"Losses",
				(PyObject*)&Losses_Type);
	Py_DECREF(&Losses_Type);

	/// Add the Uncertainty type object to Windpower_Type
	if (PyType_Ready(&Uncertainty_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"Uncertainty",
				(PyObject*)&Uncertainty_Type);
	Py_DECREF(&Uncertainty_Type);

	/// Add the Outputs type object to Windpower_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Windpower type object to the module
	if (PyType_Ready(&Windpower_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Windpower",
				(PyObject*)&Windpower_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WindpowerModule_slots[] = {
		{Py_mod_exec, WindpowerModule_exec},
		{0, NULL},
};

static struct PyModuleDef WindpowerModule = {
		PyModuleDef_HEAD_INIT,
		"Windpower",
		module_doc,
		0,
		WindpowerModule_methods,
		WindpowerModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Windpower(void)
{
	return PyModuleDef_Init(&WindpowerModule);
}