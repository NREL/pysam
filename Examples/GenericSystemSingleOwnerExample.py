#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 13:47:58 2020

Most recently tested against PySAM 6.0.0

@author: frohro
"""
import json
import PySAM.CustomGeneration as CustomGeneration
import PySAM.Grid as Grid
import PySAM.Singleowner as Singleowner
import PySAM.PySSC as pssc

ssc = pssc.PySSC()
with open("Examples/100mW_Generic.json") as f:
    dic = json.load(f)
    gs_dat = pssc.dict_to_ssc_table(dic, "custom_generation")
    grid_dat = pssc.dict_to_ssc_table(dic, "grid")
    so_dat = pssc.dict_to_ssc_table(dic, "singleowner")

    gs = CustomGeneration.wrap(gs_dat)
    grid = Grid.from_existing(gs)
    grid.assign(Grid.wrap(grid_dat).export())

    # to create CustomGeneration and Singleowner combined simulation, sharing the same data
    so = Singleowner.from_existing(gs)
    so.assign(Singleowner.wrap(so_dat).export())


gs.execute()
grid.execute()
so.execute()
print('Made it past execute.')
print(gs.Outputs.export())  # as dictionary
