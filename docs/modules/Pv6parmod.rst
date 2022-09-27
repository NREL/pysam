.. _Pv6parmod:

Pv6parmod
==========

.. automodule:: PySAM.Pv6parmod
	:members:

Pv6parmod is a wrapper for the SSC compute module `cmod_pv6parmod.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pv6parmod.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.Pv6parmod.Pv6parmod
	:members:

Weather Group
--------------

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.Weather
	:members:

CEC6ParameterPVModuleModel Group
---------------------------------

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.CEC6ParameterPVModuleModel
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.Outputs
	:members:

