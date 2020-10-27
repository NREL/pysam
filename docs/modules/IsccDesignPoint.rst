.. _IsccDesignPoint:

IsccDesignPoint
***********************************

Wrapper for SAM Simulation Core model: `cmod_iscc_design_point.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_iscc_design_point.cpp>`_

Creating an Instance
===================================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**IsccDesignPoint model description**

.. automodule:: PySAM.IsccDesignPoint
	:members:

Functions
===================================

.. autoclass:: PySAM.IsccDesignPoint.IsccDesignPoint
	:members:

Common Group
===================================

.. autoclass:: PySAM.IsccDesignPoint.IsccDesignPoint.Common
	:members:

Outputs Group
===================================

.. autoclass:: PySAM.IsccDesignPoint.IsccDesignPoint.Outputs
	:members:

