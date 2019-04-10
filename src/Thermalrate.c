#include <Python.h>

#include <SAM_Thermalrate.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Common Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thermalrate   data_ptr;
} CommonObject;

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_Thermalrate data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "Common")){
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
Common_get_en_thermal_rates(CommonObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Common_en_thermal_rates_fget, self->data_ptr);
}

static int
Common_set_en_thermal_rates(CommonObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_Common_en_thermal_rates_fset, self->data_ptr);
}

static PyObject *
Common_get_thermal_load_escalation(CommonObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_Common_thermal_load_escalation_aget, self->data_ptr);
}

static int
Common_set_thermal_load_escalation(CommonObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_Common_thermal_load_escalation_aset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"en_thermal_rates", (getter)Common_get_en_thermal_rates,(setter)Common_set_en_thermal_rates,
	"Optionally enable/disable thermal_rate [years], number.\n Constraints: INTEGER,MIN=0,MAX=1; ",
 	NULL},
{"thermal_load_escalation", (getter)Common_get_thermal_load_escalation,(setter)Common_set_thermal_load_escalation,
	"Annual load escalation [%/year], array.\n Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.Common",             /*tp_name*/
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
	 * Lifetime Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thermalrate   data_ptr;
} LifetimeObject;

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_Thermalrate data_ptr)
{
	PyObject* new_obj = Lifetime_Type.tp_alloc(&Lifetime_Type,0);

	LifetimeObject* Lifetime_obj = (LifetimeObject*)new_obj;

	Lifetime_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Lifetime methods */

static PyObject *
Lifetime_assign(LifetimeObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "Lifetime")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Lifetime_export(LifetimeObject *self, PyObject *args)
{
	PyTypeObject* tp = &Lifetime_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Lifetime_methods[] = {
		{"assign",            (PyCFunction)Lifetime_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Lifetime_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Lifetime_get_analysis_period(LifetimeObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Lifetime_analysis_period_fget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_Lifetime_analysis_period_fset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(LifetimeObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Lifetime_system_use_lifetime_output_fget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_Lifetime_system_use_lifetime_output_fset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	"Number of years in analysis [years], number.\n Constraints: INTEGER,POSITIVE; Required if: *.",
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	"Lifetime hourly system outputs [0/1], number.\n 0=hourly first year,1=hourly lifetime; Constraints: INTEGER,MIN=0,MAX=1; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.Lifetime",             /*tp_name*/
		sizeof(LifetimeObject),          /*tp_basicsize*/
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
		Lifetime_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Lifetime_getset,          /*tp_getset*/
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
	 * TimeSeries Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thermalrate   data_ptr;
} TimeSeriesObject;

static PyTypeObject TimeSeries_Type;

static PyObject *
TimeSeries_new(SAM_Thermalrate data_ptr)
{
	PyObject* new_obj = TimeSeries_Type.tp_alloc(&TimeSeries_Type,0);

	TimeSeriesObject* TimeSeries_obj = (TimeSeriesObject*)new_obj;

	TimeSeries_obj->data_ptr = data_ptr;

	return new_obj;
}

/* TimeSeries methods */

static PyObject *
TimeSeries_assign(TimeSeriesObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "TimeSeries")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TimeSeries_export(TimeSeriesObject *self, PyObject *args)
{
	PyTypeObject* tp = &TimeSeries_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TimeSeries_methods[] = {
		{"assign",            (PyCFunction)TimeSeries_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)TimeSeries_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TimeSeries_get_fuelcell_power_thermal(TimeSeriesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_TimeSeries_fuelcell_power_thermal_aget, self->data_ptr);
}

static int
TimeSeries_set_fuelcell_power_thermal(TimeSeriesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_TimeSeries_fuelcell_power_thermal_aset, self->data_ptr);
}

static PyObject *
TimeSeries_get_thermal_load(TimeSeriesObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_TimeSeries_thermal_load_aget, self->data_ptr);
}

static int
TimeSeries_set_thermal_load(TimeSeriesObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_TimeSeries_thermal_load_aset, self->data_ptr);
}

static PyGetSetDef TimeSeries_getset[] = {
{"fuelcell_power_thermal", (getter)TimeSeries_get_fuelcell_power_thermal,(setter)TimeSeries_set_fuelcell_power_thermal,
	"Fuel cell power generated [kW-t], array.\n Required if: *.",
 	NULL},
{"thermal_load", (getter)TimeSeries_get_thermal_load,(setter)TimeSeries_set_thermal_load,
	"Thermal load (year 1) [kW-t], array.\n ",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TimeSeries_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.TimeSeries",             /*tp_name*/
		sizeof(TimeSeriesObject),          /*tp_basicsize*/
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
		TimeSeries_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TimeSeries_getset,          /*tp_getset*/
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
	 * Financials Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thermalrate   data_ptr;
} FinancialsObject;

static PyTypeObject Financials_Type;

static PyObject *
Financials_new(SAM_Thermalrate data_ptr)
{
	PyObject* new_obj = Financials_Type.tp_alloc(&Financials_Type,0);

	FinancialsObject* Financials_obj = (FinancialsObject*)new_obj;

	Financials_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Financials methods */

static PyObject *
Financials_assign(FinancialsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "Financials")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Financials_export(FinancialsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Financials_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Financials_methods[] = {
		{"assign",            (PyCFunction)Financials_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Financials_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Financials_get_inflation_rate(FinancialsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Financials_inflation_rate_fget, self->data_ptr);
}

static int
Financials_set_inflation_rate(FinancialsObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_Financials_inflation_rate_fset, self->data_ptr);
}

static PyGetSetDef Financials_getset[] = {
{"inflation_rate", (getter)Financials_get_inflation_rate,(setter)Financials_set_inflation_rate,
	"Inflation rate [%], number.\n Constraints: MIN=-99; Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Financials_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.Financials",             /*tp_name*/
		sizeof(FinancialsObject),          /*tp_basicsize*/
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
		Financials_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Financials_getset,          /*tp_getset*/
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
	 * AnnualOutput Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thermalrate   data_ptr;
} AnnualOutputObject;

static PyTypeObject AnnualOutput_Type;

static PyObject *
AnnualOutput_new(SAM_Thermalrate data_ptr)
{
	PyObject* new_obj = AnnualOutput_Type.tp_alloc(&AnnualOutput_Type,0);

	AnnualOutputObject* AnnualOutput_obj = (AnnualOutputObject*)new_obj;

	AnnualOutput_obj->data_ptr = data_ptr;

	return new_obj;
}

/* AnnualOutput methods */

static PyObject *
AnnualOutput_assign(AnnualOutputObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "AnnualOutput")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
AnnualOutput_export(AnnualOutputObject *self, PyObject *args)
{
	PyTypeObject* tp = &AnnualOutput_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef AnnualOutput_methods[] = {
		{"assign",            (PyCFunction)AnnualOutput_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)AnnualOutput_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
AnnualOutput_get_thermal_degradation(AnnualOutputObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_AnnualOutput_thermal_degradation_aget, self->data_ptr);
}

static int
AnnualOutput_set_thermal_degradation(AnnualOutputObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_AnnualOutput_thermal_degradation_aset, self->data_ptr);
}

static PyGetSetDef AnnualOutput_getset[] = {
{"thermal_degradation", (getter)AnnualOutput_get_thermal_degradation,(setter)AnnualOutput_set_thermal_degradation,
	"Annual energy degradation [%], array.\n Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject AnnualOutput_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.AnnualOutput",             /*tp_name*/
		sizeof(AnnualOutputObject),          /*tp_basicsize*/
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
		AnnualOutput_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		AnnualOutput_getset,          /*tp_getset*/
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
	 * ThermalRate Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Thermalrate   data_ptr;
} ThermalRateObject;

static PyTypeObject ThermalRate_Type;

static PyObject *
ThermalRate_new(SAM_Thermalrate data_ptr)
{
	PyObject* new_obj = ThermalRate_Type.tp_alloc(&ThermalRate_Type,0);

	ThermalRateObject* ThermalRate_obj = (ThermalRateObject*)new_obj;

	ThermalRate_obj->data_ptr = data_ptr;

	return new_obj;
}

/* ThermalRate methods */

static PyObject *
ThermalRate_assign(ThermalRateObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "ThermalRate")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
ThermalRate_export(ThermalRateObject *self, PyObject *args)
{
	PyTypeObject* tp = &ThermalRate_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef ThermalRate_methods[] = {
		{"assign",            (PyCFunction)ThermalRate_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)ThermalRate_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
ThermalRate_get_thermal_buy_rate(ThermalRateObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_ThermalRate_thermal_buy_rate_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_buy_rate(ThermalRateObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_ThermalRate_thermal_buy_rate_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_buy_rate_flat(ThermalRateObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_ThermalRate_thermal_buy_rate_flat_fget, self->data_ptr);
}

static int
ThermalRate_set_thermal_buy_rate_flat(ThermalRateObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_ThermalRate_thermal_buy_rate_flat_fset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_buy_rate_option(ThermalRateObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_ThermalRate_thermal_buy_rate_option_fget, self->data_ptr);
}

static int
ThermalRate_set_thermal_buy_rate_option(ThermalRateObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_ThermalRate_thermal_buy_rate_option_fset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_rate_escalation(ThermalRateObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_ThermalRate_thermal_rate_escalation_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_rate_escalation(ThermalRateObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_ThermalRate_thermal_rate_escalation_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_sell_rate(ThermalRateObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_ThermalRate_thermal_sell_rate_aget, self->data_ptr);
}

static int
ThermalRate_set_thermal_sell_rate(ThermalRateObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Thermalrate_ThermalRate_thermal_sell_rate_aset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_sell_rate_flat(ThermalRateObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_ThermalRate_thermal_sell_rate_flat_fget, self->data_ptr);
}

static int
ThermalRate_set_thermal_sell_rate_flat(ThermalRateObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_ThermalRate_thermal_sell_rate_flat_fset, self->data_ptr);
}

static PyObject *
ThermalRate_get_thermal_sell_rate_option(ThermalRateObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_ThermalRate_thermal_sell_rate_option_fget, self->data_ptr);
}

static int
ThermalRate_set_thermal_sell_rate_option(ThermalRateObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Thermalrate_ThermalRate_thermal_sell_rate_option_fset, self->data_ptr);
}

static PyGetSetDef ThermalRate_getset[] = {
{"thermal_buy_rate", (getter)ThermalRate_get_thermal_buy_rate,(setter)ThermalRate_set_thermal_buy_rate,
	"Thermal buy rate [$/kW-t], array.\n Required if: ?=0.",
 	NULL},
{"thermal_buy_rate_flat", (getter)ThermalRate_get_thermal_buy_rate_flat,(setter)ThermalRate_set_thermal_buy_rate_flat,
	"Thermal buy rate flat [$/kW-t], number.\n Required if: ?=0.",
 	NULL},
{"thermal_buy_rate_option", (getter)ThermalRate_get_thermal_buy_rate_option,(setter)ThermalRate_set_thermal_buy_rate_option,
	"Thermal buy rate option [0/1], number.\n 0=flat,1=timestep; Constraints: INTEGER,MIN=0,MAX=1; Required if: ?=0.",
 	NULL},
{"thermal_rate_escalation", (getter)ThermalRate_get_thermal_rate_escalation,(setter)ThermalRate_set_thermal_rate_escalation,
	"Annual thermal rate escalation [%/year], array.\n Required if: ?=0.",
 	NULL},
{"thermal_sell_rate", (getter)ThermalRate_get_thermal_sell_rate,(setter)ThermalRate_set_thermal_sell_rate,
	"Thermal sell rate [$/kW-t], array.\n Required if: ?=0.",
 	NULL},
{"thermal_sell_rate_flat", (getter)ThermalRate_get_thermal_sell_rate_flat,(setter)ThermalRate_set_thermal_sell_rate_flat,
	"Thermal sell rate flat [$/kW-t], number.\n Required if: ?=0.",
 	NULL},
{"thermal_sell_rate_option", (getter)ThermalRate_get_thermal_sell_rate_option,(setter)ThermalRate_set_thermal_sell_rate_option,
	"Thermal sell rate option [0/1], number.\n 0=flat,1=timestep; Constraints: INTEGER,MIN=0,MAX=1; Required if: ?=0.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject ThermalRate_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.ThermalRate",             /*tp_name*/
		sizeof(ThermalRateObject),          /*tp_basicsize*/
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
		ThermalRate_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		ThermalRate_getset,          /*tp_getset*/
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
	SAM_Thermalrate   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Thermalrate data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Thermalrate", "Outputs")){
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
Outputs_get_thermal_cost_with_system_year1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Outputs_thermal_cost_with_system_year1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_cost_without_system_year1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Outputs_thermal_cost_without_system_year1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_load_year1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Outputs_thermal_load_year1_fget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_revenue_with_system(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_Outputs_thermal_revenue_with_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_revenue_without_system(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Thermalrate_Outputs_thermal_revenue_without_system_aget, self->data_ptr);
}

static PyObject *
Outputs_get_thermal_savings_year1(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Thermalrate_Outputs_thermal_savings_year1_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"thermal_cost_with_system_year1", (getter)Outputs_get_thermal_cost_with_system_year1,(setter)0,
	"Thermal cost with sytem (year 1) [$], number.",
 	NULL},
{"thermal_cost_without_system_year1", (getter)Outputs_get_thermal_cost_without_system_year1,(setter)0,
	"Thermal cost without system (year 1) [$], number.",
 	NULL},
{"thermal_load_year1", (getter)Outputs_get_thermal_load_year1,(setter)0,
	"Thermal load (year 1) [$], number.",
 	NULL},
{"thermal_revenue_with_system", (getter)Outputs_get_thermal_revenue_with_system,(setter)0,
	"Thermal revenue with system [$], array.",
 	NULL},
{"thermal_revenue_without_system", (getter)Outputs_get_thermal_revenue_without_system,(setter)0,
	"Thermal revenue without system [$], array.",
 	NULL},
{"thermal_savings_year1", (getter)Outputs_get_thermal_savings_year1,(setter)0,
	"Thermal savings (year 1) [$], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate.Outputs",             /*tp_name*/
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
 * Thermalrate
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Thermalrate   data_ptr;
} ThermalrateObject;

static PyTypeObject Thermalrate_Type;

#define ThermalrateObject_Check(v)      (Py_TYPE(v) == &Thermalrate_Type)

static ThermalrateObject *
newThermalrateObject(void* data_ptr)
{
	ThermalrateObject *self;
	self = PyObject_New(ThermalrateObject, &Thermalrate_Type);

	PySAM_TECH_ATTR("Thermalrate", SAM_Thermalrate_construct)

PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

PyObject* TimeSeries_obj = TimeSeries_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TimeSeries", TimeSeries_obj);
	Py_DECREF(TimeSeries_obj);

PyObject* Financials_obj = Financials_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Financials", Financials_obj);
	Py_DECREF(Financials_obj);

PyObject* AnnualOutput_obj = AnnualOutput_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "AnnualOutput", AnnualOutput_obj);
	Py_DECREF(AnnualOutput_obj);

PyObject* ThermalRate_obj = ThermalRate_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "ThermalRate", ThermalRate_obj);
	Py_DECREF(ThermalRate_obj);

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

/* Thermalrate methods */

static void
Thermalrate_dealloc(ThermalrateObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Thermalrate_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Thermalrate_execute(ThermalrateObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Thermalrate_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Thermalrate_assign(ThermalrateObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Thermalrate"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Thermalrate_export(ThermalrateObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef Thermalrate_methods[] = {
		{"execute",            (PyCFunction)Thermalrate_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Thermalrate_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Thermalrate_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Thermalrate_getattro(ThermalrateObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Thermalrate_setattr(ThermalrateObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Thermalrate_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Thermalrate",            /*tp_name*/
		sizeof(ThermalrateObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Thermalrate_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Thermalrate_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Thermalrate_getattro, /*tp_getattro*/
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
		Thermalrate_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Thermalrate object */

static PyObject *
Thermalrate_new(PyObject *self, PyObject *args)
{
	ThermalrateObject *rv;
	rv = newThermalrateObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Thermalrate_wrap(PyObject *self, PyObject *args)
{
	ThermalrateObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThermalrateObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Thermalrate_default(PyObject *self, PyObject *args)
{
	ThermalrateObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newThermalrateObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Thermalrate", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef ThermalrateModule_methods[] = {
		{"new",             Thermalrate_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Thermalrate object")},
		{"default",             Thermalrate_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Thermalrate object with financial model-specific default attributes\n"
				"Options: Single Owner, Commercial, ")},
		{"wrap",             Thermalrate_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Thermalrate object around existing PySSC data")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Refer to http://www.github.com/nrel/PySAM for source code.");


static int
ThermalrateModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Thermalrate_Type.tp_dict = PyDict_New();
	if (!Thermalrate_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Thermalrate_Type
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
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Common type object to Thermalrate_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Lifetime type object to Thermalrate_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the TimeSeries type object to Thermalrate_Type
	if (PyType_Ready(&TimeSeries_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"TimeSeries",
				(PyObject*)&TimeSeries_Type);
	Py_DECREF(&TimeSeries_Type);

	/// Add the Financials type object to Thermalrate_Type
	if (PyType_Ready(&Financials_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"Financials",
				(PyObject*)&Financials_Type);
	Py_DECREF(&Financials_Type);

	/// Add the AnnualOutput type object to Thermalrate_Type
	if (PyType_Ready(&AnnualOutput_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"AnnualOutput",
				(PyObject*)&AnnualOutput_Type);
	Py_DECREF(&AnnualOutput_Type);

	/// Add the ThermalRate type object to Thermalrate_Type
	if (PyType_Ready(&ThermalRate_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"ThermalRate",
				(PyObject*)&ThermalRate_Type);
	Py_DECREF(&ThermalRate_Type);

	/// Add the Outputs type object to Thermalrate_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Thermalrate_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Thermalrate type object to the module
	if (PyType_Ready(&Thermalrate_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Thermalrate",
				(PyObject*)&Thermalrate_Type);

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot ThermalrateModule_slots[] = {
		{Py_mod_exec, ThermalrateModule_exec},
		{0, NULL},
};

static struct PyModuleDef ThermalrateModule = {
		PyModuleDef_HEAD_INIT,
		"Thermalrate",
		module_doc,
		0,
		ThermalrateModule_methods,
		ThermalrateModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Thermalrate(void)
{
	return PyModuleDef_Init(&ThermalrateModule);
}