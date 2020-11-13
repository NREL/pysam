.. _UiTesCalcs:

UiTesCalcs
***********************************

Wrapper for SAM Simulation Core model: `cmod_ui_tes_calcs.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_ui_tes_calcs.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**UiTesCalcs model description**

.. automodule:: PySAM.UiTesCalcs
	:members:

Functions
===================================

.. autoclass:: PySAM.UiTesCalcs.UiTesCalcs
	:members:

Common Group
===================================

.. autoclass:: PySAM.UiTesCalcs.UiTesCalcs.Common
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.UiTesCalcs.UiTesCalcs.Outputs
	:members:

