.. _Tcsiscc:

Tcsiscc
**************************

Wrapper for SAM Simulation Core model: `cmod_tcsiscc.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcsiscc.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Tcsiscc model description**

.. automodule:: PySAM.Tcsiscc
	:members:

Functions
=========================

.. autoclass:: PySAM.Tcsiscc.Tcsiscc
	:members:

Weather Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Weather
	:members:

MoltenSaltTower Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.MoltenSaltTower
	:members:

Heliostat Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Heliostat
	:members:

Receiver Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Receiver
	:members:

Powerblock Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Powerblock
	:members:

Parasitics Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Parasitics
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Tcsiscc.Tcsiscc.Outputs
	:members:

