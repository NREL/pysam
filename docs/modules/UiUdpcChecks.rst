.. _UiUdpcChecks:

UiUdpcChecks
***********************************

Wrapper for SAM Simulation Core model: `cmod_ui_udpc_checks.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_ui_udpc_checks.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**UiUdpcChecks model description**

.. automodule:: PySAM.UiUdpcChecks
	:members:

Functions
===================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks
	:members:

UserDefinedPowerCycle Group
===================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks.UserDefinedPowerCycle
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.UiUdpcChecks.UiUdpcChecks.Outputs
	:members:

