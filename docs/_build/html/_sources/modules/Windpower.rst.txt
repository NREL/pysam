.. _Windpower:

Windpower Module
**************************

Wrapper for SAM Simulation Core model: `cmod_windpower.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_windpower.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`PySSC`.

**Windpower model description**

.. automodule:: PySAM.Windpower
	:members:

Functions
=========================

.. autoclass:: PySAM.Windpower.Windpower
	:members:

WindResourceFile Group
==============

.. autoclass:: PySAM.Windpower.Windpower.WindResourceFile
	:members:

WindTurbine Group
==============

.. autoclass:: PySAM.Windpower.Windpower.WindTurbine
	:members:

WindFarm Group
==============

.. autoclass:: PySAM.Windpower.Windpower.WindFarm
	:members:

WindPower Group
==============

.. autoclass:: PySAM.Windpower.Windpower.WindPower
	:members:

WindSpeedWeibullDistribution Group
==============

.. autoclass:: PySAM.Windpower.Windpower.WindSpeedWeibullDistribution
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Windpower.Windpower.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Windpower.Windpower.Outputs
	:members:

