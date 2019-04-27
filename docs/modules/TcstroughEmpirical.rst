.. _TcstroughEmpirical:

TcstroughEmpirical
**************************

Wrapper for SAM Simulation Core model: `cmod_tcstrough_empirical.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcstrough_empirical.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**TcstroughEmpirical model description**

.. automodule:: PySAM.TcstroughEmpirical
	:members:

Functions
=========================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical
	:members:

Weather Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Weather
	:members:

Trough Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Trough
	:members:

TouTranslator Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.TouTranslator
	:members:

Solarfield Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Solarfield
	:members:

Sca Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Sca
	:members:

Hce Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Hce
	:members:

Pwrb Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Pwrb
	:members:

Tes Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Tes
	:members:

Parasitic Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Parasitic
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Outputs
	:members:

