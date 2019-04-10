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

if sys.platform != 'win32':
    os.system("rm -r /Users/dguittet/SAM-Dev/PySAM/build")

libs = []
libpath = os.path.dirname(os.path.abspath(__file__))+"/data"
includepath = os.environ['SAMNTDIR']+"/api/include"
libfiles = []
extra_link_args = []
defines = []
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
    defines = [('__WINDOWS__', '1')]

defaults_dir = os.environ['SAMNTDIR']+"/api_autogen/library/defaults/"
# copy_defaults()
for filename in os.listdir(defaults_dir):
    libfiles.append('defaults/' + os.path.splitext(filename)[0] + '.df')

setup(
    name='NREL-PySAM',
    version='1.0.1',
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
                           define_macros = defines,
                           include_dirs=[includepath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           ),
                  Extension('TcsMSLF',
                            ['src/TcsMSLF.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Singleowner',
                            ['src/Singleowner.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Saleleaseback',
                            ['src/Saleleaseback.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Levpartflip',
                            ['src/Levpartflip.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Utilityrate5',
                            ['src/Utilityrate5.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('CashloanModel',
                            ['src/CashloanModel.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Lcoefcr',
                            ['src/Lcoefcr.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TcsdirectSteam',
                            ['src/TcsdirectSteam.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Equpartflip',
                            ['src/Equpartflip.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TcslinearFresnel',
                            ['src/TcslinearFresnel.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('LinearFresnelDsgIph',
                            ['src/LinearFresnelDsgIph.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TcsmoltenSalt',
                            ['src/TcsmoltenSalt.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Biomass',
                            ['src/Biomass.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Tcsdish',
                            ['src/Tcsdish.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Pvwattsv5Lifetime',
                            ['src/Pvwattsv5Lifetime.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Fuelcell',
                            ['src/Fuelcell.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('StandAloneBattery',
                            ['src/StandAloneBattery.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  # Extension('Thermalrate',
                  #           ['src/Thermalrate.c'],
                  #           include_dirs=[includepath],
                  #           library_dirs=[libpath],
                  #           libraries=libs,
                  #           extra_link_args=extra_link_args
                  #           ),
                  Extension('Swh',
                            ['src/Swh.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Geothermal',
                            ['src/Geothermal.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('GenericSystem',
                            ['src/GenericSystem.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Hcpv',
                            ['src/Hcpv.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TcsgenericSolar',
                            ['src/TcsgenericSolar.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TroughPhysicalProcessHeat',
                            ['src/TroughPhysicalProcessHeat.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('IphToLcoefcr',
                            ['src/IphToLcoefcr.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TcstroughPhysical',
                            ['src/TcstroughPhysical.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Thirdpartyownership',
                            ['src/Thirdpartyownership.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Pvsamv1',
                            ['src/Pvsamv1.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Tcsiscc',
                            ['src/Tcsiscc.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Windpower',
                            ['src/Windpower.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Pvwattsv5',
                            ['src/Pvwattsv5.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('TcstroughEmpirical',
                            ['src/TcstroughEmpirical.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Battwatts',
                            ['src/Battwatts.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('Belpe',
                            ['src/Belpe.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            ),
                  Extension('HostDeveloper',
                            ['src/HostDeveloper.c'],
                            define_macros = defines,
                            include_dirs=[includepath],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_link_args=extra_link_args
                            )
                ]
    )

