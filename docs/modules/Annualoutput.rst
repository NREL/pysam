.. _Annualoutput:

Annualoutput
**************************

Wrapper for SAM Simulation Core model: `cmod_annualoutput.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_annualoutput.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Annualoutput model description**

.. automodule:: PySAM.Annualoutput
	:members:

Functions
=========================

.. autoclass:: PySAM.Annualoutput.Annualoutput
	:members:

AnnualOutput Group
==============

.. autoclass:: PySAM.Annualoutput.Annualoutput.AnnualOutput
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Annualoutput.Annualoutput.Outputs
	:members:

