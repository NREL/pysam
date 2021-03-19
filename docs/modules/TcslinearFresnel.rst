.. _TcslinearFresnel:

TcslinearFresnel
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcslinear_fresnel.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcslinear_fresnel.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - ColAz
 - I_bn_des
 - P_boil_des
 - P_turb_des
 - Pipe_hl_coef
 - T_amb_des_sf
 - T_cold_ref
 - T_hot
 - azimuth
 - demand_var
 - eta_ref
 - nLoops
 - nModBoil
 - nModSH
 - q_max_aux
 - q_pb_des
 - solarm
 - system_capacity

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TcslinearFresnel model description**

.. automodule:: PySAM.TcslinearFresnel
	:members:

Functions
===================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Weather
	:members:

LinearFresnelr Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.LinearFresnelr
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.TouTranslator
	:members:

Solarfield Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Solarfield
	:members:

Heliostat Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Heliostat
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Powerblock
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Outputs
	:members:

