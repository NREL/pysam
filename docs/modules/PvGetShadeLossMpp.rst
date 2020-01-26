.. _PvGetShadeLossMpp:

PvGetShadeLossMpp
**************************

Wrapper for SAM Simulation Core model: `cmod_pv_get_shade_loss_mpp.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pv_get_shade_loss_mpp.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**PvGetShadeLossMpp model description**

.. automodule:: PySAM.PvGetShadeLossMpp
	:members:

Functions
=========================

.. autoclass:: PySAM.PvGetShadeLossMpp.PvGetShadeLossMpp
	:members:

PVShadeLossDB Group
==============

.. autoclass:: PySAM.PvGetShadeLossMpp.PvGetShadeLossMpp.PVShadeLossDB
	:members:

Outputs Group
==============

.. autoclass:: PySAM.PvGetShadeLossMpp.PvGetShadeLossMpp.Outputs
	:members:

