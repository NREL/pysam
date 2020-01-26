.. _Solarpilot:

Solarpilot
**************************

Wrapper for SAM Simulation Core model: `cmod_solarpilot.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_solarpilot.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Solarpilot model description**

.. automodule:: PySAM.Solarpilot
	:members:

Functions
=========================

.. autoclass:: PySAM.Solarpilot.Solarpilot
	:members:

SolarPILOT Group
==============

.. autoclass:: PySAM.Solarpilot.Solarpilot.SolarPILOT
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Solarpilot.Solarpilot.Outputs
	:members:

