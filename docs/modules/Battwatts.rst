.. _Battwatts:

Battwatts
***********************************

Wrapper for SAM Simulation Core model: `cmod_battwatts.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_battwatts.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Battwatts model description**

.. automodule:: PySAM.Battwatts
	:members:

Functions
===================================

.. autoclass:: PySAM.Battwatts.Battwatts
	:members:

Lifetime Group
===================================

.. autoclass:: PySAM.Battwatts.Battwatts.Lifetime
	:members:

Battery Group
===================================

.. autoclass:: PySAM.Battwatts.Battwatts.Battery
	:members:

Load Group
===================================

.. autoclass:: PySAM.Battwatts.Battwatts.Load
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Battwatts.Battwatts.Outputs
	:members:

