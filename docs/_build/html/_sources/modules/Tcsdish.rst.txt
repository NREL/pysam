.. _Tcsdish:

Tcsdish
**************************

Wrapper for SAM Simulation Core model: `cmod_tcsdish.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsdish.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Tcsdish model description**

.. automodule:: PySAM.Tcsdish
	:members:

Functions
=========================

.. autoclass:: PySAM.Tcsdish.Tcsdish
	:members:

Weather Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Weather
	:members:

Dish Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Dish
	:members:

Type295 Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type295
	:members:

Type296 Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type296
	:members:

Type297 Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type297
	:members:

Type298 Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Type298
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Tcsdish.Tcsdish.Outputs
	:members:

