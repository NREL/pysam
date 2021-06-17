.. Models:

Modules
=======

.. toctree::
    :hidden:
    :glob:

    modules/*

System Simulation Module Names and Descriptions
************************************************


The following modules are used in the SAM GUI's technology-financial simulations.

.. list-table::
    :widths: 50 50 100
    :header-rows: 1

    * - PySAM Module
      - SAM Desktop
      - Description
    * - :doc:`modules/Battery`
      -  Generic System-Battery
      -  Detailed battery storage model
    * - :doc:`modules/Battwatts`
      - PVWatts-Battery
      -  Simplified battery storage model
    * - :doc:`modules/Belpe`
      -  Residential, Commercial and Third Party
      -  Electric load calculator for residential buildings
    * - :doc:`modules/Biomass`
      -  Biomass combustion
      -  Biomass combustion for electricity generation
    * - :doc:`modules/Cashloan`
      -  Residential and Commercial
      -  Financial model for residential and commercial behind-the-meter projects
    * - :doc:`modules/Equpartflip`
      -  All Equity Partnership Flip
      -  PPA all equity partnership flip (no debt) financial model
    * - :doc:`modules/Fuelcell`
      -  Fuelcell
      -  Fuelcell model
    * - :doc:`modules/GenericSystem`
      -  Generic system
      -  Basic power system model using either capacity, capacity factor, and heat rate, or an hourly power generation profile as input
    * - :doc:`modules/Geothermal`
      -  Geothermal
      -  Geothermal power model for hydrothermal and EGS systems with flash or binary conversion
    * - :doc:`modules/Grid`
      -  Grid
      -  Interconnect and Curtailment limits
    * - :doc:`modules/Hcpv`
      -  High concentration PV
      -  Concentrating photovoltaic system with a high concentration photovoltaic module model and separate inverter model
    * - :doc:`modules/HostDeveloper`
      -  Third party ownership - host/developer
      -  Third party ownership with PPA financial model from host and developer perspective
    * - :doc:`modules/IphToLcoefcr`
      -  LCOH Calculator
      -  Calculate levelized cost of heat using fixed charge rate method for industrial process heat models
    * - :doc:`modules/Lcoefcr`
      -  LCOE calculator (FCR method)
      -  Calculate levelized cost of electricity using fixed charge rate method instead of cash flow
    * - :doc:`modules/Levpartflip`
      -  Leveraged Partnership Flip
      -  PPA leveraged partnership flip (with debt) financial model
    * - :doc:`modules/LinearFresnelDsgIph`
      -  Process heat linear direct steam
      -  Linear Fresnel for industrial process heat applications
    * - :doc:`modules/Merchantplant`
      -  Merchant plant
      -  Linear Fresnel for industrial process heat applications
    * - :doc:`modules/MhkWave`
      -  Marine hydrokinetic wave
      -  MHK Wave power calculation model using power distribution.
    * - :doc:`modules/Pvsamv1`
      -  Photovoltaic (detailed)
      -  Detailed photovoltaic system model with separate components for module and inverter
    * - :doc:`modules/Pvwattsv7`
      -  Photovoltaic (PVWatts)
      -  PVWatts photovoltaic system model with simple inputs
    * - :doc:`modules/Saleleaseback`
      -  PPA sale leaseback (utility)
      -  PPA sale leaseback partnership financial model
    * - :doc:`modules/Singleowner`
      -  PPA single owner (utility)
      -  PPA single owner financial model
    * - :doc:`modules/Swh`
      -  Solar water heating
      -  Solar water heating model for residential and commercial building applications
    * - :doc:`modules/TcsgenericSolar`
      -  CSP generic model
      -  CSP power system model with solar field characterized using a table of optical efficiency values
    * - :doc:`modules/Tcsiscc`
      -  CSP integrated solar combined cycle
      -  CSP molten salt power tower system with a natural gas combined cycle power plant
    * - :doc:`modules/TcslinearFresnel`
      -  CSP linear Fresnel direct steam
      -  Linear Fresnel model with steam heat transfer fluid for industrial process heat applications
    * - :doc:`modules/TcsmoltenSalt`
      -  CSP power tower molten salt
      -  CSP molten salt power tower for power generation
    * - :doc:`modules/TcsMSLF`
      -  CSP linear Fresnel molten salt
      -  CSP linear Fresnel with molten salt heat transfer fluid for power generation
    * - :doc:`modules/TcstroughEmpirical`
      -  CSP parabolic trough (empirical)
      -  CSP parabolic trough model based on empirically-derived coefficients and equations for power generation
    * - :doc:`modules/Thermalrate`
      - Fuelcell
      -  Thermal flat rate structure net revenue calculator
    * - :doc:`modules/Thirdpartyownership`
      -  Third party ownership - host
      -  Third party ownership with PPA or lease agreement financial model from host perspective
    * - :doc:`modules/TroughPhysical`
      -  CSP parabolic trough (physical)
      -  CSP parabolic trough model based on heat transfer and thermodynamic principles for power generation
    * - :doc:`modules/TroughPhysicalProcessHeat`
      -  Process heat parabolic trough
      -  Parabolic trough for industrial process heat applications
    * - :doc:`modules/Utilityrate5`
      -  Residential, Commercial, Third Party, Host Developer
      -  Retail electricity bill calculator
    * - :doc:`modules/Windpower`
      -  Wind
      -  Wind power system with one or more wind turbines



Other Modules Names and Descriptions
**************************************

These modules provide helper functions or are older versions of above modules.

.. list-table::
    :widths: 50 150
    :header-rows: 1

    * - PySAM Module
      - Description
    * - :doc:`modules/Annualoutput`
      - Annual Output
    * - :doc:`modules/BatteryStateful`
      - Single timestep battery carrying state
    * - :doc:`modules/CbConstructionFinancing`
      - Construction financing cost calculations
    * - :doc:`modules/CbEmpiricalHceHeatLoss`
      - Empirical HCE Heat Loss
    * - :doc:`modules/CbMsptSystemCosts`
      - CSP molten salt power tower system costs
    * - :doc:`modules/DsgFluxPreprocess`
      - Calculate receiver max flux and absorber (boiler, etc.) fractions
    * - :doc:`modules/GeothermalCosts`
      - Geothermal monthly and hourly models using general power block code from TRNSYS Type 224 code by M.Wagner, and some GETEM model code.
    * - :doc:`modules/Iec61853interp`
      - Determine single diode model parameters from IEC 61853 solution matrix at a given temperature and irradiance.
    * - :doc:`modules/Iec61853par`
      - Calculate 11-parameter single diode model parameters from IEC-61853 PV module test data.
    * - :doc:`modules/InvCecCg`
      - CEC Inverter Coefficient Generator
    * - :doc:`modules/Ippppa`
      - Utility IPP/Commerical PPA Finance model.
    * - :doc:`modules/Irradproc`
      - Irradiance Processor
    * - :doc:`modules/IsccDesignPoint`
      - Calculates design point inject, extraction, fossil output
    * - :doc:`modules/Layoutarea`
      - Layout Area Calculation
    * - :doc:`modules/MhkCosts`
      - Calculates various cost categories for Marine Energy arrays for different device types.
    * - :doc:`modules/Poacalib`
      - Calibrates beam and diffuse to give POA input
    * - :doc:`modules/Pv6parmod`
      - CEC 6 Parameter PV module model performance calculator.  Does not include weather file reading or irradiance processing, or inverter (DC to AC) modeling.
    * - :doc:`modules/PvGetShadeLossMpp`
      - PV get shade loss fraction for strings
    * - :doc:`modules/Pvsandiainv`
      - Sandia PV inverter performance calculator.
    * - :doc:`modules/Pvwattsv11ts`
      - pvwattsv1_1ts- single timestep calculation of PV system performance.
    * - :doc:`modules/Pvwattsv1`
      - PVWatts V.1 - integrated hourly weather reader and PV system simulator.
    * - :doc:`modules/Pvwattsv1Poa`
      - PVWatts system performance calculator.  Does not include weather file reading or irradiance processing - user must supply arrays of precalculated POA irradiance data.
    * - :doc:`modules/Pvwattsv51ts`
      - pvwattsv5_1ts- single timestep calculation of PV system performance.
    * - :doc:`modules/Pvwattsv5`
      - PVWatts V5 - integrated hourly weather reader and PV system simulator.
    * - :doc:`modules/Sco2AirCooler`
      - Returns air cooler dimensions given fluid and location design points
    * - :doc:`modules/Sco2CspSystem`
      - ...
    * - :doc:`modules/Sco2CspUdPcTables`
      - ...
    * - :doc:`modules/Sco2DesignCycle`
      - Calls sCO2 auto-design cycle function
    * - :doc:`modules/Sco2DesignPoint`
      - Returns optimized sco2 cycle parameters given inputs
    * - :doc:`modules/Singlediode`
      - Single diode model function.
    * - :doc:`modules/Singlediodeparams`
      - Single diode model parameter calculation.
    * - :doc:`modules/SixParsolve`
      - Solver for CEC/6 parameter PV module coefficients
    * - :doc:`modules/Snowmodel`
      - Estimates the Detrimental Effects due to Snow Fall
    * - :doc:`modules/Solarpilot`
      - SolarPILOT - CSP tower solar field layout tool.
    * - :doc:`modules/TcsdirectSteam`
      -  CSP direct steam power tower model for power generation
    * - :doc:`modules/Tcsdish`
      -  CSP dish-Stirling model with parameters for SES and WGA-ADDS systems for power generation
    * - :doc:`modules/TcstroughPhysical`
      - CSP model using the emperical trough TCS types.
    * - :doc:`modules/Timeseq`
      - Time sequence generator
    * - :doc:`modules/TroughPhysicalCspSolver`
      - Physical trough using CSP Solver
    * - :doc:`modules/UiTesCalcs`
      - Calculates values for all calculated values on UI TES page(s)
    * - :doc:`modules/UiUdpcChecks`
      - Calculates the levels and number of paramteric runs for 3 udpc ind variables
    * - :doc:`modules/UserHtfComparison`
      - Evaluates equivalence of two user-defined HTF tables
    * - :doc:`modules/Utilityrate2`
      - Complex utility rate structure net revenue calculator OpenEI Version 2
    * - :doc:`modules/Utilityrate3`
      - Complex utility rate structure net revenue calculator OpenEI Version 3
    * - :doc:`modules/Utilityrate4`
      - Complex utility rate structure net revenue calculator OpenEI Version 4
    * - :doc:`modules/Utilityrate`
      - Complex utility rate structure net revenue calculator
	* - :doc`modules/WaveFileReader`
	  - Wave resource data file reader (CSV)
    * - :doc:`modules/Wfcheck`
      - Weather file checker.
    * - :doc:`modules/Wfcsvconv`
      - Converter for TMY2, TMY3, INTL, EPW, SMW weather files to standard CSV format
    * - :doc:`modules/Wfreader`
      - Standard Weather File Format Reader (TMY2, TMY3, EPW, SMW, WFCSV)
    * - :doc:`modules/Windbos`
      - Wind Balance of System cost model
    * - :doc:`modules/Windcsm`
      - WISDEM turbine cost model
    * - :doc:`modules/WindFileReader`
      - SAM Wind Resource File Reader (SRW)
    * - :doc:`modules/WindObos`
      - Wind Offshore Balance of System cost model
