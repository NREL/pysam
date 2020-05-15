#include <Python.h>

#include <SAM_CbEmpiricalHceHeatLoss.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Hce Group
 */ 

static PyTypeObject Hce_Type;

static PyObject *
Hce_new(SAM_CbEmpiricalHceHeatLoss data_ptr)
{
	PyObject* new_obj = Hce_Type.tp_alloc(&Hce_Type,0);

	VarGroupObject* Hce_obj = (VarGroupObject*)new_obj;

	Hce_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Hce methods */

static PyObject *
Hce_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbEmpiricalHceHeatLoss", "Hce")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Hce_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Hce_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Hce_methods[] = {
		{"assign",            (PyCFunction)Hce_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Hce_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Hce_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Hce_get_HCEFrac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCEFrac_aget, self->data_ptr);
}

static int
Hce_set_HCEFrac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCEFrac_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A0(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A0_aget, self->data_ptr);
}

static int
Hce_set_HCE_A0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A0_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A1_aget, self->data_ptr);
}

static int
Hce_set_HCE_A1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A1_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A2_aget, self->data_ptr);
}

static int
Hce_set_HCE_A2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A2_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A3_aget, self->data_ptr);
}

static int
Hce_set_HCE_A3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A3_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A4(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A4_aget, self->data_ptr);
}

static int
Hce_set_HCE_A4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A4_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A5(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A5_aget, self->data_ptr);
}

static int
Hce_set_HCE_A5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A5_aset, self->data_ptr);
}

static PyObject *
Hce_get_HCE_A6(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A6_aget, self->data_ptr);
}

static int
Hce_set_HCE_A6(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_HCE_A6_aset, self->data_ptr);
}

static PyObject *
Hce_get_PerfFac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_PerfFac_aget, self->data_ptr);
}

static int
Hce_set_PerfFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_PerfFac_aset, self->data_ptr);
}

static PyObject *
Hce_get_RefMirrAper(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Hce_RefMirrAper_aget, self->data_ptr);
}

static int
Hce_set_RefMirrAper(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_RefMirrAper_aset, self->data_ptr);
}

static PyObject *
Hce_get_SfInTempD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Hce_SfInTempD_nget, self->data_ptr);
}

static int
Hce_set_SfInTempD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_SfInTempD_nset, self->data_ptr);
}

static PyObject *
Hce_get_SfOutTempD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Hce_SfOutTempD_nget, self->data_ptr);
}

static int
Hce_set_SfOutTempD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_SfOutTempD_nset, self->data_ptr);
}

static PyObject *
Hce_get_ui_reference_ambient_temperature(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Hce_ui_reference_ambient_temperature_nget, self->data_ptr);
}

static int
Hce_set_ui_reference_ambient_temperature(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_ui_reference_ambient_temperature_nset, self->data_ptr);
}

static PyObject *
Hce_get_ui_reference_direct_normal_irradiance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Hce_ui_reference_direct_normal_irradiance_nget, self->data_ptr);
}

static int
Hce_set_ui_reference_direct_normal_irradiance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_ui_reference_direct_normal_irradiance_nset, self->data_ptr);
}

static PyObject *
Hce_get_ui_reference_wind_speed(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Hce_ui_reference_wind_speed_nget, self->data_ptr);
}

static int
Hce_set_ui_reference_wind_speed(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_CbEmpiricalHceHeatLoss_Hce_ui_reference_wind_speed_nset, self->data_ptr);
}

static PyGetSetDef Hce_getset[] = {
{"HCEFrac", (getter)Hce_get_HCEFrac,(setter)Hce_set_HCEFrac,
	PyDoc_STR("*sequence*: Fraction of field that is this type of HCE\n\n*Required*: True"),
 	NULL},
{"HCE_A0", (getter)Hce_get_HCE_A0,(setter)Hce_set_HCE_A0,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"HCE_A1", (getter)Hce_get_HCE_A1,(setter)Hce_set_HCE_A1,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"HCE_A2", (getter)Hce_get_HCE_A2,(setter)Hce_set_HCE_A2,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"HCE_A3", (getter)Hce_get_HCE_A3,(setter)Hce_set_HCE_A3,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"HCE_A4", (getter)Hce_get_HCE_A4,(setter)Hce_set_HCE_A4,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"HCE_A5", (getter)Hce_get_HCE_A5,(setter)Hce_set_HCE_A5,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"HCE_A6", (getter)Hce_get_HCE_A6,(setter)Hce_set_HCE_A6,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"PerfFac", (getter)Hce_get_PerfFac,(setter)Hce_set_PerfFac,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"RefMirrAper", (getter)Hce_get_RefMirrAper,(setter)Hce_set_RefMirrAper,
	PyDoc_STR("*sequence*: label\n\n*Required*: True"),
 	NULL},
{"SfInTempD", (getter)Hce_get_SfInTempD,(setter)Hce_set_SfInTempD,
	PyDoc_STR("*float*: Solar Field Inlet Temp at design [C]\n\n*Required*: True"),
 	NULL},
{"SfOutTempD", (getter)Hce_get_SfOutTempD,(setter)Hce_set_SfOutTempD,
	PyDoc_STR("*float*: Solar Field Outlet Temp at design [C]\n\n*Required*: True"),
 	NULL},
{"ui_reference_ambient_temperature", (getter)Hce_get_ui_reference_ambient_temperature,(setter)Hce_set_ui_reference_ambient_temperature,
	PyDoc_STR("*float*: Ambient temp at design heat loss [C]\n\n*Required*: True"),
 	NULL},
{"ui_reference_direct_normal_irradiance", (getter)Hce_get_ui_reference_direct_normal_irradiance,(setter)Hce_set_ui_reference_direct_normal_irradiance,
	PyDoc_STR("*float*: DNI at design [W/m2]\n\n*Required*: True"),
 	NULL},
{"ui_reference_wind_speed", (getter)Hce_get_ui_reference_wind_speed,(setter)Hce_set_ui_reference_wind_speed,
	PyDoc_STR("*float*: Wind speed for design heat loss [m/s]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Hce_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbEmpiricalHceHeatLoss.Hce",             /*tp_name*/
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
		Hce_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Hce_getset,          /*tp_getset*/
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
Outputs_new(SAM_CbEmpiricalHceHeatLoss data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "CbEmpiricalHceHeatLoss", "Outputs")){
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
Outputs_get_HL(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_CbEmpiricalHceHeatLoss_Outputs_HL_aget, self->data_ptr);
}

static PyObject *
Outputs_get_HL_weighted(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Outputs_HL_weighted_nget, self->data_ptr);
}

static PyObject *
Outputs_get_HL_weighted_m2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_CbEmpiricalHceHeatLoss_Outputs_HL_weighted_m2_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"HL", (getter)Outputs_get_HL,(setter)0,
	PyDoc_STR("*sequence*: HCE Heat Losses [W/m]"),
 	NULL},
{"HL_weighted", (getter)Outputs_get_HL_weighted,(setter)0,
	PyDoc_STR("*float*: Weighted HCE Heat Loss [W/m]"),
 	NULL},
{"HL_weighted_m2", (getter)Outputs_get_HL_weighted_m2,(setter)0,
	PyDoc_STR("*float*: Weighted HCE Heat Loss per Aperture Area [W/m2]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbEmpiricalHceHeatLoss.Outputs",             /*tp_name*/
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
 * CbEmpiricalHceHeatLoss
 */

static PyTypeObject CbEmpiricalHceHeatLoss_Type;

static CmodObject *
newCbEmpiricalHceHeatLossObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &CbEmpiricalHceHeatLoss_Type);

	PySAM_TECH_ATTR()

	PyObject* Hce_obj = Hce_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Hce", Hce_obj);
	Py_DECREF(Hce_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* CbEmpiricalHceHeatLoss methods */

static void
CbEmpiricalHceHeatLoss_dealloc(CmodObject *self)
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
CbEmpiricalHceHeatLoss_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_CbEmpiricalHceHeatLoss_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CbEmpiricalHceHeatLoss_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "CbEmpiricalHceHeatLoss"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
CbEmpiricalHceHeatLoss_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
CbEmpiricalHceHeatLoss_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef CbEmpiricalHceHeatLoss_methods[] = {
		{"execute",            (PyCFunction)CbEmpiricalHceHeatLoss_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)CbEmpiricalHceHeatLoss_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'hce': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)CbEmpiricalHceHeatLoss_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)CbEmpiricalHceHeatLoss_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
CbEmpiricalHceHeatLoss_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
CbEmpiricalHceHeatLoss_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject CbEmpiricalHceHeatLoss_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"CbEmpiricalHceHeatLoss",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)CbEmpiricalHceHeatLoss_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)CbEmpiricalHceHeatLoss_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)CbEmpiricalHceHeatLoss_getattro, /*tp_getattro*/
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
		CbEmpiricalHceHeatLoss_methods,      /*tp_methods*/
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


/* Function of no arguments returning new CbEmpiricalHceHeatLoss object */

static PyObject *
CbEmpiricalHceHeatLoss_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newCbEmpiricalHceHeatLossObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CbEmpiricalHceHeatLoss_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCbEmpiricalHceHeatLossObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
CbEmpiricalHceHeatLoss_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newCbEmpiricalHceHeatLossObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CbEmpiricalHceHeatLoss", def);

	return (PyObject *)rv;
}

static PyObject *
CbEmpiricalHceHeatLoss_from_existing(PyObject *self, PyObject *args)
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

	rv = newCbEmpiricalHceHeatLossObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "CbEmpiricalHceHeatLoss", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef CbEmpiricalHceHeatLossModule_methods[] = {
		{"new",             CbEmpiricalHceHeatLoss_new,         METH_VARARGS,
				PyDoc_STR("new() -> CbEmpiricalHceHeatLoss")},
		{"default",             CbEmpiricalHceHeatLoss_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> CbEmpiricalHceHeatLoss\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             CbEmpiricalHceHeatLoss_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> CbEmpiricalHceHeatLoss\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   CbEmpiricalHceHeatLoss_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> CbEmpiricalHceHeatLoss\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "CbEmpiricalHceHeatLoss");


static int
CbEmpiricalHceHeatLossModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	CbEmpiricalHceHeatLoss_Type.tp_dict = PyDict_New();
	if (!CbEmpiricalHceHeatLoss_Type.tp_dict) { goto fail; }

	/// Add the Hce type object to CbEmpiricalHceHeatLoss_Type
	if (PyType_Ready(&Hce_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbEmpiricalHceHeatLoss_Type.tp_dict,
				"Hce",
				(PyObject*)&Hce_Type);
	Py_DECREF(&Hce_Type);

	/// Add the Outputs type object to CbEmpiricalHceHeatLoss_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(CbEmpiricalHceHeatLoss_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the CbEmpiricalHceHeatLoss type object to the module
	if (PyType_Ready(&CbEmpiricalHceHeatLoss_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"CbEmpiricalHceHeatLoss",
				(PyObject*)&CbEmpiricalHceHeatLoss_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot CbEmpiricalHceHeatLossModule_slots[] = {
		{Py_mod_exec, CbEmpiricalHceHeatLossModule_exec},
		{0, NULL},
};

static struct PyModuleDef CbEmpiricalHceHeatLossModule = {
		PyModuleDef_HEAD_INIT,
		"CbEmpiricalHceHeatLoss",
		module_doc,
		0,
		CbEmpiricalHceHeatLossModule_methods,
		CbEmpiricalHceHeatLossModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_CbEmpiricalHceHeatLoss(void)
{
	return PyModuleDef_Init(&CbEmpiricalHceHeatLossModule);
}