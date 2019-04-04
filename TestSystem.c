#include <Python.h>

#include "SAM_TestSystem.h"
#include "include/SAM_api.h"

#include "PySAM_utils.h"


/*
 *  Plant Group
 */

typedef struct {
    PyObject_HEAD
    SAM_TestSystem   data_ptr;
} PlantObject;

static PyTypeObject Plant_Type;

static PyObject *
Plant_new(SAM_TestSystem data_ptr)
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

    if (!PySAM_assign_from_dict(self->data_ptr, dict, "TestSystem", "Plant")){
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
Plant_get_derate(PlantObject *self, void *closure)
{
    return PySAM_float_getter(SAM_TestSystem_Plant_derate_fget, self->data_ptr);
}

static int
Plant_set_derate(PlantObject *self, PyObject *value, void *closure)
{
    return PySAM_float_setter(value, SAM_TestSystem_Plant_derate_fset, self->data_ptr);
}

static PyObject *
Plant_get_energy_output_array(PlantObject *self, void *closure)
{
    return PySAM_array_getter(SAM_TestSystem_Plant_energy_output_array_aget, self->data_ptr);
}

static int
Plant_set_energy_output_array(PlantObject *self, PyObject *value, void *closure)
{
    return PySAM_array_setter(value, SAM_TestSystem_Plant_energy_output_array_aset, self->data_ptr);
}

static PyObject *
Plant_get_file(PlantObject *self, void *closure)
{
    return PySAM_string_getter(SAM_TestSystem_Plant_file_sget, self->data_ptr);
}

static int
Plant_set_file(PlantObject *self, PyObject *value, void *closure)
{
    return PySAM_string_setter(value, SAM_TestSystem_Plant_file_sset, self->data_ptr);
}

static PyObject *
Plant_get_data(PlantObject *self, void *closure)
{
    return PySAM_table_getter(SAM_TestSystem_Plant_data_tget, self->data_ptr);
}

static int
Plant_set_data(PlantObject *self, PyObject *value, void *closure)
{
    return PySAM_table_setter(value, SAM_TestSystem_Plant_data_tset, self->data_ptr);
}

static PyGetSetDef Plant_getset[] = {
    {"derate", (getter)Plant_get_derate, (setter)Plant_set_derate,
        "Derate [%], number", NULL},
    {"energy_output_array", (getter)Plant_get_energy_output_array, (setter)Plant_set_energy_output_array,
        "Array of Energy Output Profile [kW], tuple", NULL},
    {"file", (getter)Plant_get_file, (setter)Plant_set_file,
            "string [%], string", NULL},
    {"data", (getter)Plant_get_data, (setter)Plant_set_data,
            "table [%], dict", NULL},
    {NULL}  /* Sentinel */
};


static PyTypeObject Plant_Type = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "TestSystem.Plant",             /*tp_name*/
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
 *  Output Group
 */

typedef struct {
    PyObject_HEAD
    SAM_TestSystem   data_ptr;
} TestSystemOutputObject;

static PyTypeObject TestSystemOutput_Type;

static PyObject *
TestSystemOutput_new(SAM_TestSystem data_ptr)
{
    PyObject* new_obj = TestSystemOutput_Type.tp_alloc(&TestSystemOutput_Type,0);

    TestSystemOutputObject* TestSystemOutput_obj = (TestSystemOutputObject*)new_obj;

    TestSystemOutput_obj->data_ptr = data_ptr;

    return new_obj;
}

/* Output methods */

static PyObject *
TestSystemOutput_export(TestSystemOutputObject *self, PyObject *args)
{
    PyTypeObject* tp = &TestSystemOutput_Type;
    PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
    return dict;
}

static PyMethodDef TestSystemOutput_methods[] = {
        {"export",            (PyCFunction)TestSystemOutput_export,  METH_VARARGS,
                PyDoc_STR("export() -> None\n Export attributes into nested dictionary")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
TestSystemOutput_get_derate(PlantObject *self, void *closure)
{
    return PyLong_FromDouble(1.0);
}

static PyObject *
TestSystemOutput_get_energy_output_array(PlantObject *self, void *closure)
{
    return PyLong_FromDouble(2.0);
}


static PyGetSetDef TestSystemOutput_getset[] = {
        {"output1", (getter)TestSystemOutput_get_derate, 0,
                "Derate [%]", NULL},
        {"output2", (getter)TestSystemOutput_get_energy_output_array, 0,
                "Array of Energy Output Profile [kW]", NULL},
        {NULL}  /* Sentinel */
};


static PyTypeObject TestSystemOutput_Type = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "TestSystem.Outputs",             /*tp_name*/
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
        TestSystemOutput_methods,         /*tp_methods*/
        0,                          /*tp_members*/
        TestSystemOutput_getset,          /*tp_getset*/
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
    SAM_TestSystem   data_ptr;
} TestSystemObject;

static PyTypeObject TestSystem_Type;

#define TestSystemObject_Check(v)      (Py_TYPE(v) == &TestSystem_Type)

static TestSystemObject *
newTestSystemObject(void* data_ptr)
{
    TestSystemObject *self;
    self = PyObject_New(TestSystemObject, &TestSystem_Type);

    PySAM_TECH_ATTR("TestSystem", SAM_TestSystem_construct)

    PyObject* Plant_obj = Plant_new(self->data_ptr);
    PyDict_SetItemString(attr_dict, "Plant", Plant_obj);
    Py_DECREF(Plant_obj);

    PyObject* TestSystemOutput_obj = TestSystemOutput_new(self->data_ptr);
    PyDict_SetItemString(attr_dict, "Outputs", TestSystemOutput_obj);
    Py_DECREF(TestSystemOutput_obj);

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

    return self;
}

/* TestSystem methods */

static void
TestSystem_dealloc(TestSystemObject *self)
{
    Py_XDECREF(self->x_attr);
    SAM_TestSystem_destruct(self->data_ptr);
    PyObject_Del(self);
}


static PyObject *
TestSystem_execute(TestSystemObject *self, PyObject *args)
{
    int verbosity = 0;

    if (!PyArg_ParseTuple(args, "|i", &verbosity))
        return NULL;

    SAM_error error = new_error();
    SAM_TestSystem_execute(self->data_ptr, verbosity, &error);
    if (PySAM_has_error(error )) return NULL;

    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject *
TestSystem_assign(TestSystemObject *self, PyObject *args)
{
    PyObject* dict;
    if (!PyArg_ParseTuple(args, "O:assign", &dict)){
        return NULL;
    }

    if (!PySAM_assign_from_nested_dict(self, self->x_attr, self->data_ptr, dict, "TestSystem"))
        return NULL;

    Py_INCREF(Py_None);
    return Py_None;
}


static PyObject *
TestSystem_export(TestSystemObject *self, PyObject *args)
{
    return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}


static PyMethodDef TestSystem_methods[] = {
        {"execute",            (PyCFunction)TestSystem_execute,  METH_VARARGS,
                PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
        {"assign",            (PyCFunction)TestSystem_assign,  METH_VARARGS,
                PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
        {"export",            (PyCFunction)TestSystem_export,  METH_VARARGS,
                PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
TestSystem_getattro(TestSystemObject *self, PyObject *name)
{
    return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
TestSystem_setattr(TestSystemObject *self, const char *name, PyObject *v)
{
    return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject TestSystem_Type = {
        /* The ob_type field must be initialized in the module init function
         * to be portable to Windows without using C++. */
        PyVarObject_HEAD_INIT(NULL, 0)
        "TestSystem",            /*tp_name*/
        sizeof(TestSystemObject),/*tp_basicsize*/
        0,                          /*tp_itemsize*/
        /* methods */
        (destructor)TestSystem_dealloc,    /*tp_dealloc*/
        0,                          /*tp_print*/
        (getattrfunc)0,             /*tp_getattr*/
        (setattrfunc)TestSystem_setattr,   /*tp_setattr*/
        0,                          /*tp_reserved*/
        0,                          /*tp_repr*/
        0,                          /*tp_as_number*/
        0,                          /*tp_as_sequence*/
        0,                          /*tp_as_mapping*/
        0,                          /*tp_hash*/
        0,                          /*tp_call*/
        0,                          /*tp_str*/
        (getattrofunc)TestSystem_getattro, /*tp_getattro*/
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
        TestSystem_methods,      /*tp_methods*/
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


/* Function of no arguments returning new TestSystem object */

static PyObject *
TestSystem_new(PyObject *self, PyObject *args)
{
    TestSystemObject *rv;
    long int ptr = 0;
    if (!PyArg_ParseTuple(args, "|l:new", &ptr))
        return NULL;
    rv = newTestSystemObject((void*)ptr);
    if (rv == NULL)
        return NULL;
    return (PyObject *)rv;
}



/* ---------- */


/* List of functions defined in the module */

static PyMethodDef TestSystemModule_methods[] = {
        {"new",             TestSystem_new,         METH_VARARGS,
                PyDoc_STR("new(optional data_ptr) -> new TestSystem object")},
        {NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
             "This is a template module just for instruction.");


static int
TestSystemModule_exec(PyObject *m)
{
    /* Finalize the type object including setting type of the new type
     * object; doing it here is required for portability, too. */

    TestSystem_Type.tp_dict = PyDict_New();
    if (!TestSystem_Type.tp_dict) { goto fail; }

    /// Add the AdjustmentFactors type object to TestSystem_Type
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
    PyDict_SetItemString(TestSystem_Type.tp_dict,
                         "AdjustmentFactors",
                         (PyObject*)AdjustmentFactors_Type);
    Py_DECREF(&AdjustmentFactors_Type);
    Py_XDECREF(AdjustmentFactors_Type);

    /// Add the Plant type object to TestSystem_Type
    if (PyType_Ready(&Plant_Type) < 0) { goto fail; }
    PyDict_SetItemString(TestSystem_Type.tp_dict,
                         "Plant",
                         (PyObject*)&Plant_Type);
    Py_DECREF(&Plant_Type);


    /// Add the Output type object to TestSystem_Type
    if (PyType_Ready(&TestSystemOutput_Type) < 0) { goto fail; }
    PyDict_SetItemString(TestSystem_Type.tp_dict,
                         "Outputs",
                         (PyObject*)&TestSystemOutput_Type);
    Py_DECREF(&TestSystemOutput_Type);

    /// Add the TestSystem type object to the module
    if (PyType_Ready(&TestSystem_Type) < 0) { goto fail; }
    PyModule_AddObject(m,
                       "TestSystem",
                       (PyObject*)&TestSystem_Type);

    if (PySAM_load_lib(m) < 0) goto fail;
    if (PySAM_init_error() < 0) goto fail;

    return 0;
    fail:
    Py_XDECREF(m);
    return -1;
}

static struct PyModuleDef_Slot TestSystemModule_slots[] = {
        {Py_mod_exec, TestSystemModule_exec},
        {0, NULL},
};

static struct PyModuleDef TestSystemModule = {
        PyModuleDef_HEAD_INIT,
        "TestSystem",
        module_doc,
        0,
        TestSystemModule_methods,
        TestSystemModule_slots,
        NULL,
        NULL,
        NULL
};

/* Export function for the module (*must* be called PyInit_TestSystem) */

PyMODINIT_FUNC
PyInit_TestSystem(void)
{
    return PyModuleDef_Init(&TestSystemModule);
}