#include <Python.h>

#include <SAM_TcsdirectSteam.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_TcsdirectSteam data_ptr)
{
	PyObject* new_obj = Weather_Type.tp_alloc(&Weather_Type,0);

	VarGroupObject* Weather_obj = (VarGroupObject*)new_obj;

	Weather_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Weather methods */

static PyObject *
Weather_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Weather_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Weather_methods[] = {
		{"assign",            (PyCFunction)Weather_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Weather_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_solar_resource_file(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_TcsdirectSteam_Weather_solar_resource_file_sget, self->data_ptr);
}

static int
Weather_set_solar_resource_file(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_TcsdirectSteam_Weather_solar_resource_file_sset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"solar_resource_file", (getter)Weather_get_solar_resource_file,(setter)Weather_set_solar_resource_file,
	PyDoc_STR("*str*: local weather file path\n\n*Constraints*: LOCAL_FILE\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.Weather",             /*tp_name*/
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
		Weather_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Weather_getset,          /*tp_getset*/
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
 * DirectSteamTower Group
 */ 

static PyTypeObject DirectSteamTower_Type;

static PyObject *
DirectSteamTower_new(SAM_TcsdirectSteam data_ptr)
{
	PyObject* new_obj = DirectSteamTower_Type.tp_alloc(&DirectSteamTower_Type,0);

	VarGroupObject* DirectSteamTower_obj = (VarGroupObject*)new_obj;

	DirectSteamTower_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* DirectSteamTower methods */

static PyObject *
DirectSteamTower_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "DirectSteamTower")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
DirectSteamTower_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &DirectSteamTower_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef DirectSteamTower_methods[] = {
		{"assign",            (PyCFunction)DirectSteamTower_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``DirectSteamTower_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)DirectSteamTower_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
DirectSteamTower_get_system_capacity(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DirectSteamTower_system_capacity_nget, self->data_ptr);
}

static int
DirectSteamTower_set_system_capacity(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DirectSteamTower_system_capacity_nset, self->data_ptr);
}

static PyGetSetDef DirectSteamTower_getset[] = {
{"system_capacity", (getter)DirectSteamTower_get_system_capacity,(setter)DirectSteamTower_set_system_capacity,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject DirectSteamTower_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.DirectSteamTower",             /*tp_name*/
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
		DirectSteamTower_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		DirectSteamTower_getset,          /*tp_getset*/
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
 * TouTranslator Group
 */ 

static PyTypeObject TouTranslator_Type;

static PyObject *
TouTranslator_new(SAM_TcsdirectSteam data_ptr)
{
	PyObject* new_obj = TouTranslator_Type.tp_alloc(&TouTranslator_Type,0);

	VarGroupObject* TouTranslator_obj = (VarGroupObject*)new_obj;

	TouTranslator_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* TouTranslator methods */

static PyObject *
TouTranslator_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "TouTranslator")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
TouTranslator_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &TouTranslator_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef TouTranslator_methods[] = {
		{"assign",            (PyCFunction)TouTranslator_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``TouTranslator_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)TouTranslator_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TouTranslator_get_weekday_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_TouTranslator_weekday_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekday_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_TouTranslator_weekday_schedule_mset, self->data_ptr);
}

static PyObject *
TouTranslator_get_weekend_schedule(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_TouTranslator_weekend_schedule_mget, self->data_ptr);
}

static int
TouTranslator_set_weekend_schedule(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_TouTranslator_weekend_schedule_mset, self->data_ptr);
}

static PyGetSetDef TouTranslator_getset[] = {
{"weekday_schedule", (getter)TouTranslator_get_weekday_schedule,(setter)TouTranslator_set_weekday_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 Time of Use Values for week days\n\n*Required*: True"),
 	NULL},
{"weekend_schedule", (getter)TouTranslator_get_weekend_schedule,(setter)TouTranslator_set_weekend_schedule,
	PyDoc_STR("*sequence[sequence]*: 12x24 Time of Use Values for week end days\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject TouTranslator_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.TouTranslator",             /*tp_name*/
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
		TouTranslator_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		TouTranslator_getset,          /*tp_getset*/
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
 * Heliostat Group
 */ 

static PyTypeObject Heliostat_Type;

static PyObject *
Heliostat_new(SAM_TcsdirectSteam data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "Heliostat")){
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
Heliostat_get_N_hel(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_N_hel_nget, self->data_ptr);
}

static int
Heliostat_set_N_hel(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_N_hel_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_bop_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_bop_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_bop_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_bop_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_c_atm_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_c_atm_0_nget, self->data_ptr);
}

static int
Heliostat_set_c_atm_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_c_atm_0_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_c_atm_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_c_atm_1_nget, self->data_ptr);
}

static int
Heliostat_set_c_atm_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_c_atm_1_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_c_atm_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_c_atm_2_nget, self->data_ptr);
}

static int
Heliostat_set_c_atm_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_c_atm_2_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_c_atm_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_c_atm_3_nget, self->data_ptr);
}

static int
Heliostat_set_c_atm_3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_c_atm_3_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_calc_fluxmaps(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_calc_fluxmaps_nget, self->data_ptr);
}

static int
Heliostat_set_calc_fluxmaps(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_calc_fluxmaps_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_cant_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_cant_type_nget, self->data_ptr);
}

static int
Heliostat_set_cant_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_cant_type_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_check_max_flux(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_check_max_flux_nget, self->data_ptr);
}

static int
Heliostat_set_check_max_flux(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_check_max_flux_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_contingency_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_contingency_rate_nget, self->data_ptr);
}

static int
Heliostat_set_contingency_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_contingency_rate_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_cost_sf_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_cost_sf_fixed_nget, self->data_ptr);
}

static int
Heliostat_set_cost_sf_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_cost_sf_fixed_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_epc_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_fixed_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_epc_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_fixed_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_epc_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_per_acre_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_epc_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_per_acre_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_epc_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_per_watt_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_epc_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_per_watt_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_epc_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_percent_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_epc_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_epc_percent_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_plm_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_fixed_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_plm_fixed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_fixed_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_plm_per_acre(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_per_acre_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_plm_per_acre(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_per_acre_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_plm_per_watt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_per_watt_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_plm_per_watt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_per_watt_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_cost_plm_percent(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_percent_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_cost_plm_percent(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_cost_plm_percent_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_sf_fixed_land_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_sf_fixed_land_area_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_sf_fixed_land_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_sf_fixed_land_area_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_csp_pt_sf_land_overhead_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_csp_pt_sf_land_overhead_factor_nget, self->data_ptr);
}

static int
Heliostat_set_csp_pt_sf_land_overhead_factor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_csp_pt_sf_land_overhead_factor_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_delta_flux_hrs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_delta_flux_hrs_nget, self->data_ptr);
}

static int
Heliostat_set_delta_flux_hrs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_delta_flux_hrs_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_dens_mirror(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_dens_mirror_nget, self->data_ptr);
}

static int
Heliostat_set_dens_mirror(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_dens_mirror_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_dni_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_dni_des_nget, self->data_ptr);
}

static int
Heliostat_set_dni_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_dni_des_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_eta_map(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_Heliostat_eta_map_mget, self->data_ptr);
}

static int
Heliostat_set_eta_map(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_Heliostat_eta_map_mset, self->data_ptr);
}

static PyObject *
Heliostat_get_flux_maps(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_Heliostat_flux_maps_mget, self->data_ptr);
}

static int
Heliostat_set_flux_maps(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_Heliostat_flux_maps_mset, self->data_ptr);
}

static PyObject *
Heliostat_get_flux_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_flux_max_nget, self->data_ptr);
}

static int
Heliostat_set_flux_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_flux_max_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_flux_positions(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_Heliostat_flux_positions_mget, self->data_ptr);
}

static int
Heliostat_set_flux_positions(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_Heliostat_flux_positions_mset, self->data_ptr);
}

static PyObject *
Heliostat_get_focus_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_focus_type_nget, self->data_ptr);
}

static int
Heliostat_set_focus_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_focus_type_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_fossil_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_fossil_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_fossil_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_fossil_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_hel_stow_deploy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_hel_stow_deploy_nget, self->data_ptr);
}

static int
Heliostat_set_hel_stow_deploy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_hel_stow_deploy_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_active_fraction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_helio_active_fraction_nget, self->data_ptr);
}

static int
Heliostat_set_helio_active_fraction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_helio_active_fraction_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_aim_points(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_Heliostat_helio_aim_points_mget, self->data_ptr);
}

static int
Heliostat_set_helio_aim_points(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_Heliostat_helio_aim_points_mset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_helio_height_nget, self->data_ptr);
}

static int
Heliostat_set_helio_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_helio_height_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_optical_error(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_helio_optical_error_nget, self->data_ptr);
}

static int
Heliostat_set_helio_optical_error(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_helio_optical_error_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_positions(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_Heliostat_helio_positions_mget, self->data_ptr);
}

static int
Heliostat_set_helio_positions(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_Heliostat_helio_positions_mset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_reflectance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_helio_reflectance_nget, self->data_ptr);
}

static int
Heliostat_set_helio_reflectance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_helio_reflectance_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_helio_width(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_helio_width_nget, self->data_ptr);
}

static int
Heliostat_set_helio_width(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_helio_width_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_heliostat_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_heliostat_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_heliostat_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_heliostat_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_interp_beta(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_interp_beta_nget, self->data_ptr);
}

static int
Heliostat_set_interp_beta(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_interp_beta_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_interp_nug(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_interp_nug_nget, self->data_ptr);
}

static int
Heliostat_set_interp_nug(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_interp_nug_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_is_optimize(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_is_optimize_nget, self->data_ptr);
}

static int
Heliostat_set_is_optimize(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_is_optimize_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_land_bound_list(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Heliostat_land_bound_list_aget, self->data_ptr);
}

static int
Heliostat_set_land_bound_list(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsdirectSteam_Heliostat_land_bound_list_aset, self->data_ptr);
}

static PyObject *
Heliostat_get_land_bound_table(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_TcsdirectSteam_Heliostat_land_bound_table_mget, self->data_ptr);
}

static int
Heliostat_set_land_bound_table(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_TcsdirectSteam_Heliostat_land_bound_table_mset, self->data_ptr);
}

static PyObject *
Heliostat_get_land_bound_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_land_bound_type_nget, self->data_ptr);
}

static int
Heliostat_set_land_bound_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_land_bound_type_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_land_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_land_max_nget, self->data_ptr);
}

static int
Heliostat_set_land_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_land_max_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_land_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_land_min_nget, self->data_ptr);
}

static int
Heliostat_set_land_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_land_min_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_land_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_land_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_land_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_land_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_n_facet_x(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_n_facet_x_nget, self->data_ptr);
}

static int
Heliostat_set_n_facet_x(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_n_facet_x_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_n_facet_y(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_n_facet_y_nget, self->data_ptr);
}

static int
Heliostat_set_n_facet_y(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_n_facet_y_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_n_flux_days(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_n_flux_days_nget, self->data_ptr);
}

static int
Heliostat_set_n_flux_days(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_n_flux_days_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_n_flux_x(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_n_flux_x_nget, self->data_ptr);
}

static int
Heliostat_set_n_flux_x(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_n_flux_x_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_n_flux_y(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_n_flux_y_nget, self->data_ptr);
}

static int
Heliostat_set_n_flux_y(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_n_flux_y_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_opt_algorithm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_opt_algorithm_nget, self->data_ptr);
}

static int
Heliostat_set_opt_algorithm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_opt_algorithm_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_opt_conv_tol(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_opt_conv_tol_nget, self->data_ptr);
}

static int
Heliostat_set_opt_conv_tol(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_opt_conv_tol_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_opt_flux_penalty(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_opt_flux_penalty_nget, self->data_ptr);
}

static int
Heliostat_set_opt_flux_penalty(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_opt_flux_penalty_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_opt_init_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_opt_init_step_nget, self->data_ptr);
}

static int
Heliostat_set_opt_init_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_opt_init_step_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_opt_max_iter(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_opt_max_iter_nget, self->data_ptr);
}

static int
Heliostat_set_opt_max_iter(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_opt_max_iter_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_p_start(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_p_start_nget, self->data_ptr);
}

static int
Heliostat_set_p_start(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_p_start_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_p_track(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_p_track_nget, self->data_ptr);
}

static int
Heliostat_set_p_track(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_p_track_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_plant_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_plant_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_plant_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_plant_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_q_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_q_design_nget, self->data_ptr);
}

static int
Heliostat_set_q_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_q_design_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_absorptance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_absorptance_nget, self->data_ptr);
}

static int
Heliostat_set_rec_absorptance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_absorptance_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_aspect(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_aspect_nget, self->data_ptr);
}

static int
Heliostat_set_rec_aspect(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_aspect_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_cost_exp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_cost_exp_nget, self->data_ptr);
}

static int
Heliostat_set_rec_cost_exp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_cost_exp_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_height_nget, self->data_ptr);
}

static int
Heliostat_set_rec_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_height_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_hl_perm2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_hl_perm2_nget, self->data_ptr);
}

static int
Heliostat_set_rec_hl_perm2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_hl_perm2_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_ref_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_ref_area_nget, self->data_ptr);
}

static int
Heliostat_set_rec_ref_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_ref_area_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_rec_ref_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_rec_ref_cost_nget, self->data_ptr);
}

static int
Heliostat_set_rec_ref_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_rec_ref_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_run_type(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_run_type_nget, self->data_ptr);
}

static int
Heliostat_set_run_type(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_run_type_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_sales_tax_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_sales_tax_frac_nget, self->data_ptr);
}

static int
Heliostat_set_sales_tax_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_sales_tax_frac_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_sales_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_sales_tax_rate_nget, self->data_ptr);
}

static int
Heliostat_set_sales_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_sales_tax_rate_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_site_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_site_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_site_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_site_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_tes_spec_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_tes_spec_cost_nget, self->data_ptr);
}

static int
Heliostat_set_tes_spec_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_tes_spec_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_total_installed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_total_installed_cost_nget, self->data_ptr);
}

static int
Heliostat_set_total_installed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_total_installed_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_tower_exp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_tower_exp_nget, self->data_ptr);
}

static int
Heliostat_set_tower_exp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_tower_exp_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_tower_fixed_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_tower_fixed_cost_nget, self->data_ptr);
}

static int
Heliostat_set_tower_fixed_cost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_tower_fixed_cost_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_v_wind_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_v_wind_max_nget, self->data_ptr);
}

static int
Heliostat_set_v_wind_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_v_wind_max_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_washing_frequency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_washing_frequency_nget, self->data_ptr);
}

static int
Heliostat_set_washing_frequency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_washing_frequency_nset, self->data_ptr);
}

static PyObject *
Heliostat_get_water_usage_per_wash(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Heliostat_water_usage_per_wash_nget, self->data_ptr);
}

static int
Heliostat_set_water_usage_per_wash(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Heliostat_water_usage_per_wash_nset, self->data_ptr);
}

static PyGetSetDef Heliostat_getset[] = {
{"N_hel", (getter)Heliostat_get_N_hel,(setter)Heliostat_set_N_hel,
	PyDoc_STR("*float*: Number of heliostats\n\n*Required*: False"),
 	NULL},
{"bop_spec_cost", (getter)Heliostat_get_bop_spec_cost,(setter)Heliostat_set_bop_spec_cost,
	PyDoc_STR("*float*: BOS specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"c_atm_0", (getter)Heliostat_get_c_atm_0,(setter)Heliostat_set_c_atm_0,
	PyDoc_STR("*float*: Attenuation coefficient 0\n\n*Required*: If not provided, assumed to be 0.006789"),
 	NULL},
{"c_atm_1", (getter)Heliostat_get_c_atm_1,(setter)Heliostat_set_c_atm_1,
	PyDoc_STR("*float*: Attenuation coefficient 1\n\n*Required*: If not provided, assumed to be 0.1046"),
 	NULL},
{"c_atm_2", (getter)Heliostat_get_c_atm_2,(setter)Heliostat_set_c_atm_2,
	PyDoc_STR("*float*: Attenuation coefficient 2\n\n*Required*: If not provided, assumed to be -0.0107"),
 	NULL},
{"c_atm_3", (getter)Heliostat_get_c_atm_3,(setter)Heliostat_set_c_atm_3,
	PyDoc_STR("*float*: Attenuation coefficient 3\n\n*Required*: If not provided, assumed to be 0.002845"),
 	NULL},
{"calc_fluxmaps", (getter)Heliostat_get_calc_fluxmaps,(setter)Heliostat_set_calc_fluxmaps,
	PyDoc_STR("*float*: Include fluxmap calculations\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"cant_type", (getter)Heliostat_get_cant_type,(setter)Heliostat_set_cant_type,
	PyDoc_STR("*float*: Heliostat cant method\n\n*Required*: True"),
 	NULL},
{"check_max_flux", (getter)Heliostat_get_check_max_flux,(setter)Heliostat_set_check_max_flux,
	PyDoc_STR("*float*: Check max flux at design point\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"contingency_rate", (getter)Heliostat_get_contingency_rate,(setter)Heliostat_set_contingency_rate,
	PyDoc_STR("*float*: Contingency for cost overrun [%]\n\n*Required*: True"),
 	NULL},
{"cost_sf_fixed", (getter)Heliostat_get_cost_sf_fixed,(setter)Heliostat_set_cost_sf_fixed,
	PyDoc_STR("*float*: Solar field fixed cost [$]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_fixed", (getter)Heliostat_get_csp_pt_cost_epc_fixed,(setter)Heliostat_set_csp_pt_cost_epc_fixed,
	PyDoc_STR("*float*: EPC fixed [$]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_per_acre", (getter)Heliostat_get_csp_pt_cost_epc_per_acre,(setter)Heliostat_set_csp_pt_cost_epc_per_acre,
	PyDoc_STR("*float*: EPC cost per acre [$/acre]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_per_watt", (getter)Heliostat_get_csp_pt_cost_epc_per_watt,(setter)Heliostat_set_csp_pt_cost_epc_per_watt,
	PyDoc_STR("*float*: EPC cost per watt [$/W]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_epc_percent", (getter)Heliostat_get_csp_pt_cost_epc_percent,(setter)Heliostat_set_csp_pt_cost_epc_percent,
	PyDoc_STR("*float*: EPC cost percent of direct\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_fixed", (getter)Heliostat_get_csp_pt_cost_plm_fixed,(setter)Heliostat_set_csp_pt_cost_plm_fixed,
	PyDoc_STR("*float*: PLM fixed [$]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_per_acre", (getter)Heliostat_get_csp_pt_cost_plm_per_acre,(setter)Heliostat_set_csp_pt_cost_plm_per_acre,
	PyDoc_STR("*float*: PLM cost per acre [$/acre]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_per_watt", (getter)Heliostat_get_csp_pt_cost_plm_per_watt,(setter)Heliostat_set_csp_pt_cost_plm_per_watt,
	PyDoc_STR("*float*: PLM cost per watt [$/W]\n\n*Required*: True"),
 	NULL},
{"csp_pt_cost_plm_percent", (getter)Heliostat_get_csp_pt_cost_plm_percent,(setter)Heliostat_set_csp_pt_cost_plm_percent,
	PyDoc_STR("*float*: PLM cost percent of direct\n\n*Required*: True"),
 	NULL},
{"csp_pt_sf_fixed_land_area", (getter)Heliostat_get_csp_pt_sf_fixed_land_area,(setter)Heliostat_set_csp_pt_sf_fixed_land_area,
	PyDoc_STR("*float*: Fixed land area [acre]\n\n*Required*: True"),
 	NULL},
{"csp_pt_sf_land_overhead_factor", (getter)Heliostat_get_csp_pt_sf_land_overhead_factor,(setter)Heliostat_set_csp_pt_sf_land_overhead_factor,
	PyDoc_STR("*float*: Land overhead factor\n\n*Required*: True"),
 	NULL},
{"delta_flux_hrs", (getter)Heliostat_get_delta_flux_hrs,(setter)Heliostat_set_delta_flux_hrs,
	PyDoc_STR("*float*: Hourly frequency in flux map lookup\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"dens_mirror", (getter)Heliostat_get_dens_mirror,(setter)Heliostat_set_dens_mirror,
	PyDoc_STR("*float*: Ratio of reflective area to profile\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - A_sf\n\t - total_installed_cost\n"),
 	NULL},
{"dni_des", (getter)Heliostat_get_dni_des,(setter)Heliostat_set_dni_des,
	PyDoc_STR("*float*: Design-point DNI [W/m2]\n\n*Required*: True"),
 	NULL},
{"eta_map", (getter)Heliostat_get_eta_map,(setter)Heliostat_set_eta_map,
	PyDoc_STR("*sequence[sequence]*: Field efficiency array\n\n*Required*: False"),
 	NULL},
{"flux_maps", (getter)Heliostat_get_flux_maps,(setter)Heliostat_set_flux_maps,
	PyDoc_STR("*sequence[sequence]*: Flux map intensities\n\n*Required*: False"),
 	NULL},
{"flux_max", (getter)Heliostat_get_flux_max,(setter)Heliostat_set_flux_max,
	PyDoc_STR("*float*: Maximum allowable flux\n\n*Required*: If not provided, assumed to be 1000"),
 	NULL},
{"flux_positions", (getter)Heliostat_get_flux_positions,(setter)Heliostat_set_flux_positions,
	PyDoc_STR("*sequence[sequence]*: Flux map sun positions [deg]\n\n*Required*: False"),
 	NULL},
{"focus_type", (getter)Heliostat_get_focus_type,(setter)Heliostat_set_focus_type,
	PyDoc_STR("*float*: Heliostat focus method\n\n*Required*: True"),
 	NULL},
{"fossil_spec_cost", (getter)Heliostat_get_fossil_spec_cost,(setter)Heliostat_set_fossil_spec_cost,
	PyDoc_STR("*float*: Fossil system specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"hel_stow_deploy", (getter)Heliostat_get_hel_stow_deploy,(setter)Heliostat_set_hel_stow_deploy,
	PyDoc_STR("*float*: Stow/deploy elevation [deg]\n\n*Required*: True"),
 	NULL},
{"helio_active_fraction", (getter)Heliostat_get_helio_active_fraction,(setter)Heliostat_set_helio_active_fraction,
	PyDoc_STR("*float*: Heliostat active frac.\n\n*Required*: True"),
 	NULL},
{"helio_aim_points", (getter)Heliostat_get_helio_aim_points,(setter)Heliostat_set_helio_aim_points,
	PyDoc_STR("*sequence[sequence]*: Heliostat aim point table [m]\n\n*Required*: False"),
 	NULL},
{"helio_height", (getter)Heliostat_get_helio_height,(setter)Heliostat_set_helio_height,
	PyDoc_STR("*float*: Heliostat height [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - A_sf\n\t - total_installed_cost\n"),
 	NULL},
{"helio_optical_error", (getter)Heliostat_get_helio_optical_error,(setter)Heliostat_set_helio_optical_error,
	PyDoc_STR("*float*: Heliostat optical error [rad]\n\n*Required*: True"),
 	NULL},
{"helio_positions", (getter)Heliostat_get_helio_positions,(setter)Heliostat_set_helio_positions,
	PyDoc_STR("*sequence[sequence]*: Heliostat position table [m]\n\n*Required*: True if run_type=1\n\n*Changes to this variable may require updating the values of the following*: \n\t - A_sf\n\t - total_installed_cost\n"),
 	NULL},
{"helio_reflectance", (getter)Heliostat_get_helio_reflectance,(setter)Heliostat_set_helio_reflectance,
	PyDoc_STR("*float*: Heliostat reflectance\n\n*Required*: True"),
 	NULL},
{"helio_width", (getter)Heliostat_get_helio_width,(setter)Heliostat_set_helio_width,
	PyDoc_STR("*float*: Heliostat width [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - A_sf\n\t - total_installed_cost\n"),
 	NULL},
{"heliostat_spec_cost", (getter)Heliostat_get_heliostat_spec_cost,(setter)Heliostat_set_heliostat_spec_cost,
	PyDoc_STR("*float*: Heliostat field cost [$/m2]\n\n*Required*: True"),
 	NULL},
{"interp_beta", (getter)Heliostat_get_interp_beta,(setter)Heliostat_set_interp_beta,
	PyDoc_STR("*float*: Interpolation beta coef.\n\n*Required*: If not provided, assumed to be 1.99"),
 	NULL},
{"interp_nug", (getter)Heliostat_get_interp_nug,(setter)Heliostat_set_interp_nug,
	PyDoc_STR("*float*: Interpolation nugget\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"is_optimize", (getter)Heliostat_get_is_optimize,(setter)Heliostat_set_is_optimize,
	PyDoc_STR("*float*: Do SolarPILOT optimization\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"land_bound_list", (getter)Heliostat_get_land_bound_list,(setter)Heliostat_set_land_bound_list,
	PyDoc_STR("*sequence*: Boundary table listing\n\n*Required*: False"),
 	NULL},
{"land_bound_table", (getter)Heliostat_get_land_bound_table,(setter)Heliostat_set_land_bound_table,
	PyDoc_STR("*sequence[sequence]*: Land boundary table [m]\n\n*Required*: False"),
 	NULL},
{"land_bound_type", (getter)Heliostat_get_land_bound_type,(setter)Heliostat_set_land_bound_type,
	PyDoc_STR("*float*: Land boundary type\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"land_max", (getter)Heliostat_get_land_max,(setter)Heliostat_set_land_max,
	PyDoc_STR("*float*: Land max boundary [-ORm]\n\n*Required*: If not provided, assumed to be 7.5"),
 	NULL},
{"land_min", (getter)Heliostat_get_land_min,(setter)Heliostat_set_land_min,
	PyDoc_STR("*float*: Land min boundary [-ORm]\n\n*Required*: If not provided, assumed to be 0.75"),
 	NULL},
{"land_spec_cost", (getter)Heliostat_get_land_spec_cost,(setter)Heliostat_set_land_spec_cost,
	PyDoc_STR("*float*: Total land area cost [$/acre]\n\n*Required*: True"),
 	NULL},
{"n_facet_x", (getter)Heliostat_get_n_facet_x,(setter)Heliostat_set_n_facet_x,
	PyDoc_STR("*float*: Number of heliostat facets - X\n\n*Required*: True"),
 	NULL},
{"n_facet_y", (getter)Heliostat_get_n_facet_y,(setter)Heliostat_set_n_facet_y,
	PyDoc_STR("*float*: Number of heliostat facets - Y\n\n*Required*: True"),
 	NULL},
{"n_flux_days", (getter)Heliostat_get_n_flux_days,(setter)Heliostat_set_n_flux_days,
	PyDoc_STR("*float*: No. days in flux map lookup\n\n*Required*: If not provided, assumed to be 8"),
 	NULL},
{"n_flux_x", (getter)Heliostat_get_n_flux_x,(setter)Heliostat_set_n_flux_x,
	PyDoc_STR("*float*: Flux map X resolution\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"n_flux_y", (getter)Heliostat_get_n_flux_y,(setter)Heliostat_set_n_flux_y,
	PyDoc_STR("*float*: Flux map Y resolution\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"opt_algorithm", (getter)Heliostat_get_opt_algorithm,(setter)Heliostat_set_opt_algorithm,
	PyDoc_STR("*float*: Optimization algorithm\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"opt_conv_tol", (getter)Heliostat_get_opt_conv_tol,(setter)Heliostat_set_opt_conv_tol,
	PyDoc_STR("*float*: Optimization convergence tol\n\n*Required*: If not provided, assumed to be 0.001"),
 	NULL},
{"opt_flux_penalty", (getter)Heliostat_get_opt_flux_penalty,(setter)Heliostat_set_opt_flux_penalty,
	PyDoc_STR("*float*: Optimization flux overage penalty\n\n*Required*: True"),
 	NULL},
{"opt_init_step", (getter)Heliostat_get_opt_init_step,(setter)Heliostat_set_opt_init_step,
	PyDoc_STR("*float*: Optimization initial step size\n\n*Required*: If not provided, assumed to be 0.05"),
 	NULL},
{"opt_max_iter", (getter)Heliostat_get_opt_max_iter,(setter)Heliostat_set_opt_max_iter,
	PyDoc_STR("*float*: Max. number iteration steps\n\n*Required*: If not provided, assumed to be 200"),
 	NULL},
{"p_start", (getter)Heliostat_get_p_start,(setter)Heliostat_set_p_start,
	PyDoc_STR("*float*: Heliostat startup energy [kWe-hr]\n\n*Required*: True"),
 	NULL},
{"p_track", (getter)Heliostat_get_p_track,(setter)Heliostat_set_p_track,
	PyDoc_STR("*float*: Heliostat tracking energy [kWe]\n\n*Required*: True"),
 	NULL},
{"plant_spec_cost", (getter)Heliostat_get_plant_spec_cost,(setter)Heliostat_set_plant_spec_cost,
	PyDoc_STR("*float*: Power cycle specific cost [$/kWe]\n\n*Required*: True"),
 	NULL},
{"q_design", (getter)Heliostat_get_q_design,(setter)Heliostat_set_q_design,
	PyDoc_STR("*float*: Receiver thermal design power [MW]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - eta_ref\n\t - q_rec_des\n"),
 	NULL},
{"rec_absorptance", (getter)Heliostat_get_rec_absorptance,(setter)Heliostat_set_rec_absorptance,
	PyDoc_STR("*float*: Receiver absorptance\n\n*Required*: True"),
 	NULL},
{"rec_aspect", (getter)Heliostat_get_rec_aspect,(setter)Heliostat_set_rec_aspect,
	PyDoc_STR("*float*: Receiver aspect ratio\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - H_rec\n\t - d_rec\n\t - h_boiler\n\t - h_rh\n\t - h_sh\n"),
 	NULL},
{"rec_cost_exp", (getter)Heliostat_get_rec_cost_exp,(setter)Heliostat_set_rec_cost_exp,
	PyDoc_STR("*float*: Receiver cost scaling exponent\n\n*Required*: True"),
 	NULL},
{"rec_height", (getter)Heliostat_get_rec_height,(setter)Heliostat_set_rec_height,
	PyDoc_STR("*float*: Receiver height [m]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - H_rec\n\t - h_boiler\n\t - h_rh\n\t - h_sh\n"),
 	NULL},
{"rec_hl_perm2", (getter)Heliostat_get_rec_hl_perm2,(setter)Heliostat_set_rec_hl_perm2,
	PyDoc_STR("*float*: Receiver design heatloss [kW/m2]\n\n*Required*: True"),
 	NULL},
{"rec_ref_area", (getter)Heliostat_get_rec_ref_area,(setter)Heliostat_set_rec_ref_area,
	PyDoc_STR("*float*: Receiver reference area for cost scale\n\n*Required*: True"),
 	NULL},
{"rec_ref_cost", (getter)Heliostat_get_rec_ref_cost,(setter)Heliostat_set_rec_ref_cost,
	PyDoc_STR("*float*: Receiver reference cost [$]\n\n*Required*: True"),
 	NULL},
{"run_type", (getter)Heliostat_get_run_type,(setter)Heliostat_set_run_type,
	PyDoc_STR("*float*: Run type [-]\n\n*Required*: True"),
 	NULL},
{"sales_tax_frac", (getter)Heliostat_get_sales_tax_frac,(setter)Heliostat_set_sales_tax_frac,
	PyDoc_STR("*float*: Percent of cost to which sales tax applies [%]\n\n*Required*: True"),
 	NULL},
{"sales_tax_rate", (getter)Heliostat_get_sales_tax_rate,(setter)Heliostat_set_sales_tax_rate,
	PyDoc_STR("*float*: Sales tax rate [%]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - total_installed_cost\n"),
 	NULL},
{"site_spec_cost", (getter)Heliostat_get_site_spec_cost,(setter)Heliostat_set_site_spec_cost,
	PyDoc_STR("*float*: Site improvement cost [$/m2]\n\n*Required*: True"),
 	NULL},
{"tes_spec_cost", (getter)Heliostat_get_tes_spec_cost,(setter)Heliostat_set_tes_spec_cost,
	PyDoc_STR("*float*: Thermal energy storage cost [$/kWht]\n\n*Required*: True"),
 	NULL},
{"total_installed_cost", (getter)Heliostat_get_total_installed_cost,(setter)Heliostat_set_total_installed_cost,
	PyDoc_STR("*float*: Total installed cost [$]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - A_sf\n\t - H_rec\n\t - P_ref\n\t - THT\n\t - d_rec\n\t - dens_mirror\n\t - design_eff\n\t - eta_ref\n\t - h_boiler\n\t - h_rh\n\t - h_sh\n\t - h_tower\n\t - helio_height\n\t - helio_positions\n\t - helio_width\n\t - sales_tax_rate\n"),
 	NULL},
{"tower_exp", (getter)Heliostat_get_tower_exp,(setter)Heliostat_set_tower_exp,
	PyDoc_STR("*float*: Tower cost scaling exponent\n\n*Required*: True"),
 	NULL},
{"tower_fixed_cost", (getter)Heliostat_get_tower_fixed_cost,(setter)Heliostat_set_tower_fixed_cost,
	PyDoc_STR("*float*: Tower fixed cost [$]\n\n*Required*: True"),
 	NULL},
{"v_wind_max", (getter)Heliostat_get_v_wind_max,(setter)Heliostat_set_v_wind_max,
	PyDoc_STR("*float*: Max. wind velocity [m/s]\n\n*Required*: True"),
 	NULL},
{"washing_frequency", (getter)Heliostat_get_washing_frequency,(setter)Heliostat_set_washing_frequency,
	PyDoc_STR("*float*: Mirror washing frequency\n\n*Required*: True"),
 	NULL},
{"water_usage_per_wash", (getter)Heliostat_get_water_usage_per_wash,(setter)Heliostat_set_water_usage_per_wash,
	PyDoc_STR("*float*: Water usage per wash [L/m2_aper]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Heliostat_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.Heliostat",             /*tp_name*/
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
 * Receiver Group
 */ 

static PyTypeObject Receiver_Type;

static PyObject *
Receiver_new(SAM_TcsdirectSteam data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "Receiver")){
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
	return PySAM_double_getter(SAM_TcsdirectSteam_Receiver_H_rec_nget, self->data_ptr);
}

static int
Receiver_set_H_rec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Receiver_H_rec_nset, self->data_ptr);
}

static PyObject *
Receiver_get_THT(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Receiver_THT_nget, self->data_ptr);
}

static int
Receiver_set_THT(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Receiver_THT_nset, self->data_ptr);
}

static PyGetSetDef Receiver_getset[] = {
{"H_rec", (getter)Receiver_get_H_rec,(setter)Receiver_set_H_rec,
	PyDoc_STR("*float*: The height of the receiver [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - rec_aspect\n\t - rec_height\n\t - total_installed_cost\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - h_boiler\n\t - h_rh\n\t - h_sh\n"),
 	NULL},
{"THT", (getter)Receiver_get_THT,(setter)Receiver_set_THT,
	PyDoc_STR("*float*: The height of the tower (hel. pivot to rec equator) [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - Piping_length\n\t - total_installed_cost\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - h_tower\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Receiver_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.Receiver",             /*tp_name*/
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
 * DsgController Group
 */ 

static PyTypeObject DsgController_Type;

static PyObject *
DsgController_new(SAM_TcsdirectSteam data_ptr)
{
	PyObject* new_obj = DsgController_Type.tp_alloc(&DsgController_Type,0);

	VarGroupObject* DsgController_obj = (VarGroupObject*)new_obj;

	DsgController_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* DsgController methods */

static PyObject *
DsgController_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "DsgController")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
DsgController_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &DsgController_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef DsgController_methods[] = {
		{"assign",            (PyCFunction)DsgController_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``DsgController_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)DsgController_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
DsgController_get_A_sf(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_A_sf_nget, self->data_ptr);
}

static int
DsgController_set_A_sf(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_A_sf_nset, self->data_ptr);
}

static PyObject *
DsgController_get_P_b_in_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_P_b_in_init_nget, self->data_ptr);
}

static int
DsgController_set_P_b_in_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_P_b_in_init_nset, self->data_ptr);
}

static PyObject *
DsgController_get_P_cond_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_P_cond_init_nget, self->data_ptr);
}

static int
DsgController_set_P_cond_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_P_cond_init_nset, self->data_ptr);
}

static PyObject *
DsgController_get_P_hp_in_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_P_hp_in_des_nget, self->data_ptr);
}

static int
DsgController_set_P_hp_in_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_P_hp_in_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_P_hp_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_P_hp_out_nget, self->data_ptr);
}

static int
DsgController_set_P_hp_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_P_hp_out_nset, self->data_ptr);
}

static PyObject *
DsgController_get_P_hp_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_P_hp_out_des_nget, self->data_ptr);
}

static int
DsgController_set_P_hp_out_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_P_hp_out_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_ITD_des_nget, self->data_ptr);
}

static int
DsgController_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_amb_des_nget, self->data_ptr);
}

static int
DsgController_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_amb_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_approach(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_approach_nget, self->data_ptr);
}

static int
DsgController_set_T_approach(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_approach_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_fw_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_fw_init_nget, self->data_ptr);
}

static int
DsgController_set_T_fw_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_fw_init_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_hp_out(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_hp_out_nget, self->data_ptr);
}

static int
DsgController_set_T_hp_out(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_hp_out_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_rh_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_rh_out_des_nget, self->data_ptr);
}

static int
DsgController_set_T_rh_out_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_rh_out_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_rh_target(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_rh_target_nget, self->data_ptr);
}

static int
DsgController_set_T_rh_target(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_rh_target_nset, self->data_ptr);
}

static PyObject *
DsgController_get_T_sh_out_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_T_sh_out_des_nget, self->data_ptr);
}

static int
DsgController_set_T_sh_out_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_T_sh_out_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_ct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_ct_nget, self->data_ptr);
}

static int
DsgController_set_ct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_ct_nset, self->data_ptr);
}

static PyObject *
DsgController_get_cycle_max_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_cycle_max_frac_nget, self->data_ptr);
}

static int
DsgController_set_cycle_max_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_cycle_max_frac_nset, self->data_ptr);
}

static PyObject *
DsgController_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_dT_cw_ref_nget, self->data_ptr);
}

static int
DsgController_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
DsgController_get_d_rec(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_d_rec_nget, self->data_ptr);
}

static int
DsgController_set_d_rec(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_d_rec_nset, self->data_ptr);
}

static PyObject *
DsgController_get_d_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_d_rh_nget, self->data_ptr);
}

static int
DsgController_set_d_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_d_rh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_d_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_d_sh_nget, self->data_ptr);
}

static int
DsgController_set_d_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_d_sh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_d_t_boiler(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_d_t_boiler_nget, self->data_ptr);
}

static int
DsgController_set_d_t_boiler(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_d_t_boiler_nset, self->data_ptr);
}

static PyObject *
DsgController_get_eta_rec_pump(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_eta_rec_pump_nget, self->data_ptr);
}

static int
DsgController_set_eta_rec_pump(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_eta_rec_pump_nset, self->data_ptr);
}

static PyObject *
DsgController_get_f_mdot_rh_init(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_f_mdot_rh_init_nget, self->data_ptr);
}

static int
DsgController_set_f_mdot_rh_init(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_f_mdot_rh_init_nset, self->data_ptr);
}

static PyObject *
DsgController_get_f_mdotrh_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_f_mdotrh_des_nget, self->data_ptr);
}

static int
DsgController_set_f_mdotrh_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_f_mdotrh_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_f_pb_cutoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_f_pb_cutoff_nget, self->data_ptr);
}

static int
DsgController_set_f_pb_cutoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_f_pb_cutoff_nset, self->data_ptr);
}

static PyObject *
DsgController_get_f_pb_sb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_f_pb_sb_nget, self->data_ptr);
}

static int
DsgController_set_f_pb_sb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_f_pb_sb_nset, self->data_ptr);
}

static PyObject *
DsgController_get_f_rec_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_f_rec_min_nget, self->data_ptr);
}

static int
DsgController_set_f_rec_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_f_rec_min_nset, self->data_ptr);
}

static PyObject *
DsgController_get_ffrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_DsgController_ffrac_aget, self->data_ptr);
}

static int
DsgController_set_ffrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsdirectSteam_DsgController_ffrac_aset, self->data_ptr);
}

static PyObject *
DsgController_get_flowtype(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_flowtype_nget, self->data_ptr);
}

static int
DsgController_set_flowtype(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_flowtype_nset, self->data_ptr);
}

static PyObject *
DsgController_get_fossil_mode(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_fossil_mode_nget, self->data_ptr);
}

static int
DsgController_set_fossil_mode(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_fossil_mode_nset, self->data_ptr);
}

static PyObject *
DsgController_get_h_boiler(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_h_boiler_nget, self->data_ptr);
}

static int
DsgController_set_h_boiler(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_h_boiler_nset, self->data_ptr);
}

static PyObject *
DsgController_get_h_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_h_rh_nget, self->data_ptr);
}

static int
DsgController_set_h_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_h_rh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_h_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_h_sh_nget, self->data_ptr);
}

static int
DsgController_set_h_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_h_sh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_h_tower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_h_tower_nget, self->data_ptr);
}

static int
DsgController_set_h_tower(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_h_tower_nset, self->data_ptr);
}

static PyObject *
DsgController_get_hl_ffact(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_hl_ffact_nget, self->data_ptr);
}

static int
DsgController_set_hl_ffact(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_hl_ffact_nset, self->data_ptr);
}

static PyObject *
DsgController_get_lhv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_lhv_eff_nget, self->data_ptr);
}

static int
DsgController_set_lhv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_lhv_eff_nset, self->data_ptr);
}

static PyObject *
DsgController_get_mat_boiler(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_mat_boiler_nget, self->data_ptr);
}

static int
DsgController_set_mat_boiler(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_mat_boiler_nset, self->data_ptr);
}

static PyObject *
DsgController_get_mat_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_mat_rh_nget, self->data_ptr);
}

static int
DsgController_set_mat_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_mat_rh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_mat_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_mat_sh_nget, self->data_ptr);
}

static int
DsgController_set_mat_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_mat_sh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_n_panels(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_n_panels_nget, self->data_ptr);
}

static int
DsgController_set_n_panels(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_n_panels_nset, self->data_ptr);
}

static PyObject *
DsgController_get_p_cycle_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_p_cycle_design_nget, self->data_ptr);
}

static int
DsgController_set_p_cycle_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_p_cycle_design_nset, self->data_ptr);
}

static PyObject *
DsgController_get_q_aux_max(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_q_aux_max_nget, self->data_ptr);
}

static int
DsgController_set_q_aux_max(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_q_aux_max_nset, self->data_ptr);
}

static PyObject *
DsgController_get_q_pb_design(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_q_pb_design_nget, self->data_ptr);
}

static int
DsgController_set_q_pb_design(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_q_pb_design_nset, self->data_ptr);
}

static PyObject *
DsgController_get_q_rec_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_q_rec_des_nget, self->data_ptr);
}

static int
DsgController_set_q_rec_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_q_rec_des_nset, self->data_ptr);
}

static PyObject *
DsgController_get_rec_absorptance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_rec_absorptance_nget, self->data_ptr);
}

static int
DsgController_set_rec_absorptance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_rec_absorptance_nset, self->data_ptr);
}

static PyObject *
DsgController_get_rec_emis(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_rec_emis_nget, self->data_ptr);
}

static int
DsgController_set_rec_emis(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_rec_emis_nset, self->data_ptr);
}

static PyObject *
DsgController_get_rec_qf_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_rec_qf_delay_nget, self->data_ptr);
}

static int
DsgController_set_rec_qf_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_rec_qf_delay_nset, self->data_ptr);
}

static PyObject *
DsgController_get_rec_su_delay(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_rec_su_delay_nget, self->data_ptr);
}

static int
DsgController_set_rec_su_delay(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_rec_su_delay_nset, self->data_ptr);
}

static PyObject *
DsgController_get_t_standby_ini(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_t_standby_ini_nget, self->data_ptr);
}

static int
DsgController_set_t_standby_ini(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_t_standby_ini_nset, self->data_ptr);
}

static PyObject *
DsgController_get_th_rh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_th_rh_nget, self->data_ptr);
}

static int
DsgController_set_th_rh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_th_rh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_th_sh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_th_sh_nget, self->data_ptr);
}

static int
DsgController_set_th_sh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_th_sh_nset, self->data_ptr);
}

static PyObject *
DsgController_get_th_t_boiler(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_th_t_boiler_nget, self->data_ptr);
}

static int
DsgController_set_th_t_boiler(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_th_t_boiler_nset, self->data_ptr);
}

static PyObject *
DsgController_get_x_b_target(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_DsgController_x_b_target_nget, self->data_ptr);
}

static int
DsgController_set_x_b_target(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_DsgController_x_b_target_nset, self->data_ptr);
}

static PyGetSetDef DsgController_getset[] = {
{"A_sf", (getter)DsgController_get_A_sf,(setter)DsgController_set_A_sf,
	PyDoc_STR("*float*: Solar field area [m^2]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - total_installed_cost\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - dens_mirror\n\t - helio_height\n\t - helio_positions\n\t - helio_width\n"),
 	NULL},
{"P_b_in_init", (getter)DsgController_get_P_b_in_init,(setter)DsgController_set_P_b_in_init,
	PyDoc_STR("*float*: Initial Boiler inlet pressure [bar]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - P_boil_des\n"),
 	NULL},
{"P_cond_init", (getter)DsgController_get_P_cond_init,(setter)DsgController_set_P_cond_init,
	PyDoc_STR("*float*: Condenser pressure [Pa]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - P_rh_ref\n"),
 	NULL},
{"P_hp_in_des", (getter)DsgController_get_P_hp_in_des,(setter)DsgController_set_P_hp_in_des,
	PyDoc_STR("*float*: Design HP Turbine Inlet Pressure [bar]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - P_boil_des\n"),
 	NULL},
{"P_hp_out", (getter)DsgController_get_P_hp_out,(setter)DsgController_set_P_hp_out,
	PyDoc_STR("*float*: HP turbine outlet pressure [bar]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - P_rh_ref\n"),
 	NULL},
{"P_hp_out_des", (getter)DsgController_get_P_hp_out_des,(setter)DsgController_set_P_hp_out_des,
	PyDoc_STR("*float*: Design HP Turbine Outlet Pressure [bar]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - P_rh_ref\n"),
 	NULL},
{"T_ITD_des", (getter)DsgController_get_T_ITD_des,(setter)DsgController_set_T_ITD_des,
	PyDoc_STR("*float*: Approach temperature for dry cooling [C]\n\n*Required*: True"),
 	NULL},
{"T_amb_des", (getter)DsgController_get_T_amb_des,(setter)DsgController_set_T_amb_des,
	PyDoc_STR("*float*: Design ambient temperature (power cycle) [C]\n\n*Required*: True"),
 	NULL},
{"T_approach", (getter)DsgController_get_T_approach,(setter)DsgController_set_T_approach,
	PyDoc_STR("*float*: Approach temperature for wet cooling [C]\n\n*Required*: True"),
 	NULL},
{"T_fw_init", (getter)DsgController_get_T_fw_init,(setter)DsgController_set_T_fw_init,
	PyDoc_STR("*float*: Initial Feedwater outlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"T_hp_out", (getter)DsgController_get_T_hp_out,(setter)DsgController_set_T_hp_out,
	PyDoc_STR("*float*: HP turbine outlet temperature [C]\n\n*Required*: True"),
 	NULL},
{"T_rh_out_des", (getter)DsgController_get_T_rh_out_des,(setter)DsgController_set_T_rh_out_des,
	PyDoc_STR("*float*: Target reheater outlet temperature [C]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - T_rh_target\n"),
 	NULL},
{"T_rh_target", (getter)DsgController_get_T_rh_target,(setter)DsgController_set_T_rh_target,
	PyDoc_STR("*float*: Target reheater outlet temp. [C]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - T_rh_out_des\n"),
 	NULL},
{"T_sh_out_des", (getter)DsgController_get_T_sh_out_des,(setter)DsgController_set_T_sh_out_des,
	PyDoc_STR("*float*: Target superheater outlet temperature [C]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - T_hot\n\t - T_hot_ref\n"),
 	NULL},
{"ct", (getter)DsgController_get_ct,(setter)DsgController_set_ct,
	PyDoc_STR("*float*: Cooling Type [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"cycle_max_frac", (getter)DsgController_get_cycle_max_frac,(setter)DsgController_set_cycle_max_frac,
	PyDoc_STR("*float*: Cycle maximum overdesign fraction [-]\n\n*Required*: True"),
 	NULL},
{"dT_cw_ref", (getter)DsgController_get_dT_cw_ref,(setter)DsgController_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser water dT [C]\n\n*Required*: True"),
 	NULL},
{"d_rec", (getter)DsgController_get_d_rec,(setter)DsgController_set_d_rec,
	PyDoc_STR("*float*: Diameter of Receiver [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - rec_aspect\n\t - total_installed_cost\n"),
 	NULL},
{"d_rh", (getter)DsgController_get_d_rh,(setter)DsgController_set_d_rh,
	PyDoc_STR("*float*: O.D. of reheater tubes [m]\n\n*Required*: True"),
 	NULL},
{"d_sh", (getter)DsgController_get_d_sh,(setter)DsgController_set_d_sh,
	PyDoc_STR("*float*: O.D. of superheater tubes [m]\n\n*Required*: True"),
 	NULL},
{"d_t_boiler", (getter)DsgController_get_d_t_boiler,(setter)DsgController_set_d_t_boiler,
	PyDoc_STR("*float*: O.D. of boiler tubes [m]\n\n*Required*: True"),
 	NULL},
{"eta_rec_pump", (getter)DsgController_get_eta_rec_pump,(setter)DsgController_set_eta_rec_pump,
	PyDoc_STR("*float*: Feedwater pump efficiency [-]\n\n*Required*: True"),
 	NULL},
{"f_mdot_rh_init", (getter)DsgController_get_f_mdot_rh_init,(setter)DsgController_set_f_mdot_rh_init,
	PyDoc_STR("*float*: Reheat mass flow rate fraction [-]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - rh_frac_ref\n"),
 	NULL},
{"f_mdotrh_des", (getter)DsgController_get_f_mdotrh_des,(setter)DsgController_set_f_mdotrh_des,
	PyDoc_STR("*float*: Design reheat mass flow rate fraction [-]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - rh_frac_ref\n"),
 	NULL},
{"f_pb_cutoff", (getter)DsgController_get_f_pb_cutoff,(setter)DsgController_set_f_pb_cutoff,
	PyDoc_STR("*float*: Cycle cut-off fraction [-]\n\n*Required*: True"),
 	NULL},
{"f_pb_sb", (getter)DsgController_get_f_pb_sb,(setter)DsgController_set_f_pb_sb,
	PyDoc_STR("*float*: Cycle minimum standby fraction [-]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - q_sby_frac\n"),
 	NULL},
{"f_rec_min", (getter)DsgController_get_f_rec_min,(setter)DsgController_set_f_rec_min,
	PyDoc_STR("*float*: Minimum receiver absorbed power fraction [-]\n\n*Required*: True"),
 	NULL},
{"ffrac", (getter)DsgController_get_ffrac,(setter)DsgController_set_ffrac,
	PyDoc_STR("*sequence*: Fossil dispatch logic [-]\n\n*Required*: True"),
 	NULL},
{"flowtype", (getter)DsgController_get_flowtype,(setter)DsgController_set_flowtype,
	PyDoc_STR("*float*: Code for flow pattern through rec. [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"fossil_mode", (getter)DsgController_get_fossil_mode,(setter)DsgController_set_fossil_mode,
	PyDoc_STR("*float*: Fossil model: 1=Normal, 2=Supplemental [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"h_boiler", (getter)DsgController_get_h_boiler,(setter)DsgController_set_h_boiler,
	PyDoc_STR("*float*: Height of boiler [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - H_rec\n\t - rec_aspect\n\t - rec_height\n\t - total_installed_cost\n"),
 	NULL},
{"h_rh", (getter)DsgController_get_h_rh,(setter)DsgController_set_h_rh,
	PyDoc_STR("*float*: Height of reheater [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - H_rec\n\t - rec_aspect\n\t - rec_height\n\t - total_installed_cost\n"),
 	NULL},
{"h_sh", (getter)DsgController_get_h_sh,(setter)DsgController_set_h_sh,
	PyDoc_STR("*float*: Height of superheater [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - H_rec\n\t - rec_aspect\n\t - rec_height\n\t - total_installed_cost\n"),
 	NULL},
{"h_tower", (getter)DsgController_get_h_tower,(setter)DsgController_set_h_tower,
	PyDoc_STR("*float*: Tower Height [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - Piping_length\n\t - THT\n\t - total_installed_cost\n"),
 	NULL},
{"hl_ffact", (getter)DsgController_get_hl_ffact,(setter)DsgController_set_hl_ffact,
	PyDoc_STR("*float*: Heat Loss Fudge FACTor [-]\n\n*Required*: True"),
 	NULL},
{"lhv_eff", (getter)DsgController_get_lhv_eff,(setter)DsgController_set_lhv_eff,
	PyDoc_STR("*float*: Aux Heater lower heating value efficiency [-]\n\n*Required*: True"),
 	NULL},
{"mat_boiler", (getter)DsgController_get_mat_boiler,(setter)DsgController_set_mat_boiler,
	PyDoc_STR("*float*: Numerical code for tube material [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"mat_rh", (getter)DsgController_get_mat_rh,(setter)DsgController_set_mat_rh,
	PyDoc_STR("*float*: Numerical code for reheater material [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"mat_sh", (getter)DsgController_get_mat_sh,(setter)DsgController_set_mat_sh,
	PyDoc_STR("*float*: Numerical code for superheater material [-]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"n_panels", (getter)DsgController_get_n_panels,(setter)DsgController_set_n_panels,
	PyDoc_STR("*float*: Number of panels [-]\n\n*Required*: True"),
 	NULL},
{"p_cycle_design", (getter)DsgController_get_p_cycle_design,(setter)DsgController_set_p_cycle_design,
	PyDoc_STR("*float*: Design Cycle Power [MW]\n\n*Required*: True"),
 	NULL},
{"q_aux_max", (getter)DsgController_get_q_aux_max,(setter)DsgController_set_q_aux_max,
	PyDoc_STR("*float*: Maximum heat rate of auxiliary heater [MW]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - eta_ref\n"),
 	NULL},
{"q_pb_design", (getter)DsgController_get_q_pb_design,(setter)DsgController_set_q_pb_design,
	PyDoc_STR("*float*: Heat rate into powerblock at design [MW]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - eta_ref\n"),
 	NULL},
{"q_rec_des", (getter)DsgController_get_q_rec_des,(setter)DsgController_set_q_rec_des,
	PyDoc_STR("*float*: Design-point thermal power [MW]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - q_design\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - eta_ref\n"),
 	NULL},
{"rec_absorptance", (getter)DsgController_get_rec_absorptance,(setter)DsgController_set_rec_absorptance,
	PyDoc_STR("*float*: Absorptance of receiver tubes [-]\n\n*Required*: True"),
 	NULL},
{"rec_emis", (getter)DsgController_get_rec_emis,(setter)DsgController_set_rec_emis,
	PyDoc_STR("*float*: Emissivity of receiver tubes [-]\n\n*Required*: True"),
 	NULL},
{"rec_qf_delay", (getter)DsgController_get_rec_qf_delay,(setter)DsgController_set_rec_qf_delay,
	PyDoc_STR("*float*: Receiver start-up delay fraction of thermal energy of receiver running at design for 1 hour [-]\n\n*Required*: True"),
 	NULL},
{"rec_su_delay", (getter)DsgController_get_rec_su_delay,(setter)DsgController_set_rec_su_delay,
	PyDoc_STR("*float*: Receiver start-up delay time [hr]\n\n*Required*: True"),
 	NULL},
{"t_standby_ini", (getter)DsgController_get_t_standby_ini,(setter)DsgController_set_t_standby_ini,
	PyDoc_STR("*float*: Power block standby time [hr]\n\n*Required*: True"),
 	NULL},
{"th_rh", (getter)DsgController_get_th_rh,(setter)DsgController_set_th_rh,
	PyDoc_STR("*float*: Thickness of reheater tubes [m]\n\n*Required*: True"),
 	NULL},
{"th_sh", (getter)DsgController_get_th_sh,(setter)DsgController_set_th_sh,
	PyDoc_STR("*float*: Thickness of superheater tubes [m]\n\n*Required*: True"),
 	NULL},
{"th_t_boiler", (getter)DsgController_get_th_t_boiler,(setter)DsgController_set_th_t_boiler,
	PyDoc_STR("*float*: Thickness of boiler tubes [m]\n\n*Required*: True"),
 	NULL},
{"x_b_target", (getter)DsgController_get_x_b_target,(setter)DsgController_set_x_b_target,
	PyDoc_STR("*float*: Target boiler outlet quality [-]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject DsgController_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.DsgController",             /*tp_name*/
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
		DsgController_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		DsgController_getset,          /*tp_getset*/
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
 * Powerblock Group
 */ 

static PyTypeObject Powerblock_Type;

static PyObject *
Powerblock_new(SAM_TcsdirectSteam data_ptr)
{
	PyObject* new_obj = Powerblock_Type.tp_alloc(&Powerblock_Type,0);

	VarGroupObject* Powerblock_obj = (VarGroupObject*)new_obj;

	Powerblock_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Powerblock methods */

static PyObject *
Powerblock_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "Powerblock")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Powerblock_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Powerblock_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Powerblock_methods[] = {
		{"assign",            (PyCFunction)Powerblock_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Powerblock_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Powerblock_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Powerblock_get_F_wc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Powerblock_F_wc_aget, self->data_ptr);
}

static int
Powerblock_set_F_wc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_TcsdirectSteam_Powerblock_F_wc_aset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_boil_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_P_boil_des_nget, self->data_ptr);
}

static int
Powerblock_set_P_boil_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_P_boil_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_min(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_P_cond_min_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_min(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_P_cond_min_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_cond_ratio(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_P_cond_ratio_nget, self->data_ptr);
}

static int
Powerblock_set_P_cond_ratio(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_P_cond_ratio_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_P_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_P_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_P_rh_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_P_rh_ref_nget, self->data_ptr);
}

static int
Powerblock_set_P_rh_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_P_rh_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_ITD_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_T_ITD_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_ITD_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_T_ITD_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_amb_des(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_T_amb_des_nget, self->data_ptr);
}

static int
Powerblock_set_T_amb_des(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_T_amb_des_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_cold_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_T_cold_ref_nget, self->data_ptr);
}

static int
Powerblock_set_T_cold_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_T_cold_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_hot(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_T_hot_nget, self->data_ptr);
}

static int
Powerblock_set_T_hot(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_T_hot_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_T_hot_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_T_hot_ref_nget, self->data_ptr);
}

static int
Powerblock_set_T_hot_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_T_hot_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_dT_cw_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_dT_cw_ref_nget, self->data_ptr);
}

static int
Powerblock_set_dT_cw_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_dT_cw_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_eta_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_eta_ref_nget, self->data_ptr);
}

static int
Powerblock_set_eta_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_eta_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_n_pl_inc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_n_pl_inc_nget, self->data_ptr);
}

static int
Powerblock_set_n_pl_inc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_n_pl_inc_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_pb_bd_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_pb_bd_frac_nget, self->data_ptr);
}

static int
Powerblock_set_pb_bd_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_pb_bd_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_q_sby_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_q_sby_frac_nget, self->data_ptr);
}

static int
Powerblock_set_q_sby_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_q_sby_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_rh_frac_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_rh_frac_ref_nget, self->data_ptr);
}

static int
Powerblock_set_rh_frac_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_rh_frac_ref_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_frac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_startup_frac_nget, self->data_ptr);
}

static int
Powerblock_set_startup_frac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_startup_frac_nset, self->data_ptr);
}

static PyObject *
Powerblock_get_startup_time(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Powerblock_startup_time_nget, self->data_ptr);
}

static int
Powerblock_set_startup_time(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Powerblock_startup_time_nset, self->data_ptr);
}

static PyGetSetDef Powerblock_getset[] = {
{"F_wc", (getter)Powerblock_get_F_wc,(setter)Powerblock_set_F_wc,
	PyDoc_STR("*sequence*: Fraction indicating wet cooling use for hybrid system [none]\n\n*Required*: True"),
 	NULL},
{"P_boil_des", (getter)Powerblock_get_P_boil_des,(setter)Powerblock_set_P_boil_des,
	PyDoc_STR("*float*: Boiler operating pressure @ design [bar]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - P_b_in_init\n\t - P_hp_in_des\n"),
 	NULL},
{"P_cond_min", (getter)Powerblock_get_P_cond_min,(setter)Powerblock_set_P_cond_min,
	PyDoc_STR("*float*: Minimum condenser pressure [inHg]\n\n*Required*: True"),
 	NULL},
{"P_cond_ratio", (getter)Powerblock_get_P_cond_ratio,(setter)Powerblock_set_P_cond_ratio,
	PyDoc_STR("*float*: Condenser pressure ratio [none]\n\n*Required*: True"),
 	NULL},
{"P_ref", (getter)Powerblock_get_P_ref,(setter)Powerblock_set_P_ref,
	PyDoc_STR("*float*: Reference output electric power at design condition [MW]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - total_installed_cost\n"),
 	NULL},
{"P_rh_ref", (getter)Powerblock_get_P_rh_ref,(setter)Powerblock_set_P_rh_ref,
	PyDoc_STR("*float*: Reheater operating pressure at design [bar]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - P_cond_init\n\t - P_hp_out\n\t - P_hp_out_des\n"),
 	NULL},
{"T_ITD_des", (getter)Powerblock_get_T_ITD_des,(setter)Powerblock_set_T_ITD_des,
	PyDoc_STR("*float*: ITD at design for dry system [C]\n\n*Required*: True"),
 	NULL},
{"T_amb_des", (getter)Powerblock_get_T_amb_des,(setter)Powerblock_set_T_amb_des,
	PyDoc_STR("*float*: Reference ambient temperature at design point [C]\n\n*Required*: True"),
 	NULL},
{"T_cold_ref", (getter)Powerblock_get_T_cold_ref,(setter)Powerblock_set_T_cold_ref,
	PyDoc_STR("*float*: Reference HTF outlet temperature at design [C]\n\n*Required*: True"),
 	NULL},
{"T_hot", (getter)Powerblock_get_T_hot,(setter)Powerblock_set_T_hot,
	PyDoc_STR("*float*: Hot HTF inlet temperature, from storage tank [C]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - T_sh_out_des\n"),
 	NULL},
{"T_hot_ref", (getter)Powerblock_get_T_hot_ref,(setter)Powerblock_set_T_hot_ref,
	PyDoc_STR("*float*: Reference HTF inlet temperature at design [C]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - T_sh_out_des\n"),
 	NULL},
{"dT_cw_ref", (getter)Powerblock_get_dT_cw_ref,(setter)Powerblock_set_dT_cw_ref,
	PyDoc_STR("*float*: Reference condenser cooling water inlet/outlet T diff [C]\n\n*Required*: True"),
 	NULL},
{"eta_ref", (getter)Powerblock_get_eta_ref,(setter)Powerblock_set_eta_ref,
	PyDoc_STR("*float*: Reference conversion efficiency at design condition [none]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - design_eff\n\t - q_aux_max\n\t - q_design\n\t - q_pb_design\n\t - q_rec_des\n\t - total_installed_cost\n"),
 	NULL},
{"n_pl_inc", (getter)Powerblock_get_n_pl_inc,(setter)Powerblock_set_n_pl_inc,
	PyDoc_STR("*float*: Number of part-load increments for the heat rejection system [none]\n\n*Constraints*: INTEGER\n\n*Required*: True"),
 	NULL},
{"pb_bd_frac", (getter)Powerblock_get_pb_bd_frac,(setter)Powerblock_set_pb_bd_frac,
	PyDoc_STR("*float*: Power block blowdown steam fraction  [none]\n\n*Required*: True"),
 	NULL},
{"q_sby_frac", (getter)Powerblock_get_q_sby_frac,(setter)Powerblock_set_q_sby_frac,
	PyDoc_STR("*float*: Fraction of thermal power required for standby mode [none]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - f_pb_sb\n"),
 	NULL},
{"rh_frac_ref", (getter)Powerblock_get_rh_frac_ref,(setter)Powerblock_set_rh_frac_ref,
	PyDoc_STR("*float*: Reheater flow fraction at design [none]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - f_mdot_rh_init\n\t - f_mdotrh_des\n"),
 	NULL},
{"startup_frac", (getter)Powerblock_get_startup_frac,(setter)Powerblock_set_startup_frac,
	PyDoc_STR("*float*: Fraction of design thermal power needed for startup [none]\n\n*Required*: True"),
 	NULL},
{"startup_time", (getter)Powerblock_get_startup_time,(setter)Powerblock_set_startup_time,
	PyDoc_STR("*float*: Time needed for power block startup [hr]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Powerblock_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.Powerblock",             /*tp_name*/
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
		Powerblock_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Powerblock_getset,          /*tp_getset*/
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
 * Parasitics Group
 */ 

static PyTypeObject Parasitics_Type;

static PyObject *
Parasitics_new(SAM_TcsdirectSteam data_ptr)
{
	PyObject* new_obj = Parasitics_Type.tp_alloc(&Parasitics_Type,0);

	VarGroupObject* Parasitics_obj = (VarGroupObject*)new_obj;

	Parasitics_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Parasitics methods */

static PyObject *
Parasitics_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "Parasitics")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Parasitics_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Parasitics_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Parasitics_methods[] = {
		{"assign",            (PyCFunction)Parasitics_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Parasitics_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Parasitics_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Parasitics_get_Design_power(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_Design_power_nget, self->data_ptr);
}

static int
Parasitics_set_Design_power(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_Design_power_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_Piping_length(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_Piping_length_nget, self->data_ptr);
}

static int
Parasitics_set_Piping_length(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_Piping_length_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_Piping_loss(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_Piping_loss_nget, self->data_ptr);
}

static int
Parasitics_set_Piping_loss(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_Piping_loss_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_aux_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_aux_par_nget, self->data_ptr);
}

static int
Parasitics_set_aux_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_aux_par_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_aux_par_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_aux_par_0_nget, self->data_ptr);
}

static int
Parasitics_set_aux_par_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_aux_par_0_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_aux_par_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_aux_par_1_nget, self->data_ptr);
}

static int
Parasitics_set_aux_par_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_aux_par_1_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_aux_par_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_aux_par_2_nget, self->data_ptr);
}

static int
Parasitics_set_aux_par_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_aux_par_2_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_aux_par_f(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_aux_par_f_nget, self->data_ptr);
}

static int
Parasitics_set_aux_par_f(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_aux_par_f_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_bop_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_bop_par_nget, self->data_ptr);
}

static int
Parasitics_set_bop_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_bop_par_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_bop_par_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_bop_par_0_nget, self->data_ptr);
}

static int
Parasitics_set_bop_par_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_bop_par_0_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_bop_par_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_bop_par_1_nget, self->data_ptr);
}

static int
Parasitics_set_bop_par_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_bop_par_1_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_bop_par_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_bop_par_2_nget, self->data_ptr);
}

static int
Parasitics_set_bop_par_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_bop_par_2_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_bop_par_f(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_bop_par_f_nget, self->data_ptr);
}

static int
Parasitics_set_bop_par_f(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_bop_par_f_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_design_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_design_eff_nget, self->data_ptr);
}

static int
Parasitics_set_design_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_design_eff_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_pb_fixed_par(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_pb_fixed_par_nget, self->data_ptr);
}

static int
Parasitics_set_pb_fixed_par(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_pb_fixed_par_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_piping_length_add(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_piping_length_add_nget, self->data_ptr);
}

static int
Parasitics_set_piping_length_add(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_piping_length_add_nset, self->data_ptr);
}

static PyObject *
Parasitics_get_piping_length_mult(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Parasitics_piping_length_mult_nget, self->data_ptr);
}

static int
Parasitics_set_piping_length_mult(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_TcsdirectSteam_Parasitics_piping_length_mult_nset, self->data_ptr);
}

static PyGetSetDef Parasitics_getset[] = {
{"Design_power", (getter)Parasitics_get_Design_power,(setter)Parasitics_set_Design_power,
	PyDoc_STR("*float*: Power production at design conditions [MWe]\n\n*Required*: True"),
 	NULL},
{"Piping_length", (getter)Parasitics_get_Piping_length,(setter)Parasitics_set_Piping_length,
	PyDoc_STR("*float*: Total length of exposed piping [m]\n\n*Required*: True\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - THT\n\t - h_tower\n\t - piping_length_add\n\t - piping_length_mult\n"),
 	NULL},
{"Piping_loss", (getter)Parasitics_get_Piping_loss,(setter)Parasitics_set_Piping_loss,
	PyDoc_STR("*float*: Thermal loss per meter of piping [Wt/m]\n\n*Required*: True"),
 	NULL},
{"aux_par", (getter)Parasitics_get_aux_par,(setter)Parasitics_set_aux_par,
	PyDoc_STR("*float*: Aux heater, boiler parasitic [MWe/MWcap]\n\n*Required*: True"),
 	NULL},
{"aux_par_0", (getter)Parasitics_get_aux_par_0,(setter)Parasitics_set_aux_par_0,
	PyDoc_STR("*float*: Aux heater, boiler parasitic - constant coefficient [none]\n\n*Required*: True"),
 	NULL},
{"aux_par_1", (getter)Parasitics_get_aux_par_1,(setter)Parasitics_set_aux_par_1,
	PyDoc_STR("*float*: Aux heater, boiler parasitic - linear coefficient [none]\n\n*Required*: True"),
 	NULL},
{"aux_par_2", (getter)Parasitics_get_aux_par_2,(setter)Parasitics_set_aux_par_2,
	PyDoc_STR("*float*: Aux heater, boiler parasitic - quadratic coefficient [none]\n\n*Required*: True"),
 	NULL},
{"aux_par_f", (getter)Parasitics_get_aux_par_f,(setter)Parasitics_set_aux_par_f,
	PyDoc_STR("*float*: Aux heater, boiler parasitic - multiplying fraction [none]\n\n*Required*: True"),
 	NULL},
{"bop_par", (getter)Parasitics_get_bop_par,(setter)Parasitics_set_bop_par,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction [MWe/MWcap]\n\n*Required*: True"),
 	NULL},
{"bop_par_0", (getter)Parasitics_get_bop_par_0,(setter)Parasitics_set_bop_par_0,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - const coeff [none]\n\n*Required*: True"),
 	NULL},
{"bop_par_1", (getter)Parasitics_get_bop_par_1,(setter)Parasitics_set_bop_par_1,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - linear coeff [none]\n\n*Required*: True"),
 	NULL},
{"bop_par_2", (getter)Parasitics_get_bop_par_2,(setter)Parasitics_set_bop_par_2,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - quadratic coeff [none]\n\n*Required*: True"),
 	NULL},
{"bop_par_f", (getter)Parasitics_get_bop_par_f,(setter)Parasitics_set_bop_par_f,
	PyDoc_STR("*float*: Balance of plant parasitic power fraction - mult frac [none]\n\n*Required*: True"),
 	NULL},
{"design_eff", (getter)Parasitics_get_design_eff,(setter)Parasitics_set_design_eff,
	PyDoc_STR("*float*: Power cycle efficiency at design [none]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - total_installed_cost\n\n\n*This variable may need to be updated if the values of the following have changed*: \n\t - eta_ref\n"),
 	NULL},
{"pb_fixed_par", (getter)Parasitics_get_pb_fixed_par,(setter)Parasitics_set_pb_fixed_par,
	PyDoc_STR("*float*: Fixed parasitic load - runs at all times [MWe/MWcap]\n\n*Required*: True"),
 	NULL},
{"piping_length_add", (getter)Parasitics_get_piping_length_add,(setter)Parasitics_set_piping_length_add,
	PyDoc_STR("*float*: Piping constant length [m]\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - Piping_length\n"),
 	NULL},
{"piping_length_mult", (getter)Parasitics_get_piping_length_mult,(setter)Parasitics_set_piping_length_mult,
	PyDoc_STR("*float*: Piping length multiplier\n\n*Required*: True\n\n*Changes to this variable may require updating the values of the following*: \n\t - Piping_length\n"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Parasitics_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.Parasitics",             /*tp_name*/
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
		Parasitics_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Parasitics_getset,          /*tp_getset*/
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
Outputs_new(SAM_TcsdirectSteam data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "TcsdirectSteam", "Outputs")){
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
Outputs_get_P_b_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_b_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_b_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_b_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cond(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_cond_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cooling_tower_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_cooling_tower_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_cycle(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_cycle_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_drop_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_drop_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_fixed(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_fixed_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_out_net(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_out_net_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_parasitics(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_parasitics_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_piping_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_piping_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_plant_balance_tot(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_plant_balance_tot_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_rh_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_rh_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_rh_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_rh_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_P_sh_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_P_sh_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_b_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_b_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_boiling(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_boiling_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_fw(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_fw_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_max_b_surf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_max_b_surf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_max_rh_surf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_max_rh_surf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_max_sh_surf(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_max_sh_surf_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rh_in(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_rh_in_aget, self->data_ptr);
}

static PyObject *
Outputs_get_T_rh_out(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_T_rh_out_aget, self->data_ptr);
}

static PyObject *
Outputs_get_W_dot_boost(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_W_dot_boost_aget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_W_cycle_gross(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_annual_W_cycle_gross_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_energy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_annual_energy_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_annual_fuel_usage_nget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_total_water_use(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_annual_total_water_use_nget, self->data_ptr);
}

static PyObject *
Outputs_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_beam_aget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_capacity_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_conversion_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_conversion_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_dP_rh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_dP_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dP_sh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_dP_sh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_defocus(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_defocus_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_b(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_eta_b_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_field(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_eta_field_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_eta_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_rh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_eta_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eta_sh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_eta_sh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_bays(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_f_bays_aget, self->data_ptr);
}

static PyObject *
Outputs_get_f_mdot_rh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_f_mdot_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hour(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_hour_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_kwh_per_kw_nget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_aux(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_m_dot_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_makeup(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_m_dot_makeup_aget, self->data_ptr);
}

static PyObject *
Outputs_get_m_dot_sh(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_m_dot_sh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_month(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_month_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pparasi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_pparasi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_pres(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_pres_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_abs_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_abs_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_aux_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_aux_fuel(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_aux_fuel_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_b_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_b_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_b_conv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_b_conv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_b_rad(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_b_rad_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_conv_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_conv_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_inc_full(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_inc_full_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_rad_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_rad_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_rh_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_rh_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_rh_conv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_rh_conv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_rh_rad(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_rh_rad_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_sh_abs(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_sh_abs_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_sh_conv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_sh_conv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_sh_rad(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_sh_rad_aget, self->data_ptr);
}

static PyObject *
Outputs_get_q_therm_in_rec(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_q_therm_in_rec_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solazi(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_solazi_aget, self->data_ptr);
}

static PyObject *
Outputs_get_solzen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_solzen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_TcsdirectSteam_Outputs_system_heat_rate_nget, self->data_ptr);
}

static PyObject *
Outputs_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_tdry_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tou_value(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_tou_value_aget, self->data_ptr);
}

static PyObject *
Outputs_get_twet(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_twet_aget, self->data_ptr);
}

static PyObject *
Outputs_get_v_rh_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_v_rh_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_v_sh_max(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_v_sh_max_aget, self->data_ptr);
}

static PyObject *
Outputs_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_TcsdirectSteam_Outputs_wspd_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"P_b_in", (getter)Outputs_get_P_b_in,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler pressure inlet [kPa]"),
 	NULL},
{"P_b_out", (getter)Outputs_get_P_b_out,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler pressure outlet [kPa]"),
 	NULL},
{"P_cond", (getter)Outputs_get_P_cond,(setter)0,
	PyDoc_STR("*sequence*: Condenser pressure [Pa]"),
 	NULL},
{"P_cooling_tower_tot", (getter)Outputs_get_P_cooling_tower_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power condenser operation [MWe]"),
 	NULL},
{"P_cycle", (getter)Outputs_get_P_cycle,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (gross) [MWe]"),
 	NULL},
{"P_drop_b", (getter)Outputs_get_P_drop_b,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler pressure drop [Pa]"),
 	NULL},
{"P_fixed", (getter)Outputs_get_P_fixed,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power fixed load [MWe]"),
 	NULL},
{"P_out_net", (getter)Outputs_get_P_out_net,(setter)0,
	PyDoc_STR("*sequence*: Cycle electrical power output (net) [MWe]"),
 	NULL},
{"P_parasitics", (getter)Outputs_get_P_parasitics,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power total consumption [MWe]"),
 	NULL},
{"P_piping_tot", (getter)Outputs_get_P_piping_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power equiv. header pipe losses [MWe]"),
 	NULL},
{"P_plant_balance_tot", (getter)Outputs_get_P_plant_balance_tot,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power generation-dependent load [MWe]"),
 	NULL},
{"P_rh_in", (getter)Outputs_get_P_rh_in,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater pressure inlet [kPa]"),
 	NULL},
{"P_rh_out", (getter)Outputs_get_P_rh_out,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater pressure outlet [kPa]"),
 	NULL},
{"P_sh_out", (getter)Outputs_get_P_sh_out,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater pressure outlet [kPa]"),
 	NULL},
{"T_b_in", (getter)Outputs_get_T_b_in,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler temperature inlet [C]"),
 	NULL},
{"T_boiling", (getter)Outputs_get_T_boiling,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler temperature drum [C]"),
 	NULL},
{"T_fw", (getter)Outputs_get_T_fw,(setter)0,
	PyDoc_STR("*sequence*: Cycle temperature feedwater outlet [C]"),
 	NULL},
{"T_max_b_surf", (getter)Outputs_get_T_max_b_surf,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler temperature surface max [C]"),
 	NULL},
{"T_max_rh_surf", (getter)Outputs_get_T_max_rh_surf,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater temperature surface max [C]"),
 	NULL},
{"T_max_sh_surf", (getter)Outputs_get_T_max_sh_surf,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater temperature surface max [C]"),
 	NULL},
{"T_rh_in", (getter)Outputs_get_T_rh_in,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater temperature inlet [C]"),
 	NULL},
{"T_rh_out", (getter)Outputs_get_T_rh_out,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater temperature outlet [C]"),
 	NULL},
{"W_dot_boost", (getter)Outputs_get_W_dot_boost,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power receiver boost pump [MWe]"),
 	NULL},
{"annual_W_cycle_gross", (getter)Outputs_get_annual_W_cycle_gross,(setter)0,
	PyDoc_STR("*float*: Electrical source - Power cycle gross output [kWh]"),
 	NULL},
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	PyDoc_STR("*float*: Annual Energy [kWh]"),
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	PyDoc_STR("*float*: Annual fuel usage [kWh]"),
 	NULL},
{"annual_total_water_use", (getter)Outputs_get_annual_total_water_use,(setter)0,
	PyDoc_STR("*float*: Total Annual Water Usage: cycle + mirror washing [m3]"),
 	NULL},
{"beam", (getter)Outputs_get_beam,(setter)0,
	PyDoc_STR("*sequence*: Resource Beam normal irradiance [W/m2]"),
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	PyDoc_STR("*float*: Capacity factor [%]"),
 	NULL},
{"conversion_factor", (getter)Outputs_get_conversion_factor,(setter)0,
	PyDoc_STR("*float*: Gross to Net Conversion Factor [%]"),
 	NULL},
{"dP_rh", (getter)Outputs_get_dP_rh,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater pressure drop [Pa]"),
 	NULL},
{"dP_sh", (getter)Outputs_get_dP_sh,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater pressure drop [Pa]"),
 	NULL},
{"defocus", (getter)Outputs_get_defocus,(setter)0,
	PyDoc_STR("*sequence*: Field optical focus fraction"),
 	NULL},
{"eta_b", (getter)Outputs_get_eta_b,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler thermal efficiency"),
 	NULL},
{"eta_field", (getter)Outputs_get_eta_field,(setter)0,
	PyDoc_STR("*sequence*: Field optical efficiency"),
 	NULL},
{"eta_rec", (getter)Outputs_get_eta_rec,(setter)0,
	PyDoc_STR("*sequence*: Receiver thermal efficiency"),
 	NULL},
{"eta_rh", (getter)Outputs_get_eta_rh,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater thermal efficiency [-]"),
 	NULL},
{"eta_sh", (getter)Outputs_get_eta_sh,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater thermal efficiency"),
 	NULL},
{"f_bays", (getter)Outputs_get_f_bays,(setter)0,
	PyDoc_STR("*sequence*: Condenser fraction of operating bays"),
 	NULL},
{"f_mdot_rh", (getter)Outputs_get_f_mdot_rh,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater mass flow rate fraction [-]"),
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	PyDoc_STR("*sequence*: System power generated [kW]"),
 	NULL},
{"hour", (getter)Outputs_get_hour,(setter)0,
	PyDoc_STR("*sequence*: Resource Hour of Day"),
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	PyDoc_STR("*float*: First year kWh/kW [kWh/kW]"),
 	NULL},
{"m_dot_aux", (getter)Outputs_get_m_dot_aux,(setter)0,
	PyDoc_STR("*sequence*: Auxiliary mass flow rate [kg/hr]"),
 	NULL},
{"m_dot_makeup", (getter)Outputs_get_m_dot_makeup,(setter)0,
	PyDoc_STR("*sequence*: Cycle mass flow rate cooling water makeup [kg/hr]"),
 	NULL},
{"m_dot_sh", (getter)Outputs_get_m_dot_sh,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater mass flow rate [kg/hr]"),
 	NULL},
{"month", (getter)Outputs_get_month,(setter)0,
	PyDoc_STR("*sequence*: Resource Month"),
 	NULL},
{"pparasi", (getter)Outputs_get_pparasi,(setter)0,
	PyDoc_STR("*sequence*: Parasitic power heliostat drives [MWe]"),
 	NULL},
{"pres", (getter)Outputs_get_pres,(setter)0,
	PyDoc_STR("*sequence*: Resource Pressure [mbar]"),
 	NULL},
{"q_abs_rec", (getter)Outputs_get_q_abs_rec,(setter)0,
	PyDoc_STR("*sequence*: Receiver power absorbed total [MWt]"),
 	NULL},
{"q_aux", (getter)Outputs_get_q_aux,(setter)0,
	PyDoc_STR("*sequence*: Auxiliary heat rate delivered to cycle [MW]"),
 	NULL},
{"q_aux_fuel", (getter)Outputs_get_q_aux_fuel,(setter)0,
	PyDoc_STR("*sequence*: Fuel energy rate to aux heater [MMBTU]"),
 	NULL},
{"q_b_abs", (getter)Outputs_get_q_b_abs,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler power absorbed [MWt]"),
 	NULL},
{"q_b_conv", (getter)Outputs_get_q_b_conv,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler power loss to convection [MWt]"),
 	NULL},
{"q_b_rad", (getter)Outputs_get_q_b_rad,(setter)0,
	PyDoc_STR("*sequence*: Receiver boiler power loss to radiation [MWt]"),
 	NULL},
{"q_conv_rec", (getter)Outputs_get_q_conv_rec,(setter)0,
	PyDoc_STR("*sequence*: Receiver power loss to convection total [MWt]"),
 	NULL},
{"q_inc_full", (getter)Outputs_get_q_inc_full,(setter)0,
	PyDoc_STR("*sequence*: Receiver power incident (excl. defocus) [MWt]"),
 	NULL},
{"q_rad_rec", (getter)Outputs_get_q_rad_rec,(setter)0,
	PyDoc_STR("*sequence*: Receiver power loss to radiation total [MWt]"),
 	NULL},
{"q_rh_abs", (getter)Outputs_get_q_rh_abs,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater power absorbed [MWt]"),
 	NULL},
{"q_rh_conv", (getter)Outputs_get_q_rh_conv,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater power loss to convection [MWt]"),
 	NULL},
{"q_rh_rad", (getter)Outputs_get_q_rh_rad,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater power loss to radiation [MWt]"),
 	NULL},
{"q_sh_abs", (getter)Outputs_get_q_sh_abs,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater power absorbed [MWt]"),
 	NULL},
{"q_sh_conv", (getter)Outputs_get_q_sh_conv,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater power loss to convection [MWt]"),
 	NULL},
{"q_sh_rad", (getter)Outputs_get_q_sh_rad,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater power loss to radiation [MWt]"),
 	NULL},
{"q_therm_in_rec", (getter)Outputs_get_q_therm_in_rec,(setter)0,
	PyDoc_STR("*sequence*: Receiver power to steam total [MWt]"),
 	NULL},
{"solazi", (getter)Outputs_get_solazi,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Azimuth [deg]"),
 	NULL},
{"solzen", (getter)Outputs_get_solzen,(setter)0,
	PyDoc_STR("*sequence*: Resource Solar Zenith [deg]"),
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	PyDoc_STR("*float*: System heat rate [MMBtu/MWh]"),
 	NULL},
{"tdry", (getter)Outputs_get_tdry,(setter)0,
	PyDoc_STR("*sequence*: Resource Dry bulb temperature [C]"),
 	NULL},
{"tou_value", (getter)Outputs_get_tou_value,(setter)0,
	PyDoc_STR("*sequence*: Resource Time-of-use value"),
 	NULL},
{"twet", (getter)Outputs_get_twet,(setter)0,
	PyDoc_STR("*sequence*: Resource Wet bulb temperature [C]"),
 	NULL},
{"v_rh_max", (getter)Outputs_get_v_rh_max,(setter)0,
	PyDoc_STR("*sequence*: Receiver reheater velocity at outlet [m/s]"),
 	NULL},
{"v_sh_max", (getter)Outputs_get_v_sh_max,(setter)0,
	PyDoc_STR("*sequence*: Receiver superheater velocity at outlet [m/s]"),
 	NULL},
{"wspd", (getter)Outputs_get_wspd,(setter)0,
	PyDoc_STR("*sequence*: Resource Wind Speed [m/s]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam.Outputs",             /*tp_name*/
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
 * TcsdirectSteam
 */

static PyTypeObject TcsdirectSteam_Type;

static CmodObject *
newTcsdirectSteamObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &TcsdirectSteam_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* DirectSteamTower_obj = DirectSteamTower_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "DirectSteamTower", DirectSteamTower_obj);
	Py_DECREF(DirectSteamTower_obj);

	PyObject* TouTranslator_obj = TouTranslator_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "TouTranslator", TouTranslator_obj);
	Py_DECREF(TouTranslator_obj);

	PyObject* Heliostat_obj = Heliostat_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Heliostat", Heliostat_obj);
	Py_DECREF(Heliostat_obj);

	PyObject* Receiver_obj = Receiver_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Receiver", Receiver_obj);
	Py_DECREF(Receiver_obj);

	PyObject* DsgController_obj = DsgController_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "DsgController", DsgController_obj);
	Py_DECREF(DsgController_obj);

	PyObject* Powerblock_obj = Powerblock_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Powerblock", Powerblock_obj);
	Py_DECREF(Powerblock_obj);

	PyObject* Parasitics_obj = Parasitics_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Parasitics", Parasitics_obj);
	Py_DECREF(Parasitics_obj);

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

/* TcsdirectSteam methods */

static void
TcsdirectSteam_dealloc(CmodObject *self)
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
TcsdirectSteam_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_TcsdirectSteam_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcsdirectSteam_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "TcsdirectSteam"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
TcsdirectSteam_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
TcsdirectSteam_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef TcsdirectSteam_methods[] = {
		{"execute",            (PyCFunction)TcsdirectSteam_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)TcsdirectSteam_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)TcsdirectSteam_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)TcsdirectSteam_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
TcsdirectSteam_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TcsdirectSteam_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TcsdirectSteam_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"TcsdirectSteam",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)TcsdirectSteam_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)TcsdirectSteam_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)TcsdirectSteam_getattro, /*tp_getattro*/
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
		TcsdirectSteam_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TcsdirectSteam object */

static PyObject *
TcsdirectSteam_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newTcsdirectSteamObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsdirectSteam_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsdirectSteamObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
TcsdirectSteam_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newTcsdirectSteamObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsdirectSteam", def);

	return (PyObject *)rv;
}

static PyObject *
TcsdirectSteam_from_existing(PyObject *self, PyObject *args)
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

	rv = newTcsdirectSteamObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "TcsdirectSteam", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TcsdirectSteamModule_methods[] = {
		{"new",             TcsdirectSteam_new,         METH_VARARGS,
				PyDoc_STR("new() -> TcsdirectSteam")},
		{"default",             TcsdirectSteam_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> TcsdirectSteam\n\nUse financial config-specific default attributes\n"
				"config options:\n\n- \"DSPTAllEquityPartnershipFlip\"\n- \"DSPTLeveragedPartnershipFlip\"\n- \"DSPTMerchantPlant\"\n- \"DSPTSaleLeaseback\"\n- \"DSPTSingleOwner\"")},
		{"wrap",             TcsdirectSteam_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> TcsdirectSteam\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   TcsdirectSteam_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> TcsdirectSteam\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CSP direct steam power tower model for power generation");


static int
TcsdirectSteamModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	TcsdirectSteam_Type.tp_dict = PyDict_New();
	if (!TcsdirectSteam_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to TcsdirectSteam_Type
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
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Weather type object to TcsdirectSteam_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the DirectSteamTower type object to TcsdirectSteam_Type
	if (PyType_Ready(&DirectSteamTower_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"DirectSteamTower",
				(PyObject*)&DirectSteamTower_Type);
	Py_DECREF(&DirectSteamTower_Type);

	/// Add the TouTranslator type object to TcsdirectSteam_Type
	if (PyType_Ready(&TouTranslator_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"TouTranslator",
				(PyObject*)&TouTranslator_Type);
	Py_DECREF(&TouTranslator_Type);

	/// Add the Heliostat type object to TcsdirectSteam_Type
	if (PyType_Ready(&Heliostat_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"Heliostat",
				(PyObject*)&Heliostat_Type);
	Py_DECREF(&Heliostat_Type);

	/// Add the Receiver type object to TcsdirectSteam_Type
	if (PyType_Ready(&Receiver_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"Receiver",
				(PyObject*)&Receiver_Type);
	Py_DECREF(&Receiver_Type);

	/// Add the DsgController type object to TcsdirectSteam_Type
	if (PyType_Ready(&DsgController_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"DsgController",
				(PyObject*)&DsgController_Type);
	Py_DECREF(&DsgController_Type);

	/// Add the Powerblock type object to TcsdirectSteam_Type
	if (PyType_Ready(&Powerblock_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"Powerblock",
				(PyObject*)&Powerblock_Type);
	Py_DECREF(&Powerblock_Type);

	/// Add the Parasitics type object to TcsdirectSteam_Type
	if (PyType_Ready(&Parasitics_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"Parasitics",
				(PyObject*)&Parasitics_Type);
	Py_DECREF(&Parasitics_Type);

	/// Add the Outputs type object to TcsdirectSteam_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(TcsdirectSteam_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the TcsdirectSteam type object to the module
	if (PyType_Ready(&TcsdirectSteam_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"TcsdirectSteam",
				(PyObject*)&TcsdirectSteam_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot TcsdirectSteamModule_slots[] = {
		{Py_mod_exec, TcsdirectSteamModule_exec},
		{0, NULL},
};

static struct PyModuleDef TcsdirectSteamModule = {
		PyModuleDef_HEAD_INIT,
		"TcsdirectSteam",
		module_doc,
		0,
		TcsdirectSteamModule_methods,
		TcsdirectSteamModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_TcsdirectSteam(void)
{
	return PyModuleDef_Init(&TcsdirectSteamModule);
}