#ifndef PYSAM_SAM_UTILS_H
#define PYSAM_SAM_UTILS_H

#include <Python.h>

//
// Runtime linking to SAM shared library
//

static char* SAM_lib_path = NULL;
#if defined(__WINDOWS__) || defined(__CYGWIN__)
static const char SAM_sep = '\\';
static char* SAM_lib = "SAM_apid.lib";
#else
static const char SAM_sep = '/';
static char* SAM_lib = "libSAM_apid.so";
#endif

static void* SAM_lib_handle = NULL;

//
// Error Handling
//

static PyObject *SAM_ErrorObject;

static int SAM_has_error(SAM_error error){
    printf("step1a\n");
    const char* cc = error_message(error);
    printf("step2a: %s, %c\n", cc, cc[0]);

    if ((cc != NULL) && (cc[0] != '\0')) {
        printf("step3a\n");

        PyErr_SetString(SAM_ErrorObject, cc);
        printf("step4a\n");

        error_destruct(error);
        printf("step5a\n");

        return 1;
    }
    printf("step6a\n");
    error_destruct(error);
    printf("step7a\n");


    return 0;
}

static int SAM_has_error_msg(SAM_error error, const char* msg){
    printf("step1b, %s\n", msg);

    const char* cc = error_message(error);
    printf("step2b\n");

    if ((cc != NULL) && (cc[0] != '\0')) {
        printf("step3b\n");
        char err_msg[256];
        strncat(err_msg, cc, strlen(err_msg) - 1);
        printf("step4b\n");
        strncat(err_msg, ". ", 2);
        strncat(err_msg, msg, strlen(msg));
        printf("step5b\n");
        PyErr_SetString(SAM_ErrorObject, err_msg);
        printf("step6b\n");
        error_destruct(error);
        printf("step7b\n");
        return 1;
    }
    printf("step8b\n");
    error_destruct(error);
    printf("step9b\n");
    return 0;
}

//
// Macros for defining attribute dictionaries and methods
//

#define SAM_GROUP_ATTR(name, tech) \
if (self == NULL) return NULL; self->data_ptr = ptr; \
PyObject* attr_dict = PyDict_New(); self->x_attr = attr_dict; \
PyDict_SetItemString(attr_dict, "name", PyUnicode_FromString(name)); \
PyDict_SetItemString(attr_dict, "technology", PyUnicode_FromString(tech));

#define SAM_TECH_ATTR(tech, ctor) \
if (self == NULL) return NULL; SAM_error error = new_error(); self->data_ptr = (*ctor)(0, &error); \
if (SAM_has_error(error)) return NULL; \
PyObject* attr_dict = PyDict_New(); self->x_attr = attr_dict; \
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

//
// Macros for defining SAM attributes getters and setters
//

#define SAM_FLOAT_GETTER(func) \
double val; SAM_error error = new_error(); \
val = (*func)(self->data_ptr, &error); \
if (SAM_has_error(error)) return NULL;  \
PyObject* result = PyFloat_FromDouble(val); Py_XINCREF(result);\
return result;

#define SAM_FLOAT_SETTER(func) \
if (value == NULL) { PyErr_SetString(PyExc_TypeError, "No value provided"); return -1;} \
if (!PyNumber_Float(value)) { PyErr_SetString(PyExc_TypeError, "Value must be numeric"); return -1; } \
float val = (float)PyFloat_AsDouble(value); SAM_error error = new_error(); \
(*func)(self->data_ptr, val, &error); \
if (SAM_has_error(error)) return -1;  return 0; \

//
// Methods for assigning class attributes from a dictionary
//

char* SAM_concat_msg(const char* first, char* second){
    char* str = (char*) malloc(strlen(first) + strlen(second) + 1);
    memcpy(str, first, strlen(first));
    strncat(str, second, strlen(second));
    return str;
}

static int SAM_assign_from_dict(void* data_ptr, PyObject* dict, const char* tech, const char* group){
    if (SAM_lib_handle == NULL){
        SAM_error error = new_error();
        SAM_lib_handle = SAM_load_library(SAM_lib_path, &error);
        if (SAM_has_error(error)) return 0;
    }
    Py_INCREF(dict);

    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    while (PyDict_Next(dict, &pos, &key, &value)){
        PyObject* ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        // numeric
        if (PyNumber_Check(value)){
            SAM_error error = new_error();
            SAM_set_float_t func = SAM_set_float_func(SAM_lib_handle, "GenericSystem", "PowerPlant", name, &error);
            if (SAM_has_error_msg(error, "Either parameter does not exist or is not numeric type.")) return 0;

            float val = (float)PyFloat_AsDouble(value);

            error = new_error();
            func(data_ptr, val, &error);
            if (SAM_has_error(error)) return 0;
        }
        // sequences
        else if (PySequence_Check(value)){
            PyObject* first = PySequence_GetItem(value, 0);
            if (!first){
                char* str = SAM_concat_msg("Error assigning empty tuple to ", name);
                PyErr_SetString(SAM_ErrorObject, str);
                free(str);
                Py_XDECREF(first);
                return 0;
            }

            Py_ssize_t n = PySequence_Size(value);

            // matrix
            if (PySequence_Check(first)){
                SAM_error error = new_error();
                SAM_set_matrix_t func = SAM_set_matrix_func(SAM_lib_handle, "GenericSystem", "PowerPlant", name, &error);
                if (SAM_has_error_msg(error, "Either parameter does not exist or is not matrix type.")) return 0;

                Py_ssize_t cols = PySequence_Size(first);
                float* mat = malloc(n*cols*sizeof(float));

                for (Py_ssize_t i = 0; i < n; i++){
                    PyObject* row = PySequence_GetItem(value, i);

                    if (PySequence_Size(row) != cols){
                        char* str = SAM_concat_msg(name, " matrix must be rectangular");
                        PyErr_SetString(SAM_ErrorObject, str);
                        free(str);
                        return 0;
                    }
                    for (Py_ssize_t j = 0; j < cols; j++){
                        PyObject* val_o = PySequence_GetItem(row, j);

                        if (!PyNumber_Check(val_o)){
                            char* str = SAM_concat_msg(name, " must have numeric matrix entries.");
                            PyErr_SetString(SAM_ErrorObject, str);
                            free(str);
                            Py_XDECREF(val_o);
                            return 0;
                        }
                        float val = (float)PyFloat_AsDouble(val_o);
                        Py_XDECREF(val_o);
                        mat[i * cols + j] = val;

                    }
                    Py_XDECREF(row);
                }

                error = new_error();
                func(data_ptr, mat, (int)n, (int)cols, &error);
                if (SAM_has_error(error)) return 0;

                free(mat);
            }
            // array
            else{
                SAM_error error = new_error();
                SAM_set_array_t func = SAM_set_array_func(SAM_lib_handle, "GenericSystem", "PowerPlant", name, &error);
                if (SAM_has_error_msg(error, "Either parameter does not exist or is not array type.")) return 0;

                float* arr = malloc(n*sizeof(float));

                printf("here\n");

                for (Py_ssize_t i = 0; i < n; i++){
                    PyObject* val_o = PySequence_GetItem(value, i);
                    Py_XINCREF(val_o);

                printf("her2\n");
                    float val = (float)PyFloat_AsDouble(val_o);

                                printf("her3\n");
                    if (PyErr_Occurred()){
                                printf("her4\n");
                        char* str = SAM_concat_msg(name, " array entries must be convertable to numbers");
                printf("her5\n");
                        PyErr_SetString(SAM_ErrorObject, str);
                                printf("her6\n");
                        if (str) free(str);
                                                        printf("her7\n");

                        Py_XDECREF(val_o);

                                                    printf("her8\n");
                        return 0;
                    }

                    Py_XDECREF(val_o);
                                                    printf("her9\n");

                    arr[i] = val;
                                                    printf("her10\n");

                }


                error = new_error();

                func(data_ptr, arr, (int)n, &error);

                if (SAM_has_error(error)) return 0;

                free(arr);

            }
        }
        // string
        else if (PyUnicode_Check(value)){
            SAM_error error = new_error();
            SAM_set_string_t func = SAM_set_string_func(SAM_lib_handle, "GenericSystem", "PowerPlant", name, &error);
            if (SAM_has_error_msg(error, "Either parameter does not exist or is not ascii string.")) return 0;

            PyObject* ascii_val = PyUnicode_AsASCIIString(value);
            char* val = PyBytes_AsString(ascii_val); \

            error = new_error();
            func(data_ptr, val, &error);
            if (SAM_has_error(error)) return 0;

            Py_DECREF(ascii_val);
        }
        else {
            char* str = SAM_concat_msg(name, " assignment value must be numeric, string or tuple.");
            PyErr_SetString(SAM_ErrorObject, str);
            free(str);
            return 0;
        }
        Py_DECREF(ascii_mystring);
    }
    Py_XDECREF(dict);
    return 1;
}

//
// Methods for reading class attributes into a dictionary
//

static PyObject *
SAM_export_to_dict(void *data_ptr, PyObject *self, PyTypeObject *tp, const char *tech, const char *group) {

    if (SAM_lib_handle == NULL){
        SAM_error error = new_error();
        SAM_lib_handle = SAM_load_library(SAM_lib_path, &error);
        if (SAM_has_error(error)) return 0;
    }
    printf("export1\n");

    PyObject* export = PyDict_New();
    if (!export){
        PyErr_NoMemory();
        return NULL;
    }
    printf("export2\n");

    PyGetSetDef* getset = tp->tp_getset;
    while(getset->name){
        PyObject* val = (*getset->get)(self, NULL);
        PyDict_SetItemString(export, getset->name, val);
        getset++;
    }

    printf("export3\n");

    return export;
}


#endif //PYSAM_SAM_UTILS_H
