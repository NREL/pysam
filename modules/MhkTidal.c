#include <Python.h>

#include <SAM_MhkTidal.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * MHKTidal Group
 */ 

static PyTypeObject MHKTidal_Type;

static PyObject *
MHKTidal_new(SAM_MhkTidal data_ptr)
{
	PyObject* new_obj = MHKTidal_Type.tp_alloc(&MHKTidal_Type,0);

	VarGroupObject* MHKTidal_obj = (VarGroupObject*)new_obj;

	MHKTidal_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* MHKTidal methods */

static PyObject *
MHKTidal_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkTidal", "MHKTidal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MHKTidal_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &MHKTidal_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MhkTidal", "MHKTidal")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MHKTidal_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &MHKTidal_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef MHKTidal_methods[] = {
		{"assign",            (PyCFunction)MHKTidal_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``MHKTidal_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)MHKTidal_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``MHKTidal_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)MHKTidal_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MHKTidal_get_balance_of_system_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_balance_of_system_cost_total_nget, self->data_ptr);
}

static int
MHKTidal_set_balance_of_system_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_balance_of_system_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_device_costs_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_device_costs_total_nget, self->data_ptr);
}

static int
MHKTidal_set_device_costs_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_device_costs_total_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_financial_cost_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_financial_cost_total_nget, self->data_ptr);
}

static int
MHKTidal_set_financial_cost_total(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_financial_cost_total_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_fixed_charge_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_fixed_charge_rate_nget, self->data_ptr);
}

static int
MHKTidal_set_fixed_charge_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_fixed_charge_rate_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_loss_additional(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_loss_additional_nget, self->data_ptr);
}

static int
MHKTidal_set_loss_additional(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_loss_additional_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_loss_array_spacing(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_loss_array_spacing_nget, self->data_ptr);
}

static int
MHKTidal_set_loss_array_spacing(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_loss_array_spacing_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_loss_downtime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_loss_downtime_nget, self->data_ptr);
}

static int
MHKTidal_set_loss_downtime(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_loss_downtime_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_loss_resource_overprediction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_loss_resource_overprediction_nget, self->data_ptr);
}

static int
MHKTidal_set_loss_resource_overprediction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_loss_resource_overprediction_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_loss_transmission(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_loss_transmission_nget, self->data_ptr);
}

static int
MHKTidal_set_loss_transmission(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_loss_transmission_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_number_devices(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_number_devices_nget, self->data_ptr);
}

static int
MHKTidal_set_number_devices(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_number_devices_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_system_capacity_nget, self->data_ptr);
}

static int
MHKTidal_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_system_capacity_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_tidal_power_curve(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkTidal_MHKTidal_tidal_power_curve_mget, self->data_ptr);
}

static int
MHKTidal_set_tidal_power_curve(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MhkTidal_MHKTidal_tidal_power_curve_mset, self->data_ptr);
}

static PyObject *
MHKTidal_get_tidal_resource(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_MhkTidal_MHKTidal_tidal_resource_mget, self->data_ptr);
}

static int
MHKTidal_set_tidal_resource(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_MhkTidal_MHKTidal_tidal_resource_mset, self->data_ptr);
}

static PyObject *
MHKTidal_get_tidal_resource_model_choice(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_tidal_resource_model_choice_nget, self->data_ptr);
}

static int
MHKTidal_set_tidal_resource_model_choice(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_tidal_resource_model_choice_nset, self->data_ptr);
}

static PyObject *
MHKTidal_get_tidal_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MhkTidal_MHKTidal_tidal_velocity_aget, self->data_ptr);
}

static int
MHKTidal_set_tidal_velocity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_MhkTidal_MHKTidal_tidal_velocity_aset, self->data_ptr);
}

static PyObject *
MHKTidal_get_total_operating_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_MHKTidal_total_operating_cost_nget, self->data_ptr);
}

static int
MHKTidal_set_total_operating_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_MhkTidal_MHKTidal_total_operating_cost_nset, self->data_ptr);
}

static PyGetSetDef MHKTidal_getset[] = {
{"balance_of_system_cost_total", (getter)MHKTidal_get_balance_of_system_cost_total,(setter)MHKTidal_set_balance_of_system_cost_total,
	PyDoc_STR("*float*: BOS costs [$]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"device_costs_total", (getter)MHKTidal_get_device_costs_total,(setter)MHKTidal_set_device_costs_total,
	PyDoc_STR("*float*: Device costs [$]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"financial_cost_total", (getter)MHKTidal_get_financial_cost_total,(setter)MHKTidal_set_financial_cost_total,
	PyDoc_STR("*float*: Financial costs [$]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"fixed_charge_rate", (getter)MHKTidal_get_fixed_charge_rate,(setter)MHKTidal_set_fixed_charge_rate,
	PyDoc_STR("*float*: FCR from LCOE Cost page\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"loss_additional", (getter)MHKTidal_get_loss_additional,(setter)MHKTidal_set_loss_additional,
	PyDoc_STR("*float*: Additional losses [%]\n\n**Required:**\nTrue"),
 	NULL},
{"loss_array_spacing", (getter)MHKTidal_get_loss_array_spacing,(setter)MHKTidal_set_loss_array_spacing,
	PyDoc_STR("*float*: Array spacing loss [%]\n\n**Required:**\nTrue"),
 	NULL},
{"loss_downtime", (getter)MHKTidal_get_loss_downtime,(setter)MHKTidal_set_loss_downtime,
	PyDoc_STR("*float*: Array/WEC downtime loss [%]\n\n**Required:**\nTrue"),
 	NULL},
{"loss_resource_overprediction", (getter)MHKTidal_get_loss_resource_overprediction,(setter)MHKTidal_set_loss_resource_overprediction,
	PyDoc_STR("*float*: Resource overprediction loss [%]\n\n**Required:**\nTrue"),
 	NULL},
{"loss_transmission", (getter)MHKTidal_get_loss_transmission,(setter)MHKTidal_set_loss_transmission,
	PyDoc_STR("*float*: Transmission losses [%]\n\n**Required:**\nTrue"),
 	NULL},
{"number_devices", (getter)MHKTidal_get_number_devices,(setter)MHKTidal_set_number_devices,
	PyDoc_STR("*float*: Number of tidal devices in the system\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults.\n\nThe value of the following variables depends on ``number_devices``:\n\n\t - system_capacity\n\n\nThe value of ``number_devices`` depends on the following variables:\n\n\t - tidal_power_curve\n\t - tidal_resource\n"),
 	NULL},
{"system_capacity", (getter)MHKTidal_get_system_capacity,(setter)MHKTidal_set_system_capacity,
	PyDoc_STR("*float*: System Nameplate Capacity [kW]\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults.\n\nThe value of ``system_capacity`` depends on the following variables:\n\n\t - number_devices\n\t - tidal_power_curve\n\t - tidal_resource\n"),
 	NULL},
{"tidal_power_curve", (getter)MHKTidal_get_tidal_power_curve,(setter)MHKTidal_set_tidal_power_curve,
	PyDoc_STR("*sequence[sequence]*: Power curve of tidal energy device as function of stream speeds [kW]\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``tidal_power_curve``:\n\n\t - number_devices\n\t - system_capacity\n\n\nThe value of ``tidal_power_curve`` depends on the following variables:\n\n\t - tidal_resource\n"),
 	NULL},
{"tidal_resource", (getter)MHKTidal_get_tidal_resource,(setter)MHKTidal_set_tidal_resource,
	PyDoc_STR("*sequence[sequence]*: Frequency distribution of resource as a function of stream speeds\n\n**Required:**\nTrue\n\nThe value of the following variables depends on ``tidal_resource``:\n\n\t - number_devices\n\t - system_capacity\n\t - tidal_power_curve\n"),
 	NULL},
{"tidal_resource_model_choice", (getter)MHKTidal_get_tidal_resource_model_choice,(setter)MHKTidal_set_tidal_resource_model_choice,
	PyDoc_STR("*float*: Resource distribution or time series tidal resource data [0/1]\n\n**Constraints:**\nINTEGER\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tidal_velocity", (getter)MHKTidal_get_tidal_velocity,(setter)MHKTidal_set_tidal_velocity,
	PyDoc_STR("*sequence*: Tidal velocity [m/s]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"total_operating_cost", (getter)MHKTidal_get_total_operating_cost,(setter)MHKTidal_set_total_operating_cost,
	PyDoc_STR("*float*: O&M costs [$]\n\n**Required:**\nFalse. Automatically set to 1 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject MHKTidal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkTidal.MHKTidal",             /*tp_name*/
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
		MHKTidal_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		MHKTidal_getset,          /*tp_getset*/
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
Outputs_new(SAM_MhkTidal data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "MhkTidal", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "MhkTidal", "Outputs")){
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
Outputs_get_annual_cumulative_energy_distribution(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MhkTidal_Outputs_annual_cumulative_energy_distribution_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy_distribution(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MhkTidal_Outputs_annual_energy_distribution_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_device_average_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_device_average_power_nget, self->data_ptr);
}

static PyObject *
Outputs_get_device_rated_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_device_rated_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_MhkTidal_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tidal_power_end_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_tidal_power_end_velocity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tidal_power_start_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_tidal_power_start_velocity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tidal_resource_end_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_tidal_resource_end_velocity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tidal_resource_start_velocity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_tidal_resource_start_velocity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_bos_cost_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_bos_cost_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_bos_cost_lcoe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_bos_cost_lcoe_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_bos_cost_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_bos_cost_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_capital_cost_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_capital_cost_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_capital_cost_lcoe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_capital_cost_lcoe_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_capital_cost_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_capital_cost_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_device_cost_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_device_cost_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_device_cost_lcoe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_device_cost_lcoe_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_device_cost_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_device_cost_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_financial_cost_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_financial_cost_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_financial_cost_lcoe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_financial_cost_lcoe_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_financial_cost_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_financial_cost_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_om_cost_kwh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_om_cost_kwh_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_om_cost_lcoe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_om_cost_lcoe_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_operations_cost_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_MhkTidal_Outputs_total_operations_cost_per_kw_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_cumulative_energy_distribution", (getter)Outputs_get_annual_cumulative_energy_distribution,(setter)0,
	PyDoc_STR("*sequence*: Cumulative annual energy production of array as function of speed [kWh]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual energy production of array [kWh]"),
 	NULL},
{"annual_energy_distribution", (getter)Outputs_get_annual_energy_distribution,(setter)0,
	PyDoc_STR("*sequence*: Annual energy production of array as function of speed [kWh]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"device_average_power", (getter)Outputs_get_device_average_power,(setter)0,
	PyDoc_STR("*float*: Average power production of a single device [kW]"),
 	NULL},
{"device_rated_capacity", (getter)Outputs_get_device_rated_capacity,(setter)0,
	PyDoc_STR("*float*: Rated capacity of device [kW]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"tidal_power_end_velocity", (getter)Outputs_get_tidal_power_end_velocity,(setter)0,
	PyDoc_STR("*float*: Last tidal velocity where power curve is greater than 0  [m/s]"),
 	NULL},
{"tidal_power_start_velocity", (getter)Outputs_get_tidal_power_start_velocity,(setter)0,
	PyDoc_STR("*float*: First tidal velocity where power curve is greater than 0  [m/s]"),
 	NULL},
{"tidal_resource_end_velocity", (getter)Outputs_get_tidal_resource_end_velocity,(setter)0,
	PyDoc_STR("*float*: Last tidal velocity where probability distribution is greater than 0  [m/s]"),
 	NULL},
{"tidal_resource_start_velocity", (getter)Outputs_get_tidal_resource_start_velocity,(setter)0,
	PyDoc_STR("*float*: First tidal velocity where probability distribution is greater than 0  [m/s]"),
 	NULL},
{"total_bos_cost_kwh", (getter)Outputs_get_total_bos_cost_kwh,(setter)0,
	PyDoc_STR("*float*: Balance of system costs per unit annual energy [$/kWh]"),
 	NULL},
{"total_bos_cost_lcoe", (getter)Outputs_get_total_bos_cost_lcoe,(setter)0,
	PyDoc_STR("*float*: BOS cost [%]"),
 	NULL},
{"total_bos_cost_per_kw", (getter)Outputs_get_total_bos_cost_per_kw,(setter)0,
	PyDoc_STR("*float*: Balance of Systems cost per kW [$/kW]"),
 	NULL},
{"total_capital_cost_kwh", (getter)Outputs_get_total_capital_cost_kwh,(setter)0,
	PyDoc_STR("*float*: Capital costs per unit annual energy [$/kWh]"),
 	NULL},
{"total_capital_cost_lcoe", (getter)Outputs_get_total_capital_cost_lcoe,(setter)0,
	PyDoc_STR("*float*: Capital cost as percentage of overall LCOE [%]"),
 	NULL},
{"total_capital_cost_per_kw", (getter)Outputs_get_total_capital_cost_per_kw,(setter)0,
	PyDoc_STR("*float*: Capital cost per kW [$/kW]"),
 	NULL},
{"total_device_cost_kwh", (getter)Outputs_get_total_device_cost_kwh,(setter)0,
	PyDoc_STR("*float*: Device costs per unit annual energy [$/kWh]"),
 	NULL},
{"total_device_cost_lcoe", (getter)Outputs_get_total_device_cost_lcoe,(setter)0,
	PyDoc_STR("*float*: Device cost [%]"),
 	NULL},
{"total_device_cost_per_kw", (getter)Outputs_get_total_device_cost_per_kw,(setter)0,
	PyDoc_STR("*float*: Device cost per kW [$/kW]"),
 	NULL},
{"total_financial_cost_kwh", (getter)Outputs_get_total_financial_cost_kwh,(setter)0,
	PyDoc_STR("*float*: Financial costs per unit annual energy [$/kWh]"),
 	NULL},
{"total_financial_cost_lcoe", (getter)Outputs_get_total_financial_cost_lcoe,(setter)0,
	PyDoc_STR("*float*: Financial cost [%]"),
 	NULL},
{"total_financial_cost_per_kw", (getter)Outputs_get_total_financial_cost_per_kw,(setter)0,
	PyDoc_STR("*float*: Financial cost per kW [$/kW]"),
 	NULL},
{"total_om_cost_kwh", (getter)Outputs_get_total_om_cost_kwh,(setter)0,
	PyDoc_STR("*float*: O&M costs per unit annual energy [$/kWh]"),
 	NULL},
{"total_om_cost_lcoe", (getter)Outputs_get_total_om_cost_lcoe,(setter)0,
	PyDoc_STR("*float*: O&M cost (annual) [%]"),
 	NULL},
{"total_operations_cost_per_kw", (getter)Outputs_get_total_operations_cost_per_kw,(setter)0,
	PyDoc_STR("*float*: O&M cost per kW [$/kW]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkTidal.Outputs",             /*tp_name*/
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
 * MhkTidal
 */

static PyTypeObject MhkTidal_Type;

static CmodObject *
newMhkTidalObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &MhkTidal_Type);

	PySAM_TECH_ATTR()

	PyObject* MHKTidal_obj = MHKTidal_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "MHKTidal", MHKTidal_obj);
	Py_DECREF(MHKTidal_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* MhkTidal methods */

static void
MhkTidal_dealloc(CmodObject *self)
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
MhkTidal_get_data_ptr(CmodObject *self, PyObject *args)
{
	PyObject* ptr = PyLong_FromVoidPtr((void*)self->data_ptr);
	return ptr;
}


static PyObject *
MhkTidal_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_MhkTidal_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
MhkTidal_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MhkTidal"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MhkTidal_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "MhkTidal"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
MhkTidal_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
MhkTidal_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
MhkTidal_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef MhkTidal_methods[] = {
		{"execute",           (PyCFunction)MhkTidal_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)MhkTidal_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'MHKTidal': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)MhkTidal_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'MHKTidal': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)MhkTidal_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)MhkTidal_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)MhkTidal_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{"get_data_ptr",           (PyCFunction)MhkTidal_get_data_ptr,  METH_VARARGS,
				PyDoc_STR("get_data_ptr() -> Pointer\n Get ssc_data_t pointer")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
MhkTidal_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
MhkTidal_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject MhkTidal_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"MhkTidal",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)MhkTidal_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)MhkTidal_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)MhkTidal_getattro, /*tp_getattro*/
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
		MhkTidal_methods,      /*tp_methods*/
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


/* Function of no arguments returning new MhkTidal object */

static PyObject *
MhkTidal_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newMhkTidalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkTidal_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkTidalObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
MhkTidal_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newMhkTidalObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MhkTidal", def) < 0) {
		MhkTidal_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
MhkTidal_from_existing(PyObject *self, PyObject *args)
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

	rv = newMhkTidalObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "MhkTidal", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef MhkTidalModule_methods[] = {
		{"new",             MhkTidal_new,         METH_VARARGS,
				PyDoc_STR("new() -> MhkTidal")},
		{"default",             MhkTidal_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> MhkTidal\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n		- *\"MEtidalLCOECalculator\"*\n\n		- *\"MEtidalNone\"*\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             MhkTidal_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> MhkTidal\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   MhkTidal_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> MhkTidal\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Tidal marine hydrokinetic system");


static int
MhkTidalModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	MhkTidal_Type.tp_dict = PyDict_New();
	if (!MhkTidal_Type.tp_dict) { goto fail; }

	/// Add the MHKTidal type object to MhkTidal_Type
	if (PyType_Ready(&MHKTidal_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkTidal_Type.tp_dict,
				"MHKTidal",
				(PyObject*)&MHKTidal_Type);
	Py_DECREF(&MHKTidal_Type);

	/// Add the Outputs type object to MhkTidal_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(MhkTidal_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the MhkTidal type object to the module
	if (PyType_Ready(&MhkTidal_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"MhkTidal",
				(PyObject*)&MhkTidal_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot MhkTidalModule_slots[] = {
		{Py_mod_exec, MhkTidalModule_exec},
		{0, NULL},
};

static struct PyModuleDef MhkTidalModule = {
		PyModuleDef_HEAD_INIT,
		"MhkTidal",
		module_doc,
		0,
		MhkTidalModule_methods,
		MhkTidalModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_MhkTidal(void)
{
	return PyModuleDef_Init(&MhkTidalModule);
}