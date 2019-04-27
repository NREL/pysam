.. _Biomass:

Biomass
**************************

Wrapper for SAM Simulation Core model: `cmod_biomass.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_biomass.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Biomass model description**

.. automodule:: PySAM.Biomass
	:members:

Functions
=========================

.. autoclass:: PySAM.Biomass.Biomass
	:members:

Biopower Group
==============

.. autoclass:: PySAM.Biomass.Biomass.Biopower
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Biomass.Biomass.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Biomass.Biomass.Outputs
	:members:

