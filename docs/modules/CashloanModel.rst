.. _CashloanModel:

Cashloan
**************************

Wrapper for SAM Simulation Core model: `cmod_cashloan.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_cashloan.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**CashloanModel model description**

.. automodule:: PySAM.CashloanModel
	:members:

Functions
=========================

.. autoclass:: PySAM.CashloanModel.CashloanModel
	:members:

FinancialParameters Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.FinancialParameters
	:members:

SystemCosts Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.SystemCosts
	:members:

Depreciation Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.Depreciation
	:members:

TaxCreditIncentives Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.TaxCreditIncentives
	:members:

PaymentIncentives Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.PaymentIncentives
	:members:

Battery Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.Battery
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.FuelCell
	:members:

Cashloan Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.Cashloan
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.SystemOutput
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.Lifetime
	:members:

ThirdPartyOwnership Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.ThirdPartyOwnership
	:members:

Outputs Group
==============

.. autoclass:: PySAM.CashloanModel.CashloanModel.Outputs
	:members:

