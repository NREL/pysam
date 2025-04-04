.. _TcsgenericSolar:

TcsgenericSolar
================

.. automodule:: PySAM.TcsgenericSolar
	:members:

TcsgenericSolar is a wrapper for the SSC compute module `cmod_tcsgeneric_solar.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsgeneric_solar.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

 - eta_des

 - qsf_des

 - solarm

 - system_capacity

 - w_des

Functions
-----------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar
	:members:

Weather Group
--------------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Weather
	:members:

GenericSolar Group
-------------------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.GenericSolar
	:members:

TouTranslator Group
--------------------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.TouTranslator
	:members:

Type260 Group
--------------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Type260
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.AdjustmentFactors
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Outputs
	:members:

