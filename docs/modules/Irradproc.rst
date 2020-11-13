.. _Irradproc:

Irradproc
***********************************

Wrapper for SAM Simulation Core model: `cmod_irradproc.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_irradproc.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Irradproc model description**

.. automodule:: PySAM.Irradproc
	:members:

Functions
===================================

.. autoclass:: PySAM.Irradproc.Irradproc
	:members:

IrradianceProcessor Group
===================================

.. autoclass:: PySAM.Irradproc.Irradproc.IrradianceProcessor
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Irradproc.Irradproc.Outputs
	:members:

