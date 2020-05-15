#include <Python.h>

#include <SAM_CbMsptSystemCosts.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Heliostat Group
 */ 

static PyTypeObject Heliostat_Type;

static PyObject *
Heliostat_new(SAM_CbMsptSystemCosts data_ptr)
{
	PyObject* new_obj = Heliostat_Type.tp_alloc(&Heliostat_Type,0);

	VarGroupObject* Heliostat_obj = (VarGroupObject*)new_obj;

	Heliostat_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Heliostat methods */

static PyObject *
Heliostat_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbMsptSystemCosts", "Heliostat")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Heliostat_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Heliostat_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Heliostat_methods[] = {
		{"assign",            (PyCFunction)Heliostat_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Heliostat_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Heliostat_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Heliostat_get_A_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Heliostat_A_sf_nget, self->data_ptr);
}

static int
Heliostat_set_A_sf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_Heliostat_A_sf_nset, self->data_ptr);
}

static PyGetSetDef Heliostat_getset[] = {
{"A_sf", (getter)Heliostat_get_A_sf,(setter)Heliostat_set_A_sf,
	PyDoc_STR("*float*: Total reflective solar field area [m2]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Heliostat_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts.Heliostat",             /*tp_name*/
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
		Heliostat_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Heliostat_getset,          /*tp_getset*/
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
SystemCosts_new(SAM_CbMsptSystemCosts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbMsptSystemCosts", "SystemCosts")){
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
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_bop_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_bop_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_bop_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_contingency_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_contingency_rate_nget, self->data_ptr);
}

static int
SystemCosts_set_contingency_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_contingency_rate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_fixed_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_fixed_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_per_acre_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_per_acre_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_per_watt_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_per_watt_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_epc_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_percent_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_epc_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_epc_percent_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_fixed_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_fixed_sf_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_fixed_sf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_fixed_sf_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_fixed_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_fixed_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_per_acre_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_per_acre_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_per_watt_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_per_watt_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_plm_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_percent_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_plm_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_plm_percent_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_power_block_per_kwe(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_power_block_per_kwe_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_power_block_per_kwe(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_power_block_per_kwe_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_csp_pt_cost_total_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_total_land_area_nget, self->data_ptr);
}

static int
SystemCosts_set_csp_pt_cost_total_land_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_csp_pt_cost_total_land_area_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_fossil_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_fossil_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_fossil_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_fossil_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_heliostat_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_heliostat_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_heliostat_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_heliostat_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_rec_cost_exp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_rec_cost_exp_nget, self->data_ptr);
}

static int
SystemCosts_set_rec_cost_exp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_rec_cost_exp_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_rec_ref_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_rec_ref_area_nget, self->data_ptr);
}

static int
SystemCosts_set_rec_ref_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_rec_ref_area_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_rec_ref_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_rec_ref_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_rec_ref_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_rec_ref_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_sales_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_sales_tax_frac_nget, self->data_ptr);
}

static int
SystemCosts_set_sales_tax_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_sales_tax_frac_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_sales_tax_rate_nget, self->data_ptr);
}

static int
SystemCosts_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_sales_tax_rate_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_site_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_site_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_site_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_site_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tes_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_tes_spec_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_tes_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_tes_spec_cost_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tower_exp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_tower_exp_nget, self->data_ptr);
}

static int
SystemCosts_set_tower_exp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_tower_exp_nset, self->data_ptr);
}

static PyObject *
SystemCosts_get_tower_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemCosts_tower_fixed_cost_nget, self->data_ptr);
}

static int
SystemCosts_set_tower_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemCosts_tower_fixed_cost_nset, self->data_ptr);
}

static PyGetSetDef SystemCosts_getset[] = {
{"bop_spec_cost", (getter)SystemCosts_get_bop_spec_cost,(setter)SystemCosts_set_bop_spec_cost,
	PyDoc_STR("*float*: BOP specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"contingency_rate", (getter)SystemCosts_get_contingency_rate,(setter)SystemCosts_set_contingency_rate,
	PyDoc_STR("*float*: Contingency for cost overrun [%]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_fixed", (getter)SystemCosts_get_csp_pt_cost_epc_fixed,(setter)SystemCosts_set_csp_pt_cost_epc_fixed,
	PyDoc_STR("*float*: EPC fixed [$]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_per_acre", (getter)SystemCosts_get_csp_pt_cost_epc_per_acre,(setter)SystemCosts_set_csp_pt_cost_epc_per_acre,
	PyDoc_STR("*float*: EPC cost per acre [$/acre]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_per_watt", (getter)SystemCosts_get_csp_pt_cost_epc_per_watt,(setter)SystemCosts_set_csp_pt_cost_epc_per_watt,
	PyDoc_STR("*float*: EPC cost per watt [$/W]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_percent", (getter)SystemCosts_get_csp_pt_cost_epc_percent,(setter)SystemCosts_set_csp_pt_cost_epc_percent,
	PyDoc_STR("*float*: EPC cost percent of direct [%]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_fixed_sf", (getter)SystemCosts_get_csp_pt_cost_fixed_sf,(setter)SystemCosts_set_csp_pt_cost_fixed_sf,
	PyDoc_STR("*float*: Heliostat field cost fixed [$]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_fixed", (getter)SystemCosts_get_csp_pt_cost_plm_fixed,(setter)SystemCosts_set_csp_pt_cost_plm_fixed,
	PyDoc_STR("*float*: PLM fixed [$]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_per_acre", (getter)SystemCosts_get_csp_pt_cost_plm_per_acre,(setter)SystemCosts_set_csp_pt_cost_plm_per_acre,
	PyDoc_STR("*float*: PLM cost per acre [$/acre]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_per_watt", (getter)SystemCosts_get_csp_pt_cost_plm_per_watt,(setter)SystemCosts_set_csp_pt_cost_plm_per_watt,
	PyDoc_STR("*float*: PLM cost per watt [$/W]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_percent", (getter)SystemCosts_get_csp_pt_cost_plm_percent,(setter)SystemCosts_set_csp_pt_cost_plm_percent,
	PyDoc_STR("*float*: PLM cost percent of direct [%]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_power_block_per_kwe", (getter)SystemCosts_get_csp_pt_cost_power_block_per_kwe,(setter)SystemCosts_set_csp_pt_cost_power_block_per_kwe,
	PyDoc_STR("*float*: Power cycle specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_total_land_area", (getter)SystemCosts_get_csp_pt_cost_total_land_area,(setter)SystemCosts_set_csp_pt_cost_total_land_area,
	PyDoc_STR("*float*: Total land area [acre]\n\n*Required*: True"),
 	NULL},
{"fossil_spec_cost", (getter)SystemCosts_get_fossil_spec_cost,(setter)SystemCosts_set_fossil_spec_cost,
	PyDoc_STR("*float*: Fossil system specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"heliostat_spec_cost", (getter)SystemCosts_get_heliostat_spec_cost,(setter)SystemCosts_set_heliostat_spec_cost,
	PyDoc_STR("*float*: Heliostat field cost [$/m2]\n\n*Required*: True"),
 	NULL},
{"rec_cost_exp", (getter)SystemCosts_get_rec_cost_exp,(setter)SystemCosts_set_rec_cost_exp,
	PyDoc_STR("*float*: Receiver cost scaling exponent\n\n*Required*: True"),
 	NULL},
{"rec_ref_area", (getter)SystemCosts_get_rec_ref_area,(setter)SystemCosts_set_rec_ref_area,
	PyDoc_STR("*float*: Receiver reference area for cost scale\n\n*Required*: True"),
 	NULL},
{"rec_ref_cost", (getter)SystemCosts_get_rec_ref_cost,(setter)SystemCosts_set_rec_ref_cost,
	PyDoc_STR("*float*: Receiver reference cost [$]\n\n*Required*: True"),
 	NULL},
{"sales_tax_frac", (getter)SystemCosts_get_sales_tax_frac,(setter)SystemCosts_set_sales_tax_frac,
	PyDoc_STR("*float*: Percent of cost to which sales tax applies [%]\n\n*Required*: True"),
 	NULL},
{"sales_tax_rate", (getter)SystemCosts_get_sales_tax_rate,(setter)SystemCosts_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales tax rate [%]\n\n*Required*: True"),
 	NULL},
{"site_spec_cost", (getter)SystemCosts_get_site_spec_cost,(setter)SystemCosts_set_site_spec_cost,
	PyDoc_STR("*float*: Site improvement cost [$/m2]\n\n*Required*: True"),
 	NULL},
{"tes_spec_cost", (getter)SystemCosts_get_tes_spec_cost,(setter)SystemCosts_set_tes_spec_cost,
	PyDoc_STR("*float*: Thermal energy storage cost [$/kWht]\n\n*Required*: True"),
 	NULL},
{"tower_exp", (getter)SystemCosts_get_tower_exp,(setter)SystemCosts_set_tower_exp,
	PyDoc_STR("*float*: Tower cost scaling exponent\n\n*Required*: True"),
 	NULL},
{"tower_fixed_cost", (getter)SystemCosts_get_tower_fixed_cost,(setter)SystemCosts_set_tower_fixed_cost,
	PyDoc_STR("*float*: Tower fixed cost [$]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts.SystemCosts",             /*tp_name*/
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
 * Receiver Group
 */ 

static PyTypeObject Receiver_Type;

static PyObject *
Receiver_new(SAM_CbMsptSystemCosts data_ptr)
{
	PyObject* new_obj = Receiver_Type.tp_alloc(&Receiver_Type,0);

	VarGroupObject* Receiver_obj = (VarGroupObject*)new_obj;

	Receiver_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Receiver methods */

static PyObject *
Receiver_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbMsptSystemCosts", "Receiver")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Receiver_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Receiver_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Receiver_methods[] = {
		{"assign",            (PyCFunction)Receiver_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Receiver_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Receiver_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Receiver_get_H_rec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Receiver_H_rec_nget, self->data_ptr);
}

static int
Receiver_set_H_rec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_Receiver_H_rec_nset, self->data_ptr);
}

static PyObject *
Receiver_get_csp_pt_cost_receiver_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Receiver_csp_pt_cost_receiver_area_nget, self->data_ptr);
}

static int
Receiver_set_csp_pt_cost_receiver_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_Receiver_csp_pt_cost_receiver_area_nset, self->data_ptr);
}

static PyObject *
Receiver_get_h_tower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Receiver_h_tower_nget, self->data_ptr);
}

static int
Receiver_set_h_tower(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_Receiver_h_tower_nset, self->data_ptr);
}

static PyObject *
Receiver_get_helio_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Receiver_helio_height_nget, self->data_ptr);
}

static int
Receiver_set_helio_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_Receiver_helio_height_nset, self->data_ptr);
}

static PyGetSetDef Receiver_getset[] = {
{"H_rec", (getter)Receiver_get_H_rec,(setter)Receiver_set_H_rec,
	PyDoc_STR("*float*: The height of the receiver [m]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_receiver_area", (getter)Receiver_get_csp_pt_cost_receiver_area,(setter)Receiver_set_csp_pt_cost_receiver_area,
	PyDoc_STR("*float*: Receiver area [m2]\n\n*Required*: True"),
 	NULL},
{"h_tower", (getter)Receiver_get_h_tower,(setter)Receiver_set_h_tower,
	PyDoc_STR("*float*: Tower height [m]\n\n*Required*: True"),
 	NULL},
{"helio_height", (getter)Receiver_get_helio_height,(setter)Receiver_set_helio_height,
	PyDoc_STR("*float*: Heliostat height [m]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Receiver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts.Receiver",             /*tp_name*/
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
		Receiver_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Receiver_getset,          /*tp_getset*/
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
 * TES Group
 */ 

static PyTypeObject TES_Type;

static PyObject *
TES_new(SAM_CbMsptSystemCosts data_ptr)
{
	PyObject* new_obj = TES_Type.tp_alloc(&TES_Type,0);

	VarGroupObject* TES_obj = (VarGroupObject*)new_obj;

	TES_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TES methods */

static PyObject *
TES_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbMsptSystemCosts", "TES")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TES_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TES_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TES_methods[] = {
		{"assign",            (PyCFunction)TES_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``TES_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TES_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TES_get_csp_pt_cost_storage_mwht(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_TES_csp_pt_cost_storage_mwht_nget, self->data_ptr);
}

static int
TES_set_csp_pt_cost_storage_mwht(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_TES_csp_pt_cost_storage_mwht_nset, self->data_ptr);
}

static PyGetSetDef TES_getset[] = {
{"csp_pt_cost_storage_mwht", (getter)TES_get_csp_pt_cost_storage_mwht,(setter)TES_set_csp_pt_cost_storage_mwht,
	PyDoc_STR("*float*: Storage capacity [MWt-hr]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TES_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts.TES",             /*tp_name*/
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
		TES_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TES_getset,          /*tp_getset*/
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
SystemDesign_new(SAM_CbMsptSystemCosts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbMsptSystemCosts", "SystemDesign")){
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
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemDesign_P_ref_nget, self->data_ptr);
}

static int
SystemDesign_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemDesign_P_ref_nset, self->data_ptr);
}

static PyObject *
SystemDesign_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_SystemDesign_system_capacity_nget, self->data_ptr);
}

static int
SystemDesign_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbMsptSystemCosts_SystemDesign_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef SystemDesign_getset[] = {
{"P_ref", (getter)SystemDesign_get_P_ref,(setter)SystemDesign_set_P_ref,
	PyDoc_STR("*float*: Reference output electric power at design condition [MWe]\n\n*Required*: True"),
 	NULL},
{"system_capacity", (getter)SystemDesign_get_system_capacity,(setter)SystemDesign_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [MWe]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SystemDesign_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts.SystemDesign",             /*tp_name*/
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
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_CbMsptSystemCosts data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbMsptSystemCosts", "Outputs")){
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
Outputs_get_csp_pt_cost_bop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_bop_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_contingency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_contingency_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_epc_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_epc_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_fossil(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_fossil_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_heliostats(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_heliostats_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_installed_per_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_installed_per_capacity_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_plm_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_plm_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_power_block(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_power_block_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_receiver(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_receiver_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_sales_tax_total(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_sales_tax_total_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_site_improvements(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_site_improvements_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_storage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_storage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_csp_pt_cost_tower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_csp_pt_cost_tower_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_direct_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_total_direct_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_indirect_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_total_indirect_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_total_installed_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_ui_direct_subtotal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbMsptSystemCosts_Outputs_ui_direct_subtotal_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"csp_pt_cost_bop", (getter)Outputs_get_csp_pt_cost_bop,(setter)0,
	PyDoc_STR("*float*: BOP cost [$]"),
 	NULL},
{"csp_pt_cost_contingency", (getter)Outputs_get_csp_pt_cost_contingency,(setter)0,
	PyDoc_STR("*float*: Contingency cost [$]"),
 	NULL},
{"csp_pt_cost_epc_total", (getter)Outputs_get_csp_pt_cost_epc_total,(setter)0,
	PyDoc_STR("*float*: EPC and owner cost [$]"),
 	NULL},
{"csp_pt_cost_fossil", (getter)Outputs_get_csp_pt_cost_fossil,(setter)0,
	PyDoc_STR("*float*: Fossil backup cost [$]"),
 	NULL},
{"csp_pt_cost_heliostats", (getter)Outputs_get_csp_pt_cost_heliostats,(setter)0,
	PyDoc_STR("*float*: Heliostat cost [$]"),
 	NULL},
{"csp_pt_cost_installed_per_capacity", (getter)Outputs_get_csp_pt_cost_installed_per_capacity,(setter)0,
	PyDoc_STR("*float*: Estimated installed cost per cap [$]"),
 	NULL},
{"csp_pt_cost_plm_total", (getter)Outputs_get_csp_pt_cost_plm_total,(setter)0,
	PyDoc_STR("*float*: Total land cost [$]"),
 	NULL},
{"csp_pt_cost_power_block", (getter)Outputs_get_csp_pt_cost_power_block,(setter)0,
	PyDoc_STR("*float*: Power cycle cost [$]"),
 	NULL},
{"csp_pt_cost_receiver", (getter)Outputs_get_csp_pt_cost_receiver,(setter)0,
	PyDoc_STR("*float*: Receiver cost [$]"),
 	NULL},
{"csp_pt_cost_sales_tax_total", (getter)Outputs_get_csp_pt_cost_sales_tax_total,(setter)0,
	PyDoc_STR("*float*: Sales tax cost [$]"),
 	NULL},
{"csp_pt_cost_site_improvements", (getter)Outputs_get_csp_pt_cost_site_improvements,(setter)0,
	PyDoc_STR("*float*: Site improvement cost [$]"),
 	NULL},
{"csp_pt_cost_storage", (getter)Outputs_get_csp_pt_cost_storage,(setter)0,
	PyDoc_STR("*float*: TES cost [$]"),
 	NULL},
{"csp_pt_cost_tower", (getter)Outputs_get_csp_pt_cost_tower,(setter)0,
	PyDoc_STR("*float*: Tower cost [$]"),
 	NULL},
{"total_direct_cost", (getter)Outputs_get_total_direct_cost,(setter)0,
	PyDoc_STR("*float*: Total direct cost [$]"),
 	NULL},
{"total_indirect_cost", (getter)Outputs_get_total_indirect_cost,(setter)0,
	PyDoc_STR("*float*: Total indirect cost [$]"),
 	NULL},
{"total_installed_cost", (getter)Outputs_get_total_installed_cost,(setter)0,
	PyDoc_STR("*float*: Total installed cost [$]"),
 	NULL},
{"ui_direct_subtotal", (getter)Outputs_get_ui_direct_subtotal,(setter)0,
	PyDoc_STR("*float*: Direct capital precontingency cost [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts.Outputs",             /*tp_name*/
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
 * CbMsptSystemCosts
 */

static PyTypeObject CbMsptSystemCosts_Type;

static CmodObject *
newCbMsptSystemCostsObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &CbMsptSystemCosts_Type);

	PySAM_TECH_ATTR()

	PyObject* Heliostat_obj = Heliostat_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Heliostat", Heliostat_obj);
	Py_DECREF(Heliostat_obj);

	PyObject* SystemCosts_obj = SystemCosts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemCosts", SystemCosts_obj);
	Py_DECREF(SystemCosts_obj);

	PyObject* Receiver_obj = Receiver_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Receiver", Receiver_obj);
	Py_DECREF(Receiver_obj);

	PyObject* TES_obj = TES_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TES", TES_obj);
	Py_DECREF(TES_obj);

	PyObject* SystemDesign_obj = SystemDesign_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SystemDesign", SystemDesign_obj);
	Py_DECREF(SystemDesign_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* CbMsptSystemCosts methods */

static void
CbMsptSystemCosts_dealloc(CmodObject *self)
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
CbMsptSystemCosts_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_CbMsptSystemCosts_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CbMsptSystemCosts_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CbMsptSystemCosts"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CbMsptSystemCosts_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
CbMsptSystemCosts_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef CbMsptSystemCosts_methods[] = {
		{"execute",            (PyCFunction)CbMsptSystemCosts_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)CbMsptSystemCosts_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'heliostat': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)CbMsptSystemCosts_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)CbMsptSystemCosts_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CbMsptSystemCosts_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
CbMsptSystemCosts_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject CbMsptSystemCosts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbMsptSystemCosts",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)CbMsptSystemCosts_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)CbMsptSystemCosts_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)CbMsptSystemCosts_getattro, /*tp_getattro*/
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
		CbMsptSystemCosts_methods,      /*tp_methods*/
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


/* Function of no arguments returning new CbMsptSystemCosts object */

static PyObject *
CbMsptSystemCosts_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newCbMsptSystemCostsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CbMsptSystemCosts_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCbMsptSystemCostsObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CbMsptSystemCosts_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCbMsptSystemCostsObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CbMsptSystemCosts", def);

	return (PyObject *)rv;
}

static PyObject *
CbMsptSystemCosts_from_existing(PyObject *self, PyObject *args)
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

	rv = newCbMsptSystemCostsObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CbMsptSystemCosts", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef CbMsptSystemCostsModule_methods[] = {
		{"new",             CbMsptSystemCosts_new,         METH_VARARGS,
				PyDoc_STR("new() -> CbMsptSystemCosts")},
		{"default",             CbMsptSystemCosts_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> CbMsptSystemCosts\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             CbMsptSystemCosts_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> CbMsptSystemCosts\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   CbMsptSystemCosts_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> CbMsptSystemCosts\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CbMsptSystemCosts");


static int
CbMsptSystemCostsModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	CbMsptSystemCosts_Type.tp_dict = PyDict_New();
	if (!CbMsptSystemCosts_Type.tp_dict) { goto fail; }

	/// Add the Heliostat type object to CbMsptSystemCosts_Type
	if (PyType_Ready(&Heliostat_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbMsptSystemCosts_Type.tp_dict,
				"Heliostat",
				(PyObject*)&Heliostat_Type);
	Py_DECREF(&Heliostat_Type);

	/// Add the SystemCosts type object to CbMsptSystemCosts_Type
	if (PyType_Ready(&SystemCosts_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbMsptSystemCosts_Type.tp_dict,
				"SystemCosts",
				(PyObject*)&SystemCosts_Type);
	Py_DECREF(&SystemCosts_Type);

	/// Add the Receiver type object to CbMsptSystemCosts_Type
	if (PyType_Ready(&Receiver_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbMsptSystemCosts_Type.tp_dict,
				"Receiver",
				(PyObject*)&Receiver_Type);
	Py_DECREF(&Receiver_Type);

	/// Add the TES type object to CbMsptSystemCosts_Type
	if (PyType_Ready(&TES_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbMsptSystemCosts_Type.tp_dict,
				"TES",
				(PyObject*)&TES_Type);
	Py_DECREF(&TES_Type);

	/// Add the SystemDesign type object to CbMsptSystemCosts_Type
	if (PyType_Ready(&SystemDesign_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbMsptSystemCosts_Type.tp_dict,
				"SystemDesign",
				(PyObject*)&SystemDesign_Type);
	Py_DECREF(&SystemDesign_Type);

	/// Add the Outputs type object to CbMsptSystemCosts_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbMsptSystemCosts_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the CbMsptSystemCosts type object to the module
	if (PyType_Ready(&CbMsptSystemCosts_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"CbMsptSystemCosts",
				(PyObject*)&CbMsptSystemCosts_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot CbMsptSystemCostsModule_slots[] = {
		{Py_mod_exec, CbMsptSystemCostsModule_exec},
		{0, NULL},
};

static struct PyModuleDef CbMsptSystemCostsModule = {
		PyModuleDef_HEAD_INIT,
		"CbMsptSystemCosts",
		module_doc,
		0,
		CbMsptSystemCostsModule_methods,
		CbMsptSystemCostsModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_CbMsptSystemCosts(void)
{
	return PyModuleDef_Init(&CbMsptSystemCostsModule);
}