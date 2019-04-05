import json, marshal, os, ntpath



# serialize all defaults into dict
def _decode(o):
    if isinstance(o, str):
        try:
            return float(o)
        except ValueError:
            return o
    elif isinstance(o, dict):
        dic = {}
        for k, v in o.items():
            if k != "hybrid_dispatch_schedule" and k != "biopwr_plant_tou_grid":
                dic[k] = _decode(v)
            else:
                dic[k] = v
        return dic
    elif isinstance(o, list):
        return [_decode(v) for v in o]
    else:
        return o

defaults_dir = os.environ['SAMNTDIR']+"/api_autogen/library/defaults/"

for filename in os.listdir(defaults_dir):
    with open(defaults_dir+'/'+filename) as f:
        data = json.load(f)

        dic = data[list(data.keys())[0]]
        with open('data/defaults/'+os.path.splitext(filename)[0]+'.df', "wb") as out:
            marshal.dump(dic, out)

import sys
from setuptools import setup, Extension

os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")

libs = []
libpath = os.path.dirname(os.path.abspath(__file__))+"/data"
includepath = os.environ['SAMNTDIR']+"/api/include"
libfiles = []
extra_link_args = ['-Wl,-rpath,'+'@loader_path/']
if sys.platform == 'darwin':
    from distutils import sysconfig
    vars = sysconfig.get_config_vars()
    vars['LDSHARED'] = vars['LDSHARED'].replace('-bundle', '-dynamiclib')
    libs = ['SAM_apid', 'sscd']
    libfiles = ['libSAM_apid.so', 'libsscd.so']

if sys.platform == 'linux':
    libs = ['SAM_apid', 'sscd']
    libfiles = ['libSAM_apid.so', 'libsscd.so']

if sys.platform == 'win32':
    libs = ['SAM_apid', 'sscd']
    libfiles = ['SAM_apid.dll', 'sscd.dll', 'SAM_apid.lib', 'sscd.lib']
    extra_link_args = ['']

for filename in os.listdir(defaults_dir):
    libfiles.append('defaults/'+os.path.splitext(filename)[0]+'.df')

setup(
    name='System-Advisor-Model',
    version='0.0',
    include_package_data=True,
    packages=[''],
    package_dir={'': 'data'},
    package_data={
        '': libfiles},
    ext_modules=[Extension('AdjustmentFactors',
                           ['src/AdjustmentFactors.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('GenericSystem',
                           ['src/GenericSystem.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('LinearFresnelDsgIph',
                           ['src/LinearFresnelDsgIph.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcsmoltenSalt',
                           ['src/TcsmoltenSalt.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Biomass',
                           ['src/Biomass.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Tcsdish',
                           ['src/Tcsdish.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Hcpv',
                           ['src/Hcpv.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcsgenericSolar',
                           ['src/TcsgenericSolar.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Pvsamv1',
                           ['src/Pvsamv1.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Geothermal',
                           ['src/Geothermal.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Swh',
                           ['src/Swh.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcsMSLF',
                           ['src/TcsMSLF.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 # Extension('Battery',
                 #           ['src/Battery.c'],
                 #           include_dirs=[includepath],
                 #           library_dirs=[libpath],
                 #           libraries=libs,
                 #           extra_link_args=extra_link_args
                 #           ),
                 Extension('Pvwattsv5',
                           ['src/Pvwattsv5.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcstroughPhysical',
                           ['src/TcstroughPhysical.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TroughPhysicalProcessHeat',
                           ['src/TroughPhysicalProcessHeat.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcslinearFresnel',
                           ['src/TcslinearFresnel.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Windpower',
                           ['src/Windpower.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcstroughEmpirical',
                           ['src/TcstroughEmpirical.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           )
                 ]
    )

