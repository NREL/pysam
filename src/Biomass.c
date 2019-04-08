#include <Python.h>

#include <SAM_Biomass.h>
#include <SAM_api.h>

#include "PySAM_utils.h"



	/*
	 * Biopower Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Biomass   data_ptr;
} BiopowerObject;

static PyTypeObject Biopower_Type;

static PyObject *
Biopower_new(SAM_Biomass data_ptr)
{
	PyObject* new_obj = Biopower_Type.tp_alloc(&Biopower_Type,0);

	BiopowerObject* Biopower_obj = (BiopowerObject*)new_obj;

	Biopower_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Biopower methods */

static PyObject *
Biopower_assign(BiopowerObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Biomass", "Biopower")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Biopower_export(BiopowerObject *self, PyObject *args)
{
	PyTypeObject* tp = &Biopower_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Biopower_methods[] = {
		{"assign",            (PyCFunction)Biopower_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Biopower_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Biopower_get_biopwr_emissions_avoided_cred(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_avoided_cred_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_avoided_cred(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_avoided_cred_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_collection_fuel(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_collection_fuel_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_collection_fuel(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_collection_fuel_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_grid_intensity(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_grid_intensity_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_grid_intensity(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_grid_intensity_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_pre_chipopt(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_pre_chipopt_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_pre_chipopt(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_pre_chipopt_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_pre_grindopt(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_pre_grindopt_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_pre_grindopt(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_pre_grindopt_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_pre_pelletopt(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_pre_pelletopt_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_pre_pelletopt(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_pre_pelletopt_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_transport_fuel(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_transport_fuel_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_transport_fuel(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_transport_fuel_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_transport_legs(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_transport_legs_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_transport_legs(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_transport_legs_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_transport_long(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_transport_long_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_transport_long(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_transport_long_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_transport_longmiles(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_transport_longmiles_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_transport_longmiles(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_transport_longmiles_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_transport_longopt(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_transport_longopt_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_transport_longopt(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_transport_longopt_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_emissions_transport_predist(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_emissions_transport_predist_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_emissions_transport_predist(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_emissions_transport_predist_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_additional_opt(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_additional_opt_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_additional_opt(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_additional_opt_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_bagasse_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_bagasse_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_bagasse_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_bagasse_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_bagasse_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_bagasse_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_bagasse_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_bagasse_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_barley_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_barley_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_barley_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_barley_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_barley_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_barley_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_barley_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_barley_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_bit_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_bit_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_bit_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_bit_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_bit_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_bit_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_bit_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_bit_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_collection_radius(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_collection_radius_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_collection_radius(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_collection_radius_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock1_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock1_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock1_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock1_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock1_h(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_h_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock1_h(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_h_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock1_hhv(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_hhv_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock1_hhv(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_hhv_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock1_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock1_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock1_resource(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_resource_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock1_resource(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock1_resource_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock2_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock2_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock2_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock2_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock2_h(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_h_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock2_h(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_h_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock2_hhv(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_hhv_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock2_hhv(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_hhv_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock2_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock2_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_feedstock2_resource(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_resource_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_feedstock2_resource(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_feedstock2_resource_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_forest_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_forest_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_forest_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_forest_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_forest_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_forest_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_forest_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_forest_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_herb_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_herb_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_herb_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_herb_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_herb_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_herb_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_herb_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_herb_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_herb_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_herb_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_herb_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_herb_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_lig_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_lig_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_lig_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_lig_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_lig_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_lig_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_lig_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_lig_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_mill_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_mill_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_mill_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_mill_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_mill_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_mill_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_mill_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_mill_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_mill_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_mill_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_mill_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_mill_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_rice_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_rice_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_rice_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_rice_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_rice_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_rice_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_rice_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_rice_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_stover_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_stover_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_stover_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_stover_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_stover_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_stover_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_stover_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_stover_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_subbit_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_subbit_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_subbit_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_subbit_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_subbit_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_subbit_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_subbit_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_subbit_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_biomass(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_biomass_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_biomass(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_biomass_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_biomass_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_biomass_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_biomass_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_biomass_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_coal(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_coal_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_coal(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_coal_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_h(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_h_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_h(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_h_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_hhv(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_hhv_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_hhv(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_hhv_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_lhv(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_lhv_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_lhv(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_lhv_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_total_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_total_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_total_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_total_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_urban_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_urban_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_urban_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_urban_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_urban_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_urban_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_urban_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_urban_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_urban_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_urban_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_urban_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_urban_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_wheat_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_wheat_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_wheat_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_wheat_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_wheat_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_wheat_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_wheat_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_wheat_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_woody_c(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_woody_c_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_woody_c(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_woody_c_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_woody_frac(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_woody_frac_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_woody_frac(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_woody_frac_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_feedstock_woody_moisture(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_feedstock_woody_moisture_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_feedstock_woody_moisture(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_feedstock_woody_moisture_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_air_feed(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_air_feed_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_air_feed(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_air_feed_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_cap_per_boiler(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_cap_per_boiler_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_cap_per_boiler(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_cap_per_boiler_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_flue_temp(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_flue_temp_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_flue_temp(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_flue_temp_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_num(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_num_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_num(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_num_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_over_design(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_over_design_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_over_design(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_over_design_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_steam_enthalpy(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_steam_enthalpy_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_steam_enthalpy(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_steam_enthalpy_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_boiler_steam_pressure(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_boiler_steam_pressure_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_boiler_steam_pressure(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_boiler_steam_pressure_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_combustor_type(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_combustor_type_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_combustor_type(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_combustor_type_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_cycle_design_temp(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_cycle_design_temp_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_cycle_design_temp(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_cycle_design_temp_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_disp_power(BiopowerObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Biopower_biopwr_plant_disp_power_aget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_disp_power(BiopowerObject *self, PyObject *value, void *closure)
{
		return PySAM_array_setter(value, SAM_Biomass_Biopower_biopwr_plant_disp_power_aset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_drying_method(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_drying_method_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_drying_method(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_drying_method_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_drying_spec(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_drying_spec_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_drying_spec(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_drying_spec_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_max_over_design(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_max_over_design_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_max_over_design(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_max_over_design_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_min_load(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_min_load_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_min_load(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_min_load_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_nameplate(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_nameplate_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_nameplate(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_nameplate_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_par_percent(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_par_percent_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_par_percent(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_par_percent_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_pl_eff_f0(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_pl_eff_f0_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_pl_eff_f0(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_pl_eff_f0_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_pl_eff_f1(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_pl_eff_f1_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_pl_eff_f1(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_pl_eff_f1_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_pl_eff_f2(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_pl_eff_f2_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_pl_eff_f2(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_pl_eff_f2_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_pl_eff_f3(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_pl_eff_f3_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_pl_eff_f3(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_pl_eff_f3_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_pl_eff_f4(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_pl_eff_f4_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_pl_eff_f4(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_pl_eff_f4_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_ramp_rate(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_ramp_rate_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_ramp_rate(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_ramp_rate_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_rated_eff(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_rated_eff_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_rated_eff(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_rated_eff_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_temp_corr_mode(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_temp_corr_mode_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_temp_corr_mode(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_temp_corr_mode_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_temp_eff_f0(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_temp_eff_f0_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_temp_eff_f0(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_temp_eff_f0_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_temp_eff_f1(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_temp_eff_f1_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_temp_eff_f1(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_temp_eff_f1_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_temp_eff_f2(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_temp_eff_f2_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_temp_eff_f2(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_temp_eff_f2_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_temp_eff_f3(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_temp_eff_f3_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_temp_eff_f3(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_temp_eff_f3_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_temp_eff_f4(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_temp_eff_f4_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_temp_eff_f4(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_temp_eff_f4_fset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_tou_grid(BiopowerObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Biomass_Biopower_file_sget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_tou_grid(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Biomass_Biopower_file_sset, self->data_ptr);
}

static PyObject *
Biopower_get_biopwr_plant_tou_option(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_biopwr_plant_tou_option_fget, self->data_ptr);
}

static int
Biopower_set_biopwr_plant_tou_option(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_biopwr_plant_tou_option_fset, self->data_ptr);
}

static PyObject *
Biopower_get_file_name(BiopowerObject *self, void *closure)
{
	return PySAM_string_getter(SAM_Biomass_Biopower_file_sget, self->data_ptr);
}

static int
Biopower_set_file_name(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_Biomass_Biopower_file_sset, self->data_ptr);
}

static PyObject *
Biopower_get_system_capacity(BiopowerObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Biopower_system_capacity_fget, self->data_ptr);
}

static int
Biopower_set_system_capacity(BiopowerObject *self, PyObject *value, void *closure)
{
	return PySAM_float_setter(value, SAM_Biomass_Biopower_system_capacity_fset, self->data_ptr);
}

static PyGetSetDef Biopower_getset[] = {
{"biopwr_emissions_avoided_cred", (getter)Biopower_get_biopwr_emissions_avoided_cred,(setter)Biopower_set_biopwr_emissions_avoided_cred,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_collection_fuel", (getter)Biopower_get_biopwr_emissions_collection_fuel,(setter)Biopower_set_biopwr_emissions_collection_fuel,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_grid_intensity", (getter)Biopower_get_biopwr_emissions_grid_intensity,(setter)Biopower_set_biopwr_emissions_grid_intensity,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_emissions_pre_chipopt", (getter)Biopower_get_biopwr_emissions_pre_chipopt,(setter)Biopower_set_biopwr_emissions_pre_chipopt,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_pre_grindopt", (getter)Biopower_get_biopwr_emissions_pre_grindopt,(setter)Biopower_set_biopwr_emissions_pre_grindopt,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_pre_pelletopt", (getter)Biopower_get_biopwr_emissions_pre_pelletopt,(setter)Biopower_set_biopwr_emissions_pre_pelletopt,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_transport_fuel", (getter)Biopower_get_biopwr_emissions_transport_fuel,(setter)Biopower_set_biopwr_emissions_transport_fuel,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_transport_legs", (getter)Biopower_get_biopwr_emissions_transport_legs,(setter)Biopower_set_biopwr_emissions_transport_legs,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_transport_long", (getter)Biopower_get_biopwr_emissions_transport_long,(setter)Biopower_set_biopwr_emissions_transport_long,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_transport_longmiles", (getter)Biopower_get_biopwr_emissions_transport_longmiles,(setter)Biopower_set_biopwr_emissions_transport_longmiles,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_emissions_transport_longopt", (getter)Biopower_get_biopwr_emissions_transport_longopt,(setter)Biopower_set_biopwr_emissions_transport_longopt,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_emissions_transport_predist", (getter)Biopower_get_biopwr_emissions_transport_predist,(setter)Biopower_set_biopwr_emissions_transport_predist,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_additional_opt", (getter)Biopower_get_biopwr_feedstock_additional_opt,(setter)Biopower_set_biopwr_feedstock_additional_opt,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_feedstock_bagasse_frac", (getter)Biopower_get_biopwr_feedstock_bagasse_frac,(setter)Biopower_set_biopwr_feedstock_bagasse_frac,
	"Bagasse feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_bagasse_moisture", (getter)Biopower_get_biopwr_feedstock_bagasse_moisture,(setter)Biopower_set_biopwr_feedstock_bagasse_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_barley_frac", (getter)Biopower_get_biopwr_feedstock_barley_frac,(setter)Biopower_set_biopwr_feedstock_barley_frac,
	"Barley feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_barley_moisture", (getter)Biopower_get_biopwr_feedstock_barley_moisture,(setter)Biopower_set_biopwr_feedstock_barley_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_bit_frac", (getter)Biopower_get_biopwr_feedstock_bit_frac,(setter)Biopower_set_biopwr_feedstock_bit_frac,
	"Bituminos coal feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_bit_moisture", (getter)Biopower_get_biopwr_feedstock_bit_moisture,(setter)Biopower_set_biopwr_feedstock_bit_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_collection_radius", (getter)Biopower_get_biopwr_feedstock_collection_radius,(setter)Biopower_set_biopwr_feedstock_collection_radius,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock1_c", (getter)Biopower_get_biopwr_feedstock_feedstock1_c,(setter)Biopower_set_biopwr_feedstock_feedstock1_c,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock1_frac", (getter)Biopower_get_biopwr_feedstock_feedstock1_frac,(setter)Biopower_set_biopwr_feedstock_feedstock1_frac,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock1_h", (getter)Biopower_get_biopwr_feedstock_feedstock1_h,(setter)Biopower_set_biopwr_feedstock_feedstock1_h,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock1_hhv", (getter)Biopower_get_biopwr_feedstock_feedstock1_hhv,(setter)Biopower_set_biopwr_feedstock_feedstock1_hhv,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock1_moisture", (getter)Biopower_get_biopwr_feedstock_feedstock1_moisture,(setter)Biopower_set_biopwr_feedstock_feedstock1_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock1_resource", (getter)Biopower_get_biopwr_feedstock_feedstock1_resource,(setter)Biopower_set_biopwr_feedstock_feedstock1_resource,
	"Opt feedstock 1 (dt/yr) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock2_c", (getter)Biopower_get_biopwr_feedstock_feedstock2_c,(setter)Biopower_set_biopwr_feedstock_feedstock2_c,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock2_frac", (getter)Biopower_get_biopwr_feedstock_feedstock2_frac,(setter)Biopower_set_biopwr_feedstock_feedstock2_frac,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock2_h", (getter)Biopower_get_biopwr_feedstock_feedstock2_h,(setter)Biopower_set_biopwr_feedstock_feedstock2_h,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock2_hhv", (getter)Biopower_get_biopwr_feedstock_feedstock2_hhv,(setter)Biopower_set_biopwr_feedstock_feedstock2_hhv,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock2_moisture", (getter)Biopower_get_biopwr_feedstock_feedstock2_moisture,(setter)Biopower_set_biopwr_feedstock_feedstock2_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_feedstock2_resource", (getter)Biopower_get_biopwr_feedstock_feedstock2_resource,(setter)Biopower_set_biopwr_feedstock_feedstock2_resource,
	"Opt feedstock 2 (dt/yr) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_forest_frac", (getter)Biopower_get_biopwr_feedstock_forest_frac,(setter)Biopower_set_biopwr_feedstock_forest_frac,
	"Forest residue feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_forest_moisture", (getter)Biopower_get_biopwr_feedstock_forest_moisture,(setter)Biopower_set_biopwr_feedstock_forest_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_herb_c", (getter)Biopower_get_biopwr_feedstock_herb_c,(setter)Biopower_set_biopwr_feedstock_herb_c,
	"Carbon fraction in herbaceous energy crop [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_herb_frac", (getter)Biopower_get_biopwr_feedstock_herb_frac,(setter)Biopower_set_biopwr_feedstock_herb_frac,
	"Herbaceous energy crop feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_herb_moisture", (getter)Biopower_get_biopwr_feedstock_herb_moisture,(setter)Biopower_set_biopwr_feedstock_herb_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_lig_frac", (getter)Biopower_get_biopwr_feedstock_lig_frac,(setter)Biopower_set_biopwr_feedstock_lig_frac,
	"Lignite coal feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_lig_moisture", (getter)Biopower_get_biopwr_feedstock_lig_moisture,(setter)Biopower_set_biopwr_feedstock_lig_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_mill_c", (getter)Biopower_get_biopwr_feedstock_mill_c,(setter)Biopower_set_biopwr_feedstock_mill_c,
	"Carbon fraction in mill residue [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_mill_frac", (getter)Biopower_get_biopwr_feedstock_mill_frac,(setter)Biopower_set_biopwr_feedstock_mill_frac,
	"Mill residue feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_mill_moisture", (getter)Biopower_get_biopwr_feedstock_mill_moisture,(setter)Biopower_set_biopwr_feedstock_mill_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_rice_frac", (getter)Biopower_get_biopwr_feedstock_rice_frac,(setter)Biopower_set_biopwr_feedstock_rice_frac,
	"Rice straw feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_rice_moisture", (getter)Biopower_get_biopwr_feedstock_rice_moisture,(setter)Biopower_set_biopwr_feedstock_rice_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_stover_frac", (getter)Biopower_get_biopwr_feedstock_stover_frac,(setter)Biopower_set_biopwr_feedstock_stover_frac,
	"Stover feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_stover_moisture", (getter)Biopower_get_biopwr_feedstock_stover_moisture,(setter)Biopower_set_biopwr_feedstock_stover_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_subbit_frac", (getter)Biopower_get_biopwr_feedstock_subbit_frac,(setter)Biopower_set_biopwr_feedstock_subbit_frac,
	"Sub-bituminous coal feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_subbit_moisture", (getter)Biopower_get_biopwr_feedstock_subbit_moisture,(setter)Biopower_set_biopwr_feedstock_subbit_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total", (getter)Biopower_get_biopwr_feedstock_total,(setter)Biopower_set_biopwr_feedstock_total,
	"Total fuel resource (dt/yr) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_biomass", (getter)Biopower_get_biopwr_feedstock_total_biomass,(setter)Biopower_set_biopwr_feedstock_total_biomass,
	"Total biomass resource (dt/yr) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_biomass_c", (getter)Biopower_get_biopwr_feedstock_total_biomass_c,(setter)Biopower_set_biopwr_feedstock_total_biomass_c,
	"Biomass fraction carbon [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_c", (getter)Biopower_get_biopwr_feedstock_total_c,(setter)Biopower_set_biopwr_feedstock_total_c,
	"Mass fraction carbon [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_coal", (getter)Biopower_get_biopwr_feedstock_total_coal,(setter)Biopower_set_biopwr_feedstock_total_coal,
	"Total coal resource (dt/yr) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_h", (getter)Biopower_get_biopwr_feedstock_total_h,(setter)Biopower_set_biopwr_feedstock_total_h,
	"Mass fraction hydrogen [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_hhv", (getter)Biopower_get_biopwr_feedstock_total_hhv,(setter)Biopower_set_biopwr_feedstock_total_hhv,
	"Dry feedstock HHV (Btu/lb) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_lhv", (getter)Biopower_get_biopwr_feedstock_total_lhv,(setter)Biopower_set_biopwr_feedstock_total_lhv,
	"Dry feedstock LHV (Btu/lb) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_total_moisture", (getter)Biopower_get_biopwr_feedstock_total_moisture,(setter)Biopower_set_biopwr_feedstock_total_moisture,
	"Overall Moisture Content (dry %) [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_urban_c", (getter)Biopower_get_biopwr_feedstock_urban_c,(setter)Biopower_set_biopwr_feedstock_urban_c,
	"Carbon fraction in urban residue [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_urban_frac", (getter)Biopower_get_biopwr_feedstock_urban_frac,(setter)Biopower_set_biopwr_feedstock_urban_frac,
	"Urban wood residue feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_urban_moisture", (getter)Biopower_get_biopwr_feedstock_urban_moisture,(setter)Biopower_set_biopwr_feedstock_urban_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_wheat_frac", (getter)Biopower_get_biopwr_feedstock_wheat_frac,(setter)Biopower_set_biopwr_feedstock_wheat_frac,
	"Wheat straw feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_wheat_moisture", (getter)Biopower_get_biopwr_feedstock_wheat_moisture,(setter)Biopower_set_biopwr_feedstock_wheat_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_woody_c", (getter)Biopower_get_biopwr_feedstock_woody_c,(setter)Biopower_set_biopwr_feedstock_woody_c,
	"Carbon fraction in woody energy crop [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_woody_frac", (getter)Biopower_get_biopwr_feedstock_woody_frac,(setter)Biopower_set_biopwr_feedstock_woody_frac,
	"Woody energy crop feedstock fraction [], number.\n Required if: *.",
 	NULL},
{"biopwr_feedstock_woody_moisture", (getter)Biopower_get_biopwr_feedstock_woody_moisture,(setter)Biopower_set_biopwr_feedstock_woody_moisture,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_air_feed", (getter)Biopower_get_biopwr_plant_boiler_air_feed,(setter)Biopower_set_biopwr_plant_boiler_air_feed,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_cap_per_boiler", (getter)Biopower_get_biopwr_plant_boiler_cap_per_boiler,(setter)Biopower_set_biopwr_plant_boiler_cap_per_boiler,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_flue_temp", (getter)Biopower_get_biopwr_plant_boiler_flue_temp,(setter)Biopower_set_biopwr_plant_boiler_flue_temp,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_num", (getter)Biopower_get_biopwr_plant_boiler_num,(setter)Biopower_set_biopwr_plant_boiler_num,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_over_design", (getter)Biopower_get_biopwr_plant_boiler_over_design,(setter)Biopower_set_biopwr_plant_boiler_over_design,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_steam_enthalpy", (getter)Biopower_get_biopwr_plant_boiler_steam_enthalpy,(setter)Biopower_set_biopwr_plant_boiler_steam_enthalpy,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_boiler_steam_pressure", (getter)Biopower_get_biopwr_plant_boiler_steam_pressure,(setter)Biopower_set_biopwr_plant_boiler_steam_pressure,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_combustor_type", (getter)Biopower_get_biopwr_plant_combustor_type,(setter)Biopower_set_biopwr_plant_combustor_type,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_plant_cycle_design_temp", (getter)Biopower_get_biopwr_plant_cycle_design_temp,(setter)Biopower_set_biopwr_plant_cycle_design_temp,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_disp_power", (getter)Biopower_get_biopwr_plant_disp_power,(setter)Biopower_set_biopwr_plant_disp_power,
	" [], array.\n Constraints: LENGTH=9; Required if: *.",
 	NULL},
{"biopwr_plant_drying_method", (getter)Biopower_get_biopwr_plant_drying_method,(setter)Biopower_set_biopwr_plant_drying_method,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_plant_drying_spec", (getter)Biopower_get_biopwr_plant_drying_spec,(setter)Biopower_set_biopwr_plant_drying_spec,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_max_over_design", (getter)Biopower_get_biopwr_plant_max_over_design,(setter)Biopower_set_biopwr_plant_max_over_design,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_min_load", (getter)Biopower_get_biopwr_plant_min_load,(setter)Biopower_set_biopwr_plant_min_load,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_nameplate", (getter)Biopower_get_biopwr_plant_nameplate,(setter)Biopower_set_biopwr_plant_nameplate,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_par_percent", (getter)Biopower_get_biopwr_plant_par_percent,(setter)Biopower_set_biopwr_plant_par_percent,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_pl_eff_f0", (getter)Biopower_get_biopwr_plant_pl_eff_f0,(setter)Biopower_set_biopwr_plant_pl_eff_f0,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_pl_eff_f1", (getter)Biopower_get_biopwr_plant_pl_eff_f1,(setter)Biopower_set_biopwr_plant_pl_eff_f1,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_pl_eff_f2", (getter)Biopower_get_biopwr_plant_pl_eff_f2,(setter)Biopower_set_biopwr_plant_pl_eff_f2,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_pl_eff_f3", (getter)Biopower_get_biopwr_plant_pl_eff_f3,(setter)Biopower_set_biopwr_plant_pl_eff_f3,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_pl_eff_f4", (getter)Biopower_get_biopwr_plant_pl_eff_f4,(setter)Biopower_set_biopwr_plant_pl_eff_f4,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_ramp_rate", (getter)Biopower_get_biopwr_plant_ramp_rate,(setter)Biopower_set_biopwr_plant_ramp_rate,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_rated_eff", (getter)Biopower_get_biopwr_plant_rated_eff,(setter)Biopower_set_biopwr_plant_rated_eff,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_temp_corr_mode", (getter)Biopower_get_biopwr_plant_temp_corr_mode,(setter)Biopower_set_biopwr_plant_temp_corr_mode,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"biopwr_plant_temp_eff_f0", (getter)Biopower_get_biopwr_plant_temp_eff_f0,(setter)Biopower_set_biopwr_plant_temp_eff_f0,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_temp_eff_f1", (getter)Biopower_get_biopwr_plant_temp_eff_f1,(setter)Biopower_set_biopwr_plant_temp_eff_f1,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_temp_eff_f2", (getter)Biopower_get_biopwr_plant_temp_eff_f2,(setter)Biopower_set_biopwr_plant_temp_eff_f2,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_temp_eff_f3", (getter)Biopower_get_biopwr_plant_temp_eff_f3,(setter)Biopower_set_biopwr_plant_temp_eff_f3,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_temp_eff_f4", (getter)Biopower_get_biopwr_plant_temp_eff_f4,(setter)Biopower_set_biopwr_plant_temp_eff_f4,
	" [], number.\n Required if: *.",
 	NULL},
{"biopwr_plant_tou_grid", (getter)Biopower_get_biopwr_plant_tou_grid,(setter)Biopower_set_biopwr_plant_tou_grid,
	" [], string.\n Required if: *.",
 	NULL},
{"biopwr_plant_tou_option", (getter)Biopower_get_biopwr_plant_tou_option,(setter)Biopower_set_biopwr_plant_tou_option,
	" [], number.\n Constraints: INTEGER; Required if: *.",
 	NULL},
{"file_name", (getter)Biopower_get_file_name,(setter)Biopower_set_file_name,
	"Local weather file path [], string.\n Constraints: LOCAL_FILE; Required if: *.",
 	NULL},
{"system_capacity", (getter)Biopower_get_system_capacity,(setter)Biopower_set_system_capacity,
	"Nameplate capacity [kW], number.\n Required if: *.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Biopower_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Biomass.Biopower",             /*tp_name*/
		sizeof(BiopowerObject),          /*tp_basicsize*/
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
		Biopower_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Biopower_getset,          /*tp_getset*/
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
	 * Outputs Group
	 */ 

typedef struct {
	PyObject_HEAD
	SAM_Biomass   data_ptr;
} OutputsObject;

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_Biomass data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	OutputsObject* Outputs_obj = (OutputsObject*)new_obj;

	Outputs_obj->data_ptr = data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(OutputsObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "Biomass", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(OutputsObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_annual_energy(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_annual_energy_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_fuel_usage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_annual_fuel_usage_fget, self->data_ptr);
}

static PyObject *
Outputs_get_annual_watter_usage(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_annual_watter_usage_fget, self->data_ptr);
}

static PyObject *
Outputs_get_capacity_factor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_capacity_factor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_gen(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_gen_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hourly_boiler_eff(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_hourly_boiler_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hourly_pbeta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_hourly_pbeta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_hourly_q_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_hourly_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_kwh_per_kw(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_kwh_per_kw_fget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_bagasse_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_bagasse_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_barley_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_barley_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_boiler_eff(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_boiler_eff_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_energy(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_energy_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_forest_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_forest_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_herb_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_herb_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_hhv_heatrate(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_hhv_heatrate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_lhv_heatrate(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_lhv_heatrate_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_mill_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_mill_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_moist(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_moist_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_pb_eta(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_pb_eta_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_q_to_pb(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_q_to_pb_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_rh(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_rh_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_rice_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_rice_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_stover_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_stover_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_temp_c(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_temp_c_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_urban_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_urban_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_wheat_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_wheat_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_monthly_woody_emc(OutputsObject *self, void *closure)
{
	return PySAM_array_getter(SAM_Biomass_Outputs_monthly_woody_emc_aget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_ash(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_ash_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_biomass(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_biomass_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_dry(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_dry_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_dry_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_dry_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_fuel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_fuel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_fuel_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_fuel_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_manu(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_manu_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_manu_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_manu_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_rad(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_rad_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_rad_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_rad_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_total(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_total_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_total_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_total_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_unburn(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_unburn_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_unburn_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_unburn_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_wet(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_wet_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_loss_wet_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_loss_wet_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_boiler_output(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_boiler_output_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_coal(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_coal_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_e_net(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_e_net_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_par_loss(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_par_loss_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_par_loss_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_par_loss_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_pb_eta(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_pb_eta_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_pb_eta_kwh(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_pb_eta_kwh_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_qtoboil_tot(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_qtoboil_tot_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_qtopb_tot(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_qtopb_tot_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_annual_turbine_output(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_annual_turbine_output_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_capfactor(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_capfactor_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_avoided(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_avoided_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_biodiesel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_biodiesel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_bunker(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_bunker_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_combustion(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_combustion_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_diesel(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_diesel_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_drying(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_drying_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_ems_per_lb(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_ems_per_lb_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_growth(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_growth_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_lime(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_lime_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_naturalgas(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_naturalgas_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_nitrogen(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_nitrogen_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_oil(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_oil_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_phosphorus(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_phosphorus_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_potassium(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_potassium_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_preprocessing(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_preprocessing_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_total_sum(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_total_sum_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_transport(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_transport_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_emissions_uptake(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_emissions_uptake_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_hhv_heatrate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_hhv_heatrate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_hhv_thermeff(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_hhv_thermeff_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_lhv_heatrate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_lhv_heatrate_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_lhv_thermeff(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_lhv_thermeff_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_total_moisture(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_total_moisture_fget, self->data_ptr);
}

static PyObject *
Outputs_get_system_heat_rate(OutputsObject *self, void *closure)
{
	return PySAM_float_getter(SAM_Biomass_Outputs_system_heat_rate_fget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"annual_energy", (getter)Outputs_get_annual_energy,(setter)0,
	"Annual Energy [kWh], number.",
 	NULL},
{"annual_fuel_usage", (getter)Outputs_get_annual_fuel_usage,(setter)0,
	"Annual Fuel Usage [kWht], number.",
 	NULL},
{"annual_watter_usage", (getter)Outputs_get_annual_watter_usage,(setter)0,
	"Annual Water Usage [m3], number.",
 	NULL},
{"capacity_factor", (getter)Outputs_get_capacity_factor,(setter)0,
	"Capacity factor [%], number.",
 	NULL},
{"gen", (getter)Outputs_get_gen,(setter)0,
	"System power generated [kW], array.",
 	NULL},
{"hourly_boiler_eff", (getter)Outputs_get_hourly_boiler_eff,(setter)0,
	"Boiler Efficiency [], array.",
 	NULL},
{"hourly_pbeta", (getter)Outputs_get_hourly_pbeta,(setter)0,
	"Power Block Efficiency [], array.",
 	NULL},
{"hourly_q_to_pb", (getter)Outputs_get_hourly_q_to_pb,(setter)0,
	"Q To Power Block [kW], array.",
 	NULL},
{"kwh_per_kw", (getter)Outputs_get_kwh_per_kw,(setter)0,
	"First year kWh/kW [kWh/kW], number.",
 	NULL},
{"monthly_bagasse_emc", (getter)Outputs_get_monthly_bagasse_emc,(setter)0,
	"Monthly bagasse EMC (dry) [], array.",
 	NULL},
{"monthly_barley_emc", (getter)Outputs_get_monthly_barley_emc,(setter)0,
	"Monthly barley EMC (dry) [], array.",
 	NULL},
{"monthly_boiler_eff", (getter)Outputs_get_monthly_boiler_eff,(setter)0,
	"Total Boiler Efficiency - HHV (%) [%], array.",
 	NULL},
{"monthly_energy", (getter)Outputs_get_monthly_energy,(setter)0,
	"Monthly Energy [kWh], array.",
 	NULL},
{"monthly_forest_emc", (getter)Outputs_get_monthly_forest_emc,(setter)0,
	"Monthly forest EMC (dry) [], array.",
 	NULL},
{"monthly_herb_emc", (getter)Outputs_get_monthly_herb_emc,(setter)0,
	"Monthly herbaceous crop EMC (dry) [], array.",
 	NULL},
{"monthly_hhv_heatrate", (getter)Outputs_get_monthly_hhv_heatrate,(setter)0,
	"Gross Monthly Heat Rate (MMBtu/MWh) [MMBtu/MWh], array.",
 	NULL},
{"monthly_lhv_heatrate", (getter)Outputs_get_monthly_lhv_heatrate,(setter)0,
	"Net Monthly Heat Rate (MMBtu/MWh) [MMBtu/MWh], array.",
 	NULL},
{"monthly_mill_emc", (getter)Outputs_get_monthly_mill_emc,(setter)0,
	"Monthly mill waste EMC (dry) [], array.",
 	NULL},
{"monthly_moist", (getter)Outputs_get_monthly_moist,(setter)0,
	"Monthly biomass moisture fraction (dry) [], array.",
 	NULL},
{"monthly_pb_eta", (getter)Outputs_get_monthly_pb_eta,(setter)0,
	"Power Block Effiency [%], array.",
 	NULL},
{"monthly_q_to_pb", (getter)Outputs_get_monthly_q_to_pb,(setter)0,
	"Q To Power Block [kWh], array.",
 	NULL},
{"monthly_rh", (getter)Outputs_get_monthly_rh,(setter)0,
	"Relative humidity [], array.",
 	NULL},
{"monthly_rice_emc", (getter)Outputs_get_monthly_rice_emc,(setter)0,
	"Monthly rice straw EMC (dry) [], array.",
 	NULL},
{"monthly_stover_emc", (getter)Outputs_get_monthly_stover_emc,(setter)0,
	"Monthly stover EMC (dry) [], array.",
 	NULL},
{"monthly_temp_c", (getter)Outputs_get_monthly_temp_c,(setter)0,
	"Temperature [], array.",
 	NULL},
{"monthly_urban_emc", (getter)Outputs_get_monthly_urban_emc,(setter)0,
	"Monthly urban wood waste EMC (dry) [], array.",
 	NULL},
{"monthly_wheat_emc", (getter)Outputs_get_monthly_wheat_emc,(setter)0,
	"Monthly wheat straw EMC (dry) [], array.",
 	NULL},
{"monthly_woody_emc", (getter)Outputs_get_monthly_woody_emc,(setter)0,
	"Monthly woody crop EMC (dry) [], array.",
 	NULL},
{"system_annual_ash", (getter)Outputs_get_system_annual_ash,(setter)0,
	"Ash produced [tons/yr], number.",
 	NULL},
{"system_annual_biomass", (getter)Outputs_get_system_annual_biomass,(setter)0,
	"Annual biomass usage [dry tons/yr], number.",
 	NULL},
{"system_annual_boiler_loss_dry", (getter)Outputs_get_system_annual_boiler_loss_dry,(setter)0,
	"Energy lost in hot flue gas [%], number.",
 	NULL},
{"system_annual_boiler_loss_dry_kwh", (getter)Outputs_get_system_annual_boiler_loss_dry_kwh,(setter)0,
	"Energy lost in hot flue gas [kWh], number.",
 	NULL},
{"system_annual_boiler_loss_fuel", (getter)Outputs_get_system_annual_boiler_loss_fuel,(setter)0,
	"Energy lost in fuel out of boiler [%], number.",
 	NULL},
{"system_annual_boiler_loss_fuel_kwh", (getter)Outputs_get_system_annual_boiler_loss_fuel_kwh,(setter)0,
	"Energy lost in fuel out of boiler [kWh], number.",
 	NULL},
{"system_annual_boiler_loss_manu", (getter)Outputs_get_system_annual_boiler_loss_manu,(setter)0,
	"Energy loss included in manufacturer's margin [%], number.",
 	NULL},
{"system_annual_boiler_loss_manu_kwh", (getter)Outputs_get_system_annual_boiler_loss_manu_kwh,(setter)0,
	"Energy loss included in manufacturer's margin [kWh], number.",
 	NULL},
{"system_annual_boiler_loss_rad", (getter)Outputs_get_system_annual_boiler_loss_rad,(setter)0,
	"Energy loss due to boiler radiation [%], number.",
 	NULL},
{"system_annual_boiler_loss_rad_kwh", (getter)Outputs_get_system_annual_boiler_loss_rad_kwh,(setter)0,
	"Energy loss due to boiler radiation [kWh], number.",
 	NULL},
{"system_annual_boiler_loss_total", (getter)Outputs_get_system_annual_boiler_loss_total,(setter)0,
	"Energy lost in boiler - total [%], number.",
 	NULL},
{"system_annual_boiler_loss_total_kwh", (getter)Outputs_get_system_annual_boiler_loss_total_kwh,(setter)0,
	"Energy lost in boiler - total [kWh], number.",
 	NULL},
{"system_annual_boiler_loss_unburn", (getter)Outputs_get_system_annual_boiler_loss_unburn,(setter)0,
	"Energy lost in unburned fuel [%], number.",
 	NULL},
{"system_annual_boiler_loss_unburn_kwh", (getter)Outputs_get_system_annual_boiler_loss_unburn_kwh,(setter)0,
	"Energy lost in unburned fuel [kWh], number.",
 	NULL},
{"system_annual_boiler_loss_wet", (getter)Outputs_get_system_annual_boiler_loss_wet,(setter)0,
	"Energy lost to moisture in air [%], number.",
 	NULL},
{"system_annual_boiler_loss_wet_kwh", (getter)Outputs_get_system_annual_boiler_loss_wet_kwh,(setter)0,
	"Energy lost to moisture in air [kWh], number.",
 	NULL},
{"system_annual_boiler_output", (getter)Outputs_get_system_annual_boiler_output,(setter)0,
	"Boiler output [kWh], number.",
 	NULL},
{"system_annual_coal", (getter)Outputs_get_system_annual_coal,(setter)0,
	"Annual coal usage [dry tons/yr], number.",
 	NULL},
{"system_annual_e_net", (getter)Outputs_get_system_annual_e_net,(setter)0,
	"Gross Annual Energy [kWh], number.",
 	NULL},
{"system_annual_par_loss", (getter)Outputs_get_system_annual_par_loss,(setter)0,
	"Energy consumed within plant - parasitic load [%], number.",
 	NULL},
{"system_annual_par_loss_kwh", (getter)Outputs_get_system_annual_par_loss_kwh,(setter)0,
	"Energy consumed within plant - parasitic load [kWh], number.",
 	NULL},
{"system_annual_pb_eta", (getter)Outputs_get_system_annual_pb_eta,(setter)0,
	"Energy lost in steam turbine and generator [%], number.",
 	NULL},
{"system_annual_pb_eta_kwh", (getter)Outputs_get_system_annual_pb_eta_kwh,(setter)0,
	"Energy lost in steam turbine and generator [kWh], number.",
 	NULL},
{"system_annual_qtoboil_tot", (getter)Outputs_get_system_annual_qtoboil_tot,(setter)0,
	"Q to Boiler [kWh], number.",
 	NULL},
{"system_annual_qtopb_tot", (getter)Outputs_get_system_annual_qtopb_tot,(setter)0,
	"Q to Power Block [kWh], number.",
 	NULL},
{"system_annual_turbine_output", (getter)Outputs_get_system_annual_turbine_output,(setter)0,
	"Turbine output [kWh], number.",
 	NULL},
{"system_capfactor", (getter)Outputs_get_system_capfactor,(setter)0,
	"Annual Capacity Factor (%) [%], number.",
 	NULL},
{"system_emissions_avoided", (getter)Outputs_get_system_emissions_avoided,(setter)0,
	"Biomass Avoided Use [kWh], number.",
 	NULL},
{"system_emissions_biodiesel", (getter)Outputs_get_system_emissions_biodiesel,(setter)0,
	"Life Cycle Biodiesel use [Btu/kWh], number.",
 	NULL},
{"system_emissions_bunker", (getter)Outputs_get_system_emissions_bunker,(setter)0,
	"Life Cycle Bunker fuel use [Btu/kWh], number.",
 	NULL},
{"system_emissions_combustion", (getter)Outputs_get_system_emissions_combustion,(setter)0,
	"Combustion [kWh], number.",
 	NULL},
{"system_emissions_diesel", (getter)Outputs_get_system_emissions_diesel,(setter)0,
	"Life Cycle Diesel use [Btu/kWh], number.",
 	NULL},
{"system_emissions_drying", (getter)Outputs_get_system_emissions_drying,(setter)0,
	"Biomass Drying [kWh], number.",
 	NULL},
{"system_emissions_ems_per_lb", (getter)Outputs_get_system_emissions_ems_per_lb,(setter)0,
	"Life Cycle g CO2eq released/lb dry biomass [], number.",
 	NULL},
{"system_emissions_growth", (getter)Outputs_get_system_emissions_growth,(setter)0,
	"Biomass Collection [kWh], number.",
 	NULL},
{"system_emissions_lime", (getter)Outputs_get_system_emissions_lime,(setter)0,
	"Life Cycle Lime fertilizer use [lb Lime/kWh], number.",
 	NULL},
{"system_emissions_naturalgas", (getter)Outputs_get_system_emissions_naturalgas,(setter)0,
	"Life Cycle Natural gas use [Btu/kWh], number.",
 	NULL},
{"system_emissions_nitrogen", (getter)Outputs_get_system_emissions_nitrogen,(setter)0,
	"Life Cycle Nitrogen fertilizer use [lb N/kWh], number.",
 	NULL},
{"system_emissions_oil", (getter)Outputs_get_system_emissions_oil,(setter)0,
	"Life Cycle Oil use [Btu/kWh], number.",
 	NULL},
{"system_emissions_phosphorus", (getter)Outputs_get_system_emissions_phosphorus,(setter)0,
	"Life Cycle Phosphorus fertilizer use [lb K2O/kWh], number.",
 	NULL},
{"system_emissions_potassium", (getter)Outputs_get_system_emissions_potassium,(setter)0,
	"Life Cycle Potassium fertilizer use [lb P2O5/kWh], number.",
 	NULL},
{"system_emissions_preprocessing", (getter)Outputs_get_system_emissions_preprocessing,(setter)0,
	"Biomass Preprocessing [kWh], number.",
 	NULL},
{"system_emissions_total_sum", (getter)Outputs_get_system_emissions_total_sum,(setter)0,
	"Biomass Life Cycle CO2 [kWh], number.",
 	NULL},
{"system_emissions_transport", (getter)Outputs_get_system_emissions_transport,(setter)0,
	"Biomass Transport [kWh], number.",
 	NULL},
{"system_emissions_uptake", (getter)Outputs_get_system_emissions_uptake,(setter)0,
	"Biomass CO2 Uptake [kWh], number.",
 	NULL},
{"system_hhv_heatrate", (getter)Outputs_get_system_hhv_heatrate,(setter)0,
	"Gross Heat Rate (MMBtu/MWh) [MMBtu/MWh], number.",
 	NULL},
{"system_hhv_thermeff", (getter)Outputs_get_system_hhv_thermeff,(setter)0,
	"Thermal efficiency, HHV (%) [%], number.",
 	NULL},
{"system_lhv_heatrate", (getter)Outputs_get_system_lhv_heatrate,(setter)0,
	"Net Heat Rate (MMBtu/MWh) [MMBtu/MWh], number.",
 	NULL},
{"system_lhv_thermeff", (getter)Outputs_get_system_lhv_thermeff,(setter)0,
	"Thermal efficiency, LHV (%) [%], number.",
 	NULL},
{"system_total_moisture", (getter)Outputs_get_system_total_moisture,(setter)0,
	"Overall Moisture Content (dry %) [%], number.",
 	NULL},
{"system_heat_rate", (getter)Outputs_get_system_heat_rate,(setter)0,
	"Heat Rate Conversion Factor (MMBTUs/MWhe) [MMBTUs/MWhe], number.",
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Biomass.Outputs",             /*tp_name*/
		sizeof(OutputsObject),          /*tp_basicsize*/
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
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
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
 * Biomass
 */

typedef struct {
	PyObject_HEAD
	PyObject            *x_attr;        /* Attributes dictionary */
	SAM_Biomass   data_ptr;
} BiomassObject;

static PyTypeObject Biomass_Type;

#define BiomassObject_Check(v)      (Py_TYPE(v) == &Biomass_Type)

static BiomassObject *
newBiomassObject(void* data_ptr)
{
	BiomassObject *self;
	self = PyObject_New(BiomassObject, &Biomass_Type);

	PySAM_TECH_ATTR("Biomass", SAM_Biomass_construct)

PyObject* Biopower_obj = Biopower_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Biopower", Biopower_obj);
	Py_DECREF(Biopower_obj);

PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

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

/* Biomass methods */

static void
Biomass_dealloc(BiomassObject *self)
{
	Py_XDECREF(self->x_attr);
	SAM_Biomass_destruct(self->data_ptr);
	PyObject_Del(self);
}


static PyObject *
Biomass_execute(BiomassObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_Biomass_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Biomass_assign(BiomassObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict(self, self->x_attr, self->data_ptr, dict, "Biomass"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
Biomass_export(BiomassObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}


static PyMethodDef Biomass_methods[] = {
		{"execute",            (PyCFunction)Biomass_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)Biomass_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs")},
		{"export",            (PyCFunction)Biomass_export,  METH_VARARGS,
				PyDoc_STR("assign() -> None\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Biomass_getattro(BiomassObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
Biomass_setattr(BiomassObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject Biomass_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"Biomass",            /*tp_name*/
		sizeof(BiomassObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)Biomass_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)Biomass_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)Biomass_getattro, /*tp_getattro*/
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
		Biomass_methods,      /*tp_methods*/
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


/* Function of no arguments returning new Biomass object */

static PyObject *
Biomass_new(PyObject *self, PyObject *args)
{
	BiomassObject *rv;
	rv = newBiomassObject(0);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Biomass_wrap(PyObject *self, PyObject *args)
{
	BiomassObject *rv;
	long int ptr = 0;
	if (!PyArg_ParseTuple(args, "l:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBiomassObject((void*)ptr);
	if (rv == NULL)
		return NULL;
	return (PyObject *)rv;
}

static PyObject *
Biomass_default(PyObject *self, PyObject *args)
{
	BiomassObject *rv;
	char* fin = 0;
	if (!PyArg_ParseTuple(args, "s:default", &fin)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newBiomassObject(0);
	if (rv == NULL)
		return NULL;

	PySAM_load_defaults(rv, rv->x_attr, rv->data_ptr, "Biomass", fin);

	return (PyObject *)rv;
}

/* ---------- */


/* List of functions defined in the module */

static PyMethodDef BiomassModule_methods[] = {
		{"new",             Biomass_new,         METH_VARARGS,
				PyDoc_STR("new() -> new Biomass object")},
		{"wrap",             Biomass_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> new Biomass object around existing data")},
		{"default",             Biomass_default,         METH_VARARGS,
				PyDoc_STR("default(financial) -> new Biomass object with financial model-specific default attributes")},		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "This is a template module just for instruction.");


static int
BiomassModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	Biomass_Type.tp_dict = PyDict_New();
	if (!Biomass_Type.tp_dict) { goto fail; }

	/// Add the AdjustmentFactors type object to Biomass_Type
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
	PyDict_SetItemString(Biomass_Type.tp_dict,
						 "AdjustmentFactors",
						 (PyObject*)AdjustmentFactors_Type);
	Py_DECREF(&AdjustmentFactors_Type);
	Py_XDECREF(AdjustmentFactors_Type);

	/// Add the Biopower type object to Biomass_Type
	if (PyType_Ready(&Biopower_Type) < 0) { goto fail; }
	PyDict_SetItemString(Biomass_Type.tp_dict,
				"Biopower",
				(PyObject*)&Biopower_Type);
	Py_DECREF(&Biopower_Type);

	/// Add the Outputs type object to Biomass_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(Biomass_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the Biomass type object to the module
	if (PyType_Ready(&Biomass_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"Biomass",
				(PyObject*)&Biomass_Type);

	if (PySAM_load_lib(m) < 0) goto fail;
	if (PySAM_init_error() < 0) goto fail;

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot BiomassModule_slots[] = {
		{Py_mod_exec, BiomassModule_exec},
		{0, NULL},
};

static struct PyModuleDef BiomassModule = {
		PyModuleDef_HEAD_INIT,
		"Biomass",
		module_doc,
		0,
		BiomassModule_methods,
		BiomassModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_Biomass(void)
{
	return PyModuleDef_Init(&BiomassModule);
}