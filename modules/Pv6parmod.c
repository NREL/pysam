#include <Python.h>

#include <SAM_Pv6parmod.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_Pv6parmod data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pv6parmod", "Weather")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Weather_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &Weather_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pv6parmod", "Weather")){
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
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``Weather_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)Weather_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``Weather_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Weather_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Weather_get_elev(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_Weather_elev_nget, self->data_ptr);
}

static int
Weather_set_elev(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_Weather_elev_nset, self->data_ptr);
}

static PyObject *
Weather_get_incidence(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_incidence_aget, self->data_ptr);
}

static int
Weather_set_incidence(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_incidence_aset, self->data_ptr);
}

static PyObject *
Weather_get_poa_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_poa_beam_aget, self->data_ptr);
}

static int
Weather_set_poa_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_poa_beam_aset, self->data_ptr);
}

static PyObject *
Weather_get_poa_gnddiff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_poa_gnddiff_aget, self->data_ptr);
}

static int
Weather_set_poa_gnddiff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_poa_gnddiff_aset, self->data_ptr);
}

static PyObject *
Weather_get_poa_skydiff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_poa_skydiff_aget, self->data_ptr);
}

static int
Weather_set_poa_skydiff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_poa_skydiff_aset, self->data_ptr);
}

static PyObject *
Weather_get_sun_zen(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_sun_zen_aget, self->data_ptr);
}

static int
Weather_set_sun_zen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_sun_zen_aset, self->data_ptr);
}

static PyObject *
Weather_get_surf_tilt(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_surf_tilt_aget, self->data_ptr);
}

static int
Weather_set_surf_tilt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_surf_tilt_aset, self->data_ptr);
}

static PyObject *
Weather_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_tdry_aget, self->data_ptr);
}

static int
Weather_set_tdry(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_tdry_aset, self->data_ptr);
}

static PyObject *
Weather_get_wdir(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_wdir_aget, self->data_ptr);
}

static int
Weather_set_wdir(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_wdir_aset, self->data_ptr);
}

static PyObject *
Weather_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Weather_wspd_aget, self->data_ptr);
}

static int
Weather_set_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_Weather_wspd_aset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"elev", (getter)Weather_get_elev,(setter)Weather_set_elev,
	PyDoc_STR("*float*: Site elevation [m]\n\n**Required:**\nTrue"),
 	NULL},
{"incidence", (getter)Weather_get_incidence,(setter)Weather_set_incidence,
	PyDoc_STR("*sequence*: Incidence angle to surface [deg]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"poa_beam", (getter)Weather_get_poa_beam,(setter)Weather_set_poa_beam,
	PyDoc_STR("*sequence*: Incident direct normal radiation [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"poa_gnddiff", (getter)Weather_get_poa_gnddiff,(setter)Weather_set_poa_gnddiff,
	PyDoc_STR("*sequence*: Incident ground diffuse irradiance [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"poa_skydiff", (getter)Weather_get_poa_skydiff,(setter)Weather_set_poa_skydiff,
	PyDoc_STR("*sequence*: Incident sky diffuse radiation [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"sun_zen", (getter)Weather_get_sun_zen,(setter)Weather_set_sun_zen,
	PyDoc_STR("*sequence*: Sun zenith angle [deg]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"surf_tilt", (getter)Weather_get_surf_tilt,(setter)Weather_set_surf_tilt,
	PyDoc_STR("*sequence*: Surface tilt angle [deg]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"tdry", (getter)Weather_get_tdry,(setter)Weather_set_tdry,
	PyDoc_STR("*sequence*: Dry bulb temperature ['C]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"wdir", (getter)Weather_get_wdir,(setter)Weather_set_wdir,
	PyDoc_STR("*sequence*: Wind direction [deg]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
{"wspd", (getter)Weather_get_wspd,(setter)Weather_set_wspd,
	PyDoc_STR("*sequence*: Wind speed [m/s]\n\n**Constraints:**\nLENGTH_EQUAL=poa_beam\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pv6parmod.Weather",             /*tp_name*/
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
 * CEC6ParameterPVModuleModel Group
 */ 

static PyTypeObject CEC6ParameterPVModuleModel_Type;

static PyObject *
CEC6ParameterPVModuleModel_new(SAM_Pv6parmod data_ptr)
{
	PyObject* new_obj = CEC6ParameterPVModuleModel_Type.tp_alloc(&CEC6ParameterPVModuleModel_Type,0);

	VarGroupObject* CEC6ParameterPVModuleModel_obj = (VarGroupObject*)new_obj;

	CEC6ParameterPVModuleModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* CEC6ParameterPVModuleModel methods */

static PyObject *
CEC6ParameterPVModuleModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pv6parmod", "CEC6ParameterPVModuleModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CEC6ParameterPVModuleModel_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &CEC6ParameterPVModuleModel_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pv6parmod", "CEC6ParameterPVModuleModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
CEC6ParameterPVModuleModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &CEC6ParameterPVModuleModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef CEC6ParameterPVModuleModel_methods[] = {
		{"assign",            (PyCFunction)CEC6ParameterPVModuleModel_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``CEC6ParameterPVModuleModel_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)CEC6ParameterPVModuleModel_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``CEC6ParameterPVModuleModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)CEC6ParameterPVModuleModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CEC6ParameterPVModuleModel_get_Adj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Adj_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Adj(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Adj_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Il(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Il_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Il(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Il_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Imp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Imp_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Imp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Imp_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Io(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Io_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Io(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Io_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Isc_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Isc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Isc_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Rs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Rs_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Rs(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Rs_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Rsh(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Rsh_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Rsh(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Rsh_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Vmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Vmp_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Vmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Vmp_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_Voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_Voc_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_Voc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_Voc_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_a(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_a_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_a(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_a_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_alpha_isc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_alpha_isc_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_alpha_isc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_alpha_isc_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_area(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_area_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_area(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_area_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_beta_voc(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_beta_voc_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_beta_voc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_beta_voc_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_gamma_pmp(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_gamma_pmp_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_gamma_pmp(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_gamma_pmp_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_height(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_height_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_height(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_height_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_opvoltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_opvoltage_aget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_opvoltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_opvoltage_aset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_standoff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_standoff_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_standoff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_standoff_nset, self->data_ptr);
}

static PyObject *
CEC6ParameterPVModuleModel_get_tnoct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pv6parmod_CEC6ParameterPVModuleModel_tnoct_nget, self->data_ptr);
}

static int
CEC6ParameterPVModuleModel_set_tnoct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pv6parmod_CEC6ParameterPVModuleModel_tnoct_nset, self->data_ptr);
}

static PyGetSetDef CEC6ParameterPVModuleModel_getset[] = {
{"Adj", (getter)CEC6ParameterPVModuleModel_get_Adj,(setter)CEC6ParameterPVModuleModel_set_Adj,
	PyDoc_STR("*float*: OC SC temp coeff adjustment [%]\n\n**Required:**\nTrue"),
 	NULL},
{"Il", (getter)CEC6ParameterPVModuleModel_get_Il,(setter)CEC6ParameterPVModuleModel_set_Il,
	PyDoc_STR("*float*: Light current [A]\n\n**Required:**\nTrue"),
 	NULL},
{"Imp", (getter)CEC6ParameterPVModuleModel_get_Imp,(setter)CEC6ParameterPVModuleModel_set_Imp,
	PyDoc_STR("*float*: Maximum power point current [A]\n\n**Required:**\nTrue"),
 	NULL},
{"Io", (getter)CEC6ParameterPVModuleModel_get_Io,(setter)CEC6ParameterPVModuleModel_set_Io,
	PyDoc_STR("*float*: Saturation current [A]\n\n**Required:**\nTrue"),
 	NULL},
{"Isc", (getter)CEC6ParameterPVModuleModel_get_Isc,(setter)CEC6ParameterPVModuleModel_set_Isc,
	PyDoc_STR("*float*: Short circuit current [A]\n\n**Required:**\nTrue"),
 	NULL},
{"Rs", (getter)CEC6ParameterPVModuleModel_get_Rs,(setter)CEC6ParameterPVModuleModel_set_Rs,
	PyDoc_STR("*float*: Series resistance [ohm]\n\n**Required:**\nTrue"),
 	NULL},
{"Rsh", (getter)CEC6ParameterPVModuleModel_get_Rsh,(setter)CEC6ParameterPVModuleModel_set_Rsh,
	PyDoc_STR("*float*: Shunt resistance [ohm]\n\n**Required:**\nTrue"),
 	NULL},
{"Vmp", (getter)CEC6ParameterPVModuleModel_get_Vmp,(setter)CEC6ParameterPVModuleModel_set_Vmp,
	PyDoc_STR("*float*: Maximum power point voltage [V]\n\n**Required:**\nTrue"),
 	NULL},
{"Voc", (getter)CEC6ParameterPVModuleModel_get_Voc,(setter)CEC6ParameterPVModuleModel_set_Voc,
	PyDoc_STR("*float*: Open circuit voltage [V]\n\n**Required:**\nTrue"),
 	NULL},
{"a", (getter)CEC6ParameterPVModuleModel_get_a,(setter)CEC6ParameterPVModuleModel_set_a,
	PyDoc_STR("*float*: Modified nonideality factor [1/V]\n\n**Required:**\nTrue"),
 	NULL},
{"alpha_isc", (getter)CEC6ParameterPVModuleModel_get_alpha_isc,(setter)CEC6ParameterPVModuleModel_set_alpha_isc,
	PyDoc_STR("*float*: Temp coeff of current at SC [A/'C]\n\n**Required:**\nTrue"),
 	NULL},
{"area", (getter)CEC6ParameterPVModuleModel_get_area,(setter)CEC6ParameterPVModuleModel_set_area,
	PyDoc_STR("*float*: Module area [m2]\n\n**Required:**\nTrue"),
 	NULL},
{"beta_voc", (getter)CEC6ParameterPVModuleModel_get_beta_voc,(setter)CEC6ParameterPVModuleModel_set_beta_voc,
	PyDoc_STR("*float*: Temp coeff of voltage at OC [V/'C]\n\n**Required:**\nTrue"),
 	NULL},
{"gamma_pmp", (getter)CEC6ParameterPVModuleModel_get_gamma_pmp,(setter)CEC6ParameterPVModuleModel_set_gamma_pmp,
	PyDoc_STR("*float*: Temp coeff of power at MP [%/'C]\n\n**Required:**\nTrue"),
 	NULL},
{"height", (getter)CEC6ParameterPVModuleModel_get_height,(setter)CEC6ParameterPVModuleModel_set_height,
	PyDoc_STR("*float*: System installation height [0/1]\n\n**Options:**\n0=less than 22ft, 1=more than 22ft\n\n**Constraints:**\nINTEGER,MIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"opvoltage", (getter)CEC6ParameterPVModuleModel_get_opvoltage,(setter)CEC6ParameterPVModuleModel_set_opvoltage,
	PyDoc_STR("*sequence*: Module operating voltage [Volt]\n\n**Required:**\nFalse for configuration with default inputs. May be required if a variable dependent on its value changes. Example: For the Detailed PV - Single Owner configuration, only Subarray 1 is enabled in the configuration defaults, so Subarray 2 inputs would not be required; if Subarray 2 is enabled, then Subarray 2 inputs is required."),
 	NULL},
{"standoff", (getter)CEC6ParameterPVModuleModel_get_standoff,(setter)CEC6ParameterPVModuleModel_set_standoff,
	PyDoc_STR("*float*: Mounting standoff option [0..6]\n\n**Options:**\n0=bipv, 1= >3.5in, 2=2.5-3.5in, 3=1.5-2.5in, 4=0.5-1.5in, 5= <0.5in, 6=ground/rack\n\n**Constraints:**\nINTEGER,MIN=0,MAX=6\n\n**Required:**\nFalse. Automatically set to 6 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"tnoct", (getter)CEC6ParameterPVModuleModel_get_tnoct,(setter)CEC6ParameterPVModuleModel_set_tnoct,
	PyDoc_STR("*float*: NOCT cell temperature ['C]\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject CEC6ParameterPVModuleModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pv6parmod.CEC6ParameterPVModuleModel",             /*tp_name*/
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
		CEC6ParameterPVModuleModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		CEC6ParameterPVModuleModel_getset,          /*tp_getset*/
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
Outputs_new(SAM_Pv6parmod data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pv6parmod", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pv6parmod", "Outputs")){
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
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Outputs_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_current(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Outputs_dc_current_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Outputs_dc_voltage_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Outputs_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pv6parmod_Outputs_tcell_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"dc", (getter)Outputs_get_dc,(setter)0,
	PyDoc_STR("*sequence*: DC power output [Watt]"),
 	NULL},
{"dc_current", (getter)Outputs_get_dc_current,(setter)0,
	PyDoc_STR("*sequence*: DC module current [Ampere]"),
 	NULL},
{"dc_voltage", (getter)Outputs_get_dc_voltage,(setter)0,
	PyDoc_STR("*sequence*: DC module voltage [Volt]"),
 	NULL},
{"eff", (getter)Outputs_get_eff,(setter)0,
	PyDoc_STR("*sequence*: Conversion efficiency [0..1]"),
 	NULL},
{"tcell", (getter)Outputs_get_tcell,(setter)0,
	PyDoc_STR("*sequence*: Cell temperature ['C]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pv6parmod.Outputs",             /*tp_name*/
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
 * Pv6parmod
 */

static PyTypeObject Pv6parmod_Type;

static CmodObject *
newPv6parmodObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pv6parmod_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* CEC6ParameterPVModuleModel_obj = CEC6ParameterPVModuleModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "CEC6ParameterPVModuleModel", CEC6ParameterPVModuleModel_obj);
	Py_DECREF(CEC6ParameterPVModuleModel_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Pv6parmod methods */

static void
Pv6parmod_dealloc(CmodObject *self)
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
Pv6parmod_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pv6parmod_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pv6parmod_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pv6parmod"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pv6parmod_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pv6parmod"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pv6parmod_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pv6parmod_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pv6parmod_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pv6parmod_methods[] = {
		{"execute",           (PyCFunction)Pv6parmod_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pv6parmod_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pv6parmod_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pv6parmod_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pv6parmod_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pv6parmod_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pv6parmod_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pv6parmod_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pv6parmod_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pv6parmod",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pv6parmod_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pv6parmod_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pv6parmod_getattro, /*tp_getattro*/
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
		Pv6parmod_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pv6parmod object */

static PyObject *
Pv6parmod_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPv6parmodObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pv6parmod_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPv6parmodObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pv6parmod_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPv6parmodObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pv6parmod", def) < 0) {
		Pv6parmod_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pv6parmod_from_existing(PyObject *self, PyObject *args)
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

	rv = newPv6parmodObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pv6parmod", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pv6parmodModule_methods[] = {
		{"new",             Pv6parmod_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pv6parmod")},
		{"default",             Pv6parmod_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pv6parmod\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pv6parmod_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pv6parmod\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pv6parmod_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pv6parmod\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pv6parmod");


static int
Pv6parmodModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pv6parmod_Type.tp_dict = PyDict_New();
	if (!Pv6parmod_Type.tp_dict) { goto fail; }

	/// Add the Weather type object to Pv6parmod_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pv6parmod_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the CEC6ParameterPVModuleModel type object to Pv6parmod_Type
	if (PyType_Ready(&CEC6ParameterPVModuleModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pv6parmod_Type.tp_dict,
				"CEC6ParameterPVModuleModel",
				(PyObject*)&CEC6ParameterPVModuleModel_Type);
	Py_DECREF(&CEC6ParameterPVModuleModel_Type);

	/// Add the Outputs type object to Pv6parmod_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pv6parmod_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pv6parmod type object to the module
	if (PyType_Ready(&Pv6parmod_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pv6parmod",
				(PyObject*)&Pv6parmod_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pv6parmodModule_slots[] = {
		{Py_mod_exec, Pv6parmodModule_exec},
		{0, NULL},
};

static struct PyModuleDef Pv6parmodModule = {
		PyModuleDef_HEAD_INIT,
		"Pv6parmod",
		module_doc,
		0,
		Pv6parmodModule_methods,
		Pv6parmodModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pv6parmod(void)
{
	return PyModuleDef_Init(&Pv6parmodModule);
}