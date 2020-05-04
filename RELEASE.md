Documentation here: https://nrel-pysam.readthedocs.io

* Provides a wrapper around the SAM library that groups together the C API functions by technology or financial model into modules.
* Includes error-checking, explicit input and output definition, and conversion between Python data types.
* PySAM modules are compatible with PySSC, which is included as a subpackage. PySSC is the original wrapper used by SAM's code generator.
* Automatically assign default values to input parameters from SAM's default value database.
* Built-in documentation of models and parameters.
* Minimum Python 3.5 for Windows 7 64-bit, MacOSX 10.6, or CentOS 5.

## Version 2.1.dev0
* BatteryStateful module
* Battery model fixes
* SAM Release fixes
	- battery bug
	- reopt size post bug
	? solar_resource_data
	- bifacial bug
* ssc_sim_from_dict bug fix
? Version attribute
* URDBv7 in ResourceTools (more units)
? case-insensitive default names
? missing windows defaults
? Mac wind error

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
