import sys, os
from setuptools import setup, Extension

libs = []
libpath = os.path.dirname(os.path.abspath(__file__))+"/lib"
libfiles = []
extra_link_args = ['-Wl,-rpath,'+'@loader_path/lib/']
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
    libs = ['SAM_apid.dll', 'sscd.dll']
    libfiles = ['SAM_apid.dll', 'sscd.dll', 'SAM_apid.lib', 'sscd.lib']
    extra_link_args = ['']


setup(
    name='PowerPlant',
    version='1.3',
    include_package_data=True,
    packages=[''],
    package_dir={'': 'lib'},
    package_data={
        '': libfiles},
    ext_modules=[Extension('PowerPlant',
                           ['PowerPlant.c'],
                           include_dirs=[libpath],
                           library_dirs=[libpath],
                           libraries=libs,
                           extra_link_args=extra_link_args
                           )]
    )

