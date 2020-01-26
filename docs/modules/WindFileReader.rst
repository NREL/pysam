.. _WindFileReader:

WindFileReader
**************************

Wrapper for SAM Simulation Core model: `cmod_wind_file_reader.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wind_file_reader.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**WindFileReader model description**

.. automodule:: PySAM.WindFileReader
	:members:

Functions
=========================

.. autoclass:: PySAM.WindFileReader.WindFileReader
	:members:

WeatherReader Group
==============

.. autoclass:: PySAM.WindFileReader.WindFileReader.WeatherReader
	:members:

Outputs Group
==============

.. autoclass:: PySAM.WindFileReader.WindFileReader.Outputs
	:members:

