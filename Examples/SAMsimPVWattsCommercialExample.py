#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar  3 09:02:22 2020

This is an example script showing how to use data exported from a SAM PVWatts
Distributed Commercial simulation and do the same simulation in PySAM.

The steps are:
    Find the modules needed for your simulation type in the docs.
    Load json file with inputs from SAM GUI.
    Load all needed PySAM module's data structures with the json input data.
    Run the simulations.
    Print the results.

Most recently tested against PySAM 2.1.4

@author: frohro
"""

import json
import PySAM.Pvwattsv7 as PVWatts
import PySAM.Grid as Grid
import PySAM.Utilityrate5 as UtilityRate
import PySAM.Cashloan as Cashloan
import PySAM.PySSC as pssc

ssc = pssc.PySSC()

verbose = True  # Make False if you don't want all the debugging info.


# Get the SAM json file, make the simulations we need for the commercial
# PVWatts simulation.

# The json file is generated from SAM using the "Generate Code" menu item
# in the added simulation case.  Choose "JSON for inputs" and a .json file
# with the title of your simulation case will be created where you select with
# the "Open" button on the file dialog.
json_file_path = 'Examples/100kW_PVWatts.json' # Change this file name to yours!
with open(json_file_path) as f:
        dic = json.load(f)
# The next seven lines are needed to load the PySAM data structures with the
# inputs from the json file.
pv_dat = pssc.dict_to_ssc_table(dic, "pvwattsv7")
grid_dat = pssc.dict_to_ssc_table(dic, "grid")
ur_dat = pssc.dict_to_ssc_table(dic, "utilityrate5")
cl_dat = pssc.dict_to_ssc_table(dic, "cashloan")
pv = PVWatts.wrap(pv_dat)
grid = Grid.from_existing(pv)
ur = UtilityRate.from_existing(pv)
cl = Cashloan.from_existing(pv)
grid.assign(Grid.wrap(grid_dat).export())
ur.assign(UtilityRate.wrap(ur_dat).export())
cl.assign(Cashloan.wrap(cl_dat).export())

# The models are executed in order.  Note that the outputs from the first
# simulation are automatically available for the next one, and so on.  :-)
pv.execute()
grid.execute()
ur.execute()
cl.execute()

if verbose: # Print out some results.  The variable names can be found in
    # the model pages of the docs.
    print('Replicating SAM Results using PySAM')
    print('ac_annual: ', pv.Outputs.ac_annual)
    print('annual_energy: ', pv.Outputs.annual_energy)
    print('ur_ec_tou_mat: ', ur.ElectricityRates.ur_ec_tou_mat)
    print('cl.Outputs.npv: ', cl.Outputs.npv)
    print('cl.FinancialParameters.analysis_period: ',
          cl.FinancialParameters.analysis_period)
    print('cl.FinancialParameters.real_discount_rate: ',
          cl.FinancialParameters.real_discount_rate)
    print('cl.Outputs.adjusted_installed cost',
          cl.Outputs.adjusted_installed_cost)
    print()

