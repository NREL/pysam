.. _TcsgenericSolar:

TcsgenericSolar
**************************

Wrapper for SAM Simulation Core model: `cmod_tcsgeneric_solar.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsgeneric_solar.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TcsgenericSolar model description**

.. automodule:: PySAM.TcsgenericSolar
	:members:

Functions
=========================

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar
	:members:

Weather Group
==============

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Weather
	:members:

GenericSolar Group
==============

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.GenericSolar
	:members:

TouTranslator Group
==============

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.TouTranslator
	:members:

Type260 Group
==============

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Type260
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TcsgenericSolar.TcsgenericSolar.Outputs
	:members:

