#include <Python.h>

#include <SAM_Windpower.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * WindResourceFile Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Windpower   data_ptr;
} WindResourceFileObject;

static PyTypeObject WindResourceFile_Type;

static PyObject *
WindResourceFile_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = WindResourceFile_Type.tp_alloc(&WindResourceFile_Type,0);

	WindResourceFileObject* WindResourceFile_obj = (WindResourceFileObject*)new_obj;

	WindResourceFile_obj->data_ptr = data_ptr;

	return new_obj;
}

/* WindResourceFile methods */

static PyObject *
WindResourceFile_assign(WindResourceFileObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "WindResourceFile")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindResourceFile_export(WindResourceFileObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindResourceFile_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindResourceFile_methods[] = {
		{"assign",            (PyCFunction)WindResourceFile_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)WindResourceFile_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindResourceFile_get_wind_resource_data(WindResourceFileObject *self, void *closure)
{
	return PySAM_table_getter(SAM_Windpower_WindResourceFile_wind_resource_data_tget, self->data_ptr);
}

static int
WindResourceFile_set_wind_resource_data(WindResourceFileObject *self, PyObject *value, void *closure)
{
	return PySAM_table_setter(value, SAM_Windpower_WindResourceFile_wind_resource_data_tset, self->data_ptr);
}

static PyObject *
WindResourceFile_get_wind_resource_filename(WindResourceFileObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Windpower_WindResourceFile_file_sget, self->data_ptr);
}

static int
WindResourceFile_set_wind_resource_filename(WindResourceFileObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Windpower_WindResourceFile_file_sset, self->data_ptr);
}

static PyGetSetDef WindResourceFile_getset[] = {
{"wind_resource_data", (getter)WindResourceFile_get_wind_resource_data,(setter)WindResourceFile_set_wind_resource_data,
	"wind resouce data in memory [], table.\n Required if: ?.",
 	NULL},
{"wind_resource_filename", (getter)WindResourceFile_get_wind_resource_filename,(setter)WindResourceFile_set_wind_resource_filename,
	"local wind data file path [], string.\n Constraints: LOCAL_FILE; Required if: ?.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindResourceFile_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.WindResourceFile",             /*tp_name*/
		sizeof(WindResourceFileObject),          /*tp_basicsize*/
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
		WindResourceFile_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindResourceFile_getset,          /*tp_getset*/
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
	 * WindTurbine Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Windpower   data_ptr;
} WindTurbineObject;

static PyTypeObject WindTurbine_Type;

static PyObject *
WindTurbine_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = WindTurbine_Type.tp_alloc(&WindTurbine_Type,0);

	WindTurbineObject* WindTurbine_obj = (WindTurbineObject*)new_obj;

	WindTurbine_obj->data_ptr = data_ptr;

	return new_obj;
}

/* WindTurbine methods */

static PyObject *
WindTurbine_assign(WindTurbineObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "WindTurbine")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindTurbine_export(WindTurbineObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindTurbine_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindTurbine_methods[] = {
		{"assign",            (PyCFunction)WindTurbine_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)WindTurbine_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindTurbine_get_wind_resource_shear(WindTurbineObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindTurbine_wind_resource_shear_fget, self->data_ptr);
}

static int
WindTurbine_set_wind_resource_shear(WindTurbineObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindTurbine_wind_resource_shear_fset, self->data_ptr);
}

static PyObject *
WindTurbine_get_wind_turbine_hub_ht(WindTurbineObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindTurbine_wind_turbine_hub_ht_fget, self->data_ptr);
}

static int
WindTurbine_set_wind_turbine_hub_ht(WindTurbineObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindTurbine_wind_turbine_hub_ht_fset, self->data_ptr);
}

static PyObject *
WindTurbine_get_wind_turbine_max_cp(WindTurbineObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindTurbine_wind_turbine_max_cp_fget, self->data_ptr);
}

static int
WindTurbine_set_wind_turbine_max_cp(WindTurbineObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindTurbine_wind_turbine_max_cp_fset, self->data_ptr);
}

static PyObject *
WindTurbine_get_wind_turbine_powercurve_powerout(WindTurbineObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_WindTurbine_wind_turbine_powercurve_powerout_aget, self->data_ptr);
}

static int
WindTurbine_set_wind_turbine_powercurve_powerout(WindTurbineObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Windpower_WindTurbine_wind_turbine_powercurve_powerout_aset, self->data_ptr);
}

static PyObject *
WindTurbine_get_wind_turbine_powercurve_windspeeds(WindTurbineObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_WindTurbine_wind_turbine_powercurve_windspeeds_aget, self->data_ptr);
}

static int
WindTurbine_set_wind_turbine_powercurve_windspeeds(WindTurbineObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Windpower_WindTurbine_wind_turbine_powercurve_windspeeds_aset, self->data_ptr);
}

static PyObject *
WindTurbine_get_wind_turbine_rotor_diameter(WindTurbineObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindTurbine_wind_turbine_rotor_diameter_fget, self->data_ptr);
}

static int
WindTurbine_set_wind_turbine_rotor_diameter(WindTurbineObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindTurbine_wind_turbine_rotor_diameter_fset, self->data_ptr);
}

static PyGetSetDef WindTurbine_getset[] = {
{"wind_resource_shear", (getter)WindTurbine_get_wind_resource_shear,(setter)WindTurbine_set_wind_resource_shear,
	"Shear exponent [], number.\n Constraints: MIN=0; Required if: *.",
 	NULL},
{"wind_turbine_hub_ht", (getter)WindTurbine_get_wind_turbine_hub_ht,(setter)WindTurbine_set_wind_turbine_hub_ht,
	"Hub height [m], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
{"wind_turbine_max_cp", (getter)WindTurbine_get_wind_turbine_max_cp,(setter)WindTurbine_set_wind_turbine_max_cp,
	"Max cp [], number.\n Constraints: MIN=0; Required if: wind_resource_model_choice=1.",
 	NULL},
{"wind_turbine_powercurve_powerout", (getter)WindTurbine_get_wind_turbine_powercurve_powerout,(setter)WindTurbine_set_wind_turbine_powercurve_powerout,
	"Power curve turbine output array [kW], array.\n Constraints: LENGTH_EQUAL=wind_turbine_powercurve_windspeeds; Required if: *.",
 	NULL},
{"wind_turbine_powercurve_windspeeds", (getter)WindTurbine_get_wind_turbine_powercurve_windspeeds,(setter)WindTurbine_set_wind_turbine_powercurve_windspeeds,
	"Power curve wind speed array [m/s], array.\n Required if: *.",
 	NULL},
{"wind_turbine_rotor_diameter", (getter)WindTurbine_get_wind_turbine_rotor_diameter,(setter)WindTurbine_set_wind_turbine_rotor_diameter,
	"Rotor diameter [m], number.\n Constraints: POSITIVE; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindTurbine_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.WindTurbine",             /*tp_name*/
		sizeof(WindTurbineObject),          /*tp_basicsize*/
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
		WindTurbine_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindTurbine_getset,          /*tp_getset*/
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
	 * WindFarm Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Windpower   data_ptr;
} WindFarmObject;

static PyTypeObject WindFarm_Type;

static PyObject *
WindFarm_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = WindFarm_Type.tp_alloc(&WindFarm_Type,0);

	WindFarmObject* WindFarm_obj = (WindFarmObject*)new_obj;

	WindFarm_obj->data_ptr = data_ptr;

	return new_obj;
}

/* WindFarm methods */

static PyObject *
WindFarm_assign(WindFarmObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "WindFarm")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindFarm_export(WindFarmObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindFarm_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindFarm_methods[] = {
		{"assign",            (PyCFunction)WindFarm_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)WindFarm_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindFarm_get_system_capacity(WindFarmObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindFarm_system_capacity_fget, self->data_ptr);
}

static int
WindFarm_set_system_capacity(WindFarmObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindFarm_system_capacity_fset, self->data_ptr);
}

static PyObject *
WindFarm_get_wind_farm_losses_percent(WindFarmObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindFarm_wind_farm_losses_percent_fget, self->data_ptr);
}

static int
WindFarm_set_wind_farm_losses_percent(WindFarmObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindFarm_wind_farm_losses_percent_fset, self->data_ptr);
}

static PyObject *
WindFarm_get_wind_farm_wake_model(WindFarmObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindFarm_wind_farm_wake_model_fget, self->data_ptr);
}

static int
WindFarm_set_wind_farm_wake_model(WindFarmObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindFarm_wind_farm_wake_model_fset, self->data_ptr);
}

static PyObject *
WindFarm_get_wind_farm_xCoordinates(WindFarmObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_WindFarm_wind_farm_xCoordinates_aget, self->data_ptr);
}

static int
WindFarm_set_wind_farm_xCoordinates(WindFarmObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Windpower_WindFarm_wind_farm_xCoordinates_aset, self->data_ptr);
}

static PyObject *
WindFarm_get_wind_farm_yCoordinates(WindFarmObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_WindFarm_wind_farm_yCoordinates_aget, self->data_ptr);
}

static int
WindFarm_set_wind_farm_yCoordinates(WindFarmObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Windpower_WindFarm_wind_farm_yCoordinates_aset, self->data_ptr);
}

static PyObject *
WindFarm_get_wind_resource_turbulence_coeff(WindFarmObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindFarm_wind_resource_turbulence_coeff_fget, self->data_ptr);
}

static int
WindFarm_set_wind_resource_turbulence_coeff(WindFarmObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindFarm_wind_resource_turbulence_coeff_fset, self->data_ptr);
}

static PyGetSetDef WindFarm_getset[] = {
{"system_capacity", (getter)WindFarm_get_system_capacity,(setter)WindFarm_set_system_capacity,
	"Nameplate capacity [kW], number.\n Constraints: MIN=0; Required if: *.",
 	NULL},
{"wind_farm_losses_percent", (getter)WindFarm_get_wind_farm_losses_percent,(setter)WindFarm_set_wind_farm_losses_percent,
	"Percentage losses [%], number.\n Required if: *.",
 	NULL},
{"wind_farm_wake_model", (getter)WindFarm_get_wind_farm_wake_model,(setter)WindFarm_set_wind_farm_wake_model,
	"Wake Model [0/1/2], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"wind_farm_xCoordinates", (getter)WindFarm_get_wind_farm_xCoordinates,(setter)WindFarm_set_wind_farm_xCoordinates,
	"Turbine X coordinates [m], array.\n Required if: *.",
 	NULL},
{"wind_farm_yCoordinates", (getter)WindFarm_get_wind_farm_yCoordinates,(setter)WindFarm_set_wind_farm_yCoordinates,
	"Turbine Y coordinates [m], array.\n Constraints: LENGTH_EQUAL=wind_farm_xCoordinates; Required if: *.",
 	NULL},
{"wind_resource_turbulence_coeff", (getter)WindFarm_get_wind_resource_turbulence_coeff,(setter)WindFarm_set_wind_resource_turbulence_coeff,
	"Turbulence coefficient [%], number.\n Constraints: MIN=0; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindFarm_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.WindFarm",             /*tp_name*/
		sizeof(WindFarmObject),          /*tp_basicsize*/
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
		WindFarm_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindFarm_getset,          /*tp_getset*/
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
	 * WindPower Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Windpower   data_ptr;
} WindPowerObject;

static PyTypeObject WindPower_Type;

static PyObject *
WindPower_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = WindPower_Type.tp_alloc(&WindPower_Type,0);

	WindPowerObject* WindPower_obj = (WindPowerObject*)new_obj;

	WindPower_obj->data_ptr = data_ptr;

	return new_obj;
}

/* WindPower methods */

static PyObject *
WindPower_assign(WindPowerObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "WindPower")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindPower_export(WindPowerObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindPower_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindPower_methods[] = {
		{"assign",            (PyCFunction)WindPower_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)WindPower_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindPower_get_en_icing_cutoff(WindPowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindPower_en_icing_cutoff_fget, self->data_ptr);
}

static int
WindPower_set_en_icing_cutoff(WindPowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindPower_en_icing_cutoff_fset, self->data_ptr);
}

static PyObject *
WindPower_get_en_low_temp_cutoff(WindPowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindPower_en_low_temp_cutoff_fget, self->data_ptr);
}

static int
WindPower_set_en_low_temp_cutoff(WindPowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindPower_en_low_temp_cutoff_fset, self->data_ptr);
}

static PyObject *
WindPower_get_icing_cutoff_rh(WindPowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindPower_icing_cutoff_rh_fget, self->data_ptr);
}

static int
WindPower_set_icing_cutoff_rh(WindPowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindPower_icing_cutoff_rh_fset, self->data_ptr);
}

static PyObject *
WindPower_get_icing_cutoff_temp(WindPowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindPower_icing_cutoff_temp_fget, self->data_ptr);
}

static int
WindPower_set_icing_cutoff_temp(WindPowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindPower_icing_cutoff_temp_fset, self->data_ptr);
}

static PyObject *
WindPower_get_low_temp_cutoff(WindPowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindPower_low_temp_cutoff_fget, self->data_ptr);
}

static int
WindPower_set_low_temp_cutoff(WindPowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindPower_low_temp_cutoff_fset, self->data_ptr);
}

static PyObject *
WindPower_get_wind_resource_model_choice(WindPowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindPower_wind_resource_model_choice_fget, self->data_ptr);
}

static int
WindPower_set_wind_resource_model_choice(WindPowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindPower_wind_resource_model_choice_fset, self->data_ptr);
}

static PyGetSetDef WindPower_getset[] = {
{"en_icing_cutoff", (getter)WindPower_get_en_icing_cutoff,(setter)WindPower_set_en_icing_cutoff,
	"Enable Icing Cutoff [0/1], number.\n Constraints: INTEGER; Required if: ?=0.",
 	NULL},
{"en_low_temp_cutoff", (getter)WindPower_get_en_low_temp_cutoff,(setter)WindPower_set_en_low_temp_cutoff,
	"Enable Low Temperature Cutoff [0/1], number.\n Constraints: INTEGER; Required if: ?=0.",
 	NULL},
{"icing_cutoff_rh", (getter)WindPower_get_icing_cutoff_rh,(setter)WindPower_set_icing_cutoff_rh,
	"Icing Cutoff Relative Humidity [%], number.\n Constraints: MIN=0; Required if: en_icing_cutoff=1.",
 	NULL},
{"icing_cutoff_temp", (getter)WindPower_get_icing_cutoff_temp,(setter)WindPower_set_icing_cutoff_temp,
	"Icing Cutoff Temperature [C], number.\n Required if: en_icing_cutoff=1.",
 	NULL},
{"low_temp_cutoff", (getter)WindPower_get_low_temp_cutoff,(setter)WindPower_set_low_temp_cutoff,
	"Low Temperature Cutoff [C], number.\n Required if: en_low_temp_cutoff=1.",
 	NULL},
{"wind_resource_model_choice", (getter)WindPower_get_wind_resource_model_choice,(setter)WindPower_set_wind_resource_model_choice,
	"Hourly or Weibull model [0/1], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindPower_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.WindPower",             /*tp_name*/
		sizeof(WindPowerObject),          /*tp_basicsize*/
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
		WindPower_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindPower_getset,          /*tp_getset*/
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
	 * WindSpeedWeibullDistribution Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Windpower   data_ptr;
} WindSpeedWeibullDistributionObject;

static PyTypeObject WindSpeedWeibullDistribution_Type;

static PyObject *
WindSpeedWeibullDistribution_new(SAM_Windpower data_ptr)
{
	PyObject* new_obj = WindSpeedWeibullDistribution_Type.tp_alloc(&WindSpeedWeibullDistribution_Type,0);

	WindSpeedWeibullDistributionObject* WindSpeedWeibullDistribution_obj = (WindSpeedWeibullDistributionObject*)new_obj;

	WindSpeedWeibullDistribution_obj->data_ptr = data_ptr;

	return new_obj;
}

/* WindSpeedWeibullDistribution methods */

static PyObject *
WindSpeedWeibullDistribution_assign(WindSpeedWeibullDistributionObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "WindSpeedWeibullDistribution")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindSpeedWeibullDistribution_export(WindSpeedWeibullDistributionObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindSpeedWeibullDistribution_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindSpeedWeibullDistribution_methods[] = {
		{"assign",            (PyCFunction)WindSpeedWeibullDistribution_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)WindSpeedWeibullDistribution_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindSpeedWeibullDistribution_get_weibull_k_factor(WindSpeedWeibullDistributionObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindSpeedWeibullDistribution_weibull_k_factor_fget, self->data_ptr);
}

static int
WindSpeedWeibullDistribution_set_weibull_k_factor(WindSpeedWeibullDistributionObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindSpeedWeibullDistribution_weibull_k_factor_fset, self->data_ptr);
}

static PyObject *
WindSpeedWeibullDistribution_get_weibull_reference_height(WindSpeedWeibullDistributionObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindSpeedWeibullDistribution_weibull_reference_height_fget, self->data_ptr);
}

static int
WindSpeedWeibullDistribution_set_weibull_reference_height(WindSpeedWeibullDistributionObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindSpeedWeibullDistribution_weibull_reference_height_fset, self->data_ptr);
}

static PyObject *
WindSpeedWeibullDistribution_get_weibull_wind_speed(WindSpeedWeibullDistributionObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_WindSpeedWeibullDistribution_weibull_wind_speed_fget, self->data_ptr);
}

static int
WindSpeedWeibullDistribution_set_weibull_wind_speed(WindSpeedWeibullDistributionObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Windpower_WindSpeedWeibullDistribution_weibull_wind_speed_fset, self->data_ptr);
}

static PyGetSetDef WindSpeedWeibullDistribution_getset[] = {
{"weibull_k_factor", (getter)WindSpeedWeibullDistribution_get_weibull_k_factor,(setter)WindSpeedWeibullDistribution_set_weibull_k_factor,
	"Weibull K factor for wind resource [], number.\n Required if: wind_resource_model_choice=1.",
 	NULL},
{"weibull_reference_height", (getter)WindSpeedWeibullDistribution_get_weibull_reference_height,(setter)WindSpeedWeibullDistribution_set_weibull_reference_height,
	"Reference height for Weibull wind speed [m], number.\n Constraints: MIN=0; Required if: ?=50.",
 	NULL},
{"weibull_wind_speed", (getter)WindSpeedWeibullDistribution_get_weibull_wind_speed,(setter)WindSpeedWeibullDistribution_set_weibull_wind_speed,
	"Average wind speed for Weibull model [], number.\n Constraints: MIN=0; Required if: wind_resource_model_choice=1.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindSpeedWeibullDistribution_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.WindSpeedWeibullDistribution",             /*tp_name*/
		sizeof(WindSpeedWeibullDistributionObject),          /*tp_basicsize*/
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
		WindSpeedWeibullDistribution_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindSpeedWeibullDistribution_getset,          /*tp_getset*/
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
	SAM_Windpower   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Windpower data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windpower", "Outputs")){
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
	return PySAM_float_getter(SAM_Windpower_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_cutoff_losses(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_Outputs_cutoff_losses_fget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Windpower_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pressure(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_pressure_aget, self->data_ptr);
}

static PyObject *
Outputs_get_temp(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_temp_aget, self->data_ptr);
}

static PyObject *
Outputs_get_turbine_output_by_windspeed_bin(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_turbine_output_by_windspeed_bin_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_direction(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_wind_direction_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wind_speed(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Windpower_Outputs_wind_speed_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual Energy [kWh], number.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"cutoff_losses", (getter)Outputs_get_cutoff_losses,(setter)0,
	"Cutoff losses [%], number.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"Total electric power to grid [kWh], array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly Energy [kWh], array.",
 	NULL},
{"pressure", (getter)Outputs_get_pressure,(setter)0,
	"Pressure [atm], array.",
 	NULL},
{"temp", (getter)Outputs_get_temp,(setter)0,
	"Air temperature ['C], array.",
 	NULL},
{"turbine_output_by_windspeed_bin", (getter)Outputs_get_turbine_output_by_windspeed_bin,(setter)0,
	"Turbine output by wind speed bin [kW], array.",
 	NULL},
{"wind_direction", (getter)Outputs_get_wind_direction,(setter)0,
	"Wind direction [deg], array.",
 	NULL},
{"wind_speed", (getter)Outputs_get_wind_speed,(setter)0,
	"Wind speed [m/s], array.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower.Outputs",             /*tp_name*/
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
 * Windpower
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Windpower   data_ptr;
} WindpowerObject;

static PyTypeObject Windpower_Type;

#define WindpowerObject_Check(v)      (Py_TYPE(v) == &Windpower_Type)

static WindpowerObject *
newWindpowerObject(void* data_ptr)
{
	WindpowerObject *self;
	self = PyObject_New(WindpowerObject, &Windpower_Type);

	PySAM_TECH_ATTR("Windpower", SAM_Windpower_construct)

PyObject* WindResourceFile_obj = WindResourceFile_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindResourceFile", WindResourceFile_obj);
	Py_DECREF(WindResourceFile_obj);

PyObject* WindTurbine_obj = WindTurbine_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindTurbine", WindTurbine_obj);
	Py_DECREF(WindTurbine_obj);

PyObject* WindFarm_obj = WindFarm_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindFarm", WindFarm_obj);
	Py_DECREF(WindFarm_obj);

PyObject* WindPower_obj = WindPower_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindPower", WindPower_obj);
	Py_DECREF(WindPower_obj);

PyObject* WindSpeedWeibullDistribution_obj = WindSpeedWeibullDistribution_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindSpeedWeibullDistribution", WindSpeedWeibullDistribution_obj);
	Py_DECREF(WindSpeedWeibullDistribution_obj);

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

/* Windpower methods */

static void
Windpower_dealloc(WindpowerObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Windpower_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Windpower_execute(WindpowerObject *self, PyObject *args)
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
Windpower_assign(WindpowerObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict(self, self->x_attr, self->data_ptr, dict, "Windpower"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Windpower_export(WindpowerObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}


static PyMethodDef Windpower_methods[] = {
		{"execute",            (PyCFunction)Windpower_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Windpower_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Windpower_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Windpower_getattro(WindpowerObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Windpower_setattr(WindpowerObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Windpower_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windpower",            /*tp_name*/
		sizeof(WindpowerObject),/*tp_basicsize*/
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
		"see html for help",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistoffset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Windpower_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Windpower object */

static PyObject *
Windpower_new(PyObject *self, PyObject *args)
{
	WindpowerObject *rv;
	rv = newWindpowerObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Windpower_wrap(PyObject *self, PyObject *args)
{
	WindpowerObject *rv;
	long int ptr = 0;
	if (!PyArg_ParseTuple(args, "l:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindpowerObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Windpower_default(PyObject *self, PyObject *args)
{
	WindpowerObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindpowerObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults(rv, rv->x_attr, rv->data_ptr, "Windpower", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WindpowerModule_methods[] = {
		{"new",             Windpower_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Windpower object")},
		{"wrap",             Windpower_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Windpower object around existing data")},
		{"default",             Windpower_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Windpower object with financial model-specific default attributes")},		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "This is a template module just for instruction.");


static int
WindpowerModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

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

	/// Add the WindResourceFile type object to Windpower_Type
	if (PyType_Ready(&WindResourceFile_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"WindResourceFile",
				(PyObject*)&WindResourceFile_Type);
	Py_DECREF(&WindResourceFile_Type);

	/// Add the WindTurbine type object to Windpower_Type
	if (PyType_Ready(&WindTurbine_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"WindTurbine",
				(PyObject*)&WindTurbine_Type);
	Py_DECREF(&WindTurbine_Type);

	/// Add the WindFarm type object to Windpower_Type
	if (PyType_Ready(&WindFarm_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"WindFarm",
				(PyObject*)&WindFarm_Type);
	Py_DECREF(&WindFarm_Type);

	/// Add the WindPower type object to Windpower_Type
	if (PyType_Ready(&WindPower_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"WindPower",
				(PyObject*)&WindPower_Type);
	Py_DECREF(&WindPower_Type);

	/// Add the WindSpeedWeibullDistribution type object to Windpower_Type
	if (PyType_Ready(&WindSpeedWeibullDistribution_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windpower_Type.tp_dict,
				"WindSpeedWeibullDistribution",
				(PyObject*)&WindSpeedWeibullDistribution_Type);
	Py_DECREF(&WindSpeedWeibullDistribution_Type);

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

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

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