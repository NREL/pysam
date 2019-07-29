.. _MhkTidal:

MhkTidal
**************************

Wrapper for SAM Simulation Core model: `cmod_mhk_tidal.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_tidal.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**MhkTidal model description**

.. automodule:: PySAM.MhkTidal
	:members:

Functions
=========================

.. autoclass:: PySAM.MhkTidal.MhkTidal
	:members:

MHKTidal Group
==============

.. autoclass:: PySAM.MhkTidal.MhkTidal.MHKTidal
	:members:

Outputs Group
==============

.. autoclass:: PySAM.MhkTidal.MhkTidal.Outputs
	:members:

