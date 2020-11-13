.. _Sco2AirCooler:

Sco2AirCooler
***********************************

Wrapper for SAM Simulation Core model: `cmod_sco2_air_cooler.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_air_cooler.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Sco2AirCooler model description**

.. automodule:: PySAM.Sco2AirCooler
	:members:

Functions
===================================

.. autoclass:: PySAM.Sco2AirCooler.Sco2AirCooler
	:members:

Common Group
===================================

.. autoclass:: PySAM.Sco2AirCooler.Sco2AirCooler.Common
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Sco2AirCooler.Sco2AirCooler.Outputs
	:members:

