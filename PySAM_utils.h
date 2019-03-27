#ifndef PYSAM_SAM_UTILS_H
#define PYSAM_SAM_UTILS_H

#include <Python.h>

#define SAM_GROUP_ATTR(name, tech) \
if (self == NULL) return NULL; self->data_ptr = ptr; \
PyObject* attr_dict = PyDict_New(); Py_XINCREF(attr_dict); self->x_attr = attr_dict; \
PyDict_SetItemString(attr_dict, "name", PyUnicode_FromString(name)); \
PyDict_SetItemString(attr_dict, "technology", PyUnicode_FromString(tech));



#define ERROR_CHECK(error_type) \
const char* c = error_message(error); \
if ((c != NULL) && (c[0] != '\0')) { PyErr_SetString(PyExc_RuntimeError, c); \
    error_destruct(error); return error_type; } error_destruct(error); \



#define SAM_FLOAT_GETTER(func) \
double val; SAM_error error = new_error(); \
val = (*func)(self->data_ptr, &error); \
ERROR_CHECK(NULL) \
PyObject* result = PyFloat_FromDouble(val); \
Py_INCREF(result); return result;



#define SAM_FLOAT_SETTER(func) \
if (value == NULL) { PyErr_SetString(PyExc_TypeError, "No value provided"); return -1;} \
if (!PyNumber_Float(value)) { PyErr_SetString(PyExc_TypeError, "Value must be numeric"); return -1; } \
float val = (float)PyFloat_AsDouble(value); SAM_error error = new_error(); \
(*func)(self->data_ptr, val, &error); \
ERROR_CHECK(-1) return 0; \



#define SAM_TECH_ATTR(tech, ctor) \
if (self == NULL) return NULL; SAM_error error = new_error(); self->data_ptr = (*ctor)(0, &error); \
ERROR_CHECK(NULL) \
PyObject* attr_dict = PyDict_New(); Py_XINCREF(attr_dict); self->x_attr = attr_dict; \
PyDict_SetItemString(attr_dict, "technology", PyUnicode_FromString(tech));



#define SAM_GET_ATTR() \
if (self->x_attr != NULL) { PyObject *v = PyDict_GetItemWithError(self->x_attr, name); \
    if (v != NULL) { Py_INCREF(v); return v; } \
    else if (PyErr_Occurred()) { return NULL; }  \
    return PyObject_GenericGetAttr((PyObject *)self, name); }



#define SAM_SET_ATTR() \
if (self->x_attr == NULL) { self->x_attr = PyDict_New(); \
    if (self->x_attr == NULL) return -1; } \
if (v == NULL) { int rv = PyDict_DelItemString(self->x_attr, name); \
    if (rv < 0 && PyErr_ExceptionMatches(PyExc_KeyError)) \
    PyErr_SetString(PyExc_AttributeError, "delete non-existing attribute"); return rv; } \
else return PyDict_SetItemString(self->x_attr, name, v);

#endif //PYSAM_SAM_UTILS_H
