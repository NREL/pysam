.. _Solarpilot:

Solarpilot
===========

.. automodule:: PySAM.Solarpilot
	:members:

Solarpilot is a wrapper for the SSC compute module `cmod_solarpilot.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_solarpilot.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.Solarpilot.Solarpilot
	:members:

SolarPILOT Group
-----------------

.. autoclass:: PySAM.Solarpilot.Solarpilot.SolarPILOT
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Solarpilot.Solarpilot.Outputs
	:members:

