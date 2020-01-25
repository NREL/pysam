.. _Pvwattsv51ts:

Pvwattsv51ts
**************************

Wrapper for SAM Simulation Core model: `cmod_pvwattsv5_1ts.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvwattsv5_1ts.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvwattsv51ts model description**

.. automodule:: PySAM.Pvwattsv51ts
	:members:

Functions
=========================

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts
	:members:

PVWatts Group
==============

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts.PVWatts
	:members:

SystemDesign Group
==============

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts.SystemDesign
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Pvwattsv51ts.Pvwattsv51ts.Outputs
	:members:

