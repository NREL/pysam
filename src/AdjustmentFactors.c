#include <Python.h>

#include <SAM_AdjustmentFactors.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 *  AdjustmentFactors Group
 */

typedef struct {
    PyObject_HEAD
    // General SAM technology system
    void*   data_ptr;
} AdjustmentFactorsObject;

static PyTypeObject AdjustmentFactors_Type;

static PyObject *
AdjustmentFactors_new(PyObject* self, PyObject* args)
{
    PyObject* new_obj = AdjustmentFactors_Type.tp_alloc(&AdjustmentFactors_Type,0);

    AdjustmentFactorsObject* adj = (AdjustmentFactorsObject*)new_obj;

    PyObject* data_cap;
    if (!PyArg_ParseTuple(args, "O", &data_cap)){
        PyErr_SetString(PyExc_Exception, "AdjustmentFactors initialization requires a data ptr.");
        return NULL;
    }

    adj->data_ptr = PyCapsule_GetPointer(data_cap, NULL);

    return new_obj;
}

/* AdjustmentFactors methods */

static PyObject *
AdjustmentFactors_assign(AdjustmentFactorsObject *self, PyObject *args)
{
    return PySAM_assign_from_attr(&AdjustmentFactors_Type, (PyObject*)self, args);
}

static PyObject *
AdjustmentFactors_export(AdjustmentFactorsObject *self, PyObject *args)
{
    PyTypeObject* tp = &AdjustmentFactors_Type;
    PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
    return dict;
}

static PyMethodDef AdjustmentFactors_methods[] = {
        {"assign",            (PyCFunction)AdjustmentFactors_assign,  METH_VARARGS,
                PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
        {"export",            (PyCFunction)AdjustmentFactors_export,  METH_VARARGS,
                PyDoc_STR("export() -> Dict\n Export attributes into dictionary")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
AdjustmentFactors_get_constant(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_double_getter(SAM_AdjustmentFactors_adjust_constant_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_constant(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_double_setter(value, SAM_AdjustmentFactors_adjust_constant_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_hourly(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_array_getter(SAM_AdjustmentFactors_adjust_hourly_aget, self->data_ptr);
}

static int
AdjustmentFactors_set_hourly(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_array_setter(value, SAM_AdjustmentFactors_adjust_hourly_aset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_periods(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_matrix_getter(SAM_AdjustmentFactors_adjust_periods_mget, self->data_ptr);
}

static int
AdjustmentFactors_set_periods(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_matrix_setter(value, SAM_AdjustmentFactors_adjust_periods_mset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_dc_constant(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_double_getter(SAM_AdjustmentFactors_dc_adjust_constant_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_dc_constant(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_double_setter(value, SAM_AdjustmentFactors_dc_adjust_constant_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_dc_hourly(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_array_getter(SAM_AdjustmentFactors_dc_adjust_hourly_aget, self->data_ptr);
}

static int
AdjustmentFactors_set_dc_hourly(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_array_setter(value, SAM_AdjustmentFactors_dc_adjust_hourly_aset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_dc_periods(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_matrix_getter(SAM_AdjustmentFactors_dc_adjust_periods_mget, self->data_ptr);
}

static int
AdjustmentFactors_set_dc_periods(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_matrix_setter(value, SAM_AdjustmentFactors_dc_adjust_periods_mset, self->data_ptr);
}
static PyObject *
AdjustmentFactors_get_sf_constant(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_double_getter(SAM_AdjustmentFactors_sf_adjust_constant_nget, self->data_ptr);
}

static int
AdjustmentFactors_set_sf_constant(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_double_setter(value, SAM_AdjustmentFactors_sf_adjust_constant_nset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_sf_hourly(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_array_getter(SAM_AdjustmentFactors_sf_adjust_hourly_aget, self->data_ptr);
}

static int
AdjustmentFactors_set_sf_hourly(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_array_setter(value, SAM_AdjustmentFactors_sf_adjust_hourly_aset, self->data_ptr);
}

static PyObject *
AdjustmentFactors_get_sf_periods(AdjustmentFactorsObject *self, void *closure)
{
    return PySAM_matrix_getter(SAM_AdjustmentFactors_sf_adjust_periods_mget, self->data_ptr);
}

static int
AdjustmentFactors_set_sf_periods(AdjustmentFactorsObject *self, PyObject *value, void *closure)
{
    return PySAM_matrix_setter(value, SAM_AdjustmentFactors_sf_adjust_periods_mset, self->data_ptr);
}

static PyGetSetDef AdjustmentFactors_getset[] = {
        {"constant", (getter)AdjustmentFactors_get_constant, (setter)AdjustmentFactors_set_constant,
                "type: float", NULL},
        {"hourly", (getter)AdjustmentFactors_get_hourly, (setter)AdjustmentFactors_set_hourly,
                "AC Hourly Adjustment Factors [%]", NULL},
        {"periods", (getter)AdjustmentFactors_get_periods, (setter)AdjustmentFactors_set_periods,
                "AC Period-based Adjustment Factors [%]", NULL},
        {"dc_constant", (getter)AdjustmentFactors_get_dc_constant, (setter)AdjustmentFactors_set_dc_constant,
                "DC Constant loss adjustment [%]", NULL},
        {"dc_hourly", (getter)AdjustmentFactors_get_dc_hourly, (setter)AdjustmentFactors_set_dc_hourly,
                "DC Hourly Adjustment Factors [%]", NULL},
        {"dc_periods", (getter)AdjustmentFactors_get_dc_periods, (setter)AdjustmentFactors_set_dc_periods,
                "DC Period-based Adjustment Factors [%]", NULL},
        {"sf_constant", (getter)AdjustmentFactors_get_sf_constant, (setter)AdjustmentFactors_set_sf_constant,
                "DC Constant loss adjustment [%]", NULL},
        {"sf_hourly", (getter)AdjustmentFactors_get_sf_hourly, (setter)AdjustmentFactors_set_sf_hourly,
                "DC Hourly Adjustment Factors [%]", NULL},
        {"sf_periods", (getter)AdjustmentFactors_get_sf_periods, (setter)AdjustmentFactors_set_sf_periods,
                "DC Period-based Adjustment Factors [%]", NULL},
        {NULL}  /* Sentinel */
};



static PyTypeObject AdjustmentFactors_Type = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "AdjustmentFactors",             /*tp_name*/
        sizeof(AdjustmentFactorsObject),          /*tp_basicsize*/
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
        AdjustmentFactors_methods,         /*tp_methods*/
        0,                          /*tp_members*/
        AdjustmentFactors_getset,          /*tp_getset*/
        0,                          /*tp_base*/
        0,  /*tp_dict*/
        0,                          /*tp_descr_get*/
        0,                          /*tp_descr_set*/
        0,                          /*tp_dictofnset*/
        0,                          /*tp_init*/
        0,                          /*tp_alloc*/
        0,             /*tp_new*/
        0,                          /*tp_free*/
        0,                          /*tp_is_gc*/
};

static PyMethodDef AdjustmentFactorsModule_methods[] = {
        {"new",             AdjustmentFactors_new,         METH_VARARGS,
                PyDoc_STR("new(data_capsule) -> AdjustmentFactors")},
        {NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
             "Adjustment Factors for AC, DC and SF adjustments on a constant, hourly, or period basis.");


static int
AdjustmentFactorsModule_exec(PyObject *m)
{
    /* Slot initialization is subject to the rules of initializing globals.
       C99 requires the initializers to be "address constants".  Function
       designators like 'PyType_GenericNew', with implicit conversion to
       a pointer, are valid C99 address constants.

       However, the unary '&' operator applied to a non-static variable
       like 'PyBaseObject_Type' is not required to produce an address
       constant.  Compilers may support this (gcc does), MSVC does not.

       Both compilers are strictly standard conforming in this particular
       behavior.
    */


    /* Finalize the type object including setting type of the new type
     * object; doing it here is required for portability, too. */

    AdjustmentFactors_Type.tp_dict = PyDict_New();
    if (!AdjustmentFactors_Type.tp_dict) { goto fail; }

    /// Add the AdjustmentFactors type object to the module
    if (PyType_Ready(&AdjustmentFactors_Type) < 0) { goto fail; }
    PyModule_AddObject(m,
                       "AdjustmentFactors",
                       (PyObject*)&AdjustmentFactors_Type);

	if (PySAM_load_lib(m) < 0) goto fail;

    return 0;
    fail:
    Py_XDECREF(m);
    return -1;
}

static struct PyModuleDef_Slot AdjustmentFactorsModule_slots[] = {
        {Py_mod_exec, AdjustmentFactorsModule_exec},
        {0, NULL},
};

static struct PyModuleDef AdjustmentFactorsModule = {
        PyModuleDef_HEAD_INIT,
        "AdjustmentFactors",
        module_doc,
        0,
        AdjustmentFactorsModule_methods,
        AdjustmentFactorsModule_slots,
        NULL,
        NULL,
        NULL
};

/* Export function for the module (*must* be called PyInit_AdjustmentFactors) */

PyMODINIT_FUNC
PyInit_AdjustmentFactors(void)
{
    return PyModuleDef_Init(&AdjustmentFactorsModule);
}
