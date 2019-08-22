.. _Sco2DesignPoint:

Sco2DesignPoint
**************************

Wrapper for SAM Simulation Core model: `cmod_sco2_design_point.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_design_point.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Sco2DesignPoint model description**

.. automodule:: PySAM.Sco2DesignPoint
	:members:

Functions
=========================

.. autoclass:: PySAM.Sco2DesignPoint.Sco2DesignPoint
	:members:

Common Group
==============

.. autoclass:: PySAM.Sco2DesignPoint.Sco2DesignPoint.Common
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Sco2DesignPoint.Sco2DesignPoint.Outputs
	:members:

