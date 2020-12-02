.. _Sco2CspSystem:

Sco2CspSystem
***********************************

Wrapper for SAM Simulation Core model: `cmod_sco2_csp_system.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_csp_system.cpp>`_

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

**Sco2CspSystem model description**

.. automodule:: PySAM.Sco2CspSystem
	:members:

Functions
===================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem
	:members:

SystemDesign Group
======================================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.SystemDesign
	:members:

HeatExchangerDesign Group
======================================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.HeatExchangerDesign
	:members:

Common Group
======================================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.Common
	:members:

PHXDesign Group
======================================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.PHXDesign
	:members:

AirCoolerDesign Group
======================================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.AirCoolerDesign
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.Outputs
	:members:

