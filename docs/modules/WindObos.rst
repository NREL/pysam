.. _WindObos:

WindObos
**************************

Wrapper for SAM Simulation Core model: `cmod_wind_obos.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wind_obos.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**WindObos model description**

.. automodule:: PySAM.WindObos
	:members:

Functions
=========================

.. autoclass:: PySAM.WindObos.WindObos
	:members:

Wobos Group
==============

.. autoclass:: PySAM.WindObos.WindObos.Wobos
	:members:

Outputs Group
==============

.. autoclass:: PySAM.WindObos.WindObos.Outputs
	:members:

