.. _Biomass:

Biomass
========

.. automodule:: PySAM.Biomass
	:members:

Biomass is a wrapper for the SSC compute module `cmod_biomass.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_biomass.cpp>`_

Interdependent Variables
--------------------------

The variables listed below are interdependent with other variables. If you change the value of one of these variables, you may need to change values of other variables. The SAM user interface manages these interdependent variables, but in PySAM, it is up to you change the value of all interdependent variables so they are consistent. See :doc:`../interdependent-variables` for examples and details.

- None

Functions
-----------

.. autoclass:: PySAM.Biomass.Biomass
	:members:

Biopower Group
---------------

.. autoclass:: PySAM.Biomass.Biomass.Biopower
	:members:

AdjustmentFactors Group
------------------------

.. autoclass:: PySAM.AdjustmentFactors.AdjustmentFactors
	:members:
	:noindex:

Outputs Group
--------------

.. autoclass:: PySAM.Biomass.Biomass.Outputs
	:members:

