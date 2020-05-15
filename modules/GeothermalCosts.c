#include <Python.h>

#include <SAM_GeothermalCosts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * GeoHourly Group
 */ 

static PyTypeObject GeoHourly_Type;

static PyObject *
GeoHourly_new(SAM_GeothermalCosts data_ptr)
{
	PyObject* new_obj = GeoHourly_Type.tp_alloc(&GeoHourly_Type,0);

	VarGroupObject* GeoHourly_obj = (VarGroupObject*)new_obj;

	GeoHourly_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* GeoHourly methods */

static PyObject *
GeoHourly_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GeothermalCosts", "GeoHourly")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
GeoHourly_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &GeoHourly_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef GeoHourly_methods[] = {
		{"assign",            (PyCFunction)GeoHourly_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``GeoHourly_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)GeoHourly_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GeoHourly_get_GF_flowrate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_GF_flowrate_nget, self->data_ptr);
}

static int
GeoHourly_set_GF_flowrate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_GF_flowrate_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_condensate_pump_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_condensate_pump_power_nget, self->data_ptr);
}

static int
GeoHourly_set_condensate_pump_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_condensate_pump_power_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_conversion_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_conversion_type_nget, self->data_ptr);
}

static int
GeoHourly_set_conversion_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_conversion_type_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_cw_pump_head(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_cw_pump_head_nget, self->data_ptr);
}

static int
GeoHourly_set_cw_pump_head(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_cw_pump_head_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_cw_pump_work(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_cw_pump_work_nget, self->data_ptr);
}

static int
GeoHourly_set_cw_pump_work(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_cw_pump_work_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_cwflow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_cwflow_nget, self->data_ptr);
}

static int
GeoHourly_set_cwflow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_cwflow_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_design_temp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_design_temp_nget, self->data_ptr);
}

static int
GeoHourly_set_design_temp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_design_temp_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_eff_secondlaw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_eff_secondlaw_nget, self->data_ptr);
}

static int
GeoHourly_set_eff_secondlaw(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_eff_secondlaw_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_flash_count(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_flash_count_nget, self->data_ptr);
}

static int
GeoHourly_set_flash_count(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_flash_count_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_gross_output(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_gross_output_nget, self->data_ptr);
}

static int
GeoHourly_set_gross_output(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_gross_output_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_hp_flash_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_hp_flash_pressure_nget, self->data_ptr);
}

static int
GeoHourly_set_hp_flash_pressure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_hp_flash_pressure_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_lp_flash_pressure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_lp_flash_pressure_nget, self->data_ptr);
}

static int
GeoHourly_set_lp_flash_pressure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_lp_flash_pressure_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_ncg_condensate_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_ncg_condensate_pump_nget, self->data_ptr);
}

static int
GeoHourly_set_ncg_condensate_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_ncg_condensate_pump_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pressure_ratio_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_pressure_ratio_1_nget, self->data_ptr);
}

static int
GeoHourly_set_pressure_ratio_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_pressure_ratio_1_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pressure_ratio_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_pressure_ratio_2_nget, self->data_ptr);
}

static int
GeoHourly_set_pressure_ratio_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_pressure_ratio_2_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_pressure_ratio_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_pressure_ratio_3_nget, self->data_ptr);
}

static int
GeoHourly_set_pressure_ratio_3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_pressure_ratio_3_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_qCondenser(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_qCondenser_nget, self->data_ptr);
}

static int
GeoHourly_set_qCondenser(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_qCondenser_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_qRejectByStage_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_qRejectByStage_1_nget, self->data_ptr);
}

static int
GeoHourly_set_qRejectByStage_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_qRejectByStage_1_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_qRejectByStage_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_qRejectByStage_2_nget, self->data_ptr);
}

static int
GeoHourly_set_qRejectByStage_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_qRejectByStage_2_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_qRejectByStage_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_qRejectByStage_3_nget, self->data_ptr);
}

static int
GeoHourly_set_qRejectByStage_3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_qRejectByStage_3_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_qRejectTotal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_qRejectTotal_nget, self->data_ptr);
}

static int
GeoHourly_set_qRejectTotal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_qRejectTotal_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_spec_vol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_spec_vol_nget, self->data_ptr);
}

static int
GeoHourly_set_spec_vol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_spec_vol_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_spec_vol_lp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_spec_vol_lp_nget, self->data_ptr);
}

static int
GeoHourly_set_spec_vol_lp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_spec_vol_lp_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_v_stage_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_v_stage_1_nget, self->data_ptr);
}

static int
GeoHourly_set_v_stage_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_v_stage_1_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_v_stage_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_v_stage_2_nget, self->data_ptr);
}

static int
GeoHourly_set_v_stage_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_v_stage_2_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_v_stage_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_v_stage_3_nget, self->data_ptr);
}

static int
GeoHourly_set_v_stage_3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_v_stage_3_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_x_hp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_x_hp_nget, self->data_ptr);
}

static int
GeoHourly_set_x_hp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_x_hp_nset, self->data_ptr);
}

static PyObject *
GeoHourly_get_x_lp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_GeoHourly_x_lp_nget, self->data_ptr);
}

static int
GeoHourly_set_x_lp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_GeothermalCosts_GeoHourly_x_lp_nset, self->data_ptr);
}

static PyGetSetDef GeoHourly_getset[] = {
{"GF_flowrate", (getter)GeoHourly_get_GF_flowrate,(setter)GeoHourly_set_GF_flowrate,
	PyDoc_STR("*float*: GF Flow Rate [lb/h]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"condensate_pump_power", (getter)GeoHourly_get_condensate_pump_power,(setter)GeoHourly_set_condensate_pump_power,
	PyDoc_STR("*float*: hp\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"conversion_type", (getter)GeoHourly_get_conversion_type,(setter)GeoHourly_set_conversion_type,
	PyDoc_STR("*float*: Conversion Type\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"cw_pump_head", (getter)GeoHourly_get_cw_pump_head,(setter)GeoHourly_set_cw_pump_head,
	PyDoc_STR("*float*: Cooling Water Pump Head [lb/h]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"cw_pump_work", (getter)GeoHourly_get_cw_pump_work,(setter)GeoHourly_set_cw_pump_work,
	PyDoc_STR("*float*: CW Pump Work [kW]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"cwflow", (getter)GeoHourly_get_cwflow,(setter)GeoHourly_set_cwflow,
	PyDoc_STR("*float*: Cooling Water Flow [lb/h]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"design_temp", (getter)GeoHourly_get_design_temp,(setter)GeoHourly_set_design_temp,
	PyDoc_STR("*float*: Power block design temperature [C]\n\n*Required*: True"),
 	NULL},
{"eff_secondlaw", (getter)GeoHourly_get_eff_secondlaw,(setter)GeoHourly_set_eff_secondlaw,
	PyDoc_STR("*float*: Second Law Efficiency [%]\n\n*Required*: True"),
 	NULL},
{"flash_count", (getter)GeoHourly_get_flash_count,(setter)GeoHourly_set_flash_count,
	PyDoc_STR("*float*: Flash Count [(1 -2)]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"gross_output", (getter)GeoHourly_get_gross_output,(setter)GeoHourly_set_gross_output,
	PyDoc_STR("*float*: Gross output from GETEM [kW]\n\n*Required*: True"),
 	NULL},
{"hp_flash_pressure", (getter)GeoHourly_get_hp_flash_pressure,(setter)GeoHourly_set_hp_flash_pressure,
	PyDoc_STR("*float*: HP Flash Pressure [psia]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"lp_flash_pressure", (getter)GeoHourly_get_lp_flash_pressure,(setter)GeoHourly_set_lp_flash_pressure,
	PyDoc_STR("*float*: LP Flash Pressure [psia]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"ncg_condensate_pump", (getter)GeoHourly_get_ncg_condensate_pump,(setter)GeoHourly_set_ncg_condensate_pump,
	PyDoc_STR("*float*: Condensate Pump Work [kW]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"pressure_ratio_1", (getter)GeoHourly_get_pressure_ratio_1,(setter)GeoHourly_set_pressure_ratio_1,
	PyDoc_STR("*float*: Suction Steam Ratio 1\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"pressure_ratio_2", (getter)GeoHourly_get_pressure_ratio_2,(setter)GeoHourly_set_pressure_ratio_2,
	PyDoc_STR("*float*: Suction Steam Ratio 2\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"pressure_ratio_3", (getter)GeoHourly_get_pressure_ratio_3,(setter)GeoHourly_set_pressure_ratio_3,
	PyDoc_STR("*float*: Suction Steam Ratio 3\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"qCondenser", (getter)GeoHourly_get_qCondenser,(setter)GeoHourly_set_qCondenser,
	PyDoc_STR("*float*: Condenser Heat Rejected [btu/h]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"qRejectByStage_1", (getter)GeoHourly_get_qRejectByStage_1,(setter)GeoHourly_set_qRejectByStage_1,
	PyDoc_STR("*float*: Heat Rejected by NCG Condenser Stage 1 [BTU/hr]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"qRejectByStage_2", (getter)GeoHourly_get_qRejectByStage_2,(setter)GeoHourly_set_qRejectByStage_2,
	PyDoc_STR("*float*: Heat Rejected by NCG Condenser Stage 2 [BTU/hr]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"qRejectByStage_3", (getter)GeoHourly_get_qRejectByStage_3,(setter)GeoHourly_set_qRejectByStage_3,
	PyDoc_STR("*float*: Heat Rejected by NCG Condenser Stage 3 [BTU/hr]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"qRejectTotal", (getter)GeoHourly_get_qRejectTotal,(setter)GeoHourly_set_qRejectTotal,
	PyDoc_STR("*float*: Total Rejected Heat [btu/h]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"spec_vol", (getter)GeoHourly_get_spec_vol,(setter)GeoHourly_set_spec_vol,
	PyDoc_STR("*float*: Specific Volume [cft/lb]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"spec_vol_lp", (getter)GeoHourly_get_spec_vol_lp,(setter)GeoHourly_set_spec_vol_lp,
	PyDoc_STR("*float*: LP Specific Volume [cft/lb]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"v_stage_1", (getter)GeoHourly_get_v_stage_1,(setter)GeoHourly_set_v_stage_1,
	PyDoc_STR("*float*: Vacumm Pump Stage 1 [kW]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"v_stage_2", (getter)GeoHourly_get_v_stage_2,(setter)GeoHourly_set_v_stage_2,
	PyDoc_STR("*float*: Vacumm Pump Stage 2 [kW]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"v_stage_3", (getter)GeoHourly_get_v_stage_3,(setter)GeoHourly_set_v_stage_3,
	PyDoc_STR("*float*: Vacumm Pump Stage 3 [kW]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"x_hp", (getter)GeoHourly_get_x_hp,(setter)GeoHourly_set_x_hp,
	PyDoc_STR("*float*: HP Mass Fraction [%]\n\n*Required*: True if conversion_type=1"),
 	NULL},
{"x_lp", (getter)GeoHourly_get_x_lp,(setter)GeoHourly_set_x_lp,
	PyDoc_STR("*float*: LP Mass Fraction [%]\n\n*Required*: True if conversion_type=1"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject GeoHourly_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GeothermalCosts.GeoHourly",             /*tp_name*/
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
		GeoHourly_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		GeoHourly_getset,          /*tp_getset*/
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
Outputs_new(SAM_GeothermalCosts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GeothermalCosts", "Outputs")){
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
Outputs_get_baseline_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_GeothermalCosts_Outputs_baseline_cost_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"baseline_cost", (getter)Outputs_get_baseline_cost,(setter)0,
	PyDoc_STR("*float*: Baseline Cost [$/kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GeothermalCosts.Outputs",             /*tp_name*/
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
 * GeothermalCosts
 */

static PyTypeObject GeothermalCosts_Type;

static CmodObject *
newGeothermalCostsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &GeothermalCosts_Type);

	PySAM_TECH_ATTR()

	PyObject* GeoHourly_obj = GeoHourly_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "GeoHourly", GeoHourly_obj);
	Py_DECREF(GeoHourly_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* GeothermalCosts methods */

static void
GeothermalCosts_dealloc(CmodObject *self)
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
GeothermalCosts_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_GeothermalCosts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GeothermalCosts_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "GeothermalCosts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GeothermalCosts_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
GeothermalCosts_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef GeothermalCosts_methods[] = {
		{"execute",            (PyCFunction)GeothermalCosts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)GeothermalCosts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'GeoHourly': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)GeothermalCosts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)GeothermalCosts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GeothermalCosts_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
GeothermalCosts_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject GeothermalCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GeothermalCosts",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)GeothermalCosts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)GeothermalCosts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)GeothermalCosts_getattro, /*tp_getattro*/
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
		GeothermalCosts_methods,      /*tp_methods*/
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


/* Function of no arguments returning new GeothermalCosts object */

static PyObject *
GeothermalCosts_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newGeothermalCostsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
GeothermalCosts_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGeothermalCostsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
GeothermalCosts_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGeothermalCostsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "GeothermalCosts", def);

	return (PyObject *)rv;
}

static PyObject *
GeothermalCosts_from_existing(PyObject *self, PyObject *args)
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

	rv = newGeothermalCostsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "GeothermalCosts", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GeothermalCostsModule_methods[] = {
		{"new",             GeothermalCosts_new,         METH_VARARGS,
				PyDoc_STR("new() -> GeothermalCosts")},
		{"default",             GeothermalCosts_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> GeothermalCosts\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             GeothermalCosts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> GeothermalCosts\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   GeothermalCosts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> GeothermalCosts\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "GeothermalCosts");


static int
GeothermalCostsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	GeothermalCosts_Type.tp_dict = PyDict_New();
	if (!GeothermalCosts_Type.tp_dict) { goto fail; }

	/// Add the GeoHourly type object to GeothermalCosts_Type
	if (PyType_Ready(&GeoHourly_Type) < 0) { goto fail; }
	PyDict_SetItemString(GeothermalCosts_Type.tp_dict,
				"GeoHourly",
				(PyObject*)&GeoHourly_Type);
	Py_DECREF(&GeoHourly_Type);

	/// Add the Outputs type object to GeothermalCosts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(GeothermalCosts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the GeothermalCosts type object to the module
	if (PyType_Ready(&GeothermalCosts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"GeothermalCosts",
				(PyObject*)&GeothermalCosts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot GeothermalCostsModule_slots[] = {
		{Py_mod_exec, GeothermalCostsModule_exec},
		{0, NULL},
};

static struct PyModuleDef GeothermalCostsModule = {
		PyModuleDef_HEAD_INIT,
		"GeothermalCosts",
		module_doc,
		0,
		GeothermalCostsModule_methods,
		GeothermalCostsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_GeothermalCosts(void)
{
	return PyModuleDef_Init(&GeothermalCostsModule);
}