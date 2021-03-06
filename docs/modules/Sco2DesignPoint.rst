.. _Sco2DesignPoint:

Sco2DesignPoint
***********************************

Wrapper for SAM Simulation Core model: `cmod_sco2_design_point.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_design_point.cpp>`_

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

**Sco2DesignPoint model description**

.. automodule:: PySAM.Sco2DesignPoint
	:members:

Functions
===================================

.. autoclass:: PySAM.Sco2DesignPoint.Sco2DesignPoint
	:members:

Common Group
======================================================

.. autoclass:: PySAM.Sco2DesignPoint.Sco2DesignPoint.Common
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Sco2DesignPoint.Sco2DesignPoint.Outputs
	:members:

