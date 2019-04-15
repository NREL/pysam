# NREL-PySAM

* Provides a wrapper around the SAM library that groups together the C API functions by technology or financial model into modules.
* Includes error-checking, explicit input and output definition, and conversion between Python data types.
* PySAM modules are compatible with PySSC, which is included as a subpackage. PySSC is the original wrapper used by SAM's code generator.
* Automatically assign default values to input parameters from SAM's default value database.
* Built-in documentation of models and parameters.
* Minimum Python 3.5 for Windows 7 64-bit, MacOSX 10.6, or CentOS 5.

# Set up

Install:
`pip install NREL-PySAM`

Import a technology or financial model:
`import PySAM.<PySAM Module>`

Import PySSC subpackage:
`from PySAM.PySSC import PySSC`

Create a new empty model:
`PySAM.<PySAM Module>.new()`

Create a new model with values assigned from defaults:
`PySAM.<PySAM Module>.default(string option)`

View parameter groups per class and available default values:
`help(model)`

View descriptions of parameters in a group:
`help(model.<group>)`


## Module Names and Descriptions

PySAM Module | SAM Desktop | Description
-------------|-------------|------------
Battwatts | | Simplified battery storage model
Belpe | | Electric load calculator for residential buildings
Biomass | Biomass combustion | Biomass combustion for electricity generation
CashloanModel | | Financial model for residential and commercial behind-the-meter projects
Equpartflip | All Equity Partnership Flip | PPA all equity partnership flip (no debt) financial model
Fuelcell | |
GenericSystem | Generic system | Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input
Geothermal | Geothermal | Geothermal power model for hydrothermal and EGS systems with flash or binary conversion
Hcpv | High concentration PV | Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model
HostDeveloper | Third party ownership - host/developer | Third party ownership with PPA financial model from host and developer perspective
IphToLcoefcr | LCOH Calculator | Calculate levelized cost of heat using fixed charge rate method for industrial process heat models
Lcoefcr | LCOE calculator (FCR method) | Calculate levelized cost of electricity using fixed charge rate method instead of cash flow
Levpartflip | Leveraged Partnership Flip | PPA leveraged partnership flip (with debt) financial model
LinearFresnelDsgIph | Process heat linear direct steam | Linear Fresnel for industrial process heat applications
Pvsamv1 | Photovoltaic (detailed) | Detailed photovoltaic system model with separate components for module and inverter
Pvwattsv5 | Photovoltaic (PVWatts) | PVWatts photovoltaic system model with simple inputs
Pvwattsv5Lifetime | | PVWatts photovoltaic system model for multi-year lifetime analysis
Saleleaseback | PPA sale leaseback (utility) | PPA sale leaseback partnership financial model
Singleowner |  PPA single owner (utility) | PPA single owner financial model
StandAloneBattery | | Detailed battery storage model
Swh | Solar water heating | Solar water heating model for residential and commercial building applications
TcsdirectSteam | CSP power tower direct steam | CSP direct steam power tower model for power generation
Tcsdish | CSP dish Stirling | CSP dish-Stirling model with parameters for SES and WGA-ADDS systems for power generation
TcsgenericSolar | CSP generic model | CSP power system model with solar field characterized using a table of optical efficiency values
Tcsiscc | CSP integrated solar combined cycle | CSP molten salt power tower system with a natural gas combined cycle power plant
TcslinearFresnel | CSP linear Fresnel direct steam | Linear Fresnel model with steam heat transfer fluid for industrial process heat applications
TcsmoltenSalt | CSP power tower molten salt | CSP molten salt power tower for power generation
TcsMSLF | CSP linear Fresnel molten salt | CSP linear Fresnel with molten salt heat transfer fluid for power generation
TcstroughEmpirical | CSP parabolic trough (empirical) | CSP parabolic trough model based on empirically-derived coefficients and equations for power generation
TcstroughPhysical | CSP parabolic trough (physical) | CSP parabolic trough model based on heat transfer and thermodynamic principles for power generation
Thermalrates | | Thermal flat rate structure net revenue calculator
Thirdpartyownership | Third party ownership - host | Third party ownership with PPA or lease agreement financial model from host perspective
TroughPhysicalProcessHeat | Process heat parabolic trough | Parabolic trough for industrial process heat applications
Utilityrate5 | | Retail electricity bill calculator
Windpower | Wind | Wind power system with one or more wind turbines


# To run a case from the SAM GUI:

1. On the drop-down menu for the case, click __Generate code__ then __JSON for inputs__, and export the case inputs to a JSON file.

2. For each SSC compute module required for the simulation (see [Configurations and SSC Compute Modules](#configurations-and-ssc-compute-modules) below), create a new PySSC data table and wrap it with the equivalent PySAM class, releasing memory ownership to the newly created instance. Do not call `PySSC.data_free` on the data passed to the wrap function!

For example, the following code imports the parameters from a JSON file named _genericsystem_case.json_ that was exported from a Generic System-Single Owner case in SAM, creates a PySSC table for the Generic System and Single Owner SSC compute modules, and then wraps each table in the appropriate PySAM class:

```
import json
import PySAM.GenericSystem as GenericSystem
import PySAM.Singleowner as Singleowner
from PySAM.PySSC import *

ssc = PySSC()
with open("genericsystem_case.json") as f:
	dic = json.load(f)
	gs_dat = dict_to_ssc_table(dic, "generic_system")
	so_dat = dict_to_ssc_table(dic, "singleowner")
	gs = GenericSystem.wrap(gs_dat)
	so = Singleowner.wrap(so_dat)
```

3. For each PySAM class, you can export the parameters to separate dictionaries. This allows the data to be loaded later using `assign`.

	```
	help(gs.Plant) # descriptions
	gs_params = gs.export()
	so_params = so.export()
	...
	another_gs = GenericSystem.new()
	another_gs.assign(gs_params)
	another_so = Singleowner.new()
	another_so.assign(so_params)
	```

4. For some compute module input parameters, the SAM graphical user interface (GUI) uses equations to calculate the value of the parameter from special GUI inputs that are not passed to the compute module. Other compute module input parameters are used by more than one compute module in the simulation. In some cases, you may need to write additional code to ensure values for these parameters are correctly assigned. We hope to eliminate the need for this additional code in the future. Until then, you can find the SAM GUI equations in the [runtime/ui folder](https://github.com/NREL/SAM/tree/develop/deploy/runtime/ui), and determine compute module inputs from the [SSC source code](https://github.com/nrel/ssc) or using the SDKtool, available as part of the SAM installation as described on the [SAM SDK web page](https://sam.nrel.gov/sdk).

For example, for the Flat Plate PV-Single Owner configuration, the ground coverage ratio (GCR) is used in two ways: It is an input to the Flat Plate PV compute module for self-shading calculations, and also may be used in GUI equations to calculate the land cost component of the total installed cost input to the Single Owner compute module. If your Python code changes the value of `Pvsamv1.SystemDesign.gcr` to `x`, and you are including land cost `y` in $/acre in your analysis, you need code like the following adapted from the GUI equations in _runtime/ui/PV System Design.txt_ to ensure the change is accounted for in `Singleowner.SystemCosts.total_installed_cost`: 

```
pv.SystemDesign.subarray1_gcr = x
land_area = pv.CECPerformanceModelWithModuleDatabase.cec_area 
	* (pv.SystemDesign.subarray1_nstrings 
	* pv.SystemDesign.subarray1_modules_per_string) / x * 0.0002471  # m^2 to acres

# total_installed_cost = total_direct_cost + permitting_total + engr_total + grid_total + landprep_total + sales_tax_total + land_total
# y = land cost in $/acre
so.SystemCosts.total_installed_cost = cost_without_land + y * land_area
```

For the same Flat Plate PV-Single Owner configuration, an example of an input that is used by both compute modules is `analysis_period`. It is used by the Single Owner module as the number of years for the cash flow, and by the Flat Plate PV model for battery lifecycle calculations.
	
5. To run a simulation, use `execute(verbosity)` where 0 indicates minimal messages and 1 produces log messages. All outputs are available in the Outputs group of a PySAM class.
```
pv.Outputs.export() # as dictionary
```

## Configurations and SSC Compute Modules

A configuration is a combination of compute modules required to model a type of system (performance model) or project (performance model plus financial model).

Configuration | SSC Compute Module(s)
---------------| ------------------------
Battery-None | battery
Biopower-All Equity Partnership Flip | biomass, equpartflip
Biopower-Commercial | biomass, utilityrate5, cashloan
Biopower-LCOE Calculator | biomass, lcoefcr
Biopower-Leveraged Partnership Flip | biomass, levpartflip
Biopower-None | biomass
Biopower-Sale Leaseback | biomass, saleleaseback
Biopower-Single Owner | biomass, singleowner
Dish Stirling-All Equity Partnership Flip | tcsdish, equpartflip
Dish Stirling-Commercial | tcsdish, utilityrate5, cashloan
Dish Stirling-LCOE Calculator | tcsdish, lcoefcr
Dish Stirling-Leveraged Partnership Flip | tcsdish, levpartflip
Dish Stirling-None | tcsdish
Dish Stirling-Sale Leaseback | tcsdish, saleleaseback
Dish Stirling-Single Owner | tcsdish, singleowner
DSGL IPH-LCOH Calculator | linear_fresnel_dsg_iph, iph_to_lcoefcr, lcoefcr
DSGL IPH-None | linear_fresnel_dsg_iph
DSLF-All Equity Partnership Flip | tcslinear_fresnel, equpartflip
DSLF-Commercial | tcslinear_fresnel, utilityrate5, cashloan
DSLF-LCOE Calculator | tcslinear_fresnel, lcoefcr
DSLF-Leveraged Partnership Flip | tcslinear_fresnel, levpartflip
DSLF-None | tcslinear_fresnel
DSLF-Sale Leaseback | tcslinear_fresnel, saleleaseback
DSLF-Single Owner | tcslinear_fresnel, singleowner
DSPT-All Equity Partnership Flip | tcsdirect_steam, equpartflip
DSPT-Leveraged Partnership Flip | tcsdirect_steam, levpartflip
DSPT-Sale Leaseback | tcsdirect_steam, saleleaseback
DSPT-Single Owner | tcsdirect_steam, singleowner
Empirical Trough-All Equity Partnership Flip | tcstrough_empirical, equpartflip
Empirical Trough-Commercial | tcstrough_empirical, utilityrate5, cashloan
Empirical Trough-LCOE Calculator | tcstrough_empirical, lcoefcr
Empirical Trough-Leveraged Partnership Flip | tcstrough_empirical, levpartflip
Empirical Trough-None | tcstrough_empirical
Empirical Trough-Sale Leaseback | tcstrough_empirical, saleleaseback
Empirical Trough-Single Owner | tcstrough_empirical, singleowner
Flat Plate PV-All Equity Partnership Flip | pvsamv1, equpartflip
Flat Plate PV-Commercial | pvsamv1, utilityrate5, cashloan
Flat Plate PV-Host Developer | pvsamv1, utilityrate5, host_developer
Flat Plate PV-LCOE Calculator | pvsamv1, lcoefcr
Flat Plate PV-Leveraged Partnership Flip | pvsamv1, levpartflip
Flat Plate PV-None | pvsamv1
Flat Plate PV-Residential | belpe, pvsamv1, utilityrate5, cashloan
Flat Plate PV-Sale Leaseback | pvsamv1, saleleaseback
Flat Plate PV-Single Owner | pvsamv1, utilityrate5, singleowner
Flat Plate PV-Third Party | belpe, pvsamv1, utilityrate5, thirdpartyownership
Fuel Cell-Commercial | pvwattsv5_lifetime, fuelcell, battery, utilityrate5, thermalrate, cashloan
Fuel Cell-Single Owner | pvwattsv5_lifetime, fuelcell, battery, utilityrate5, thermalrate, singleowner
Generic CSP System-All Equity Partnership Flip | tcsgeneric_solar, equpartflip
Generic CSP System-Commercial | tcsgeneric_solar, utilityrate5, cashloan
Generic CSP System-LCOE Calculator | tcsgeneric_solar, lcoefcr
Generic CSP System-Leveraged Partnership Flip | tcsgeneric_solar, levpartflip
Generic CSP System-None | tcsgeneric_solar
Generic CSP System-Sale Leaseback | tcsgeneric_solar, saleleaseback
Generic CSP System-Single Owner | tcsgeneric_solar, singleowner
Generic System-All Equity Partnership Flip | generic_system, equpartflip
Generic System-Commercial | generic_system, utilityrate5, cashloan
Generic System-Host Developer | generic_system, utilityrate5, host_developer
Generic System-LCOE Calculator | generic_system, lcoefcr
Generic System-Leveraged Partnership Flip | generic_system, levpartflip
Generic System-None | generic_system
Generic System-Residential | generic_system, utilityrate5, cashloan
Generic System-Sale Leaseback | generic_system, saleleaseback
Generic System-Single Owner | generic_system, singleowner
Generic System-Third Party | generic_system, utilityrate5, thirdpartyownership
Geothermal Power-All Equity Partnership Flip | geothermal, equpartflip
Geothermal Power-LCOE Calculator | geothermal, lcoefcr
Geothermal Power-Leveraged Partnership Flip | geothermal, levpartflip
Geothermal Power-None | geothermal
Geothermal Power-Sale Leaseback | geothermal, saleleaseback
Geothermal Power-Single Owner | geothermal, singleowner
High-X Concentrating PV-All Equity Partnership Flip | hcpv, equpartflip
High-X Concentrating PV-LCOE Calculator | hcpv, lcoefcr
High-X Concentrating PV-Leveraged Partnership Flip | hcpv, levpartflip
High-X Concentrating PV-None | hcpv
High-X Concentrating PV-Sale Leaseback | hcpv, saleleaseback
High-X Concentrating PV-Single Owner | hcpv, singleowner
ISCC-Single Owner | tcsiscc, singleowner
MSLF-All Equity Partnership Flip | tcsMSLF, equpartflip
MSLF-Commercial | tcsMSLF, utilityrate5, cashloan
MSLF-LCOE Calculator | tcsMSLF, lcoefcr
MSLF-Leveraged Partnership Flip | tcsMSLF, levpartflip
MSLF-None | tcsMSLF
MSLF-Sale Leaseback | tcsMSLF, saleleaseback
MSLF-Single Owner | tcsMSLF, singleowner
MSPT-All Equity Partnership Flip | tcsmolten_salt, equpartflip
MSPT-Leveraged Partnership Flip | tcsmolten_salt, levpartflip
MSPT-Sale Leaseback | tcsmolten_salt, saleleaseback
MSPT-Single Owner | tcsmolten_salt, singleowner
Physical Trough IPH-LCOH Calculator | trough_physical_process_heat, iph_to_lcoefcr, lcoefcr
Physical Trough IPH-None | trough_physical_process_heat
Physical Trough-All Equity Partnership Flip | tcstrough_physical, equpartflip
Physical Trough-Commercial | tcstrough_physical, utilityrate5, cashloan
Physical Trough-LCOE Calculator | tcstrough_physical, lcoefcr
Physical Trough-Leveraged Partnership Flip | tcstrough_physical, levpartflip
Physical Trough-None | tcstrough_physical
Physical Trough-Sale Leaseback | tcstrough_physical, saleleaseback
Physical Trough-Single Owner | tcstrough_physical, singleowner
PVWatts-All Equity Partnership Flip | pvwattsv5, equpartflip
PVWatts-Commercial | pvwattsv5, battwatts, utilityrate5, cashloan
PVWatts-Host Developer | pvwattsv5, utilityrate5, host_developer
PVWatts-LCOE Calculator | pvwattsv5, lcoefcr
PVWatts-Leveraged Partnership Flip | pvwattsv5, levpartflip
PVWatts-None | pvwattsv5
PVWatts-Residential | pvwattsv5, belpe, battwatts, utilityrate5, cashloan
PVWatts-Sale Leaseback | pvwattsv5, saleleaseback
PVWatts-Single Owner | pvwattsv5, singleowner
PVWatts-Third Party | pvwattsv5, belpe, battwatts, utilityrate5, thirdpartyownership
Solar Water Heating-Commercial | swh, utilityrate5, cashloan
Solar Water Heating-LCOE Calculator | swh, lcoefcr
Solar Water Heating-None | swh
Solar Water Heating-Residential | swh, belpe, utilityrate5, cashloan
Wind Power-All Equity Partnership Flip | windpower, equpartflip
Wind Power-Commercial | windpower, utilityrate5, cashloan
Wind Power-LCOE Calculator | windpower, lcoefcr
Wind Power-Leveraged Partnership Flip | windpower, levpartflip
Wind Power-None | windpower
Wind Power-Residential | windpower, utilityrate5, cashloan
Wind Power-Sale Leaseback | windpower, saleleaseback
Wind Power-Single Owner | windpower, singleowner

# Version 1.0.2, April 15, 2019 ~ SAM 2018.11.11.3, SSC Version 207
* Group all modules under PySAM namespace
* Provide financial defaults per technology
* Include PySSC with dictionary functions as subpackage
* Remove AdjustmentFactors group from non-technology modules
* Fixes custom exception for use with multiprocessing package
* Documentation updates