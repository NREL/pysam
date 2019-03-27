/*
 * Generic System technology consists of modules:
 *      - PowerPlant
 *      - Common
 */

#include <Python.h>

#include "SAM_api.h"
#include "SAM_GenericSystem.h"

static PyObject *ErrorObject;


// construct
static PyObject *
PowerPlant_construct(PyObject *self, PyObject *args, PyObject *keywds)
{
    SAM_GenericSystem ptr = SAM_GenericSystem_construct(0, 0);
    SAM_GenericSystem_PowerPlant_derate_set(ptr, 0, 0);

    Py_RETURN_NONE;
}



// Method set_derate
static PyObject *
PowerPlant_set_derate(PyObject *self, PyObject *args, PyObject *keywds)
{
    int voltage;
    const char *state = "a stiff";
    const char *action = "voom";
    const char *type = "Norwegian Blue";

    static char *kwlist[] = {"voltage", "state", "action", "type", NULL};

    if (!PyArg_ParseTupleAndKeywords(args, keywds, "i|sss", kwlist,
                                     &voltage, &state, &action, &type))
        return NULL;

    printf("-- This parrot wouldn't %s if you put %i Volts through it.\n",
           action, voltage);
    printf("-- Lovely plumage, the %s -- It's %s!\n", type, state);

    Py_RETURN_NONE;
}

static PyMethodDef PowerPlant_methods[] = {
        /* The cast of the function is necessary since PyCFunction values
         * only take two PyObject* parameters, and keywdarg_parrot() takes
         * three.
         */
        {"set_derate", (PyCFunction)PowerPlant_set_derate, METH_VARARGS | METH_KEYWORDS,
                        "Set the derate in units..."},
        {"construct", (PyCFunction)PowerPlant_construct, METH_VARARGS | METH_KEYWORDS,
                        "Construct a PowerPlant"},
        {NULL, NULL, 0, NULL}   /* sentinel */
};


// Generic System Module Definition
static struct PyModuleDef PowerPlantmodule = {
        PyModuleDef_HEAD_INIT,
        "PowerPlant",
        NULL,
        -1,
        PowerPlant_methods
};

PyMODINIT_FUNC
PyInit_PowerPlant(void)
{
    return PyModule_Create(&PowerPlantmodule);
}