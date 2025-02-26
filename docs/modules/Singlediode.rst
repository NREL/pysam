.. _Singlediode:

Singlediode
============

.. automodule:: PySAM.Singlediode
	:members:

Singlediode is a wrapper for the SSC compute module `cmod_singlediode.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_singlediode.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.Singlediode.Singlediode
	:members:

SingleDiodeModel Group
-----------------------

.. autoclass:: PySAM.Singlediode.Singlediode.SingleDiodeModel
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.Singlediode.Singlediode.Outputs
	:members:

