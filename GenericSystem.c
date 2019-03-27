#include <Python.h>

#include "SAM_GenericSystem.h"
#include "SAM_api.h"

#include "PySAM_utils.h"


/*
 *  PowerPlant Group
 */

typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
    SAM_GenericSystem   data_ptr;
} PowerPlantObject;

static PyTypeObject PowerPlant_Type;

#define PowerPlantObject_Check(v)      (Py_TYPE(v) == &PowerPlant_Type)

static PowerPlantObject *
newPowerPlantObject(PyObject *arg, SAM_GenericSystem ptr)
{
    PowerPlantObject *self;
    self = PyObject_New(PowerPlantObject, &PowerPlant_Type);

    SAM_GROUP_ATTR("PowerPlant", "GenericSystem")

    return self;
}

/* PowerPlant methods */

static void
PowerPlant_dealloc(PowerPlantObject *self)
{
    Py_XDECREF(self->x_attr);
    PyObject_Del(self);
}


static int
PowerPlant_set_derate(PowerPlantObject *self, PyObject *value, void *closure)
{
    SAM_FLOAT_SETTER(SAM_GenericSystem_PowerPlant_derate_set)
}

static PyObject *
PowerPlant_get_derate(PowerPlantObject *self, void *closure)
{
    SAM_FLOAT_GETTER(SAM_GenericSystem_PowerPlant_derate_get)
}


static PyGetSetDef PowerPlant_getset[] = {
    {"derate", (getter)PowerPlant_get_derate, (setter)PowerPlant_set_derate,
        "Derate [%]", NULL},
    {NULL}  /* Sentinel */
};


static PyTypeObject PowerPlant_Type = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "GenericSystem.PowerPlant",             /*tp_name*/
        sizeof(PowerPlantObject),          /*tp_basicsize*/
        0,                          /*tp_itemsize*/
        /* methods */
        (destructor)PowerPlant_dealloc,    /*tp_dealloc*/
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
        0,         /*tp_methods*/
        0,                          /*tp_members*/
        PowerPlant_getset,          /*tp_getset*/
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


/*
 * Generic System
 */

typedef struct {
    PyObject_HEAD
    PyObject            *x_attr;        /* Attributes dictionary */
    SAM_GenericSystem   data_ptr;
} GenericSystemObject;

static PyTypeObject GenericSystem_Type;

#define GenericSystemObject_Check(v)      (Py_TYPE(v) == &GenericSystem_Type)

static GenericSystemObject *
newGenericSystemObject(PyObject *arg)
{
    GenericSystemObject *self;
    self = PyObject_New(GenericSystemObject, &GenericSystem_Type);

    SAM_TECH_ATTR("GenericSystem", SAM_GenericSystem_construct)

    PyDict_SetItemString(attr_dict, "PowerPlant", newPowerPlantObject(0, self->data_ptr));


    return self;
}

/* GenericSystem methods */

static void
GenericSystem_dealloc(GenericSystemObject *self)
{
    Py_XDECREF(self->x_attr);
//    Py_XDECREF(self->powerplant);
    SAM_GenericSystem_destruct(self->data_ptr);
    PyObject_Del(self);
}


static PyObject *
GenericSystem_execute(GenericSystemObject *self, PyObject *args)
{
    float derate;
    SAM_error error = new_error();

    if (!PyArg_ParseTuple(args, "f", &derate))
        return NULL;

    SAM_GenericSystem_PowerPlant_derate_set(self->data_ptr, derate, &error);

    ERROR_CHECK(NULL)

    Py_INCREF(Py_None);
    return Py_None;
}


static PyMethodDef GenericSystem_methods[] = {
        {"execute",            (PyCFunction)GenericSystem_execute,  METH_VARARGS,
                PyDoc_STR("execute() -> None\n Execute simulation")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject*
GenericSystem_get_PowerPlant(GenericSystemObject* self, void* closure)
{
    return self->x_attr;
}

static PyGetSetDef GenericSystem_getset[] = {
    {"PowerPlant", (getter)GenericSystem_get_PowerPlant, NULL, "Power Plant properties", NULL},
    {NULL}  /* Sentinel */
};


static PyObject *
GenericSystem_getattro(GenericSystemObject *self, PyObject *name)
{
    SAM_GET_ATTR()
}

static int
GenericSystem_setattr(GenericSystemObject *self, const char *name, PyObject *v)
{
    SAM_SET_ATTR()
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
        GenericSystem_getset,       /*tp_getset*/
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

    if (!PyArg_ParseTuple(args, ":new"))
        return NULL;
    rv = newGenericSystemObject(args);
    if (rv == NULL)
        return NULL;
    return (PyObject *)rv;
}



/* ---------- */


/* List of functions defined in the module */

static PyMethodDef GenericSystemModule_methods[] = {
        {"new",             GenericSystem_new,         METH_VARARGS,
                PyDoc_STR("new() -> new GenericSystem object")},
        {NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
             "This is a template module just for instruction.");


static int
GenericSystemModule_exec(PyObject *m)
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

    if (PyType_Ready(&PowerPlant_Type) < 0)
        goto fail;

    if (PyType_Ready(&GenericSystem_Type) < 0)
        goto fail;

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

/* Export function for the module (*must* be called PyInit_GenericSystem) */

PyMODINIT_FUNC
PyInit_GenericSystem(void)
{
    return PyModuleDef_Init(&GenericSystemModule);
}