#include <Python.h>

#include <SAM_WindObos.h>
#include <SAM_api.h>

#include "PySAM_utils.h"


/*
 * Wobos Group
 */ 

static PyTypeObject Wobos_Type;

static PyObject *
Wobos_new(SAM_WindObos data_ptr)
{
	PyObject* new_obj = Wobos_Type.tp_alloc(&Wobos_Type,0);

	VarGroupObject* Wobos_obj = (VarGroupObject*)new_obj;

	Wobos_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Wobos methods */

static PyObject *
Wobos_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "WindObos", "Wobos")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Wobos_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Wobos_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Wobos_methods[] = {
		{"assign",            (PyCFunction)Wobos_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Wobos_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Wobos_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Wobos_get_addLocPerm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_addLocPerm_nget, self->data_ptr);
}

static int
Wobos_set_addLocPerm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_addLocPerm_nset, self->data_ptr);
}

static PyObject *
Wobos_get_anchor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_anchor_nget, self->data_ptr);
}

static int
Wobos_set_anchor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_anchor_nset, self->data_ptr);
}

static PyObject *
Wobos_get_arrCab1Mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_arrCab1Mass_nget, self->data_ptr);
}

static int
Wobos_set_arrCab1Mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_arrCab1Mass_nset, self->data_ptr);
}

static PyObject *
Wobos_get_arrCab2Mass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_arrCab2Mass_nget, self->data_ptr);
}

static int
Wobos_set_arrCab2Mass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_arrCab2Mass_nset, self->data_ptr);
}

static PyObject *
Wobos_get_arrVoltage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_arrVoltage_nget, self->data_ptr);
}

static int
Wobos_set_arrVoltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_arrVoltage_nset, self->data_ptr);
}

static PyObject *
Wobos_get_arrayCables(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindObos_Wobos_arrayCables_sget, self->data_ptr);
}

static int
Wobos_set_arrayCables(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_WindObos_Wobos_arrayCables_sset, self->data_ptr);
}

static PyObject *
Wobos_get_arrayX(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_arrayX_nget, self->data_ptr);
}

static int
Wobos_set_arrayX(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_arrayX_nset, self->data_ptr);
}

static PyObject *
Wobos_get_arrayY(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_arrayY_nget, self->data_ptr);
}

static int
Wobos_set_arrayY(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_arrayY_nset, self->data_ptr);
}

static PyObject *
Wobos_get_backUpGen(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_backUpGen_nget, self->data_ptr);
}

static int
Wobos_set_backUpGen(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_backUpGen_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ballCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ballCR_nget, self->data_ptr);
}

static int
Wobos_set_ballCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ballCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_bioResStudyMet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_bioResStudyMet_nget, self->data_ptr);
}

static int
Wobos_set_bioResStudyMet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_bioResStudyMet_nset, self->data_ptr);
}

static PyObject *
Wobos_get_bioResStudyProj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_bioResStudyProj_nget, self->data_ptr);
}

static int
Wobos_set_bioResStudyProj(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_bioResStudyProj_nset, self->data_ptr);
}

static PyObject *
Wobos_get_bladeL(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_bladeL_nget, self->data_ptr);
}

static int
Wobos_set_bladeL(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_bladeL_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltBlade1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltBlade1_nget, self->data_ptr);
}

static int
Wobos_set_boltBlade1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltBlade1_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltBlade2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltBlade2_nget, self->data_ptr);
}

static int
Wobos_set_boltBlade2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltBlade2_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltNacelle1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltNacelle1_nget, self->data_ptr);
}

static int
Wobos_set_boltNacelle1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltNacelle1_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltNacelle2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltNacelle2_nget, self->data_ptr);
}

static int
Wobos_set_boltNacelle2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltNacelle2_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltNacelle3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltNacelle3_nget, self->data_ptr);
}

static int
Wobos_set_boltNacelle3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltNacelle3_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltRotor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltRotor_nget, self->data_ptr);
}

static int
Wobos_set_boltRotor(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltRotor_nset, self->data_ptr);
}

static PyObject *
Wobos_get_boltTower(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_boltTower_nget, self->data_ptr);
}

static int
Wobos_set_boltTower(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_boltTower_nset, self->data_ptr);
}

static PyObject *
Wobos_get_buryDepth(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_buryDepth_nget, self->data_ptr);
}

static int
Wobos_set_buryDepth(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_buryDepth_nset, self->data_ptr);
}

static PyObject *
Wobos_get_buryFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_buryFac_nget, self->data_ptr);
}

static int
Wobos_set_buryFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_buryFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_buryRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_buryRate_nget, self->data_ptr);
}

static int
Wobos_set_buryRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_buryRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab1CR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab1CR_nget, self->data_ptr);
}

static int
Wobos_set_cab1CR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab1CR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab1CurrRating(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab1CurrRating_nget, self->data_ptr);
}

static int
Wobos_set_cab1CurrRating(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab1CurrRating_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab1TurbInterCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab1TurbInterCR_nget, self->data_ptr);
}

static int
Wobos_set_cab1TurbInterCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab1TurbInterCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab2CR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab2CR_nget, self->data_ptr);
}

static int
Wobos_set_cab2CR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab2CR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab2CurrRating(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab2CurrRating_nget, self->data_ptr);
}

static int
Wobos_set_cab2CurrRating(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab2CurrRating_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab2SubsInterCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab2SubsInterCR_nget, self->data_ptr);
}

static int
Wobos_set_cab2SubsInterCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab2SubsInterCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cab2TurbInterCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cab2TurbInterCR_nget, self->data_ptr);
}

static int
Wobos_set_cab2TurbInterCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cab2TurbInterCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cabDrillCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cabDrillCR_nget, self->data_ptr);
}

static int
Wobos_set_cabDrillCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cabDrillCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cabDrillDist(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cabDrillDist_nget, self->data_ptr);
}

static int
Wobos_set_cabDrillDist(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cabDrillDist_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cabLoadout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cabLoadout_nget, self->data_ptr);
}

static int
Wobos_set_cabLoadout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cabLoadout_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cabPullIn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cabPullIn_nget, self->data_ptr);
}

static int
Wobos_set_cabPullIn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cabPullIn_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cabSurveyCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cabSurveyCR_nget, self->data_ptr);
}

static int
Wobos_set_cabSurveyCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cabSurveyCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cabTerm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cabTerm_nget, self->data_ptr);
}

static int
Wobos_set_cabTerm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cabTerm_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cableOptimizer(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cableOptimizer_nget, self->data_ptr);
}

static int
Wobos_set_cableOptimizer(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cableOptimizer_nset, self->data_ptr);
}

static PyObject *
Wobos_get_capital_cost_year_0(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_capital_cost_year_0_nget, self->data_ptr);
}

static int
Wobos_set_capital_cost_year_0(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_capital_cost_year_0_nset, self->data_ptr);
}

static PyObject *
Wobos_get_capital_cost_year_1(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_capital_cost_year_1_nget, self->data_ptr);
}

static int
Wobos_set_capital_cost_year_1(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_capital_cost_year_1_nset, self->data_ptr);
}

static PyObject *
Wobos_get_capital_cost_year_2(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_capital_cost_year_2_nget, self->data_ptr);
}

static int
Wobos_set_capital_cost_year_2(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_capital_cost_year_2_nset, self->data_ptr);
}

static PyObject *
Wobos_get_capital_cost_year_3(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_capital_cost_year_3_nget, self->data_ptr);
}

static int
Wobos_set_capital_cost_year_3(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_capital_cost_year_3_nset, self->data_ptr);
}

static PyObject *
Wobos_get_capital_cost_year_4(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_capital_cost_year_4_nget, self->data_ptr);
}

static int
Wobos_set_capital_cost_year_4(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_capital_cost_year_4_nset, self->data_ptr);
}

static PyObject *
Wobos_get_capital_cost_year_5(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_capital_cost_year_5_nget, self->data_ptr);
}

static int
Wobos_set_capital_cost_year_5(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_capital_cost_year_5_nset, self->data_ptr);
}

static PyObject *
Wobos_get_catLengFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_catLengFac_nget, self->data_ptr);
}

static int
Wobos_set_catLengFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_catLengFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_chord(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_chord_nget, self->data_ptr);
}

static int
Wobos_set_chord(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_chord_nset, self->data_ptr);
}

static PyObject *
Wobos_get_civilWork(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_civilWork_nget, self->data_ptr);
}

static int
Wobos_set_civilWork(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_civilWork_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cleanWatAct402(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cleanWatAct402_nget, self->data_ptr);
}

static int
Wobos_set_cleanWatAct402(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cleanWatAct402_nset, self->data_ptr);
}

static PyObject *
Wobos_get_cleanWatAct404(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_cleanWatAct404_nget, self->data_ptr);
}

static int
Wobos_set_cleanWatAct404(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_cleanWatAct404_nset, self->data_ptr);
}

static PyObject *
Wobos_get_coastZoneManAct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_coastZoneManAct_nget, self->data_ptr);
}

static int
Wobos_set_coastZoneManAct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_coastZoneManAct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_compRacks(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_compRacks_nget, self->data_ptr);
}

static int
Wobos_set_compRacks(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_compRacks_nset, self->data_ptr);
}

static PyObject *
Wobos_get_conOpPlan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_conOpPlan_nget, self->data_ptr);
}

static int
Wobos_set_conOpPlan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_conOpPlan_nset, self->data_ptr);
}

static PyObject *
Wobos_get_construction_insurance(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_construction_insurance_nget, self->data_ptr);
}

static int
Wobos_set_construction_insurance(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_construction_insurance_nset, self->data_ptr);
}

static PyObject *
Wobos_get_crane1000DR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_crane1000DR_nget, self->data_ptr);
}

static int
Wobos_set_crane1000DR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_crane1000DR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_crane600DR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_crane600DR_nget, self->data_ptr);
}

static int
Wobos_set_crane600DR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_crane600DR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_craneMobDemob(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_craneMobDemob_nget, self->data_ptr);
}

static int
Wobos_set_craneMobDemob(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_craneMobDemob_nset, self->data_ptr);
}

static PyObject *
Wobos_get_deaFixLeng(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_deaFixLeng_nget, self->data_ptr);
}

static int
Wobos_set_deaFixLeng(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_deaFixLeng_nset, self->data_ptr);
}

static PyObject *
Wobos_get_decomDiscRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_decomDiscRate_nget, self->data_ptr);
}

static int
Wobos_set_decomDiscRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_decomDiscRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_distAtoS(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_distAtoS_nget, self->data_ptr);
}

static int
Wobos_set_distAtoS(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_distAtoS_nset, self->data_ptr);
}

static PyObject *
Wobos_get_distInterCon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_distInterCon_nget, self->data_ptr);
}

static int
Wobos_set_distInterCon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_distInterCon_nset, self->data_ptr);
}

static PyObject *
Wobos_get_distPort(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_distPort_nget, self->data_ptr);
}

static int
Wobos_set_distPort(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_distPort_nset, self->data_ptr);
}

static PyObject *
Wobos_get_distPtoA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_distPtoA_nget, self->data_ptr);
}

static int
Wobos_set_distPtoA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_distPtoA_nset, self->data_ptr);
}

static PyObject *
Wobos_get_distShore(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_distShore_nget, self->data_ptr);
}

static int
Wobos_set_distShore(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_distShore_nset, self->data_ptr);
}

static PyObject *
Wobos_get_diveTeamDR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_diveTeamDR_nget, self->data_ptr);
}

static int
Wobos_set_diveTeamDR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_diveTeamDR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_dockRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_dockRate_nget, self->data_ptr);
}

static int
Wobos_set_dockRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_dockRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_dynCabFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_dynCabFac_nget, self->data_ptr);
}

static int
Wobos_set_dynCabFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_dynCabFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_elecCont(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_elecCont_nget, self->data_ptr);
}

static int
Wobos_set_elecCont(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_elecCont_nset, self->data_ptr);
}

static PyObject *
Wobos_get_elecWork(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_elecWork_nget, self->data_ptr);
}

static int
Wobos_set_elecWork(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_elecWork_nset, self->data_ptr);
}

static PyObject *
Wobos_get_endSpecAct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_endSpecAct_nget, self->data_ptr);
}

static int
Wobos_set_endSpecAct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_endSpecAct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_entranceExitRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_entranceExitRate_nget, self->data_ptr);
}

static int
Wobos_set_entranceExitRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_entranceExitRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_estEnMFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_estEnMFac_nget, self->data_ptr);
}

static int
Wobos_set_estEnMFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_estEnMFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_exCabFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_exCabFac_nget, self->data_ptr);
}

static int
Wobos_set_exCabFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_exCabFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_expCabCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_expCabCR_nget, self->data_ptr);
}

static int
Wobos_set_expCabCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_expCabCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_expCabLoad(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_expCabLoad_nget, self->data_ptr);
}

static int
Wobos_set_expCabLoad(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_expCabLoad_nset, self->data_ptr);
}

static PyObject *
Wobos_get_expCabMass(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_expCabMass_nget, self->data_ptr);
}

static int
Wobos_set_expCabMass(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_expCabMass_nset, self->data_ptr);
}

static PyObject *
Wobos_get_expCurrRating(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_expCurrRating_nget, self->data_ptr);
}

static int
Wobos_set_expCurrRating(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_expCurrRating_nset, self->data_ptr);
}

static PyObject *
Wobos_get_expSubsInterCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_expSubsInterCR_nget, self->data_ptr);
}

static int
Wobos_set_expSubsInterCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_expSubsInterCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_expVoltage(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_expVoltage_nget, self->data_ptr);
}

static int
Wobos_set_expVoltage(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_expVoltage_nset, self->data_ptr);
}

static PyObject *
Wobos_get_exportCables(VarGroupObject *self, void *closure)
{
	return PySAM_string_getter(SAM_WindObos_Wobos_exportCables_sget, self->data_ptr);
}

static int
Wobos_set_exportCables(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_string_setter(value, SAM_WindObos_Wobos_exportCables_sset, self->data_ptr);
}

static PyObject *
Wobos_get_faaPlan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_faaPlan_nget, self->data_ptr);
}

static int
Wobos_set_faaPlan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_faaPlan_nset, self->data_ptr);
}

static PyObject *
Wobos_get_feedStudy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_feedStudy_nget, self->data_ptr);
}

static int
Wobos_set_feedStudy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_feedStudy_nset, self->data_ptr);
}

static PyObject *
Wobos_get_groutSpreadDR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_groutSpreadDR_nget, self->data_ptr);
}

static int
Wobos_set_groutSpreadDR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_groutSpreadDR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_groutSpreadMob(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_groutSpreadMob_nget, self->data_ptr);
}

static int
Wobos_set_groutSpreadMob(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_groutSpreadMob_nset, self->data_ptr);
}

static PyObject *
Wobos_get_groutTP(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_groutTP_nget, self->data_ptr);
}

static int
Wobos_set_groutTP(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_groutTP_nset, self->data_ptr);
}

static PyObject *
Wobos_get_hamRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_hamRate_nget, self->data_ptr);
}

static int
Wobos_set_hamRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_hamRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_highVoltSG(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_highVoltSG_nget, self->data_ptr);
}

static int
Wobos_set_highVoltSG(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_highVoltSG_nset, self->data_ptr);
}

static PyObject *
Wobos_get_hubD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_hubD_nget, self->data_ptr);
}

static int
Wobos_set_hubD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_hubD_nset, self->data_ptr);
}

static PyObject *
Wobos_get_hubH(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_hubH_nget, self->data_ptr);
}

static int
Wobos_set_hubH(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_hubH_nset, self->data_ptr);
}

static PyObject *
Wobos_get_inspectClear(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_inspectClear_nget, self->data_ptr);
}

static int
Wobos_set_inspectClear(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_inspectClear_nset, self->data_ptr);
}

static PyObject *
Wobos_get_instScour(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_instScour_nget, self->data_ptr);
}

static int
Wobos_set_instScour(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_instScour_nset, self->data_ptr);
}

static PyObject *
Wobos_get_installStrategy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_installStrategy_nget, self->data_ptr);
}

static int
Wobos_set_installStrategy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_installStrategy_nset, self->data_ptr);
}

static PyObject *
Wobos_get_install_contingency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_install_contingency_nget, self->data_ptr);
}

static int
Wobos_set_install_contingency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_install_contingency_nset, self->data_ptr);
}

static PyObject *
Wobos_get_interConVolt(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_interConVolt_nget, self->data_ptr);
}

static int
Wobos_set_interConVolt(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_interConVolt_nset, self->data_ptr);
}

static PyObject *
Wobos_get_interest_during_construction(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_interest_during_construction_nget, self->data_ptr);
}

static int
Wobos_set_interest_during_construction(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_interest_during_construction_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jackFasten(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jackFasten_nget, self->data_ptr);
}

static int
Wobos_set_jackFasten(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jackFasten_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jlatticeA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jlatticeA_nget, self->data_ptr);
}

static int
Wobos_set_jlatticeA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jlatticeA_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jlatticeCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jlatticeCR_nget, self->data_ptr);
}

static int
Wobos_set_jlatticeCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jlatticeCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jpileCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jpileCR_nget, self->data_ptr);
}

static int
Wobos_set_jpileCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jpileCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jpileD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jpileD_nget, self->data_ptr);
}

static int
Wobos_set_jpileD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jpileD_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jpileL(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jpileL_nget, self->data_ptr);
}

static int
Wobos_set_jpileL(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jpileL_nset, self->data_ptr);
}

static PyObject *
Wobos_get_jtransCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_jtransCR_nget, self->data_ptr);
}

static int
Wobos_set_jtransCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_jtransCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_landConstruct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_landConstruct_nget, self->data_ptr);
}

static int
Wobos_set_landConstruct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_landConstruct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_laydownCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_laydownCR_nget, self->data_ptr);
}

static int
Wobos_set_laydownCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_laydownCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_levJack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_levJack_nget, self->data_ptr);
}

static int
Wobos_set_levJack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_levJack_nset, self->data_ptr);
}

static PyObject *
Wobos_get_marMamProtAct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_marMamProtAct_nget, self->data_ptr);
}

static int
Wobos_set_marMamProtAct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_marMamProtAct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_medVoltSG(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_medVoltSG_nget, self->data_ptr);
}

static int
Wobos_set_medVoltSG(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_medVoltSG_nset, self->data_ptr);
}

static PyObject *
Wobos_get_metTowCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_metTowCR_nget, self->data_ptr);
}

static int
Wobos_set_metTowCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_metTowCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_migBirdAct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_migBirdAct_nget, self->data_ptr);
}

static int
Wobos_set_migBirdAct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_migBirdAct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_monoFasten(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_monoFasten_nget, self->data_ptr);
}

static int
Wobos_set_monoFasten(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_monoFasten_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorCR_nget, self->data_ptr);
}

static int
Wobos_set_moorCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorCost_nget, self->data_ptr);
}

static int
Wobos_set_moorCost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorCost_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorDia(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorDia_nget, self->data_ptr);
}

static int
Wobos_set_moorDia(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorDia_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorLines(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorLines_nget, self->data_ptr);
}

static int
Wobos_set_moorLines(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorLines_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorLoadout(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorLoadout_nget, self->data_ptr);
}

static int
Wobos_set_moorLoadout(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorLoadout_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorSurvey(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorSurvey_nget, self->data_ptr);
}

static int
Wobos_set_moorSurvey(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorSurvey_nset, self->data_ptr);
}

static PyObject *
Wobos_get_moorTimeFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_moorTimeFac_nget, self->data_ptr);
}

static int
Wobos_set_moorTimeFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_moorTimeFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mpEmbedL(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mpEmbedL_nget, self->data_ptr);
}

static int
Wobos_set_mpEmbedL(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mpEmbedL_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mpileCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mpileCR_nget, self->data_ptr);
}

static int
Wobos_set_mpileCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mpileCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mpileD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mpileD_nget, self->data_ptr);
}

static int
Wobos_set_mpileD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mpileD_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mpileL(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mpileL_nget, self->data_ptr);
}

static int
Wobos_set_mpileL(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mpileL_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mptCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mptCR_nget, self->data_ptr);
}

static int
Wobos_set_mptCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mptCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mpvRentalDR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mpvRentalDR_nget, self->data_ptr);
}

static int
Wobos_set_mpvRentalDR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mpvRentalDR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_mtransCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_mtransCR_nget, self->data_ptr);
}

static int
Wobos_set_mtransCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_mtransCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nCrane1000(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nCrane1000_nget, self->data_ptr);
}

static int
Wobos_set_nCrane1000(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nCrane1000_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nCrane600(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nCrane600_nget, self->data_ptr);
}

static int
Wobos_set_nCrane600(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nCrane600_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nTurb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nTurb_nget, self->data_ptr);
}

static int
Wobos_set_nTurb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nTurb_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nacelleL(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nacelleL_nget, self->data_ptr);
}

static int
Wobos_set_nacelleL(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nacelleL_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nacelleW(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nacelleW_nget, self->data_ptr);
}

static int
Wobos_set_nacelleW(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nacelleW_nset, self->data_ptr);
}

static PyObject *
Wobos_get_natHisPresAct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_natHisPresAct_nget, self->data_ptr);
}

static int
Wobos_set_natHisPresAct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_natHisPresAct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_navStudyMet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_navStudyMet_nget, self->data_ptr);
}

static int
Wobos_set_navStudyMet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_navStudyMet_nset, self->data_ptr);
}

static PyObject *
Wobos_get_navStudyProj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_navStudyProj_nget, self->data_ptr);
}

static int
Wobos_set_navStudyProj(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_navStudyProj_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nepaEisMet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nepaEisMet_nget, self->data_ptr);
}

static int
Wobos_set_nepaEisMet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nepaEisMet_nset, self->data_ptr);
}

static PyObject *
Wobos_get_nepaEisProj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_nepaEisProj_nget, self->data_ptr);
}

static int
Wobos_set_nepaEisProj(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_nepaEisProj_nset, self->data_ptr);
}

static PyObject *
Wobos_get_number_install_seasons(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_number_install_seasons_nget, self->data_ptr);
}

static int
Wobos_set_number_install_seasons(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_number_install_seasons_nset, self->data_ptr);
}

static PyObject *
Wobos_get_otherAncillary(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_otherAncillary_nget, self->data_ptr);
}

static int
Wobos_set_otherAncillary(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_otherAncillary_nset, self->data_ptr);
}

static PyObject *
Wobos_get_outConShelfLease(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_outConShelfLease_nget, self->data_ptr);
}

static int
Wobos_set_outConShelfLease(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_outConShelfLease_nset, self->data_ptr);
}

static PyObject *
Wobos_get_physResStudyMet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_physResStudyMet_nget, self->data_ptr);
}

static int
Wobos_set_physResStudyMet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_physResStudyMet_nset, self->data_ptr);
}

static PyObject *
Wobos_get_physResStudyProj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_physResStudyProj_nget, self->data_ptr);
}

static int
Wobos_set_physResStudyProj(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_physResStudyProj_nset, self->data_ptr);
}

static PyObject *
Wobos_get_pileSpreadDR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_pileSpreadDR_nget, self->data_ptr);
}

static int
Wobos_set_pileSpreadDR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_pileSpreadDR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_pileSpreadMob(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_pileSpreadMob_nget, self->data_ptr);
}

static int
Wobos_set_pileSpreadMob(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_pileSpreadMob_nset, self->data_ptr);
}

static PyObject *
Wobos_get_placeJack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_placeJack_nget, self->data_ptr);
}

static int
Wobos_set_placeJack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_placeJack_nset, self->data_ptr);
}

static PyObject *
Wobos_get_placeMP(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_placeMP_nget, self->data_ptr);
}

static int
Wobos_set_placeMP(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_placeMP_nset, self->data_ptr);
}

static PyObject *
Wobos_get_placePiles(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_placePiles_nget, self->data_ptr);
}

static int
Wobos_set_placePiles(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_placePiles_nset, self->data_ptr);
}

static PyObject *
Wobos_get_placeTP(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_placeTP_nget, self->data_ptr);
}

static int
Wobos_set_placeTP(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_placeTP_nset, self->data_ptr);
}

static PyObject *
Wobos_get_placeTemplate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_placeTemplate_nget, self->data_ptr);
}

static int
Wobos_set_placeTemplate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_placeTemplate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_placeTop(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_placeTop_nget, self->data_ptr);
}

static int
Wobos_set_placeTop(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_placeTop_nset, self->data_ptr);
}

static PyObject *
Wobos_get_plantComm(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_plantComm_nget, self->data_ptr);
}

static int
Wobos_set_plantComm(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_plantComm_nset, self->data_ptr);
}

static PyObject *
Wobos_get_preFEEDStudy(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_preFEEDStudy_nget, self->data_ptr);
}

static int
Wobos_set_preFEEDStudy(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_preFEEDStudy_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepAA(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepAA_nget, self->data_ptr);
}

static int
Wobos_set_prepAA(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepAA_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepGripperJack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepGripperJack_nget, self->data_ptr);
}

static int
Wobos_set_prepGripperJack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepGripperJack_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepGripperMono(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepGripperMono_nget, self->data_ptr);
}

static int
Wobos_set_prepGripperMono(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepGripperMono_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepHamJack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepHamJack_nget, self->data_ptr);
}

static int
Wobos_set_prepHamJack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepHamJack_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepHamMono(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepHamMono_nget, self->data_ptr);
}

static int
Wobos_set_prepHamMono(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepHamMono_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepSemi(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepSemi_nget, self->data_ptr);
}

static int
Wobos_set_prepSemi(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepSemi_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepSpar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepSpar_nget, self->data_ptr);
}

static int
Wobos_set_prepSpar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepSpar_nset, self->data_ptr);
}

static PyObject *
Wobos_get_prepTow(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_prepTow_nget, self->data_ptr);
}

static int
Wobos_set_prepTow(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_prepTow_nset, self->data_ptr);
}

static PyObject *
Wobos_get_procurement_contingency(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_procurement_contingency_nget, self->data_ptr);
}

static int
Wobos_set_procurement_contingency(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_procurement_contingency_nset, self->data_ptr);
}

static PyObject *
Wobos_get_projLife(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_projLife_nget, self->data_ptr);
}

static int
Wobos_set_projLife(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_projLife_nset, self->data_ptr);
}

static PyObject *
Wobos_get_pwrFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_pwrFac_nget, self->data_ptr);
}

static int
Wobos_set_pwrFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_pwrFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_removeHamJack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_removeHamJack_nget, self->data_ptr);
}

static int
Wobos_set_removeHamJack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_removeHamJack_nset, self->data_ptr);
}

static PyObject *
Wobos_get_removeHamMono(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_removeHamMono_nget, self->data_ptr);
}

static int
Wobos_set_removeHamMono(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_removeHamMono_nset, self->data_ptr);
}

static PyObject *
Wobos_get_rivsnHarbsAct(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_rivsnHarbsAct_nget, self->data_ptr);
}

static int
Wobos_set_rivsnHarbsAct(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_rivsnHarbsAct_nset, self->data_ptr);
}

static PyObject *
Wobos_get_rnaM(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_rnaM_nget, self->data_ptr);
}

static int
Wobos_set_rnaM(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_rnaM_nset, self->data_ptr);
}

static PyObject *
Wobos_get_rotorD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_rotorD_nget, self->data_ptr);
}

static int
Wobos_set_rotorD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_rotorD_nset, self->data_ptr);
}

static PyObject *
Wobos_get_sSteelCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_sSteelCR_nget, self->data_ptr);
}

static int
Wobos_set_sSteelCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_sSteelCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_saPlan(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_saPlan_nget, self->data_ptr);
}

static int
Wobos_set_saPlan(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_saPlan_nset, self->data_ptr);
}

static PyObject *
Wobos_get_scourMat(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_scourMat_nget, self->data_ptr);
}

static int
Wobos_set_scourMat(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_scourMat_nset, self->data_ptr);
}

static PyObject *
Wobos_get_scrapVal(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_scrapVal_nget, self->data_ptr);
}

static int
Wobos_set_scrapVal(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_scrapVal_nset, self->data_ptr);
}

static PyObject *
Wobos_get_seaSpreadDR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_seaSpreadDR_nget, self->data_ptr);
}

static int
Wobos_set_seaSpreadDR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_seaSpreadDR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_seaSpreadMob(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_seaSpreadMob_nget, self->data_ptr);
}

static int
Wobos_set_seaSpreadMob(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_seaSpreadMob_nset, self->data_ptr);
}

static PyObject *
Wobos_get_shorePullIn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_shorePullIn_nget, self->data_ptr);
}

static int
Wobos_set_shorePullIn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_shorePullIn_nset, self->data_ptr);
}

static PyObject *
Wobos_get_shuntCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_shuntCR_nget, self->data_ptr);
}

static int
Wobos_set_shuntCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_shuntCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_socEconStudyMet(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_socEconStudyMet_nget, self->data_ptr);
}

static int
Wobos_set_socEconStudyMet(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_socEconStudyMet_nset, self->data_ptr);
}

static PyObject *
Wobos_get_socEconStudyProj(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_socEconStudyProj_nget, self->data_ptr);
}

static int
Wobos_set_socEconStudyProj(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_socEconStudyProj_nset, self->data_ptr);
}

static PyObject *
Wobos_get_spMoorCheck(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_spMoorCheck_nget, self->data_ptr);
}

static int
Wobos_set_spMoorCheck(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_spMoorCheck_nset, self->data_ptr);
}

static PyObject *
Wobos_get_spMoorCon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_spMoorCon_nget, self->data_ptr);
}

static int
Wobos_set_spMoorCon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_spMoorCon_nset, self->data_ptr);
}

static PyObject *
Wobos_get_spStifColCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_spStifColCR_nget, self->data_ptr);
}

static int
Wobos_set_spStifColCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_spStifColCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_spTapColCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_spTapColCR_nget, self->data_ptr);
}

static int
Wobos_set_spTapColCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_spTapColCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ssBall(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ssBall_nget, self->data_ptr);
}

static int
Wobos_set_ssBall(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ssBall_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ssHeaveCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ssHeaveCR_nget, self->data_ptr);
}

static int
Wobos_set_ssHeaveCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ssHeaveCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ssMoorCheck(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ssMoorCheck_nget, self->data_ptr);
}

static int
Wobos_set_ssMoorCheck(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ssMoorCheck_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ssMoorCon(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ssMoorCon_nget, self->data_ptr);
}

static int
Wobos_set_ssMoorCon(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ssMoorCon_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ssStifColCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ssStifColCR_nget, self->data_ptr);
}

static int
Wobos_set_ssStifColCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ssStifColCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_ssTrussCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_ssTrussCR_nget, self->data_ptr);
}

static int
Wobos_set_ssTrussCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_ssTrussCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_stateLease(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_stateLease_nget, self->data_ptr);
}

static int
Wobos_set_stateLease(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_stateLease_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subTotCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subTotCost_nget, self->data_ptr);
}

static int
Wobos_set_subTotCost(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subTotCost_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subTotM(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subTotM_nget, self->data_ptr);
}

static int
Wobos_set_subTotM(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subTotM_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsJackCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsJackCR_nget, self->data_ptr);
}

static int
Wobos_set_subsJackCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsJackCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsLoad(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsLoad_nget, self->data_ptr);
}

static int
Wobos_set_subsLoad(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsLoad_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsPileCR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsPileCR_nget, self->data_ptr);
}

static int
Wobos_set_subsPileCR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsPileCR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsPullIn(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsPullIn_nget, self->data_ptr);
}

static int
Wobos_set_subsPullIn(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsPullIn_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsTopDes(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsTopDes_nget, self->data_ptr);
}

static int
Wobos_set_subsTopDes(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsTopDes_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsTopFab(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsTopFab_nget, self->data_ptr);
}

static int
Wobos_set_subsTopFab(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsTopFab_nset, self->data_ptr);
}

static PyObject *
Wobos_get_subsVessPos(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_subsVessPos_nget, self->data_ptr);
}

static int
Wobos_set_subsVessPos(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_subsVessPos_nset, self->data_ptr);
}

static PyObject *
Wobos_get_substructCont(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_substructCont_nget, self->data_ptr);
}

static int
Wobos_set_substructCont(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_substructCont_nset, self->data_ptr);
}

static PyObject *
Wobos_get_substructure(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_substructure_nget, self->data_ptr);
}

static int
Wobos_set_substructure(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_substructure_nset, self->data_ptr);
}

static PyObject *
Wobos_get_surfLayRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_surfLayRate_nget, self->data_ptr);
}

static int
Wobos_set_surfLayRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_surfLayRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_tax_rate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_tax_rate_nget, self->data_ptr);
}

static int
Wobos_set_tax_rate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_tax_rate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_topAssemblyFac(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_topAssemblyFac_nget, self->data_ptr);
}

static int
Wobos_set_topAssemblyFac(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_topAssemblyFac_nset, self->data_ptr);
}

static PyObject *
Wobos_get_towerD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_towerD_nget, self->data_ptr);
}

static int
Wobos_set_towerD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_towerD_nset, self->data_ptr);
}

static PyObject *
Wobos_get_towerInstallMethod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_towerInstallMethod_nget, self->data_ptr);
}

static int
Wobos_set_towerInstallMethod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_towerInstallMethod_nset, self->data_ptr);
}

static PyObject *
Wobos_get_towerM(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_towerM_nget, self->data_ptr);
}

static int
Wobos_set_towerM(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_towerM_nset, self->data_ptr);
}

static PyObject *
Wobos_get_tpCover(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_tpCover_nget, self->data_ptr);
}

static int
Wobos_set_tpCover(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_tpCover_nset, self->data_ptr);
}

static PyObject *
Wobos_get_turbCapEx(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_turbCapEx_nget, self->data_ptr);
}

static int
Wobos_set_turbCapEx(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_turbCapEx_nset, self->data_ptr);
}

static PyObject *
Wobos_get_turbCont(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_turbCont_nget, self->data_ptr);
}

static int
Wobos_set_turbCont(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_turbCont_nset, self->data_ptr);
}

static PyObject *
Wobos_get_turbFasten(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_turbFasten_nget, self->data_ptr);
}

static int
Wobos_set_turbFasten(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_turbFasten_nset, self->data_ptr);
}

static PyObject *
Wobos_get_turbInstallMethod(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_turbInstallMethod_nget, self->data_ptr);
}

static int
Wobos_set_turbInstallMethod(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_turbInstallMethod_nset, self->data_ptr);
}

static PyObject *
Wobos_get_turbR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_turbR_nget, self->data_ptr);
}

static int
Wobos_set_turbR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_turbR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_upendSpar(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_upendSpar_nget, self->data_ptr);
}

static int
Wobos_set_upendSpar(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_upendSpar_nset, self->data_ptr);
}

static PyObject *
Wobos_get_vesselPosJack(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_vesselPosJack_nget, self->data_ptr);
}

static int
Wobos_set_vesselPosJack(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_vesselPosJack_nset, self->data_ptr);
}

static PyObject *
Wobos_get_vesselPosMono(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_vesselPosMono_nget, self->data_ptr);
}

static int
Wobos_set_vesselPosMono(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_vesselPosMono_nset, self->data_ptr);
}

static PyObject *
Wobos_get_vesselPosTurb(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_vesselPosTurb_nget, self->data_ptr);
}

static int
Wobos_set_vesselPosTurb(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_vesselPosTurb_nset, self->data_ptr);
}

static PyObject *
Wobos_get_waterD(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_waterD_nget, self->data_ptr);
}

static int
Wobos_set_waterD(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_waterD_nset, self->data_ptr);
}

static PyObject *
Wobos_get_wharfRate(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_wharfRate_nget, self->data_ptr);
}

static int
Wobos_set_wharfRate(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_wharfRate_nset, self->data_ptr);
}

static PyObject *
Wobos_get_winchDR(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_winchDR_nget, self->data_ptr);
}

static int
Wobos_set_winchDR(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_winchDR_nset, self->data_ptr);
}

static PyObject *
Wobos_get_workSpace(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Wobos_workSpace_nget, self->data_ptr);
}

static int
Wobos_set_workSpace(VarGroupObject *self, PyObject *value, void *closure)
{
	return PySAM_double_setter(value, SAM_WindObos_Wobos_workSpace_nset, self->data_ptr);
}

static PyGetSetDef Wobos_getset[] = {
{"addLocPerm", (getter)Wobos_get_addLocPerm,(setter)Wobos_set_addLocPerm,
	PyDoc_STR("*float*: Additional State and Local Permitting Cost [$]\n\n*Required*: If not provided, assumed to be 200000"),
 	NULL},
{"anchor", (getter)Wobos_get_anchor,(setter)Wobos_set_anchor,
	PyDoc_STR("*float*: Anchor Type\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be DRAGEMBEDMENT"),
 	NULL},
{"arrCab1Mass", (getter)Wobos_get_arrCab1Mass,(setter)Wobos_set_arrCab1Mass,
	PyDoc_STR("*float*: Array cable 1 mass [kg/m]\n\n*Required*: If not provided, assumed to be 20.384"),
 	NULL},
{"arrCab2Mass", (getter)Wobos_get_arrCab2Mass,(setter)Wobos_set_arrCab2Mass,
	PyDoc_STR("*float*: Array cable 2 mass [kg/m]\n\n*Required*: If not provided, assumed to be 21.854"),
 	NULL},
{"arrVoltage", (getter)Wobos_get_arrVoltage,(setter)Wobos_set_arrVoltage,
	PyDoc_STR("*float*: Array cable voltage [kV]\n\n*Required*: If not provided, assumed to be 33"),
 	NULL},
{"arrayCables", (getter)Wobos_get_arrayCables,(setter)Wobos_set_arrayCables,
	PyDoc_STR("*str*: Inter-array cables to consider by voltage [kV]\n\n*Required*: If not provided, assumed to be 33 66"),
 	NULL},
{"arrayX", (getter)Wobos_get_arrayX,(setter)Wobos_set_arrayX,
	PyDoc_STR("*float*: Spacing Between Turbine Rows [rotor diameters]\n\n*Constraints*: MIN=1\n\n*Required*: If not provided, assumed to be 9"),
 	NULL},
{"arrayY", (getter)Wobos_get_arrayY,(setter)Wobos_set_arrayY,
	PyDoc_STR("*float*: Spacing Between Turbines in Rows [rotor diameters]\n\n*Constraints*: MIN=1\n\n*Required*: If not provided, assumed to be 9"),
 	NULL},
{"backUpGen", (getter)Wobos_get_backUpGen,(setter)Wobos_set_backUpGen,
	PyDoc_STR("*float*: Back up Diesel Generator Cost [$]\n\n*Required*: If not provided, assumed to be 1000000"),
 	NULL},
{"ballCR", (getter)Wobos_get_ballCR,(setter)Wobos_set_ballCR,
	PyDoc_STR("*float*: Floating Ballast Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 100"),
 	NULL},
{"bioResStudyMet", (getter)Wobos_get_bioResStudyMet,(setter)Wobos_set_bioResStudyMet,
	PyDoc_STR("*float*: Biological Resource Study Met Tower Cost [$]\n\n*Required*: If not provided, assumed to be 1500000"),
 	NULL},
{"bioResStudyProj", (getter)Wobos_get_bioResStudyProj,(setter)Wobos_set_bioResStudyProj,
	PyDoc_STR("*float*: Biological Resource Study Porject Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"bladeL", (getter)Wobos_get_bladeL,(setter)Wobos_set_bladeL,
	PyDoc_STR("*float*: Blade Length [m]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"boltBlade1", (getter)Wobos_get_boltBlade1,(setter)Wobos_set_boltBlade1,
	PyDoc_STR("*float*: Lift and Bolt Blade Individual Components Method [hours]\n\n*Required*: If not provided, assumed to be 3.5"),
 	NULL},
{"boltBlade2", (getter)Wobos_get_boltBlade2,(setter)Wobos_set_boltBlade2,
	PyDoc_STR("*float*: Lift and Bolt Blade Bunny Ears Method [hours]\n\n*Required*: If not provided, assumed to be 3.5"),
 	NULL},
{"boltNacelle1", (getter)Wobos_get_boltNacelle1,(setter)Wobos_set_boltNacelle1,
	PyDoc_STR("*float*: Lift and Bolt Nacelle Individual Components Method [hours]\n\n*Required*: If not provided, assumed to be 7"),
 	NULL},
{"boltNacelle2", (getter)Wobos_get_boltNacelle2,(setter)Wobos_set_boltNacelle2,
	PyDoc_STR("*float*: Lift and Bolt Nacelle Bunny Ears Method [hours]\n\n*Required*: If not provided, assumed to be 7"),
 	NULL},
{"boltNacelle3", (getter)Wobos_get_boltNacelle3,(setter)Wobos_set_boltNacelle3,
	PyDoc_STR("*float*: Lift and Bolt Nacelle Fully Assembled Rotor Method [hours]\n\n*Required*: If not provided, assumed to be 7"),
 	NULL},
{"boltRotor", (getter)Wobos_get_boltRotor,(setter)Wobos_set_boltRotor,
	PyDoc_STR("*float*: Lift and Bolt Rotor Fully Assembled Rotor Method [hours]\n\n*Required*: If not provided, assumed to be 7"),
 	NULL},
{"boltTower", (getter)Wobos_get_boltTower,(setter)Wobos_set_boltTower,
	PyDoc_STR("*float*: Lift and Bolt Tower Section [hours]\n\n*Required*: If not provided, assumed to be 7"),
 	NULL},
{"buryDepth", (getter)Wobos_get_buryDepth,(setter)Wobos_set_buryDepth,
	PyDoc_STR("*float*: Electrical Cable Burial Depth [m]\n\n*Constraints*: MIN=0,MAX=15\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"buryFac", (getter)Wobos_get_buryFac,(setter)Wobos_set_buryFac,
	PyDoc_STR("*float*: Cable Burial Depth Factor [1/m]\n\n*Required*: If not provided, assumed to be 0.1"),
 	NULL},
{"buryRate", (getter)Wobos_get_buryRate,(setter)Wobos_set_buryRate,
	PyDoc_STR("*float*: Cable Burial Rate [m/hour]\n\n*Required*: If not provided, assumed to be 125"),
 	NULL},
{"cab1CR", (getter)Wobos_get_cab1CR,(setter)Wobos_set_cab1CR,
	PyDoc_STR("*float*: Array cable 1 Cost Rate [$/m]\n\n*Required*: If not provided, assumed to be 185.889"),
 	NULL},
{"cab1CurrRating", (getter)Wobos_get_cab1CurrRating,(setter)Wobos_set_cab1CurrRating,
	PyDoc_STR("*float*: Array cable 1 current rating [A]\n\n*Required*: If not provided, assumed to be 300"),
 	NULL},
{"cab1TurbInterCR", (getter)Wobos_get_cab1TurbInterCR,(setter)Wobos_set_cab1TurbInterCR,
	PyDoc_STR("*float*: Cable 1 turbine interface cost [$/interface]\n\n*Required*: If not provided, assumed to be 8410"),
 	NULL},
{"cab2CR", (getter)Wobos_get_cab2CR,(setter)Wobos_set_cab2CR,
	PyDoc_STR("*float*: Array cable 2 Cost Rate [$/m]\n\n*Required*: If not provided, assumed to be 202.788"),
 	NULL},
{"cab2CurrRating", (getter)Wobos_get_cab2CurrRating,(setter)Wobos_set_cab2CurrRating,
	PyDoc_STR("*float*: Array cable 2 current rating [A]\n\n*Required*: If not provided, assumed to be 340"),
 	NULL},
{"cab2SubsInterCR", (getter)Wobos_get_cab2SubsInterCR,(setter)Wobos_set_cab2SubsInterCR,
	PyDoc_STR("*float*: Cable 2 substation interface cost [$/interface]\n\n*Required*: If not provided, assumed to be 19815"),
 	NULL},
{"cab2TurbInterCR", (getter)Wobos_get_cab2TurbInterCR,(setter)Wobos_set_cab2TurbInterCR,
	PyDoc_STR("*float*: Cable 2 turbine interface cost [$/interface]\n\n*Required*: If not provided, assumed to be 8615"),
 	NULL},
{"cabDrillCR", (getter)Wobos_get_cabDrillCR,(setter)Wobos_set_cabDrillCR,
	PyDoc_STR("*float*: Cost Rate for Horizontal Drilling [$/m]\n\n*Required*: If not provided, assumed to be 3200"),
 	NULL},
{"cabDrillDist", (getter)Wobos_get_cabDrillDist,(setter)Wobos_set_cabDrillDist,
	PyDoc_STR("*float*: Horizontal Drilling distance for Cable Landfall [m]\n\n*Required*: If not provided, assumed to be 500"),
 	NULL},
{"cabLoadout", (getter)Wobos_get_cabLoadout,(setter)Wobos_set_cabLoadout,
	PyDoc_STR("*float*: Array Cable Loadout for Installation [hours]\n\n*Required*: If not provided, assumed to be 14"),
 	NULL},
{"cabPullIn", (getter)Wobos_get_cabPullIn,(setter)Wobos_set_cabPullIn,
	PyDoc_STR("*float*: Array Cable Pull in to Interfaces [hours]\n\n*Required*: If not provided, assumed to be 5.5"),
 	NULL},
{"cabSurveyCR", (getter)Wobos_get_cabSurveyCR,(setter)Wobos_set_cabSurveyCR,
	PyDoc_STR("*float*: Cable Route Survey Cost [$/m]\n\n*Required*: If not provided, assumed to be 240"),
 	NULL},
{"cabTerm", (getter)Wobos_get_cabTerm,(setter)Wobos_set_cabTerm,
	PyDoc_STR("*float*: Cable Termination and Testing [hours]\n\n*Required*: If not provided, assumed to be 5.5"),
 	NULL},
{"cableOptimizer", (getter)Wobos_get_cableOptimizer,(setter)Wobos_set_cableOptimizer,
	PyDoc_STR("*float*: Electrical Cable Cost Optimization\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be FALSE"),
 	NULL},
{"capital_cost_year_0", (getter)Wobos_get_capital_cost_year_0,(setter)Wobos_set_capital_cost_year_0,
	PyDoc_STR("*float*: Capital cost spent in year 0\n\n*Required*: If not provided, assumed to be 0.2"),
 	NULL},
{"capital_cost_year_1", (getter)Wobos_get_capital_cost_year_1,(setter)Wobos_set_capital_cost_year_1,
	PyDoc_STR("*float*: Capital cost spent in year 1\n\n*Required*: If not provided, assumed to be 0.6"),
 	NULL},
{"capital_cost_year_2", (getter)Wobos_get_capital_cost_year_2,(setter)Wobos_set_capital_cost_year_2,
	PyDoc_STR("*float*: Capital cost spent in year 2\n\n*Required*: If not provided, assumed to be 0.1"),
 	NULL},
{"capital_cost_year_3", (getter)Wobos_get_capital_cost_year_3,(setter)Wobos_set_capital_cost_year_3,
	PyDoc_STR("*float*: Capital cost spent in year 3\n\n*Required*: If not provided, assumed to be 0.1"),
 	NULL},
{"capital_cost_year_4", (getter)Wobos_get_capital_cost_year_4,(setter)Wobos_set_capital_cost_year_4,
	PyDoc_STR("*float*: Capital cost spent in year 4\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"capital_cost_year_5", (getter)Wobos_get_capital_cost_year_5,(setter)Wobos_set_capital_cost_year_5,
	PyDoc_STR("*float*: Capital cost spent in year 5\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"catLengFac", (getter)Wobos_get_catLengFac,(setter)Wobos_set_catLengFac,
	PyDoc_STR("*float*: Catenary Cable Length Factor\n\n*Required*: If not provided, assumed to be 0.04"),
 	NULL},
{"chord", (getter)Wobos_get_chord,(setter)Wobos_set_chord,
	PyDoc_STR("*float*: Blade Max Chord [m]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"civilWork", (getter)Wobos_get_civilWork,(setter)Wobos_set_civilWork,
	PyDoc_STR("*float*: Onshore Infrastructure Civil Work Cost [$]\n\n*Required*: If not provided, assumed to be 40000"),
 	NULL},
{"cleanWatAct402", (getter)Wobos_get_cleanWatAct402,(setter)Wobos_set_cleanWatAct402,
	PyDoc_STR("*float*: Clean Water Act Section 402 Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 100000"),
 	NULL},
{"cleanWatAct404", (getter)Wobos_get_cleanWatAct404,(setter)Wobos_set_cleanWatAct404,
	PyDoc_STR("*float*: Clean Water Act Section 404 Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 100000"),
 	NULL},
{"coastZoneManAct", (getter)Wobos_get_coastZoneManAct,(setter)Wobos_set_coastZoneManAct,
	PyDoc_STR("*float*: Coastal Zone Management Act Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 100000"),
 	NULL},
{"compRacks", (getter)Wobos_get_compRacks,(setter)Wobos_set_compRacks,
	PyDoc_STR("*float*: Component Racks Cost [$]\n\n*Required*: If not provided, assumed to be 1000000"),
 	NULL},
{"conOpPlan", (getter)Wobos_get_conOpPlan,(setter)Wobos_set_conOpPlan,
	PyDoc_STR("*float*: Construction Operations Plan Cost [$]\n\n*Required*: If not provided, assumed to be 1000000"),
 	NULL},
{"construction_insurance", (getter)Wobos_get_construction_insurance,(setter)Wobos_set_construction_insurance,
	PyDoc_STR("*float*: Insurance During Construction (% of ICC)\n\n*Required*: If not provided, assumed to be 0.01"),
 	NULL},
{"crane1000DR", (getter)Wobos_get_crane1000DR,(setter)Wobos_set_crane1000DR,
	PyDoc_STR("*float*: 1000 t Crawler Crane Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 8000"),
 	NULL},
{"crane600DR", (getter)Wobos_get_crane600DR,(setter)Wobos_set_crane600DR,
	PyDoc_STR("*float*: 600 t Crawler Crane Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 5000"),
 	NULL},
{"craneMobDemob", (getter)Wobos_get_craneMobDemob,(setter)Wobos_set_craneMobDemob,
	PyDoc_STR("*float*: Port Crane Mobilization/Demobilization Cost [$]\n\n*Required*: If not provided, assumed to be 150000"),
 	NULL},
{"deaFixLeng", (getter)Wobos_get_deaFixLeng,(setter)Wobos_set_deaFixLeng,
	PyDoc_STR("*float*: Fixed Mooring Length for Drag Embedment Anchors [m]\n\n*Required*: If not provided, assumed to be 500"),
 	NULL},
{"decomDiscRate", (getter)Wobos_get_decomDiscRate,(setter)Wobos_set_decomDiscRate,
	PyDoc_STR("*float*: Decommissioning Cost Discount Rate\n\n*Required*: If not provided, assumed to be 0.03"),
 	NULL},
{"distAtoS", (getter)Wobos_get_distAtoS,(setter)Wobos_set_distAtoS,
	PyDoc_STR("*float*: Distance form Inshore Assembly Area to Site [km]\n\n*Constraints*: MIN=5,MAX=1000\n\n*Required*: If not provided, assumed to be 90"),
 	NULL},
{"distInterCon", (getter)Wobos_get_distInterCon,(setter)Wobos_set_distInterCon,
	PyDoc_STR("*float*: Distance Over Land to Grid Interconnect [miles]\n\n*Required*: If not provided, assumed to be 3"),
 	NULL},
{"distPort", (getter)Wobos_get_distPort,(setter)Wobos_set_distPort,
	PyDoc_STR("*float*: Distance from Installation Port to Site [km]\n\n*Constraints*: MIN=5,MAX=1000\n\n*Required*: If not provided, assumed to be 90"),
 	NULL},
{"distPtoA", (getter)Wobos_get_distPtoA,(setter)Wobos_set_distPtoA,
	PyDoc_STR("*float*: Distance from Installation Port to Inshore Assembly Area [km]\n\n*Constraints*: MIN=5,MAX=1000\n\n*Required*: If not provided, assumed to be 90"),
 	NULL},
{"distShore", (getter)Wobos_get_distShore,(setter)Wobos_set_distShore,
	PyDoc_STR("*float*: Distance to Landfall [km]\n\n*Constraints*: MIN=5,MAX=1000\n\n*Required*: If not provided, assumed to be 90"),
 	NULL},
{"diveTeamDR", (getter)Wobos_get_diveTeamDR,(setter)Wobos_set_diveTeamDR,
	PyDoc_STR("*float*: Cable Landfall Dive Team Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 3200"),
 	NULL},
{"dockRate", (getter)Wobos_get_dockRate,(setter)Wobos_set_dockRate,
	PyDoc_STR("*float*: Quayside Docking Cost Rate [$/day]\n\n*Required*: If not provided, assumed to be 3000"),
 	NULL},
{"dynCabFac", (getter)Wobos_get_dynCabFac,(setter)Wobos_set_dynCabFac,
	PyDoc_STR("*float*: Dynamic Cable Cost Premium Factor\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"elecCont", (getter)Wobos_get_elecCont,(setter)Wobos_set_elecCont,
	PyDoc_STR("*float*: Electrical Install Weather Contingency [%]\n\n*Required*: If not provided, assumed to be 0.3"),
 	NULL},
{"elecWork", (getter)Wobos_get_elecWork,(setter)Wobos_set_elecWork,
	PyDoc_STR("*float*: Onshore Infrastructure Electrical Work Cost [$]\n\n*Required*: If not provided, assumed to be 25000"),
 	NULL},
{"endSpecAct", (getter)Wobos_get_endSpecAct,(setter)Wobos_set_endSpecAct,
	PyDoc_STR("*float*: Endangered Species Act Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"entranceExitRate", (getter)Wobos_get_entranceExitRate,(setter)Wobos_set_entranceExitRate,
	PyDoc_STR("*float*: Port Entrance and Exit Cost Rate [$/occurrence]\n\n*Required*: If not provided, assumed to be 0.525"),
 	NULL},
{"estEnMFac", (getter)Wobos_get_estEnMFac,(setter)Wobos_set_estEnMFac,
	PyDoc_STR("*float*: Estimated Engineering & Management Cost Factor\n\n*Required*: If not provided, assumed to be 0.04"),
 	NULL},
{"exCabFac", (getter)Wobos_get_exCabFac,(setter)Wobos_set_exCabFac,
	PyDoc_STR("*float*: Excess Cable Factor\n\n*Required*: If not provided, assumed to be 0.1"),
 	NULL},
{"expCabCR", (getter)Wobos_get_expCabCR,(setter)Wobos_set_expCabCR,
	PyDoc_STR("*float*: Export cable cost rate [$/m]\n\n*Required*: If not provided, assumed to be 495.411"),
 	NULL},
{"expCabLoad", (getter)Wobos_get_expCabLoad,(setter)Wobos_set_expCabLoad,
	PyDoc_STR("*float*: Export Cable Loadout for Installation [hours]\n\n*Required*: If not provided, assumed to be 24"),
 	NULL},
{"expCabMass", (getter)Wobos_get_expCabMass,(setter)Wobos_set_expCabMass,
	PyDoc_STR("*float*: Export cable mass [kg/m]\n\n*Required*: If not provided, assumed to be 71.9"),
 	NULL},
{"expCurrRating", (getter)Wobos_get_expCurrRating,(setter)Wobos_set_expCurrRating,
	PyDoc_STR("*float*: Export cable current rating [A]\n\n*Required*: If not provided, assumed to be 530"),
 	NULL},
{"expSubsInterCR", (getter)Wobos_get_expSubsInterCR,(setter)Wobos_set_expSubsInterCR,
	PyDoc_STR("*float*: Export cable substation interface cost [$/interface]\n\n*Required*: If not provided, assumed to be 57500"),
 	NULL},
{"expVoltage", (getter)Wobos_get_expVoltage,(setter)Wobos_set_expVoltage,
	PyDoc_STR("*float*: Export cable voltage [kV]\n\n*Required*: If not provided, assumed to be 220"),
 	NULL},
{"exportCables", (getter)Wobos_get_exportCables,(setter)Wobos_set_exportCables,
	PyDoc_STR("*str*: Export cables to consider by voltage [kV]\n\n*Required*: If not provided, assumed to be 132 220"),
 	NULL},
{"faaPlan", (getter)Wobos_get_faaPlan,(setter)Wobos_set_faaPlan,
	PyDoc_STR("*float*: Federal Aviation Administration Plans & Mitigation Cost [$]\n\n*Required*: If not provided, assumed to be 10000"),
 	NULL},
{"feedStudy", (getter)Wobos_get_feedStudy,(setter)Wobos_set_feedStudy,
	PyDoc_STR("*float*: FEED Study Cost [$]\n\n*Required*: If not provided, assumed to be 10000000"),
 	NULL},
{"groutSpreadDR", (getter)Wobos_get_groutSpreadDR,(setter)Wobos_set_groutSpreadDR,
	PyDoc_STR("*float*: Grouting Spread Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 3000"),
 	NULL},
{"groutSpreadMob", (getter)Wobos_get_groutSpreadMob,(setter)Wobos_set_groutSpreadMob,
	PyDoc_STR("*float*: Grouting Spread Mobilization Cost [$]\n\n*Required*: If not provided, assumed to be 1000000"),
 	NULL},
{"groutTP", (getter)Wobos_get_groutTP,(setter)Wobos_set_groutTP,
	PyDoc_STR("*float*: Grout Transition Piece/Monopile Interface [hours]\n\n*Required*: If not provided, assumed to be 8"),
 	NULL},
{"hamRate", (getter)Wobos_get_hamRate,(setter)Wobos_set_hamRate,
	PyDoc_STR("*float*: Pile Hammer Rate [m/hour]\n\n*Required*: If not provided, assumed to be 20"),
 	NULL},
{"highVoltSG", (getter)Wobos_get_highVoltSG,(setter)Wobos_set_highVoltSG,
	PyDoc_STR("*float*: High Voltage Switchgear Cost [$]\n\n*Required*: If not provided, assumed to be 950000"),
 	NULL},
{"hubD", (getter)Wobos_get_hubD,(setter)Wobos_set_hubD,
	PyDoc_STR("*float*: Hub Diameter [m]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"hubH", (getter)Wobos_get_hubH,(setter)Wobos_set_hubH,
	PyDoc_STR("*float*: Hub Height [m]\n\n*Required*: If not provided, assumed to be 90"),
 	NULL},
{"inspectClear", (getter)Wobos_get_inspectClear,(setter)Wobos_set_inspectClear,
	PyDoc_STR("*float*: Inspection Clearance [m]\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"instScour", (getter)Wobos_get_instScour,(setter)Wobos_set_instScour,
	PyDoc_STR("*float*: Install Scour Protection Around Monopile Base [hours]\n\n*Required*: If not provided, assumed to be 6"),
 	NULL},
{"installStrategy", (getter)Wobos_get_installStrategy,(setter)Wobos_set_installStrategy,
	PyDoc_STR("*float*: Installation Vessel Strategy\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be PRIMARYVESSEL"),
 	NULL},
{"install_contingency", (getter)Wobos_get_install_contingency,(setter)Wobos_set_install_contingency,
	PyDoc_STR("*float*: Installation Contingency\n\n*Required*: If not provided, assumed to be 0.3"),
 	NULL},
{"interConVolt", (getter)Wobos_get_interConVolt,(setter)Wobos_set_interConVolt,
	PyDoc_STR("*float*: Grid Interconnect Voltage [kV]\n\n*Required*: If not provided, assumed to be 345"),
 	NULL},
{"interest_during_construction", (getter)Wobos_get_interest_during_construction,(setter)Wobos_set_interest_during_construction,
	PyDoc_STR("*float*: Interest During Construction\n\n*Required*: If not provided, assumed to be 0.08"),
 	NULL},
{"jackFasten", (getter)Wobos_get_jackFasten,(setter)Wobos_set_jackFasten,
	PyDoc_STR("*float*: Prepare and Fasten Jacket for Transport [hours/unit]\n\n*Required*: If not provided, assumed to be 20"),
 	NULL},
{"jlatticeA", (getter)Wobos_get_jlatticeA,(setter)Wobos_set_jlatticeA,
	PyDoc_STR("*float*: Jacket Main Lattice Footprint Area [m^2]\n\n*Required*: If not provided, assumed to be 26"),
 	NULL},
{"jlatticeCR", (getter)Wobos_get_jlatticeCR,(setter)Wobos_set_jlatticeCR,
	PyDoc_STR("*float*: Jacket Main Lattice Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 4680"),
 	NULL},
{"jpileCR", (getter)Wobos_get_jpileCR,(setter)Wobos_set_jpileCR,
	PyDoc_STR("*float*: Jacket Pile Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 2250"),
 	NULL},
{"jpileD", (getter)Wobos_get_jpileD,(setter)Wobos_set_jpileD,
	PyDoc_STR("*float*: Jacket Pile Diameter [m]\n\n*Required*: If not provided, assumed to be 1.6"),
 	NULL},
{"jpileL", (getter)Wobos_get_jpileL,(setter)Wobos_set_jpileL,
	PyDoc_STR("*float*: Jacket Pile Length [m]\n\n*Required*: If not provided, assumed to be 47.5"),
 	NULL},
{"jtransCR", (getter)Wobos_get_jtransCR,(setter)Wobos_set_jtransCR,
	PyDoc_STR("*float*: Jacket Transition Piece Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 4500"),
 	NULL},
{"landConstruct", (getter)Wobos_get_landConstruct,(setter)Wobos_set_landConstruct,
	PyDoc_STR("*float*: Onshore Infrastructure Construction [days]\n\n*Required*: If not provided, assumed to be 7"),
 	NULL},
{"laydownCR", (getter)Wobos_get_laydownCR,(setter)Wobos_set_laydownCR,
	PyDoc_STR("*float*: Laydown and Storage Cost Rate [$/m^2/day]\n\n*Required*: If not provided, assumed to be 0.25"),
 	NULL},
{"levJack", (getter)Wobos_get_levJack,(setter)Wobos_set_levJack,
	PyDoc_STR("*float*: Level Jacket Main Lattice [hours]\n\n*Required*: If not provided, assumed to be 24"),
 	NULL},
{"marMamProtAct", (getter)Wobos_get_marMamProtAct,(setter)Wobos_set_marMamProtAct,
	PyDoc_STR("*float*: Marine Mammal Protection Act Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"medVoltSG", (getter)Wobos_get_medVoltSG,(setter)Wobos_set_medVoltSG,
	PyDoc_STR("*float*: Medium Voltage Switchgear Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"metTowCR", (getter)Wobos_get_metTowCR,(setter)Wobos_set_metTowCR,
	PyDoc_STR("*float*: Meteorological (Met Tower Fabrication & Install Cost [$/MW]\n\n*Required*: If not provided, assumed to be 11518"),
 	NULL},
{"migBirdAct", (getter)Wobos_get_migBirdAct,(setter)Wobos_set_migBirdAct,
	PyDoc_STR("*float*: Migratory Bird Treaty Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"monoFasten", (getter)Wobos_get_monoFasten,(setter)Wobos_set_monoFasten,
	PyDoc_STR("*float*: Prepare and Fasten Monopile for Transport [hours/unit]\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"moorCR", (getter)Wobos_get_moorCR,(setter)Wobos_set_moorCR,
	PyDoc_STR("*float*: Mooring Line Cost Rate [$/m]\n\n*Constraints*: MIN=399\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"moorCost", (getter)Wobos_get_moorCost,(setter)Wobos_set_moorCost,
	PyDoc_STR("*float*: Capital cost of mooring lines and anchors [$]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"moorDia", (getter)Wobos_get_moorDia,(setter)Wobos_set_moorDia,
	PyDoc_STR("*float*: Mooring Line Diameter [m]\n\n*Constraints*: MIN=0.09\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"moorLines", (getter)Wobos_get_moorLines,(setter)Wobos_set_moorLines,
	PyDoc_STR("*float*: Number Of Mooring Lines\n\n*Required*: If not provided, assumed to be 3"),
 	NULL},
{"moorLoadout", (getter)Wobos_get_moorLoadout,(setter)Wobos_set_moorLoadout,
	PyDoc_STR("*float*: Anchor & Mooring Loadout Time [hours]\n\n*Required*: If not provided, assumed to be 5"),
 	NULL},
{"moorSurvey", (getter)Wobos_get_moorSurvey,(setter)Wobos_set_moorSurvey,
	PyDoc_STR("*float*: Survey Mooring Lines & Anchor Positions Time [hours]\n\n*Required*: If not provided, assumed to be 4"),
 	NULL},
{"moorTimeFac", (getter)Wobos_get_moorTimeFac,(setter)Wobos_set_moorTimeFac,
	PyDoc_STR("*float*: Anchor & Mooring Water Depth Time Factor\n\n*Required*: If not provided, assumed to be 0.005"),
 	NULL},
{"mpEmbedL", (getter)Wobos_get_mpEmbedL,(setter)Wobos_set_mpEmbedL,
	PyDoc_STR("*float*: Monopile Embedment Length [m]\n\n*Required*: If not provided, assumed to be 30"),
 	NULL},
{"mpileCR", (getter)Wobos_get_mpileCR,(setter)Wobos_set_mpileCR,
	PyDoc_STR("*float*: Monopile Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 2250"),
 	NULL},
{"mpileD", (getter)Wobos_get_mpileD,(setter)Wobos_set_mpileD,
	PyDoc_STR("*float*: Monopile Diameter [m]\n\n*Constraints*: MIN=0.01\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"mpileL", (getter)Wobos_get_mpileL,(setter)Wobos_set_mpileL,
	PyDoc_STR("*float*: Monopile Length [m]\n\n*Constraints*: MIN=0.01\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"mptCR", (getter)Wobos_get_mptCR,(setter)Wobos_set_mptCR,
	PyDoc_STR("*float*: Main Power Transformer Cost Rate [$/MVA]\n\n*Required*: If not provided, assumed to be 12500"),
 	NULL},
{"mpvRentalDR", (getter)Wobos_get_mpvRentalDR,(setter)Wobos_set_mpvRentalDR,
	PyDoc_STR("*float*: MPV Rental Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 72000"),
 	NULL},
{"mtransCR", (getter)Wobos_get_mtransCR,(setter)Wobos_set_mtransCR,
	PyDoc_STR("*float*: Monopile Transition Piece Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 3230"),
 	NULL},
{"nCrane1000", (getter)Wobos_get_nCrane1000,(setter)Wobos_set_nCrane1000,
	PyDoc_STR("*float*: Number of 1000 t Crawler Cranes\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"nCrane600", (getter)Wobos_get_nCrane600,(setter)Wobos_set_nCrane600,
	PyDoc_STR("*float*: Number of 600 t Crawler Cranes\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"nTurb", (getter)Wobos_get_nTurb,(setter)Wobos_set_nTurb,
	PyDoc_STR("*float*: Number of Turbines\n\n*Constraints*: MIN=2,MAX=200\n\n*Required*: If not provided, assumed to be 20"),
 	NULL},
{"nacelleL", (getter)Wobos_get_nacelleL,(setter)Wobos_set_nacelleL,
	PyDoc_STR("*float*: Nacelle Length [m]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"nacelleW", (getter)Wobos_get_nacelleW,(setter)Wobos_set_nacelleW,
	PyDoc_STR("*float*: Nacelle Width [m]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"natHisPresAct", (getter)Wobos_get_natHisPresAct,(setter)Wobos_set_natHisPresAct,
	PyDoc_STR("*float*: National Historic Preservation Act Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 250000"),
 	NULL},
{"navStudyMet", (getter)Wobos_get_navStudyMet,(setter)Wobos_set_navStudyMet,
	PyDoc_STR("*float*: Navigation and Transport Study Met Tower Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"navStudyProj", (getter)Wobos_get_navStudyProj,(setter)Wobos_set_navStudyProj,
	PyDoc_STR("*float*: Navigation and Transport Study Project Cost [$]\n\n*Required*: If not provided, assumed to be 250000"),
 	NULL},
{"nepaEisMet", (getter)Wobos_get_nepaEisMet,(setter)Wobos_set_nepaEisMet,
	PyDoc_STR("*float*: NEPA Environmental Impact Statement Met Tower Cost [$]\n\n*Required*: If not provided, assumed to be 2000000"),
 	NULL},
{"nepaEisProj", (getter)Wobos_get_nepaEisProj,(setter)Wobos_set_nepaEisProj,
	PyDoc_STR("*float*: NEPA Environmental Impact Study Project Cost [$]\n\n*Required*: If not provided, assumed to be 5000000"),
 	NULL},
{"number_install_seasons", (getter)Wobos_get_number_install_seasons,(setter)Wobos_set_number_install_seasons,
	PyDoc_STR("*float*: Number of Installation Seasons\n\n*Required*: If not provided, assumed to be 1"),
 	NULL},
{"otherAncillary", (getter)Wobos_get_otherAncillary,(setter)Wobos_set_otherAncillary,
	PyDoc_STR("*float*: Other Ancillary Systems Costs [$]\n\n*Required*: If not provided, assumed to be 3000000"),
 	NULL},
{"outConShelfLease", (getter)Wobos_get_outConShelfLease,(setter)Wobos_set_outConShelfLease,
	PyDoc_STR("*float*: Outer Continental Shelf Lease Cost [$]\n\n*Required*: If not provided, assumed to be 1000000"),
 	NULL},
{"physResStudyMet", (getter)Wobos_get_physResStudyMet,(setter)Wobos_set_physResStudyMet,
	PyDoc_STR("*float*: Physical Resource Study Met Tower Cost [$]\n\n*Required*: If not provided, assumed to be 1500000"),
 	NULL},
{"physResStudyProj", (getter)Wobos_get_physResStudyProj,(setter)Wobos_set_physResStudyProj,
	PyDoc_STR("*float*: Physical Resource Study Project Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"pileSpreadDR", (getter)Wobos_get_pileSpreadDR,(setter)Wobos_set_pileSpreadDR,
	PyDoc_STR("*float*: Piling Spread Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 2500"),
 	NULL},
{"pileSpreadMob", (getter)Wobos_get_pileSpreadMob,(setter)Wobos_set_pileSpreadMob,
	PyDoc_STR("*float*: Piling Spread Mobilization Cost [$]\n\n*Required*: If not provided, assumed to be 750000"),
 	NULL},
{"placeJack", (getter)Wobos_get_placeJack,(setter)Wobos_set_placeJack,
	PyDoc_STR("*float*: Place Jacket Main Lattice onto Piles [hours]\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"placeMP", (getter)Wobos_get_placeMP,(setter)Wobos_set_placeMP,
	PyDoc_STR("*float*: Lift and Place Monopile for Hammering [hours]\n\n*Required*: If not provided, assumed to be 3"),
 	NULL},
{"placePiles", (getter)Wobos_get_placePiles,(setter)Wobos_set_placePiles,
	PyDoc_STR("*float*: Place Jacket Piles [hours]\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"placeTP", (getter)Wobos_get_placeTP,(setter)Wobos_set_placeTP,
	PyDoc_STR("*float*: Place Transition Piece onto Monopile [hours]\n\n*Required*: If not provided, assumed to be 3"),
 	NULL},
{"placeTemplate", (getter)Wobos_get_placeTemplate,(setter)Wobos_set_placeTemplate,
	PyDoc_STR("*float*: Place Jacket Pile Template on Seabed [hours]\n\n*Required*: If not provided, assumed to be 4"),
 	NULL},
{"placeTop", (getter)Wobos_get_placeTop,(setter)Wobos_set_placeTop,
	PyDoc_STR("*float*: Lift and Place Offshore Substation Topside [hours]\n\n*Required*: If not provided, assumed to be 24"),
 	NULL},
{"plantComm", (getter)Wobos_get_plantComm,(setter)Wobos_set_plantComm,
	PyDoc_STR("*float*: Plant Commissioning Cost Factor\n\n*Required*: If not provided, assumed to be 0.01"),
 	NULL},
{"preFEEDStudy", (getter)Wobos_get_preFEEDStudy,(setter)Wobos_set_preFEEDStudy,
	PyDoc_STR("*float*: Pre-FEED study Cost [$]\n\n*Required*: If not provided, assumed to be 5000000"),
 	NULL},
{"prepAA", (getter)Wobos_get_prepAA,(setter)Wobos_set_prepAA,
	PyDoc_STR("*float*: Prepare Inshore Assembly Area For Turbine Installation [hours]\n\n*Required*: If not provided, assumed to be 168"),
 	NULL},
{"prepGripperJack", (getter)Wobos_get_prepGripperJack,(setter)Wobos_set_prepGripperJack,
	PyDoc_STR("*float*: Prepare Jacket Gripper and Upender [hours]\n\n*Required*: If not provided, assumed to be 8"),
 	NULL},
{"prepGripperMono", (getter)Wobos_get_prepGripperMono,(setter)Wobos_set_prepGripperMono,
	PyDoc_STR("*float*: Prepare Monopile Gripper and Upender [hours]\n\n*Required*: If not provided, assumed to be 1.5"),
 	NULL},
{"prepHamJack", (getter)Wobos_get_prepHamJack,(setter)Wobos_set_prepHamJack,
	PyDoc_STR("*float*: Prepare Hammer for jacket Piles Installation [hours]\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"prepHamMono", (getter)Wobos_get_prepHamMono,(setter)Wobos_set_prepHamMono,
	PyDoc_STR("*float*: Prepare Hammer for Monopile Installation [hours]\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"prepSemi", (getter)Wobos_get_prepSemi,(setter)Wobos_set_prepSemi,
	PyDoc_STR("*float*: Prepare Semi-submersible for Turbine Installation [hours]\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"prepSpar", (getter)Wobos_get_prepSpar,(setter)Wobos_set_prepSpar,
	PyDoc_STR("*float*: Prepare Spar for Tow to Inshore Assembly Area [hours]\n\n*Required*: If not provided, assumed to be 18"),
 	NULL},
{"prepTow", (getter)Wobos_get_prepTow,(setter)Wobos_set_prepTow,
	PyDoc_STR("*float*: Prepare Floating Substructure for Tow to Site [hours]\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"procurement_contingency", (getter)Wobos_get_procurement_contingency,(setter)Wobos_set_procurement_contingency,
	PyDoc_STR("*float*: Procurement Contingency\n\n*Required*: If not provided, assumed to be 0.05"),
 	NULL},
{"projLife", (getter)Wobos_get_projLife,(setter)Wobos_set_projLife,
	PyDoc_STR("*float*: Project Economic Life [years]\n\n*Required*: If not provided, assumed to be 20"),
 	NULL},
{"pwrFac", (getter)Wobos_get_pwrFac,(setter)Wobos_set_pwrFac,
	PyDoc_STR("*float*: Power Transfer Efficiency Factor\n\n*Required*: If not provided, assumed to be 0.95"),
 	NULL},
{"removeHamJack", (getter)Wobos_get_removeHamJack,(setter)Wobos_set_removeHamJack,
	PyDoc_STR("*float*: Remove Hammer for Jacket Piles Installation [hours]\n\n*Required*: If not provided, assumed to be 4"),
 	NULL},
{"removeHamMono", (getter)Wobos_get_removeHamMono,(setter)Wobos_set_removeHamMono,
	PyDoc_STR("*float*: Remove Hammer for Monopile Installation [hours]\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"rivsnHarbsAct", (getter)Wobos_get_rivsnHarbsAct,(setter)Wobos_set_rivsnHarbsAct,
	PyDoc_STR("*float*: Rivers & Harbors Act Section 10 Compliance Cost [$]\n\n*Required*: If not provided, assumed to be 100000"),
 	NULL},
{"rnaM", (getter)Wobos_get_rnaM,(setter)Wobos_set_rnaM,
	PyDoc_STR("*float*: Rotor-Nacelle Assembly Mass [tonne]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"rotorD", (getter)Wobos_get_rotorD,(setter)Wobos_set_rotorD,
	PyDoc_STR("*float*: Rotor Diameter [m]\n\n*Required*: If not provided, assumed to be 120"),
 	NULL},
{"sSteelCR", (getter)Wobos_get_sSteelCR,(setter)Wobos_set_sSteelCR,
	PyDoc_STR("*float*: Secondary/Outfitting Steel Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 7250"),
 	NULL},
{"saPlan", (getter)Wobos_get_saPlan,(setter)Wobos_set_saPlan,
	PyDoc_STR("*float*: Site Assessment Plan Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"scourMat", (getter)Wobos_get_scourMat,(setter)Wobos_set_scourMat,
	PyDoc_STR("*float*: Scour Protection Material Cost [$/location]\n\n*Required*: If not provided, assumed to be 250000"),
 	NULL},
{"scrapVal", (getter)Wobos_get_scrapVal,(setter)Wobos_set_scrapVal,
	PyDoc_STR("*float*: Total Scrap Value of Decommissioned Components [$]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"seaSpreadDR", (getter)Wobos_get_seaSpreadDR,(setter)Wobos_set_seaSpreadDR,
	PyDoc_STR("*float*: Suction Pile Anchor Spread Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 165000"),
 	NULL},
{"seaSpreadMob", (getter)Wobos_get_seaSpreadMob,(setter)Wobos_set_seaSpreadMob,
	PyDoc_STR("*float*: Suction Pile Anchor Spread Mobilization Cost [$]\n\n*Required*: If not provided, assumed to be 4500000"),
 	NULL},
{"shorePullIn", (getter)Wobos_get_shorePullIn,(setter)Wobos_set_shorePullIn,
	PyDoc_STR("*float*: Cable Pull in to Onshore Infrastructure [hours]\n\n*Required*: If not provided, assumed to be 96"),
 	NULL},
{"shuntCR", (getter)Wobos_get_shuntCR,(setter)Wobos_set_shuntCR,
	PyDoc_STR("*float*: Shunt Reactor Cost Rate [$/MVA]\n\n*Required*: If not provided, assumed to be 35000"),
 	NULL},
{"socEconStudyMet", (getter)Wobos_get_socEconStudyMet,(setter)Wobos_set_socEconStudyMet,
	PyDoc_STR("*float*: Socioeconomic and Land use Study Met Tower Cost [$]\n\n*Required*: If not provided, assumed to be 500000"),
 	NULL},
{"socEconStudyProj", (getter)Wobos_get_socEconStudyProj,(setter)Wobos_set_socEconStudyProj,
	PyDoc_STR("*float*: Socioeconomic and Land use Study Project Cost [$]\n\n*Required*: If not provided, assumed to be 200000"),
 	NULL},
{"spMoorCheck", (getter)Wobos_get_spMoorCheck,(setter)Wobos_set_spMoorCheck,
	PyDoc_STR("*float*: Survey Spar Mooring Lines and Connections [hours]\n\n*Required*: If not provided, assumed to be 16"),
 	NULL},
{"spMoorCon", (getter)Wobos_get_spMoorCon,(setter)Wobos_set_spMoorCon,
	PyDoc_STR("*float*: Connect Mooring Lines to Spar [hours]\n\n*Required*: If not provided, assumed to be 20"),
 	NULL},
{"spStifColCR", (getter)Wobos_get_spStifColCR,(setter)Wobos_set_spStifColCR,
	PyDoc_STR("*float*: Spar Stiffened Column Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 3120"),
 	NULL},
{"spTapColCR", (getter)Wobos_get_spTapColCR,(setter)Wobos_set_spTapColCR,
	PyDoc_STR("*float*: Spar Tapered Column Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 4220"),
 	NULL},
{"ssBall", (getter)Wobos_get_ssBall,(setter)Wobos_set_ssBall,
	PyDoc_STR("*float*: Ballast Semi-submersible [hours]\n\n*Required*: If not provided, assumed to be 6"),
 	NULL},
{"ssHeaveCR", (getter)Wobos_get_ssHeaveCR,(setter)Wobos_set_ssHeaveCR,
	PyDoc_STR("*float*: Semi-submersible Heave Plate Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 6250"),
 	NULL},
{"ssMoorCheck", (getter)Wobos_get_ssMoorCheck,(setter)Wobos_set_ssMoorCheck,
	PyDoc_STR("*float*: Survey Semi-submersible Mooing Lines and Connections [hours]\n\n*Required*: If not provided, assumed to be 12"),
 	NULL},
{"ssMoorCon", (getter)Wobos_get_ssMoorCon,(setter)Wobos_set_ssMoorCon,
	PyDoc_STR("*float*: Connect Mooring Lines to Semi-Submersible [hours]\n\n*Required*: If not provided, assumed to be 22"),
 	NULL},
{"ssStifColCR", (getter)Wobos_get_ssStifColCR,(setter)Wobos_set_ssStifColCR,
	PyDoc_STR("*float*: Semi-submersible Stiffened Column Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 3120"),
 	NULL},
{"ssTrussCR", (getter)Wobos_get_ssTrussCR,(setter)Wobos_set_ssTrussCR,
	PyDoc_STR("*float*: Semi-submersible Truss Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 6250"),
 	NULL},
{"stateLease", (getter)Wobos_get_stateLease,(setter)Wobos_set_stateLease,
	PyDoc_STR("*float*: State Leasing and Permitting Cost [$]\n\n*Required*: If not provided, assumed to be 250000"),
 	NULL},
{"subTotCost", (getter)Wobos_get_subTotCost,(setter)Wobos_set_subTotCost,
	PyDoc_STR("*float*: Substructure & Foundation Total Cost [$]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"subTotM", (getter)Wobos_get_subTotM,(setter)Wobos_set_subTotM,
	PyDoc_STR("*float*: Total Substructure Mass per Turbine [tonne]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"subsJackCR", (getter)Wobos_get_subsJackCR,(setter)Wobos_set_subsJackCR,
	PyDoc_STR("*float*: Offshore Substation Jacket Lattice Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 6250"),
 	NULL},
{"subsLoad", (getter)Wobos_get_subsLoad,(setter)Wobos_set_subsLoad,
	PyDoc_STR("*float*: Offshore Substation Loadout for Installation [hours]\n\n*Required*: If not provided, assumed to be 60"),
 	NULL},
{"subsPileCR", (getter)Wobos_get_subsPileCR,(setter)Wobos_set_subsPileCR,
	PyDoc_STR("*float*: Offshore Substation Jacket Pile Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 2250"),
 	NULL},
{"subsPullIn", (getter)Wobos_get_subsPullIn,(setter)Wobos_set_subsPullIn,
	PyDoc_STR("*float*: Cable Pull in to Offshore Substation [hours]\n\n*Required*: If not provided, assumed to be 48"),
 	NULL},
{"subsTopDes", (getter)Wobos_get_subsTopDes,(setter)Wobos_set_subsTopDes,
	PyDoc_STR("*float*: Offshore Substation Design Cost [$]\n\n*Required*: If not provided, assumed to be 4500000"),
 	NULL},
{"subsTopFab", (getter)Wobos_get_subsTopFab,(setter)Wobos_set_subsTopFab,
	PyDoc_STR("*float*: Offshore Substation Fabrication Cost [$/tonne]\n\n*Required*: If not provided, assumed to be 14500"),
 	NULL},
{"subsVessPos", (getter)Wobos_get_subsVessPos,(setter)Wobos_set_subsVessPos,
	PyDoc_STR("*float*: Vessel Positioning Time Offshore Substation Installation [hours]\n\n*Required*: If not provided, assumed to be 6"),
 	NULL},
{"substructCont", (getter)Wobos_get_substructCont,(setter)Wobos_set_substructCont,
	PyDoc_STR("*float*: Substructure Install Weather Contingency [%]\n\n*Required*: If not provided, assumed to be 0.3"),
 	NULL},
{"substructure", (getter)Wobos_get_substructure,(setter)Wobos_set_substructure,
	PyDoc_STR("*float*: Substructure Type\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be MONOPILE"),
 	NULL},
{"surfLayRate", (getter)Wobos_get_surfLayRate,(setter)Wobos_set_surfLayRate,
	PyDoc_STR("*float*: Cable Surface Lay Rate [m/hour]\n\n*Required*: If not provided, assumed to be 375"),
 	NULL},
{"tax_rate", (getter)Wobos_get_tax_rate,(setter)Wobos_set_tax_rate,
	PyDoc_STR("*float*: Effective Tax Rate\n\n*Required*: If not provided, assumed to be 0.4"),
 	NULL},
{"topAssemblyFac", (getter)Wobos_get_topAssemblyFac,(setter)Wobos_set_topAssemblyFac,
	PyDoc_STR("*float*: Offshore Substation Land-based Assembly Factor\n\n*Required*: If not provided, assumed to be 0.075"),
 	NULL},
{"towerD", (getter)Wobos_get_towerD,(setter)Wobos_set_towerD,
	PyDoc_STR("*float*: Tower Base Diameter [m]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"towerInstallMethod", (getter)Wobos_get_towerInstallMethod,(setter)Wobos_set_towerInstallMethod,
	PyDoc_STR("*float*: Tower Installation Method\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be ONEPIECE"),
 	NULL},
{"towerM", (getter)Wobos_get_towerM,(setter)Wobos_set_towerM,
	PyDoc_STR("*float*: Tower Mass [tonne]\n\n*Required*: If not provided, assumed to be 0"),
 	NULL},
{"tpCover", (getter)Wobos_get_tpCover,(setter)Wobos_set_tpCover,
	PyDoc_STR("*float*: Install Transition Piece Cover [hours]\n\n*Required*: If not provided, assumed to be 1.5"),
 	NULL},
{"turbCapEx", (getter)Wobos_get_turbCapEx,(setter)Wobos_set_turbCapEx,
	PyDoc_STR("*float*: Turbine Capital Cost [$/kW]\n\n*Required*: If not provided, assumed to be 1605"),
 	NULL},
{"turbCont", (getter)Wobos_get_turbCont,(setter)Wobos_set_turbCont,
	PyDoc_STR("*float*: Turbine Install Weather Contingency [%]\n\n*Required*: If not provided, assumed to be 0.3"),
 	NULL},
{"turbFasten", (getter)Wobos_get_turbFasten,(setter)Wobos_set_turbFasten,
	PyDoc_STR("*float*: Prepare and Fasten Turbine for Transport [hours/turbine]\n\n*Required*: If not provided, assumed to be 8"),
 	NULL},
{"turbInstallMethod", (getter)Wobos_get_turbInstallMethod,(setter)Wobos_set_turbInstallMethod,
	PyDoc_STR("*float*: Turbine Installation Method\n\n*Constraints*: INTEGER\n\n*Required*: If not provided, assumed to be INDIVIDUAL"),
 	NULL},
{"turbR", (getter)Wobos_get_turbR,(setter)Wobos_set_turbR,
	PyDoc_STR("*float*: Turbine Rating [MW]\n\n*Constraints*: MIN=1,MAX=15\n\n*Required*: If not provided, assumed to be 5"),
 	NULL},
{"upendSpar", (getter)Wobos_get_upendSpar,(setter)Wobos_set_upendSpar,
	PyDoc_STR("*float*: Upend and Ballast Spar [hours]\n\n*Required*: If not provided, assumed to be 36"),
 	NULL},
{"vesselPosJack", (getter)Wobos_get_vesselPosJack,(setter)Wobos_set_vesselPosJack,
	PyDoc_STR("*float*: Vessel Positioning Time Jacket Installation [hours]\n\n*Required*: If not provided, assumed to be 8"),
 	NULL},
{"vesselPosMono", (getter)Wobos_get_vesselPosMono,(setter)Wobos_set_vesselPosMono,
	PyDoc_STR("*float*: Vessel Positioning Time Monopile Installation [hours]\n\n*Required*: If not provided, assumed to be 3"),
 	NULL},
{"vesselPosTurb", (getter)Wobos_get_vesselPosTurb,(setter)Wobos_set_vesselPosTurb,
	PyDoc_STR("*float*: Vessel Positioning Time Turbine Installation [hours]\n\n*Required*: If not provided, assumed to be 2"),
 	NULL},
{"waterD", (getter)Wobos_get_waterD,(setter)Wobos_set_waterD,
	PyDoc_STR("*float*: Max Water Depth [m]\n\n*Constraints*: MIN=3,MAX=1000\n\n*Required*: If not provided, assumed to be 30"),
 	NULL},
{"wharfRate", (getter)Wobos_get_wharfRate,(setter)Wobos_set_wharfRate,
	PyDoc_STR("*float*: Wharf Loading and Unloading Cost Rate [$/tonne]\n\n*Required*: If not provided, assumed to be 2.75"),
 	NULL},
{"winchDR", (getter)Wobos_get_winchDR,(setter)Wobos_set_winchDR,
	PyDoc_STR("*float*: Cable Landfall Winch Day Rate [$/day]\n\n*Required*: If not provided, assumed to be 1000"),
 	NULL},
{"workSpace", (getter)Wobos_get_workSpace,(setter)Wobos_set_workSpace,
	PyDoc_STR("*float*: Offshore Substation Workspace & Accommodations Cost [$]\n\n*Required*: If not provided, assumed to be 2000000"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Wobos_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WindObos.Wobos",             /*tp_name*/
		sizeof(VarGroupObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Wobos_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Wobos_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};


/*
 * Outputs Group
 */ 

static PyTypeObject Outputs_Type;

static PyObject *
Outputs_new(SAM_WindObos data_ptr)
{
	PyObject* new_obj = Outputs_Type.tp_alloc(&Outputs_Type,0);

	VarGroupObject* Outputs_obj = (VarGroupObject*)new_obj;

	Outputs_obj->data_ptr = (SAM_table)data_ptr;

	return new_obj;
}

/* Outputs methods */

static PyObject *
Outputs_assign(VarGroupObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_dict(self->data_ptr, dict, "WindObos", "Outputs")){
		return NULL;
	}

	Py_INCREF(Py_None);
	return Py_None;
}

static PyObject *
Outputs_export(VarGroupObject *self, PyObject *args)
{
	PyTypeObject* tp = &Outputs_Type;
	PyObject* dict = PySAM_export_to_dict((PyObject *) self, tp);
	return dict;
}

static PyMethodDef Outputs_methods[] = {
		{"assign",            (PyCFunction)Outputs_assign,  METH_VARARGS,
			PyDoc_STR("assign() -> None\n Assign attributes from dictionary\n\n``Outputs_vals = { var: val, ...}``")},
		{"export",            (PyCFunction)Outputs_export,  METH_VARARGS,
			PyDoc_STR("export() -> dict\n Export attributes into dictionary")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
Outputs_get_arrCab1Cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_arrCab1Cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_arrCab2Cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_arrCab2Cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_arrInstTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_arrInstTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_array_cable_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_array_cable_install_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_bos_capex(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_bos_capex_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cab1Leng(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_cab1Leng_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cab2Leng(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_cab2Leng_nget, self->data_ptr);
}

static PyObject *
Outputs_get_cabSurvey(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_cabSurvey_nget, self->data_ptr);
}

static PyObject *
Outputs_get_commissioning(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_commissioning_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_finance_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_construction_finance_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_finance_factor(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_construction_finance_factor_nget, self->data_ptr);
}

static PyObject *
Outputs_get_construction_insurance_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_construction_insurance_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_decomCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_decomCost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_electrical_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_electrical_install_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_expCabCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_expCabCost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_expCabLeng(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_expCabLeng_nget, self->data_ptr);
}

static PyObject *
Outputs_get_expInstTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_expInstTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_export_cable_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_export_cable_install_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_fixCabLeng(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_fixCabLeng_nget, self->data_ptr);
}

static PyObject *
Outputs_get_floatPrepTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_floatPrepTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_freeCabLeng(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_freeCabLeng_nget, self->data_ptr);
}

static PyObject *
Outputs_get_mob_demob_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_mob_demob_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_moorTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_moorTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_nExpCab(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_nExpCab_nget, self->data_ptr);
}

static PyObject *
Outputs_get_nSubPerTrip(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_nSubPerTrip_nget, self->data_ptr);
}

static PyObject *
Outputs_get_nTurbPerTrip(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_nTurbPerTrip_nget, self->data_ptr);
}

static PyObject *
Outputs_get_soft_costs(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_soft_costs_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subDeckArea(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_subDeckArea_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subInstTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_subInstTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subsInstTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_subsInstTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subsPileM(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_subsPileM_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subsSubM(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_subsSubM_nget, self->data_ptr);
}

static PyObject *
Outputs_get_subsTopM(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_subsTopM_nget, self->data_ptr);
}

static PyObject *
Outputs_get_substation_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_substation_install_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_substructure_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_substructure_install_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_systAngle(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_systAngle_nget, self->data_ptr);
}

static PyObject *
Outputs_get_totAnICost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_totAnICost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_totDevCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_totDevCost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_totElecCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_totElecCost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_totEnMCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_totEnMCost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_totInstTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_totInstTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_totPnSCost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_totPnSCost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_bos_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_total_bos_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_total_contingency_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_total_contingency_cost_nget, self->data_ptr);
}

static PyObject *
Outputs_get_turbDeckArea(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_turbDeckArea_nget, self->data_ptr);
}

static PyObject *
Outputs_get_turbInstTime(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_turbInstTime_nget, self->data_ptr);
}

static PyObject *
Outputs_get_turbine_install_cost(VarGroupObject *self, void *closure)
{
	return PySAM_double_getter(SAM_WindObos_Outputs_turbine_install_cost_nget, self->data_ptr);
}

static PyGetSetDef Outputs_getset[] = {
{"arrCab1Cost", (getter)Outputs_get_arrCab1Cost,(setter)0,
	PyDoc_STR("*float*: Array Cable #1 and Ancillary Cost [$]"),
 	NULL},
{"arrCab2Cost", (getter)Outputs_get_arrCab2Cost,(setter)0,
	PyDoc_STR("*float*: Array Cable #2 and Ancillary Cost [$]"),
 	NULL},
{"arrInstTime", (getter)Outputs_get_arrInstTime,(setter)0,
	PyDoc_STR("*float*: Array Cable System Installation Time [days]"),
 	NULL},
{"array_cable_install_cost", (getter)Outputs_get_array_cable_install_cost,(setter)0,
	PyDoc_STR("*float*: Array Cable Installation Cost [$]"),
 	NULL},
{"bos_capex", (getter)Outputs_get_bos_capex,(setter)0,
	PyDoc_STR("*float*: BOS Capital Expenditures [$]"),
 	NULL},
{"cab1Leng", (getter)Outputs_get_cab1Leng,(setter)0,
	PyDoc_STR("*float*: Array Cable #1 Length [m]"),
 	NULL},
{"cab2Leng", (getter)Outputs_get_cab2Leng,(setter)0,
	PyDoc_STR("*float*: Array Cabel #2 Length [m]"),
 	NULL},
{"cabSurvey", (getter)Outputs_get_cabSurvey,(setter)0,
	PyDoc_STR("*float*: Cable Route Survey Cost [$]"),
 	NULL},
{"commissioning", (getter)Outputs_get_commissioning,(setter)0,
	PyDoc_STR("*float*: Plant Commissioning Cost [$]"),
 	NULL},
{"construction_finance_cost", (getter)Outputs_get_construction_finance_cost,(setter)0,
	PyDoc_STR("*float*: Construction Finance Cost [$]"),
 	NULL},
{"construction_finance_factor", (getter)Outputs_get_construction_finance_factor,(setter)0,
	PyDoc_STR("*float*: Construction Finance Factor"),
 	NULL},
{"construction_insurance_cost", (getter)Outputs_get_construction_insurance_cost,(setter)0,
	PyDoc_STR("*float*: Construction Insurance Cost [$]"),
 	NULL},
{"decomCost", (getter)Outputs_get_decomCost,(setter)0,
	PyDoc_STR("*float*: Plant Decommissioning Cost [$]"),
 	NULL},
{"electrical_install_cost", (getter)Outputs_get_electrical_install_cost,(setter)0,
	PyDoc_STR("*float*: Electrical Install Cost [$]"),
 	NULL},
{"expCabCost", (getter)Outputs_get_expCabCost,(setter)0,
	PyDoc_STR("*float*: Export Cable and Ancillary Cost [$]"),
 	NULL},
{"expCabLeng", (getter)Outputs_get_expCabLeng,(setter)0,
	PyDoc_STR("*float*: Export Cable Length [m]"),
 	NULL},
{"expInstTime", (getter)Outputs_get_expInstTime,(setter)0,
	PyDoc_STR("*float*: Export Cable Installation Time [days]"),
 	NULL},
{"export_cable_install_cost", (getter)Outputs_get_export_cable_install_cost,(setter)0,
	PyDoc_STR("*float*: Export Cable Installation Cost [$]"),
 	NULL},
{"fixCabLeng", (getter)Outputs_get_fixCabLeng,(setter)0,
	PyDoc_STR("*float*: Fixed Cable Length [m]"),
 	NULL},
{"floatPrepTime", (getter)Outputs_get_floatPrepTime,(setter)0,
	PyDoc_STR("*float*: Floating Preparation Time [days]"),
 	NULL},
{"freeCabLeng", (getter)Outputs_get_freeCabLeng,(setter)0,
	PyDoc_STR("*float*: Free Hanging Cable Length [m]"),
 	NULL},
{"mob_demob_cost", (getter)Outputs_get_mob_demob_cost,(setter)0,
	PyDoc_STR("*float*: Mobilization/Demobilization Cost [$]"),
 	NULL},
{"moorTime", (getter)Outputs_get_moorTime,(setter)0,
	PyDoc_STR("*float*: Mooring and Anchor System Installation Time [days]"),
 	NULL},
{"nExpCab", (getter)Outputs_get_nExpCab,(setter)0,
	PyDoc_STR("*float*: Number of Export Cables"),
 	NULL},
{"nSubPerTrip", (getter)Outputs_get_nSubPerTrip,(setter)0,
	PyDoc_STR("*float*: Maximum Number of Substructures per Vessel Trip"),
 	NULL},
{"nTurbPerTrip", (getter)Outputs_get_nTurbPerTrip,(setter)0,
	PyDoc_STR("*float*: Maximum Number of Turbines per Vessel Trip"),
 	NULL},
{"soft_costs", (getter)Outputs_get_soft_costs,(setter)0,
	PyDoc_STR("*float*: Soft Costs [$]"),
 	NULL},
{"subDeckArea", (getter)Outputs_get_subDeckArea,(setter)0,
	PyDoc_STR("*float*: Deck Area Required per Substructure [m^2]"),
 	NULL},
{"subInstTime", (getter)Outputs_get_subInstTime,(setter)0,
	PyDoc_STR("*float*: Substructure Installation Time [days]"),
 	NULL},
{"subsInstTime", (getter)Outputs_get_subsInstTime,(setter)0,
	PyDoc_STR("*float*: Offshore Substation Installation Time [days]"),
 	NULL},
{"subsPileM", (getter)Outputs_get_subsPileM,(setter)0,
	PyDoc_STR("*float*: Offshore Substation Jacket Piles Mass [tonne]"),
 	NULL},
{"subsSubM", (getter)Outputs_get_subsSubM,(setter)0,
	PyDoc_STR("*float*: Offshore Substation Substructure Mass [tonne]"),
 	NULL},
{"subsTopM", (getter)Outputs_get_subsTopM,(setter)0,
	PyDoc_STR("*float*: Substation Topside Mass [tonne]"),
 	NULL},
{"substation_install_cost", (getter)Outputs_get_substation_install_cost,(setter)0,
	PyDoc_STR("*float*: Substation Installation Cost [$]"),
 	NULL},
{"substructure_install_cost", (getter)Outputs_get_substructure_install_cost,(setter)0,
	PyDoc_STR("*float*: Substructure Install Cost [$]"),
 	NULL},
{"systAngle", (getter)Outputs_get_systAngle,(setter)0,
	PyDoc_STR("*float*: Floating System Angle [degrees]"),
 	NULL},
{"totAnICost", (getter)Outputs_get_totAnICost,(setter)0,
	PyDoc_STR("*float*: Total Assembly & Installation Cost [$]"),
 	NULL},
{"totDevCost", (getter)Outputs_get_totDevCost,(setter)0,
	PyDoc_STR("*float*: Total Development Cost [$]"),
 	NULL},
{"totElecCost", (getter)Outputs_get_totElecCost,(setter)0,
	PyDoc_STR("*float*: Total Electrical Infrastructure Cost [$]"),
 	NULL},
{"totEnMCost", (getter)Outputs_get_totEnMCost,(setter)0,
	PyDoc_STR("*float*: Total Engineering & Management Cost [$]"),
 	NULL},
{"totInstTime", (getter)Outputs_get_totInstTime,(setter)0,
	PyDoc_STR("*float*: Total Installation Time [days]"),
 	NULL},
{"totPnSCost", (getter)Outputs_get_totPnSCost,(setter)0,
	PyDoc_STR("*float*: Total Port & Staging Cost [$]"),
 	NULL},
{"total_bos_cost", (getter)Outputs_get_total_bos_cost,(setter)0,
	PyDoc_STR("*float*: Total Balance of System Cost [$]"),
 	NULL},
{"total_contingency_cost", (getter)Outputs_get_total_contingency_cost,(setter)0,
	PyDoc_STR("*float*: Total Contingency Cost [$]"),
 	NULL},
{"turbDeckArea", (getter)Outputs_get_turbDeckArea,(setter)0,
	PyDoc_STR("*float*: Deck Area Required per Turbine [m^2]"),
 	NULL},
{"turbInstTime", (getter)Outputs_get_turbInstTime,(setter)0,
	PyDoc_STR("*float*: Turbine Installation Time [days]"),
 	NULL},
{"turbine_install_cost", (getter)Outputs_get_turbine_install_cost,(setter)0,
	PyDoc_STR("*float*: Turbine Install Cost [$]"),
 	NULL},
	{NULL}  /* Sentinel */
};

static PyTypeObject Outputs_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WindObos.Outputs",             /*tp_name*/
		sizeof(VarGroupObject),          /*tp_basicsize*/
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
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		Outputs_methods,         /*tp_methods*/
		0,                          /*tp_members*/
		Outputs_getset,          /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,             /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/*
 * WindObos
 */

static PyTypeObject WindObos_Type;

static CmodObject *
newWindObosObject(void* data_ptr)
{
	CmodObject *self;
	self = PyObject_New(CmodObject, &WindObos_Type);

	PySAM_TECH_ATTR()

	PyObject* Wobos_obj = Wobos_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Wobos", Wobos_obj);
	Py_DECREF(Wobos_obj);

	PyObject* Outputs_obj = Outputs_new(self->data_ptr);
	PyDict_SetItemString(attr_dict, "Outputs", Outputs_obj);
	Py_DECREF(Outputs_obj);

	return self;
}

/* WindObos methods */

static void
WindObos_dealloc(CmodObject *self)
{
	Py_XDECREF(self->x_attr);

	if (!self->data_owner_ptr) {
		SAM_error error = new_error();
		SAM_table_destruct(self->data_ptr, &error);
		PySAM_has_error(error);
	}
	PyObject_Del(self);
}


static PyObject *
WindObos_execute(CmodObject *self, PyObject *args)
{
	int verbosity = 0;

	if (!PyArg_ParseTuple(args, "|i", &verbosity))
		return NULL;

	SAM_error error = new_error();
	SAM_WindObos_execute(self->data_ptr, verbosity, &error);
	if (PySAM_has_error(error )) return NULL;
	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
WindObos_assign(CmodObject *self, PyObject *args)
{
	PyObject* dict;
	if (!PyArg_ParseTuple(args, "O:assign", &dict)){
		return NULL;
	}

	if (!PySAM_assign_from_nested_dict((PyObject*)self, self->x_attr, self->data_ptr, dict, "WindObos"))
		return NULL;

	Py_INCREF(Py_None);
	return Py_None;
}


static PyObject *
WindObos_export(CmodObject *self, PyObject *args)
{
	return PySAM_export_to_nested_dict((PyObject *) self, self->x_attr);
}

static PyObject *
WindObos_value(CmodObject *self, PyObject *args)
{
	return Cmod_value(self, args);
}

static PyMethodDef WindObos_methods[] = {
		{"execute",            (PyCFunction)WindObos_execute,  METH_VARARGS,
				PyDoc_STR("execute(int verbosity) -> None\n Execute simulation with verbosity level 0 (default) or 1")},
		{"assign",            (PyCFunction)WindObos_assign,  METH_VARARGS,
				PyDoc_STR("assign(dict) -> None\n Assign attributes from nested dictionary, except for Outputs\n\n``nested_dict = { 'wobos': { var: val, ...}, ...}``")},
		{"export",            (PyCFunction)WindObos_export,  METH_VARARGS,
				PyDoc_STR("export() -> dict\n Export attributes into nested dictionary")},
		{"value",             (PyCFunction)WindObos_value, METH_VARARGS,
				PyDoc_STR("value(name, optional value) -> Union[None, float, dict, sequence, str]\n Get or set by name a value in any of the variable groups.")},
		{NULL,              NULL}           /* sentinel */
};

static PyObject *
WindObos_getattro(CmodObject *self, PyObject *name)
{
	return PySAM_get_attr((PyObject*) self, (PyObject*) self->x_attr, name);
}

static int
WindObos_setattr(CmodObject *self, const char *name, PyObject *v)
{
	return PySAM_set_attr((PyObject*)self, (PyObject*)self->x_attr, name, v);
}

static PyTypeObject WindObos_Type = {
		/* The ob_type field must be initialized in the module init function
		 * to be portable to Windows without using C++. */
		PyVarObject_HEAD_INIT(NULL, 0)
		"WindObos",            /*tp_name*/
		sizeof(CmodObject),/*tp_basicsize*/
		0,                          /*tp_itemsize*/
		/* methods */
		(destructor)WindObos_dealloc,    /*tp_dealloc*/
		0,                          /*tp_print*/
		(getattrfunc)0,             /*tp_getattr*/
		(setattrfunc)WindObos_setattr,   /*tp_setattr*/
		0,                          /*tp_reserved*/
		0,                          /*tp_repr*/
		0,                          /*tp_as_number*/
		0,                          /*tp_as_sequence*/
		0,                          /*tp_as_mapping*/
		0,                          /*tp_hash*/
		0,                          /*tp_call*/
		0,                          /*tp_str*/
		(getattrofunc)WindObos_getattro, /*tp_getattro*/
		0,                          /*tp_setattro*/
		0,                          /*tp_as_buffer*/
		Py_TPFLAGS_DEFAULT,         /*tp_flags*/
		"This class contains all the variable information for running a simulation. Variables are grouped together in the subclasses as properties. If property assignments are the wrong type, an error is thrown.",        /*tp_doc*/
		0,                          /*tp_traverse*/
		0,                          /*tp_clear*/
		0,                          /*tp_richcompare*/
		0,                          /*tp_weaklistofnset*/
		0,                          /*tp_iter*/
		0,                          /*tp_iternext*/
		WindObos_methods,      /*tp_methods*/
		0,                          /*tp_members*/
		0,       /*tp_getset*/
		0,                          /*tp_base*/
		0,                          /*tp_dict*/
		0,                          /*tp_descr_get*/
		0,                          /*tp_descr_set*/
		0,                          /*tp_dictofnset*/
		0,                          /*tp_init*/
		0,                          /*tp_alloc*/
		0,                          /*tp_new*/
		0,                          /*tp_free*/
		0,                          /*tp_is_gc*/
};

/* --------------------------------------------------------------------- */


/* Function of no arguments returning new WindObos object */

static PyObject *
WindObos_new(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	rv = newWindObosObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
WindObos_wrap(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	long long int ptr = 0;  // 64 bit arch
	if (!PyArg_ParseTuple(args, "L:wrap", &ptr)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindObosObject((void*)ptr);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	return (PyObject *)rv;
}

static PyObject *
WindObos_default(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "s:default", &def)){
		PyErr_BadArgument();
		return NULL;
	}
	rv = newWindObosObject(0);
	if (rv == NULL)
		return NULL;

	rv->data_owner_ptr = NULL;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "WindObos", def);

	return (PyObject *)rv;
}

static PyObject *
WindObos_from_existing(PyObject *self, PyObject *args)
{
	CmodObject *rv;
	PyObject * module = 0;
	char* def = 0;
	if (!PyArg_ParseTuple(args, "O|s:from_existing", &module, &def)){
		PyErr_BadArgument();
		return NULL;
	}
	CmodObject *module_obj = (CmodObject *)module;
	SAM_table ptr = module_obj->data_ptr;

	// do a rough validity check on the data by checking its size
	SAM_error error = new_error();
	int data_size = SAM_table_size(ptr, &error);
	if (PySAM_has_error(error))
		goto fail;
	if (data_size < 0)
		goto fail;

	rv = newWindObosObject((void*)ptr);
	if (rv == NULL)
		goto fail;
	rv->data_owner_ptr = module;
	if (!def)
		return (PyObject *)rv;
	PySAM_load_defaults((PyObject*)rv, rv->x_attr, rv->data_ptr, "WindObos", def);
	return (PyObject *)rv;

	fail:
	Py_DECREF(module);
	return NULL;
}/* ---------- */


/* List of functions defined in the module */

static PyMethodDef WindObosModule_methods[] = {
		{"new",             WindObos_new,         METH_VARARGS,
				PyDoc_STR("new() -> WindObos")},
		{"default",             WindObos_default,         METH_VARARGS,
				PyDoc_STR("default(config) -> WindObos\n\nUse financial config-specific default attributes\n"
				"")},
		{"wrap",             WindObos_wrap,         METH_VARARGS,
				PyDoc_STR("wrap(ssc_data_t) -> WindObos\n\nUse existing PySSC data\n\n.. warning::\n\n	Do not call PySSC.data_free on the ssc_data_t provided to ``wrap``")},
		{"from_existing",   WindObos_from_existing,        METH_VARARGS,
				PyDoc_STR("from_existing(data, optional config) -> WindObos\n\nShare underlying data with an existing PySAM class. If config provided, default attributes are loaded otherwise.")},
		{NULL,              NULL}           /* sentinel */
};

PyDoc_STRVAR(module_doc,
			 "WindObos");


static int
WindObosModule_exec(PyObject *m)
{
	/* Finalize the type object including setting type of the new type
	 * object; doing it here is required for portability, too. */

	if (PySAM_load_lib(m) < 0) goto fail;

	WindObos_Type.tp_dict = PyDict_New();
	if (!WindObos_Type.tp_dict) { goto fail; }

	/// Add the Wobos type object to WindObos_Type
	if (PyType_Ready(&Wobos_Type) < 0) { goto fail; }
	PyDict_SetItemString(WindObos_Type.tp_dict,
				"Wobos",
				(PyObject*)&Wobos_Type);
	Py_DECREF(&Wobos_Type);

	/// Add the Outputs type object to WindObos_Type
	if (PyType_Ready(&Outputs_Type) < 0) { goto fail; }
	PyDict_SetItemString(WindObos_Type.tp_dict,
				"Outputs",
				(PyObject*)&Outputs_Type);
	Py_DECREF(&Outputs_Type);

	/// Add the WindObos type object to the module
	if (PyType_Ready(&WindObos_Type) < 0) { goto fail; }
	PyModule_AddObject(m,
				"WindObos",
				(PyObject*)&WindObos_Type);

	return 0;
	fail:
	Py_XDECREF(m);
	return -1;
}

static struct PyModuleDef_Slot WindObosModule_slots[] = {
		{Py_mod_exec, WindObosModule_exec},
		{0, NULL},
};

static struct PyModuleDef WindObosModule = {
		PyModuleDef_HEAD_INIT,
		"WindObos",
		module_doc,
		0,
		WindObosModule_methods,
		WindObosModule_slots,
		NULL,
		NULL,
		NULL
};

/* Export function for the module */

PyMODINIT_FUNC
PyInit_WindObos(void)
{
	return PyModuleDef_Init(&WindObosModule);
}