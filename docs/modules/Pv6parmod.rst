.. _Pv6parmod:

Pv6parmod
***********************************

Wrapper for SAM Simulation Core model: `cmod_pv6parmod.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pv6parmod.cpp>`_

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

**Pv6parmod model description**

.. automodule:: PySAM.Pv6parmod
	:members:

Functions
===================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.Weather
	:members:

CEC6ParameterPVModuleModel Group
======================================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.CEC6ParameterPVModuleModel
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.Outputs
	:members:

