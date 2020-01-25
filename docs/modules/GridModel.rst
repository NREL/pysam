.. _GridModel:

Grid
**************************

Wrapper for SAM Simulation Core model: `cmod_grid.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_grid.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**GridModel model description**

.. automodule:: PySAM.GridModel
	:members:

Functions
=========================

.. autoclass:: PySAM.GridModel.GridModel
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.GridModel.GridModel.Lifetime
	:members:

Grid Group
==============

.. autoclass:: PySAM.GridModel.GridModel.Grid
	:members:

SystemOutput Group
==============

.. autoclass:: PySAM.GridModel.GridModel.SystemOutput
	:members:

Load Group
==============

.. autoclass:: PySAM.GridModel.GridModel.Load
	:members:

Common Group
==============

.. autoclass:: PySAM.GridModel.GridModel.Common
	:members:

LossAdjustments Group
==============

.. autoclass:: PySAM.GridModel.GridModel.LossAdjustments
	:members:

Outputs Group
==============

.. autoclass:: PySAM.GridModel.GridModel.Outputs
	:members:

