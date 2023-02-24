#include <Python.h>

#include <SAM_Pvwattsv1Poa.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Weather Group
 */ 

static PyTypeObject Weather_Type;

static PyObject *
Weather_new(SAM_Pvwattsv1Poa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv1Poa", "Weather")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv1Poa", "Weather")){
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
Weather_get_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_beam_aget, self->data_ptr);
}

static int
Weather_set_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_beam_aset, self->data_ptr);
}

static PyObject *
Weather_get_incidence(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_incidence_aget, self->data_ptr);
}

static int
Weather_set_incidence(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_incidence_aset, self->data_ptr);
}

static PyObject *
Weather_get_poa_beam(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_poa_beam_aget, self->data_ptr);
}

static int
Weather_set_poa_beam(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_poa_beam_aset, self->data_ptr);
}

static PyObject *
Weather_get_poa_gnddiff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_poa_gnddiff_aget, self->data_ptr);
}

static int
Weather_set_poa_gnddiff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_poa_gnddiff_aset, self->data_ptr);
}

static PyObject *
Weather_get_poa_skydiff(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_poa_skydiff_aget, self->data_ptr);
}

static int
Weather_set_poa_skydiff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_poa_skydiff_aset, self->data_ptr);
}

static PyObject *
Weather_get_tdry(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_tdry_aget, self->data_ptr);
}

static int
Weather_set_tdry(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_tdry_aset, self->data_ptr);
}

static PyObject *
Weather_get_wspd(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Weather_wspd_aget, self->data_ptr);
}

static int
Weather_set_wspd(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvwattsv1Poa_Weather_wspd_aset, self->data_ptr);
}

static PyGetSetDef Weather_getset[] = {
{"beam", (getter)Weather_get_beam,(setter)Weather_set_beam,
	PyDoc_STR("*sequence*: Direct normal radiation [W/m2]\n\n**Required:**\nTrue"),
 	NULL},
{"incidence", (getter)Weather_get_incidence,(setter)Weather_set_incidence,
	PyDoc_STR("*sequence*: Incidence angle to surface [deg]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"poa_beam", (getter)Weather_get_poa_beam,(setter)Weather_set_poa_beam,
	PyDoc_STR("*sequence*: Incident direct normal radiation [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"poa_gnddiff", (getter)Weather_get_poa_gnddiff,(setter)Weather_set_poa_gnddiff,
	PyDoc_STR("*sequence*: Incident ground diffuse irradiance [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"poa_skydiff", (getter)Weather_get_poa_skydiff,(setter)Weather_set_poa_skydiff,
	PyDoc_STR("*sequence*: Incident sky diffuse radiation [W/m2]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"tdry", (getter)Weather_get_tdry,(setter)Weather_set_tdry,
	PyDoc_STR("*sequence*: Dry bulb temperature ['C]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
{"wspd", (getter)Weather_get_wspd,(setter)Weather_set_wspd,
	PyDoc_STR("*sequence*: Wind speed [m/s]\n\n**Constraints:**\nLENGTH_EQUAL=beam\n\n**Required:**\nTrue"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Weather_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1Poa.Weather",             /*tp_name*/
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
 * PVWatts Group
 */ 

static PyTypeObject PVWatts_Type;

static PyObject *
PVWatts_new(SAM_Pvwattsv1Poa data_ptr)
{
	PyObject* new_obj = PVWatts_Type.tp_alloc(&PVWatts_Type,0);

	VarGroupObject* PVWatts_obj = (VarGroupObject*)new_obj;

	PVWatts_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* PVWatts methods */

static PyObject *
PVWatts_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv1Poa", "PVWatts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVWatts_replace(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}
	PyTypeObject* tp = &PVWatts_Type;

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv1Poa", "PVWatts")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
PVWatts_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &PVWatts_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef PVWatts_methods[] = {
		{"assign",            (PyCFunction)PVWatts_assign,  METH_VARARGS,
			PyDoc_STR("assign(dict) -> None\n Assign attributes from dictionary, overwriting but not removing values.\n\n``PVWatts_vals = { var: val, ...}``")},
		{"replace",            (PyCFunction)PVWatts_replace,  METH_VARARGS,
			PyDoc_STR("replace(dict) -> None\n Replace attributes from dictionary, unassigning values not present in input ``dict``.\n\n``PVWatts_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)PVWatts_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
PVWatts_get_derate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_derate_nget, self->data_ptr);
}

static int
PVWatts_set_derate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_derate_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_gamma(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_gamma_nget, self->data_ptr);
}

static int
PVWatts_set_gamma(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_gamma_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_inoct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_inoct_nget, self->data_ptr);
}

static int
PVWatts_set_inoct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_inoct_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_inv_eff(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_inv_eff_nget, self->data_ptr);
}

static int
PVWatts_set_inv_eff(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_inv_eff_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_step(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_step_nget, self->data_ptr);
}

static int
PVWatts_set_step(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_step_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_system_size(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_system_size_nget, self->data_ptr);
}

static int
PVWatts_set_system_size(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_system_size_nset, self->data_ptr);
}

static PyObject *
PVWatts_get_t_ref(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvwattsv1Poa_PVWatts_t_ref_nget, self->data_ptr);
}

static int
PVWatts_set_t_ref(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvwattsv1Poa_PVWatts_t_ref_nset, self->data_ptr);
}

static PyGetSetDef PVWatts_getset[] = {
{"derate", (getter)PVWatts_get_derate,(setter)PVWatts_set_derate,
	PyDoc_STR("*float*: System derate value [frac]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nTrue"),
 	NULL},
{"gamma", (getter)PVWatts_get_gamma,(setter)PVWatts_set_gamma,
	PyDoc_STR("*float*: Max power temperature coefficient [%/'C]\n\n**Required:**\nFalse. Automatically set to -0.5 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inoct", (getter)PVWatts_get_inoct,(setter)PVWatts_set_inoct,
	PyDoc_STR("*float*: Nominal operating cell temperature ['C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 45.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"inv_eff", (getter)PVWatts_get_inv_eff,(setter)PVWatts_set_inv_eff,
	PyDoc_STR("*float*: Inverter efficiency at rated power [frac]\n\n**Constraints:**\nMIN=0,MAX=1\n\n**Required:**\nFalse. Automatically set to 0.92 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"step", (getter)PVWatts_get_step,(setter)PVWatts_set_step,
	PyDoc_STR("*float*: Time step of input data [sec]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 3600 if not assigned explicitly or loaded from defaults."),
 	NULL},
{"system_size", (getter)PVWatts_get_system_size,(setter)PVWatts_set_system_size,
	PyDoc_STR("*float*: Nameplate capacity [kW]\n\n**Constraints:**\nMIN=0.5,MAX=100000\n\n**Required:**\nTrue"),
 	NULL},
{"t_ref", (getter)PVWatts_get_t_ref,(setter)PVWatts_set_t_ref,
	PyDoc_STR("*float*: Reference cell temperature ['C]\n\n**Constraints:**\nPOSITIVE\n\n**Required:**\nFalse. Automatically set to 25.0 if not assigned explicitly or loaded from defaults."),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject PVWatts_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1Poa.PVWatts",             /*tp_name*/
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
		PVWatts_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		PVWatts_getset,          /*tp_getset*/
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
Outputs_new(SAM_Pvwattsv1Poa data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvwattsv1Poa", "Outputs")){
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

	if (!PySAM_replace_from_dict(tp, self->data_ptr, dict, "Pvwattsv1Poa", "Outputs")){
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
Outputs_get_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Outputs_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Outputs_dc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_tcell(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvwattsv1Poa_Outputs_tcell_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	PyDoc_STR("*sequence*: AC system output [kWhac]"),
 	NULL},
{"dc", (getter)Outputs_get_dc,(setter)0,
	PyDoc_STR("*sequence*: DC array output [kWhdc]"),
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
		"Pvwattsv1Poa.Outputs",             /*tp_name*/
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
 * Pvwattsv1Poa
 */

static PyTypeObject Pvwattsv1Poa_Type;

static CmodObject *
newPvwattsv1PoaObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvwattsv1Poa_Type);

	PySAM_TECH_ATTR()

	PyObject* Weather_obj = Weather_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Weather", Weather_obj);
	Py_DECREF(Weather_obj);

	PyObject* PVWatts_obj = PVWatts_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "PVWatts", PVWatts_obj);
	Py_DECREF(PVWatts_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Pvwattsv1Poa methods */

static void
Pvwattsv1Poa_dealloc(CmodObject *self)
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
Pvwattsv1Poa_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvwattsv1Poa_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvwattsv1Poa_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv1Poa"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv1Poa_replace(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_replace_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvwattsv1Poa"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Pvwattsv1Poa_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvwattsv1Poa_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyObject *
Pvwattsv1Poa_unassign(CmodObject *self, PyObject *args)
{
	return Cmod_unassign(self, args);
}

static PyMethodDef Pvwattsv1Poa_methods[] = {
		{"execute",           (PyCFunction)Pvwattsv1Poa_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvwattsv1Poa_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"replace",            (PyCFunction)Pvwattsv1Poa_replace,  METH_VARARGS,
				PyDoc_STR("replace(dict) -> None\n Replace attributes from nested dictionary, except for Outputs. Unassigns all values in each Group then assigns from the input dict.\n\n``nested_dict = { 'weather': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvwattsv1Poa_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvwattsv1Poa_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{"unassign",          (PyCFunction)Pvwattsv1Poa_unassign, METH_VARARGS,
				PyDoc_STR("unassign(name) -> None\n Unassign a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvwattsv1Poa_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvwattsv1Poa_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvwattsv1Poa_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvwattsv1Poa",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvwattsv1Poa_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvwattsv1Poa_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvwattsv1Poa_getattro, /*tp_getattro*/
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
		Pvwattsv1Poa_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvwattsv1Poa object */

static PyObject *
Pvwattsv1Poa_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvwattsv1PoaObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv1Poa_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv1PoaObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv1Poa_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvwattsv1PoaObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	if (PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv1Poa", def) < 0) {
		Pvwattsv1Poa_dealloc(rv);
		return NULL;
	}
	return (PyObject *)rv;
}

static PyObject *
Pvwattsv1Poa_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvwattsv1PoaObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvwattsv1Poa", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef Pvwattsv1PoaModule_methods[] = {
		{"new",             Pvwattsv1Poa_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvwattsv1Poa")},
		{"default",             Pvwattsv1Poa_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvwattsv1Poa\n\nLoad defaults for the configuration ``config``. Available configurations are:\n\n- None\n\n.. note::\n\n	Some inputs do not have default values and may be assigned a value from the variable's **Required** attribute. See variable attribute descriptions below.")},
		{"wrap",             Pvwattsv1Poa_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvwattsv1Poa\n\nLoad data from a PySSC object.\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap()``")},
		{"from_existing",   Pvwattsv1Poa_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvwattsv1Poa\n\nShare data with an existing PySAM class. If ``optional config`` is a valid configuration name, load the module's defaults for that configuration.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pvwattsv1Poa");


static int
Pvwattsv1PoaModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvwattsv1Poa_Type.tp_dict = PyDict_New();
	if (!Pvwattsv1Poa_Type.tp_dict) { goto fail; }

	/// Add the Weather type object to Pvwattsv1Poa_Type
	if (PyType_Ready(&Weather_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv1Poa_Type.tp_dict,
				"Weather",
				(PyObject*)&Weather_Type);
	Py_DECREF(&Weather_Type);

	/// Add the PVWatts type object to Pvwattsv1Poa_Type
	if (PyType_Ready(&PVWatts_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv1Poa_Type.tp_dict,
				"PVWatts",
				(PyObject*)&PVWatts_Type);
	Py_DECREF(&PVWatts_Type);

	/// Add the Outputs type object to Pvwattsv1Poa_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvwattsv1Poa_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvwattsv1Poa type object to the module
	if (PyType_Ready(&Pvwattsv1Poa_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvwattsv1Poa",
				(PyObject*)&Pvwattsv1Poa_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot Pvwattsv1PoaModule_slots[] = {
		{Py_mod_exec, Pvwattsv1PoaModule_exec},
		{0, NULL},
};

static struct PyModuleDef Pvwattsv1PoaModule = {
		PyModuleDef_HEAD_INIT,
		"Pvwattsv1Poa",
		module_doc,
		0,
		Pvwattsv1PoaModule_methods,
		Pvwattsv1PoaModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvwattsv1Poa(void)
{
	return PyModuleDef_Init(&Pvwattsv1PoaModule);
}