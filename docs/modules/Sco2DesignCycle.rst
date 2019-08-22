.. _Sco2DesignCycle:

Sco2DesignCycle
**************************

Wrapper for SAM Simulation Core model: `cmod_sco2_design_cycle.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_sco2_design_cycle.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Sco2DesignCycle model description**

.. automodule:: PySAM.Sco2DesignCycle
	:members:

Functions
=========================

.. autoclass:: PySAM.Sco2DesignCycle.Sco2DesignCycle
	:members:

SCO2PowerCycle Group
==============

.. autoclass:: PySAM.Sco2DesignCycle.Sco2DesignCycle.SCO2PowerCycle
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Sco2DesignCycle.Sco2DesignCycle.Outputs
	:members:

