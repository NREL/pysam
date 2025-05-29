'''
This example script shows how to use `PySAM.ResourceTools` to download solar
and wind resource files from the  Resource Database (NSRDB) and and WIND
ToolKit (WTK) APIs on the NREL Developer Network.

The files are saved to `data/PySAM Downloaded Weather Files`. For each NSRDB
file, a .json file listing all available data for the location is also saved
to `data`.

To use the `FetchResourceFile` function, register an email address to receive a
free API key at at https://developer.nrel.gov/signup/.

Most recently tested against PySAM 7.0.0

@authors: skoeb, cpaulgilman
'''

import os
import PySAM.ResourceTools as tools  # MOVE BACK TO FILES FOLDER
import PySAM.Windpower as wp
import PySAM.Singleowner as so
import PySAM.Pvwattsv8 as pv

import geocoder

# replace with key and email address from https://developer.nrel.gov/signup/
sam_api_key = os.environ.get('NREL_API_KEY')
sam_email = os.environ.get('NREL_API_EMAIL')
geocode_api_key = ''  # optional, may be required for geocoder

# --- Location Coordinates ---

# Set geocode to True to use geocoding service API
geocode = False
if geocode:
    # See https://geocoder.readthedocs.io/ for different geocoding services
    g = geocoder.bing('golden, co', key=geocode_api_key)
    lon = g.latlng[1]
    lat = g.latlng[0]
else:
    lon = -105.22
    lat = 39.75

# --- Wind Example ---

# --- Initialize Wind Resource Fetcher using minimum parameters---
# See function documentation for full parameter list
wtkfetcher = tools.FetchResourceFiles(
                tech='wind',
                nrel_api_key=sam_api_key,
                nrel_api_email=sam_email)

# --- List of (lon, lat) tuples or Shapely points ---
lon_lats = [(lon, lat)]
wtkfetcher.fetch(lon_lats)

# --- Get resource data file path ---
wtk_path_dict = wtkfetcher.resource_file_paths_dict
wtk_fp = wtk_path_dict[lon_lats[0]]

# --- Initialize generator ---
if wtk_fp is not None:
    generator = wp.default('WindPowerSingleOwner')
    generator.Resource.assign({'wind_resource_model_choice': 0})
    generator.Resource.assign({'wind_resource_filename': wtk_fp})

    # --- Initialize financial model ---
    financial = so.from_existing(generator, 'WindPowerSingleOwner')

    print('Wind Power - Single Owner Results')
    generator.execute()
    print('capacity factor = {:.3f}'.format(generator.Outputs.capacity_factor))
    financial.execute()
    print('npv = ${:,.2f}'.format(financial.Outputs.project_return_aftertax_npv))

else:
    print('Wind resource file does not exist. Skipping wind model simulation.')

# --- Solar Example ---

# --- Initialize Solar Resource Fetcher with minimum parameters ---
# See function documentation for full parameter list
nsrdbfetcher = tools.FetchResourceFiles(
                tech='solar',
                nrel_api_key=sam_api_key,
                nrel_api_email=sam_email)

# --- List of (lon, lat) tuples or Shapely points ---
lon_lats = [(lon, lat)]
nsrdbfetcher.fetch(lon_lats)

# --- Get resource data file path ---
nsrdb_path_dict = nsrdbfetcher.resource_file_paths_dict
nsrdb_fp = nsrdb_path_dict[lon_lats[0]]
if nsrdb_fp is not None:

    # --- Initialize Generator ---
    generator = pv.default('PVWattsSingleOwner')
    generator.SolarResource.assign({'solar_resource_file': nsrdb_fp})

    # --- Initialize Financial Model ---
    financial = so.from_existing(generator, 'PVWattsSingleOwner')

    # --- Execute Models ---
    print('PVWatts V7 - Single Owner Results')
    generator.execute()
    print('capacity factor = {:.3f}'.format(generator.Outputs.capacity_factor))
    financial.execute()
    print('npv = ${:,.2f}'.format(financial.Outputs.project_return_aftertax_npv))
else:
    print('Solar resource file does not exist. Skipping solar simulations.')
