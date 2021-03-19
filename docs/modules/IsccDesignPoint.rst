.. _IsccDesignPoint:

IsccDesignPoint
***********************************

Wrapper for SAM Simulation Core model: `cmod_iscc_design_point.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_iscc_design_point.cpp>`_

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

**IsccDesignPoint model description**

.. automodule:: PySAM.IsccDesignPoint
	:members:

Functions
===================================

.. autoclass:: PySAM.IsccDesignPoint.IsccDesignPoint
	:members:

Common Group
======================================================

.. autoclass:: PySAM.IsccDesignPoint.IsccDesignPoint.Common
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.IsccDesignPoint.IsccDesignPoint.Outputs
	:members:

