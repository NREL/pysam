#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Mar  4 13:47:58 2020

@author: frohro
"""
import json
import PySAM.GenericSystem as GenericSystem
import PySAM.Singleowner as Singleowner
import PySAM.PySSC as pssc

ssc = pssc.PySSC()
with open("genericsystem_case_2020.1.17.json") as f:
    dic = json.load(f)
    gs_dat = pssc.dict_to_ssc_table(dic, "generic_system")
    so_dat = pssc.dict_to_ssc_table(dic, "singleowner")
    gs = GenericSystem.wrap(gs_dat)

    # to create GenericSystem and Singleowner combined simulation, sharing the same data
    so = Singleowner.from_existing(gs)
    so.assign(Singleowner.wrap(so_dat).export())
    
    
gs.execute()
so.execute()
print('Made it past execute.')
print(so.Outputs.export()) # as dictionary