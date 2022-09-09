.. _Utilityrateforecast:

Utilityrateforecast
***********************************

Wrapper for SAM Simulation Core model: `cmod_utilityrateforecast.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_utilityrateforecast.cpp>`_

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

**Utilityrateforecast model description**

.. automodule:: PySAM.Utilityrateforecast
	:members:

Functions
===================================

.. autoclass:: PySAM.Utilityrateforecast.Utilityrateforecast
	:members:

ElectricityRates Group
======================================================

.. autoclass:: PySAM.Utilityrateforecast.Utilityrateforecast.ElectricityRates
	:members:

Lifetime Group
======================================================

.. autoclass:: PySAM.Utilityrateforecast.Utilityrateforecast.Lifetime
	:members:

Controls Group
======================================================

.. autoclass:: PySAM.Utilityrateforecast.Utilityrateforecast.Controls
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Utilityrateforecast.Utilityrateforecast.Outputs
	:members:

