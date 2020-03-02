.. _TcslinearFresnel:

TcslinearFresnel
**************************

Wrapper for SAM Simulation Core model: `cmod_tcslinear_fresnel.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcslinear_fresnel.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TcslinearFresnel model description**

.. automodule:: PySAM.TcslinearFresnel
	:members:

Functions
=========================

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel
	:members:

Weather Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Weather
	:members:

LinearFresnelr Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.LinearFresnelr
	:members:

TouTranslator Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.TouTranslator
	:members:

Solarfield Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Solarfield
	:members:

Heliostat Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Heliostat
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Powerblock
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TcslinearFresnel.TcslinearFresnel.Outputs
	:members:

