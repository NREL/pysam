.. _Tcsdish:

Tcsdish
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcsdish.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsdish.cpp>`_

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

**Tcsdish model description**

.. automodule:: PySAM.Tcsdish
	:members:

Functions
===================================

.. autoclass:: PySAM.Tcsdish.Tcsdish
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Weather
	:members:

Dish Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Dish
	:members:

Type295 Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type295
	:members:

Type296 Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type296
	:members:

Type297 Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type297
	:members:

Type298 Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type298
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Tcsdish.Tcsdish.Outputs
	:members:

