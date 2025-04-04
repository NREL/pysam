.. _LinearFresnelDsgIph:

LinearFresnelDsgIph
====================

.. automodule:: PySAM.LinearFresnelDsgIph
	:members:

LinearFresnelDsgIph is a wrapper for the SSC compute module `cmod_linear_fresnel_dsg_iph.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_linear_fresnel_dsg_iph.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - I_bn_des

 - P_turb_des

 - T_amb_des_sf

 - T_cold_ref

 - deltaT_subcooled

 - nLoops

 - nModBoil

 - q_pb_des

 - use_quality_or_subcooled

Functions
-----------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph
	:members:

Weather Group
--------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Weather
	:members:

Solarfield Group
-----------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Solarfield
	:members:

Powerblock Group
-----------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Powerblock
	:members:

Heliostat Group
----------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Heliostat
	:members:

HeatSink Group
---------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.HeatSink
	:members:

Revenue Group
--------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Revenue
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Outputs
	:members:

