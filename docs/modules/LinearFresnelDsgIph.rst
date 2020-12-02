.. _LinearFresnelDsgIph:

LinearFresnelDsgIph
***********************************

Wrapper for SAM Simulation Core model: `cmod_linear_fresnel_dsg_iph.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_linear_fresnel_dsg_iph.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - I_bn_des
 - T_amb_des_sf
 - T_cold_ref
 - T_hot
 - nLoops
 - nModBoil
 - q_pb_des

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**LinearFresnelDsgIph model description**

.. automodule:: PySAM.LinearFresnelDsgIph
	:members:

Functions
===================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Weather
	:members:

Solarfield Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Solarfield
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Powerblock
	:members:

Heliostat Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Heliostat
	:members:

HeatSink Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.HeatSink
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Outputs
	:members:

