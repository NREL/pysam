.. _TcsgenericSolar:

TcsgenericSolar
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcsgeneric_solar.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsgeneric_solar.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - eta_des
 - qsf_des
 - solarm
 - system_capacity
 - w_des

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TcsgenericSolar model description**

.. automodule:: PySAM.TcsgenericSolar
	:members:

Functions
===================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Weather
	:members:

GenericSolar Group
======================================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.GenericSolar
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.TouTranslator
	:members:

Type260 Group
======================================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Type260
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Outputs
	:members:

