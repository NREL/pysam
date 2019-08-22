.. _Sco2Offdesign:

Sco2Offdesign
**************************

Wrapper for SAM Simulation Core model: `cmod_sco2_offdesign.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_offdesign.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Sco2Offdesign model description**

.. automodule:: PySAM.Sco2Offdesign
	:members:

Functions
=========================

.. autoclass:: PySAM.Sco2Offdesign.Sco2Offdesign
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Sco2Offdesign.Sco2Offdesign.Outputs
	:members:

