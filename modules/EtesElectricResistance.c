#include <Python.h>

#include <SAM_EtesElectricResistance.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SolarResource Group
 */ 

static PyTypeObject SolarResource_Type;

static PyObject *
SolarResource_new(SAM_EtesElectricResistance data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "SolarResource")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SolarResource_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SolarResource_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SolarResource_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_EtesElectricResistance_SolarResource_solar_resource_file_sget, self->data_ptr);
}

static int
SolarResource_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_EtesElectricResistance_SolarResource_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef SolarResource_getset[] = {
{"solar_resource_file", (getter)SolarResource_get_solar_resource_file,(setter)SolarResource_set_solar_resource_file,
	PyDoc_STR("*str*: Local weather file path\n\n*Constraints*: LOCAL_FILE\n\n*Required*: False"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SolarResource_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.SolarResource",             /*tp_name*/
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
 * SystemControl Group
 */ 

static PyTypeObject SystemControl_Type;

static PyObject *
SystemControl_new(SAM_EtesElectricResistance data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "SystemControl")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemControl_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemControl_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemControl_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_SystemControl_F_wc_aget, self->data_ptr);
}

static int
SystemControl_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_EtesElectricResistance_SystemControl_F_wc_aset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_bop_par_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_bop_par_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_bop_par_0_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_bop_par_0_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_bop_par_1_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_bop_par_1_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_bop_par_2_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_bop_par_2_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_bop_par_f(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_bop_par_f_nget, self->data_ptr);
}

static int
SystemControl_set_bop_par_f(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_bop_par_f_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_is_dispatch(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_is_dispatch_nget, self->data_ptr);
}

static int
SystemControl_set_is_dispatch(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_is_dispatch_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_pb_fixed_par_nget, self->data_ptr);
}

static int
SystemControl_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_time_start_nget, self->data_ptr);
}

static int
SystemControl_set_time_start(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_time_start_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_steps_per_hour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_time_steps_per_hour_nget, self->data_ptr);
}

static int
SystemControl_set_time_steps_per_hour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_time_steps_per_hour_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_time_stop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_time_stop_nget, self->data_ptr);
}

static int
SystemControl_set_time_stop(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_time_stop_nset, self->data_ptr);
}

static PyObject *
SystemControl_get_vacuum_arrays(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemControl_vacuum_arrays_nget, self->data_ptr);
}

static int
SystemControl_set_vacuum_arrays(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemControl_vacuum_arrays_nset, self->data_ptr);
}

static PyGetSetDef SystemControl_getset[] = {
{"F_wc", (getter)SystemControl_get_F_wc,(setter)SystemControl_set_F_wc,
	PyDoc_STR("*sequence*: TOU array of fractions indicating wet cooling share for hybrid cooling\n\n*Required*: True if pc_config=0"),
 	NULL},
{"bop_par", (getter)SystemControl_get_bop_par,(setter)SystemControl_set_bop_par,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction [MWe/MWcap]\n\n*Required*: True"),
 	NULL},
{"bop_par_0", (getter)SystemControl_get_bop_par_0,(setter)SystemControl_set_bop_par_0,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - const coeff\n\n*Required*: True"),
 	NULL},
{"bop_par_1", (getter)SystemControl_get_bop_par_1,(setter)SystemControl_set_bop_par_1,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - linear coeff\n\n*Required*: True"),
 	NULL},
{"bop_par_2", (getter)SystemControl_get_bop_par_2,(setter)SystemControl_set_bop_par_2,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - quadratic coeff\n\n*Required*: True"),
 	NULL},
{"bop_par_f", (getter)SystemControl_get_bop_par_f,(setter)SystemControl_set_bop_par_f,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - mult frac\n\n*Required*: True"),
 	NULL},
{"is_dispatch", (getter)SystemControl_get_is_dispatch,(setter)SystemControl_set_is_dispatch,
	PyDoc_STR("*float*: Allow dispatch optimization?\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"pb_fixed_par", (getter)SystemControl_get_pb_fixed_par,(setter)SystemControl_set_pb_fixed_par,
	PyDoc_STR("*float*: Fixed parasitic load that don't generate heat - runs at all times [MWe/MWcap]\n\n*Required*: True"),
 	NULL},
{"time_start", (getter)SystemControl_get_time_start,(setter)SystemControl_set_time_start,
	PyDoc_STR("*float*: Simulation start time [s]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"time_steps_per_hour", (getter)SystemControl_get_time_steps_per_hour,(setter)SystemControl_set_time_steps_per_hour,
	PyDoc_STR("*float*: Number of simulation time steps per hour\n\n*Required*: If not provided, assumed to be -1"),
 	NULL},
{"time_stop", (getter)SystemControl_get_time_stop,(setter)SystemControl_set_time_stop,
	PyDoc_STR("*float*: Simulation stop time [s]\n\n*Required*: If not provided, assumed to be 31536000"),
 	NULL},
{"vacuum_arrays", (getter)SystemControl_get_vacuum_arrays,(setter)SystemControl_set_vacuum_arrays,
	PyDoc_STR("*float*: Allocate arrays for only the required number of steps\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemControl_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.SystemControl",             /*tp_name*/
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
 * SystemDesign Group
 */ 

static PyTypeObject SystemDesign_Type;

static PyObject *
SystemDesign_new(SAM_EtesElectricResistance data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "SystemDesign")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemDesign_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemDesign_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemDesign_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_P_ref_nget, self->data_ptr);
}

static int
SystemDesign_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_P_ref_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_htf_cold_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_T_htf_cold_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_htf_cold_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_T_htf_cold_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_T_htf_hot_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_T_htf_hot_des_nget, self->data_ptr);
}

static int
SystemDesign_set_T_htf_hot_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_T_htf_hot_des_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_design_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_design_eff_nget, self->data_ptr);
}

static int
SystemDesign_set_design_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_design_eff_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_gross_net_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_gross_net_conversion_factor_nget, self->data_ptr);
}

static int
SystemDesign_set_gross_net_conversion_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_gross_net_conversion_factor_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_heater_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_heater_mult_nget, self->data_ptr);
}

static int
SystemDesign_set_heater_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_heater_mult_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_tshours(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemDesign_tshours_nget, self->data_ptr);
}

static int
SystemDesign_set_tshours(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemDesign_tshours_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"P_ref", (getter)SystemDesign_get_P_ref,(setter)SystemDesign_set_P_ref,
	PyDoc_STR("*float*: Reference output electric power at design condition [MW]\n\n*Required*: True"),
 	NULL},
{"T_htf_cold_des", (getter)SystemDesign_get_T_htf_cold_des,(setter)SystemDesign_set_T_htf_cold_des,
	PyDoc_STR("*float*: Cold HTF inlet temperature at design conditions [C]\n\n*Required*: True"),
 	NULL},
{"T_htf_hot_des", (getter)SystemDesign_get_T_htf_hot_des,(setter)SystemDesign_set_T_htf_hot_des,
	PyDoc_STR("*float*: Hot HTF outlet temperature at design conditions [C]\n\n*Required*: True"),
 	NULL},
{"design_eff", (getter)SystemDesign_get_design_eff,(setter)SystemDesign_set_design_eff,
	PyDoc_STR("*float*: Power cycle efficiency at design [none]\n\n*Required*: True"),
 	NULL},
{"gross_net_conversion_factor", (getter)SystemDesign_get_gross_net_conversion_factor,(setter)SystemDesign_set_gross_net_conversion_factor,
	PyDoc_STR("*float*: Estimated gross to net conversion factor\n\n*Required*: True"),
 	NULL},
{"heater_mult", (getter)SystemDesign_get_heater_mult,(setter)SystemDesign_set_heater_mult,
	PyDoc_STR("*float*: Heater multiple relative to design cycle thermal power [-]\n\n*Required*: True"),
 	NULL},
{"tshours", (getter)SystemDesign_get_tshours,(setter)SystemDesign_set_tshours,
	PyDoc_STR("*float*: Equivalent full-load thermal storage hours [hr]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.SystemDesign",             /*tp_name*/
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
 * PowerCycle Group
 */ 

static PyTypeObject PowerCycle_Type;

static PyObject *
PowerCycle_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = PowerCycle_Type.tp_alloc(&PowerCycle_Type,0);

	VarGroupObject* PowerCycle_obj = (VarGroupObject*)new_obj;

	PowerCycle_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PowerCycle methods */

static PyObject *
PowerCycle_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "PowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PowerCycle_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PowerCycle_methods[] = {
		{"assign",            (PyCFunction)PowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``PowerCycle_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PowerCycle_get_cycle_cutoff_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_cycle_cutoff_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_cycle_cutoff_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_cycle_cutoff_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_cycle_max_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_pb_pump_coef(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_pb_pump_coef_nget, self->data_ptr);
}

static int
PowerCycle_set_pb_pump_coef(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_pb_pump_coef_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_pc_config(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_pc_config_nget, self->data_ptr);
}

static int
PowerCycle_set_pc_config(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_pc_config_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_q_sby_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_startup_frac_nget, self->data_ptr);
}

static int
PowerCycle_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_startup_frac_nset, self->data_ptr);
}

static PyObject *
PowerCycle_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_PowerCycle_startup_time_nget, self->data_ptr);
}

static int
PowerCycle_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_PowerCycle_startup_time_nset, self->data_ptr);
}

static PyGetSetDef PowerCycle_getset[] = {
{"cycle_cutoff_frac", (getter)PowerCycle_get_cycle_cutoff_frac,(setter)PowerCycle_set_cycle_cutoff_frac,
	PyDoc_STR("*float*: Minimum turbine operation fraction before shutdown\n\n*Required*: True"),
 	NULL},
{"cycle_max_frac", (getter)PowerCycle_get_cycle_max_frac,(setter)PowerCycle_set_cycle_max_frac,
	PyDoc_STR("*float*: Maximum turbine over design operation fraction\n\n*Required*: True"),
 	NULL},
{"pb_pump_coef", (getter)PowerCycle_get_pb_pump_coef,(setter)PowerCycle_set_pb_pump_coef,
	PyDoc_STR("*float*: Pumping power to move 1kg of HTF through PB loop [kW/kg]\n\n*Required*: True"),
 	NULL},
{"pc_config", (getter)PowerCycle_get_pc_config,(setter)PowerCycle_set_pc_config,
	PyDoc_STR("*float*: PC configuration 0=Steam Rankine, 1=user defined\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"q_sby_frac", (getter)PowerCycle_get_q_sby_frac,(setter)PowerCycle_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby\n\n*Required*: True"),
 	NULL},
{"startup_frac", (getter)PowerCycle_get_startup_frac,(setter)PowerCycle_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n*Required*: True"),
 	NULL},
{"startup_time", (getter)PowerCycle_get_startup_time,(setter)PowerCycle_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.PowerCycle",             /*tp_name*/
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
		PowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PowerCycle_getset,          /*tp_getset*/
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
 * RankineCycle Group
 */ 

static PyTypeObject RankineCycle_Type;

static PyObject *
RankineCycle_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = RankineCycle_Type.tp_alloc(&RankineCycle_Type,0);

	VarGroupObject* RankineCycle_obj = (VarGroupObject*)new_obj;

	RankineCycle_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* RankineCycle methods */

static PyObject *
RankineCycle_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "RankineCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
RankineCycle_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &RankineCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef RankineCycle_methods[] = {
		{"assign",            (PyCFunction)RankineCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``RankineCycle_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)RankineCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
RankineCycle_get_CT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_CT_nget, self->data_ptr);
}

static int
RankineCycle_set_CT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_CT_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_P_boil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_P_boil_nget, self->data_ptr);
}

static int
RankineCycle_set_P_boil(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_P_boil_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_P_cond_min_nget, self->data_ptr);
}

static int
RankineCycle_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_P_cond_min_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_P_cond_ratio_nget, self->data_ptr);
}

static int
RankineCycle_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_T_ITD_des_nget, self->data_ptr);
}

static int
RankineCycle_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_T_amb_des_nget, self->data_ptr);
}

static int
RankineCycle_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_T_amb_des_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_T_approach_nget, self->data_ptr);
}

static int
RankineCycle_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_T_approach_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_dT_cw_ref_nget, self->data_ptr);
}

static int
RankineCycle_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_n_pl_inc_nget, self->data_ptr);
}

static int
RankineCycle_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_pb_bd_frac_nget, self->data_ptr);
}

static int
RankineCycle_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
RankineCycle_get_tech_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_RankineCycle_tech_type_nget, self->data_ptr);
}

static int
RankineCycle_set_tech_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_RankineCycle_tech_type_nset, self->data_ptr);
}

static PyGetSetDef RankineCycle_getset[] = {
{"CT", (getter)RankineCycle_get_CT,(setter)RankineCycle_set_CT,
	PyDoc_STR("*float*: Condensor type: 1=evaporative, 2=air, 3=hybrid\n\n*Required*: True if pc_config=0"),
 	NULL},
{"P_boil", (getter)RankineCycle_get_P_boil,(setter)RankineCycle_set_P_boil,
	PyDoc_STR("*float*: Boiler operating pressure [bar]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"P_cond_min", (getter)RankineCycle_get_P_cond_min,(setter)RankineCycle_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"P_cond_ratio", (getter)RankineCycle_get_P_cond_ratio,(setter)RankineCycle_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio\n\n*Required*: True if pc_config=0"),
 	NULL},
{"T_ITD_des", (getter)RankineCycle_get_T_ITD_des,(setter)RankineCycle_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"T_amb_des", (getter)RankineCycle_get_T_amb_des,(setter)RankineCycle_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"T_approach", (getter)RankineCycle_get_T_approach,(setter)RankineCycle_set_T_approach,
	PyDoc_STR("*float*: Cooling tower approach temperature [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"dT_cw_ref", (getter)RankineCycle_get_dT_cw_ref,(setter)RankineCycle_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet temperature difference [C]\n\n*Required*: True if pc_config=0"),
 	NULL},
{"n_pl_inc", (getter)RankineCycle_get_n_pl_inc,(setter)RankineCycle_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n*Constraints*: INTEGER\n\n*Required*: True if pc_config=0"),
 	NULL},
{"pb_bd_frac", (getter)RankineCycle_get_pb_bd_frac,(setter)RankineCycle_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction\n\n*Required*: True if pc_config=0"),
 	NULL},
{"tech_type", (getter)RankineCycle_get_tech_type,(setter)RankineCycle_set_tech_type,
	PyDoc_STR("*float*: Turbine inlet pressure control 1=Fixed, 3=Sliding\n\n*Required*: True if pc_config=0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject RankineCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.RankineCycle",             /*tp_name*/
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
		RankineCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		RankineCycle_getset,          /*tp_getset*/
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
 * UserDefinedPowerCycle Group
 */ 

static PyTypeObject UserDefinedPowerCycle_Type;

static PyObject *
UserDefinedPowerCycle_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = UserDefinedPowerCycle_Type.tp_alloc(&UserDefinedPowerCycle_Type,0);

	VarGroupObject* UserDefinedPowerCycle_obj = (VarGroupObject*)new_obj;

	UserDefinedPowerCycle_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* UserDefinedPowerCycle methods */

static PyObject *
UserDefinedPowerCycle_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "UserDefinedPowerCycle")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
UserDefinedPowerCycle_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &UserDefinedPowerCycle_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef UserDefinedPowerCycle_methods[] = {
		{"assign",            (PyCFunction)UserDefinedPowerCycle_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``UserDefinedPowerCycle_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)UserDefinedPowerCycle_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
UserDefinedPowerCycle_get_ud_f_W_dot_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_UserDefinedPowerCycle_ud_f_W_dot_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_f_W_dot_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_UserDefinedPowerCycle_ud_f_W_dot_cool_des_nset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_ind_od(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesElectricResistance_UserDefinedPowerCycle_ud_ind_od_mget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_ind_od(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesElectricResistance_UserDefinedPowerCycle_ud_ind_od_mset, self->data_ptr);
}

static PyObject *
UserDefinedPowerCycle_get_ud_m_dot_water_cool_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_UserDefinedPowerCycle_ud_m_dot_water_cool_des_nget, self->data_ptr);
}

static int
UserDefinedPowerCycle_set_ud_m_dot_water_cool_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_UserDefinedPowerCycle_ud_m_dot_water_cool_des_nset, self->data_ptr);
}

static PyGetSetDef UserDefinedPowerCycle_getset[] = {
{"ud_f_W_dot_cool_des", (getter)UserDefinedPowerCycle_get_ud_f_W_dot_cool_des,(setter)UserDefinedPowerCycle_set_ud_f_W_dot_cool_des,
	PyDoc_STR("*float*: Percent of user-defined power cycle design gross output consumed by cooling [%]\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_ind_od", (getter)UserDefinedPowerCycle_get_ud_ind_od,(setter)UserDefinedPowerCycle_set_ud_ind_od,
	PyDoc_STR("*sequence[sequence]*: Off design user-defined power cycle performance as function of T_htf, m_dot_htf [ND], and T_amb\n\n*Required*: True if pc_config=1"),
 	NULL},
{"ud_m_dot_water_cool_des", (getter)UserDefinedPowerCycle_get_ud_m_dot_water_cool_des,(setter)UserDefinedPowerCycle_set_ud_m_dot_water_cool_des,
	PyDoc_STR("*float*: Mass flow rate of water required at user-defined power cycle design point [kg/s]\n\n*Required*: True if pc_config=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject UserDefinedPowerCycle_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.UserDefinedPowerCycle",             /*tp_name*/
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
		UserDefinedPowerCycle_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		UserDefinedPowerCycle_getset,          /*tp_getset*/
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
 * ThermalStorage Group
 */ 

static PyTypeObject ThermalStorage_Type;

static PyObject *
ThermalStorage_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = ThermalStorage_Type.tp_alloc(&ThermalStorage_Type,0);

	VarGroupObject* ThermalStorage_obj = (VarGroupObject*)new_obj;

	ThermalStorage_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* ThermalStorage methods */

static PyObject *
ThermalStorage_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "ThermalStorage")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalStorage_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &ThermalStorage_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ThermalStorage_methods[] = {
		{"assign",            (PyCFunction)ThermalStorage_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``ThermalStorage_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)ThermalStorage_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThermalStorage_get_cold_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_cold_tank_Thtr_nget, self->data_ptr);
}

static int
ThermalStorage_set_cold_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_cold_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_cold_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_cold_tank_max_heat_nget, self->data_ptr);
}

static int
ThermalStorage_set_cold_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_cold_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_csp_pt_tes_init_hot_htf_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_csp_pt_tes_init_hot_htf_percent_nget, self->data_ptr);
}

static int
ThermalStorage_set_csp_pt_tes_init_hot_htf_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_csp_pt_tes_init_hot_htf_percent_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_h_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_h_tank_nget, self->data_ptr);
}

static int
ThermalStorage_set_h_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_h_tank_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_h_tank_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_h_tank_min_nget, self->data_ptr);
}

static int
ThermalStorage_set_h_tank_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_h_tank_min_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_hot_tank_Thtr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_hot_tank_Thtr_nget, self->data_ptr);
}

static int
ThermalStorage_set_hot_tank_Thtr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_hot_tank_Thtr_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_hot_tank_max_heat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_hot_tank_max_heat_nget, self->data_ptr);
}

static int
ThermalStorage_set_hot_tank_max_heat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_hot_tank_max_heat_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_tank_pairs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_tank_pairs_nget, self->data_ptr);
}

static int
ThermalStorage_set_tank_pairs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_tank_pairs_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_tes_fl_code(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_tes_fl_code_nget, self->data_ptr);
}

static int
ThermalStorage_set_tes_fl_code(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_tes_fl_code_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_u_tank(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_ThermalStorage_u_tank_nget, self->data_ptr);
}

static int
ThermalStorage_set_u_tank(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_ThermalStorage_u_tank_nset, self->data_ptr);
}

static PyObject *
ThermalStorage_get_ud_tes_fl_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesElectricResistance_ThermalStorage_ud_tes_fl_props_mget, self->data_ptr);
}

static int
ThermalStorage_set_ud_tes_fl_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesElectricResistance_ThermalStorage_ud_tes_fl_props_mset, self->data_ptr);
}

static PyGetSetDef ThermalStorage_getset[] = {
{"cold_tank_Thtr", (getter)ThermalStorage_get_cold_tank_Thtr,(setter)ThermalStorage_set_cold_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable cold tank HTF temperature [C]\n\n*Required*: True"),
 	NULL},
{"cold_tank_max_heat", (getter)ThermalStorage_get_cold_tank_max_heat,(setter)ThermalStorage_set_cold_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for cold tank heating [MW]\n\n*Required*: True"),
 	NULL},
{"csp_pt_tes_init_hot_htf_percent", (getter)ThermalStorage_get_csp_pt_tes_init_hot_htf_percent,(setter)ThermalStorage_set_csp_pt_tes_init_hot_htf_percent,
	PyDoc_STR("*float*: Initial fraction of available volume that is hot [%]\n\n*Required*: True"),
 	NULL},
{"h_tank", (getter)ThermalStorage_get_h_tank,(setter)ThermalStorage_set_h_tank,
	PyDoc_STR("*float*: Total height of tank (height of HTF when tank is full) [m]\n\n*Required*: True"),
 	NULL},
{"h_tank_min", (getter)ThermalStorage_get_h_tank_min,(setter)ThermalStorage_set_h_tank_min,
	PyDoc_STR("*float*: Minimum allowable HTF height in storage tank [m]\n\n*Required*: True"),
 	NULL},
{"hot_tank_Thtr", (getter)ThermalStorage_get_hot_tank_Thtr,(setter)ThermalStorage_set_hot_tank_Thtr,
	PyDoc_STR("*float*: Minimum allowable hot tank HTF temperature [C]\n\n*Required*: True"),
 	NULL},
{"hot_tank_max_heat", (getter)ThermalStorage_get_hot_tank_max_heat,(setter)ThermalStorage_set_hot_tank_max_heat,
	PyDoc_STR("*float*: Rated heater capacity for hot tank heating [MW]\n\n*Required*: True"),
 	NULL},
{"tank_pairs", (getter)ThermalStorage_get_tank_pairs,(setter)ThermalStorage_set_tank_pairs,
	PyDoc_STR("*float*: Number of equivalent tank pairs\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"tes_fl_code", (getter)ThermalStorage_get_tes_fl_code,(setter)ThermalStorage_set_tes_fl_code,
	PyDoc_STR("*float*: Receiver HTF, 17=Salt (60% NaNO3, 40% KNO3) 10=Salt (46.5% LiF 11.5% NaF 42% KF) 50=Lookup tables\n\n*Required*: True"),
 	NULL},
{"u_tank", (getter)ThermalStorage_get_u_tank,(setter)ThermalStorage_set_u_tank,
	PyDoc_STR("*float*: Loss coefficient from the tank [W/m2-K]\n\n*Required*: True"),
 	NULL},
{"ud_tes_fl_props", (getter)ThermalStorage_get_ud_tes_fl_props,(setter)ThermalStorage_set_ud_tes_fl_props,
	PyDoc_STR("*sequence[sequence]*: User-defined TES fluid property data [-]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ThermalStorage_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.ThermalStorage",             /*tp_name*/
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
		ThermalStorage_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ThermalStorage_getset,          /*tp_getset*/
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
 * TimeOfDeliveryFactors Group
 */ 

static PyTypeObject TimeOfDeliveryFactors_Type;

static PyObject *
TimeOfDeliveryFactors_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = TimeOfDeliveryFactors_Type.tp_alloc(&TimeOfDeliveryFactors_Type,0);

	VarGroupObject* TimeOfDeliveryFactors_obj = (VarGroupObject*)new_obj;

	TimeOfDeliveryFactors_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TimeOfDeliveryFactors methods */

static PyObject *
TimeOfDeliveryFactors_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "TimeOfDeliveryFactors")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeOfDeliveryFactors_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeOfDeliveryFactors_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeOfDeliveryFactors_methods[] = {
		{"assign",            (PyCFunction)TimeOfDeliveryFactors_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``TimeOfDeliveryFactors_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TimeOfDeliveryFactors_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor1_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor1_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor2_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor2_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor3_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor3_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor4_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor4_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor5_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor5_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor6(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor6_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor6_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor7(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor7_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor7(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor7_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor8(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor8_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor8(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor8_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factor9(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor9_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factor9(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factor9_nset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_factors_ts(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factors_ts_aget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_factors_ts(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_factors_ts_aset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekday(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_sched_weekday_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekday(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_sched_weekday_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_dispatch_sched_weekend(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_sched_weekend_mget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_dispatch_sched_weekend(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_dispatch_sched_weekend_mset, self->data_ptr);
}

static PyObject *
TimeOfDeliveryFactors_get_ppa_multiplier_model(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_TimeOfDeliveryFactors_ppa_multiplier_model_nget, self->data_ptr);
}

static int
TimeOfDeliveryFactors_set_ppa_multiplier_model(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_TimeOfDeliveryFactors_ppa_multiplier_model_nset, self->data_ptr);
}

static PyGetSetDef TimeOfDeliveryFactors_getset[] = {
{"dispatch_factor1", (getter)TimeOfDeliveryFactors_get_dispatch_factor1,(setter)TimeOfDeliveryFactors_set_dispatch_factor1,
	PyDoc_STR("*float*: Dispatch payment factor 1\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor2", (getter)TimeOfDeliveryFactors_get_dispatch_factor2,(setter)TimeOfDeliveryFactors_set_dispatch_factor2,
	PyDoc_STR("*float*: Dispatch payment factor 2\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor3", (getter)TimeOfDeliveryFactors_get_dispatch_factor3,(setter)TimeOfDeliveryFactors_set_dispatch_factor3,
	PyDoc_STR("*float*: Dispatch payment factor 3\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor4", (getter)TimeOfDeliveryFactors_get_dispatch_factor4,(setter)TimeOfDeliveryFactors_set_dispatch_factor4,
	PyDoc_STR("*float*: Dispatch payment factor 4\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor5", (getter)TimeOfDeliveryFactors_get_dispatch_factor5,(setter)TimeOfDeliveryFactors_set_dispatch_factor5,
	PyDoc_STR("*float*: Dispatch payment factor 5\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor6", (getter)TimeOfDeliveryFactors_get_dispatch_factor6,(setter)TimeOfDeliveryFactors_set_dispatch_factor6,
	PyDoc_STR("*float*: Dispatch payment factor 6\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor7", (getter)TimeOfDeliveryFactors_get_dispatch_factor7,(setter)TimeOfDeliveryFactors_set_dispatch_factor7,
	PyDoc_STR("*float*: Dispatch payment factor 7\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor8", (getter)TimeOfDeliveryFactors_get_dispatch_factor8,(setter)TimeOfDeliveryFactors_set_dispatch_factor8,
	PyDoc_STR("*float*: Dispatch payment factor 8\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factor9", (getter)TimeOfDeliveryFactors_get_dispatch_factor9,(setter)TimeOfDeliveryFactors_set_dispatch_factor9,
	PyDoc_STR("*float*: Dispatch payment factor 9\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dispatch_factors_ts", (getter)TimeOfDeliveryFactors_get_dispatch_factors_ts,(setter)TimeOfDeliveryFactors_set_dispatch_factors_ts,
	PyDoc_STR("*sequence*: Dispatch payment factor array\n\n*Required*: True if ppa_multiplier_model=1"),
 	NULL},
{"dispatch_sched_weekday", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekday,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekday,
	PyDoc_STR("*sequence[sequence]*: PPA pricing weekday schedule, 12x24\n\n*Required*: If not provided, assumed to be [[1]]"),
 	NULL},
{"dispatch_sched_weekend", (getter)TimeOfDeliveryFactors_get_dispatch_sched_weekend,(setter)TimeOfDeliveryFactors_set_dispatch_sched_weekend,
	PyDoc_STR("*sequence[sequence]*: PPA pricing weekend schedule, 12x24\n\n*Required*: If not provided, assumed to be [[1]]"),
 	NULL},
{"ppa_multiplier_model", (getter)TimeOfDeliveryFactors_get_ppa_multiplier_model,(setter)TimeOfDeliveryFactors_set_ppa_multiplier_model,
	PyDoc_STR("*float*: PPA multiplier model [0/1]\n\n*Options*: 0=diurnal,1=timestep\n\n*Constraints*: INTEGER,MIN=0\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeOfDeliveryFactors_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.TimeOfDeliveryFactors",             /*tp_name*/
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
		TimeOfDeliveryFactors_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeOfDeliveryFactors_getset,          /*tp_getset*/
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
 * SystemCost Group
 */ 

static PyTypeObject SystemCost_Type;

static PyObject *
SystemCost_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = SystemCost_Type.tp_alloc(&SystemCost_Type,0);

	VarGroupObject* SystemCost_obj = (VarGroupObject*)new_obj;

	SystemCost_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SystemCost methods */

static PyObject *
SystemCost_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "SystemCost")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SystemCost_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SystemCost_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SystemCost_methods[] = {
		{"assign",            (PyCFunction)SystemCost_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemCost_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemCost_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCost_get_cycle_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCost_cycle_spec_cost_nget, self->data_ptr);
}

static int
SystemCost_set_cycle_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCost_cycle_spec_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCost_getset[] = {
{"cycle_spec_cost", (getter)SystemCost_get_cycle_spec_cost,(setter)SystemCost_set_cycle_spec_cost,
	PyDoc_STR("*float*: Power cycle specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCost_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.SystemCost",             /*tp_name*/
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
		SystemCost_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SystemCost_getset,          /*tp_getset*/
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
SystemCosts_new(SAM_EtesElectricResistance data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "SystemCosts")){
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
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SystemCosts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SystemCosts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SystemCosts_get_bop_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_bop_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_bop_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_bop_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_contingency_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_contingency_rate_nget, self->data_ptr);
}

static int
SystemCosts_set_contingency_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_contingency_rate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_epc_cost_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_epc_cost_fixed_nget, self->data_ptr);
}

static int
SystemCosts_set_epc_cost_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_epc_cost_fixed_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_epc_cost_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_epc_cost_per_watt_nget, self->data_ptr);
}

static int
SystemCosts_set_epc_cost_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_epc_cost_per_watt_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_epc_cost_perc_of_direct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_epc_cost_perc_of_direct_nget, self->data_ptr);
}

static int
SystemCosts_set_epc_cost_perc_of_direct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_epc_cost_perc_of_direct_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_heater_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_heater_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_heater_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_heater_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_cost_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_land_cost_fixed_nget, self->data_ptr);
}

static int
SystemCosts_set_land_cost_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_land_cost_fixed_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_cost_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_land_cost_per_watt_nget, self->data_ptr);
}

static int
SystemCosts_set_land_cost_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_land_cost_per_watt_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_land_cost_perc_of_direct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_land_cost_perc_of_direct_nget, self->data_ptr);
}

static int
SystemCosts_set_land_cost_perc_of_direct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_land_cost_perc_of_direct_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_sales_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_sales_tax_frac_nget, self->data_ptr);
}

static int
SystemCosts_set_sales_tax_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_sales_tax_frac_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tes_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_SystemCosts_tes_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_tes_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_SystemCosts_tes_spec_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"bop_spec_cost", (getter)SystemCosts_get_bop_spec_cost,(setter)SystemCosts_set_bop_spec_cost,
	PyDoc_STR("*float*: Balance of plant specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"contingency_rate", (getter)SystemCosts_get_contingency_rate,(setter)SystemCosts_set_contingency_rate,
	PyDoc_STR("*float*: Contingency for cost overrun [%]\n\n*Required*: True"),
 	NULL},
{"epc_cost_fixed", (getter)SystemCosts_get_epc_cost_fixed,(setter)SystemCosts_set_epc_cost_fixed,
	PyDoc_STR("*float*: EPC fixed [$]\n\n*Required*: True"),
 	NULL},
{"epc_cost_per_watt", (getter)SystemCosts_get_epc_cost_per_watt,(setter)SystemCosts_set_epc_cost_per_watt,
	PyDoc_STR("*float*: EPC cost per watt [$/W]\n\n*Required*: True"),
 	NULL},
{"epc_cost_perc_of_direct", (getter)SystemCosts_get_epc_cost_perc_of_direct,(setter)SystemCosts_set_epc_cost_perc_of_direct,
	PyDoc_STR("*float*: EPC cost percent of direct [%]\n\n*Required*: True"),
 	NULL},
{"heater_spec_cost", (getter)SystemCosts_get_heater_spec_cost,(setter)SystemCosts_set_heater_spec_cost,
	PyDoc_STR("*float*: Heater specific cost [$/kWht]\n\n*Required*: True"),
 	NULL},
{"land_cost_fixed", (getter)SystemCosts_get_land_cost_fixed,(setter)SystemCosts_set_land_cost_fixed,
	PyDoc_STR("*float*: Land fixed [$]\n\n*Required*: True"),
 	NULL},
{"land_cost_per_watt", (getter)SystemCosts_get_land_cost_per_watt,(setter)SystemCosts_set_land_cost_per_watt,
	PyDoc_STR("*float*: Land cost per watt [$/W]\n\n*Required*: True"),
 	NULL},
{"land_cost_perc_of_direct", (getter)SystemCosts_get_land_cost_perc_of_direct,(setter)SystemCosts_set_land_cost_perc_of_direct,
	PyDoc_STR("*float*: Land cost percent of direct [%]\n\n*Required*: True"),
 	NULL},
{"sales_tax_frac", (getter)SystemCosts_get_sales_tax_frac,(setter)SystemCosts_set_sales_tax_frac,
	PyDoc_STR("*float*: Percent of cost to which sales tax applies [%]\n\n*Required*: True"),
 	NULL},
{"tes_spec_cost", (getter)SystemCosts_get_tes_spec_cost,(setter)SystemCosts_set_tes_spec_cost,
	PyDoc_STR("*float*: Thermal energy storage specific cost [$/kWht]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.SystemCosts",             /*tp_name*/
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
 * FinancialParameters Group
 */ 

static PyTypeObject FinancialParameters_Type;

static PyObject *
FinancialParameters_new(SAM_EtesElectricResistance data_ptr)
{
	PyObject* new_obj = FinancialParameters_Type.tp_alloc(&FinancialParameters_Type,0);

	VarGroupObject* FinancialParameters_obj = (VarGroupObject*)new_obj;

	FinancialParameters_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* FinancialParameters methods */

static PyObject *
FinancialParameters_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "FinancialParameters")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
FinancialParameters_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &FinancialParameters_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef FinancialParameters_methods[] = {
		{"assign",            (PyCFunction)FinancialParameters_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``FinancialParameters_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)FinancialParameters_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
FinancialParameters_get_const_per_interest_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_interest_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_interest_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_interest_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_months1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_months1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_months2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_months2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_months3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_months3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_months4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_months4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_months5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_months5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_months5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_months5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_percent1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_percent1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_percent2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_percent2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_percent3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_percent3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_percent4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_percent4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_percent5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_percent5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_percent5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_percent5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate1_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate1_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate2_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate2_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate3_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate3_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate4_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate4_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_const_per_upfront_rate5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate5_nget, self->data_ptr);
}

static int
FinancialParameters_set_const_per_upfront_rate5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_const_per_upfront_rate5_nset, self->data_ptr);
}

static PyObject *
FinancialParameters_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_FinancialParameters_sales_tax_rate_nget, self->data_ptr);
}

static int
FinancialParameters_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_EtesElectricResistance_FinancialParameters_sales_tax_rate_nset, self->data_ptr);
}

static PyGetSetDef FinancialParameters_getset[] = {
{"const_per_interest_rate1", (getter)FinancialParameters_get_const_per_interest_rate1,(setter)FinancialParameters_set_const_per_interest_rate1,
	PyDoc_STR("*float*: Interest rate, loan 1 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate2", (getter)FinancialParameters_get_const_per_interest_rate2,(setter)FinancialParameters_set_const_per_interest_rate2,
	PyDoc_STR("*float*: Interest rate, loan 2 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate3", (getter)FinancialParameters_get_const_per_interest_rate3,(setter)FinancialParameters_set_const_per_interest_rate3,
	PyDoc_STR("*float*: Interest rate, loan 3 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate4", (getter)FinancialParameters_get_const_per_interest_rate4,(setter)FinancialParameters_set_const_per_interest_rate4,
	PyDoc_STR("*float*: Interest rate, loan 4 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_interest_rate5", (getter)FinancialParameters_get_const_per_interest_rate5,(setter)FinancialParameters_set_const_per_interest_rate5,
	PyDoc_STR("*float*: Interest rate, loan 5 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_months1", (getter)FinancialParameters_get_const_per_months1,(setter)FinancialParameters_set_const_per_months1,
	PyDoc_STR("*float*: Months prior to operation, loan 1\n\n*Required*: True"),
 	NULL},
{"const_per_months2", (getter)FinancialParameters_get_const_per_months2,(setter)FinancialParameters_set_const_per_months2,
	PyDoc_STR("*float*: Months prior to operation, loan 2\n\n*Required*: True"),
 	NULL},
{"const_per_months3", (getter)FinancialParameters_get_const_per_months3,(setter)FinancialParameters_set_const_per_months3,
	PyDoc_STR("*float*: Months prior to operation, loan 3\n\n*Required*: True"),
 	NULL},
{"const_per_months4", (getter)FinancialParameters_get_const_per_months4,(setter)FinancialParameters_set_const_per_months4,
	PyDoc_STR("*float*: Months prior to operation, loan 4\n\n*Required*: True"),
 	NULL},
{"const_per_months5", (getter)FinancialParameters_get_const_per_months5,(setter)FinancialParameters_set_const_per_months5,
	PyDoc_STR("*float*: Months prior to operation, loan 5\n\n*Required*: True"),
 	NULL},
{"const_per_percent1", (getter)FinancialParameters_get_const_per_percent1,(setter)FinancialParameters_set_const_per_percent1,
	PyDoc_STR("*float*: Percent of total installed cost, loan 1 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent2", (getter)FinancialParameters_get_const_per_percent2,(setter)FinancialParameters_set_const_per_percent2,
	PyDoc_STR("*float*: Percent of total installed cost, loan 2 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent3", (getter)FinancialParameters_get_const_per_percent3,(setter)FinancialParameters_set_const_per_percent3,
	PyDoc_STR("*float*: Percent of total installed cost, loan 3 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent4", (getter)FinancialParameters_get_const_per_percent4,(setter)FinancialParameters_set_const_per_percent4,
	PyDoc_STR("*float*: Percent of total installed cost, loan 4 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_percent5", (getter)FinancialParameters_get_const_per_percent5,(setter)FinancialParameters_set_const_per_percent5,
	PyDoc_STR("*float*: Percent of total installed cost, loan 5 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate1", (getter)FinancialParameters_get_const_per_upfront_rate1,(setter)FinancialParameters_set_const_per_upfront_rate1,
	PyDoc_STR("*float*: Upfront fee on principal, loan 1 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate2", (getter)FinancialParameters_get_const_per_upfront_rate2,(setter)FinancialParameters_set_const_per_upfront_rate2,
	PyDoc_STR("*float*: Upfront fee on principal, loan 2 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate3", (getter)FinancialParameters_get_const_per_upfront_rate3,(setter)FinancialParameters_set_const_per_upfront_rate3,
	PyDoc_STR("*float*: Upfront fee on principal, loan 3 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate4", (getter)FinancialParameters_get_const_per_upfront_rate4,(setter)FinancialParameters_set_const_per_upfront_rate4,
	PyDoc_STR("*float*: Upfront fee on principal, loan 4 [%]\n\n*Required*: True"),
 	NULL},
{"const_per_upfront_rate5", (getter)FinancialParameters_get_const_per_upfront_rate5,(setter)FinancialParameters_set_const_per_upfront_rate5,
	PyDoc_STR("*float*: Upfront fee on principal, loan 5 [%]\n\n*Required*: True"),
 	NULL},
{"sales_tax_rate", (getter)FinancialParameters_get_sales_tax_rate,(setter)FinancialParameters_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales tax rate [%]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject FinancialParameters_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.FinancialParameters",             /*tp_name*/
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
		FinancialParameters_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		FinancialParameters_getset,          /*tp_getset*/
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
Outputs_new(SAM_EtesElectricResistance data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "EtesElectricResistance", "Outputs")){
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
Outputs_get_T_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_T_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_T_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_W_dot_cycle_gross_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_W_dot_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_out_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_W_dot_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_E_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_E_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_E_heater(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_E_heater_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_E_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_E_tes_heater_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_cycle_thermal_in(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_Q_cycle_thermal_in_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_cycle_thermal_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_Q_cycle_thermal_startup_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_heater_startup(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_Q_heater_startup_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_heater_to_htf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_Q_heater_to_htf_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_Q_tes_losses(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_Q_tes_losses_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_full_availability(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_annual_energy_full_availability_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_financing_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_construction_financing_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_e_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_e_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_cold(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_mass_tes_cold_aget, self->data_ptr);
}

static PyObject *
Outputs_get_mass_tes_hot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_mass_tes_hot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_ch_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_ch_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_cycle_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_cycle_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_dc_tes(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_dc_tes_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_heater_startup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_heater_startup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_heater_to_htf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_heater_to_htf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_tes_heater(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_tes_heater_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_dot_tes_losses(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_q_dot_tes_losses_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_system_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_EtesElectricResistance_Outputs_time_hr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_EtesElectricResistance_Outputs_total_installed_cost_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"T_tes_cold", (getter)Outputs_get_T_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold temperature [C]"),
 	NULL},
{"T_tes_hot", (getter)Outputs_get_T_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot temperature [C]"),
 	NULL},
{"W_dot_cycle_gross", (getter)Outputs_get_W_dot_cycle_gross,(setter)0,
	PyDoc_STR("*sequence*: PC electrical power gross (no cooling parasitics) [MWe]"),
 	NULL},
{"W_dot_heater", (getter)Outputs_get_W_dot_heater,(setter)0,
	PyDoc_STR("*sequence*: Heater electricity consumption [MWe]"),
 	NULL},
{"W_dot_out_net", (getter)Outputs_get_W_dot_out_net,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid [MWe]"),
 	NULL},
{"annual_E_cycle_gross", (getter)Outputs_get_annual_E_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Annual cycle gross electric energy generation [MWhe]"),
 	NULL},
{"annual_E_heater", (getter)Outputs_get_annual_E_heater,(setter)0,
	PyDoc_STR("*float*: Annual heater electric energy consumption [MWhe]"),
 	NULL},
{"annual_E_tes_heater", (getter)Outputs_get_annual_E_tes_heater,(setter)0,
	PyDoc_STR("*float*: Annual TES freeze heater electric energy consumption [MWhe]"),
 	NULL},
{"annual_Q_cycle_thermal_in", (getter)Outputs_get_annual_Q_cycle_thermal_in,(setter)0,
	PyDoc_STR("*float*: Annual cycle thermal energy input [MWht]"),
 	NULL},
{"annual_Q_cycle_thermal_startup", (getter)Outputs_get_annual_Q_cycle_thermal_startup,(setter)0,
	PyDoc_STR("*float*: Annual cycle thermal energy consumed by startup [MWht]"),
 	NULL},
{"annual_Q_heater_startup", (getter)Outputs_get_annual_Q_heater_startup,(setter)0,
	PyDoc_STR("*float*: Annual heater thermal energy consumed by startup [MWht]"),
 	NULL},
{"annual_Q_heater_to_htf", (getter)Outputs_get_annual_Q_heater_to_htf,(setter)0,
	PyDoc_STR("*float*: Annual heater thermal power to HTF [MWhe]"),
 	NULL},
{"annual_Q_tes_losses", (getter)Outputs_get_annual_Q_tes_losses,(setter)0,
	PyDoc_STR("*float*: Annual TES thermal energy lost to ambient [MWht]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual total electric power to grid [kWhe]"),
 	NULL},
{"annual_energy_full_availability", (getter)Outputs_get_annual_energy_full_availability,(setter)0,
	PyDoc_STR("*float*: Annual total electric power to grid w/ full availability [MWhe]"),
 	NULL},
{"construction_financing_cost", (getter)Outputs_get_construction_financing_cost,(setter)0,
	PyDoc_STR("*float*: Total construction financing cost [$]"),
 	NULL},
{"e_ch_tes", (getter)Outputs_get_e_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge state [MWht]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: Total electric power to grid with available derate [kWe]"),
 	NULL},
{"mass_tes_cold", (getter)Outputs_get_mass_tes_cold,(setter)0,
	PyDoc_STR("*sequence*: TES cold tank mass (end) [kg]"),
 	NULL},
{"mass_tes_hot", (getter)Outputs_get_mass_tes_hot,(setter)0,
	PyDoc_STR("*sequence*: TES hot tank mass (end) [kg]"),
 	NULL},
{"q_dot_ch_tes", (getter)Outputs_get_q_dot_ch_tes,(setter)0,
	PyDoc_STR("*sequence*: TES charge thermal power [MWt]"),
 	NULL},
{"q_dot_cycle", (getter)Outputs_get_q_dot_cycle,(setter)0,
	PyDoc_STR("*sequence*: PC thermal power [MWt]"),
 	NULL},
{"q_dot_cycle_startup", (getter)Outputs_get_q_dot_cycle_startup,(setter)0,
	PyDoc_STR("*sequence*: PC startup thermal power [MWt]"),
 	NULL},
{"q_dot_dc_tes", (getter)Outputs_get_q_dot_dc_tes,(setter)0,
	PyDoc_STR("*sequence*: TES discharge thermal power [MWt]"),
 	NULL},
{"q_dot_heater_startup", (getter)Outputs_get_q_dot_heater_startup,(setter)0,
	PyDoc_STR("*sequence*: Heater thermal power consumed during startup [MWt]"),
 	NULL},
{"q_dot_heater_to_htf", (getter)Outputs_get_q_dot_heater_to_htf,(setter)0,
	PyDoc_STR("*sequence*: Heater thermal power to HTF [MWt]"),
 	NULL},
{"q_dot_tes_heater", (getter)Outputs_get_q_dot_tes_heater,(setter)0,
	PyDoc_STR("*sequence*: TES freeze protection power [MWe]"),
 	NULL},
{"q_dot_tes_losses", (getter)Outputs_get_q_dot_tes_losses,(setter)0,
	PyDoc_STR("*sequence*: TES thermal losses [MWt]"),
 	NULL},
{"system_capacity", (getter)Outputs_get_system_capacity,(setter)0,
	PyDoc_STR("*float*: System capacity [kWe]"),
 	NULL},
{"time_hr", (getter)Outputs_get_time_hr,(setter)0,
	PyDoc_STR("*sequence*: Time at end of timestep [hr]"),
 	NULL},
{"total_installed_cost", (getter)Outputs_get_total_installed_cost,(setter)0,
	PyDoc_STR("*float*: Total installed cost [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance.Outputs",             /*tp_name*/
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
 * EtesElectricResistance
 */

static PyTypeObject EtesElectricResistance_Type;

static CmodObject *
newEtesElectricResistanceObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &EtesElectricResistance_Type);

	PySAM_TECH_ATTR()

	PyObject* SolarResource_obj = SolarResource_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SolarResource", SolarResource_obj);
	Py_DECREF(SolarResource_obj);

	PyObject* SystemControl_obj = SystemControl_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemControl", SystemControl_obj);
	Py_DECREF(SystemControl_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* PowerCycle_obj = PowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PowerCycle", PowerCycle_obj);
	Py_DECREF(PowerCycle_obj);

	PyObject* RankineCycle_obj = RankineCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "RankineCycle", RankineCycle_obj);
	Py_DECREF(RankineCycle_obj);

	PyObject* UserDefinedPowerCycle_obj = UserDefinedPowerCycle_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "UserDefinedPowerCycle", UserDefinedPowerCycle_obj);
	Py_DECREF(UserDefinedPowerCycle_obj);

	PyObject* ThermalStorage_obj = ThermalStorage_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ThermalStorage", ThermalStorage_obj);
	Py_DECREF(ThermalStorage_obj);

	PyObject* TimeOfDeliveryFactors_obj = TimeOfDeliveryFactors_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeOfDeliveryFactors", TimeOfDeliveryFactors_obj);
	Py_DECREF(TimeOfDeliveryFactors_obj);

	PyObject* SystemCost_obj = SystemCost_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCost", SystemCost_obj);
	Py_DECREF(SystemCost_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* FinancialParameters_obj = FinancialParameters_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "FinancialParameters", FinancialParameters_obj);
	Py_DECREF(FinancialParameters_obj);

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

/* EtesElectricResistance methods */

static void
EtesElectricResistance_dealloc(CmodObject *self)
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
EtesElectricResistance_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_EtesElectricResistance_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
EtesElectricResistance_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "EtesElectricResistance"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
EtesElectricResistance_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
EtesElectricResistance_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
EtesElectricResistance_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef EtesElectricResistance_methods[] = {
		{"execute",           (PyCFunction)EtesElectricResistance_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)EtesElectricResistance_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Solar Resource': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)EtesElectricResistance_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)EtesElectricResistance_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)EtesElectricResistance_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
EtesElectricResistance_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
EtesElectricResistance_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject EtesElectricResistance_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"EtesElectricResistance",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)EtesElectricResistance_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)EtesElectricResistance_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)EtesElectricResistance_getattro, /*tp_getattro*/
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
		EtesElectricResistance_methods,      /*tp_methods*/
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


/* Function of no arguments returning new EtesElectricResistance object */

static PyObject *
EtesElectricResistance_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newEtesElectricResistanceObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
EtesElectricResistance_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newEtesElectricResistanceObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
EtesElectricResistance_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newEtesElectricResistanceObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "EtesElectricResistance", def) < 0) {
		EtesElectricResistance_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
EtesElectricResistance_from_existing(PyObject *self, PyObject *args)
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

	rv = newEtesElectricResistanceObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "EtesElectricResistance", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef EtesElectricResistanceModule_methods[] = {
		{"new",             EtesElectricResistance_new,         METH_VARARGS,
				PyDoc_STR("new() -> EtesElectricResistance")},
		{"default",             EtesElectricResistance_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> EtesElectricResistance\n\nUse default attributes\n"
				"None")},
		{"wrap",             EtesElectricResistance_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> EtesElectricResistance\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   EtesElectricResistance_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> EtesElectricResistance\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "EtesElectricResistance");


static int
EtesElectricResistanceModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	EtesElectricResistance_Type.tp_dict = PyDict_New();
	if (!EtesElectricResistance_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to EtesElectricResistance_Type
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
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the SolarResource type object to EtesElectricResistance_Type
	if (PyType_Ready(&SolarResource_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"SolarResource",
				(PyObject*)&SolarResource_Type);
	Py_DECREF(&SolarResource_Type);

	/// Add the SystemControl type object to EtesElectricResistance_Type
	if (PyType_Ready(&SystemControl_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"SystemControl",
				(PyObject*)&SystemControl_Type);
	Py_DECREF(&SystemControl_Type);

	/// Add the SystemDesign type object to EtesElectricResistance_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the PowerCycle type object to EtesElectricResistance_Type
	if (PyType_Ready(&PowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"PowerCycle",
				(PyObject*)&PowerCycle_Type);
	Py_DECREF(&PowerCycle_Type);

	/// Add the RankineCycle type object to EtesElectricResistance_Type
	if (PyType_Ready(&RankineCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"RankineCycle",
				(PyObject*)&RankineCycle_Type);
	Py_DECREF(&RankineCycle_Type);

	/// Add the UserDefinedPowerCycle type object to EtesElectricResistance_Type
	if (PyType_Ready(&UserDefinedPowerCycle_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"UserDefinedPowerCycle",
				(PyObject*)&UserDefinedPowerCycle_Type);
	Py_DECREF(&UserDefinedPowerCycle_Type);

	/// Add the ThermalStorage type object to EtesElectricResistance_Type
	if (PyType_Ready(&ThermalStorage_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"ThermalStorage",
				(PyObject*)&ThermalStorage_Type);
	Py_DECREF(&ThermalStorage_Type);

	/// Add the TimeOfDeliveryFactors type object to EtesElectricResistance_Type
	if (PyType_Ready(&TimeOfDeliveryFactors_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"TimeOfDeliveryFactors",
				(PyObject*)&TimeOfDeliveryFactors_Type);
	Py_DECREF(&TimeOfDeliveryFactors_Type);

	/// Add the SystemCost type object to EtesElectricResistance_Type
	if (PyType_Ready(&SystemCost_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"SystemCost",
				(PyObject*)&SystemCost_Type);
	Py_DECREF(&SystemCost_Type);

	/// Add the SystemCosts type object to EtesElectricResistance_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the FinancialParameters type object to EtesElectricResistance_Type
	if (PyType_Ready(&FinancialParameters_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"FinancialParameters",
				(PyObject*)&FinancialParameters_Type);
	Py_DECREF(&FinancialParameters_Type);

	/// Add the Outputs type object to EtesElectricResistance_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(EtesElectricResistance_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the EtesElectricResistance type object to the module
	if (PyType_Ready(&EtesElectricResistance_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"EtesElectricResistance",
				(PyObject*)&EtesElectricResistance_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot EtesElectricResistanceModule_slots[] = {
		{Py_mod_exec, EtesElectricResistanceModule_exec},
		{0, NULL},
};

static struct PyModuleDef EtesElectricResistanceModule = {
		PyModuleDef_HEAD_INIT,
		"EtesElectricResistance",
		module_doc,
		0,
		EtesElectricResistanceModule_methods,
		EtesElectricResistanceModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_EtesElectricResistance(void)
{
	return PyModuleDef_Init(&EtesElectricResistanceModule);
}