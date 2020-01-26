.. _Layoutarea:

Layoutarea
**************************

Wrapper for SAM Simulation Core model: `cmod_layoutarea.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_layoutarea.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Layoutarea model description**

.. automodule:: PySAM.Layoutarea
	:members:

Functions
=========================

.. autoclass:: PySAM.Layoutarea.Layoutarea
	:members:

Common Group
==============

.. autoclass:: PySAM.Layoutarea.Layoutarea.Common
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Layoutarea.Layoutarea.Outputs
	:members:

