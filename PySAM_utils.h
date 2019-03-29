#ifndef PYSAM_SAM_UTILS_H
#define PYSAM_SAM_UTILS_H

#include <Python.h>

static char* SAM_lib_path = NULL;
#if defined(__WINDOWS__) || defined(__CYGWIN__)
static const char SAM_sep = '\\';
static char* SAM_lib = "SAM_apid.lib";
#else
static const char SAM_sep = '/';
static char* SAM_lib = "libSAM_apid.so";
#endif

static PyObject *SAM_ErrorObject;




#define SAM_GROUP_ATTR(name, tech) \
if (self == NULL) return NULL; self->data_ptr = ptr; \
PyObject* attr_dict = PyDict_New(); Py_XINCREF(attr_dict); self->x_attr = attr_dict; \
PyDict_SetItemString(attr_dict, "name", PyUnicode_FromString(name)); \
PyDict_SetItemString(attr_dict, "technology", PyUnicode_FromString(tech));



#define SAM_TECH_ATTR(tech, ctor) \
if (self == NULL) return NULL; SAM_error error = new_error(); self->data_ptr = (*ctor)(0, &error); \
if (has_error(&error)) return NULL; \
PyObject* attr_dict = PyDict_New(); Py_XINCREF(attr_dict); self->x_attr = attr_dict; \
PyDict_SetItemString(attr_dict, "technology", PyUnicode_FromString(tech));




static int has_error(SAM_error* error){
    const char* cc = error_message(*error);
    if ((cc != NULL) && (cc[0] != '\0')) {
        PyErr_SetString(SAM_ErrorObject, cc);
        error_destruct(*error);
        return 1;
    }
    error_destruct(*error);
    return 0;
}



#define SAM_FLOAT_GETTER(func) \
double val; SAM_error error = new_error(); \
val = (*func)(self->data_ptr, &error); \
if (has_error(&error)) return NULL;  \
PyObject* result = PyFloat_FromDouble(val); \
return result;



#define SAM_FLOAT_SETTER(func) \
if (value == NULL) { PyErr_SetString(PyExc_TypeError, "No value provided"); return -1;} \
if (!PyNumber_Float(value)) { PyErr_SetString(PyExc_TypeError, "Value must be numeric"); return -1; } \
float val = (float)PyFloat_AsDouble(value); SAM_error error = new_error(); \
(*func)(self->data_ptr, val, &error); \
if (has_error(&error)) return -1;  return 0; \



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
