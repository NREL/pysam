.. _Fuelcell:

Fuelcell
**************************

Wrapper for SAM Simulation Core model: `cmod_fuelcell.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_fuelcell.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Fuelcell model description**

.. automodule:: PySAM.Fuelcell
	:members:

Functions
=========================

.. autoclass:: PySAM.Fuelcell.Fuelcell
	:members:

Common Group
==============

.. autoclass:: PySAM.Fuelcell.Fuelcell.Common
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Fuelcell.Fuelcell.Lifetime
	:members:

Load Group
==============

.. autoclass:: PySAM.Fuelcell.Fuelcell.Load
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.Fuelcell.Fuelcell.FuelCell
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Fuelcell.Fuelcell.Outputs
	:members:

