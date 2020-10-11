.. Configs:

Configuration Names and SSC Models
**********************************

A configuration is a combination of compute modules required to model a type of system (performance model) or project (performance model plus financial models).

.. list-table::
	:widths: 50 100
	:header-rows: 1

	* - SAM Configuration
	  - SSC Compute Module(s)
	* - Biopower-All Equity Partnership Flip
	  - biomass, grid, equpartflip
	* - Biopower-LCOE Calculator
	  - biomass, grid, lcoefcr
	* - Biopower-Leveraged Partnership Flip
	  - biomass, grid, levpartflip
	* - Biopower-Merchant Plant
	  - biomass, grid, merchantplant
	* - Biopower-None
	  - biomass, grid
	* - Biopower-Sale Leaseback
	  - biomass, grid, saleleaseback
	* - Biopower-Single Owner
	  - biomass, grid, singleowner
	* - DSGL IPH-LCOH Calculator
	  - linear_fresnel_dsg_iph, iph_to_lcoefcr, lcoefcr
	* - DSGL IPH-None
	  - linear_fresnel_dsg_iph
	* - DSLF-All Equity Partnership Flip
	  - tcslinear_fresnel, grid, equpartflip
	* - DSLF-Commercial
	  - tcslinear_fresnel, grid, utilityrate5, cashloan
	* - DSLF-LCOE Calculator
	  - tcslinear_fresnel, grid, lcoefcr
	* - DSLF-Leveraged Partnership Flip
	  - tcslinear_fresnel, grid, levpartflip
	* - DSLF-Merchant Plant
	  - tcslinear_fresnel, grid, merchantplant
	* - DSLF-None
	  - tcslinear_fresnel, grid
	* - DSLF-Sale Leaseback
	  - tcslinear_fresnel, grid, saleleaseback
	* - DSLF-Single Owner
	  - tcslinear_fresnel, grid, singleowner
	* - DSPT-All Equity Partnership Flip
	  - tcsdirect_steam, grid, equpartflip
	* - DSPT-Leveraged Partnership Flip
	  - tcsdirect_steam, grid, levpartflip
	* - DSPT-Merchant Plant
	  - tcsdirect_steam, grid, merchantplant
	* - DSPT-Sale Leaseback
	  - tcsdirect_steam, grid, saleleaseback
	* - DSPT-Single Owner
	  - tcsdirect_steam, grid, singleowner
	* - Dish Stirling-All Equity Partnership Flip
	  - tcsdish, grid, equpartflip
	* - Dish Stirling-Commercial
	  - tcsdish, grid, utilityrate5, cashloan
	* - Dish Stirling-LCOE Calculator
	  - tcsdish, grid, lcoefcr
	* - Dish Stirling-Leveraged Partnership Flip
	  - tcsdish, grid, levpartflip
	* - Dish Stirling-Merchant Plant
	  - tcsdish, grid, merchantplant
	* - Dish Stirling-None
	  - tcsdish, grid
	* - Dish Stirling-Sale Leaseback
	  - tcsdish, grid, saleleaseback
	* - Dish Stirling-Single Owner
	  - tcsdish, grid, singleowner
	* - Empirical Trough-All Equity Partnership Flip
	  - tcstrough_empirical, equpartflip
	* - Empirical Trough-Commercial
	  - tcstrough_empirical, utilityrate5, cashloan
	* - Empirical Trough-LCOE Calculator
	  - tcstrough_empirical, lcoefcr
	* - Empirical Trough-Leveraged Partnership Flip
	  - tcstrough_empirical, levpartflip
	* - Empirical Trough-Merchant Plant
	  - tcstrough_empirical, merchantplant
	* - Empirical Trough-None
	  - tcstrough_empirical
	* - Empirical Trough-Sale Leaseback
	  - tcstrough_empirical, saleleaseback
	* - Empirical Trough-Single Owner
	  - tcstrough_empirical, singleowner
	* - Flat Plate PV-All Equity Partnership Flip
	  - pvsamv1, grid, equpartflip
	* - Flat Plate PV-Commercial
	  - pvsamv1, grid, utilityrate5, cashloan
	* - Flat Plate PV-Host Developer
	  - pvsamv1, grid, utilityrate5, host_developer
	* - Flat Plate PV-LCOE Calculator
	  - pvsamv1, grid, lcoefcr
	* - Flat Plate PV-Leveraged Partnership Flip
	  - pvsamv1, grid, levpartflip
	* - Flat Plate PV-Merchant Plant
	  - pvsamv1, grid, merchantplant
	* - Flat Plate PV-None
	  - pvsamv1, grid
	* - Flat Plate PV-Residential
	  - belpe, pvsamv1, grid, utilityrate5, cashloan
	* - Flat Plate PV-Sale Leaseback
	  - pvsamv1, grid, saleleaseback
	* - Flat Plate PV-Single Owner
	  - pvsamv1, grid, singleowner
	* - Flat Plate PV-Third Party
	  - belpe, pvsamv1, grid, utilityrate5, thirdpartyownership
	* - Fuel Cell-Commercial
	  - pvwattsv7, fuelcell, battery, grid, utilityrate5, thermalrate, cashloan
	* - Fuel Cell-Single Owner
	  - pvwattsv7, fuelcell, battery, grid, utilityrate5, thermalrate, singleowner
	* - Generic Battery-All Equity Partnership Flip
	  - generic_system, battery, grid, equpartflip
	* - Generic Battery-Commercial
	  - generic_system, battery, grid, utilityrate5, cashloan
	* - Generic Battery-Host Developer
	  - generic_system, battery, grid, utilityrate5, host_developer
	* - Generic Battery-Leveraged Partnership Flip
	  - generic_system, battery, grid, levpartflip
	* - Generic Battery-Merchant Plant
	  - generic_system, battery, grid, merchantplant
	* - Generic Battery-Residential
	  - belpe, generic_system, battery, grid, utilityrate5, cashloan
	* - Generic Battery-Sale Leaseback
	  - generic_system, battery, grid, saleleaseback
	* - Generic Battery-Single Owner
	  - generic_system, battery, grid, utilityrate5, singleowner
	* - Generic Battery-Third Party
	  - belpe, generic_system, battery, grid, utilityrate5, thirdpartyownership
	* - Generic CSP System-All Equity Partnership Flip
	  - tcsgeneric_solar, grid, equpartflip
	* - Generic CSP System-Commercial
	  - tcsgeneric_solar, grid, utilityrate5, cashloan
	* - Generic CSP System-LCOE Calculator
	  - tcsgeneric_solar, grid, lcoefcr
	* - Generic CSP System-Leveraged Partnership Flip
	  - tcsgeneric_solar, grid, levpartflip
	* - Generic CSP System-Merchant Plant
	  - tcsgeneric_solar, grid, merchantplant
	* - Generic CSP System-None
	  - tcsgeneric_solar, grid
	* - Generic CSP System-Sale Leaseback
	  - tcsgeneric_solar, grid, saleleaseback
	* - Generic CSP System-Single Owner
	  - tcsgeneric_solar, grid, singleowner
	* - Generic System-All Equity Partnership Flip
	  - generic_system, grid, equpartflip
	* - Generic System-Commercial
	  - generic_system, grid, utilityrate5, cashloan
	* - Generic System-Host Developer
	  - generic_system, grid, utilityrate5, host_developer
	* - Generic System-LCOE Calculator
	  - generic_system, grid, lcoefcr
	* - Generic System-Leveraged Partnership Flip
	  - generic_system, grid, levpartflip
	* - Generic System-Merchant Plant
	  - generic_system, grid, merchantplant
	* - Generic System-None
	  - generic_system, grid
	* - Generic System-Residential
	  - generic_system, grid, utilityrate5, cashloan
	* - Generic System-Sale Leaseback
	  - generic_system, grid, saleleaseback
	* - Generic System-Single Owner
	  - generic_system, grid, singleowner
	* - Generic System-Third Party
	  - generic_system, grid, utilityrate5, thirdpartyownership
	* - Geothermal Power-All Equity Partnership Flip
	  - geothermal, grid, equpartflip
	* - Geothermal Power-LCOE Calculator
	  - geothermal, grid, lcoefcr
	* - Geothermal Power-Leveraged Partnership Flip
	  - geothermal, grid, levpartflip
	* - Geothermal Power-Merchant Plant
	  - geothermal, grid, merchantplant
	* - Geothermal Power-None
	  - geothermal, grid
	* - Geothermal Power-Sale Leaseback
	  - geothermal, grid, saleleaseback
	* - Geothermal Power-Single Owner
	  - geothermal, grid, singleowner
	* - High-X Concentrating PV-All Equity Partnership Flip
	  - hcpv, grid, equpartflip
	* - High-X Concentrating PV-LCOE Calculator
	  - hcpv, grid, lcoefcr
	* - High-X Concentrating PV-Leveraged Partnership Flip
	  - hcpv, grid, levpartflip
	* - High-X Concentrating PV-Merchant Plant
	  - hcpv, grid, merchantplant
	* - High-X Concentrating PV-None
	  - hcpv, grid
	* - High-X Concentrating PV-Sale Leaseback
	  - hcpv, grid, saleleaseback
	* - High-X Concentrating PV-Single Owner
	  - hcpv, grid, singleowner
	* - MEtidal-LCOE Calculator
	  - mhk_tidal, lcoefcr
	* - MEwave-LCOE Calculator
	  - wave_file_reader, mhk_wave, lcoefcr
	* - MSLF-All Equity Partnership Flip
	  - tcsMSLF, grid, equpartflip
	* - MSLF-Commercial
	  - tcsMSLF, grid, utilityrate5, cashloan
	* - MSLF-LCOE Calculator
	  - tcsMSLF, grid, lcoefcr
	* - MSLF-Leveraged Partnership Flip
	  - tcsMSLF, grid, levpartflip
	* - MSLF-Merchant Plant
	  - tcsMSLF, grid, merchantplant
	* - MSLF-None
	  - tcsMSLF, grid
	* - MSLF-Sale Leaseback
	  - tcsMSLF, grid, saleleaseback
	* - MSLF-Single Owner
	  - tcsMSLF, grid, singleowner
	* - MSPT-All Equity Partnership Flip
	  - tcsmolten_salt, grid, equpartflip
	* - MSPT-Leveraged Partnership Flip
	  - tcsmolten_salt, grid, levpartflip
	* - MSPT-Merchant Plant
	  - tcsmolten_salt, grid, merchantplant
	* - MSPT-Sale Leaseback
	  - tcsmolten_salt, grid, saleleaseback
	* - MSPT-Single Owner
	  - tcsmolten_salt, grid, singleowner
	* - PV Battery-All Equity Partnership Flip
	  - pvsamv1, grid, equpartflip
	* - PV Battery-Commercial
	  - pvsamv1, grid, utilityrate5, cashloan
	* - PV Battery-Host Developer
	  - pvsamv1, grid, utilityrate5, host_developer
	* - PV Battery-Leveraged Partnership Flip
	  - pvsamv1, grid, levpartflip
	* - PV Battery-Merchant Plant
	  - pvsamv1, grid, merchantplant
	* - PV Battery-Residential
	  - belpe, pvsamv1, grid, utilityrate5, cashloan
	* - PV Battery-Sale Leaseback
	  - pvsamv1, grid, saleleaseback
	* - PV Battery-Single Owner
	  - pvsamv1, grid, utilityrate5, singleowner
	* - PV Battery-Third Party
	  - belpe, pvsamv1, grid, utilityrate5, thirdpartyownership
	* - PVWatts Battery-Commercial
	  - pvwattsv7, battwatts, grid, utilityrate5, cashloan
	* - PVWatts Battery-Host Developer
	  - pvwattsv7, battwatts, grid, utilityrate5, host_developer
	* - PVWatts Battery-Residential
	  - pvwattsv7, belpe, battwatts, grid, utilityrate5, cashloan
	* - PVWatts Battery-Third Party
	  - pvwattsv7, belpe, battwatts, grid, utilityrate5, thirdpartyownership
	* - PVWatts-All Equity Partnership Flip
	  - pvwattsv7, grid, equpartflip
	* - PVWatts-Commercial
	  - pvwattsv7, grid, utilityrate5, cashloan
	* - PVWatts-Host Developer
	  - pvwattsv7, grid, utilityrate5, host_developer
	* - PVWatts-LCOE Calculator
	  - pvwattsv7, grid, lcoefcr
	* - PVWatts-Leveraged Partnership Flip
	  - pvwattsv7, grid, levpartflip
	* - PVWatts-Merchant Plant
	  - pvwattsv7, grid, merchantplant
	* - PVWatts-None
	  - pvwattsv7, grid
	* - PVWatts-Residential
	  - pvwattsv7, belpe, grid, utilityrate5, cashloan
	* - PVWatts-Sale Leaseback
	  - pvwattsv7, grid, saleleaseback
	* - PVWatts-Single Owner
	  - pvwattsv7, grid, singleowner
	* - PVWatts-Third Party
	  - pvwattsv7, belpe, grid, utilityrate5, thirdpartyownership
	* - Physical Trough IPH-LCOH Calculator
	  - trough_physical_process_heat, iph_to_lcoefcr, lcoefcr
	* - Physical Trough IPH-None
	  - trough_physical_process_heat
	* - Physical Trough-All Equity Partnership Flip
	  - trough_physical, grid, equpartflip
	* - Physical Trough-Commercial
	  - trough_physical, grid, utilityrate5, cashloan
	* - Physical Trough-LCOE Calculator
	  - trough_physical, grid, lcoefcr
	* - Physical Trough-Leveraged Partnership Flip
	  - trough_physical, grid, levpartflip
	* - Physical Trough-Merchant Plant
	  - trough_physical, grid, merchantplant
	* - Physical Trough-None
	  - trough_physical, grid
	* - Physical Trough-Sale Leaseback
	  - trough_physical, grid, saleleaseback
	* - Physical Trough-Single Owner
	  - trough_physical, grid, singleowner
	* - Solar Water Heating-Commercial
	  - swh, utilityrate5, cashloan
	* - Solar Water Heating-LCOE Calculator
	  - swh, lcoefcr
	* - Solar Water Heating-None
	  - swh
	* - Solar Water Heating-Residential
	  - swh, belpe, utilityrate5, cashloan
	* - Wind Power-All Equity Partnership Flip
	  - windpower, grid, equpartflip
	* - Wind Power-Commercial
	  - windpower, grid, utilityrate5, cashloan
	* - Wind Power-LCOE Calculator
	  - windpower, grid, lcoefcr
	* - Wind Power-Leveraged Partnership Flip
	  - windpower, grid, levpartflip
	* - Wind Power-Merchant Plant
	  - windpower, grid, merchantplant
	* - Wind Power-None
	  - windpower, grid
	* - Wind Power-Residential
	  - windpower, grid, utilityrate5, cashloan
	* - Wind Power-Sale Leaseback
	  - windpower, grid, saleleaseback
	* - Wind Power-Single Owner
	  - windpower, grid, singleowner


