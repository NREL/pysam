#include <Python.h>

#include <SAM_GenericSystem.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Plant Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_GenericSystem   data_ptr;
} PlantObject;

static PyTypeObject Plant_Type;

static PyObject *
Plant_new(SAM_GenericSystem data_ptr)
{
	PyObject* new_obj = Plant_Type.tp_alloc(&Plant_Type,0);

	PlantObject* Plant_obj = (PlantObject*)new_obj;

	Plant_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Plant methods */

static PyObject *
Plant_assign(PlantObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "Plant")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Plant_export(PlantObject *self, PyObject *args)
{
	PyTypeObject* tp = &Plant_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Plant_methods[] = {
		{"assign",            (PyCFunction)Plant_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Plant_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Plant_get_conv_eff(PlantObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Plant_conv_eff_fget, self->data_ptr);
}

static int
Plant_set_conv_eff(PlantObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Plant_conv_eff_fset, self->data_ptr);
}

static PyObject *
Plant_get_derate(PlantObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Plant_derate_fget, self->data_ptr);
}

static int
Plant_set_derate(PlantObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Plant_derate_fset, self->data_ptr);
}

static PyObject *
Plant_get_energy_output_array(PlantObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Plant_energy_output_array_aget, self->data_ptr);
}

static int
Plant_set_energy_output_array(PlantObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_GenericSystem_Plant_energy_output_array_aset, self->data_ptr);
}

static PyObject *
Plant_get_heat_rate(PlantObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Plant_heat_rate_fget, self->data_ptr);
}

static int
Plant_set_heat_rate(PlantObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Plant_heat_rate_fset, self->data_ptr);
}

static PyObject *
Plant_get_spec_mode(PlantObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Plant_spec_mode_fget, self->data_ptr);
}

static int
Plant_set_spec_mode(PlantObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Plant_spec_mode_fset, self->data_ptr);
}

static PyObject *
Plant_get_system_capacity(PlantObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Plant_system_capacity_fget, self->data_ptr);
}

static int
Plant_set_system_capacity(PlantObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Plant_system_capacity_fset, self->data_ptr);
}

static PyObject *
Plant_get_user_capacity_factor(PlantObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Plant_user_capacity_factor_fget, self->data_ptr);
}

static int
Plant_set_user_capacity_factor(PlantObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Plant_user_capacity_factor_fset, self->data_ptr);
}

static PyGetSetDef Plant_getset[] = {
{"conv_eff", (getter)Plant_get_conv_eff,(setter)Plant_set_conv_eff,
	"Conversion Efficiency [%], number.\n Required.",
 	NULL},
{"derate", (getter)Plant_get_derate,(setter)Plant_set_derate,
	"Derate [%], number.\n Required.",
 	NULL},
{"energy_output_array", (getter)Plant_get_energy_output_array,(setter)Plant_set_energy_output_array,
	"Array of Energy Output Profile [kW], array.\n Required if spec_mode=1.",
 	NULL},
{"heat_rate", (getter)Plant_get_heat_rate,(setter)Plant_set_heat_rate,
	"Heat Rate [MMBTUs/MWhe], number.\n Required.",
 	NULL},
{"spec_mode", (getter)Plant_get_spec_mode,(setter)Plant_set_spec_mode,
	"Spec mode: 0=constant CF,1=profile, number.\n Required.",
 	NULL},
{"system_capacity", (getter)Plant_get_system_capacity,(setter)Plant_set_system_capacity,
	"Nameplace Capcity [kW], number.\n Required.",
 	NULL},
{"user_capacity_factor", (getter)Plant_get_user_capacity_factor,(setter)Plant_set_user_capacity_factor,
	"Capacity Factor [%], number.\n Required.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Plant_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem.Plant",             /*tp_name*/
		sizeof(PlantObject),          /*tp_basicsize*/
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
		Plant_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Plant_getset,          /*tp_getset*/
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
	SAM_GenericSystem   data_ptr;
} LifetimeObject;

static PyTypeObject Lifetime_Type;

static PyObject *
Lifetime_new(SAM_GenericSystem data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "Lifetime")){
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
	return PySAM_float_getter(SAM_GenericSystem_Lifetime_analysis_period_fget, self->data_ptr);
}

static int
Lifetime_set_analysis_period(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Lifetime_analysis_period_fset, self->data_ptr);
}

static PyObject *
Lifetime_get_generic_degradation(LifetimeObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Lifetime_generic_degradation_aget, self->data_ptr);
}

static int
Lifetime_set_generic_degradation(LifetimeObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_GenericSystem_Lifetime_generic_degradation_aset, self->data_ptr);
}

static PyObject *
Lifetime_get_system_use_lifetime_output(LifetimeObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Lifetime_system_use_lifetime_output_fget, self->data_ptr);
}

static int
Lifetime_set_system_use_lifetime_output(LifetimeObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_GenericSystem_Lifetime_system_use_lifetime_output_fset, self->data_ptr);
}

static PyGetSetDef Lifetime_getset[] = {
{"analysis_period", (getter)Lifetime_get_analysis_period,(setter)Lifetime_set_analysis_period,
	"Lifetime analysis period [years], number.\n Required if system_use_lifetime_output=1.",
 	NULL},
{"generic_degradation", (getter)Lifetime_get_generic_degradation,(setter)Lifetime_set_generic_degradation,
	"Annual module degradation [%/year], array.\n Required if system_use_lifetime_output=1.",
 	NULL},
{"system_use_lifetime_output", (getter)Lifetime_get_system_use_lifetime_output,(setter)Lifetime_set_system_use_lifetime_output,
	"Generic lifetime simulation [0/1], number.\n Constraints: INTEGER,MIN=0,MAX=1; 0 if not set.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Lifetime_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem.Lifetime",             /*tp_name*/
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
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_GenericSystem   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_GenericSystem data_ptr)
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

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "Outputs")){
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
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Outputs_annual_fuel_usage_fget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_GenericSystem_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Outputs_system_heat_rate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_water_usage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_GenericSystem_Outputs_water_usage_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual Energy [kWh], number.",
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	"Annual Fuel Usage [kWht], number.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"System power generated [kW], array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly Energy [kWh], array.",
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	"Heat Rate Conversion Factor [MMBTUs/MWhe], number.",
 	NULL},
{"water_usage", (getter)Outputs_get_water_usage,(setter)0,
	"Annual Water Usage, number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem.Outputs",             /*tp_name*/
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
 * GenericSystem
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_GenericSystem   data_ptr;
} GenericSystemObject;

static PyTypeObject GenericSystem_Type;

#define GenericSystemObject_Check(v)      (Py_TYPE(v) == &GenericSystem_Type)

static GenericSystemObject *
newGenericSystemObject(void* data_ptr)
{
	GenericSystemObject *self;
	self = PyObject_New(GenericSystemObject, &GenericSystem_Type);

	PySAM_TECH_ATTR("GenericSystem", SAM_GenericSystem_construct)

	PyObject* Plant_obj = Plant_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Plant", Plant_obj);
	Py_DECREF(Plant_obj);

	PyObject* Lifetime_obj = Lifetime_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Lifetime", Lifetime_obj);
	Py_DECREF(Lifetime_obj);

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

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);


	return self;
}

/* GenericSystem methods */

static void
GenericSystem_dealloc(GenericSystemObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_GenericSystem_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
GenericSystem_execute(GenericSystemObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_GenericSystem_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GenericSystem_assign(GenericSystemObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "GenericSystem"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
GenericSystem_export(GenericSystemObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyMethodDef GenericSystem_methods[] = {
		{"execute",            (PyCFunction)GenericSystem_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)GenericSystem_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)GenericSystem_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
GenericSystem_getattro(GenericSystemObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
GenericSystem_setattr(GenericSystemObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject GenericSystem_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"GenericSystem",            /*tp_name*/
		sizeof(GenericSystemObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)GenericSystem_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)GenericSystem_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)GenericSystem_getattro, /*tp_getattro*/
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
		GenericSystem_methods,      /*tp_methods*/
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


/* Function of no arguments returning new GenericSystem object */

static PyObject *
GenericSystem_new(PyObject *self, PyObject *args)
{
	GenericSystemObject *rv;
	rv = newGenericSystemObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
GenericSystem_wrap(PyObject *self, PyObject *args)
{
	GenericSystemObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGenericSystemObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
GenericSystem_default(PyObject *self, PyObject *args)
{
	GenericSystemObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newGenericSystemObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "GenericSystem", def);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GenericSystemModule_methods[] = {
		{"new",             GenericSystem_new,         METH_VARARGS,
				PyDoc_STR("new() -> new GenericSystem object")},
		{"default",             GenericSystem_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new GenericSystem object with financial model-specific default attributes\n"
				"Options: Equpartflip, None, Lcoefcr, , Commercial, Thirdpartyownership, Residential, Levpartflip, Singleowner, Saleleaseback, , HostDeveloper")},
		{"wrap",             GenericSystem_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new GenericSystem object around existing PySSC data, taking over memory ownership")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input");


static int
GenericSystemModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error(m) < 0) goto fail;

	GenericSystem_Type.tp_dict = PyDict_New();
	if (!GenericSystem_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to GenericSystem_Type
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
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Plant type object to GenericSystem_Type
	if (PyType_Ready(&Plant_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
				"Plant",
				(PyObject*)&Plant_Type);
	Py_DECREF(&Plant_Type);

	/// Add the Lifetime type object to GenericSystem_Type
	if (PyType_Ready(&Lifetime_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
				"Lifetime",
				(PyObject*)&Lifetime_Type);
	Py_DECREF(&Lifetime_Type);

	/// Add the Outputs type object to GenericSystem_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(GenericSystem_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the GenericSystem type object to the module
	if (PyType_Ready(&GenericSystem_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"GenericSystem",
				(PyObject*)&GenericSystem_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot GenericSystemModule_slots[] = {
		{Py_mod_exec, GenericSystemModule_exec},
		{0, NULL},
};

static struct PyModuleDef GenericSystemModule = {
		PyModuleDef_HEAD_INIT,
		"GenericSystem",
		module_doc,
		0,
		GenericSystemModule_methods,
		GenericSystemModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_GenericSystem(void)
{
	return PyModuleDef_Init(&GenericSystemModule);
}