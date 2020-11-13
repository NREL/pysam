.. _Sco2CompCurves:

Sco2CompCurves
***********************************

Wrapper for SAM Simulation Core model: `cmod_sco2_comp_curves.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_comp_curves.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Sco2CompCurves model description**

.. automodule:: PySAM.Sco2CompCurves
	:members:

Functions
===================================

.. autoclass:: PySAM.Sco2CompCurves.Sco2CompCurves
	:members:

Common Group
===================================

.. autoclass:: PySAM.Sco2CompCurves.Sco2CompCurves.Common
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Sco2CompCurves.Sco2CompCurves.Outputs
	:members:

