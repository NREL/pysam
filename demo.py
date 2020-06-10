"""
Most recently tested against PySAM 2.1.4
"""

import matplotlib.pyplot as plot
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

import PySAM.Singleowner as Singleowner

import time
import multiprocessing
from itertools import product

import PySAM.Pvsamv1 as Pvsamv1


def gcr_func(x, y):
    # set up base
    a = Pvsamv1.default("FlatPlatePVSingleowner")
    a.SolarResource.solar_resource_file = "../sam/deploy/solar_resource/tucson_az_32.116521_-110.933042_psmv3_60_tmy.csv"

    b = Singleowner.default("FlatPlatePVSingleowner")

    # set up shading
    a.Shading.subarray1_shade_mode = 1
    a.Layout.subarray1_nmodx = 12
    a.Layout.subarray1_nmody = 2

    a.SystemDesign.subarray1_gcr = float(x)
    land_area = a.CECPerformanceModelWithModuleDatabase.cec_area * (a.SystemDesign.subarray1_nstrings
                        * a.SystemDesign.subarray1_modules_per_string) / x * 0.0002471

    a.execute()
    # total_installed_cost = total_direct_cost + permitting_total + engr_total + grid_total + landprep_total + sales_tax_total + land_total
    b.SystemCosts.total_installed_cost += y * land_area * 1000
    b.SystemOutput.system_pre_curtailment_kwac = a.Outputs.gen
    b.SystemOutput.gen = a.Outputs.gen
    b.execute()
    return b.Outputs.analysis_period_irr


x = np.arange(1, 10)
y = np.arange(1, 10)

X, Y = np.meshgrid(x, y)

multi1 = time.process_time()

if __name__ == '__main__':
    with multiprocessing.Pool(processes=4) as pool:
        results = pool.starmap(gcr_func, product(x / 10, repeat=2))

multi2 = time.process_time()
print("multi process time:", multi2 - multi1, "\n")

results = np.array([results])
results = np.reshape(results, (-1, 9))
print(results)

fig = plot.figure()
ax = Axes3D(fig)
ax.plot_surface(X, Y, results)
plot.show()

plot.contour(X, Y, results)
plot.show()
