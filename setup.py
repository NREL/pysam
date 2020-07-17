import json, marshal, os, shutil
from setuptools import setup, Extension
import sys
from distutils.core import Command
from files.version import __version__

###################################################################################################
#
# Setup for NREL-PySAM Package
#
###################################################################################################

latest_version = __version__

# defaults and include directories
defaults_dir = os.environ['SAMNTDIR'] + "/api/api_autogen/library/defaults/"
includepath = os.environ['SAMNTDIR'] + "/api/include"
srcpath = os.environ['SAMNTDIR'] + "/api/src"

this_directory = os.environ['PYSAMDIR']
libpath = this_directory + "/files"


# prepare package description
with open(os.path.join(this_directory, 'RELEASE.md'), encoding='utf-8') as f:
    long_description = f.read()


# prepare package
libs = []
libfiles = ['__init__.py', 'version.py']
extra_compile_args = ["-Wno-implicit-function-declaration", "-Wno-unused-function", "-Wno-strict-prototypes"]
extra_link_args = []
defines = []

if sys.platform == 'darwin':
    from distutils import sysconfig
    vars = sysconfig.get_config_vars()
    vars['LDSHARED'] = vars['LDSHARED'].replace('-bundle', '-dynamiclib')
    libs = ['SAM_api', 'ssc']
    libfiles += ['libSAM_api.so', 'libssc.so']
    extra_link_args = ["-Wl,-rpath,@loader_path/"]
    extra_compile_args.append("-Wno-ignored-attributes")

if sys.platform == 'linux':
    libs = ['SAM_api', 'ssc']
    libfiles += ['libSAM_api.so', 'libssc.so']
    extra_link_args = ["-Wl,-rpath,$ORIGIN/"]
    extra_compile_args.append('-Wno-attributes')

if sys.platform == 'win32':
    libs = ['SAM_api', 'ssc']
    libfiles += ['SAM_api.dll', 'ssc.dll', 'SAM_api.lib', 'ssc.lib']
    defines = [('__WINDOWS__', '1')]
    extra_compile_args = []


###################################################################################################
#
# Copy Required Source and Data Files
#
###################################################################################################

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


defaults_df_dir = 'files/defaults'
if os.path.exists(defaults_df_dir):
    shutil.rmtree(defaults_df_dir)
os.mkdir(defaults_df_dir)
# generate defaults and copy them into installation
for filename in os.listdir(defaults_dir):
    with open(defaults_dir + '/' + filename) as f:
        name = os.path.splitext(filename)
        if name[1] != '.json':
            continue
        data = json.load(f)

        dic = data[list(data.keys())[0]]
        with open('files/defaults/' + name[0].lower() + '.df', "wb") as out:
            marshal.dump(dic, out)

for filename in os.listdir(defaults_df_dir):
    libfiles.append('defaults/' + os.path.splitext(filename)[0] + '.df')

# make list of all extension modules
extension_modules = [Extension('PySAM.AdjustmentFactors',
                     ['src/AdjustmentFactors.c'],
                    define_macros=defines,
                    include_dirs=[srcpath, includepath, this_directory + "/src"],
                    library_dirs=[libpath],
                    libraries=libs,
                    extra_compile_args=extra_compile_args,
                    extra_link_args=extra_link_args
                    )]

for filename in os.listdir(this_directory + "/modules"):
    extension_modules.append(Extension('PySAM.' + os.path.splitext(filename)[0],
                             ['modules/' + filename],
                            define_macros=defines,
                            include_dirs=[srcpath, includepath, this_directory + "/src"],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_compile_args=extra_compile_args,
                            extra_link_args=extra_link_args
                            ))

# function to rename macosx distribution for Python 3.7 to be minimum version of 10.12 instead of 10.14


class PostProcess(Command):
    description = "rename macosx distribution for Python 3.7 to be minimum version of 10.12 instead of 10.14"
    user_options = []

    def initialize_options(self):
        self.cwd = None

    def finalize_options(self):
        self.cwd = os.getcwd()

    def run(self):
        assert os.getcwd() == self.cwd, 'Must be in package root: %s' % self.cwd
        name = "NREL_PySAM-" + latest_version + "-" + "cp37-cp37m-macosx_10_14_x86_64.whl"
        newname = "NREL_PySAM-" + latest_version + "-" + "cp37-cp37m-macosx_10_12_x86_64.whl"
        os.system('mv ./dist/' + name + ' ./dist/' + newname)

    ###################################################################################################
#
# setup script
#
###################################################################################################


setup(
    name='NREL-PySAM',
    version=latest_version,
    url='https://nrel-pysam.readthedocs.io',
    description="National Renewable Energy Laboratory's System Advisor Model Python Wrapper",
    long_description=long_description,
    long_description_content_type='text/markdown',
    license='BSD 3-Clause',
    author="dguittet",
    author_email="dguittet@nrel.gov",
    include_package_data=True,
    packages=['PySAM'],
    package_dir={'PySAM': 'files'},
    package_data={
        '': libfiles},
    install_requires=['NREL-PySAM-stubs'],
    setup_requires=["pytest-runner"],
    tests_require=["pytest"],
    cmdclass={
        'post': PostProcess
    },
    ext_modules=extension_modules
)


# Clean up
shutil.rmtree(defaults_df_dir)
