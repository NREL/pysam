.. _LinearFresnelDsgIph:

LinearFresnelDsgIph
**************************

Wrapper for SAM Simulation Core model: `cmod_linear_fresnel_dsg_iph.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_linear_fresnel_dsg_iph.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**LinearFresnelDsgIph model description**

.. automodule:: PySAM.LinearFresnelDsgIph
	:members:

Functions
=========================

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph
	:members:

Weather Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Weather
	:members:

Solarfield Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Solarfield
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Powerblock
	:members:

Heliostat Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Heliostat
	:members:

HeatSink Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.HeatSink
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.LinearFresnelDsgIph.LinearFresnelDsgIph.Outputs
	:members:

