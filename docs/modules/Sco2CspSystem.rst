.. _Sco2CspSystem:

Sco2CspSystem
**************************

Wrapper for SAM Simulation Core model: `cmod_sco2_csp_system.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_csp_system.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Sco2CspSystem model description**

.. automodule:: PySAM.Sco2CspSystem
	:members:

Functions
=========================

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem
	:members:

SystemDesign Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.SystemDesign
	:members:

HeatExchangerDesign Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.HeatExchangerDesign
	:members:

CycleDesign Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.CycleDesign
	:members:

PHXDesign Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.PHXDesign
	:members:

AirCoolerDesign Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.AirCoolerDesign
	:members:

OffDesignInputs Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.OffDesignInputs
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Sco2CspSystem.Sco2CspSystem.Outputs
	:members:

