.. _Hcpv:

Hcpv
**************************

Wrapper for SAM Simulation Core model: `cmod_hcpv.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_hcpv.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Hcpv model description**

.. automodule:: PySAM.Hcpv
	:members:

Functions
=========================

.. autoclass:: PySAM.Hcpv.Hcpv
	:members:

SolarResourceData Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.SolarResourceData
	:members:

PVWatts Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.PVWatts
	:members:

HCPVModule Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.HCPVModule
	:members:

InverterCECDatabase Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.InverterCECDatabase
	:members:

HCPVArray Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.HCPVArray
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Hcpv.Hcpv.Outputs
	:members:

