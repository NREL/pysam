.. _TroughPhysicalProcessHeat:

TroughPhysicalProcessHeat
***********************************

Wrapper for SAM Simulation Core model: `cmod_trough_physical_process_heat.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_trough_physical_process_heat.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - A_aperture
 - Ave_Focal_Length
 - ColperSCA
 - D_cpnt
 - Dirt_mirror
 - Distance_SCA
 - Error
 - GeomEffects
 - I_bn_des
 - K_cpnt
 - L_SCA
 - L_aperture
 - L_cpnt
 - Rho_mirror_clean
 - SCAInfoArray
 - TrackingError
 - Type_cpnt
 - W_aperture
 - is_dispatch
 - is_wlim_series
 - nColt
 - nLoops
 - nSCA
 - q_pb_design
 - solar_mult

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TroughPhysicalProcessHeat model description**

.. automodule:: PySAM.TroughPhysicalProcessHeat
	:members:

Functions
===================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Weather
	:members:

SolarField Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.SolarField
	:members:

Controller Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Controller
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.SystemDesign
	:members:

TES Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.TES
	:members:

TES2tank Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.TES2tank
	:members:

Tou Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Tou
	:members:

System Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.System
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Powerblock
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TroughPhysicalProcessHeat.TroughPhysicalProcessHeat.Outputs
	:members:

