.. _Tcsiscc:

Tcsiscc
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcsiscc.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsiscc.cpp>`_

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

**Tcsiscc model description**

.. automodule:: PySAM.Tcsiscc
	:members:

Functions
===================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Weather
	:members:

MoltenSaltTower Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.MoltenSaltTower
	:members:

Heliostat Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Heliostat
	:members:

Receiver Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Receiver
	:members:

Powerblock Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Powerblock
	:members:

Parasitics Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Parasitics
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Outputs
	:members:

