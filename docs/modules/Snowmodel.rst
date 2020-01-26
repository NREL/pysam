.. _Snowmodel:

Snowmodel
**************************

Wrapper for SAM Simulation Core model: `cmod_snowmodel.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_snowmodel.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Snowmodel model description**

.. automodule:: PySAM.Snowmodel
	:members:

Functions
=========================

.. autoclass:: PySAM.Snowmodel.Snowmodel
	:members:

PVSnowModel Group
==============

.. autoclass:: PySAM.Snowmodel.Snowmodel.PVSnowModel
	:members:

TimeSeries Group
==============

.. autoclass:: PySAM.Snowmodel.Snowmodel.TimeSeries
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Snowmodel.Snowmodel.Outputs
	:members:

