.. _MhkTidal:

MhkTidal
***********************************

Wrapper for SAM Simulation Core model: `cmod_mhk_tidal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_tidal.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - number_devices
 - tidal_power_curve

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**MhkTidal model description**

.. automodule:: PySAM.MhkTidal
	:members:

Functions
===================================

.. autoclass:: PySAM.MhkTidal.MhkTidal
	:members:

MHKTidal Group
======================================================

.. autoclass:: PySAM.MhkTidal.MhkTidal.MHKTidal
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.MhkTidal.MhkTidal.Outputs
	:members:

