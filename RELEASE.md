# Release Notes

## Version 7.1.0, July 24, 2025 - SAM 2025.4.16 Revision 1, SSC Version 303
* [SAM Release updates for Version 2025.4.16 Revision 1](https://nrel.github.io/SAM/doc/releasenotes.html)

## Version 7.0.0, Apr, 17 2025 - SAM 2025.4.16, SSC Version 302
* [SAM Release updates for Version 2025.4.16](https://nrel.github.io/SAM/doc/releasenotes.html)
* Added GETEM model and equations for Geothermal (#189)
* Fixed AdjustmentFactors to be specific to the module (#188)
* Dropped Python 3.8 support

## Version 6.0.0, Dec 12, 2024 - SAM 2024.12.12, SSC Version 298
* [SAM Release updates for Version 2024.12.12](https://nrel.github.io/SAM/doc/releasenotes.html)
* GenericSystem renamed to CustomGeneration
* Fix attribute error when using "value" on non-existing attribute (#178)
* Added Python 3.13 support

## Version 5.1.0, Mar 13, 2024 - SAM 2023.12.17, Revision 1, SSC Version 290
* [SAM Release updates for Version 2023.12.17 Revision 1](https://nrel.github.io/SAM/doc/releasenotes.html)
* Enable Hybrids in PySAM (#162)

## Version 5.0.0, Dec 13, 2023 - SAM 2023.12.17, SSC Version 288
* [SAM Release updates for Version 2023.12.17](https://nrel.github.io/SAM/doc/releasenotes.html)
* Fix AdjustmentFactors (#158)
* Fix Non-annual Pvwatts simulations (#159)

## Version 4.2.0, June 30, 2023 - SAM 2022.11.21, Revision 3, SSC Version 280
* [SAM Release updates for Version 2022.11.21 Revision 3](https://nrel.github.io/SAM/doc/releasenotes.html)
* Fix support for arm64 and aarch64 (#143, #144)
* Fix URDB v8 function (#145)
* Windpower module example (#148)
* Battery functions for reopt sizing (#149)

## Version 4.1.0, Feb 24, 2023 - SAM 2022.11.21, Revision 1, SSC Version 279
* [SAM Release updates for Version 2022.11.21 Revision 2](https://nrel.github.io/SAM/doc/releasenotes.html)
* Updated Documentation for INOUT variables (#141)
* Added tolerance for Battery sizing tool (#140)
* Add Python 3.11 support

## Version 4.0.0, Dec 10, 2022 - SAM 2022.11.21, SSC Version 278
* [SAM Release updates for Version 2022.11.21](https://nrel.github.io/SAM/doc/releasenotes.html)
* Added LoadTools, URDBv8 support and utility rate fixes (#126, 128)
* License update (#127)
* PySSC modifications for arrays (#125)

## Version 3.0.2, Sep 27, 2022 - SAM 2021.12.02, Revision 2, SSC Version 274
* [SAM Release updates for Version 2021.12.02 Revision 2](https://nrel.github.io/SAM/doc/releasenotes.html)
* Added support for Apple Silicon (#108)

## Version 3.0.1, Mar 4, 2022 - SAM 2021.12.02, Revision 1, SSC Version 268
* [SAM Release updates for Version 2021.12.02 Revision 1](https://nrel.github.io/SAM/doc/releasenotes.html)
* Moved all stub files from NREL-PySAM-stubs package into NREL-PySAM (#109)

## Version 3.0.0, Dec 23, 2021 ~ SAM 2021.12.02, SSC Version 267
* __Warning: Significant changes to Battery and UtilityRate5 Modules, including redefinition of some variables.__
 Please see [SSC Release Notes](https://nrel.github.io/ssc/doc/releasenotes.html) for description of functionality and
 variable changes, and please see "Version Changes" section in [PySAM Documentation](https://nrel-pysam.readthedocs.io/)
 for full list of variable changes.
* Fix FetchResourceFiles's InsecureRequestWarning (#89); html error messages (#94); verbosity (#96)
* Fix SAM_CSV_to_solar_data function missing information (#98)
* Fix URDBv7_to_ElectricityRates error for certain demand structures (#99)
* Add Python 3.10 Support (#104)
* New Example for Selecting Modules and Inverter from the SAM Library (#103)
* [SAM Release updates for Version 2021.12.02](https://nrel.github.io/SAM/doc/releasenotes.html)

## Version 2.2.4, Aug 20, 2021 ~ SAM 2020.11.29, Revision 2, SSC Version 259
* Fix bug in Battery LMO/LTO life model
* Fix a few cost defaults for PV PPA-model configuration
* Clean up PhysicalTroughProcessHeat inputs

## Version 2.2.3, July 22, 2021 ~ SAM 2020.11.29 Revision 2, SSC Version
* Fix ResourceTools solar resource download bug (#86)
* Update Models.rst and module docs
* New analytic battery life model for LMO/LTO chemistry
* Updates and Examples for WaveFileReader (#87)
* Fix bug in 5-min PV files (#88)
* Add `replace` function for Module and Module's Groups (#93)
* [SAM Release updates for Version 2020.11.29 Revision 2](https://nrel.github.io/SAM/doc/releasenotes.html)

## Version 2.2.2, Mar 19, 2021 ~ SAM 2020.11.29 Revision 1, SSC Version 253
* Add `unassign` function to modules (#65)
* Fix mypy errors in stubs (#47)
* Fix BatteryStateful bugs: memory leak; unintialized pointer in some constructors; fix `setup` error messaging (#67)
* BatteryStateful features: ability to use adaptive timestep in simulation; speed up execution; Smith 2017 Life Model
* Voltage cutoff feature for battery model (Battery & BatteryStateful)
* Battery sizing tool can use per-module scaling for surface area (#77)
* Updates to ResourceTools for weather download (#53, #50)
* Leap year 2/29 date is now acceptable
* Fix docs for TcsMoltenSalt (#66)
* Update Import from SAM GUI example to use "PySAM JSON" option in Generate Code
* Better error messaging (#74)
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
