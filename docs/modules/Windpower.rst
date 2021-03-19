.. _Windpower:

Windpower
***********************************

Wrapper for SAM Simulation Core model: `cmod_windpower.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_windpower.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

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

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Windpower model description**

.. automodule:: PySAM.Windpower
	:members:

Functions
===================================

.. autoclass:: PySAM.Windpower.Windpower
	:members:

Resource Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.Resource
	:members:

Turbine Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.Turbine
	:members:

Farm Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.Farm
	:members:

Losses Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.Losses
	:members:

Uncertainty Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.Uncertainty
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Windpower.Windpower.Outputs
	:members:

