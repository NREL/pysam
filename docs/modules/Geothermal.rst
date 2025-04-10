.. _Geothermal:

Geothermal
===========

.. automodule:: PySAM.Geothermal
	:members:

Geothermal is a wrapper for the SSC compute module `cmod_geothermal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_geothermal.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - T_htf_hot_ref

 - allow_reservoir_replacements

 - ambient_pressure

 - analysis_type

 - conversion_subtype

 - conversion_type

 - decline_type

 - delta_pressure_equip

 - design_temp

 - drilling_success_rate

 - dt_prod_well

 - excess_pressure_pump

 - failed_prod_flow_ratio

 - fracture_angle

 - fracture_aperature

 - fracture_length

 - fracture_spacing

 - fracture_width

 - geothermal_analysis_period

 - hr_pl_nlev

 - inj_prod_well_distance

 - injectivity_index

 - model_choice

 - nameplate

 - num_fractures

 - num_wells

 - num_wells_getem

 - plant_efficiency_input

 - prod_well_choice

 - pump_efficiency

 - reservoir_height

 - reservoir_model_inputs

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

 - stim_success_rate

 - subsurface_water_loss

 - temp_decline_max

 - temp_decline_rate

 - use_weather_file_conditions

 - well_flow_rate

 - wet_bulb_temp

Functions
-----------

.. autoclass:: PySAM.Geothermal.Geothermal
	:members:

GeoHourly Group
----------------

.. autoclass:: PySAM.Geothermal.Geothermal.GeoHourly
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.Geothermal.Geothermal.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Geothermal.Geothermal.Outputs
	:members:

