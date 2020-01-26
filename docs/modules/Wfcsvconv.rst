.. _Wfcsvconv:

Wfcsvconv
**************************

Wrapper for SAM Simulation Core model: `cmod_wfcsvconv.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wfcsvconv.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Wfcsvconv model description**

.. automodule:: PySAM.Wfcsvconv
	:members:

Functions
=========================

.. autoclass:: PySAM.Wfcsvconv.Wfcsvconv
	:members:

WeatherFileConverter Group
==============

.. autoclass:: PySAM.Wfcsvconv.Wfcsvconv.WeatherFileConverter
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Wfcsvconv.Wfcsvconv.Outputs
	:members:

