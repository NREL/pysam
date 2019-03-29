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

#define ASSIGNMENT_ERROR_STR(msg) \
char assignment_err_str[256] = "error assigning "; \
strncat(assignment_err_str, name, strlen(name) - 2); \
strncat(assignment_err_str, msg, sizeof(assignment_err_str) - strlen(msg) - 1);


static PyObject *
PowerPlant_assign(PowerPlantObject *self, PyObject *args)
{
    PyObject* dict;

    if (!PyArg_ParseTuple(args, "O:assign", &dict))
        return NULL;

    SAM_error error = new_error();
    void* handle = SAM_load_library(SAM_lib_path, &error);
    if (has_error(&error)) return NULL;


    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    while (PyDict_Next(dict, &pos, &key, &value)){
        PyObject* ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        if (PyNumber_Check(value)){
            float val = (float)PyFloat_AsDouble(value);
            error = new_error();
            SAM_set_float_t func = SAM_set_float_func(handle, "GenericSystem", "PowerPlant", name, &error);
            if (has_error(&error)) return NULL;

            error = new_error();
            func(self->data_ptr, val, &error);
            if (has_error(&error)) return NULL;

        }
        else if (PySequence_Check(value)){
            PyObject* first = PySequence_GetItem(value, 0);
            if (!first){
                ASSIGNMENT_ERROR_STR("empty tuple");
                PyErr_SetString(SAM_ErrorObject, assignment_err_str);
                Py_XDECREF(first);
                return NULL;
            }

            Py_ssize_t n = PySequence_Size(value);

            // matrix
            if (PySequence_Check(first)){
                Py_ssize_t cols = PySequence_Size(first);
                float* mat = malloc(n*cols*sizeof(float));

                for (Py_ssize_t i = 0; i < n; i++){
                    PyObject* row = PySequence_GetItem(value, i);
                                    printf("set mat %d x %d", (int)n, (int)PySequence_Size(row));


                    if (PySequence_Size(row) != cols){
                            ASSIGNMENT_ERROR_STR(", matrix must be rectangular");
                            PyErr_SetString(SAM_ErrorObject, assignment_err_str);
                            return NULL;
                        }
                    for (Py_ssize_t j = 0; j < cols; j++){
                        PyObject* val_o = PySequence_GetItem(row, j);

                        if (!PyNumber_Check(val_o)){
                            ASSIGNMENT_ERROR_STR(", matrix entries must be numeric");
                            PyErr_SetString(SAM_ErrorObject, assignment_err_str);
                            Py_XDECREF(val_o);
                            return NULL;
                        }
                        float val = (float)PyFloat_AsDouble(val_o);
                        Py_XDECREF(val_o);
                        mat[i * cols + j] = val;

                    }
                    Py_XDECREF(row);
                }

                error = new_error();
                SAM_set_matrix_t func = SAM_set_matrix_func(handle, "GenericSystem", "PowerPlant", name, &error);
                if (has_error(&error)) return NULL;

                error = new_error();
                func(self->data_ptr, mat, n, cols, &error);
                if (has_error(&error)) return NULL;

                free(mat);
            }
            // array
            else{
                float* arr = malloc(n*sizeof(float));

                printf("set array %d", (int)n);

                for (Py_ssize_t i = 0; i < n; i++){
                    PyObject* val_o = PySequence_GetItem(value, i);

                    float val = (float)PyFloat_AsDouble(val_o);
                    printf("set array %f", val);

                    if (PyErr_Occurred()){
                        printf("err name %s", name);
                        ASSIGNMENT_ERROR_STR(", array entries must be convertable to numbers");
                        PyErr_SetString(SAM_ErrorObject, assignment_err_str);
                        Py_XDECREF(val_o);
                        return NULL;
                    }
                    Py_XDECREF(val_o);
                    arr[i] = val;
                }
                error = new_error();
                SAM_set_array_t func = SAM_set_array_func(handle, "GenericSystem", "PowerPlant", name, &error);
                if (has_error(&error)) return NULL;

                error = new_error();
                func(self->data_ptr, arr, (int)n, &error);
                if (has_error(&error)) return NULL;

                free(arr);
            }
        }
        else if (PyUnicode_Check(value)){
            PyObject* ascii_val = PyUnicode_AsASCIIString(value);
            char* val = PyBytes_AsString(ascii_val); \

            error = new_error();
            SAM_set_string_t func = SAM_set_string_func(handle, "GenericSystem", "PowerPlant", name, &error);
            if (has_error(&error)) return NULL;

            error = new_error();
            func(self->data_ptr, val, &error);
            if (has_error(&error)) return NULL;

            Py_DECREF(ascii_val);
        }
        else {
            ASSIGNMENT_ERROR_STR( ", assigned types must be numeric, string or tuple.")
            PyErr_SetString(SAM_ErrorObject, assignment_err_str);
            return NULL;
        }
        Py_DECREF(ascii_mystring);
    }


    Py_INCREF(Py_None);
    return Py_None;
}


static PyMethodDef PowerPlant_methods[] = {
        {"assign",            (PyCFunction)PowerPlant_assign,  METH_VARARGS,
                PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
        {NULL,              NULL}           /* sentinel */
};

static PyObject *
PowerPlant_get_derate(PowerPlantObject *self, void *closure)
{
    SAM_FLOAT_GETTER(SAM_GenericSystem_PowerPlant_derate_get)
}

static int
PowerPlant_set_derate(PowerPlantObject *self, PyObject *value, void *closure)
{
    SAM_FLOAT_SETTER(SAM_GenericSystem_PowerPlant_derate_set)
}

static PyObject *
PowerPlant_get_energy_output_array(PowerPlantObject *self, void *closure)
{
    float* arr;
    int seqlen;
    int i = 0;

    SAM_error error = new_error();
    arr = SAM_GenericSystem_PowerPlant_energy_output_array_get(self->data_ptr, &seqlen, &error);
    if (has_error(&error)) return NULL;

    PyObject* seq = PyTuple_New(seqlen);
    for(i=0; i < seqlen; i++) {
        PyTuple_SetItem(seq, i, PyFloat_FromDouble(arr[i]));
    }
    return seq;
}

static int
PowerPlant_set_energy_output_array(PowerPlantObject *self, PyObject *value, void *closure)
{
    PyObject* seq;
    float *arr;
    int seqlen;
    int i;

    seq = PySequence_Fast(value, "argument must be iterable");
    if(!seq)
        return -1;

    seqlen = PySequence_Fast_GET_SIZE(seq);
    arr = malloc(seqlen*sizeof(float));
    if(!arr) {
        Py_DECREF(seq);
        PyErr_NoMemory(  );
        return -1;
    }
    for(i=0; i < seqlen; i++) {
        PyObject *fitem;
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        if(!item) {
            Py_DECREF(seq);
            free(arr);
            return -1;
        }
        fitem = PyNumber_Float(item);
        if(!fitem) {
            Py_DECREF(seq);
            free(arr);
            PyErr_SetString(PyExc_TypeError, "all items must be numbers");
            return -1;
        }
        arr[i] = (float)PyFloat_AS_DOUBLE(fitem);
        Py_DECREF(fitem);
    }

    /* clean up, compute, and return result */
    Py_DECREF(seq);

    SAM_error error = new_error();
    SAM_GenericSystem_PowerPlant_energy_output_array_set(self->data_ptr, arr, seqlen, &error);

    if (has_error(&error)) return -1;


    return 0;
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

    PyDict_SetItemString(attr_dict, "PowerPlant", (PyObject *)newPowerPlantObject(0, self->data_ptr));


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

    if (!PyArg_ParseTuple(args, "f", &derate))
        return NULL;

    SAM_error error = new_error();
    SAM_GenericSystem_PowerPlant_derate_set(self->data_ptr, derate, &error);
    if (has_error(&error)) return NULL;

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

    if (SAM_ErrorObject == NULL) {
        SAM_ErrorObject = PyErr_NewException("PySAM.error", NULL, NULL);
        if (SAM_ErrorObject == NULL)
            goto fail;
    }

    if (!SAM_lib_path){
        PyObject* file = PyModule_GetFilenameObject(m);

        PyObject* ascii_mystring = PyUnicode_AsASCIIString(file);
        char* filename = PyBytes_AsString(ascii_mystring);

        char* lastSlash = strrchr(filename, SAM_sep);
        char* dir = strndup(filename, strlen(filename) - strlen(lastSlash) + 1);

        SAM_lib_path = malloc(strlen(dir) + strlen(SAM_lib) + 1);
        strcpy(SAM_lib_path, dir);
        strcat(SAM_lib_path, SAM_lib);

        Py_DECREF(ascii_mystring);
        Py_XDECREF(file);
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