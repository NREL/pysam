.. _Swh:

Swh
***********************************

Wrapper for SAM Simulation Core model: `cmod_swh.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_swh.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - FRUL
 - FRta
 - area_coll
 - ncoll
 - system_capacity

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Swh model description**

.. automodule:: PySAM.Swh
	:members:

Functions
===================================

.. autoclass:: PySAM.Swh.Swh
	:members:

SolarResource Group
======================================================

.. autoclass:: PySAM.Swh.Swh.SolarResource
	:members:

SWH Group
======================================================

.. autoclass:: PySAM.Swh.Swh.SWH
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Swh.Swh.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Swh.Swh.Outputs
	:members:

