.. _CbConstructionFinancing:

CbConstructionFinancing
***********************************

Wrapper for SAM Simulation Core model: `cmod_cb_construction_financing.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_cb_construction_financing.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**CbConstructionFinancing model description**

.. automodule:: PySAM.CbConstructionFinancing
	:members:

Functions
===================================

.. autoclass:: PySAM.CbConstructionFinancing.CbConstructionFinancing
	:members:

SystemCosts Group
===================================

.. autoclass:: PySAM.CbConstructionFinancing.CbConstructionFinancing.SystemCosts
	:members:

FinancialParameters Group
===================================

.. autoclass:: PySAM.CbConstructionFinancing.CbConstructionFinancing.FinancialParameters
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.CbConstructionFinancing.CbConstructionFinancing.Outputs
	:members:

