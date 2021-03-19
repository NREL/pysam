.. _TroughPhysicalCspSolver:

TroughPhysicalCspSolver
***********************************

Wrapper for SAM Simulation Core model: `cmod_trough_physical_csp_solver.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_trough_physical_csp_solver.cpp>`_

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

**TroughPhysicalCspSolver model description**

.. automodule:: PySAM.TroughPhysicalCspSolver
	:members:

Functions
===================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.Weather
	:members:

Trough Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.Trough
	:members:

TimeOfDelivery Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.TimeOfDelivery
	:members:

SolarField Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.SolarField
	:members:

Controller Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.Controller
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.TouTranslator
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.Powerblock
	:members:

UserDefinedPC Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.UserDefinedPC
	:members:

Enet Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.Enet
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TroughPhysicalCspSolver.TroughPhysicalCspSolver.Outputs
	:members:

