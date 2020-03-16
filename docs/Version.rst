.. Version:

Version 2.0.2
*************

Jan 27, 2020 ~ SAM 2020.2.x, SSC Version 233

* All new functions and models in `latest SAM Release <https://nrel.github.io/SAM/doc/releasenotes.html>`_
    - Switched from PVwattsv5 to PVwattsv7
* New functions (Reopt_size_batter_post, value, from_existing)
    - Chaining cmods together
    - Get variable by a name without knowing group, list all variables
* New Tools section (BatteryTools, ResourceTools)
    - Easy way to create wind or solar data
    - Battery sizing
* All compute modules to PySAM
* Major reorganization of variable groups
* Bug fixes
    - fopen defaults
    - turbine powercurve
* Documentation features
    - Downstream and upstream variable suggestions
    - Examples page


Compatibility Issues Upgrading to 2.0
*************************************

In Version 2.0, there is major reorganization of variable groups within most financial, PV, and Battery modules. This is
part of an effort to make the grouping more logical by having fewer groups per module and with groups more consistent
across modules. The group organization should stabilize after this version.

But it represents a compatibility issue with older versions using different group names and memberships.


Older Versions
**************
Version 1.2.dev3, August 21, 2019 ~ SAM 2018.11.11.3, SSC Version 211

* Wind PRUF framework
* Wind resource distribution
* Physical Trough reorganization
* Grid compute module
* Marine hydrokinetic compute module
* Supercritical CO2 compute modules
* Geothermal output names
* Battwatts fix
* Documentation: Variable requirement
* Stubs: Added AdjustmentmentFactors

Version 1.2.1, April 26, 2019 ~ SAM 2018.11.11.3, SSC Version 209

* SSC using doubles
* Tcs_moltensalt RADCOOL group
* Stub files and .rst files for readthedocs
* Documentation updates

Version 1.1, April 15, 2019 ~ SAM 2018.11.11.3, SSC Version 208

* Group all modules under PySAM namespace
* Defaults for technology and financial models according to SAM GUI configurations
* Include PySSC with dictionary functions as subpackage
* Remove AdjustmentFactors group from non-technology modules
* Fix custom exception for use with multiprocessing package
* Documentation updates
