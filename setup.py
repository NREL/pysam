import json, marshal, os, ntpath

# serialize all defaults into dict
def _decode(o):
    # Note the "unicode" part is only for python2
    if isinstance(o, str):
        try:
            return float(o)
        except ValueError:
            return o
    elif isinstance(o, dict):
        return {k: _decode(v) for k, v in o.items()}
    elif isinstance(o, list):
        return [_decode(v) for v in o]
    else:
        return o


defaults_dir = os.environ['SAMNTDIR']+"/api_autogen/library/defaults/"

for filename in os.listdir(defaults_dir):
    with open(defaults_dir+'/'+filename) as f:
        data = json.load(f, object_hook=_decode)
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
                           )
                 ]
)

    #              Extension('LinearFresnelDsgIph',
    #                        ['LinearFresnelDsgIph.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TcsmoltenSalt',
    #                        ['TcsmoltenSalt.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Biomass',
    #                        ['Biomass.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Tcsdish',
    #                        ['Tcsdish.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Hcpv',
    #                        ['Hcpv.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TcsgenericSolar',
    #                        ['TcsgenericSolar.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Pvsamv1',
    #                        ['Pvsamv1.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Geothermal',
    #                        ['Geothermal.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Swh',
    #                        ['Swh.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TcsMSLF',
    #                        ['TcsMSLF.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Battery',
    #                        ['Battery.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Pvwattsv5',
    #                        ['Pvwattsv5.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TcstroughPhysical',
    #                        ['TcstroughPhysical.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TroughPhysicalProcessHeat',
    #                        ['TroughPhysicalProcessHeat.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TcslinearFresnel',
    #                        ['TcslinearFresnel.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('Windpower',
    #                        ['Windpower.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        ),
    #              Extension('TcstroughEmpirical',
    #                        ['TcstroughEmpirical.c'],
    #                        include_dirs=[includepath],
    #                        library_dirs=[libpath],
    #                        libraries=libs,
    #                        extra_link_args=extra_link_args
    #                        )
    #              ]
    # )
    #
