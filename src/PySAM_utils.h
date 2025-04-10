#ifndef PYSAM_SAM_UTILS_H
#define PYSAM_SAM_UTILS_H

#include <Python.h>
#include <marshal.h>
#include <stdio.h>
#include <ctype.h>

#if defined(__WINDOWS__)
#define strcasecmp _stricmp
#endif

//
// Structures for PySAM Classes (compute modules) and subclasses (variable groups)
//

typedef struct {
	PyObject_HEAD
	SAM_table   data_ptr;
} VarGroupObject;

typedef struct {
	PyObject_HEAD
	SAM_table data_ptr;
	PyObject *x_attr;        /* Attributes dictionary */
    PyObject *data_owner_ptr;     // NULL if owns data_ptr, otherwise pts to another PySAM object
} CmodObject;

typedef struct {
    PyObject_HEAD
    SAM_table data_ptr;
    PyObject *x_attr;        /* Attributes dictionary */
    PyObject *data_owner_ptr;     // NULL if owns data_ptr, otherwise pts to another PySAM object
    SAM_module cmod_ptr;
} CmodStatefulObject;

//
// Error Handling
//

static char *PySAM_error_context;

static void PySAM_error_context_clear(){
    if (PySAM_error_context) free(PySAM_error_context);
    PySAM_error_context = NULL;
}

static void PySAM_error_context_set(const char * msg){
    PySAM_error_context_clear();
    PySAM_error_context = malloc(strlen(msg) + 12);
    strcpy(PySAM_error_context, msg);
    char error_msg[] = " error: ";
    strcat(PySAM_error_context, error_msg);
}

static void PySAM_error_set_with_context(const char * msg){
    char err_msg[1024];
    if (PySAM_error_context) {
        strcpy(err_msg, PySAM_error_context);
        strcat(err_msg, msg);
        PyErr_SetString(PyExc_Exception, err_msg);
    }
    else
        PyErr_SetString(PyExc_Exception, msg);
}

static int PySAM_has_error(SAM_error error){
    const char* cc = error_message(error);
    if ((cc != NULL) && (cc[0] != '\0')) {
        PySAM_error_set_with_context(cc);
        error_destruct(error);
        return 1;
    }
    error_destruct(error);
    return 0;
}

static int PySAM_has_error_msg(SAM_error error, const char *msg){
    const char* cc = error_message(error);
    if ((cc != NULL) && (cc[0] != '\0')) {
        char err_msg[1024];
        strcpy(err_msg, cc);
        strcat(err_msg, ". ");
        strcat(err_msg, msg);
        PySAM_error_set_with_context(err_msg);
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
// Runtime linking to SAM shared library
//
static char* SAM_lib_dir = NULL;	// dir ends with '/'
static char* SAM_lib_path = NULL;
#if defined(__WINDOWS__) || defined(__CYGWIN__)
static const char SAM_sep = '\\';
static char* SAM_lib = "SAM_api.dll";
#else
static const char SAM_sep = '/';
static char* SAM_lib = "libSAM_api.so";
#endif

static void* SAM_lib_handle = NULL;

static int PySAM_load_lib(PyObject* m){
    if (!SAM_lib_path){
        PyObject* file = PyModule_GetFilenameObject(m);

        if (!file){
            PyErr_SetString(PyExc_Exception, "Could not get module filepath");
            Py_XDECREF(file);
            return -1;
        }
        PyObject* ascii_mystring = PyUnicode_AsASCIIString(file);
        char* filename = PyBytes_AsString(ascii_mystring);

        char* lastSlash = strrchr(filename, SAM_sep);

		SAM_lib_dir = malloc(strlen(filename) - strlen(lastSlash) + 2);
		memcpy(SAM_lib_dir, filename, strlen(filename) - strlen(lastSlash) + 1);
		SAM_lib_dir[strlen(filename) - strlen(lastSlash) + 1] = '\0';

        SAM_lib_path = malloc(strlen(SAM_lib_dir) + strlen(SAM_lib) + 1);

		memcpy(SAM_lib_path, SAM_lib_dir, strlen(SAM_lib_dir) + 1);
        strcat(SAM_lib_path, SAM_lib);

        PyObject *sys_path = PySys_GetObject("path");
        PyList_Append(sys_path, PyUnicode_FromString(SAM_lib_dir));

        Py_XDECREF(file);
        Py_XDECREF(ascii_mystring);
    }
    return 0;
}

static int PySAM_check_lib_loaded(){
    if (SAM_lib_handle == NULL){
        SAM_error error = new_error();
        SAM_lib_handle = SAM_load_library(SAM_lib_path, &error);
        if (PySAM_has_error(error)) return 0;
    }
    return 1;
}

//
// Macros for defining attribute dictionaries and methods
//

#define PySAM_TECH_ATTR() \
if (self == NULL) return NULL; SAM_error error = new_error(); \
if(!data_ptr) self->data_ptr = SAM_table_construct(&error); else self->data_ptr = data_ptr; \
if (PySAM_has_error(error)) return NULL; \
PyObject* attr_dict = PyDict_New(); self->x_attr = attr_dict;

#define PySAM_TECH_STATEFUL_ATTR(ctor) \
if (self == NULL) return NULL; SAM_error error = new_error(); \
if(!data_ptr) self->data_ptr = SAM_table_construct(&error); else self->data_ptr = data_ptr; \
if (PySAM_has_error(error)) return NULL; \
error = new_error(); self->cmod_ptr = ctor(self->data_ptr, &error); \
if (PySAM_has_error(error)) return NULL; \
PyObject* attr_dict = PyDict_New(); self->x_attr = attr_dict;

static PyObject * PySAM_get_attr(PyObject *self, PyObject* x_attr, PyObject *name){
    if (x_attr != NULL) {
        PyObject *v = PyDict_GetItemWithError(x_attr, name);
        if (v != NULL) {
            Py_INCREF(v);
            return v;
        }
        else if (PyErr_Occurred()) {
            return NULL;
        }
        return PyObject_GenericGetAttr((PyObject *)self, name);
    }
    return NULL;
}

static int PySAM_set_attr(PyObject *self, PyObject* x_attr, const char *name, PyObject *v){
    if (x_attr == NULL) {
        x_attr = PyDict_New();
        if (x_attr == NULL)
            return -1;
    }
    if (v == NULL) {
        int rv = PyDict_DelItemString(x_attr, name);
        if (rv < 0 && PyErr_ExceptionMatches(PyExc_KeyError))
            PyErr_SetString(PyExc_AttributeError, "delete non-existing attribute");
        return rv;
    }
    else
        return PyDict_SetItemString(x_attr, name, v);
}


//
// Functions for converting between Python and C types
//

static int PySAM_seq_to_array(PyObject *value, double **arr, int *seqlen){
    PyObject* seq;
    int i;

    seq = PySequence_Fast(value, "error converting tuple to array: argument must be iterable");
    if(!seq)
        return -1;

    *seqlen = (int)PySequence_Fast_GET_SIZE(seq);
    *arr = malloc(*seqlen*sizeof(double));
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
            PySAM_error_set_with_context("error converting tuple to array: could not get item");
            return -3;
        }
        if(!PyNumber_Check(item)) {
            Py_DECREF(seq);
            free(*arr);
            PySAM_error_set_with_context("error converting tuple to array: all items must be numbers");
            return -4;
        }
        fitem = PyNumber_Float(item);

        (*arr)[i] = PyFloat_AS_DOUBLE(fitem);
        Py_DECREF(fitem);
    }
    Py_DECREF(seq);
    return 0;
}

static int PySAM_seq_to_matrix(PyObject *value, double **mat, int *nrows, int *ncols){
    PyObject* seq, *row;
    int i;

    seq = PySequence_Fast(value, "argument must be iterable");
    if(!seq)
        return -1;

    row = PySequence_Fast_GET_ITEM(seq, 0);

    *nrows = (int)PySequence_Fast_GET_SIZE(seq);
    *ncols = (int)PySequence_Fast_GET_SIZE(row);

    *mat = malloc((*nrows)*(*ncols)*sizeof(double));
    double *arr = NULL;
    int seqlen;

    if(!*mat) {
        Py_DECREF(seq);
        PyErr_NoMemory(  );
        return -2;
    }
    for(i=0; i < *nrows; i++) {
        row = PySequence_Fast_GET_ITEM(seq, i);
        if (PySequence_Fast_GET_SIZE(row) != *ncols){
            free(*mat);
            Py_DECREF(seq);
            PySAM_error_set_with_context("Matrix must be rectangular.");
            return -6;
        }
        int res = PySAM_seq_to_array(row, &arr, &seqlen);
        if ( res < 0){
            free(*mat);
            Py_DECREF(seq);
            char str[256];
            sprintf(str, "Error (%d) converting nested tuple %d into row in matrix.", res, i);
            PySAM_error_set_with_context(str);
            return res;
        }
        double* mat_pos = &((*mat)[*ncols * i]);
        memcpy(mat_pos, arr, (*ncols)*sizeof(double));
        free(arr);
    }
    Py_DECREF(seq);
    return 0;
}

static PyObject* PySAM_table_to_dict(SAM_table table);

static PyObject* SAM_var_to_PyObject(SAM_var var){
    PyObject* result = NULL;
    SAM_error error = new_error();

    double num;
    const char* str;
    SAM_var v;
    const double* arr;
    SAM_table tab;
    int i, j, n, m;
    PyObject* seqq = NULL;
    int type = SAM_var_query(var, &error);

    if (PySAM_has_error(error)) return NULL;

    error = new_error();
    switch (type){
        case SAM_STRING:
            str = SAM_var_get_string(var, &error);
            if (PySAM_has_error(error)) return NULL;
            return PyUnicode_FromString(str);
            break;
        case SAM_NUMBER:
            num = SAM_var_get_number(var, &error);
            if (PySAM_has_error(error)) return NULL;
            return PyLong_FromDouble(num);
        case SAM_ARRAY:
            arr = SAM_var_get_arr(var, &n, &error);
            if (PySAM_has_error(error)) return NULL;
            result = PyTuple_New(n);
            for(i=0; i < n; i++) {
                PyTuple_SET_ITEM(result, i, PyFloat_FromDouble(arr[i]));
            }
            return result;
        case SAM_MATRIX:
            arr = SAM_var_get_mat(var, &n, &m, &error);
            if (PySAM_has_error(error)) return NULL;
            result = PyTuple_New(n);
            for(i=0; i < n; i++) {
                seqq = PyTuple_New(m);
                for(j=0; j < m; j++) {
                    PyTuple_SET_ITEM(seqq, j, PyFloat_FromDouble(arr[i * m + j]));
                }
                PyTuple_SET_ITEM(result, i, seqq);
            }
            return result;
        case SAM_TABLE:
            tab = SAM_var_get_table(var, &error);
            return PySAM_table_to_dict(tab);
        case SAM_DATARR:
            SAM_var_size(var, &n, NULL, &error);
            if (PySAM_has_error(error)) return NULL;
            result = PyTuple_New(n);
            for(i=0; i < n; i++) {
                error = new_error();
                v = SAM_var_get_datarr(var, i, &error);
                if (PySAM_has_error(error)) goto fail;
                PyTuple_SET_ITEM(result, i, SAM_var_to_PyObject(v));
            }
            return result;
        case SAM_DATMAT:
            SAM_var_size(var, &n, &m, &error);
            if (PySAM_has_error(error)) return NULL;
            result = PyTuple_New(n);
            for(i=0; i < n; i++) {
                seqq = PyTuple_New(m);
                for(j=0; j < m; j++) {
                    error = new_error();
                    v = SAM_var_get_datmat(var, i, j, &error);
                    if (PySAM_has_error(error)) goto fail;
                    PyTuple_SET_ITEM(seqq, j, SAM_var_to_PyObject(v));
                }
                PyTuple_SET_ITEM(result, i, seqq);
            }
            return result;
        default:
            return NULL;
    }
    fail:
    Py_XDECREF(result);
    Py_XDECREF(seqq);
    return NULL;
}

