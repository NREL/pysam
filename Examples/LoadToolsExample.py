import pandas as pd

from pathlib import Path

from PySAM.LoadTools import get_monthly_peaks

"""
A usage example for LoadTools.get_monthly peaks with hourly annual data
Requires PySAM 4.2.0 or greater
Recently tested with 7.1.0
"""
if __name__ == "__main__":
    df = pd.read_csv(str(Path(__file__).parent / "sample_load.csv"), dtype=float)
    load = pd.to_numeric(df.iloc[:, 0]).values # Consider checking length of array in case of subhourly data

    peaks = get_monthly_peaks(load, 1)

    print(peaks)