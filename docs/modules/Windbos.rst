.. _Windbos:

Windbos
***********************************

Wrapper for SAM Simulation Core model: `cmod_windbos.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_windbos.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Windbos model description**

.. automodule:: PySAM.Windbos
	:members:

Functions
===================================

.. autoclass:: PySAM.Windbos.Windbos
	:members:

WindBos Group
===================================

.. autoclass:: PySAM.Windbos.Windbos.WindBos
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Windbos.Windbos.Outputs
	:members:

