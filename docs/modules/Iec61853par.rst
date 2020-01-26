.. _Iec61853par:

Iec61853par
**************************

Wrapper for SAM Simulation Core model: `cmod_iec61853par.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_iec61853par.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Iec61853par model description**

.. automodule:: PySAM.Iec61853par
	:members:

Functions
=========================

.. autoclass:: PySAM.Iec61853par.Iec61853par
	:members:

IEC61853 Group
==============

.. autoclass:: PySAM.Iec61853par.Iec61853par.IEC61853
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Iec61853par.Iec61853par.Outputs
	:members:

