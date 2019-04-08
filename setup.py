import json, marshal, os, ntpath

def copy_defaults():

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


    for filename in os.listdir(defaults_dir):
        with open(defaults_dir+'/'+filename) as f:
            data = json.load(f)

            dic = data[list(data.keys())[0]]
            with open('data/defaults/'+os.path.splitext(filename)[0]+'.df', "wb") as out:
                marshal.dump(dic, out)

import sys
from setuptools import setup, Extension

# os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")

libs = []
libpath = os.path.dirname(os.path.abspath(__file__))+"/data"
includepath = os.environ['SAMNTDIR']+"/api/include"
libfiles = []
extra_link_args = ['']
if sys.platform == 'darwin':
    from distutils import sysconfig
    vars = sysconfig.get_config_vars()
    vars['LDSHARED'] = vars['LDSHARED'].replace('-bundle', '-dynamiclib')
    libs = ['SAM_api', 'ssc']
    libfiles = ['libSAM_api.so', 'libssc.so']
    extra_link_args = ["-Wl,-rpath,@loader_path/"]

if sys.platform == 'linux':
    libs = ['SAM_api', 'ssc']
    libfiles = ['libSAM_api.so', 'libssc.so']
    extra_link_args = ["-Wl,-rpath,$ORIGIN/"]

if sys.platform == 'win32':
    libs = ['SAM_api', 'ssc']
    libfiles = ['SAM_api.dll', 'ssc.dll', 'SAM_api.lib', 'ssc.lib']

defaults_dir = os.environ['SAMNTDIR']+"/api_autogen/library/defaults/"
copy_defaults()
for filename in os.listdir(defaults_dir):
    libfiles.append('defaults/' + os.path.splitext(filename)[0] + '.df')

setup(
    name='NREL-PySAM',
    version='1.0',
    url='http://www.github.com/nrel/pysam',
    description="National Renewable Energy Laboratory's System Advisor Model Python Wrapper",
    license='BSD 3-Clause',
    author="dguittet",
    author_email="dguittet@nrel.gov",
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
                 Extension('TcsMSLF',
                           ['src/TcsMSLF.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Singleowner',
                           ['src/Singleowner.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Saleleaseback',
                           ['src/Saleleaseback.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Levpartflip',
                           ['src/Levpartflip.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Utilityrate5',
                           ['src/Utilityrate5.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('CashloanModel',
                           ['src/CashloanModel.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Lcoefcr',
                           ['src/Lcoefcr.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('TcsdirectSteam',
                           ['src/TcsdirectSteam.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Equpartflip',
                           ['src/Equpartflip.c'],
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
                 Extension('Pvwattsv5Lifetime',
                           ['src/Pvwattsv5Lifetime.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Fuelcell',
                           ['src/Fuelcell.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('StandAloneBattery',
                           ['src/StandAloneBattery.c'],
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
                 Extension('Geothermal',
                           ['src/Geothermal.c'],
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
                 Extension('TroughPhysicalProcessHeat',
                           ['src/TroughPhysicalProcessHeat.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('IphToLcoefcr',
                           ['src/IphToLcoefcr.c'],
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
                 Extension('Thirdpartyownership',
                           ['src/Thirdpartyownership.c'],
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
                 Extension('Tcsiscc',
                           ['src/Tcsiscc.c'],
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
                 Extension('Pvwattsv5',
                           ['src/Pvwattsv5.c'],
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
                           ),
                 Extension('Battwatts',
                           ['src/Battwatts.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('Belpe',
                           ['src/Belpe.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                 Extension('HostDeveloper',
                           ['src/HostDeveloper.c'],
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           )
                ]
    )

