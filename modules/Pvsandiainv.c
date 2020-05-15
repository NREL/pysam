#include <Python.h>

#include <SAM_Pvsandiainv.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * SandiaInverterModel Group
 */ 

static PyTypeObject SandiaInverterModel_Type;

static PyObject *
SandiaInverterModel_new(SAM_Pvsandiainv data_ptr)
{
	PyObject* new_obj = SandiaInverterModel_Type.tp_alloc(&SandiaInverterModel_Type,0);

	VarGroupObject* SandiaInverterModel_obj = (VarGroupObject*)new_obj;

	SandiaInverterModel_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* SandiaInverterModel methods */

static PyObject *
SandiaInverterModel_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsandiainv", "SandiaInverterModel")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
SandiaInverterModel_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &SandiaInverterModel_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef SandiaInverterModel_methods[] = {
		{"assign",            (PyCFunction)SandiaInverterModel_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``SandiaInverterModel_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)SandiaInverterModel_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
SandiaInverterModel_get_c0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_c0_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_c0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_c0_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_c1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_c1_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_c1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_c1_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_c2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_c2_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_c2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_c2_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_c3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_c3_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_c3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_c3_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_dc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_SandiaInverterModel_dc_aget, self->data_ptr);
}

static int
SandiaInverterModel_set_dc(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsandiainv_SandiaInverterModel_dc_aset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_dc_voltage(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_SandiaInverterModel_dc_voltage_aget, self->data_ptr);
}

static int
SandiaInverterModel_set_dc_voltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_array_setter(value, SAM_Pvsandiainv_SandiaInverterModel_dc_voltage_aset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_paco_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_paco_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_pdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_pdco_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_pdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_pdco_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_pntare(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_pntare_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_pntare(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_pntare_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_pso(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_pso_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_pso(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_pso_nset, self->data_ptr);
}

static PyObject *
SandiaInverterModel_get_vdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_Pvsandiainv_SandiaInverterModel_vdco_nget, self->data_ptr);
}

static int
SandiaInverterModel_set_vdco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_Pvsandiainv_SandiaInverterModel_vdco_nset, self->data_ptr);
}

static PyGetSetDef SandiaInverterModel_getset[] = {
{"c0", (getter)SandiaInverterModel_get_c0,(setter)SandiaInverterModel_set_c0,
	PyDoc_STR("*float*: C0: Defines parabolic curvature of relationship between ac power and dc power at reference conditions [1/W]\n\n*Required*: True"),
 	NULL},
{"c1", (getter)SandiaInverterModel_get_c1,(setter)SandiaInverterModel_set_c1,
	PyDoc_STR("*float*: C1: Parameter allowing Pdco to vary linearly with dc voltage input [1/V]\n\n*Required*: True"),
 	NULL},
{"c2", (getter)SandiaInverterModel_get_c2,(setter)SandiaInverterModel_set_c2,
	PyDoc_STR("*float*: C2: Parameter allowing Pso to vary linearly with dc voltage input  [1/V]\n\n*Required*: True"),
 	NULL},
{"c3", (getter)SandiaInverterModel_get_c3,(setter)SandiaInverterModel_set_c3,
	PyDoc_STR("*float*: C3: Parameter allowing C0 to vary linearly with dc voltage input [1/V]\n\n*Required*: True"),
 	NULL},
{"dc", (getter)SandiaInverterModel_get_dc,(setter)SandiaInverterModel_set_dc,
	PyDoc_STR("*sequence*: DC power input to inverter [Watt]\n\n*Required*: True"),
 	NULL},
{"dc_voltage", (getter)SandiaInverterModel_get_dc_voltage,(setter)SandiaInverterModel_set_dc_voltage,
	PyDoc_STR("*sequence*: DC voltage input to inverter [Volt]\n\n*Constraints*: LENGTH_EQUAL=dc\n\n*Required*: True"),
 	NULL},
{"paco", (getter)SandiaInverterModel_get_paco,(setter)SandiaInverterModel_set_paco,
	PyDoc_STR("*float*: Max AC power rating [Wac]\n\n*Required*: True"),
 	NULL},
{"pdco", (getter)SandiaInverterModel_get_pdco,(setter)SandiaInverterModel_set_pdco,
	PyDoc_STR("*float*: DC power level at which Paco is achieved [Wdc]\n\n*Required*: True"),
 	NULL},
{"pntare", (getter)SandiaInverterModel_get_pntare,(setter)SandiaInverterModel_set_pntare,
	PyDoc_STR("*float*: Parasitic AC consumption [Wac]\n\n*Required*: True"),
 	NULL},
{"pso", (getter)SandiaInverterModel_get_pso,(setter)SandiaInverterModel_set_pso,
	PyDoc_STR("*float*: DC power level required to start inversion [Wdc]\n\n*Required*: True"),
 	NULL},
{"vdco", (getter)SandiaInverterModel_get_vdco,(setter)SandiaInverterModel_set_vdco,
	PyDoc_STR("*float*: DV voltage level at which Paco is achieved [Volt]\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject SandiaInverterModel_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsandiainv.SandiaInverterModel",             /*tp_name*/
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
		SandiaInverterModel_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		SandiaInverterModel_getset,          /*tp_getset*/
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
Outputs_new(SAM_Pvsandiainv data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Pvsandiainv", "Outputs")){
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
Outputs_get_ac(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_ac_aget, self->data_ptr);
}

static PyObject *
Outputs_get_acpar(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_acpar_aget, self->data_ptr);
}

static PyObject *
Outputs_get_cliploss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_cliploss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_eff_inv(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_eff_inv_aget, self->data_ptr);
}

static PyObject *
Outputs_get_ntloss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_ntloss_aget, self->data_ptr);
}

static PyObject *
Outputs_get_plr(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_plr_aget, self->data_ptr);
}

static PyObject *
Outputs_get_soloss(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Pvsandiainv_Outputs_soloss_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"ac", (getter)Outputs_get_ac,(setter)0,
	PyDoc_STR("*sequence*: AC power output [Wac]"),
 	NULL},
{"acpar", (getter)Outputs_get_acpar,(setter)0,
	PyDoc_STR("*sequence*: AC parasitic power [Wac]"),
 	NULL},
{"cliploss", (getter)Outputs_get_cliploss,(setter)0,
	PyDoc_STR("*sequence*: Power loss due to clipping (Wac) [Wac]"),
 	NULL},
{"eff_inv", (getter)Outputs_get_eff_inv,(setter)0,
	PyDoc_STR("*sequence*: Conversion efficiency [0..1]"),
 	NULL},
{"ntloss", (getter)Outputs_get_ntloss,(setter)0,
	PyDoc_STR("*sequence*: Power loss due to night time tare loss (Wac) [Wac]"),
 	NULL},
{"plr", (getter)Outputs_get_plr,(setter)0,
	PyDoc_STR("*sequence*: Part load ratio [0..1]"),
 	NULL},
{"soloss", (getter)Outputs_get_soloss,(setter)0,
	PyDoc_STR("*sequence*: Power loss due to operating power consumption (Wac) [Wac]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsandiainv.Outputs",             /*tp_name*/
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
 * Pvsandiainv
 */

static PyTypeObject Pvsandiainv_Type;

static CmodObject *
newPvsandiainvObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &Pvsandiainv_Type);

	PySAM_TECH_ATTR()

	PyObject* SandiaInverterModel_obj = SandiaInverterModel_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "SandiaInverterModel", SandiaInverterModel_obj);
	Py_DECREF(SandiaInverterModel_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* Pvsandiainv methods */

static void
Pvsandiainv_dealloc(CmodObject *self)
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
Pvsandiainv_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Pvsandiainv_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvsandiainv_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "Pvsandiainv"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Pvsandiainv_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
Pvsandiainv_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef Pvsandiainv_methods[] = {
		{"execute",            (PyCFunction)Pvsandiainv_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Pvsandiainv_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Sandia Inverter Model': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)Pvsandiainv_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)Pvsandiainv_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Pvsandiainv_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Pvsandiainv_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Pvsandiainv_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Pvsandiainv",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Pvsandiainv_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Pvsandiainv_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Pvsandiainv_getattro, /*tp_getattro*/
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
		Pvsandiainv_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Pvsandiainv object */

static PyObject *
Pvsandiainv_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newPvsandiainvObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvsandiainv_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvsandiainvObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
Pvsandiainv_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newPvsandiainvObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvsandiainv", def);

	return (PyObject *)rv;
}

static PyObject *
Pvsandiainv_from_existing(PyObject *self, PyObject *args)
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

	rv = newPvsandiainvObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "Pvsandiainv", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef PvsandiainvModule_methods[] = {
		{"new",             Pvsandiainv_new,         METH_VARARGS,
				PyDoc_STR("new() -> Pvsandiainv")},
		{"default",             Pvsandiainv_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> Pvsandiainv\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             Pvsandiainv_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> Pvsandiainv\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   Pvsandiainv_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> Pvsandiainv\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Pvsandiainv");


static int
PvsandiainvModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	Pvsandiainv_Type.tp_dict = PyDict_New();
	if (!Pvsandiainv_Type.tp_dict) { goto fail; }

	/// Add the SandiaInverterModel type object to Pvsandiainv_Type
	if (PyType_Ready(&SandiaInverterModel_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsandiainv_Type.tp_dict,
				"SandiaInverterModel",
				(PyObject*)&SandiaInverterModel_Type);
	Py_DECREF(&SandiaInverterModel_Type);

	/// Add the Outputs type object to Pvsandiainv_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Pvsandiainv_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Pvsandiainv type object to the module
	if (PyType_Ready(&Pvsandiainv_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Pvsandiainv",
				(PyObject*)&Pvsandiainv_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot PvsandiainvModule_slots[] = {
		{Py_mod_exec, PvsandiainvModule_exec},
		{0, NULL},
};

static struct PyModuleDef PvsandiainvModule = {
		PyModuleDef_HEAD_INIT,
		"Pvsandiainv",
		module_doc,
		0,
		PvsandiainvModule_methods,
		PvsandiainvModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Pvsandiainv(void)
{
	return PyModuleDef_Init(&PvsandiainvModule);
}