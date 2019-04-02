#ifndef PYSAM_SAM_UTILS_H
#define PYSAM_SAM_UTILS_H

#include <Python.h>
#include <stdio.h>
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

static PyObject *PySAM_ErrorObject;

static int PySAM_has_error(SAM_error error){
    const char* cc = error_message(error);
    if ((cc != NULL) && (cc[0] != '\0')) {
        PyErr_SetString(PySAM_ErrorObject, cc);
        error_destruct(error);
        return 1;
    }
    error_destruct(error);
    return 0;
}

static int PySAM_has_error_msg(SAM_error error, const char *msg){
    const char* cc = error_message(error);
    if ((cc != NULL) && (cc[0] != '\0')) {
        char err_msg[256];
        strncat(err_msg, cc, strlen(err_msg) - 1);
        strncat(err_msg, ". ", 2);
        strncat(err_msg, msg, strlen(msg));
        PyErr_SetString(PySAM_ErrorObject, err_msg);
        error_destruct(error);
        return 1;
    }
    error_destruct(error);
    return 0;
}

static void PySAM_concat_msg(char *dest, const char *first, char *second) {
    memcpy(dest, first, strlen(first));
    strncat(dest, second, strlen(second));
}

//
// Macros for defining attribute dictionaries and methods
//

#define PySAM_TECH_ATTR(tech, ctor) \
if (self == NULL) return NULL; SAM_error error = new_error(); \
if(!data_ptr) self->data_ptr = (*ctor)(0, &error); else self->data_ptr = data_ptr; \
if (PySAM_has_error(error)) return NULL; \
PyObject* attr_dict = PyDict_New(); self->x_attr = attr_dict; \
PyDict_SetItemString(attr_dict, "technology", PyUnicode_FromString(tech));

#define PySAM_GET_ATTR() \
if (self->x_attr != NULL) { PyObject *v = PyDict_GetItemWithError(self->x_attr, name); \
    if (v != NULL) { Py_INCREF(v); return v; } \
    else if (PyErr_Occurred()) { return NULL; }  \
    return PyObject_GenericGetAttr((PyObject *)self, name); }

#define PySAM_SET_ATTR() \
if (self->x_attr == NULL) { self->x_attr = PyDict_New(); \
    if (self->x_attr == NULL) return -1; } \
if (v == NULL) { int rv = PyDict_DelItemString(self->x_attr, name); \
    if (rv < 0 && PyErr_ExceptionMatches(PyExc_KeyError)) \
    PyErr_SetString(PyExc_AttributeError, "delete non-existing attribute"); return rv; } \
else return PyDict_SetItemString(self->x_attr, name, v);

//
// Functions for converting between Python and C types
//

static int PySAM_seq_to_array(PyObject *value, float **arr, int *seqlen){
    PyObject* seq;
    int i;

    seq = PySequence_Fast(value, "argument must be iterable");
    if(!seq)
        return -1;

    *seqlen = PySequence_Fast_GET_SIZE(seq);
    *arr = malloc(*seqlen*sizeof(float));
    if(!*arr) {
        Py_DECREF(seq);
        PyErr_NoMemory(  );
        return -2;
    }
    for(i=0; i < *seqlen; i++) {
        PyObject *fitem;
        PyObject *item = PySequence_Fast_GET_ITEM(seq, i);
        if(!item) {
            Py_DECREF(seq);
            free(*arr);
            return -3;
        }
        if(!PyNumber_Check(item)) {
            Py_DECREF(seq);
            free(*arr);
            PyErr_SetString(PyExc_TypeError, "all items must be numbers");
            return -4;
        }
        fitem = PyNumber_Float(item);
        (*arr)[i] = (float)PyFloat_AS_DOUBLE(fitem);
        Py_DECREF(fitem);
    }

    Py_DECREF(seq);
    return 0;
}

static int PySAM_seq_to_matrix(PyObject *value, float **mat, int *nrows, int *ncols){
    PyObject* seq, *row;
    int i, j;

    seq = PySequence_Fast(value, "argument must be iterable");
    if(!seq)
        return -1;

    *nrows = PySequence_Fast_GET_SIZE(seq);
    row = PySequence_Fast_GET_ITEM(seq, 0);
    *ncols = PySequence_Fast_GET_SIZE(row);
    *mat = malloc((*nrows)*(*ncols)*sizeof(float));
    if(!*mat) {
        Py_DECREF(seq);
        Py_DECREF(row);
        PyErr_NoMemory(  );
        return -2;
    }
    for(i=0; i < *nrows; i++) {
        row = PySequence_Fast_GET_ITEM(seq, i);
        if (PySequence_Fast_GET_SIZE(row) != *ncols){
            PyErr_SetString(PyExc_TypeError, "Matrix must be rectangular.");
            return -6;
        }
        for(j=0; j < *ncols; j++) {
            PyObject *fitem;
            PyObject *item = PySequence_Fast_GET_ITEM(row, j);
            if(!item) {
                Py_DECREF(seq);
                Py_DECREF(row);
                free(*mat);
                return -3;
            }
            if(!PyNumber_Check(item)) {
                Py_DECREF(seq);
                Py_DECREF(row);
                free(*mat);
                PyErr_SetString(PyExc_TypeError, "all items must be numbers");
                return -4;
            }
            fitem = PyNumber_Float(item);
            (*mat)[i * (*ncols) + j] = (float)PyFloat_AS_DOUBLE(fitem);
            Py_DECREF(fitem);
        }
    }
    Py_DECREF(seq);
    Py_DECREF(row);
    return 0;
}

static PyObject* PySAM_table_to_dict(SAM_table table){
    int size, s = 0, i = 0, j=0;

    const char* str;
    float num;
    const float* arr;
    int n, m;

    SAM_error error = new_error();
    size = SAM_table_size(table, &error);
    if (PySAM_has_error(error)) return NULL;

    PyObject* table_dict = PyDict_New();
    PyObject* seq, *seqq;
    SAM_table data = NULL;
    for(s=0; s < size; s++) {
        int type;
        const char* key = SAM_table_key(table, s, &type, NULL);
        error = new_error();

        switch(type){
            case SAM_STRING:
                str = SAM_table_read_string(table, key, &error);
                if (PySAM_has_error(error)) return NULL;
                PyDict_SetItemString(table_dict, key, PyUnicode_FromString(str));
                break;
            case SAM_NUMBER:
                num = SAM_table_read_num(table, key, &error);
                if (PySAM_has_error(error)) return NULL;
                PyDict_SetItemString(table_dict, key, PyLong_FromDouble((double)num));
                break;
            case SAM_ARRAY:
                arr = SAM_table_read_array(table, key, &n, &error);
                seq = PyTuple_New(n);
                for(i=0; i < n; i++) {
                    PyTuple_SET_ITEM(seq, i, PyFloat_FromDouble(arr[i]));
                }
                if (PySAM_has_error(error)) return NULL;
                PyDict_SetItemString(table_dict, key, seq);
                break;
            case SAM_MATRIX:
                arr = SAM_table_read_matrix(table, key, &n, &m, &error);

                seq = PyTuple_New(n);
                for(i=0; i < n; i++) {
                    seqq = PyTuple_New(m);
                    for(j=0; j < m; j++) {
                        PyTuple_SET_ITEM(seqq, j, PyFloat_FromDouble(arr[i * m + j]));
                    }
                    PyTuple_SET_ITEM(seq, i, seqq);
                }
                if (PySAM_has_error(error)) return NULL;
                PyDict_SetItemString(table_dict, key, seq);
                break;
            case SAM_TABLE:
                data = SAM_table_get_table(table, key, &error);
                seq = PySAM_table_to_dict(data);
                if (PySAM_has_error(error)) return NULL;
                PyDict_SetItemString(table_dict, key, seq);
                break;
            case SAM_INVALID:
            default:
                PyErr_SetString(PySAM_ErrorObject, "Table contains entry with invalid type.");
                goto fail;
        }
    }
    return table_dict;
    fail:
    Py_XDECREF(table_dict);
    error_destruct(error);
    return NULL;
}


static SAM_table PySAM_dict_to_table(PyObject* dict){
    PyObject* key, *value;
    Py_ssize_t pos = 0;

    SAM_table table = SAM_table_construct(NULL);
    if (!table){
        PyErr_NoMemory();
        return NULL;
    }

    PyObject* ascii_mystring, *first;
    while (PyDict_Next(dict, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        // numeric
        if (PyNumber_Check(value)){
            float val = (float)PyFloat_AsDouble(value);

            SAM_error error = new_error();
            SAM_table_set_num(table, name, val, &error);
            if (PySAM_has_error(error)) goto fail;
        }
        // string
        else if (PyUnicode_Check(value)){
            PyObject* ascii_val = PyUnicode_AsASCIIString(value);
            char* val = PyBytes_AsString(ascii_val);

            SAM_error error = new_error();
            SAM_table_set_string(table, name, val, &error);
            if (PySAM_has_error(error)){
                Py_DECREF(ascii_val);
                goto fail;
            }
            Py_DECREF(ascii_val);
        }
        // sequences
        else if (PySequence_Check(value)){
            first = PySequence_GetItem(value, 0);
            if (!first){
                char str[256];
                PySAM_concat_msg(str, "Error assigning empty tuple to ", name);
                PyErr_SetString(PySAM_ErrorObject, str);
                goto fail;
            }

            // matrix
            if (PySequence_Check(first)){
                float* mat;
                int nrows, ncols;
                if(PySAM_seq_to_matrix(value, &mat, &nrows, &ncols) < 0){
                    goto fail;
                }
                SAM_error error = new_error();
                SAM_table_set_matrix(table, name, mat, nrows, ncols, &error);
                if (PySAM_has_error(error)) goto fail;
            }
            // array
            else{
                float* arr;
                int seqlen;
                if(PySAM_seq_to_array(value, &arr, &seqlen) < 0)
                    goto fail;
                SAM_error error = new_error();
                SAM_table_set_array(table, name, arr, seqlen, &error);
                if (PySAM_has_error(error)) goto fail;
            }
            Py_XDECREF(first);
        }
        else {
            SAM_table data_tab = PySAM_dict_to_table(value);
            if (!data_tab)
                return NULL;
            SAM_error error = new_error();
            SAM_table_set_table(table, name, data_tab, &error);
            if (PySAM_has_error(error)) goto fail;
        }
        Py_DECREF(ascii_mystring);
    }
    return table;
    fail:
    Py_DECREF(ascii_mystring);
    Py_XDECREF(first);
    SAM_table_destruct(table, NULL);
    return NULL;
}

//
// Functions for defining SAM attributes getters and setters
//

static PyObject* PySAM_float_getter(SAM_get_float_t func, void *data_ptr){
    double val;
    SAM_error error = new_error();
    val = (func)(data_ptr, &error);
    if (PySAM_has_error(error))
        return NULL;
    PyObject* result = PyFloat_FromDouble(val);
    Py_XINCREF(result);
    return result;
}

static int PySAM_float_setter(PyObject *value, SAM_set_float_t func, void *data_ptr) {
    if (value == NULL) {
        PyErr_SetString(PyExc_TypeError, "No value provided");
        return -1;
    }
    if (!PyNumber_Float(value)) {
        PyErr_SetString(PyExc_TypeError, "Value must be numeric");
        return -1;
    }

    float val = (float)PyFloat_AsDouble(value);

    SAM_error error = new_error();
    (*func)(data_ptr, val, &error);
    if (PySAM_has_error(error))
        return -1;
    return 0;
}

static PyObject* PySAM_string_getter(SAM_get_string_t func, void *data_ptr){
    const char* val;
    SAM_error error = new_error();
    val = (func)(data_ptr, &error);
    if (PySAM_has_error(error))
        return NULL;
    PyObject* result = PyUnicode_FromString(val);
    Py_XINCREF(result);
    return result;
}

static int PySAM_string_setter(PyObject *value, SAM_set_string_t func, void *data_ptr) {
    if (value == NULL) {
        PyErr_SetString(PyExc_TypeError, "No value provided");
        return -1;
    }
    if (!PyUnicode_Check(value)) {
        PyErr_SetString(PyExc_TypeError, "Value must be string");
        return -1;
    }
    PyObject* ascii_mystring = PyUnicode_AsASCIIString(value);
    char* val = PyBytes_AsString(ascii_mystring);

    SAM_error error = new_error();
    (*func)(data_ptr, val, &error);
    Py_XDECREF(ascii_mystring);
    if (PySAM_has_error(error))
        return -1;
    return 0;
}

static PyObject* PySAM_array_getter(SAM_get_array_t func,void *data_ptr){
    float* arr;
    int seqlen;
    int i = 0;

    SAM_error error = new_error();
    arr = (*func)(data_ptr, &seqlen, &error);
    if (PySAM_has_error(error)) return NULL;

    PyObject* seq = PyTuple_New(seqlen);
    for(i=0; i < seqlen; i++) {
        PyTuple_SET_ITEM(seq, i, PyFloat_FromDouble(arr[i]));
    }
    return seq;
}


static int PySAM_array_setter(PyObject *value, SAM_set_array_t func, void *data_ptr) {
    float* arr = NULL;
    int seqlen;
    int res = PySAM_seq_to_array(value, &arr, &seqlen);

    if (res < 0) return res;

    SAM_error error = new_error();
    (*func)(data_ptr, arr, seqlen, &error);

    if (PySAM_has_error(error)){
        free(arr);
        return -5;
    }
    free(arr);
    return 0;
}

static PyObject* PySAM_matrix_getter(SAM_get_matrix_t func,void *data_ptr){
    float* mat;
    int rows, cols;
    int i = 0, j = 0;

    SAM_error error = new_error();
    mat = (*func)(data_ptr, &rows, &cols, &error);
    if (PySAM_has_error(error)) return NULL;

    PyObject* seq = PyTuple_New(rows);
    for(i=0; i < rows; i++) {
        PyObject* row = PyTuple_New(cols);
        for (j = 0; j < cols; j++)
            PyTuple_SET_ITEM(row, j, PyFloat_FromDouble(mat[i * cols + j]));
        PyTuple_SET_ITEM(seq, i, row);
    }
    return seq;
}



static int PySAM_matrix_setter(PyObject *value, SAM_set_matrix_t func, void *data_ptr){
    Py_ssize_t rows = PySequence_Size(value);
    Py_ssize_t cols = PySequence_Size(PySequence_GetItem(value, 0));

    float* mat = malloc(rows*cols*sizeof(float));

    for (Py_ssize_t i = 0; i < rows; i++){
        PyObject* row = PySequence_GetItem(value, i);

        if (PySequence_Size(row) != cols){
            PyErr_SetString(PyExc_TypeError, "matrix must be rectangular");
            free(mat);
            return -6;
        }

        float* arr = NULL;
        int seqlen;

        int res = PySAM_seq_to_array(row, &arr, &seqlen);
        if (res < 0) return res;

        memcpy(&mat[i * cols], arr, cols* sizeof(float));

        free(arr);
        Py_XDECREF(row);
    }

    SAM_error error = new_error();
    func(data_ptr, mat, (int)rows, (int)cols, &error);
    if (PySAM_has_error(error)){
        free(mat);
        return -5;
    }
    free(mat);
    return 0;
}

static PyObject* PySAM_table_getter(SAM_get_table_t func,void *data_ptr){
    SAM_table table;
    SAM_error error = new_error();
    table = (*func)(data_ptr, &error);
    if (PySAM_has_error(error)) return NULL;

    return PySAM_table_to_dict(table);
}

static int PySAM_table_setter(PyObject *value, SAM_set_table_t func, void *data_ptr){
    if (!PyDict_Check(value)){
        PyErr_SetString(PyExc_TypeError, "Table must be set from dict.");
        return -1;
    }

    SAM_table table = PySAM_dict_to_table(value);


    if(!table) return -2;

    SAM_error error = new_error();
    (*func)(data_ptr, table, &error);

    if (PySAM_has_error(error)){
        SAM_table_destruct(table, NULL);
        return -5;
    }

    return 0;
}


//
// Methods for assigning class attributes from a dictionary
//

static int PySAM_assign_from_dict(void *data_ptr, PyObject *dict, const char *tech, const char *group){
    if (SAM_lib_handle == NULL){
        SAM_error error = new_error();
        SAM_lib_handle = SAM_load_library(SAM_lib_path, &error);
        if (PySAM_has_error(error)) return 0;
    }
    Py_INCREF(dict);

    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;

    while (PyDict_Next(dict, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        // numeric
        if (PyNumber_Check(value)){
            SAM_error error = new_error();
            SAM_set_float_t func = SAM_set_float_func(SAM_lib_handle, tech, group, name, &error);
            if (PySAM_has_error_msg(error, "Either parameter does not exist or is not numeric type.")) goto fail;

            float val = (float)PyFloat_AsDouble(value);

            error = new_error();
            func(data_ptr, val, &error);
            if (PySAM_has_error(error)) goto fail;
        }
        // string
        else if (PyUnicode_Check(value)){
            SAM_error error = new_error();
            SAM_set_string_t func = SAM_set_string_func(SAM_lib_handle, tech, group, name, &error);
            if (PySAM_has_error_msg(error, "Either parameter does not exist or is not string.")) goto fail;

            PyObject* ascii_val = PyUnicode_AsASCIIString(value);
            char* val = PyBytes_AsString(ascii_val); \

            error = new_error();
            func(data_ptr, val, &error);
            if (PySAM_has_error(error)) goto fail;

            Py_DECREF(ascii_val);
        }
        // sequences
        else if (PySequence_Check(value)){
            PyObject* first = PySequence_GetItem(value, 0);
            if (!first){
                char str[256];
                PySAM_concat_msg(str, "Error assigning empty tuple to ", name);
                PyErr_SetString(PySAM_ErrorObject, str);
                Py_XDECREF(first);
                goto fail;
            }

            // matrix
            if (PySequence_Check(first)){
                SAM_error error = new_error();
                SAM_set_matrix_t func = SAM_set_matrix_func(SAM_lib_handle, tech, group, name, &error);
                if (PySAM_has_error_msg(error, "Either parameter does not exist or is not matrix type.")) goto fail;

                char str[256];
                switch(PySAM_matrix_setter(value, func, data_ptr)){
                    case 0: // no error
                        continue;
                    case -5:
                        goto fail;
                    case -1:
                        PySAM_concat_msg(str, name, " must be iterable.");
                        break;
                    case -2:
                        PySAM_concat_msg(str, name, " memory unavailble.");
                        break;
                    case -3:
                    case -4:
                        PySAM_concat_msg(str, name, " items must be numeric.");
                        break;
                }
                PyErr_SetString(PySAM_ErrorObject, str);
                goto fail;
            }
            // array
            else{
                SAM_error error = new_error();
                SAM_set_array_t func = SAM_set_array_func(SAM_lib_handle, tech, group, name, &error);
                if (PySAM_has_error_msg(error, "Either parameter does not exist or is not array type.")) goto fail;

                char str[256];
                switch(PySAM_array_setter(value, func, data_ptr)){
                    case 0: // no error
                        continue;
                    case -5:
                        goto fail;
                    case -1:
                        PySAM_concat_msg(str, name, "must be iterable.");
                        break;
                    case -2:
                        PySAM_concat_msg(str, name, " memory unavailble.");
                        break;
                    case -3:
                    case -4:
                        PySAM_concat_msg(str, name, " items must be numeric.");
                        break;
                    case -6:
                        PySAM_concat_msg(str, name, "must be iterable matrix must be rectangular.");
                        break;
                }
                PyErr_SetString(PySAM_ErrorObject, str);
                goto fail;
            }
        }
        else if (PyDict_Check(value)) {
            SAM_error error = new_error();
            SAM_set_table_t func = SAM_set_table_func(SAM_lib_handle, tech, group, name, &error);
            if (PySAM_has_error_msg(error, "Either parameter does not exist or is not table type.")) goto fail;

            SAM_table table = PySAM_dict_to_table(value);
            if (!table){
                goto fail;
            }

            error = new_error();
            func(data_ptr, table, &error);
            if (PySAM_has_error(error)) goto fail;

        }
        else {
            char str[256];
            PySAM_concat_msg(str, name, " assignment value must be numeric, string, tuple or dict.");
            PyErr_SetString(PySAM_ErrorObject, str);
            goto fail;
        }
        Py_DECREF(ascii_mystring);
    }
    Py_XDECREF(dict);
    return 1;
    fail:
    Py_XDECREF(ascii_mystring);
    Py_XDECREF(dict);
    return 0;
}

static int PySAM_assign_from_attr(PyObject* self, PyTypeObject* tp, PyObject* dict){
    if (SAM_lib_handle == NULL){
        SAM_error error = new_error();
        SAM_lib_handle = SAM_load_library(SAM_lib_path, &error);
        if (PySAM_has_error(error)) return 0;
    }

    PyGetSetDef* getset = tp->tp_getset;
    while(getset->name){
        printf("heree in PySAM_assign_from_attr %s\n", getset->name);

        PyObject* val = PyDict_GetItemString(dict, getset->name);
        if (val){
            (*getset->set)((PyObject*)self, val, NULL);
        }
        getset++;
    }
    return 1;
}

static int PySAM_assign_from_nested_dict(PyObject* self, PyObject* x_attr, void *data_ptr, PyObject *dict, const char *tech){
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;

    while (PyDict_Next(dict, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        if(!PyDict_Check(value)){
            PyErr_SetString(PyExc_TypeError, "Must assign Technology module attributes with nested dictionaries");
            return 0;
        }
        if (strcmp(name, "AdjustmentFactors") == 0){
            PyObject* adj_obj = PyDict_GetItemString(x_attr, "AdjustmentFactors");
            if (!PyObject_CallMethod(adj_obj, "assign", "(O)", value)){
                PyErr_SetString(PyExc_ImportError, "Could not call 'assign' from imported AdjustmentFactors module.");
                return -1;
            }
        }
        else if (!PySAM_assign_from_dict(data_ptr, value, tech, name))
            return 0;

    }
    Py_XDECREF(ascii_mystring);
    return 1;
}

//
// Methods for exporting class attributes into a dictionary
//

static PyObject *
PySAM_export_to_dict(PyObject *self, PyTypeObject *tp) {

    if (SAM_lib_handle == NULL){
        SAM_error error = new_error();
        SAM_lib_handle = SAM_load_library(SAM_lib_path, &error);
        if (PySAM_has_error(error)) return 0;
    }

    PyObject* export = PyDict_New();
    if (!export){
        PyErr_NoMemory();
        return NULL;
    }

    PyGetSetDef* getset = tp->tp_getset;
    while(getset->name){
        PyObject* val = (*getset->get)(self, NULL);

        if(val) PyDict_SetItemString(export, getset->name, val);
        else PyErr_Clear();    // clear error warning about unassigned value
        getset++;
    }

    return export;
}

static PyObject *
PySAM_export_to_nested_dict(PyObject *self, PyObject *x_attr, PyObject *export) {
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;

    while (PyDict_Next(x_attr, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        PyObject* tp = PyObject_Type(value);
        if(!tp){
            PyErr_SetString(PyExc_TypeError, "Attribute type error.");
            Py_XDECREF(ascii_mystring);
            return 0;
        }
        PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp->ob_type);
        if (!dict){
            Py_XDECREF(ascii_mystring);
            return NULL;
        }
        PyDict_SetItemString(export, name, dict);
        Py_XDECREF(ascii_mystring);
    }
    return export;
}
#endif //PYSAM_SAM_UTILS_H