static PyObject* PySAM_table_to_dict(SAM_table table){
    int size, s = 0, i = 0, j=0;

    const char* str;
    double num;
    const double* arr;
    int n, m;

    SAM_error error = new_error();
    size = SAM_table_size(table, &error);
    if (PySAM_has_error(error)) return NULL;

    PyObject* table_dict = PyDict_New();
    PyObject* seq, *seqq, *obj;
    SAM_table data = NULL;
    SAM_var var = NULL;
    for(s=0; s < size; s++) {
        int type;
        error = new_error();
        const char* key = SAM_table_key(table, s, &type, &error);
        if (PySAM_has_error(error)) goto fail;
        error = new_error();

        switch(type){
            case SAM_STRING:
                str = SAM_table_get_string(table, key, &error);
                if (PySAM_has_error(error)) goto fail;
                PyObject* str_obj = PyUnicode_FromString(str);
                PyDict_SetItemString(table_dict, key, str_obj);
                Py_DECREF(str_obj);
                break;
            case SAM_NUMBER:
                num = SAM_table_get_num(table, key, &error);
                if (PySAM_has_error(error)) goto fail;
                PyObject* long_obj = PyFloat_FromDouble((double)num);
                PyDict_SetItemString(table_dict, key, long_obj);
                Py_DECREF(long_obj);
                break;
            case SAM_ARRAY:
                arr = SAM_table_get_array(table, key, &n, &error);
                if (PySAM_has_error(error)) goto fail;
                seq = PyTuple_New(n);
                for(i=0; i < n; i++) {
                    PyTuple_SET_ITEM(seq, i, PyFloat_FromDouble(arr[i]));
                }
                PyDict_SetItemString(table_dict, key, seq);
                Py_DECREF(seq);
                break;
            case SAM_MATRIX:
                arr = SAM_table_get_matrix(table, key, &n, &m, &error);

                if (PySAM_has_error(error)) goto fail;
                seq = PyTuple_New(n);
                for(i=0; i < n; i++) {
                    seqq = PyTuple_New(m);
                    for(j=0; j < m; j++) {
                        PyTuple_SET_ITEM(seqq, j, PyFloat_FromDouble(arr[i * m + j]));
                    }
                    PyTuple_SET_ITEM(seq, i, seqq);
                }
                PyDict_SetItemString(table_dict, key, seq);
                Py_XDECREF(seq);
                break;
            case SAM_TABLE:
                data = SAM_table_get_table(table, key, &error);
                if (PySAM_has_error(error)) goto fail;
                seq = PySAM_table_to_dict(data);
                PyDict_SetItemString(table_dict, key, seq);
                Py_DECREF(seq);
                break;
            case SAM_DATARR:
                var = SAM_table_get_datarr(table, key, &n, &error);

                if (PySAM_has_error(error)) goto fail;
                obj = SAM_var_to_PyObject(var);

                if (!obj) goto fail;
                PyDict_SetItemString(table_dict, key, obj);
                Py_DECREF(obj);
                break;
            case SAM_DATMAT:
                var = SAM_table_get_datmat(table, key, &n, &m, &error);
                if (PySAM_has_error(error)) goto fail;
                obj = SAM_var_to_PyObject(var);
                if (!obj) goto fail;
                PyDict_SetItemString(table_dict, key, obj);
                Py_DECREF(obj);
                break;
            case SAM_INVALID:
            default:
                PySAM_error_set_with_context("Table contains entry with invalid type. Types must be number, string"
                                                   ", sequence, or dict.");
                goto fail;
        }
    }
    return table_dict;
    fail:
    Py_XDECREF(table_dict);
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

    Py_INCREF(dict);
    PyObject* ascii_mystring, *first = NULL;

    double *mat = NULL;
    double *arr = NULL;
    SAM_table data_tab = NULL;
    while (PyDict_Next(dict, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        // numeric
        if (PyNumber_Check(value)){
            double val = PyFloat_AsDouble(value);

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
                PySAM_error_set_with_context(str);
                goto fail;
            }

            // matrix
            if (PySequence_Check(first)){
                int nrows, ncols;
                if(PySAM_seq_to_matrix(value, &mat, &nrows, &ncols) < 0){
                    goto fail;
                }
                SAM_error error = new_error();
                SAM_table_set_matrix(table, name, mat, nrows, ncols, &error);
                if (PySAM_has_error(error)) goto fail;
                free(mat);
            }
            // array
            else{
                int seqlen;
                if(PySAM_seq_to_array(value, &arr, &seqlen) < 0)
                    goto fail;
                SAM_error error = new_error();
                SAM_table_set_array(table, name, arr, seqlen, &error);
                if (PySAM_has_error(error)) goto fail;
                free(arr);
            }
            Py_XDECREF(first);
        }
        else {
            data_tab = PySAM_dict_to_table(value);

            if (!data_tab)
                return NULL;

            SAM_error error = new_error();
            SAM_table_set_table(table, name, data_tab, &error);
            if (PySAM_has_error(error)) goto fail;

            SAM_table_destruct(data_tab, NULL);
            data_tab = NULL;
        }
        Py_DECREF(ascii_mystring);
    }
    Py_XDECREF(dict);

    return table;
    fail:
    if (data_tab) SAM_table_destruct(data_tab, NULL);
    Py_XDECREF(dict);
    Py_DECREF(ascii_mystring);
    Py_XDECREF(first);
    if (table) SAM_table_destruct(table, NULL);
    return NULL;
}

//
// Functions for defining SAM attributes getters and setters
//

static PyObject* PySAM_double_getter(SAM_get_double_t func, void *data_ptr){
    double val;
    SAM_error error = new_error();
    val = (func)(data_ptr, &error);
    if (PySAM_has_error(error))
        return NULL;
    PyObject* result = PyFloat_FromDouble(val);
    return result;
}

static int PySAM_double_setter(PyObject *value, SAM_set_double_t func, void *data_ptr) {
    if (value == NULL) {
        PySAM_error_set_with_context("No value provided");
        return -1;
    }
    if (!PyNumber_Float(value)) {
        PySAM_error_set_with_context("Value must be numeric");
        return -1;
    }

    double val = PyFloat_AsDouble(value);

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
    return result;
}

static int PySAM_string_setter(PyObject *value, SAM_set_string_t func, void *data_ptr) {
    if (value == NULL) {
        PySAM_error_set_with_context("No value provided");
        return -1;
    }
    if (!PyUnicode_Check(value)) {
        PySAM_error_set_with_context("Value must be string");
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
    double* arr;
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
    double* arr = NULL;
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
    double* mat;
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

    int rows, cols;
    double* mat = NULL;
    int res = PySAM_seq_to_matrix(value, &mat, &rows, &cols);
    if (res < 0){
        return -1;
    }

    SAM_error error = new_error();
    func(data_ptr, mat, (int)rows, (int)cols, &error);
    if (PySAM_has_error(error)){
        free(mat);
        return -1;
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
        PySAM_error_set_with_context("Table must be set from dict.");
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
    if (!PySAM_check_lib_loaded()) return 0;

    Py_INCREF(dict);

    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;

    int existing_error_context = (PySAM_error_context != NULL);

    while (PyDict_Next(dict, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        if (!existing_error_context)
            PySAM_error_context_set(name);

        // numeric
        if (PyNumber_Check(value)){
            SAM_error error = new_error();
            SAM_set_double_t func = SAM_set_double_func(SAM_lib_handle, tech, group, name, &error);
            if (PySAM_has_error_msg(error, "Either parameter does not exist or is not numeric type.")) goto fail;

            double val = PyFloat_AsDouble(value);

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
                PySAM_error_set_with_context(str);
                Py_XDECREF(first);
                goto fail;
            }

            // matrix
            if (PySequence_Check(first)){
                SAM_error error = new_error();
                SAM_set_matrix_t func = SAM_set_matrix_func(SAM_lib_handle, tech, group, name, &error);
                if (PySAM_has_error_msg(error, "Either parameter does not exist or is not matrix type.")) goto fail;

                switch(PySAM_matrix_setter(value, func, data_ptr)){
                    case 0: // no error
                        continue;
                    default:
                        goto fail;
                }
            }
            // array
            else{
                SAM_error error = new_error();
                SAM_set_array_t func = SAM_set_array_func(SAM_lib_handle, tech, group, name, &error);
                if (PySAM_has_error_msg(error, "Either parameter does not exist or is not array type.")) goto fail;

                switch(PySAM_array_setter(value, func, data_ptr)){
                    case 0: // no error
                        continue;
                    default:
                        goto fail;
                }
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
            PySAM_error_set_with_context(str);
            goto fail;
        }
        Py_DECREF(ascii_mystring);
    }
    Py_XDECREF(dict);
    if (!existing_error_context)
        PySAM_error_context_clear();
    return 1;
    fail:
    Py_XDECREF(ascii_mystring);
    Py_XDECREF(dict);
    PySAM_error_context_clear();
    return 0;
}

static PyObject*
PySAM_assign_from_attr(PyTypeObject *tp, PyObject *self, PyObject *args){
    PyObject* dict;
    if (!PyArg_ParseTuple(args, "O:assign", &dict)){
        return NULL;
    }

    if (!PySAM_check_lib_loaded()) return NULL;

    PyGetSetDef* getset = tp->tp_getset;
    while(getset->name){
        PyObject* val = PyDict_GetItemString(dict, getset->name);
        if (val){
            (*getset->set)((PyObject*)self, val, NULL);
        }
        getset++;
    }

    Py_INCREF(Py_None);
    return Py_None;
}

static int PySAM_assign_from_nested_dict(PyObject* self, PyObject* x_attr, void *data_ptr, PyObject *dict, const char *tech){
    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;

    while (PyDict_Next(dict, &pos, &key, &value)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);

        if (!PySAM_error_context)
            PySAM_error_context_set(name);

        if (strcmp(name, "Outputs") == 0)
            continue;

        if(!PyDict_Check(value)){
            PySAM_error_set_with_context("Mismatch between provided input and expected structure. PySAM modules are assigned using nested dictionaries. Restructure your input or double check which object to which you are assigning the input.");
            goto fail;
        }
        if (!PySAM_assign_from_dict(data_ptr, value, tech, name))
            goto fail;
    }
    Py_XDECREF(ascii_mystring);
    PySAM_error_context_clear();
    return 1;
    fail:
    Py_XDECREF(ascii_mystring);
    PySAM_error_context_clear();
    return -1;
}

//
// Methods for replacing class attributes from a dictionary
//

static int PySAM_replace_from_dict(PyTypeObject *tp, void *data_ptr, PyObject *dict, const char *tech, const char *group){
    PyGetSetDef* getset = tp->tp_getset;
    while(getset->name){
        SAM_error error = new_error();
        char ssc_name[1024];
        strcpy(ssc_name, getset->name);
        SAM_table_unassign_entry(data_ptr, ssc_name, &error);
        PySAM_has_error(error);
        getset++;
    }
    return PySAM_assign_from_dict(data_ptr, dict, tech, group);
}

static int PySAM_replace_from_nested_dict(PyObject* self, PyObject* x_attr, void *data_ptr, PyObject *dict, const char *tech){
    PyObject* key;
    PyObject* group_val;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;
    PyObject* empty_dict = PyDict_New();

    while (PyDict_Next(x_attr, &pos, &key, &group_val)){
        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);
        PySAM_error_context_set(name);

        if (strcmp(name, "Outputs") == 0)
            continue;

        PyObject* value = PyDict_GetItemString(dict, name);

        if (!value)
            value = empty_dict;

        PyTypeObject* tp = (PyTypeObject*)PyObject_Type(group_val);
        int success = PySAM_replace_from_dict(tp, data_ptr, value, tech, name);
        Py_XDECREF(tp);
        if (!success)
            goto fail;
    }
    Py_XDECREF(empty_dict);
    Py_XDECREF(ascii_mystring);
    PySAM_error_context_clear();
    return 1;
    fail:
    Py_XDECREF(empty_dict);
    Py_XDECREF(ascii_mystring);
    PySAM_error_context_clear();
    return 0;
}

//
// Methods for exporting class attributes into a dictionary
//

/// returns new reference to a dictionary
static PyObject *
PySAM_export_to_dict(PyObject *self, PyTypeObject *tp) {

    if (!PySAM_check_lib_loaded()) return NULL;

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
        Py_XDECREF(val);       // PyDict_Set* does not steal reference
        getset++;
    }

    return export;
}

/// returns new reference to a dictionary
static PyObject *
PySAM_export_to_nested_dict(PyObject *self, PyObject *x_attr) {
    PyObject* export = PyDict_New();
    if(!export){
        PyErr_NoMemory();
        return NULL;
    }

    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;

    PyObject* ascii_mystring = NULL;

    while (PyDict_Next(x_attr, &pos, &key, &value)){

        PyTypeObject* tp = (PyTypeObject*)PyObject_Type(value);
        if(!tp){
            PyErr_SetString(PyExc_TypeError, "Attribute type error.");
            return 0;
        }

        PyObject* dict = PySAM_export_to_dict((PyObject *) value, tp);
        Py_XDECREF(tp);

        if (!dict){
            return NULL;
        }

        ascii_mystring = PyUnicode_AsASCIIString(key);
        char* name = PyBytes_AsString(ascii_mystring);
        PyDict_SetItemString(export, name, dict);
        Py_XDECREF(dict);
        Py_XDECREF(ascii_mystring);
    }
    return export;
}

char *lower_case(char *string)
{
    char *temp = strdup(string);
    unsigned char *tptr = (unsigned char *)temp;
    while(*tptr) {
        *tptr = tolower(*tptr);
        tptr++;
    }
    return temp;
}

/// Loading defaults from marshalled data
static int PySAM_load_defaults(PyObject* self, PyObject* x_attr, void* data_ptr, char* cmod, char* def){
    FILE* f = NULL;
    char path[256];

    char* def_lower = lower_case(def);
    char* cmod_lower = lower_case(cmod);
    sprintf(path, "%sdefaults/%s_%s.df", SAM_lib_dir, cmod_lower, def_lower);
    free(def_lower);
    free(cmod_lower);

    f = fopen(path, "rb");
    if (!f){
        PyErr_SetString(PyExc_Exception, "Default configuration by that name was not found.");
        return -1;
    }

    PyObject* dict = PyMarshal_ReadObjectFromFile(f);
    fclose(f);

    if (!dict){
        PyErr_SetString(PyExc_Exception, "Could not load defaults dict.");
        return -1;
    }

    PySAM_error_context_set("Loading defaults");
    if (PySAM_assign_from_nested_dict(self, x_attr, data_ptr, dict, cmod) < 0)
        return -1;
    Py_DECREF(dict);
    PySAM_error_context_clear();
    return 0;
}

// assigning and unassigning value by name

static PyObject* PySAM_run_getset(PyObject *self, PyObject *arg, PyObject * x_attr, char* name, char* VarGroup_name){
    if (!PySAM_check_lib_loaded()) return NULL;

    PyObject* key;
    PyObject* value;
    Py_ssize_t pos = 0;
    while (PyDict_Next(x_attr, &pos, &key, &value)) {
        PyTypeObject* var_type = value->ob_type;
        PyGetSetDef* getset = var_type->tp_getset;
        if (!getset)
            continue;

        while(getset->name){
            if (strcmp(getset->name, name) == 0){
                if (VarGroup_name){
                    strcpy(VarGroup_name, getset->name);
                }
                if (!arg){
                    return (*getset->get)(self, NULL);
                }
                else{
                    if ((*getset->set)(self, arg, NULL) == 0){
                        Py_INCREF(Py_None);
                        return Py_None;
                    }
                    return NULL;
                }
            }
            getset++;
        }
    }
    PyErr_SetString(PyExc_AttributeError, "\"value\" error, could not find attribute by that name");
    return NULL;
}

static PyObject * CmodStateful_value(CmodStatefulObject *self, PyObject *args)
{
    char* name = 0;
    PyObject* value = NULL;
    if (!PyArg_ParseTuple(args, "s|O", &name, &value))
		return NULL;

    return PySAM_run_getset((PyObject *)self, value, self->x_attr, name, NULL);
}

static PyObject * Cmod_value(CmodObject *self, PyObject *args)
{
    char* name = 0;
    PyObject* value = NULL;
    if (!PyArg_ParseTuple(args, "s|O", &name, &value))
		return NULL;
        
    return PySAM_run_getset((PyObject *)self, value, self->x_attr, name, NULL);
}

static PyObject * CmodStateful_unassign(CmodStatefulObject *self, PyObject *args)
{
    char* name = 0;
    if (!PyArg_ParseTuple(args, "s", &name))
		return NULL;

    SAM_error error = new_error();
    SAM_table_unassign_entry(self->data_ptr, name, &error);
    PySAM_has_error(error);
    return Py_None;
}

static PyObject * Cmod_unassign(CmodObject *self, PyObject *args)
{
    char* name = 0;
    if (!PyArg_ParseTuple(args, "s", &name))
		return NULL;

    SAM_error error = new_error();
    SAM_table_unassign_entry(self->data_ptr, name, &error);
    PySAM_has_error(error);
    return Py_None;
}

#endif //PYSAM_SAM_UTILS_H
