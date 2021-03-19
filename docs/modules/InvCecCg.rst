.. _InvCecCg:

InvCecCg
***********************************

Wrapper for SAM Simulation Core model: `cmod_inv_cec_cg.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_inv_cec_cg.cpp>`_

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

**InvCecCg model description**

.. automodule:: PySAM.InvCecCg
	:members:

Functions
===================================

.. autoclass:: PySAM.InvCecCg.InvCecCg
	:members:

Common Group
======================================================

.. autoclass:: PySAM.InvCecCg.InvCecCg.Common
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.InvCecCg.InvCecCg.Outputs
	:members:

