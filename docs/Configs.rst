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
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Biopower-LCOE Calculator
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Biopower-Leveraged Partnership Flip
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Biopower-Merchant Plant
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Biopower-None
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`
	* - Biopower-Sale Leaseback
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Biopower-Single Owner
	  - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - DSGL IPH-LCOH Calculator
	  - :doc:`modules/LinearFresnelDsgIph`, :doc:`modules/IphToLcoefcr`, :doc:`modules/Lcoefcr`
	* - DSGL IPH-None
	  - :doc:`modules/LinearFresnelDsgIph`
	* - DSLF-All Equity Partnership Flip
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - DSLF-Commercial
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - DSLF-LCOE Calculator
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - DSLF-Leveraged Partnership Flip
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - DSLF-Merchant Plant
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - DSLF-None
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`
	* - DSLF-Sale Leaseback
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - DSLF-Single Owner
	  - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - DSPT-All Equity Partnership Flip
	  - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - DSPT-Leveraged Partnership Flip
	  - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - DSPT-Merchant Plant
	  - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - DSPT-Sale Leaseback
	  - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - DSPT-Single Owner
	  - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - Dish Stirling-All Equity Partnership Flip
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Dish Stirling-Commercial
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Dish Stirling-LCOE Calculator
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Dish Stirling-Leveraged Partnership Flip
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Dish Stirling-Merchant Plant
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Dish Stirling-None
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`
	* - Dish Stirling-Sale Leaseback
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Dish Stirling-Single Owner
	  - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - Empirical Trough-All Equity Partnership Flip
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Equpartflip`
	* - Empirical Trough-Commercial
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Empirical Trough-LCOE Calculator
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Lcoefcr`
	* - Empirical Trough-Leveraged Partnership Flip
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Levpartflip`
	* - Empirical Trough-Merchant Plant
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Merchantplant`
	* - Empirical Trough-None
	  - :doc:`modules/TcstroughEmpirical`
	* - Empirical Trough-Sale Leaseback
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Saleleaseback`
	* - Empirical Trough-Single Owner
	  - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Singleowner`
	* - Flat Plate PV-All Equity Partnership Flip
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Flat Plate PV-Commercial
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Flat Plate PV-Host Developer
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
	* - Flat Plate PV-LCOE Calculator
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Flat Plate PV-Leveraged Partnership Flip
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Flat Plate PV-Merchant Plant
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Flat Plate PV-None
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`
	* - Flat Plate PV-Residential
	  - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Flat Plate PV-Sale Leaseback
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Flat Plate PV-Single Owner
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - Flat Plate PV-Third Party
	  - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
	* - Fuel Cell-Commercial
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Fuelcell`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thermalrate`, :doc:`modules/Cashloan`
	* - Fuel Cell-Single Owner
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Fuelcell`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thermalrate`, :doc:`modules/Singleowner`
	* - Generic Battery-All Equity Partnership Flip
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Generic Battery-Commercial
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Generic Battery-Host Developer
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
	* - Generic Battery-Leveraged Partnership Flip
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Generic Battery-Merchant Plant
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Generic Battery-Residential
	  - :doc:`modules/Belpe`, :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Generic Battery-Sale Leaseback
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Generic Battery-Single Owner
	  - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Singleowner`
	* - Generic Battery-Third Party
	  - :doc:`modules/Belpe`, :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
	* - Generic CSP System-All Equity Partnership Flip
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Generic CSP System-Commercial
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Generic CSP System-LCOE Calculator
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Generic CSP System-Leveraged Partnership Flip
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Generic CSP System-Merchant Plant
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Generic CSP System-None
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`
	* - Generic CSP System-Sale Leaseback
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Generic CSP System-Single Owner
	  - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - Generic System-All Equity Partnership Flip
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Generic System-Commercial
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Generic System-Host Developer
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
	* - Generic System-LCOE Calculator
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Generic System-Leveraged Partnership Flip
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Generic System-Merchant Plant
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Generic System-None
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`
	* - Generic System-Residential
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Generic System-Sale Leaseback
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Generic System-Single Owner
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - Generic System-Third Party
	  - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
	* - Geothermal Power-All Equity Partnership Flip
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Geothermal Power-LCOE Calculator
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Geothermal Power-Leveraged Partnership Flip
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Geothermal Power-Merchant Plant
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Geothermal Power-None
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`
	* - Geothermal Power-Sale Leaseback
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Geothermal Power-Single Owner
	  - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - High-X Concentrating PV-All Equity Partnership Flip
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - High-X Concentrating PV-LCOE Calculator
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - High-X Concentrating PV-Leveraged Partnership Flip
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - High-X Concentrating PV-Merchant Plant
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - High-X Concentrating PV-None
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`
	* - High-X Concentrating PV-Sale Leaseback
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - High-X Concentrating PV-Single Owner
	  - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - MEtidal-LCOE Calculator
	  - :doc:`modules/MhkTidal`, :doc:`modules/Lcoefcr`
	* - MEwave-LCOE Calculator
	  - :doc:`modules/WaveFileReader`, :doc:`modules/MhkWave`, :doc:`modules/Lcoefcr`
	* - MSLF-All Equity Partnership Flip
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - MSLF-Commercial
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - MSLF-LCOE Calculator
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - MSLF-Leveraged Partnership Flip
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - MSLF-Merchant Plant
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - MSLF-None
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`
	* - MSLF-Sale Leaseback
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - MSLF-Single Owner
	  - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - MSPT-All Equity Partnership Flip
	  - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - MSPT-Leveraged Partnership Flip
	  - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - MSPT-Merchant Plant
	  - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - MSPT-Sale Leaseback
	  - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - MSPT-Single Owner
	  - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - PV Battery-All Equity Partnership Flip
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - PV Battery-Commercial
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - PV Battery-Host Developer
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
	* - PV Battery-Leveraged Partnership Flip
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - PV Battery-Merchant Plant
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - PV Battery-Residential
	  - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - PV Battery-Sale Leaseback
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - PV Battery-Single Owner
	  - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Singleowner`
	* - PV Battery-Third Party
	  - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
	* - PVWatts Battery-Commercial
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - PVWatts Battery-Host Developer
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
	* - PVWatts Battery-Residential
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - PVWatts Battery-Third Party
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
	* - PVWatts-All Equity Partnership Flip
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - PVWatts-Commercial
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - PVWatts-Host Developer
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
	* - PVWatts-LCOE Calculator
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - PVWatts-Leveraged Partnership Flip
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - PVWatts-Merchant Plant
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - PVWatts-None
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`
	* - PVWatts-Residential
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - PVWatts-Sale Leaseback
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - PVWatts-Single Owner
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - PVWatts-Third Party
	  - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
	* - Physical Trough IPH-LCOH Calculator
	  - :doc:`modules/TroughPhysicalProcessHeat`, :doc:`modules/IphToLcoefcr`, :doc:`modules/Lcoefcr`
	* - Physical Trough IPH-None
	  - :doc:`modules/TroughPhysicalProcessHeat`
	* - Physical Trough-All Equity Partnership Flip
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Physical Trough-Commercial
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Physical Trough-LCOE Calculator
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Physical Trough-Leveraged Partnership Flip
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Physical Trough-Merchant Plant
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Physical Trough-None
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`
	* - Physical Trough-Sale Leaseback
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Physical Trough-Single Owner
	  - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
	* - Solar Water Heating-Commercial
	  - :doc:`modules/Swh`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Solar Water Heating-LCOE Calculator
	  - :doc:`modules/Swh`, :doc:`modules/Lcoefcr`
	* - Solar Water Heating-None
	  - :doc:`modules/Swh`
	* - Solar Water Heating-Residential
	  - :doc:`modules/Swh`, :doc:`modules/Belpe`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Wind Power-All Equity Partnership Flip
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
	* - Wind Power-Commercial
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Wind Power-LCOE Calculator
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
	* - Wind Power-Leveraged Partnership Flip
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
	* - Wind Power-Merchant Plant
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
	* - Wind Power-None
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`
	* - Wind Power-Residential
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
	* - Wind Power-Sale Leaseback
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
	* - Wind Power-Single Owner
	  - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
