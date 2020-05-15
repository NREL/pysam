#include <Python.h>

#include <SAM_Windbos.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * WindBos Group
 */ 

static PyTypeObject WindBos_Type;

static PyObject *
WindBos_new(SAM_Windbos data_ptr)
{
	PyObject* new_obj = WindBos_Type.tp_alloc(&WindBos_Type,0);

	VarGroupObject* WindBos_obj = (VarGroupObject*)new_obj;

	WindBos_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* WindBos methods */

static PyObject *
WindBos_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windbos", "WindBos")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
WindBos_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &WindBos_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef WindBos_methods[] = {
		{"assign",            (PyCFunction)WindBos_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``WindBos_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)WindBos_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindBos_get_access_road_entrances(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_access_road_entrances_nget, self->data_ptr);
}

static int
WindBos_set_access_road_entrances(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_access_road_entrances_nset, self->data_ptr);
}

static PyObject *
WindBos_get_construction_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_construction_time_nget, self->data_ptr);
}

static int
WindBos_set_construction_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_construction_time_nset, self->data_ptr);
}

static PyObject *
WindBos_get_contingency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_contingency_nget, self->data_ptr);
}

static int
WindBos_set_contingency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_contingency_nset, self->data_ptr);
}

static PyObject *
WindBos_get_crane_breakdowns(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_crane_breakdowns_nget, self->data_ptr);
}

static int
WindBos_set_crane_breakdowns(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_crane_breakdowns_nset, self->data_ptr);
}

static PyObject *
WindBos_get_delivery_assist_required(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_delivery_assist_required_nget, self->data_ptr);
}

static int
WindBos_set_delivery_assist_required(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_delivery_assist_required_nset, self->data_ptr);
}

static PyObject *
WindBos_get_development_fee(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_development_fee_nget, self->data_ptr);
}

static int
WindBos_set_development_fee(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_development_fee_nset, self->data_ptr);
}

static PyObject *
WindBos_get_distance_to_interconnect(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_distance_to_interconnect_nget, self->data_ptr);
}

static int
WindBos_set_distance_to_interconnect(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_distance_to_interconnect_nset, self->data_ptr);
}

static PyObject *
WindBos_get_hub_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_hub_height_nget, self->data_ptr);
}

static int
WindBos_set_hub_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_hub_height_nset, self->data_ptr);
}

static PyObject *
WindBos_get_interconnect_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_interconnect_voltage_nget, self->data_ptr);
}

static int
WindBos_set_interconnect_voltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_interconnect_voltage_nset, self->data_ptr);
}

static PyObject *
WindBos_get_machine_rating(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_machine_rating_nget, self->data_ptr);
}

static int
WindBos_set_machine_rating(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_machine_rating_nset, self->data_ptr);
}

static PyObject *
WindBos_get_mv_overhead_collector(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_mv_overhead_collector_nget, self->data_ptr);
}

static int
WindBos_set_mv_overhead_collector(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_mv_overhead_collector_nset, self->data_ptr);
}

static PyObject *
WindBos_get_mv_thermal_backfill(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_mv_thermal_backfill_nget, self->data_ptr);
}

static int
WindBos_set_mv_thermal_backfill(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_mv_thermal_backfill_nset, self->data_ptr);
}

static PyObject *
WindBos_get_new_switchyard_required(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_new_switchyard_required_nget, self->data_ptr);
}

static int
WindBos_set_new_switchyard_required(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_new_switchyard_required_nset, self->data_ptr);
}

static PyObject *
WindBos_get_number_of_turbines(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_number_of_turbines_nget, self->data_ptr);
}

static int
WindBos_set_number_of_turbines(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_number_of_turbines_nset, self->data_ptr);
}

static PyObject *
WindBos_get_om_building_size(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_om_building_size_nget, self->data_ptr);
}

static int
WindBos_set_om_building_size(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_om_building_size_nset, self->data_ptr);
}

static PyObject *
WindBos_get_overhead(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_overhead_nget, self->data_ptr);
}

static int
WindBos_set_overhead(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_overhead_nset, self->data_ptr);
}

static PyObject *
WindBos_get_pad_mount_transformer_required(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_pad_mount_transformer_required_nget, self->data_ptr);
}

static int
WindBos_set_pad_mount_transformer_required(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_pad_mount_transformer_required_nset, self->data_ptr);
}

static PyObject *
WindBos_get_performance_bond(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_performance_bond_nget, self->data_ptr);
}

static int
WindBos_set_performance_bond(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_performance_bond_nset, self->data_ptr);
}

static PyObject *
WindBos_get_profit_margin(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_profit_margin_nget, self->data_ptr);
}

static int
WindBos_set_profit_margin(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_profit_margin_nset, self->data_ptr);
}

static PyObject *
WindBos_get_quantity_permanent_met_towers(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_quantity_permanent_met_towers_nget, self->data_ptr);
}

static int
WindBos_set_quantity_permanent_met_towers(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_quantity_permanent_met_towers_nset, self->data_ptr);
}

static PyObject *
WindBos_get_quantity_test_met_towers(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_quantity_test_met_towers_nget, self->data_ptr);
}

static int
WindBos_set_quantity_test_met_towers(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_quantity_test_met_towers_nset, self->data_ptr);
}

static PyObject *
WindBos_get_rock_trenching_required(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_rock_trenching_required_nget, self->data_ptr);
}

static int
WindBos_set_rock_trenching_required(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_rock_trenching_required_nset, self->data_ptr);
}

static PyObject *
WindBos_get_rotor_diameter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_rotor_diameter_nget, self->data_ptr);
}

static int
WindBos_set_rotor_diameter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_rotor_diameter_nset, self->data_ptr);
}

static PyObject *
WindBos_get_sales_and_use_tax(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_sales_and_use_tax_nget, self->data_ptr);
}

static int
WindBos_set_sales_and_use_tax(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_sales_and_use_tax_nset, self->data_ptr);
}

static PyObject *
WindBos_get_site_terrain(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_site_terrain_nget, self->data_ptr);
}

static int
WindBos_set_site_terrain(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_site_terrain_nset, self->data_ptr);
}

static PyObject *
WindBos_get_soil_condition(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_soil_condition_nget, self->data_ptr);
}

static int
WindBos_set_soil_condition(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_soil_condition_nset, self->data_ptr);
}

static PyObject *
WindBos_get_tower_top_mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_tower_top_mass_nget, self->data_ptr);
}

static int
WindBos_set_tower_top_mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_tower_top_mass_nset, self->data_ptr);
}

static PyObject *
WindBos_get_turbine_capital_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_turbine_capital_cost_nget, self->data_ptr);
}

static int
WindBos_set_turbine_capital_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_turbine_capital_cost_nset, self->data_ptr);
}

static PyObject *
WindBos_get_turbine_layout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_turbine_layout_nget, self->data_ptr);
}

static int
WindBos_set_turbine_layout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_turbine_layout_nset, self->data_ptr);
}

static PyObject *
WindBos_get_turbine_transportation(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_turbine_transportation_nget, self->data_ptr);
}

static int
WindBos_set_turbine_transportation(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_turbine_transportation_nset, self->data_ptr);
}

static PyObject *
WindBos_get_warranty_management(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_warranty_management_nget, self->data_ptr);
}

static int
WindBos_set_warranty_management(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_warranty_management_nset, self->data_ptr);
}

static PyObject *
WindBos_get_weather_delay_days(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_WindBos_weather_delay_days_nget, self->data_ptr);
}

static int
WindBos_set_weather_delay_days(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Windbos_WindBos_weather_delay_days_nset, self->data_ptr);
}

static PyGetSetDef WindBos_getset[] = {
{"access_road_entrances", (getter)WindBos_get_access_road_entrances,(setter)WindBos_set_access_road_entrances,
	PyDoc_STR("*float*: Access road entrances\n\n*Required*: True"),
 	NULL},
{"construction_time", (getter)WindBos_get_construction_time,(setter)WindBos_set_construction_time,
	PyDoc_STR("*float*: Construction Time [months]\n\n*Required*: True"),
 	NULL},
{"contingency", (getter)WindBos_get_contingency,(setter)WindBos_set_contingency,
	PyDoc_STR("*float*: Contingency [%]\n\n*Required*: True"),
 	NULL},
{"crane_breakdowns", (getter)WindBos_get_crane_breakdowns,(setter)WindBos_set_crane_breakdowns,
	PyDoc_STR("*float*: Crane breakdowns\n\n*Required*: True"),
 	NULL},
{"delivery_assist_required", (getter)WindBos_get_delivery_assist_required,(setter)WindBos_set_delivery_assist_required,
	PyDoc_STR("*float*: Delivery Assist Required [y/n]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"development_fee", (getter)WindBos_get_development_fee,(setter)WindBos_set_development_fee,
	PyDoc_STR("*float*: Development Fee [$M]\n\n*Required*: True"),
 	NULL},
{"distance_to_interconnect", (getter)WindBos_get_distance_to_interconnect,(setter)WindBos_set_distance_to_interconnect,
	PyDoc_STR("*float*: Distance to Interconnect [miles]\n\n*Required*: True"),
 	NULL},
{"hub_height", (getter)WindBos_get_hub_height,(setter)WindBos_set_hub_height,
	PyDoc_STR("*float*: Hub Height [m]\n\n*Required*: True"),
 	NULL},
{"interconnect_voltage", (getter)WindBos_get_interconnect_voltage,(setter)WindBos_set_interconnect_voltage,
	PyDoc_STR("*float*: Interconnect Voltage [kV]\n\n*Required*: True"),
 	NULL},
{"machine_rating", (getter)WindBos_get_machine_rating,(setter)WindBos_set_machine_rating,
	PyDoc_STR("*float*: Machine Rating [kW]\n\n*Required*: True"),
 	NULL},
{"mv_overhead_collector", (getter)WindBos_get_mv_overhead_collector,(setter)WindBos_set_mv_overhead_collector,
	PyDoc_STR("*float*: MV overhead collector [mi]\n\n*Required*: True"),
 	NULL},
{"mv_thermal_backfill", (getter)WindBos_get_mv_thermal_backfill,(setter)WindBos_set_mv_thermal_backfill,
	PyDoc_STR("*float*: MV thermal backfill [mi]\n\n*Required*: True"),
 	NULL},
{"new_switchyard_required", (getter)WindBos_get_new_switchyard_required,(setter)WindBos_set_new_switchyard_required,
	PyDoc_STR("*float*: New Switchyard Required [y/n]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"number_of_turbines", (getter)WindBos_get_number_of_turbines,(setter)WindBos_set_number_of_turbines,
	PyDoc_STR("*float*: Number of Turbines\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"om_building_size", (getter)WindBos_get_om_building_size,(setter)WindBos_set_om_building_size,
	PyDoc_STR("*float*: O&M Building Size [ft^2]\n\n*Required*: True"),
 	NULL},
{"overhead", (getter)WindBos_get_overhead,(setter)WindBos_set_overhead,
	PyDoc_STR("*float*: Overhead [%]\n\n*Required*: True"),
 	NULL},
{"pad_mount_transformer_required", (getter)WindBos_get_pad_mount_transformer_required,(setter)WindBos_set_pad_mount_transformer_required,
	PyDoc_STR("*float*: Pad mount Transformer required [y/n]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"performance_bond", (getter)WindBos_get_performance_bond,(setter)WindBos_set_performance_bond,
	PyDoc_STR("*float*: Performance bond [%]\n\n*Required*: True"),
 	NULL},
{"profit_margin", (getter)WindBos_get_profit_margin,(setter)WindBos_set_profit_margin,
	PyDoc_STR("*float*: Profit Margin [%]\n\n*Required*: True"),
 	NULL},
{"quantity_permanent_met_towers", (getter)WindBos_get_quantity_permanent_met_towers,(setter)WindBos_set_quantity_permanent_met_towers,
	PyDoc_STR("*float*: Quantity of Permanent Meteorological Towers for Testing\n\n*Required*: True"),
 	NULL},
{"quantity_test_met_towers", (getter)WindBos_get_quantity_test_met_towers,(setter)WindBos_set_quantity_test_met_towers,
	PyDoc_STR("*float*: Quantity of Temporary Meteorological Towers for Testing\n\n*Required*: True"),
 	NULL},
{"rock_trenching_required", (getter)WindBos_get_rock_trenching_required,(setter)WindBos_set_rock_trenching_required,
	PyDoc_STR("*float*: Rock trenching required [%]\n\n*Required*: True"),
 	NULL},
{"rotor_diameter", (getter)WindBos_get_rotor_diameter,(setter)WindBos_set_rotor_diameter,
	PyDoc_STR("*float*: Rotor Diameter [m]\n\n*Required*: True"),
 	NULL},
{"sales_and_use_tax", (getter)WindBos_get_sales_and_use_tax,(setter)WindBos_set_sales_and_use_tax,
	PyDoc_STR("*float*: Sales and Use Tax [%]\n\n*Required*: True"),
 	NULL},
{"site_terrain", (getter)WindBos_get_site_terrain,(setter)WindBos_set_site_terrain,
	PyDoc_STR("*float*: Site Terrain\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"soil_condition", (getter)WindBos_get_soil_condition,(setter)WindBos_set_soil_condition,
	PyDoc_STR("*float*: Soil Condition\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"tower_top_mass", (getter)WindBos_get_tower_top_mass,(setter)WindBos_set_tower_top_mass,
	PyDoc_STR("*float*: Tower Top Mass [Tonnes]\n\n*Required*: True"),
 	NULL},
{"turbine_capital_cost", (getter)WindBos_get_turbine_capital_cost,(setter)WindBos_set_turbine_capital_cost,
	PyDoc_STR("*float*: Turbine Capital Cost [$/kW]\n\n*Required*: True"),
 	NULL},
{"turbine_layout", (getter)WindBos_get_turbine_layout,(setter)WindBos_set_turbine_layout,
	PyDoc_STR("*float*: Turbine Layout\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"turbine_transportation", (getter)WindBos_get_turbine_transportation,(setter)WindBos_set_turbine_transportation,
	PyDoc_STR("*float*: Turbine Transportation [mi]\n\n*Required*: True"),
 	NULL},
{"warranty_management", (getter)WindBos_get_warranty_management,(setter)WindBos_set_warranty_management,
	PyDoc_STR("*float*: Warranty management [%]\n\n*Required*: True"),
 	NULL},
{"weather_delay_days", (getter)WindBos_get_weather_delay_days,(setter)WindBos_set_weather_delay_days,
	PyDoc_STR("*float*: Wind / Weather delay days\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject WindBos_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windbos.WindBos",             /*tp_name*/
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
		WindBos_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		WindBos_getset,          /*tp_getset*/
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
Outputs_new(SAM_Windbos data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Windbos", "Outputs")){
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
Outputs_get_access_roads_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_access_roads_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_building_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_building_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_development_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_development_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_electrical_installation_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_electrical_installation_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_electrical_materials_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_electrical_materials_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_engineering_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_engineering_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_erection_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_erection_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_foundation_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_foundation_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_insurance_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_insurance_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_markup_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_markup_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_power_performance_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_power_performance_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_project_mgmt_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_project_mgmt_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_project_total_budgeted_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_project_total_budgeted_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_site_compound_security_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_site_compound_security_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_substation_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_substation_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_transmission_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_transmission_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_transportation_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Windbos_Outputs_transportation_cost_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"access_roads_cost", (getter)Outputs_get_access_roads_cost,(setter)0,
	PyDoc_STR("*float*: Access Roads Cost [$s]"),
 	NULL},
{"building_cost", (getter)Outputs_get_building_cost,(setter)0,
	PyDoc_STR("*float*: Building Cost [$s]"),
 	NULL},
{"development_cost", (getter)Outputs_get_development_cost,(setter)0,
	PyDoc_STR("*float*: Development Cost [$s]"),
 	NULL},
{"electrical_installation_cost", (getter)Outputs_get_electrical_installation_cost,(setter)0,
	PyDoc_STR("*float*: MV Electrical Installation Cost [$s]"),
 	NULL},
{"electrical_materials_cost", (getter)Outputs_get_electrical_materials_cost,(setter)0,
	PyDoc_STR("*float*: MV Electrical Materials Cost [$s]"),
 	NULL},
{"engineering_cost", (getter)Outputs_get_engineering_cost,(setter)0,
	PyDoc_STR("*float*: Engineering Cost [$s]"),
 	NULL},
{"erection_cost", (getter)Outputs_get_erection_cost,(setter)0,
	PyDoc_STR("*float*: Turbine Erection Cost [$s]"),
 	NULL},
{"foundation_cost", (getter)Outputs_get_foundation_cost,(setter)0,
	PyDoc_STR("*float*: Foundation Cost [$s]"),
 	NULL},
{"insurance_cost", (getter)Outputs_get_insurance_cost,(setter)0,
	PyDoc_STR("*float*: Insurance Cost [$s]"),
 	NULL},
{"markup_cost", (getter)Outputs_get_markup_cost,(setter)0,
	PyDoc_STR("*float*: Markup Cost [$s]"),
 	NULL},
{"power_performance_cost", (getter)Outputs_get_power_performance_cost,(setter)0,
	PyDoc_STR("*float*: Power Performance Cost [$s]"),
 	NULL},
{"project_mgmt_cost", (getter)Outputs_get_project_mgmt_cost,(setter)0,
	PyDoc_STR("*float*: Project Management Cost [$s]"),
 	NULL},
{"project_total_budgeted_cost", (getter)Outputs_get_project_total_budgeted_cost,(setter)0,
	PyDoc_STR("*float*: Project Total Budgeted Cost [$s]"),
 	NULL},
{"site_compound_security_cost", (getter)Outputs_get_site_compound_security_cost,(setter)0,
	PyDoc_STR("*float*: Site Compound & Security Cost [$s]"),
 	NULL},
{"substation_cost", (getter)Outputs_get_substation_cost,(setter)0,
	PyDoc_STR("*float*: Substation Cost [$s]"),
 	NULL},
{"transmission_cost", (getter)Outputs_get_transmission_cost,(setter)0,
	PyDoc_STR("*float*: Transmission Cost [$s]"),
 	NULL},
{"transportation_cost", (getter)Outputs_get_transportation_cost,(setter)0,
	PyDoc_STR("*float*: Transportation Cost [$s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windbos.Outputs",             /*tp_name*/
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
 * Windbos
 */

static PyTypeObject Windbos_Type;

static CmodObject *
newWindbosObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Windbos_Type);

	PySAM_TECH_ATTR()

	PyObject* WindBos_obj = WindBos_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "WindBos", WindBos_obj);
	Py_DECREF(WindBos_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Windbos methods */

static void
Windbos_dealloc(CmodObject *self)
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
Windbos_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Windbos_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Windbos_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Windbos"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Windbos_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Windbos_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Windbos_methods[] = {
		{"execute",            (PyCFunction)Windbos_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Windbos_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'wind_bos': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Windbos_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Windbos_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Windbos_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Windbos_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Windbos_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Windbos",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Windbos_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Windbos_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Windbos_getattro, /*tp_getattro*/
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
		Windbos_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Windbos object */

static PyObject *
Windbos_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWindbosObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Windbos_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindbosObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Windbos_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindbosObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Windbos", def);

	return (PyObject *)rv;
}

static PyObject *
Windbos_from_existing(PyObject *self, PyObject *args)
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

	rv = newWindbosObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Windbos", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WindbosModule_methods[] = {
		{"new",             Windbos_new,         METH_VARARGS,
				PyDoc_STR("new() -> Windbos")},
		{"default",             Windbos_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Windbos\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Windbos_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Windbos\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Windbos_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Windbos\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Windbos");


static int
WindbosModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Windbos_Type.tp_dict = PyDict_New();
	if (!Windbos_Type.tp_dict) { goto fail; }

	/// Add the WindBos type object to Windbos_Type
	if (PyType_Ready(&WindBos_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windbos_Type.tp_dict,
				"WindBos",
				(PyObject*)&WindBos_Type);
	Py_DECREF(&WindBos_Type);

	/// Add the Outputs type object to Windbos_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Windbos_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Windbos type object to the module
	if (PyType_Ready(&Windbos_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Windbos",
				(PyObject*)&Windbos_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WindbosModule_slots[] = {
		{Py_mod_exec, WindbosModule_exec},
		{0, NULL},
};

static struct PyModuleDef WindbosModule = {
		PyModuleDef_HEAD_INIT,
		"Windbos",
		module_doc,
		0,
		WindbosModule_methods,
		WindbosModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Windbos(void)
{
	return PyModuleDef_Init(&WindbosModule);
}