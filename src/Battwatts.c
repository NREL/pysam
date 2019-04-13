#include <Python.h>

#include <SAM_Battwatts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * BatteryModelSimple Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battwatts   data_ptr;
} BatteryModelSimpleObject;

static PyTypeObject BatteryModelSimple_Type;

static PyObject *
BatteryModelSimple_new(SAM_Battwatts data_ptr)
{
	PyObject* new_obj = BatteryModelSimple_Type.tp_alloc(&BatteryModelSimple_Type,0);

	BatteryModelSimpleObject* BatteryModelSimple_obj = (BatteryModelSimpleObject*)new_obj;

	BatteryModelSimple_obj->data_ptr = data_ptr;

	return new_obj;
}

/* BatteryModelSimple methods */

static PyObject *
BatteryModelSimple_assign(BatteryModelSimpleObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "BatteryModelSimple")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
BatteryModelSimple_export(BatteryModelSimpleObject *self, PyObject *args)
{
	PyTypeObject* tp = &BatteryModelSimple_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef BatteryModelSimple_methods[] = {
		{"assign",            (PyCFunction)BatteryModelSimple_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)BatteryModelSimple_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
BatteryModelSimple_get_batt_simple_chemistry(BatteryModelSimpleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_BatteryModelSimple_batt_simple_chemistry_fget, self->data_ptr);
}

static int
BatteryModelSimple_set_batt_simple_chemistry(BatteryModelSimpleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_BatteryModelSimple_batt_simple_chemistry_fset, self->data_ptr);
}

static PyObject *
BatteryModelSimple_get_batt_simple_dispatch(BatteryModelSimpleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_BatteryModelSimple_batt_simple_dispatch_fget, self->data_ptr);
}

static int
BatteryModelSimple_set_batt_simple_dispatch(BatteryModelSimpleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_BatteryModelSimple_batt_simple_dispatch_fset, self->data_ptr);
}

static PyObject *
BatteryModelSimple_get_batt_simple_enable(BatteryModelSimpleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_BatteryModelSimple_batt_simple_enable_fget, self->data_ptr);
}

static int
BatteryModelSimple_set_batt_simple_enable(BatteryModelSimpleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_BatteryModelSimple_batt_simple_enable_fset, self->data_ptr);
}

static PyObject *
BatteryModelSimple_get_batt_simple_kw(BatteryModelSimpleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_BatteryModelSimple_batt_simple_kw_fget, self->data_ptr);
}

static int
BatteryModelSimple_set_batt_simple_kw(BatteryModelSimpleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_BatteryModelSimple_batt_simple_kw_fset, self->data_ptr);
}

static PyObject *
BatteryModelSimple_get_batt_simple_kwh(BatteryModelSimpleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_BatteryModelSimple_batt_simple_kwh_fget, self->data_ptr);
}

static int
BatteryModelSimple_set_batt_simple_kwh(BatteryModelSimpleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_BatteryModelSimple_batt_simple_kwh_fset, self->data_ptr);
}

static PyObject *
BatteryModelSimple_get_batt_simple_meter_position(BatteryModelSimpleObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_BatteryModelSimple_batt_simple_meter_position_fget, self->data_ptr);
}

static int
BatteryModelSimple_set_batt_simple_meter_position(BatteryModelSimpleObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_BatteryModelSimple_batt_simple_meter_position_fset, self->data_ptr);
}

static PyGetSetDef BatteryModelSimple_getset[] = {
{"batt_simple_chemistry", (getter)BatteryModelSimple_get_batt_simple_chemistry,(setter)BatteryModelSimple_set_batt_simple_chemistry,
	"Battery Chemistry [0=lead acid/1=Li-ion/2], number.\n 0 if not set.",
 	NULL},
{"batt_simple_dispatch", (getter)BatteryModelSimple_get_batt_simple_dispatch,(setter)BatteryModelSimple_set_batt_simple_dispatch,
	"Battery Dispatch [0=peak shaving look ahead/1=peak shaving look behind], number.\n 0 if not set.",
 	NULL},
{"batt_simple_enable", (getter)BatteryModelSimple_get_batt_simple_enable,(setter)BatteryModelSimple_set_batt_simple_enable,
	"Enable Battery [0/1], number.\n Constraints: BOOLEAN; 0 if not set.",
 	NULL},
{"batt_simple_kw", (getter)BatteryModelSimple_get_batt_simple_kw,(setter)BatteryModelSimple_set_batt_simple_kw,
	"Battery Power [kW], number.\n 0 if not set.",
 	NULL},
{"batt_simple_kwh", (getter)BatteryModelSimple_get_batt_simple_kwh,(setter)BatteryModelSimple_set_batt_simple_kwh,
	"Battery Capacity [kWh], number.\n 0 if not set.",
 	NULL},
{"batt_simple_meter_position", (getter)BatteryModelSimple_get_batt_simple_meter_position,(setter)BatteryModelSimple_set_batt_simple_meter_position,
	"Battery Meter Position [0=behind meter/1=front of meter], number.\n 0 if not set.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject BatteryModelSimple_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts.BatteryModelSimple",             /*tp_name*/
		sizeof(BatteryModelSimpleObject),          /*tp_basicsize*/
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
		BatteryModelSimple_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		BatteryModelSimple_getset,          /*tp_getset*/
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
	 * Common Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battwatts   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Battwatts data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	CommonObject* Common_obj = (CommonObject*)new_obj;

	Common_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(CommonObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(CommonObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_ac(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Common_ac_aget, self->data_ptr);
}

static int
Common_set_ac(CommonObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battwatts_Common_ac_aset, self->data_ptr);
}

static PyObject *
Common_get_dc(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Common_dc_aget, self->data_ptr);
}

static int
Common_set_dc(CommonObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battwatts_Common_dc_aset, self->data_ptr);
}

static PyObject *
Common_get_inverter_efficiency(CommonObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_Common_inverter_efficiency_fget, self->data_ptr);
}

static int
Common_set_inverter_efficiency(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_Common_inverter_efficiency_fset, self->data_ptr);
}

static PyObject *
Common_get_inverter_model(CommonObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_Common_inverter_model_fget, self->data_ptr);
}

static int
Common_set_inverter_model(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Battwatts_Common_inverter_model_fset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"ac", (getter)Common_get_ac,(setter)Common_set_ac,
	"AC inverter power [W], array.\n ",
 	NULL},
{"dc", (getter)Common_get_dc,(setter)Common_set_dc,
	"DC array power [W], array.\n ",
 	NULL},
{"inverter_efficiency", (getter)Common_get_inverter_efficiency,(setter)Common_set_inverter_efficiency,
	"Inverter Efficiency [%], number.\n ",
 	NULL},
{"inverter_model", (getter)Common_get_inverter_model,(setter)Common_set_inverter_model,
	"Inverter model specifier, number.\n 0=cec,1=datasheet,2=partload,3=coefficientgenerator,4=generic; Constraints: INTEGER,MIN=0,MAX=4; ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts.Common",             /*tp_name*/
		sizeof(CommonObject),          /*tp_basicsize*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
	 * ElectricLoadOther Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Battwatts   data_ptr;
} ElectricLoadOtherObject;

static PyTypeObject ElectricLoadOther_Type;

static PyObject *
ElectricLoadOther_new(SAM_Battwatts data_ptr)
{
	PyObject* new_obj = ElectricLoadOther_Type.tp_alloc(&ElectricLoadOther_Type,0);

	ElectricLoadOtherObject* ElectricLoadOther_obj = (ElectricLoadOtherObject*)new_obj;

	ElectricLoadOther_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ElectricLoadOther methods */

static PyObject *
ElectricLoadOther_assign(ElectricLoadOtherObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "ElectricLoadOther")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ElectricLoadOther_export(ElectricLoadOtherObject *self, PyObject *args)
{
	PyTypeObject* tp = &ElectricLoadOther_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ElectricLoadOther_methods[] = {
		{"assign",            (PyCFunction)ElectricLoadOther_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ElectricLoadOther_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ElectricLoadOther_get_load(ElectricLoadOtherObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_ElectricLoadOther_load_aget, self->data_ptr);
}

static int
ElectricLoadOther_set_load(ElectricLoadOtherObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Battwatts_ElectricLoadOther_load_aset, self->data_ptr);
}

static PyGetSetDef ElectricLoadOther_getset[] = {
{"load", (getter)ElectricLoadOther_get_load,(setter)ElectricLoadOther_set_load,
	"Electricity load (year 1) [kW], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ElectricLoadOther_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts.ElectricLoadOther",             /*tp_name*/
		sizeof(ElectricLoadOtherObject),          /*tp_basicsize*/
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
		ElectricLoadOther_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ElectricLoadOther_getset,          /*tp_getset*/
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
	SAM_Battwatts   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Battwatts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Battwatts", "Outputs")){
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
Outputs_get_annual_export_to_grid_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_annual_export_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_import_to_grid_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_annual_import_to_grid_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_conversion_efficiency(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_Outputs_average_battery_conversion_efficiency_fget, self->data_ptr);
}

static PyObject *
Outputs_get_average_battery_roundtrip_efficiency(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_Outputs_average_battery_roundtrip_efficiency_fget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_DOD(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_DOD_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_I(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_I_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_SOC(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_SOC_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_from_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_charge_from_pv(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_charge_from_pv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_discharge_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_discharge_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_energy_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_annual_energy_system_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_annual_energy_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_installed_capacity(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_Outputs_batt_bank_installed_capacity_fget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_bank_replacement(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_bank_replacement_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_percent(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_capacity_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_capacity_thermal_percent(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_capacity_thermal_percent_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_conversion_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_conversion_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cost_to_cycle(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_cost_to_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_cycles(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_cycles_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_dispatch_sched(OutputsObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_Battwatts_Outputs_batt_dispatch_sched_mget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_power_target(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_pv_charge_percent(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Battwatts_Outputs_batt_pv_charge_percent_fget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q0(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_q0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q1(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_q1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_q2(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_q2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_qmax_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmaxI(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_qmaxI_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_qmax_thermal(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_qmax_thermal_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_system_loss(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_system_loss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_temperature(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_temperature_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_batt_voltage_cell(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_batt_voltage_cell_aget, self->data_ptr);
}

static PyObject *
Outputs_get_fuelcell_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_fuelcell_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_power_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_power_target(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_power_target_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_grid_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_batt_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_batt_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_batt_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_grid_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_grid_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_grid_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pv_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_monthly_pv_to_load_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_batt(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pv_to_batt_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_grid(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pv_to_grid_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pv_to_load(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Battwatts_Outputs_pv_to_load_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_export_to_grid_energy", (getter)Outputs_get_annual_export_to_grid_energy,(setter)0,
	"Annual energy exported to grid [kWh], array.",
 	NULL},
{"annual_import_to_grid_energy", (getter)Outputs_get_annual_import_to_grid_energy,(setter)0,
	"Annual energy imported from grid [kWh], array.",
 	NULL},
{"average_battery_conversion_efficiency", (getter)Outputs_get_average_battery_conversion_efficiency,(setter)0,
	"Battery average cycle conversion efficiency [%], number.",
 	NULL},
{"average_battery_roundtrip_efficiency", (getter)Outputs_get_average_battery_roundtrip_efficiency,(setter)0,
	"Battery average roundtrip efficiency [%], number.",
 	NULL},
{"batt_DOD", (getter)Outputs_get_batt_DOD,(setter)0,
	"Battery cycle depth of discharge [%], array.",
 	NULL},
{"batt_I", (getter)Outputs_get_batt_I,(setter)0,
	"Battery current [A], array.",
 	NULL},
{"batt_SOC", (getter)Outputs_get_batt_SOC,(setter)0,
	"Battery state of charge [%], array.",
 	NULL},
{"batt_annual_charge_energy", (getter)Outputs_get_batt_annual_charge_energy,(setter)0,
	"Battery annual energy charged [kWh], array.",
 	NULL},
{"batt_annual_charge_from_grid", (getter)Outputs_get_batt_annual_charge_from_grid,(setter)0,
	"Battery annual energy charged from grid [kWh], array.",
 	NULL},
{"batt_annual_charge_from_pv", (getter)Outputs_get_batt_annual_charge_from_pv,(setter)0,
	"Battery annual energy charged from PV [kWh], array.",
 	NULL},
{"batt_annual_discharge_energy", (getter)Outputs_get_batt_annual_discharge_energy,(setter)0,
	"Battery annual energy discharged [kWh], array.",
 	NULL},
{"batt_annual_energy_loss", (getter)Outputs_get_batt_annual_energy_loss,(setter)0,
	"Battery annual energy loss [kWh], array.",
 	NULL},
{"batt_annual_energy_system_loss", (getter)Outputs_get_batt_annual_energy_system_loss,(setter)0,
	"Battery annual system energy loss [kWh], array.",
 	NULL},
{"batt_bank_installed_capacity", (getter)Outputs_get_batt_bank_installed_capacity,(setter)0,
	"Battery bank installed capacity [kWh], number.",
 	NULL},
{"batt_bank_replacement", (getter)Outputs_get_batt_bank_replacement,(setter)0,
	"Battery bank replacements per year [number/year], array.",
 	NULL},
{"batt_capacity_percent", (getter)Outputs_get_batt_capacity_percent,(setter)0,
	"Battery capacity percent for lifetime [%], array.",
 	NULL},
{"batt_capacity_thermal_percent", (getter)Outputs_get_batt_capacity_thermal_percent,(setter)0,
	"Battery capacity percent for temperature [%], array.",
 	NULL},
{"batt_conversion_loss", (getter)Outputs_get_batt_conversion_loss,(setter)0,
	"Electricity loss in battery power electronics [kW], array.",
 	NULL},
{"batt_cost_to_cycle", (getter)Outputs_get_batt_cost_to_cycle,(setter)0,
	"Computed cost to cycle [$/cycle], array.",
 	NULL},
{"batt_cycles", (getter)Outputs_get_batt_cycles,(setter)0,
	"Battery number of cycles, array.",
 	NULL},
{"batt_dispatch_sched", (getter)Outputs_get_batt_dispatch_sched,(setter)0,
	"Battery dispatch schedule, matrix.",
 	NULL},
{"batt_power", (getter)Outputs_get_batt_power,(setter)0,
	"Electricity to/from battery [kW], array.",
 	NULL},
{"batt_power_target", (getter)Outputs_get_batt_power_target,(setter)0,
	"Electricity battery power target for automated dispatch [kW], array.",
 	NULL},
{"batt_pv_charge_percent", (getter)Outputs_get_batt_pv_charge_percent,(setter)0,
	"Battery percent energy charged from PV [%], number.",
 	NULL},
{"batt_q0", (getter)Outputs_get_batt_q0,(setter)0,
	"Battery total charge [Ah], array.",
 	NULL},
{"batt_q1", (getter)Outputs_get_batt_q1,(setter)0,
	"Battery available charge [Ah], array.",
 	NULL},
{"batt_q2", (getter)Outputs_get_batt_q2,(setter)0,
	"Battery bound charge [Ah], array.",
 	NULL},
{"batt_qmax", (getter)Outputs_get_batt_qmax,(setter)0,
	"Battery maximum charge with degradation [Ah], array.",
 	NULL},
{"batt_qmaxI", (getter)Outputs_get_batt_qmaxI,(setter)0,
	"Battery maximum capacity at current [Ah], array.",
 	NULL},
{"batt_qmax_thermal", (getter)Outputs_get_batt_qmax_thermal,(setter)0,
	"Battery maximum charge at temperature [Ah], array.",
 	NULL},
{"batt_system_loss", (getter)Outputs_get_batt_system_loss,(setter)0,
	"Electricity loss from battery ancillary equipment [kW], array.",
 	NULL},
{"batt_temperature", (getter)Outputs_get_batt_temperature,(setter)0,
	"Battery temperature [C], array.",
 	NULL},
{"batt_to_grid", (getter)Outputs_get_batt_to_grid,(setter)0,
	"Electricity to grid from battery [kW], array.",
 	NULL},
{"batt_to_load", (getter)Outputs_get_batt_to_load,(setter)0,
	"Electricity to load from battery [kW], array.",
 	NULL},
{"batt_voltage", (getter)Outputs_get_batt_voltage,(setter)0,
	"Battery voltage [V], array.",
 	NULL},
{"batt_voltage_cell", (getter)Outputs_get_batt_voltage_cell,(setter)0,
	"Battery cell voltage [V], array.",
 	NULL},
{"fuelcell_to_batt", (getter)Outputs_get_fuelcell_to_batt,(setter)0,
	"Electricity to battery from fuel cell [kW], array.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"System power generated [kW], array.",
 	NULL},
{"grid_power", (getter)Outputs_get_grid_power,(setter)0,
	"Electricity to/from grid [kW], array.",
 	NULL},
{"grid_power_target", (getter)Outputs_get_grid_power_target,(setter)0,
	"Electricity grid power target for automated dispatch [kW], array.",
 	NULL},
{"grid_to_batt", (getter)Outputs_get_grid_to_batt,(setter)0,
	"Electricity to battery from grid [kW], array.",
 	NULL},
{"grid_to_load", (getter)Outputs_get_grid_to_load,(setter)0,
	"Electricity to load from grid [kW], array.",
 	NULL},
{"monthly_batt_to_grid", (getter)Outputs_get_monthly_batt_to_grid,(setter)0,
	"Energy to grid from battery [kWh], array.",
 	NULL},
{"monthly_batt_to_load", (getter)Outputs_get_monthly_batt_to_load,(setter)0,
	"Energy to load from battery [kWh], array.",
 	NULL},
{"monthly_grid_to_batt", (getter)Outputs_get_monthly_grid_to_batt,(setter)0,
	"Energy to battery from grid [kWh], array.",
 	NULL},
{"monthly_grid_to_load", (getter)Outputs_get_monthly_grid_to_load,(setter)0,
	"Energy to load from grid [kWh], array.",
 	NULL},
{"monthly_pv_to_batt", (getter)Outputs_get_monthly_pv_to_batt,(setter)0,
	"Energy to battery from PV [kWh], array.",
 	NULL},
{"monthly_pv_to_grid", (getter)Outputs_get_monthly_pv_to_grid,(setter)0,
	"Energy to grid from PV [kWh], array.",
 	NULL},
{"monthly_pv_to_load", (getter)Outputs_get_monthly_pv_to_load,(setter)0,
	"Energy to load from PV [kWh], array.",
 	NULL},
{"pv_to_batt", (getter)Outputs_get_pv_to_batt,(setter)0,
	"Electricity to battery from PV [kW], array.",
 	NULL},
{"pv_to_grid", (getter)Outputs_get_pv_to_grid,(setter)0,
	"Electricity to grid from PV [kW], array.",
 	NULL},
{"pv_to_load", (getter)Outputs_get_pv_to_load,(setter)0,
	"Electricity to load from PV [kW], array.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts.Outputs",             /*tp_name*/
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
 * Battwatts
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Battwatts   data_ptr;
} BattwattsObject;

static PyTypeObject Battwatts_Type;

#define BattwattsObject_Check(v)      (Py_TYPE(v) == &Battwatts_Type)

static BattwattsObject *
newBattwattsObject(void* data_ptr)
{
	BattwattsObject *self;
	self = PyObject_New(BattwattsObject, &Battwatts_Type);

	PySAM_TECH_ATTR("Battwatts", SAM_Battwatts_construct)

	PyObject* BatteryModelSimple_obj = BatteryModelSimple_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "BatteryModelSimple", BatteryModelSimple_obj);
	Py_DECREF(BatteryModelSimple_obj);

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* ElectricLoadOther_obj = ElectricLoadOther_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ElectricLoadOther", ElectricLoadOther_obj);
	Py_DECREF(ElectricLoadOther_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* Battwatts methods */

static void
Battwatts_dealloc(BattwattsObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Battwatts_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Battwatts_execute(BattwattsObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Battwatts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Battwatts_assign(BattwattsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Battwatts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Battwatts_export(BattwattsObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Battwatts_methods[] = {
		{"execute",            (PyCFunction)Battwatts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Battwatts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Battwatts_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Battwatts_getattro(BattwattsObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Battwatts_setattr(BattwattsObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Battwatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Battwatts",            /*tp_name*/
		sizeof(BattwattsObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Battwatts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Battwatts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Battwatts_getattro, /*tp_getattro*/
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
		Battwatts_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Battwatts object */

static PyObject *
Battwatts_new(PyObject *self, PyObject *args)
{
	BattwattsObject *rv;
	rv = newBattwattsObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Battwatts_wrap(PyObject *self, PyObject *args)
{
	BattwattsObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBattwattsObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Battwatts_default(PyObject *self, PyObject *args)
{
	BattwattsObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBattwattsObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Battwatts", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BattwattsModule_methods[] = {
		{"new",             Battwatts_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Battwatts object")},
		{"default",             Battwatts_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Battwatts object with financial model-specific default attributes\n"
				"Options: TcsMSLF, TcslinearFresnel, Swh, Tcsdish, GenericSystem, Pvsamv1, Fuelcell, TcsgenericSolar, TcstroughPhysical, Pvwattsv5, TcstroughEmpirical, Biomass, Windpower")},
		{"wrap",             Battwatts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Battwatts object around existing PySSC data, taking over memory ownership")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Simplified battery storage model");


static int
BattwattsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	Battwatts_Type.tp_dict = PyDict_New();
	if (!Battwatts_Type.tp_dict) { goto fail; }

	/// Add the BatteryModelSimple type object to Battwatts_Type
	if (PyType_Ready(&BatteryModelSimple_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"BatteryModelSimple",
				(PyObject*)&BatteryModelSimple_Type);
	Py_DECREF(&BatteryModelSimple_Type);

	/// Add the Common type object to Battwatts_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the ElectricLoadOther type object to Battwatts_Type
	if (PyType_Ready(&ElectricLoadOther_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"ElectricLoadOther",
				(PyObject*)&ElectricLoadOther_Type);
	Py_DECREF(&ElectricLoadOther_Type);

	/// Add the Outputs type object to Battwatts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Battwatts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Battwatts type object to the module
	if (PyType_Ready(&Battwatts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Battwatts",
				(PyObject*)&Battwatts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot BattwattsModule_slots[] = {
		{Py_mod_exec, BattwattsModule_exec},
		{0, NULL},
};

static struct PyModuleDef BattwattsModule = {
		PyModuleDef_HEAD_INIT,
		"Battwatts",
		module_doc,
		0,
		BattwattsModule_methods,
		BattwattsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Battwatts(void)
{
	return PyModuleDef_Init(&BattwattsModule);
}