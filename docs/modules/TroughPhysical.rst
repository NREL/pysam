.. _TroughPhysical:

TroughPhysical
***********************************

Wrapper for SAM Simulation Core model: `cmod_trough_physical.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_trough_physical.cpp>`_

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
 - P_ref
 - Rho_mirror_clean
 - SCAInfoArray
 - TrackingError
 - Type_cpnt
 - W_aperture
 - eta_ref
 - is_dispatch
 - is_wlim_series
 - nColt
 - nLoops
 - nSCA
 - solar_mult

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TroughPhysical model description**

.. automodule:: PySAM.TroughPhysical
	:members:

Functions
===================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Weather
	:members:

SolarField Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.SolarField
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Powerblock
	:members:

TES Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.TES
	:members:

Tou Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Tou
	:members:

System Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.System
	:members:

Controller Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Controller
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TroughPhysical.TroughPhysical.Outputs
	:members:

