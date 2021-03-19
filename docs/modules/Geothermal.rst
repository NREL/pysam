.. _Geothermal:

Geothermal
***********************************

Wrapper for SAM Simulation Core model: `cmod_geothermal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_geothermal.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - T_htf_hot_ref
 - ambient_pressure
 - analysis_type
 - casing_size
 - conversion_subtype
 - conversion_type
 - decline_type
 - delta_pressure_equip
 - design_temp
 - excess_pressure_pump
 - fracture_angle
 - fracture_aperature
 - fracture_width
 - geothermal_analysis_period
 - hr_pl_nlev
 - inj_prod_well_distance
 - inj_well_diam
 - model_choice
 - nameplate
 - num_fractures
 - num_wells
 - num_wells_getem
 - plant_efficiency_input
 - pump_efficiency
 - reservoir_height
 - reservoir_permeability
 - reservoir_pressure_change
 - reservoir_pressure_change_type
 - reservoir_width
 - resource_depth
 - resource_temp
 - resource_type
 - rock_density
 - rock_specific_heat
 - rock_thermal_conductivity
 - specified_pump_work_amount
 - specify_pump_work
 - subsurface_water_loss
 - temp_decline_max
 - temp_decline_rate
 - well_diameter
 - well_flow_rate
 - wet_bulb_temp

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Geothermal model description**

.. automodule:: PySAM.Geothermal
	:members:

Functions
===================================

.. autoclass:: PySAM.Geothermal.Geothermal
	:members:

GeoHourly Group
======================================================

.. autoclass:: PySAM.Geothermal.Geothermal.GeoHourly
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Geothermal.Geothermal.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Geothermal.Geothermal.Outputs
	:members:

