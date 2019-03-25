import sys, os
from setuptools import setup, Extension

libs = []
libpath = os.path.dirname(os.path.abspath(__file__))+"/lib"
if sys.platform == 'darwin':
    from distutils import sysconfig
    vars = sysconfig.get_config_vars()
    vars['LDSHARED'] = vars['LDSHARED'].replace('-bundle', '-dynamiclib')
    libs = ['lib/libSAM_apid.so', 'lib/libsscd.so']

if sys.platform == 'linux':
    libs = ['lib/libSAM_apid.so', 'lib/libsscd.so']

if sys.platform == 'win32':
    libs = ['lib/libSAM_apid.dll', 'lib/libsscd.dll']


setup(
    name='PowerPlant',
    version='1.3',
    include_package_data=True,`
    packages=[''],
    package_data={
        '': libs},
    ext_modules=[Extension('PowerPlant',
                           ['PowerPlant.c'],
                           include_dirs=[libpath],
                           library_dirs=[libpath],
                           libraries=["SAM_apid",
                                      "sscd"],
                           extra_link_args=['-Wl,-rpath,'+'@loader_path/lib/']
                           )]
    )

