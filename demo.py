"""
Most recently tested against PySAM 2.1.4
"""

from pathlib import Path
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

import PySAM.Singleowner as Singleowner

import time
import multiprocessing
from itertools import product

import PySAM.Pvsamv1 as Pvsamv1

solar_resource_file = Path(__file__).parent / "tests" / "blythe_ca_33.617773_-114.588261_psmv3_60_tmy.csv"


def gcr_func(gcr, cost_per_land_area):
    """
    Returns the Internal Rate of Return of a default PV single owner project given modified ground-coverage-ratio (GCR)
    and cost per land area
    Args:
        gcr: ratio, between 0.1 - 1
        cost_per_land_area: $

    Returns: IRR

    """
    # set up base
    a = Pvsamv1.default("FlatPlatePVSingleowner")
    a.SolarResource.solar_resource_file = solar_resource_file

    b = Singleowner.default("FlatPlatePVSingleowner")

    # set up shading
    a.Shading.subarray1_shade_mode = 1
    a.Layout.subarray1_nmodx = 12
    a.Layout.subarray1_nmody = 2

    a.SystemDesign.subarray1_gcr = float(gcr)
    land_area = a.CECPerformanceModelWithModuleDatabase.cec_area * (a.SystemDesign.subarray1_nstrings
                        * a.SystemDesign.subarray1_modules_per_string) / gcr * 0.0002471
    a.execute(0)

    # total_installed_cost = total_direct_cost + permitting_total + engr_total + grid_total + landprep_total + sales_tax_total + land_total
    b.SystemCosts.total_installed_cost += cost_per_land_area * land_area * 1000
    b.SystemOutput.system_pre_curtailment_kwac = a.Outputs.gen
    b.SystemOutput.gen = a.Outputs.gen
    b.execute(0)
    return b.Outputs.analysis_period_irr


gcrs = np.arange(1, 10)
costs = np.arange(1, 10)

multi1 = time.process_time()

if __name__ == '__main__':
    with multiprocessing.Pool(processes=4) as pool:
        results = pool.starmap(gcr_func, product(gcrs / 10, repeat=2))

multi2 = time.process_time()
print("multi process time:", multi2 - multi1, "\n")

results = np.array([results])
results = np.reshape(results, (-1, 9))

X, Y = np.meshgrid(gcrs, costs)
fig = plt.figure()
ax = Axes3D(fig)
ax.plot_surface(X, Y, results)
plt.title("Internal Rate of Return")
plt.xlabel("GCR")
plt.ylabel("$ / land area")
plt.show()

plt.contour(X, Y, results)
plt.title("Internal Rate of Return")
plt.xlabel("GCR")
plt.ylabel("$ / land area")
plt.show()
