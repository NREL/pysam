import os
import sys
from ctypes import *
from tokenize import Number
from numbers import Number
from collections.abc import Sequence
c_number = c_double  # must be c_double or c_float depending on how defined in sscapi.h


class PySSC:
    def __init__(self, pdll_path=None):
        this_directory = os.path.abspath(os.path.dirname(__file__))

        if pdll_path == None: 
            if sys.platform == 'win32' or sys.platform == 'cygwin':
                self.pdll = CDLL(os.path.join(this_directory, "ssc.dll"))
            elif sys.platform == 'darwin':
                self.pdll = CDLL(os.path.join(this_directory, "libssc.so"))
            elif sys.platform == 'linux':
                self.pdll = CDLL(os.path.join(this_directory, 'libssc.so'))
            else:
                print('Platform not supported ', sys.platform)
        else:
            self.pdll = CDLL(pdll_path)

        self.pdll.ssc_version.restype = c_int
        self.pdll.ssc_var_create.restype = c_void_p

        self.pdll.ssc_data_get_string.restype = c_char_p
        self.pdll.ssc_data_get_array.restype = POINTER(c_number)
        self.pdll.ssc_data_get_matrix.restype = POINTER(c_number)
        self.pdll.ssc_data_get_data_array.restype = c_void_p
        self.pdll.ssc_data_get_data_matrix.restype = c_void_p

        self.pdll.ssc_var_get_string.restype = c_char_p
        self.pdll.ssc_var_get_number.restype = c_float
        self.pdll.ssc_var_get_array.restype = POINTER(c_number)
        self.pdll.ssc_var_get_matrix.restype = POINTER(c_number)
        self.pdll.ssc_var_get_var_array.restype = c_void_p
        self.pdll.ssc_var_get_var_matrix.restype = c_void_p

    INVALID = 0
    STRING = 1
    NUMBER = 2
    ARRAY = 3
    MATRIX = 4
    TABLE = 5
    INPUT = 1
    OUTPUT = 2
    INOUT = 3

    def version(self):
        return self.pdll.ssc_version()

    def var_create(self):
        return self.pdll.ssc_var_create()

    def var_free(self, p_var):
        self.pdll.ssc_var_free(c_void_p(p_var))

    def var_set_string(self, p_var, value):
        self.pdll.ssc_var_set_string(c_void_p(p_var), c_char_p(value))
    
    def var_set_number(self, p_var, value):
        self.pdll.ssc_var_set_number(c_void_p(p_var), c_float(value))

    def var_set_array(self, p_var, parr):
        try:
            count = len(parr)
            arr = (c_number * count)()
            arr[:] = parr  # set all at once instead of looping
        except TypeError:
            if type(parr) == int or type(parr) == float:
                count = 1
                arr = (c_number * count)()
                arr[:] = [parr]  # set all at once instead of looping
                print("input type should be array. Changing to single element array")
        self.pdll.ssc_var_set_array(c_void_p(p_var), pointer(arr), c_int(count))

    def var_set_matrix(self, p_var, mat):
        nrows = len(mat)
        ncols = len(mat[0])
        size = nrows * ncols
        arr = (c_number * size)()
        idx = 0
        for r in range(nrows):
            for c in range(ncols):
                arr[idx] = c_number(mat[r][c])
                idx = idx + 1
        self.pdll.ssc_var_set_matrix(c_void_p(p_var), pointer(arr), c_int(nrows), c_int(ncols))

    def var_set_data_array(self, p_var, p_arr, r):
        self.pdll.ssc_var_set_data_array(c_void_p(p_var), c_void_p(p_arr), c_int(r))
    
    def var_set_data_matrix(self, p_var, p_mat, r, c):
        self.pdll.ssc_var_set_data_matrix(c_void_p(p_var), c_void_p(p_mat), c_int(r), c_int(c))

    def var_set_table(self, p_var, p_tab):
        self.pdll.ssc_var_set_table(c_void_p(p_var), c_void_p(p_tab))

    def var_get_string(self, p_var):
        return self.pdll.ssc_var_get_string(c_void_p(p_var))
    
    def var_get_number(self, p_var):
        return self.pdll.ssc_var_get_number(c_void_p(p_var))
    
    def var_get_array(self, p_var):
        count = c_int()
        ptr = self.pdll.ssc_var_get_array(c_void_p(p_var), byref(count))
        return ptr[0:count.value]
        
    def var_get_matrix(self, p_var):
        nrows = c_int()
        ncols = c_int()
        parr = self.pdll.ssc_var_get_matrix(c_void_p(p_var), byref(nrows), byref(ncols))
        idx = 0
        mat = []
        for r in range(nrows.value):
            row = []
            for c in range(ncols.value):
                row.append(float(parr[idx]))
                idx = idx + 1
            mat.append(row)
        return mat

    def get_var_value(self, p_var, var_type):
        if var_type == self.STRING:
            return self.var_get_string(p_var)
        elif var_type == self.NUMBER:
            return self.var_get_number(p_var)
        elif var_type == self.ARRAY:
            return self.var_get_array(p_var)
        elif var_type == self.MATRIX:
            return self.var_get_matrix(p_var)
        else:
            raise NotImplementedError

    def var_get_data_array(self, p_var, n, var_type):
        parr = self.pdll.ssc_var_get_var_array(c_void_p(p_var), c_int(n))
        return self.get_var_value(parr, var_type)
    
    def var_get_data_matrix(self, p_var, r, c, var_type):
        parr = self.pdll.ssc_var_get_var_matrix(c_void_p(p_var), c_int(r), c_int(c))
        return self.get_var_value(parr, var_type)

    def data_create(self):
        self.pdll.ssc_data_create.restype = c_void_p
        return self.pdll.ssc_data_create()

    def data_free(self, p_data):
        self.pdll.ssc_data_free(c_void_p(p_data))

    def data_clear(self, p_data):
        self.pdll.ssc_data_clear(c_void_p(p_data))

    def data_unassign(self, p_data, name):
        self.pdll.ssc_data_unassign(c_void_p(p_data), c_char_p(name))

    def data_query(self, p_data, name):
        self.pdll.ssc_data_query.restype = c_int
        return self.pdll.ssc_data_query(c_void_p(p_data), c_char_p(name))

    def data_first(self, p_data):
        self.pdll.ssc_data_first.restype = c_char_p
        return self.pdll.ssc_data_first(c_void_p(p_data))

    def data_next(self, p_data):
        self.pdll.ssc_data_next.restype = c_char_p
        return self.pdll.ssc_data_next(c_void_p(p_data))

    def data_set_string(self, p_data, name, value):
        self.pdll.ssc_data_set_string(c_void_p(p_data), c_char_p(name), c_char_p(value))

    def data_set_number(self, p_data, name, value):
        self.pdll.ssc_data_set_number(c_void_p(p_data), c_char_p(name), c_number(value))

    def data_set_array(self, p_data, name, parr):
        try:
            count = len(parr)
            arr = (c_number * count)()
            arr[:] = parr  # set all at once instead of looping
        except TypeError:
            if type(parr) == int or type(parr) == float:
                count = 1
                arr = (c_number * count)()
                arr[:] = [parr]  # set all at once instead of looping
                print(name, " input type should be array. Changing to single element array")

        self.pdll.ssc_data_set_array(c_void_p(p_data), c_char_p(name), pointer(arr), c_int(count))

    def data_set_array_from_csv(self, p_data, name, fn):
        f = open(fn, 'rb')
        data = []
        for line in f:
            data.extend([n for n in map(float, line.split(b','))])
        f.close()
        self.data_set_array(p_data, name, data)

    def data_set_matrix(self, p_data, name, mat):
        nrows = len(mat)
        ncols = len(mat[0])
        size = nrows * ncols
        arr = (c_number * size)()
        idx = 0
        for r in range(nrows):
            for c in range(ncols):
                arr[idx] = c_number(mat[r][c])
                idx = idx + 1
        self.pdll.ssc_data_set_matrix(c_void_p(p_data), c_char_p(name), pointer(arr), c_int(nrows), c_int(ncols))

    def data_set_matrix_from_csv(self, p_data, name, fn):
        f = open(fn, 'rb')
        data = []
        for line in f:
            lst = ([n for n in map(float, line.split(b','))])
            data.append(lst)
        f.close()
        self.data_set_matrix(p_data, name, data)

    def data_set_data_array(self, p_data, name, data_arr):
        p_var = self.var_create()
        self.var_set_value(p_var, data_arr)
        self.data_set_var(p_data, name, p_var)
    
    def data_set_data_matrix(self, p_data, name, data_mat):
        p_var = self.var_create()
        self.var_set_value(p_var, data_mat)
        self.data_set_var(p_data, name, p_var)

    def data_set_table(self, p_data, name, tab):
        self.pdll.ssc_data_set_table(c_void_p(p_data), c_char_p(name), c_void_p(tab))

    def data_set_var(self, p_var, name, p_val):
        self.pdll.ssc_data_set_var(c_void_p(p_var), c_char_p(name), c_void_p(p_val))

    def data_get_string(self, p_data, name):
        return self.pdll.ssc_data_get_string(c_void_p(p_data), c_char_p(name))

    def data_get_number(self, p_data, name):
        val = c_number(0)
        if self.pdll.ssc_data_get_number(c_void_p(p_data), c_char_p(name), byref(val)):
            return val.value
        else:
            raise RuntimeError(f"Error {str(name)} not assigned.")

    def data_get_array(self, p_data, name):
        count = c_int()
        parr = self.pdll.ssc_data_get_array(c_void_p(p_data), c_char_p(name), byref(count))
        arr = parr[0:count.value]  # extract all at once
        return arr

    def data_get_matrix(self, p_data, name):
        nrows = c_int()
        ncols = c_int()
        parr = self.pdll.ssc_data_get_matrix(c_void_p(p_data), c_char_p(name), byref(nrows), byref(ncols))
        idx = 0
        mat = []
        for r in range(nrows.value):
            row = []
            for c in range(ncols.value):
                row.append(float(parr[idx]))
                idx = idx + 1
            mat.append(row)
        return mat
    
    # list_of_types gives the type of each entry in the data array
    def data_get_data_array(self, p_data, name, list_of_types):
        count = c_int()
        pvar = self.pdll.ssc_data_get_data_array(c_void_p(p_data), c_char_p(name), byref(count))
        if count.value != len(list_of_types):
            raise ValueError(f"list_of_types must be same length as data array, which has length {count.value}")
        vals = []
        for n, var_type in enumerate(list_of_types):
            var = self.var_get_data_array(pvar, n, var_type)
            vals.append(var)
        return vals
    
    # matrix_of_types gives the type of each entry in the data array
    def data_get_data_matrix(self, p_data, name, matrix_of_types):
        nrows = c_int()
        ncols = c_int()
        pvar = self.pdll.ssc_data_get_data_matrix(c_void_p(p_data), c_char_p(name), byref(nrows), byref(ncols))
        if nrows.value != len(matrix_of_types):
            raise ValueError(f"matrix_of_types must be same number of rows as data matrix, which has {nrows.value} rows")
        if ncols.value != len(matrix_of_types[0]):
            raise ValueError(f"matrix_of_types must be same number of cols as data matrix, which has {ncols.value} cols")
        vals = []
        for r, row in enumerate(matrix_of_types):
            row_vals = []
            for c, var_type in enumerate(row):
                var = self.var_get_data_matrix(pvar, r, c, var_type)
                row_vals.append(var)
            vals.append(row_vals)
        return vals

    # don't call data_free() on the result, it's an internal
    # pointer inside SSC
    def data_get_table(self, p_data, name):
        return self.pdll.ssc_data_get_table(c_void_p(p_data), name)

    def module_entry(self, index):
        self.pdll.ssc_module_entry.restype = c_void_p
        return self.pdll.ssc_module_entry(c_int(index))

    def entry_name(self, p_entry):
        self.pdll.ssc_entry_name.restype = c_char_p
        return self.pdll.ssc_entry_name(c_void_p(p_entry))

    def entry_description(self, p_entry):
        self.pdll.ssc_entry_description.restype = c_char_p
        return self.pdll.ssc_entry_description(c_void_p(p_entry))

    def entry_version(self, p_entry):
        self.pdll.ssc_entry_version.restype = c_int
        return self.pdll.ssc_entry_version(c_void_p(p_entry))

    def module_create(self, name):
        self.pdll.ssc_module_create.restype = c_void_p
        return self.pdll.ssc_module_create(c_char_p(name))

    def module_free(self, p_mod):
        self.pdll.ssc_module_free(c_void_p(p_mod))

    def module_var_info(self, p_mod, index):
        self.pdll.ssc_module_var_info.restype = c_void_p
        return self.pdll.ssc_module_var_info(c_void_p(p_mod), c_int(index))

    def info_var_type(self, p_inf):
        return self.pdll.ssc_info_var_type(c_void_p(p_inf))

    def info_data_type(self, p_inf):
        return self.pdll.ssc_info_data_type(c_void_p(p_inf))

    def info_name(self, p_inf):
        self.pdll.ssc_info_name.restype = c_char_p
        return self.pdll.ssc_info_name(c_void_p(p_inf))

    def info_label(self, p_inf):
        self.pdll.ssc_info_label.restype = c_char_p
        return self.pdll.ssc_info_label(c_void_p(p_inf))

    def info_units(self, p_inf):
        self.pdll.ssc_info_units.restype = c_char_p
        return self.pdll.ssc_info_units(c_void_p(p_inf))

    def info_meta(self, p_inf):
        self.pdll.ssc_info_meta.restype = c_char_p
        return self.pdll.ssc_info_meta(c_void_p(p_inf))

    def info_group(self, p_inf):
        self.pdll.ssc_info_group.restype = c_char_p
        return self.pdll.ssc_info_group(c_void_p(p_inf))

    def info_uihint(self, p_inf):
        self.pdll.ssc_info_uihint.restype = c_char_p
        return self.pdll.ssc_info_uihint(c_void_p(p_inf))

    def info_required(self, p_inf):
        self.pdll.ssc_info_required.restype = c_char_p
        return self.pdll.ssc_info_required(c_void_p(p_inf))

    def info_constraints(self, p_inf):
        self.pdll.ssc_info_constraints.restype = c_char_p
        return self.pdll.ssc_info_constraints(c_void_p(p_inf))

    def module_exec(self, p_mod, p_data):
        self.pdll.ssc_module_exec.restype = c_int
        return self.pdll.ssc_module_exec(c_void_p(p_mod), c_void_p(p_data))

    def module_exec_simple_no_thread(self, modname, data):
        self.pdll.ssc_module_exec_simple_nothread.restype = c_char_p
        return self.pdll.ssc_module_exec_simple_nothread(c_char_p(modname), c_void_p(data))

    def module_log(self, p_mod, index):
        log_type = c_int()
        time = c_float()
        self.pdll.ssc_module_log.restype = c_char_p
        return self.pdll.ssc_module_log(c_void_p(p_mod), c_int(index), byref(log_type), byref(time))

    def module_exec_set_print(self, prn):
        return self.pdll.ssc_module_exec_set_print(c_int(prn))
    
    def var_set_value(self, var, value):
        if isinstance(value, str):
            self.var_set_string(var, value.encode("ascii"))
        elif isinstance(value, Number):
            self.var_set_number(var, value)
        elif isinstance(value, Sequence):
            if (not isinstance(value[0], Sequence)) or isinstance(value[0], str):
                not_numeric = [int(not isinstance(v, Number)) for v in value]
                if sum(not_numeric) == 0:
                    self.var_set_array(var, value)
                else:
                    for n, val in enumerate(value):
                        arr_var = self.var_create()
                        self.var_set_value(arr_var, val)
                        self.var_set_data_array(var, arr_var, n)
            else:
                flat_list = [item for sublist in value for item in sublist]
                not_numeric = [int(not isinstance(v, Number)) for v in flat_list]
                if sum(not_numeric) == 0:
                    self.var_set_matrix(var, value)
                else:
                    for r, row in enumerate(value):
                        for c, val in enumerate(row):
                            mat_var = self.var_create()
                            self.var_set_value(mat_var, val)
                            self.var_set_data_matrix(var, mat_var, r, c)
        elif isinstance(value, dict):
            table = self.data_create()
            for k, v in value.items():
                self.data_set_variable(table, k, v)
            self.var_set_table(var, table)

    def data_set_variable(self, table, ssc_input_data_name, value):
        if isinstance(ssc_input_data_name, str):
            ssc_input_data_name = ssc_input_data_name.encode("ascii")
        if isinstance(value, str):
            if isinstance(value, str):
                value = value.encode("ascii")
            self.data_set_string(table, ssc_input_data_name, value)
        elif isinstance(value, Number):
            self.data_set_number(table, ssc_input_data_name, value)
        elif isinstance(value, Sequence):
            if not isinstance(value[0], Sequence):
                not_numeric = [int(not isinstance(v, Number)) for v in value]
                if sum(not_numeric) == 0:
                    self.data_set_array(table, ssc_input_data_name, value)
                else:
                    self.data_set_data_array(table, ssc_input_data_name, value)
            else:
                for row in value:
                    not_numeric = [int(not isinstance(v, Number)) for v in row]
                    if sum(not_numeric) == 0:
                        self.data_set_matrix(table, ssc_input_data_name, value)
                    else:
                        self.data_set_data_matrix(table, ssc_input_data_name, value)
        elif isinstance(value, dict):
            input_table = self.data_create()
            for k, v in value.items():
                self.data_set_variable(input_table, k, v)
            self.data_set_table(table, ssc_input_data_name, input_table)

    def data_get_variable(self, data, ssc_var_name):
        if isinstance(ssc_var_name, str):
            ssc_var_name = ssc_var_name.encode('ascii')
        ssc_data_query = self.data_query(data, ssc_var_name)
        if ssc_data_query < self.STRING or ssc_data_query > self.TABLE:
            raise ValueError(f"Error with variable f'{ssc_var_name}', invalid data type")
        if ssc_data_query > 0:
            if ssc_data_query == self.STRING:
                return self.data_get_string(data, ssc_var_name).decode(
                    "ascii")
            elif ssc_data_query == self.NUMBER:
                return self.data_get_number(data, ssc_var_name)
            elif ssc_data_query == self.ARRAY:
                return self.data_get_array(data, ssc_var_name)
            elif ssc_data_query == self.MATRIX:
                return self.data_get_matrix(data, ssc_var_name)
            elif ssc_data_query == self.TABLE:
                return self.data_get_table(data, ssc_var_name)
            
    def data_deep_copy(self, data_source, data_dest):
        return self.pdll.ssc_data_deep_copy(c_void_p(data_source), c_void_p(data_dest))

# Functions to simulate compute modules through dictionaries
def ssc_sim_from_dict(data_pydict):
    """
    Run a technology compute module using parameters in a dict.

    Parameters
    ----------
    data_pydict: dict
        Required keys are:
            tech_model: str
                name of the compute module to run.
            financial_model: str or None
                name of the financial model to apply. If None, no financial
                model is used.
        Other keys are names of args for the selected tech_model or
        financial_model.
    
    Returns
    -------
    (dict): dict
        keys are outputs from the selected compute module.
    """

    tech_model_name = data_pydict["tech_model"]
    # Convert python dictionary into ssc var info table
    data_ssc_tech_model = dict_to_ssc_table(data_pydict, tech_model_name)

    financial_model_name = data_pydict["financial_model"]
    if financial_model_name is None:
        data_ssc = data_ssc_tech_model
    else:
        data_ssc = dict_to_ssc_table_dat(data_pydict, financial_model_name,
                                         data_ssc_tech_model)

    return ssc_sim(data_ssc, tech_model_name, financial_model_name)


def ssc_sim(data_ssc, tech_model_name, financial_model_name):

    # Run the technology model compute module
    tech_model_return = ssc_cmod(data_ssc, tech_model_name)
    tech_model_success = tech_model_return[0]
    tech_model_dict = tech_model_return[1]

    # Add tech and financial models back to dictionary
    tech_model_dict["tech_model"] = tech_model_name
    tech_model_dict["financial_model"] = financial_model_name

    if (tech_model_success == 0):
        tech_model_dict["cmod_success"] = 0
        return tech_model_dict

    if financial_model_name in [None, "none"]:
        tech_model_dict["cmod_success"] = 1
        return tech_model_dict

    # Run the financial model
    financial_model_return = ssc_cmod(data_ssc, financial_model_name)
    financial_model_success = financial_model_return[0]
    financial_model_dict = financial_model_return[1]

    if (financial_model_success == 0):
        financial_model_dict["cmod_success"] = 0
        out_err_dict = tech_model_dict.copy()
        return out_err_dict.update(financial_model_dict)

    # If all models are successful, set boolean true
    financial_model_dict["cmod_success"] = 1

    # Combine tech and financial model dictionaries
    out_dict = tech_model_dict.copy()
    out_dict.update(financial_model_dict)

    return out_dict


def ssc_cmod(dat, name):
    ssc = PySSC()

    cmod = ssc.module_create(name.encode("utf-8"))
    ssc.module_exec_set_print(0)

    # Run compute module
    # Check for simulation errors
    if ssc.module_exec(cmod, dat) == 0:
        print(name + ' simulation error')
        idx = 1
        msg = ssc.module_log(cmod, 0)
        while msg is not None:
            print(' : ' + msg.decode("utf - 8"))
            msg = ssc.module_log(cmod, idx)
            idx = idx + 1
        cmod_err_dict = ssc_table_to_dict(cmod, dat)
        return [False, cmod_err_dict]

    # Get python dictionary representing compute module with all inputs/outputs defined
    return [True, ssc_table_to_dict(cmod, dat)]


def dict_to_ssc_table(py_dict, cmod_name):
    ssc = PySSC()
    dat = ssc.data_create()
    return dict_to_ssc_table_dat(py_dict, cmod_name, dat)


def dict_to_ssc_table_dat(py_dict, cmod_name, dat):
    ssc = PySSC()

    cmod = ssc.module_create(cmod_name.encode("utf-8"))

    dict_keys = list(py_dict.keys())
    # dat = ssc.data_create()

    ii = 0
    while (True):

        p_ssc_entry = ssc.module_var_info(cmod, ii)

        ssc_input_data_type = ssc.info_data_type(p_ssc_entry)

        # 1 = String, 2 = Number, 3 = Array, 4 = Matrix, 5 = Table
        if (ssc_input_data_type <= 0 or ssc_input_data_type > 5):
            break

        ssc_input_var_type = ssc.info_var_type(p_ssc_entry)

        # If the variable type is INPUT (1) or INOUT (3)
        if (ssc_input_var_type == 1 or ssc_input_var_type == 3):

            # Get name of iith variable in compute module table
            ssc_input_data_name = str(ssc.info_name(p_ssc_entry).decode("ascii"))

            # Find corresponding 'des_par' dictionary item
            is_str_test_key = False
            for i in range(len(dict_keys)):
                if (dict_keys[i] == ssc_input_data_name):
                    is_str_test_key = True
                    # print ("Found key")
                    break

            # Helpful for debugging:
            # if(is_str_test_key == False):
            #    print ("Did not find key: ", ssc_input_data_name)

            # Set compute module data to dictionary value
            if is_str_test_key:
                if (ssc_input_data_type == 1):
                    ssc.data_set_string(dat, ssc_input_data_name.encode("ascii"),
                                        py_dict[ssc_input_data_name].encode("ascii"))
                elif (ssc_input_data_type == 2):
                    ssc.data_set_number(dat, ssc_input_data_name.encode("ascii"), py_dict[ssc_input_data_name])
                elif (ssc_input_data_type == 3):
                    ssc.data_set_array(dat, ssc_input_data_name.encode("ascii"), py_dict[ssc_input_data_name])
                elif (ssc_input_data_type == 4):
                    ssc.data_set_matrix(dat, ssc_input_data_name.encode("ascii"), py_dict[ssc_input_data_name])
                elif (ssc_input_data_type == 5):
                    ssc.data_set_table(dat, ssc_input_data_name.encode("ascii"), py_dict[ssc_input_data_name])

        ii = ii + 1

    return dat


# Returns python dictionary representing SSC compute module w/ all required inputs/outputs defined
def ssc_table_to_dict(cmod, dat):
    ssc = PySSC()
    i = 0
    ssc_out = {}
    while (True):
        p_ssc_entry = ssc.module_var_info(cmod, i)
        ssc_output_data_type = ssc.info_data_type(p_ssc_entry)
        if (ssc_output_data_type <= 0 or ssc_output_data_type > 5):
            break
        ssc_output_data_name = str(ssc.info_name(p_ssc_entry).decode("ascii"))
        ssc_data_query = ssc.data_query(dat, ssc_output_data_name.encode("ascii"))
        if (ssc_data_query > 0):
            if (ssc_output_data_type == 1):
                ssc_out[ssc_output_data_name] = ssc.data_get_string(dat,
                                                                    ssc_output_data_name.encode("ascii")).decode(
                    "ascii")
            elif (ssc_output_data_type == 2):
                ssc_out[ssc_output_data_name] = ssc.data_get_number(dat, ssc_output_data_name.encode("ascii"))
            elif (ssc_output_data_type == 3):
                ssc_out[ssc_output_data_name] = ssc.data_get_array(dat, ssc_output_data_name.encode("ascii"))
            elif (ssc_output_data_type == 4):
                ssc_out[ssc_output_data_name] = ssc.data_get_matrix(dat, ssc_output_data_name.encode("ascii"))
            elif (ssc_output_data_type == 5):
                ssc_out[ssc_output_data_name] = ssc.data_get_table(dat, ssc_output_data_name.encode("ascii"))
        i = i + 1

    return ssc_out
