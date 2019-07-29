.. _MhkWave:

MhkWave
**************************

Wrapper for SAM Simulation Core model: `cmod_mhk_wave.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_mhk_wave.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**MhkWave model description**

.. automodule:: PySAM.MhkWave
	:members:

Functions
=========================

.. autoclass:: PySAM.MhkWave.MhkWave
	:members:

MHKWave Group
==============

.. autoclass:: PySAM.MhkWave.MhkWave.MHKWave
	:members:

Outputs Group
==============

.. autoclass:: PySAM.MhkWave.MhkWave.Outputs
	:members:

