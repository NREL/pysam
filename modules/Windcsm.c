#include <Python.h>

#include <SAM_Windcsm.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WindCsm Group
 */ 

static PyTypeObject WindCsm_Type;

static PyObject *
WindCsm_new(SAM_Windcsm data_ptr)
{
	PyObject* new_obj = WindCsm_Type.tp_alloc(&WindCsm_Type,0);

	VarGroupObject* WindCsm_obj = (VarGroupObject*)new_obj;

	WindCsm_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* WindCsm methods */

static PyObject *
WindCsm_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windcsm", "WindCsm")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindCsm_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindCsm_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindCsm_methods[] = {
		{"assign",            (PyCFunction)WindCsm_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``WindCsm_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)WindCsm_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindCsm_get_hub_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_hub_height_nget, self->data_ptr);
}

static int
WindCsm_set_hub_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_hub_height_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_machine_rating(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_machine_rating_nget, self->data_ptr);
}

static int
WindCsm_set_machine_rating(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_machine_rating_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_num_bearings(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_num_bearings_nget, self->data_ptr);
}

static int
WindCsm_set_num_bearings(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_num_bearings_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_num_blades(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_num_blades_nget, self->data_ptr);
}

static int
WindCsm_set_num_blades(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_num_blades_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_onboard_crane(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_onboard_crane_nget, self->data_ptr);
}

static int
WindCsm_set_onboard_crane(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_onboard_crane_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_rotor_torque(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_rotor_torque_nget, self->data_ptr);
}

static int
WindCsm_set_rotor_torque(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_rotor_torque_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_turbine_carbon_blades(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_turbine_carbon_blades_nget, self->data_ptr);
}

static int
WindCsm_set_turbine_carbon_blades(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_turbine_carbon_blades_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_turbine_class(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_turbine_class_nget, self->data_ptr);
}

static int
WindCsm_set_turbine_class(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_turbine_class_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_turbine_rotor_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_turbine_rotor_diameter_nget, self->data_ptr);
}

static int
WindCsm_set_turbine_rotor_diameter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_turbine_rotor_diameter_nset, self->data_ptr);
}

static PyObject *
WindCsm_get_turbine_user_exponent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_WindCsm_turbine_user_exponent_nget, self->data_ptr);
}

static int
WindCsm_set_turbine_user_exponent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windcsm_WindCsm_turbine_user_exponent_nset, self->data_ptr);
}

static PyGetSetDef WindCsm_getset[] = {
{"hub_height", (getter)WindCsm_get_hub_height,(setter)WindCsm_set_hub_height,
	PyDoc_STR("*float*: Hub height [m]\n\n*Required*: True"),
 	NULL},
{"machine_rating", (getter)WindCsm_get_machine_rating,(setter)WindCsm_set_machine_rating,
	PyDoc_STR("*float*: Machine rating [kW]\n\n*Required*: True"),
 	NULL},
{"num_bearings", (getter)WindCsm_get_num_bearings,(setter)WindCsm_set_num_bearings,
	PyDoc_STR("*float*: Number of main bearings\n\n*Constraints*: INTEGER,MIN=1\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"num_blades", (getter)WindCsm_get_num_blades,(setter)WindCsm_set_num_blades,
	PyDoc_STR("*float*: Number of blades\n\n*Constraints*: INTEGER,MIN=1\n\n*Required*: If not provided, assumed to be 3"),
 	NULL},
{"onboard_crane", (getter)WindCsm_get_onboard_crane,(setter)WindCsm_set_onboard_crane,
	PyDoc_STR("*float*: Onboard crane [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"rotor_torque", (getter)WindCsm_get_rotor_torque,(setter)WindCsm_set_rotor_torque,
	PyDoc_STR("*float*: Rotor torque [Nm]\n\n*Required*: True"),
 	NULL},
{"turbine_carbon_blades", (getter)WindCsm_get_turbine_carbon_blades,(setter)WindCsm_set_turbine_carbon_blades,
	PyDoc_STR("*float*: Turbine carbon blades [0/1]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"turbine_class", (getter)WindCsm_get_turbine_class,(setter)WindCsm_set_turbine_class,
	PyDoc_STR("*float*: Turbine class\n\n*Constraints*: INTEGER,MIN=0,MAX=3\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"turbine_rotor_diameter", (getter)WindCsm_get_turbine_rotor_diameter,(setter)WindCsm_set_turbine_rotor_diameter,
	PyDoc_STR("*float*: Turbine rotor diameter [m]\n\n*Required*: True"),
 	NULL},
{"turbine_user_exponent", (getter)WindCsm_get_turbine_user_exponent,(setter)WindCsm_set_turbine_user_exponent,
	PyDoc_STR("*float*: Turbine user exponent\n\n*Required*: If not provided, assumed to be 2.5"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindCsm_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windcsm.WindCsm",             /*tp_name*/
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
		WindCsm_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindCsm_getset,          /*tp_getset*/
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
Outputs_new(SAM_Windcsm data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windcsm", "Outputs")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_bedplate_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_bedplate_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_blade_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_blade_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_controls_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_controls_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_drivetrain_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_drivetrain_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_drivetrain_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_drivetrain_mass_nget, self->data_ptr);
}

static PyObject *
Outputs_get_electrical_connections_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_electrical_connections_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gearbox_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_gearbox_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_generator_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_generator_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_high_speed_side_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_high_speed_side_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hub_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_hub_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hvac_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_hvac_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_low_speed_side_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_low_speed_side_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_main_bearings_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_main_bearings_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mainframe_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_mainframe_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pitch_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_pitch_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rotor_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_rotor_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_rotor_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_rotor_mass_nget, self->data_ptr);
}

static PyObject *
Outputs_get_spinner_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_spinner_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tower_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_tower_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tower_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_tower_mass_nget, self->data_ptr);
}

static PyObject *
Outputs_get_transformer_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_transformer_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_turbine_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_turbine_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_variable_speed_electronics_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_variable_speed_electronics_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_yaw_system_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windcsm_Outputs_yaw_system_cost_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"bedplate_cost", (getter)Outputs_get_bedplate_cost,(setter)0,
	PyDoc_STR("*float*: Bedplate cost [$]"),
 	NULL},
{"blade_cost", (getter)Outputs_get_blade_cost,(setter)0,
	PyDoc_STR("*float*: Rotor cost [$]"),
 	NULL},
{"controls_cost", (getter)Outputs_get_controls_cost,(setter)0,
	PyDoc_STR("*float*: Controls cost [$]"),
 	NULL},
{"drivetrain_cost", (getter)Outputs_get_drivetrain_cost,(setter)0,
	PyDoc_STR("*float*: Drivetrain cost [$]"),
 	NULL},
{"drivetrain_mass", (getter)Outputs_get_drivetrain_mass,(setter)0,
	PyDoc_STR("*float*: Drivetrain mass [kg]"),
 	NULL},
{"electrical_connections_cost", (getter)Outputs_get_electrical_connections_cost,(setter)0,
	PyDoc_STR("*float*: Electrical connections cost [$]"),
 	NULL},
{"gearbox_cost", (getter)Outputs_get_gearbox_cost,(setter)0,
	PyDoc_STR("*float*: Gearbox cost [$]"),
 	NULL},
{"generator_cost", (getter)Outputs_get_generator_cost,(setter)0,
	PyDoc_STR("*float*: Generator cost [$]"),
 	NULL},
{"high_speed_side_cost", (getter)Outputs_get_high_speed_side_cost,(setter)0,
	PyDoc_STR("*float*: High speed side cost [$]"),
 	NULL},
{"hub_cost", (getter)Outputs_get_hub_cost,(setter)0,
	PyDoc_STR("*float*: Hub cost [$]"),
 	NULL},
{"hvac_cost", (getter)Outputs_get_hvac_cost,(setter)0,
	PyDoc_STR("*float*: HVAC cost [$]"),
 	NULL},
{"low_speed_side_cost", (getter)Outputs_get_low_speed_side_cost,(setter)0,
	PyDoc_STR("*float*: Low speed side cost [$]"),
 	NULL},
{"main_bearings_cost", (getter)Outputs_get_main_bearings_cost,(setter)0,
	PyDoc_STR("*float*: Main bearings cost [$]"),
 	NULL},
{"mainframe_cost", (getter)Outputs_get_mainframe_cost,(setter)0,
	PyDoc_STR("*float*: Mainframe cost [$]"),
 	NULL},
{"pitch_cost", (getter)Outputs_get_pitch_cost,(setter)0,
	PyDoc_STR("*float*: Pitch cost [$]"),
 	NULL},
{"rotor_cost", (getter)Outputs_get_rotor_cost,(setter)0,
	PyDoc_STR("*float*: Rotor cost [$]"),
 	NULL},
{"rotor_mass", (getter)Outputs_get_rotor_mass,(setter)0,
	PyDoc_STR("*float*: Rotor mass [kg]"),
 	NULL},
{"spinner_cost", (getter)Outputs_get_spinner_cost,(setter)0,
	PyDoc_STR("*float*: Spinner cost [$]"),
 	NULL},
{"tower_cost", (getter)Outputs_get_tower_cost,(setter)0,
	PyDoc_STR("*float*: Tower cost [$]"),
 	NULL},
{"tower_mass", (getter)Outputs_get_tower_mass,(setter)0,
	PyDoc_STR("*float*: Tower mass [kg]"),
 	NULL},
{"transformer_cost", (getter)Outputs_get_transformer_cost,(setter)0,
	PyDoc_STR("*float*: Transformer cost [$]"),
 	NULL},
{"turbine_cost", (getter)Outputs_get_turbine_cost,(setter)0,
	PyDoc_STR("*float*: Turbine cost [$]"),
 	NULL},
{"variable_speed_electronics_cost", (getter)Outputs_get_variable_speed_electronics_cost,(setter)0,
	PyDoc_STR("*float*: Variable speed electronics cost [$]"),
 	NULL},
{"yaw_system_cost", (getter)Outputs_get_yaw_system_cost,(setter)0,
	PyDoc_STR("*float*: Yaw system cost [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windcsm.Outputs",             /*tp_name*/
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
 * Windcsm
 */

static PyTypeObject Windcsm_Type;

static CmodObject *
newWindcsmObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Windcsm_Type);

	PySAM_TECH_ATTR()

	PyObject* WindCsm_obj = WindCsm_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindCsm", WindCsm_obj);
	Py_DECREF(WindCsm_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Windcsm methods */

static void
Windcsm_dealloc(CmodObject *self)
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
Windcsm_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Windcsm_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Windcsm_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Windcsm"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Windcsm_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Windcsm_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Windcsm_methods[] = {
		{"execute",            (PyCFunction)Windcsm_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Windcsm_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'wind_csm': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Windcsm_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Windcsm_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Windcsm_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Windcsm_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Windcsm_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windcsm",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Windcsm_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Windcsm_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Windcsm_getattro, /*tp_getattro*/
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
		Windcsm_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Windcsm object */

static PyObject *
Windcsm_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWindcsmObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Windcsm_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindcsmObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Windcsm_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindcsmObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Windcsm", def);

	return (PyObject *)rv;
}

static PyObject *
Windcsm_from_existing(PyObject *self, PyObject *args)
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

	rv = newWindcsmObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Windcsm", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WindcsmModule_methods[] = {
		{"new",             Windcsm_new,         METH_VARARGS,
				PyDoc_STR("new() -> Windcsm")},
		{"default",             Windcsm_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Windcsm\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Windcsm_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Windcsm\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Windcsm_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Windcsm\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Windcsm");


static int
WindcsmModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Windcsm_Type.tp_dict = PyDict_New();
	if (!Windcsm_Type.tp_dict) { goto fail; }

	/// Add the WindCsm type object to Windcsm_Type
	if (PyType_Ready(&WindCsm_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windcsm_Type.tp_dict,
				"WindCsm",
				(PyObject*)&WindCsm_Type);
	Py_DECREF(&WindCsm_Type);

	/// Add the Outputs type object to Windcsm_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windcsm_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Windcsm type object to the module
	if (PyType_Ready(&Windcsm_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Windcsm",
				(PyObject*)&Windcsm_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WindcsmModule_slots[] = {
		{Py_mod_exec, WindcsmModule_exec},
		{0, NULL},
};

static struct PyModuleDef WindcsmModule = {
		PyModuleDef_HEAD_INIT,
		"Windcsm",
		module_doc,
		0,
		WindcsmModule_methods,
		WindcsmModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Windcsm(void)
{
	return PyModuleDef_Init(&WindcsmModule);
}