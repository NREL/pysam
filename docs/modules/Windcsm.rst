.. _Windcsm:

Windcsm
***********************************

Wrapper for SAM Simulation Core model: `cmod_windcsm.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_windcsm.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Windcsm model description**

.. automodule:: PySAM.Windcsm
	:members:

Functions
===================================

.. autoclass:: PySAM.Windcsm.Windcsm
	:members:

WindCsm Group
===================================

.. autoclass:: PySAM.Windcsm.Windcsm.WindCsm
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Windcsm.Windcsm.Outputs
	:members:

