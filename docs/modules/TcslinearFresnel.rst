.. _TcslinearFresnel:

TcslinearFresnel
=================

.. automodule:: PySAM.TcslinearFresnel
	:members:

TcslinearFresnel is a wrapper for the SSC compute module `cmod_tcslinear_fresnel.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcslinear_fresnel.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

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

Functions
-----------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel
	:members:

Weather Group
--------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Weather
	:members:

LinearFresnelr Group
---------------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.LinearFresnelr
	:members:

TouTranslator Group
--------------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.TouTranslator
	:members:

Solarfield Group
-----------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Solarfield
	:members:

Heliostat Group
----------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Heliostat
	:members:

Powerblock Group
-----------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Powerblock
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Outputs
	:members:

