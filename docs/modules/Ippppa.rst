.. _Ippppa:

Ippppa
**************************

Wrapper for SAM Simulation Core model: `cmod_ippppa.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_ippppa.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Ippppa model description**

.. automodule:: PySAM.Ippppa
	:members:

Functions
=========================

.. autoclass:: PySAM.Ippppa.Ippppa
	:members:

FinancialParameters Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.FinancialParameters
	:members:

SystemCosts Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.SystemCosts
	:members:

Depreciation Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.Depreciation
	:members:

TaxCreditIncentives Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.TaxCreditIncentives
	:members:

PaymentIncentives Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.PaymentIncentives
	:members:

Common Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.Common
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Ippppa.Ippppa.Outputs
	:members:

