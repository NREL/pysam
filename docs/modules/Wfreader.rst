.. _Wfreader:

Wfreader
***********************************

Wrapper for SAM Simulation Core model: `cmod_wfreader.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_wfreader.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Wfreader model description**

.. automodule:: PySAM.Wfreader
	:members:

Functions
===================================

.. autoclass:: PySAM.Wfreader.Wfreader
	:members:

WeatherReader Group
===================================

.. autoclass:: PySAM.Wfreader.Wfreader.WeatherReader
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Wfreader.Wfreader.Outputs
	:members:

