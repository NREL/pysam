.. _Swh:

Swh
====

.. automodule:: PySAM.Swh
	:members:

Swh is a wrapper for the SSC compute module `cmod_swh.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_swh.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - FRUL

 - FRta

 - area_coll

 - ncoll

 - system_capacity

Functions
-----------

.. autoclass:: PySAM.Swh.Swh
	:members:

SolarResource Group
--------------------

.. autoclass:: PySAM.Swh.Swh.SolarResource
	:members:

SWH Group
----------

.. autoclass:: PySAM.Swh.Swh.SWH
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.Swh.Swh.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Swh.Swh.Outputs
	:members:

