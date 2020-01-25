import json, marshal, os, ntpath, shutil
from setuptools import setup, Extension
import distutils
import sys
from shutil import copyfile
import distutils.dir_util
from distutils.core import Command

###################################################################################################
#
# Setup for NREL-PySAM Package
#
###################################################################################################

latest_version = '2.0'

# determine if making PyPi or Conda distribution
distclass = distutils.core.Distribution
if sys.argv[1] == "bdist_conda":
    import distutils.command.bdist_conda
    distclass = distutils.command.bdist_conda.CondaDistribution


# defaults and include directories
defaults_dir = os.environ['SAMNTDIR']+"/api/api_autogen/library/defaults/"
includepath = os.environ['SAMNTDIR']+"/api/include"
srcpath = os.environ['SAMNTDIR']+"/api/src"

this_directory = os.path.abspath(os.path.dirname(__file__))
libpath = this_directory+"/files"


# prepare package description
with open(os.path.join(this_directory, 'RELEASE.md'), encoding='utf-8') as f:
    long_description = f.read()


# prepare package
libs = []
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


###################################################################################################
#
# Copy Required Source and Data Files
#
###################################################################################################

# dynamic library files should be exported to pysam/files by post-build step of each library but copy over headers

distutils.dir_util.copy_tree(
    includepath,
    this_directory+"/include",
    update=1,
    verbose=1,
)

for filename in os.listdir(srcpath):
    name = os.path.splitext(filename)
    if name[1] == ".h":
        copyfile(os.path.join(srcpath, filename), os.path.join("src", filename))

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

shutil.rmtree('files/defaults')
os.mkdir('files/defaults')
# generate defaults and copy them into installation
for filename in os.listdir(defaults_dir):
    with open(defaults_dir + '/' + filename) as f:
        name = os.path.splitext(filename)
        if name[1] != '.json':
            continue
        data = json.load(f)

        dic = data[list(data.keys())[0]]
        with open('files/defaults/' + name[0] + '.df', "wb") as out:
            marshal.dump(dic, out)

for filename in os.listdir(defaults_dir):
    libfiles.append('defaults/' + os.path.splitext(filename)[0] + '.df')

# make list of all extension modules
extension_modules = [Extension('PySAM.AdjustmentFactors',
                     ['src/AdjustmentFactors.c'],
                    define_macros=defines,
                    include_dirs=["include", "src"],
                    library_dirs=[libpath],
                    libraries=libs,
                    extra_compile_args=["-Wno-unused-function", "-Wno-ignored-attributes", "-Wno-strict-prototypes"],
                    extra_link_args=extra_link_args
                    )]

for filename in os.listdir(this_directory+"/modules"):
    extension_modules.append(Extension('PySAM.' + os.path.splitext(filename)[0],
                             ['modules/' + filename],
                            define_macros=defines,
                            include_dirs=["include", "src"],
                            library_dirs=[libpath],
                            libraries=libs,
                            extra_compile_args=["-Wno-unused-function", "-Wno-ignored-attributes", "-Wno-strict-prototypes"],
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
    distclass=distclass,
    url='https://pysam-docs.readthedocs.io',
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

