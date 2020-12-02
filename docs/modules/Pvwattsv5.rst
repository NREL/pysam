.. _Pvwattsv5:

Pvwattsv5
***********************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv5.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv5.cpp>`_

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

**Pvwattsv5 model description**

.. automodule:: PySAM.Pvwattsv5
	:members:

Functions
===================================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.Lifetime
	:members:

SolarResource Group
======================================================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.SolarResource
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.SystemDesign
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.Outputs
	:members:

