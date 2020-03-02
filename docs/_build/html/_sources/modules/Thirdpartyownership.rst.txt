.. _Thirdpartyownership:

Thirdpartyownership
**************************

Wrapper for SAM Simulation Core model: `cmod_thirdpartyownership.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_thirdpartyownership.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Thirdpartyownership model description**

.. automodule:: PySAM.Thirdpartyownership
	:members:

Functions
=========================

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership
	:members:

Depreciation Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Depreciation
	:members:

Financials Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Financials
	:members:

FinancialThirdPartyOwnership Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.FinancialThirdPartyOwnership
	:members:

Common Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Common
	:members:

AnnualOutput Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.AnnualOutput
	:members:

CashFlow Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.CashFlow
	:members:

ElectricityCost Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.ElectricityCost
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Thirdpartyownership.Thirdpartyownership.Outputs
	:members:

