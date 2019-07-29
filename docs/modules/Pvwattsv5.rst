.. _Pvwattsv5:

Pvwattsv5
**************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv5.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv5.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvwattsv5 model description**

.. automodule:: PySAM.Pvwattsv5
	:members:

Functions
=========================

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.Lifetime
	:members:

LocationAndResource Group
==============

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.LocationAndResource
	:members:

SystemDesign Group
==============

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.SystemDesign
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Pvwattsv5.Pvwattsv5.Outputs
	:members:

