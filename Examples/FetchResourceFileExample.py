"""
This example script shows how to fetch National Solar Resource Database (NSRDB)
and Wind ToolKit (WTK) data from NREL's developer network using the FetchResourceFiles()
class within `PySAM.ResourceTools`.

Resource data is saved to disk, within the `data/PySAM Downloaded Weather Files` directory by default, 
and relative file paths to the saved files are returned.

For wind data, an additional step is taken to convert the wind toolkit output into the .srw
format PySAM expects.

Note
----
Please register for NREL_API_KEY at https://developer.nrel.gov/signup/, it's free. 

@author: skoeb
"""

import PySAM.ResourceTools as tools
import PySAM.Windpower as wp
import PySAM.Singleowner as so
    
# --- Initialize Wind Fetcher ---
wtkfetcher = tools.FetchResourceFiles(
                tech='wind',
                workers=1, #thread workers if fetching multiple files
                nrel_api_key=<NREL_API_KEY>,
                nrel_api_email=<NREL_API_EMAIL>)

# --- Pass a list of (lon, lat) tuples or Shapely points to fetch the nearest resource data ---
lon_lats = [(-105.1800775, 39.7383155)]  # golden CO
wtkfetcher.fetch(lon_lats)
    
# --- Get resource data file path ---
wtk_path_dict = wtkfetcher.resource_file_paths_dict
wtk_fp = wtk_path_dict[lon_lats[0]]

# --- Initialize Generator ---
generator = wp.default('WindPowerSingleOwner')
generator.Resource.assign({'wind_resource_model_choice': 0})
generator.Resource.assign({'wind_resource_filename': wtk_fp}) #pass path to resource file

# --- Initialize Financial Model ---
financial = so.from_existing(generator, "WindPowerSingleOwner")

# --- Execute Models ---
generator.execute()
financial.execute()
