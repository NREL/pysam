.. _Pvwattsv51ts:

Pvwattsv51ts
***********************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv5_1ts.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv5_1ts.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdepedent but the equations accounting for these
interdependencies that enforce consistency among these input parameters are not available in the PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:


Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**Pvwattsv51ts model description**

.. automodule:: PySAM.Pvwattsv51ts
	:members:

Functions
===================================

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts
	:members:

PVWatts Group
======================================================

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts.PVWatts
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts.SystemDesign
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts.Outputs
	:members:

