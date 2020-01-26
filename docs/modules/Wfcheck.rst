.. _Wfcheck:

Wfcheck
**************************

Wrapper for SAM Simulation Core model: `cmod_wfcheck.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wfcheck.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Wfcheck model description**

.. automodule:: PySAM.Wfcheck
	:members:

Functions
=========================

.. autoclass:: PySAM.Wfcheck.Wfcheck
	:members:

WeatherFileChecker Group
==============

.. autoclass:: PySAM.Wfcheck.Wfcheck.WeatherFileChecker
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Wfcheck.Wfcheck.Outputs
	:members:

