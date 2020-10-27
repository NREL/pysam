.. _WaveFileReader:

WaveFileReader
***********************************

Wrapper for SAM Simulation Core model: `cmod_wave_file_reader.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wave_file_reader.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**WaveFileReader model description**

.. automodule:: PySAM.WaveFileReader
	:members:

Functions
===================================

.. autoclass:: PySAM.WaveFileReader.WaveFileReader
	:members:

WeatherReader Group
===================================

.. autoclass:: PySAM.WaveFileReader.WaveFileReader.WeatherReader
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.WaveFileReader.WaveFileReader.Outputs
	:members:

