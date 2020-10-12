.. Configs:

SAM Simulation Configurations
******************************

A SAM simulation is a combination of unit compute_modules that models a type of system (performance model) or project (performance model plus financial models).

.. list-table::
    :widths: 100 100 100
    :header-rows: 1

    * - SAM Configuration
      - Description
      - SSC Compute Module(s)
    * - Biomass Combustion - Partnership Flip without Debt
      - Biomass combustion for electricity generation. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Biomass Combustion - LCOE Calculator (FCR Method)
      - Biomass combustion for electricity generation. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Biomass Combustion - Partnership Flip with Debt
      - Biomass combustion for electricity generation. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Biomass Combustion - Merchant Plant
      - Biomass combustion for electricity generation. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Biomass Combustion - No Financial Model
      - Biomass combustion for electricity generation. Run the performance model with no financial model
      - :doc:`modules/Biomass`, :doc:`modules/Grid`
    * - Biomass Combustion - Sale Leaseback
      - Biomass combustion for electricity generation. Sale leaseback partnership PPA structure
      - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Biomass Combustion - Single Owner
      - Biomass combustion for electricity generation. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Biomass`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Linear Fresnel Direct Steam - Heat -
      - Industrial process heat linear collector system.
      - :doc:`modules/LinearFresnelDsgIph`, :doc:`modules/IphToLcoefcr`, :doc:`modules/Lcoefcr`
    * - Linear Fresnel Direct Steam - Heat - No Financial Model
      - Industrial process heat linear collector system. Run the performance model with no financial model
      - :doc:`modules/LinearFresnelDsgIph`
    * - Linear Fresnel Direct Steam - Partnership Flip without Debt
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Linear Fresnel Direct Steam - Commercial Owner
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Renewable energy system displaces commercial building electric load
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Linear Fresnel Direct Steam - LCOE Calculator (FCR Method)
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Calculate LCOE using fixed charge rate method
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Linear Fresnel Direct Steam - Partnership Flip with Debt
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Linear Fresnel Direct Steam - Merchant Plant
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Linear Fresnel Direct Steam - No Financial Model
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Run the performance model with no financial model
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`
    * - Linear Fresnel Direct Steam - Sale Leaseback
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Sale leaseback partnership PPA structure
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Linear Fresnel Direct Steam - Single Owner
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TcslinearFresnel`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Power Tower Direct Steam - Partnership Flip without Debt
      - CSP direct steam power tower system using heat transfer and thermodynamic component models. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Power Tower Direct Steam - Partnership Flip with Debt
      - CSP direct steam power tower system using heat transfer and thermodynamic component models. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Power Tower Direct Steam - Merchant Plant
      - CSP direct steam power tower system using heat transfer and thermodynamic component models. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Power Tower Direct Steam - Sale Leaseback
      - CSP direct steam power tower system using heat transfer and thermodynamic component models. Sale leaseback partnership PPA structure
      - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Power Tower Direct Steam - Single Owner
      - CSP direct steam power tower system using heat transfer and thermodynamic component models. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TcsdirectSteam`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Dish Stirling - Partnership Flip without Debt
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Dish Stirling - Commercial Owner
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Dish Stirling - LCOE Calculator (FCR Method)
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Dish Stirling - Partnership Flip with Debt
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Dish Stirling - Merchant Plant
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Dish Stirling - No Financial Model
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Run the performance model with no financial model
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`
    * - Dish Stirling - Sale Leaseback
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Sale leaseback partnership PPA structure
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Dish Stirling - Single Owner
      - Dish Stirling model with parameters for SES and WGA-ADDS systems. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Tcsdish`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Parabolic Trough - Empirical - Partnership Flip without Debt
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Equpartflip`
    * - Parabolic Trough - Empirical - Commercial Owner
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Renewable energy system displaces commercial building electric load
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Parabolic Trough - Empirical - LCOE Calculator (FCR Method)
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Calculate LCOE using fixed charge rate method
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Lcoefcr`
    * - Parabolic Trough - Empirical - Partnership Flip with Debt
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Levpartflip`
    * - Parabolic Trough - Empirical - Merchant Plant
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Merchantplant`
    * - Parabolic Trough - Empirical - No Financial Model
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Run the performance model with no financial model
      - :doc:`modules/TcstroughEmpirical`
    * - Parabolic Trough - Empirical - Sale Leaseback
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Sale leaseback partnership PPA structure
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Saleleaseback`
    * - Parabolic Trough - Empirical - Single Owner
      - CSP parabolic trough system using model with empirically-derived coefficients and equations. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TcstroughEmpirical`, :doc:`modules/Singleowner`
    * - Detailed PV Model - Partnership Flip without Debt
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Detailed PV Model - Commercial Owner
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Detailed PV Model - Third Party - Host / Developer
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Third party ownershop from host and developer perspective for PPA
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
    * - Detailed PV Model - LCOE Calculator (FCR Method)
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Detailed PV Model - Partnership Flip with Debt
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Detailed PV Model - Merchant Plant
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Detailed PV Model - No Financial Model
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Run the performance model with no financial model
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`
    * - Detailed PV Model - Residential Owner
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Renewable energy system displaces residential home electric load
      - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Detailed PV Model - Sale Leaseback
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Sale leaseback partnership PPA structure
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Detailed PV Model - Single Owner
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Detailed PV Model - Third Party Owner - Host
      - Photovoltaic system using detailed photovoltaic model with separate module and inverter component models. Third party ownership from host perspective for PPA or lease agreement
      - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
    * - Fuel Cell-PV-Battery - Commercial Owner
      - Fuel cell with photovoltaic system and optional electric battery for commercial building or PPA project applications. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Fuelcell`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thermalrate`, :doc:`modules/Cashloan`
    * - Fuel Cell-PV-Battery - Single Owner
      - Fuel cell with photovoltaic system and optional electric battery for commercial building or PPA project applications. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Fuelcell`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thermalrate`, :doc:`modules/Singleowner`
    * - Generic System-Battery - Partnership Flip without Debt
      - Generic system model with battery storage. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Generic System-Battery - Commercial Owner
      - Generic system model with battery storage. Renewable energy system displaces commercial building electric load
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Generic System-Battery - Third Party - Host / Developer
      - Generic system model with battery storage. Third party ownershop from host and developer perspective for PPA
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
    * - Generic System-Battery - Partnership Flip with Debt
      - Generic system model with battery storage. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Generic System-Battery - Merchant Plant
      - Generic system model with battery storage. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Generic System-Battery - Residential Owner
      - Generic system model with battery storage. Renewable energy system displaces residential home electric load
      - :doc:`modules/Belpe`, :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Generic System-Battery - Sale Leaseback
      - Generic system model with battery storage. Sale leaseback partnership PPA structure
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Generic System-Battery - Single Owner
      - Generic system model with battery storage. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Singleowner`
    * - Generic System-Battery - Third Party Owner - Host
      - Generic system model with battery storage. Third party ownership from host perspective for PPA or lease agreement
      - :doc:`modules/Belpe`, :doc:`modules/GenericSystem`, :doc:`modules/StandAloneBattery`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
    * - Generic Model - Partnership Flip without Debt
      - CSP power system with solar field modeled using a table of optical efficiency values. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Generic Model - Commercial Owner
      - CSP power system with solar field modeled using a table of optical efficiency values. Renewable energy system displaces commercial building electric load
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Generic Model - LCOE Calculator (FCR Method)
      - CSP power system with solar field modeled using a table of optical efficiency values. Calculate LCOE using fixed charge rate method
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Generic Model - Partnership Flip with Debt
      - CSP power system with solar field modeled using a table of optical efficiency values. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Generic Model - Merchant Plant
      - CSP power system with solar field modeled using a table of optical efficiency values. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Generic Model - No Financial Model
      - CSP power system with solar field modeled using a table of optical efficiency values. Run the performance model with no financial model
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`
    * - Generic Model - Sale Leaseback
      - CSP power system with solar field modeled using a table of optical efficiency values. Sale leaseback partnership PPA structure
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Generic Model - Single Owner
      - CSP power system with solar field modeled using a table of optical efficiency values. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TcsgenericSolar`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Generic System - Partnership Flip without Debt
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Generic System - Commercial Owner
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Renewable energy system displaces commercial building electric load
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Generic System - Third Party - Host / Developer
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Third party ownershop from host and developer perspective for PPA
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
    * - Generic System - LCOE Calculator (FCR Method)
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Calculate LCOE using fixed charge rate method
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Generic System - Partnership Flip with Debt
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Generic System - Merchant Plant
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Generic System - No Financial Model
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Run the performance model with no financial model
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`
    * - Generic System - Residential Owner
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Renewable energy system displaces residential home electric load
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Generic System - Sale Leaseback
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Sale leaseback partnership PPA structure
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Generic System - Single Owner
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Generic System - Third Party Owner - Host
      - Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input. Third party ownership from host perspective for PPA or lease agreement
      - :doc:`modules/GenericSystem`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
    * - Geothermal - Partnership Flip without Debt
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Geothermal - LCOE Calculator (FCR Method)
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Geothermal - Partnership Flip with Debt
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Geothermal - Merchant Plant
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Geothermal - No Financial Model
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Run the performance model with no financial model
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`
    * - Geothermal - Sale Leaseback
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Sale leaseback partnership PPA structure
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Geothermal - Single Owner
      - Geothermal power model for hydrothermal and EGS systems with flash or binary conversion. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Geothermal`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - High Concentration PV - Partnership Flip without Debt
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - High Concentration PV - LCOE Calculator (FCR Method)
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - High Concentration PV - Partnership Flip with Debt
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - High Concentration PV - Merchant Plant
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - High Concentration PV - No Financial Model
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Run the performance model with no financial model
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`
    * - High Concentration PV - Sale Leaseback
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Sale leaseback partnership PPA structure
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - High Concentration PV - Single Owner
      - Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Hcpv`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Tidal - LCOE Calculator (FCR Method)
      - Marine energy tidal system. Calculate LCOE using fixed charge rate method
      - :doc:`modules/MhkTidal`, :doc:`modules/Lcoefcr`
    * - Wave - LCOE Calculator (FCR Method)
      - Marine energy wave system. Calculate LCOE using fixed charge rate method
      - :doc:`modules/WaveFileReader`, :doc:`modules/MhkWave`, :doc:`modules/Lcoefcr`
    * - Linear Fresnel Molten Salt - Partnership Flip without Debt
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Linear Fresnel Molten Salt - Commercial Owner
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Renewable energy system displaces commercial building electric load
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Linear Fresnel Molten Salt - LCOE Calculator (FCR Method)
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Calculate LCOE using fixed charge rate method
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Linear Fresnel Molten Salt - Partnership Flip with Debt
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Linear Fresnel Molten Salt - Merchant Plant
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Linear Fresnel Molten Salt - No Financial Model
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Run the performance model with no financial model
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`
    * - Linear Fresnel Molten Salt - Sale Leaseback
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Sale leaseback partnership PPA structure
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Linear Fresnel Molten Salt - Single Owner
      - CSP power system that uses long small mirrors to line focus sunlight on fixed receiver tubes mounted above them.. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TcsMSLF`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Power Tower Molten Salt - Partnership Flip without Debt
      - CSP molten salt power tower system using heat transfer and thermodynamic component models. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Power Tower Molten Salt - Partnership Flip with Debt
      - CSP molten salt power tower system using heat transfer and thermodynamic component models. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Power Tower Molten Salt - Merchant Plant
      - CSP molten salt power tower system using heat transfer and thermodynamic component models. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Power Tower Molten Salt - Sale Leaseback
      - CSP molten salt power tower system using heat transfer and thermodynamic component models. Sale leaseback partnership PPA structure
      - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Power Tower Molten Salt - Single Owner
      - CSP molten salt power tower system using heat transfer and thermodynamic component models. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TcsmoltenSalt`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Detailed PV-Battery - Partnership Flip without Debt
      - Detailed photovoltaic model with battery storage. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Detailed PV-Battery - Commercial Owner
      - Detailed photovoltaic model with battery storage. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Detailed PV-Battery - Third Party - Host / Developer
      - Detailed photovoltaic model with battery storage. Third party ownershop from host and developer perspective for PPA
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
    * - Detailed PV-Battery - Partnership Flip with Debt
      - Detailed photovoltaic model with battery storage. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Detailed PV-Battery - Merchant Plant
      - Detailed photovoltaic model with battery storage. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Detailed PV-Battery - Residential Owner
      - Detailed photovoltaic model with battery storage. Renewable energy system displaces residential home electric load
      - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Detailed PV-Battery - Sale Leaseback
      - Detailed photovoltaic model with battery storage. Sale leaseback partnership PPA structure
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Detailed PV-Battery - Single Owner
      - Detailed photovoltaic model with battery storage. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Singleowner`
    * - Detailed PV-Battery - Third Party Owner - Host
      - Detailed photovoltaic model with battery storage. Third party ownership from host perspective for PPA or lease agreement
      - :doc:`modules/Belpe`, :doc:`modules/Pvsamv1`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
    * - PVWatts-Battery - Commercial Owner
      - PVWatts system model with battery storage. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - PVWatts-Battery - Third Party - Host / Developer
      - PVWatts system model with battery storage. Third party ownershop from host and developer perspective for PPA
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
    * - PVWatts-Battery - Residential Owner
      - PVWatts system model with battery storage. Renewable energy system displaces residential home electric load
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - PVWatts-Battery - Third Party Owner - Host
      - PVWatts system model with battery storage. Third party ownership from host perspective for PPA or lease agreement
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Battwatts`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
    * - PVWatts - Partnership Flip without Debt
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - PVWatts - Commercial Owner
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - PVWatts - Third Party - Host / Developer
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Third party ownershop from host and developer perspective for PPA
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/HostDeveloper`
    * - PVWatts - LCOE Calculator (FCR Method)
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - PVWatts - Partnership Flip with Debt
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - PVWatts - Merchant Plant
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - PVWatts - No Financial Model
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Run the performance model with no financial model
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`
    * - PVWatts - Residential Owner
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Renewable energy system displaces residential home electric load
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - PVWatts - Sale Leaseback
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Sale leaseback partnership PPA structure
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - PVWatts - Single Owner
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - PVWatts - Third Party Owner - Host
      - Photovoltaic system using basic NREL PVWatts V5 algorithm. Third party ownership from host perspective for PPA or lease agreement
      - :doc:`modules/Pvwattsv7`, :doc:`modules/Belpe`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Thirdpartyownership`
    * - Parabolic Trough - Heat -
      - Industrial process heat parabolic trough system using heat transfer and thermodynamic component models.
      - :doc:`modules/TroughPhysicalProcessHeat`, :doc:`modules/IphToLcoefcr`, :doc:`modules/Lcoefcr`
    * - Parabolic Trough - Heat - No Financial Model
      - Industrial process heat parabolic trough system using heat transfer and thermodynamic component models. Run the performance model with no financial model
      - :doc:`modules/TroughPhysicalProcessHeat`
    * - Parabolic Trough - Physical - Partnership Flip without Debt
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Parabolic Trough - Physical - Commercial Owner
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Renewable energy system displaces commercial building electric load
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Parabolic Trough - Physical - LCOE Calculator (FCR Method)
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Calculate LCOE using fixed charge rate method
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Parabolic Trough - Physical - Partnership Flip with Debt
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Parabolic Trough - Physical - Merchant Plant
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Parabolic Trough - Physical - No Financial Model
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Run the performance model with no financial model
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`
    * - Parabolic Trough - Physical - Sale Leaseback
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Sale leaseback partnership PPA structure
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Parabolic Trough - Physical - Single Owner
      - CSP parabolic trough system using heat transfer and thermodynamic component models. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/TroughPhysical`, :doc:`modules/Grid`, :doc:`modules/Singleowner`
    * - Solar Water Heating - Commercial Owner
      - Solar water heating model for residential and commercial building applications. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Swh`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Solar Water Heating - LCOE Calculator (FCR Method)
      - Solar water heating model for residential and commercial building applications. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Swh`, :doc:`modules/Lcoefcr`
    * - Solar Water Heating - No Financial Model
      - Solar water heating model for residential and commercial building applications. Run the performance model with no financial model
      - :doc:`modules/Swh`
    * - Solar Water Heating - Residential Owner
      - Solar water heating model for residential and commercial building applications. Renewable energy system displaces residential home electric load
      - :doc:`modules/Swh`, :doc:`modules/Belpe`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Wind - Partnership Flip without Debt
      - Small or large wind power system. Developer/investor partnership flip PPA structure without debt
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Equpartflip`
    * - Wind - Commercial Owner
      - Small or large wind power system. Renewable energy system displaces commercial building electric load
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Wind - LCOE Calculator (FCR Method)
      - Small or large wind power system. Calculate LCOE using fixed charge rate method
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Lcoefcr`
    * - Wind - Partnership Flip with Debt
      - Small or large wind power system. Developer/investor partnership flip PPA structure with debt
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Levpartflip`
    * - Wind - Merchant Plant
      - Small or large wind power system. Merchant plant with constant DSCR and ancillary services revenue, reserve accounts and depreciation allocations
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Merchantplant`
    * - Wind - No Financial Model
      - Small or large wind power system. Run the performance model with no financial model
      - :doc:`modules/Windpower`, :doc:`modules/Grid`
    * - Wind - Residential Owner
      - Small or large wind power system. Renewable energy system displaces residential home electric load
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Utilityrate5`, :doc:`modules/Cashloan`
    * - Wind - Sale Leaseback
      - Small or large wind power system. Sale leaseback partnership PPA structure
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Saleleaseback`
    * - Wind - Single Owner
      - Small or large wind power system. Single owner PPA with constant DSCR and IRR target year, reserve accounts and depreciation allocations
      - :doc:`modules/Windpower`, :doc:`modules/Grid`, :doc:`modules/Singleowner`

