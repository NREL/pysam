.. Models:

Modules
=======

.. toctree::
    :hidden:
    :glob:

    modules/*

Simulation Module Names and Descriptions
************************************************


The modules with "SAM Desktop" names are used in the SAM GUI's technology-financial simulations.

The modules without a "SAM Desktop" entry provide helper functions or are older versions of above modules.

Technical help documentation for the SAM models is available from the `SAM Help Website <https://samrepo.nrelcloud.org/help/index.html>`_.

.. list-table::
    :widths: 50 50 100
    :header-rows: 1

    * - PySAM Module
      - SAM Desktop
      - Description
    * - :doc:`modules/Annualoutput`
      -
      - Annual Output
    * - :doc:`modules/Battery`
      - Battery
      - Battery storage standalone model .
    * - :doc:`modules/BatteryStateful`
      -
      - Battery management system model with state
    * - :doc:`modules/Battwatts`
      -
      - simple battery model
    * - :doc:`modules/Belpe`
      - Belpe
      - Estimates an electric load profile given basic building characteristics and a weather file
    * - :doc:`modules/Biomass`
      - Biopower
      - Utility scale wind farm model (adapted from TRNSYS code by P.Quinlan and openWind software by AWS Truepower)
    * - :doc:`modules/Cashloan`
      -
      - Residential/Commerical Finance model.
    * - :doc:`modules/CbConstructionFinancing`
      -
      - Construction financing cost calculations
    * - :doc:`modules/CbEmpiricalHceHeatLoss`
      -
      - Empirical HCE Heat Loss
    * - :doc:`modules/CbMsptSystemCosts`
      -
      - CSP molten salt power tower system costs
    * - :doc:`modules/Communitysolar`
      - CommunitySolar
      - Comunity Solar Financial Model
    * - :doc:`modules/DsgFluxPreprocess`
      -
      - Calculate receiver max flux and absorber (boiler, etc.) fractions
    * - :doc:`modules/Equpartflip`
      - AllEquityPartnershipFlip
      - All Equity Partnership Flip Financial Model
    * - :doc:`modules/EtesElectricResistance`
      - ETES
      - Electric resistance heater charging TES from grid, discharge with power cycle
    * - :doc:`modules/Fuelcell`
      - FuelCell
      - Fuel cell model
    * - :doc:`modules/GenericSystem`
      - GenericSystem
      - Generic System
    * - :doc:`modules/Geothermal`
      - GeothermalPower
      - Geothermal monthly and hourly models using general power block code from TRNSYS Type 224 code by M.Wagner, and some GETEM model code.
    * - :doc:`modules/GeothermalCosts`
      -
      - Geothermal monthly and hourly models using general power block code from TRNSYS Type 224 code by M.Wagner, and some GETEM model code.
    * - :doc:`modules/Grid`
      -
      - Grid model
    * - :doc:`modules/Hcpv`
      - HighXConcentratingPV
      - High-X Concentrating PV, SAM component models V.1
    * - :doc:`modules/HostDeveloper`
      - HostDeveloper
      - Host Developer Financial Model
    * - :doc:`modules/Iec61853interp`
      -
      - Determine single diode model parameters from IEC 61853 solution matrix at a given temperature and irradiance.
    * - :doc:`modules/Iec61853par`
      -
      - Calculate 11-parameter single diode model parameters from IEC-61853 PV module test data.
    * - :doc:`modules/InvCecCg`
      -
      - CEC Inverter Coefficient Generator
    * - :doc:`modules/IphToLcoefcr`
      - LCOHCalculator
      - Convert annual energy to kWt-hr and adjust fixed cost to include electric parasitic costs.
    * - :doc:`modules/Ippppa`
      -
      - Utility IPP/Commerical PPA Finance model.
    * - :doc:`modules/Irradproc`
      -
      - Irradiance Processor
    * - :doc:`modules/IsccDesignPoint`
      -
      - Calculates design point inject, extraction, fossil output
    * - :doc:`modules/Layoutarea`
      -
      - Layout Area Calculation
    * - :doc:`modules/Lcoefcr`
      - LCOECalculator
      - Calculate levelized cost of energy using fixed charge rate method.
    * - :doc:`modules/Levpartflip`
      - LeveragedPartnershipFlip
      - Leveraged Partnership Flip Financial Model
    * - :doc:`modules/LinearFresnelDsgIph`
      - DSGLIPH
      - CSP model using the linear fresnel TCS types.
    * - :doc:`modules/Merchantplant`
      -
      - Single Owner Financial Model
    * - :doc:`modules/MhkCosts`
      -
      - Calculates various cost categories for Marine Energy arrays for different device types.
    * - :doc:`modules/MhkTidal`
      -
      - MHK Tidal power calculation model using power distribution.
    * - :doc:`modules/MhkWave`
      -
      - MHK Wave power calculation model using power distribution.
    * - :doc:`modules/Poacalib`
      -
      - Calibrates beam and diffuse to give POA input
    * - :doc:`modules/Pv6parmod`
      -
      - CEC 6 Parameter PV module model performance calculator.  Does not include weather file reading or irradiance processing, or inverter (DC to AC) modeling.
    * - :doc:`modules/PvGetShadeLossMpp`
      -
      - PV get shade loss fraction for strings
    * - :doc:`modules/Pvsamv1`
      - FlatPlatePV
      - Photovoltaic performance model, SAM component models V.1
    * - :doc:`modules/Pvsandiainv`
      -
      - Sandia PV inverter performance calculator.
    * - :doc:`modules/Pvwattsv1`
      -
      - PVWatts V.1 - integrated hourly weather reader and PV system simulator.
    * - :doc:`modules/Pvwattsv11ts`
      -
      - pvwattsv1_1ts- single timestep calculation of PV system performance.
    * - :doc:`modules/Pvwattsv1Poa`
      -
      - PVWatts system performance calculator.  Does not include weather file reading or irradiance processing - user must supply arrays of precalculated POA irradiance data.
    * - :doc:`modules/Pvwattsv5`
      -
      - PVWatts V5 - integrated hourly weather reader and PV system simulator.
    * - :doc:`modules/Pvwattsv51ts`
      -
      - pvwattsv5_1ts- single timestep calculation of PV system performance.
    * - :doc:`modules/Pvwattsv7`
      -
      - PVWatts V7 - integrated hourly weather reader and PV system simulator.
    * - :doc:`modules/Pvwattsv8`
      - PVWatts
      - PVWatts V8 - integrated hourly weather reader and PV system simulator.
    * - :doc:`modules/Saleleaseback`
      - SaleLeaseback
      - Sale Leaseback Financial Model
    * - :doc:`modules/Sco2AirCooler`
      -
      - Returns air cooler dimensions given fluid and location design points
    * - :doc:`modules/Sco2CompCurves`
      -
      - Calls sCO2 auto-design cycle function
    * - :doc:`modules/Sco2CspSystem`
      -
      - ...
    * - :doc:`modules/Sco2CspUdPcTables`
      -
      - ...
    * - :doc:`modules/Singlediode`
      -
      - Single diode model function.
    * - :doc:`modules/Singlediodeparams`
      -
      - Single diode model parameter calculation.
    * - :doc:`modules/Singleowner`
      - SingleOwner
      - Single Owner Financial Model
    * - :doc:`modules/Snowmodel`
      -
      - Estimates the Detrimental Effects due to Snow Fall
    * - :doc:`modules/Solarpilot`
      -
      - SolarPILOT - CSP tower solar field layout tool.
    * - :doc:`modules/Swh`
      - SolarWaterHeating
      - Solar water heating model using multi-mode tank node model.
    * - :doc:`modules/TcsgenericSolar`
      - GenericCSPSystem
      - Generic CSP model using the generic solar TCS types.
    * - :doc:`modules/TcslinearFresnel`
      - DSLF
      - CSP model using the linear fresnel TCS types.
    * - :doc:`modules/TcsmoltenSalt`
      - MSPT
      - CSP molten salt power tower with hierarchical controller and dispatch optimization
    * - :doc:`modules/TcsMSLF`
      - MSLF
      - CSP model using the molten salt linear fresnel TCS types.
    * - :doc:`modules/TcstroughEmpirical`
      - EmpiricalTrough
      - CSP model using the emperical trough TCS types.
    * - :doc:`modules/TcstroughPhysical`
      -
      - CSP model using the emperical trough TCS types.
    * - :doc:`modules/TestUdPowerCycle`
      -
      - Test user-defined power cylce model
    * - :doc:`modules/Thermalrate`
      -
      - Thermal flat rate structure net revenue calculator
    * - :doc:`modules/Thirdpartyownership`
      - ThirdParty
      - Residential/Commercial 3rd Party Ownership Finance model.
    * - :doc:`modules/Timeseq`
      -
      - Time sequence generator
    * - :doc:`modules/TroughPhysical`
      - PhysicalTrough
      - Physical trough applications
    * - :doc:`modules/TroughPhysicalCspSolver`
      -
      - Physical trough using CSP Solver
    * - :doc:`modules/TroughPhysicalProcessHeat`
      - PhysicalTroughIPH
      - Physical trough process heat applications
    * - :doc:`modules/UiTesCalcs`
      -
      - Calculates values for all calculated values on UI TES page(s)
    * - :doc:`modules/UiUdpcChecks`
      -
      - Calculates the levels and number of paramteric runs for 3 udpc ind variables
    * - :doc:`modules/UserHtfComparison`
      -
      - Evaluates equivalence of two user-defined HTF tables
    * - :doc:`modules/Utilityrate`
      -
      - Complex utility rate structure net revenue calculator
    * - :doc:`modules/Utilityrate2`
      -
      - Complex utility rate structure net revenue calculator OpenEI Version 2
    * - :doc:`modules/Utilityrate3`
      -
      - Complex utility rate structure net revenue calculator OpenEI Version 3
    * - :doc:`modules/Utilityrate4`
      -
      - Complex utility rate structure net revenue calculator OpenEI Version 4
    * - :doc:`modules/Utilityrate5`
      - Utilityrate5
      - Complex utility rate structure net revenue calculator OpenEI Version 4 with net billing
    * - :doc:`modules/WaveFileReader`
      -
      - SAM Wave Resource File Reader
    * - :doc:`modules/Wfcheck`
      -
      - Weather file checker.
    * - :doc:`modules/Wfcsvconv`
      -
      - Converter for TMY2, TMY3, INTL, EPW, SMW weather files to standard CSV format
    * - :doc:`modules/Wfreader`
      -
      - Standard Weather File Format Reader (TMY2, TMY3, EPW, SMW, WFCSV)
    * - :doc:`modules/WindFileReader`
      -
      - SAM Wind Resource File Reader (SRW)
    * - :doc:`modules/WindObos`
      -
      - Wind Offshore Balance of System cost model
    * - :doc:`modules/Windbos`
      -
      - Wind Balance of System cost model
    * - :doc:`modules/Windcsm`
      -
      - WISDEM turbine cost model
    * - :doc:`modules/Windpower`
      - WindPower
      - Utility scale wind farm model (adapted from TRNSYS code by P.Quinlan and openWind software by AWS Truepower)
    * - :doc:`modules/SixParsolve`
      -
      - Solver for CEC/6 parameter PV module coefficients
