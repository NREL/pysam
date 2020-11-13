.. _Pv6parmod:

Pv6parmod
***********************************

Wrapper for SAM Simulation Core model: `cmod_pv6parmod.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pv6parmod.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pv6parmod model description**

.. automodule:: PySAM.Pv6parmod
	:members:

Functions
===================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod
	:members:

Weather Group
===================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.Weather
	:members:

CEC6ParameterPVModuleModel Group
===================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.CEC6ParameterPVModuleModel
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.Pv6parmod.Pv6parmod.Outputs
	:members:

