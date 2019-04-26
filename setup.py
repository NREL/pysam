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


from setuptools import setup, Extension
import distutils
import sys

# determine if making PyPi or Conda distribution
distclass = distutils.core.Distribution
if sys.argv[1] == "bdist_conda":
    import distutils.command.bdist_conda
    distclass = distutils.command.bdist_conda.CondaDistribution

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

# generate defaults and copy them into installation
defaults_dir = os.environ['SAMNTDIR']+"/api_autogen/library/defaults/"
copy_defaults()
for filename in os.listdir(defaults_dir):
    libfiles.append('defaults/' + os.path.splitext(filename)[0] + '.df')

# prepare package description
from os import path
this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'RELEASE.md'), encoding='utf-8') as f:
    long_description = f.read()

setup(
    name='NREL-PySAM',
    version='1.2',
    distclass=distclass,
    url='http://www.github.com/nrel/pysam',
    description="National Renewable Energy Laboratory's System Advisor Model Python Wrapper",
    long_description=long_description,
    long_description_content_type='text/markdown',
    license='BSD 3-Clause',
    author="dguittet",
    author_email="dguittet@nrel.gov",
    include_package_data=True,
    packages=['PySAM'],
    package_dir={'PySAM': 'data'},
    package_data={
        '': libfiles},
    install_requires=[ 'NREL-PySAM-stubs' ],
    ext_modules=[
        Extension('PySAM.AdjustmentFactors',
                  ['src/AdjustmentFactors.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcsMSLF',
                  ['src/TcsMSLF.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Singleowner',
                  ['src/Singleowner.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Saleleaseback',
                  ['src/Saleleaseback.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Levpartflip',
                  ['src/Levpartflip.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Utilityrate5',
                  ['src/Utilityrate5.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.CashloanModel',
                  ['src/CashloanModel.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Lcoefcr',
                  ['src/Lcoefcr.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcsdirectSteam',
                  ['src/TcsdirectSteam.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Equpartflip',
                  ['src/Equpartflip.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcslinearFresnel',
                  ['src/TcslinearFresnel.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.LinearFresnelDsgIph',
                  ['src/LinearFresnelDsgIph.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcsmoltenSalt',
                  ['src/TcsmoltenSalt.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Biomass',
                  ['src/Biomass.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Tcsdish',
                  ['src/Tcsdish.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Pvwattsv5Lifetime',
                  ['src/Pvwattsv5Lifetime.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Fuelcell',
                  ['src/Fuelcell.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.StandAloneBattery',
                  ['src/StandAloneBattery.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Thermalrate',
                  ['src/Thermalrate.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Swh',
                  ['src/Swh.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Geothermal',
                  ['src/Geothermal.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.GenericSystem',
                  ['src/GenericSystem.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Hcpv',
                  ['src/Hcpv.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcsgenericSolar',
                  ['src/TcsgenericSolar.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TroughPhysicalProcessHeat',
                  ['src/TroughPhysicalProcessHeat.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.IphToLcoefcr',
                  ['src/IphToLcoefcr.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcstroughPhysical',
                  ['src/TcstroughPhysical.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Thirdpartyownership',
                  ['src/Thirdpartyownership.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Pvsamv1',
                  ['src/Pvsamv1.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Tcsiscc',
                  ['src/Tcsiscc.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Windpower',
                  ['src/Windpower.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Pvwattsv5',
                  ['src/Pvwattsv5.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.TcstroughEmpirical',
                  ['src/TcstroughEmpirical.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Battwatts',
                  ['src/Battwatts.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.Belpe',
                  ['src/Belpe.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  ),
        Extension('PySAM.HostDeveloper',
                  ['src/HostDeveloper.c'],
                  define_macros = defines,
                  include_dirs=[includepath],
                  library_dirs=[libpath],
                  libraries=libs,
                  extra_link_args=extra_link_args
                  )
    ]
)

