#include <Python.h>

#include <SAM_InvCecCg.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Common Group
 */ 

static PyTypeObject Common_Type;

static PyObject *
Common_new(SAM_InvCecCg data_ptr)
{
	PyObject* new_obj = Common_Type.tp_alloc(&Common_Type,0);

	VarGroupObject* Common_obj = (VarGroupObject*)new_obj;

	Common_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Common methods */

static PyObject *
Common_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "InvCecCg", "Common")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Common_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Common_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Common_methods[] = {
		{"assign",            (PyCFunction)Common_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Common_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Common_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Common_get_inv_cec_cg_paco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Common_inv_cec_cg_paco_nget, self->data_ptr);
}

static int
Common_set_inv_cec_cg_paco(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_InvCecCg_Common_inv_cec_cg_paco_nset, self->data_ptr);
}

static PyObject *
Common_get_inv_cec_cg_sample_power_units(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Common_inv_cec_cg_sample_power_units_nget, self->data_ptr);
}

static int
Common_set_inv_cec_cg_sample_power_units(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_InvCecCg_Common_inv_cec_cg_sample_power_units_nset, self->data_ptr);
}

static PyObject *
Common_get_inv_cec_cg_test_samples(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_InvCecCg_Common_inv_cec_cg_test_samples_mget, self->data_ptr);
}

static int
Common_set_inv_cec_cg_test_samples(VarGroupObject *self, PyObject *value, void *closure)
{
		return PySAM_matrix_setter(value, SAM_InvCecCg_Common_inv_cec_cg_test_samples_mset, self->data_ptr);
}

static PyGetSetDef Common_getset[] = {
{"inv_cec_cg_paco", (getter)Common_get_inv_cec_cg_paco,(setter)Common_set_inv_cec_cg_paco,
	PyDoc_STR("*float*: Rated max output [W]\n\n*Required*: True"),
 	NULL},
{"inv_cec_cg_sample_power_units", (getter)Common_get_inv_cec_cg_sample_power_units,(setter)Common_set_inv_cec_cg_sample_power_units,
	PyDoc_STR("*float*: Sample data units for power output [0=W,1=kW]\n\n*Constraints*: INTEGER,MIN=0,MAX=1\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"inv_cec_cg_test_samples", (getter)Common_get_inv_cec_cg_test_samples,(setter)Common_set_inv_cec_cg_test_samples,
	PyDoc_STR("*sequence[sequence]*: Sample data\n\n*Required*: True"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Common_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"InvCecCg.Common",             /*tp_name*/
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
		Common_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Common_getset,          /*tp_getset*/
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
Outputs_new(SAM_InvCecCg data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "InvCecCg", "Outputs")){
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
Outputs_get_Pdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_Pdco_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Pso(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_Pso_nget, self->data_ptr);
}

static PyObject *
Outputs_get_Vdco(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_Vdco_nget, self->data_ptr);
}

static PyObject *
Outputs_get_c0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_c0_nget, self->data_ptr);
}

static PyObject *
Outputs_get_c1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_c1_nget, self->data_ptr);
}

static PyObject *
Outputs_get_c2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_c2_nget, self->data_ptr);
}

static PyObject *
Outputs_get_c3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_InvCecCg_Outputs_c3_nget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_C0(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_C0_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_C1(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_C1_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_C2(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_C2_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_C3(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_C3_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Pdco(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Pdco_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Psco(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Psco_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vdc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vdc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vdc_Vnom(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vdc_Vnom_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vmax(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vmax_mget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vmax_abc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vmax_abc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vmin(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vmin_mget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vmin_abc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vmin_abc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vnom(VarGroupObject *self, void *closure)
{
	return PySAM_matrix_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vnom_mget, self->data_ptr);
}

static PyObject *
Outputs_get_inv_cec_cg_Vnom_abc(VarGroupObject *self, void *closure)
{
	return PySAM_array_getter(SAM_InvCecCg_Outputs_inv_cec_cg_Vnom_abc_aget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"Pdco", (getter)Outputs_get_Pdco,(setter)0,
	PyDoc_STR("*float*: CEC generated Pdco [Wac]"),
 	NULL},
{"Pso", (getter)Outputs_get_Pso,(setter)0,
	PyDoc_STR("*float*: CEC generated Pso [Wdc]"),
 	NULL},
{"Vdco", (getter)Outputs_get_Vdco,(setter)0,
	PyDoc_STR("*float*: CEC generated Vdco [Vdc]"),
 	NULL},
{"c0", (getter)Outputs_get_c0,(setter)0,
	PyDoc_STR("*float*: CEC generated c0 [1/W]"),
 	NULL},
{"c1", (getter)Outputs_get_c1,(setter)0,
	PyDoc_STR("*float*: CEC generated c1 [1/V]"),
 	NULL},
{"c2", (getter)Outputs_get_c2,(setter)0,
	PyDoc_STR("*float*: CEC generated c2 [1/V]"),
 	NULL},
{"c3", (getter)Outputs_get_c3,(setter)0,
	PyDoc_STR("*float*: CEC generated c3 [1/V]"),
 	NULL},
{"inv_cec_cg_C0", (getter)Outputs_get_inv_cec_cg_C0,(setter)0,
	PyDoc_STR("*sequence*: C0 at Vmin, Vnom, Vmax"),
 	NULL},
{"inv_cec_cg_C1", (getter)Outputs_get_inv_cec_cg_C1,(setter)0,
	PyDoc_STR("*sequence*: C1 at m and b"),
 	NULL},
{"inv_cec_cg_C2", (getter)Outputs_get_inv_cec_cg_C2,(setter)0,
	PyDoc_STR("*sequence*: C1 at m and b"),
 	NULL},
{"inv_cec_cg_C3", (getter)Outputs_get_inv_cec_cg_C3,(setter)0,
	PyDoc_STR("*sequence*: C1 at m and b"),
 	NULL},
{"inv_cec_cg_Pdco", (getter)Outputs_get_inv_cec_cg_Pdco,(setter)0,
	PyDoc_STR("*sequence*: Pdco at Vmin, Vnom, Vmax"),
 	NULL},
{"inv_cec_cg_Psco", (getter)Outputs_get_inv_cec_cg_Psco,(setter)0,
	PyDoc_STR("*sequence*: Psco at Vmin, Vnom, Vmax"),
 	NULL},
{"inv_cec_cg_Vdc", (getter)Outputs_get_inv_cec_cg_Vdc,(setter)0,
	PyDoc_STR("*sequence*: Vdc at Vmin, Vnom, Vmax"),
 	NULL},
{"inv_cec_cg_Vdc_Vnom", (getter)Outputs_get_inv_cec_cg_Vdc_Vnom,(setter)0,
	PyDoc_STR("*sequence*: Vdc - Vnom at Vmin, Vnom, Vmax"),
 	NULL},
{"inv_cec_cg_Vmax", (getter)Outputs_get_inv_cec_cg_Vmax,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Vmax for least squares fit"),
 	NULL},
{"inv_cec_cg_Vmax_abc", (getter)Outputs_get_inv_cec_cg_Vmax_abc,(setter)0,
	PyDoc_STR("*sequence*: Vmax a,b,c for least squares fit"),
 	NULL},
{"inv_cec_cg_Vmin", (getter)Outputs_get_inv_cec_cg_Vmin,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Vmin for least squares fit"),
 	NULL},
{"inv_cec_cg_Vmin_abc", (getter)Outputs_get_inv_cec_cg_Vmin_abc,(setter)0,
	PyDoc_STR("*sequence*: Vmin a,b,c for least squares fit"),
 	NULL},
{"inv_cec_cg_Vnom", (getter)Outputs_get_inv_cec_cg_Vnom,(setter)0,
	PyDoc_STR("*sequence[sequence]*: Vnom for least squares fit"),
 	NULL},
{"inv_cec_cg_Vnom_abc", (getter)Outputs_get_inv_cec_cg_Vnom_abc,(setter)0,
	PyDoc_STR("*sequence*: Vnom a,b,c for least squares fit"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"InvCecCg.Outputs",             /*tp_name*/
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
 * InvCecCg
 */

static PyTypeObject InvCecCg_Type;

static CmodObject *
newInvCecCgObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &InvCecCg_Type);

	PySAM_TECH_ATTR()

	PyObject* Common_obj = Common_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Common", Common_obj);
	Py_DECREF(Common_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* InvCecCg methods */

static void
InvCecCg_dealloc(CmodObject *self)
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
InvCecCg_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_InvCecCg_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
InvCecCg_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "InvCecCg"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
InvCecCg_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
InvCecCg_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef InvCecCg_methods[] = {
		{"execute",            (PyCFunction)InvCecCg_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)InvCecCg_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'Common': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)InvCecCg_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)InvCecCg_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
InvCecCg_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
InvCecCg_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject InvCecCg_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"InvCecCg",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)InvCecCg_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)InvCecCg_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)InvCecCg_getattro, /*tp_getattro*/
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
		InvCecCg_methods,      /*tp_methods*/
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


/* Function of no arguments returning new InvCecCg object */

static PyObject *
InvCecCg_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newInvCecCgObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
InvCecCg_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newInvCecCgObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
InvCecCg_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newInvCecCgObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "InvCecCg", def);

	return (PyObject *)rv;
}

static PyObject *
InvCecCg_from_existing(PyObject *self, PyObject *args)
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

	rv = newInvCecCgObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "InvCecCg", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef InvCecCgModule_methods[] = {
		{"new",             InvCecCg_new,         METH_VARARGS,
				PyDoc_STR("new() -> InvCecCg")},
		{"default",             InvCecCg_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> InvCecCg\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             InvCecCg_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> InvCecCg\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   InvCecCg_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> InvCecCg\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "InvCecCg");


static int
InvCecCgModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	InvCecCg_Type.tp_dict = PyDict_New();
	if (!InvCecCg_Type.tp_dict) { goto fail; }

	/// Add the Common type object to InvCecCg_Type
	if (PyType_Ready(&Common_Type) < 0) { goto fail; }
	PyDict_SetItemString(InvCecCg_Type.tp_dict,
				"Common",
				(PyObject*)&Common_Type);
	Py_DECREF(&Common_Type);

	/// Add the Outputs type object to InvCecCg_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(InvCecCg_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the InvCecCg type object to the module
	if (PyType_Ready(&InvCecCg_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"InvCecCg",
				(PyObject*)&InvCecCg_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot InvCecCgModule_slots[] = {
		{Py_mod_exec, InvCecCgModule_exec},
		{0, NULL},
};

static struct PyModuleDef InvCecCgModule = {
		PyModuleDef_HEAD_INIT,
		"InvCecCg",
		module_doc,
		0,
		InvCecCgModule_methods,
		InvCecCgModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_InvCecCg(void)
{
	return PyModuleDef_Init(&InvCecCgModule);
}