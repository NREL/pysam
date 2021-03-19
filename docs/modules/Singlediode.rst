.. _Singlediode:

Singlediode
***********************************

Wrapper for SAM Simulation Core model: `cmod_singlediode.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singlediode.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:


Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Singlediode model description**

.. automodule:: PySAM.Singlediode
	:members:

Functions
===================================

.. autoclass:: PySAM.Singlediode.Singlediode
	:members:

SingleDiodeModel Group
======================================================

.. autoclass:: PySAM.Singlediode.Singlediode.SingleDiodeModel
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Singlediode.Singlediode.Outputs
	:members:

