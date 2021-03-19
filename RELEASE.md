# Release Notes

## Version 2.2.1,
* Add `unassign` function to modules
* Fix mypy errors in stubs
* Fix BatteryStateful bugs: memory leak; unintialized pointer in some constructors; fix `setup` error messaging
* BatteryStateful features: ability to use adaptive timestep in simulation; speed up execution; Smith 2017 Life Model
* Voltage cutoff feature for battery model (Battery & BatteryStateful)
* Fix docs for TcsMoltenSalt
* Leap year 2/29 date is now acceptable
* [SAM Release updates for Version 2020.11.29 Revision 1](https://nrel.github.io/SAM/doc/releasenotes.html)

## Version 2.2.0, Dec 2, 2020 ~ SAM 2020.11.29, SSC Version 250
* [SAM Release updates for Version 2020.11.29](https://nrel.github.io/SAM/doc/releasenotes.html)
* Rename StandAloneBattery to Battery
* New module: BatteryStateful with 3 defaults: NMCGraphite, LFPGraphite, LeadAcid
* BatteryTools functions for switching chemistries
* Update Docs to show list of interdependent variables at beginning
* All changes from 2.1.5.devx versions
* First PySAM package for Python 3.9

## Version 2.1.5.dev3, Sep 3, 2020 ~ SAM 2020.2.29 r3, SSC Version 242
* Price Signals Dispatch
* Bug fix in PVWattsBatteryCommercial and PVBatteryCommercial incentives defaults

## Version 2.1.5.dev2, Aug 10, 2020 ~ SAM 2020.2.29 r3, SSC Version 242
* BatteryStateful bug fixes: current

## Version 2.1.5.dev1, Aug 3, 2020 ~ SAM 2020.2.29 r3, SSC Version 242
* BatteryStateful bug fixes: thermal, voltage
* Stub files syntax fix

## Version 2.1.5, July 7, 2020 ~ SAM 2020.2.29 r2, SSC Version 240
* Updates to enable non-annual (single timestep or multiple, non-8760 timestep) simulations via weather input data
(NOT weather files) for both pvsamv1 and pvwattsv7
* Vanadium Redox Flow battery bug fix
* Transformer loss units bug fix

## Version 2.1.4, June 8, 2020 ~ SAM 2020.2.29 r2, SSC Version 240
* Pvwattsv5_1ts bug fix
* Self-shading calculation speed-up for Pvwattsv7, Pvsamv1 & Pvwattsv5

## Version 2.1.3, May 29, 2020 ~ SAM 2020.2.29 r2, SSC Version 240
* [SAM Release fixes for revision 2](https://nrel.github.io/SAM/doc/releasenotes.html)

## Version 2.1.1, May 15, 2020 ~ SAM 2020.2.29 r1, SSC Version 238
* reopt size post bug
* ssc_sim_from_dict bug fix
* Version attribute: `PySAM.__version__`
* URDBv7 in ResourceTools bug fix
* ResourceFetcher for WindToolKit and National Solar Radiation Database downloads
* case-insensitive default configuration names
* Generic Exception replaces PySAM.Error for easier MP debugging

## Version 2.0.2, Jan 27, 2020 ~ SAM 2020.2.x, SSC Version 233

* All new functions and models in latest SAM Release
* New functions (Reopt_size_batter_post, value, from_existing)
* Chaining cmods together
* Get variable by a name without knowing group, list all variables
* New Tools section (BatteryTools, ResourceTools)
* Easy way to create wind or solar data
* Battery sizing
* All compute modules to PySAM
* Major reorganization of variable groups
* Bug fixes
* fopen defaults
* turbine powercurve
* Documentation features
* Downstream and upstream variable suggestions
* Examples page

## Version 1.2.dev3, August 21, 2019 ~ SAM 2018.11.11.3, SSC Version 211
* Wind PRUF framework
* Wind resource distribution
* Physical Trough reorganization
* Grid compute module
* Marine hydrokinetic compute module
* Supercritical CO2 compute modules
* Geothermal output names
* Documentation: Variable requirement
* Stubs: Added AdjustmentmentFactors

## Version 1.2.1, April 26, 2019 ~ SAM 2018.11.11.3, SSC Version 209
* SSC using doubles
* Tcs_moltensalt RADCOOL group
* Stub files and .rst files for readthedocs
* Documentation updates

## Version 1.1, April 15, 2019 ~ SAM 2018.11.11.3, SSC Version 208
* Group all modules under PySAM namespace
* Defaults for technology and financial models according to SAM GUI configurations
* Include PySSC with dictionary functions as subpackage
* Remove AdjustmentFactors group from non-technology modules
* Fix custom exception for use with multiprocessing package
* Documentation updates
