.. _TcstroughEmpirical:

TcstroughEmpirical
***********************************

Wrapper for SAM Simulation Core model: `cmod_tcstrough_empirical.cpp <https://github.com/NREL/ssc/blob/develop/ssc/cmod_tcstrough_empirical.cpp>`_

Input Consistency Warning
==================================

As described in :ref:`Possible Problems <possible_problems>`, some input parameters are interdependent but the equations 
that enforce consistency are not available in this PySAM module. Therefore,
the onus is on the PySAM user to check that interdependencies are correctly handled. The variables which may require
additional logic include:

 - AntiFrPar
 - BOPPar
 - BOPParPF
 - ChtfPar
 - ChtfParPF
 - ConcFac
 - CtPar
 - CtParPF
 - GeoAcc
 - HCEdust
 - HhtfPar
 - HhtfParPF
 - HtrPar
 - HtrParPF
 - MaxGrOut
 - MinGrOut
 - MirCln
 - MirRef
 - PFSmax
 - PTSmax
 - PTTMAX
 - PTTMIN
 - PbFixPar
 - RefMirrAper
 - SCA_aper
 - SfInTempD
 - SfOutTempD
 - SfPar
 - SfParPF
 - SfPipeHl1
 - SfPipeHl2
 - SfPipeHl3
 - SfPipeHl300
 - Solar_Field_Area
 - Solar_Field_Mult
 - TrkTwstErr
 - TurTesEffAdj
 - TurTesOutAdj
 - TurbEffG
 - TurbOutG
 - system_capacity

Provided for each of these inputs is a list of other inputs that are potentially interdependent. 

Creating an Instance
===================================

Refer to the :ref:`Initializing a Model <initializing>` page for details on the different ways to create an instance of a PySAM class.

**TcstroughEmpirical model description**

.. automodule:: PySAM.TcstroughEmpirical
	:members:

Functions
===================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical
	:members:

Weather Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Weather
	:members:

Trough Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Trough
	:members:

TouTranslator Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.TouTranslator
	:members:

Solarfield Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Solarfield
	:members:

Sca Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Sca
	:members:

Hce Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Hce
	:members:

Pwrb Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Pwrb
	:members:

Tes Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Tes
	:members:

Parasitic Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Parasitic
	:members:

AdjustmentFactors Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.AdjustmentFactors
	:members:

Outputs Group
======================================================

.. autoclass:: PySAM.TcstroughEmpirical.TcstroughEmpirical.Outputs
	:members:

