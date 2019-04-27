.. _Swh:

Swh
**************************

Wrapper for SAM Simulation Core model: `cmod_swh.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_swh.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Swh model description**

.. automodule:: PySAM.Swh
	:members:

Functions
=========================

.. autoclass:: PySAM.Swh.Swh
	:members:

Weather Group
==============

.. autoclass:: PySAM.Swh.Swh.Weather
	:members:

SWH Group
==============

.. autoclass:: PySAM.Swh.Swh.SWH
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Swh.Swh.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Swh.Swh.Outputs
	:members:

