Documentation here: https://pysam-docs.readthedocs.io/en/latest/

* Provides a wrapper around the SAM library that groups together the C API functions by technology or financial model into modules.
* Includes error-checking, explicit input and output definition, and conversion between Python data types.
* PySAM modules are compatible with PySSC, which is included as a subpackage. PySSC is the original wrapper used by SAM's code generator.
* Automatically assign default values to input parameters from SAM's default value database.
* Built-in documentation of models and parameters.
* Minimum Python 3.5 for Windows 7 64-bit, MacOSX 10.6, or CentOS 5.

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