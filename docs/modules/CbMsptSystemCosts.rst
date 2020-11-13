.. _CbMsptSystemCosts:

CbMsptSystemCosts
***********************************

Wrapper for SAM Simulation Core model: `cmod_cb_mspt_system_costs.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_cb_mspt_system_costs.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**CbMsptSystemCosts model description**

.. automodule:: PySAM.CbMsptSystemCosts
	:members:

Functions
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts
	:members:

Heliostat Group
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts.Heliostat
	:members:

SystemCosts Group
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts.SystemCosts
	:members:

Receiver Group
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts.Receiver
	:members:

TES Group
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts.TES
	:members:

SystemDesign Group
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts.SystemDesign
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.CbMsptSystemCosts.CbMsptSystemCosts.Outputs
	:members:

