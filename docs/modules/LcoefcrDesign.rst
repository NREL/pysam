.. _LcoefcrDesign:

LcoefcrDesign
==============

.. automodule:: PySAM.LcoefcrDesign
	:members:

LcoefcrDesign is a wrapper for the SSC compute module `cmod_lcoefcr_design.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_lcoefcr_design.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.LcoefcrDesign.LcoefcrDesign
	:members:

SystemControl Group
--------------------

.. autoclass:: PySAM.LcoefcrDesign.LcoefcrDesign.SystemControl
	:members:

SimpleLCOE Group
-----------------

.. autoclass:: PySAM.LcoefcrDesign.LcoefcrDesign.SimpleLCOE
	:members:

SystemCosts Group
------------------

.. autoclass:: PySAM.LcoefcrDesign.LcoefcrDesign.SystemCosts
	:members:

IPHLCOH Group
--------------

.. autoclass:: PySAM.LcoefcrDesign.LcoefcrDesign.IPHLCOH
	:members:

Outputs Group
--------------

.. autoclass:: PySAM.LcoefcrDesign.LcoefcrDesign.Outputs
	:members:

