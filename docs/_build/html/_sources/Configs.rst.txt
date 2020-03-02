.. Configs:

Configuration Names and SSC Models
**********************************

A configuration is a combination of compute modules required to model a type of system (performance model) or project (performance model plus financial models).

.. list-table::
	:widths: 50 100
	:header-rows: 1
	
	* - SAM Configuration
	  - SSC Compute Module(s)
	* - Battery-None
	  - battery
	* - Biopower-All Equity Partnership Flip
	  -  biomass, equpartflip
	* - Biopower-Commercial
	  -  biomass, utilityrate5, cashloan
	* - Biopower-LCOE Calculator
	  -  biomass, lcoefcr
	* - Biopower-Leveraged Partnership Flip
	  -  biomass, levpartflip
	* - Biopower-None
	  -  biomass
	* - Biopower-Sale Leaseback
	  -  biomass, saleleaseback
	* - Biopower-Single Owner
	  -  biomass, singleowner
	* - Dish Stirling-All Equity Partnership Flip
	  -  tcsdish, equpartflip
	* - Dish Stirling-Commercial
	  -  tcsdish, utilityrate5, cashloan
	* - Dish Stirling-LCOE Calculator
	  -  tcsdish, lcoefcr
	* - Dish Stirling-Leveraged Partnership Flip
	  -  tcsdish, levpartflip
	* - Dish Stirling-None
	  -  tcsdish
	* - Dish Stirling-Sale Leaseback
	  -  tcsdish, saleleaseback
	* - Dish Stirling-Single Owner
	  -  tcsdish, singleowner
	* - DSGL IPH-LCOH Calculator
	  -  linear_fresnel_dsg_iph, iph_to_lcoefcr, lcoefcr
	* - DSGL IPH-None
	  -  linear_fresnel_dsg_iph
	* - DSLF-All Equity Partnership Flip
	  -  tcslinear_fresnel, equpartflip
	* - DSLF-Commercial
	  -  tcslinear_fresnel, utilityrate5, cashloan
	* - DSLF-LCOE Calculator
	  -  tcslinear_fresnel, lcoefcr
	* - DSLF-Leveraged Partnership Flip
	  -  tcslinear_fresnel, levpartflip
	* - DSLF-None
	  -  tcslinear_fresnel
	* - DSLF-Sale Leaseback
	  -  tcslinear_fresnel, saleleaseback
	* - DSLF-Single Owner
	  -  tcslinear_fresnel, singleowner
	* - DSPT-All Equity Partnership Flip
	  -  tcsdirect_steam, equpartflip
	* - DSPT-Leveraged Partnership Flip
	  -  tcsdirect_steam, levpartflip
	* - DSPT-Sale Leaseback
	  -  tcsdirect_steam, saleleaseback
	* - DSPT-Single Owner
	  -  tcsdirect_steam, singleowner
	* - Empirical Trough-All Equity Partnership Flip
	  -  tcstrough_empirical, equpartflip
	* - Empirical Trough-Commercial
	  -  tcstrough_empirical, utilityrate5, cashloan
	* - Empirical Trough-LCOE Calculator
	  -  tcstrough_empirical, lcoefcr
	* - Empirical Trough-Leveraged Partnership Flip
	  -  tcstrough_empirical, levpartflip
	* - Empirical Trough-None
	  -  tcstrough_empirical
	* - Empirical Trough-Sale Leaseback
	  -  tcstrough_empirical, saleleaseback
	* - Empirical Trough-Single Owner
	  -  tcstrough_empirical, singleowner
	* - Flat Plate PV-All Equity Partnership Flip
	  -  pvsamv1, equpartflip
	* - Flat Plate PV-Commercial
	  -  pvsamv1, utilityrate5, cashloan
	* - Flat Plate PV-Host Developer
	  -  pvsamv1, utilityrate5, host_developer
	* - Flat Plate PV-LCOE Calculator
	  -  pvsamv1, lcoefcr
	* - Flat Plate PV-Leveraged Partnership Flip
	  -  pvsamv1, levpartflip
	* - Flat Plate PV-None
	  -  pvsamv1
	* - Flat Plate PV-Residential
	  -  belpe, pvsamv1, utilityrate5, cashloan
	* - Flat Plate PV-Sale Leaseback
	  -  pvsamv1, saleleaseback
	* - Flat Plate PV-Single Owner
	  -  pvsamv1, utilityrate5, singleowner
	* - Flat Plate PV-Third Party
	  -  belpe, pvsamv1, utilityrate5, thirdpartyownership
	* - Fuel Cell-Commercial
	  -  pvwattsv5_lifetime, fuelcell, battery, utilityrate5, thermalrate, cashloan
	* - Fuel Cell-Single Owner
	  -  pvwattsv5_lifetime, fuelcell, battery, utilityrate5, thermalrate, singleowner
	* - Generic CSP System-All Equity Partnership Flip
	  -  tcsgeneric_solar, equpartflip
	* - Generic CSP System-Commercial
	  -  tcsgeneric_solar, utilityrate5, cashloan
	* - Generic CSP System-LCOE Calculator
	  -  tcsgeneric_solar, lcoefcr
	* - Generic CSP System-Leveraged Partnership Flip
	  -  tcsgeneric_solar, levpartflip
	* - Generic CSP System-None
	  -  tcsgeneric_solar
	* - Generic CSP System-Sale Leaseback
	  -  tcsgeneric_solar, saleleaseback
	* - Generic CSP System-Single Owner
	  -  tcsgeneric_solar, singleowner
	* - Generic System-All Equity Partnership Flip
	  -  generic_system, equpartflip
	* - Generic System-Commercial
	  -  generic_system, utilityrate5, cashloan
	* - Generic System-Host Developer
	  -  generic_system, utilityrate5, host_developer
	* - Generic System-LCOE Calculator
	  -  generic_system, lcoefcr
	* - Generic System-Leveraged Partnership Flip
	  -  generic_system, levpartflip
	* - Generic System-None
	  -  generic_system
	* - Generic System-Residential
	  -  generic_system, utilityrate5, cashloan
	* - Generic System-Sale Leaseback
	  -  generic_system, saleleaseback
	* - Generic System-Single Owner
	  -  generic_system, singleowner
	* - Generic System-Third Party
	  -  generic_system, utilityrate5, thirdpartyownership
	* - Geothermal Power-All Equity Partnership Flip
	  -  geothermal, equpartflip
	* - Geothermal Power-LCOE Calculator
	  -  geothermal, lcoefcr
	* - Geothermal Power-Leveraged Partnership Flip
	  -  geothermal, levpartflip
	* - Geothermal Power-None
	  -  geothermal
	* - Geothermal Power-Sale Leaseback
	  -  geothermal, saleleaseback
	* - Geothermal Power-Single Owner
	  -  geothermal, singleowner
	* - High-X Concentrating PV-All Equity Partnership Flip
	  -  hcpv, equpartflip
	* - High-X Concentrating PV-LCOE Calculator
	  -  hcpv, lcoefcr
	* - High-X Concentrating PV-Leveraged Partnership Flip
	  -  hcpv, levpartflip
	* - High-X Concentrating PV-None
	  -  hcpv
	* - High-X Concentrating PV-Sale Leaseback
	  -  hcpv, saleleaseback
	* - High-X Concentrating PV-Single Owner
	  -  hcpv, singleowner
	* - ISCC-Single Owner
	  -  tcsiscc, singleowner
	* - MSLF-All Equity Partnership Flip
	  -  tcsMSLF, equpartflip
	* - MSLF-Commercial
	  -  tcsMSLF, utilityrate5, cashloan
	* - MSLF-LCOE Calculator
	  -  tcsMSLF, lcoefcr
	* - MSLF-Leveraged Partnership Flip
	  -  tcsMSLF, levpartflip
	* - MSLF-None
	  -  tcsMSLF
	* - MSLF-Sale Leaseback
	  -  tcsMSLF, saleleaseback
	* - MSLF-Single Owner
	  -  tcsMSLF, singleowner
	* - MSPT-All Equity Partnership Flip
	  -  tcsmolten_salt, equpartflip
	* - MSPT-Leveraged Partnership Flip
	  -  tcsmolten_salt, levpartflip
	* - MSPT-Sale Leaseback
	  -  tcsmolten_salt, saleleaseback
	* - MSPT-Single Owner
	  -  tcsmolten_salt, singleowner
	* - Physical Trough IPH-LCOH Calculator
	  -  trough_physical_process_heat, iph_to_lcoefcr, lcoefcr
	* - Physical Trough IPH-None
	  -  trough_physical_process_heat
	* - Physical Trough-All Equity Partnership Flip
	  -  tcstrough_physical, equpartflip
	* - Physical Trough-Commercial
	  -  tcstrough_physical, utilityrate5, cashloan
	* - Physical Trough-LCOE Calculator
	  -  tcstrough_physical, lcoefcr
	* - Physical Trough-Leveraged Partnership Flip
	  -  tcstrough_physical, levpartflip
	* - Physical Trough-None
	  -  tcstrough_physical
	* - Physical Trough-Sale Leaseback
	  -  tcstrough_physical, saleleaseback
	* - Physical Trough-Single Owner
	  -  tcstrough_physical, singleowner
	* - PVWatts-All Equity Partnership Flip
	  -  pvwattsv7, equpartflip
	* - PVWatts-Commercial
	  -  pvwattsv7, battwatts, utilityrate5, cashloan
	* - PVWatts-Host Developer
	  -  pvwattsv7, utilityrate5, host_developer
	* - PVWatts-LCOE Calculator
	  -  pvwattsv7, lcoefcr
	* - PVWatts-Leveraged Partnership Flip
	  -  pvwattsv7, levpartflip
	* - PVWatts-None
	  -  pvwattsv7
	* - PVWatts-Residential
	  -  pvwattsv7, belpe, battwatts, utilityrate5, cashloan
	* - PVWatts-Sale Leaseback
	  -  pvwattsv7, saleleaseback
	* - PVWatts-Single Owner
	  -  pvwattsv7, singleowner
	* - PVWatts-Third Party
	  -  pvwattsv7, belpe, battwatts, utilityrate5, thirdpartyownership
	* - Solar Water Heating-Commercial
	  -  swh, utilityrate5, cashloan
	* - Solar Water Heating-LCOE Calculator
	  -  swh, lcoefcr
	* - Solar Water Heating-None
	  -  swh
	* - Solar Water Heating-Residential
	  -  swh, belpe, utilityrate5, cashloan
	* - Wind Power-All Equity Partnership Flip
	  -  windpower, equpartflip
	* - Wind Power-Commercial
	  -  windpower, utilityrate5, cashloan
	* - Wind Power-LCOE Calculator
	  -  windpower, lcoefcr
	* - Wind Power-Leveraged Partnership Flip
	  -  windpower, levpartflip
	* - Wind Power-None
	  -  windpower
	* - Wind Power-Residential
	  -  windpower, utilityrate5, cashloan
	* - Wind Power-Sale Leaseback
	  -  windpower, saleleaseback
	* - Wind Power-Single Owner 
	  -  windpower, singleowner


