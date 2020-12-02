.. _Iec61853interp:

Iec61853interp
***********************************

Wrapper for SAM Simulation Core model: `cmod_iec61853interp.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_iec61853interp.cpp>`_

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

**Iec61853interp model description**

.. automodule:: PySAM.Iec61853interp
	:members:

Functions
===================================

.. autoclass:: PySAM.Iec61853interp.Iec61853interp
	:members:

IEC61853 Group
======================================================

.. autoclass:: PySAM.Iec61853interp.Iec61853interp.IEC61853
	:members:

SingleDiodeModel Group
======================================================

.. autoclass:: PySAM.Iec61853interp.Iec61853interp.SingleDiodeModel
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Iec61853interp.Iec61853interp.Outputs
	:members:

