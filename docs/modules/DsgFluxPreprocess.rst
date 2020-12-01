.. _DsgFluxPreprocess:

DsgFluxPreprocess
***********************************

Wrapper for SAM Simulation Core model: `cmod_dsg_flux_preprocess.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_dsg_flux_preprocess.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**DsgFluxPreprocess model description**

.. automodule:: PySAM.DsgFluxPreprocess
	:members:

Functions
===================================

.. autoclass:: PySAM.DsgFluxPreprocess.DsgFluxPreprocess
	:members:

Common Group
===================================

.. autoclass:: PySAM.DsgFluxPreprocess.DsgFluxPreprocess.Common
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.DsgFluxPreprocess.DsgFluxPreprocess.Outputs
	:members:

