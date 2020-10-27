.. _Pvwattsv1Poa:

Pvwattsv1Poa
***********************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv1_poa.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv1_poa.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvwattsv1Poa model description**

.. automodule:: PySAM.Pvwattsv1Poa
	:members:

Functions
===================================

.. autoclass:: PySAM.Pvwattsv1Poa.Pvwattsv1Poa
	:members:

Weather Group
===================================

.. autoclass:: PySAM.Pvwattsv1Poa.Pvwattsv1Poa.Weather
	:members:

PVWatts Group
===================================

.. autoclass:: PySAM.Pvwattsv1Poa.Pvwattsv1Poa.PVWatts
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Pvwattsv1Poa.Pvwattsv1Poa.Outputs
	:members:

