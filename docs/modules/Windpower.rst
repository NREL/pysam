.. _Windpower:

Windpower
==========

.. automodule:: PySAM.Windpower
	:members:

Windpower is a wrapper for the SSC compute module `cmod_windpower.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_windpower.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - system_capacity

 - wake_int_loss

 - wind_farm_wake_model

 - wind_farm_xCoordinates

 - wind_farm_yCoordinates

 - wind_resource_model_choice

 - wind_turbine_hub_ht

 - wind_turbine_max_cp

 - wind_turbine_powercurve_powerout

 - wind_turbine_powercurve_windspeeds

 - wind_turbine_rotor_diameter

Functions
-----------

.. autoclass:: PySAM.Windpower.Windpower
	:members:

Resource Group
---------------

.. autoclass:: PySAM.Windpower.Windpower.Resource
	:members:

Turbine Group
--------------

.. autoclass:: PySAM.Windpower.Windpower.Turbine
	:members:

Farm Group
-----------

.. autoclass:: PySAM.Windpower.Windpower.Farm
	:members:

Losses Group
-------------

.. autoclass:: PySAM.Windpower.Windpower.Losses
	:members:

Uncertainty Group
------------------

.. autoclass:: PySAM.Windpower.Windpower.Uncertainty
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Windpower.Windpower.Outputs
	:members:

