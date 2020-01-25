.. _Iec61853interp:

Iec61853interp
**************************

Wrapper for SAM Simulation Core model: `cmod_iec61853interp.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_iec61853interp.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Iec61853interp model description**

.. automodule:: PySAM.Iec61853interp
	:members:

Functions
=========================

.. autoclass:: PySAM.Iec61853interp.Iec61853interp
	:members:

IEC61853 Group
==============

.. autoclass:: PySAM.Iec61853interp.Iec61853interp.IEC61853
	:members:

SingleDiodeModel Group
==============

.. autoclass:: PySAM.Iec61853interp.Iec61853interp.SingleDiodeModel
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Iec61853interp.Iec61853interp.Outputs
	:members:

