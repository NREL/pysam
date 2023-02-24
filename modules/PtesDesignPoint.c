#include <Python.h>

#include <SAM_PtesDesignPoint.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_PtesDesignPoint data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	VarGroupObject* Common_obj = (VarGroupObject*)new_obj;

	Common_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "PtesDesignPoint", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Common_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "PtesDesignPoint", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Common_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Common_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_P0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_P0_nget, self->data_ptr);
}

static int
Common_set_P0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_P0_nset, self->data_ptr);
}

static PyObject *
Common_get_P1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_P1_nget, self->data_ptr);
}

static int
Common_set_P1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_P1_nset, self->data_ptr);
}

static PyObject *
Common_get_T0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_T0_nget, self->data_ptr);
}

static int
Common_set_T0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_T0_nset, self->data_ptr);
}

static PyObject *
Common_get_T_compressor_inlet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_T_compressor_inlet_nget, self->data_ptr);
}

static int
Common_set_T_compressor_inlet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_T_compressor_inlet_nset, self->data_ptr);
}

static PyObject *
Common_get_T_compressor_outlet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_T_compressor_outlet_nget, self->data_ptr);
}

static int
Common_set_T_compressor_outlet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_T_compressor_outlet_nset, self->data_ptr);
}

static PyObject *
Common_get_alpha(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_alpha_nget, self->data_ptr);
}

static int
Common_set_alpha(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_alpha_nset, self->data_ptr);
}

static PyObject *
Common_get_charge_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_charge_time_hr_nget, self->data_ptr);
}

static int
Common_set_charge_time_hr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_charge_time_hr_nset, self->data_ptr);
}

static PyObject *
Common_get_cold_fluid_id(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_cold_fluid_id_nget, self->data_ptr);
}

static int
Common_set_cold_fluid_id(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_cold_fluid_id_nset, self->data_ptr);
}

static PyObject *
Common_get_cold_ud_fluid_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_PtesDesignPoint_Common_cold_ud_fluid_props_mget, self->data_ptr);
}

static int
Common_set_cold_ud_fluid_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_PtesDesignPoint_Common_cold_ud_fluid_props_mset, self->data_ptr);
}

static PyObject *
Common_get_discharge_time_hr(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_discharge_time_hr_nget, self->data_ptr);
}

static int
Common_set_discharge_time_hr(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_discharge_time_hr_nset, self->data_ptr);
}

static PyObject *
Common_get_eta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_eta_nget, self->data_ptr);
}

static int
Common_set_eta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_eta_nset, self->data_ptr);
}

static PyObject *
Common_get_eta_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_eta_pump_nget, self->data_ptr);
}

static int
Common_set_eta_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_eta_pump_nset, self->data_ptr);
}

static PyObject *
Common_get_gen_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_gen_eff_nget, self->data_ptr);
}

static int
Common_set_gen_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_gen_eff_nset, self->data_ptr);
}

static PyObject *
Common_get_hot_fluid_id(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_hot_fluid_id_nget, self->data_ptr);
}

static int
Common_set_hot_fluid_id(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_hot_fluid_id_nset, self->data_ptr);
}

static PyObject *
Common_get_hot_ud_fluid_props(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_PtesDesignPoint_Common_hot_ud_fluid_props_mget, self->data_ptr);
}

static int
Common_set_hot_ud_fluid_props(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_PtesDesignPoint_Common_hot_ud_fluid_props_mset, self->data_ptr);
}

static PyObject *
Common_get_hx_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_hx_eff_nget, self->data_ptr);
}

static int
Common_set_hx_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_hx_eff_nset, self->data_ptr);
}

static PyObject *
Common_get_motor_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_motor_eff_nget, self->data_ptr);
}

static int
Common_set_motor_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_motor_eff_nset, self->data_ptr);
}

static PyObject *
Common_get_ploss_air(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_ploss_air_nget, self->data_ptr);
}

static int
Common_set_ploss_air(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_ploss_air_nset, self->data_ptr);
}

static PyObject *
Common_get_ploss_liquid(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_ploss_liquid_nget, self->data_ptr);
}

static int
Common_set_ploss_liquid(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_ploss_liquid_nset, self->data_ptr);
}

static PyObject *
Common_get_ploss_working(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_ploss_working_nget, self->data_ptr);
}

static int
Common_set_ploss_working(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_ploss_working_nset, self->data_ptr);
}

static PyObject *
Common_get_power_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Common_power_output_nget, self->data_ptr);
}

static int
Common_set_power_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_PtesDesignPoint_Common_power_output_nset, self->data_ptr);
}

static PyObject *
Common_get_working_fluid_type(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_PtesDesignPoint_Common_working_fluid_type_sget, self->data_ptr);
}

static int
Common_set_working_fluid_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_PtesDesignPoint_Common_working_fluid_type_sset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"P0", (getter)Common_get_P0,(setter)Common_set_P0,
	PyDoc_STR("*float*: Ambient Pressure [Pa]\n\n**Required:**\nTrue"),
 	NULL},
{"P1", (getter)Common_get_P1,(setter)Common_set_P1,
	PyDoc_STR("*float*: Lowest Pressure in cycle [Pa]\n\n**Required:**\nTrue"),
 	NULL},
{"T0", (getter)Common_get_T0,(setter)Common_set_T0,
	PyDoc_STR("*float*: Ambient Temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_compressor_inlet", (getter)Common_get_T_compressor_inlet,(setter)Common_set_T_compressor_inlet,
	PyDoc_STR("*float*: Charging compressor inlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"T_compressor_outlet", (getter)Common_get_T_compressor_outlet,(setter)Common_set_T_compressor_outlet,
	PyDoc_STR("*float*: Charging compressor outlet temperature [C]\n\n**Required:**\nTrue"),
 	NULL},
{"alpha", (getter)Common_get_alpha,(setter)Common_set_alpha,
	PyDoc_STR("*float*: Ratio of mdot cp     AIR/WF\n\n**Required:**\nTrue"),
 	NULL},
{"charge_time_hr", (getter)Common_get_charge_time_hr,(setter)Common_set_charge_time_hr,
	PyDoc_STR("*float*: charging time [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"cold_fluid_id", (getter)Common_get_cold_fluid_id,(setter)Common_set_cold_fluid_id,
	PyDoc_STR("*float*: Cold Reservoir Fluid ID"),
 	NULL},
{"cold_ud_fluid_props", (getter)Common_get_cold_ud_fluid_props,(setter)Common_set_cold_ud_fluid_props,
	PyDoc_STR("*sequence[sequence]*: User Defined Cold Resevior Fluid Properties"),
 	NULL},
{"discharge_time_hr", (getter)Common_get_discharge_time_hr,(setter)Common_set_discharge_time_hr,
	PyDoc_STR("*float*: discharge time [hr]\n\n**Required:**\nTrue"),
 	NULL},
{"eta", (getter)Common_get_eta,(setter)Common_set_eta,
	PyDoc_STR("*float*: polytropic efficiency of compressors and expanders\n\n**Required:**\nTrue"),
 	NULL},
{"eta_pump", (getter)Common_get_eta_pump,(setter)Common_set_eta_pump,
	PyDoc_STR("*float*: polytropic efficiency of air pump\n\n**Required:**\nTrue"),
 	NULL},
{"gen_eff", (getter)Common_get_gen_eff,(setter)Common_set_gen_eff,
	PyDoc_STR("*float*: Generator Efficiency\n\n**Required:**\nTrue"),
 	NULL},
{"hot_fluid_id", (getter)Common_get_hot_fluid_id,(setter)Common_set_hot_fluid_id,
	PyDoc_STR("*float*: Hot Reservoir Fluid ID"),
 	NULL},
{"hot_ud_fluid_props", (getter)Common_get_hot_ud_fluid_props,(setter)Common_set_hot_ud_fluid_props,
	PyDoc_STR("*sequence[sequence]*: User Defined Hot Resevior Fluid Properties"),
 	NULL},
{"hx_eff", (getter)Common_get_hx_eff,(setter)Common_set_hx_eff,
	PyDoc_STR("*float*: hx effectiveness\n\n**Required:**\nTrue"),
 	NULL},
{"motor_eff", (getter)Common_get_motor_eff,(setter)Common_set_motor_eff,
	PyDoc_STR("*float*: Motor Efficiency\n\n**Required:**\nTrue"),
 	NULL},
{"ploss_air", (getter)Common_get_ploss_air,(setter)Common_set_ploss_air,
	PyDoc_STR("*float*: Fractional pressure loss (air)\n\n**Required:**\nTrue"),
 	NULL},
{"ploss_liquid", (getter)Common_get_ploss_liquid,(setter)Common_set_ploss_liquid,
	PyDoc_STR("*float*: Fractional pressure loss (liquid)\n\n**Required:**\nTrue"),
 	NULL},
{"ploss_working", (getter)Common_get_ploss_working,(setter)Common_set_ploss_working,
	PyDoc_STR("*float*: Fractional pressure loss in each heat exchanger\n\n**Required:**\nTrue"),
 	NULL},
{"power_output", (getter)Common_get_power_output,(setter)Common_set_power_output,
	PyDoc_STR("*float*: Power Output [MW]\n\n**Required:**\nTrue"),
 	NULL},
{"working_fluid_type", (getter)Common_get_working_fluid_type,(setter)Common_set_working_fluid_type,
	PyDoc_STR("*str*: Working Fluid Type"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"PtesDesignPoint.Common",             /*tp_name*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
Outputs_new(SAM_PtesDesignPoint data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "PtesDesignPoint", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "PtesDesignPoint", "Outputs")){
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
Outputs_get_N_pts_charge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_N_pts_charge_nget, self->data_ptr);
}

static PyObject *
Outputs_get_N_pts_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_N_pts_discharge_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Tc_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_Tc_cold_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Tc_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_Tc_hot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Th_cold(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_Th_cold_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Th_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_Th_hot_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cycle_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_cycle_eff_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hp_COP(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_hp_COP_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hp_cold_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_hp_cold_pump_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hp_hot_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_hp_hot_pump_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_hp_parasitic_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_hp_parasitic_fraction_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_cold_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_pc_cold_pump_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_hot_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_pc_hot_pump_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_pc_parasitic_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_PtesDesignPoint_Outputs_pc_parasitic_fraction_nget, self->data_ptr);
}

static PyObject *
Outputs_get_s_series_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PtesDesignPoint_Outputs_s_series_charge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_s_series_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PtesDesignPoint_Outputs_s_series_discharge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_temp_series_charge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PtesDesignPoint_Outputs_temp_series_charge_aget, self->data_ptr);
}

static PyObject *
Outputs_get_temp_series_discharge(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_PtesDesignPoint_Outputs_temp_series_discharge_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"N_pts_charge", (getter)Outputs_get_N_pts_charge,(setter)0,
	PyDoc_STR("*float*: Number data points on plot"),
 	NULL},
{"N_pts_discharge", (getter)Outputs_get_N_pts_discharge,(setter)0,
	PyDoc_STR("*float*: Number data points on plot"),
 	NULL},
{"Tc_cold", (getter)Outputs_get_Tc_cold,(setter)0,
	PyDoc_STR("*float*: Cold Storage Cold Temp [C]"),
 	NULL},
{"Tc_hot", (getter)Outputs_get_Tc_hot,(setter)0,
	PyDoc_STR("*float*: Cold Storage Hot Temp [C]"),
 	NULL},
{"Th_cold", (getter)Outputs_get_Th_cold,(setter)0,
	PyDoc_STR("*float*: Hot Storage Cold Temp [C]"),
 	NULL},
{"Th_hot", (getter)Outputs_get_Th_hot,(setter)0,
	PyDoc_STR("*float*: Hot Storage Hot Temp [C]"),
 	NULL},
{"cycle_eff", (getter)Outputs_get_cycle_eff,(setter)0,
	PyDoc_STR("*float*: Cycle Efficiency"),
 	NULL},
{"hp_COP", (getter)Outputs_get_hp_COP,(setter)0,
	PyDoc_STR("*float*: Heat Pump COP"),
 	NULL},
{"hp_cold_pump_power", (getter)Outputs_get_hp_cold_pump_power,(setter)0,
	PyDoc_STR("*float*: Heat Pump Cold HX Pump Power [kW/kg/s]"),
 	NULL},
{"hp_hot_pump_power", (getter)Outputs_get_hp_hot_pump_power,(setter)0,
	PyDoc_STR("*float*: Heat Pump Hot HX Pump Power [kW/kg/s]"),
 	NULL},
{"hp_parasitic_fraction", (getter)Outputs_get_hp_parasitic_fraction,(setter)0,
	PyDoc_STR("*float*: Heat Pump Parasitics Fraction"),
 	NULL},
{"pc_cold_pump_power", (getter)Outputs_get_pc_cold_pump_power,(setter)0,
	PyDoc_STR("*float*: Power Cycle Cold HX Pump Power [kW/kg/s]"),
 	NULL},
{"pc_hot_pump_power", (getter)Outputs_get_pc_hot_pump_power,(setter)0,
	PyDoc_STR("*float*: Power Cycle Hot HX Pump Power [kW/kg/s]"),
 	NULL},
{"pc_parasitic_fraction", (getter)Outputs_get_pc_parasitic_fraction,(setter)0,
	PyDoc_STR("*float*: Power Cycle Parasitics Fraction"),
 	NULL},
{"s_series_charge", (getter)Outputs_get_s_series_charge,(setter)0,
	PyDoc_STR("*sequence*: Entropy Values [kJ/kg K]"),
 	NULL},
{"s_series_discharge", (getter)Outputs_get_s_series_discharge,(setter)0,
	PyDoc_STR("*sequence*: Entropy Values [kJ/kg K]"),
 	NULL},
{"temp_series_charge", (getter)Outputs_get_temp_series_charge,(setter)0,
	PyDoc_STR("*sequence*: Temperature Values [C]"),
 	NULL},
{"temp_series_discharge", (getter)Outputs_get_temp_series_discharge,(setter)0,
	PyDoc_STR("*sequence*: Temperature Values [C]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"PtesDesignPoint.Outputs",             /*tp_name*/
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
 * PtesDesignPoint
 */

static PyTypeObject PtesDesignPoint_Type;

static CmodObject *
newPtesDesignPointObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &PtesDesignPoint_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* PtesDesignPoint methods */

static void
PtesDesignPoint_dealloc(CmodObject *self)
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
PtesDesignPoint_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_PtesDesignPoint_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
PtesDesignPoint_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "PtesDesignPoint"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PtesDesignPoint_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "PtesDesignPoint"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PtesDesignPoint_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
PtesDesignPoint_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
PtesDesignPoint_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef PtesDesignPoint_methods[] = {
		{"execute",           (PyCFunction)PtesDesignPoint_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)PtesDesignPoint_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)PtesDesignPoint_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)PtesDesignPoint_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)PtesDesignPoint_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)PtesDesignPoint_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PtesDesignPoint_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
PtesDesignPoint_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject PtesDesignPoint_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"PtesDesignPoint",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)PtesDesignPoint_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)PtesDesignPoint_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)PtesDesignPoint_getattro, /*tp_getattro*/
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
		PtesDesignPoint_methods,      /*tp_methods*/
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


/* Function of no arguments returning new PtesDesignPoint object */

static PyObject *
PtesDesignPoint_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPtesDesignPointObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
PtesDesignPoint_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPtesDesignPointObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
PtesDesignPoint_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPtesDesignPointObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "PtesDesignPoint", def) < 0) {
		PtesDesignPoint_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
PtesDesignPoint_from_existing(PyObject *self, PyObject *args)
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

	rv = newPtesDesignPointObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "PtesDesignPoint", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef PtesDesignPointModule_methods[] = {
		{"new",             PtesDesignPoint_new,         METH_VARARGS,
				PyDoc_STR("new() -> PtesDesignPoint")},
		{"default",             PtesDesignPoint_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> PtesDesignPoint\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             PtesDesignPoint_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> PtesDesignPoint\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   PtesDesignPoint_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> PtesDesignPoint\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "PtesDesignPoint");


static int
PtesDesignPointModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	PtesDesignPoint_Type.tp_dict = PyDict_New();
	if (!PtesDesignPoint_Type.tp_dict) { goto fail; }

	/// Add the Common type object to PtesDesignPoint_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(PtesDesignPoint_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to PtesDesignPoint_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(PtesDesignPoint_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the PtesDesignPoint type object to the module
	if (PyType_Ready(&PtesDesignPoint_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"PtesDesignPoint",
				(PyObject*)&PtesDesignPoint_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot PtesDesignPointModule_slots[] = {
		{Py_mod_exec, PtesDesignPointModule_exec},
		{0, NULL},
};

static struct PyModuleDef PtesDesignPointModule = {
		PyModuleDef_HEAD_INIT,
		"PtesDesignPoint",
		module_doc,
		0,
		PtesDesignPointModule_methods,
		PtesDesignPointModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_PtesDesignPoint(void)
{
	return PyModuleDef_Init(&PtesDesignPointModule);
}