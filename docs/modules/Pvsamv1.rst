.. _Pvsamv1:

Pvsamv1
**************************

Wrapper for SAM Simulation Core model: `cmod_pvsamv1.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_pvsamv1.cpp>`_

Creating an Instance
=========================

There are three methods to create a new instance of a PySAM module. Using ``default`` populates the newclass' attributes with default values specific to a ``config``. Each technology-financialconfiguration corresponds to a SAM GUI configuration. Using ``new`` creates an instance with empty attributes. The ``wrap`` function allows compatibility with PySSC, for details, refer to :doc:`../PySSC`.

**Pvsamv1 model description**

.. automodule:: PySAM.Pvsamv1
	:members:

Functions
=========================

.. autoclass:: PySAM.Pvsamv1.Pvsamv1
	:members:

SolarResource Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SolarResource
	:members:

Losses Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Losses
	:members:

Lifetime Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Lifetime
	:members:

SystemDesign Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SystemDesign
	:members:

Shading Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Shading
	:members:

Layout Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Layout
	:members:

Module Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Module
	:members:

SimpleEfficiencyModuleModel Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SimpleEfficiencyModuleModel
	:members:

CECPerformanceModelWithModuleDatabase Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.CECPerformanceModelWithModuleDatabase
	:members:

CECPerformanceModelWithUserEnteredSpecifications Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.CECPerformanceModelWithUserEnteredSpecifications
	:members:

SandiaPVArrayPerformanceModelWithModuleDatabase Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.SandiaPVArrayPerformanceModelWithModuleDatabase
	:members:

IEC61853SingleDiodeModel Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.IEC61853SingleDiodeModel
	:members:

MermoudLejeuneSingleDiodeModel Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.MermoudLejeuneSingleDiodeModel
	:members:

Inverter Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Inverter
	:members:

InverterCECDatabase Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterCECDatabase
	:members:

InverterCECCoefficientGenerator Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterCECCoefficientGenerator
	:members:

InverterDatasheet Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterDatasheet
	:members:

InverterPartLoadCurve Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterPartLoadCurve
	:members:

InverterMermoudLejeuneModel Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.InverterMermoudLejeuneModel
	:members:

Battery Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Battery
	:members:

Simulation Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Simulation
	:members:

Common Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Common
	:members:

PV Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.PV
	:members:

FuelCell Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.FuelCell
	:members:

ElectricityRate Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.ElectricityRate
	:members:

TimeOfDelivery Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.TimeOfDelivery
	:members:

AdjustmentFactors Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.AdjustmentFactors
	:members:

Outputs Group
==============

.. autoclass:: PySAM.Pvsamv1.Pvsamv1.Outputs
	:members:

