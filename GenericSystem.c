#include <Python.h>

#include "SAM_GenericSystem.h"
#include "SAM_api.h"

#include "PySAM_utils.h"


/*
 *  PowerPlant Group
 */

typedef struct {
    PyObject_HEAD
    SAM_GenericSystem   data_ptr;
} PowerPlantObject;

static PyTypeObject PowerPlant_Type;

static PyObject *
PowerPlant_new(SAM_GenericSystem data_ptr)
{
    PyObject* new_obj = PowerPlant_Type.tp_alloc(&PowerPlant_Type,0);

    PowerPlantObject* PowerPlant_obj = (PowerPlantObject*)new_obj;

    PowerPlant_obj->data_ptr = data_ptr;

    return new_obj;
}

/* PowerPlant methods */

static PyObject *
PowerPlant_assign(PowerPlantObject *self, PyObject *args)
{
    PyObject* dict;
    if (!PyArg_ParseTuple(args, "O:assign", &dict)){
        return NULL;
    }

    if (!PySAM_assign_from_dict(self->data_ptr, dict, "GenericSystem", "PowerPlant")){
        return NULL;
    }

    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject *
PowerPlant_export(PowerPlantObject *self, PyObject *args)
{
    PyTypeObject* tp = &PowerPlant_Type;
    PyObject* dict = PySAM_export_to_dict(self->data_ptr, (PyObject *) self, tp, "GenericSystem", "PowerPlant");
    return dict;
}

static PyMethodDef PowerPlant_methods[] = {
        {"assign",            (PyCFunction)PowerPlant_assign,  METH_VARARGS,
                PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
        {"export",            (PyCFunction)PowerPlant_export,  METH_VARARGS,
                PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
PowerPlant_get_derate(PowerPlantObject *self, void *closure)
{
    PySAM_FLOAT_GETTER(SAM_GenericSystem_PowerPlant_derate_fget)
}

static int
PowerPlant_set_derate(PowerPlantObject *self, PyObject *value, void *closure)
{
    PySAM_FLOAT_SETTER(SAM_GenericSystem_PowerPlant_derate_fset)
}

static PyObject *
PowerPlant_get_energy_output_array(PowerPlantObject *self, void *closure)
{
    return PySAM_array_getter(SAM_GenericSystem_PowerPlant_energy_output_array_aget, self->data_ptr);
}

static int
PowerPlant_set_energy_output_array(PowerPlantObject *self, PyObject *value, void *closure)
{
    return PySAM_array_setter(value, SAM_GenericSystem_PowerPlant_energy_output_array_aset, self->data_ptr);
}

static PyGetSetDef PowerPlant_getset[] = {
    {"derate", (getter)PowerPlant_get_derate, (setter)PowerPlant_set_derate,
        "Derate [%]", NULL},
    {"energy_output_array", (getter)PowerPlant_get_energy_output_array, (setter)PowerPlant_set_energy_output_array,
        "Array of Energy Output Profile [kW]", NULL},
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
        PowerPlant_methods,         /*tp_methods*/
        0,                          /*tp_members*/
        PowerPlant_getset,          /*tp_getset*/
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
 *  Output Group
 */

typedef struct {
    PyObject_HEAD
    SAM_GenericSystem   data_ptr;
} GenericSystemOutputObject;

static PyTypeObject GenericSystemOutput_Type;

static PyObject *
GenericSystemOutput_new(SAM_GenericSystem data_ptr)
{
    PyObject* new_obj = GenericSystemOutput_Type.tp_alloc(&GenericSystemOutput_Type,0);

    GenericSystemOutputObject* GenericSystemOutput_obj = (GenericSystemOutputObject*)new_obj;

    GenericSystemOutput_obj->data_ptr = data_ptr;

    return new_obj;
}

/* Output methods */

static PyObject *
GenericSystemOutput_export(GenericSystemOutputObject *self, PyObject *args)
{
    PyTypeObject* tp = &GenericSystemOutput_Type;
    PyObject* dict = PySAM_export_to_dict(self->data_ptr, (PyObject *) self, tp, "GenericSystem", "");
    return dict;
}

static PyMethodDef GenericSystemOutput_methods[] = {
        {"export",            (PyCFunction)GenericSystemOutput_export,  METH_VARARGS,
                PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
GenericSystemOutput_get_derate(PowerPlantObject *self, void *closure)
{
    return PyLong_FromDouble(1.0);
}

static PyObject *
GenericSystemOutput_get_energy_output_array(PowerPlantObject *self, void *closure)
{
    return PyLong_FromDouble(2.0);
}


static PyGetSetDef GenericSystemOutput_getset[] = {
        {"output1", (getter)GenericSystemOutput_get_derate, 0,
                "Derate [%]", NULL},
        {"output2", (getter)GenericSystemOutput_get_energy_output_array, 0,
                "Array of Energy Output Profile [kW]", NULL},
        {NULL}  /* Sentinel */
};


static PyTypeObject GenericSystemOutput_Type = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "GenericSystem.Outputs",             /*tp_name*/
        sizeof(PowerPlantObject),          /*tp_basicsize*/
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
        GenericSystemOutput_methods,         /*tp_methods*/
        0,                          /*tp_members*/
        GenericSystemOutput_getset,          /*tp_getset*/
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

    PySAM_TECH_ATTR("GenericSystem", SAM_GenericSystem_construct)

    PyObject* PowerPlant_obj = PowerPlant_new(self->data_ptr);
    PyDict_SetItemString(attr_dict, "PowerPlant", PowerPlant_obj);

    PyObject* GenericSystemOutput_obj = GenericSystemOutput_new(self->data_ptr);
    PyDict_SetItemString(attr_dict, "Outputs", GenericSystemOutput_obj);

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


static PyMethodDef GenericSystem_methods[] = {
        {"execute",            (PyCFunction)GenericSystem_execute,  METH_VARARGS,
                PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
GenericSystem_getattro(GenericSystemObject *self, PyObject *name)
{
    PySAM_GET_ATTR()
}

static int
GenericSystem_setattr(GenericSystemObject *self, const char *name, PyObject *v)
{
    PySAM_SET_ATTR()
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

    GenericSystem_Type.tp_dict = PyDict_New();
    if (!GenericSystem_Type.tp_dict) { goto fail; }

    /// Add the PowerPlant type object to GenericSystem_Type
    if (PyType_Ready(&PowerPlant_Type) < 0) { goto fail; }
    Py_INCREF(&PowerPlant_Type);
    PyDict_SetItemString(GenericSystem_Type.tp_dict,
                         "PowerPlant",
                         (PyObject*)&PowerPlant_Type);

    /// Add the Output type object to GenericSystem_Type
    if (PyType_Ready(&GenericSystemOutput_Type) < 0) { goto fail; }
    Py_INCREF(&GenericSystemOutput_Type);
    PyDict_SetItemString(GenericSystem_Type.tp_dict,
                         "Outputs",
                         (PyObject*)&GenericSystemOutput_Type);

    /// Add the GenericSystem type object to the module
    if (PyType_Ready(&GenericSystem_Type) < 0) { goto fail; }
    Py_INCREF(&GenericSystem_Type);
    PyModule_AddObject(m,
                       "GenericSystem",
                       (PyObject*)&GenericSystem_Type);


    if (PySAM_ErrorObject == NULL) {
        PySAM_ErrorObject = PyErr_NewException("PySAM.error", NULL, NULL);
        if (PySAM_ErrorObject == NULL)
            goto fail;
    }
    Py_INCREF(PySAM_ErrorObject);

    if (!SAM_lib_path){
        PyObject* file = PyModule_GetFilenameObject(m);

        if (!file){
            PyErr_SetString(PySAM_ErrorObject, "Could not get module filepath");
            Py_XDECREF(file);
            return -1;
        }
        PyObject* ascii_mystring = PyUnicode_AsASCIIString(file);
        char* filename = PyBytes_AsString(ascii_mystring);

        char* lastSlash = strrchr(filename, SAM_sep);
        char* dir = strndup(filename, strlen(filename) - strlen(lastSlash) + 1);

        SAM_lib_path = malloc(strlen(dir) + strlen(SAM_lib) + 1);
        strcpy(SAM_lib_path, dir);
        strcat(SAM_lib_path, SAM_lib);

        Py_XDECREF(file);
        Py_XDECREF(ascii_mystring);
    }

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